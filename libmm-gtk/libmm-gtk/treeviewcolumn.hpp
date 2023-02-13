
#ifndef _GTKMM_TREEVIEWCOLUMN_H
#define _GTKMM_TREEVIEWCOLUMN_H

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


#include <mm/gtk/treeiter.hpp>
#include <mm/gtk/button.hpp>
#include <mm/gtk/treemodel.hpp>
#include <mm/gtk/celllayout.hpp>
#include <mm/gtk/buildable.hpp>
#include <mm/gtk/cellrenderer_generation.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeViewColumn = struct _GtkTreeViewColumn;
using GtkTreeViewColumnClass = struct _GtkTreeViewColumnClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API TreeViewColumn_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{


// We use GTKMM_API here because gcc needs the extra help on win32 , even
// when using --export-all and auto-import.
// See http://bugzilla.gnome.org/show_bug.cgi?id=309030.

class CellArea;
class TreeView;

//TODO: Deal with the GtkObject->GObject change?
/** Typedefed as Gtk::TreeView::Column.
* This is a visible column in a Gtk::TreeView widget. It determines the geometry, type.
*
* @ingroup TreeView
*/

class GTKMM_API TreeViewColumn
: public Object,
  public CellLayout,
  public Buildable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TreeViewColumn CppObjectType;
  typedef TreeViewColumn_Class CppClassType;
  typedef GtkTreeViewColumn BaseObjectType;
  typedef GtkTreeViewColumnClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  TreeViewColumn(TreeViewColumn&& src) noexcept;
  auto operator=(TreeViewColumn&& src) noexcept -> TreeViewColumn&;

  // noncopyable
  TreeViewColumn(const TreeViewColumn&) = delete;
  auto operator=(const TreeViewColumn&) -> TreeViewColumn& = delete;

  ~TreeViewColumn() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class TreeViewColumn_Class;
  static CppClassType treeviewcolumn_class_;

protected:
  explicit TreeViewColumn(const Glib::ConstructParams& construct_params);
  explicit TreeViewColumn(GtkTreeViewColumn* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkTreeViewColumn*       { return reinterpret_cast<GtkTreeViewColumn*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkTreeViewColumn* { return reinterpret_cast<GtkTreeViewColumn*>(gobject_); }

private:


public:
/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Sizing GROW_ONLY
   * Columns only get bigger in reaction to changes in the model.
   *
   *  @var Sizing AUTOSIZE
   * Columns resize to be the optimal size every time the model changes.
   *
   *  @var Sizing FIXED
   * Columns are a fixed numbers of pixels wide.
   *
   *  @enum Sizing
   *
   * The sizing method the column uses to determine its width.  Please note
   * that Gtk::TreeViewColumn::Sizing::AUTOSIZE are inefficient for large views, and
   * can make columns appear choppy.
   *
   * @ingroup gtkmmEnums
   */
  enum class Sizing
  {
    GROW_ONLY,
    AUTOSIZE,
    FIXED
  };


typedef TreeViewColumn Column;

TreeViewColumn();

explicit TreeViewColumn(const Glib::ustring& title);
TreeViewColumn(const Glib::ustring& title, CellRenderer& cell);

/** Create a default view column for the given model column type.
 */
template<class T_ModelColumnType>
TreeViewColumn(const Glib::ustring& title, const TreeModelColumn<T_ModelColumnType>& column);


  /** Packs the @a cell into the beginning of the column. If @a expand is <tt>false</tt>, then
   * the @a cell is allocated no more space than it needs. Any unused space is divided
   * evenly between cells for which @a expand is <tt>true</tt>.
   *
   * @param cell The `Gtk::CellRenderer`.
   * @param expand <tt>true</tt> if @a cell is to be given extra space allocated to @a tree_column.
   */
  void pack_start(CellRenderer& cell, bool expand =  true);

  /** Adds the @a cell to end of the column. If @a expand is <tt>false</tt>, then the @a cell
   * is allocated no more space than it needs. Any unused space is divided
   * evenly between cells for which @a expand is <tt>true</tt>.
   *
   * @param cell The `Gtk::CellRenderer`.
   * @param expand <tt>true</tt> if @a cell is to be given extra space allocated to @a tree_column.
   */
  void pack_end(CellRenderer& cell, bool expand =  true);

/** Creates an appropriate CellRenderer for the @a column, and packs that cell into the beginning of the column.
 * If @a expand  is <tt>false</tt>, then
 * the cell is allocated no more space than it needs. Any unused space is divided
 * evenly between cells for which @a expand is <tt>true</tt>.
 *
 * You can use get_first_cell() or get_cells() to access the generated CellRenderer.
 *
 * @param column The model column that will be rendered by the view cell.
 * @param expand <tt>true</tt> if the cell is to be given extra space allocated to the view column.
 */
template<class T_ModelColumnType>
void pack_start(const TreeModelColumn<T_ModelColumnType>& column, bool expand = true);

/** Creates an appropriate CellRenderer for the @a column, and packs that cell at the end of the column.
 * If @a expand  is <tt>false</tt>, then
 * the cell is allocated no more space than it needs. Any unused space is divided
 * evenly between cells for which @a expand is <tt>true</tt>.
 *
 * You can use get_first_cell() or get_cells() to access the generated CellRenderer.
 *
 * @param column The model column that will be rendered by the view cell.
 * @param expand <tt>true</tt> if the cell is to be given extra space allocated to the view column.
 */
template<class T_ModelColumnType>
void pack_end(const TreeModelColumn<T_ModelColumnType>& column, bool expand = true);


  /** Unsets all the mappings on all renderers on the @a tree_column.
   */
  void clear();


  /** Adds an attribute mapping to the list in @a tree_column.
   *
   * The @a column is the
   * column of the model to get a value from, and the @a attribute is the
   * parameter on @a cell_renderer to be set from the value. So for example
   * if column 2 of the model contains strings, you could have the
   * “text” attribute of a `Gtk::CellRendererText` get its values from
   * column 2.
   *
   * @param cell_renderer The `Gtk::CellRenderer` to set attributes on.
   * @param attribute An attribute on the renderer.
   * @param column The column position on the model to get the attribute from.
   */
  void add_attribute(CellRenderer& cell_renderer, const Glib::ustring& attribute, int column);

void add_attribute(const Glib::PropertyProxy_Base& property, const TreeModelColumnBase& column);

void add_attribute(Gtk::CellRenderer& cell, const Glib::ustring& property_name, const TreeModelColumnBase& column);


/** Associate a view CellRenderer with a model column, so that the CellRenderer renders the data in the model column.
 *
 * @param renderer The view cell renderer which will render the model column.
 * @param column The model column to be renderered by this view.
 */
void set_renderer(Gtk::CellRenderer& renderer, const TreeModelColumnBase& column);

// _WRAP_METHOD(void set_attributes(CellRenderer& cell_renderer, ...), )

  /** For instance,
   * void on_cell_data(Gtk::CellRenderer* cell, const Gtk::TreeModel::iterator& iter);
   *
   * This function is used instead of the standard attributes mapping for setting the column value, and should set the
   * value of the column's cell renderer as appropriate.
   */
  typedef sigc::slot<void(CellRenderer*, const Gtk::TreeModel::const_iterator&)> SlotTreeCellData;

  /** Sets the slot callback to use for the column.
   * This callback function is used instead of the standard attributes mapping for setting the column value, and should set the
   * value of the column's cell renderer as appropriate.
   *
   * See also unset_cell_data_func().
   *
   * @param cell_renderer A Gtk::CellRenderer
   * @param slot The callback slot to use. Create this with sigc::mem_fun(), or sigc::ptr_fun().
   */
  void set_cell_data_func(CellRenderer& cell_renderer, const SlotTreeCellData& slot);

  /** Removes a previously set callback slot. See set_cell_data_func().
   */
  void unset_cell_data_func(CellRenderer& cell_renderer);


  /** Clears all existing attributes previously set with
   * set_attributes().
   *
   * @param cell_renderer A `Gtk::CellRenderer` to clear the attribute mapping on.
   */
  void clear_attributes(CellRenderer& cell_renderer);

  /** Sets the spacing field of @a tree_column, which is the number of pixels to
   * place between cell renderers packed into it.
   *
   * @param spacing Distance between cell renderers in pixels.
   */
  void set_spacing(int spacing);

  /** Returns the spacing of @a tree_column.
   *
   * @return The spacing of @a tree_column.
   */
  auto get_spacing() const -> int;

  /** Sets the visibility of @a tree_column.
   *
   * @param visible <tt>true</tt> if the @a tree_column is visible.
   */
  void set_visible(bool visible =  true);

  /** Returns <tt>true</tt> if @a tree_column is visible.
   *
   * @return Whether the column is visible or not.  If it is visible, then
   * the tree will show the column.
   */
  auto get_visible() const -> bool;

  /** If @a resizable is <tt>true</tt>, then the user can explicitly resize the column by
   * grabbing the outer edge of the column button.
   *
   * If resizable is <tt>true</tt> and
   * sizing mode of the column is Gtk::TreeViewColumn::Sizing::AUTOSIZE, then the sizing
   * mode is changed to Gtk::TreeViewColumn::Sizing::GROW_ONLY.
   *
   * @param resizable <tt>true</tt>, if the column can be resized.
   */
  void set_resizable(bool resizable =  true);

  /** Returns <tt>true</tt> if the @a tree_column can be resized by the end user.
   *
   * @return <tt>true</tt>, if the @a tree_column can be resized.
   */
  auto get_resizable() const -> bool;

  /** Sets the growth behavior of @a tree_column to @a type.
   *
   * @param type The `Gtk::TreeViewColumn`Sizing.
   */
  void set_sizing(Sizing type);

  /** Returns the current type of @a tree_column.
   *
   * @return The type of @a tree_column.
   */
  auto get_sizing() -> Sizing;

  /** Returns the current X offset of @a tree_column in pixels.
   *
   * @return The current X offset of @a tree_column.
   */
  auto get_x_offset() const -> int;

  /** Returns the current size of @a tree_column in pixels.
   *
   * @return The current width of @a tree_column.
   */
  auto get_width() const -> int;

  /** Gets the fixed width of the column.  This may not be the actual displayed
   * width of the column; for that, use get_width().
   *
   * @return The fixed width of the column.
   */
  auto get_fixed_width() const -> int;

  /** If @a fixed_width is not -1, sets the fixed width of @a tree_column; otherwise
   * unsets it.  The effective value of @a fixed_width is clamped between the
   * minimum and maximum width of the column; however, the value stored in the
   * “fixed-width” property is not clamped.  If the column sizing is
   * Gtk::TreeViewColumn::Sizing::GROW_ONLY or Gtk::TreeViewColumn::Sizing::AUTOSIZE, setting
   * a fixed width overrides the automatically calculated width.  Note that
   *  @a fixed_width is only a hint to GTK; the width actually allocated to the
   * column may be greater or less than requested.
   *
   * Along with “expand”, the “fixed-width” property changes when the column is
   * resized by the user.
   *
   * @param fixed_width The new fixed width, in pixels, or -1.
   */
  void set_fixed_width(int fixed_width);

  /** Sets the minimum width of the @a tree_column.  If @a min_width is -1, then the
   * minimum width is unset.
   *
   * @param min_width The minimum width of the column in pixels, or -1.
   */
  void set_min_width(int min_width);

  /** Returns the minimum width in pixels of the @a tree_column, or -1 if no minimum
   * width is set.
   *
   * @return The minimum width of the @a tree_column.
   */
  auto get_min_width() const -> int;

  /** Sets the maximum width of the @a tree_column.  If @a max_width is -1, then the
   * maximum width is unset.  Note, the column can actually be wider than max
   * width if it’s the last column in a view.  In this case, the column expands to
   * fill any extra space.
   *
   * @param max_width The maximum width of the column in pixels, or -1.
   */
  void set_max_width(int max_width);

  /** Returns the maximum width in pixels of the @a tree_column, or -1 if no maximum
   * width is set.
   *
   * @return The maximum width of the @a tree_column.
   */
  auto get_max_width() const -> int;

  /** Emits the “clicked” signal on the column.  This function will only work if
   *  @a tree_column is clickable.
   */
  void clicked();


  /** Sets the title of the @a tree_column.  If a custom widget has been set, then
   * this value is ignored.
   *
   * @param title The title of the @a tree_column.
   */
  void set_title(const Glib::ustring& title);

  /** Returns the title of the widget.
   *
   * @return The title of the column. This string should not be
   * modified or freed.
   */
  auto get_title() const -> Glib::ustring;


  /** Sets the column to take available extra space.  This space is shared equally
   * amongst all columns that have the expand set to <tt>true</tt>.  If no column has this
   * option set, then the last column gets all extra space.  By default, every
   * column is created with this <tt>false</tt>.
   *
   * Along with “fixed-width”, the “expand” property changes when the column is
   * resized by the user.
   *
   * @param expand <tt>true</tt> if the column should expand to fill available space.
   */
  void set_expand(bool expand =  true);

  /** Returns <tt>true</tt> if the column expands to fill available space.
   *
   * @return <tt>true</tt> if the column expands to fill available space.
   */
  auto get_expand() const -> bool;


  /** Sets the header to be active if @a clickable is <tt>true</tt>.  When the header is
   * active, then it can take keyboard focus, and can be clicked.
   *
   * @param clickable <tt>true</tt> if the header is active.
   */
  void set_clickable(bool clickable =  true);

  /** Returns <tt>true</tt> if the user can click on the header for the column.
   *
   * @return <tt>true</tt> if user can click the column header.
   */
  auto get_clickable() const -> bool;

  /** Sets the widget in the header to be @a widget.  If widget is <tt>nullptr</tt>, then the
   * header button is set with a `Gtk::Label` set to the title of @a tree_column.
   *
   * @param widget A child `Gtk::Widget`.
   */
  void set_widget(Gtk::Widget& widget);

  /** Returns the `Gtk::Widget` in the button on the column header.
   *
   * If a custom widget has not been set then <tt>nullptr</tt> is returned.
   *
   * @return The `Gtk::Widget` in the column header.
   */
  auto get_widget() -> Widget*;

  /** Returns the `Gtk::Widget` in the button on the column header.
   *
   * If a custom widget has not been set then <tt>nullptr</tt> is returned.
   *
   * @return The `Gtk::Widget` in the column header.
   */
  auto get_widget() const -> const Widget*;


  /** Sets the alignment of the title or custom widget inside the column header.
   * The alignment determines its location inside the button -- 0.0 for left, 0.5
   * for center, 1.0 for right.
   *
   * @param xalign The alignment, which is between [0.0 and 1.0] inclusive.
   */
  void set_alignment(float xalign);

  /** Sets the alignment of the title or custom widget inside the column header.
   * The alignment determines its location inside the button -- 0.0 for left, 0.5
   * for center, 1.0 for right.
   *
   * @param xalign The alignment, which is between [0.0 and 1.0] inclusive.
   */
  void set_alignment(Align xalign);


  /** Returns the current x alignment of @a tree_column.  This value can range
   * between 0.0 and 1.0.
   *
   * @return The current alignent of @a tree_column.
   */
  auto get_alignment() const -> float;

  /** If @a reorderable is <tt>true</tt>, then the column can be reordered by the end user
   * dragging the header.
   *
   * @param reorderable <tt>true</tt>, if the column can be reordered.
   */
  void set_reorderable(bool reorderable =  true);

  /** Returns <tt>true</tt> if the @a tree_column can be reordered by the user.
   *
   * @return <tt>true</tt> if the @a tree_column can be reordered by the user.
   */
  auto get_reorderable() const -> bool;


  /** Sets the logical @a sort_column_id that this column sorts on when this column
   * is selected for sorting.  Doing so makes the column header clickable.
   *
   * @param sort_column_id The @a sort_column_id of the model to sort on.
   */
  void set_sort_column(const TreeModelColumnBase& sort_column_id);

  /** Sets the logical @a sort_column_id that this column sorts on when this column
   * is selected for sorting.  Doing so makes the column header clickable.
   *
   * @param sort_column_id The @a sort_column_id of the model to sort on.
   */
  void set_sort_column(int sort_column_id);


  /** Gets the logical @a sort_column_id that the model sorts on
   * when this column is selected for sorting.
   *
   * See set_sort_column_id().
   *
   * @return The current @a sort_column_id for this column, or -1 if
   * this column can’t be used for sorting.
   */
  auto get_sort_column_id() const -> int;

  /** Call this function with a @a setting of <tt>true</tt> to display an arrow in
   * the header button indicating the column is sorted. Call
   * set_sort_order() to change the direction of
   * the arrow.
   *
   * @param setting <tt>true</tt> to display an indicator that the column is sorted.
   */
  void set_sort_indicator(bool setting);

  /** Gets the value set by set_sort_indicator().
   *
   * @return Whether the sort indicator arrow is displayed.
   */
  auto get_sort_indicator() const -> bool;

  /** Changes the appearance of the sort indicator.
   *
   * This does not actually sort the model.  Use
   * set_sort_column_id() if you want automatic sorting
   * support.  This function is primarily for custom sorting behavior, and should
   * be used in conjunction with Gtk::TreeSortable::set_sort_column_id() to do
   * that. For custom models, the mechanism will vary.
   *
   * The sort indicator changes direction to indicate normal sort or reverse sort.
   * Note that you must have the sort indicator enabled to see anything when
   * calling this function; see set_sort_indicator().
   *
   * @param order Sort order that the sort indicator should indicate.
   */
  void set_sort_order(SortType order);

  /** Gets the value set by set_sort_order().
   *
   * @return The sort order the sort indicator is indicating.
   */
  auto get_sort_order() const -> SortType;


  /** Sets the cell renderer based on the @a tree_model and @a iter.  That is, for
   * every attribute mapping in @a tree_column, it will get a value from the set
   * column on the @a iter, and use that value to set the attribute on the cell
   * renderer.  This is used primarily by the `Gtk::TreeView`.
   *
   * @param tree_model The `Gtk::TreeModel` to get the cell renderers attributes from.
   * @param iter The `Gtk::TreeIter` to get the cell renderer’s attributes from.
   * @param is_expander <tt>true</tt>, if the row has children.
   * @param is_expanded <tt>true</tt>, if the row has visible children.
   */
  void cell_set_cell_data(const Glib::RefPtr<TreeModel>& tree_model, const TreeModel::iterator& iter, bool is_expander, bool is_expanded);


  /** Obtains the width and height needed to render the column.  This is used
   * primarily by the `Gtk::TreeView`.
   *
   * @param x_offset Location to return x offset of a cell relative to @a cell_area.
   * @param y_offset Location to return y offset of a cell relative to @a cell_area.
   * @param width Location to return width needed to render a cell.
   * @param height Location to return height needed to render a cell.
   */
  void cell_get_size(int& x_offset, int& y_offset, int& width, int& height) const;


  /** Returns <tt>true</tt> if any of the cells packed into the @a tree_column are visible.
   * For this to be meaningful, you must first initialize the cells with
   * cell_set_cell_data()
   *
   * @return <tt>true</tt>, if any of the cells packed into the @a tree_column are currently visible.
   */
  auto cell_is_visible() const -> bool;

  /** Sets the current keyboard focus to be at @a cell, if the column contains
   * 2 or more editable and activatable cells.
   *
   * @param cell A `Gtk::CellRenderer`.
   */
  void focus_cell(CellRenderer& cell);


  /** Obtains the horizontal position and size of a cell in a column.
   *
   * If the  cell is not found in the column, @a start_pos and @a width
   * are not changed and <tt>false</tt> is returned.
   *
   * @param cell_renderer A Gtk::CellRenderer.
   * @param start_pos Return location for the horizontal position of @a cell within
   *  @a tree_column.
   * @param width Return location for the width of @a cell.
   * @return <tt>true</tt> if @a cell belongs to @a tree_column.
   */
  auto get_cell_position(const CellRenderer& cell_renderer, int& start_pos, int& width) const -> bool;

  /** Flags the column, and the cell renderers added to this column, to have
   * their sizes renegotiated.
   */
  void queue_resize();


  /** Returns the `Gtk::TreeView` wherein @a tree_column has been inserted.
   * If @a column is currently not inserted in any tree view, <tt>nullptr</tt> is
   * returned.
   *
   * @return The tree view wherein @a column
   * has been inserted.
   */
  auto get_tree_view() -> TreeView*;

  /** Returns the `Gtk::TreeView` wherein @a tree_column has been inserted.
   * If @a column is currently not inserted in any tree view, <tt>nullptr</tt> is
   * returned.
   *
   * @return The tree view wherein @a column
   * has been inserted.
   */
  auto get_tree_view() const -> const TreeView*;


  /** Returns the button used in the treeview column header
   *
   * @return The button for the column header.
   */
  auto get_button() -> Button*;

  /** Returns the button used in the treeview column header
   *
   * @return The button for the column header.
   */
  auto get_button() const -> const Button*;

  // no_default_handler because GtkTreeViewColumnClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%clicked()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the column's header has been clicked.
   */

  auto signal_clicked() -> Glib::SignalProxy<void()>;


  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_x_offset() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() -> Glib::PropertyProxy< int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: Gtk::TreeViewColumn::Sizing::GROW_ONLY
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sizing() -> Glib::PropertyProxy< Sizing > ;

/** Default value: Gtk::TreeViewColumn::Sizing::GROW_ONLY
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sizing() const -> Glib::PropertyProxy_ReadOnly< Sizing >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_width() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fixed_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_width() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expand() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_expand() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_clickable() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_clickable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_widget() -> Glib::PropertyProxy< Widget* > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alignment() -> Glib::PropertyProxy< float > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_alignment() const -> Glib::PropertyProxy_ReadOnly< float >;

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

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_indicator() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_indicator() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: Gtk::SortType::ASCENDING
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_order() -> Glib::PropertyProxy< SortType > ;

/** Default value: Gtk::SortType::ASCENDING
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_order() const -> Glib::PropertyProxy_ReadOnly< SortType >;

  /** Logical sort column ID this column sorts on when selected for sorting. Setting the sort column ID makes the column header
   * clickable. Set to -1 to make the column unsortable.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_column_id() -> Glib::PropertyProxy< int > ;

/** Logical sort column ID this column sorts on when selected for sorting. Setting the sort column ID makes the column header
   * clickable. Set to -1 to make the column unsortable.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sort_column_id() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The `Gtk::CellArea` used to layout cell renderers for this column.
   *
   * If no area is specified when creating the tree view column with Gtk::TreeViewColumn::new_with_area()
   * a horizontally oriented `Gtk::CellAreaBox` will be used.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
  // Only necessary because of the templated ctor, see below.
  static auto class_init_() -> const Glib::Class&;
#endif //DOXYGEN_SHOULD_SKIP_THIS


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template<class T_ModelColumnType> inline
void TreeViewColumn::pack_start(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
{
  //Generate appropriate Renderer for the column:
  CellRenderer* pCellRenderer = manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>() );

  //Use the renderer:
  pack_start(*pCellRenderer, expand);
  set_renderer(*pCellRenderer, column);
}

template<class T_ModelColumnType> inline
void TreeViewColumn::pack_end(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
{
  //Generate appropriate Renderer for the column:
  CellRenderer* pCellRenderer= manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>() );

  //Use the renderer:
  pack_end(*pCellRenderer, expand);
  set_renderer(*pCellRenderer, column);
}

template <class T_ModelColumnType> inline
TreeViewColumn::TreeViewColumn(const Glib::ustring& title,
                               const TreeModelColumn<T_ModelColumnType>& column)
:
  Glib::ObjectBase(nullptr), // not (yet) a custom class
  Gtk::Object(Glib::ConstructParams(class_init_(), "title", title.c_str(), nullptr))
{
  pack_start(column, true /* expand */);
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::TreeViewColumn::Sizing> : public Glib::Value_Enum<Gtk::TreeViewColumn::Sizing>
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
   * @relates Gtk::TreeViewColumn
   */
  GTKMM_API
  auto wrap(GtkTreeViewColumn* object, bool take_copy = false) -> Gtk::TreeViewColumn*;
} //namespace Glib


#endif /* _GTKMM_TREEVIEWCOLUMN_H */

