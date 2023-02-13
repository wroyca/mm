
#ifndef _GDKMM_EVENT_H
#define _GDKMM_EVENT_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <libmm-glib/refptr.hpp>
#include <libmm-glib/value.hpp>
#include <libmm-gdk/enums.hpp>
#include <libmm-gdk/timecoord.hpp>

/* Shadow DELETE macro (from winnt.h).
 * It interferes with Gdk::Event::Type::DELETE.
 */
#if defined(DELETE) && !defined(GTKMM_MACRO_SHADOW_DELETE)
enum { GTKMM_MACRO_DEFINITION_DELETE = DELETE };
#undef DELETE
enum { DELETE = GTKMM_MACRO_DEFINITION_DELETE };
#define DELETE DELETE
#define GTKMM_MACRO_SHADOW_DELETE 1
#endif

namespace Gdk
{
class GDKMM_API Device;
class GDKMM_API DeviceTool;
class GDKMM_API Display;
class GDKMM_API Drop;
class GDKMM_API Seat;
class GDKMM_API Surface;

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var KeyMatch NONE
 * The key event does not match.
 *
 *  @var KeyMatch PARTIAL
 * The key event matches if keyboard state
 * (specifically, the currently active group) is ignored.
 *
 *  @var KeyMatch EXACT
 * The key event matches.
 *
 *  @enum KeyMatch
 *
 * Describes how well an event matches a given keyval and modifiers.
 *
 * `Gdk::KeyMatch` values are returned by Gdk::KeyEvent::matches().
 *
 * @ingroup gdkmmEnums
 */
enum class KeyMatch
{
  NONE,
  PARTIAL,
  EXACT
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::KeyMatch> : public Glib::Value_Enum<Gdk::KeyMatch>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** Representing an event sequence.
 * Used to differentiate between multiple touches on multitouch touchscreens.
 * It's a hidden struct. You can test %EventSequence pointers for equality,
 * but you can't do much more with them.
 */
struct EventSequence;

/** Functions for handling events from the window system.
 *
 * In GTK applications the events are handled automatically by toplevel
 * widgets and passed on to the event controllers of appropriate widgets,
 * so these functions are rarely needed.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 */
class GDKMM_API Event final
{
  // GdkEvent is registered as a fundamental type.
  // It has custom reference-counting, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Event;
  using BaseObjectType = GdkEvent;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkEvent*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkEvent*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkEvent*;

  Event() = delete;

