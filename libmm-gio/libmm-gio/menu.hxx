
#ifndef _GIOMM_MENU_H
#define _GIOMM_MENU_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gio/menumodel.hxx>
#include <libmm-gio/menuitem.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenu = struct _GMenu;
using GMenuClass = struct _GMenuClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Menu_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A simple implementation of MenuModel.
 * You populate a Menu by adding MenuItem instances to it.
 *
 * There are some convenience methods to allow you to directly
 * add items (avoiding MenuItem) for the common cases. To add
 * a regular item, use insert(). To add a section, use
 * insert_section(). To add a submenu, use
 * insert_submenu().
 *
 * @newin{2,32}
 */

class GIOMM_API Menu : public Gio::MenuModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Menu;
  using CppClassType = Menu_Class;
  using BaseObjectType = GMenu;
  using BaseClassType = GMenuClass;

  // noncopyable
  Menu(const Menu&) = delete;
  auto operator=(const Menu&) -> Menu& = delete;

private:  friend class Menu_Class;
  static CppClassType menu_class_;

protected:
  explicit Menu(const Glib::ConstructParams& construct_params);
  explicit Menu(GMenu* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Menu(Menu&& src) noexcept;
  auto operator=(Menu&& src) noexcept -> Menu&;

  ~Menu() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMenu*       { return reinterpret_cast<GMenu*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMenu* { return reinterpret_cast<GMenu*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GMenu*;

private:


protected:
  Menu();


public:

  static auto create() -> Glib::RefPtr<Menu>;


  /** Marks @a menu as frozen.
   *
   * After the menu is frozen, it is an error to attempt to make any
   * changes to it.  In effect this means that the Menu API must no
   * longer be used.
   *
   * This function causes g_menu_model_is_mutable() to begin returning
   * <tt>false</tt>, which has some positive performance implications.
   *
   * @newin{2,32}
   */
  void freeze();


  /** Inserts @a item into @a menu.
   *
   * The "insertion" is actually done by copying all of the attribute and
   * link values of @a item and using them to form a new item within @a menu.
   * As such, @a item itself is not really inserted, but rather, a menu item
   * that is exactly the same as the one presently described by @a item.
   *
   * This means that @a item is essentially useless after the insertion
   * occurs.  Any changes you make to it are ignored unless it is inserted
   * again (at which point its updated values will be copied).
   *
   * You should probably just free @a item once you're done.
   *
   * There are many convenience functions to take care of common cases.
   * See g_menu_insert(), g_menu_insert_section() and
   * g_menu_insert_submenu() as well as "prepend" and "append" variants of
   * each of these functions.
   *
   * @newin{2,32}
   *
   * @param position The position at which to insert the item.
   * @param item The MenuItem to insert.
   */
  void insert_item(int position, const Glib::RefPtr<const MenuItem>& item);

  /** Prepends @a item to the start of @a menu.
   *
   * See g_menu_insert_item() for more information.
   *
   * @newin{2,32}
   *
   * @param item A MenuItem to prepend.
   */
  void prepend_item(const Glib::RefPtr<const MenuItem>& item);

  /** Appends @a item to the end of @a menu.
   *
   * See g_menu_insert_item() for more information.
   *
   * @newin{2,32}
   *
   * @param item A MenuItem to append.
   */
  void append_item(const Glib::RefPtr<const MenuItem>& item);

  /** Removes an item from the menu.
   *
   *  @a position gives the index of the item to remove.
   *
   * It is an error if position is not in range the range from 0 to one
   * less than the number of items in the menu.
   *
   * It is not possible to remove items by identity since items are added
   * to the menu simply by copying their links and attributes (ie:
   * identity of the item itself is not preserved).
   *
   * @newin{2,32}
   *
   * @param position The position of the item to remove.
   */
  void remove(int position);

  /** Removes all items in the menu.
   *
   * @newin{2,38}
   */
  void remove_all();

// The glib docs says that label can be null in all insert/prepend/append functions.
// But except in the xxx_section() functions, a null label results in a critical message,
// and does not seem useful. See https://bugzilla.gnome.org/show_bug.cgi?id=733203
//We don't return the MenuItem* because the C API can't give us something modifiable: See https://bugzilla.gnome.org/show_bug.cgi?id=708906

  /** Convenience function for inserting a normal menu item into @a menu.
   * Combine g_menu_item_new() and g_menu_insert_item() for a more flexible
   * alternative.
   *
   * @newin{2,32}
   *
   * @param position The position at which to insert the item.
   * @param label The section label, or <tt>nullptr</tt>.
   * @param detailed_action The detailed action string, or <tt>nullptr</tt>.
   */
  void insert(int position, const Glib::ustring& label, const Glib::ustring& detailed_action);

  /// A insert() convenience overload.
  void insert(int position, const Glib::ustring& label);

  /** Convenience function for prepending a normal menu item to the start
   * of @a menu.  Combine g_menu_item_new() and g_menu_insert_item() for a more
   * flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param detailed_action The detailed action string, or <tt>nullptr</tt>.
   */
  void prepend(const Glib::ustring& label, const Glib::ustring& detailed_action);

  /// A prepend() convenience overload.
  void prepend(const Glib::ustring& label);

  /** Convenience function for appending a normal menu item to the end of
   *  @a menu.  Combine g_menu_item_new() and g_menu_insert_item() for a more
   * flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param detailed_action The detailed action string, or <tt>nullptr</tt>.
   */
  void append(const Glib::ustring& label, const Glib::ustring& detailed_action);

  /// A append() convenience overload.
  void append(const Glib::ustring& label);

// TODO: Should the MenuModel be const too?

  /** Convenience function for inserting a section menu item into @a menu.
   * Combine g_menu_item_new_section() and g_menu_insert_item() for a more
   * flexible alternative.
   *
   * @newin{2,32}
   *
   * @param position The position at which to insert the item.
   * @param label The section label, or <tt>nullptr</tt>.
   * @param section A MenuModel with the items of the section.
   */
  void insert_section(int position, const Glib::ustring& label, const Glib::RefPtr<MenuModel>& section);

  /// A insert_section() convenience overload.
  void insert_section(int position, const Glib::RefPtr<MenuModel>& section);

  /** Convenience function for prepending a section menu item to the start
   * of @a menu.  Combine g_menu_item_new_section() and g_menu_insert_item() for
   * a more flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param section A MenuModel with the items of the section.
   */
  void prepend_section(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& section);

  /// A prepend_section() convenience overload.
  void prepend_section(const Glib::RefPtr<MenuModel>& section);

  /** Convenience function for appending a section menu item to the end of
   *  @a menu.  Combine g_menu_item_new_section() and g_menu_insert_item() for a
   * more flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param section A MenuModel with the items of the section.
   */
  void append_section(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& section);

  /// A append_section() convenience overload.
  void append_section(const Glib::RefPtr<MenuModel>& section);


  /** Convenience function for inserting a submenu menu item into @a menu.
   * Combine g_menu_item_new_submenu() and g_menu_insert_item() for a more
   * flexible alternative.
   *
   * @newin{2,32}
   *
   * @param position The position at which to insert the item.
   * @param label The section label, or <tt>nullptr</tt>.
   * @param submenu A MenuModel with the items of the submenu.
   */
  void insert_submenu(int position, const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu);

  /** Convenience function for prepending a submenu menu item to the start
   * of @a menu.  Combine g_menu_item_new_submenu() and g_menu_insert_item() for
   * a more flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param submenu A MenuModel with the items of the submenu.
   */
  void prepend_submenu(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu);

  /** Convenience function for appending a submenu menu item to the end of
   *  @a menu.  Combine g_menu_item_new_submenu() and g_menu_insert_item() for a
   * more flexible alternative.
   *
   * @newin{2,32}
   *
   * @param label The section label, or <tt>nullptr</tt>.
   * @param submenu A MenuModel with the items of the submenu.
   */
  void append_submenu(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Menu
   */
  GIOMM_API
  auto wrap(GMenu* object, bool take_copy = false) -> Glib::RefPtr<Gio::Menu>;
}


#endif /* _GIOMM_MENU_H */

