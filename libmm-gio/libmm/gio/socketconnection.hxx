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
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketConnection_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnection : public gio::IOStream
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
    explicit SocketConnection (const glib::ConstructParams& construct_params);
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
    connect (const glib::RefPtr<SocketAddress>& address,
             const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    connect (const glib::RefPtr<SocketAddress>& address) -> bool;

    auto
    connect_async (const glib::RefPtr<SocketAddress>& address,
                   const SlotAsyncReady& slot,
                   const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    connect_async (const glib::RefPtr<SocketAddress>& address,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    is_connected () const -> bool;

    auto
    get_socket () -> glib::RefPtr<Socket>;

    auto
    get_socket () const -> glib::RefPtr<const Socket>;

    auto
    get_local_address () -> glib::RefPtr<SocketAddress>;

    auto
    get_local_address () const -> glib::RefPtr<const SocketAddress>;

    auto
    get_remote_address () -> glib::RefPtr<SocketAddress>;

    auto
    get_remote_address () const -> glib::RefPtr<const SocketAddress>;

    static auto
    create (const glib::RefPtr<Socket>& socket)
        -> glib::RefPtr<SocketConnection>;

    auto
    property_socket () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Socket>>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketConnection* object, bool take_copy = false) -> glib::RefPtr<gio::SocketConnection>;
} // namespace glib

#endif
