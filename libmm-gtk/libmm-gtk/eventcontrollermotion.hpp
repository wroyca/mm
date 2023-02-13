
#ifndef _GTKMM_EVENTCONTROLLERMOTION_H
#define _GTKMM_EVENTCONTROLLERMOTION_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/eventcontroller.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerMotion = struct _GtkEventControllerMotion;
using GtkEventControllerMotionClass = struct _GtkEventControllerMotionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EventControllerMotion_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Event controller for motion events.
 *
 * %Gtk::EventControllerMotion is an event controller meant for situations
 * where you need to track the position of the pointer.
 *
 * @newin{3,94}
 *
 * @ingroup Gestures
 */

class GTKMM_API EventControllerMotion : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EventControllerMotion;
  using CppClassType = EventControllerMotion_Class;
  using BaseObjectType = GtkEventControllerMotion;
  using BaseClassType = GtkEventControllerMotionClass;

  // noncopyable
  EventControllerMotion(const EventControllerMotion&) = delete;
  auto operator=(const EventControllerMotion&) -> EventControllerMotion& = delete;

private:  friend class EventControllerMotion_Class;
  static CppClassType eventcontrollermotion_class_;

protected:
  explicit EventControllerMotion(const Glib::ConstructParams& construct_params);
  explicit EventControllerMotion(GtkEventControllerMotion* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerMotion(EventControllerMotion&& src) noexcept;
  auto operator=(EventControllerMotion&& src) noexcept -> EventControllerMotion&;

  ~EventControllerMotion() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEventControllerMotion*       { return reinterpret_cast<GtkEventControllerMotion*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEventControllerMotion* { return reinterpret_cast<GtkEventControllerMotion*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEventControllerMotion*;

private:


protected:
  EventControllerMotion();

public:

  static auto create() -> Glib::RefPtr<EventControllerMotion>;


  /** Returns if a pointer is within @a self or one of its children.
   *
   * @return <tt>true</tt> if a pointer is within @a self or one of its children.
   */
  auto contains_pointer() const -> bool;

  /** Returns if a pointer is within @a self, but not one of its children.
   *
   * @return <tt>true</tt> if a pointer is within @a self but not one of its children.
   */
  auto is_pointer() const -> bool;

  // no_default_handler because GtkEventControllerMotionClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%enter(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Signals that the pointer has entered the widget.
   *
   * @param x Coordinates of pointer location.
   * @param y Coordinates of pointer location.
   */

  auto signal_enter() -> Glib::SignalProxy<void(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%leave()</tt>
   *
   * Flags: Run Last
   *
   * Signals that the pointer has left the widget.
   */

  auto signal_leave() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%motion(double x, double y)</tt>
   *
   * Flags: Run First
   *
   * Emitted when the pointer moves inside the widget.
   *
   * @param x The x coordinate.
   * @param y The y coordinate.
   */

  auto signal_motion() -> Glib::SignalProxy<void(double, double)>;


  /** Whether the pointer is in the controllers widget itself,
   * as opposed to in a descendent widget.
   *
   * See also property_contains_pointer().
   *
   * When handling crossing events, this property is updated
   * before signal_enter(), but after
   * signal_leave() is emitted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_pointer() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the pointer is in the controllers widget or a descendant.
   *
   * See also property_is_pointer().
   *
   * When handling crossing events, this property is updated
   * before signal_enter(), but after
   * signal_leave() is emitted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_contains_pointer() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::EventControllerMotion
   */
  GTKMM_API
  auto wrap(GtkEventControllerMotion* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerMotion>;
}


#endif /* _GTKMM_EVENTCONTROLLERMOTION_H */

