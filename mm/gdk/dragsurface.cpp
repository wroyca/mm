// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/dragsurface.hpp>
#include <mm/gdk/private/dragsurface_p.hpp>


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

#include <gdk/gdk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkDragSurface* object, bool take_copy) -> Glib::RefPtr<Gdk::DragSurface>
{
  return Glib::make_refptr_for_instance<Gdk::DragSurface>( dynamic_cast<Gdk::DragSurface*> (Glib::wrap_auto_interface<Gdk::DragSurface> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gdk
{


/* The *_Class implementation: */

auto DragSurface_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &DragSurface_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gdk_drag_surface_get_type();
  }

  return *this;
}

auto DragSurface_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto DragSurface_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DragSurface((GdkDragSurface*)(object));
}


/* The implementation: */

DragSurface::DragSurface()
:
  Glib::Interface(dragsurface_class_.init())
{}

DragSurface::DragSurface(GdkDragSurface* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

DragSurface::DragSurface(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

DragSurface::DragSurface(DragSurface&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto DragSurface::operator=(DragSurface&& src) noexcept -> DragSurface&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

DragSurface::~DragSurface() noexcept
{}

// static
auto DragSurface::add_interface (GType gtype_implementer) -> void
{
  dragsurface_class_.init().add_interface(gtype_implementer);
}

DragSurface::CppClassType DragSurface::dragsurface_class_; // initialize static member

auto DragSurface::get_type() -> GType
{
  return dragsurface_class_.init().get_type();
}


auto DragSurface::get_base_type() -> GType
{
  return gdk_drag_surface_get_type();
}


auto DragSurface::present(int width, int height) -> bool
{
  return gdk_drag_surface_present(gobj(), width, height);
}


} // namespace Gdk


