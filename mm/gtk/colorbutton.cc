// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/colorbutton.h>
#include <mm/gtk/private/colorbutton_p.h>


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


const Glib::SignalProxyInfo ColorButton_signal_color_set_info =
{
  "color-set",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkColorButton* object, bool take_copy) -> Gtk::ColorButton*
{
  return dynamic_cast<Gtk::ColorButton *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ColorButton_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ColorButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_color_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  ColorChooser::add_interface(get_type());

  }

  return *this;
}


void ColorButton_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ColorButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ColorButton((GtkColorButton*)(o)));

}


/* The implementation: */

ColorButton::ColorButton(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

ColorButton::ColorButton(GtkColorButton* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


ColorButton::ColorButton(ColorButton&& src) noexcept
: Gtk::Widget(std::move(src))
  , ColorChooser(std::move(src))
{}

auto ColorButton::operator=(ColorButton&& src) noexcept -> ColorButton&
{
  Gtk::Widget::operator=(std::move(src));
  ColorChooser::operator=(std::move(src));
  return *this;
}

ColorButton::~ColorButton() noexcept
{
  destroy_();
}

ColorButton::CppClassType ColorButton::colorbutton_class_; // initialize static member

auto ColorButton::get_type() -> GType
{
  return colorbutton_class_.init().get_type();
}


auto ColorButton::get_base_type() -> GType
{
  return gtk_color_button_get_type();
}


ColorButton::ColorButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(colorbutton_class_.init()))
{


}

ColorButton::ColorButton(const Gdk::RGBA& rgba)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(colorbutton_class_.init(), "rgba", (rgba).gobj(), nullptr))
{


}

void ColorButton::set_title(const Glib::ustring& title)
{
  gtk_color_button_set_title(gobj(), title.c_str());
}

auto ColorButton::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_color_button_get_title(const_cast<GtkColorButton*>(gobj())));
}

void ColorButton::set_modal(bool modal)
{
  gtk_color_button_set_modal(gobj(), static_cast<int>(modal));
}

auto ColorButton::get_modal() const -> bool
{
  return gtk_color_button_get_modal(const_cast<GtkColorButton*>(gobj()));
}


auto ColorButton::signal_color_set() -> Glib::SignalProxy<void()>
{
  return Glib::SignalProxy<void() >(this, &ColorButton_signal_color_set_info);
}


auto ColorButton::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "title");
}

auto ColorButton::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "title");
}

auto ColorButton::property_show_editor() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "show-editor");
}

auto ColorButton::property_show_editor() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "show-editor");
}

auto ColorButton::property_modal() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "modal");
}

auto ColorButton::property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "modal");
}


} // namespace Gtk