  // noncopyable
  Event(const Event&) = delete;
  auto operator=(const Event&) -> Event& = delete;

protected:
  // Do not derive this.  Gdk::Event can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:
  /**
   *  @var Type DELETE
   * The window manager has requested that the toplevel surface be
   * hidden or destroyed, usually when the user clicks on a special icon in the
   * title bar.
   *
   *  @var Type MOTION_NOTIFY
   * The pointer (usually a mouse) has moved.
   *
   *  @var Type BUTTON_PRESS
   * A mouse button has been pressed.
   *
   *  @var Type BUTTON_RELEASE
   * A mouse button has been released.
   *
   *  @var Type KEY_PRESS
   * A key has been pressed.
   *
   *  @var Type KEY_RELEASE
   * A key has been released.
   *
   *  @var Type ENTER_NOTIFY
   * The pointer has entered the surface.
   *
   *  @var Type LEAVE_NOTIFY
   * The pointer has left the surface.
   *
   *  @var Type FOCUS_CHANGE
   * The keyboard focus has entered or left the surface.
   *
   *  @var Type PROXIMITY_IN
   * An input device has moved into contact with a sensing
   * surface (e.g. a touchscreen or graphics tablet).
   *
   *  @var Type PROXIMITY_OUT
   * An input device has moved out of contact with a sensing
   * surface.
   *
   *  @var Type DRAG_ENTER
   * The mouse has entered the surface while a drag is in progress.
   *
   *  @var Type DRAG_LEAVE
   * The mouse has left the surface while a drag is in progress.
   *
   *  @var Type DRAG_MOTION
   * The mouse has moved in the surface while a drag is in
   * progress.
   *
   *  @var Type DROP_START
   * A drop operation onto the surface has started.
   *
   *  @var Type SCROLL
   * The scroll wheel was turned.
   *
   *  @var Type GRAB_BROKEN
   * A pointer or keyboard grab was broken.
   *
   *  @var Type TOUCH_BEGIN
   * A new touch event sequence has just started.
   *
   *  @var Type TOUCH_UPDATE
   * A touch event sequence has been updated.
   *
   *  @var Type TOUCH_END
   * A touch event sequence has finished.
   *
   *  @var Type TOUCH_CANCEL
   * A touch event sequence has been canceled.
   *
   *  @var Type TOUCHPAD_SWIPE
   * A touchpad swipe gesture event, the current state
   * is determined by its phase field.
   *
   *  @var Type TOUCHPAD_PINCH
   * A touchpad pinch gesture event, the current state
   * is determined by its phase field.
   *
   *  @var Type PAD_BUTTON_PRESS
   * A tablet pad button press event.
   *
   *  @var Type PAD_BUTTON_RELEASE
   * A tablet pad button release event.
   *
   *  @var Type PAD_RING
   * A tablet pad axis event from a "ring".
   *
   *  @var Type PAD_STRIP
   * A tablet pad axis event from a "strip".
   *
   *  @var Type PAD_GROUP_MODE
   * A tablet pad group mode change.
   *
   *  @var Type TOUCHPAD_HOLD
   * A touchpad hold gesture event, the current state
   * is determined by its phase field. @newin{4,6}
   *
   *  @var Type EVENT_LAST
   * Marks the end of the GdkEventType enumeration.
   *
   *  @enum Type
   *
   * Specifies the type of the event.
   *
   * @ingroup gdkmmEnums
   */
  enum class Type
  {
    DELETE,
    MOTION_NOTIFY,
    BUTTON_PRESS,
    BUTTON_RELEASE,
    KEY_PRESS,
    KEY_RELEASE,
    ENTER_NOTIFY,
    LEAVE_NOTIFY,
    FOCUS_CHANGE,
    PROXIMITY_IN,
    PROXIMITY_OUT,
    DRAG_ENTER,
    DRAG_LEAVE,
    DRAG_MOTION,
    DROP_START,
    SCROLL,
    GRAB_BROKEN,
    TOUCH_BEGIN,
    TOUCH_UPDATE,
    TOUCH_END,
    TOUCH_CANCEL,
    TOUCHPAD_SWIPE,
    TOUCHPAD_PINCH,
    PAD_BUTTON_PRESS,
    PAD_BUTTON_RELEASE,
    PAD_RING,
    PAD_STRIP,
    PAD_GROUP_MODE,
    TOUCHPAD_HOLD,
    EVENT_LAST
  };


  /** Retrieves the type of the event.
   *
   * @return A `Gdk::Event`Type.
   */
  auto get_event_type() const -> Type;


  /** Extracts the surface associated with an event.
   *
   * @return The `Gdk::Surface` associated with the event.
   */
  auto get_surface() -> Glib::RefPtr<Surface>;

  /** Extracts the surface associated with an event.
   *
   * @return The `Gdk::Surface` associated with the event.
   */
  auto get_surface() const -> Glib::RefPtr<const Surface>;


  /** Returns the seat that originated the event.
   *
   * @return A `Gdk::Seat`.
   */
  auto get_seat() -> Glib::RefPtr<Seat>;

  /** Returns the seat that originated the event.
   *
   * @return A `Gdk::Seat`.
   */
  auto get_seat() const -> Glib::RefPtr<const Seat>;


  /** Returns the device of an event.
   *
   * @newin{3,94}
   *
   * @return A `Gdk::Device`.
   */
  auto get_device() -> Glib::RefPtr<Device>;

  /** Returns the device of an event.
   *
   * @newin{3,94}
   *
   * @return A `Gdk::Device`.
   */
  auto get_device() const -> Glib::RefPtr<const Device>;


