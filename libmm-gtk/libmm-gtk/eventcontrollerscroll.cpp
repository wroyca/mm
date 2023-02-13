


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/eventcontrollerscroll.hpp>
#include <mm/gtk/private/eventcontrollerscroll_p.hpp>


/* Copyright (C) 2018 The gtkmm Development Team
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

using Flags = Gtk::EventControllerScroll::Flags;


namespace
{


const Glib::SignalProxyInfo EventControllerScroll_signal_scroll_begin_info =
{
  "scroll-begin",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto EventControllerScroll_signal_scroll_callback(GtkEventControllerScroll* self, const gdouble p0, const gdouble p1,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(double, double)>;

  const auto obj = dynamic_cast<EventControllerScroll*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(p0
                                               , p1
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto EventControllerScroll_signal_scroll_notify_callback(GtkEventControllerScroll* self, const gdouble p0, const gdouble p1, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<EventControllerScroll*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo EventControllerScroll_signal_scroll_info =
{
  "scroll",
  (GCallback) &EventControllerScroll_signal_scroll_callback,
  (GCallback) &EventControllerScroll_signal_scroll_notify_callback
};


const Glib::SignalProxyInfo EventControllerScroll_signal_scroll_end_info =
{
  "scroll-end",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto EventControllerScroll_signal_decelerate_callback (
  GtkEventControllerScroll *self, const gdouble p0, const gdouble p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<EventControllerScroll*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo EventControllerScroll_signal_decelerate_info =
{
  "decelerate",
  (GCallback) &EventControllerScroll_signal_decelerate_callback,
  (GCallback) &EventControllerScroll_signal_decelerate_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::EventControllerScroll::Flags>::value_type() -> GType
{
  return gtk_event_controller_scroll_flags_get_type();
}


namespace Glib
{

auto wrap(GtkEventControllerScroll* object, const bool take_copy) -> RefPtr<Gtk::EventControllerScroll>
{
  return Glib::make_refptr_for_instance<Gtk::EventControllerScroll>( dynamic_cast<Gtk::EventControllerScroll*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EventControllerScroll_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EventControllerScroll_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_event_controller_scroll_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EventControllerScroll_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EventControllerScroll_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EventControllerScroll((GtkEventControllerScroll*)object);
}


/* The implementation: */

auto EventControllerScroll::gobj_copy() -> GtkEventControllerScroll*
{
  reference();
  return gobj();
}

EventControllerScroll::EventControllerScroll(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

EventControllerScroll::EventControllerScroll(GtkEventControllerScroll* castitem)
:
  EventController((GtkEventController*)castitem)
{}


EventControllerScroll::EventControllerScroll(EventControllerScroll&& src) noexcept
: EventController(std::move(src))
{}

auto EventControllerScroll::operator=(EventControllerScroll&& src) noexcept -> EventControllerScroll&
{
  EventController::operator=(std::move(src));
  return *this;
}


EventControllerScroll::~EventControllerScroll() noexcept = default;

EventControllerScroll::CppClassType EventControllerScroll::eventcontrollerscroll_class_; // initialize static member

auto EventControllerScroll::get_type() -> GType
{
  return eventcontrollerscroll_class_.init().get_type();
}


auto EventControllerScroll::get_base_type() -> GType
{
  return gtk_event_controller_scroll_get_type();
}


EventControllerScroll::EventControllerScroll()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  EventController(Glib::ConstructParams(eventcontrollerscroll_class_.init()))
{


}

auto EventControllerScroll::create() -> Glib::RefPtr<EventControllerScroll>
{
  return Glib::make_refptr_for_instance<EventControllerScroll>( new EventControllerScroll() );
}

auto EventControllerScroll::set_flags (Flags flags) -> void
{
  gtk_event_controller_scroll_set_flags(gobj(), static_cast<GtkEventControllerScrollFlags>(flags));
}

auto EventControllerScroll::get_flags() const -> Flags
{
  return static_cast<Flags>(gtk_event_controller_scroll_get_flags(const_cast<GtkEventControllerScroll*>(gobj())));
}

auto EventControllerScroll::get_unit() const -> Gdk::ScrollUnit
{
  return static_cast<Gdk::ScrollUnit>(gtk_event_controller_scroll_get_unit(const_cast<GtkEventControllerScroll*>(gobj())));
}


auto EventControllerScroll::signal_scroll_begin() -> Glib::SignalProxy<void()>
{
  return {this, &EventControllerScroll_signal_scroll_begin_info};
}


auto EventControllerScroll::signal_scroll() -> Glib::SignalProxy<bool(double, double)>
{
  return {this, &EventControllerScroll_signal_scroll_info};
}


auto EventControllerScroll::signal_scroll_end() -> Glib::SignalProxy<void()>
{
  return {this, &EventControllerScroll_signal_scroll_end_info};
}


auto EventControllerScroll::signal_decelerate() -> Glib::SignalProxy<void(double, double)>
{
  return {this, &EventControllerScroll_signal_decelerate_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
  "Type Flags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto EventControllerScroll::property_flags() -> Glib::PropertyProxy< Flags >
{
  return {this, "flags"};
}

auto EventControllerScroll::property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >
{
  return {this, "flags"};
}


} // namespace Gtk


