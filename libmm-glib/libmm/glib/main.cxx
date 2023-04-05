// SPDX-License-Identifier: LGPL-2.1-or-later

#include <algorithm>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/iochannel.hxx>
#include <libmm/glib/main.hxx>
#include <libmm/glib/utility.hxx>
#include <libmm/glib/wrap.hxx>

namespace
{

  inline auto
  ms2us (const unsigned int ms) -> gint64
  {
    return static_cast<gint64> (ms) * 1000;
  }

  class SourceConnectionNode : public sigc::notifiable
  {
  public:
    explicit inline SourceConnectionNode (const sigc::slot_base& slot);

    static auto
    notify (notifiable* data) -> void;
    static auto
    destroy_notify_callback (notifiable* data) -> void;

    inline auto
    install (GSource* source) -> void;
    inline auto
    get_slot () -> sigc::slot_base*;

  private:
    sigc::slot_base slot_;
    GSource* source_;
  };

  inline SourceConnectionNode::SourceConnectionNode (
      const sigc::slot_base& slot)
    : slot_ (slot),
      source_ (nullptr)
  {
    slot_.set_parent (this, &SourceConnectionNode::notify);
  }

  auto
  SourceConnectionNode::notify (notifiable* data) -> void
  {
    SourceConnectionNode* const self =
        static_cast<SourceConnectionNode*> (data);

    if (self->source_)
    {
      GSource* s = self->source_;
      self->source_ = nullptr;
      g_source_destroy (s);
    }
  }

  auto
  SourceConnectionNode::destroy_notify_callback (notifiable* data) -> void
  {
    SourceConnectionNode* const self =
        static_cast<SourceConnectionNode*> (data);

    if (self)
    {
      self->source_ = nullptr;

      delete self;
    }
  }

  inline auto
  SourceConnectionNode::install (GSource* source) -> void
  {
    source_ = source;
  }

  inline auto
  SourceConnectionNode::get_slot () -> sigc::slot_base*
  {
    return &slot_;
  }

  struct SourceCallbackData
  {
    explicit inline SourceCallbackData (glib::Source* wrapper_);

    auto
    set_node (SourceConnectionNode* node_) -> void;

    static auto
    destroy_notify_callback (void* data) -> void;

    glib::Source* wrapper;
    SourceConnectionNode* node;
  };

  inline SourceCallbackData::SourceCallbackData (glib::Source* wrapper_)
    : wrapper (wrapper_),
      node (nullptr)
  {
  }

  auto
  SourceCallbackData::set_node (SourceConnectionNode* node_) -> void
  {
    if (node)
      SourceConnectionNode::destroy_notify_callback (node);

    node = node_;
  }

  auto
  SourceCallbackData::destroy_notify_callback (void* data) -> void
  {
    const SourceCallbackData* const self =
        static_cast<SourceCallbackData*> (data);

    if (self->node)
      SourceConnectionNode::destroy_notify_callback (self->node);

    glib::Source::destroy_notify_callback2 (self->wrapper);

    delete self;
  }

  auto
  glibmm_source_get_callback_data (GSource* source) -> SourceCallbackData*
  {
    const gpointer callback_data = source->callback_data;
    const GSourceCallbackFuncs* callback_funcs = source->callback_funcs;

    g_return_val_if_fail (callback_funcs != nullptr, nullptr);

    if (g_source_is_destroyed (source))
      return nullptr;

    GSourceFunc func;
    void* user_data = nullptr;

    (*callback_funcs->get) (callback_data, source, &func, &user_data);

    return static_cast<SourceCallbackData*> (user_data);
  }

  auto
  glibmm_dummy_source_callback (void*) -> gboolean
  {
    g_assert_not_reached ();
    return 0;
  }

