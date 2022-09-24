// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/tcpconnection.h>
#include <mm/gio/private/tcpconnection_p.h>


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

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GTcpConnection* object, bool take_copy) -> Glib::RefPtr<Gio::TcpConnection>
{
  return Glib::make_refptr_for_instance<Gio::TcpConnection>( dynamic_cast<Gio::TcpConnection*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TcpConnection_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TcpConnection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_tcp_connection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void TcpConnection_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TcpConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TcpConnection((GTcpConnection*)object);
}


/* The implementation: */

auto TcpConnection::gobj_copy() -> GTcpConnection*
{
  reference();
  return gobj();
}

TcpConnection::TcpConnection(const Glib::ConstructParams& construct_params)
:
  Gio::SocketConnection(construct_params)
{

}

TcpConnection::TcpConnection(GTcpConnection* castitem)
:
  Gio::SocketConnection((GSocketConnection*)(castitem))
{}


TcpConnection::TcpConnection(TcpConnection&& src) noexcept
: Gio::SocketConnection(std::move(src))
{}

auto TcpConnection::operator=(TcpConnection&& src) noexcept -> TcpConnection&
{
  Gio::SocketConnection::operator=(std::move(src));
  return *this;
}


TcpConnection::~TcpConnection() noexcept
{}


TcpConnection::CppClassType TcpConnection::tcpconnection_class_; // initialize static member

auto TcpConnection::get_type() -> GType
{
  return tcpconnection_class_.init().get_type();
}


auto TcpConnection::get_base_type() -> GType
{
  return g_tcp_connection_get_type();
}


void TcpConnection::set_graceful_disconnect(bool graceful_disconnect)
{
  g_tcp_connection_set_graceful_disconnect(gobj(), static_cast<int>(graceful_disconnect));
}

auto TcpConnection::get_graceful_disconnect() const -> bool
{
  return g_tcp_connection_get_graceful_disconnect(const_cast<GTcpConnection*>(gobj()));
}


auto TcpConnection::property_graceful_disconnect() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "graceful-disconnect");
}

auto TcpConnection::property_graceful_disconnect() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "graceful-disconnect");
}


} // namespace Gio


