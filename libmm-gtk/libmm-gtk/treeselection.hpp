
#ifndef _GTKMM_TREESELECTION_H
#define _GTKMM_TREESELECTION_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 1998-1999 The gtkmm Development Team
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

#include <mm/gtk/enums.hpp>
#include <mm/gtk/treemodel.hpp>
#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/treepath.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeSelection = struct _GtkTreeSelection;
using GtkTreeSelectionClass = struct _GtkTreeSelectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeSelection_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API TreeView;

/** Typedefed as Gtk::TreeView::Selection.
 * This is a helper object to manage the selection for a Gtk::TreeView widget.
 *
 * It is automatically created when a new Gtk::TreeView widget is created, and
 * cannot exist independently of this widget.  The primary reason this class
 * exists is for cleanliness of code and API. That is, there is no conceptual
 * reason all these methods could not be methods on the Gtk::TreeView widget
 * instead of a separate class.
 *
 * The Gtk::TreeSelection object can be obtained from a Gtk::TreeView by
 * calling Gtk::TreeView::get_selection().  It can be manipulated to check the
 * selection status of the tree, as well as to select and deselect individual
 * rows.  Selection is done completely view-side. As a result, multiple views
 * of the same model can have completely different selections.  Additionally,
 * you cannot change the selection of a row on the model that is not currently
 * displayed by the view without expanding its parents first.
 *
 * When monitoring the selection of a view, it's important to remember that the
 * "changed" signal is mostly a hint. That is, it may only emit one signal when
 * a range of rows is selected. Additionally, it may on occasion emit a
 * "changed" signal when nothing has happened.
 *
 * @ingroup TreeView
 */

class GTKMM_API TreeSelection : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TreeSelection;
  using CppClassType = TreeSelection_Class;
  using BaseObjectType = GtkTreeSelection;
  using BaseClassType = GtkTreeSelectionClass;

  // noncopyable
  TreeSelection(const TreeSelection&) = delete;
  auto operator=(const TreeSelection&) -> TreeSelection& = delete;

private:  friend class TreeSelection_Class;
  static CppClassType treeselection_class_;

