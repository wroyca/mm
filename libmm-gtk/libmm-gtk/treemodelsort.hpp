
#ifndef _GTKMM_TREEMODELSORT_H
#define _GTKMM_TREEMODELSORT_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright(C) 1998-2002 The gtkmm Development Team
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


#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/treemodel.hpp>
#include <mm/gtk/treesortable.hpp>
#include <mm/gtk/treedragsource.hpp>
// We couldn't include it in treemodel.h, but doing it here makes it easier for people.
#include <mm/gtk/treepath.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeModelSort = struct _GtkTreeModelSort;
using GtkTreeModelSortClass = struct _GtkTreeModelSortClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeModelSort_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A wrapper which makes an underlying Gtk::TreeModel sortable.
 *
 * The TreeModelSort is a model which implements the TreeSortable interface.
 * It does not hold any data itself, but rather is created with
 * a child model and proxies its data.  It has identical column types to
 * this child model, and the changes in the child are propagated.  The
 * primary purpose of this model is to provide a way to sort a different
 * model without modifying it. Note that the sort function used by
 * TreeModelSort is not guaranteed to be stable.
 *
 * For instance, you might create two TreeView widgets each with a
 * view of the same data.  If the model is wrapped by a
 * TreeModelSort then the two TreeViews can each sort their
 * view of the data without affecting the other.  By contrast, if we
 * simply put the same model in each widget, then sorting the first would
 * sort the second.
 *
 * @ingroup TreeView
 */

class GTKMM_API TreeModelSort :
  public Glib::Object,
  public TreeModel,
  public TreeSortable,
  public TreeDragSource
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeModelSort;
  using CppClassType = TreeModelSort_Class;
  using BaseObjectType = GtkTreeModelSort;
  using BaseClassType = GtkTreeModelSortClass;

  // noncopyable
  TreeModelSort(const TreeModelSort&) = delete;
  auto operator=(const TreeModelSort&) -> TreeModelSort& = delete;

private:  friend class TreeModelSort_Class;
  static CppClassType treemodelsort_class_;

protected:
  explicit TreeModelSort(const Glib::ConstructParams& construct_params);
  explicit TreeModelSort(GtkTreeModelSort* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeModelSort(TreeModelSort&& src) noexcept;
  auto operator=(TreeModelSort&& src) noexcept -> TreeModelSort&;

  ~TreeModelSort() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeModelSort*       { return reinterpret_cast<GtkTreeModelSort*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeModelSort* { return reinterpret_cast<GtkTreeModelSort*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTreeModelSort*;

private:


protected:
    explicit TreeModelSort(const Glib::RefPtr<TreeModel>& model);


public:

  static auto create(const Glib::RefPtr<TreeModel>& model) -> Glib::RefPtr<TreeModelSort>;


  /** Returns the model the `Gtk::TreeModelSort` is sorting.
   *
   * @return The "child model" being sorted.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the model the `Gtk::TreeModelSort` is sorting.
   *
   * @return The "child model" being sorted.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;


  /** Converts @a child_path to a path relative to @a tree_model_sort.  That is,
   *  @a child_path points to a path in the child model.  The returned path will
   * point to the same row in the sorted model.  If @a child_path isn’t a valid
   * path on the child model, then <tt>nullptr</tt> is returned.
   *
   * @param child_path A `Gtk::TreePath` to convert.
   * @return A newly allocated `Gtk::TreePath`.
   */
  auto convert_child_path_to_path(const Path& child_path) const -> Path;

  /** Gets an iterator that points to the sorted row that corresponds to the child row pointed at by child_iter.
   *
   * @param child_iter A valid iterator pointing to a row on the child model.
   * @result A valid iterator that points to the row in this sorted model.
   */
  auto convert_child_iter_to_iter(const iterator& child_iter) -> iterator;

  /** Gets an iterator that points to the sorted row that corresponds to the child row pointed at by child_iter.
   *
   * @param child_iter A valid iterator pointing to a row on the child model.
   * @result A valid iterator that points to the row in this sorted model.
   */
  auto convert_child_iter_to_iter(const const_iterator& child_iter) const -> const_iterator;


  /** Converts @a sorted_path to a path on the child model of @a tree_model_sort.
   * That is, @a sorted_path points to a location in @a tree_model_sort.  The
   * returned path will point to the same location in the model not being
   * sorted.  If @a sorted_path does not point to a location in the child model,
   * <tt>nullptr</tt> is returned.
   *
   * @param sorted_path A `Gtk::TreePath` to convert.
   * @return A newly allocated `Gtk::TreePath`.
   */
  auto convert_path_to_child_path(const Path& sorted_path) const -> Path;

  /** Gets an iterator that points to the child row that corresponds to the sorted row pointed at by sorted_iter.
   *
   * @param sorted_iter A valid iterator pointing to a row on the sorted model.
   * @result A valid iterator that points to the row in the child model.
   */
  auto convert_iter_to_child_iter(const iterator& sorted_iter) -> iterator;

  /** Gets an iterator that points to the child row that corresponds to the sorted row pointed at by sorted_iter.
   *
   * @param sorted_iter A valid iterator pointing to a row on the sorted model.
   * @result A valid iterator that points to the row in the child model.
   */
  auto convert_iter_to_child_iter(const const_iterator& sorted_iter) const -> const_iterator;


  /** This resets the default sort function to be in the “unsorted” state.  That
   * is, it is in the same order as the child model. It will re-sort the model
   * to be in the same order as the child model only if the `Gtk::TreeModelSort`
   * is in “unsorted” state.
   */
  void reset_default_sort_func();

  /** This function should almost never be called.  It clears the @a tree_model_sort
   * of any cached iterators that haven’t been reffed with
   * ref_node().  This might be useful if the child model being
   * sorted is static (and doesn’t change often) and there has been a lot of
   * unreffed access to nodes.  As a side effect of this function, all unreffed
   * iters will be invalid.
   */
  void clear_cache();


  /** > This function is slow. Only use it for debugging and/or testing
   * > purposes.
   *
   * Checks if the given iter is a valid iter for this `Gtk::TreeModelSort`.
   *
   * @param iter A `Gtk::TreeIter`.
   * @return <tt>true</tt> if the iter is valid, <tt>false</tt> if the iter is invalid.
   */
  auto iter_is_valid(const const_iterator& iter) const -> bool;

  /**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >;


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
   * @relates Gtk::TreeModelSort
   */
  GTKMM_API
  auto wrap(GtkTreeModelSort* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeModelSort>;
}


#endif /* _GTKMM_TREEMODELSORT_H */

