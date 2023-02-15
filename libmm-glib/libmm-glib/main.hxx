// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MAIN_H
#define _GLIBMM_MAIN_H

#include <atomic>
#include <cstddef>
#include <libmm-glib/enums.hxx>
#include <libmm-glib/iochannel.hxx>
#include <libmm-glib/priorities.hxx>
#include <libmm-glib/refptr.hxx>
#include <sigc++/sigc++.h>
#include <vector>

namespace Glib
{

  class GLIBMM_API PollFD
  {
  public:
    using fd_t = decltype (GPollFD::fd);

    PollFD ();
    explicit PollFD (fd_t fd);
    PollFD (fd_t fd, IOCondition events);

    auto
    set_fd (fd_t fd) -> void
    {
      gobject_.fd = fd;
    }

    auto
    get_fd () const -> fd_t
    {
      return gobject_.fd;
    }

    auto
    set_events (IOCondition events) -> void
    {
      gobject_.events = static_cast<decltype (gobject_.events)> (events);
    }

    auto
    get_events () const -> IOCondition
    {
      return static_cast<IOCondition> (gobject_.events);
    }

    auto
    set_revents (IOCondition revents) -> void
    {
      gobject_.revents = static_cast<decltype (gobject_.revents)> (revents);
    }

    auto
    get_revents () const -> IOCondition
    {
      return static_cast<IOCondition> (gobject_.revents);
    }

    auto
    gobj () -> GPollFD*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GPollFD*
    {
      return &gobject_;
    }

  private:
    GPollFD gobject_;
  };

  class GLIBMM_API SignalTimeout
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalTimeout (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<bool ()>& slot,
             unsigned int interval,
             int priority = PRIORITY_DEFAULT) -> sigc::connection;

    auto
    connect_once (const sigc::slot<void ()>& slot,
                  unsigned int interval,
                  int priority = PRIORITY_DEFAULT) -> void;

    auto
    connect_seconds (const sigc::slot<bool ()>& slot,
                     unsigned int interval,
                     int priority = PRIORITY_DEFAULT) -> sigc::connection;

