
#ifndef _GTKMM_GRID_H
#define _GTKMM_GRID_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/orientable.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGrid = struct _GtkGrid;
using GtkGridClass = struct _GtkGridClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Grid_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container which arranges its child widgets in rows and columns.
 * It is very similar to Box,
 * but it consistently uses Widget's margin and expand
 * properties instead of custom child properties, and it fully supports
 * height-for-width geometry management.
 *
 * Children are added using attach(). They can span multiple
 * rows or columns. It is also possible to add a child next to an
 * existing child, using attach_next_to(). To remove a child
 * from the grid, use remove(). The behaviour of %Grid when
 * several children occupy the same grid cell is undefined.
 *
 * @ingroup Widgets
 * @ingroup Containers
 *
 * @newin{3,0}
 */

class GTKMM_API Grid
  : public Widget,
    public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Grid CppObjectType;
  typedef Grid_Class CppClassType;
  typedef GtkGrid BaseObjectType;
  typedef GtkGridClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Grid(Grid&& src) noexcept;
  auto operator=(Grid&& src) noexcept -> Grid&;

  // noncopyable
  Grid(const Grid&) = delete;
  auto operator=(const Grid&) -> Grid& = delete;

  ~Grid() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Grid_Class;
  static CppClassType grid_class_;

