


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/image.hpp>
#include <mm/gtk/private/image_p.hpp>

#include <gtk/gtk.h>

/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

using Type = Gtk::Image::Type;

namespace Gtk
{

Image::Image(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(image_class_.init()))
{
  gtk_image_set_from_pixbuf(gobj(), Glib::unwrap(pixbuf));
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Image::Type>::value_type() -> GType
{
  return gtk_image_type_get_type();
}


namespace Glib
{

auto wrap(GtkImage* object, const bool take_copy) -> Gtk::Image*
{
  return dynamic_cast<Gtk::Image *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Image_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Image_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_image_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Image_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Image_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Image((GtkImage*)o));

}


/* The implementation: */

Image::Image(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Image::Image(GtkImage* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Image::Image(Image&& src) noexcept
: Widget(std::move(src))
{}

auto Image::operator=(Image&& src) noexcept -> Image&
{
  Widget::operator=(std::move(src));
  return *this;
}

Image::~Image() noexcept
{
  destroy_();
}

Image::CppClassType Image::image_class_; // initialize static member

auto Image::get_type() -> GType
{
  return image_class_.init().get_type();
}


auto Image::get_base_type() -> GType
{
  return gtk_image_get_type();
}


Image::Image()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(image_class_.init()))
{


}

Image::Image(const std::string& file)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(image_class_.init(), "file", file.c_str(), nullptr))
{


}

Image::Image(const Glib::RefPtr<Gdk::Paintable>& paintable)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(image_class_.init(), "paintable", Glib::unwrap(paintable), nullptr))
{


}

Image::Image(const Glib::RefPtr<Gio::Icon>& gicon)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(image_class_.init(), "gicon", Glib::unwrap<Gio::Icon>(gicon), nullptr))
{


}

auto Image::set (const std::string &filename) -> void
{
  gtk_image_set_from_file(gobj(), filename.c_str());
}

auto Image::set_from_resource (const std::string &resource_path) -> void
{
  gtk_image_set_from_resource(gobj(), resource_path.c_str());
}

auto Image::set (const Glib::RefPtr <Gdk::Pixbuf> &pixbuf) -> void
{
  gtk_image_set_from_pixbuf(gobj(), Glib::unwrap(pixbuf));
}

auto Image::set (const Glib::RefPtr <Gdk::Paintable> &paintable) -> void
{
  gtk_image_set_from_paintable(gobj(), Glib::unwrap(paintable));
}

auto Image::set (const Glib::RefPtr <const Gio::Icon> &icon) -> void
{
  gtk_image_set_from_gicon(gobj(), const_cast<GIcon*>(Glib::unwrap<Gio::Icon>(icon)));
}

auto Image::set_from_icon_name (const Glib::ustring &icon_name) -> void
{
  gtk_image_set_from_icon_name(gobj(), icon_name.c_str());
}

auto Image::clear () -> void
{
  gtk_image_clear(gobj());
}

auto Image::get_storage_type() const -> Type
{
  return static_cast<Type>(gtk_image_get_storage_type(const_cast<GtkImage*>(gobj())));
}

auto Image::get_paintable() -> Glib::RefPtr<Gdk::Paintable>
{
  auto retvalue = Glib::wrap(gtk_image_get_paintable(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Image::get_paintable() const -> Glib::RefPtr<const Gdk::Paintable>
{
  return const_cast<Image*>(this)->get_paintable();
}

auto Image::set_icon_size (IconSize icon_size) -> void
{
  gtk_image_set_icon_size(gobj(), static_cast<GtkIconSize>(icon_size));
}

auto Image::get_icon_size() const -> IconSize
{
  return static_cast<IconSize>(gtk_image_get_icon_size(const_cast<GtkImage*>(gobj())));
}

auto Image::get_gicon() -> Glib::RefPtr<Gio::Icon>
{
  auto retvalue = Glib::wrap(gtk_image_get_gicon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Image::get_gicon() const -> Glib::RefPtr<const Gio::Icon>
{
  return const_cast<Image*>(this)->get_gicon();
}

auto Image::get_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_image_get_icon_name(const_cast<GtkImage*>(gobj())));
}

auto Image::get_pixel_size() const -> int
{
  return gtk_image_get_pixel_size(const_cast<GtkImage*>(gobj()));
}

auto Image::set_pixel_size (
  const int pixel_size) -> void
{
  gtk_image_set_pixel_size(gobj(), pixel_size);
}


auto Image::property_file() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "file"};
}

auto Image::property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "file"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<IconSize>::value,
  "Type IconSize cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Image::property_icon_size() -> Glib::PropertyProxy< IconSize >
{
  return {this, "icon-size"};
}

auto Image::property_icon_size() const -> Glib::PropertyProxy_ReadOnly< IconSize >
{
  return {this, "icon-size"};
}

auto Image::property_pixel_size() -> Glib::PropertyProxy< int >
{
  return {this, "pixel-size"};
}

auto Image::property_pixel_size() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pixel-size"};
}

auto Image::property_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "icon-name"};
}

auto Image::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "icon-name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Image::property_storage_type() const -> Glib::PropertyProxy_ReadOnly< Type >
{
  return {this, "storage-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Icon>>::value,
  "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Image::property_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >
{
  return {this, "gicon"};
}

auto Image::property_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >
{
  return {this, "gicon"};
}

auto Image::property_use_fallback() -> Glib::PropertyProxy< bool >
{
  return {this, "use-fallback"};
}

auto Image::property_use_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-fallback"};
}

auto Image::property_resource() -> Glib::PropertyProxy< std::string >
{
  return {this, "resource"};
}

auto Image::property_resource() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "resource"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Paintable>>::value,
  "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Image::property_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "paintable"};
}

auto Image::property_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "paintable"};
}


} // namespace Gtk


