


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/tcpconnection.hpp>
#include <mm/gio/private/tcpconnection_p.hpp>


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

auto wrap(GTcpConnection* object, const bool take_copy) -> RefPtr<Gio::TcpConnection>
{
  return Glib::make_refptr_for_instance<Gio::TcpConnection>( dynamic_cast<Gio::TcpConnection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TcpConnection_Class::init() -> const Class&
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


auto TcpConnection_Class::class_init_function (void *g_class, void *class_data) -> void
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
: SocketConnection(construct_params)
{

}

TcpConnection::TcpConnection(GTcpConnection* castitem)
: SocketConnection((GSocketConnection*)castitem)
{}


TcpConnection::TcpConnection(TcpConnection&& src) noexcept
: SocketConnection(std::move(src))
{}

auto TcpConnection::operator=(TcpConnection&& src) noexcept -> TcpConnection&
{
  SocketConnection::operator=(std::move(src));
  return *this;
}


TcpConnection::~TcpConnection() noexcept = default;

TcpConnection::CppClassType TcpConnection::tcpconnection_class_; // initialize static member

auto TcpConnection::get_type() -> GType
{
  return tcpconnection_class_.init().get_type();
}


auto TcpConnection::get_base_type() -> GType
{
  return g_tcp_connection_get_type();
}


auto TcpConnection::set_graceful_disconnect (
  const bool graceful_disconnect) -> void
{
  g_tcp_connection_set_graceful_disconnect(gobj(), graceful_disconnect);
}

auto TcpConnection::get_graceful_disconnect() const -> bool
{
  return g_tcp_connection_get_graceful_disconnect(const_cast<GTcpConnection*>(gobj()));
}


auto TcpConnection::property_graceful_disconnect() -> Glib::PropertyProxy< bool >
{
  return {this, "graceful-disconnect"};
}

auto TcpConnection::property_graceful_disconnect() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "graceful-disconnect"};
}


} // namespace Gio


