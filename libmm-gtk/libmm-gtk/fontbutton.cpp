


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/fontbutton.hpp>
#include <mm/gtk/private/fontbutton_p.hpp>


/*
 * Copyright 2003 The gtkmm Development Team
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

namespace Gtk
{


} // namespace Gtk


namespace
{


const Glib::SignalProxyInfo FontButton_signal_font_set_info =
{
  "font-set",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkFontButton* object, const bool take_copy) -> Gtk::FontButton*
{
  return dynamic_cast<Gtk::FontButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FontButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_font_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  FontChooser::add_interface(get_type());

  }

  return *this;
}


auto FontButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FontButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new FontButton((GtkFontButton*)o));

}


/* The implementation: */

FontButton::FontButton(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

FontButton::FontButton(GtkFontButton* castitem)
: Widget((GtkWidget*)castitem)
{
  }


FontButton::FontButton(FontButton&& src) noexcept
: Widget(std::move(src))
  , FontChooser(std::move(src))
{}

auto FontButton::operator=(FontButton&& src) noexcept -> FontButton&
{
  Widget::operator=(std::move(src));
  FontChooser::operator=(std::move(src));
  return *this;
}

FontButton::~FontButton() noexcept
{
  destroy_();
}

FontButton::CppClassType FontButton::fontbutton_class_; // initialize static member

auto FontButton::get_type() -> GType
{
  return fontbutton_class_.init().get_type();
}


auto FontButton::get_base_type() -> GType
{
  return gtk_font_button_get_type();
}


FontButton::FontButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(fontbutton_class_.init()))
{


}

FontButton::FontButton(const Glib::ustring& font)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(fontbutton_class_.init(), "font", font.c_str(), nullptr))
{


}

auto FontButton::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_font_button_get_title(const_cast<GtkFontButton*>(gobj())));
}

auto FontButton::set_title (const Glib::ustring &title) -> void
{
  gtk_font_button_set_title(gobj(), title.c_str());
}

auto FontButton::get_modal() const -> bool
{
  return gtk_font_button_get_modal(const_cast<GtkFontButton*>(gobj()));
}

auto FontButton::set_modal (
  const bool modal) -> void
{
  gtk_font_button_set_modal(gobj(), modal);
}

auto FontButton::get_use_font() const -> bool
{
  return gtk_font_button_get_use_font(const_cast<GtkFontButton*>(gobj()));
}

auto FontButton::set_use_font (
  const bool use_font) -> void
{
  gtk_font_button_set_use_font(gobj(), use_font);
}

auto FontButton::get_use_size() const -> bool
{
  return gtk_font_button_get_use_size(const_cast<GtkFontButton*>(gobj()));
}

auto FontButton::set_use_size (
  const bool use_size) -> void
{
  gtk_font_button_set_use_size(gobj(), use_size);
}


auto FontButton::signal_font_set() -> Glib::SignalProxy<void()>
{
  return {this, &FontButton_signal_font_set_info};
}


auto FontButton::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto FontButton::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto FontButton::property_modal() -> Glib::PropertyProxy< bool >
{
  return {this, "modal"};
}

auto FontButton::property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "modal"};
}

auto FontButton::property_use_font() -> Glib::PropertyProxy< bool >
{
  return {this, "use-font"};
}

auto FontButton::property_use_font() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-font"};
}

auto FontButton::property_use_size() -> Glib::PropertyProxy< bool >
{
  return {this, "use-size"};
}

auto FontButton::property_use_size() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-size"};
}


} // namespace Gtk


