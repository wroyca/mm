// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/networkservice.hxx>
#include <libmm/gio/networkservice_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GNetworkService* object, const bool take_copy) -> RefPtr<Gio::NetworkService>
  {
    return Glib::make_refptr_for_instance<Gio::NetworkService> (
        dynamic_cast<Gio::NetworkService*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  NetworkService_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new NetworkService ((GNetworkService*) object);
  }

  auto
  NetworkService::gobj_copy () -> GNetworkService*
  {
    reference ();
    return gobj ();
  }

  NetworkService::NetworkService (const Glib::ConstructParams& construct_params)
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

  NetworkService::NetworkService (const Glib::ustring& service,
                                  const Glib::ustring& protocol,
                                  const Glib::ustring& domain)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (networkservice_class_.init (),
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
  NetworkService::create (const Glib::ustring& service,
                          const Glib::ustring& protocol,
                          const Glib::ustring& domain) -> Glib::RefPtr<NetworkService>
  {
    return Glib::make_refptr_for_instance<NetworkService> (
        new NetworkService (service, protocol, domain));
  }

  auto
  NetworkService::get_service () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_service (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_protocol () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_protocol (
            const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_domain () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_domain (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::get_scheme () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_network_service_get_scheme (const_cast<GNetworkService*> (gobj ())));
  }

  auto
  NetworkService::set_scheme (const Glib::ustring& scheme) -> void
  {
    g_network_service_set_scheme (gobj (), scheme.c_str ());
  }

  auto
  NetworkService::property_domain () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "domain"};
  }

  auto
  NetworkService::property_protocol () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "protocol"};
  }

  auto
  NetworkService::property_scheme () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "scheme"};
  }

  auto
  NetworkService::property_scheme () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "scheme"};
  }

  auto
  NetworkService::property_service () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "service"};
  }

} // namespace Gio
