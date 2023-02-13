
#ifndef _GTKMM_EVENTCONTROLLERSCROLL_H
#define _GTKMM_EVENTCONTROLLERSCROLL_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

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

#include <mm/gtk/eventcontroller.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerScroll = struct _GtkEventControllerScroll;
using GtkEventControllerScrollClass = struct _GtkEventControllerScrollClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EventControllerScroll_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Event controller for scroll events.
 *
 * %Gtk::EventControllerScroll is an event controller meant to handle
 * scroll events from mice and touchpads. It is capable of handling
 * both discrete and continuous scroll events, abstracting them both
 * on the signal_scroll() signal (deltas in the discrete case are multiples of 1).
 *
 * In the case of continuous scroll events, %EventControllerScroll
 * encloses all signal_scroll() events between two
 * signal_scroll_begin() and signal_scroll_end() signals.
 *
 * The behavior of the event controller can be modified by the
 * flags given at creation time, or modified at a later point through
 * set_flags() (e.g. because the scrolling conditions of the widget changed).
 *
 * The controller can be set up to emit motion for either/both vertical and
 * horizontal scroll events through Gtk::EventControllerScroll::Flags::VERTICAL,
 * Gtk::EventControllerScroll::Flags::HORIZONTAL and
 * Gtk::EventControllerScroll::Flags::BOTH_AXES.
 * If any axis is disabled, the respective signal_scroll()
 * delta will be 0. Vertical scroll events will be translated to horizontal
 * motion for the devices incapable of horizontal scrolling.
 *
 * The event controller can also be forced to emit discrete events on all devices
 * through Gtk::EventControllerScroll::Flags::DISCRETE. This can be used to implement
 * discrete actions triggered through scroll events (e.g. switching across
 * combobox options).
 *
 * The Gtk::EventControllerScroll::Flags::KINETIC flag toggles the emission of the
 * signal_decelerate() signal, emitted at the end of scrolling
 * with two X/Y velocity arguments that are consistent with the motion that
 * was received.
 *
 * @newin{3,94}
 *
 * @ingroup Gestures
 */

class GTKMM_API EventControllerScroll : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EventControllerScroll;
  using CppClassType = EventControllerScroll_Class;
  using BaseObjectType = GtkEventControllerScroll;
  using BaseClassType = GtkEventControllerScrollClass;

  // noncopyable
  EventControllerScroll(const EventControllerScroll&) = delete;
  auto operator=(const EventControllerScroll&) -> EventControllerScroll& = delete;

private:  friend class EventControllerScroll_Class;
  static CppClassType eventcontrollerscroll_class_;

