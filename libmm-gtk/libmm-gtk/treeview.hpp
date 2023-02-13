
#ifndef _GTKMM_TREEVIEW_H
#define _GTKMM_TREEVIEW_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright(C) 2002 The gtkmm Development Team
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

// This is for including the config header before any code (such as
// the #ifndef GTKMM_DISABLE_DEPRECATED in deprecated classes) is generated:


#include <vector>
#include <cstdlib> // std::strto*()
#include <mm/gtk/widget.hpp>
#include <mm/gtk/treeviewcolumn.hpp>
#include <mm/gtk/treeselection.hpp>
#include <mm/gtk/treemodelcolumn.hpp>
#include <mm/gtk/cellrenderer.hpp>
#include <mm/gtk/scrollable.hpp>
#include <mm/gtk/editable.hpp>
#include <mm/gtk/tooltip.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeView = struct _GtkTreeView;
using GtkTreeViewClass = struct _GtkTreeViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class ContentFormats;
}

namespace Gtk
{


#ifndef DOXYGEN_SHOULD_SKIP_THIS

class TreeView;

namespace TreeView_Private
{
/* This helper function is not a member of TreeView just for the reason that
 * there are compilers that have problems compiling it otherwise. E.g. in gcc
 * 2.95.3 a compiler bug prevents member functions from refering to specialized
 * member function templates and that's what we do here: In function
 * _connect_auto_store_editable_signal_handler we build a slot from
 * TreeView::_auto_store_on_cellrenderer_*_edited. (The latter must be member
 * functions of TreeView since we connect them to signals and we want the
 * connections to vanish when the TreeView dies, of course.)
 */
  template <class ColumnType>
  void _connect_auto_store_editable_signal_handler(Gtk::TreeView* this_p, Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<ColumnType>& model_column);

  template <class ColumnType> inline
  void _connect_auto_store_numeric_editable_signal_handler(Gtk::TreeView* this_p, Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<ColumnType>& model_column);

  template<class ColumnType> inline
  void _auto_store_on_cellrenderer_text_edited_string(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);

  template <class ColumnType> inline
  void _auto_store_on_cellrenderer_text_edited_numerical(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);

  template <class ColumnType> inline
  void _auto_cell_data_func(Gtk::CellRenderer* cell, const Gtk::TreeModel::const_iterator& iter, int model_column, const Glib::ustring& format);

  template <typename T>
  auto _convert_from_ustring_to_numeric_type(const Glib::ustring& text) -> T;
}

#endif //DOXYGEN_SHOULD_SKIP_THIS


//class TreeViewColumn;
class TreeModel;

/** @defgroup TreeView TreeView Classes
 * These classes are used with the Gtk::TreeView widget.
 */

/** The TreeView widget displays the model (Gtk::TreeModel) data and allows the user to interact with it.
 * The View can show all of the model's columns, or just some, and it can show them in various ways.
 * You must provide the TreeModel in the constructor, or with set_model().
 *
 * Add View columns with append_column(), append_column_editable(), append_column_numeric(),
 * append_column_numeric_editable(), insert_column(), or insert_column_editable().
 *
 * You can manipulate the selection by obtaining the @link Gtk::TreeSelection Gtk::TreeView::Selection@endlink from get_selection().
 *
 * @ingroup Widgets
 * @ingroup Containers
 * @ingroup TreeView
 */

class GTKMM_API TreeView
 : public Widget,
   public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TreeView CppObjectType;
  typedef TreeView_Class CppClassType;
  typedef GtkTreeView BaseObjectType;
  typedef GtkTreeViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TreeView(TreeView&& src) noexcept;
  auto operator=(TreeView&& src) noexcept -> TreeView&;

  // noncopyable
  TreeView(const TreeView&) = delete;
  auto operator=(const TreeView&) -> TreeView& = delete;

  ~TreeView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class TreeView_Class;
  static CppClassType treeview_class_;

protected:
  explicit TreeView(const Glib::ConstructParams& construct_params);
  explicit TreeView(GtkTreeView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeView*       { return reinterpret_cast<GtkTreeView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeView* { return reinterpret_cast<GtkTreeView*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var DropPosition BEFORE
   * Dropped row is inserted before.
   *
   *  @var DropPosition AFTER
   * Dropped row is inserted after.
   *
   *  @var DropPosition INTO_OR_BEFORE
   * Dropped row becomes a child or is inserted before.
   *
   *  @var DropPosition INTO_OR_AFTER
   * Dropped row becomes a child or is inserted after.
   *
   *  @enum DropPosition
   *
   * An enum for determining where a dropped row goes.
   *
   * @ingroup gtkmmEnums
   */
  enum class DropPosition
  {
    BEFORE,
    AFTER,
    INTO_OR_BEFORE,
    INTO_OR_AFTER
  };


  /**
   *  @var GridLines NONE
   * No grid lines.
   *
   *  @var GridLines HORIZONTAL
   * Horizontal grid lines.
   *
   *  @var GridLines VERTICAL
   * Vertical grid lines.
   *
   *  @var GridLines BOTH
   * Horizontal and vertical grid lines.
   *
   *  @enum GridLines
   *
   * Used to indicate which grid lines to draw in a tree view.
   *
   * @ingroup gtkmmEnums
   */
  enum class GridLines
  {
    NONE,
    HORIZONTAL,
    VERTICAL,
    BOTH
  };


  /**  A visible column in a Gtk::TreeView widget.
   */
  typedef TreeViewColumn Column;

  /** A selection object for Gtk::TreeView.
   */
  typedef TreeSelection Selection;

  /** Default constructor.
   */
  TreeView();

  /**
     Constructor that binds to a TreeModel.
   */
    explicit TreeView(const Glib::RefPtr<TreeModel>& model);


  /** Returns the model the `Gtk::TreeView` is based on.  Returns <tt>nullptr</tt> if the
   * model is unset.
   *
   * @return A `Gtk::TreeModel`.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the model the `Gtk::TreeView` is based on.  Returns <tt>nullptr</tt> if the
   * model is unset.
   *
   * @return A `Gtk::TreeModel`.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;

  /** Sets the model for a Gtk::TreeView.  If the @a tree_view already has a model
   * set, it will remove it before setting the new model. Use unset_model() to
   * unset the old model.
   *
   * @param model The model.
   */
  void set_model(const Glib::RefPtr<TreeModel>& model);

  /** Remove the model from the TreeView.
   *
   * @see set_model().
   *
   * @newin{2,8}
   */
  void unset_model();


  /** Gets the `Gtk::TreeSelection` associated with @a tree_view.
   *
   * @return A `Gtk::TreeSelection` object.
   */
  auto get_selection() -> Glib::RefPtr<TreeSelection>;

  /** Gets the `Gtk::TreeSelection` associated with @a tree_view.
   *
   * @return A `Gtk::TreeSelection` object.
   */
  auto get_selection() const -> Glib::RefPtr<const TreeSelection>;


  /** Returns <tt>true</tt> if the headers on the @a tree_view are visible.
   *
   * @return Whether the headers are visible or not.
   */
  auto get_headers_visible() const -> bool;

  /** Sets the visibility state of the headers.
   *
   * @param headers_visible <tt>true</tt> if the headers are visible.
   */
  void set_headers_visible(bool headers_visible =  true);

  /** Resizes all columns to their optimal width. Only works after the
   * treeview has been realized.
   */
  void columns_autosize();

  /** Returns whether all header columns are clickable.
   *
   * @return <tt>true</tt> if all header columns are clickable, otherwise <tt>false</tt>.
   */
  auto get_headers_clickable() const -> bool;

  /** Allow the column title buttons to be clicked.
   *
   * @param setting <tt>true</tt> if the columns are clickable.
   */
  void set_headers_clickable(bool setting =  true);


  /** Cause the `Gtk::TreeView`::row-activated signal to be emitted
   * on a single click instead of a double click.
   *
   * @param single <tt>true</tt> to emit row-activated on a single click.
   */
  void set_activate_on_single_click(bool single =  true);

  /** Gets the setting set by set_activate_on_single_click().
   *
   * @return <tt>true</tt> if row-activated will be emitted on a single click.
   */
  auto get_activate_on_single_click() const -> bool;


  /** Appends @a column to the list of columns. If @a tree_view has “fixed_height”
   * mode enabled, then @a column must have its “sizing” property set to be
   * GTK_TREE_VIEW_COLUMN_FIXED.
   *
   * @param column The `Gtk::TreeViewColumn` to add.
   * @return The number of columns in @a tree_view after appending.
   */
  auto append_column(TreeViewColumn& column) -> int;

  /** Appends a View column with the appropriate CellRenderer for the Model column.
   *
   * The CellRenderer can only be created automatically for some basic
   * column types, such as Glib::ustring, int, double, bool, and Gdk::Pixbuf.
   * If the type is not supported then the following warning will be shown:
   * GLib-GObject-WARNING **: unable to set property `text' of type
   * `gchararray' from value of type `glibmm__CustomBoxed_t'.
   *
   * If the default formatting is not sufficient, or the numeric type is
   * not supported, then you could use append_column_numeric(). Or you
   * could create the TreeView::Column and/or CellRenderer
   * manually and use TreeViewColumn::set_cell_data_func() to provide a callback
   * that converts the model value into a string representation with .
   *
   * The returned value is useful, for example, for connecting the column renderer signal to
   * a slot:
   * @code
   *    int Ncolumns = mTreeView.append_column("Column Title", mColumns.mName);
   *    auto renderer =
   *      dynamic_cast<Gtk::CellRendererText*>(mTreeView.get_column_cell_renderer(Ncolumns-1));
   *    renderer->signal_edited().connect(sigc::mem_fun(*this, &MyWindow::on_name_edited));
   * @endcode
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @result The number of columns in the View after appending.
   */
  template <class ColumnType> inline
  auto append_column(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column) -> int;

  /** Like append_column(), but only for numeric types, which will be displayed in the specified format.
   * This convenience template uses TreeView::Column::set_cell_data_func(), so the numeric formatting will
   * be deactivated if you specify your own cell_data callback by calling set_cell_data_func() again.
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @param format A printf-style format, such as "%d", used to create a text representation of the number.
   * @result The number of columns in the View after appending.
   */
  template <class ColumnType> inline
  auto append_column_numeric(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, const Glib::ustring& format) -> int;

  //TODO: danielk suggested use of Glib::Value to simplify/improve this.
  /** Appends a View column with the appropriate CellRenderer for the Model
   * column.  The compiler will attempt to instantiate appropriate template
   * code to automatically store user changes in the model.  To intercept the
   * user's change and implement non-default logic, or if the compiler can't
   * instantiate appropriate code for your model type, you could use
   * append_column() and connect a signal handler to the CellRenderer.
   *
   * @see append_column_numeric_editable().
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @result The number of columns in the View after appending.
   */
  template <class ColumnType> inline
  auto append_column_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column) -> int;

  /** Like append_column_editable(), but only for numeric types, which will be displayed in the specified format.
   * This convenience template uses TreeView::Column::set_cell_data_func(), so the numeric formatting will
   * be deactivated if you specify your own cell_data callback by calling set_cell_data_func() again.
   *
   * Note that the @a format does not influence the interpretation of the user's input.
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @param format A printf-style format, such as "%d", used to create a text representation of the number.
   * @result The number of columns in the View after appending.
   */
  template <class ColumnType> inline
  auto append_column_numeric_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, const Glib::ustring& format) -> int;


  /// Creates a View column containing the CellRenderer, and appends it.
  auto append_column(const Glib::ustring& title, CellRenderer& cell) -> int;


  /** Removes @a column from @a tree_view.
   *
   * @param column The `Gtk::TreeViewColumn` to remove.
   * @return The number of columns in @a tree_view after removing.
   */
  auto remove_column(TreeViewColumn& column) -> int;

  /// Removes all View columns.
  void remove_all_columns();


  /** This inserts the @a column into the @a tree_view at @a position.  If @a position is
   * -1, then the column is inserted at the end. If @a tree_view has
   * “fixed_height” mode enabled, then @a column must have its “sizing” property
   * set to be GTK_TREE_VIEW_COLUMN_FIXED.
   *
   * @param column The `Gtk::TreeViewColumn` to be inserted.
   * @param position The position to insert @a column in.
   * @return The number of columns in @a tree_view after insertion.
   */
  auto insert_column(TreeViewColumn& column, int position) -> int;

  /** Creates a View column containing the CellRenderer, and inserts it.
   *
   * @param title The text to be used in the title header of this column.
   * @param cell The CellRenderer.
   * @param position The position at which the CellRenderer should be inserted.
   * @result The number of columns in the View after inserting.
   */
  auto insert_column(const Glib::ustring& title, CellRenderer& cell, int position) -> int;


  /** Inserts a View column with the appropriate CellRenderer for the Model column.
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @param position The position at which the CellRenderer should be inserted.
   * @result The number of columns in the View after inserting.
   */
  template <class ColumnType> inline
  auto insert_column(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, int position) -> int;

  /** Inserts a View column with the appropriate CellRenderer for the Model
   * column.  The compiler will attempt to instantiate appropriate template
   * code to automatically store user changes in the model.  To intercept the
   * user's change and implement non-default logic, or if the compiler can't
   * instantiate appropriate code for your model type, you should use
   * insert_column() and connect a signal handler to the CellRenderer.
   *
   * @param title The text to be used in the title header of this column.
   * @param model_column The column in the TreeModel that will be rendered by this View column.
   * @param position The position at which the CellRenderer should be inserted.
   * @result The number of columns in the View after inserting.
   */
  template <class ColumnType> inline
  auto insert_column_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, int position) -> int;

