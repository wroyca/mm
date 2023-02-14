

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketaddress.hxx>
#include <libmm-gio/socketaddress_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/error.hxx>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketAddress* object, const bool take_copy) -> RefPtr<Gio::SocketAddress>
  {
    return Glib::make_refptr_for_instance<Gio::SocketAddress> (
        dynamic_cast<Gio::SocketAddress*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketAddress_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketAddress_Class::class_init_function;

      register_derived_type (g_socket_address_get_type ());

      SocketConnectable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  SocketAddress_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SocketAddress_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketAddress ((GSocketAddress*) object);
  }

  auto
  SocketAddress::gobj_copy () -> GSocketAddress*
  {
    reference ();
    return gobj ();
  }

  SocketAddress::SocketAddress (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SocketAddress::SocketAddress (GSocketAddress* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SocketAddress::SocketAddress (SocketAddress&& src) noexcept
    : Object (std::move (src)),
      SocketConnectable (std::move (src))
  {
  }

  auto
  SocketAddress::operator= (SocketAddress&& src) noexcept -> SocketAddress&
  {
    Object::operator= (std::move (src));
    SocketConnectable::operator= (std::move (src));
    return *this;
  }

  SocketAddress::~SocketAddress () noexcept = default;

  SocketAddress::CppClassType SocketAddress::socketaddress_class_;

  auto
  SocketAddress::get_type () -> GType
  {
    return socketaddress_class_.init ().get_type ();
  }

  auto
  SocketAddress::get_base_type () -> GType
  {
    return g_socket_address_get_type ();
  }

  auto
  SocketAddress::create (const gpointer native, const gsize len) -> Glib::RefPtr<SocketAddress>
  {
    return Glib::wrap (g_socket_address_new_from_native (native, len));
  }

  auto
  SocketAddress::get_family () const -> SocketFamily
  {
    return static_cast<SocketFamily> (
        g_socket_address_get_family (const_cast<GSocketAddress*> (gobj ())));
  }

  auto
  SocketAddress::to_native (const gpointer dest, const gsize destlen) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_socket_address_to_native (gobj (), dest, destlen, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  SocketAddress::get_native_size () const -> gssize
  {
    return g_socket_address_get_native_size (
        const_cast<GSocketAddress*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
      "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SocketAddress::property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>
  {
    return {this, "family"};
  }

} // namespace Gio
