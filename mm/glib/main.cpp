/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/main.hpp>
#include <mm/glib/exceptionhandler.hpp>
#include <mm/glib/wrap.hpp>
#include <mm/glib/iochannel.hpp>
#include <mm/glib/utility.hpp>
#include <algorithm>

namespace
{
// Convert an interval from milliseconds to microseconds,
// suitable for adding to Source::get_time().
inline auto ms2us(unsigned int ms) -> gint64
{
  return static_cast<gint64>(ms) * 1000;
}

class SourceConnectionNode : public sigc::notifiable
{
public:
  explicit inline SourceConnectionNode(const sigc::slot_base& slot);

  static void notify(sigc::notifiable* data);
  static void destroy_notify_callback(sigc::notifiable* data);

  inline void install(GSource* source);
  inline auto get_slot() -> sigc::slot_base*;

private:
  sigc::slot_base slot_;
  GSource* source_;
};

inline SourceConnectionNode::SourceConnectionNode(const sigc::slot_base& slot)
: slot_(slot), source_(nullptr)
{
  slot_.set_parent(this, &SourceConnectionNode::notify);
}

void
SourceConnectionNode::notify(sigc::notifiable* data)
{
  SourceConnectionNode* const self = static_cast<SourceConnectionNode*>(data);

  // if there is no object, this call was triggered from destroy_notify_handler(),
  // because we set self->source_ to nullptr there:
  if (self->source_)
  {
    GSource* s = self->source_;
    self->source_ = nullptr;
    g_source_destroy(s);

    // Destroying the object triggers execution of destroy_notify_handler(),
    // either immediately or later, so we leave that to do the deletion.
  }
}

// static
void
SourceConnectionNode::destroy_notify_callback(sigc::notifiable* data)
{
  SourceConnectionNode* const self = static_cast<SourceConnectionNode*>(data);

  if (self)
  {
    // The GLib side is disconnected now, thus the GSource* is no longer valid.
    self->source_ = nullptr;

    delete self;
  }
}

inline void
SourceConnectionNode::install(GSource* source)
{
  source_ = source;
}

inline auto
SourceConnectionNode::get_slot() -> sigc::slot_base*
{
  return &slot_;
}

/* We use the callback data member of GSource to store both a pointer to our
 * wrapper and a pointer to the connection node that is currently being used.
 * The one and only SourceCallbackData object of a Glib::Source is constructed
 * in the ctor of Glib::Source and destroyed when the GSource object is destroyed,
 * which may occur before the reference counter of the GSource object reaches zero!
 */
struct SourceCallbackData
{
  explicit inline SourceCallbackData(Glib::Source* wrapper_);

  void set_node(SourceConnectionNode* node_);

  static void destroy_notify_callback(void* data);