  typedef TreeViewColumn::SlotTreeCellData SlotTreeCellData;

  /**
   * Inserts a new column into the TreeView with the given cell
   * renderer and a SlotTreeCellData to set cell renderer attributes
   * (normally using data from the model).
   *
   * @param position Position to insert, -1 for append
   * @param title column title
   * @param cell cell renderer for column
   * @param slot function to set attributes of cell renderer
   * @return number of columns in the TreeView after the insert
   */
  auto insert_column_with_data_func(int position, const Glib::ustring& title, CellRenderer& cell, const SlotTreeCellData& slot) -> int;


  /** Queries the number of columns in the given @a tree_view.
   *
   * @return The number of columns in the @a tree_view.
   */
  auto get_n_columns() const -> guint;


  /** Gets the `Gtk::TreeViewColumn` at the given position in the #tree_view.
   *
   * @param n The position of the column, counting from 0.
   * @return The `Gtk::TreeViewColumn`, or <tt>nullptr</tt> if the
   * position is outside the range of columns.
   */
  auto get_column(int n) -> TreeViewColumn*;

  /** Gets the `Gtk::TreeViewColumn` at the given position in the #tree_view.
   *
   * @param n The position of the column, counting from 0.
   * @return The `Gtk::TreeViewColumn`, or <tt>nullptr</tt> if the
   * position is outside the range of columns.
   */
  auto get_column(int n) const -> const TreeViewColumn*;

  //The column index is of the view, not the model, so we do not need TreeViewColumn* get_column(TreeViewColumn& base_column).

  /** Gets the CellRenderer for that column.
    * You should dynamic_cast<> to the expected derived CellRenderer type.
    * This assumes that the TreeViewColumn contains only one CellRenderer.
    *
    * @param n The position of the view column.
    * @result The CellRenderer.
    */
  auto get_column_cell_renderer(int n) -> CellRenderer*;

 //TODO: Add TreeViewColumn* get_column_cell_renderer(TreeViewColumn& base_column); and a const one.


  /** Gets the CellRenderer for that column.
    * You should dynamic_cast<> to the expected derived CellRenderer type.
    * This assumes that the TreeViewColumn contains only one CellRenderer.
    *
    * @param n The position of the view column.
    * @result The CellRenderer.
    */
  auto get_column_cell_renderer(int n) const -> const CellRenderer*;


  /** Returns a list of all the Gtk::TreeViewColumn s currently in @a tree_view.
   *
   * @return A list of `Gtk::TreeViewColumn`s.
   */
  auto get_columns() -> std::vector<TreeViewColumn*>;


  /** Returns a list of all the Gtk::TreeViewColumn s currently in @a tree_view.
   *
   * @return A list of `Gtk::TreeViewColumn`s.
   */
  auto get_columns() const -> std::vector<const TreeViewColumn*>;


  /** Moves @a column to be after to @a base_column.  See also move_column_to_start().
   *
   * @param column The Gtk::TreeViewColumn to be moved.
   * @param base_column The Gtk::TreeViewColumn to be moved relative to.
   */
  void move_column_after(TreeViewColumn& column, TreeViewColumn& base_column);

  /** This method moves column to the first position in the view.
   *
   * @param column The view column that will be moved
   */
  void move_column_to_start(TreeViewColumn& column);


  /** Sets the column to draw the expander arrow at. It must be in the TreeView.  See also reset_expander_column().
   *
   * @param column The column to draw the expander arrow at.
   */
  void set_expander_column(TreeViewColumn& column);

  /** This method resets the expander arrow to the default - the first visible column.
   * @see set_expander_column().
   */
  void reset_expander_column();


  /** Returns the column that is the current expander column,
   * or <tt>nullptr</tt> if none has been set.
   * This column has the expander arrow drawn next to it.
   *
   * @return The expander column.
   */
  auto get_expander_column() -> TreeViewColumn*;

  /** Returns the column that is the current expander column,
   * or <tt>nullptr</tt> if none has been set.
   * This column has the expander arrow drawn next to it.
   *
   * @return The expander column.
   */
  auto get_expander_column() const -> const TreeViewColumn*;

  /** For instance,
   * bool on_column_drop(TreeView*, tree_view, TreeViewColumn* column, TreeViewColumn* prev_column, TreeViewColumn* next_column)
   *
   * This function is called on every column pair in turn at the beginning of a column drag to determine where a
   * drop can take place. The arguments passed to the function are: the tree_view, the view Column being dragged,
   * and the two view Columns determining the drop spot. If either of the view Column arguments for the drop spot
   * are 0, then they indicate an edge.
   */
  typedef sigc::slot<bool(TreeView*, TreeViewColumn*,  TreeViewColumn*, TreeViewColumn*)> SlotColumnDrop;

  /** Sets a callback slot for determining where a column may be dropped when dragged.
   * This function is called on every column pair in turn at the beginning of a column drag to determine where a
   * drop can take place. The arguments passed to the function are: the tree_view, the view Column being dragged,
   * and the two view Columns determining the drop spot. If either of the view Column arguments for the drop spot
   * are 0, then they indicate an edge.
   *
   * See unset_column_drag_function().
   *
   * @param slot A callback function to determine which columns are reorderable.
   */
  void set_column_drag_function(const SlotColumnDrop& slot);


