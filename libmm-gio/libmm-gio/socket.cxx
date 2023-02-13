


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socket.hxx>
#include <libmm-gio/socket_p.hxx>


/* Copyright (C) 2007 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-glib/error.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/socketsource.hxx>
#include <libmm-gio/slot_async.hxx>

using Type = Gio::Socket::Type;
using Protocol = Gio::Socket::Protocol;

namespace Gio
{

Socket::Socket(SocketFamily family, Type type, Protocol protocol,
  const Glib::RefPtr<Cancellable>& cancellable)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(socket_class_.init(), "family",int(family),"type",int(type),"protocol",int(protocol), nullptr))
{
  init(cancellable);
}

Socket::Socket(const int fd, const Glib::RefPtr<Cancellable>& cancellable) : // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  ObjectBase(nullptr),
  Object(Glib::ConstructParams(socket_class_.init(), "fd",fd, nullptr))
{
  init(cancellable);
}

// static
auto
Socket::create(
  const SocketFamily family, const Type type, const Protocol protocol,
  const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>
{
  return Glib::make_refptr_for_instance<Socket>(new Socket(family, type, protocol, cancellable));
}

// static
auto
Socket::create_from_fd(
  const int fd, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>
{
  return Glib::make_refptr_for_instance<Socket>(new Socket(fd, cancellable));
}

auto
Socket::receive_from(Glib::RefPtr<SocketAddress>& address, char* buffer, const gsize size,
  const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  GSocketAddress* caddr = nullptr;
  const auto retvalue = g_socket_receive_from(
    gobj(), &caddr, buffer, size, Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (caddr)
    address = Glib::wrap(caddr);

  return retvalue;
}

auto
Socket::receive_from(Glib::RefPtr<SocketAddress>& address, char* buffer, const gsize size) -> gssize
{
  GError* gerror = nullptr;
  GSocketAddress* caddr = nullptr;
  const auto retvalue = g_socket_receive_from(gobj(), &caddr, buffer, size, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (caddr)
    address = Glib::wrap(caddr);

  return retvalue;
}

auto
Socket::receive_with_blocking(
  gchar* buffer, const gsize size, const bool blocking, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_receive_with_blocking(
    gobj(), buffer, size, blocking, Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
Socket::send_with_blocking(
  gchar* buffer, const gsize size, const bool blocking, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_send_with_blocking(
    gobj(), buffer, size, blocking, Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
Socket::create_source(
  const Glib::IOCondition condition, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketSource>
{
  return SocketSource::create(gobj(), condition, cancellable);
}

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::Socket::Type>::value_type() -> GType
{
  return g_socket_type_get_type();
}

// static
auto Glib::Value<Gio::Socket::Protocol>::value_type() -> GType
{
  return g_socket_protocol_get_type();
}

// static
auto Glib::Value<Gio::Socket::MsgFlags>::value_type() -> GType
{
  return g_socket_msg_flags_get_type();
}


namespace Glib
{

auto wrap(GSocket* object, const bool take_copy) -> RefPtr<Gio::Socket>
{
  return Glib::make_refptr_for_instance<Gio::Socket>( dynamic_cast<Gio::Socket*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Socket_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Socket_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Initable::add_interface(get_type());

  }

  return *this;
}


auto Socket_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Socket_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Socket((GSocket*)object);
}


/* The implementation: */

auto Socket::gobj_copy() -> GSocket*
{
  reference();
  return gobj();
}

