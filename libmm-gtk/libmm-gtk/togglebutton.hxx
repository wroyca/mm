
#ifndef _GTKMM_TOGGLEBUTTON_H
#define _GTKMM_TOGGLEBUTTON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/button.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkToggleButton = struct _GtkToggleButton;
using GtkToggleButtonClass = struct _GtkToggleButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ToggleButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Create buttons which retain their state.
 *
 * A %Gtk::ToggleButton is a Gtk::Button which will remain “pressed-in” when
 * clicked. Clicking again will cause the toggle button to return to its
 * normal state.
 *
 * The state of a %Gtk::ToggleButton can be set specifically using
 * set_active(), and retrieved using get_active().
 *
 * To simply switch the state of a toggle button, use gtk_toggle_button_toggled().
 *
 * @see Button, Checkbutton
 * @ingroup Widgets
 */

class GTKMM_API ToggleButton : public Button
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ToggleButton CppObjectType;
  typedef ToggleButton_Class CppClassType;
  typedef GtkToggleButton BaseObjectType;
  typedef GtkToggleButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ToggleButton(ToggleButton&& src) noexcept;
  auto operator=(ToggleButton&& src) noexcept -> ToggleButton&;

  // noncopyable
  ToggleButton(const ToggleButton&) = delete;
  auto operator=(const ToggleButton&) -> ToggleButton& = delete;

  ~ToggleButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ToggleButton_Class;
  static CppClassType togglebutton_class_;

protected:
  explicit ToggleButton(const Glib::ConstructParams& construct_params);
  explicit ToggleButton(GtkToggleButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkToggleButton*       { return reinterpret_cast<GtkToggleButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkToggleButton* { return reinterpret_cast<GtkToggleButton*>(gobject_); }

private:

public:

  /** Create an empty toggle button.
   * With an empty button, you can Gtk::Button::add() a widget such as a
   * Gtk::Image or Gtk::Box.
   *
   * If you just wish to add a Gtk::Label, you may want to use the
   * Gtk::ToggleButton(const Glib::ustring &label, bool mnemonic)
   * constructor directly instead.
   */
  ToggleButton();

  /** Create a toggle button with a label.
   * You won't be able to add a widget to this button since it
   * already contains a Gtk::Label.
   */
  explicit ToggleButton(const Glib::ustring& label, bool mnemonic = false);


  /** Sets the status of the toggle button.
   *
   * Set to <tt>true</tt> if you want the `Gtk::ToggleButton` to be “pressed in”,
   * and <tt>false</tt> to raise it.
   *
   * If the status of the button changes, this action causes the
   * Gtk::GtkToggleButton::signal_toggled() signal to be emitted.
   *
   * @param is_active <tt>true</tt> or <tt>false</tt>.
   */
  void set_active(bool is_active =  true);

  /** Queries a `Gtk::ToggleButton` and returns its current state.
   *
   * @return Whether the button is pressed.
   */
  auto get_active() const -> bool;


  /** Emits the signal_toggled() signal on the `Gtk::ToggleButton`.
   *
   * There is no good reason for an application ever to call this function.
   */
  void toggled();


  /** Adds @a self to the group of @a group.
   *
   * In a group of multiple toggle buttons, only one button can be active
   * at a time.
   *
   * Setting up groups in a cycle leads to undefined behavior.
   *
   * Note that the same effect can be achieved via the Gtk::Actionable
   * API, by using the same action with parameter type and state type 's'
   * for all buttons in the group, and giving each button its own target
   * value.
   *
   * @param group Another `Gtk::ToggleButton` to
   * form a group with.
   */
  void set_group(ToggleButton& group);
  void unset_group();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%toggled()</tt>
   *
   * Flags: Run First
   *
   * Emitted whenever the `Gtk::ToggleButton`'s state is changed.
   */

  auto signal_toggled() -> Glib::SignalProxy<void()>;


  /** If the toggle button should be pressed in.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() -> Glib::PropertyProxy< bool > ;

/** If the toggle button should be pressed in.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The toggle button whose group this widget belongs to.
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_group() -> Glib::PropertyProxy_WriteOnly< ToggleButton* > ;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_toggled().
  virtual void on_toggled();


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ToggleButton
   */
  GTKMM_API
  auto wrap(GtkToggleButton* object, bool take_copy = false) -> Gtk::ToggleButton*;
} //namespace Glib


#endif /* _GTKMM_TOGGLEBUTTON_H */