  /** See set_column_drag_function(). After this method has been called, the TreeView reverts to the default behavior of
  * allowing all columns to be dropped everywhere.
  */
  void unset_column_drag_function();


  /** Scrolls the tree view such that the top-left corner of the visible
   * area is @a tree_x, @a tree_y, where @a tree_x and @a tree_y are specified
   * in tree coordinates.  The @a tree_view must be realized before
   * this function is called.  If it isn't, you probably want to be
   * using scroll_to_cell().
   *
   * If either @a tree_x or @a tree_y are -1, then that direction isn’t scrolled.
   *
   * @param tree_x X coordinate of new top-left pixel of visible area, or -1.
   * @param tree_y Y coordinate of new top-left pixel of visible area, or -1.
   */
  void scroll_to_point(int tree_x, int tree_y);

  /** Moves the alignments of tree view to the position specified by @a column and @a path.
   * @a row_align determines where the row is placed, and @a col_align determines where
   * column is placed. Both are expected to be between 0.0 and 1.0. 0.0 means left/top
   * alignment, 1.0 means right/bottom alignment, 0.5 means center.
   *
   * This function only works if the model is set, and @a path is a valid row on the model.
   * If the model changes before the tree view is realized, the centered path will be
   * modified to reflect this change.
   *
   * @param path The path of the row to move to.
   * @param column The Gtk::TreeViewColumn to move horizontally to.
   * @param row_align The vertical alignment of the row specified by @a path.
   * @param col_align The horizontal alignment of the column specified by @a column.
   */
  void scroll_to_cell(const TreeModel::Path& path, TreeViewColumn& column, float row_align, float col_align);


  /** Moves the alignments of tree view to the position specified by @a column and @a path.
   * The tree does the minimum amount of work to scroll the cell onto the screen. This means
   * that the cell will be scrolled to the edge closest to it's current position. If the cell
   * is currently visible on the screen, nothing is done.
   *
   * This function only works if the model is set, and @a path is a valid row on the model.
   * If the model changes before the tree_view is realized, the centered path will be modified
   * to reflect this change.
   *
   * @param path The path of the row to move to.
   * @param column The Gtk::TreeViewColumn to move horizontally to.
   */
  void scroll_to_cell(const TreeModel::Path& path, TreeViewColumn& column);

  /** Moves the alignments of tree view to the position specified by @a path.
   * @a row_align determines where the row is placed, and is expected to be between 0.0
   * and 1.0.  0.0 means top alignment, 1.0 means bottom alignment, 0.5 means center.
   *
   * This function only works if the model is set, and @a path is a valid row on the model.
   * If the model changes before the tree view is realized, the centered path will be
   * modified to reflect this change.
   *
   * @param path The path of the row to move to.
   * @param row_align The vertical alignment of the row specified by @a path.
   */
  void scroll_to_row(const TreeModel::Path& path, float row_align);

  /** Moves the alignments of tree view to the position specified by @a path.
   * The tree does the minimum amount of work to scroll the row onto the screen. This means
   * that the row will be scrolled to the edge closest to it's current position. If the row
   * is currently visible on the screen, nothing is done.
   *
   * This function only works if the model is set, and @a path is a valid row on the model.
   * If the model changes before the tree view is realized, the centered path will be
   * modified to reflect this change.
   *
   * @param path The path of the row to move to.
   */
  void scroll_to_row(const TreeModel::Path& path);

  /** Moves the alignments of tree view to the position specified by @a column.
   * @a col_align determines where the column is placed, and is expected to be between 0.0
   * and 1.0.  0.0 means left alignment, 1.0 means right alignment, 0.5 means center.
   *
   * This function only works if the model is set.  If the model changes before the tree
   * view is realized, the centered path will be modified to reflect this change.
   *
   * @param column The Gtk::TreeViewColumn to move horizontally to.
   * @param col_align The horizontal alignment of the column specified by @a column.
   */
  void scroll_to_column(TreeViewColumn& column, float col_align);

  /** Moves the alignments of tree view to the position specified by @a column.
   * The tree does the minimum amount of work to scroll the column onto the screen. This means
   * that the column will be scrolled to the edge closest to it's current position. If the column
   * is currently visible on the screen, nothing is done.
   *
   * This function only works if the model is set.  If the model changes before the
   * tree view is realized, the centered path will be modified to reflect this change.
   *
   * @param column The Gtk::TreeViewColumn to move horizontally to.
   */
  void scroll_to_column(TreeViewColumn& column);


  /** Activates the cell determined by @a path and @a column.
   *
   * @param path The `Gtk::TreePath` to be activated.
   * @param column The `Gtk::TreeViewColumn` to be activated.
   */
  void row_activated(const TreeModel::Path& path, TreeViewColumn& column);

  /** Recursively expands all nodes in the @a tree_view.
   */
  void expand_all();

  /** Recursively collapses all visible, expanded nodes in @a tree_view.
   */
  void collapse_all();

  /** Expands the row at @a path. This will also expand all parent rows of
   *  @a path as necessary.
   *
   * @param path Path to a row.
   */
  void expand_to_path(const TreeModel::Path& path);

  /** Opens the row so its children are visible.
   *
   * @param path Path to a row.
   * @param open_all Whether to recursively expand, or just expand immediate children.
   * @return <tt>true</tt> if the row existed and had children.
   */
  auto expand_row(const TreeModel::Path& path, bool open_all) -> bool;

  /** Collapses a row (hides its child rows, if they exist).
   *
   * @param path Path to a row in the @a tree_view.
   * @return <tt>true</tt> if the row was collapsed.
   */
  auto collapse_row(const TreeModel::Path& path) -> bool;

  /** For example,
   * void on_map_expanded_rows(TreeView* tree_view, const TreeModel::Path& path);
   */
  typedef sigc::slot<void(TreeView*, const TreeModel::Path&)> SlotMapping;

  /** Calls the callback slot on all expanded rows.
   * @param slot A callback function to be called.
   */
  void map_expanded_rows(const SlotMapping& slot);


  /** Returns <tt>true</tt> if the node pointed to by @a path is expanded in @a tree_view.
   *
   * @param path A `Gtk::TreePath` to test expansion state.
   * @return <tt>true</tt> if #path is expanded.
   */
  auto row_expanded(const TreeModel::Path& path) -> bool;

  /** This function is a convenience function to allow you to reorder
   * models that support the `Gtk::TreeDragSourceIface` and the
   * `Gtk::TreeDragDestIface`.  Both `Gtk::TreeStore` and `Gtk::ListStore` support
   * these.  If @a reorderable is <tt>true</tt>, then the user can reorder the
   * model by dragging and dropping rows. The developer can listen to
   * these changes by connecting to the model’s `GtkTreeModel::row-inserted`
   * and `GtkTreeModel::row-deleted` signals. The reordering is implemented
   * by setting up the tree view as a drag source and destination.
   * Therefore, drag and drop can not be used in a reorderable view for any
   * other purpose.
   *
   * This function does not give you any degree of control over the order -- any
   * reordering is allowed.  If more control is needed, you should probably
   * handle drag and drop manually.
   *
   * @param reorderable <tt>true</tt>, if the tree can be reordered.
   */
  void set_reorderable(bool reorderable =  true);

  /** Retrieves whether the user can reorder the tree via drag-and-drop. See
   * set_reorderable().
   *
   * @return <tt>true</tt> if the tree can be reordered.
   */
  auto get_reorderable() const -> bool;

  //TODO: Add set_cursor(path, ModelColumnBase&, start_editing)?

  /** Sets the current keyboard focus to be at @a path, and selects it.  This is
   * useful when you want to focus the user's attention on a particular row. Focus is given to the column specified.
   * Additionally, if @a start_editing is
   * <tt>true</tt>, then editing should be started in the specified cell.
   * This function is often followed by Gtk::Widget::grab_focus( @a tree_view)
   * in order to give keyboard focus to the widget.  Please note that editing
   * can only happen when the widget is realized.
   *
   * @param path A Gtk::TreePath.
   * @param focus_column A Gtk::TreeViewColumn.
   * @param start_editing <tt>true</tt> if the specified cell should start being edited.
   */
  void set_cursor(const TreeModel::Path& path, TreeViewColumn& focus_column, bool start_editing =  false);


  /** Sets the current keyboard focus to be at @a path, and selects it.  This is
   * useful when you want to focus the user’s attention on a particular row.  If
   *  @a focus_column is not <tt>nullptr</tt>, then focus is given to the column specified by
   * it. If @a focus_column and @a focus_cell are not <tt>nullptr</tt>, and @a focus_column
   * contains 2 or more editable or activatable cells, then focus is given to
   * the cell specified by @a focus_cell. Additionally, if @a focus_column is
   * specified, and @a start_editing is <tt>true</tt>, then editing should be started in
   * the specified cell.  This function is often followed by
   *  @a gtk_widget_grab_focus ( @a tree_view) in order to give keyboard focus to the
   * widget.  Please note that editing can only happen when the widget is
   * realized.
   *
   * If @a path is invalid for @a model, the current cursor (if any) will be unset
   * and the function will return without failing.
   *
   * @param path A `Gtk::TreePath`.
   * @param focus_column A `Gtk::TreeViewColumn`.
   * @param focus_cell A `Gtk::CellRenderer`.
   * @param start_editing <tt>true</tt> if the specified cell should start being edited.
   */
  void set_cursor(const TreeModel::Path& path, TreeViewColumn& focus_column, CellRenderer& focus_cell, bool start_editing =  false);


