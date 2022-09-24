// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/socketconnection.h>
#include <mm/gio/private/socketconnection_p.h>


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
#include <mm/gio/slot_async.h>

namespace Gio
{

void
SocketConnection::connect_async(const Glib::RefPtr<SocketAddress>& address,
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable)
{
  auto slot_copy = new SlotAsyncReady(slot);

  g_socket_connection_connect_async(gobj(), Glib::unwrap(address), Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

void
SocketConnection::connect_async(
  const Glib::RefPtr<SocketAddress>& address, const SlotAsyncReady& slot)
{
  auto slot_copy = new SlotAsyncReady(slot);

  g_socket_connection_connect_async(
    gobj(), Glib::unwrap(address), nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSocketConnection* object, bool take_copy) -> Glib::RefPtr<Gio::SocketConnection>
{
  return Glib::make_refptr_for_instance<Gio::SocketConnection>( dynamic_cast<Gio::SocketConnection*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SocketConnection_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketConnection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_connection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void SocketConnection_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SocketConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketConnection((GSocketConnection*)object);
}


/* The implementation: */

auto SocketConnection::gobj_copy() -> GSocketConnection*
{
  reference();
  return gobj();
}

SocketConnection::SocketConnection(const Glib::ConstructParams& construct_params)
:
  Gio::IOStream(construct_params)
{

}

SocketConnection::SocketConnection(GSocketConnection* castitem)
:
  Gio::IOStream((GIOStream*)(castitem))
{}


SocketConnection::SocketConnection(SocketConnection&& src) noexcept
: Gio::IOStream(std::move(src))
{}

auto SocketConnection::operator=(SocketConnection&& src) noexcept -> SocketConnection&
{
  Gio::IOStream::operator=(std::move(src));
  return *this;
}


SocketConnection::~SocketConnection() noexcept
{}


SocketConnection::CppClassType SocketConnection::socketconnection_class_; // initialize static member

auto SocketConnection::get_type() -> GType
{
  return socketconnection_class_.init().get_type();
}


auto SocketConnection::get_base_type() -> GType
{
  return g_socket_connection_get_type();
}


auto SocketConnection::connect(const Glib::RefPtr<SocketAddress>& address, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_socket_connection_connect(gobj(), const_cast<GSocketAddress*>(Glib::unwrap(address)), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketConnection::connect(const Glib::RefPtr<SocketAddress>& address) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_socket_connection_connect(gobj(), const_cast<GSocketAddress*>(Glib::unwrap(address)), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketConnection::connect_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_socket_connection_connect_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketConnection::is_connected() const -> bool
{
  return g_socket_connection_is_connected(const_cast<GSocketConnection*>(gobj()));
}

auto SocketConnection::get_socket() -> Glib::RefPtr<Socket>
{
  auto retvalue = Glib::wrap(g_socket_connection_get_socket(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SocketConnection::get_socket() const -> Glib::RefPtr<const Socket>
{
  return const_cast<SocketConnection*>(this)->get_socket();
}

auto SocketConnection::get_local_address() -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_connection_get_local_address(gobj(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketConnection::get_local_address() const -> Glib::RefPtr<const SocketAddress>
{
  return const_cast<SocketConnection*>(this)->get_local_address();
}

auto SocketConnection::get_remote_address() -> Glib::RefPtr<SocketAddress>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_connection_get_remote_address(gobj(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketConnection::get_remote_address() const -> Glib::RefPtr<const SocketAddress>
{
  return const_cast<SocketConnection*>(this)->get_remote_address();
}

auto SocketConnection::create(const Glib::RefPtr<Socket>& socket) -> Glib::RefPtr<SocketConnection>
{
  return Glib::wrap(g_socket_connection_factory_create_connection(const_cast<GSocket*>(Glib::unwrap(socket))));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Socket>>::value,
  "Type Glib::RefPtr<Socket> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketConnection::property_socket() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Socket> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Socket> >(this, "socket");
}


} // namespace Gio


