


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/unixsocketaddress.hpp>
#include <libmm-gio/unixsocketaddress_p.hpp>


/* Copyright (C) 2010 The giomm Development Team
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

#include <gio/gunixsocketaddress.h>

using Type = Gio::UnixSocketAddress::Type;

namespace Gio
{

auto
UnixSocketAddress::create(const std::string& path, Type type, const int path_len) -> Glib::RefPtr<UnixSocketAddress>
{
  return Glib::wrap(reinterpret_cast<GUnixSocketAddress*>(g_unix_socket_address_new_with_type(
    path.c_str(), path_len, static_cast<GUnixSocketAddressType>(type))));
}

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::UnixSocketAddress::Type>::value_type() -> GType
{
  return g_unix_socket_address_type_get_type();
}


namespace Glib
{

auto wrap(GUnixSocketAddress* object, const bool take_copy) -> RefPtr<Gio::UnixSocketAddress>
{
  return Glib::make_refptr_for_instance<Gio::UnixSocketAddress>( dynamic_cast<Gio::UnixSocketAddress*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixSocketAddress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixSocketAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_socket_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto UnixSocketAddress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixSocketAddress_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixSocketAddress((GUnixSocketAddress*)object);
}


/* The implementation: */

auto UnixSocketAddress::gobj_copy() -> GUnixSocketAddress*
{
  reference();
  return gobj();
}

UnixSocketAddress::UnixSocketAddress(const Glib::ConstructParams& construct_params)
:
  SocketAddress(construct_params)
{

}

UnixSocketAddress::UnixSocketAddress(GUnixSocketAddress* castitem)
:
  SocketAddress((GSocketAddress*)castitem)
{}


UnixSocketAddress::UnixSocketAddress(UnixSocketAddress&& src) noexcept
: SocketAddress(std::move(src))
{}

auto UnixSocketAddress::operator=(UnixSocketAddress&& src) noexcept -> UnixSocketAddress&
{
  SocketAddress::operator=(std::move(src));
  return *this;
}


UnixSocketAddress::~UnixSocketAddress() noexcept = default;

UnixSocketAddress::CppClassType UnixSocketAddress::unixsocketaddress_class_; // initialize static member

auto UnixSocketAddress::get_type() -> GType
{
  return unixsocketaddress_class_.init().get_type();
}


auto UnixSocketAddress::get_base_type() -> GType
{
  return g_unix_socket_address_get_type();
}


UnixSocketAddress::UnixSocketAddress(const std::string& path)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  SocketAddress(Glib::ConstructParams(unixsocketaddress_class_.init(), "path", path.c_str(), nullptr))
{


}

auto UnixSocketAddress::create(const std::string& path) -> Glib::RefPtr<UnixSocketAddress>
{
  return Glib::make_refptr_for_instance<UnixSocketAddress>( new UnixSocketAddress(path) );
}

auto UnixSocketAddress::get_address_type() const -> Type
{
  return static_cast<Type>(g_unix_socket_address_get_address_type(const_cast<GUnixSocketAddress*>(gobj())));
}

auto UnixSocketAddress::get_path() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_unix_socket_address_get_path(const_cast<GUnixSocketAddress*>(gobj())));
}

auto UnixSocketAddress::abstract_names_supported() -> bool
{
  return g_unix_socket_address_abstract_names_supported();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto UnixSocketAddress::property_address_type() const -> Glib::PropertyProxy_ReadOnly< Type >
{
  return {this, "address-type"};
}

auto UnixSocketAddress::property_path() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "path"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ByteArray>>::value,
  "Type Glib::RefPtr<Glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto UnixSocketAddress::property_path_as_array() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ByteArray> >
{
  return {this, "path-as-array"};
}


} // namespace Gio