    auto
    connect_seconds_once (const sigc::slot<void ()>& slot,
                          unsigned int interval,
                          int priority = PRIORITY_DEFAULT) -> void;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalTimeout&) -> SignalTimeout& = delete;
  };

  class GLIBMM_API SignalIdle
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalIdle (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<bool ()>& slot,
             int priority = PRIORITY_DEFAULT_IDLE) -> sigc::connection;

    auto
    connect_once (const sigc::slot<void ()>& slot,
                  int priority = PRIORITY_DEFAULT_IDLE) -> void;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalIdle&) -> SignalIdle& = delete;
  };

  class GLIBMM_API SignalIO
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalIO (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<bool (IOCondition)>& slot,
             PollFD::fd_t fd,
             IOCondition condition,
             int priority = PRIORITY_DEFAULT) -> sigc::connection;

    auto
    connect (const sigc::slot<bool (IOCondition)>& slot,
             const Glib::RefPtr<IOChannel>& channel,
             IOCondition condition,
             int priority = PRIORITY_DEFAULT) -> sigc::connection;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalIO&) -> SignalIO& = delete;
  };

  class GLIBMM_API SignalChildWatch
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalChildWatch (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<void (GPid, int)>& slot,
             GPid pid,
             int priority = PRIORITY_DEFAULT) -> sigc::connection;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalChildWatch&) -> SignalChildWatch& = delete;
  };

  GLIBMM_API
  auto
  signal_timeout () -> SignalTimeout;

  GLIBMM_API
  auto
  signal_idle () -> SignalIdle;

  GLIBMM_API
  auto
  signal_io () -> SignalIO;

  GLIBMM_API
  auto
  signal_child_watch () -> SignalChildWatch;

  class GLIBMM_API MainContext
  {
  public:
    using CppObjectType = Glib::MainContext;
    using BaseObjectType = GMainContext;

    MainContext (const MainContext& other) = delete;
    auto
    operator= (const MainContext& other) -> MainContext& = delete;

    static auto
    create () -> Glib::RefPtr<MainContext>;

    static auto
    create (MainContextFlags flags) -> Glib::RefPtr<MainContext>;

    static auto
    get_default () -> Glib::RefPtr<MainContext>;

    auto
    iteration (bool may_block) -> bool;

    auto
    pending () -> bool;

    auto
    wakeup () -> void;

    auto
    acquire () -> bool;

    auto
    release () -> void;

    auto
    prepare (int& priority) -> bool;

    auto
    prepare () -> bool;

    auto
    query (int max_priority, int& timeout, std::vector<PollFD>& fds) -> void;

    auto
    check (int max_priority, std::vector<PollFD>& fds) -> bool;

    auto
    dispatch () -> void;

    auto
    set_poll_func (GPollFunc poll_func) -> void;

    auto
    get_poll_func () -> GPollFunc;

    auto
    add_poll (PollFD& fd, int priority) -> void;

    auto
    remove_poll (PollFD& fd) -> void;

    auto
    push_thread_default () -> void;

    auto
    pop_thread_default () -> void;

    static auto
    get_thread_default () -> Glib::RefPtr<MainContext>;

    auto
    invoke (const sigc::slot<bool ()>& slot, int priority = PRIORITY_DEFAULT)
        -> void;

    auto
    signal_timeout () -> SignalTimeout;

    auto
    signal_idle () -> SignalIdle;

    auto
    signal_io () -> SignalIO;

    auto
    signal_child_watch () -> SignalChildWatch;

    auto
    reference () const -> void;
    auto
    unreference () const -> void;

    auto
    gobj () -> GMainContext*;
    auto
    gobj () const -> const GMainContext*;
    auto
    gobj_copy () const -> GMainContext*;

  private:
    MainContext ();
    auto
    operator delete (void*, std::size_t) -> void;
  };

  GLIBMM_API
  auto
  wrap (GMainContext* gobject, bool take_copy = false) -> Glib::RefPtr<MainContext>;

  class GLIBMM_API MainLoop
  {
  public:
    using CppObjectType = Glib::MainLoop;
    using BaseObjectType = GMainLoop;

    static auto
    create (bool is_running = false) -> Glib::RefPtr<MainLoop>;
    static auto
    create (const Glib::RefPtr<MainContext>& context, bool is_running = false)
        -> Glib::RefPtr<MainLoop>;

    auto
    run () -> void;

    auto
    quit () -> void;

    auto
    is_running () -> bool;

    auto
    get_context () -> Glib::RefPtr<MainContext>;

    static auto
    depth () -> int;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GMainLoop*;
    auto
    gobj () const -> const GMainLoop*;
    auto
    gobj_copy () const -> GMainLoop*;

  private:
    MainLoop ();
    auto
    operator delete (void*, std::size_t) -> void;

    MainLoop (const MainLoop&) = delete;
    auto
    operator= (const MainLoop&) -> MainLoop& = delete;
  };

  GLIBMM_API
  auto
  wrap (GMainLoop* gobject, bool take_copy = false) -> Glib::RefPtr<MainLoop>;

  class Source
  {
  public:
    using CppObjectType = Glib::Source;
    using BaseObjectType = GSource;

    Source (const Source&) = delete;
    auto
    operator= (const Source&) -> Source& = delete;

    GLIBMM_API static auto
    create () -> Glib::RefPtr<Source>;

    GLIBMM_API auto
    attach (const Glib::RefPtr<MainContext>& context) -> unsigned int;

    GLIBMM_API auto
    attach () -> unsigned int;

    GLIBMM_API auto
    destroy () -> void;

    GLIBMM_API auto
    set_priority (int priority) -> void;

    GLIBMM_API auto
    get_priority () const -> int;

    GLIBMM_API auto
    set_can_recurse (bool can_recurse) -> void;

    GLIBMM_API auto
    get_can_recurse () const -> bool;

    GLIBMM_API auto
    get_id () const -> unsigned int;

    GLIBMM_API auto
    get_context () -> Glib::RefPtr<MainContext>;

    GLIBMM_API auto
    gobj () -> GSource*
    {
      return gobject_;
    }

    GLIBMM_API auto
    gobj () const -> const GSource*
    {
      return gobject_;
    }

    GLIBMM_API auto
    gobj_copy () const -> GSource*;

    GLIBMM_API auto
    reference () const -> void;
    GLIBMM_API auto
    unreference () const -> void;

  protected:
    GLIBMM_API
    Source ();

    GLIBMM_API
    Source (GSource* cast_item, GSourceFunc callback_func);

    GLIBMM_API virtual ~Source () noexcept;

    GLIBMM_API auto
    connect_generic (const sigc::slot_base& slot) -> sigc::connection;

    GLIBMM_API auto
    add_poll (PollFD& poll_fd) -> void;

    GLIBMM_API auto
    remove_poll (PollFD& poll_fd) -> void;

    GLIBMM_API auto
    get_time () const -> gint64;

    GLIBMM_API virtual auto
    prepare (int& timeout) -> bool = 0;
    GLIBMM_API virtual auto
    check () -> bool = 0;
    GLIBMM_API virtual auto
    dispatch (sigc::slot_base* slot) -> bool = 0;

  private:
    GSource* gobject_;

    mutable std::atomic_int ref_count_{1};

    std::atomic_int keep_wrapper_{2};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    GLIBMM_API static inline auto
    get_wrapper (GSource* source) -> Source*;

    static const GSourceFuncs vfunc_table_;

    GLIBMM_API static auto
    prepare_vfunc (GSource* source, int* timeout) -> gboolean;
    GLIBMM_API static auto
    check_vfunc (GSource* source) -> gboolean;
    GLIBMM_API static auto
    dispatch_vfunc (GSource* source, GSourceFunc callback, void* user_data)
        -> gboolean;

  public:
    GLIBMM_API static auto
    destroy_notify_callback2 (void* data) -> void;

    GLIBMM_API static auto
    attach_signal_source (const sigc::slot_base& slot,
                          int priority,
                          GSource* source,
                          GMainContext* context,
                          GSourceFunc callback_func) -> sigc::connection;

    GLIBMM_API static auto
    get_slot_from_connection_node (void* data) -> sigc::slot_base*;

    GLIBMM_API static auto
    get_slot_from_callback_data (void* data) -> sigc::slot_base*;
#endif
  };

  class TimeoutSource : public Glib::Source
  {
  public:
    using CppObjectType = Glib::TimeoutSource;

    GLIBMM_API static auto
    create (unsigned int interval) -> Glib::RefPtr<TimeoutSource>;
    GLIBMM_API auto
    connect (const sigc::slot<bool ()>& slot) -> sigc::connection;

  protected:
    GLIBMM_API explicit TimeoutSource (unsigned int interval);
    GLIBMM_API ~TimeoutSource () noexcept override;

    GLIBMM_API auto
    prepare (int& timeout) -> bool override;
    GLIBMM_API auto
    check () -> bool override;
    GLIBMM_API auto
    dispatch (sigc::slot_base* slot) -> bool override;

  private:
    gint64 expiration_;
    unsigned int interval_;
  };

  class IdleSource : public Glib::Source
  {
  public:
    using CppObjectType = Glib::IdleSource;

    GLIBMM_API static auto
    create () -> Glib::RefPtr<IdleSource>;
    GLIBMM_API auto
    connect (const sigc::slot<bool ()>& slot) -> sigc::connection;

  protected:
    GLIBMM_API
    IdleSource ();
    GLIBMM_API ~IdleSource () noexcept override;

    GLIBMM_API auto
    prepare (int& timeout) -> bool override;
    GLIBMM_API auto
    check () -> bool override;
    GLIBMM_API auto
    dispatch (sigc::slot_base* slot_data) -> bool override;
  };

  class IOSource : public Glib::Source
  {
  public:
    using CppObjectType = Glib::IOSource;

    GLIBMM_API static auto
    create (PollFD::fd_t fd, IOCondition condition) -> Glib::RefPtr<IOSource>;
    GLIBMM_API static auto
    create (const Glib::RefPtr<IOChannel>& channel, IOCondition condition)
        -> Glib::RefPtr<IOSource>;
    GLIBMM_API auto
    connect (const sigc::slot<bool (IOCondition)>& slot) -> sigc::connection;

  protected:
    GLIBMM_API
    IOSource (PollFD::fd_t fd, IOCondition condition);
    GLIBMM_API
    IOSource (const Glib::RefPtr<IOChannel>& channel, IOCondition condition);

    GLIBMM_API
    IOSource (GSource* cast_item, GSourceFunc callback_func);

    GLIBMM_API ~IOSource () noexcept override;

    GLIBMM_API auto
    prepare (int& timeout) -> bool override;
    GLIBMM_API auto
    check () -> bool override;
    GLIBMM_API auto
    dispatch (sigc::slot_base* slot) -> bool override;

  private:
    friend GLIBMM_API IOChannel;

    GLIBMM_API static auto
    create (GIOChannel* channel, IOCondition condition)
        -> Glib::RefPtr<IOSource>;

    GLIBMM_API
    IOSource (GIOChannel* channel, IOCondition condition);

    PollFD poll_fd_;
  };

} // namespace Glib

#endif
