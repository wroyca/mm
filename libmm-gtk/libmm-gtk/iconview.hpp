
#ifndef _GTKMM_ICONVIEW_H
#define _GTKMM_ICONVIEW_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2004 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gtk/treepath.hpp>
#include <libmm-gtk/celllayout.hpp>
#include <libmm-gtk/cellarea.hpp>
#include <libmm-gtk/cellrenderer.hpp>
#include <libmm-gtk/scrollable.hpp>
#include <libmm-gtk/tooltip.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconView = struct _GtkIconView;
using GtkIconViewClass = struct _GtkIconViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API IconView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** The IconView provides an alternative view of a list model.
 * It displays the model as a grid of icons with labels.
 * Like the TreeView, it allows the user to select one or multiple items
 * (depending on the selection mode - see set_selection_mode()).
 * In addition to selection with the arrow keys, the IconView supports
 * rubberband selection, by dragging the pointer.
 *
 * @ingroup Widgets
 */

class GTKMM_API IconView
 : public Widget,
   public CellLayout,
   public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef IconView CppObjectType;
  typedef IconView_Class CppClassType;
  typedef GtkIconView BaseObjectType;
  typedef GtkIconViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  IconView(IconView&& src) noexcept;
  auto operator=(IconView&& src) noexcept -> IconView&;

  // noncopyable
  IconView(const IconView&) = delete;
  auto operator=(const IconView&) -> IconView& = delete;

  ~IconView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class IconView_Class;
  static CppClassType iconview_class_;