  /** Sets the current keyboard focus to be at path , and selects it.
   * This is useful when you want to focus the user's attention on a particular row.
   * This function is often followed by Gtk::widget::grab_focus(tree_view)
   * in order to give keyboard focus to the widget.
   *
   *  @param path A reference to cursor path.
   */
  void set_cursor(const TreeModel::Path& path);

  /**  Fills in path and focus_column with the current path and focus column.
   *
   *  @param path A reference to be filled with the current cursor path
   *  @param focus_column A reference to be filled with the current focus column
   */
  void get_cursor(TreeModel::Path& path, TreeViewColumn*& focus_column);

/* Layout information */
  /** Finds the path at the point (@a x, @a y), relative to bin_window coordinates.
   *
   * That is, @a x and @a y are relative to an events coordinates. Widget-relative
   * coordinates must be converted using
   * convert_widget_to_bin_window_coords(). It is primarily for
   * things like popup menus. @a path will be filled
   * with the TreeModel::Path at that point. @a column will be filled
   * with the column at that point.  @a cell_x and @a cell_y return the coordinates
   * relative to the cell background (i.e. the background_area passed to
   * Gtk::CellRenderer::render()).  This method is only meaningful if
   * the TreeView is realized.
   *
   * For converting widget coordinates (eg. the ones you get from
   * Widget::property_query_tooltip()), please see
   * convert_widget_to_bin_window_coords().
   *
   * @param x The x position to be identified (relative to bin_window).
   * @param y The y position to be identified (relative to bin_window).
   * @param[out] path A reference to a TreeModel::Path to be filled in
   * @param[out] column A reference to a TreeViewColumn pointer to be filled in
   * @param[out] cell_x A reference where the X coordinate relative to the cell
   *   can be placed
   * @param[out] cell_y A reference where the Y coordinate relative to the cell
   *   can be placed
   * @return true if a row exists at that coordinate.
   *
   * @newin{2,8}
   */
  auto get_path_at_pos(int x, int y, TreeModel::Path& path, TreeViewColumn*& column, int& cell_x, int& cell_y) const -> bool;

  /** Finds the path at the point (@a x, @a y), relative to bin_window coordinates.
   *
   * That is, @a x and @a y are relative to an events coordinates. Widget-relative
   * coordinates must be converted using
   * convert_widget_to_bin_window_coords(). It is primarily for
   * things like popup menus. @a path will be filled
   * with the TreeModel::Path at that point.
   * This method is only meaningful if the TreeView is realized.
   *
   * For converting widget coordinates (eg. the ones you get from
   * Widget::property_query_tooltip()), please see
   * convert_widget_to_bin_window_coords().
   *
   * @param x The x position to be identified (relative to bin_window).
   * @param y The y position to be identified (relative to bin_window).
   * @param path A reference to a TreeModel::Path to be filled in
   * @return true if a row exists at that coordinate.
   *
   * newin{2,16}
   */
  auto get_path_at_pos(int x, int y, TreeModel::Path& path) const -> bool;

  //We ignore the fact that one of the arguments can be 0 - it does not seem useful.

  /** Fills the bounding rectangle in tree window coordinates for the cell at the
   * row specified by @a path and the column specified by @a column.  If @a path points to a path not currently displayed, the @a y and @a height fields
   * of the rectangle will be filled with 0.  The sum of all cell rects does not cover the
   * entire tree; there are extra pixels in between rows, for example. The
   * returned rectangle is equivalent to the @a cell_area passed to
   * gtk_cell_renderer_render().  This function is only valid if #tree_view is
   * realized.
   *
   * @param path A Gtk::TreePath for the row.
   * @param column A Gtk::TreeViewColumn for the column.
   * @param rect Rectangle to fill with cell rect.
   */
  void get_cell_area(const TreeModel::Path& path, TreeViewColumn& column, Gdk::Rectangle& rect) const;


  /** Fills the bounding rectangle in tree window coordinates for the cell at the
   * row specified by @a path and the column specified by @a column.  The returned rectangle is equivalent to the
   *  @a background_area passed to gtk_cell_renderer_render().  These background
   * areas tile to cover the entire tree window (except for the area used for
   * header buttons). Contrast with the @a cell_area, returned by
   * get_cell_area(), which returns only the cell itself, excluding
   * surrounding borders and the tree expander area.
   *
   * @param path A Gtk::TreePath for the row.
   * @param column A Gtk::TreeViewColumn for the column.
   * @param rect Rectangle to fill with cell background rect.
   */
  void get_background_area(const TreeModel::Path& path, TreeViewColumn& column, Gdk::Rectangle& rect) const;
  //We ignore the fact that one of the arguments can be 0 - it does not seem useful.


  /** Fills @a visible_rect with the currently-visible region of the
   * buffer, in tree coordinates. Convert to bin_window coordinates with
   * convert_tree_to_bin_window_coords().
   * Tree coordinates start at 0,0 for row 0 of the tree, and cover the entire
   * scrollable area of the tree.
   *
   * @param visible_rect Rectangle to fill.
   */
  void get_visible_rect(Gdk::Rectangle& visible_rect) const;

   auto get_visible_range(TreeModel::Path& start_path, TreeModel::Path& end_path) const -> bool;


  /** Determine whether the point (@a x, @a y) in the tree view is blank, that is no
   * cell content nor an expander arrow is drawn at the location.
   *
   * If so, the location can be considered as the background. You might wish to take
   * special action on clicks on the background, such as clearing a current
   * selection, having a custom context menu or starting rubber banding.
   *
   * The @a x and @a y coordinates that are provided must be relative to bin_window
   * coordinates.  Widget-relative coordinates must be converted using
   * convert_widget_to_bin_window_coords().
   *
   * For converting widget coordinates (eg. the ones you get from
   * Gtk::Widget::signal_query_tooltip()), please see
   * convert_widget_to_bin_window_coords().
   *
   * The @a path, @a column, @a cell_x and @a cell_y arguments will be filled in
   * likewise as for get_path_at_pos(). Please see get_path_at_pos() for more information.
   *
   * @param x The x position to be identified (relative to bin_window).
   * @param y The y position to be identified (relative to bin_window).
   * @param[out] path A reference to a Gtk::TreePath to be filled in.
   * @param[out] column A reference to a Gtk::TreeViewColumn pointer to be filled in.
   * @param[out] cell_x A reference where the X coordinate relative to the
   *             cell can be placed.
   * @param[out] cell_y A reference where the Y coordinate relative to the
   *             cell can be placed.
   * @return <tt>true</tt> if the area at the given coordinates is blank,
   * <tt>false</tt> otherwise.
   */
  auto is_blank_at_pos(int x, int y, TreePath& path, TreeViewColumn*& column, int& cell_x, int& cell_y) const -> bool;


  /** Determine whether the point (@a x, @a y) in the tree view is blank, that is no
   * cell content nor an expander arrow is drawn at the location.
   *
   * If so, the location can be considered as the background. You might wish to take
   * special action on clicks on the background, such as clearing a current
   * selection, having a custom context menu or starting rubber banding.
   *
   * The @a x and @a y coordinates that are provided must be relative to bin_window
   * coordinates.  Widget-relative coordinates must be converted using
   * convert_widget_to_bin_window_coords().
   *
   * For converting widget coordinates (eg. the ones you get from
   * Gtk::Widget::signal_query_tooltip()), please see
   * convert_widget_to_bin_window_coords().
   *
   * @param x The x position to be identified (relative to bin_window).
   * @param y The y position to be identified (relative to bin_window).
   * @return <tt>true</tt> if the area at the given coordinates is blank,
   * <tt>false</tt> otherwise.
   */
  auto is_blank_at_pos(int x, int y) const -> bool;


/* Drag-and-Drop support */
  // Gdk::ContentFormats is an immutable object. It can be declared const
  // in input parameters. No one can change it.


  /** Turns @a tree_view into a drag source for automatic DND. Calling this
   * method sets `Gtk::TreeView`:reorderable to <tt>false</tt>.
   *
   * @param start_button_mask Mask of allowed buttons to start drag.
   * @param formats The target formats that the drag will support.
   * @param actions The bitmask of possible actions for a drag from this
   * widget.
   */
  void enable_model_drag_source(const Glib::RefPtr<const Gdk::ContentFormats>& formats, Gdk::ModifierType start_button_mask =  static_cast<Gdk::ModifierType>(GDK_MODIFIER_MASK), Gdk::DragAction actions =  Gdk::DragAction::COPY | Gdk::DragAction::MOVE);

  /** Turns the %TreeView into a drag source for automatic DND.
   *
   * Calling this method sets property_reorderable() to <tt>false</tt>.
   * Uses the GTK_TYPE_TREE_ROW_DATA GType target, which the %TreeView can handle automatically.
   *
   * @param start_button_mask Mask of allowed buttons to start drag.
   * @param actions The bitmask of possible actions for a drag from this widget.
   */
  void enable_model_drag_source(Gdk::ModifierType start_button_mask = static_cast<Gdk::ModifierType>(GDK_MODIFIER_MASK),
                                Gdk::DragAction actions = Gdk::DragAction::COPY | Gdk::DragAction::MOVE);


