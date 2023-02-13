
#ifndef _GTKMM_CHECKBUTTON_H
#define _GTKMM_CHECKBUTTON_H


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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/actionable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCheckButton = struct _GtkCheckButton;
using GtkCheckButtonClass = struct _GtkCheckButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CheckButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Create widgets with a discrete toggle button.
 *
 * A %Gtk::CheckButton places a label next to an indicator.
 *
 * The CheckButton widget looks like this:
 * @image html checkbutton1.png
 *
 * @see Button, ToggleButton
 * @ingroup Widgets
 */

class GTKMM_API CheckButton : public Widget, public Actionable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CheckButton CppObjectType;
  typedef CheckButton_Class CppClassType;
  typedef GtkCheckButton BaseObjectType;
  typedef GtkCheckButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CheckButton(CheckButton&& src) noexcept;
  auto operator=(CheckButton&& src) noexcept -> CheckButton&;

  // noncopyable
  CheckButton(const CheckButton&) = delete;
  auto operator=(const CheckButton&) -> CheckButton& = delete;

  ~CheckButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CheckButton_Class;
  static CppClassType checkbutton_class_;

protected:
  explicit CheckButton(const Glib::ConstructParams& construct_params);
  explicit CheckButton(GtkCheckButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCheckButton*       { return reinterpret_cast<GtkCheckButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCheckButton* { return reinterpret_cast<GtkCheckButton*>(gobject_); }

private:


public:

  /** Create an empty check button.
   *
   * If you wish to add a Gtk::Label, you may want to use the
   * Gtk::CheckButton(const Glib::ustring& label, bool mnemonic)
   * constructor directly instead.
   */
  CheckButton();

  /** Create a check button with a label.
   */
  explicit CheckButton(const Glib::ustring& label, bool mnemonic = false);


  /** Sets the `Gtk::CheckButton` to inconsistent state.
   *
   * You shoud turn off the inconsistent state again if the user checks
   * the check button. This has to be done manually.
   *
   * @param inconsistent <tt>true</tt> if state is inconsistent.
   */
  void set_inconsistent(bool inconsistent =  true);

  /** Returns whether the check button is in an inconsistent state.
   *
   * @return <tt>true</tt> if @a check_button is currently in an inconsistent state.
   */
  auto get_inconsistent() const -> bool;

  /** Changes the check buttons active state.
   *
   * @param setting The new value to set.
   */
  void set_active(bool setting =  true);

  /** Returns whether the check button is active.
   *
   * @return Whether the check button is active.
   */
  auto get_active() const -> bool;

  /** Sets the text of @a self.
   *
   * If property_use_underline() is <tt>true</tt>, an underscore
   * in @a label is interpreted as mnemonic indicator, see
   * set_use_underline() for details on this behavior.
   *
   * @param label The text shown next to the indicator, or <tt>nullptr</tt>
   * to show no text.
   */
  void set_label(const Glib::ustring& label);

  /** Returns the label of the check button or <tt>nullptr</tt> if property_child() is set.
   *
   * @return The label @a self shows next
   * to the indicator. If no label is shown, <tt>nullptr</tt> will be returned.
   */
  auto get_label() const -> Glib::ustring;

  /** Sets whether underlines in the label indicate mnemonics.
   *
   * If @a setting is <tt>true</tt>, an underscore character in @a self's label
   * indicates a mnemonic accelerator key. This behavior is similar
   * to Gtk::Label::property_use_underline().
   *
   * @param setting The new value to set.
   */
  void set_use_underline(bool setting =  true);

  /** Returns whether underlines in the label indicate mnemonics.
   *
   * @return The value of the property_use_underline() property.
   * See set_use_underline() for details on how to set
   * a new value.
   */
  auto get_use_underline() const -> bool;


  /** Sets the child widget of @a button.
   *
   * Note that by using this API, you take full responsibility for setting
   * up the proper accessibility label and description information for @a button.
   * Most likely, you'll either set the accessibility label or description
   * for @a button explicitly, or you'll set a labelled-by or described-by
   * relations from @a child to @a button.
   *
   * @newin{4,8}
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a button or <tt>nullptr</tt> if property_label() is set.
   *
   * @newin{4,8}
   *
   * @return The child widget of @a button.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a button or <tt>nullptr</tt> if property_label() is set.
   *
   * @newin{4,8}
   *
   * @return The child widget of @a button.
   */
  auto get_child() const -> const Widget*;


  /** Adds @a self to the group of @a group.
   *
   * In a group of multiple check buttons, only one button can be active
   * at a time. The behavior of a checkbutton in a group is also commonly
   * known as a *radio button*.
   *
   * Setting the group of a check button also changes the css name of the
   * indicator widget's CSS node to 'radio'.
   *
   * Setting up groups in a cycle leads to undefined behavior.
   *
   * Note that the same effect can be achieved via the Gtk::Actionable
   * API, by using the same action with parameter type and state type 's'
   * for all buttons in the group, and giving each button its own target
   * value.
   *
   * @param group Another `Gtk::CheckButton` to
   * form a group with.
   */
  void set_group(CheckButton& group);
  void unset_group();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%toggled()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the buttons's property_active()
   * property changes.
   */

  auto signal_toggled() -> Glib::SignalProxy<void()>;


  /** If the check button is active.
   *
   * Setting `active` to <tt>true</tt> will add the `:checked:` state to both
   * the check button and the indicator CSS node.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() -> Glib::PropertyProxy< bool > ;

/** If the check button is active.
   *
   * Setting `active` to <tt>true</tt> will add the `:checked:` state to both
   * the check button and the indicator CSS node.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The check button whose group this widget belongs to.
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_group() -> Glib::PropertyProxy_WriteOnly< CheckButton* > ;


  /** Text of the label inside the check button, if it contains a label widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** Text of the label inside the check button, if it contains a label widget.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** If the check button is in an “in between” state.
   *
   * The inconsistent state only affects visual appearance,
   * not the semantics of the button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inconsistent() -> Glib::PropertyProxy< bool > ;

/** If the check button is in an “in between” state.
   *
   * The inconsistent state only affects visual appearance,
   * not the semantics of the button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inconsistent() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If set, an underline in the text indicates that the following
   * character is to be used as mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() -> Glib::PropertyProxy< bool > ;

/** If set, an underline in the text indicates that the following
   * character is to be used as mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The child widget.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @newin{4,8}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


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
   * @relates Gtk::CheckButton
   */
  GTKMM_API
  auto wrap(GtkCheckButton* object, bool take_copy = false) -> Gtk::CheckButton*;
} //namespace Glib


#endif /* _GTKMM_CHECKBUTTON_H */
