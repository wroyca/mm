// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/unixsocketaddress.hxx>
#include <libmm/gio/unixsocketaddress_p.hxx>

#include <gio/gunixsocketaddress.h>

using Type = gio::UnixSocketAddress::Type;

namespace gio
{

  auto
  UnixSocketAddress::create (const std::string& path,
                             Type type,
                             const int path_len) -> glib::RefPtr<UnixSocketAddress>
  {
    return glib::wrap (reinterpret_cast<GUnixSocketAddress*> (
        g_unix_socket_address_new_with_type (
            path.c_str (),
            path_len,
            static_cast<GUnixSocketAddressType> (type))));
  }

} // namespace gio

namespace
{
}

auto
glib::Value<gio::UnixSocketAddress::Type>::value_type () -> GType
{
  return g_unix_socket_address_type_get_type ();
}

namespace glib
{

  auto
  wrap (GUnixSocketAddress* object, const bool take_copy) -> RefPtr<gio::UnixSocketAddress>
  {
    return glib::make_refptr_for_instance<gio::UnixSocketAddress> (
        dynamic_cast<gio::UnixSocketAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixSocketAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixSocketAddress_Class::class_init_function;

      register_derived_type (g_unix_socket_address_get_type ());
    }

    return *this;
  }

  auto
  UnixSocketAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixSocketAddress_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixSocketAddress ((GUnixSocketAddress*) object);
  }

  auto
  UnixSocketAddress::gobj_copy () -> GUnixSocketAddress*
  {
    reference ();
    return gobj ();
  }

  UnixSocketAddress::UnixSocketAddress (
      const glib::ConstructParams& construct_params)
    : SocketAddress (construct_params)
  {
  }

  UnixSocketAddress::UnixSocketAddress (GUnixSocketAddress* castitem)
    : SocketAddress ((GSocketAddress*) castitem)
  {
  }

  UnixSocketAddress::UnixSocketAddress (UnixSocketAddress&& src) noexcept
    : SocketAddress (std::move (src))
  {
  }

  auto
  UnixSocketAddress::operator= (UnixSocketAddress&& src) noexcept -> UnixSocketAddress&
  {
    SocketAddress::operator= (std::move (src));
    return *this;
  }

  UnixSocketAddress::~UnixSocketAddress () noexcept = default;

  UnixSocketAddress::CppClassType UnixSocketAddress::unixsocketaddress_class_;

  auto
  UnixSocketAddress::get_type () -> GType
  {
    return unixsocketaddress_class_.init ().get_type ();
  }

  auto
  UnixSocketAddress::get_base_type () -> GType
  {
    return g_unix_socket_address_get_type ();
  }

  UnixSocketAddress::UnixSocketAddress (const std::string& path)
    : ObjectBase (nullptr),
      SocketAddress (glib::ConstructParams (unixsocketaddress_class_.init (),
                                            "path",
                                            path.c_str (),
                                            nullptr))
  {
  }

  auto
  UnixSocketAddress::create (const std::string& path) -> glib::RefPtr<UnixSocketAddress>
  {
    return glib::make_refptr_for_instance<UnixSocketAddress> (
        new UnixSocketAddress (path));
  }

  auto
  UnixSocketAddress::get_address_type () const -> Type
  {
    return static_cast<Type> (g_unix_socket_address_get_address_type (
        const_cast<GUnixSocketAddress*> (gobj ())));
  }

  auto
  UnixSocketAddress::get_path () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_unix_socket_address_get_path (
            const_cast<GUnixSocketAddress*> (gobj ())));
  }

  auto
  UnixSocketAddress::abstract_names_supported () -> bool
  {
    return g_unix_socket_address_abstract_names_supported ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  UnixSocketAddress::property_address_type () const -> glib::PropertyProxy_ReadOnly<Type>
  {
    return {this, "address-type"};
  }

  auto
  UnixSocketAddress::property_path () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "path"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ByteArray>>::value,
      "Type glib::RefPtr<glib::ByteArray> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  UnixSocketAddress::property_path_as_array () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>
  {
    return {this, "path-as-array"};
  }

} // namespace gio
