// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/eventcontroller.h>
#include <gtkmm/private/eventcontroller_p.h>


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
GType Glib::Value<Gtk::PropagationPhase>::value_type()
{
  return gtk_propagation_phase_get_type();
}

// static
GType Glib::Value<Gtk::PropagationLimit>::value_type()
{
  return gtk_propagation_limit_get_type();
}


namespace Glib
{

Glib::RefPtr<Gtk::EventController> wrap(GtkEventController* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::EventController>( dynamic_cast<Gtk::EventController*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& EventController_Class::init()
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


void EventController_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* EventController_Class::wrap_new(GObject* object)
{
  return new EventController((GtkEventController*)object);
}


/* The implementation: */

GtkEventController* EventController::gobj_copy()
{
  reference();
  return gobj();
}

EventController::EventController(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

EventController::EventController(GtkEventController* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


EventController::EventController(EventController&& src) noexcept
: Glib::Object(std::move(src))
{}

EventController& EventController::operator=(EventController&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


EventController::~EventController() noexcept
{}


EventController::CppClassType EventController::eventcontroller_class_; // initialize static member

GType EventController::get_type()
{
  return eventcontroller_class_.init().get_type();
}


GType EventController::get_base_type()
{
  return gtk_event_controller_get_type();
}


EventController::EventController()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(eventcontroller_class_.init()))
{
  

}

Widget* EventController::get_widget()
{
  return Glib::wrap(gtk_event_controller_get_widget(gobj()));
}

const Widget* EventController::get_widget() const
{
  return const_cast<EventController*>(this)->get_widget();
}

void EventController::reset()
{
  gtk_event_controller_reset(gobj());
}

PropagationPhase EventController::get_propagation_phase() const
{
  return static_cast<PropagationPhase>(gtk_event_controller_get_propagation_phase(const_cast<GtkEventController*>(gobj())));
}

void EventController::set_propagation_phase(PropagationPhase phase)
{
  gtk_event_controller_set_propagation_phase(gobj(), static_cast<GtkPropagationPhase>(phase));
}

PropagationLimit EventController::get_propagation_limit() const
{
  return static_cast<PropagationLimit>(gtk_event_controller_get_propagation_limit(const_cast<GtkEventController*>(gobj())));
}

void EventController::set_propagation_limit(PropagationLimit limit)
{
  gtk_event_controller_set_propagation_limit(gobj(), static_cast<GtkPropagationLimit>(limit));
}

Glib::ustring EventController::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_event_controller_get_name(const_cast<GtkEventController*>(gobj())));
}

void EventController::set_name(const Glib::ustring& name)
{
  gtk_event_controller_set_name(gobj(), name.c_str());
}

Glib::RefPtr<const Gdk::Event> EventController::get_current_event() const
{
  auto retvalue = Glib::wrap(gtk_event_controller_get_current_event(const_cast<GtkEventController*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

guint32 EventController::get_current_event_time() const
{
  return gtk_event_controller_get_current_event_time(const_cast<GtkEventController*>(gobj()));
}

Glib::RefPtr<Gdk::Device> EventController::get_current_event_device()
{
  auto retvalue = Glib::wrap(gtk_event_controller_get_current_event_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gdk::Device> EventController::get_current_event_device() const
{
  return const_cast<EventController*>(this)->get_current_event_device();
}

Gdk::ModifierType EventController::get_current_event_state() const
{
  return static_cast<Gdk::ModifierType>(gtk_event_controller_get_current_event_state(const_cast<GtkEventController*>(gobj())));
}


Glib::PropertyProxy_ReadOnly< Widget* > EventController::property_widget() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "widget");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PropagationPhase>::value,
  "Type PropagationPhase cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< PropagationPhase > EventController::property_propagation_phase() 
{
  return Glib::PropertyProxy< PropagationPhase >(this, "propagation-phase");
}

Glib::PropertyProxy_ReadOnly< PropagationPhase > EventController::property_propagation_phase() const
{
  return Glib::PropertyProxy_ReadOnly< PropagationPhase >(this, "propagation-phase");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PropagationLimit>::value,
  "Type PropagationLimit cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< PropagationLimit > EventController::property_propagation_limit() 
{
  return Glib::PropertyProxy< PropagationLimit >(this, "propagation-limit");
}

Glib::PropertyProxy_ReadOnly< PropagationLimit > EventController::property_propagation_limit() const
{
  return Glib::PropertyProxy_ReadOnly< PropagationLimit >(this, "propagation-limit");
}

Glib::PropertyProxy< Glib::ustring > EventController::property_name() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "name");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > EventController::property_name() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "name");
}


} // namespace Gtk


