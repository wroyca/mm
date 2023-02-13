


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/eventcontrollerlegacy.hxx>
#include <libmm-gtk/eventcontrollerlegacy_p.hxx>


/* Copyright (C) 2021 The gtkmm Development Team
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


auto EventControllerLegacy_signal_event_callback(GtkEventControllerLegacy* self, GdkEvent* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<const Gdk::Event>&)>;

  const auto obj = dynamic_cast<EventControllerLegacy*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
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

auto EventControllerLegacy_signal_event_notify_callback(GtkEventControllerLegacy* self, GdkEvent* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<const Gdk::Event>&)>;

  const auto obj = dynamic_cast<EventControllerLegacy*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
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

const Glib::SignalProxyInfo EventControllerLegacy_signal_event_info =
{
  "event",
  (GCallback) &EventControllerLegacy_signal_event_callback,
  (GCallback) &EventControllerLegacy_signal_event_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEventControllerLegacy* object, const bool take_copy) -> RefPtr<Gtk::EventControllerLegacy>
{
  return Glib::make_refptr_for_instance<Gtk::EventControllerLegacy>( dynamic_cast<Gtk::EventControllerLegacy*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EventControllerLegacy_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EventControllerLegacy_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_event_controller_legacy_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EventControllerLegacy_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EventControllerLegacy_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EventControllerLegacy((GtkEventControllerLegacy*)object);
}


/* The implementation: */

auto EventControllerLegacy::gobj_copy() -> GtkEventControllerLegacy*
{
  reference();
  return gobj();
}

EventControllerLegacy::EventControllerLegacy(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

EventControllerLegacy::EventControllerLegacy(GtkEventControllerLegacy* castitem)
:
  EventController((GtkEventController*)castitem)
{}


EventControllerLegacy::EventControllerLegacy(EventControllerLegacy&& src) noexcept
: EventController(std::move(src))
{}

auto EventControllerLegacy::operator=(EventControllerLegacy&& src) noexcept -> EventControllerLegacy&
{
  EventController::operator=(std::move(src));
  return *this;
}


EventControllerLegacy::~EventControllerLegacy() noexcept = default;

EventControllerLegacy::CppClassType EventControllerLegacy::eventcontrollerlegacy_class_; // initialize static member

auto EventControllerLegacy::get_type() -> GType
{
  return eventcontrollerlegacy_class_.init().get_type();
}


auto EventControllerLegacy::get_base_type() -> GType
{
  return gtk_event_controller_legacy_get_type();
}


EventControllerLegacy::EventControllerLegacy()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  EventController(Glib::ConstructParams(eventcontrollerlegacy_class_.init()))
{


}

auto EventControllerLegacy::create() -> Glib::RefPtr<EventControllerLegacy>
{
  return Glib::make_refptr_for_instance<EventControllerLegacy>( new EventControllerLegacy() );
}


auto EventControllerLegacy::signal_event() -> Glib::SignalProxy<bool(const Glib::RefPtr<const Gdk::Event>&)>
{
  return {this, &EventControllerLegacy_signal_event_info};
}


} // namespace Gtk

