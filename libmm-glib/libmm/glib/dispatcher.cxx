// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/dispatcher.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/fileutils.hxx>
#include <libmm/glib/main.hxx>

#include <cerrno>
#include <fcntl.h>
#include <forward_list>
#include <glib.h>
#include <memory>
#include <utility>

#ifdef G_OS_WIN32
  #include <direct.h>
  #include <io.h>
  #include <list>
  #include <mutex>
  #include <windows.h>
#else
  #include <unistd.h>
#endif

#if defined(_tru64) && !defined(EINTR)
  #define EINTR 0
#endif

namespace glib
{
  class DispatchNotifier;
}

namespace
{

  struct DispatchNotifyData
  {
    glib::Dispatcher::Impl* dispatcher_impl;
    glib::DispatchNotifier* notifier;

    DispatchNotifyData ()
      : dispatcher_impl (nullptr),
        notifier (nullptr)
    {
    }

    DispatchNotifyData (glib::Dispatcher::Impl* d, glib::DispatchNotifier* n)
      : dispatcher_impl (d),
        notifier (n)
    {
    }
  };

  auto
  warn_failed_pipe_io (const char* what) -> void
  {
#ifdef G_OS_WIN32
    const char* const message = g_win32_error_message (GetLastError ());
#else
    const char* const message = g_strerror (errno);
#endif
    g_critical ("Error in inter-thread communication: %s() failed: %s",
                what,
                message);
  }

#ifdef G_OS_WIN32

  static auto
  fd_close_and_invalidate (HANDLE& fd) -> void
  {
    if (fd != 0)
    {
      if (!CloseHandle (fd))
        warn_failed_pipe_io ("CloseHandle");

      fd = 0;
    }
  }
#else

  void
  fd_set_close_on_exec (int fd)
  {
    const int flags = fcntl (fd, F_GETFD, 0);

    if (flags < 0 || fcntl (fd, F_SETFD, unsigned (flags) | FD_CLOEXEC) < 0)
      warn_failed_pipe_io ("fcntl");
  }

  void
  fd_close_and_invalidate (int& fd)
  {
    if (fd >= 0)
    {
      int result;

      do
        result = close (fd);
      while (G_UNLIKELY (result < 0) && errno == EINTR);

      if (G_UNLIKELY (result < 0))
        warn_failed_pipe_io ("close");

      fd = -1;
    }
  }
#endif

  auto
  warn_dropped_dispatcher_message () -> void
  {
    g_warning (
        "Dropped dispatcher message as the dispatcher no longer exists.");
  }

} // namespace

namespace glib
{

  struct Dispatcher::Impl
  {
  public:
    sigc::signal<void ()> signal_;
    DispatchNotifier* notifier_;

    explicit Impl (const RefPtr<MainContext>& context);

    Impl (const Impl&) = delete;
    auto
    operator= (const Impl&) -> Impl& = delete;
  };

  class DispatchNotifier : public sigc::trackable
  {
  public:
    ~DispatchNotifier () noexcept;

    DispatchNotifier (const DispatchNotifier&) = delete;
    auto
    operator= (const DispatchNotifier&) -> DispatchNotifier& = delete;

    static auto
    reference_instance (const RefPtr<MainContext>& context)
        -> DispatchNotifier*;
    static auto
    unreference_instance (DispatchNotifier* notifier,
                          Dispatcher::Impl* dispatcher_impl) -> void;

    auto
    send_notification (Dispatcher::Impl* dispatcher_impl) -> void;

  protected:
    explicit DispatchNotifier (const RefPtr<MainContext>& context);

  private:
    static thread_local DispatchNotifier* thread_specific_instance_;

    using UniqueImplPtr = std::unique_ptr<Dispatcher::Impl>;
    std::forward_list<UniqueImplPtr> orphaned_dispatcher_impl_;
    long ref_count_;
    RefPtr<MainContext> context_;
#ifdef G_OS_WIN32
    std::mutex mutex_;
    std::list<DispatchNotifyData> notify_queue_;
    HANDLE fd_receiver_;
#else
    int fd_receiver_;
    int fd_sender_;
#endif