  /** Returns a `Gdk::DeviceTool` representing the tool that
   * caused the event.
   *
   * If the was not generated by a device that supports
   * different tools (such as a tablet), this function will
   * return <tt>nullptr</tt>.
   *
   * @note the `Gdk::DeviceTool` will be constant during
   * the application lifetime, if settings must be stored
   * persistently across runs, see Gdk::DeviceTool::get_serial().
   *
   * @return The current device tool.
   */
  auto get_device_tool() -> Glib::RefPtr<DeviceTool>;

  /** Returns a `Gdk::DeviceTool` representing the tool that
   * caused the event.
   *
   * If the was not generated by a device that supports
   * different tools (such as a tablet), this function will
   * return <tt>nullptr</tt>.
   *
   * @note the `Gdk::DeviceTool` will be constant during
   * the application lifetime, if settings must be stored
   * persistently across runs, see Gdk::DeviceTool::get_serial().
   *
   * @return The current device tool.
   */
  auto get_device_tool() const -> Glib::RefPtr<const DeviceTool>;


  /** Returns the timestamp of @a event.
   *
   * Not all events have timestamps. In that case, this function
   * returns GDK_CURRENT_TIME.
   *
   * @return Timestamp field from @a event.
   */
  auto get_time() const -> guint32;


  /** Retrieves the display associated to the @a event.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Retrieves the display associated to the @a event.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;


  /** Retuns the event sequence to which the event belongs.
   *
   * Related touch events are connected in a sequence. Other
   * events typically don't have event sequence information.
   *
   * @return The event sequence that the event belongs to.
   */
  auto get_event_sequence() const -> const EventSequence*;

  /** Returns the modifier state field of an event.
   *
   * @return The modifier state of @a event.
   */
  auto get_modifier_state() const -> ModifierType;

  /** Extract the event surface relative x/y coordinates from an event.
   *
   * @param x Location to put event surface x coordinate.
   * @param y Location to put event surface y coordinate.
   */
  auto get_position(double& x, double& y) const -> bool;

  /** Extracts all axis values from an event.
   *
   * @return A vector of values for all axes. An empty vector in case of failure.
   */
  auto get_axes() const -> std::vector<double>;


  /** Extract the axis value for a particular axis use from
   * an event structure.
   *
   * To find out which axes are used, use Gdk::DeviceTool::get_axes()
   * on the device tool returned by get_device_tool().
   *
   * @param axis_use The axis use to look for.
   * @param value Location to store the value found.
   * @return <tt>true</tt> if the specified axis was found, otherwise <tt>false</tt>.
   */
  auto get_axis(Gdk::AxisUse axis_use, double& value) const -> bool;

  /** Returns whether this event is an 'emulated' pointer event.
   *
   * Emulated pointer events typically originate from a touch events.
   *
   * @return <tt>true</tt> if this event is emulated.
   */
  auto get_pointer_emulated() const -> bool;

  /** Extract the button number from a button event.
   *
   * @return The button of @a event.
   */
  auto get_button() const -> guint;

  /** Extracts the direction of a scroll event.
   *
   * @return The scroll direction of @a event.
   */
  auto get_direction() const -> ScrollDirection;

  /** Extracts the scroll deltas of a scroll event.
   *
   * The deltas will be zero unless the scroll direction
   * is Gdk::ScrollDirection::SMOOTH.
   *
   * For the representation unit of these deltas, see
   * get_unit().
   *
   * @param delta_x Return location for x scroll delta.
   * @param delta_y Return location for y scroll delta.
   */
  void get_deltas(double& delta_x, double& delta_y) const;

  /** Extracts the scroll delta unit of a scroll event.
   *
   * The unit will always be Gdk::ScrollUnit::WHEEL if the scroll direction is not
   * Gdk::ScrollDirection::SMOOTH.
   *
   * @newin{4,8}
   *
   * @return The scroll unit.
   */
  auto get_scroll_unit() const -> ScrollUnit;

