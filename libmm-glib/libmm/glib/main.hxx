// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MAIN_H
#define _GLIBMM_MAIN_H

#include <atomic>
#include <cstddef>
#include <libmm/glib/enums.hxx>
#include <libmm/glib/iochannel.hxx>
#include <libmm/glib/priorities.hxx>
#include <libmm/glib/refptr.hxx>
#include <sigc++/sigc++.h>
#include <vector>

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT PollFD
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

  class LIBMM_GLIB_SYMEXPORT SignalTimeout
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

  class LIBMM_GLIB_SYMEXPORT SignalIdle
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

  class LIBMM_GLIB_SYMEXPORT SignalIO
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
             const glib::RefPtr<IOChannel>& channel,
             IOCondition condition,
             int priority = PRIORITY_DEFAULT) -> sigc::connection;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalIO&) -> SignalIO& = delete;
  };

  class LIBMM_GLIB_SYMEXPORT SignalChildWatch
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

  LIBMM_GLIB_SYMEXPORT
  auto
  signal_timeout () -> SignalTimeout;

  LIBMM_GLIB_SYMEXPORT
  auto
  signal_idle () -> SignalIdle;

  LIBMM_GLIB_SYMEXPORT
  auto
  signal_io () -> SignalIO;

  LIBMM_GLIB_SYMEXPORT
  auto
  signal_child_watch () -> SignalChildWatch;

  class LIBMM_GLIB_SYMEXPORT MainContext
  {
  public:
    using CppObjectType = glib::MainContext;
    using BaseObjectType = GMainContext;

    MainContext (const MainContext& other) = delete;
    auto
    operator= (const MainContext& other) -> MainContext& = delete;

    static auto
    create () -> glib::RefPtr<MainContext>;

    static auto
    create (MainContextFlags flags) -> glib::RefPtr<MainContext>;

    static auto
    get_default () -> glib::RefPtr<MainContext>;

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
    get_thread_default () -> glib::RefPtr<MainContext>;

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

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GMainContext* gobject, bool take_copy = false) -> glib::RefPtr<MainContext>;

  class LIBMM_GLIB_SYMEXPORT MainLoop
  {
  public:
    using CppObjectType = glib::MainLoop;
    using BaseObjectType = GMainLoop;

    static auto
    create (bool is_running = false) -> glib::RefPtr<MainLoop>;
    static auto
    create (const glib::RefPtr<MainContext>& context, bool is_running = false)
        -> glib::RefPtr<MainLoop>;

    auto
    run () -> void;

    auto
    quit () -> void;

    auto
    is_running () -> bool;

    auto
    get_context () -> glib::RefPtr<MainContext>;

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

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GMainLoop* gobject, bool take_copy = false) -> glib::RefPtr<MainLoop>;

  class Source
  {
  public:
    using CppObjectType = glib::Source;
    using BaseObjectType = GSource;

    Source (const Source&) = delete;
    auto
    operator= (const Source&) -> Source& = delete;

    LIBMM_GLIB_SYMEXPORT static auto
    create () -> glib::RefPtr<Source>;

    LIBMM_GLIB_SYMEXPORT auto
    attach (const glib::RefPtr<MainContext>& context) -> unsigned int;

    LIBMM_GLIB_SYMEXPORT auto
    attach () -> unsigned int;

    LIBMM_GLIB_SYMEXPORT auto
    destroy () -> void;

    LIBMM_GLIB_SYMEXPORT auto
    set_priority (int priority) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    get_priority () const -> int;

    LIBMM_GLIB_SYMEXPORT auto
    set_can_recurse (bool can_recurse) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    get_can_recurse () const -> bool;

    LIBMM_GLIB_SYMEXPORT auto
    get_id () const -> unsigned int;

    LIBMM_GLIB_SYMEXPORT auto
    get_context () -> glib::RefPtr<MainContext>;

    LIBMM_GLIB_SYMEXPORT auto
    gobj () -> GSource*
    {
      return gobject_;
    }

    LIBMM_GLIB_SYMEXPORT auto
    gobj () const -> const GSource*
    {
      return gobject_;
    }

    LIBMM_GLIB_SYMEXPORT auto
    gobj_copy () const -> GSource*;

    LIBMM_GLIB_SYMEXPORT auto
    reference () const -> void;
    LIBMM_GLIB_SYMEXPORT auto
    unreference () const -> void;

  protected:
    LIBMM_GLIB_SYMEXPORT
    Source ();

    LIBMM_GLIB_SYMEXPORT
    Source (GSource* cast_item, GSourceFunc callback_func);

    LIBMM_GLIB_SYMEXPORT virtual ~Source () noexcept;

    LIBMM_GLIB_SYMEXPORT auto
    connect_generic (const sigc::slot_base& slot) -> sigc::connection;

    LIBMM_GLIB_SYMEXPORT auto
    add_poll (PollFD& poll_fd) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    remove_poll (PollFD& poll_fd) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    get_time () const -> gint64;

    LIBMM_GLIB_SYMEXPORT virtual auto
    prepare (int& timeout) -> bool = 0;
    LIBMM_GLIB_SYMEXPORT virtual auto
    check () -> bool = 0;
    LIBMM_GLIB_SYMEXPORT virtual auto
    dispatch (sigc::slot_base* slot) -> bool = 0;

  private:
    GSource* gobject_;

    mutable std::atomic_int ref_count_{1};

    std::atomic_int keep_wrapper_{2};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    LIBMM_GLIB_SYMEXPORT static inline auto
    get_wrapper (GSource* source) -> Source*;

    static const GSourceFuncs vfunc_table_;

    LIBMM_GLIB_SYMEXPORT static auto
    prepare_vfunc (GSource* source, int* timeout) -> gboolean;
    LIBMM_GLIB_SYMEXPORT static auto
    check_vfunc (GSource* source) -> gboolean;
    LIBMM_GLIB_SYMEXPORT static auto
    dispatch_vfunc (GSource* source, GSourceFunc callback, void* user_data)
        -> gboolean;

  public:
    LIBMM_GLIB_SYMEXPORT static auto
    destroy_notify_callback2 (void* data) -> void;

    LIBMM_GLIB_SYMEXPORT static auto
    attach_signal_source (const sigc::slot_base& slot,
                          int priority,
                          GSource* source,
                          GMainContext* context,
                          GSourceFunc callback_func) -> sigc::connection;

    LIBMM_GLIB_SYMEXPORT static auto
    get_slot_from_connection_node (void* data) -> sigc::slot_base*;

    LIBMM_GLIB_SYMEXPORT static auto
    get_slot_from_callback_data (void* data) -> sigc::slot_base*;
#endif
  };

  class TimeoutSource : public glib::Source
  {
  public:
    using CppObjectType = glib::TimeoutSource;

    LIBMM_GLIB_SYMEXPORT static auto
    create (unsigned int interval) -> glib::RefPtr<TimeoutSource>;
    LIBMM_GLIB_SYMEXPORT auto
    connect (const sigc::slot<bool ()>& slot) -> sigc::connection;

  protected:
    LIBMM_GLIB_SYMEXPORT explicit TimeoutSource (unsigned int interval);
    LIBMM_GLIB_SYMEXPORT ~TimeoutSource () noexcept override;

    LIBMM_GLIB_SYMEXPORT auto
    prepare (int& timeout) -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    check () -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    dispatch (sigc::slot_base* slot) -> bool override;

  private:
    gint64 expiration_;
    unsigned int interval_;
  };

  class IdleSource : public glib::Source
  {
  public:
    using CppObjectType = glib::IdleSource;

    LIBMM_GLIB_SYMEXPORT static auto
    create () -> glib::RefPtr<IdleSource>;
    LIBMM_GLIB_SYMEXPORT auto
    connect (const sigc::slot<bool ()>& slot) -> sigc::connection;

  protected:
    LIBMM_GLIB_SYMEXPORT
    IdleSource ();
    LIBMM_GLIB_SYMEXPORT ~IdleSource () noexcept override;

    LIBMM_GLIB_SYMEXPORT auto
    prepare (int& timeout) -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    check () -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    dispatch (sigc::slot_base* slot_data) -> bool override;
  };

  class IOSource : public glib::Source
  {
  public:
    using CppObjectType = glib::IOSource;

    LIBMM_GLIB_SYMEXPORT static auto
    create (PollFD::fd_t fd, IOCondition condition) -> glib::RefPtr<IOSource>;
    LIBMM_GLIB_SYMEXPORT static auto
    create (const glib::RefPtr<IOChannel>& channel, IOCondition condition)
        -> glib::RefPtr<IOSource>;
    LIBMM_GLIB_SYMEXPORT auto
    connect (const sigc::slot<bool (IOCondition)>& slot) -> sigc::connection;

  protected:
    LIBMM_GLIB_SYMEXPORT
    IOSource (PollFD::fd_t fd, IOCondition condition);
    LIBMM_GLIB_SYMEXPORT
    IOSource (const glib::RefPtr<IOChannel>& channel, IOCondition condition);

    LIBMM_GLIB_SYMEXPORT
    IOSource (GSource* cast_item, GSourceFunc callback_func);

    LIBMM_GLIB_SYMEXPORT ~IOSource () noexcept override;

    LIBMM_GLIB_SYMEXPORT auto
    prepare (int& timeout) -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    check () -> bool override;
    LIBMM_GLIB_SYMEXPORT auto
    dispatch (sigc::slot_base* slot) -> bool override;

  private:
    friend LIBMM_GLIB_SYMEXPORT IOChannel;

    LIBMM_GLIB_SYMEXPORT static auto
    create (GIOChannel* channel, IOCondition condition)
        -> glib::RefPtr<IOSource>;

    LIBMM_GLIB_SYMEXPORT
    IOSource (GIOChannel* channel, IOCondition condition);

    PollFD poll_fd_;
  };

} // namespace glib

#endif
