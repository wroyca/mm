// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETSOURCE_H
#define _GIOMM_SOCKETSOURCE_H

#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/main.hxx>
#include <libmm-glib/priorities.hxx>
#include <libmm-glib/refptr.hxx>
#include <sigc++/sigc++.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocket = struct _GSocket;
#endif

namespace Gio
{
  class GIOMM_API Socket;

  class GIOMM_API SignalSocket
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalSocket (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<bool (Glib::IOCondition)>& slot,
             const Glib::RefPtr<Socket>& socket,
             Glib::IOCondition condition,
             const Glib::RefPtr<Cancellable>& cancellable = {},
             int priority = Glib::PRIORITY_DEFAULT) -> sigc::connection;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalSocket&) -> SignalSocket& = delete;
  };

  GIOMM_API
  auto
  signal_socket (const Glib::RefPtr<Glib::MainContext>& context = {}) -> SignalSocket;

  class SocketSource : public Glib::IOSource
  {
  public:
    using CppObjectType = Gio::SocketSource;

    GIOMM_API static auto
    create (const Glib::RefPtr<Socket>& socket,
            Glib::IOCondition condition,
            const Glib::RefPtr<Cancellable>& cancellable = {})
        -> Glib::RefPtr<SocketSource>;

  protected:
    GIOMM_API
    SocketSource (const Glib::RefPtr<Socket>& socket,
                  Glib::IOCondition condition,
                  const Glib::RefPtr<Cancellable>& cancellable);
    GIOMM_API ~SocketSource () noexcept override;

  private:
    friend GIOMM_API Socket;

    GIOMM_API static auto
    create (GSocket* socket,
            Glib::IOCondition condition,
            const Glib::RefPtr<Cancellable>& cancellable = {})
        -> Glib::RefPtr<SocketSource>;

    GIOMM_API
    SocketSource (GSocket* socket,
                  Glib::IOCondition condition,
                  const Glib::RefPtr<Cancellable>& cancellable);
  };

} // namespace Gio

#endif
