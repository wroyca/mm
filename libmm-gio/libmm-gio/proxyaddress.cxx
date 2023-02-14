

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/proxyaddress.hxx>
#include <libmm-gio/proxyaddress_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GProxyAddress* object, const bool take_copy) -> RefPtr<Gio::ProxyAddress>
  {
    return Glib::make_refptr_for_instance<Gio::ProxyAddress> (
        dynamic_cast<Gio::ProxyAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  ProxyAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ProxyAddress_Class::class_init_function;

      register_derived_type (g_proxy_address_get_type ());
    }

    return *this;
  }

  auto
  ProxyAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ProxyAddress_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ProxyAddress ((GProxyAddress*) object);
  }

  auto
  ProxyAddress::gobj_copy () -> GProxyAddress*
  {
    reference ();
    return gobj ();
  }

  ProxyAddress::ProxyAddress (const Glib::ConstructParams& construct_params)
    : InetSocketAddress (construct_params)
  {
  }

  ProxyAddress::ProxyAddress (GProxyAddress* castitem)
    : InetSocketAddress ((GInetSocketAddress*) castitem)
  {
  }

  ProxyAddress::ProxyAddress (ProxyAddress&& src) noexcept
    : InetSocketAddress (std::move (src))
  {
  }

  auto
  ProxyAddress::operator= (ProxyAddress&& src) noexcept -> ProxyAddress&
  {
    InetSocketAddress::operator= (std::move (src));
    return *this;
  }

  ProxyAddress::~ProxyAddress () noexcept = default;

  ProxyAddress::CppClassType ProxyAddress::proxyaddress_class_;

  auto
  ProxyAddress::get_type () -> GType
  {
    return proxyaddress_class_.init ().get_type ();
  }

  auto
  ProxyAddress::get_base_type () -> GType
  {
    return g_proxy_address_get_type ();
  }

  ProxyAddress::ProxyAddress (const Glib::RefPtr<InetAddress>& address,
                              const guint16 port,
                              const Glib::ustring& protocol,
                              const Glib::ustring& destination_hostname,
                              const guint16 destination_port,
                              const Glib::ustring& username,
                              const Glib::ustring& password)
    : ObjectBase (nullptr),
      InetSocketAddress (Glib::ConstructParams (proxyaddress_class_.init (),
                                                "address",
                                                Glib::unwrap (address),
                                                "port",
                                                port,
                                                "protocol",
                                                protocol.c_str (),
                                                "destination_hostname",
                                                destination_hostname.c_str (),
                                                "destination_port",
                                                destination_port,
                                                "username",
                                                username.c_str (),
                                                "password",
                                                password.c_str (),
                                                nullptr))
  {
  }

  auto
  ProxyAddress::create (const Glib::RefPtr<InetAddress>& address,
                        const guint16 port,
                        const Glib::ustring& protocol,
                        const Glib::ustring& destination_hostname,
                        const guint16 destination_port,
                        const Glib::ustring& username,
                        const Glib::ustring& password) -> Glib::RefPtr<ProxyAddress>
  {
    return Glib::make_refptr_for_instance<ProxyAddress> (
        new ProxyAddress (address,
                          port,
                          protocol,
                          destination_hostname,
                          destination_port,
                          username,
                          password));
  }

  auto
  ProxyAddress::get_protocol () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_protocol (const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::get_destination_protocol () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_destination_protocol (
            const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::get_destination_hostname () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_destination_hostname (
            const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::get_destination_port () const -> guint16
  {
    return g_proxy_address_get_destination_port (
        const_cast<GProxyAddress*> (gobj ()));
  }

  auto
  ProxyAddress::get_username () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_username (const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::get_password () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_password (const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::get_uri () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_proxy_address_get_uri (const_cast<GProxyAddress*> (gobj ())));
  }

  auto
  ProxyAddress::property_protocol () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "protocol"};
  }

  auto
  ProxyAddress::property_destination_protocol () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "destination-protocol"};
  }

  auto
  ProxyAddress::property_destination_hostname () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "destination-hostname"};
  }

  auto
  ProxyAddress::property_destination_port () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "destination-port"};
  }

  auto
  ProxyAddress::property_username () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "username"};
  }

  auto
  ProxyAddress::property_password () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "password"};
  }

  auto
  ProxyAddress::property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "uri"};
  }

} // namespace Gio
