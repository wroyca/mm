
#ifndef _GTKMM_TREEMODEL_H
#define _GTKMM_TREEMODEL_H


#include <libmm-glib/ustring.hpp>
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

#include <vector>

#include <gtk/gtk.h>
#include <libmm-glib/interface.hpp>
#include <libmm-gtk/treeiter.hpp>
#include <libmm-gtk/treemodelcolumn.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeModel = struct _GtkTreeModel;
using GtkTreeModelClass = struct _GtkTreeModelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeModel_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API TreeModelFilter;
class GTKMM_API TreeModelSort;
class GTKMM_API TreePath;
class GTKMM_API TreeRowReference;


//TODO: Remove any mention of null arguments from the method documentation, by adding overrides in gtk_docs_override.xml.
/** This class defines a generic tree interface for use by the Gtk::TreeView widget.
 * @ingroup TreeView
 *
 * It is is designed to be usable with any appropriate data structure. The
 * programmer just has to implement this interface on their own data type for
 * it to be viewable by a Gtk::TreeView widget.
 *
 * The model is represented as a hierarchical tree of strongly-typed, columned
 * data. In other words, the model can be seen as a tree where every node has
 * different values depending on which column is being queried.  The type of
 * data found in a column is determined by TreeModel::Column<> templates.
 * The types are homogeneous per column across all nodes. It is important to note that this
 * interface only provides a way of examining a model and observing changes.
 * The implementation of each individual model decides how and if changes are
 * made.
 *
 * In order to make life simpler for programmers who do not need to write their
 * own specialized model, two generic models are provided - the Gtk::TreeStore
 * and the Gtk::ListStore. To use these, the developer simply pushes data into
 * these models as necessary. These models provide the data structure as well
 * as all appropriate tree interfaces. As a result, implementing drag and drop,
 * sorting, and storing data is trivial. For the vast majority of trees and
 * lists, these two models are sufficient.
 *
 * Models are accessed on a node/column level of granularity. One can query for
 * the value of a model at a certain node and a certain column on that node.
 * There are two structures used to reference a particular node in a model.
 * They are the @link Gtk::TreePath Path@endlink and the iterator. Most of the interface consists of
 * operations on an @link Gtk::TreeIter iterator@endlink.
 *
 * A @link Gtk::TreePath Gtk::TreeModel::Path@endlink is essentially a potential node. It is a location on a model that may
 * or may not actually correspond to a node on a specific model.
 *
 * By contrast, an @link Gtk::TreeIter Gtk::TreeModel::iterator@endlink  is a reference to a specific node on a specific
 * model. One can convert a path to an @link Gtk::TreeIter iterator@endlink by calling Gtk::TreeModel::get_iter().
 * These iterators are the primary way of accessing a model and are similar to the iterators
 * used by Gtk::TextBuffer. The model interface defines a set of operations
 * using them for navigating the model.
 *
 * The @link Gtk::TreeRowReference RowReference@endlink is also useful, because it remains
 * valid as long as there is an existing row pointed to by it's path. You can convert between RowReferences and iterators and @link Gtk::TreePath Path@endlink s.
 */

class GTKMM_API TreeModel : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeModel;
  using CppClassType = TreeModel_Class;
  using BaseObjectType = GtkTreeModel;
  using BaseClassType = GtkTreeModelIface;

  // noncopyable
  TreeModel(const TreeModel&) = delete;
  auto operator=(const TreeModel&) -> TreeModel& = delete;

