// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETSOURCE_H
#define _GIOMM_SOCKETSOURCE_H

#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/main.hxx>
#include <libmm/glib/priorities.hxx>
#include <libmm/glib/refptr.hxx>
#include <sigc++/sigc++.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocket = struct _GSocket;
#endif

namespace gio
{
  class LIBMM_GIO_SYMEXPORT Socket;

  class LIBMM_GIO_SYMEXPORT SignalSocket
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    explicit inline SignalSocket (GMainContext* context);
#endif

    auto
    connect (const sigc::slot<bool (glib::IOCondition)>& slot,
             const glib::RefPtr<Socket>& socket,
             glib::IOCondition condition,
             const glib::RefPtr<Cancellable>& cancellable = {},
             int priority = glib::PRIORITY_DEFAULT) -> sigc::connection;

  private:
    GMainContext* context_;

    auto
    operator= (const SignalSocket&) -> SignalSocket& = delete;
  };

  LIBMM_GIO_SYMEXPORT
  auto
  signal_socket (const glib::RefPtr<glib::MainContext>& context = {}) -> SignalSocket;

  class SocketSource : public glib::IOSource
  {
  public:
    using CppObjectType = gio::SocketSource;

    LIBMM_GIO_SYMEXPORT static auto
    create (const glib::RefPtr<Socket>& socket,
            glib::IOCondition condition,
            const glib::RefPtr<Cancellable>& cancellable = {})
        -> glib::RefPtr<SocketSource>;

  protected:
    LIBMM_GIO_SYMEXPORT
    SocketSource (const glib::RefPtr<Socket>& socket,
                  glib::IOCondition condition,
                  const glib::RefPtr<Cancellable>& cancellable);
    LIBMM_GIO_SYMEXPORT ~SocketSource () noexcept override;

  private:
    friend LIBMM_GIO_SYMEXPORT Socket;

    LIBMM_GIO_SYMEXPORT static auto
    create (GSocket* socket,
            glib::IOCondition condition,
            const glib::RefPtr<Cancellable>& cancellable = {})
        -> glib::RefPtr<SocketSource>;

    LIBMM_GIO_SYMEXPORT
    SocketSource (GSocket* socket,
                  glib::IOCondition condition,
                  const glib::RefPtr<Cancellable>& cancellable);
  };

} // namespace gio

#endif