  /** Turns @a tree_view into a drop destination for automatic DND. Calling
   * this method sets `Gtk::TreeView`:reorderable to <tt>false</tt>.
   *
   * @param formats The target formats that the drag will support.
   * @param actions The bitmask of possible actions for a drag from this
   * widget.
   */
  void enable_model_drag_dest(const Glib::RefPtr<const Gdk::ContentFormats>& formats, Gdk::DragAction actions =  Gdk::DragAction::COPY | Gdk::DragAction::MOVE);

  /** Turns the %TreeView into a drop destination for automatic DND.
   *
   * Calling this method sets property_reorderable() to <tt>false</tt>.
   * Uses the GTK_TYPE_TREE_ROW_DATA GType target, which the %TreeView can handle automatically.
   *
   * @param actions The bitmask of possible actions for a drag to this widget.
   */
  void enable_model_drag_dest(Gdk::DragAction actions = Gdk::DragAction::COPY | Gdk::DragAction::MOVE);


  /** Undoes the effect of enable_model_drag_source()
   */
  void unset_rows_drag_source();


  /** Undoes the effect of enable_model_drag_dest()
   */
  void unset_rows_drag_dest();


  /* These are useful to implement your own custom stuff. */


  /** Sets the row that is highlighted for feedback.
   * See also unset_drag_dest_row().
   *
   * @param path The path of the row to highlight
   * @param pos Specifies whether to drop before, after or into the row
   */
  void set_drag_dest_row(const TreeModel::Path& path, DropPosition pos);

  /** Remove an existing highlight.
   * See set_drag_dest_row().
   *
   * @newin{3,2}
   */
  void unset_drag_dest_row();

  /** Gets information about the row that is highlighted for feedback.
   *
   * @param path Return location for the path of the highlighted row
   * @param pos Return location for the drop position
   */
  void get_drag_dest_row(TreeModel::Path& path, DropPosition& pos) const;

  /** Determines the destination row for a given position.
   *
   * @param drag_x The x position to determine the destination row for
   * @param drag_y The y position to determine the destination row for
   * @param path Return location for the path of the highlighted row
   * @param pos Return location for the drop position
   */
  auto get_dest_row_at_pos(int drag_x, int drag_y, TreeModel::Path& path, DropPosition& pos) const -> bool;


