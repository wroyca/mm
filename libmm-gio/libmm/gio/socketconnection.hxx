// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCONNECTION_H
#define _GIOMM_SOCKETCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/enums.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/gio/socket.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketConnection = struct _GSocketConnection;
using GSocketConnectionClass = struct _GSocketConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT SocketConnection_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnection : public Gio::IOStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketConnection;
    using CppClassType = SocketConnection_Class;
    using BaseObjectType = GSocketConnection;
    using BaseClassType = GSocketConnectionClass;

    SocketConnection (const SocketConnection&) = delete;
    auto
    operator= (const SocketConnection&) -> SocketConnection& = delete;

  private:
    friend class SocketConnection_Class;
    static CppClassType socketconnection_class_;

  protected:
    explicit SocketConnection (const Glib::ConstructParams& construct_params);
    explicit SocketConnection (GSocketConnection* castitem);

#endif

  public:
    SocketConnection (SocketConnection&& src) noexcept;
    auto
    operator= (SocketConnection&& src) noexcept -> SocketConnection&;

    ~SocketConnection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketConnection*
    {
      return reinterpret_cast<GSocketConnection*> (gobject_);
    }

    auto
    gobj () const -> const GSocketConnection*
    {
      return reinterpret_cast<GSocketConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketConnection*;

  private:
  public:
    auto
    connect (const Glib::RefPtr<SocketAddress>& address,
             const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    connect (const Glib::RefPtr<SocketAddress>& address) -> bool;

    auto
    connect_async (const Glib::RefPtr<SocketAddress>& address,
                   const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    connect_async (const Glib::RefPtr<SocketAddress>& address,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    is_connected () const -> bool;

    auto
    get_socket () -> Glib::RefPtr<Socket>;

    auto
    get_socket () const -> Glib::RefPtr<const Socket>;

    auto
    get_local_address () -> Glib::RefPtr<SocketAddress>;

    auto
    get_local_address () const -> Glib::RefPtr<const SocketAddress>;

    auto
    get_remote_address () -> Glib::RefPtr<SocketAddress>;

    auto
    get_remote_address () const -> Glib::RefPtr<const SocketAddress>;

    static auto
    create (const Glib::RefPtr<Socket>& socket)
        -> Glib::RefPtr<SocketConnection>;

    auto
    property_socket () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Socket>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketConnection>;
} // namespace Glib

#endif