  auto
  glibmm_source_callback (void* data) -> gboolean
  {
    SourceConnectionNode* const conn_data =
        static_cast<SourceConnectionNode*> (data);

    try
    {
      return (*static_cast<sigc::slot<bool ()>*> (conn_data->get_slot ())) ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  glibmm_source_callback_once (void* data) -> gboolean
  {
    SourceConnectionNode* const conn_data =
        static_cast<SourceConnectionNode*> (data);

    try
    {
      (*static_cast<sigc::slot<void ()>*> (conn_data->get_slot ())) ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  glibmm_source_destroy_notify_callback (void* data) -> void
  {
    SourceConnectionNode* const conn_data =
        static_cast<SourceConnectionNode*> (data);
    SourceConnectionNode::destroy_notify_callback (conn_data);
  }

  auto
  glibmm_iosource_callback (GIOChannel*, GIOCondition condition, void* data) -> gboolean
  {
    const SourceCallbackData* const callback_data =
        static_cast<SourceCallbackData*> (data);
    g_return_val_if_fail (callback_data->node != nullptr, 0);

    try
    {
      return (*static_cast<sigc::slot<bool (glib::IOCondition)>*> (
          callback_data->node->get_slot ())) ((glib::IOCondition) condition);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  glibmm_child_watch_callback (const GPid pid,
                               const gint child_status,
                               void* data) -> gboolean
  {
    SourceConnectionNode* const conn_data =
        static_cast<SourceConnectionNode*> (data);

    try
    {
      (*static_cast<sigc::slot<void (GPid, int)>*> (
          conn_data->get_slot ())) (pid, child_status);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  glibmm_signal_connect_once (const sigc::slot<void ()>& slot,
                              const int priority,
                              GSource* source,
                              GMainContext* context) -> void
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (source,
                           &glibmm_source_callback_once,
                           conn_node,
                           &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context);
    g_source_unref (source);
  }

  auto
  glibmm_main_context_invoke_callback (void* data) -> gboolean
  {
    sigc::slot_base* const slot = reinterpret_cast<sigc::slot_base*> (data);

    try
    {
      return (*static_cast<sigc::slot<bool ()>*> (slot)) ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  glibmm_main_context_invoke_destroy_notify_callback (void* data) -> void
  {
    const sigc::slot_base* const slot =
        reinterpret_cast<sigc::slot_base*> (data);
    delete slot;
  }

} // namespace

namespace glib
{

  PollFD::PollFD ()
  {
    gobject_.fd = 0;
    gobject_.events = 0;
    gobject_.revents = 0;
  }

  PollFD::PollFD (const fd_t fd)
  {
    gobject_.fd = fd;
    gobject_.events = 0;
    gobject_.revents = 0;
  }

  PollFD::PollFD (const fd_t fd, IOCondition events)
  {
    gobject_.fd = fd;
    gobject_.events = static_cast<decltype (gobject_.events)> (events);
    gobject_.revents = 0;
  }

  inline SignalTimeout::SignalTimeout (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalTimeout::connect (const sigc::slot<bool ()>& slot,
                          const unsigned int interval,
                          const int priority) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    GSource* const source = g_timeout_source_new (interval);

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (source,
                           &glibmm_source_callback,
                           conn_node,
                           &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context_);
    g_source_unref (source);

    return connection;
  }

  auto
  SignalTimeout::connect_once (const sigc::slot<void ()>& slot,
                               const unsigned int interval,
                               const int priority) -> void
  {
    GSource* const source = g_timeout_source_new (interval);
    glibmm_signal_connect_once (slot, priority, source, context_);
  }

  auto
  SignalTimeout::connect_seconds (const sigc::slot<bool ()>& slot,
                                  const unsigned int interval,
                                  const int priority) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    GSource* const source = g_timeout_source_new_seconds (interval);

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (source,
                           &glibmm_source_callback,
                           conn_node,
                           &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context_);
    g_source_unref (source);

    return connection;
  }

  auto
  SignalTimeout::connect_seconds_once (const sigc::slot<void ()>& slot,
                                       const unsigned int interval,
                                       const int priority) -> void
  {
    GSource* const source = g_timeout_source_new_seconds (interval);
    glibmm_signal_connect_once (slot, priority, source, context_);
  }

  auto
  signal_timeout () -> SignalTimeout
  {
    return SignalTimeout (nullptr);
  }

  inline SignalIdle::SignalIdle (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalIdle::connect (const sigc::slot<bool ()>& slot, const int priority) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    GSource* const source = g_idle_source_new ();

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (source,
                           &glibmm_source_callback,
                           conn_node,
                           &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context_);
    g_source_unref (source);

    return connection;
  }

  auto
  SignalIdle::connect_once (const sigc::slot<void ()>& slot, const int priority) -> void
  {
    GSource* const source = g_idle_source_new ();
    glibmm_signal_connect_once (slot, priority, source, context_);
  }

  auto
  signal_idle () -> SignalIdle
  {
    return SignalIdle (nullptr);
  }

  inline SignalIO::SignalIO (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalIO::connect (const sigc::slot<bool (IOCondition)>& slot,
                     const PollFD::fd_t fd,
                     const IOCondition condition,
                     const int priority) -> sigc::connection
  {
    const auto source = IOSource::create (fd, condition);

    if (priority != G_PRIORITY_DEFAULT)
      source->set_priority (priority);

    const sigc::connection connection = source->connect (slot);

    g_source_attach (source->gobj (), context_);

    return connection;
  }

  auto
  SignalIO::connect (const sigc::slot<bool (IOCondition)>& slot,
                     const RefPtr<IOChannel>& channel,
                     const IOCondition condition,
                     const int priority) -> sigc::connection
  {
    const auto source = IOSource::create (channel, condition);

    if (priority != G_PRIORITY_DEFAULT)
      source->set_priority (priority);

    const sigc::connection connection = source->connect (slot);

    g_source_attach (source->gobj (), context_);

    return connection;
  }

  auto
  signal_io () -> SignalIO
  {
    return SignalIO (nullptr);
  }

  inline SignalChildWatch::SignalChildWatch (GMainContext* context)
    : context_ (context)
  {
  }

  auto
  SignalChildWatch::connect (const sigc::slot<void (GPid, int)>& slot,
                             const GPid pid,
                             const int priority) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    GSource* const source = g_child_watch_source_new (pid);

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (
        source,
        glib::function_pointer_cast<GSourceFunc> (&glibmm_child_watch_callback),
        conn_node,
        &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context_);
    g_source_unref (source);

    return connection;
  }

  auto
  signal_child_watch () -> SignalChildWatch
  {
    return SignalChildWatch (nullptr);
  }

  auto
  MainContext::create () -> RefPtr<MainContext>
  {
    return glib::make_refptr_for_instance<MainContext> (
        reinterpret_cast<MainContext*> (g_main_context_new ()));
  }

  auto
  MainContext::create (MainContextFlags flags) -> RefPtr<MainContext>
  {
    return glib::make_refptr_for_instance<MainContext> (
        reinterpret_cast<MainContext*> (g_main_context_new_with_flags (
            static_cast<GMainContextFlags> (flags))));
  }

  auto
  MainContext::get_default () -> RefPtr<MainContext>
  {
    return wrap (g_main_context_default (), true);
  }

  auto
  MainContext::iteration (const bool may_block) -> bool
  {
    return g_main_context_iteration (gobj (), may_block);
  }

  auto
  MainContext::pending () -> bool
  {
    return g_main_context_pending (gobj ());
  }

  auto
  MainContext::wakeup () -> void
  {
    g_main_context_wakeup (gobj ());
  }

  auto
  MainContext::acquire () -> bool
  {
    return g_main_context_acquire (gobj ());
  }

  auto
  MainContext::release () -> void
  {
    g_main_context_release (gobj ());
  }

  auto
  MainContext::prepare (int& priority) -> bool
  {
    return g_main_context_prepare (gobj (), &priority);
  }

  auto
  MainContext::prepare () -> bool
  {
    return g_main_context_prepare (gobj (), nullptr);
  }

  auto
  MainContext::query (const int max_priority,
                      int& timeout,
                      std::vector<PollFD>& fds) -> void
  {
    if (fds.empty ())
      fds.resize (8);

    for (;;)
    {
      const int size_before = fds.size ();
      const int size_needed = g_main_context_query (
          gobj (),
          max_priority,
          &timeout,
          reinterpret_cast<GPollFD*> (&fds.front ()),
          size_before);

      fds.resize (size_needed);

      if (size_needed <= size_before)
        break;
    }
  }

  auto
  MainContext::check (const int max_priority, std::vector<PollFD>& fds) -> bool
  {
    if (!fds.empty ())
      return g_main_context_check (gobj (),
                                   max_priority,
                                   reinterpret_cast<GPollFD*> (&fds.front ()),
                                   fds.size ());
    else
      return false;
  }

  auto
  MainContext::dispatch () -> void
  {
    g_main_context_dispatch (gobj ());
  }

  auto
  MainContext::set_poll_func (const GPollFunc poll_func) -> void
  {
    g_main_context_set_poll_func (gobj (), poll_func);
  }

  auto
  MainContext::get_poll_func () -> GPollFunc
  {
    return g_main_context_get_poll_func (gobj ());
  }

  auto
  MainContext::add_poll (PollFD& fd, const int priority) -> void
  {
    g_main_context_add_poll (gobj (), fd.gobj (), priority);
  }

  auto
  MainContext::remove_poll (PollFD& fd) -> void
  {
    g_main_context_remove_poll (gobj (), fd.gobj ());
  }

  auto
  MainContext::push_thread_default () -> void
  {
    g_main_context_push_thread_default (gobj ());
  }

  auto
  MainContext::pop_thread_default () -> void
  {
    g_main_context_pop_thread_default (gobj ());
  }

  auto
  MainContext::get_thread_default () -> RefPtr<MainContext>
  {
    return wrap (g_main_context_ref_thread_default (), false);
  }

  auto
  MainContext::invoke (const sigc::slot<bool ()>& slot, const int priority) -> void
  {
    sigc::slot_base* const slot_copy = new sigc::slot<bool ()> (slot);

    g_main_context_invoke_full (
        gobj (),
        priority,
        glibmm_main_context_invoke_callback,
        slot_copy,
        glibmm_main_context_invoke_destroy_notify_callback);
  }

  auto
  MainContext::signal_timeout () -> SignalTimeout
  {
    return SignalTimeout (gobj ());
  }

  auto
  MainContext::signal_idle () -> SignalIdle
  {
    return SignalIdle (gobj ());
  }

  auto
  MainContext::signal_io () -> SignalIO
  {
    return SignalIO (gobj ());
  }

  auto
  MainContext::signal_child_watch () -> SignalChildWatch
  {
    return SignalChildWatch (gobj ());
  }

  auto
  MainContext::reference () const -> void
  {
    g_main_context_ref (
        reinterpret_cast<GMainContext*> (const_cast<MainContext*> (this)));
  }

  auto
  MainContext::unreference () const -> void
  {
    g_main_context_unref (
        reinterpret_cast<GMainContext*> (const_cast<MainContext*> (this)));
  }

  auto
  MainContext::gobj () -> GMainContext*
  {
    return reinterpret_cast<GMainContext*> (this);
  }

  auto
  MainContext::gobj () const -> const GMainContext*
  {
    return reinterpret_cast<const GMainContext*> (this);
  }

  auto
  MainContext::gobj_copy () const -> GMainContext*
  {
    reference ();
    return const_cast<GMainContext*> (gobj ());
  }

  auto
  wrap (GMainContext* gobject, const bool take_copy) -> RefPtr<MainContext>
  {
    if (take_copy && gobject)
      g_main_context_ref (gobject);

    return glib::make_refptr_for_instance<MainContext> (
        reinterpret_cast<MainContext*> (gobject));
  }

  auto
  MainLoop::create (const bool is_running) -> RefPtr<MainLoop>
  {
    return glib::make_refptr_for_instance<MainLoop> (
        reinterpret_cast<MainLoop*> (g_main_loop_new (nullptr, is_running)));
  }

  auto
  MainLoop::create (const RefPtr<MainContext>& context, const bool is_running) -> RefPtr<MainLoop>
  {
    return glib::make_refptr_for_instance<MainLoop> (
        reinterpret_cast<MainLoop*> (
            g_main_loop_new (unwrap (context), is_running)));
  }

  auto
  MainLoop::run () -> void
  {
    g_main_loop_run (gobj ());
  }

  auto
  MainLoop::quit () -> void
  {
    g_main_loop_quit (gobj ());
  }

  auto
  MainLoop::is_running () -> bool
  {
    return g_main_loop_is_running (gobj ());
  }

  auto
  MainLoop::get_context () -> RefPtr<MainContext>
  {
    return wrap (g_main_loop_get_context (gobj ()), true);
  }

  auto
  MainLoop::depth () -> int
  {
    return g_main_depth ();
  }

  auto
  MainLoop::reference () const -> void
  {
    g_main_loop_ref (
        reinterpret_cast<GMainLoop*> (const_cast<MainLoop*> (this)));
  }

  auto
  MainLoop::unreference () const -> void
  {
    g_main_loop_unref (
        reinterpret_cast<GMainLoop*> (const_cast<MainLoop*> (this)));
  }

  auto
  MainLoop::gobj () -> GMainLoop*
  {
    return reinterpret_cast<GMainLoop*> (this);
  }

  auto
  MainLoop::gobj () const -> const GMainLoop*
  {
    return reinterpret_cast<const GMainLoop*> (this);
  }

  auto
  MainLoop::gobj_copy () const -> GMainLoop*
  {
    reference ();
    return const_cast<GMainLoop*> (gobj ());
  }

  auto
  wrap (GMainLoop* gobject, const bool take_copy) -> RefPtr<MainLoop>
  {
    if (take_copy && gobject)
      g_main_loop_ref (gobject);

    return glib::make_refptr_for_instance<MainLoop> (
        reinterpret_cast<MainLoop*> (gobject));
  }

  const GSourceFuncs Source::vfunc_table_ = {
      &Source::prepare_vfunc,
      &Source::check_vfunc,
      &Source::dispatch_vfunc,

      nullptr,
      nullptr,
      nullptr,
  };

  auto
  Source::attach (const RefPtr<MainContext>& context) -> unsigned int
  {
    return g_source_attach (gobject_, unwrap (context));
  }

  auto
  Source::attach () -> unsigned int
  {
    return g_source_attach (gobject_, nullptr);
  }

  auto
  Source::destroy () -> void
  {
    g_source_destroy (gobject_);
  }

  auto
  Source::set_priority (const int priority) -> void
  {
    g_source_set_priority (gobject_, priority);
  }

  auto
  Source::get_priority () const -> int
  {
    return g_source_get_priority (gobject_);
  }

  auto
  Source::set_can_recurse (const bool can_recurse) -> void
  {
    g_source_set_can_recurse (gobject_, can_recurse);
  }

  auto
  Source::get_can_recurse () const -> bool
  {
    return g_source_get_can_recurse (gobject_);
  }

  auto
  Source::get_id () const -> unsigned int
  {
    return g_source_get_id (gobject_);
  }

  auto
  Source::get_context () -> RefPtr<MainContext>
  {
    return wrap (g_source_get_context (gobject_), true);
  }

  auto
  Source::gobj_copy () const -> GSource*
  {
    return g_source_ref (gobject_);
  }

  auto
  Source::reference () const -> void
  {
    ++ref_count_;
  }

  auto
  Source::unreference () const -> void
  {
    if (--ref_count_ == 0)
    {
      GSource* const tmp_gobject = gobject_;

      destroy_notify_callback2 (const_cast<Source*> (this));

      g_source_unref (tmp_gobject);
    }
  }

  Source::Source ()
    : gobject_ (g_source_new (const_cast<GSourceFuncs*> (&vfunc_table_),
                              sizeof (GSource)))
  {
    g_source_set_callback (gobject_,
                           &glibmm_dummy_source_callback,
                           new SourceCallbackData (this),
                           &SourceCallbackData::destroy_notify_callback);
  }

  Source::Source (GSource* cast_item, const GSourceFunc callback_func)
    : gobject_ (cast_item)
  {
    g_source_set_callback (gobject_,
                           callback_func,
                           new SourceCallbackData (this),
                           &SourceCallbackData::destroy_notify_callback);
  }

  Source::~Source () noexcept
  {
    if (gobject_)
    {
      SourceCallbackData* const data =
          glibmm_source_get_callback_data (gobject_);

      if (data)
      {
        data->wrapper = nullptr;
      }

      GSource* const tmp_gobject = gobject_;
      gobject_ = nullptr;

      g_source_unref (tmp_gobject);
    }
  }

  auto
  Source::connect_generic (const sigc::slot_base& slot) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    SourceCallbackData* const data = glibmm_source_get_callback_data (gobject_);

    if (data)
    {
      data->set_node (conn_node);
    }

    conn_node->install (gobject_);
    return connection;
  }

  auto
  Source::add_poll (PollFD& poll_fd) -> void
  {
    g_source_add_poll (gobject_, poll_fd.gobj ());
  }

  auto
  Source::remove_poll (PollFD& poll_fd) -> void
  {
    g_source_remove_poll (gobject_, poll_fd.gobj ());
  }

  auto
  Source::get_time () const -> gint64
  {
    if (g_source_get_context (gobject_))
      return g_source_get_time (gobject_);
    else
      return g_get_monotonic_time ();
  }

  inline auto
  Source::get_wrapper (GSource* source) -> Source*
  {
    const SourceCallbackData* const data =
        glibmm_source_get_callback_data (source);
    return data ? data->wrapper : nullptr;
  }

  auto
  Source::prepare_vfunc (GSource* source, int* timeout) -> gboolean
  {
    try
    {
      Source* const self = get_wrapper (source);
      return self ? self->prepare (*timeout) : 0;
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }

    return 0;
  }

  auto
  Source::check_vfunc (GSource* source) -> gboolean
  {
    try
    {
      Source* const self = get_wrapper (source);
      return self ? self->check () : 0;
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }

    return 0;
  }

  auto
  Source::dispatch_vfunc (GSource*, const GSourceFunc callback, void* user_data) -> gboolean
  {
    const SourceCallbackData* const callback_data =
        static_cast<SourceCallbackData*> (user_data);

    g_return_val_if_fail (callback == &glibmm_dummy_source_callback, 0);
    g_return_val_if_fail (
        callback_data != nullptr && callback_data->node != nullptr,
        0);

    try
    {
      Source* const self = callback_data->wrapper;
      return self->dispatch (callback_data->node->get_slot ());
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
    return 0;
  }

  auto
  Source::destroy_notify_callback2 (void* data) -> void
  {
    if (data)
    {
      Source* const self = static_cast<Source*> (data);
      if (--self->keep_wrapper_ == 0)
      {
        self->gobject_ = nullptr;

        delete self;
      }
    }
  }

  auto
  Source::attach_signal_source (const sigc::slot_base& slot,
                                const int priority,
                                GSource* source,
                                GMainContext* context,
                                const GSourceFunc callback_func) -> sigc::connection
  {
    SourceConnectionNode* const conn_node = new SourceConnectionNode (slot);
    const sigc::connection connection (*conn_node->get_slot ());

    if (priority != G_PRIORITY_DEFAULT)
      g_source_set_priority (source, priority);

    g_source_set_callback (source,
                           callback_func,
                           conn_node,
                           &glibmm_source_destroy_notify_callback);

    conn_node->install (source);
    g_source_attach (source, context);
    g_source_unref (source);

    return connection;
  }

  auto
  Source::get_slot_from_connection_node (void* data) -> sigc::slot_base*
  {
    return static_cast<SourceConnectionNode*> (data)->get_slot ();
  }

  auto
  Source::get_slot_from_callback_data (void* data) -> sigc::slot_base*
  {
    const SourceCallbackData* const callback_data =
        static_cast<SourceCallbackData*> (data);
    g_return_val_if_fail (callback_data->node != nullptr, nullptr);
    return callback_data->node->get_slot ();
  }

  auto
  TimeoutSource::create (const unsigned int interval) -> RefPtr<TimeoutSource>
  {
    return glib::make_refptr_for_instance<TimeoutSource> (
        new TimeoutSource (interval));
  }

  auto
  TimeoutSource::connect (const sigc::slot<bool ()>& slot) -> sigc::connection
  {
    return connect_generic (slot);
  }

  TimeoutSource::TimeoutSource (const unsigned int interval)
    : interval_ (interval)
  {
    expiration_ = get_time () + ms2us (interval_);
  }

  TimeoutSource::~TimeoutSource () noexcept = default;

  auto
  TimeoutSource::prepare (int& timeout) -> bool
  {
    const gint64 remaining = expiration_ - get_time ();

    if (remaining <= 0)
    {
      timeout = 0;
    }
    else
    {
      timeout = std::min<gint64> (G_MAXINT, remaining / 1000);

      if (remaining > ms2us (interval_))
      {
        expiration_ = get_time () + ms2us (interval_);
        timeout = std::min<unsigned int> (G_MAXINT, interval_);
      }
    }

    return timeout == 0;
  }

  auto
  TimeoutSource::check () -> bool
  {
    return expiration_ <= get_time ();
  }

  auto
  TimeoutSource::dispatch (sigc::slot_base* slot) -> bool
  {
    const bool again = (*static_cast<sigc::slot<bool ()>*> (slot)) ();

    if (again)
      expiration_ = get_time () + ms2us (interval_);

    return again;
  }

  auto
  IdleSource::create () -> RefPtr<IdleSource>
  {
    return glib::make_refptr_for_instance<IdleSource> (new IdleSource ());
  }

  auto
  IdleSource::connect (const sigc::slot<bool ()>& slot) -> sigc::connection
  {
    return connect_generic (slot);
  }

  IdleSource::IdleSource ()
  {
    set_priority (PRIORITY_DEFAULT_IDLE);
  }

  IdleSource::~IdleSource () noexcept = default;

  auto
  IdleSource::prepare (int& timeout) -> bool
  {
    timeout = 0;
    return true;
  }

  auto
  IdleSource::check () -> bool
  {
    return true;
  }

  auto
  IdleSource::dispatch (sigc::slot_base* slot) -> bool
  {
    return (*static_cast<sigc::slot<bool ()>*> (slot)) ();
  }

  auto
  IOSource::create (const PollFD::fd_t fd, const IOCondition condition) -> RefPtr<IOSource>
  {
    return glib::make_refptr_for_instance<IOSource> (
        new IOSource (fd, condition));
  }

  auto
  IOSource::create (const RefPtr<IOChannel>& channel,
                    const IOCondition condition) -> RefPtr<IOSource>
  {
    return glib::make_refptr_for_instance<IOSource> (
        new IOSource (channel, condition));
  }

  auto
  IOSource::create (GIOChannel* channel, const IOCondition condition) -> RefPtr<IOSource>
  {
    return glib::make_refptr_for_instance<IOSource> (
        new IOSource (channel, condition));
  }

  auto
  IOSource::connect (const sigc::slot<bool (IOCondition)>& slot) -> sigc::connection
  {
    return connect_generic (slot);
  }

  IOSource::IOSource (const PollFD::fd_t fd, const IOCondition condition)
    : poll_fd_ (fd, condition)
  {
    add_poll (poll_fd_);
  }

  IOSource::IOSource (const RefPtr<IOChannel>& channel, IOCondition condition)
    : Source (
          g_io_create_watch (channel->gobj (), (GIOCondition) condition),
          glib::function_pointer_cast<GSourceFunc> (&glibmm_iosource_callback))
  {
  }

  IOSource::IOSource (GIOChannel* channel, IOCondition condition)
    : Source (
          g_io_create_watch (channel, (GIOCondition) condition),
          glib::function_pointer_cast<GSourceFunc> (&glibmm_iosource_callback))
  {
  }

  IOSource::IOSource (GSource* cast_item, const GSourceFunc callback_func)
    : Source (cast_item, callback_func)
  {
  }

  IOSource::~IOSource () noexcept = default;

  auto
  IOSource::prepare (int& timeout) -> bool
  {
    timeout = -1;
    return false;
  }

  auto
  IOSource::check () -> bool
  {
    return static_cast<int> (poll_fd_.get_revents () &
                             poll_fd_.get_events ()) != 0;
  }

  auto
  IOSource::dispatch (sigc::slot_base* slot) -> bool
  {
    return (*static_cast<sigc::slot<bool (IOCondition)>*> (slot)) (
        poll_fd_.get_revents ());
  }

} // namespace glib
