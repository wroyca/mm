


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/applicationwindow.hpp>
#include <mm/gtk/private/applicationwindow_p.hpp>


/* Copyright 2012 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <mm/gtk/applicationwindow.hpp>
#include <mm/gtk/shortcutswindow.hpp>

namespace Gtk
{
ApplicationWindow::ApplicationWindow(const Glib::RefPtr<Application>& application)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(applicationwindow_class_.init()))
{
  // Don't set the "application" property in ConstructParams. It would result in
  // an attempt to set two C++ wrappers on the GApplicationWindow C object,
  // if "application" is not a plain Gtk::Application, but derived from it.
  // Like so:
  // - Glib::Object::Object(const Glib::ConstructParams& construct_params) calls
  //   g_object_newv() to create a new GApplicationWindow.
  // - In gtk+, gtk_application_add_window() is called. It emits the window_added
  //   signal with the new GApplicationWindow as a parameter.
  // - Application_signal_window_added_callback() calls Glib::wrap(GWindow*)
  //   before *this has been set as the wrapper. Glib::wrap() then creates a
  //   wrapper (not *this).
  // - Glib::Object::Object() calls Glib::ObjectBase::initialize(), which calls
  //   Glib::ObjectBase::_set_current_wrapper() to set *this as the C++ wrapper,
  //   but by then another wrapper has already been set.
  // https://bugzilla.gnome.org/show_bug.cgi?id=758813

  if (application)
    application->add_window(*this);
}

auto ApplicationWindow::unset_help_overlay () -> void
{
  gtk_application_window_set_help_overlay(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkApplicationWindow* object, const bool take_copy) -> Gtk::ApplicationWindow*
{
  return dynamic_cast<Gtk::ApplicationWindow *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ApplicationWindow_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ApplicationWindow_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_application_window_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::ActionGroup::add_interface(get_type());
  Gio::ActionMap::add_interface(get_type());

  }

  return *this;
}


auto ApplicationWindow_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ApplicationWindow_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new ApplicationWindow((GtkApplicationWindow*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

ApplicationWindow::ApplicationWindow(const Glib::ConstructParams& construct_params)
: Window(construct_params)
{
  }

ApplicationWindow::ApplicationWindow(GtkApplicationWindow* castitem)
: Window((GtkWindow*)castitem)
{
  }


ApplicationWindow::ApplicationWindow(ApplicationWindow&& src) noexcept
: Window(std::move(src))
  ,
  ActionGroup(std::move(src))
  ,
  ActionMap(std::move(src))
{}

auto ApplicationWindow::operator=(ApplicationWindow&& src) noexcept -> ApplicationWindow&
{
  Window::operator=(std::move(src));
  ActionGroup::operator=(std::move(src));
  ActionMap::operator=(std::move(src));
  return *this;
}

ApplicationWindow::~ApplicationWindow() noexcept
{
  destroy_();
}

ApplicationWindow::CppClassType ApplicationWindow::applicationwindow_class_; // initialize static member

auto ApplicationWindow::get_type() -> GType
{
  return applicationwindow_class_.init().get_type();
}


auto ApplicationWindow::get_base_type() -> GType
{
  return gtk_application_window_get_type();
}


ApplicationWindow::ApplicationWindow()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(applicationwindow_class_.init()))
{


}

auto ApplicationWindow::set_show_menubar (
  const bool show_menubar) -> void
{
  gtk_application_window_set_show_menubar(gobj(), show_menubar);
}

auto ApplicationWindow::get_show_menubar() const -> bool
{
  return gtk_application_window_get_show_menubar(const_cast<GtkApplicationWindow*>(gobj()));
}

auto ApplicationWindow::get_id() const -> guint
{
  return gtk_application_window_get_id(const_cast<GtkApplicationWindow*>(gobj()));
}

auto ApplicationWindow::set_help_overlay (ShortcutsWindow &help_overlay) -> void
{
  gtk_application_window_set_help_overlay(gobj(), help_overlay.gobj());
}

auto ApplicationWindow::get_help_overlay() -> ShortcutsWindow*
{
  return Glib::wrap(gtk_application_window_get_help_overlay(gobj()));
}

auto ApplicationWindow::get_help_overlay() const -> const ShortcutsWindow*
{
  return const_cast<ApplicationWindow*>(this)->get_help_overlay();
}


auto ApplicationWindow::property_show_menubar() -> Glib::PropertyProxy< bool >
{
  return {this, "show-menubar"};
}

auto ApplicationWindow::property_show_menubar() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-menubar"};
}


} // namespace Gtk