Socket::Socket(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Socket::Socket(GSocket* castitem)
: Object((GObject*)castitem)
{}


Socket::Socket(Socket&& src) noexcept
: Object(std::move(src))
  , Initable(std::move(src))
{}

auto Socket::operator=(Socket&& src) noexcept -> Socket&
{
  Object::operator=(std::move(src));
  Initable::operator=(std::move(src));
  return *this;
}


Socket::~Socket() noexcept = default;

Socket::CppClassType Socket::socket_class_; // initialize static member

auto Socket::get_type() -> GType
{
  return socket_class_.init().get_type();
}


auto Socket::get_base_type() -> GType
{
  return g_socket_get_type();
}


auto Socket::bind (const Glib::RefPtr <SocketAddress> &address, const bool allow_reuse) -> void
{
  GError* gerror = nullptr;
  g_socket_bind(gobj(), Glib::unwrap(address), allow_reuse, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::listen () -> void
{
  GError* gerror = nullptr;
  g_socket_listen(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::accept(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_accept(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::accept() -> Glib::RefPtr<Socket>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_accept(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::connect (
  const Glib::RefPtr <SocketAddress> &address,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  GError* gerror = nullptr;
  g_socket_connect(gobj(), Glib::unwrap(address), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::connect (const Glib::RefPtr <SocketAddress> &address) -> void
{
  GError* gerror = nullptr;
  g_socket_connect(gobj(), Glib::unwrap(address), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::check_connect_result () -> void
{
  GError* gerror = nullptr;
  g_socket_check_connect_result(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::receive(char* buffer, const gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_receive(gobj(), buffer, size, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::receive(char* buffer, const gsize size) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_receive(gobj(), buffer, size, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::send(const gchar* buffer, const gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_send(gobj(), buffer, size, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::send(const gchar* buffer, const gsize size) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_send(gobj(), buffer, size, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::send_to(const Glib::RefPtr<SocketAddress>& address, const char* buffer, const gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_send_to(gobj(), Glib::unwrap(address), buffer, size, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::send_to(const Glib::RefPtr<SocketAddress>& address, const char* buffer, const gsize size) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_send_to(gobj(), Glib::unwrap(address), buffer, size, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::close () -> void
{
  GError* gerror = nullptr;
  g_socket_close(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::is_closed() -> bool
{
  return g_socket_is_closed(gobj());
}

auto Socket::shutdown (
  const bool shutdown_read, const bool shutdown_write) -> void
{
  GError* gerror = nullptr;
  g_socket_shutdown(gobj(), shutdown_read, shutdown_write, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::is_connected() -> bool
{
  return g_socket_is_connected(gobj());
}

auto Socket::get_available_bytes() const -> gssize
{
  return g_socket_get_available_bytes(const_cast<GSocket*>(gobj()));
}

auto Socket::condition_check(Glib::IOCondition condition) -> Glib::IOCondition
{
  return static_cast<Glib::IOCondition>(g_socket_condition_check(gobj(), static_cast<GIOCondition>(condition)));
}

auto Socket::condition_wait (
  Glib::IOCondition condition, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  GError* gerror = nullptr;
  g_socket_condition_wait(gobj(), static_cast<GIOCondition>(condition), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::condition_wait (Glib::IOCondition condition) -> void
{
  GError* gerror = nullptr;
  g_socket_condition_wait(gobj(), static_cast<GIOCondition>(condition), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::condition_timed_wait (
  Glib::IOCondition condition, const gint64 timeout,
  const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  GError* gerror = nullptr;
  g_socket_condition_timed_wait(gobj(), static_cast<GIOCondition>(condition), timeout, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::condition_timed_wait (Glib::IOCondition condition, const gint64 timeout) -> void
{
  GError* gerror = nullptr;
  g_socket_condition_timed_wait(gobj(), static_cast<GIOCondition>(condition), timeout, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Socket::set_listen_backlog (
  const int backlog) -> void
{
  g_socket_set_listen_backlog(gobj(), backlog);
}

auto Socket::get_listen_backlog() const -> int
{
  return g_socket_get_listen_backlog(const_cast<GSocket*>(gobj()));
}

auto Socket::set_blocking (
  const bool blocking) -> void
{
  g_socket_set_blocking(gobj(), blocking);
}

auto Socket::get_blocking() const -> bool
{
  return g_socket_get_blocking(const_cast<GSocket*>(gobj()));
}

auto Socket::set_keepalive (
  const bool keepalive) -> void
{
  g_socket_set_keepalive(gobj(), keepalive);
}

auto Socket::get_keepalive() const -> bool
{
  return g_socket_get_keepalive(const_cast<GSocket*>(gobj()));
}

auto Socket::get_family() const -> SocketFamily
{
  return static_cast<SocketFamily>(g_socket_get_family(const_cast<GSocket*>(gobj())));
}

auto Socket::get_fd() const -> int
{
  return g_socket_get_fd(const_cast<GSocket*>(gobj()));
}

auto Socket::get_local_address() const -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_get_local_address(const_cast<GSocket*>(gobj()), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::get_remote_address() const -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_get_remote_address(const_cast<GSocket*>(gobj()), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::get_protocol() const -> Protocol
{
  return static_cast<Protocol>(g_socket_get_protocol(const_cast<GSocket*>(gobj())));
}

auto Socket::get_socket_type() const -> Type
{
  return static_cast<Type>(g_socket_get_socket_type(const_cast<GSocket*>(gobj())));
}

auto Socket::speaks_ipv4() const -> bool
{
  return g_socket_speaks_ipv4(const_cast<GSocket*>(gobj()));
}

auto Socket::get_credentials() -> Glib::RefPtr<Credentials>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_get_credentials(gobj(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::get_credentials() const -> Glib::RefPtr<const Credentials>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_get_credentials(const_cast<GSocket*>(gobj()), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::get_timeout() const -> guint
{
  return g_socket_get_timeout(const_cast<GSocket*>(gobj()));
}

auto Socket::set_timeout (
  const guint timeout) -> void
{
  g_socket_set_timeout(gobj(), timeout);
}

auto Socket::get_option(
  const int level, const int optname, int& value) const -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_get_option(const_cast<GSocket*>(gobj()), level, optname, &value, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::set_option(
  const int level, const int optname, const int value) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_set_option(gobj(), level, optname, value, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::get_ttl() const -> guint
{
  return g_socket_get_ttl(const_cast<GSocket*>(gobj()));
}

auto Socket::set_ttl (
  const guint ttl) -> void
{
  g_socket_set_ttl(gobj(), ttl);
}

auto Socket::get_broadcast() const -> bool
{
  return g_socket_get_broadcast(const_cast<GSocket*>(gobj()));
}

auto Socket::set_broadcast (
  const bool broadcast) -> void
{
  g_socket_set_broadcast(gobj(), broadcast);
}

auto Socket::get_multicast_loopback() const -> bool
{
  return g_socket_get_multicast_loopback(const_cast<GSocket*>(gobj()));
}

auto Socket::set_multicast_loopback (
  const bool loopback) -> void
{
  g_socket_set_multicast_loopback(gobj(), loopback);
}

auto Socket::get_multicast_ttl() const -> guint
{
  return g_socket_get_multicast_ttl(const_cast<GSocket*>(gobj()));
}

auto Socket::set_multicast_ttl (
  const guint ttl) -> void
{
  g_socket_set_multicast_ttl(gobj(), ttl);
}

auto Socket::join_multicast_group(const Glib::RefPtr<InetAddress>& group, const bool source_specific, const std::string& iface) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_join_multicast_group(gobj(), Glib::unwrap(group), source_specific, iface.empty() ? nullptr : iface.c_str(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::join_multicast_group(const Glib::RefPtr<InetAddress>& group, const bool source_specific) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_join_multicast_group(gobj(), Glib::unwrap(group), source_specific, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::leave_multicast_group(const Glib::RefPtr<InetAddress>& group, const bool source_specific, const std::string& iface) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_leave_multicast_group(gobj(), Glib::unwrap(group), source_specific, iface.empty() ? nullptr : iface.c_str(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Socket::leave_multicast_group(const Glib::RefPtr<InetAddress>& group, const bool source_specific) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_leave_multicast_group(gobj(), Glib::unwrap(group), source_specific, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


auto Socket::property_blocking() -> Glib::PropertyProxy< bool >
{
  return {this, "blocking"};
}

auto Socket::property_blocking() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "blocking"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
  "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Socket::property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >
{
  return {this, "family"};
}

auto Socket::property_fd() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "fd"};
}

auto Socket::property_keepalive() -> Glib::PropertyProxy< bool >
{
  return {this, "keepalive"};
}

auto Socket::property_keepalive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "keepalive"};
}

auto Socket::property_listen_backlog() -> Glib::PropertyProxy< int >
{
  return {this, "listen-backlog"};
}

auto Socket::property_listen_backlog() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "listen-backlog"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SocketAddress>>::value,
  "Type Glib::RefPtr<SocketAddress> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Socket::property_local_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketAddress> >
{
  return {this, "local-address"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SocketAddress>>::value,
  "Type Glib::RefPtr<SocketAddress> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Socket::property_remote_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketAddress> >
{
  return {this, "remote-address"};
}

auto Socket::property_timeout() -> Glib::PropertyProxy< guint >
{
  return {this, "timeout"};
}

auto Socket::property_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "timeout"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Protocol>::value,
  "Type Protocol cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Socket::property_protocol() const -> Glib::PropertyProxy_ReadOnly< Protocol >
{
  return {this, "protocol"};
}

auto Socket::property_broadcast() -> Glib::PropertyProxy< bool >
{
  return {this, "broadcast"};
}

auto Socket::property_broadcast() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "broadcast"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Socket::property_type() const -> Glib::PropertyProxy_ReadOnly< Type >
{
  return {this, "type"};
}

auto Socket::property_ttl() -> Glib::PropertyProxy< guint >
{
  return {this, "ttl"};
}

auto Socket::property_ttl() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "ttl"};
}

auto Socket::property_multicast_loopback() -> Glib::PropertyProxy< bool >
{
  return {this, "multicast-loopback"};
}

auto Socket::property_multicast_loopback() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "multicast-loopback"};
}

auto Socket::property_multicast_ttl() -> Glib::PropertyProxy< guint >
{
  return {this, "multicast-ttl"};
}

auto Socket::property_multicast_ttl() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "multicast-ttl"};
}


} // namespace Gio


