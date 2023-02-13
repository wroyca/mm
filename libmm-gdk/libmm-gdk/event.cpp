


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/event.hpp>
#include <libmm-gdk/event_p.hpp>


/* Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gdk/device.hpp>
#include <libmm-gdk/devicetool.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/drop.hpp>
#include <libmm-gdk/seat.hpp>
#include <libmm-gdk/surface.hpp>

using Type = Gdk::Event::Type;

namespace Gdk
{

auto Event::get_axes() const -> std::vector<double>
{
  double* axes = nullptr;
  guint n_axes = 0;
  if (!gdk_event_get_axes(const_cast<GdkEvent*>(gobj()), &axes, &n_axes))
    return {};

  return std::vector<double>(axes, axes + n_axes);
}

auto Event::get_history() const -> std::vector<TimeCoord>
{
  guint n_coords = 0;
  const GdkTimeCoord* coords = gdk_event_get_history(const_cast<GdkEvent*>(gobj()), &n_coords);
  return Glib::ArrayHandler<TimeCoord, TimeCoordTraits>::array_to_vector(
    coords, n_coords, Glib::OWNERSHIP_DEEP);
}

} // name space Gdk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::KeyMatch>::value_type() -> GType
{
  return gdk_key_match_get_type();
}

// static
auto Glib::Value<Gdk::Event::Type>::value_type() -> GType
{
  return gdk_event_type_get_type();
}


/* Why reinterpret_cast<Event*>(gobject) is needed:
 *
 * A Event instance is in fact always a GdkEvent instance.
 * Unfortunately, GdkEvent cannot be a member of Event,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because Event does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GdkEvent* object, const bool take_copy) -> RefPtr<Gdk::Event>
{
  if(take_copy && object)
    gdk_event_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gdk::Event>(reinterpret_cast<Gdk::Event*>(object));
}

} // namespace Glib


namespace Gdk
{

auto Event::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_event_ref(reinterpret_cast<GdkEvent*>(const_cast<Event*>(this)));
}

auto Event::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_event_unref(reinterpret_cast<GdkEvent*>(const_cast<Event*>(this)));
}

auto Event::gobj() -> GdkEvent*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GdkEvent*>(this);
}

auto Event::gobj() const -> const GdkEvent*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GdkEvent*>(this);
}

auto Event::gobj_copy() const -> GdkEvent*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GdkEvent*>(const_cast<Event*>(this));
  gdk_event_ref(gobject);
  return gobject;
}


auto Event::get_event_type() const -> Type
{
  return static_cast<Type>(gdk_event_get_event_type(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_surface() -> Glib::RefPtr<Surface>
{
  auto retvalue = Glib::wrap(gdk_event_get_surface(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_surface() const -> Glib::RefPtr<const Surface>
{
  return const_cast<Event*>(this)->get_surface();
}

auto Event::get_seat() -> Glib::RefPtr<Seat>
{
  auto retvalue = Glib::wrap(gdk_event_get_seat(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_seat() const -> Glib::RefPtr<const Seat>
{
  return const_cast<Event*>(this)->get_seat();
}

auto Event::get_device() -> Glib::RefPtr<Device>
{
  auto retvalue = Glib::wrap(gdk_event_get_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_device() const -> Glib::RefPtr<const Device>
{
  return const_cast<Event*>(this)->get_device();
}

auto Event::get_device_tool() -> Glib::RefPtr<DeviceTool>
{
  auto retvalue = Glib::wrap(gdk_event_get_device_tool(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_device_tool() const -> Glib::RefPtr<const DeviceTool>
{
  return const_cast<Event*>(this)->get_device_tool();
}

auto Event::get_time() const -> guint32
{
  return gdk_event_get_time(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_event_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<Event*>(this)->get_display();
}

auto Event::get_event_sequence() const -> const EventSequence*
{
  return reinterpret_cast<const EventSequence*>(gdk_event_get_event_sequence(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_modifier_state() const -> ModifierType
{
  return static_cast<ModifierType>(gdk_event_get_modifier_state(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_position(double& x, double& y) const -> bool
{
  return gdk_event_get_position(const_cast<GdkEvent*>(gobj()), &x, &y);
}

auto Event::get_axis(
  AxisUse axis_use, double& value) const -> bool
{
  return gdk_event_get_axis(const_cast<GdkEvent*>(gobj()), static_cast<GdkAxisUse>(axis_use), &value);
}

auto Event::get_pointer_emulated() const -> bool
{
  return gdk_event_get_pointer_emulated(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_button() const -> guint
{
  return gdk_button_event_get_button(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_direction() const -> ScrollDirection
{
  return static_cast<ScrollDirection>(gdk_scroll_event_get_direction(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_deltas (double &delta_x, double &delta_y) const -> void
{
  gdk_scroll_event_get_deltas(const_cast<GdkEvent*>(gobj()), &delta_x, &delta_y);
}

auto Event::get_scroll_unit() const -> ScrollUnit
{
  return static_cast<ScrollUnit>(gdk_scroll_event_get_unit(const_cast<GdkEvent*>(gobj())));
}

auto Event::is_scroll_stop() const -> bool
{
  return gdk_scroll_event_is_stop(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_keyval() const -> guint
{
  return gdk_key_event_get_keyval(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_keycode() const -> guint
{
  return gdk_key_event_get_keycode(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_consumed_modifiers() const -> ModifierType
{
  return static_cast<ModifierType>(gdk_key_event_get_consumed_modifiers(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_layout() const -> guint
{
  return gdk_key_event_get_layout(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_level() const -> guint
{
  return gdk_key_event_get_level(const_cast<GdkEvent*>(gobj()));
}

auto Event::is_modifier() const -> bool
{
  return gdk_key_event_is_modifier(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_focus_in() const -> bool
{
  return gdk_focus_event_get_in(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_touch_emulating_pointer() const -> bool
{
  return gdk_touch_event_get_emulating_pointer(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_crossing_mode() const -> CrossingMode
{
  return static_cast<CrossingMode>(gdk_crossing_event_get_mode(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_crossing_detail() const -> NotifyType
{
  return static_cast<NotifyType>(gdk_crossing_event_get_detail(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_crossing_focus() const -> bool
{
  return gdk_crossing_event_get_focus(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_touchpad_gesture_phase() const -> TouchpadGesturePhase
{
  return static_cast<TouchpadGesturePhase>(gdk_touchpad_event_get_gesture_phase(const_cast<GdkEvent*>(gobj())));
}

auto Event::get_touchpad_n_fingers() const -> guint
{
  return gdk_touchpad_event_get_n_fingers(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_touchpad_deltas (double &dx, double &dy) const -> void
{
  gdk_touchpad_event_get_deltas(const_cast<GdkEvent*>(gobj()), &dx, &dy);
}

auto Event::get_touchpad_pinch_angle_delta() const -> double
{
  return gdk_touchpad_event_get_pinch_angle_delta(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_touchpad_pinch_scale() const -> double
{
  return gdk_touchpad_event_get_pinch_scale(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_pad_button() const -> guint
{
  return gdk_pad_event_get_button(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_pad_axis_value (guint &index, double &value) const -> void
{
  gdk_pad_event_get_axis_value(const_cast<GdkEvent*>(gobj()), &index, &value);
}

auto Event::get_pad_group_mode (guint &group, guint &mode) const -> void
{
  gdk_pad_event_get_group_mode(const_cast<GdkEvent*>(gobj()), &group, &mode);
}

auto Event::get_dnd_drop() -> Glib::RefPtr<Drop>
{
  auto retvalue = Glib::wrap(gdk_dnd_event_get_drop(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_dnd_drop() const -> Glib::RefPtr<const Drop>
{
  return const_cast<Event*>(this)->get_dnd_drop();
}

auto Event::get_grab_broken_grab_surface() -> Glib::RefPtr<Surface>
{
  auto retvalue = Glib::wrap(gdk_grab_broken_event_get_grab_surface(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Event::get_grab_broken_grab_surface() const -> Glib::RefPtr<const Surface>
{
  return const_cast<Event*>(this)->get_grab_broken_grab_surface();
}

auto Event::get_grab_broken_implicit() const -> bool
{
  return gdk_grab_broken_event_get_implicit(const_cast<GdkEvent*>(gobj()));
}

auto Event::triggers_context_menu() const -> bool
{
  return gdk_event_triggers_context_menu(const_cast<GdkEvent*>(gobj()));
}

auto Event::get_distance(const Glib::RefPtr<const Event>& event2, double& distance) const -> bool
{
  return gdk_events_get_distance(const_cast<GdkEvent*>(gobj()), const_cast<GdkEvent*>(Glib::unwrap(event2)), &distance);
}

auto Event::get_angle(const Glib::RefPtr<const Event>& event2, double& angle) const -> bool
{
  return gdk_events_get_angle(const_cast<GdkEvent*>(gobj()), const_cast<GdkEvent*>(Glib::unwrap(event2)), &angle);
}

auto Event::get_center(const Glib::RefPtr<const Event>& event2, double& x, double& y) const -> bool
{
  return gdk_events_get_center(const_cast<GdkEvent*>(gobj()), const_cast<GdkEvent*>(Glib::unwrap(event2)), &x, &y);
}

auto Event::matches(
  const guint keyval, ModifierType modifiers) const -> KeyMatch
{
  return static_cast<KeyMatch>(gdk_key_event_matches(const_cast<GdkEvent*>(gobj()), keyval, static_cast<GdkModifierType>(modifiers)));
}

auto Event::get_match(guint& keyval, ModifierType& modifiers) const -> bool
{
  return gdk_key_event_get_match(const_cast<GdkEvent*>(gobj()), &keyval, (GdkModifierType*) &modifiers);
}


} // namespace Gdk


