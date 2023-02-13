


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/eventcontroller.hpp>
#include <libmm-gtk/eventcontroller_p.hpp>


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

// static
auto Glib::Value<Gtk::PropagationPhase>::value_type() -> GType
{
  return gtk_propagation_phase_get_type();
}

// static
auto Glib::Value<Gtk::PropagationLimit>::value_type() -> GType
{
  return gtk_propagation_limit_get_type();
}


namespace Glib
{

auto wrap(GtkEventController* object, const bool take_copy) -> RefPtr<Gtk::EventController>
{
  return Glib::make_refptr_for_instance<Gtk::EventController>( dynamic_cast<Gtk::EventController*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EventController_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EventController_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_event_controller_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EventController_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EventController_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EventController((GtkEventController*)object);
}


/* The implementation: */

auto EventController::gobj_copy() -> GtkEventController*
{
  reference();
  return gobj();
}

EventController::EventController(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

EventController::EventController(GtkEventController* castitem)
: Object((GObject*)castitem)
{}


EventController::EventController(EventController&& src) noexcept
: Object(std::move(src))
{}

auto EventController::operator=(EventController&& src) noexcept -> EventController&
{
  Object::operator=(std::move(src));
  return *this;
}


EventController::~EventController() noexcept = default;

EventController::CppClassType EventController::eventcontroller_class_; // initialize static member

auto EventController::get_type() -> GType
{
  return eventcontroller_class_.init().get_type();
}


auto EventController::get_base_type() -> GType
{
  return gtk_event_controller_get_type();
}


EventController::EventController()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(eventcontroller_class_.init()))
{


}

auto EventController::get_widget() -> Widget*
{
  return Glib::wrap(gtk_event_controller_get_widget(gobj()));
}

auto EventController::get_widget() const -> const Widget*
{
  return const_cast<EventController*>(this)->get_widget();
}

auto EventController::reset () -> void
{
  gtk_event_controller_reset(gobj());
}

auto EventController::get_propagation_phase() const -> PropagationPhase
{
  return static_cast<PropagationPhase>(gtk_event_controller_get_propagation_phase(const_cast<GtkEventController*>(gobj())));
}

auto EventController::set_propagation_phase (PropagationPhase phase) -> void
{
  gtk_event_controller_set_propagation_phase(gobj(), static_cast<GtkPropagationPhase>(phase));
}

auto EventController::get_propagation_limit() const -> PropagationLimit
{
  return static_cast<PropagationLimit>(gtk_event_controller_get_propagation_limit(const_cast<GtkEventController*>(gobj())));
}

auto EventController::set_propagation_limit (PropagationLimit limit) -> void
{
  gtk_event_controller_set_propagation_limit(gobj(), static_cast<GtkPropagationLimit>(limit));
}

auto EventController::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_event_controller_get_name(const_cast<GtkEventController*>(gobj())));
}

auto EventController::set_name (const Glib::ustring &name) -> void
{
  gtk_event_controller_set_name(gobj(), name.c_str());
}

auto EventController::get_current_event() const -> Glib::RefPtr<const Gdk::Event>
{
  auto retvalue = Glib::wrap(gtk_event_controller_get_current_event(const_cast<GtkEventController*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto EventController::get_current_event_time() const -> guint32
{
  return gtk_event_controller_get_current_event_time(const_cast<GtkEventController*>(gobj()));
}

auto EventController::get_current_event_device() -> Glib::RefPtr<Gdk::Device>
{
  auto retvalue = Glib::wrap(gtk_event_controller_get_current_event_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto EventController::get_current_event_device() const -> Glib::RefPtr<const Gdk::Device>
{
  return const_cast<EventController*>(this)->get_current_event_device();
}

auto EventController::get_current_event_state() const -> Gdk::ModifierType
{
  return static_cast<Gdk::ModifierType>(gtk_event_controller_get_current_event_state(const_cast<GtkEventController*>(gobj())));
}


auto EventController::property_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "widget"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PropagationPhase>::value,
  "Type PropagationPhase cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto EventController::property_propagation_phase() -> Glib::PropertyProxy< PropagationPhase >
{
  return {this, "propagation-phase"};
}

auto EventController::property_propagation_phase() const -> Glib::PropertyProxy_ReadOnly< PropagationPhase >
{
  return {this, "propagation-phase"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PropagationLimit>::value,
  "Type PropagationLimit cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto EventController::property_propagation_limit() -> Glib::PropertyProxy< PropagationLimit >
{
  return {this, "propagation-limit"};
}

auto EventController::property_propagation_limit() const -> Glib::PropertyProxy_ReadOnly< PropagationLimit >
{
  return {this, "propagation-limit"};
}

auto EventController::property_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "name"};
}

auto EventController::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}


} // namespace Gtk


