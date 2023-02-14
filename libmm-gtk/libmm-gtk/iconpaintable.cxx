// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/iconpaintable.hxx>
#include <libmm-gtk/iconpaintable_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkIconPaintable* object, const bool take_copy) -> RefPtr<Gtk::IconPaintable>
  {
    return Glib::make_refptr_for_instance<Gtk::IconPaintable> (
        dynamic_cast<Gtk::IconPaintable*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  IconPaintable_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &IconPaintable_Class::class_init_function;

      register_derived_type (gtk_icon_paintable_get_type ());

      Gdk::Paintable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  IconPaintable_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  IconPaintable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new IconPaintable ((GtkIconPaintable*) object);
  }

  auto
  IconPaintable::gobj_copy () -> GtkIconPaintable*
  {
    reference ();
    return gobj ();
  }

  IconPaintable::IconPaintable (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  IconPaintable::IconPaintable (GtkIconPaintable* castitem)
    : Object ((GObject*) castitem)
  {
  }

  IconPaintable::IconPaintable (IconPaintable&& src) noexcept
    : Object (std::move (src)),
      Paintable (std::move (src))
  {
  }

  auto
  IconPaintable::operator= (IconPaintable&& src) noexcept -> IconPaintable&
  {
    Object::operator= (std::move (src));
    Paintable::operator= (std::move (src));
    return *this;
  }

  IconPaintable::~IconPaintable () noexcept = default;

  IconPaintable::CppClassType IconPaintable::iconpaintable_class_;

  auto
  IconPaintable::get_type () -> GType
  {
    return iconpaintable_class_.init ().get_type ();
  }

  auto
  IconPaintable::get_base_type () -> GType
  {
    return gtk_icon_paintable_get_type ();
  }

  auto
  IconPaintable::create (const Glib::RefPtr<Gio::File>& file,
                         const int size,
                         const int scale) -> Glib::RefPtr<IconPaintable>
  {
    return Glib::wrap (
        gtk_icon_paintable_new_for_file (Glib::unwrap<Gio::File> (file),
                                         size,
                                         scale));
  }

  auto
  IconPaintable::get_file () const -> Glib::RefPtr<Gio::File>
  {
    return Glib::wrap (
        gtk_icon_paintable_get_file (const_cast<GtkIconPaintable*> (gobj ())));
  }

  auto
  IconPaintable::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_icon_paintable_get_icon_name (
            const_cast<GtkIconPaintable*> (gobj ())));
  }

  auto
  IconPaintable::is_symbolic () const -> bool
  {
    return gtk_icon_paintable_is_symbolic (
        const_cast<GtkIconPaintable*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconPaintable::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return {this, "file"};
  }

  auto
  IconPaintable::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  IconPaintable::property_is_symbolic () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "is-symbolic"};
  }

} // namespace Gtk
