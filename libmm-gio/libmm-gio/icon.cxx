// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/icon.hxx>
#include <libmm-gio/icon_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/error.hxx>

namespace Gio
{

  auto
  Icon::equal (const Glib::RefPtr<Icon>& other) const -> bool
  {
    return static_cast<bool> (
        g_icon_equal (const_cast<GIcon*> (this->gobj ()), other->gobj ()));
  }

  auto
  Icon::create (const std::string& str) -> Glib::RefPtr<Icon>
  {
    GError* gerror = nullptr;
    const auto icon = g_icon_new_for_string (str.c_str (), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return Glib::wrap (icon);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GIcon* object, const bool take_copy) -> RefPtr<Gio::Icon>
  {
    return Glib::make_refptr_for_instance<Gio::Icon> (
        Glib::wrap_auto_interface<Gio::Icon> ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  Icon_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Icon_Class::iface_init_function;

      gtype_ = g_icon_get_type ();
    }

    return *this;
  }

  auto
  Icon_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Icon_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Icon ((GIcon*) object);
  }

  Icon::Icon ()
    : Interface (icon_class_.init ())
  {
  }

  Icon::Icon (GIcon* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Icon::Icon (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Icon::Icon (Icon&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Icon::operator= (Icon&& src) noexcept -> Icon&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Icon::~Icon () noexcept = default;

  auto
  Icon::add_interface (const GType gtype_implementer) -> void
  {
    icon_class_.init ().add_interface (gtype_implementer);
  }

  Icon::CppClassType Icon::icon_class_;

  auto
  Icon::get_type () -> GType
  {
    return icon_class_.init ().get_type ();
  }

  auto
  Icon::get_base_type () -> GType
  {
    return g_icon_get_type ();
  }

  auto
  Icon::hash () const -> guint
  {
    return g_icon_hash (gobj ());
  }

  auto
  Icon::to_string () const -> std::string
  {
    return Glib::convert_return_gchar_ptr_to_stdstring (
        g_icon_to_string (const_cast<GIcon*> (gobj ())));
  }

  auto
  Icon::serialize () const -> Glib::VariantBase
  {
    return Glib::wrap (g_icon_serialize (const_cast<GIcon*> (gobj ())), false);
  }

  auto
  Icon::deserialize (const Glib::VariantBase& value) -> Glib::RefPtr<Icon>
  {
    return Glib::wrap (
        g_icon_deserialize (const_cast<GVariant*> (value.gobj ())));
  }

} // namespace Gio
