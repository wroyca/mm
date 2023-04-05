// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/iconpaintable.hxx>
#include <libmm/gtk/iconpaintable_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkIconPaintable* object, bool take_copy) -> glib::RefPtr<gtk::IconPaintable>
  {
    return glib::make_refptr_for_instance<gtk::IconPaintable> (
        dynamic_cast<gtk::IconPaintable*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  IconPaintable_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &IconPaintable_Class::class_init_function;

      register_derived_type (gtk_icon_paintable_get_type ());

      gdk::Paintable::add_interface (get_type ());
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
  IconPaintable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new IconPaintable ((GtkIconPaintable*) object);
  }

  auto
  IconPaintable::gobj_copy () -> GtkIconPaintable*
  {
    reference ();
    return gobj ();
  }

  IconPaintable::IconPaintable (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  IconPaintable::IconPaintable (GtkIconPaintable* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  IconPaintable::IconPaintable (IconPaintable&& src) noexcept
    : glib::Object (std::move (src)),
      gdk::Paintable (std::move (src))
  {
  }

  auto
  IconPaintable::operator= (IconPaintable&& src) noexcept -> IconPaintable&
  {
    glib::Object::operator= (std::move (src));
    gdk::Paintable::operator= (std::move (src));
    return *this;
  }

  IconPaintable::~IconPaintable () noexcept {}

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
  IconPaintable::create (const glib::RefPtr<gio::File>& file,
                         int size,
                         int scale) -> glib::RefPtr<IconPaintable>
  {
    return glib::wrap (gtk_icon_paintable_new_for_file (
        const_cast<GFile*> (glib::unwrap<gio::File> (file)),
        size,
        scale));
  }

  auto
  IconPaintable::get_file () const -> glib::RefPtr<gio::File>
  {
    return glib::wrap (
        gtk_icon_paintable_get_file (const_cast<GtkIconPaintable*> (gobj ())));
  }

  auto
  IconPaintable::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  IconPaintable::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  IconPaintable::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  IconPaintable::property_is_symbolic () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-symbolic");
  }

} // namespace gtk