  /** Check whether a scroll event is a stop scroll event.
   *
   * Scroll sequences with smooth scroll information may provide
   * a stop scroll event once the interaction with the device finishes,
   * e.g. by lifting a finger. This stop scroll event is the signal
   * that a widget may trigger kinetic scrolling based on the current
   * velocity.
   *
   * Stop scroll events always have a delta of 0/0.
   *
   * @return <tt>true</tt> if the event is a scroll stop event.
   */
  auto is_scroll_stop() const -> bool;

  /** Extracts the keyval from a key event.
   *
   * @return The keyval of @a event.
   */
  auto get_keyval() const -> guint;

  /** Extracts the keycode from a key event.
   *
   * @return The keycode of @a event.
   */
  auto get_keycode() const -> guint;

  /** Extracts the consumed modifiers from a key event.
   *
   * @return The consumed modifiers or @a event.
   */
  auto get_consumed_modifiers() const -> ModifierType;

  /** Extracts the layout from a key event.
   *
   * @return The layout of @a event.
   */
  auto get_layout() const -> guint;

  /** Extracts the shift level from a key event.
   *
   * @return The shift level of @a event.
   */
  auto get_level() const -> guint;

  /** Extracts whether the key event is for a modifier key.
   *
   * @return <tt>true</tt> if the @a event is for a modifier key.
   */
  auto is_modifier() const -> bool;

  /** Extracts whether this event is about focus entering or
   * leaving the surface.
   *
   * @return <tt>true</tt> of the focus is entering.
   */
  auto get_focus_in() const -> bool;

  /** Extracts whether a touch event is emulating a pointer event.
   *
   * @return <tt>true</tt> if @a event is emulating.
   */
  auto get_touch_emulating_pointer() const -> bool;

  /** Extracts the crossing mode from a crossing event.
   *
   * @return The mode of @a event.
   */
  auto get_crossing_mode() const -> CrossingMode;

  /** Extracts the notify detail from a crossing event.
   *
   * @return The notify detail of @a event.
   */
  auto get_crossing_detail() const -> NotifyType;

  /** Checks if the @a event surface is the focus surface.
   *
   * @return <tt>true</tt> if the surface is the focus surface.
   */
  auto get_crossing_focus() const -> bool;

  /** Extracts the touchpad gesture phase from a touchpad event.
   *
   * @return The gesture phase of @a event.
   */
  auto get_touchpad_gesture_phase() const -> TouchpadGesturePhase;

  /** Extracts the number of fingers from a touchpad event.
   *
   * @return The number of fingers for @a event.
   */
  auto get_touchpad_n_fingers() const -> guint;

  /** Extracts delta information from a touchpad event.
   *
   * @param dx Return location for x.
   * @param dy Return location for y.
   */
  void get_touchpad_deltas(double& dx, double& dy) const;

  /** Extracts the angle delta from a touchpad pinch event.
   *
   * @return The angle delta of @a event.
   */
  auto get_touchpad_pinch_angle_delta() const -> double;

  /** Extracts the scale from a touchpad pinch event.
   *
   * @return The scale of @a event.
   */
  auto get_touchpad_pinch_scale() const -> double;

  /** Extracts information about the pressed button from
   * a pad event.
   *
   * @return The button of @a event.
   */
  auto get_pad_button() const -> guint;

  /** Extracts the information from a pad strip or ring event.
   *
   * @param index Return location for the axis index.
   * @param value Return location for the axis value.
   */
  void get_pad_axis_value(guint& index, double& value) const;

  /** Extracts group and mode information from a pad event.
   *
   * @param group Return location for the group.
   * @param mode Return location for the mode.
   */
  void get_pad_group_mode(guint& group, guint& mode) const;


  /** Gets the `Gdk::Drop` object from a DND event.
   *
   * @return The drop.
   */
  auto get_dnd_drop() -> Glib::RefPtr<Drop>;

  /** Gets the `Gdk::Drop` object from a DND event.
   *
   * @return The drop.
   */
  auto get_dnd_drop() const -> Glib::RefPtr<const Drop>;