protected:
  explicit Grid(const Glib::ConstructParams& construct_params);
  explicit Grid(GtkGrid* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkGrid*       { return reinterpret_cast<GtkGrid*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGrid* { return reinterpret_cast<GtkGrid*>(gobject_); }

private:


public:
  Grid();


  /** Adds a widget to the grid.
   *
   * The position of @a child is determined by @a column and @a row.
   * The number of “cells” that @a child will occupy is determined
   * by @a width and @a height.
   *
   * @param child The widget to add.
   * @param column The column number to attach the left side of @a child to.
   * @param row The row number to attach the top side of @a child to.
   * @param width The number of columns that @a child will span.
   * @param height The number of rows that @a child will span.
   */
  void attach(Widget& child, int column, int row, int width =  1, int height =  1);


  /** Adds a widget to the grid.
   *
   * The widget is placed next to @a sibling, on the side determined by
   * @a side. The %attach_next_to() without the @a sibling parameter
   * places the widget in row 0 (for left or right placement) or column 0
   * (for top or bottom placement), at the end indicated by @a side.
   *
   * Attaching widgets labeled [1], [2], [3] without the @a sibling parameter and
   * @a side == Gtk::PositionType::LEFT yields a layout of [3][2][1].
   *
   * @param child The widget to add.
   * @param sibling The child of @a grid that @a child will be placed
   *        next to, or omitted to place @a child at the beginning or end.
   * @param side The side of @a sibling that @a child is positioned next to.
   * @param width The number of columns that @a child will span.
   * @param height The number of rows that @a child will span.
   */
  void attach_next_to(Widget& child, Widget& sibling, PositionType side, int width =  1, int height =  1);

  /// A attach_next_to() convenience overload.
  void attach_next_to(Widget& child, PositionType side, int width =  1, int height =  1);


  /** Gets the child of @a grid whose area covers the grid
   * cell at @a column, @a row.
   *
   * @param column The left edge of the cell.
   * @param row The top edge of the cell.
   * @return The child at the given position.
   */
  auto get_child_at(int column, int row) -> Widget*;

  /** Gets the child of @a grid whose area covers the grid
   * cell at @a column, @a row.
   *
   * @param column The left edge of the cell.
   * @param row The top edge of the cell.
   * @return The child at the given position.
   */
  auto get_child_at(int column, int row) const -> const Widget*;

  /** Removes a child from @a grid.
   *
   * The child must have been added with
   * attach() or attach_next_to().
   *
   * @param child The child widget to remove.
   */
  void remove(Widget& child);

  /** Inserts a row at the specified position.
   *
   * Children which are attached at or below this position
   * are moved one row down. Children which span across this
   * position are grown to span the new row.
   *
   * @param position The position to insert the row at.
   */
  void insert_row(int position);

  /** Inserts a column at the specified position.
   *
   * Children which are attached at or to the right of this position
   * are moved one column to the right. Children which span across this
   * position are grown to span the new column.
   *
   * @param position The position to insert the column at.
   */
  void insert_column(int position);

  /** Removes a row from the grid.
   *
   * Children that are placed in this row are removed,
   * spanning children that overlap this row have their
   * height reduced by one, and children below the row
   * are moved up.
   *
   * @param position The position of the row to remove.
   */
  void remove_row(int position);

  /** Removes a column from the grid.
   *
   * Children that are placed in this column are removed,
   * spanning children that overlap this column have their
   * width reduced by one, and children after the column
   * are moved to the left.
   *
   * @param position The position of the column to remove.
   */
  void remove_column(int position);

  /** Inserts a row or column at the specified position.
   *
   * The new row or column is placed next to @a sibling, on the side
   * determined by @a side. If @a side is Gtk::PositionType::TOP or Gtk::PositionType::BOTTOM,
   * a row is inserted. If @a side is Gtk::PositionType::LEFT of Gtk::PositionType::RIGHT,
   * a column is inserted.
   *
   * @param sibling The child of @a grid that the new row or column will be
   * placed next to.
   * @param side The side of @a sibling that @a child is positioned next to.
   */
  void insert_next_to(Widget& sibling, PositionType side);


  /** Sets whether all rows of @a grid will have the same height.
   *
   * @param homogeneous <tt>true</tt> to make rows homogeneous.
   */
  void set_row_homogeneous(bool homogeneous =  true);

  /** Returns whether all rows of @a grid have the same height.
   *
   * @return Whether all rows of @a grid have the same height.
   */
  auto get_row_homogeneous() const -> bool;

  /** Sets the amount of space between rows of @a grid.
   *
   * @param spacing The amount of space to insert between rows.
   */
  void set_row_spacing(guint spacing);

  /** Returns the amount of space between the rows of @a grid.
   *
   * @return The row spacing of @a grid.
   */
  auto get_row_spacing() const -> guint;

  /** Sets whether all columns of @a grid will have the same width.
   *
   * @param homogeneous <tt>true</tt> to make columns homogeneous.
   */
  void set_column_homogeneous(bool homogeneous =  true);

  /** Returns whether all columns of @a grid have the same width.
   *
   * @return Whether all columns of @a grid have the same width.
   */
  auto get_column_homogeneous() const -> bool;

  /** Sets the amount of space between columns of @a grid.
   *
   * @param spacing The amount of space to insert between columns.
   */
  void set_column_spacing(guint spacing);

  /** Returns the amount of space between the columns of @a grid.
   *
   * @return The column spacing of @a grid.
   */
  auto get_column_spacing() const -> guint;

  /** Sets how the baseline should be positioned on @a row of the
   * grid, in case that row is assigned more space than is requested.
   *
   * The default baseline position is Gtk::BaselinePosition::CENTER.
   *
   * @param row A row index.
   * @param pos A `Gtk::BaselinePosition`.
   */
  void set_row_baseline_position(int row, BaselinePosition pos);

  /** Returns the baseline position of @a row.
   *
   * See set_row_baseline_position().
   *
   * @param row A row index.
   * @return The baseline position of @a row.
   */
  auto get_row_baseline_position(int row) const -> BaselinePosition;

  /** Sets which row defines the global baseline for the entire grid.
   *
   * Each row in the grid can have its own local baseline, but only
   * one of those is global, meaning it will be the baseline in the
   * parent of the @a grid.
   *
   * @param row The row index.
   */
  void set_baseline_row(int row);

  /** Returns which row defines the global baseline of @a grid.
   *
   * @return The row index defining the global baseline.
   */
  auto get_baseline_row() const -> int;

  /** Queries the attach points and spans of @a child inside the given `Gtk::Grid`.
   *
   * @param child A `Gtk::Widget` child of @a grid.
   * @param column The column used to attach the left side of @a child.
   * @param row The row used to attach the top side of @a child.
   * @param width The number of columns @a child spans.
   * @param height The number of rows @a child spans.
   */
  void query_child(const Widget& child, int& column, int& row, int& width, int& height) const;

  /** The amount of space between two consecutive rows.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() -> Glib::PropertyProxy< guint > ;

/** The amount of space between two consecutive rows.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The amount of space between two consecutive columns.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() -> Glib::PropertyProxy< guint > ;

/** The amount of space between two consecutive columns.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** If <tt>true</tt>, the rows are all the same height.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_homogeneous() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the rows are all the same height.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, the columns are all the same width.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_homogeneous() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the columns are all the same width.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The row to align to the baseline when valign is Gtk::Align::BASELINE.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_row() -> Glib::PropertyProxy< int > ;

/** The row to align to the baseline when valign is Gtk::Align::BASELINE.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_row() const -> Glib::PropertyProxy_ReadOnly< int >;


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
   * @relates Gtk::Grid
   */
  GTKMM_API
  auto wrap(GtkGrid* object, bool take_copy = false) -> Gtk::Grid*;
} //namespace Glib


#endif /* _GTKMM_GRID_H */