    auto
    create_pipe () -> void;
    auto
    pipe_io_handler (IOCondition condition) -> bool;
    auto
    pipe_is_empty () -> bool;
  };

  thread_local DispatchNotifier* DispatchNotifier::thread_specific_instance_ =
      nullptr;

  DispatchNotifier::DispatchNotifier (const RefPtr<MainContext>& context)
    : orphaned_dispatcher_impl_ (),
      ref_count_ (0),
      context_ (context),
#ifdef G_OS_WIN32
      mutex_ (),
      notify_queue_ (),
      fd_receiver_ (0)
#else
      fd_receiver_ (-1),
      fd_sender_ (-1)
#endif
  {
    create_pipe ();

    try
    {
      const auto fd = (PollFD::fd_t) fd_receiver_;

      const auto source = IOSource::create (fd, IOCondition::IO_IN);

      source->set_can_recurse (true);

      source->connect (mem_fun (*this, &DispatchNotifier::pipe_io_handler));
      g_source_attach (source->gobj (), context_->gobj ());
    }
    catch (...)
    {
#ifndef G_OS_WIN32
      fd_close_and_invalidate (fd_sender_);
#endif
      fd_close_and_invalidate (fd_receiver_);

      throw;
    }
  }

  DispatchNotifier::~DispatchNotifier () noexcept
  {
#ifndef G_OS_WIN32
    fd_close_and_invalidate (fd_sender_);
#endif
    fd_close_and_invalidate (fd_receiver_);
  }

  auto
  DispatchNotifier::create_pipe () -> void
  {
#ifdef G_OS_WIN32

    const HANDLE event = CreateEvent (0, TRUE, FALSE, 0);

    if (!event)
    {
      GError* const error = g_error_new (
          G_FILE_ERROR,
          G_FILE_ERROR_FAILED,
          "Failed to create event for inter-thread communication: %s",
          g_win32_error_message (GetLastError ()));
      throw FileError (error);
    }

    fd_receiver_ = event;

#else

    int filedes[2] = {-1, -1};

    if (pipe (filedes) < 0)
    {
      GError* const error = g_error_new (
          G_FILE_ERROR,
          g_file_error_from_errno (errno),
          "Failed to create pipe for inter-thread communication: %s",
          g_strerror (errno));
      throw glib::FileError (error);
    }

    fd_set_close_on_exec (filedes[0]);
    fd_set_close_on_exec (filedes[1]);

    fd_receiver_ = filedes[0];
    fd_sender_ = filedes[1];

#endif
  }

  auto
  DispatchNotifier::reference_instance (const RefPtr<MainContext>& context) -> DispatchNotifier*
  {
    DispatchNotifier* instance = thread_specific_instance_;

    if (!instance)
    {
      instance = new DispatchNotifier (context);
      thread_specific_instance_ = instance;
    }
    else
    {
      g_return_val_if_fail (instance->context_ == context, nullptr);
    }

    ++instance->ref_count_;

    return instance;
  }

  auto
  DispatchNotifier::unreference_instance (DispatchNotifier* notifier,
                                          Dispatcher::Impl* dispatcher_impl) -> void
  {
    DispatchNotifier* const instance = thread_specific_instance_;

    g_return_if_fail (instance == notifier);

    if (instance->pipe_is_empty ())
    {
      delete dispatcher_impl;
      instance->orphaned_dispatcher_impl_.clear ();
    }
    else
    {
      dispatcher_impl->signal_.clear ();

      dispatcher_impl->signal_.connect (
          sigc::ptr_fun (warn_dropped_dispatcher_message));
      instance->orphaned_dispatcher_impl_.push_front (
          UniqueImplPtr (dispatcher_impl));
    }

    if (--instance->ref_count_ <= 0)
    {
      g_return_if_fail (instance->ref_count_ == 0);

      delete thread_specific_instance_;
      thread_specific_instance_ = nullptr;
    }
  }

