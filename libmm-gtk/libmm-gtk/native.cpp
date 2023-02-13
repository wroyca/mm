


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/native.hpp>
#include <mm/gtk/private/native_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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
#include <mm/gdk/surface.hpp>
#include <mm/gtk/widget.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkNative* object, const bool take_copy) -> RefPtr<Gtk::Native>
{
  return Glib::make_refptr_for_instance<Gtk::Native>( Glib::wrap_auto_interface<Gtk::Native> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Native_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Native_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_native_get_type();
  }

  return *this;
}

auto Native_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Native_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Native((GtkNative*)object);
}


/* The implementation: */

Native::Native()
: Interface(native_class_.init())
{}

Native::Native(GtkNative* castitem)
: Interface((GObject*)castitem)
{}

Native::Native(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Native::Native(Native&& src) noexcept
: Interface(std::move(src))
{}

auto Native::operator=(Native&& src) noexcept -> Native&
{
  Interface::operator=(std::move(src));
  return *this;
}

Native::~Native() noexcept = default;

// static
auto Native::add_interface (
  const GType gtype_implementer) -> void
{
  native_class_.init().add_interface(gtype_implementer);
}

Native::CppClassType Native::native_class_; // initialize static member

auto Native::get_type() -> GType
{
  return native_class_.init().get_type();
}


auto Native::get_base_type() -> GType
{
  return gtk_native_get_type();
}


auto Native::realize () -> void
{
  gtk_native_realize(gobj());
}

auto Native::unrealize () -> void
{
  gtk_native_unrealize(gobj());
}

auto Native::get_for_surface(const Glib::RefPtr<const Gdk::Surface>& surface) -> Native*
{
  return dynamic_cast<Native*>(Glib::wrap_auto((GObject*)gtk_native_get_for_surface(const_cast<GdkSurface*>(Glib::unwrap<Gdk::Surface>(surface))), false));
}

auto Native::get_surface() -> Glib::RefPtr<Gdk::Surface>
{
  auto retvalue = Glib::wrap(gtk_native_get_surface(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Native::get_surface() const -> Glib::RefPtr<const Gdk::Surface>
{
  return const_cast<Native*>(this)->get_surface();
}

auto Native::get_surface_transform (double &x, double &y) -> void
{
  gtk_native_get_surface_transform(gobj(), &x, &y);
}


} // namespace Gtk


