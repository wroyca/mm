// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/gesturesingle.hpp>
#include <mm/gtk/private/gesturesingle_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureSingle* object, bool take_copy) -> Glib::RefPtr<Gtk::GestureSingle>
{
  return Glib::make_refptr_for_instance<Gtk::GestureSingle>( dynamic_cast<Gtk::GestureSingle*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureSingle_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureSingle_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_single_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void GestureSingle_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureSingle_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureSingle((GtkGestureSingle*)object);
}


/* The implementation: */

auto GestureSingle::gobj_copy() -> GtkGestureSingle*
{
  reference();
  return gobj();
}

GestureSingle::GestureSingle(const Glib::ConstructParams& construct_params)
:
  Gesture(construct_params)
{

}

GestureSingle::GestureSingle(GtkGestureSingle* castitem)
:
  Gesture((GtkGesture*)(castitem))
{}


GestureSingle::GestureSingle(GestureSingle&& src) noexcept
: Gesture(std::move(src))
{}

auto GestureSingle::operator=(GestureSingle&& src) noexcept -> GestureSingle&
{
  Gesture::operator=(std::move(src));
  return *this;
}


GestureSingle::~GestureSingle() noexcept
{}


GestureSingle::CppClassType GestureSingle::gesturesingle_class_; // initialize static member

auto GestureSingle::get_type() -> GType
{
  return gesturesingle_class_.init().get_type();
}


auto GestureSingle::get_base_type() -> GType
{
  return gtk_gesture_single_get_type();
}


GestureSingle::GestureSingle()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gesture(Glib::ConstructParams(gesturesingle_class_.init()))
{


}

auto GestureSingle::get_touch_only() const -> bool
{
  return gtk_gesture_single_get_touch_only(const_cast<GtkGestureSingle*>(gobj()));
}

void GestureSingle::set_touch_only(bool touch_only)
{
  gtk_gesture_single_set_touch_only(gobj(), static_cast<int>(touch_only));
}

auto GestureSingle::get_exclusive() const -> bool
{
  return gtk_gesture_single_get_exclusive(const_cast<GtkGestureSingle*>(gobj()));
}

void GestureSingle::set_exclusive(bool exclusive) const
{
  gtk_gesture_single_set_exclusive(const_cast<GtkGestureSingle*>(gobj()), static_cast<int>(exclusive));
}

auto GestureSingle::get_button() const -> unsigned int
{
  return gtk_gesture_single_get_button(const_cast<GtkGestureSingle*>(gobj()));
}

void GestureSingle::set_button(unsigned int button)
{
  gtk_gesture_single_set_button(gobj(), button);
}

auto GestureSingle::get_current_button() const -> unsigned int
{
  return gtk_gesture_single_get_current_button(const_cast<GtkGestureSingle*>(gobj()));
}

auto GestureSingle::get_current_sequence() -> Gdk::EventSequence*
{
  return reinterpret_cast<Gdk::EventSequence*>(gtk_gesture_single_get_current_sequence(gobj()));
}

auto GestureSingle::get_current_sequence() const -> const Gdk::EventSequence*
{
  return const_cast<GestureSingle*>(this)->get_current_sequence();
}


auto GestureSingle::property_touch_only() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "touch-only");
}

auto GestureSingle::property_touch_only() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "touch-only");
}

auto GestureSingle::property_exclusive() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "exclusive");
}

auto GestureSingle::property_exclusive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "exclusive");
}

auto GestureSingle::property_button() -> Glib::PropertyProxy< unsigned int >
{
  return Glib::PropertyProxy< unsigned int >(this, "button");
}

auto GestureSingle::property_button() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "button");
}


} // namespace Gtk


