

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/inetaddress.hxx>
#include <libmm-gio/inetaddress_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  auto
  InetAddress::create (const Glib::ustring& string) -> Glib::RefPtr<InetAddress>
  {
    return Glib::wrap (g_inet_address_new_from_string (string.c_str ()));
  }

  auto
  InetAddress::create_any (SocketFamily family) -> Glib::RefPtr<InetAddress>
  {
    return Glib::wrap (g_inet_address_new_any ((GSocketFamily) family));
  }

  auto
  InetAddress::create_loopback (SocketFamily family) -> Glib::RefPtr<InetAddress>
  {
    return Glib::wrap (g_inet_address_new_loopback ((GSocketFamily) family));
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GInetAddress* object, const bool take_copy) -> RefPtr<Gio::InetAddress>
  {
    return Glib::make_refptr_for_instance<Gio::InetAddress> (
        dynamic_cast<Gio::InetAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  InetAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &InetAddress_Class::class_init_function;

      register_derived_type (g_inet_address_get_type ());
    }

    return *this;
  }

  auto
  InetAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  InetAddress_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new InetAddress ((GInetAddress*) object);
  }

  auto
  InetAddress::gobj_copy () -> GInetAddress*
  {
    reference ();
    return gobj ();
  }

  InetAddress::InetAddress (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  InetAddress::InetAddress (GInetAddress* castitem)
    : Object ((GObject*) castitem)
  {
  }

  InetAddress::InetAddress (InetAddress&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  InetAddress::operator= (InetAddress&& src) noexcept -> InetAddress&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  InetAddress::~InetAddress () noexcept = default;

  InetAddress::CppClassType InetAddress::inetaddress_class_;

  auto
  InetAddress::get_type () -> GType
  {
    return inetaddress_class_.init ().get_type ();
  }

  auto
  InetAddress::get_base_type () -> GType
  {
    return g_inet_address_get_type ();
  }

  InetAddress::InetAddress (const guint8* bytes, const SocketFamily family)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (inetaddress_class_.init (),
                                     "bytes",
                                     bytes,
                                     "family",
                                     family,
                                     nullptr))
  {
  }

  auto
  InetAddress::create (const guint8* bytes, const SocketFamily family) -> Glib::RefPtr<InetAddress>
  {
    return Glib::make_refptr_for_instance<InetAddress> (
        new InetAddress (bytes, family));
  }

  auto
  InetAddress::address_equal (
      const Glib::RefPtr<const InetAddress>& other_address) const -> bool
  {
    return g_inet_address_equal (
        const_cast<GInetAddress*> (gobj ()),
        const_cast<GInetAddress*> (Glib::unwrap (other_address)));
  }

  auto
  InetAddress::to_bytes () const -> const guint8*
  {
    return g_inet_address_to_bytes (const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_inet_address_to_string (const_cast<GInetAddress*> (gobj ())));
  }

  auto
  InetAddress::get_family () const -> SocketFamily
  {
    return static_cast<SocketFamily> (
        g_inet_address_get_family (const_cast<GInetAddress*> (gobj ())));
  }

  auto
  InetAddress::get_is_any () const -> bool
  {
    return g_inet_address_get_is_any (const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_link_local () const -> bool
  {
    return g_inet_address_get_is_link_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_loopback () const -> bool
  {
    return g_inet_address_get_is_loopback (const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_mc_global () const -> bool
  {
    return g_inet_address_get_is_mc_global (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_mc_link_local () const -> bool
  {
    return g_inet_address_get_is_mc_link_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_mc_node_local () const -> bool
  {
    return g_inet_address_get_is_mc_node_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_mc_org_local () const -> bool
  {
    return g_inet_address_get_is_mc_org_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_mc_site_local () const -> bool
  {
    return g_inet_address_get_is_mc_site_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_multicast () const -> bool
  {
    return g_inet_address_get_is_multicast (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_is_site_local () const -> bool
  {
    return g_inet_address_get_is_site_local (
        const_cast<GInetAddress*> (gobj ()));
  }

  auto
  InetAddress::get_native_size () const -> gsize
  {
    return g_inet_address_get_native_size (const_cast<GInetAddress*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<void*>::value,
      "Type void* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  InetAddress::property_bytes () const -> Glib::PropertyProxy_ReadOnly<void*>
  {
    return {this, "bytes"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
      "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  InetAddress::property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>
  {
    return {this, "family"};
  }

  auto
  InetAddress::property_is_any () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-any"};
  }

  auto
  InetAddress::property_is_link_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-link-local"};
  }

  auto
  InetAddress::property_is_loopback () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-loopback"};
  }

  auto
  InetAddress::property_is_mc_global () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-mc-global"};
  }

  auto
  InetAddress::property_is_mc_link_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-mc-link-local"};
  }

  auto
  InetAddress::property_is_mc_node_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-mc-node-local"};
  }

  auto
  InetAddress::property_is_mc_org_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-mc-org-local"};
  }

  auto
  InetAddress::property_is_mc_site_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-mc-site-local"};
  }

  auto
  InetAddress::property_is_multicast () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-multicast"};
  }

  auto
  InetAddress::property_is_site_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-site-local"};
  }

} // namespace Gio
