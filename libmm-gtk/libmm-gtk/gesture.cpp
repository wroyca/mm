


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/gesture.hpp>
#include <mm/gtk/private/gesture_p.hpp>


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

#include <mm/gdk/device.hpp>
#include <gtk/gtk.h>

namespace Gtk
{
// Glib::ListHandler is not well suited for this case, where the contents
// of the GList shall not be converted to a C++ type.
auto Gesture::get_sequences() const -> std::vector<const Gdk::EventSequence*>
{
  std::vector<const Gdk::EventSequence*> sequences;
  const auto list = g_list_first(gtk_gesture_get_sequences(const_cast<GtkGesture*>(gobj())));

  for (GList* node = list; node; node = g_list_next(node))
    sequences.emplace_back(static_cast<Gdk::EventSequence*>(node->data));

  g_list_free(list);

  return sequences;
}

} //namespace Gtk

namespace
{


auto Gesture_signal_begin_callback (GtkGesture *self, GdkEventSequence *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Gdk::EventSequence*)>;

  const auto obj = dynamic_cast<Gesture*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(reinterpret_cast<Gdk::EventSequence*>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Gesture_signal_begin_info =
{
  "begin",
  (GCallback) &Gesture_signal_begin_callback,
  (GCallback) &Gesture_signal_begin_callback
};


auto Gesture_signal_end_callback (GtkGesture *self, GdkEventSequence *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Gdk::EventSequence*)>;

  const auto obj = dynamic_cast<Gesture*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(reinterpret_cast<Gdk::EventSequence*>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Gesture_signal_end_info =
{
  "end",
  (GCallback) &Gesture_signal_end_callback,
  (GCallback) &Gesture_signal_end_callback
};


auto Gesture_signal_update_callback (GtkGesture *self, GdkEventSequence *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Gdk::EventSequence*)>;

  const auto obj = dynamic_cast<Gesture*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(reinterpret_cast<Gdk::EventSequence*>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Gesture_signal_update_info =
{
  "update",
  (GCallback) &Gesture_signal_update_callback,
  (GCallback) &Gesture_signal_update_callback
};


auto Gesture_signal_cancel_callback (GtkGesture *self, GdkEventSequence *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Gdk::EventSequence*)>;

  const auto obj = dynamic_cast<Gesture*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(reinterpret_cast<Gdk::EventSequence*>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Gesture_signal_cancel_info =
{
  "cancel",
  (GCallback) &Gesture_signal_cancel_callback,
  (GCallback) &Gesture_signal_cancel_callback
};


auto Gesture_signal_sequence_state_changed_callback (
  GtkGesture *self, GdkEventSequence *p0, GtkEventSequenceState p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Gdk::EventSequence*, EventSequenceState)>;

  const auto obj = dynamic_cast<Gesture*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(reinterpret_cast<Gdk::EventSequence*>(p0)
, static_cast<EventSequenceState>(p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Gesture_signal_sequence_state_changed_info =
{
  "sequence_state_changed",
  (GCallback) &Gesture_signal_sequence_state_changed_callback,
  (GCallback) &Gesture_signal_sequence_state_changed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::EventSequenceState>::value_type() -> GType
{
  return gtk_event_sequence_state_get_type();
}


namespace Glib
{

auto wrap(GtkGesture* object, const bool take_copy) -> RefPtr<Gtk::Gesture>
{
  return Glib::make_refptr_for_instance<Gtk::Gesture>( dynamic_cast<Gtk::Gesture*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Gesture_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Gesture_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gesture_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Gesture_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Gesture_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Gesture((GtkGesture*)object);
}


/* The implementation: */

auto Gesture::gobj_copy() -> GtkGesture*
{
  reference();
  return gobj();
}

Gesture::Gesture(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

Gesture::Gesture(GtkGesture* castitem)
:
  EventController((GtkEventController*)castitem)
{}


Gesture::Gesture(Gesture&& src) noexcept
: EventController(std::move(src))
{}

auto Gesture::operator=(Gesture&& src) noexcept -> Gesture&
{
  EventController::operator=(std::move(src));
  return *this;
}


Gesture::~Gesture() noexcept = default;

Gesture::CppClassType Gesture::gesture_class_; // initialize static member

auto Gesture::get_type() -> GType
{
  return gesture_class_.init().get_type();
}


auto Gesture::get_base_type() -> GType
{
  return gtk_gesture_get_type();
}


Gesture::Gesture()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  EventController(Glib::ConstructParams(gesture_class_.init()))
{


}

auto Gesture::get_device() -> Glib::RefPtr<Gdk::Device>
{
  auto retvalue = Glib::wrap(gtk_gesture_get_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Gesture::get_device() const -> Glib::RefPtr<const Gdk::Device>
{
  return const_cast<Gesture*>(this)->get_device();
}

auto Gesture::set_state(EventSequenceState state) -> bool
{
  return gtk_gesture_set_state(gobj(), static_cast<GtkEventSequenceState>(state));
}

auto Gesture::get_sequence_state(Gdk::EventSequence* sequence) const -> EventSequenceState
{
  return static_cast<EventSequenceState>(gtk_gesture_get_sequence_state(const_cast<GtkGesture*>(gobj()), reinterpret_cast<GdkEventSequence*>(sequence)));
}

auto Gesture::set_sequence_state(Gdk::EventSequence* sequence, EventSequenceState state) -> bool
{
  return gtk_gesture_set_sequence_state(gobj(), reinterpret_cast<GdkEventSequence*>(sequence), static_cast<GtkEventSequenceState>(state));
}

auto Gesture::get_last_updated_sequence() -> Gdk::EventSequence*
{
  return reinterpret_cast<Gdk::EventSequence*>(gtk_gesture_get_last_updated_sequence(gobj()));
}

auto Gesture::get_last_updated_sequence() const -> const Gdk::EventSequence*
{
  return const_cast<Gesture*>(this)->get_last_updated_sequence();
}

auto Gesture::handles_sequence(Gdk::EventSequence* sequence) const -> bool
{
  return gtk_gesture_handles_sequence(const_cast<GtkGesture*>(gobj()), reinterpret_cast<GdkEventSequence*>(sequence));
}

auto Gesture::get_last_event(Gdk::EventSequence* sequence) -> Glib::RefPtr<Gdk::Event>
{
  auto retvalue = Glib::wrap(gtk_gesture_get_last_event(gobj(), reinterpret_cast<GdkEventSequence*>(sequence)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Gesture::get_last_event(Gdk::EventSequence* sequence) const -> Glib::RefPtr<const Gdk::Event>
{
  return const_cast<Gesture*>(this)->get_last_event(sequence);
}

auto Gesture::get_point(Gdk::EventSequence* sequence, double& x, double& y) const -> bool
{
  return gtk_gesture_get_point(const_cast<GtkGesture*>(gobj()), reinterpret_cast<GdkEventSequence*>(sequence), &x, &y);
}

auto Gesture::get_bounding_box(Gdk::Rectangle& rect) const -> bool
{
  return gtk_gesture_get_bounding_box(const_cast<GtkGesture*>(gobj()), rect.gobj());
}

auto Gesture::get_bounding_box_center(double& x, double& y) const -> bool
{
  return gtk_gesture_get_bounding_box_center(const_cast<GtkGesture*>(gobj()), &x, &y);
}

auto Gesture::is_active() const -> bool
{
  return gtk_gesture_is_active(const_cast<GtkGesture*>(gobj()));
}

auto Gesture::is_recognized() const -> bool
{
  return gtk_gesture_is_recognized(const_cast<GtkGesture*>(gobj()));
}

auto Gesture::group (const Glib::RefPtr <Gesture> &group_gesture) -> void
{
  gtk_gesture_group(gobj(), Glib::unwrap(group_gesture));
}

auto Gesture::ungroup () -> void
{
  gtk_gesture_ungroup(gobj());
}

auto Gesture::get_group() -> std::vector< Glib::RefPtr<Gesture> >
{
  return Glib::ListHandler< Glib::RefPtr<Gesture> >::list_to_vector(gtk_gesture_get_group(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto Gesture::get_group() const -> std::vector< Glib::RefPtr<const Gesture> >
{
  return Glib::ListHandler< Glib::RefPtr<const Gesture> >::list_to_vector(gtk_gesture_get_group(const_cast<GtkGesture*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto Gesture::is_grouped_with(const Glib::RefPtr<Gesture>& other) const -> bool
{
  return gtk_gesture_is_grouped_with(const_cast<GtkGesture*>(gobj()), Glib::unwrap(other));
}


auto Gesture::signal_begin() -> Glib::SignalProxy<void(Gdk::EventSequence*)>
{
  return {this, &Gesture_signal_begin_info};
}


auto Gesture::signal_end() -> Glib::SignalProxy<void(Gdk::EventSequence*)>
{
  return {this, &Gesture_signal_end_info};
}


auto Gesture::signal_update() -> Glib::SignalProxy<void(Gdk::EventSequence*)>
{
  return {this, &Gesture_signal_update_info};
}


auto Gesture::signal_cancel() -> Glib::SignalProxy<void(Gdk::EventSequence*)>
{
  return {this, &Gesture_signal_cancel_info};
}


auto Gesture::signal_sequence_state_changed() -> Glib::SignalProxy<void(Gdk::EventSequence*, EventSequenceState)>
{
  return {this, &Gesture_signal_sequence_state_changed_info};
}


auto Gesture::property_n_points() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-points"};
}


} // namespace Gtk


