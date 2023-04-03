// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/enums_p.hxx>

namespace
{
}

auto
Glib::Value<Gdk::AxisFlags>::value_type () -> GType
{
  return gdk_axis_flags_get_type ();
}

auto
Glib::Value<Gdk::AxisUse>::value_type () -> GType
{
  return gdk_axis_use_get_type ();
}

auto
Glib::Value<Gdk::CrossingMode>::value_type () -> GType
{
  return gdk_crossing_mode_get_type ();
}

auto
Glib::Value<Gdk::DragAction>::value_type () -> GType
{
  return gdk_drag_action_get_type ();
}

auto
Glib::Value<Gdk::Gravity>::value_type () -> GType
{
  return gdk_gravity_get_type ();
}

auto
Glib::Value<Gdk::ModifierType>::value_type () -> GType
{
  return gdk_modifier_type_get_type ();
}

auto
Glib::Value<Gdk::NotifyType>::value_type () -> GType
{
  return gdk_notify_type_get_type ();
}

auto
Glib::Value<Gdk::ScrollDirection>::value_type () -> GType
{
  return gdk_scroll_direction_get_type ();
}

auto
Glib::Value<Gdk::TouchpadGesturePhase>::value_type () -> GType
{
  return gdk_touchpad_gesture_phase_get_type ();
}

auto
Glib::Value<Gdk::ScrollUnit>::value_type () -> GType
{
  return gdk_scroll_unit_get_type ();
}
