// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketconnection.hxx>
#include <libmm/gio/socketconnection_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>

namespace Gio
{

  auto
  SocketConnection::connect_async (const Glib::RefPtr<SocketAddress>& address,
                                   const SlotAsyncReady& slot,
                                   const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_connection_connect_async (gobj (),
                                       Glib::unwrap (address),
                                       Glib::unwrap (cancellable),
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

  auto
  SocketConnection::connect_async (const Glib::RefPtr<SocketAddress>& address,
                                   const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_socket_connection_connect_async (gobj (),
                                       Glib::unwrap (address),
                                       nullptr,
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketConnection* object, const bool take_copy) -> RefPtr<Gio::SocketConnection>
  {
    return Glib::make_refptr_for_instance<Gio::SocketConnection> (
        dynamic_cast<Gio::SocketConnection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  SocketConnection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
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
  SocketConnection::connect (const Glib::RefPtr<SocketAddress>& address,
                             const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect (
        gobj (),
        Glib::unwrap (address),
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::connect (const Glib::RefPtr<SocketAddress>& address) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect (gobj (),
                                                       Glib::unwrap (address),
                                                       nullptr,
                                                       &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::connect_finish (const Glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_connection_connect_finish (
        gobj (),
        Glib::unwrap (result),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::is_connected () const -> bool
  {
    return g_socket_connection_is_connected (
        const_cast<GSocketConnection*> (gobj ()));
  }

  auto
  SocketConnection::get_socket () -> Glib::RefPtr<Socket>
  {
    auto retvalue = Glib::wrap (g_socket_connection_get_socket (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SocketConnection::get_socket () const -> Glib::RefPtr<const Socket>
  {
    return const_cast<SocketConnection*> (this)->get_socket ();
  }

  auto
  SocketConnection::get_local_address () -> Glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_socket_connection_get_local_address (gobj (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::get_local_address () const -> Glib::RefPtr<const SocketAddress>
  {
    return const_cast<SocketConnection*> (this)->get_local_address ();
  }

  auto
  SocketConnection::get_remote_address () -> Glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_socket_connection_get_remote_address (gobj (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketConnection::get_remote_address () const -> Glib::RefPtr<const SocketAddress>
  {
    return const_cast<SocketConnection*> (this)->get_remote_address ();
  }

  auto
  SocketConnection::create (const Glib::RefPtr<Socket>& socket) -> Glib::RefPtr<SocketConnection>
  {
    return Glib::wrap (
        g_socket_connection_factory_create_connection (Glib::unwrap (socket)));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Socket>>::value,
      "Type Glib::RefPtr<Socket> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SocketConnection::property_socket () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Socket>>
  {
    return {this, "socket"};
  }

} // namespace Gio
