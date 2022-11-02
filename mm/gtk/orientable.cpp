// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/orientable.hpp>
#include <mm/gtk/private/orientable_p.hpp>


/* Copyright 2009 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkOrientable* object, bool take_copy) -> Glib::RefPtr<Gtk::Orientable>
{
  return Glib::make_refptr_for_instance<Gtk::Orientable>( dynamic_cast<Gtk::Orientable*> (Glib::wrap_auto_interface<Gtk::Orientable> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Orientable_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Orientable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_orientable_get_type();
  }

  return *this;
}

void Orientable_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Orientable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Orientable((GtkOrientable*)(object));
}


/* The implementation: */

Orientable::Orientable()
:
  Glib::Interface(orientable_class_.init())
{}

Orientable::Orientable(GtkOrientable* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Orientable::Orientable(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Orientable::Orientable(Orientable&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto Orientable::operator=(Orientable&& src) noexcept -> Orientable&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Orientable::~Orientable() noexcept
{}

// static
void Orientable::add_interface(GType gtype_implementer)
{
  orientable_class_.init().add_interface(gtype_implementer);
}

Orientable::CppClassType Orientable::orientable_class_; // initialize static member

auto Orientable::get_type() -> GType
{
  return orientable_class_.init().get_type();
}


auto Orientable::get_base_type() -> GType
{
  return gtk_orientable_get_type();
}


void Orientable::set_orientation(Orientation orientation)
{
  gtk_orientable_set_orientation(gobj(), static_cast<GtkOrientation>(orientation));
}

auto Orientable::get_orientation() const -> Orientation
{
  return static_cast<Orientation>(gtk_orientable_get_orientation(const_cast<GtkOrientable*>(gobj())));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Orientation>::value,
  "Type Orientation cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Orientable::property_orientation() -> Glib::PropertyProxy< Orientation >
{
  return Glib::PropertyProxy< Orientation >(this, "orientation");
}

auto Orientable::property_orientation() const -> Glib::PropertyProxy_ReadOnly< Orientation >
{
  return Glib::PropertyProxy_ReadOnly< Orientation >(this, "orientation");
}


} // namespace Gtk