  auto
  DispatchNotifier::send_notification (Dispatcher::Impl* dispatcher_impl) -> void
  {
#ifdef G_OS_WIN32
    {
      const std::lock_guard<std::mutex> lock (mutex_);

      const bool was_empty = notify_queue_.empty ();
      notify_queue_.emplace_back (DispatchNotifyData (dispatcher_impl, this));

      if (was_empty)
      {
        if (!SetEvent (fd_receiver_))
          warn_failed_pipe_io ("SetEvent");
      }
    }
#else

    DispatchNotifyData data (dispatcher_impl, this);
    gssize n_written;

    do
      n_written = write (fd_sender_, &data, sizeof (data));
    while (G_UNLIKELY (n_written < 0) && errno == EINTR);

    if (G_UNLIKELY (n_written != sizeof (data)))
      warn_failed_pipe_io ("write");

#endif
  }

  auto
  DispatchNotifier::pipe_is_empty () -> bool
  {
#ifdef G_OS_WIN32
    return notify_queue_.empty ();
#else
    PollFD poll_fd (fd_receiver_, glib::IOCondition::IO_IN);

    g_poll (poll_fd.gobj (), 1, 0);
    return static_cast<int> (poll_fd.get_revents () &
                             glib::IOCondition::IO_IN) == 0;
#endif
  }

  auto
  DispatchNotifier::pipe_io_handler (IOCondition) -> bool
  {
    DispatchNotifyData data;

#ifdef G_OS_WIN32
    {
      const std::lock_guard<std::mutex> lock (mutex_);

      if (notify_queue_.empty ())
      {
        if (!ResetEvent (fd_receiver_))
          warn_failed_pipe_io ("ResetEvent");

        return true;
      }

      data = notify_queue_.front ();
      notify_queue_.pop_front ();

      if (notify_queue_.empty ())
      {
        if (!ResetEvent (fd_receiver_))
          warn_failed_pipe_io ("ResetEvent");
      }
    }
#else

    gssize n_read;

    do
      n_read = read (fd_receiver_, &data, sizeof (data));
    while (G_UNLIKELY (n_read < 0) && errno == EINTR);

    if (G_UNLIKELY (n_read != sizeof (data)))
    {
      if (n_read != 0)
        warn_failed_pipe_io ("read");

      return true;
    }
#endif

    g_return_val_if_fail (data.notifier == this, true);

    try
    {
      data.dispatcher_impl->signal_ ();
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }

    if (!orphaned_dispatcher_impl_.empty () && pipe_is_empty ())
      orphaned_dispatcher_impl_.clear ();

    return true;
  }

  Dispatcher::Impl::Impl (const RefPtr<MainContext>& context)
    : signal_ (),
      notifier_ (DispatchNotifier::reference_instance (context))
  {
  }

  Dispatcher::Dispatcher ()
    : impl_ (new Impl (MainContext::get_default ()))
  {
  }

  Dispatcher::Dispatcher (const RefPtr<MainContext>& context)
    : impl_ (new Impl (context))
  {
  }

  Dispatcher::~Dispatcher () noexcept
  {
    DispatchNotifier::unreference_instance (impl_->notifier_, impl_);
  }

  auto
  Dispatcher::emit () -> void
  {
    impl_->notifier_->send_notification (impl_);
  }

  auto
  Dispatcher::operator() () -> void
  {
    impl_->notifier_->send_notification (impl_);
  }

  auto
  Dispatcher::connect (const sigc::slot<void ()>& slot) -> sigc::connection
  {
    return impl_->signal_.connect (slot);
  }

  auto
  Dispatcher::connect (sigc::slot<void ()>&& slot) -> sigc::connection
  {
    return impl_->signal_.connect (std::move (slot));
  }

} // namespace glib
