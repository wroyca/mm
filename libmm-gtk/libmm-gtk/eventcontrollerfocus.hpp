
#ifndef _GTKMM_EVENTCONTROLLERFOCUS_H
#define _GTKMM_EVENTCONTROLLERFOCUS_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
#include <mm/gdk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerFocus = struct _GtkEventControllerFocus;
using GtkEventControllerFocusClass = struct _GtkEventControllerFocusClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EventControllerFocus_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Event controller for focus.
 *
 * %Gtk::EventControllerFocus is an event controller meant for situations
 * where you need to know where the focus is.
 *
 * @newin{3,98}
 *
 * @ingroup Gestures
 */

class GTKMM_API EventControllerFocus : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EventControllerFocus;
  using CppClassType = EventControllerFocus_Class;
  using BaseObjectType = GtkEventControllerFocus;
  using BaseClassType = GtkEventControllerFocusClass;

  // noncopyable
  EventControllerFocus(const EventControllerFocus&) = delete;
  auto operator=(const EventControllerFocus&) -> EventControllerFocus& = delete;

private:  friend class EventControllerFocus_Class;
  static CppClassType eventcontrollerfocus_class_;

protected:
  explicit EventControllerFocus(const Glib::ConstructParams& construct_params);
  explicit EventControllerFocus(GtkEventControllerFocus* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerFocus(EventControllerFocus&& src) noexcept;
  auto operator=(EventControllerFocus&& src) noexcept -> EventControllerFocus&;

  ~EventControllerFocus() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEventControllerFocus*       { return reinterpret_cast<GtkEventControllerFocus*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEventControllerFocus* { return reinterpret_cast<GtkEventControllerFocus*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEventControllerFocus*;

private:


protected:
  EventControllerFocus();

public:

  static auto create() -> Glib::RefPtr<EventControllerFocus>;


  /** Returns <tt>true</tt> if focus is within @a self or one of its children.
   *
   * @return <tt>true</tt> if focus is within @a self or one of its children.
   */
  auto contains_focus() const -> bool;

  /** Returns <tt>true</tt> if focus is within @a self, but not one of its children.
   *
   * @return <tt>true</tt> if focus is within @a self, but not one of its children.
   */
  auto is_focus() const -> bool;

  // no_default_handler because GtkEventControllerFocusClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%enter()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the focus enters into the widget or one
   * of its descendents.
   *
   * Note that this means you may not get an signal_enter() signal
   * even though the widget becomes the focus location, in
   * certain cases (such as when the focus moves from a descendent
   * of the widget to the widget itself). If you are interested
   * in these cases, you can monitor the
   * property_is_focus()
   * property for changes.
   */

  auto signal_enter() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%leave()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the focus leaves the widget hierarchy
   * that is rooted at the widget that the controller is attached to.
   *
   * Note that this means you may not get a signal_leave() signal
   * even though the focus moves away from the widget, in
   * certain cases (such as when the focus moves from the widget
   * to a descendent). If you are interested in these cases, you
   * can monitor the property_is_focus()
   * property for changes.
   */

  auto signal_leave() -> Glib::SignalProxy<void()>;


  /** <tt>true</tt> if focus is in the controllers widget itself,
   * as opposed to in a descendent widget.
   *
   * See also property_contains_focus().
   *
   * When handling focus events, this property is updated
   * before signal_enter() or
   * signal_leave() are emitted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** <tt>true</tt> if focus is contained in the controllers widget.
   *
   * See property_is_focus() for whether
   * the focus is in the widget itself or inside a descendent.
   *
   * When handling focus events, this property is updated
   * before signal_enter() or
   * signal_leave() are emitted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_contains_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::EventControllerFocus
   */
  GTKMM_API
  auto wrap(GtkEventControllerFocus* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerFocus>;
}


#endif /* _GTKMM_EVENTCONTROLLERFOCUS_H */

