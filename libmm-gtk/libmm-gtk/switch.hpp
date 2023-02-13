
#ifndef _GTKMM_SWITCH_H
#define _GTKMM_SWITCH_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/actionable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSwitch = struct _GtkSwitch;
using GtkSwitchClass = struct _GtkSwitchClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Switch_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A "light switch"-style toggle.
 *
 * The Switch widget has two states: on or off. The user can control
 * which state should be active by clicking the empty area, or by dragging the
 * handle.
 *
 * @ingroup Widgets
 * @newin{3,0}
 */

class GTKMM_API Switch
  : public Widget,
    public Actionable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Switch CppObjectType;
  typedef Switch_Class CppClassType;
  typedef GtkSwitch BaseObjectType;
  typedef GtkSwitchClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Switch(Switch&& src) noexcept;
  auto operator=(Switch&& src) noexcept -> Switch&;

  // noncopyable
  Switch(const Switch&) = delete;
  auto operator=(const Switch&) -> Switch& = delete;

  ~Switch() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Switch_Class;
  static CppClassType switch_class_;

protected:
  explicit Switch(const Glib::ConstructParams& construct_params);
  explicit Switch(GtkSwitch* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkSwitch*       { return reinterpret_cast<GtkSwitch*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSwitch* { return reinterpret_cast<GtkSwitch*>(gobject_); }

private:


public:

  Switch();


  /** Changes the state of @a self to the desired one.
   *
   * @param is_active <tt>true</tt> if @a self should be active, and <tt>false</tt> otherwise.
   */
  void set_active(bool is_active =  true);

  /** Gets whether the `Gtk::Switch` is in its “on” or “off” state.
   *
   * @return <tt>true</tt> if the `Gtk::Switch` is active, and <tt>false</tt> otherwise.
   */
  auto get_active() const -> bool;


  /** Sets the underlying state of the `Gtk::Switch`.
   *
   * Normally, this is the same as property_active(), unless
   * the switch is set up for delayed state changes. This function is
   * typically called from a signal_state_set() signal handler.
   *
   * See signal_state_set() for details.
   *
   * @param state The new state.
   */
  void set_state(bool state =  true);

  /** Gets the underlying state of the `Gtk::Switch`.
   *
   * @return The underlying state.
   */
  auto get_state() const -> bool;

  /** Whether the `Gtk::Switch` widget is in its on or off state.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() -> Glib::PropertyProxy< bool > ;

/** Whether the `Gtk::Switch` widget is in its on or off state.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The backend state that is controlled by the switch.
   *
   * See Gtk::GtkSwitch::signal_state_set() for details.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state() -> Glib::PropertyProxy< bool > ;

/** The backend state that is controlled by the switch.
   *
   * See Gtk::GtkSwitch::signal_state_set() for details.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_state() const -> Glib::PropertyProxy_ReadOnly< bool >;


  //activate is an action signal that's documented as not for use by applications.


  // no_default_handler because GtkSwitchClass is private.

  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%state_set(bool state)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to change the underlying state.
   *
   * The signal_state_set() signal is emitted when the user changes the switch
   * position. The default handler keeps the state in sync with the
   * property_active() property.
   *
   * To implement delayed state change, applications can connect to this
   * signal, initiate the change of the underlying state, and call
   * Gtk::Switch::set_state() when the underlying state change is
   * complete. The signal handler should return <tt>true</tt> to prevent the
   * default handler from running.
   *
   * Visually, the underlying state is represented by the trough color of
   * the switch, while the property_active() property is
   * represented by the position of the switch.
   *
   * @param state The new state of the switch.
   * @return <tt>true</tt> to stop the signal emission.
   */

  auto signal_state_set() -> Glib::SignalProxy<bool(bool)>;


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
   * @relates Gtk::Switch
   */
  GTKMM_API
  auto wrap(GtkSwitch* object, bool take_copy = false) -> Gtk::Switch*;
} //namespace Glib


#endif /* _GTKMM_SWITCH_H */

