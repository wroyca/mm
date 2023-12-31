// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETLISTENER_H
#define _GIOMM_SOCKETLISTENER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/enums.hxx>
#include <libmm/gio/socket.hxx>
#include <libmm/gio/socketconnection.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketListener = struct _GSocketListener;
using GSocketListenerClass = struct _GSocketListenerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketListener_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketListener : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketListener;
    using CppClassType = SocketListener_Class;
    using BaseObjectType = GSocketListener;
    using BaseClassType = GSocketListenerClass;

    SocketListener (const SocketListener&) = delete;
    auto
    operator= (const SocketListener&) -> SocketListener& = delete;

  private:
    friend class SocketListener_Class;
    static CppClassType socketlistener_class_;

  protected:
    explicit SocketListener (const glib::ConstructParams& construct_params);
    explicit SocketListener (GSocketListener* castitem);

#endif

  public:
    SocketListener (SocketListener&& src) noexcept;
    auto
    operator= (SocketListener&& src) noexcept -> SocketListener&;

    ~SocketListener () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketListener*
    {
      return reinterpret_cast<GSocketListener*> (gobject_);
    }

    auto
    gobj () const -> const GSocketListener*
    {
      return reinterpret_cast<GSocketListener*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketListener*;

  private:
  protected:
    SocketListener ();

  public:
    static auto
    create () -> glib::RefPtr<SocketListener>;

    auto
    set_backlog (int listen_backlog) -> void;

    auto
    add_socket (const glib::RefPtr<Socket>& socket,
                const glib::RefPtr<glib::Object>& source_object) -> bool;

    auto
    add_socket (const glib::RefPtr<Socket>& socket) -> bool;

    auto
    add_address (const glib::RefPtr<SocketAddress>& address,
                 Socket::Type type,
                 Socket::Protocol protocol,
                 const glib::RefPtr<glib::Object>& source_object,
                 glib::RefPtr<SocketAddress>& effective_address) -> bool;

    auto
    add_address (const glib::RefPtr<SocketAddress>& address,
                 Socket::Type type,
                 Socket::Protocol protocol,
                 glib::RefPtr<SocketAddress>& effective_address) -> bool;

    auto
    add_inet_port (guint16 port,
                   const glib::RefPtr<glib::Object>& source_object) -> bool;

    auto
    add_inet_port (guint16 port) -> bool;

    auto
    add_any_inet_port (const glib::RefPtr<glib::Object>& source_object)
        -> guint16;

    auto
    add_any_inet_port () -> guint16;

    auto
    accept_socket (glib::RefPtr<glib::Object>& source_object,
                   const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<Socket>;

    auto
    accept_socket (glib::RefPtr<glib::Object>& source_object)
        -> glib::RefPtr<Socket>;

    auto
    accept_socket (const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<Socket>;

    auto
    accept_socket () -> glib::RefPtr<Socket>;

    auto
    accept_socket_async (const glib::RefPtr<Cancellable>& cancellable,
                         const SlotAsyncReady& slot) -> void;

    auto
    accept_socket_async (const SlotAsyncReady& slot) -> void;

    auto
    accept_socket_finish (const glib::RefPtr<AsyncResult>& result,
                          glib::RefPtr<glib::Object>& source_object)
        -> glib::RefPtr<Socket>;

    auto
    accept_socket_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<Socket>;

    auto
    accept (glib::RefPtr<Object>& source_object,
            const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    accept (glib::RefPtr<Object>& source_object)
        -> glib::RefPtr<SocketConnection>;

    auto
    accept (const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    accept () -> glib::RefPtr<SocketConnection>;

    auto
    accept_async (const SlotAsyncReady& slot) -> void;

    auto
    accept_async (const glib::RefPtr<Cancellable>& cancellable,
                  const SlotAsyncReady& slot) -> void;

    auto
    accept_finish (const glib::RefPtr<AsyncResult>& result,
                   glib::RefPtr<glib::Object>& source_object)
        -> glib::RefPtr<SocketConnection>;

    auto
    accept_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketConnection>;

    auto
    close () -> void;

    auto
    property_listen_backlog () -> glib::PropertyProxy<int>;

    auto
    property_listen_backlog () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketListener* object, bool take_copy = false) -> glib::RefPtr<gio::SocketListener>;
} // namespace glib

#endif
