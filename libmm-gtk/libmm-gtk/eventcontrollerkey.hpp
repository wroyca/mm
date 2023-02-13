
#ifndef _GTKMM_EVENTCONTROLLERKEY_H
#define _GTKMM_EVENTCONTROLLERKEY_H


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
#include <mm/gdk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerKey = struct _GtkEventControllerKey;
using GtkEventControllerKeyClass = struct _GtkEventControllerKeyClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EventControllerKey_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Event controller for key events.
 *
 * %Gtk::EventControllerKey is an event controller meant for situations
 * where you need access to key events.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 *
 * @newin{3,94}
 *
 * @ingroup Gestures
 */

class GTKMM_API EventControllerKey : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = EventControllerKey;
  using CppClassType = EventControllerKey_Class;
  using BaseObjectType = GtkEventControllerKey;
  using BaseClassType = GtkEventControllerKeyClass;

  // noncopyable
  EventControllerKey(const EventControllerKey&) = delete;
  auto operator=(const EventControllerKey&) -> EventControllerKey& = delete;

private:  friend class EventControllerKey_Class;
  static CppClassType eventcontrollerkey_class_;

protected:
  explicit EventControllerKey(const Glib::ConstructParams& construct_params);
  explicit EventControllerKey(GtkEventControllerKey* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerKey(EventControllerKey&& src) noexcept;
  auto operator=(EventControllerKey&& src) noexcept -> EventControllerKey&;

  ~EventControllerKey() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkEventControllerKey*       { return reinterpret_cast<GtkEventControllerKey*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEventControllerKey* { return reinterpret_cast<GtkEventControllerKey*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkEventControllerKey*;

private:


protected:
  EventControllerKey();

public:

  static auto create() -> Glib::RefPtr<EventControllerKey>;


  //TODO: GtkIMContext has not (yet) been wrapped in gtkmm.
  //_WRAP_METHOD(void set_im_context(const Glib::RefPtr<Gtk::IMContext>& im_context), gtk_event_controller_key_set_im_context)
  //_WRAP_METHOD(Glib::RefPtr<Gtk::IMContext> get_im_context(), gtk_event_controller_key_get_im_context, refreturn)
  //_WRAP_METHOD(Glib::RefPtr<const Gtk::IMContext> get_im_context(), gtk_event_controller_key_get_im_context, refreturn, constversion)


  /** Forwards the current event of this @a controller to a @a widget.
   *
   * This function can only be used in handlers for the
   * signal_key_pressed(),
   * signal_key_released()
   * or signal_modifiers() signals.
   *
   * @param widget A `Gtk::Widget`.
   * @return Whether the @a widget handled the event.
   */
  auto forward(Widget& widget) -> bool;

  /** Gets the key group of the current event of this @a controller.
   *
   * See Gdk::KeyEvent::get_layout().
   *
   * @return The key group.
   */
  auto get_group() const -> guint;

  // no_default_handler because GtkEventControllerKeyClass is private.

  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%key_pressed(guint keyval, guint keycode, Gdk::ModifierType state)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a key is pressed.
   *
   * @param keyval The pressed key.
   * @param keycode The raw code of the pressed key.
   * @param state The bitmask, representing the state of modifier keys and pointer buttons. See `Gdk::ModifierType`.
   * @return <tt>true</tt> if the key press was handled, <tt>false</tt> otherwise.
   */

  auto signal_key_pressed() -> Glib::SignalProxy<bool(guint, guint, Gdk::ModifierType)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%key_released(guint keyval, guint keycode, Gdk::ModifierType state)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a key is released.
   *
   * @param keyval The released key.
   * @param keycode The raw code of the released key.
   * @param state The bitmask, representing the state of modifier keys and pointer buttons. See `Gdk::ModifierType`.
   */

  auto signal_key_released() -> Glib::SignalProxy<void(guint, guint, Gdk::ModifierType)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%modifiers(Gdk::ModifierType state)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted whenever the state of modifier keys and pointer
   * buttons change.
   *
   * @param state The bitmask, representing the new state of modifier keys and
   * pointer buttons. See Gdk::ModifierType.
   */

  auto signal_modifiers() -> Glib::SignalProxy<bool(Gdk::ModifierType)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%im_update()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the input method context filters away
   * a keypress and prevents the @a controller receiving it.
   *
   * See Gtk::EventControllerKey::set_im_context() and
   * Gtk::IMContext::filter_keypress().
   */

  auto signal_im_update() -> Glib::SignalProxy<void()>;


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
   * @relates Gtk::EventControllerKey
   */
  GTKMM_API
  auto wrap(GtkEventControllerKey* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerKey>;
}


#endif /* _GTKMM_EVENTCONTROLLERKEY_H */

