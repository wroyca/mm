// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socket.hxx>
#include <libmm/gio/socket_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/socketsource.hxx>
#include <libmm/glib/error.hxx>

using Type = gio::Socket::Type;
using Protocol = gio::Socket::Protocol;

namespace gio
{

  Socket::Socket (SocketFamily family,
                  Type type,
                  Protocol protocol,
                  const glib::RefPtr<Cancellable>& cancellable)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (socket_class_.init (),
                                     "family",
                                     int (family),
                                     "type",
                                     int (type),
                                     "protocol",
                                     int (protocol),
                                     nullptr))
  {
    init (cancellable);
  }

  Socket::Socket (const int fd, const glib::RefPtr<Cancellable>& cancellable)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (socket_class_.init (), "fd", fd, nullptr))
  {
    init (cancellable);
  }

  auto
  Socket::create (const SocketFamily family,
                  const Type type,
                  const Protocol protocol,
                  const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Socket>
  {
    return glib::make_refptr_for_instance<Socket> (
        new Socket (family, type, protocol, cancellable));
  }

  auto
  Socket::create_from_fd (const int fd,
                          const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Socket>
  {
    return glib::make_refptr_for_instance<Socket> (
        new Socket (fd, cancellable));
  }

  auto
  Socket::receive_from (glib::RefPtr<SocketAddress>& address,
                        char* buffer,
                        const gsize size,
                        const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    GSocketAddress* caddr = nullptr;
    const auto retvalue = g_socket_receive_from (gobj (),
                                                 &caddr,
                                                 buffer,
                                                 size,
                                                 glib::unwrap (cancellable),
                                                 &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (caddr)
      address = glib::wrap (caddr);

    return retvalue;
  }

  auto
  Socket::receive_from (glib::RefPtr<SocketAddress>& address,
                        char* buffer,
                        const gsize size) -> gssize
  {
    GError* gerror = nullptr;
    GSocketAddress* caddr = nullptr;
    const auto retvalue =
        g_socket_receive_from (gobj (), &caddr, buffer, size, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    if (caddr)
      address = glib::wrap (caddr);

    return retvalue;
  }

  auto
  Socket::receive_with_blocking (gchar* buffer,
                                 const gsize size,
                                 const bool blocking,
                                 const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_receive_with_blocking (
        gobj (),
        buffer,
        size,
        blocking,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Socket::send_with_blocking (gchar* buffer,
                              const gsize size,
                              const bool blocking,
                              const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_send_with_blocking (
        gobj (),
        buffer,
        size,
        blocking,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Socket::create_source (const glib::IOCondition condition,
                         const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<SocketSource>
  {
    return SocketSource::create (gobj (), condition, cancellable);
  }

} // namespace gio

namespace
{
}

auto
glib::Value<gio::Socket::Type>::value_type () -> GType
{
  return g_socket_type_get_type ();
}

auto
glib::Value<gio::Socket::Protocol>::value_type () -> GType
{
  return g_socket_protocol_get_type ();
}

auto
glib::Value<gio::Socket::MsgFlags>::value_type () -> GType
{
  return g_socket_msg_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GSocket* object, const bool take_copy) -> RefPtr<gio::Socket>
  {
    return glib::make_refptr_for_instance<gio::Socket> (
        dynamic_cast<gio::Socket*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  Socket_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Socket_Class::class_init_function;

      register_derived_type (g_socket_get_type ());

      Initable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Socket_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Socket_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Socket ((GSocket*) object);
  }

  auto
  Socket::gobj_copy () -> GSocket*
  {
    reference ();
    return gobj ();
  }

  Socket::Socket (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Socket::Socket (GSocket* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Socket::Socket (Socket&& src) noexcept
    : Object (std::move (src)),
      Initable (std::move (src))
  {
  }

  auto
  Socket::operator= (Socket&& src) noexcept -> Socket&
  {
    Object::operator= (std::move (src));
    Initable::operator= (std::move (src));
    return *this;
  }

  Socket::~Socket () noexcept = default;

  Socket::CppClassType Socket::socket_class_;

  auto
  Socket::get_type () -> GType
  {
    return socket_class_.init ().get_type ();
  }

  auto
  Socket::get_base_type () -> GType
  {
    return g_socket_get_type ();
  }

  auto
  Socket::bind (const glib::RefPtr<SocketAddress>& address,
                const bool allow_reuse) -> void
  {
    GError* gerror = nullptr;
    g_socket_bind (gobj (), glib::unwrap (address), allow_reuse, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::listen () -> void
  {
    GError* gerror = nullptr;
    g_socket_listen (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::accept (const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_accept (gobj (), glib::unwrap (cancellable), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::accept () -> glib::RefPtr<Socket>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_socket_accept (gobj (), nullptr, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::connect (const glib::RefPtr<SocketAddress>& address,
                   const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_socket_connect (gobj (),
                      glib::unwrap (address),
                      glib::unwrap (cancellable),
                      &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::connect (const glib::RefPtr<SocketAddress>& address) -> void
  {
    GError* gerror = nullptr;
    g_socket_connect (gobj (), glib::unwrap (address), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::check_connect_result () -> void
  {
    GError* gerror = nullptr;
    g_socket_check_connect_result (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::receive (char* buffer,
                   const gsize size,
                   const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_receive (gobj (),
                                            buffer,
                                            size,
                                            glib::unwrap (cancellable),
                                            &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::receive (char* buffer, const gsize size) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_receive (gobj (), buffer, size, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::send (const gchar* buffer,
                const gsize size,
                const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_send (gobj (),
                                         buffer,
                                         size,
                                         glib::unwrap (cancellable),
                                         &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::send (const gchar* buffer, const gsize size) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_send (gobj (), buffer, size, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::send_to (const glib::RefPtr<SocketAddress>& address,
                   const char* buffer,
                   const gsize size,
                   const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_send_to (gobj (),
                                            glib::unwrap (address),
                                            buffer,
                                            size,
                                            glib::unwrap (cancellable),
                                            &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::send_to (const glib::RefPtr<SocketAddress>& address,
                   const char* buffer,
                   const gsize size) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_send_to (gobj (),
                                            glib::unwrap (address),
                                            buffer,
                                            size,
                                            nullptr,
                                            &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::close () -> void
  {
    GError* gerror = nullptr;
    g_socket_close (gobj (), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::is_closed () -> bool
  {
    return g_socket_is_closed (gobj ());
  }

  auto
  Socket::shutdown (const bool shutdown_read, const bool shutdown_write) -> void
  {
    GError* gerror = nullptr;
    g_socket_shutdown (gobj (), shutdown_read, shutdown_write, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::is_connected () -> bool
  {
    return g_socket_is_connected (gobj ());
  }

  auto
  Socket::get_available_bytes () const -> gssize
  {
    return g_socket_get_available_bytes (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::condition_check (glib::IOCondition condition) -> glib::IOCondition
  {
    return static_cast<glib::IOCondition> (
        g_socket_condition_check (gobj (),
                                  static_cast<GIOCondition> (condition)));
  }

  auto
  Socket::condition_wait (glib::IOCondition condition,
                          const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_socket_condition_wait (gobj (),
                             static_cast<GIOCondition> (condition),
                             glib::unwrap (cancellable),
                             &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::condition_wait (glib::IOCondition condition) -> void
  {
    GError* gerror = nullptr;
    g_socket_condition_wait (gobj (),
                             static_cast<GIOCondition> (condition),
                             nullptr,
                             &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::condition_timed_wait (glib::IOCondition condition,
                                const gint64 timeout,
                                const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_socket_condition_timed_wait (gobj (),
                                   static_cast<GIOCondition> (condition),
                                   timeout,
                                   glib::unwrap (cancellable),
                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::condition_timed_wait (glib::IOCondition condition,
                                const gint64 timeout) -> void
  {
    GError* gerror = nullptr;
    g_socket_condition_timed_wait (gobj (),
                                   static_cast<GIOCondition> (condition),
                                   timeout,
                                   nullptr,
                                   &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Socket::set_listen_backlog (const int backlog) -> void
  {
    g_socket_set_listen_backlog (gobj (), backlog);
  }

  auto
  Socket::get_listen_backlog () const -> int
  {
    return g_socket_get_listen_backlog (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_blocking (const bool blocking) -> void
  {
    g_socket_set_blocking (gobj (), blocking);
  }

  auto
  Socket::get_blocking () const -> bool
  {
    return g_socket_get_blocking (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_keepalive (const bool keepalive) -> void
  {
    g_socket_set_keepalive (gobj (), keepalive);
  }

  auto
  Socket::get_keepalive () const -> bool
  {
    return g_socket_get_keepalive (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::get_family () const -> SocketFamily
  {
    return static_cast<SocketFamily> (
        g_socket_get_family (const_cast<GSocket*> (gobj ())));
  }

  auto
  Socket::get_fd () const -> int
  {
    return g_socket_get_fd (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::get_local_address () const -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_get_local_address (const_cast<GSocket*> (gobj ()), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::get_remote_address () const -> glib::RefPtr<SocketAddress>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_get_remote_address (const_cast<GSocket*> (gobj ()), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::get_protocol () const -> Protocol
  {
    return static_cast<Protocol> (
        g_socket_get_protocol (const_cast<GSocket*> (gobj ())));
  }

  auto
  Socket::get_socket_type () const -> Type
  {
    return static_cast<Type> (
        g_socket_get_socket_type (const_cast<GSocket*> (gobj ())));
  }

  auto
  Socket::speaks_ipv4 () const -> bool
  {
    return g_socket_speaks_ipv4 (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::get_credentials () -> glib::RefPtr<Credentials>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (g_socket_get_credentials (gobj (), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::get_credentials () const -> glib::RefPtr<const Credentials>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_socket_get_credentials (const_cast<GSocket*> (gobj ()), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::get_timeout () const -> guint
  {
    return g_socket_get_timeout (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_timeout (const guint timeout) -> void
  {
    g_socket_set_timeout (gobj (), timeout);
  }

  auto
  Socket::get_option (const int level, const int optname, int& value) const -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_get_option (const_cast<GSocket*> (gobj ()),
                                               level,
                                               optname,
                                               &value,
                                               &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::set_option (const int level, const int optname, const int value) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_set_option (gobj (), level, optname, value, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::get_ttl () const -> guint
  {
    return g_socket_get_ttl (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_ttl (const guint ttl) -> void
  {
    g_socket_set_ttl (gobj (), ttl);
  }

  auto
  Socket::get_broadcast () const -> bool
  {
    return g_socket_get_broadcast (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_broadcast (const bool broadcast) -> void
  {
    g_socket_set_broadcast (gobj (), broadcast);
  }

  auto
  Socket::get_multicast_loopback () const -> bool
  {
    return g_socket_get_multicast_loopback (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_multicast_loopback (const bool loopback) -> void
  {
    g_socket_set_multicast_loopback (gobj (), loopback);
  }

  auto
  Socket::get_multicast_ttl () const -> guint
  {
    return g_socket_get_multicast_ttl (const_cast<GSocket*> (gobj ()));
  }

  auto
  Socket::set_multicast_ttl (const guint ttl) -> void
  {
    g_socket_set_multicast_ttl (gobj (), ttl);
  }

  auto
  Socket::join_multicast_group (const glib::RefPtr<InetAddress>& group,
                                const bool source_specific,
                                const std::string& iface) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_join_multicast_group (
        gobj (),
        glib::unwrap (group),
        source_specific,
        iface.empty () ? nullptr : iface.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::join_multicast_group (const glib::RefPtr<InetAddress>& group,
                                const bool source_specific) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_join_multicast_group (gobj (),
                                                         glib::unwrap (group),
                                                         source_specific,
                                                         nullptr,
                                                         &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::leave_multicast_group (const glib::RefPtr<InetAddress>& group,
                                 const bool source_specific,
                                 const std::string& iface) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_leave_multicast_group (
        gobj (),
        glib::unwrap (group),
        source_specific,
        iface.empty () ? nullptr : iface.c_str (),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::leave_multicast_group (const glib::RefPtr<InetAddress>& group,
                                 const bool source_specific) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_socket_leave_multicast_group (gobj (),
                                                          glib::unwrap (group),
                                                          source_specific,
                                                          nullptr,
                                                          &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Socket::property_blocking () -> glib::PropertyProxy<bool>
  {
    return {this, "blocking"};
  }

  auto
  Socket::property_blocking () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "blocking"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
      "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Socket::property_family () const -> glib::PropertyProxy_ReadOnly<SocketFamily>
  {
    return {this, "family"};
  }

  auto
  Socket::property_fd () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "fd"};
  }

  auto
  Socket::property_keepalive () -> glib::PropertyProxy<bool>
  {
    return {this, "keepalive"};
  }

  auto
  Socket::property_keepalive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "keepalive"};
  }

  auto
  Socket::property_listen_backlog () -> glib::PropertyProxy<int>
  {
    return {this, "listen-backlog"};
  }

  auto
  Socket::property_listen_backlog () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "listen-backlog"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SocketAddress>>::value,
      "Type glib::RefPtr<SocketAddress> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Socket::property_local_address () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SocketAddress>>
  {
    return {this, "local-address"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SocketAddress>>::value,
      "Type glib::RefPtr<SocketAddress> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Socket::property_remote_address () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SocketAddress>>
  {
    return {this, "remote-address"};
  }

  auto
  Socket::property_timeout () -> glib::PropertyProxy<guint>
  {
    return {this, "timeout"};
  }

  auto
  Socket::property_timeout () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "timeout"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Protocol>::value,
      "Type Protocol cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Socket::property_protocol () const -> glib::PropertyProxy_ReadOnly<Protocol>
  {
    return {this, "protocol"};
  }

  auto
  Socket::property_broadcast () -> glib::PropertyProxy<bool>
  {
    return {this, "broadcast"};
  }

  auto
  Socket::property_broadcast () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "broadcast"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Socket::property_type () const -> glib::PropertyProxy_ReadOnly<Type>
  {
    return {this, "type"};
  }

  auto
  Socket::property_ttl () -> glib::PropertyProxy<guint>
  {
    return {this, "ttl"};
  }

  auto
  Socket::property_ttl () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "ttl"};
  }

  auto
  Socket::property_multicast_loopback () -> glib::PropertyProxy<bool>
  {
    return {this, "multicast-loopback"};
  }

  auto
  Socket::property_multicast_loopback () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "multicast-loopback"};
  }

  auto
  Socket::property_multicast_ttl () -> glib::PropertyProxy<guint>
  {
    return {this, "multicast-ttl"};
  }

  auto
  Socket::property_multicast_ttl () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "multicast-ttl"};
  }

} // namespace gio
