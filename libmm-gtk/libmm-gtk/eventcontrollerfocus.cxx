


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerfocus.hxx>
#include <libmm-gtk/eventcontrollerfocus_p.hxx>


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

#include <gtk/gtk.h>


namespace
{


const Glib::SignalProxyInfo EventControllerFocus_signal_enter_info =
{
  "enter",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo EventControllerFocus_signal_leave_info =
{
  "leave",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEventControllerFocus* object, const bool take_copy) -> RefPtr<Gtk::EventControllerFocus>
{
  return Glib::make_refptr_for_instance<Gtk::EventControllerFocus>( dynamic_cast<Gtk::EventControllerFocus*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EventControllerFocus_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EventControllerFocus_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_event_controller_focus_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EventControllerFocus_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EventControllerFocus_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EventControllerFocus((GtkEventControllerFocus*)object);
}


/* The implementation: */

auto EventControllerFocus::gobj_copy() -> GtkEventControllerFocus*
{
  reference();
  return gobj();
}

EventControllerFocus::EventControllerFocus(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

EventControllerFocus::EventControllerFocus(GtkEventControllerFocus* castitem)
:
  EventController((GtkEventController*)castitem)
{}


EventControllerFocus::EventControllerFocus(EventControllerFocus&& src) noexcept
: EventController(std::move(src))
{}

auto EventControllerFocus::operator=(EventControllerFocus&& src) noexcept -> EventControllerFocus&
{
  EventController::operator=(std::move(src));
  return *this;
}


EventControllerFocus::~EventControllerFocus() noexcept = default;

EventControllerFocus::CppClassType EventControllerFocus::eventcontrollerfocus_class_; // initialize static member

auto EventControllerFocus::get_type() -> GType
{
  return eventcontrollerfocus_class_.init().get_type();
}


auto EventControllerFocus::get_base_type() -> GType
{
  return gtk_event_controller_focus_get_type();
}


EventControllerFocus::EventControllerFocus()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  EventController(Glib::ConstructParams(eventcontrollerfocus_class_.init()))
{


}

auto EventControllerFocus::create() -> Glib::RefPtr<EventControllerFocus>
{
  return Glib::make_refptr_for_instance<EventControllerFocus>( new EventControllerFocus() );
}

auto EventControllerFocus::contains_focus() const -> bool
{
  return gtk_event_controller_focus_contains_focus(const_cast<GtkEventControllerFocus*>(gobj()));
}

auto EventControllerFocus::is_focus() const -> bool
{
  return gtk_event_controller_focus_is_focus(const_cast<GtkEventControllerFocus*>(gobj()));
}


auto EventControllerFocus::signal_enter() -> Glib::SignalProxy<void()>
{
  return {this, &EventControllerFocus_signal_enter_info};
}


auto EventControllerFocus::signal_leave() -> Glib::SignalProxy<void()>
{
  return {this, &EventControllerFocus_signal_leave_info};
}


auto EventControllerFocus::property_is_focus() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-focus"};
}

auto EventControllerFocus::property_contains_focus() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "contains-focus"};
}


} // namespace Gtk

