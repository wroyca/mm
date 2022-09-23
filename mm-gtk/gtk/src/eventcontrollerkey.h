// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_EVENTCONTROLLERKEY_H
#define _GTKMM_EVENTCONTROLLERKEY_H


#include <glibmm/ustring.h>
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

#include <gtkmm/eventcontroller.h>
#include <gdkmm/enums.h>


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
  EventControllerKey& operator=(const EventControllerKey&) = delete;

private:  friend class EventControllerKey_Class;
  static CppClassType eventcontrollerkey_class_;

protected:
  explicit EventControllerKey(const Glib::ConstructParams& construct_params);
  explicit EventControllerKey(GtkEventControllerKey* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  EventControllerKey(EventControllerKey&& src) noexcept;
  EventControllerKey& operator=(EventControllerKey&& src) noexcept;

  ~EventControllerKey() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkEventControllerKey*       gobj()       { return reinterpret_cast<GtkEventControllerKey*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkEventControllerKey* gobj() const { return reinterpret_cast<GtkEventControllerKey*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkEventControllerKey* gobj_copy();

private:


protected:
  EventControllerKey();

public:
  
  static Glib::RefPtr<EventControllerKey> create();


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
  bool forward(Widget& widget);
  
  /** Gets the key group of the current event of this @a controller.
   * 
   * See Gdk::KeyEvent::get_layout().
   * 
   * @return The key group.
   */
  guint get_group() const;

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

  Glib::SignalProxy<bool(guint, guint, Gdk::ModifierType)> signal_key_pressed();

  
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

  Glib::SignalProxy<void(guint, guint, Gdk::ModifierType)> signal_key_released();

  
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

  Glib::SignalProxy<bool(Gdk::ModifierType)> signal_modifiers();

  
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

  Glib::SignalProxy<void()> signal_im_update();


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
  Glib::RefPtr<Gtk::EventControllerKey> wrap(GtkEventControllerKey* object, bool take_copy = false);
}


#endif /* _GTKMM_EVENTCONTROLLERKEY_H */

