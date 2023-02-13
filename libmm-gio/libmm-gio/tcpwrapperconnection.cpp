


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/tcpwrapperconnection.hpp>
#include <mm/gio/private/tcpwrapperconnection_p.hpp>


/* Copyright (C) 2015 The giomm Development Team
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

auto wrap(GTcpWrapperConnection* object, const bool take_copy) -> RefPtr<Gio::TcpWrapperConnection>
{
  return Glib::make_refptr_for_instance<Gio::TcpWrapperConnection>( dynamic_cast<Gio::TcpWrapperConnection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto TcpWrapperConnection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TcpWrapperConnection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_tcp_wrapper_connection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto TcpWrapperConnection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TcpWrapperConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TcpWrapperConnection((GTcpWrapperConnection*)object);
}


/* The implementation: */

auto TcpWrapperConnection::gobj_copy() -> GTcpWrapperConnection*
{
  reference();
  return gobj();
}

TcpWrapperConnection::TcpWrapperConnection(const Glib::ConstructParams& construct_params)
: TcpConnection(construct_params)
{

}

TcpWrapperConnection::TcpWrapperConnection(GTcpWrapperConnection* castitem)
: TcpConnection((GTcpConnection*)castitem)
{}


TcpWrapperConnection::TcpWrapperConnection(TcpWrapperConnection&& src) noexcept
: TcpConnection(std::move(src))
{}

auto TcpWrapperConnection::operator=(TcpWrapperConnection&& src) noexcept -> TcpWrapperConnection&
{
  TcpConnection::operator=(std::move(src));
  return *this;
}


TcpWrapperConnection::~TcpWrapperConnection() noexcept = default;

TcpWrapperConnection::CppClassType TcpWrapperConnection::tcpwrapperconnection_class_; // initialize static member

auto TcpWrapperConnection::get_type() -> GType
{
  return tcpwrapperconnection_class_.init().get_type();
}


auto TcpWrapperConnection::get_base_type() -> GType
{
  return g_tcp_wrapper_connection_get_type();
}


TcpWrapperConnection::TcpWrapperConnection(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<Socket>& socket)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
TcpConnection(Glib::ConstructParams(tcpwrapperconnection_class_.init(), "base_io_stream", Glib::unwrap(base_io_stream), "socket", Glib::unwrap(socket), nullptr))
{


}

auto TcpWrapperConnection::get_base_io_stream() -> Glib::RefPtr<IOStream>
{
  auto retvalue = Glib::wrap(g_tcp_wrapper_connection_get_base_io_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TcpWrapperConnection::get_base_io_stream() const -> Glib::RefPtr<const IOStream>
{
  return const_cast<TcpWrapperConnection*>(this)->get_base_io_stream();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<IOStream>>::value,
  "Type Glib::RefPtr<IOStream> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TcpWrapperConnection::property_base_io_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<IOStream> >
{
  return {this, "base-io-stream"};
}


} // namespace Gio


