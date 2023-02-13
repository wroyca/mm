
#ifndef _GTKMM_LISTSTORE_H
#define _GTKMM_LISTSTORE_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/treeiter.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treesortable.hxx>
#include <libmm-gtk/treedragdest.hxx>
#include <libmm-gtk/treedragsource.hxx>
#include <libmm-gtk/buildable.hxx>
// We couldn't include it in treemodel.h, but doing it here makes it easier for people.
#include <libmm-gtk/treepath.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListStore = struct _GtkListStore;
using GtkListStoreClass = struct _GtkListStoreClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ListStore_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Thist is a list model for use with a Gtk::TreeView widget.
 * @ingroup TreeView
 * It implements the Gtk::TreeModel interface, and also implements the
 * Gtk::TreeSortable interface so you can sort the list using the view.
 * Finally, it also implements the tree drag and drop interfaces.
 */

class GTKMM_API ListStore :
  public Glib::Object,
  public TreeModel,
  public TreeSortable,
  public TreeDragSource,
  public TreeDragDest,
  public Buildable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ListStore;
  using CppClassType = ListStore_Class;
  using BaseObjectType = GtkListStore;
  using BaseClassType = GtkListStoreClass;

  // noncopyable
  ListStore(const ListStore&) = delete;
  auto operator=(const ListStore&) -> ListStore& = delete;

private:  friend class ListStore_Class;
  static CppClassType liststore_class_;

protected:
  explicit ListStore(const Glib::ConstructParams& construct_params);
  explicit ListStore(GtkListStore* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ListStore(ListStore&& src) noexcept;
  auto operator=(ListStore&& src) noexcept -> ListStore&;

  ~ListStore() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkListStore*       { return reinterpret_cast<GtkListStore*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkListStore* { return reinterpret_cast<GtkListStore*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkListStore*;

private:


protected:
  /** When using this constructor, you must use set_column_types() immediately afterwards.
   * This can be useful when deriving from this class, with a fixed TreeModelColumnRecord
   * that is a member of the class.
   * There is no create() method that corresponds to this constructor, because this
   * constructor should only be used by derived classes.
   */
  ListStore();

  explicit ListStore(const TreeModelColumnRecord& columns);

public:

  /** Instantiate a new ListStore.
   * @param columns The column types for this tree model.
   * @result The new ListStore.
   */

  static auto create(const TreeModelColumnRecord& columns) -> Glib::RefPtr<ListStore>;


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


  //TODO: Docs. This one is apparently faster.
  /** Creates a new row after the position.
   * If iter is end() then a new row will be prepended to the list.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert(), prepend() and append().
   *
   * @param iter An iterator to the row after which the new row will be inserted.
   * @result An iterator to the new row.
   */
  auto insert_after(const iterator& iter) -> iterator;


  /** Creates a new row at the start.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and append().
   *
   * @result An iterator to the new row.
   */
  auto prepend() -> iterator;

  /** Creates a new row at the end.
   * The row will be empty - to fill in values, you need to dereference the returned iterator and use Row::operator[] or Row::set_value().
   * See also insert() and prepend().
   *
   * @result An iterator to the new row.
   */
  auto append() -> iterator;


  /** Swaps @a a and @a b in @a store. Note that this function only works with
   * unsorted stores.
   *
   * @param a A `Gtk::TreeIter`.
   * @param b Another `Gtk::TreeIter`.
   */
  void iter_swap(const iterator& a, const iterator& b);

  /** Moves @a source to the position at @a destination.
   * Note that this function only works with unsorted stores.
   * @param source The row that should be moved.
   * @param destination The position to move to.
   */
  void move(const iterator& source, const iterator& destination);

  /** Reorders the list store to follow the order indicated by @a new_order.
   * Note that this function only works with unsorted stores.
   */
  void reorder(const std::vector<int>& new_order);


  /** Removes all rows from the list store.
   */
  void clear();


  /** Checks if the given iter is a valid iter for this `Gtk::ListStore`.
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
   * @relates Gtk::ListStore
   */
  GTKMM_API
  auto wrap(GtkListStore* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ListStore>;
}


#endif /* _GTKMM_LISTSTORE_H */
