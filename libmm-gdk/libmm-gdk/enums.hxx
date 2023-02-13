
#ifndef _GDKMM_ENUMS_H
#define _GDKMM_ENUMS_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

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


#include <libmm-glib/value.hxx>
#include <gdk/gdk.h>


namespace Gdk
{
/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var AxisFlags X
 * X axis is present.
 *
 *  @var AxisFlags Y
 * Y axis is present.
 *
 *  @var AxisFlags DELTA_X
 * Scroll X delta axis is present.
 *
 *  @var AxisFlags DELTA_Y
 * Scroll Y delta axis is present.
 *
 *  @var AxisFlags PRESSURE
 * Pressure axis is present.
 *
 *  @var AxisFlags XTILT
 * X tilt axis is present.
 *
 *  @var AxisFlags YTILT
 * Y tilt axis is present.
 *
 *  @var AxisFlags WHEEL
 * Wheel axis is present.
 *
 *  @var AxisFlags DISTANCE
 * Distance axis is present.
 *
 *  @var AxisFlags ROTATION
 * Z-axis rotation is present.
 *
 *  @var AxisFlags SLIDER
 * Slider axis is present.
 *
 *  @enum AxisFlags
 *
 * Flags describing the current capabilities of a device/tool.
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>AxisFlags operator|(AxisFlags, AxisFlags)</tt><br>
 * <tt>AxisFlags operator&(AxisFlags, AxisFlags)</tt><br>
 * <tt>AxisFlags operator^(AxisFlags, AxisFlags)</tt><br>
 * <tt>AxisFlags operator~(AxisFlags)</tt><br>
 * <tt>AxisFlags& operator|=(AxisFlags&, AxisFlags)</tt><br>
 * <tt>AxisFlags& operator&=(AxisFlags&, AxisFlags)</tt><br>
 * <tt>AxisFlags& operator^=(AxisFlags&, AxisFlags)</tt><br>
 */
enum class AxisFlags
{
  X = 0x2,
  Y = 0x4,
  DELTA_X = 0x8,
  DELTA_Y = 0x10,
  PRESSURE = 0x20,
  XTILT = 0x40,
  YTILT = 0x80,
  WHEEL = 0x100,
  DISTANCE = 0x200,
  ROTATION = 0x400,
  SLIDER = 0x800
};

/** @ingroup gdkmmEnums */
inline auto operator|(AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  { return static_cast<AxisFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  { return static_cast<AxisFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(AxisFlags lhs, AxisFlags rhs) -> AxisFlags
  { return static_cast<AxisFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(AxisFlags flags) -> AxisFlags
  { return static_cast<AxisFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  { return (lhs = static_cast<AxisFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  { return (lhs = static_cast<AxisFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(AxisFlags& lhs, AxisFlags rhs) -> AxisFlags&
  { return (lhs = static_cast<AxisFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::AxisFlags> : public Glib::Value_Flags<Gdk::AxisFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var AxisUse IGNORE
 * The axis is ignored.
 *
 *  @var AxisUse X
 * The axis is used as the x axis.
 *
 *  @var AxisUse Y
 * The axis is used as the y axis.
 *
 *  @var AxisUse DELTA_X
 * The axis is used as the scroll x delta.
 *
 *  @var AxisUse DELTA_Y
 * The axis is used as the scroll y delta.
 *
 *  @var AxisUse PRESSURE
 * The axis is used for pressure information.
 *
 *  @var AxisUse XTILT
 * The axis is used for x tilt information.
 *
 *  @var AxisUse YTILT
 * The axis is used for y tilt information.
 *
 *  @var AxisUse WHEEL
 * The axis is used for wheel information.
 *
 *  @var AxisUse DISTANCE
 * The axis is used for pen/tablet distance information.
 *
 *  @var AxisUse ROTATION
 * The axis is used for pen rotation information.
 *
 *  @var AxisUse SLIDER
 * The axis is used for pen slider information.
 *
 *  @var AxisUse LAST
 * A constant equal to the numerically highest axis value.
 *
 *  @enum AxisUse
 *
 * Defines how device axes are interpreted by GTK.
 *
 * Note that the X and Y axes are not really needed; pointer devices
 * report their location via the x/y members of events regardless. Whether
 * X and Y are present as axes depends on the GDK backend.
 *
 * @ingroup gdkmmEnums
 */
enum class AxisUse
{
  IGNORE,
  X,
  Y,
  DELTA_X,
  DELTA_Y,
  PRESSURE,
  XTILT,
  YTILT,
  WHEEL,
  DISTANCE,
  ROTATION,
  SLIDER,
  LAST
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::AxisUse> : public Glib::Value_Enum<Gdk::AxisUse>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var CrossingMode NORMAL
 * Crossing because of pointer motion.
 *
 *  @var CrossingMode GRAB
 * Crossing because a grab is activated.
 *
 *  @var CrossingMode UNGRAB
 * Crossing because a grab is deactivated.
 *
 *  @var CrossingMode GTK_GRAB
 * Crossing because a GTK grab is activated.
 *
 *  @var CrossingMode GTK_UNGRAB
 * Crossing because a GTK grab is deactivated.
 *
 *  @var CrossingMode STATE_CHANGED
 * Crossing because a GTK widget changed
 * state (e.g. sensitivity).
 *
 *  @var CrossingMode TOUCH_BEGIN
 * Crossing because a touch sequence has begun,
 * this event is synthetic as the pointer might have not left the surface.
 *
 *  @var CrossingMode TOUCH_END
 * Crossing because a touch sequence has ended,
 * this event is synthetic as the pointer might have not left the surface.
 *
 *  @var CrossingMode DEVICE_SWITCH
 * Crossing because of a device switch (i.e.
 * a mouse taking control of the pointer after a touch device), this event
 * is synthetic as the pointer didn’t leave the surface.
 *
 *  @enum CrossingMode
 *
 * Specifies the crossing mode for enter and leave events.
 *
 * @ingroup gdkmmEnums
 */
enum class CrossingMode
{
  NORMAL,
  GRAB,
  UNGRAB,
  GTK_GRAB,
  GTK_UNGRAB,
  STATE_CHANGED,
  TOUCH_BEGIN,
  TOUCH_END,
  DEVICE_SWITCH
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::CrossingMode> : public Glib::Value_Enum<Gdk::CrossingMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var DragAction COPY
 * Copy the data.
 *
 *  @var DragAction MOVE
 * Move the data, i.e. first copy it, then delete
 * it from the source using the DELETE target of the X selection protocol.
 *
 *  @var DragAction LINK
 * Add a link to the data. Note that this is only
 * useful if source and destination agree on what it means, and is not
 * supported on all platforms.
 *
 *  @var DragAction ASK
 * Ask the user what to do with the data.
 *
 *  @enum DragAction
 *
 * Used in `Gdk::Drop` and `Gdk::Drag` to indicate the actions that the
 * destination can and should do with the dropped data.
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>DragAction operator|(DragAction, DragAction)</tt><br>
 * <tt>DragAction operator&(DragAction, DragAction)</tt><br>
 * <tt>DragAction operator^(DragAction, DragAction)</tt><br>
 * <tt>DragAction operator~(DragAction)</tt><br>
 * <tt>DragAction& operator|=(DragAction&, DragAction)</tt><br>
 * <tt>DragAction& operator&=(DragAction&, DragAction)</tt><br>
 * <tt>DragAction& operator^=(DragAction&, DragAction)</tt><br>
 */
enum class DragAction
{
  COPY = 1 << 0,
  MOVE = 1 << 1,
  LINK = 1 << 2,
  ASK = 1 << 3
};

/** @ingroup gdkmmEnums */
inline auto operator|(DragAction lhs, DragAction rhs) -> DragAction
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(DragAction lhs, DragAction rhs) -> DragAction
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(DragAction lhs, DragAction rhs) -> DragAction
  { return static_cast<DragAction>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(DragAction flags) -> DragAction
  { return static_cast<DragAction>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(DragAction& lhs, DragAction rhs) -> DragAction&
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(DragAction& lhs, DragAction rhs) -> DragAction&
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(DragAction& lhs, DragAction rhs) -> DragAction&
  { return (lhs = static_cast<DragAction>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::DragAction> : public Glib::Value_Flags<Gdk::DragAction>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var Gravity NORTH_WEST
 * The reference point is at the top left corner.
 *
 *  @var Gravity NORTH
 * The reference point is in the middle of the top edge.
 *
 *  @var Gravity NORTH_EAST
 * The reference point is at the top right corner.
 *
 *  @var Gravity WEST
 * The reference point is at the middle of the left edge.
 *
 *  @var Gravity CENTER
 * The reference point is at the center of the surface.
 *
 *  @var Gravity EAST
 * The reference point is at the middle of the right edge.
 *
 *  @var Gravity SOUTH_WEST
 * The reference point is at the lower left corner.
 *
 *  @var Gravity SOUTH
 * The reference point is at the middle of the lower edge.
 *
 *  @var Gravity SOUTH_EAST
 * The reference point is at the lower right corner.
 *
 *  @var Gravity STATIC
 * The reference point is at the top left corner of the
 * surface itself, ignoring window manager decorations.
 *
 *  @enum Gravity
 *
 * Defines the reference point of a surface and is used in `Gdk::PopupLayout`.
 *
 * @ingroup gdkmmEnums
 */
enum class Gravity
{
  NORTH_WEST = 1,
  NORTH,
  NORTH_EAST,
  WEST,
  CENTER,
  EAST,
  SOUTH_WEST,
  SOUTH,
  SOUTH_EAST,
  STATIC
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Gravity> : public Glib::Value_Enum<Gdk::Gravity>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var ModifierType SHIFT_MASK
 * The Shift key.
 *
 *  @var ModifierType LOCK_MASK
 * A Lock key (depending on the modifier mapping of the
 * X server this may either be CapsLock or ShiftLock).
 *
 *  @var ModifierType CONTROL_MASK
 * The Control key.
 *
 *  @var ModifierType ALT_MASK
 * The fourth modifier key (it depends on the modifier
 * mapping of the X server which key is interpreted as this modifier, but
 * normally it is the Alt key).
 *
 *  @var ModifierType BUTTON1_MASK
 * The first mouse button.
 *
 *  @var ModifierType BUTTON2_MASK
 * The second mouse button.
 *
 *  @var ModifierType BUTTON3_MASK
 * The third mouse button.
 *
 *  @var ModifierType BUTTON4_MASK
 * The fourth mouse button.
 *
 *  @var ModifierType BUTTON5_MASK
 * The fifth mouse button.
 *
 *  @var ModifierType SUPER_MASK
 * The Super modifier.
 *
 *  @var ModifierType HYPER_MASK
 * The Hyper modifier.
 *
 *  @var ModifierType META_MASK
 * The Meta modifier.
 *
 *  @enum ModifierType
 *
 * Flags to indicate the state of modifier keys and mouse buttons
 * in events.
 *
 * Typical modifier keys are Shift, Control, Meta, Super, Hyper, Alt, Compose,
 * Apple, CapsLock or ShiftLock.
 *
 * Note that GDK may add internal values to events which include values outside
 * of this enumeration. Your code should preserve and ignore them.  You can use
 * GDK_MODIFIER_MASK to remove all private values.
 *
 * @ingroup gdkmmEnums
 * @par Bitwise operators:
 * <tt>ModifierType operator|(ModifierType, ModifierType)</tt><br>
 * <tt>ModifierType operator&(ModifierType, ModifierType)</tt><br>
 * <tt>ModifierType operator^(ModifierType, ModifierType)</tt><br>
 * <tt>ModifierType operator~(ModifierType)</tt><br>
 * <tt>ModifierType& operator|=(ModifierType&, ModifierType)</tt><br>
 * <tt>ModifierType& operator&=(ModifierType&, ModifierType)</tt><br>
 * <tt>ModifierType& operator^=(ModifierType&, ModifierType)</tt><br>
 */
enum class ModifierType
{
  SHIFT_MASK = 1 << 0,
  LOCK_MASK = 1 << 1,
  CONTROL_MASK = 1 << 2,
  ALT_MASK = 1 << 3,
  BUTTON1_MASK = 1 << 8,
  BUTTON2_MASK = 1 << 9,
  BUTTON3_MASK = 1 << 10,
  BUTTON4_MASK = 1 << 11,
  BUTTON5_MASK = 1 << 12,
  SUPER_MASK = 1 << 26,
  HYPER_MASK = 1 << 27,
  META_MASK = 1 << 28
};

/** @ingroup gdkmmEnums */
inline auto operator|(ModifierType lhs, ModifierType rhs) -> ModifierType
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(ModifierType lhs, ModifierType rhs) -> ModifierType
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(ModifierType lhs, ModifierType rhs) -> ModifierType
  { return static_cast<ModifierType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(ModifierType flags) -> ModifierType
  { return static_cast<ModifierType>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(ModifierType& lhs, ModifierType rhs) -> ModifierType&
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(ModifierType& lhs, ModifierType rhs) -> ModifierType&
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(ModifierType& lhs, ModifierType rhs) -> ModifierType&
  { return (lhs = static_cast<ModifierType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::ModifierType> : public Glib::Value_Flags<Gdk::ModifierType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var NotifyType ANCESTOR
 * The surface is entered from an ancestor or
 * left towards an ancestor.
 *
 *  @var NotifyType VIRTUAL
 * The pointer moves between an ancestor and an
 * inferior of the surface.
 *
 *  @var NotifyType INFERIOR
 * The surface is entered from an inferior or
 * left towards an inferior.
 *
 *  @var NotifyType NONLINEAR
 * The surface is entered from or left towards
 * a surface which is neither an ancestor nor an inferior.
 *
 *  @var NotifyType NONLINEAR_VIRTUAL
 * The pointer moves between two surfaces
 * which are not ancestors of each other and the surface is part of
 * the ancestor chain between one of these surfaces and their least
 * common ancestor.
 *
 *  @var NotifyType UNKNOWN
 * An unknown type of enter/leave event occurred.
 *
 *  @enum NotifyType
 *
 * Specifies the kind of crossing for enter and leave events.
 *
 * See the X11 protocol specification of LeaveNotify for
 * full details of crossing event generation.
 *
 * @ingroup gdkmmEnums
 */
enum class NotifyType
{
  ANCESTOR,
  VIRTUAL,
  INFERIOR,
  NONLINEAR,
  NONLINEAR_VIRTUAL,
  UNKNOWN
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::NotifyType> : public Glib::Value_Enum<Gdk::NotifyType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var ScrollDirection UP
 * The surface is scrolled up.
 *
 *  @var ScrollDirection DOWN
 * The surface is scrolled down.
 *
 *  @var ScrollDirection LEFT
 * The surface is scrolled to the left.
 *
 *  @var ScrollDirection RIGHT
 * The surface is scrolled to the right.
 *
 *  @var ScrollDirection SMOOTH
 * The scrolling is determined by the delta values
 * in scroll events. See gdk_scroll_event_get_deltas().
 *
 *  @enum ScrollDirection
 *
 * Specifies the direction for scroll events.
 *
 * @ingroup gdkmmEnums
 */
enum class ScrollDirection
{
  UP,
  DOWN,
  LEFT,
  RIGHT,
  SMOOTH
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::ScrollDirection> : public Glib::Value_Enum<Gdk::ScrollDirection>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var TouchpadGesturePhase BEGIN
 * The gesture has begun.
 *
 *  @var TouchpadGesturePhase UPDATE
 * The gesture has been updated.
 *
 *  @var TouchpadGesturePhase END
 * The gesture was finished, changes
 * should be permanently applied.
 *
 *  @var TouchpadGesturePhase CANCEL
 * The gesture was cancelled, all
 * changes should be undone.
 *
 *  @enum TouchpadGesturePhase
 *
 * Specifies the current state of a touchpad gesture.
 *
 * All gestures are guaranteed to begin with an event with phase
 * Gdk::TouchpadGesturePhase::BEGIN, followed by 0 or several events
 * with phase Gdk::TouchpadGesturePhase::UPDATE.
 *
 * A finished gesture may have 2 possible outcomes, an event with phase
 * Gdk::TouchpadGesturePhase::END will be emitted when the gesture is
 * considered successful, this should be used as the hint to perform any
 * permanent changes.
 *
 * Cancelled gestures may be so for a variety of reasons, due to hardware
 * or the compositor, or due to the gesture recognition layers hinting the
 * gesture did not finish resolutely (eg. a 3rd finger being added during
 * a pinch gesture). In these cases, the last event will report the phase
 * Gdk::TouchpadGesturePhase::CANCEL, this should be used as a hint
 * to undo any visible/permanent changes that were done throughout the
 * progress of the gesture.
 *
 * @ingroup gdkmmEnums
 */
enum class TouchpadGesturePhase
{
  BEGIN,
  UPDATE,
  END,
  CANCEL
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::TouchpadGesturePhase> : public Glib::Value_Enum<Gdk::TouchpadGesturePhase>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var ScrollUnit WHEEL
 * The delta is in number of wheel clicks.
 *
 *  @var ScrollUnit SURFACE
 * The delta is in surface pixels to scroll directly
 * on screen.
 *
 *  @enum ScrollUnit
 *
 * Specifies the unit of scroll deltas.
 *
 * When you get Gdk::ScrollUnit::WHEEL, a delta of 1.0 means 1 wheel detent
 * click in the south direction, 2.0 means 2 wheel detent clicks in the south
 * direction... This is the same logic for negative values but in the north
 * direction.
 *
 * If you get Gdk::ScrollUnit::SURFACE, are managing a scrollable view and get a
 * value of 123, you have to scroll 123 surface logical pixels right if it's
 *  @a delta_x or down if it's @a delta_y. This is the same logic for negative values
 * but you have to scroll left instead of right if it's @a delta_x and up instead
 * of down if it's @a delta_y.
 *
 * 1 surface logical pixel is equal to 1 real screen pixel multiplied by the
 * final scale factor of your graphical interface (the product of the desktop
 * scale factor and eventually a custom scale factor in your app).
 *
 * @newin{4,8}
 *
 * @ingroup gdkmmEnums
 */
enum class ScrollUnit
{
  WHEEL,
  SURFACE
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::ScrollUnit> : public Glib::Value_Enum<Gdk::ScrollUnit>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


} //namespace Gdk


#endif /* _GDKMM_ENUMS_H */

