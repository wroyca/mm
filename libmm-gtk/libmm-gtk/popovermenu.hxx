
#ifndef _GTKMM_POPOVERMENU_H
#define _GTKMM_POPOVERMENU_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The gtkmm Development Team
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

#include <libmm-gtk/popover.hxx>
#include <libmm-gio/menumodel.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPopoverMenu = struct _GtkPopoverMenu;
using GtkPopoverMenuClass = struct _GtkPopoverMenuClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API PopoverMenu_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** @defgroup Menus Menu classes
 * @see Gio::Menu, Gio::MenuItem, Gio::MenuModel, Gio::SimpleActionGroup
 */

/** A Popover to use as a menu.
 *
 * %PopoverMenu is a subclass of Popover that treats its
 * children like menus and allows switching between them. It
 * can open submenus as traditional, nested submenus, or in a
 * more touch-friendly sliding fashion.
 *
 * %PopoverMenu is meant to be used primarily with menu models,
 * using one of the constructors or set_menu_model(). If you need to put
 * other widgets such as SpinButton or Switch into a popover, use a Popover.
 *
 * In addition to all the regular menu model features, this function
 * supports rendering sections in the model in a more compact form,
 * as a row of image buttons instead of menu items.
 * To use this rendering, set the ”display-hint” attribute of the
 * section to ”horizontal-buttons” and set the icons of your items
 * with the ”verb-icon” attribute.
 *
 * @newin{3,18}
 *
 * @ingroup Widgets
 * @ingroup Containers
 * @ingroup Menus
 */

class GTKMM_API PopoverMenu : public Popover
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef PopoverMenu CppObjectType;
  typedef PopoverMenu_Class CppClassType;
  typedef GtkPopoverMenu BaseObjectType;
  typedef GtkPopoverMenuClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  PopoverMenu(PopoverMenu&& src) noexcept;
  auto operator=(PopoverMenu&& src) noexcept -> PopoverMenu&;

  // noncopyable
  PopoverMenu(const PopoverMenu&) = delete;
  auto operator=(const PopoverMenu&) -> PopoverMenu& = delete;

  ~PopoverMenu() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class PopoverMenu_Class;
  static CppClassType popovermenu_class_;

protected:
  explicit PopoverMenu(const Glib::ConstructParams& construct_params);
  explicit PopoverMenu(GtkPopoverMenu* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkPopoverMenu*       { return reinterpret_cast<GtkPopoverMenu*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPopoverMenu* { return reinterpret_cast<GtkPopoverMenu*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Flags NESTED
   * Create submenus as nested
   * popovers. Without this flag, submenus are created as
   * sliding pages that replace the main menu.
   *
   *  @enum Flags
   *
   * Flags that affect how popover menus are created from
   * a menu model.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>PopoverMenu::Flags operator|(PopoverMenu::Flags, PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags operator&(PopoverMenu::Flags, PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags operator^(PopoverMenu::Flags, PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags operator~(PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags& operator|=(PopoverMenu::Flags&, PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags& operator&=(PopoverMenu::Flags&, PopoverMenu::Flags)</tt><br>
   * <tt>PopoverMenu::Flags& operator^=(PopoverMenu::Flags&, PopoverMenu::Flags)</tt><br>
   */
  enum class Flags
  {
    NESTED = 1 << 0
  };


  //This is custom-implemented because the gtk_popover_menu_new_from_model() does more
  //than just call g_object_new().
  //See https://bugzilla.gnome.org/show_bug.cgi?id=704671
  /** Creates a %PopoverMenu and populates it according to @a model.
   *
   * The created buttons are connected to actions found in the
   * ApplicationWindow to which the popover menu belongs - typically
   * by means of being attached to a widget that is contained within
   * the ApplicationWindow widget hierarchy.
   *
   * Actions can also be added using Widget::insert_action_group()
   * on the menu's attached widget or on any of its parent widgets.
   *
   * The only flag that is supported currently is
   * Gtk::PopoverMenu::Flags::NESTED, which makes GTK create traditional,
   * nested submenus instead of the default sliding submenus.
   *
   * @param model A Gio::MenuModel or an empty Glib::RefPtr
   * @param flags Flags that affect how the menu is created
   */
  explicit PopoverMenu(const Glib::RefPtr<Gio::MenuModel>& model = {},
    Flags flags = static_cast<Flags>(0));


  /** Sets a new menu model on @a popover.
   *
   * The existing contents of @a popover are removed, and
   * the @a popover is populated with new contents according
   * to @a model.
   *
   * @param model A `Gio::MenuModel`.
   */
  void set_menu_model(const Glib::RefPtr<Gio::MenuModel>& model);

  /** Returns the menu model used to populate the popover.
   *
   * @return The menu model of @a popover.
   */
  auto get_menu_model() -> Glib::RefPtr<Gio::MenuModel>;

  /** Returns the menu model used to populate the popover.
   *
   * @return The menu model of @a popover.
   */
  auto get_menu_model() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Adds a custom widget to a generated menu.
   *
   * For this to work, the menu model of @a popover must have
   * an item with a `custom` attribute that matches @a id.
   *
   * @param child The `Gtk::Widget` to add.
   * @param id The ID to insert @a child at.
   * @return <tt>true</tt> if @a id was found and the widget added.
   */
  auto add_child(Widget& child, const Glib::ustring& id) -> bool;

  /** Removes a widget that has previously been added with
   * add_child().
   *
   * @param child The `Gtk::Widget` to remove.
   * @return <tt>true</tt> if the widget was removed.
   */
  auto remove_child(Widget& child) -> bool;

  /** The name of the visible submenu.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible_submenu() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the visible submenu.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible_submenu() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The model from which the menu is made.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** The model from which the menu is made.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menu_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;


  // PopoverMenu has no signals nor vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  { return static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  { return static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  { return static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(PopoverMenu::Flags flags) -> PopoverMenu::Flags
  { return static_cast<PopoverMenu::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  { return (lhs = static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  { return (lhs = static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  { return (lhs = static_cast<PopoverMenu::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PopoverMenu::Flags> : public Glib::Value_Flags<Gtk::PopoverMenu::Flags>
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
   * @relates Gtk::PopoverMenu
   */
  GTKMM_API
  auto wrap(GtkPopoverMenu* object, bool take_copy = false) -> Gtk::PopoverMenu*;
} //namespace Glib


#endif /* _GTKMM_POPOVERMENU_H */

