// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/networkservice.hxx>
#include <libmm/gio/networkservice_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>

namespace gio
{
}

namespace
{
}

namespace glib
{

  auto
  wrap (GNetworkService* object, const bool take_copy) -> RefPtr<gio::NetworkService>
  {
    return glib::make_refptr_for_instance<gio::NetworkService> (
        dynamic_cast<gio::NetworkService*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  NetworkService_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NetworkService_Class::class_init_function;

      register_derived_type (g_network_service_get_type ());

      SocketConnectable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  NetworkService_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NetworkService_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NetworkService ((GNetworkService*) object);
  }

  auto
  NetworkService::gobj_copy () -> GNetworkService*
  {
    reference ();
    return gobj ();
  }

  NetworkService::NetworkService (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  NetworkService::NetworkService (GNetworkService* castitem)
    : Object ((GObject*) castitem)
  {
  }

  NetworkService::NetworkService (NetworkService&& src) noexcept
    : Object (std::move (src)),
      SocketConnectable (std::move (src))
  {
  }

  auto
  NetworkService::operator= (NetworkService&& src) noexcept -> NetworkService&
  {
    Object::operator= (std::move (src));
    SocketConnectable::operator= (std::move (src));
    return *this;
  }

  NetworkService::~NetworkService () noexcept = default;

  NetworkService::CppClassType NetworkService::networkservice_class_;

  auto
  NetworkService::get_type () -> GType
  {
    return networkservice_class_.init ().get_type ();
  }

  auto
  NetworkService::get_base_type () -> GType
  {
    return g_network_service_get_type ();
  }

  NetworkService::NetworkService (const glib::ustring& service,
                                  const glib::ustring& protocol,
                                  const glib::ustring& domain)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (networkservice_class_.init (),
                                     "service",
                                     service.c_str (),
                                     "protocol",
                                     protocol.c_str (),
                                     "domain",
                                     domain.c_str (),
                                     nullptr))
  {
  }

  auto
  NetworkService::create (const glib::ustring& service,
                          const glib::ustring& protocol,
                          const glib::ustring& domain) -> glib::RefPtr<NetworkService>
  {
    return glib::make_refptr_for_instance<NetworkService> (
        new NetworkService (service, protocol, domain));
  }

  auto
  NetworkService::get_service () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_service (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_protocol () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_protocol (
            const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_domain () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_domain (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_scheme () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_scheme (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::set_scheme (const glib::ustring& scheme) -> void
  {
    g_network_service_set_scheme (gobj (), scheme.c_str ());
  }

  auto
  NetworkService::property_domain () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "domain"};
  }

  auto
  NetworkService::property_protocol () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "protocol"};
  }

  auto
  NetworkService::property_scheme () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "scheme"};
  }

  auto
  NetworkService::property_scheme () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "scheme"};
  }

  auto
  NetworkService::property_service () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "service"};
  }

} // namespace gio
