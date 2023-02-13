
#ifndef _GTKMM_MENUBUTTON_H
#define _GTKMM_MENUBUTTON_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/popover.hpp>
#include <mm/gio/menumodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMenuButton = struct _GtkMenuButton;
using GtkMenuButtonClass = struct _GtkMenuButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MenuButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget that shows a menu when clicked on.
 *
 * This menu can be provided either as a Gtk::Menu, a Gtk::Popover or an
 * abstract Gio::MenuModel.
 *
 * The %Gtk::MenuButton widget can show either an icon (set with set_icon_name())
 * or a label (set with set_label()). If neither is explicitly set,
 * a Gtk::Image is automatically created, using an arrow image oriented according
 * to set_direction() or the generic “open-menu-symbolic” icon if the direction
 * is not set.
 *
 * @ingroup Widgets
 * @newin{3,6}
 */

class GTKMM_API MenuButton : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MenuButton CppObjectType;
  typedef MenuButton_Class CppClassType;
  typedef GtkMenuButton BaseObjectType;
  typedef GtkMenuButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  MenuButton(MenuButton&& src) noexcept;
  auto operator=(MenuButton&& src) noexcept -> MenuButton&;

  // noncopyable
  MenuButton(const MenuButton&) = delete;
  auto operator=(const MenuButton&) -> MenuButton& = delete;

  ~MenuButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class MenuButton_Class;
  static CppClassType menubutton_class_;