protected:
  explicit EventControllerScroll(const Glib::ConstructParams& construct_params);
  explicit EventControllerScroll(GtkEventControllerScroll* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerScroll(EventControllerScroll&& src) noexcept;
  auto operator=(EventControllerScroll&& src) noexcept -> EventControllerScroll&;

  ~EventControllerScroll() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEventControllerScroll*       { return reinterpret_cast<GtkEventControllerScroll*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEventControllerScroll* { return reinterpret_cast<GtkEventControllerScroll*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEventControllerScroll*;

private:


protected:
  EventControllerScroll();

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Flags NONE
   * Don't emit scroll.
   *
   *  @var Flags VERTICAL
   * Emit scroll with vertical deltas.
   *
   *  @var Flags HORIZONTAL
   * Emit scroll with horizontal deltas.
   *
   *  @var Flags DISCRETE
   * Only emit deltas that are multiples of 1.
   *
   *  @var Flags KINETIC
   * Emit signal_decelerate() after continuous scroll finishes.
   *
   *  @var Flags BOTH_AXES
   * Emit scroll on both axes.
   *
   *  @enum Flags
   *
   * Describes the behavior of a `Gtk::EventControllerScroll`.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>EventControllerScroll::Flags operator|(EventControllerScroll::Flags, EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags operator&(EventControllerScroll::Flags, EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags operator^(EventControllerScroll::Flags, EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags operator~(EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags& operator|=(EventControllerScroll::Flags&, EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags& operator&=(EventControllerScroll::Flags&, EventControllerScroll::Flags)</tt><br>
   * <tt>EventControllerScroll::Flags& operator^=(EventControllerScroll::Flags&, EventControllerScroll::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    VERTICAL = 1 << 0,
    HORIZONTAL = 1 << 1,
    DISCRETE = 1 << 2,
    KINETIC = 1 << 3,
    BOTH_AXES = 0x3
  };


  static auto create() -> Glib::RefPtr<EventControllerScroll>;


  /** Sets the flags conditioning scroll controller behavior.
   *
   * @param flags Flags affecting the controller behavior.
   */
  void set_flags(Flags flags);

  /** Gets the flags conditioning the scroll controller behavior.
   *
   * @return The controller flags.
   */
  auto get_flags() const -> Flags;

  /** Gets the scroll unit of the last
   * signal_scroll() signal received.
   *
   * Always returns Gdk::ScrollUnit::WHEEL if the
   * Gtk::EventControllerScroll::Flags::DISCRETE flag is set.
   *
   * @newin{4,8}
   *
   * @return The scroll unit.
   */
  auto get_unit() const -> Gdk::ScrollUnit;

  /** The flags affecting event controller behavior.
   *
   * Default value: Gtk::EventControllerScroll::Flags::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() -> Glib::PropertyProxy< Flags > ;

/** The flags affecting event controller behavior.
   *
   * Default value: Gtk::EventControllerScroll::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;


  // no_default_handler because GtkEventControllerScrollClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%scroll_begin()</tt>
   *
   * Flags: Run First
   *
   * Signals that a new scrolling operation has begun.
   *
   * It will only be emitted on devices capable of it.
   */

  auto signal_scroll_begin() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%scroll(double dx, double dy)</tt>
   *
   * Flags: Run Last
   *
   * Signals that the widget should scroll by the
   * amount specified by @a dx and @a dy.
   *
   * For the representation unit of the deltas, see
   * Gtk::EventControllerScroll::get_unit().
   *
   * @param dx X delta.
   * @param dy Y delta.
   * @return <tt>true</tt> if the scroll event was handled,
   * <tt>false</tt> otherwise.
   */

  auto signal_scroll() -> Glib::SignalProxy<bool(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%scroll_end()</tt>
   *
   * Flags: Run First
   *
   * Signals that a scrolling operation has finished.
   *
   * It will only be emitted on devices capable of it.
   */

  auto signal_scroll_end() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%decelerate(double vel_x, double vel_y)</tt>
   *
   * Flags: Run First
   *
   * Emitted after scroll is finished if the
   * Gtk::EventControllerScroll::Flags::KINETIC flag is set.
   *
   *  @a vel_x and @a vel_y express the initial velocity that was
   * imprinted by the scroll events. @a vel_x and @a vel_y are expressed in
   * pixels/ms.
   *
   * @param vel_x X velocity.
   * @param vel_y Y velocity.
   */

  auto signal_decelerate() -> Glib::SignalProxy<void(double, double)>;


  // There are no vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  { return static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  { return static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  { return static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(EventControllerScroll::Flags flags) -> EventControllerScroll::Flags
  { return static_cast<EventControllerScroll::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(EventControllerScroll::Flags& lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  { return (lhs = static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(EventControllerScroll::Flags& lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  { return (lhs = static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(EventControllerScroll::Flags& lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  { return (lhs = static_cast<EventControllerScroll::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::EventControllerScroll::Flags> : public Glib::Value_Flags<Gtk::EventControllerScroll::Flags>
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
   * @relates Gtk::EventControllerScroll
   */
  GTKMM_API
  auto wrap(GtkEventControllerScroll* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerScroll>;
}


#endif /* _GTKMM_EVENTCONTROLLERSCROLL_H */

