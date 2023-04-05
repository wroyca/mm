// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/networkaddress.hxx>
#include <libmm/gio/networkaddress_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{

  auto
  NetworkAddress::parse (const std::string& host_and_port,
                         const guint16 default_port) -> glib::RefPtr<NetworkAddress>
  {
    GError* error = nullptr;
    auto* address = G_NETWORK_ADDRESS (
        g_network_address_parse (host_and_port.c_str (), default_port, &error));
    if (error)
      glib::Error::throw_exception (error);

    return glib::wrap (address);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GNetworkAddress* object, const bool take_copy) -> RefPtr<gio::NetworkAddress>
  {
    return glib::make_refptr_for_instance<gio::NetworkAddress> (
        dynamic_cast<gio::NetworkAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  NetworkAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NetworkAddress_Class::class_init_function;

      register_derived_type (g_network_address_get_type ());

      SocketConnectable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  NetworkAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NetworkAddress_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NetworkAddress ((GNetworkAddress*) object);
  }

  auto
  NetworkAddress::gobj_copy () -> GNetworkAddress*
  {
    reference ();
    return gobj ();
  }

  NetworkAddress::NetworkAddress (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  NetworkAddress::NetworkAddress (GNetworkAddress* castitem)
    : Object ((GObject*) castitem)
  {
  }

  NetworkAddress::NetworkAddress (NetworkAddress&& src) noexcept
    : Object (std::move (src)),
      SocketConnectable (std::move (src))
  {
  }

  auto
  NetworkAddress::operator= (NetworkAddress&& src) noexcept -> NetworkAddress&
  {
    Object::operator= (std::move (src));
    SocketConnectable::operator= (std::move (src));
    return *this;
  }

  NetworkAddress::~NetworkAddress () noexcept = default;

  NetworkAddress::CppClassType NetworkAddress::networkaddress_class_;

  auto
  NetworkAddress::get_type () -> GType
  {
    return networkaddress_class_.init ().get_type ();
  }

  auto
  NetworkAddress::get_base_type () -> GType
  {
    return g_network_address_get_type ();
  }

  NetworkAddress::NetworkAddress (const std::string& hostname,
                                  const guint16 port)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (networkaddress_class_.init (),
                                     "hostname",
                                     hostname.c_str (),
                                     "port",
                                     port,
                                     nullptr))
  {
  }

  auto
  NetworkAddress::create (const std::string& hostname, const guint16 port) -> glib::RefPtr<NetworkAddress>
  {
    return glib::make_refptr_for_instance<NetworkAddress> (
        new NetworkAddress (hostname, port));
  }

  auto
  NetworkAddress::get_hostname () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_network_address_get_hostname (
            const_cast<GNetworkAddress*> (gobj ())));
  }

  auto
  NetworkAddress::get_port () const -> guint16
  {
    return g_network_address_get_port (const_cast<GNetworkAddress*> (gobj ()));
  }

  auto
  NetworkAddress::get_scheme () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_network_address_get_scheme (const_cast<GNetworkAddress*> (gobj ())));
  }

  auto
  NetworkAddress::property_hostname () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "hostname"};
  }

  auto
  NetworkAddress::property_port () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "port"};
  }

  auto
  NetworkAddress::property_scheme () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "scheme"};
  }

} // namespace gio