  Glib::Source* wrapper;
  SourceConnectionNode* node;
};

inline SourceCallbackData::SourceCallbackData(Glib::Source* wrapper_)
: wrapper(wrapper_), node(nullptr)
{
}

void
SourceCallbackData::set_node(SourceConnectionNode* node_)
{
  if (node)
    SourceConnectionNode::destroy_notify_callback(node);

  node = node_;
}

// static
void
SourceCallbackData::destroy_notify_callback(void* data)
{
  SourceCallbackData* const self = static_cast<SourceCallbackData*>(data);

  if (self->node)
    SourceConnectionNode::destroy_notify_callback(self->node);

  // destroy_notify_callback2() does nothing if self->wrapper == nullptr.
  Glib::Source::destroy_notify_callback2(self->wrapper);

  delete self;
}

/* Retrieve the callback data from a wrapped GSource object.
 */
auto
glibmm_source_get_callback_data(GSource* source) -> SourceCallbackData*
{
  /* There is race between iteration of sources in main loop
   * that checks whether they are still active and source
   * destruction happening in other threads.
   */
  gpointer callback_data = source->callback_data;
  GSourceCallbackFuncs* callback_funcs = source->callback_funcs;

  g_return_val_if_fail(callback_funcs != nullptr, nullptr);

  if (g_source_is_destroyed(source))
    return nullptr;

  GSourceFunc func;
  void* user_data = nullptr;

  // Retrieve the callback function and data.
  (*callback_funcs->get)(callback_data, source, &func, &user_data);

  return static_cast<SourceCallbackData*>(user_data);
}

/* Glib::Source doesn't use the callback function installed with
 * g_source_set_callback().  Instead, it invokes the sigc++ slot
 * directly from dispatch_vfunc(), which is both simpler and more
 * efficient.
 * For correctness, provide a pointer to this dummy callback rather
 * than some random pointer.  That also allows for sanity checks
 * here as well as in Source::dispatch_vfunc().
 */
auto
glibmm_dummy_source_callback(void*) -> gboolean
{
  g_assert_not_reached();
  return 0;
}

/* Only used by SignalTimeout::connect(), SignalTimeout::connect_seconds()
 * and SignalIdle::connect(). These don't use Glib::Source, to avoid the
 * unnecessary overhead of a completely unused wrapper object.
 */
auto
glibmm_source_callback(void* data) -> gboolean
{
  SourceConnectionNode* const conn_data = static_cast<SourceConnectionNode*>(data);

  try
  {
    // Recreate the specific slot from the generic slot node.
    return (*static_cast<sigc::slot<bool()>*>(conn_data->get_slot()))();
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

/* Only used by SignalTimeout::connect_once(), SignalTimeout::connect_seconds_once()
 * and SignalIdle::connect_once(). These don't use Glib::Source, to avoid the
 * unnecessary overhead of a completely unused wrapper object.
 */
auto
glibmm_source_callback_once(void* data) -> gboolean
{
  SourceConnectionNode* const conn_data = static_cast<SourceConnectionNode*>(data);

  try
  {
    // Recreate the specific slot from the generic slot node.
    (*static_cast<sigc::slot<void()>*>(conn_data->get_slot()))();
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0; // Destroy the event source after one call
}

void
glibmm_source_destroy_notify_callback(void* data)
{
  SourceConnectionNode* const conn_data = static_cast<SourceConnectionNode*>(data);
  SourceConnectionNode::destroy_notify_callback(conn_data);
}

auto
glibmm_iosource_callback(GIOChannel*, GIOCondition condition, void* data) -> gboolean
{
  SourceCallbackData* const callback_data = static_cast<SourceCallbackData*>(data);
  g_return_val_if_fail(callback_data->node != nullptr, 0);

  try
  {
    // Recreate the specific slot from the generic slot node.
    return (*static_cast<sigc::slot<bool(Glib::IOCondition)>*>(callback_data->node->get_slot()))(
      (Glib::IOCondition)condition);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

/* Only used by SignalChildWatch::connect().
 * These don't use Glib::Source, to avoid the unnecessary overhead
 * of a completely unused wrapper object.
 */
auto
glibmm_child_watch_callback(GPid pid, gint child_status, void* data) -> gboolean
{
  SourceConnectionNode* const conn_data = static_cast<SourceConnectionNode*>(data);

  try
  {
    // Recreate the specific slot from the generic slot node.
    (*static_cast<sigc::slot<void(GPid, int)>*>(conn_data->get_slot()))(pid, child_status);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

void
glibmm_signal_connect_once(
  const sigc::slot<void()>& slot, int priority, GSource* source, GMainContext* context)
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(source, &glibmm_source_callback_once, conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context);
  g_source_unref(source); // GMainContext holds a reference
}

auto
glibmm_main_context_invoke_callback(void* data) -> gboolean
{
  sigc::slot_base* const slot = reinterpret_cast<sigc::slot_base*>(data);

  try
  {
    // Recreate the specific slot from the generic slot node.
    return (*static_cast<sigc::slot<bool()>*>(slot))();
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

void
glibmm_main_context_invoke_destroy_notify_callback(void* data)
{
  sigc::slot_base* const slot = reinterpret_cast<sigc::slot_base*>(data);
  delete slot;
}

} // anonymous namespace

namespace Glib
{

/**** Glib::PollFD *********************************************************/

PollFD::PollFD()
{
  gobject_.fd = 0;
  gobject_.events = 0;
  gobject_.revents = 0;
}

PollFD::PollFD(PollFD::fd_t fd)
{
  gobject_.fd = fd;
  gobject_.events = 0;
  gobject_.revents = 0;
}

PollFD::PollFD(PollFD::fd_t fd, IOCondition events)
{
  gobject_.fd = fd;
  gobject_.events = static_cast<decltype(gobject_.events)>(events);
  gobject_.revents = 0;
}

/**** Glib::SignalTimeout **************************************************/

inline SignalTimeout::SignalTimeout(GMainContext* context) : context_(context)
{
}

/* Note that this is our equivalent of g_timeout_add(). */
auto
SignalTimeout::connect(const sigc::slot<bool()>& slot, unsigned int interval, int priority) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  GSource* const source = g_timeout_source_new(interval);

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(
    source, &glibmm_source_callback, conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context_);
  g_source_unref(source); // GMainContext holds a reference

  return connection;
}

void
SignalTimeout::connect_once(const sigc::slot<void()>& slot, unsigned int interval, int priority)
{
  GSource* const source = g_timeout_source_new(interval);
  glibmm_signal_connect_once(slot, priority, source, context_);
}

/* Note that this is our equivalent of g_timeout_add_seconds(). */
auto
SignalTimeout::connect_seconds(const sigc::slot<bool()>& slot, unsigned int interval, int priority) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  GSource* const source = g_timeout_source_new_seconds(interval);

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(
    source, &glibmm_source_callback, conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context_);
  g_source_unref(source); // GMainContext holds a reference

  return connection;
}

void
SignalTimeout::connect_seconds_once(
  const sigc::slot<void()>& slot, unsigned int interval, int priority)
{
  GSource* const source = g_timeout_source_new_seconds(interval);
  glibmm_signal_connect_once(slot, priority, source, context_);
}

auto
signal_timeout() -> SignalTimeout
{
  return SignalTimeout(nullptr); // nullptr means default context
}

/**** Glib::SignalIdle *****************************************************/

inline SignalIdle::SignalIdle(GMainContext* context) : context_(context)
{
}

auto
SignalIdle::connect(const sigc::slot<bool()>& slot, int priority) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  GSource* const source = g_idle_source_new();

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(
    source, &glibmm_source_callback, conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context_);
  g_source_unref(source); // GMainContext holds a reference

  return connection;
}

void
SignalIdle::connect_once(const sigc::slot<void()>& slot, int priority)
{
  GSource* const source = g_idle_source_new();
  glibmm_signal_connect_once(slot, priority, source, context_);
}

auto
signal_idle() -> SignalIdle
{
  return SignalIdle(nullptr); // nullptr means default context
}

/**** Glib::SignalIO *******************************************************/

inline SignalIO::SignalIO(GMainContext* context) : context_(context)
{
}

auto
SignalIO::connect(
  const sigc::slot<bool(IOCondition)>& slot, PollFD::fd_t fd, IOCondition condition, int priority) -> sigc::connection
{
  const auto source = IOSource::create(fd, condition);

  if (priority != G_PRIORITY_DEFAULT)
    source->set_priority(priority);

  const sigc::connection connection = source->connect(slot);

  g_source_attach(source->gobj(), context_);

  return connection;
}

auto
SignalIO::connect(const sigc::slot<bool(IOCondition)>& slot, const Glib::RefPtr<IOChannel>& channel,
  IOCondition condition, int priority) -> sigc::connection
{
  const auto source = IOSource::create(channel, condition);

  if (priority != G_PRIORITY_DEFAULT)
    source->set_priority(priority);

  const sigc::connection connection = source->connect(slot);

  g_source_attach(source->gobj(), context_);

  return connection;
}

auto
signal_io() -> SignalIO
{
  return SignalIO(nullptr); // nullptr means default context
}

/**** Glib::SignalChildWatch **************************************************/

inline SignalChildWatch::SignalChildWatch(GMainContext* context) : context_(context)
{
}

auto
SignalChildWatch::connect(const sigc::slot<void(GPid, int)>& slot, GPid pid, int priority) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  GSource* const source = g_child_watch_source_new(pid);

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(source, Glib::function_pointer_cast<GSourceFunc>(&glibmm_child_watch_callback),
    conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context_);
  g_source_unref(source); // GMainContext holds a reference

  return connection;
}

auto
signal_child_watch() -> SignalChildWatch
{
  return SignalChildWatch(nullptr); // nullptr means default context
}

/**** Glib::MainContext ****************************************************/

// static
auto
MainContext::create() -> Glib::RefPtr<MainContext>
{
  return Glib::make_refptr_for_instance<MainContext>(reinterpret_cast<MainContext*>(g_main_context_new()));
}

// static
auto
MainContext::create(MainContextFlags flags) -> Glib::RefPtr<MainContext>
{
  return Glib::make_refptr_for_instance<MainContext>(
    reinterpret_cast<MainContext*>(g_main_context_new_with_flags(static_cast<GMainContextFlags>(flags))));
}

// static
auto
MainContext::get_default() -> Glib::RefPtr<MainContext>
{
  return Glib::wrap(g_main_context_default(), true);
}

auto
MainContext::iteration(bool may_block) -> bool
{
  return g_main_context_iteration(gobj(), may_block);
}

auto
MainContext::pending() -> bool
{
  return g_main_context_pending(gobj());
}

void
MainContext::wakeup()
{
  g_main_context_wakeup(gobj());
}

auto
MainContext::acquire() -> bool
{
  return g_main_context_acquire(gobj());
}

void
MainContext::release()
{
  g_main_context_release(gobj());
}

auto
MainContext::prepare(int& priority) -> bool
{
  return g_main_context_prepare(gobj(), &priority);
}

auto
MainContext::prepare() -> bool
{
  return g_main_context_prepare(gobj(), nullptr);
}

void
MainContext::query(int max_priority, int& timeout, std::vector<PollFD>& fds)
{
  if (fds.empty())
    fds.resize(8); // rather bogus number, but better than 0

  for (;;)
  {
    const int size_before = fds.size();
    const int size_needed = g_main_context_query(
      gobj(), max_priority, &timeout, reinterpret_cast<GPollFD*>(&fds.front()), size_before);

    fds.resize(size_needed);

    if (size_needed <= size_before)
      break;
  }
}

auto
MainContext::check(int max_priority, std::vector<PollFD>& fds) -> bool
{
  if (!fds.empty())
    return g_main_context_check(
      gobj(), max_priority, reinterpret_cast<GPollFD*>(&fds.front()), fds.size());
  else
    return false;
}

void
MainContext::dispatch()
{
  g_main_context_dispatch(gobj());
}

void
MainContext::set_poll_func(GPollFunc poll_func)
{
  g_main_context_set_poll_func(gobj(), poll_func);
}

GPollFunc
MainContext::get_poll_func()
{
  return g_main_context_get_poll_func(gobj());
}

void
MainContext::add_poll(PollFD& fd, int priority)
{
  g_main_context_add_poll(gobj(), fd.gobj(), priority);
}

void
MainContext::remove_poll(PollFD& fd)
{
  g_main_context_remove_poll(gobj(), fd.gobj());
}

void
MainContext::push_thread_default()
{
  g_main_context_push_thread_default(gobj());
}

void
MainContext::pop_thread_default()
{
  g_main_context_pop_thread_default(gobj());
}

// static
auto
MainContext::get_thread_default() -> Glib::RefPtr<MainContext>
{
  // g_main_context_ref_thread_default() gives us a ref.
  return Glib::wrap(g_main_context_ref_thread_default(), false);
}

void
MainContext::invoke(const sigc::slot<bool()>& slot, int priority)
{
  // Make a copy of slot on the heap.
  sigc::slot_base* const slot_copy = new sigc::slot<bool()>(slot);

  g_main_context_invoke_full(gobj(), priority, glibmm_main_context_invoke_callback, slot_copy,
    glibmm_main_context_invoke_destroy_notify_callback);
}

auto
MainContext::signal_timeout() -> SignalTimeout
{
  return SignalTimeout(gobj());
}

auto
MainContext::signal_idle() -> SignalIdle
{
  return SignalIdle(gobj());
}

auto
MainContext::signal_io() -> SignalIO
{
  return SignalIO(gobj());
}

auto
MainContext::signal_child_watch() -> SignalChildWatch
{
  return SignalChildWatch(gobj());
}

void
MainContext::reference() const
{
  g_main_context_ref(reinterpret_cast<GMainContext*>(const_cast<MainContext*>(this)));
}

void
MainContext::unreference() const
{
  g_main_context_unref(reinterpret_cast<GMainContext*>(const_cast<MainContext*>(this)));
}

auto
MainContext::gobj() -> GMainContext*
{
  return reinterpret_cast<GMainContext*>(this);
}

auto
MainContext::gobj() const -> const GMainContext*
{
  return reinterpret_cast<const GMainContext*>(this);
}

auto
MainContext::gobj_copy() const -> GMainContext*
{
  reference();
  return const_cast<GMainContext*>(gobj());
}

auto
wrap(GMainContext* gobject, bool take_copy) -> Glib::RefPtr<MainContext>
{
  if (take_copy && gobject)
    g_main_context_ref(gobject);

  return Glib::make_refptr_for_instance<MainContext>(reinterpret_cast<MainContext*>(gobject));
}

/**** Glib::MainLoop *******************************************************/

auto
MainLoop::create(bool is_running) -> Glib::RefPtr<MainLoop>
{
  return Glib::make_refptr_for_instance<MainLoop>(reinterpret_cast<MainLoop*>(g_main_loop_new(nullptr, is_running)));
}

auto
MainLoop::create(const Glib::RefPtr<MainContext>& context, bool is_running) -> Glib::RefPtr<MainLoop>
{
  return Glib::make_refptr_for_instance<MainLoop>(
    reinterpret_cast<MainLoop*>(g_main_loop_new(Glib::unwrap(context), is_running)));
}

void
MainLoop::run()
{
  g_main_loop_run(gobj());
}

void
MainLoop::quit()
{
  g_main_loop_quit(gobj());
}

auto
MainLoop::is_running() -> bool
{
  return g_main_loop_is_running(gobj());
}

auto
MainLoop::get_context() -> Glib::RefPtr<MainContext>
{
  return Glib::wrap(g_main_loop_get_context(gobj()), true);
}

// static:
auto
MainLoop::depth() -> int
{
  return g_main_depth();
}

void
MainLoop::reference() const
{
  g_main_loop_ref(reinterpret_cast<GMainLoop*>(const_cast<MainLoop*>(this)));
}

void
MainLoop::unreference() const
{
  g_main_loop_unref(reinterpret_cast<GMainLoop*>(const_cast<MainLoop*>(this)));
}

auto
MainLoop::gobj() -> GMainLoop*
{
  return reinterpret_cast<GMainLoop*>(this);
}

auto
MainLoop::gobj() const -> const GMainLoop*
{
  return reinterpret_cast<const GMainLoop*>(this);
}

auto
MainLoop::gobj_copy() const -> GMainLoop*
{
  reference();
  return const_cast<GMainLoop*>(gobj());
}

auto
wrap(GMainLoop* gobject, bool take_copy) -> Glib::RefPtr<MainLoop>
{
  if (take_copy && gobject)
    g_main_loop_ref(gobject);

  return Glib::make_refptr_for_instance<MainLoop>(reinterpret_cast<MainLoop*>(gobject));
}

/**** Glib::Source *********************************************************/

// static
const GSourceFuncs Source::vfunc_table_ = {
  &Source::prepare_vfunc, &Source::check_vfunc, &Source::dispatch_vfunc,
  // We can't use finalize_vfunc because there is no way
  // to store a pointer to our wrapper anywhere in GSource so
  // that it persists until finalize_vfunc would be called from here.
  nullptr, // finalize_vfunc
  nullptr, // closure_callback
  nullptr, // closure_marshal
};

auto
Source::attach(const Glib::RefPtr<MainContext>& context) -> unsigned int
{
  return g_source_attach(gobject_, Glib::unwrap(context));
}

auto
Source::attach() -> unsigned int
{
  return g_source_attach(gobject_, nullptr);
}

void
Source::destroy()
{
  g_source_destroy(gobject_);
}

void
Source::set_priority(int priority)
{
  g_source_set_priority(gobject_, priority);
}

auto
Source::get_priority() const -> int
{
  return g_source_get_priority(gobject_);
}

void
Source::set_can_recurse(bool can_recurse)
{
  g_source_set_can_recurse(gobject_, can_recurse);
}

auto
Source::get_can_recurse() const -> bool
{
  return g_source_get_can_recurse(gobject_);
}

auto
Source::get_id() const -> unsigned int
{
  return g_source_get_id(gobject_);
}

auto
Source::get_context() -> Glib::RefPtr<MainContext>
{
  return Glib::wrap(g_source_get_context(gobject_), true);
}

auto
Source::gobj_copy() const -> GSource*
{
  return g_source_ref(gobject_);
}

void
Source::reference() const
{
  ++ref_count_;
}

void
Source::unreference() const
{
  if (--ref_count_ == 0)
  {
    GSource* const tmp_gobject = gobject_;

    destroy_notify_callback2(const_cast<Source*>(this));

    // Drop the one and only GSource reference held by the C++ wrapper.
    // If the GSource instance is attached to a main context, the GMainContext
    // holds a reference until the source is detached (destroyed).
    g_source_unref(tmp_gobject);
  }
}

Source::Source() : gobject_(g_source_new(const_cast<GSourceFuncs*>(&vfunc_table_), sizeof(GSource)))
{
  g_source_set_callback(gobject_, &glibmm_dummy_source_callback,
    new SourceCallbackData(this), // our persistent callback data object
    &SourceCallbackData::destroy_notify_callback);
}

Source::Source(GSource* cast_item, GSourceFunc callback_func) : gobject_(cast_item)
{
  g_source_set_callback(gobject_, callback_func,
    new SourceCallbackData(this), // our persistent callback data object
    &SourceCallbackData::destroy_notify_callback);
}

Source::~Source() noexcept
{
  // The dtor should be invoked by destroy_notify_callback() only, which clears
  // gobject_ before deleting.  However, we might also get to this point if
  // a derived ctor threw an exception, and then we need to unref manually.

  if (gobject_)
  {
    SourceCallbackData* const data = glibmm_source_get_callback_data(gobject_);

    if (data) {
      data->wrapper = nullptr;
    }

    GSource* const tmp_gobject = gobject_;
    gobject_ = nullptr;

    g_source_unref(tmp_gobject);

    // The constructor does not add this to extra_source_data. No need to erase.
  }
}

auto
Source::connect_generic(const sigc::slot_base& slot) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  // Don't override the callback data.  Reuse the existing one
  // calling SourceCallbackData::set_node() to register conn_node.
  SourceCallbackData* const data = glibmm_source_get_callback_data(gobject_);

  if (data) {
    data->set_node(conn_node);
  }

  conn_node->install(gobject_);
  return connection;
}

void
Source::add_poll(Glib::PollFD& poll_fd)
{
  g_source_add_poll(gobject_, poll_fd.gobj());
}

void
Source::remove_poll(Glib::PollFD& poll_fd)
{
  g_source_remove_poll(gobject_, poll_fd.gobj());
}

auto
Source::get_time() const -> gint64
{
  if (g_source_get_context(const_cast<GSource*>(gobject_)))
    return g_source_get_time(const_cast<GSource*>(gobject_));
  else
    return g_get_monotonic_time();
}

inline // static
  auto
  Source::get_wrapper(GSource* source) -> Source*
{
  SourceCallbackData* const data = glibmm_source_get_callback_data(source);
  return (data) ? data->wrapper : nullptr;
}

// static
auto
Source::prepare_vfunc(GSource* source, int* timeout) -> gboolean
{
  try
  {
    Source* const self = get_wrapper(source);
    return (self) ? self->prepare(*timeout) : 0;
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}

// static
auto
Source::check_vfunc(GSource* source) -> gboolean
{
  try
  {
    Source* const self = get_wrapper(source);
    return (self) ? self->check() : 0;
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
}

// static
auto
Source::dispatch_vfunc(GSource*, GSourceFunc callback, void* user_data) -> gboolean
{
  SourceCallbackData* const callback_data = static_cast<SourceCallbackData*>(user_data);

  g_return_val_if_fail(callback == &glibmm_dummy_source_callback, 0);
  g_return_val_if_fail(callback_data != nullptr && callback_data->node != nullptr, 0);

  try
  {
    Source* const self = callback_data->wrapper;
    return self->dispatch(callback_data->node->get_slot());
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return 0;
}

// static
void
Source::destroy_notify_callback2(void* data)
{
  if (data)
  {
    Source* const self = static_cast<Source*>(data);
    if (--self->keep_wrapper_ == 0)
    {
      // gobject_ is already invalid at this point.
      self->gobject_ = nullptr;

      // No exception checking: if the dtor throws, you're out of luck anyway.
      delete self;
    }
  }
}

// static
auto
Source::attach_signal_source(const sigc::slot_base& slot, int priority, GSource* source,
  GMainContext* context, GSourceFunc callback_func) -> sigc::connection
{
  SourceConnectionNode* const conn_node = new SourceConnectionNode(slot);
  const sigc::connection connection(*conn_node->get_slot());

  if (priority != G_PRIORITY_DEFAULT)
    g_source_set_priority(source, priority);

  g_source_set_callback(
    source, callback_func, conn_node,
    &glibmm_source_destroy_notify_callback);

  conn_node->install(source);
  g_source_attach(source, context);
  g_source_unref(source); // GMainContext holds a reference

  return connection;
}

// static
auto
Source::get_slot_from_connection_node(void* data) -> sigc::slot_base*
{
  return static_cast<SourceConnectionNode*>(data)->get_slot();
}

// static
auto
Source::get_slot_from_callback_data(void* data) -> sigc::slot_base*
{
  SourceCallbackData* const callback_data = static_cast<SourceCallbackData*>(data);
  g_return_val_if_fail(callback_data->node != nullptr, nullptr);
  return callback_data->node->get_slot();
}

/**** Glib::TimeoutSource **************************************************/

// static
auto
TimeoutSource::create(unsigned int interval) -> Glib::RefPtr<TimeoutSource>
{
  return Glib::make_refptr_for_instance<TimeoutSource>(new TimeoutSource(interval));
}

auto
TimeoutSource::connect(const sigc::slot<bool()>& slot) -> sigc::connection
{
  return connect_generic(slot);
}

TimeoutSource::TimeoutSource(unsigned int interval) : interval_(interval)
{
  expiration_ = get_time() + ms2us(interval_);
}

TimeoutSource::~TimeoutSource() noexcept
{
}

auto
TimeoutSource::prepare(int& timeout) -> bool
{
  gint64 remaining = expiration_ - get_time();

  if (remaining <= 0)
  {
    // Already expired.
    timeout = 0;
  }
  else
  {
    // Set remaining milliseconds.
    timeout = std::min<gint64>(G_MAXINT, remaining / 1000);

    // Check if the system time has been set backwards. (remaining > interval)
    if (remaining > ms2us(interval_))
    {
      // Oh well.  Reset the expiration time to now + interval;
      // this at least avoids hanging for long periods of time.
      expiration_ = get_time() + ms2us(interval_);
      timeout = std::min<unsigned int>(G_MAXINT, interval_);
    }
  }

  return (timeout == 0);
}

auto
TimeoutSource::check() -> bool
{
  return expiration_ <= get_time();
}

auto
TimeoutSource::dispatch(sigc::slot_base* slot) -> bool
{
  const bool again = (*static_cast<sigc::slot<bool()>*>(slot))();

  if (again)
    expiration_ = get_time() + ms2us(interval_);

  return again;
}

/**** Glib::IdleSource *****************************************************/

// static
auto
IdleSource::create() -> Glib::RefPtr<IdleSource>
{
  return Glib::make_refptr_for_instance<IdleSource>(new IdleSource());
}

auto
IdleSource::connect(const sigc::slot<bool()>& slot) -> sigc::connection
{
  return connect_generic(slot);
}

IdleSource::IdleSource()
{
  set_priority(PRIORITY_DEFAULT_IDLE);
}

IdleSource::~IdleSource() noexcept
{
}

auto
IdleSource::prepare(int& timeout) -> bool
{
  timeout = 0;
  return true;
}

auto
IdleSource::check() -> bool
{
  return true;
}

auto
IdleSource::dispatch(sigc::slot_base* slot) -> bool
{
  return (*static_cast<sigc::slot<bool()>*>(slot))();
}

/**** Glib::IOSource *******************************************************/

// static
auto
IOSource::create(PollFD::fd_t fd, IOCondition condition) -> Glib::RefPtr<IOSource>
{
  return Glib::make_refptr_for_instance<IOSource>(new IOSource(fd, condition));
}

auto
IOSource::create(const Glib::RefPtr<IOChannel>& channel, IOCondition condition) -> Glib::RefPtr<IOSource>
{
  return Glib::make_refptr_for_instance<IOSource>(new IOSource(channel, condition));
}

auto
IOSource::create(GIOChannel* channel, IOCondition condition) -> Glib::RefPtr<IOSource>
{
  return Glib::make_refptr_for_instance<IOSource>(new IOSource(channel, condition));
}

auto
IOSource::connect(const sigc::slot<bool(IOCondition)>& slot) -> sigc::connection
{
  return connect_generic(slot);
}

IOSource::IOSource(PollFD::fd_t fd, IOCondition condition) : poll_fd_(fd, condition)
{
  add_poll(poll_fd_);
}

IOSource::IOSource(const Glib::RefPtr<IOChannel>& channel, IOCondition condition)
: Source(g_io_create_watch(channel->gobj(), (GIOCondition)condition),
    Glib::function_pointer_cast<GSourceFunc>(&glibmm_iosource_callback))
{
}

IOSource::IOSource(GIOChannel* channel, IOCondition condition)
: Source(g_io_create_watch(channel, (GIOCondition)condition),
    Glib::function_pointer_cast<GSourceFunc>(&glibmm_iosource_callback))
{
}

IOSource::IOSource(GSource* cast_item, GSourceFunc callback_func) : Source(cast_item, callback_func)
{
}

IOSource::~IOSource() noexcept
{
}

auto
IOSource::prepare(int& timeout) -> bool
{
  timeout = -1;
  return false;
}

auto
IOSource::check() -> bool
{
  return static_cast<int>(poll_fd_.get_revents() & poll_fd_.get_events()) != 0;
}

auto
IOSource::dispatch(sigc::slot_base* slot) -> bool
{
  return (*static_cast<sigc::slot<bool(IOCondition)>*>(slot))(poll_fd_.get_revents());
}

} // namespace Glib
