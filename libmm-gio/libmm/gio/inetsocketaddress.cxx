// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/inetsocketaddress.hxx>
#include <libmm/gio/inetsocketaddress_p.hxx>

#include <gio/gio.h>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GInetSocketAddress* object, const bool take_copy) -> RefPtr<gio::InetSocketAddress>
  {
    return glib::make_refptr_for_instance<gio::InetSocketAddress> (
        dynamic_cast<gio::InetSocketAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  InetSocketAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &InetSocketAddress_Class::class_init_function;

      register_derived_type (g_inet_socket_address_get_type ());
    }

    return *this;
  }

  auto
  InetSocketAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  InetSocketAddress_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new InetSocketAddress ((GInetSocketAddress*) object);
  }

  auto
  InetSocketAddress::gobj_copy () -> GInetSocketAddress*
  {
    reference ();
    return gobj ();
  }

  InetSocketAddress::InetSocketAddress (
      const glib::ConstructParams& construct_params)
    : SocketAddress (construct_params)
  {
  }

  InetSocketAddress::InetSocketAddress (GInetSocketAddress* castitem)
    : SocketAddress ((GSocketAddress*) castitem)
  {
  }

  InetSocketAddress::InetSocketAddress (InetSocketAddress&& src) noexcept
    : SocketAddress (std::move (src))
  {
  }

  auto
  InetSocketAddress::operator= (InetSocketAddress&& src) noexcept -> InetSocketAddress&
  {
    SocketAddress::operator= (std::move (src));
    return *this;
  }

  InetSocketAddress::~InetSocketAddress () noexcept = default;

  InetSocketAddress::CppClassType InetSocketAddress::inetsocketaddress_class_;

  auto
  InetSocketAddress::get_type () -> GType
  {
    return inetsocketaddress_class_.init ().get_type ();
  }

  auto
  InetSocketAddress::get_base_type () -> GType
  {
    return g_inet_socket_address_get_type ();
  }

  InetSocketAddress::InetSocketAddress (
      const glib::RefPtr<InetAddress>& address,
      const guint16 port)
    : ObjectBase (nullptr),
      SocketAddress (glib::ConstructParams (inetsocketaddress_class_.init (),
                                            "address",
                                            glib::unwrap (address),
                                            "port",
                                            port,
                                            nullptr))
  {
  }

  auto
  InetSocketAddress::create (const glib::RefPtr<InetAddress>& address,
                             const guint16 port) -> glib::RefPtr<InetSocketAddress>
  {
    return glib::make_refptr_for_instance<InetSocketAddress> (
        new InetSocketAddress (address, port));
  }

  auto
  InetSocketAddress::get_address () -> glib::RefPtr<InetAddress>
  {
    auto retvalue = glib::wrap (g_inet_socket_address_get_address (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  InetSocketAddress::get_address () const -> glib::RefPtr<const InetAddress>
  {
    return const_cast<InetSocketAddress*> (this)->get_address ();
  }

  auto
  InetSocketAddress::get_port () const -> guint16
  {
    return g_inet_socket_address_get_port (
        const_cast<GInetSocketAddress*> (gobj ()));
  }

  auto
  InetSocketAddress::get_flowinfo () const -> guint32
  {
    return g_inet_socket_address_get_flowinfo (
        const_cast<GInetSocketAddress*> (gobj ()));
  }

  auto
  InetSocketAddress::get_scope_id () const -> guint32
  {
    return g_inet_socket_address_get_scope_id (
        const_cast<GInetSocketAddress*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<InetAddress>>::value,
      "Type glib::RefPtr<InetAddress> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  InetSocketAddress::property_address () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InetAddress>>
  {
    return {this, "address"};
  }

  auto
  InetSocketAddress::property_port () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "port"};
  }

  auto
  InetSocketAddress::property_flowinfo () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "flowinfo"};
  }

  auto
  InetSocketAddress::property_scope_id () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "scope-id"};
  }

} // namespace gio
