// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/enums_p.hxx>

namespace
{
}

auto
glib::Value<gdk::AxisFlags>::value_type () -> GType
{
  return gdk_axis_flags_get_type ();
}

auto
glib::Value<gdk::AxisUse>::value_type () -> GType
{
  return gdk_axis_use_get_type ();
}

auto
glib::Value<gdk::CrossingMode>::value_type () -> GType
{
  return gdk_crossing_mode_get_type ();
}

auto
glib::Value<gdk::DragAction>::value_type () -> GType
{
  return gdk_drag_action_get_type ();
}

auto
glib::Value<gdk::Gravity>::value_type () -> GType
{
  return gdk_gravity_get_type ();
}

auto
glib::Value<gdk::ModifierType>::value_type () -> GType
{
  return gdk_modifier_type_get_type ();
}

auto
glib::Value<gdk::NotifyType>::value_type () -> GType
{
  return gdk_notify_type_get_type ();
}

auto
glib::Value<gdk::ScrollDirection>::value_type () -> GType
{
  return gdk_scroll_direction_get_type ();
}

auto
glib::Value<gdk::TouchpadGesturePhase>::value_type () -> GType
{
  return gdk_touchpad_gesture_phase_get_type ();
}

auto
glib::Value<gdk::ScrollUnit>::value_type () -> GType
{
  return gdk_scroll_unit_get_type ();
}
