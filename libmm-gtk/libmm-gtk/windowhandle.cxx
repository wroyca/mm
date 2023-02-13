


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/windowhandle.hxx>
#include <libmm-gtk/windowhandle_p.hxx>


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

auto WindowHandle::unset_child () -> void
{
  gtk_window_handle_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkWindowHandle* object, const bool take_copy) -> Gtk::WindowHandle*
{
  return dynamic_cast<Gtk::WindowHandle *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto WindowHandle_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &WindowHandle_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_window_handle_get_type();

  }

  return *this;
}


auto WindowHandle_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto WindowHandle_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new WindowHandle((GtkWindowHandle*)o));

}


/* The implementation: */

WindowHandle::WindowHandle(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

WindowHandle::WindowHandle(GtkWindowHandle* castitem)
: Widget((GtkWidget*)castitem)
{
  }


WindowHandle::WindowHandle(WindowHandle&& src) noexcept
: Widget(std::move(src))
{}

auto WindowHandle::operator=(WindowHandle&& src) noexcept -> WindowHandle&
{
  Widget::operator=(std::move(src));
  return *this;
}

WindowHandle::~WindowHandle() noexcept
{
  destroy_();
}

WindowHandle::CppClassType WindowHandle::windowhandle_class_; // initialize static member

auto WindowHandle::get_type() -> GType
{
  return windowhandle_class_.init().get_type();
}


auto WindowHandle::get_base_type() -> GType
{
  return gtk_window_handle_get_type();
}


WindowHandle::WindowHandle()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(windowhandle_class_.init()))
{


}

auto WindowHandle::set_child (Widget &child) -> void
{
  gtk_window_handle_set_child(gobj(), child.gobj());
}

auto WindowHandle::get_child() -> Widget*
{
  return Glib::wrap(gtk_window_handle_get_child(gobj()));
}

auto WindowHandle::get_child() const -> const Widget*
{
  return const_cast<WindowHandle*>(this)->get_child();
}


auto WindowHandle::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto WindowHandle::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


} // namespace Gtk


