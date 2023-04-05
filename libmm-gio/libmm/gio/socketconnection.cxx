// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketconnection.hxx>
#include <libmm/gio/socketconnection_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>

namespace gio
{

  auto
  SocketConnection::connect_async (const glib::RefPtr<SocketAddress>& address,
                                   const SlotAsyncReady& slot,
                                   const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_connection_connect_async (gobj (),
                                       glib::unwrap (address),
                                       glib::unwrap (cancellable),
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

  auto
  SocketConnection::connect_async (const glib::RefPtr<SocketAddress>& address,
                                   const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_connection_connect_async (gobj (),
                                       glib::unwrap (address),
                                       nullptr,
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GSocketConnection* object, const bool take_copy) -> RefPtr<gio::SocketConnection>
  {
    return glib::make_refptr_for_instance<gio::SocketConnection> (
        dynamic_cast<gio::SocketConnection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  SocketConnection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketConnection_Class::class_init_function;

      register_derived_type (g_socket_connection_get_type ());
    }

    return *this;
  }

  auto
  SocketConnection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SocketConnection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SocketConnection ((GSocketConnection*) object);
  }

  auto
  SocketConnection::gobj_copy () -> GSocketConnection*
  {
    reference ();
    return gobj ();
  }

  SocketConnection::SocketConnection (
      const glib::ConstructParams& construct_params)
    : IOStream (construct_params)
  {
  }

  SocketConnection::SocketConnection (GSocketConnection* castitem)
    : IOStream ((GIOStream*) castitem)
  {
  }

  SocketConnection::SocketConnection (SocketConnection&& src) noexcept
    : IOStream (std::move (src))
  {
  }

  auto
  SocketConnection::operator= (SocketConnection&& src) noexcept -> SocketConnection&
  {
    IOStream::operator= (std::move (src));
    return *this;
  }

  SocketConnection::~SocketConnection () noexcept = default;

  SocketConnection::CppClassType SocketConnection::socketconnection_class_;

  auto
  SocketConnection::get_type () -> GType
  {
    return socketconnection_class_.init ().get_type ();
  }

  auto
  SocketConnection::get_base_type () -> GType
  {
    return g_socket_connection_get_type ();
  }

  auto
  SocketConnection::connect (const glib::RefPtr<SocketAddress>& address,
                             const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect (
        gobj (),
        glib::unwrap (address),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::connect (const glib::RefPtr<SocketAddress>& address) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect (gobj (),
                                                       glib::unwrap (address),
                                                       nullptr,
                                                       &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::connect_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::is_connected () const -> bool
  {
    return g_socket_connection_is_connected (
        const_cast<GSocketConnection*> (gobj ()));
  }

  auto
  SocketConnection::get_socket () -> glib::RefPtr<Socket>
  {
    auto retvalue = glib::wrap (g_socket_connection_get_socket (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SocketConnection::get_socket () const -> glib::RefPtr<const Socket>
  {
    return const_cast<SocketConnection*> (this)->get_socket ();
  }

  auto
  SocketConnection::get_local_address () -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_socket_connection_get_local_address (gobj (), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::get_local_address () const -> glib::RefPtr<const SocketAddress>
  {
    return const_cast<SocketConnection*> (this)->get_local_address ();
  }

  auto
  SocketConnection::get_remote_address () -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_socket_connection_get_remote_address (gobj (), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::get_remote_address () const -> glib::RefPtr<const SocketAddress>
  {
    return const_cast<SocketConnection*> (this)->get_remote_address ();
  }

  auto
  SocketConnection::create (const glib::RefPtr<Socket>& socket) -> glib::RefPtr<SocketConnection>
  {
    return glib::wrap (
        g_socket_connection_factory_create_connection (glib::unwrap (socket)));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Socket>>::value,
      "Type glib::RefPtr<Socket> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SocketConnection::property_socket () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Socket>>
  {
    return {this, "socket"};
  }

} // namespace gio
