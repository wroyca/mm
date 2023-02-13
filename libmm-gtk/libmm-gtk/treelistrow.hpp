
#ifndef _GTKMM_TREELISTROW_H
#define _GTKMM_TREELISTROW_H

#include <mm/gtk/mm-gtkconfig.hpp>


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


#include <mm/glib/object.hpp>
#include <mm/gio/listmodel.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeListRow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A row in a Gtk::TreeListModel.
 *
 * %Gtk::TreeListRow is the object used by Gtk::TreeListModel to
 * represent items. It allows navigating the model as a tree and
 * modify the state of rows.
 *
 * %Gtk::TreeListRow instances are created by a Gtk::TreeListModel only
 * when the Gtk::TreeListModel::property_passthrough() property is not set.
 *
 * There are various support objects that can make use of %Gtk::TreeListRow
 * objects, such as the Gtk::TreeExpander widget that allows displaying
 * an icon to expand or collapse a row or Gtk::TreeListRowSorter that makes
 * it possible to sort trees properly.
 *
 * @see Gtk::TreeListModel
 *
 * @newin{3,98}
 */

class GTKMM_API TreeListRow : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeListRow;
  using CppClassType = TreeListRow_Class;
  using BaseObjectType = GtkTreeListRow;
  using BaseClassType = GtkTreeListRowClass;

  // noncopyable
  TreeListRow(const TreeListRow&) = delete;
  auto operator=(const TreeListRow&) -> TreeListRow& = delete;

private:  friend class TreeListRow_Class;
  static CppClassType treelistrow_class_;

protected:
  explicit TreeListRow(const Glib::ConstructParams& construct_params);
  explicit TreeListRow(GtkTreeListRow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeListRow(TreeListRow&& src) noexcept;
  auto operator=(TreeListRow&& src) noexcept -> TreeListRow&;

  ~TreeListRow() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeListRow*       { return reinterpret_cast<GtkTreeListRow*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeListRow* { return reinterpret_cast<GtkTreeListRow*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTreeListRow*;

private:


public:


  /** Gets the item corresponding to this row,
   *
   * The value returned by this function never changes until the
   * row is destroyed.
   *
   * @return The item
   * of this row or <tt>nullptr</tt> when the row was destroyed.
   */
  auto get_item() -> Glib::RefPtr<Glib::ObjectBase>;

  /** Gets the item corresponding to this row,
   *
   * The value returned by this function never changes until the
   * row is destroyed.
   *
   * @return The item
   * of this row or <tt>nullptr</tt> when the row was destroyed.
   */
  auto get_item() const -> Glib::RefPtr<const Glib::ObjectBase>;

  /** Expands or collapses a row.
   *
   * If a row is expanded, the model of calling the
   * [callback@Gtk.TreeListModelCreateModelFunc] for the row's
   * item will be inserted after this row. If a row is collapsed,
   * those items will be removed from the model.
   *
   * If the row is not expandable, this function does nothing.
   *
   * @param expanded <tt>true</tt> if the row should be expanded.
   */
  void set_expanded(bool expanded =  true);

  /** Gets if a row is currently expanded.
   *
   * @return <tt>true</tt> if the row is expanded.
   */
  auto get_expanded() const -> bool;

  /** Checks if a row can be expanded.
   *
   * This does not mean that the row is actually expanded,
   * this can be checked with get_expanded().
   *
   * If a row is expandable never changes until the row is destroyed.
   *
   * @return <tt>true</tt> if the row is expandable.
   */
  auto is_expandable() const -> bool;

  /** Returns the position in the `Gtk::TreeListModel` that @a self occupies
   * at the moment.
   *
   * @return The position in the model.
   */
  auto get_position() const -> guint;

  /** Gets the depth of this row.
   *
   * Rows that correspond to items in the root model have a depth
   * of zero, rows corresponding to items of models of direct children
   * of the root model have a depth of 1 and so on.
   *
   * The depth of a row never changes until the row is destroyed.
   *
   * @return The depth of this row.
   */
  auto get_depth() const -> guint;

  /** If the row is expanded, gets the model holding the children of @a self.
   *
   * This model is the model created by the
   * [callback@Gtk.TreeListModelCreateModelFunc]
   * and contains the original items, no matter what value
   * Gtk::TreeListModel::property_passthrough() is set to.
   *
   * @return The model containing the children.
   */
  auto get_children() -> Glib::RefPtr<Gio::ListModel>;

  /** If the row is expanded, gets the model holding the children of @a self.
   *
   * This model is the model created by the
   * [callback@Gtk.TreeListModelCreateModelFunc]
   * and contains the original items, no matter what value
   * Gtk::TreeListModel::property_passthrough() is set to.
   *
   * @return The model containing the children.
   */
  auto get_children() const -> Glib::RefPtr<const Gio::ListModel>;

  /** Gets the row representing the parent for @a self.
   *
   * That is the row that would need to be collapsed
   * to make this row disappear.
   *
   * If @a self is a row corresponding to the root model,
   * <tt>nullptr</tt> is returned.
   *
   * The value returned by this function never changes
   * until the row is destroyed.
   *
   * @return The parent of @a self.
   */
  auto get_parent() -> Glib::RefPtr<TreeListRow>;

  /** Gets the row representing the parent for @a self.
   *
   * That is the row that would need to be collapsed
   * to make this row disappear.
   *
   * If @a self is a row corresponding to the root model,
   * <tt>nullptr</tt> is returned.
   *
   * The value returned by this function never changes
   * until the row is destroyed.
   *
   * @return The parent of @a self.
   */
  auto get_parent() const -> Glib::RefPtr<const TreeListRow>;

  /** If @a self is not expanded or @a position is greater than the
   * number of children, <tt>nullptr</tt> is returned.
   *
   * @param position Position of the child to get.
   * @return The child in @a position.
   */
  auto get_child_row(guint position) -> Glib::RefPtr<TreeListRow>;

  /** If @a self is not expanded or @a position is greater than the
   * number of children, <tt>nullptr</tt> is returned.
   *
   * @param position Position of the child to get.
   * @return The child in @a position.
   */
  auto get_child_row(guint position) const -> Glib::RefPtr<const TreeListRow>;

  /** The model holding the row's children.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_children() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


  /** The depth in the tree of this row.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_depth() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** If this row can ever be expanded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expandable() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** If this row is currently expanded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expanded() -> Glib::PropertyProxy< bool > ;

/** If this row is currently expanded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expanded() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The item held in this row.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::TreeListRow
   */
  GTKMM_API
  auto wrap(GtkTreeListRow* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeListRow>;
}


#endif /* _GTKMM_TREELISTROW_H */

