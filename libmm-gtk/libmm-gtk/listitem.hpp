
#ifndef _GTKMM_LISTITEM_H
#define _GTKMM_LISTITEM_H


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

#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListItem = struct _GtkListItem;
using GtkListItemClass = struct _GtkListItemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListItem_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** %Object used to represent items of a list model.
 *
 * %Gtk::ListItem is the object that list-handling containers such
 * as Gtk::ListView use to represent items in a Gio::ListModel. They are
 * managed by the container and cannot be created by application code.
 *
 * %Gtk::ListItems need to be populated by application code. This is done by
 * calling set_child().
 *
 * %Gtk::ListItems exist in 2 stages:
 *
 * 1. The unbound stage where the listitem is not currently connected to
 *    an item in the list. In that case, the property_item() property is
 *    not set.
 *
 * 2. The bound stage where the listitem references an item from the list.
 *    The property_item() property is set.
 *
 * @see Gtk::ListView, Gio::ListModel
 * @newin{3,98}
 */

class GTKMM_API ListItem : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ListItem;
  using CppClassType = ListItem_Class;
  using BaseObjectType = GtkListItem;
  using BaseClassType = GtkListItemClass;

  // noncopyable
  ListItem(const ListItem&) = delete;
  auto operator=(const ListItem&) -> ListItem& = delete;

private:  friend class ListItem_Class;
  static CppClassType listitem_class_;

protected:
  explicit ListItem(const Glib::ConstructParams& construct_params);
  explicit ListItem(GtkListItem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ListItem(ListItem&& src) noexcept;
  auto operator=(ListItem&& src) noexcept -> ListItem&;

  ~ListItem() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkListItem*       { return reinterpret_cast<GtkListItem*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListItem* { return reinterpret_cast<GtkListItem*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkListItem*;

private:


public:
  // Don't use Glib::RefPtr<Glib::Object> Glib::wrap(GObject* object, bool take_copy).
  // The object may be an interface object, e.g. Gio::AppInfo. Such an object can't be
  // cast to Glib::Object. https://gitlab.gnome.org/GNOME/glibmm/-/issues/93


  /** Gets the model item that associated with @a self.
   *
   * If @a self is unbound, this function returns <tt>nullptr</tt>.
   *
   * @return The item displayed.
   */
  auto get_item() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Gets the model item that associated with @a self.
   *
   * If @a self is unbound, this function returns <tt>nullptr</tt>.
   *
   * @return The item displayed.
   */
  auto get_item() const -> Glib::RefPtr<const Glib::ObjectBase>;

  /** Gets the position in the model that @a self currently displays.
   *
   * If @a self is unbound, GTK_INVALID_LIST_POSITION is returned.
   *
   * @return The position of this item.
   */
  auto get_position() const -> guint;

  /** Checks if the item is displayed as selected.
   *
   * The selected state is maintained by the liste widget and its model
   * and cannot be set otherwise.
   *
   * @return <tt>true</tt> if the item is selected.
   */
  auto get_selected() const -> bool;

  /** Checks if a list item has been set to be selectable via
   * set_selectable().
   *
   * Do not confuse this function with get_selected().
   *
   * @return <tt>true</tt> if the item is selectable.
   */
  auto get_selectable() const -> bool;

  /** Sets @a self to be selectable.
   *
   * If an item is selectable, clicking on the item or using the keyboard
   * will try to select or unselect the item. If this succeeds is up to
   * the model to determine, as it is managing the selected state.
   *
   * Note that this means that making an item non-selectable has no
   * influence on the selected state at all. A non-selectable item
   * may still be selected.
   *
   * By default, list items are selectable. When rebinding them to
   * a new item, they will also be reset to be selectable by GTK.
   *
   * @param selectable If the item should be selectable.
   */
  void set_selectable(bool selectable =  true);

  /** Checks if a list item has been set to be activatable via
   * set_activatable().
   *
   * @return <tt>true</tt> if the item is activatable.
   */
  auto get_activatable() const -> bool;

  /** Sets @a self to be activatable.
   *
   * If an item is activatable, double-clicking on the item, using
   * the Return key or calling Gtk::Widget::activate() will activate
   * the item. Activating instructs the containing view to handle
   * activation. `Gtk::ListView` for example will be emitting the
   * Gtk::ListView::signal_activate() signal.
   *
   * By default, list items are activatable.
   *
   * @param activatable If the item should be activatable.
   */
  void set_activatable(bool activatable =  true);

  /** Sets the child to be used for this listitem.
   *
   * This function is typically called by applications when
   * setting up a listitem so that the widget can be reused when
   * binding it multiple times.
   *
   * @param child The list item's child or <tt>nullptr</tt> to unset.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child previously set via set_child() or
   * <tt>nullptr</tt> if none was set.
   *
   * @return The child.
   */
  auto get_child() -> Widget*;

  /** Gets the child previously set via set_child() or
   * <tt>nullptr</tt> if none was set.
   *
   * @return The child.
   */
  auto get_child() const -> const Widget*;

  /** If the item can be activated by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activatable() -> Glib::PropertyProxy< bool > ;

/** If the item can be activated by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Widget used for display.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** Widget used for display.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** Displayed item.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


  /** Position of the item.
   *
   * Default value: 4294967295
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** If the item can be selected by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() -> Glib::PropertyProxy< bool > ;

/** If the item can be selected by the user.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selectable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If the item is currently selected.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selected() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::ListItem
   */
  GTKMM_API
  auto wrap(GtkListItem* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ListItem>;
}


#endif /* _GTKMM_LISTITEM_H */

