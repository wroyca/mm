


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gestureswipe.hxx>
#include <libmm-gtk/gestureswipe_p.hxx>


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


auto GestureSwipe_signal_swipe_callback (
  GtkGestureSwipe *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureSwipe*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GestureSwipe_signal_swipe_info =
{
  "swipe",
  (GCallback) &GestureSwipe_signal_swipe_callback,
  (GCallback) &GestureSwipe_signal_swipe_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureSwipe* object, const bool take_copy) -> RefPtr<Gtk::GestureSwipe>
{
  return Glib::make_refptr_for_instance<Gtk::GestureSwipe>( dynamic_cast<Gtk::GestureSwipe*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureSwipe_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureSwipe_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_swipe_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GestureSwipe_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureSwipe_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureSwipe((GtkGestureSwipe*)object);
}


/* The implementation: */

auto GestureSwipe::gobj_copy() -> GtkGestureSwipe*
{
  reference();
  return gobj();
}

GestureSwipe::GestureSwipe(const Glib::ConstructParams& construct_params)
:
  GestureSingle(construct_params)
{

}

GestureSwipe::GestureSwipe(GtkGestureSwipe* castitem)
:
  GestureSingle((GtkGestureSingle*)castitem)
{}


GestureSwipe::GestureSwipe(GestureSwipe&& src) noexcept
: GestureSingle(std::move(src))
{}

auto GestureSwipe::operator=(GestureSwipe&& src) noexcept -> GestureSwipe&
{
  GestureSingle::operator=(std::move(src));
  return *this;
}


GestureSwipe::~GestureSwipe() noexcept = default;

GestureSwipe::CppClassType GestureSwipe::gestureswipe_class_; // initialize static member

auto GestureSwipe::get_type() -> GType
{
  return gestureswipe_class_.init().get_type();
}


auto GestureSwipe::get_base_type() -> GType
{
  return gtk_gesture_swipe_get_type();
}


GestureSwipe::GestureSwipe()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  GestureSingle(Glib::ConstructParams(gestureswipe_class_.init()))
{


}

auto GestureSwipe::create() -> Glib::RefPtr<GestureSwipe>
{
  return Glib::make_refptr_for_instance<GestureSwipe>( new GestureSwipe() );
}

auto GestureSwipe::get_velocity(double& velocity_x, double& velocity_y) const -> bool
{
  return gtk_gesture_swipe_get_velocity(const_cast<GtkGestureSwipe*>(gobj()), &velocity_x, &velocity_y);
}


auto GestureSwipe::signal_swipe() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureSwipe_signal_swipe_info};
}


} // namespace Gtk


