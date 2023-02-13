
#ifndef _GTKMM_GRIDLAYOUT_H
#define _GTKMM_GRIDLAYOUT_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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

#include <mm/gtk/layoutmanager.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GridLayout_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Layout manager for grid-like widgets.
 *
 * %Gtk::GridLayout is a layout manager which arranges child widgets in
 * rows and columns, with arbitrary positions and horizontal/vertical spans.
 *
 * Children have an "attach point" defined by the horizontal and vertical
 * index of the cell they occupy; children can span multiple rows or columns.
 * The layout properties for setting the attach points and spans are set
 * using the Gtk::GridLayoutChild associated to each child widget.
 *
 * The behaviour of Gtk::Grid when several children occupy the same grid cell
 * is undefined.
 *
 * %Gtk::GridLayout can be used like a Gtk::BoxLayout if all children are attached
 * to the same row or column; however, if you only ever need a single row or
 * column, you should consider using Gtk::BoxLayout.
 *
 * @newin{3,96}
 */

class GTKMM_API GridLayout : public LayoutManager
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GridLayout;
  using CppClassType = GridLayout_Class;
  using BaseObjectType = GtkGridLayout;
  using BaseClassType = GtkGridLayoutClass;

  // noncopyable
  GridLayout(const GridLayout&) = delete;
  auto operator=(const GridLayout&) -> GridLayout& = delete;

private:  friend class GridLayout_Class;
  static CppClassType gridlayout_class_;

protected:
  explicit GridLayout(const Glib::ConstructParams& construct_params);
  explicit GridLayout(GtkGridLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GridLayout(GridLayout&& src) noexcept;
  auto operator=(GridLayout&& src) noexcept -> GridLayout&;

  ~GridLayout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGridLayout*       { return reinterpret_cast<GtkGridLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGridLayout* { return reinterpret_cast<GtkGridLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGridLayout*;

private:


protected:
  GridLayout();

public:

  static auto create() -> Glib::RefPtr<GridLayout>;


  /** Sets whether all rows of @a grid should have the same height.
   *
   * @param homogeneous <tt>true</tt> to make rows homogeneous.
   */
  void set_row_homogeneous(bool homogeneous =  true);

  /** Checks whether all rows of @a grid should have the same height.
   *
   * @return <tt>true</tt> if the rows are homogeneous, and <tt>false</tt> otherwise.
   */
  auto get_row_homogeneous() const -> bool;

  /** Sets the amount of space to insert between consecutive rows.
   *
   * @param spacing The amount of space between rows, in pixels.
   */
  void set_row_spacing(guint spacing);

  /** Retrieves the spacing set with set_row_spacing().
   *
   * @return The spacing between consecutive rows.
   */
  auto get_row_spacing() const -> guint;

  /** Sets whether all columns of @a grid should have the same width.
   *
   * @param homogeneous <tt>true</tt> to make columns homogeneous.
   */
  void set_column_homogeneous(bool homogeneous =  true);

  /** Checks whether all columns of @a grid should have the same width.
   *
   * @return <tt>true</tt> if the columns are homogeneous, and <tt>false</tt> otherwise.
   */
  auto get_column_homogeneous() const -> bool;

  /** Sets the amount of space to insert between consecutive columns.
   *
   * @param spacing The amount of space between columns, in pixels.
   */
  void set_column_spacing(guint spacing);

  /** Retrieves the spacing set with set_column_spacing().
   *
   * @return The spacing between consecutive columns.
   */
  auto get_column_spacing() const -> guint;

  /** Sets how the baseline should be positioned on @a row of the
   * grid, in case that row is assigned more space than is requested.
   *
   * @param row A row index.
   * @param pos A `Gtk::BaselinePosition`.
   */
  void set_row_baseline_position(int row, BaselinePosition pos);

  /** Returns the baseline position of @a row.
   *
   * If no value has been set with
   * set_row_baseline_position(),
   * the default value of Gtk::BaselinePosition::CENTER
   * is returned.
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

  /** Retrieves the row set with set_baseline_row().
   *
   * @return The global baseline row.
   */
  auto get_baseline_row() const -> int;

  /** The amount of space between to consecutive rows.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() -> Glib::PropertyProxy< int > ;

/** The amount of space between to consecutive rows.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The amount of space between to consecutive columns.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() -> Glib::PropertyProxy< int > ;

/** The amount of space between to consecutive columns.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether all the rows in the grid have the same height.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_homogeneous() -> Glib::PropertyProxy< bool > ;

/** Whether all the rows in the grid have the same height.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether all the columns in the grid have the same width.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_homogeneous() -> Glib::PropertyProxy< bool > ;

/** Whether all the columns in the grid have the same width.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The row to align to the baseline, when `GtkWidget:valign` is set
   * to Gtk::Align::BASELINE.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_row() -> Glib::PropertyProxy< int > ;

/** The row to align to the baseline, when `GtkWidget:valign` is set
   * to Gtk::Align::BASELINE.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_row() const -> Glib::PropertyProxy_ReadOnly< int >;


  // There are no signals or vfuncs.


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
   * @relates Gtk::GridLayout
   */
  GTKMM_API
  auto wrap(GtkGridLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GridLayout>;
}


#endif /* _GTKMM_GRIDLAYOUT_H */