  /** Extracts the grab surface from a grab broken event.
   *
   * @return The grab surface of @a event.
   */
  auto get_grab_broken_grab_surface() -> Glib::RefPtr<Surface>;

  /** Extracts the grab surface from a grab broken event.
   *
   * @return The grab surface of @a event.
   */
  auto get_grab_broken_grab_surface() const -> Glib::RefPtr<const Surface>;

  /** Checks whether the grab broken event is for an implicit grab.
   *
   * @return <tt>true</tt> if the an implicit grab was broken.
   */
  auto get_grab_broken_implicit() const -> bool;

  /** Retrieves the history of the event, as a vector of time and coordinates.
   *
   * The history includes events that are not delivered to the application
   * because they occurred in the same frame as this event.
   *
   * Note that only motion and scroll events record history, and motion
   * events only if one of the mouse buttons is down.
   *
   * @return A vector of time and coordinates.
   */
  auto get_history() const -> std::vector<TimeCoord>;


  /** Returns whether a `Gdk::Event` should trigger a context menu,
   * according to platform conventions.
   *
   * The right mouse button typically triggers context menus.
   *
   * This function should always be used instead of simply checking for
   * event->button == GDK_BUTTON_SECONDARY.
   *
   * @return <tt>true</tt> if the event should trigger a context menu.
   */
  auto triggers_context_menu() const -> bool;

  /** Returns the distance between the event locations.
   *
   * This assumes that both events have X/Y information.
   * If not, this function returns <tt>false</tt>.
   *
   * @param event2 Second `Gdk::Event`.
   * @param distance Return location for the distance.
   * @return <tt>true</tt> if the distance could be calculated.
   */
  auto get_distance(const Glib::RefPtr<const Event>& event2, double& distance) const -> bool;

  /** Returns the relative angle from @a event1 to @a event2.
   *
   * The relative angle is the angle between the X axis and the line
   * through both events' positions. The rotation direction for positive
   * angles is from the positive X axis towards the positive Y axis.
   *
   * This assumes that both events have X/Y information.
   * If not, this function returns <tt>false</tt>.
   *
   * @param event2 Second `Gdk::Event`.
   * @param angle Return location for the relative angle between both events.
   * @return <tt>true</tt> if the angle could be calculated.
   */
  auto get_angle(const Glib::RefPtr<const Event>& event2, double& angle) const -> bool;

  /** Returns the point halfway between the events' positions.
   *
   * This assumes that both events have X/Y information.
   * If not, this function returns <tt>false</tt>.
   *
   * @param event2 Second `Gdk::Event`.
   * @param x Return location for the X coordinate of the center.
   * @param y Return location for the Y coordinate of the center.
   * @return <tt>true</tt> if the center could be calculated.
   */
  auto get_center(const Glib::RefPtr<const Event>& event2, double& x, double& y) const -> bool;


  /** Matches a key event against a keyval and modifiers.
   *
   * This is typically used to trigger keyboard shortcuts such as Ctrl-C.
   *
   * Partial matches are possible where the combination matches
   * if the currently active group is ignored.
   *
   * Note that we ignore Caps Lock for matching.
   *
   * @param keyval The keyval to match.
   * @param modifiers The modifiers to match.
   * @return A `Gdk::KeyMatch` value describing whether @a event matches.
   */
  auto matches(guint keyval, ModifierType modifiers) const -> KeyMatch;

  /** Gets a keyval and modifier combination that will match
   * the event.
   *
   * See matches().
   *
   * @param keyval Return location for a keyval.
   * @param modifiers Return location for modifiers.
   * @return <tt>true</tt> on success.
   */
  auto get_match(guint& keyval, ModifierType& modifiers) const -> bool;


};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Event::Type> : public Glib::Value_Enum<Gdk::Event::Type>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::Event
 */
GDKMM_API
auto wrap(GdkEvent* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Event>;

} // namespace Glib


#endif /* _GDKMM_EVENT_H */

