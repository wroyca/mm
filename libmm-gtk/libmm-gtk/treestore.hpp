
#ifndef _GTKMM_TREESTORE_H
#define _GTKMM_TREESTORE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or(at your option) any later version.
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

#include <vector>

#include <libmm-gtk/treeiter.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gtk/treesortable.hpp>
#include <libmm-gtk/treedragdest.hpp>
#include <libmm-gtk/treedragsource.hpp>
#include <libmm-gtk/buildable.hpp>
// We couldn't include it in treemodel.h, but doing it here makes it easier for people.
#include <libmm-gtk/treepath.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeStore = struct _GtkTreeStore;
using GtkTreeStoreClass = struct _GtkTreeStoreClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeStore_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**
 * @ingroup TreeView
 */

class GTKMM_API TreeStore :
  public Glib::Object,
  public Gtk::TreeModel,
  public TreeSortable,
  public TreeDragSource,
  public TreeDragDest,
  public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeStore;
  using CppClassType = TreeStore_Class;
  using BaseObjectType = GtkTreeStore;
  using BaseClassType = GtkTreeStoreClass;

  // noncopyable
  TreeStore(const TreeStore&) = delete;
  auto operator=(const TreeStore&) -> TreeStore& = delete;

private:  friend class TreeStore_Class;
  static CppClassType treestore_class_;

protected:
  explicit TreeStore(const Glib::ConstructParams& construct_params);
  explicit TreeStore(GtkTreeStore* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeStore(TreeStore&& src) noexcept;
  auto operator=(TreeStore&& src) noexcept -> TreeStore&;

  ~TreeStore() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeStore*       { return reinterpret_cast<GtkTreeStore*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeStore* { return reinterpret_cast<GtkTreeStore*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTreeStore*;

private:


protected:
  /** When using this constructor, you must use set_column_types() immediately afterwards.
   * This can be useful when deriving from this class, with a fixed TreeModelColumnRecord
   * that is a member of the class.
   * There is no create() method that corresponds to this constructor, because this
   * constructor should only be used by derived classes.
   */
  TreeStore();

  explicit TreeStore(const TreeModelColumnRecord& columns);

public:
  /** Instantiate a new TreeStore.
   * @param columns The column types for this tree model.
   * @result The new TreeStore.
   */

  static auto create(const TreeModelColumnRecord& columns) -> Glib::RefPtr<TreeStore>;


  void set_column_types(const TreeModelColumnRecord& columns);


  /** Removes the given row from the list store.
   * @param iter The iterator to the row to be removed.
   * @result An iterator to the next row, or end() if there is none.
   */
  auto erase(const iterator& iter) -> iterator;


  //TODO: Make this documentation similar to documentation for Standard C++ insert methods.
  /** Creates a new row before the position.
   * If iter is end() then a new row will be appended to the list.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also prepend() and append().
   *
   * @param iter An iterator to the row before which the new row will be inserted.
   * @result An iterator to the new row.
   */
  auto insert(const iterator& iter) -> iterator;


  /** Creates a new row after the position.
   * If iter is end() then a new row will be prepended to the list.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also prepend() and append().
   *
   * @param iter An iterator to the row after which the new row will be inserted.
   * @result An iterator to the new row.
   */
  auto insert_after(const iterator& iter) -> iterator;


  /** Creates a new row at the start of the top-level.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and append().
   *
   * @result An iterator to the new row.
   */
  auto prepend() -> iterator;

  /** Creates a new row at the start of the row's children.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and append().
   *
   * @param node The list of the parent row's children, as returned by Gtk::TreeModel::iterator::children().
   * @result An iterator to the new row.
   */
  auto prepend(const TreeNodeChildren& node) -> iterator;


  /** Creates a new row at the end of the top-level.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and prepend().
   *
   * @result An iterator to the new row.
   */
  auto append() -> iterator;

  /** Creates a new row at the end of the row's children.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and prepend().
   *
   * @param node The list of the parent row's children, as returned by Gtk::TreeModel::iterator::children().
   * @result An iterator to the new row.
   */
  auto append(const TreeNodeChildren& node) -> iterator;


  /** Swaps @a a and @a b in the same level of @a tree_store. Note that this function
   * only works with unsorted stores.
   *
   * @param a A `Gtk::TreeIter`.
   * @param b Another `Gtk::TreeIter`.
   */
  void iter_swap(const iterator& a, const iterator& b);

  /** Moves @a source to the position at @a destination.
   * @a source and @a destination should be at the same level.
   * Note that this function only works with unsorted stores.
   * @param source The row that should be moved.
   * @param destination The position to move to.
   */
  void move(const iterator& source, const iterator& destination);

  /** Reorders the children of @a node to follow the order indicated by @a new_order.
   * Note that this function only works with unsorted stores.
   */
  void reorder(const TreeNodeChildren& node, const std::vector<int>& new_order);


  /** Removes all rows from @a tree_store
   */
  void clear();

  /** Returns <tt>true</tt> if @a iter is an ancestor of @a descendant.  That is, @a iter is the
   * parent (or grandparent or great-grandparent) of @a descendant.
   *
   * @param iter A valid `Gtk::TreeIter`.
   * @param descendant A valid `Gtk::TreeIter`.
   * @return <tt>true</tt>, if @a iter is an ancestor of @a descendant.
   */
  auto is_ancestor(const const_iterator& iter, const const_iterator& descendant) const -> bool;

  /** Returns the depth of @a iter.  This will be 0 for anything on the root level, 1
   * for anything down a level, etc.
   *
   * @param iter A valid `Gtk::TreeIter`.
   * @return The depth of @a iter.
   */
  auto iter_depth(const const_iterator& iter) const -> int;


  /** Checks if the given iter is a valid iter for this `Gtk::TreeStore`.
   *
   * This function is slow. Only use it for debugging and/or testing
   * purposes.
   *
   * @param iter The iterator to check.
   * @return <tt>true</tt> if the iter is valid, <tt>false</tt> if the iter is invalid.
   */
  auto iter_is_valid(const const_iterator& iter) const -> bool;

protected:
  void set_value_impl(const iterator& row, int column, const Glib::ValueBase& value) override;


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
   * @relates Gtk::TreeStore
   */
  GTKMM_API
  auto wrap(GtkTreeStore* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeStore>;
}


#endif /* _GTKMM_TREESTORE_H */