protected:
  explicit IconView(const Glib::ConstructParams& construct_params);
  explicit IconView(GtkIconView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkIconView*       { return reinterpret_cast<GtkIconView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkIconView* { return reinterpret_cast<GtkIconView*>(gobject_); }

private:


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var DropPosition NO_DROP
   * No drop possible.
   *
   *  @var DropPosition DROP_INTO
   * Dropped item replaces the item.
   *
   *  @var DropPosition DROP_LEFT
   * Dropped item is inserted to the left.
   *
   *  @var DropPosition DROP_RIGHT
   * Dropped item is inserted to the right.
   *
   *  @var DropPosition DROP_ABOVE
   * Dropped item is inserted above.
   *
   *  @var DropPosition DROP_BELOW
   * Dropped item is inserted below.
   *
   *  @enum DropPosition
   *
   * An enum for determining where a dropped item goes.
   *
   * @ingroup gtkmmEnums
   */
  enum class DropPosition
  {
    NO_DROP,
    DROP_INTO,
    DROP_LEFT,
    DROP_RIGHT,
    DROP_ABOVE,
    DROP_BELOW
  };


  IconView();
    explicit IconView(const Glib::RefPtr<TreeModel>& model);

    explicit IconView(const Glib::RefPtr<CellArea>& cell_area);


  /** Sets the model for a Gtk::IconView.
   * If the @a icon_view already has a model set, it will remove
   * it before setting the new model. Use unset_model() to
   * unset the old model.
   *
   * @newin{2,6}
   *
   * @param model The model.
   */
  void set_model(const Glib::RefPtr<TreeModel>& model);

  /** Returns the model the `Gtk::IconView` is based on.  Returns <tt>nullptr</tt> if the
   * model is unset.
   *
   * @return The currently used `Gtk::TreeModel`.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the model the `Gtk::IconView` is based on.  Returns <tt>nullptr</tt> if the
   * model is unset.
   *
   * @return The currently used `Gtk::TreeModel`.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;

  /** Remove the model from the IconView.
   *
   * @see set_model().
   *
   * @newin{2,16}
   */
  void unset_model();


  /** Sets the column with text for @a icon_view to be @a column. The text
   * column must be of type `G_TYPE_STRING`.
   *
   * @param column A column in the currently used model, or -1 to display no text.
   */
  void set_text_column(int column);

  /** Sets the column with text for @a icon_view to be @a model_column. The text
   * column must be of type `G_TYPE_STRING`.
   *
   * @param model_column A column in the currently used model, or -1 to display no text.
   */
  void set_text_column(const TreeModelColumnBase& model_column);

  /** Returns the column with text for @a icon_view.
   *
   * @return The text column, or -1 if it’s unset.
   */
  auto get_text_column() const -> int;

  /** Sets the column with markup information for @a icon_view to be
   *  @a column. The markup column must be of type `G_TYPE_STRING`.
   * If the markup column is set to something, it overrides
   * the text column set by set_text_column().
   *
   * @param column A column in the currently used model, or -1 to display no text.
   */
  void set_markup_column(int column);

  /** Sets the column with markup information for @a icon_view to be
   *  @a column. The markup column must be of type `G_TYPE_STRING`.
   * If the markup column is set to something, it overrides
   * the text column set by set_text_column().
   *
   * @param column A column in the currently used model, or -1 to display no text.
   */
  void set_markup_column(const TreeModelColumnBase& column);

  /** Returns the column with markup text for @a icon_view.
   *
   * @return The markup column, or -1 if it’s unset.
   */
  auto get_markup_column() const -> int;

  /** Sets the column with pixbufs for @a icon_view to be @a column. The pixbuf
   * column must be of type `GDK_TYPE_PIXBUF`
   *
   * @param column A column in the currently used model, or -1 to disable.
   */
  void set_pixbuf_column(int column);

  /** Sets the column with pixbufs for @a icon_view to be @a column. The pixbuf
   * column must be of type `GDK_TYPE_PIXBUF`
   *
   * @param column A column in the currently used model, or -1 to disable.
   */
  void set_pixbuf_column(const TreeModelColumnBase& column);

  /** Returns the column with pixbufs for @a icon_view.
   *
   * @return The pixbuf column, or -1 if it’s unset.
   */
  auto get_pixbuf_column() const -> int;


  /** Sets the property_item_orientation() property which determines whether the labels
   * are drawn beside the icons instead of below.
   *
   * @param orientation The relative position of texts and icons.
   */
  void set_item_orientation(Orientation orientation);

  /** Returns the value of the property_item_orientation() property which determines
   * whether the labels are drawn beside the icons instead of below.
   *
   * @return The relative position of texts and icons.
   */
  auto get_item_orientation() const -> Orientation;


  /** Sets the property_columns() property which determines in how
   * many columns the icons are arranged. If @a columns is
   * -1, the number of columns will be chosen automatically
   * to fill the available area.
   *
   * @param columns The number of columns.
   */
  void set_columns(int columns);

  /** Returns the value of the property_columns() property.
   *
   * @return The number of columns, or -1.
   */
  auto get_columns() const -> int;

  /** Sets the property_item_width() property which specifies the width
   * to use for each item. If it is set to -1, the icon view will
   * automatically determine a suitable item size.
   *
   * @param item_width The width for each item.
   */
  void set_item_width(int item_width);

  /** Returns the value of the property_item_width() property.
   *
   * @return The width of a single item, or -1.
   */
  auto get_icon_width() const -> int;

  /** Sets the property_spacing() property which specifies the space
   * which is inserted between the cells (i.e.\ the icon and
   * the text) of an item.
   *
   * @param spacing The spacing.
   */
  void set_spacing(int spacing);

  /** Returns the value of the property_spacing() property.
   *
   * @return The space between cells.
   */
  auto get_spacing() const -> int;

  /** Sets the property_row_spacing() property which specifies the space
   * which is inserted between the rows of the icon view.
   *
   * @param row_spacing The row spacing.
   */
  void set_row_spacing(int row_spacing);

  /** Returns the value of the property_row_spacing() property.
   *
   * @return The space between rows.
   */
  auto get_row_spacing() const -> int;

  /** Sets the property_column_spacing() property which specifies the space
   * which is inserted between the columns of the icon view.
   *
   * @param column_spacing The column spacing.
   */
  void set_column_spacing(int column_spacing);

  /** Returns the value of the property_column_spacing() property.
   *
   * @return The space between columns.
   */
  auto get_column_spacing() const -> int;


  /** Sets the property_margin() property which specifies the space
   * which is inserted at the top, bottom, left and right
   * of the icon view.
   *
   * @param margin The margin.
   */
  void set_margin(int margin);

  /** Returns the value of the property_margin() property.
   *
   * @return The space at the borders.
   */
  auto get_margin() const -> int;


  /** Sets the `Gtk::IconView`:item-padding property which specifies the padding
   * around each of the icon view’s items.
   *
   * @param item_padding The item padding.
   */
  void set_item_padding(int item_padding);

  /** Returns the value of the property_item_padding() property.
   *
   * @return The padding around items.
   */
  auto get_item_padding() const -> int;


  /** Gets the path for the icon at the given position.
   *
   * @param x The x position to be identified.
   * @param y The y position to be identified.
   * @return The `Gtk::TreePath` corresponding
   * to the icon or <tt>nullptr</tt> if no icon exists at that position.
   */
  auto get_path_at_pos(int x, int y) const -> TreeModel::Path;


  /** Finds the path at the point (@a x, @a y), relative to widget coordinates.
   *
   * @param x The x position to be identified.
   * @param y The y position to be identified.
   * @param[out] path The path.
   * @param[out] cell The renderer responsible for the cell at (@a x, @a y).
   * @result true if an item exists at the specified position.
   *
   * @newin{2,6}
   */
  auto get_item_at_pos(int x, int y, TreeModel::Path& path, CellRenderer*& cell) const -> bool;

  /** Finds the path at the point (@a x, @a y), relative to widget coordinates.
   *
   * @param x The x position to be identified.
   * @param y The y position to be identified.
   * @param[out] path The path.
   * @result true if an item exists at the specified position.
   *
   * @newin{2,6}
   */
  auto get_item_at_pos(int x, int y, TreeModel::Path& path) const -> bool;

  /** Finds the path at the point (@a x, @a y), relative to widget coordinates.
   *
   * @param x The x position to be identified.
   * @param y The y position to be identified.
   * @param[out] cell The renderer responsible for the cell at (@a x, @a y).
   * @result true if an item exists at the specified position.
   *
   * @newin{2,6}
   */
  auto get_item_at_pos(int x, int y, CellRenderer*& cell) const -> bool;


  /** Sets @a start_path and @a end_path to be the first and last visible path.
   * Note that there may be invisible paths in between.
   *
   * @param[out] start_path Return location for start of region.
   * @param[out] end_path Return location for end of region.
   * @result <tt>true</tt> if valid paths were placed in @a start_path and @a end_path.
   */
  auto get_visible_range(TreeModel::Path& start_path, TreeModel::Path& end_path) const -> bool;


  /** Causes the `Gtk::IconView`::item-activated signal to be emitted on
   * a single click instead of a double click.
   *
   * @param single <tt>true</tt> to emit item-activated on a single click.
   */
  void set_activate_on_single_click(bool single =  true);

  /** Gets the setting set by set_activate_on_single_click().
   *
   * @return <tt>true</tt> if item-activated will be emitted on a single click.
   */
  auto get_activate_on_single_click() const -> bool;

  /** For instance,
   * void on_foreach(const Gtk::TreeModel::Path& path);
   */
  using SlotForeach = sigc::slot<void(const TreeModel::Path&)>;

  /** Calls a function for each selected icon. Note that the model or
  * selection cannot be modified from within this function.
  *
  * @param slot The callback to call for each selected icon.
  */
  void selected_foreach(const SlotForeach& slot);


//Default value?:

  /** Sets the selection mode of the @a icon_view.
   *
   * @param mode The selection mode.
   */
  void set_selection_mode(SelectionMode mode);

  /** Gets the selection mode of the @a icon_view.
   *
   * @return The current selection mode.
   */
  auto get_selection_mode() const -> SelectionMode;

  /** Selects the row at @a path.
   *
   * @param path The `Gtk::TreePath` to be selected.
   */
  void select_path(const TreeModel::Path& path);

  /** Unselects the row at @a path.
   *
   * @param path The `Gtk::TreePath` to be unselected.
   */
  void unselect_path(const TreeModel::Path& path);

  /** Returns <tt>true</tt> if the icon pointed to by @a path is currently
   * selected. If @a path does not point to a valid location, <tt>false</tt> is returned.
   *
   * @param path A `Gtk::TreePath` to check selection on.
   * @return <tt>true</tt> if @a path is selected.
   */
  auto path_is_selected(const TreeModel::Path& path) const -> bool;


  /** Gets the row in which the item @a path is currently
   * displayed. Row numbers start at 0.
   *
   * @param path The `Gtk::TreePath` of the item.
   * @return The row in which the item is displayed.
   */
  auto get_item_row(const TreeModel::Path& path) const -> int;

  /** Gets the column in which the item @a path is currently
   * displayed. Column numbers start at 0.
   *
   * @param path The `Gtk::TreePath` of the item.
   * @return The column in which the item is displayed.
   */
  auto get_item_column(const TreeModel::Path& path) const -> int;


  /** Creates a list of paths of all selected items. Additionally, if you are
   * planning on modifying the model after calling this function, you may
   * want to convert the returned list into a list of `Gtk::TreeRowReferences`.
   * To do this, you can use Gtk::TreeRowReference::new().
   *
   * To free the return value, use `g_list_free_full`:
   *
   * [C example ellipted]
   *
   * @return A `GList` containing a `Gtk::TreePath` for each selected row.
   */
  auto get_selected_items() const -> std::vector<TreePath>;


  /** Selects all the icons. @a icon_view must has its selection mode set
   * to Gtk::SelectionMode::MULTIPLE.
   */
  void select_all();

  /** Unselects all the icons.
   */
  void unselect_all();

  /** Activates the item determined by @a path.
   *
   * @param path The `Gtk::TreePath` to be activated.
   */
  void item_activated(const TreeModel::Path& path);


  /** Sets the current keyboard focus to be at @a path, and selects it.  This is
   * useful when you want to focus the user’s attention on a particular item.
   * If @a cell is not <tt>nullptr</tt>, then focus is given to the cell specified by
   * it. Additionally, if @a start_editing is <tt>true</tt>, then editing should be
   * started in the specified cell.
   *
   * This function is often followed by `gtk_widget_grab_focus
   * (icon_view)` in order to give keyboard focus to the widget.
   * Please note that editing can only happen when the widget is realized.
   *
   * @param path A `Gtk::TreePath`.
   * @param cell One of the cell renderers of @a icon_view.
   * @param start_editing <tt>true</tt> if the specified cell should start being edited.
   */
  void set_cursor(const TreeModel::Path& path, CellRenderer& cell, bool start_editing);

  /// A set_cursor() convenience overload.
  void set_cursor(const TreeModel::Path& path, bool start_editing);

  /** Fills in @a path and @a cell with the current cursor path and cell.
   * If the cursor isn't currently set, then @a path will be empty.
   * If no cell currently has focus, then @a cell will be nullptr.
   *
   * @param[out] path The current cursor path.
   * @param[out] cell The current focus cell.
   * @result true if the cursor is set.
   *
   * @newin{2,8}
   */
  auto get_cursor(TreeModel::Path& path, CellRenderer*& cell) const -> bool;

  /** Fills in @a path and @a cell with the current cursor path and cell.
   * If the cursor isn't currently set, then @a path will be empty.
   * If no cell currently has focus, then @a cell will be nullptr.
   *
   * @param[out] path The current cursor path.
   * @result true if the cursor is set.
   *
   * @newin{2,8}
   */
  auto get_cursor(TreeModel::Path& path) const -> bool;

  /** Fills in @a path and @a cell with the current cursor path and cell.
   * If the cursor isn't currently set, then @a path will be empty.
   * If no cell currently has focus, then @a cell will be nullptr.
   *
   * @param[out] cell The current focus cell.
   * @result true if the cursor is set.
   *
   * @newin{2,8}
   */
  auto get_cursor(CellRenderer*& cell) const -> bool;


  /** Moves the alignments of @a icon_view to the position specified by @a path.
   *  @a row_align determines where the row is placed, and @a col_align determines
   * where @a column is placed.  Both are expected to be between 0.0 and 1.0.
   * 0.0 means left/top alignment, 1.0 means right/bottom alignment, 0.5 means
   * center.
   *
   * If @a use_align is <tt>false</tt>, then the alignment arguments are ignored, and the
   * tree does the minimum amount of work to scroll the item onto the screen.
   * This means that the item will be scrolled to the edge closest to its current
   * position.  If the item is currently visible on the screen, nothing is done.
   *
   * This function only works if the model is set, and @a path is a valid row on
   * the model. If the model changes before the @a icon_view is realized, the
   * centered path will be modified to reflect this change.
   *
   * @param path The path of the item to move to.
   * @param use_align Whether to use alignment arguments, or <tt>false</tt>.
   * @param row_align The vertical alignment of the item specified by @a path.
   * @param col_align The horizontal alignment of the item specified by @a path.
   */
  void scroll_to_path(const TreeModel::Path& path, bool use_align, float row_align, float col_align);

/* Drag-and-Drop support */
  // Gdk::ContentFormats is an immutable object. It can be declared const
  // in input parameters. No one can change it.


  /** Turns @a icon_view into a drag source for automatic DND. Calling this
   * method sets `Gtk::IconView`:reorderable to <tt>false</tt>.
   *
   * @param start_button_mask Mask of allowed buttons to start drag.
   * @param formats The formats that the drag will support.
   * @param actions The bitmask of possible actions for a drag from this
   * widget.
   */
  void enable_model_drag_source(const Glib::RefPtr<const Gdk::ContentFormats>& formats, Gdk::ModifierType start_button_mask =  static_cast<Gdk::ModifierType>(GDK_MODIFIER_MASK), Gdk::DragAction actions =  Gdk::DragAction::COPY | Gdk::DragAction::MOVE);


  /** Turns @a icon_view into a drop destination for automatic DND. Calling this
   * method sets `Gtk::IconView`:reorderable to <tt>false</tt>.
   *
   * @param formats The formats that the drag will support.
   * @param actions The bitmask of possible actions for a drag to this
   * widget.
   */
  void enable_model_drag_dest(const Glib::RefPtr<const Gdk::ContentFormats>& formats, Gdk::DragAction actions =  Gdk::DragAction::COPY | Gdk::DragAction::MOVE);


  /** Undoes the effect of enable_model_drag_source(). Calling this
   * method sets `Gtk::IconView`:reorderable to <tt>false</tt>.
   */
  void unset_model_drag_source();

  /** Undoes the effect of enable_model_drag_dest(). Calling this
   * method sets `Gtk::IconView`:reorderable to <tt>false</tt>.
   */
  void unset_model_drag_dest();


  /** This function is a convenience function to allow you to reorder models that
   * support the `Gtk::TreeDragSourceIface` and the `Gtk::TreeDragDestIface`. Both
   * `Gtk::TreeStore` and `Gtk::ListStore` support these. If @a reorderable is <tt>true</tt>, then
   * the user can reorder the model by dragging and dropping rows.  The
   * developer can listen to these changes by connecting to the model's
   * row_inserted and row_deleted signals. The reordering is implemented by setting up
   * the icon view as a drag source and destination. Therefore, drag and
   * drop can not be used in a reorderable view for any other purpose.
   *
   * This function does not give you any degree of control over the order -- any
   * reordering is allowed.  If more control is needed, you should probably
   * handle drag and drop manually.
   *
   * @param reorderable <tt>true</tt>, if the list of items can be reordered.
   */
  void set_reorderable(bool reorderable =  true);

  /** Retrieves whether the user can reorder the list via drag-and-drop.
   * See set_reorderable().
   *
   * @return <tt>true</tt> if the list can be reordered.
   */
  auto get_reorderable() const -> bool;

/* These are useful to implement your own custom stuff. */

  /** Sets the item that is highlighted for feedback.
   *
   * @param path The path of the item to highlight.
   * @param pos Specifies where to drop, relative to the item.
   */
  void set_drag_dest_item(const TreeModel::Path& path, DropPosition pos);

  /** Gets information about the item that is highlighted for feedback.
   *
   * @param[out] path The highlighted item.
   * @param[out] pos The drop position.
   *
   * @newin{2,10}
   */
  void get_drag_dest_item(TreeModel::Path& path, DropPosition& pos) const;

  /** Gets information about the item that is highlighted for feedback.
   *
   * @param[out] path The highlighted item.
   *
   * @newin{2,10}
   */
  void get_drag_dest_item(TreeModel::Path& path) const;

  /** Gets information about the item that is highlighted for feedback.
   *
   * @param[out] pos The drop position.
   *
   * @newin{2,10}
   */
  void get_drag_dest_item(DropPosition& pos) const;


  /** Determines the destination item for a given position.
   *
   * @param drag_x The position to determine the destination item for.
   * @param drag_y the position to determine the destination item for.
   * @param[out] path The path of the item.
   * @param[out] pos The drop position.
   * @result Whether there is an item at the given position.
   *
   * @newin{2,10}
   */
  auto get_dest_item_at_pos(int drag_x, int drag_y, TreeModel::Path& path, DropPosition& pos) const -> bool;

  /** Determines the destination item for a given position.
   *
   * @param drag_x The position to determine the destination item for.
   * @param drag_y the position to determine the destination item for.
   * @param[out] path The path of the item.
   * @result Whether there is an item at the given position.
   *
   * @newin{2,10}
   */
  auto get_dest_item_at_pos(int drag_x, int drag_y, TreeModel::Path& path) const -> bool;

  /** Determines the destination item for a given position.
   *
   * @param drag_x The position to determine the destination item for.
   * @param drag_y the position to determine the destination item for.
   * @param[out] pos The drop position.
   * @result Whether there is an item at the given position.
   *
   * @newin{2,10}
   */
  auto get_dest_item_at_pos(int drag_x, int drag_y, DropPosition& pos) const -> bool;


  // create_drag_icon() is const because it returns a newly created Gdk::Paintable.

  /** Creates a `Gdk::Paintable` representation of the item at @a path.
   * This image is used for a drag icon.
   *
   * @param path A `Gtk::TreePath` in @a icon_view.
   * @return A newly-allocated `Gdk::Paintable` of the drag icon.
   */
  auto create_drag_icon(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::Paintable>;


  /** Fills the bounding rectangle in widget coordinates for the cell specified by
   *  @a path and @a cell. If @a cell is <tt>nullptr</tt> the main cell area is used.
   *
   * This function is only valid if @a icon_view is realized.
   *
   * @param path A `Gtk::TreePath`.
   * @param cell A `Gtk::CellRenderer`.
   * @param rect Rectangle to fill with cell rect.
   * @return <tt>false</tt> if there is no such item, <tt>true</tt> otherwise.
   */
  auto get_cell_rect(const TreeModel::Path& path, const CellRenderer& cell, Gdk::Rectangle& rect) const -> bool;

  /// A get_cell_rect() convenience overload.
  auto get_cell_rect(const TreeModel::Path& path, Gdk::Rectangle& rect) const -> bool;


  /** Sets the tip area of @a tooltip to be the area covered by the item at @a path.
   * See also Tooltip::set_tip_area().
   *
   * @newin{2,12}
   *
   * @param tooltip A `Gtk::Tooltip`.
   * @param path A `Gtk::TreePath`.
   */
  void set_tooltip_item(const Glib::RefPtr<Tooltip>& tooltip, const TreeModel::Path& path);

  /** Sets the tip area of @a tooltip to the area which @a cell occupies in
   * the item pointed to by @a path. See also Tooltip::set_tip_area().
   *
   * @newin{2,12}
   *
   * @param tooltip A Gtk::Tooltip.
   * @param path A Gtk::TreePath.
   * @param cell A Gtk::CellRenderer.
   */
  void set_tooltip_cell(const Glib::RefPtr<Tooltip>& tooltip, const TreeModel::Path& path, CellRenderer& cell);

  /** Sets the tip area of @a tooltip to the area occupied by
   * the item pointed to by @a path. See also Tooltip::set_tip_area().
   *
   * @newin{2,12}
   *
   * @param tooltip A Gtk::Tooltip.
   * @param path A Gtk::TreePath.
   */
  void set_tooltip_cell(const Glib::RefPtr<Tooltip>& tooltip, const TreeModel::Path& path);

  /** This function is supposed to be used in a Gtk::Widget::query-tooltip
   * signal handler for Gtk::IconView. The x, y and keyboard_tip values
   * which are received in the signal handler, should be passed to this
   * function without modification.
   *
   * The return value indicates whether there is an icon view item at the given
   * coordinates (true) or not (false) for mouse tooltips. For keyboard
   * tooltips the item returned will be the cursor item. When true, then the
   * @a path which has been provided will be set to point to
   * that row and the corresponding model.
   *
   * @param x The x coordinate (relative to widget coordinates)
   * @param y The y coordinate (relative to widget coordinates)
   * @param keyboard_tip Whether this is a keyboard tooltip or not
   * @param[out] path A reference to receive a Gtk::TreePath
   * @result Whether or not the given tooltip context points to an item.
   *
   * @newin{2,12}
   */
  auto get_tooltip_context_path(int x, int y,
                                bool keyboard_tip,
                                TreeModel::Path& path) -> bool;

  /** This function is supposed to be used in a Gtk::Widget::query-tooltip
   * signal handler for Gtk::IconView. The x, y and keyboard_tip values
   * which are received in the signal handler, should be passed to this
   * function without modification.
   *
   * The return value indicates whether there is an icon view item at the given
   * coordinates (true) or not (false) for mouse tooltips. For keyboard
   * tooltips the item returned will be the cursor item. When true, then the
   * @a iter which has been provided will be set to point to
   * that row and the corresponding model.
   *
   * @param x The x coordinate (relative to widget coordinates)
   * @param y The y coordinate (relative to widget coordinates)
   * @param keyboard_tip Whether this is a keyboard tooltip or not
   * @param[out] iter A reference to receive a Gtk::TreeModel::iterator
   * @result Whether or not the given tooltip context points to an item.
   *
   * @newin{2,12}
   */
  auto get_tooltip_context_iter(int x, int y,
                                bool keyboard_tip,
                                Gtk::TreeModel::iterator& iter) -> bool;


  /** If you only plan to have simple (text-only) tooltips on full items, you
   * can use this function to have `Gtk::IconView` handle these automatically
   * for you. @a column should be set to the column in @a icon_view’s model
   * containing the tooltip texts, or -1 to disable this feature.
   *
   * When enabled, `GtkWidget:has-tooltip` will be set to <tt>true</tt> and
   *  @a icon_view will connect a `GtkWidget::query-tooltip` signal handler.
   *
   * Note that the signal handler sets the text with Gtk::Tooltip::set_markup(),
   * so &, <, etc have to be escaped in the text.
   *
   * @param column An integer, which is a valid column number for @a icon_view’s model.
   */
  void set_tooltip_column(int column);

  /** Returns the column of @a icon_view’s model which is being used for
   * displaying tooltips on @a icon_view’s rows.
   *
   * @return The index of the tooltip column that is currently being
   * used, or -1 if this is disabled.
   */
  auto get_tooltip_column() const -> int;

  // no_default_handler because GtkIconViewClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%item_activated(const TreeModel::Path& path)</tt>
   *
   * Flags: Run Last
   *
   * The signal_item_activated() signal is emitted when the method
   * Gtk::IconView::item_activated() is called, when the user double
   * clicks an item with the "activate-on-single-click" property set
   * to <tt>false</tt>, or when the user single clicks an item when the
   * "activate-on-single-click" property set to <tt>true</tt>. It is also
   * emitted when a non-editable item is selected and one of the keys:
   * Space, Return or Enter is pressed.
   *
   * @param path The `Gtk::TreePath` for the activated item.
   */

  auto signal_item_activated() -> Glib::SignalProxy<void(const TreeModel::Path&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%selection_changed()</tt>
   *
   * Flags: Run First
   *
   * The signal_selection_changed() signal is emitted when the selection
   * (i.e.\ the set of selected items) changes.
   */

  auto signal_selection_changed() -> Glib::SignalProxy<void()>;


  /* Key binding signals */


  /** The property_pixbuf_column() property contains the number of the model column
   * containing the pixbufs which are displayed. The pixbuf column must be
   * of type `GDK_TYPE_PIXBUF`. Setting this property to -1 turns off the
   * display of pixbufs.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_column() -> Glib::PropertyProxy< int > ;

/** The property_pixbuf_column() property contains the number of the model column
   * containing the pixbufs which are displayed. The pixbuf column must be
   * of type `GDK_TYPE_PIXBUF`. Setting this property to -1 turns off the
   * display of pixbufs.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixbuf_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The property_text_column() property contains the number of the model column
   * containing the texts which are displayed. The text column must be
   * of type `G_TYPE_STRING`. If this property and the :markup-column
   * property are both set to -1, no texts are displayed.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_column() -> Glib::PropertyProxy< int > ;

/** The property_text_column() property contains the number of the model column
   * containing the texts which are displayed. The text column must be
   * of type `G_TYPE_STRING`. If this property and the :markup-column
   * property are both set to -1, no texts are displayed.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_text_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The property_markup_column() property contains the number of the model column
   * containing markup information to be displayed. The markup column must be
   * of type `G_TYPE_STRING`. If this property and the :text-column property
   * are both set to column numbers, it overrides the text column.
   * If both are set to -1, no texts are displayed.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_markup_column() -> Glib::PropertyProxy< int > ;

/** The property_markup_column() property contains the number of the model column
   * containing markup information to be displayed. The markup column must be
   * of type `G_TYPE_STRING`. If this property and the :text-column property
   * are both set to column numbers, it overrides the text column.
   * If both are set to -1, no texts are displayed.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_markup_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The property_selection_mode() property specifies the selection mode of
   * icon view. If the mode is Gtk::SelectionMode::MULTIPLE, rubberband selection
   * is enabled, for the other modes, only keyboard selection is possible.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selection_mode() -> Glib::PropertyProxy< SelectionMode > ;

/** The property_selection_mode() property specifies the selection mode of
   * icon view. If the mode is Gtk::SelectionMode::MULTIPLE, rubberband selection
   * is enabled, for the other modes, only keyboard selection is possible.
   *
   * Default value: Gtk::SelectionMode::SINGLE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_selection_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >;

  /** The item-orientation property specifies how the cells (i.e.\ the icon and
   * the text) of the item are positioned relative to each other.
   *
   * Default value: Gtk::Orientation::VERTICAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_orientation() -> Glib::PropertyProxy< Orientation > ;

/** The item-orientation property specifies how the cells (i.e.\ the icon and
   * the text) of the item are positioned relative to each other.
   *
   * Default value: Gtk::Orientation::VERTICAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_orientation() const -> Glib::PropertyProxy_ReadOnly< Orientation >;

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

  /** The columns property contains the number of the columns in which the
   * items should be displayed. If it is -1, the number of columns will
   * be chosen automatically to fill the available area.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_columns() -> Glib::PropertyProxy< int > ;

/** The columns property contains the number of the columns in which the
   * items should be displayed. If it is -1, the number of columns will
   * be chosen automatically to fill the available area.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_columns() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The item-width property specifies the width to use for each item.
   * If it is set to -1, the icon view will automatically determine a
   * suitable item size.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_width() -> Glib::PropertyProxy< int > ;

/** The item-width property specifies the width to use for each item.
   * If it is set to -1, the icon view will automatically determine a
   * suitable item size.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The spacing property specifies the space which is inserted between
   * the cells (i.e.\ the icon and the text) of an item.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() -> Glib::PropertyProxy< int > ;

/** The spacing property specifies the space which is inserted between
   * the cells (i.e.\ the icon and the text) of an item.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The row-spacing property specifies the space which is inserted between
   * the rows of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() -> Glib::PropertyProxy< int > ;

/** The row-spacing property specifies the space which is inserted between
   * the rows of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The column-spacing property specifies the space which is inserted between
   * the columns of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() -> Glib::PropertyProxy< int > ;

/** The column-spacing property specifies the space which is inserted between
   * the columns of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The margin property specifies the space which is inserted
   * at the edges of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin() -> Glib::PropertyProxy< int > ;

/** The margin property specifies the space which is inserted
   * at the edges of the icon view.
   *
   * Default value: 6
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_margin() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The reorderable property specifies if the items can be reordered
   * by DND.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() -> Glib::PropertyProxy< int > ;

/** The reorderable property specifies if the items can be reordered
   * by DND.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() const -> Glib::PropertyProxy_ReadOnly< int >;

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

  /** The item-padding property specifies the padding around each
   * of the icon view's item.
   *
   * Default value: 6
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_padding() -> Glib::PropertyProxy< int > ;

/** The item-padding property specifies the padding around each
   * of the icon view's item.
   *
   * Default value: 6
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_item_padding() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The `Gtk::CellArea` used to layout cell renderers for this view.
   *
   * If no area is specified when creating the icon view with Gtk::IconView::new_with_area()
   * a `Gtk::CellAreaBox` will be used.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >;


  /** The activate-on-single-click property specifies whether the "item-activated" signal
   * will be emitted after a single click.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() -> Glib::PropertyProxy< bool > ;

/** The activate-on-single-click property specifies whether the "item-activated" signal
   * will be emitted after a single click.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::IconView::DropPosition> : public Glib::Value_Enum<Gtk::IconView::DropPosition>
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
   * @relates Gtk::IconView
   */
  GTKMM_API
  auto wrap(GtkIconView* object, bool take_copy = false) -> Gtk::IconView*;
} //namespace Glib


#endif /* _GTKMM_ICONVIEW_H */