private:
  friend class TreeModel_Class;
  static CppClassType treemodel_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  TreeModel();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit TreeModel(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit TreeModel(GtkTreeModel* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeModel(TreeModel&& src) noexcept;
  auto operator=(TreeModel&& src) noexcept -> TreeModel&;

  ~TreeModel() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeModel*       { return reinterpret_cast<GtkTreeModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeModel* { return reinterpret_cast<GtkTreeModel*>(gobject_); }

private:


public:
  typedef TreeModelColumnRecord ColumnRecord;

  typedef TreeNodeChildren Children;
  typedef TreeNodeConstChildren ConstChildren;
  typedef Children::iterator iterator;
  typedef ConstChildren::const_iterator const_iterator;

  typedef TreeConstRow ConstRow;
  typedef TreeRow Row;
  typedef TreePath Path;
  typedef TreeRowReference RowReference;

  //These are part of GtkTreeModelFilter or GtkTreeModelSort, not GtkTreeModel:


  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Flags ITERS_PERSIST
   * Iterators survive all signals
   * emitted by the tree.
   *
   *  @var Flags LIST_ONLY
   * The model is a list only, and never
   * has children.
   *
   *  @enum Flags
   *
   * These flags indicate various properties of a `Gtk::TreeModel`.
   *
   * They are returned by Gtk::TreeModel::get_flags(), and must be
   * static for the lifetime of the object. A more complete description
   * of Gtk::TreeModel::Flags::ITERS_PERSIST can be found in the overview of
   * this section.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>TreeModel::Flags operator|(TreeModel::Flags, TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags operator&(TreeModel::Flags, TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags operator^(TreeModel::Flags, TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags operator~(TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags& operator|=(TreeModel::Flags&, TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags& operator&=(TreeModel::Flags&, TreeModel::Flags)</tt><br>
   * <tt>TreeModel::Flags& operator^=(TreeModel::Flags&, TreeModel::Flags)</tt><br>
   */
  enum class Flags
  {
    ITERS_PERSIST = 1 << 0,
    LIST_ONLY = 1 << 1
  };


  /** Returns a valid iterator pointing to @a path.
   *
   * @param path The @link Gtk::TreePath Gtk::TreeModel::Path@endlink.
   * @result A valid iterator pointing to the path, or an invalid iterator if that is not possible.
   */
  auto get_iter(const Path& path) -> iterator;

  /** Returns a valid iterator pointing to @a path.
   *
   * @param path The @link Gtk::TreePath Gtk::TreeModel::Path@endlink.
   * @result A valid iterator pointing to the path, or an invalid iterator if that is not possible.
   */
  auto get_iter(const Path& path) const -> const_iterator;

  /** Returns a valid iterator pointing to @a path_string.
   *
   * @param path_string The path, as a string representation.
   * @result A valid iterator pointing to the path, or an invalid iterator if that is not possible.
   */
  auto get_iter(const Glib::ustring& path_string) -> iterator;

  /** Returns a valid iterator pointing to @a path_string.
   *
   * @param path_string The path, as a string representation.
   * @result A valid iterator pointing to the path, or an invalid iterator if that is not possible.
   */
  auto get_iter(const Glib::ustring& path_string) const -> const_iterator;

  ///This returns an STL-like container API, for iterating over the rows.
  auto children() -> Children;

  ///This returns an STL-like container API, for iterating over the rows.
  auto children() const -> const ConstChildren;


  /** The type of callback slot used by foreach_iter().
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach_iter() returns.
   *
   * For example: bool on_foreach_iter(const Gtk::TreeModel::iterator& iter);
   */
  typedef sigc::slot<bool(const TreeModel::iterator&)> SlotForeachIter;

  /** Calls a callback of type @link Gtk::TreeModel::SlotForeachIter
   * SlotForeachIter @endlink on each node in the model in a depth-first
   * fashion.
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach_iter() returns.
   *
   * @param slot The function to call for each selected node.
   */
  void foreach_iter(const SlotForeachIter& slot);

  /** The type of callback slot used by foreach_path().
   *
   * For example: bool on_foreach_path(const Gtk::TreeModel::Path& path);
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach_path() returns.
   */
  typedef sigc::slot<bool(const TreeModel::Path&)> SlotForeachPath;

  /** Calls a callback of type @link Gtk::TreeModel::SlotForeachPath
   * SlotForeachPath @endlink on each node in the model in a depth-first
   * fashion.
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach_path() returns.
   *
   * @param slot The function to call for each selected node.
   */
  void foreach_path(const SlotForeachPath& slot);

  /** The type of callback slot used by foreach().
   *
   * For example: bool on_foreach(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& iter);
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach() returns.
   */
  typedef sigc::slot<bool(const TreeModel::Path&, const TreeModel::iterator&)> SlotForeachPathAndIter;

  /** Calls a callback of type @link Gtk::TreeModel::SlotForeachPathAndIter
   * SlotForeachPathAndIter @endlink on each node in the model in a depth-first
   * fashion.
   *
   * If the callback function returns true, then the tree ceases to be walked, and foreach() returns.
   *
   * @param slot The function to call for each selected node.
   */
  void foreach(const SlotForeachPathAndIter& slot);


  /** Returns a set of flags supported by this interface.
   *
   * The flags are a bitwise combination of `Gtk::TreeModel`Flags.
   * The flags supported should not change during the lifetime
   * of the @a tree_model.
   *
   * @return The flags supported by this interface.
   */
  auto get_flags() const -> Flags;

  /** Returns the number of columns supported by @a tree_model.
   *
   * @return The number of columns.
   */
  auto get_n_columns() const -> int;

  /** Returns the type of the column.
   *
   * @param index The column index.
   * @return The type of the column.
   */
  auto get_column_type(int index) const -> GType;
  //TODO: A C++-type version of get_column_type()?


  /** Returns a Gtk::TreePath referenced by @a iter.
   *
   * @param iter The Gtk::TreeIter.
   * @return A Gtk::TreePath.
   */
  auto get_path(const const_iterator& iter) const -> TreeModel::Path;


  /** Emits the signal_row_changed() signal on @a tree_model.
   *
   * See signal_row_changed().
   *
   * @param path A `Gtk::TreePath` pointing to the changed row.
   * @param iter A valid `Gtk::TreeIter` pointing to the changed row.
   */
  void row_changed(const Path& path, const const_iterator& iter);

  /** Emits the signal_row_inserted() signal on @a tree_model.
   *
   * See signal_row_inserted().
   *
   * @param path A `Gtk::TreePath` pointing to the inserted row.
   * @param iter A valid `Gtk::TreeIter` pointing to the inserted row.
   */
  void row_inserted(const Path& path, const const_iterator& iter);

  /** Emits the signal_row_has_child_toggled() signal on @a tree_model.
   *
   * See signal_row_has_child_toggled().
   *
   * This should be called by models after the child
   * state of a node changes.
   *
   * @param path A `Gtk::TreePath` pointing to the changed row.
   * @param iter A valid `Gtk::TreeIter` pointing to the changed row.
   */
  void row_has_child_toggled(const Path& path, const const_iterator& iter);

  /** Emits the signal_row_deleted() signal on @a tree_model.
   *
   * See signal_row_deleted().
   *
   * This should be called by models after a row has been removed.
   * The location pointed to by @a path should be the location that
   * the row previously was at. It may not be a valid location anymore.
   *
   * Nodes that are deleted are not unreffed, this means that any
   * outstanding references on the deleted node should not be released.
   *
   * @param path A `Gtk::TreePath` pointing to the previous location of
   * the deleted row.
   */
  void row_deleted(const Path& path);

 /** Emits the "rows_reordered" signal on the tree model.  This should be called by
  * custom models when their rows have been reordered.
  *
  * @param path A tree path pointing to the tree node whose children have been reordered.
  * @param iter A valid iterator pointing to the node whose children have been reordered. See also, rows_reordered(const Path& path, const std::vector<int>& new_order), if the path has a depth of 0.
  * @param new_order An array of integers mapping the current position of each child
  * to its old position before the re-ordering, i.e. @a new_order<literal>[newpos] = oldpos.
  */
  void rows_reordered(const Path& path, const const_iterator& iter, const std::vector<int>& new_order);


 /** Emits the "rows_reordered" signal on the tree model.  This should be called by
  * custom models when their rows have been reordered. This method overload is for nodes whose
  * path has a depth of 0.
  * @newin{2,10}
  *
  * @param path A tree path pointing to the tree node whose children have been reordered.
  * @param new_order An array of integers mapping the current position of each child
  * to its old position before the re-ordering, i.e. @a new_order<literal>[newpos] = oldpos.
  */
  void rows_reordered(const Path& path, const std::vector<int>& new_order);


  /** Emits the Gtk::TreeModel::signal_rows_reordered() signal on @a tree_model.
   *
   * This should be called by models when their rows have been
   * reordered.
   *
   * @param path A Gtk::TreePath pointing to the tree node whose children
   * have been reordered.
   * @param iter A valid Gtk::TreeIter pointing to the node whose children
   * have been reordered, or <tt>nullptr</tt> if the depth of @a path is 0.
   * @param new_order An array of integers mapping the current position of
   * each child to its old position before the re-ordering,
   * i.e. new_order<tt>[newpos] = oldpos</tt>.
   */
  void rows_reordered(const Path& path, const const_iterator& iter, int* new_order);


  /** Generates a string representation of the iter.
   *
   * This string is a “:” separated list of numbers.
   * For example, “4:10:0:3” would be an acceptable
   * return value for this string.
   *
   * @param iter An Gtk::TreeIter.
   * @return The string.
   */
  auto get_string(const const_iterator& iter) const -> Glib::ustring;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_changed(const TreeModel::Path& path, const TreeModel::iterator& iter)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when a row in the model has changed.
   *
   * @param path A `Gtk::TreePath` identifying the changed row.
   * @param iter A valid `Gtk::TreeIter` pointing to the changed row.
   */

  auto signal_row_changed() -> Glib::SignalProxy<void(const TreeModel::Path&, const TreeModel::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_inserted(const TreeModel::Path& path, const TreeModel::iterator& iter)</tt>
   *
   * Flags: Run First
   *
   * This signal is emitted when a new row has been inserted in
   * the model.
   *
   * Note that the row may still be empty at this point, since
   * it is a common pattern to first insert an empty row, and
   * then fill it with the desired values.
   *
   * @param path A `Gtk::TreePath` identifying the new row.
   * @param iter A valid `Gtk::TreeIter` pointing to the new row.
   */

  auto signal_row_inserted() -> Glib::SignalProxy<void(const TreeModel::Path&, const TreeModel::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_has_child_toggled(const TreeModel::Path& path, const TreeModel::iterator& iter)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when a row has gotten the first child
   * row or lost its last child row.
   *
   * @param path A `Gtk::TreePath` identifying the row.
   * @param iter A valid `Gtk::TreeIter` pointing to the row.
   */

  auto signal_row_has_child_toggled() -> Glib::SignalProxy<void(const TreeModel::Path&, const TreeModel::iterator&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_deleted(const TreeModel::Path& path)</tt>
   *
   * Flags: Run First
   *
   * This signal is emitted when a row has been deleted.
   *
   * Note that no iterator is passed to the signal handler,
   * since the row is already deleted.
   *
   * This should be called by models after a row has been removed.
   * The location pointed to by @a path should be the location that
   * the row previously was at. It may not be a valid location anymore.
   *
   * @param path A `Gtk::TreePath` identifying the row.
   */

  auto signal_row_deleted() -> Glib::SignalProxy<void(const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%rows_reordered(const TreeModel::Path& path, const TreeModel::iterator& iter, int* new_order)</tt>
   *
   * Flags: Run First
   *
   * This signal is emitted when the children of a node in the
   * `Gtk::TreeModel` have been reordered.
   *
   * Note that this signal is not emitted
   * when rows are reordered by DND, since this is implemented
   * by removing and then reinserting the row.
   *
   * @param path A `Gtk::TreePath` identifying the tree node whose children
   * have been reordered.
   * @param iter A valid `Gtk::TreeIter` pointing to the node whose children
   * have been reordered, or <tt>nullptr</tt> if the depth of @a path is 0.
   * @param new_order An array of integers mapping the current position
   * of each child to its old position before the re-ordering,
   * i.e. @a new_order`[newpos] = oldpos`.
   */

  auto signal_rows_reordered() -> Glib::SignalProxy<void(const TreeModel::Path&, const TreeModel::iterator&, int*)>;


protected:
    virtual auto get_flags_vfunc() const -> Flags;

    virtual auto get_n_columns_vfunc() const -> int;

    virtual auto get_column_type_vfunc(int index) const -> GType;


  //These are only for deriving new TreeModels, which isn't very common or easy:

  /** Override and implement this in a derived TreeModel class.
   * Sets @a iter_next to refer to the node following @a iter it at the current level.
   * If there is no next iter, false is returned and iter_next is set to be invalid.
   *
   * @param iter An iterator.
   * @param iter_next An iterator that will be set to refer to the next node, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto iter_next_vfunc(const iterator& iter, iterator& iter_next) const -> bool;

  /** Override and implement this in a derived TreeModel class.
   * Sets @a iter to a valid iterator pointing to @a path
   *
   * @param path An path to a node.
   * @param iter An iterator that will be set to refer to a node to the path, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto get_iter_vfunc(const Path& path, iterator& iter) const -> bool;

  /** Override and implement this in a derived TreeModel class.
   * Sets @a iter to refer to the first child of @a parent. If @a parent has no children,
   * false is returned and @a iter is set to be invalid.
   *
   * @param parent An iterator.
   * @param iter An iterator that will be set to refer to the firt child node, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto iter_children_vfunc(const iterator& parent, iterator& iter) const -> bool;

  /** Override and implement this in a derived TreeModel class.
   * Sets @a iter to be the parent of @a child. If @a child is at the toplevel, and
   * doesn't have a parent, then @a iter is set to an invalid iterator and false
   * is returned.
   *
   * @param child An iterator.
   * @param iter An iterator that will be set to refer to the parent node, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto iter_parent_vfunc(const iterator& child, iterator& iter) const -> bool;

  /** Override and implement this in a derived TreeModel class.
   * Sets @a iter to be the child of @a parent using the given index.  The first
   * index is 0.  If @a n is too big, or @a parent has no children, @a iter is set
   * to an invalid iterator and false is returned.
   * See also iter_nth_root_child_vfunc()
   *
   * @param parent An iterator.
   * @param n The index of the child node to which @a iter should be set.
   * @param iter An iterator that will be set to refer to the nth node, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto iter_nth_child_vfunc(const iterator& parent, int n, iterator& iter) const -> bool;

   /** Override and implement this in a derived TreeModel class.
   * Sets @a iter to be the child of at the root level using the given index.  The first
   * index is 0.  If @a n is too big, or if there are no children, @a iter is set
   * to an invalid iterator and false is returned.
   * See also iter_nth_child_vfunc().
   *
   * @param n The index of the child node to which @a iter should be set.
   * @param iter An iterator that will be set to refer to the nth node, or will be set as invalid.
   * @result true if the operation was possible.
   */
  virtual auto iter_nth_root_child_vfunc(int n, iterator& iter) const -> bool;


  /** Override and implement this in a derived TreeModel class.
   * Returns true if @a iter has children, false otherwise.
   *
   * @param iter The iterator to test for children.
   * @result true if @a iter has children.
   */
    virtual auto iter_has_child_vfunc(const const_iterator& iter) const -> bool;


  /** Override and implement this in a derived TreeModel class.
   * Returns the number of children that @a iter has.
   * See also iter_n_root_children_vfunc().
   *
   * @param iter The iterator to test for children.
   * @result The number of children of @a iter.
   */
  virtual auto iter_n_children_vfunc(const const_iterator& iter) const -> int;

  /** Override and implement this in a derived TreeModel class.
   * Returns the number of toplevel nodes.
   * See also iter_n_children().
   *
   * @result The number of children at the root level.
   */
  virtual auto iter_n_root_children_vfunc() const -> int;

  /** Override and implement this in a derived TreeModel class.
   * Lets the tree ref the node.  This is an optional method for models to
   * implement.  To be more specific, models may ignore this call as it exists
   * primarily for performance reasons.
   *
   * This function is primarily meant as a way for views to let caching model know
   * when nodes are being displayed (and hence, whether or not to cache that
   * node.)  For example, a file-system based model would not want to keep the
   * entire file-hierarchy in memory, just the sections that are currently being
   * displayed by every current view.
   *
   * A model should be expected to be able to get an iter independent of its
   * reffed state.
   *
   * @param iter the iterator.
   */
    virtual void ref_node_vfunc(const iterator& iter) const;


  /** Override and implement this in a derived TreeModel class.
   * Lets the tree unref the node.  This is an optional method for models to
   * implement.  To be more specific, models may ignore this call as it exists
   * primarily for performance reasons.
   *
   * For more information on what this means, see unref_node_vfunc().
   * Please note that nodes that are deleted are not unreffed.
   *
   * @param iter the iterator.
   */
    virtual void unref_node_vfunc(const iterator& iter) const;


  /** Override and implement this in a derived TreeModel class.
   * Returns a Path referenced by @a iter.
   *
   * @param iter The iterator.
   * @result The path.
   */


    virtual auto get_path_vfunc(const const_iterator& iter) const -> TreeModel::Path;


  /** Override and implement this in a derived TreeModel class.
   * Initializes and sets @a value to that at @a column.
   *
   * @param iter The iterator.
   * @param column The column to lookup the value at.
   * @param value An empty Glib:Value to set.
   */
    virtual void get_value_vfunc(const const_iterator& iter, int column, Glib::ValueBase& value) const;


  //Called by TreeRow, which is a friend class:
  //The comment about row_changed() in the documentation is based on my reading of the source of
  //gtk_list_store_set_value() and gtk_tree_store_set_value(). murrayc
  /** Override and implement this in a derived TreeModel class, so that Row::operator() and
   * Row::set_value() work.
   * Your implementation of set_value_impl() should call row_changed() after changing the value.
   */
  virtual void set_value_impl(const iterator& iter, int column, const Glib::ValueBase& value);

  //This might not need to be virtual, but it's not a big deal. murrayc.
  virtual void get_value_impl(const const_iterator& iter, int column, Glib::ValueBase& value) const;

  friend GTKMM_API class Gtk::TreeModelFilter;
  friend GTKMM_API class Gtk::TreeModelSort;
  friend GTKMM_API class Gtk::TreeConstRow;
  friend GTKMM_API class Gtk::TreeRow;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_row_changed().
  virtual void on_row_changed(const TreeModel::Path& path, const TreeModel::iterator& iter);
  /// This is a default handler for the signal signal_row_inserted().
  virtual void on_row_inserted(const TreeModel::Path& path, const TreeModel::iterator& iter);
  /// This is a default handler for the signal signal_row_has_child_toggled().
  virtual void on_row_has_child_toggled(const TreeModel::Path& path, const TreeModel::iterator& iter);
  /// This is a default handler for the signal signal_row_deleted().
  virtual void on_row_deleted(const TreeModel::Path& path);
  /// This is a default handler for the signal signal_rows_reordered().
  virtual void on_rows_reordered(const TreeModel::Path& path, const TreeModel::iterator& iter, int* new_order);


};

} // namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  { return static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  { return static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  { return static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(TreeModel::Flags flags) -> TreeModel::Flags
  { return static_cast<TreeModel::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  { return (lhs = static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  { return (lhs = static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  { return (lhs = static_cast<TreeModel::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TreeModel::Flags> : public Glib::Value_Flags<Gtk::TreeModel::Flags>
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
   * @relates Gtk::TreeModel
   */
  GTKMM_API
  auto wrap(GtkTreeModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeModel>;

} // namespace Glib


#endif /* _GTKMM_TREEMODEL_H */

