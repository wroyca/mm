


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/networkaddress.hpp>
#include <libmm-gio/networkaddress_p.hpp>


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
#include <libmm-glib/error.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto
NetworkAddress::parse(const std::string& host_and_port, const guint16 default_port) -> Glib::RefPtr<NetworkAddress>
{
  GError* error = nullptr;
  auto* address =
    G_NETWORK_ADDRESS(g_network_address_parse(host_and_port.c_str(), default_port, &error));
  if (error)
    Glib::Error::throw_exception(error);

  return Glib::wrap(address);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GNetworkAddress* object, const bool take_copy) -> RefPtr<Gio::NetworkAddress>
{
  return Glib::make_refptr_for_instance<Gio::NetworkAddress>( dynamic_cast<Gio::NetworkAddress*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto NetworkAddress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NetworkAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_network_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  SocketConnectable::add_interface(get_type());

  }

  return *this;
}


auto NetworkAddress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto NetworkAddress_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new NetworkAddress((GNetworkAddress*)object);
}


/* The implementation: */

auto NetworkAddress::gobj_copy() -> GNetworkAddress*
{
  reference();
  return gobj();
}

NetworkAddress::NetworkAddress(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

NetworkAddress::NetworkAddress(GNetworkAddress* castitem)
: Object((GObject*)castitem)
{}


NetworkAddress::NetworkAddress(NetworkAddress&& src) noexcept
: Object(std::move(src))
  , SocketConnectable(std::move(src))
{}

auto NetworkAddress::operator=(NetworkAddress&& src) noexcept -> NetworkAddress&
{
  Object::operator=(std::move(src));
  SocketConnectable::operator=(std::move(src));
  return *this;
}


NetworkAddress::~NetworkAddress() noexcept = default;

NetworkAddress::CppClassType NetworkAddress::networkaddress_class_; // initialize static member

auto NetworkAddress::get_type() -> GType
{
  return networkaddress_class_.init().get_type();
}


auto NetworkAddress::get_base_type() -> GType
{
  return g_network_address_get_type();
}


NetworkAddress::NetworkAddress(const std::string& hostname, const guint16 port)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(networkaddress_class_.init(), "hostname", hostname.c_str(), "port", port, nullptr))
{


}

auto NetworkAddress::create(const std::string& hostname, const guint16 port) -> Glib::RefPtr<NetworkAddress>
{
  return Glib::make_refptr_for_instance<NetworkAddress>( new NetworkAddress(hostname, port) );
}

auto NetworkAddress::get_hostname() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_network_address_get_hostname(const_cast<GNetworkAddress*>(gobj())));
}

auto NetworkAddress::get_port() const -> guint16
{
  return g_network_address_get_port(const_cast<GNetworkAddress*>(gobj()));
}

auto NetworkAddress::get_scheme() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_network_address_get_scheme(const_cast<GNetworkAddress*>(gobj())));
}


auto NetworkAddress::property_hostname() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "hostname"};
}

auto NetworkAddress::property_port() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "port"};
}

auto NetworkAddress::property_scheme() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "scheme"};
}


} // namespace Gio


