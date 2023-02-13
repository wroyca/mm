


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/socketaddress.hpp>
#include <mm/gio/private/socketaddress_p.hpp>


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
#include <mm/glib/error.hpp>
#include <mm/gio/asyncresult.hpp>
#include <mm/gio/slot_async.hpp>

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSocketAddress* object, const bool take_copy) -> RefPtr<Gio::SocketAddress>
{
  return Glib::make_refptr_for_instance<Gio::SocketAddress>( dynamic_cast<Gio::SocketAddress*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SocketAddress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  SocketConnectable::add_interface(get_type());

  }

  return *this;
}


auto SocketAddress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SocketAddress_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketAddress((GSocketAddress*)object);
}


/* The implementation: */

auto SocketAddress::gobj_copy() -> GSocketAddress*
{
  reference();
  return gobj();
}

SocketAddress::SocketAddress(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SocketAddress::SocketAddress(GSocketAddress* castitem)
: Object((GObject*)castitem)
{}


SocketAddress::SocketAddress(SocketAddress&& src) noexcept
: Object(std::move(src))
  , SocketConnectable(std::move(src))
{}

auto SocketAddress::operator=(SocketAddress&& src) noexcept -> SocketAddress&
{
  Object::operator=(std::move(src));
  SocketConnectable::operator=(std::move(src));
  return *this;
}


SocketAddress::~SocketAddress() noexcept = default;

SocketAddress::CppClassType SocketAddress::socketaddress_class_; // initialize static member

auto SocketAddress::get_type() -> GType
{
  return socketaddress_class_.init().get_type();
}


auto SocketAddress::get_base_type() -> GType
{
  return g_socket_address_get_type();
}


auto SocketAddress::create(
  const gpointer native, const gsize len) -> Glib::RefPtr<SocketAddress>
{
  return Glib::wrap(g_socket_address_new_from_native(native, len));
}

auto SocketAddress::get_family() const -> SocketFamily
{
  return static_cast<SocketFamily>(g_socket_address_get_family(const_cast<GSocketAddress*>(gobj())));
}

auto SocketAddress::to_native(
  const gpointer dest, const gsize destlen) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_socket_address_to_native(gobj(), dest, destlen, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketAddress::get_native_size() const -> gssize
{
  return g_socket_address_get_native_size(const_cast<GSocketAddress*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
  "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketAddress::property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >
{
  return {this, "family"};
}


} // namespace Gio


