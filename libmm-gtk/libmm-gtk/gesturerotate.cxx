


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gesturerotate.hxx>
#include <libmm-gtk/gesturerotate_p.hxx>


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


auto GestureRotate_signal_angle_changed_callback (
  GtkGestureRotate *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureRotate*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo GestureRotate_signal_angle_changed_info =
{
  "angle-changed",
  (GCallback) &GestureRotate_signal_angle_changed_callback,
  (GCallback) &GestureRotate_signal_angle_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureRotate* object, const bool take_copy) -> RefPtr<Gtk::GestureRotate>
{
  return Glib::make_refptr_for_instance<Gtk::GestureRotate>( dynamic_cast<Gtk::GestureRotate*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureRotate_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureRotate_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_rotate_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GestureRotate_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureRotate_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureRotate((GtkGestureRotate*)object);
}


/* The implementation: */

auto GestureRotate::gobj_copy() -> GtkGestureRotate*
{
  reference();
  return gobj();
}

GestureRotate::GestureRotate(const Glib::ConstructParams& construct_params)
:
  Gesture(construct_params)
{

}

GestureRotate::GestureRotate(GtkGestureRotate* castitem)
:
  Gesture((GtkGesture*)castitem)
{}


GestureRotate::GestureRotate(GestureRotate&& src) noexcept
: Gesture(std::move(src))
{}

auto GestureRotate::operator=(GestureRotate&& src) noexcept -> GestureRotate&
{
  Gesture::operator=(std::move(src));
  return *this;
}


GestureRotate::~GestureRotate() noexcept = default;

GestureRotate::CppClassType GestureRotate::gesturerotate_class_; // initialize static member

auto GestureRotate::get_type() -> GType
{
  return gesturerotate_class_.init().get_type();
}


auto GestureRotate::get_base_type() -> GType
{
  return gtk_gesture_rotate_get_type();
}


GestureRotate::GestureRotate()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Gesture(Glib::ConstructParams(gesturerotate_class_.init()))
{


}

auto GestureRotate::create() -> Glib::RefPtr<GestureRotate>
{
  return Glib::make_refptr_for_instance<GestureRotate>( new GestureRotate() );
}

auto GestureRotate::get_angle_delta() const -> double
{
  return gtk_gesture_rotate_get_angle_delta(const_cast<GtkGestureRotate*>(gobj()));
}


auto GestureRotate::signal_angle_changed() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureRotate_signal_angle_changed_info};
}


} // namespace Gtk