  /** Creates a `cairo_surface_t` representation of the row at @a path.
   * This image is used for a drag icon.
   *
   * @param path A `Gtk::TreePath` in @a tree_view.
   * @return A newly-allocated surface of the drag icon.
   */
  auto create_row_drag_icon(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::Paintable>;

/* Interactive search */

  /** If @a enable_search is set, then the user can type in text to search through
   * the tree interactively (this is sometimes called "typeahead find").
   *
   * Note that even if this is <tt>false</tt>, the user can still initiate a search
   * using the “start-interactive-search” key binding.
   *
   * @param enable_search <tt>true</tt>, if the user can search interactively.
   */
  void set_enable_search(bool enable_search =  true);

  /** Returns whether or not the tree allows to start interactive searching
   * by typing in text.
   *
   * @return Whether or not to let the user search interactively.
   */
  auto get_enable_search() const -> bool;

  /** Gets the column searched on by the interactive search code.
   *
   * @return The column the interactive search code searches in.
   */
  auto get_search_column() const -> int;

  /** Sets @a column as the column where the interactive search code should
   * search in for the current model.
   *
   * If the search column is set, users can use the “start-interactive-search”
   * key binding to bring up search popup. The enable-search property controls
   * whether simply typing text will also start an interactive search.
   *
   * Note that @a column refers to a column of the current model. The search
   * column is reset to -1 when the model is changed.
   *
   * @param column The column of the model to search in, or -1 to disable searching.
   */
  void set_search_column(const TreeModelColumnBase& column);

  /** Sets @a column as the column where the interactive search code should
   * search in for the current model.
   *
   * If the search column is set, users can use the “start-interactive-search”
   * key binding to bring up search popup. The enable-search property controls
   * whether simply typing text will also start an interactive search.
   *
   * Note that @a column refers to a column of the current model. The search
   * column is reset to -1 when the model is changed.
   *
   * @param column The column of the model to search in, or -1 to disable searching.
   */
  void set_search_column(int column);

  /// void on_search_equal(const Glib::RefPtr<TreeModel>& model, int column, const Glib::ustring& key, const TreeModel::const_iterator& iter)
  typedef sigc::slot<bool(const Glib::RefPtr<TreeModel>&, int, const Glib::ustring&, const TreeModel::const_iterator&)> SlotSearchEqual;
  //SlotSearchEqual get_search_equal_func();


  /** Sets the compare function for the interactive search capabilities.
   *
   * @param slot The compare function to use during the search
   */
  void set_search_equal_func(const SlotSearchEqual& slot);


  /** Returns the `Gtk::Entry` which is currently in use as interactive search
   * entry for @a tree_view.  In case the built-in entry is being used, <tt>nullptr</tt>
   * will be returned.
   *
   * @return The entry currently in use as search entry.
   */
  auto get_search_entry() -> Editable*;

  /** Returns the `Gtk::Entry` which is currently in use as interactive search
   * entry for @a tree_view.  In case the built-in entry is being used, <tt>nullptr</tt>
   * will be returned.
   *
   * @return The entry currently in use as search entry.
   */
  auto get_search_entry() const -> const Editable*;

  /** Sets the entry which the interactive search code will use for this
   *  @a tree_view.  This is useful when you want to provide a search entry
   * in our interface at all time at a fixed position.  Passing <tt>nullptr</tt> for
   *  @a entry will make the interactive search code use the built-in popup
   * entry again.
   *
   * @param entry The entry the interactive search code of @a tree_view should use.
   */
  void set_search_entry(Editable& entry);


  /** Converts widget coordinates to coordinates for the
   * tree (the full scrollable area of the tree).
   *
   * @param wx X coordinate relative to the widget.
   * @param wy Y coordinate relative to the widget.
   * @param tx Return location for tree X coordinate.
   * @param ty Return location for tree Y coordinate.
   */
  void convert_widget_to_tree_coords(int wx, int wy, int& tx, int& ty) const;

  /** Converts tree coordinates (coordinates in full scrollable area of the tree)
   * to widget coordinates.
   *
   * @param tx X coordinate relative to the tree.
   * @param ty Y coordinate relative to the tree.
   * @param wx Return location for widget X coordinate.
   * @param wy Return location for widget Y coordinate.
   */
  void convert_tree_to_widget_coords(int tx, int ty, int& wx, int& wy) const;

  /** Converts widget coordinates to coordinates for the bin_window.
   *
   * @param wx X coordinate relative to the widget.
   * @param wy Y coordinate relative to the widget.
   * @param bx Return location for bin_window X coordinate.
   * @param by Return location for bin_window Y coordinate.
   */
  void convert_widget_to_bin_window_coords(int wx, int wy, int& bx, int& by) const;

  /** Converts bin_window coordinates to widget relative coordinates.
   *
   * @param bx Bin_window X coordinate.
   * @param by Bin_window Y coordinate.
   * @param wx Return location for widget X coordinate.
   * @param wy Return location for widget Y coordinate.
   */
  void convert_bin_window_to_widget_coords(int bx, int by, int& wx, int& wy) const;

  /** Converts tree coordinates (coordinates in full scrollable area of the tree)
   * to bin_window coordinates.
   *
   * @param tx Tree X coordinate.
   * @param ty Tree Y coordinate.
   * @param bx Return location for X coordinate relative to bin_window.
   * @param by Return location for Y coordinate relative to bin_window.
   */
  void convert_tree_to_bin_window_coords(int tx, int ty, int& bx, int& by) const;

  /** Converts bin_window coordinates to coordinates for the
   * tree (the full scrollable area of the tree).
   *
   * @param bx X coordinate relative to bin_window.
   * @param by Y coordinate relative to bin_window.
   * @param tx Return location for tree X coordinate.
   * @param ty Return location for tree Y coordinate.
   */
  void convert_bin_window_to_tree_coords(int bx, int by, int& tx, int& ty) const;


  /** Enables or disables the fixed height mode of @a tree_view.
   * Fixed height mode speeds up `Gtk::TreeView` by assuming that all
   * rows have the same height.
   * Only enable this option if all rows are the same height and all
   * columns are of type Gtk::TreeViewColumn::Sizing::FIXED.
   *
   * @param enable <tt>true</tt> to enable fixed height mode.
   */
  void set_fixed_height_mode(bool enable =  true);

  /** Returns whether fixed height mode is turned on for @a tree_view.
   *
   * @return <tt>true</tt> if @a tree_view is in fixed height mode.
   */
  auto get_fixed_height_mode() const -> bool;

  /** Enables or disables the hover selection mode of @a tree_view.
   * Hover selection makes the selected row follow the pointer.
   * Currently, this works only for the selection modes
   * Gtk::SelectionMode::SINGLE and Gtk::SelectionMode::BROWSE.
   *
   * @param hover <tt>true</tt> to enable hover selection mode.
   */
  void set_hover_selection(bool hover =  true);

  /** Returns whether hover selection mode is turned on for @a tree_view.
   *
   * @return <tt>true</tt> if @a tree_view is in hover selection mode.
   */
  auto get_hover_selection() const -> bool;

  /** Enables or disables the hover expansion mode of @a tree_view.
   * Hover expansion makes rows expand or collapse if the pointer
   * moves over them.
   *
   * @param expand <tt>true</tt> to enable hover selection mode.
   */
  void set_hover_expand(bool expand =  true);

  /** Returns whether hover expansion mode is turned on for @a tree_view.
   *
   * @return <tt>true</tt> if @a tree_view is in hover expansion mode.
   */
  auto get_hover_expand() const -> bool;

  /** Enables or disables rubber banding in @a tree_view.  If the selection mode
   * is Gtk::SelectionMode::MULTIPLE, rubber banding will allow the user to select
   * multiple rows by dragging the mouse.
   *
   * @param enable <tt>true</tt> to enable rubber banding.
   */
  void set_rubber_banding(bool enable =  true);

  /** Returns whether rubber banding is turned on for @a tree_view.  If the
   * selection mode is Gtk::SelectionMode::MULTIPLE, rubber banding will allow the
   * user to select multiple rows by dragging the mouse.
   *
   * @return <tt>true</tt> if rubber banding in @a tree_view is enabled.
   */
  auto get_rubber_banding() const -> bool;


  /** Returns whether a rubber banding operation is currently being done
   * in @a tree_view.
   *
   * @return <tt>true</tt> if a rubber banding operation is currently being
   * done in @a tree_view.
   */
  auto is_rubber_banding_active() const -> bool;

  /** The slot type for determining whether the row pointed to by the iterator should be rendered as a separator.
   * Return true if the row is a separator.
   * A common way to implement this is to have a boolean column in the model, whose values the slot returns.
   *
   * For instance,
   * bool on_row_separator(const Glib::RefPtr<Gtk::TreeModel>& model, const Gtk::TreeModel::const_iterator& iter);
   */
  typedef sigc::slot<bool(const Glib::RefPtr<TreeModel>&, const TreeModel::const_iterator&)> SlotRowSeparator;

  /** Sets the row separator function, which is used to determine whether a row should be drawn as a separator.
   */
  void set_row_separator_func(const SlotRowSeparator& slot);


  /** Removes the row separator function, so no separators are drawn.
   * See set_row_separator_func().
   *
   * @newin{3,2}
   */
  void unset_row_separator_func();


  /** Sets which grid lines to draw in @a tree_view.
   *
   * @param grid_lines A `Gtk::TreeView`GridLines value indicating which grid lines to
   * enable.
   */
  void set_grid_lines(GridLines grid_lines);

  /** Returns which grid lines are enabled in @a tree_view.
   *
   * @return A `Gtk::TreeView`GridLines value indicating which grid lines
   * are enabled.
   */
  auto get_grid_lines() const -> GridLines;


  /** Sets whether to draw lines interconnecting the expanders in @a tree_view.
   * This does not have any visible effects for lists.
   *
   * @param enable <tt>true</tt> to enable tree line drawing, <tt>false</tt> otherwise.
   */
  void set_enable_tree_lines(bool enable =  true);

  /** Returns whether or not tree lines are drawn in @a tree_view.
   *
   * @return <tt>true</tt> if tree lines are drawn in @a tree_view, <tt>false</tt>
   * otherwise.
   */
  auto get_enable_tree_lines() const -> bool;


  /** Sets whether to draw and enable expanders and indent child rows in
   *  @a tree_view.  When disabled there will be no expanders visible in trees
   * and there will be no way to expand and collapse rows by default.  Also
   * note that hiding the expanders will disable the default indentation.  You
   * can set a custom indentation in this case using
   * set_level_indentation().
   * This does not have any visible effects for lists.
   *
   * @param enabled <tt>true</tt> to enable expander drawing, <tt>false</tt> otherwise.
   */
  void set_show_expanders(bool enabled =  true);

  /** Returns whether or not expanders are drawn in @a tree_view.
   *
   * @return <tt>true</tt> if expanders are drawn in @a tree_view, <tt>false</tt>
   * otherwise.
   */
  auto get_show_expanders() const -> bool;

  /** Sets the amount of extra indentation for child levels to use in @a tree_view
   * in addition to the default indentation.  The value should be specified in
   * pixels, a value of 0 disables this feature and in this case only the default
   * indentation will be used.
   * This does not have any visible effects for lists.
   *
   * @param indentation The amount, in pixels, of extra indentation in @a tree_view.
   */
  void set_level_indentation(int indentation);

  /** Returns the amount, in pixels, of extra indentation for child levels
   * in @a tree_view.
   *
   * @return The amount of extra indentation for child levels in
   *  @a tree_view.  A return value of 0 means that this feature is disabled.
   */
  auto get_level_indentation() const -> int;


  /** Sets the tip area of @a tooltip to be the area covered by the row at @a path.
   * See also set_tooltip_column() for a simpler alternative.
   * See also Gtk::Tooltip::set_tip_area().
   *
   * @param tooltip A `Gtk::Tooltip`.
   * @param path A `Gtk::TreePath`.
   */
  void set_tooltip_row(const Glib::RefPtr<Tooltip>& tooltip, const TreePath& path);

  //Note that we use pointers instead of references because any one of the 3 arguments may be NULL, and we don't want that many method overloads:


  /** Sets the tip area of @a tooltip to the area @a path, @a column and @a cell have
   * in common.  For example if @a path is <tt>nullptr</tt> and @a column is set, the tip
   * area will be set to the full area covered by @a column.  See also
   * Gtk::Tooltip::set_tip_area().
   *
   * Note that if @a path is not specified and @a cell is set and part of a column
   * containing the expander, the tooltip might not show and hide at the correct
   * position.  In such cases @a path must be set to the current node under the
   * mouse cursor for this function to operate correctly.
   *
   * See also set_tooltip_column() for a simpler alternative.
   *
   * @param tooltip A `Gtk::Tooltip`.
   * @param path A `Gtk::TreePath`.
   * @param column A `Gtk::TreeViewColumn`.
   * @param cell A `Gtk::CellRenderer`.
   */
  void set_tooltip_cell(const Glib::RefPtr<Tooltip>& tooltip, const TreeModel::Path* path, TreeViewColumn* column, CellRenderer* cell);


  /** This function is supposed to be used in a Gtk::Widget::query-tooltip
   * signal handler for Gtk::TreeView. The x, y and keyboard_tip values
   * which are received in the signal handler, should be passed to this
   * function without modification.
   *
   * The return value indicates whether there is an tree view row at the given
   * coordinates (true) or not (false) for mouse tooltips. For keyboard
   * tooltips the row returned will be the cursor item. When true, then the
   * @a path which has been provided will be set to point to
   * that row and the corresponding model.
   *
   * @param x The x coordinate (relative to widget coordinates)
   * @param y The y coordinate (relative to widget coordinates)
   * @param keyboard_tip Whether this is a keyboard tooltip or not
   * @param path A reference to receive a Gtk::TreePath
   * @return Whether or not the given tooltip context points to a row.
   *
   * @newin{2,12}
   */
  auto get_tooltip_context_path(int x, int y,
                                bool keyboard_tip,
                                TreeModel::Path& path) -> bool;

  /** This function is supposed to be used in a Gtk::Widget::query-tooltip
   * signal handler for Gtk::TreeView. The x, y and keyboard_tip values
   * which are received in the signal handler, should be passed to this
   * function without modification.
   *
   * The return value indicates whether there is an tree view row at the given
   * coordinates (true) or not (false) for mouse tooltips. For keyboard
   * tooltips the row returned will be the cursor item. When true, then the
   * @a iter which has been provided will be set to point to
   * that row and the corresponding model.
   *
   * @param x The x coordinate (relative to widget coordinates)
   * @param y The y coordinate (relative to widget coordinates)
   * @param keyboard_tip Whether this is a keyboard tooltip or not
   * @param iter A reference to receive a Gtk::TreeModel::iterator
   * @return Whether or not the given tooltip context points to a row.
   *
   * @newin{2,12}
   */
  auto get_tooltip_context_iter(int x, int y,
                                bool keyboard_tip,
                                Gtk::TreeModel::iterator& iter) -> bool;


  /** If you only plan to have simple (text-only) tooltips on full rows, you
   * can use this function to have `Gtk::TreeView` handle these automatically
   * for you. @a column should be set to the column in @a tree_view’s model
   * containing the tooltip texts, or -1 to disable this feature.
   *
   * When enabled, `GtkWidget:has-tooltip` will be set to <tt>true</tt> and
   *  @a tree_view will connect a `GtkWidget::query-tooltip` signal handler.
   *
   * Note that the signal handler sets the text with Gtk::Tooltip::set_markup(),
   * so &, <, etc have to be escaped in the text.
   *
   * @param column An integer, which is a valid column number for @a tree_view’s model.
   */
  void set_tooltip_column(int column);

  /** Returns the column of @a tree_view’s model which is being used for
   * displaying tooltips on @a tree_view’s rows.
   *
   * @return The index of the tooltip column that is currently being
   * used, or -1 if this is disabled.
   */
  auto get_tooltip_column() const -> int;


  // no_default_handler because GtkTreeViewClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_activated(const TreeModel::Path& path, TreeViewColumn* column)</tt>
   *
   * Flags: Run Last, Action
   *
   * The "row-activated" signal is emitted when the method
   * [`method @a Gtk.TreeView.row_activated`] is called.
   *
   * This signal is emitted when the user double-clicks a treeview row with the
   * property_activate_on_single_click() property set to <tt>false</tt>,
   * or when the user single-clicks a row when that property set to <tt>true</tt>.
   *
   * This signal is also emitted when a non-editable row is selected and one
   * of the keys: <kbd>Space</kbd>, <kbd>Shift</kbd>+<kbd>Space</kbd>,
   * <kbd>Return</kbd> or <kbd>Enter</kbd> is pressed.
   *
   * For selection handling refer to the
   * [tree widget conceptual overview](section-tree-widget.html)
   * as well as `Gtk::TreeSelection`.
   *
   * @param path The `Gtk::TreePath` for the activated row.
   * @param column The `Gtk::TreeViewColumn` in which the activation occurred.
   */

  auto signal_row_activated() -> Glib::SignalProxy<void(const TreeModel::Path&, TreeViewColumn*)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%test_expand_row(const TreeModel::iterator& iter, const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * The given row is about to be expanded (show its children nodes). Use this
   * signal if you need to control the expandability of individual rows.
   *
   * @param iter The tree iter of the row to expand.
   * @param path A tree path that points to the row.
   * @return <tt>false</tt> to allow expansion, <tt>true</tt> to reject.
   */

  auto signal_test_expand_row() -> Glib::SignalProxy<bool(const TreeModel::iterator&, const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%test_collapse_row(const TreeModel::iterator& iter, const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * The given row is about to be collapsed (hide its children nodes). Use this
   * signal if you need to control the collapsibility of individual rows.
   *
   * @param iter The tree iter of the row to collapse.
   * @param path A tree path that points to the row.
   * @return <tt>false</tt> to allow collapsing, <tt>true</tt> to reject.
   */

  auto signal_test_collapse_row() -> Glib::SignalProxy<bool(const TreeModel::iterator&, const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_expanded(const TreeModel::iterator& iter, const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * The given row has been expanded (child nodes are shown).
   *
   * @param iter The tree iter of the expanded row.
   * @param path A tree path that points to the row.
   */

  auto signal_row_expanded() -> Glib::SignalProxy<void(const TreeModel::iterator&, const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%row_collapsed(const TreeModel::iterator& iter, const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * The given row has been collapsed (child nodes are hidden).
   *
   * @param iter The tree iter of the collapsed row.
   * @param path A tree path that points to the row.
   */

  auto signal_row_collapsed() -> Glib::SignalProxy<void(const TreeModel::iterator&, const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cursor_changed()</tt>
   *
   * Flags: Run Last
   *
   * The position of the cursor (focused cell) has changed.
   */

  auto signal_cursor_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%columns_changed()</tt>
   *
   * Flags: Run Last
   *
   * The number of columns of the treeview has changed.
   */

  auto signal_columns_changed() -> Glib::SignalProxy<void()>;


  //Don't wrap these. They are keybinding signals, and their API broke for GTK+ 2.2.


  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >;

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_headers_visible() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_headers_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_headers_clickable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_headers_clickable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expander_column() -> Glib::PropertyProxy< TreeViewColumn* > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expander_column() const -> Glib::PropertyProxy_ReadOnly< TreeViewColumn* >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_search() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_search() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_column() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Setting the property_fixed_height_mode() property to <tt>true</tt> speeds up
   * `Gtk::TreeView` by assuming that all rows have the same height.
   * Only enable this option if all rows are the same height.
   * Please see Gtk::TreeView::set_fixed_height_mode() for more
   * information on this option.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_height_mode() -> Glib::PropertyProxy< bool > ;

/** Setting the property_fixed_height_mode() property to <tt>true</tt> speeds up
   * `Gtk::TreeView` by assuming that all rows have the same height.
   * Only enable this option if all rows are the same height.
   * Please see Gtk::TreeView::set_fixed_height_mode() for more
   * information on this option.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_height_mode() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Enables or disables the hover selection mode of @a tree_view.
   * Hover selection makes the selected row follow the pointer.
   * Currently, this works only for the selection modes
   * Gtk::SelectionMode::SINGLE and Gtk::SelectionMode::BROWSE.
   *
   * This mode is primarily intended for treeviews in popups, e.g.
   * in `Gtk::ComboBox` or `Gtk::EntryCompletion`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hover_selection() -> Glib::PropertyProxy< bool > ;

/** Enables or disables the hover selection mode of @a tree_view.
   * Hover selection makes the selected row follow the pointer.
   * Currently, this works only for the selection modes
   * Gtk::SelectionMode::SINGLE and Gtk::SelectionMode::BROWSE.
   *
   * This mode is primarily intended for treeviews in popups, e.g.
   * in `Gtk::ComboBox` or `Gtk::EntryCompletion`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hover_selection() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Enables or disables the hover expansion mode of @a tree_view.
   * Hover expansion makes rows expand or collapse if the pointer moves
   * over them.
   *
   * This mode is primarily intended for treeviews in popups, e.g.
   * in `Gtk::ComboBox` or `Gtk::EntryCompletion`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hover_expand() -> Glib::PropertyProxy< bool > ;

/** Enables or disables the hover expansion mode of @a tree_view.
   * Hover expansion makes rows expand or collapse if the pointer moves
   * over them.
   *
   * This mode is primarily intended for treeviews in popups, e.g.
   * in `Gtk::ComboBox` or `Gtk::EntryCompletion`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hover_expand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** <tt>true</tt> if the view has expanders.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_expanders() -> Glib::PropertyProxy< bool > ;

/** <tt>true</tt> if the view has expanders.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_expanders() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Extra indentation for each level.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_level_indentation() -> Glib::PropertyProxy< bool > ;

/** Extra indentation for each level.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_level_indentation() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rubber_banding() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rubber_banding() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: Gtk::TreeView::GridLines::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_grid_lines() -> Glib::PropertyProxy< bool > ;

/** Default value: Gtk::TreeView::GridLines::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_grid_lines() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_tree_lines() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_tree_lines() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_column() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_tooltip_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The activate-on-single-click property specifies whether the "row-activated" signal
   * will be emitted after a single click.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() -> Glib::PropertyProxy< bool > ;

/** The activate-on-single-click property specifies whether the "row-activated" signal
   * will be emitted after a single click.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >;


protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template<class ColumnType> friend
  void _auto_store_on_cellrenderer_text_edited_string(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);

  template <class ColumnType> friend
  void _auto_store_on_cellrenderer_text_edited_numerical(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);

  void _auto_store_on_cellrenderer_toggle_edited_with_model(const Glib::ustring& path_string, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);

  template<class ColumnType> friend
  void TreeView_Private::_connect_auto_store_editable_signal_handler(TreeView*, CellRenderer*, const TreeModelColumn<ColumnType>&);

#endif //DOXYGEN_SHOULD_SKIP_THIS


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};


template <class ColumnType> inline
auto TreeView::append_column(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column) -> int
{
  // compilation will fail if there is no appropriate TreeViewColumn
  // constructor for this model column type.
  TreeViewColumn *const pViewColumn = Gtk::manage( new TreeViewColumn(title, model_column) );

  return append_column(*pViewColumn);
}

template <class ColumnType> inline
auto TreeView::append_column_numeric(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, const Glib::ustring& format) -> int
{
  TreeViewColumn* const pViewColumn = Gtk::manage( new TreeViewColumn(title) );

  //Use a CellRendererText:
  //We don't use TreeView::Column::append_column(model_column) to generate an appropriate CellRenderer,
  //because that uses set_renderer(), which renders the model value using the automatic glib "transformations" (number-string conversions). As well as being unnecessary here, those automatic conversions can't handle all numeric types.
  CellRenderer* pCellRenderer = manage( new CellRendererText() );
  pViewColumn->pack_start(*pCellRenderer);


  //Some compilers don't like us to give the pointer to a template function directly to sigc::ptr_fun():
  typedef void (*type_fptr)(Gtk::CellRenderer* cell, const Gtk::TreeModel::const_iterator& iter, int model_column, const Glib::ustring& format);
  type_fptr fptr = TreeView_Private::_auto_cell_data_func<ColumnType>;

  //Connect a cell_data callback, to show the number's text representation in the specified format:
  //We use sigc::bind<-1> twice here, instead of sigc::bind() once, because some compilers need the extra hint.
  auto slot = sigc::bind<-1>(
    sigc::bind<-1>( sigc::ptr_fun(fptr), format),
    model_column.index()
  );

  pViewColumn->set_cell_data_func(*pCellRenderer, slot);

  return append_column(*pViewColumn);
}

template <class ColumnType> inline
auto TreeView::append_column_numeric_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, const Glib::ustring& format) -> int
{
  int cols_count = append_column_numeric(title, model_column, format);

  //connect signal handlers for auto-storing of edited cell data
  CellRenderer *const cell = get_column_cell_renderer(cols_count - 1);
  if(cell)
  {
    TreeView_Private::_connect_auto_store_numeric_editable_signal_handler<ColumnType>(this, cell, model_column);
  }

  return cols_count;
}

template <class ColumnType> inline
auto TreeView::append_column_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column) -> int
{
  //Don't use this in a header, because it gives warnings when disabled: g_assert(model_column.type() != 0);

  // compilation will fail if there is no appropriate TreeViewColumn
  // constructor for this model column type.
  TreeViewColumn *const pViewColumn = Gtk::manage( new TreeViewColumn(title, model_column) );

  //connect signal handlers for auto-storing of edited cell data
  CellRenderer* pCellRender = pViewColumn->get_first_cell();
  TreeView_Private::_connect_auto_store_editable_signal_handler<ColumnType>(this, pCellRender, model_column);

  return append_column(*pViewColumn);
}

template <class ColumnType> inline
auto TreeView::insert_column(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, int position) -> int
{
  // compilation will fail if there is no appropriate TreeViewColumn
  // constructor for this model column type.
  TreeViewColumn *const pViewColumn = Gtk::manage( new TreeViewColumn(title, model_column) );

  return insert_column(*pViewColumn, position);
}

template <class ColumnType> inline
auto TreeView::insert_column_editable(const Glib::ustring& title, const TreeModelColumn<ColumnType>& model_column, int position) -> int
{
  // compilation will fail if there is no appropriate TreeViewColumn
  // constructor for this model column type.
  TreeViewColumn *const pViewColumn = Gtk::manage( new TreeViewColumn(title, model_column) );

   //connect signal handlers for auto-storing of edited cell data
  CellRenderer* pCellRender = pViewColumn->get_first_cell();
  TreeView_Private::_connect_auto_store_editable_signal_handler(this, pCellRender, model_column);

  return insert_column(*pViewColumn, position);
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace TreeView_Private
{

//Template specializations, for different model column types:

// append_column_editable<>() and insert_column_editable<>() call template function
// _connect_auto_store_editable_signal_handler<ColumnType>().
// There are 3 versions of _connect_auto_store_editable_signal_handler<>():
//
// 1. The default version for string data. It connects
//    CellRendererText::signal_edited() to template function
//    _auto_store_on_cellrenderer_text_edited_string<ColumnType>().
//
// 2. A bool specialization. It connects CellRendererToggle::signal_toggled()
//    to function _auto_store_on_cellrenderer_toggle_edited_with_model().
//
// 3. Several identical (except for the type name) specializations for numeric data.
//    They call _connect_auto_store_numeric_editable_signal_handler<ColumnType>(),
//    which connects CellRendererText::signal_edited() to template function
//    _auto_store_on_cellrenderer_text_edited_numerical<ColumnType>().
//
// We need all those specializations with identical implementations, because we
// chose to avoid multiple specializations for the string types by dealing with
// string types in the default implementation.
//
// With these numeric specializations append_column_editable<>() and
// insert_column_editable<>() can be used for the same numeric types as
// append_column<>() and insert_column<>(). Those are fundamental types in the
// GType system, and Glib registers conversion functions from those types to
// gchararray with g_value_register_transform_func().
// 'short' is not one of those types. It can be handled only by
// append_column_numeric<>() and append_column_numeric_editable<>().

//bool specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<bool>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<bool>& model_column);

//int specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<int>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<int>& model_column);

//unsigned int specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<unsigned int>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<unsigned int>& model_column);

//long specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<long>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<long>& model_column);

//unsigned long specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<unsigned long>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<unsigned long>& model_column);

//float specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<float>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<float>& model_column);

//double specialization:
template<> GTKMM_API
void _connect_auto_store_editable_signal_handler<double>(Gtk::TreeView* this_p,
  Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<double>& model_column);

} // namespace TreeView_Private
#endif //DOXYGEN_SHOULD_SKIP_THIS


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace TreeView_Private
{

// Primary template falls back to std::strtod()
template <typename T>
auto _convert_from_ustring_to_numeric_type(const Glib::ustring& text) -> T
{
  return std::strtod(text.c_str(), nullptr);
}

// Floating point specializations
template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<float>(const Glib::ustring& text) -> float;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<long double>(const Glib::ustring& text) -> long double;

// Integral specializations
template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<short>(const Glib::ustring& text) -> short;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<unsigned short>(const Glib::ustring& text) -> unsigned short;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<int>(const Glib::ustring& text) -> int;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<unsigned int>(const Glib::ustring& text) -> unsigned int;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<long>(const Glib::ustring& text) -> long;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<unsigned long>(const Glib::ustring& text) -> unsigned long;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<long long>(const Glib::ustring& text) -> long long;

template<> GTKMM_API
auto _convert_from_ustring_to_numeric_type<unsigned long long>(const Glib::ustring& text) -> unsigned long long;


template <class ColumnType> inline
void _connect_auto_store_editable_signal_handler(Gtk::TreeView* this_p, Gtk::CellRenderer* pCellRenderer, const Gtk::TreeModelColumn<ColumnType>& model_column)
{
  //Don't use this in a header, because it gives warnings when disabled: g_assert(model_column.type() != 0);

  //The different CellRenderers have different "edited" signals,
  //and numerical values need to convert the text value to a number,
  //so there are specializations for this template.

  Gtk::CellRendererText* pCellText = dynamic_cast<Gtk::CellRendererText*>(pCellRenderer);

  //Set the appropriate property,
  //and connect to the appropriate signal, sending the model_column too,
  if(pCellText)
  {
    pCellText->property_editable() = true;

    //Some compilers (IRIX MipsPro) don't like us to give the pointer to a template function directly to sigc::ptr_fun():
    typedef void (*type_func)(const Glib::ustring&, const Glib::ustring&, int, const Glib::RefPtr<Gtk::TreeModel>&);
    type_func func = &(Gtk::TreeView_Private::_auto_store_on_cellrenderer_text_edited_string<ColumnType>);
    sigc::slot<void(const Glib::ustring&, const Glib::ustring&, int, const Glib::RefPtr<Gtk::TreeModel>&)> theslot  =
      sigc::ptr_fun(func);

    //We use bind<-1> twice here, instead of using bind() once, because some compilers need the extra hint.
    pCellText->signal_edited().connect(
      sigc::bind<-1>(
        sigc::bind<-1>( theslot, this_p->get_model()),
        model_column.index()
      )
    );
  }
}

template<class ColumnType> inline
void _connect_auto_store_numeric_editable_signal_handler(Gtk::TreeView* this_p, Gtk::CellRenderer* pCellRenderer,  const Gtk::TreeModelColumn<ColumnType>& model_column)
{
  //The different CellRenderers have different "edited" signals,
  //and numerical values need to convert the text value to a number.

  Gtk::CellRendererText* pCellText = dynamic_cast<Gtk::CellRendererText*>(pCellRenderer);
  if(pCellText)
  {
    //Set the appropriate property.
    pCellText->property_editable() = true;

    //Some compilers don't like us to give the pointer to a template function directly to sigc::ptr_fun():
    typedef void (*type_fptr)(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model);
    type_fptr fptr = _auto_store_on_cellrenderer_text_edited_numerical<ColumnType>;

    //Connect to the appropriate signal, sending the model_column too.
    //We use bind<-1> twice here, instead of using bind() once, because some compilers need the extra hint.
    pCellText->signal_edited().connect(
      sigc::bind<-1>(
        sigc::bind<-1>(
          sigc::ptr_fun(fptr),
          this_p->get_model() ),
        model_column.index()
      )
    );
  }
}

template <class ColumnType> inline
void _auto_store_on_cellrenderer_text_edited_string(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model)
{
  Gtk::TreePath path(path_string);

  //Get the row from the path:
  if(model)
  {
    auto iter = model->get_iter(path);
    if(iter)
    {
        //Store the user's new text in the model:
        Gtk::TreeRow row = *iter;
        row.set_value(model_column, (ColumnType)new_text);
    }
  }
}

template <class ColumnType> inline
void _auto_store_on_cellrenderer_text_edited_numerical(const Glib::ustring& path_string, const Glib::ustring& new_text, int model_column, const Glib::RefPtr<Gtk::TreeModel>& model)
{
  //This is used on numerical model columns:

  Gtk::TreePath path(path_string);

  //Get the row from the path:
  if(model)
  {
    auto iter = model->get_iter(path);
    if(iter)
    {
      // Convert the user's new text to a number, and store the number in the model:
      Gtk::TreeRow row = *iter;
      row.set_value(model_column, _convert_from_ustring_to_numeric_type<ColumnType>(new_text));
    }
  }
}

template <class ColumnType> inline
void _auto_cell_data_func(Gtk::CellRenderer* cell, const Gtk::TreeModel::const_iterator& iter, int model_column, const Glib::ustring& format)
{
  Gtk::CellRendererText* pTextRenderer = dynamic_cast<Gtk::CellRendererText*>(cell);
  if(!pTextRenderer)
  {
    g_warning("gtkmm: TextView: append_column_numeric() was used with a non-numeric type.");
  }
  else
  {
    if(iter)
    {
      //Get the value from the model.
      const auto row = *iter;
      ColumnType value = ColumnType();
      row.get_value(model_column, value);

      //Convert it to a string representation:
      char buff[20];
      int used = g_snprintf(buff, sizeof(buff), format.c_str(), value); //value must be a numeric type.
      if(used > 0)
      {
        //Show the text representation in the view:
        pTextRenderer->property_text() = buff;
      }
    }
  }
}

} // namespace TreeView_Private
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TreeView::DropPosition> : public Glib::Value_Enum<Gtk::TreeView::DropPosition>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TreeView::GridLines> : public Glib::Value_Enum<Gtk::TreeView::GridLines>
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
   * @relates Gtk::TreeView
   */
  GTKMM_API
  auto wrap(GtkTreeView* object, bool take_copy = false) -> Gtk::TreeView*;
} //namespace Glib


#endif /* _GTKMM_TREEVIEW_H */

