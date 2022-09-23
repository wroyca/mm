// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/windowcontrols.h>
#include <gtkmm/private/windowcontrols_p.h>


/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace Gtk
{

// gtk_window_controls_set_decoration_layout(gobj(), nullptr) is not the same as
// gtk_window_controls_set_decoration_layout(gobj(), "").
// nullptr means: Use Gtk::Settings::property_gtk_decoration_layout().
// An empty string means: No decorations.
void WindowControls::unset_decoration_layout()
{
  gtk_window_controls_set_decoration_layout(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::WindowControls* wrap(GtkWindowControls* object, bool take_copy)
{
  return dynamic_cast<Gtk::WindowControls *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& WindowControls_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &WindowControls_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_window_controls_get_type();

  }

  return *this;
}


void WindowControls_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* WindowControls_Class::wrap_new(GObject* o)
{
  return manage(new WindowControls((GtkWindowControls*)(o)));

}


/* The implementation: */

WindowControls::WindowControls(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

WindowControls::WindowControls(GtkWindowControls* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


WindowControls::WindowControls(WindowControls&& src) noexcept
: Gtk::Widget(std::move(src))
{}

WindowControls& WindowControls::operator=(WindowControls&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

WindowControls::~WindowControls() noexcept
{
  destroy_();
}

WindowControls::CppClassType WindowControls::windowcontrols_class_; // initialize static member

GType WindowControls::get_type()
{
  return windowcontrols_class_.init().get_type();
}


GType WindowControls::get_base_type()
{
  return gtk_window_controls_get_type();
}


WindowControls::WindowControls(PackType side)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(windowcontrols_class_.init(), "side", static_cast<GtkPackType>(side), nullptr))
{
  

}

void WindowControls::set_side(PackType side)
{
  gtk_window_controls_set_side(gobj(), static_cast<GtkPackType>(side));
}

PackType WindowControls::get_side() const
{
  return static_cast<PackType>(gtk_window_controls_get_side(const_cast<GtkWindowControls*>(gobj())));
}

void WindowControls::set_decoration_layout(const Glib::ustring& layout)
{
  gtk_window_controls_set_decoration_layout(gobj(), layout.c_str());
}

Glib::ustring WindowControls::get_decoration_layout() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_window_controls_get_decoration_layout(const_cast<GtkWindowControls*>(gobj())));
}

bool WindowControls::get_empty() const
{
  return gtk_window_controls_get_empty(const_cast<GtkWindowControls*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PackType>::value,
  "Type PackType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< PackType > WindowControls::property_side() 
{
  return Glib::PropertyProxy< PackType >(this, "side");
}

Glib::PropertyProxy_ReadOnly< PackType > WindowControls::property_side() const
{
  return Glib::PropertyProxy_ReadOnly< PackType >(this, "side");
}

Glib::PropertyProxy< Glib::ustring > WindowControls::property_decoration_layout() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "decoration-layout");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > WindowControls::property_decoration_layout() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "decoration-layout");
}

Glib::PropertyProxy_ReadOnly< bool > WindowControls::property_empty() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "empty");
}


} // namespace Gtk