protected:
  explicit MenuButton(const Glib::ConstructParams& construct_params);
  explicit MenuButton(GtkMenuButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkMenuButton*       { return reinterpret_cast<GtkMenuButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMenuButton* { return reinterpret_cast<GtkMenuButton*>(gobject_); }

private:

public:

  MenuButton();


  /** Sets the `Gtk::Popover` that will be popped up when the @a menu_button is clicked.
   *
   * If @a popover is <tt>nullptr</tt>, the button is disabled.
   *
   * If property_menu_model() is set, the menu model is dissociated
   * from the @a menu_button, and the property is set to <tt>nullptr</tt>.
   *
   * @param popover A `Gtk::Popover`, or <tt>nullptr</tt> to unset and disable the button.
   */
  void set_popover(Popover& popover);

  /** Disables the button.
   */
  void unset_popover();


  /** Returns the `Gtk::Popover` that pops out of the button.
   *
   * If the button is not using a `Gtk::Popover`, this function
   * returns <tt>nullptr</tt>.
   *
   * @return A `Gtk::Popover` or <tt>nullptr</tt>.
   */
  auto get_popover() -> Popover*;

  /** Returns the `Gtk::Popover` that pops out of the button.
   *
   * If the button is not using a `Gtk::Popover`, this function
   * returns <tt>nullptr</tt>.
   *
   * @return A `Gtk::Popover` or <tt>nullptr</tt>.
   */
  auto get_popover() const -> const Popover*;


  /** Sets the direction in which the popup will be popped up.
   *
   * If the button is automatically populated with an arrow icon,
   * its direction will be changed to match.
   *
   * If the does not fit in the available space in the given direction,
   * GTK will its best to keep it inside the screen and fully visible.
   *
   * If you pass Gtk::ArrowType::NONE for a @a direction, the popup will behave
   * as if you passed Gtk::ArrowType::DOWN (although you won’t see any arrows).
   *
   * @param direction A `Gtk::ArrowType`.
   */
  void set_direction(ArrowType direction);

  /** Returns the direction the popup will be pointing at when popped up.
   *
   * @return A `Gtk::ArrowType` value.
   */
  auto get_direction() const -> ArrowType;


  /** Sets the `Gio::MenuModel` from which the popup will be constructed.
   *
   * If @a menu_model is <tt>nullptr</tt>, the button is disabled.
   *
   * A Gtk::Popover will be created from the menu model with
   * Gtk::PopoverMenu::new_from_model(). Actions will be connected
   * as documented for this function.
   *
   * If property_popover() is already set, it will be
   * dissociated from the @a menu_button, and the property is set to <tt>nullptr</tt>.
   *
   * @param menu_model A `Gio::MenuModel`, or <tt>nullptr</tt> to unset and disable the
   * button.
   */
  void set_menu_model(const Glib::RefPtr<const Gio::MenuModel>& menu_model);

  /** Disables the button.
   */
  void unset_menu_model();


  /** Returns the `Gio::MenuModel` used to generate the popup.
   *
   * @return A `Gio::MenuModel`.
   */
  auto get_menu_model() -> Glib::RefPtr<Gio::MenuModel>;

  /** Returns the `Gio::MenuModel` used to generate the popup.
   *
   * @return A `Gio::MenuModel`.
   */
  auto get_menu_model() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Sets the name of an icon to show inside the menu button.
   *
   * Setting icon name resets property_label() and
   * property_child().
   *
   * If property_always_show_arrow() is set to <tt>true</tt> and
   * property_direction() is not `Gtk::ArrowType::NONE`, a dropdown arrow
   * will be shown next to the icon.
   *
   * @param icon_name The icon name.
   */
  void set_icon_name(const Glib::ustring& icon_name);

  /** Gets the name of the icon shown in the button.
   *
   * @return The name of the icon shown in the button.
   */
  auto get_icon_name() const -> Glib::ustring;


  /** Sets whether to show a dropdown arrow even when using an icon or a custom
   * child.
   *
   * @newin{4,4}
   *
   * @param always_show_arrow Hether to show a dropdown arrow even when using an icon.
   */
  void set_always_show_arrow(bool always_show_arrow =  true);

  /** Gets whether to show a dropdown arrow even when using an icon.
   *
   * @newin{4,4}
   *
   * @return Whether to show a dropdown arrow even when using an icon.
   */
  auto get_always_show_arrow() const -> bool;


  /** Sets the label to show inside the menu button.
   *
   * Setting a label resets property_icon_name() and
   * property_child().
   *
   * If property_direction() is not `Gtk::ArrowType::NONE`, a dropdown
   * arrow will be shown next to the label.
   *
   * @param label The label.
   */
  void set_label(const Glib::ustring& label);

  /** Gets the label shown in the button
   *
   * @return The label shown in the button.
   */
  auto get_label() const -> Glib::ustring;


  /** If true, an underline in the text indicates a mnemonic.
   *
   * @param use_underline <tt>true</tt> if underlines in the text indicate mnemonics.
   */
  void set_use_underline(bool use_underline =  true);

  /** Returns whether an embedded underline in the text indicates a
   * mnemonic.
   *
   * @return <tt>true</tt> whether an embedded underline in the text indicates
   * the mnemonic accelerator keys.
   */
  auto get_use_underline() const -> bool;


  /** Sets the style of the button.
   *
   * @param has_frame Whether the button should have a visible frame.
   */
  void set_has_frame(bool has_frame =  true);

  /** Returns whether the button has a frame.
   *
   * @return <tt>true</tt> if the button has a frame.
   */
  auto get_has_frame() const -> bool;


  /** Pop up the menu.
   */
  void popup();

  /** Dismiss the menu.
   */
  void popdown();

  /** Slot to create a popup for the %MenuButton on demand.
   *
   * This slot is called when the popoup of the %MenuButton is shown, but none has
   * been provided via set_popup(), set_popover() or set_menu_model().
   */
  using SlotCreatePopup = sigc::slot<void()>;

  /** Sets @a slot to be called when a popup is about to be shown.
   *
   *  @a slot should use one of
   *
   * - set_popup()
   * - set_popover()
   * - set_menu_model()
   *
   * to set a popup for the %MenuButton.
   * The %MenuButton will always be sensitive.
   *
   * Using this method will NOT reset the menu widget attached to the %MenuButton.
   * Instead, this can be done manually in @a slot.
   *
   * @param slot Slot to call when a popup is about to be shown, but none
   *             has been provided via other means.
   * @newin{3,96}
   */
  void set_create_popup_func(const SlotCreatePopup& slot);


  /** Undoes the effect of a previous call to set_create_popup_func().
   */
  void unset_create_popup_func();


  /** Sets whether menu button acts as a primary menu.
   *
   * Primary menus can be opened with the <kbd>F10</kbd> key.
   *
   * @newin{4,4}
   *
   * @param primary Whether the menubutton should act as a primary menu.
   */
  void set_primary(bool primary =  true);

  /** Returns whether the menu button acts as a primary menu.
   *
   * @newin{4,4}
   *
   * @return <tt>true</tt> if the button is a primary menu.
   */
  auto get_primary() const -> bool;


  /** Sets the child widget of @a menu_button.
   *
   * Setting a child resets property_label() and
   * property_icon_name().
   *
   * If property_always_show_arrow() is set to <tt>true</tt> and
   * property_direction() is not `Gtk::ArrowType::NONE`, a dropdown arrow
   * will be shown next to the child.
   *
   * @newin{4,6}
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);

  /** Removes the child widget.
   * @newin{4,6}
   */
  void unset_child();


  /** Gets the child widget of @a menu_button.
   *
   * @newin{4,6}
   *
   * @return The child widget of @a menu_button.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a menu_button.
   *
   * @newin{4,6}
   *
   * @return The child widget of @a menu_button.
   */
  auto get_child() const -> const Widget*;


  /** The `Gio::MenuModel` from which the popup will be created.
   *
   * See Gtk::MenuButton::set_menu_model() for the interaction
   * with the property_popover() property.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** The `Gio::MenuModel` from which the popup will be created.
   *
   * See Gtk::MenuButton::set_menu_model() for the interaction
   * with the property_popover() property.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;

  /** The `Gtk::ArrowType` representing the direction in which the
   * menu or popover will be popped out.
   *
   * Default value: Gtk::ArrowType::DOWN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() -> Glib::PropertyProxy< ArrowType > ;

/** The `Gtk::ArrowType` representing the direction in which the
   * menu or popover will be popped out.
   *
   * Default value: Gtk::ArrowType::DOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_direction() const -> Glib::PropertyProxy_ReadOnly< ArrowType >;

  /** The `Gtk::Popover` that will be popped up when the button is clicked.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_popover() -> Glib::PropertyProxy< Popover* > ;

/** The `Gtk::Popover` that will be popped up when the button is clicked.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_popover() const -> Glib::PropertyProxy_ReadOnly< Popover* >;

  /** The name of the icon used to automatically populate the button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the icon used to automatically populate the button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to show a dropdown arrow even when using an icon or a custom child.
   *
   * @newin{4,4}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_always_show_arrow() -> Glib::PropertyProxy< bool > ;

/** Whether to show a dropdown arrow even when using an icon or a custom child.
   *
   * @newin{4,4}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_always_show_arrow() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The label for the button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The label for the button.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** If set an underscore in the text indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() -> Glib::PropertyProxy< bool > ;

/** If set an underscore in the text indicates a mnemonic.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the button has a frame.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() -> Glib::PropertyProxy< bool > ;

/** Whether the button has a frame.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the menu button acts as a primary menu.
   *
   * Primary menus can be opened using the <kbd>F10</kbd> key
   *
   * @newin{4,4}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary() -> Glib::PropertyProxy< bool > ;

/** Whether the menu button acts as a primary menu.
   *
   * Primary menus can be opened using the <kbd>F10</kbd> key
   *
   * @newin{4,4}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_primary() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The child widget.
   *
   * @newin{4,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @newin{4,6}
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


};

} /* namespace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MenuButton
   */
  GTKMM_API
  auto wrap(GtkMenuButton* object, bool take_copy = false) -> Gtk::MenuButton*;
} //namespace Glib


#endif /* _GTKMM_MENUBUTTON_H */

