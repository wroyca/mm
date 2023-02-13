


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/inetsocketaddress.hxx>
#include <libmm-gio/inetsocketaddress_p.hxx>


/* Copyright (C) 2008 Jonathon Jongsma
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

auto wrap(GInetSocketAddress* object, const bool take_copy) -> RefPtr<Gio::InetSocketAddress>
{
  return Glib::make_refptr_for_instance<Gio::InetSocketAddress>( dynamic_cast<Gio::InetSocketAddress*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto InetSocketAddress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &InetSocketAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_inet_socket_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto InetSocketAddress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto InetSocketAddress_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new InetSocketAddress((GInetSocketAddress*)object);
}


/* The implementation: */

auto InetSocketAddress::gobj_copy() -> GInetSocketAddress*
{
  reference();
  return gobj();
}

InetSocketAddress::InetSocketAddress(const Glib::ConstructParams& construct_params)
:
  SocketAddress(construct_params)
{

}

InetSocketAddress::InetSocketAddress(GInetSocketAddress* castitem)
:
  SocketAddress((GSocketAddress*)castitem)
{}


InetSocketAddress::InetSocketAddress(InetSocketAddress&& src) noexcept
: SocketAddress(std::move(src))
{}

auto InetSocketAddress::operator=(InetSocketAddress&& src) noexcept -> InetSocketAddress&
{
  SocketAddress::operator=(std::move(src));
  return *this;
}


InetSocketAddress::~InetSocketAddress() noexcept = default;

InetSocketAddress::CppClassType InetSocketAddress::inetsocketaddress_class_; // initialize static member

auto InetSocketAddress::get_type() -> GType
{
  return inetsocketaddress_class_.init().get_type();
}


auto InetSocketAddress::get_base_type() -> GType
{
  return g_inet_socket_address_get_type();
}


InetSocketAddress::InetSocketAddress(const Glib::RefPtr<InetAddress>& address, const guint16 port)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  SocketAddress(Glib::ConstructParams(inetsocketaddress_class_.init(), "address", Glib::unwrap(address), "port", port, nullptr))
{


}

auto InetSocketAddress::create(const Glib::RefPtr<InetAddress>& address, const guint16 port) -> Glib::RefPtr<InetSocketAddress>
{
  return Glib::make_refptr_for_instance<InetSocketAddress>( new InetSocketAddress(address, port) );
}

auto InetSocketAddress::get_address() -> Glib::RefPtr<InetAddress>
{
  auto retvalue = Glib::wrap(g_inet_socket_address_get_address(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto InetSocketAddress::get_address() const -> Glib::RefPtr<const InetAddress>
{
  return const_cast<InetSocketAddress*>(this)->get_address();
}

auto InetSocketAddress::get_port() const -> guint16
{
  return g_inet_socket_address_get_port(const_cast<GInetSocketAddress*>(gobj()));
}

auto InetSocketAddress::get_flowinfo() const -> guint32
{
  return g_inet_socket_address_get_flowinfo(const_cast<GInetSocketAddress*>(gobj()));
}

auto InetSocketAddress::get_scope_id() const -> guint32
{
  return g_inet_socket_address_get_scope_id(const_cast<GInetSocketAddress*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<InetAddress>>::value,
  "Type Glib::RefPtr<InetAddress> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto InetSocketAddress::property_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InetAddress> >
{
  return {this, "address"};
}

auto InetSocketAddress::property_port() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "port"};
}

auto InetSocketAddress::property_flowinfo() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "flowinfo"};
}

auto InetSocketAddress::property_scope_id() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "scope-id"};
}


} // namespace Gio

