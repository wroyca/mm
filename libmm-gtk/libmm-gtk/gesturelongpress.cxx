


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/gesturelongpress.hpp>
#include <libmm-gtk/gesturelongpress_p.hpp>


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


auto GestureLongPress_signal_pressed_callback (
  GtkGestureLongPress *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<GestureLongPress*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo GestureLongPress_signal_pressed_info =
{
  "pressed",
  (GCallback) &GestureLongPress_signal_pressed_callback,
  (GCallback) &GestureLongPress_signal_pressed_callback
};


const Glib::SignalProxyInfo GestureLongPress_signal_cancelled_info =
{
  "cancelled",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGestureLongPress* object, const bool take_copy) -> RefPtr<Gtk::GestureLongPress>
{
  return Glib::make_refptr_for_instance<Gtk::GestureLongPress>( dynamic_cast<Gtk::GestureLongPress*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GestureLongPress_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GestureLongPress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_long_press_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GestureLongPress_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GestureLongPress_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GestureLongPress((GtkGestureLongPress*)object);
}


/* The implementation: */

auto GestureLongPress::gobj_copy() -> GtkGestureLongPress*
{
  reference();
  return gobj();
}

GestureLongPress::GestureLongPress(const Glib::ConstructParams& construct_params)
:
  GestureSingle(construct_params)
{

}

GestureLongPress::GestureLongPress(GtkGestureLongPress* castitem)
:
  GestureSingle((GtkGestureSingle*)castitem)
{}


GestureLongPress::GestureLongPress(GestureLongPress&& src) noexcept
: GestureSingle(std::move(src))
{}

auto GestureLongPress::operator=(GestureLongPress&& src) noexcept -> GestureLongPress&
{
  GestureSingle::operator=(std::move(src));
  return *this;
}


GestureLongPress::~GestureLongPress() noexcept = default;

GestureLongPress::CppClassType GestureLongPress::gesturelongpress_class_; // initialize static member

auto GestureLongPress::get_type() -> GType
{
  return gesturelongpress_class_.init().get_type();
}


auto GestureLongPress::get_base_type() -> GType
{
  return gtk_gesture_long_press_get_type();
}


GestureLongPress::GestureLongPress()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  GestureSingle(Glib::ConstructParams(gesturelongpress_class_.init()))
{


}

auto GestureLongPress::create() -> Glib::RefPtr<GestureLongPress>
{
  return Glib::make_refptr_for_instance<GestureLongPress>( new GestureLongPress() );
}

auto GestureLongPress::set_delay_factor (
  const double delay_factor) -> void
{
  gtk_gesture_long_press_set_delay_factor(gobj(), delay_factor);
}

auto GestureLongPress::get_delay_factor() const -> double
{
  return gtk_gesture_long_press_get_delay_factor(const_cast<GtkGestureLongPress*>(gobj()));
}


auto GestureLongPress::signal_pressed() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &GestureLongPress_signal_pressed_info};
}


auto GestureLongPress::signal_cancelled() -> Glib::SignalProxy<void()>
{
  return {this, &GestureLongPress_signal_cancelled_info};
}


auto GestureLongPress::property_delay_factor() -> Glib::PropertyProxy< double >
{
  return {this, "delay-factor"};
}

auto GestureLongPress::property_delay_factor() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "delay-factor"};
}


} // namespace Gtk


