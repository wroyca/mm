


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/enums_p.hxx>


/* Copyright (C) 2017 The gtkmm Development Team
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

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::AxisFlags>::value_type() -> GType
{
  return gdk_axis_flags_get_type();
}

// static
auto Glib::Value<Gdk::AxisUse>::value_type() -> GType
{
  return gdk_axis_use_get_type();
}

// static
auto Glib::Value<Gdk::CrossingMode>::value_type() -> GType
{
  return gdk_crossing_mode_get_type();
}

// static
auto Glib::Value<Gdk::DragAction>::value_type() -> GType
{
  return gdk_drag_action_get_type();
}

// static
auto Glib::Value<Gdk::Gravity>::value_type() -> GType
{
  return gdk_gravity_get_type();
}

// static
auto Glib::Value<Gdk::ModifierType>::value_type() -> GType
{
  return gdk_modifier_type_get_type();
}

// static
auto Glib::Value<Gdk::NotifyType>::value_type() -> GType
{
  return gdk_notify_type_get_type();
}

// static
auto Glib::Value<Gdk::ScrollDirection>::value_type() -> GType
{
  return gdk_scroll_direction_get_type();
}

// static
auto Glib::Value<Gdk::TouchpadGesturePhase>::value_type() -> GType
{
  return gdk_touchpad_gesture_phase_get_type();
}

// static
auto Glib::Value<Gdk::ScrollUnit>::value_type() -> GType
{
  return gdk_scroll_unit_get_type();
}


