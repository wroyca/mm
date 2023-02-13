


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/unixconnection.hpp>
#include <mm/gio/private/unixconnection_p.hpp>


/* Copyright (C) 2010 Jonathon Jongsma
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
#include <gio/gunixconnection.h>
#include <mm/gio/slot_async.hpp>

namespace Gio
{

auto UnixConnection::receive_credentials_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  const auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_receive_credentials_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto UnixConnection::receive_credentials_async (const SlotAsyncReady &slot) -> void
{
  const auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_receive_credentials_async(
    gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto UnixConnection::send_credentials_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  const auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_send_credentials_async(
    gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto UnixConnection::send_credentials_async (const SlotAsyncReady &slot) -> void

{
  const auto slot_copy = new SlotAsyncReady(slot);

  g_unix_connection_send_credentials_async(gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GUnixConnection* object, const bool take_copy) -> RefPtr<Gio::UnixConnection>
{
  return Glib::make_refptr_for_instance<Gio::UnixConnection>( dynamic_cast<Gio::UnixConnection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixConnection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixConnection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_connection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto UnixConnection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixConnection((GUnixConnection*)object);
}


/* The implementation: */

auto UnixConnection::gobj_copy() -> GUnixConnection*
{
  reference();
  return gobj();
}

UnixConnection::UnixConnection(const Glib::ConstructParams& construct_params)
: SocketConnection(construct_params)
{

}

UnixConnection::UnixConnection(GUnixConnection* castitem)
: SocketConnection((GSocketConnection*)castitem)
{}


UnixConnection::UnixConnection(UnixConnection&& src) noexcept
: SocketConnection(std::move(src))
{}

auto UnixConnection::operator=(UnixConnection&& src) noexcept -> UnixConnection&
{
  SocketConnection::operator=(std::move(src));
  return *this;
}


UnixConnection::~UnixConnection() noexcept = default;

UnixConnection::CppClassType UnixConnection::unixconnection_class_; // initialize static member

auto UnixConnection::get_type() -> GType
{
  return unixconnection_class_.init().get_type();
}


auto UnixConnection::get_base_type() -> GType
{
  return g_unix_connection_get_type();
}


auto UnixConnection::send_fd(
  const int fd, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_send_fd(gobj(), fd, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::send_fd(
  const int fd) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_send_fd(gobj(), fd, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::receive_fd(const Glib::RefPtr<Cancellable>& cancellable) -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_receive_fd(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::receive_fd() -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_receive_fd(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::receive_credentials(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Credentials>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials(gobj(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::receive_credentials() -> Glib::RefPtr<Credentials>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials(gobj(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::receive_credentials(const Glib::RefPtr<Cancellable>& cancellable) const -> Glib::RefPtr<const Credentials>
{
  return const_cast<UnixConnection*>(this)->receive_credentials(cancellable);
}

auto UnixConnection::receive_credentials() const -> Glib::RefPtr<const Credentials>
{
  return const_cast<UnixConnection*>(this)->receive_credentials();
}

auto UnixConnection::receive_credentials_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<Credentials>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_unix_connection_receive_credentials_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::send_credentials(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_send_credentials(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::send_credentials() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_send_credentials(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixConnection::send_credentials_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_connection_send_credentials_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