protected:
  explicit TreeSelection(const Glib::ConstructParams& construct_params);
  explicit TreeSelection(GtkTreeSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TreeSelection(TreeSelection&& src) noexcept;
  auto operator=(TreeSelection&& src) noexcept -> TreeSelection&;

  ~TreeSelection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeSelection*       { return reinterpret_cast<GtkTreeSelection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeSelection* { return reinterpret_cast<GtkTreeSelection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkTreeSelection*;

private:


public:

  /** Sets the selection mode of the @a selection.  If the previous type was
   * Gtk::SelectionMode::MULTIPLE, then the anchor is kept selected, if it was
   * previously selected.
   *
   * @param type The selection mode.
   */
  void set_mode(SelectionMode type);

  /** Gets the selection mode for @a selection. See
   * set_mode().
   *
   * @return The current selection mode.
   */
  auto get_mode() const -> SelectionMode;

  /** For instance,
   * bool on_select_function(const Glib::RefPtr<TreeModel>& model, const TreeModel::Path& path, bool path_currently_selected);
   *
   * The select function should return true if the state of the node may be toggled,
   * and false if the state of the node should be left unchanged.
   */
  using SlotSelect = sigc::slot<bool(const Glib::RefPtr<TreeModel>&, const TreeModel::Path&, bool)>;

  /** Sets the selection callback slot. If set, this function is called before any node is selected or unselected,
   * giving some control over which nodes are selected.
   *
   * The select function should return true if the state of the node may be toggled, and FALSE if the state of the node
   * should be left unchanged.
   *
   * @param slot The selection function.
   */
  void set_select_function(const SlotSelect& slot);

   // This would be our SignalProxy_Select* data.


  /** Returns the tree view associated with @a selection.
   *
   * @return A `Gtk::TreeView`.
   */
  auto get_tree_view() -> TreeView*;

  /** Returns the tree view associated with @a selection.
   *
   * @return A `Gtk::TreeView`.
   */
  auto get_tree_view() const -> const TreeView*;

  /** Shortcut for get_tree_view()->get_model().
   * @return The TreeModel associated with this TreeSelection.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>; // convenience function, not in GTK+
  auto get_model() const -> Glib::RefPtr<const TreeModel>; // convenience function, not in GTK+

  /** Get the currently selected row.
   * @return The currently selected row. Or an invalid iterator, if no row is selected.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SelectionMode::MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   */
  auto get_selected() -> TreeModel::iterator;

  /** Get the currently selected row.
   * @return The currently selected row. Or an invalid iterator, if no row is selected.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SelectionMode::MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   *
   * @newin{3,90}
   */
  auto get_selected() const -> TreeModel::const_iterator;

  /** Get the currently selected row.
   * @param[out] model The current TreeModel.
   * @return The currently selected row. Or an invalid iterator, if no row is selected.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SelectionMode::MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   */
  auto get_selected(Glib::RefPtr<TreeModel>& model) -> TreeModel::iterator;

  /** Get the currently selected row.
   * @param[out] model The current TreeModel.
   * @return The currently selected row. Or an invalid iterator, if no row is selected.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SelectionMode::MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   *
   * @newin{3,90}
   */
  auto get_selected(Glib::RefPtr<const TreeModel>& model) const -> TreeModel::const_iterator;

  /** Creates a vector of paths of all selected rows.
   * Additionally, if you are planning on modifying the model after calling this function,
   * you may want to convert the returned list into a list of GtkTreeRowReferences.
   *
   * @returns A vector containing a Gtk::TreeModel::Path for each selected row.
   */
  auto get_selected_rows() const -> std::vector<TreeModel::Path>;


  /** Creates a list of paths of all selected rows.
   * Additionally, if you are planning on modifying the model after calling this function,
   * you may want to convert the returned list into a list of GtkTreeRowReferences.
   *
   * @param[out] model The current TreeModel.
   * @returns A vector containing a Gtk::TreeModel::Path for each selected row.
   */
  auto get_selected_rows(Glib::RefPtr<TreeModel>& model) -> std::vector<TreeModel::Path>;


  /** Returns the number of rows that have been selected in @a tree.
   *
   * @return The number of rows selected.
   */
  auto count_selected_rows() const -> int;

  /** For example,
   * void on_foreach(const Gtk::TreeModel::const_iterator& iter);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  using SlotForeachIter = sigc::slot<void(const TreeModel::const_iterator&)>;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach_iter(const SlotForeachIter& slot) const;

  /** For example,
   * void on_foreach(const Gtk::TreeModel::Path& path);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  using SlotForeachPath = sigc::slot<void(const TreeModel::Path&)>;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach_path(const SlotForeachPath& slot) const;


  /** For example,
   * void on_foreach(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::const_iterator& iter);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  using SlotForeachPathAndIter = sigc::slot<void(const TreeModel::Path&, const TreeModel::const_iterator&)>;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach(const SlotForeachPathAndIter& slot) const;


  /** Select the row at @a path.
   *
   * @param path The `Gtk::TreePath` to be selected.
   */
  void select(const TreeModel::Path& path);

  /** Selects a range of nodes, determined by @a start_path and @a end_path inclusive.
   *  @a selection must be set to Gtk::SelectionMode::MULTIPLE mode.
   *
   * @param start_path The initial node of the range.
   * @param end_path The final node of the range.
   */
  void select(const TreeModel::Path& start_path, const TreeModel::Path& end_path);

  /** Selects the specified iterator.
   *
   * @param iter The `Gtk::TreeIter` to be selected.
   */
  void select(const TreeModel::const_iterator& iter);


  /** Unselects the row at @a path.
   *
   * @param path The `Gtk::TreePath` to be unselected.
   */
  void unselect(const TreeModel::Path& path);

  /** Unselects a range of nodes, determined by @a start_path and @a end_path
   * inclusive.
   *
   * @param start_path The initial node of the range.
   * @param end_path The initial node of the range.
   */
  void unselect(const TreeModel::Path& start_path, const TreeModel::Path& end_path);

  /** Unselects the specified iterator.
   *
   * @param iter The `Gtk::TreeIter` to be unselected.
   */
  void unselect(const TreeModel::const_iterator& iter);


  /** Returns <tt>true</tt> if the row pointed to by @a path is currently selected.  If @a path
   * does not point to a valid location, <tt>false</tt> is returned
   *
   * @param path A `Gtk::TreePath` to check selection on.
   * @return <tt>true</tt> if @a path is selected.
   */
  auto is_selected(const TreeModel::Path& path) const -> bool;

  /** Returns <tt>true</tt> if the row at @a iter is currently selected.
   *
   * @param iter A valid `Gtk::TreeIter`.
   * @return <tt>true</tt>, if @a iter is selected.
   */
  auto is_selected(const TreeModel::const_iterator& iter) const -> bool;


  /** Selects all the nodes. @a selection must be set to Gtk::SelectionMode::MULTIPLE
   * mode.
   */
  void select_all();

  /** Unselects all the nodes.
   */
  void unselect_all();

  /** Selection mode.
   * See Gtk::TreeSelection::set_mode() for more information on this property.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() -> Glib::PropertyProxy< SelectionMode > ;

/** Selection mode.
   * See Gtk::TreeSelection::set_mode() for more information on this property.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >;


  // no_default_handler because GtkTreeSelectionClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run First
   *
   * Emitted whenever the selection has (possibly) changed. Please note that
   * this signal is mostly a hint.  It may only be emitted once when a range
   * of rows are selected, and it may occasionally be emitted when nothing
   * has happened.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


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
   * @relates Gtk::TreeSelection
   */
  GTKMM_API
  auto wrap(GtkTreeSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeSelection>;
}


#endif /* _GTKMM_TREESELECTION_H */

