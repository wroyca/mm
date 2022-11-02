// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/shortcutswindow.hpp>
#include <mm/gtk/private/shortcutswindow_p.hpp>


/* Copyright (C) 2016 The gtkmm Development Team
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
void ShortcutsWindow::unset_view_name()
{
  // Set gtk+'s char* to nullptr.
  property_view_name().reset_value();
}
} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcutsWindow* object, bool take_copy) -> Gtk::ShortcutsWindow*
{
  return dynamic_cast<Gtk::ShortcutsWindow *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutsWindow_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutsWindow_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_shortcuts_window_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void ShortcutsWindow_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutsWindow_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new ShortcutsWindow((GtkShortcutsWindow*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

ShortcutsWindow::ShortcutsWindow(const Glib::ConstructParams& construct_params)
:
  Window(construct_params)
{
  }

ShortcutsWindow::ShortcutsWindow(GtkShortcutsWindow* castitem)
:
  Window((GtkWindow*)(castitem))
{
  }


ShortcutsWindow::ShortcutsWindow(ShortcutsWindow&& src) noexcept
: Window(std::move(src))
{}

auto ShortcutsWindow::operator=(ShortcutsWindow&& src) noexcept -> ShortcutsWindow&
{
  Window::operator=(std::move(src));
  return *this;
}

ShortcutsWindow::~ShortcutsWindow() noexcept
{
  destroy_();
}

ShortcutsWindow::CppClassType ShortcutsWindow::shortcutswindow_class_; // initialize static member

auto ShortcutsWindow::get_type() -> GType
{
  return shortcutswindow_class_.init().get_type();
}


auto ShortcutsWindow::get_base_type() -> GType
{
  return gtk_shortcuts_window_get_type();
}


ShortcutsWindow::ShortcutsWindow()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Window(Glib::ConstructParams(shortcutswindow_class_.init()))
{


}


auto ShortcutsWindow::property_section_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "section-name");
}

auto ShortcutsWindow::property_section_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "section-name");
}

auto ShortcutsWindow::property_view_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "view-name");
}

auto ShortcutsWindow::property_view_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "view-name");
}


} // namespace Gtk


