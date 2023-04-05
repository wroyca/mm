// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/image.hxx>
#include <libmm/gtk/image_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

using Type = gtk::Image::Type;

namespace gtk
{

  Image::Image (const glib::RefPtr<gdk::Pixbuf>& pixbuf)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (image_class_.init ()))
  {
    gtk_image_set_from_pixbuf (gobj (), glib::unwrap (pixbuf));
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::Image::Type>::value_type () -> GType
{
  return gtk_image_type_get_type ();
}

namespace glib
{

  auto
  wrap (GtkImage* object, bool take_copy) -> gtk::Image*
  {
    return dynamic_cast<gtk::Image*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Image_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Image_Class::class_init_function;

      register_derived_type (gtk_image_get_type ());
    }

    return *this;
  }

  auto
  Image_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Image_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Image ((GtkImage*) (o)));
  }

  Image::Image (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Image::Image (GtkImage* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Image::Image (Image&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Image::operator= (Image&& src) noexcept -> Image&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Image::~Image () noexcept
  {
    destroy_ ();
  }

  Image::CppClassType Image::image_class_;

  auto
  Image::get_type () -> GType
  {
    return image_class_.init ().get_type ();
  }

  auto
  Image::get_base_type () -> GType
  {
    return gtk_image_get_type ();
  }

  Image::Image ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (image_class_.init ()))
  {
  }

  Image::Image (const std::string& file)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (image_class_.init (),
                                          "file",
                                          file.c_str (),
                                          nullptr))
  {
  }

  Image::Image (const glib::RefPtr<gdk::Paintable>& paintable)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (image_class_.init (),
                                          "paintable",
                                          glib::unwrap (paintable),
                                          nullptr))
  {
  }

  Image::Image (const glib::RefPtr<gio::Icon>& gicon)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (
          image_class_.init (),
          "gicon",
          const_cast<GIcon*> (glib::unwrap<gio::Icon> (gicon)),
          nullptr))
  {
  }

  auto
  Image::set (const std::string& filename) -> void
  {
    gtk_image_set_from_file (gobj (), filename.c_str ());
  }

  auto
  Image::set_from_resource (const std::string& resource_path) -> void
  {
    gtk_image_set_from_resource (gobj (), resource_path.c_str ());
  }

  auto
  Image::set (const glib::RefPtr<gdk::Pixbuf>& pixbuf) -> void
  {
    gtk_image_set_from_pixbuf (gobj (), glib::unwrap (pixbuf));
  }

  auto
  Image::set (const glib::RefPtr<gdk::Paintable>& paintable) -> void
  {
    gtk_image_set_from_paintable (gobj (), glib::unwrap (paintable));
  }

  auto
  Image::set (const glib::RefPtr<const gio::Icon>& icon) -> void
  {
    gtk_image_set_from_gicon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)));
  }

  auto
  Image::set_from_icon_name (const glib::ustring& icon_name) -> void
  {
    gtk_image_set_from_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  Image::clear () -> void
  {
    gtk_image_clear (gobj ());
  }

  auto
  Image::get_storage_type () const -> Type
  {
    return static_cast<Type> (
        gtk_image_get_storage_type (const_cast<GtkImage*> (gobj ())));
  }

  auto
  Image::get_paintable () -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (gtk_image_get_paintable (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Image::get_paintable () const -> glib::RefPtr<const gdk::Paintable>
  {
    return const_cast<Image*> (this)->get_paintable ();
  }

  auto
  Image::set_icon_size (IconSize icon_size) -> void
  {
    gtk_image_set_icon_size (gobj (), static_cast<GtkIconSize> (icon_size));
  }

  auto
  Image::get_icon_size () const -> IconSize
  {
    return static_cast<IconSize> (
        gtk_image_get_icon_size (const_cast<GtkImage*> (gobj ())));
  }

  auto
  Image::get_gicon () -> glib::RefPtr<gio::Icon>
  {
    auto retvalue = glib::wrap (gtk_image_get_gicon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Image::get_gicon () const -> glib::RefPtr<const gio::Icon>
  {
    return const_cast<Image*> (this)->get_gicon ();
  }

  auto
  Image::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_image_get_icon_name (const_cast<GtkImage*> (gobj ())));
  }

  auto
  Image::get_pixel_size () const -> int
  {
    return gtk_image_get_pixel_size (const_cast<GtkImage*> (gobj ()));
  }

  auto
  Image::set_pixel_size (int pixel_size) -> void
  {
    gtk_image_set_pixel_size (gobj (), pixel_size);
  }

  auto
  Image::property_file () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "file");
  }

  auto
  Image::property_file () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "file");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<IconSize>::value,
      "Type IconSize cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Image::property_icon_size () -> glib::PropertyProxy<IconSize>
  {
    return glib::PropertyProxy<IconSize> (this, "icon-size");
  }

  auto
  Image::property_icon_size () const -> glib::PropertyProxy_ReadOnly<IconSize>
  {
    return glib::PropertyProxy_ReadOnly<IconSize> (this, "icon-size");
  }

  auto
  Image::property_pixel_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixel-size");
  }

  auto
  Image::property_pixel_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixel-size");
  }

  auto
  Image::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  Image::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Image::property_storage_type () const -> glib::PropertyProxy_ReadOnly<Type>
  {
    return glib::PropertyProxy_ReadOnly<Type> (this, "storage-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Icon>>::value,
      "Type glib::RefPtr<gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Image::property_gicon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Icon>> (this, "gicon");
  }

  auto
  Image::property_gicon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>> (this,
                                                                  "gicon");
  }

  auto
  Image::property_use_fallback () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-fallback");
  }

  auto
  Image::property_use_fallback () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-fallback");
  }

  auto
  Image::property_resource () -> glib::PropertyProxy<std::string>
  {
    return glib::PropertyProxy<std::string> (this, "resource");
  }

  auto
  Image::property_resource () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return glib::PropertyProxy_ReadOnly<std::string> (this, "resource");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Image::property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (this,
                                                              "paintable");
  }

  auto
  Image::property_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (
        this,
        "paintable");
  }

} // namespace gtk
