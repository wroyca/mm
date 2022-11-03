// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/gesturezoom.hpp>
#include <mm/gtk/private/gesturezoom_p.hpp>


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


auto GestureZoom_signal_scale_changed_callback (
  GtkGestureZoom *self, const gdouble p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double)>;

  const auto obj = dynamic_cast<GestureZoom*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GestureZoom_signal_scale_changed_info =
{
  "scale-changed",
  (GCallback) &GestureZoom_signal_scale_changed_callback,
  (GCallback) &GestureZoom_signal_scale_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureZoom* object, const bool take_copy) -> RefPtr<Gtk::GestureZoom>
{
  return Glib::make_refptr_for_instance<Gtk::GestureZoom>( dynamic_cast<Gtk::GestureZoom*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureZoom_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureZoom_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_zoom_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GestureZoom_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureZoom_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureZoom((GtkGestureZoom*)object);
}


/* The implementation: */

auto GestureZoom::gobj_copy() -> GtkGestureZoom*
{
  reference();
  return gobj();
}

GestureZoom::GestureZoom(const Glib::ConstructParams& construct_params)
:
  Gesture(construct_params)
{

}

GestureZoom::GestureZoom(GtkGestureZoom* castitem)
:
  Gesture((GtkGesture*)castitem)
{}


GestureZoom::GestureZoom(GestureZoom&& src) noexcept
: Gesture(std::move(src))
{}

auto GestureZoom::operator=(GestureZoom&& src) noexcept -> GestureZoom&
{
  Gesture::operator=(std::move(src));
  return *this;
}


GestureZoom::~GestureZoom() noexcept = default;

GestureZoom::CppClassType GestureZoom::gesturezoom_class_; // initialize static member

auto GestureZoom::get_type() -> GType
{
  return gesturezoom_class_.init().get_type();
}


auto GestureZoom::get_base_type() -> GType
{
  return gtk_gesture_zoom_get_type();
}


GestureZoom::GestureZoom()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Gesture(Glib::ConstructParams(gesturezoom_class_.init()))
{


}

auto GestureZoom::create() -> Glib::RefPtr<GestureZoom>
{
  return Glib::make_refptr_for_instance<GestureZoom>( new GestureZoom() );
}

auto GestureZoom::get_scale_delta() const -> double
{
  return gtk_gesture_zoom_get_scale_delta(const_cast<GtkGestureZoom*>(gobj()));
}


auto GestureZoom::signal_scale_changed() -> Glib::SignalProxy<void(double)>
{
  return {this, &GestureZoom_signal_scale_changed_info};
}


} // namespace Gtk


