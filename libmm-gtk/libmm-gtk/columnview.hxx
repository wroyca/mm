
#ifndef _GTKMM_COLUMNVIEW_H
#define _GTKMM_COLUMNVIEW_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/selectionmodel.hxx>
#include <libmm-gtk/columnviewcolumn.hxx>
#include <libmm-gtk/scrollable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ColumnView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget for displaying lists in multiple columns.
 *
 * %Gtk::ColumnView is a widget to present a view into a large dynamic list of items
 * using multiple columns with headers.
 *
 * %Gtk::ColumnView uses the factories of its columns to generate a cell widget for
 * each column, for each visible item and displays them together as the row for
 * this item. The property_show_row_separators() and
 * property_show_column_separators() properties offer a simple way to display
 * separators between the rows or columns.
 *
 * %Gtk::ColumnView allows the user to select items according to the selection
 * characteristics of the model. For models that allow multiple selected items,
 * it is possible to turn on *rubberband selection*, using set_enable_rubberband().
 *
 * The column view supports sorting that can be customized by the user by
 * clicking on column headers. To set this up, the Gtk::Sorter returned by
 * get_sorter() must be attached to a sort model for the data
 * that the view is showing, and the columns must have sorters attached to them
 * by calling Gtk::ColumnViewColumn::set_sorter(). The initial sort order can be
 * set with sort_by_column().
 *
 * The column view also supports interactive resizing and reordering of
 * columns, via Drag-and-Drop of the column headers. This can be enabled or
 * disabled with the property_reorderable() and
 * Gtk::ColumnViewColumn::property_resizable() properties.
 *
 * @see Gtk::ColumnViewColumn, Gtk::TreeView
 *
 * @ingroup Widgets
 *
 * @newin{3,98}
 */

class GTKMM_API ColumnView : public Widget, public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ColumnView CppObjectType;
  typedef ColumnView_Class CppClassType;
  typedef GtkColumnView BaseObjectType;
  typedef GtkColumnViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ColumnView(ColumnView&& src) noexcept;
  auto operator=(ColumnView&& src) noexcept -> ColumnView&;

  // noncopyable
  ColumnView(const ColumnView&) = delete;
  auto operator=(const ColumnView&) -> ColumnView& = delete;

  ~ColumnView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ColumnView_Class;
  static CppClassType columnview_class_;

protected:
  explicit ColumnView(const Glib::ConstructParams& construct_params);
  explicit ColumnView(GtkColumnView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkColumnView*       { return reinterpret_cast<GtkColumnView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkColumnView* { return reinterpret_cast<GtkColumnView*>(gobject_); }

private:


public:
    explicit ColumnView(const Glib::RefPtr<SelectionModel>& model =  {});


  /** Gets the list of columns in this column view.
   *
   * This list is constant over the lifetime of @a self and can be used to
   * monitor changes to the columns of @a self by connecting to the
   * signal_items_changed() signal.
   *
   * @return The list managing the columns.
   */
  auto get_columns() -> Glib::RefPtr<Gio::ListModel>;

  /** Gets the list of columns in this column view.
   *
   * This list is constant over the lifetime of @a self and can be used to
   * monitor changes to the columns of @a self by connecting to the
   * signal_items_changed() signal.
   *
   * @return The list managing the columns.
   */
  auto get_columns() const -> Glib::RefPtr<const Gio::ListModel>;


  /** Appends the @a column to the end of the columns in @a self.
   *
   * @param column A `Gtk::ColumnViewColumn` that hasn't been added to a
   * `Gtk::ColumnView` yet.
   */
  void append_column(const Glib::RefPtr<ColumnViewColumn>& column);

  /** Removes the @a column from the list of columns of @a self.
   *
   * @param column A `Gtk::ColumnViewColumn` that's part of @a self.
   */
  void remove_column(const Glib::RefPtr<ColumnViewColumn>& column);

  /** Inserts a column at the given position in the columns of @a self.
   *
   * If @a column is already a column of @a self, it will be repositioned.
   *
   * @param position The position to insert @a column at.
   * @param column The `Gtk::ColumnViewColumn` to insert.
   */
  void insert_column(guint position, const Glib::RefPtr<ColumnViewColumn>& column);


  /** Gets the model that's currently used to read the items displayed.
   *
   * @return The model in use.
   */
  auto get_model() -> Glib::RefPtr<SelectionModel>;

  /** Gets the model that's currently used to read the items displayed.
   *
   * @return The model in use.
   */
  auto get_model() const -> Glib::RefPtr<const SelectionModel>;

  /** Sets the model to use.
   *
   * This must be a Gtk::SelectionModel.
   *
   * @param model The model to use.
   */
  void set_model(const Glib::RefPtr<SelectionModel>& model);


  /** Returns whether the list should show separators
   * between rows.
   *
   * @return <tt>true</tt> if the list shows separators.
   */
  auto get_show_row_separators() const -> bool;

  /** Sets whether the list should show separators
   * between rows.
   *
   * @param show_separators <tt>true</tt> to show row separators.
   */
  void set_show_row_separators(bool show_separators =  true);


  /** Returns whether the list should show separators
   * between columns.
   *
   * @return <tt>true</tt> if the list shows column separators.
   */
  auto get_show_column_separators() const -> bool;

  /** Sets whether the list should show separators
   * between columns.
   *
   * @param show_separators <tt>true</tt> to show column separators.
   */
  void set_show_column_separators(bool show_separators =  true);


  /** Returns a special sorter that reflects the users sorting
   * choices in the column view.
   *
   * To allow users to customizable sorting by clicking on column
   * headers, this sorter needs to be set on the sort model underneath
   * the model that is displayed by the view.
   *
   * See Gtk::ColumnViewColumn::set_sorter() for setting up
   * per-column sorting.
   *
   * Here is an example:
   *
   * [C example ellipted]
   *
   * @return The `Gtk::Sorter` of @a self.
   */
  auto get_sorter() -> Glib::RefPtr<Sorter>;

  /** Returns a special sorter that reflects the users sorting
   * choices in the column view.
   *
   * To allow users to customizable sorting by clicking on column
   * headers, this sorter needs to be set on the sort model underneath
   * the model that is displayed by the view.
   *
   * See Gtk::ColumnViewColumn::set_sorter() for setting up
   * per-column sorting.
   *
   * Here is an example:
   *
   * [C example ellipted]
   *
   * @return The `Gtk::Sorter` of @a self.
   */
  auto get_sorter() const -> Glib::RefPtr<const Sorter>;

  /** Sets the sorting of the view.
   *
   * This function should be used to set up the initial sorting.
   * At runtime, users can change the sorting of a column view
   * by clicking on the list headers.
   *
   * This call only has an effect if the sorter returned by
   * get_sorter() is set on a sort model,
   * and Gtk::ColumnViewColumn::set_sorter() has been called
   * on @a column to associate a sorter with the column.
   *
   * If @a column is <tt>nullptr</tt>, the view will be unsorted.
   *
   * @param column The `Gtk::ColumnViewColumn` to sort by.
   * @param direction The direction to sort in.
   */
  void sort_by_column(const Glib::RefPtr<ColumnViewColumn>& column, SortType direction);


  /** Sets whether rows should be activated on single click and
   * selected on hover.
   *
   * @param single_click_activate <tt>true</tt> to activate items on single click.
   */
  void set_single_click_activate(bool single_click_activate =  true);

  /** Returns whether rows will be activated on single click and
   * selected on hover.
   *
   * @return <tt>true</tt> if rows are activated on single click.
   */
  auto get_single_click_activate() const -> bool;

  /** Sets whether columns should be reorderable by dragging.
   *
   * @param reorderable Whether columns should be reorderable.
   */
  void set_reorderable(bool reorderable =  true);

  /** Returns whether columns are reorderable.
   *
   * @return <tt>true</tt> if columns are reorderable.
   */
  auto get_reorderable() const -> bool;

  /** Sets whether selections can be changed by dragging with the mouse.
   *
   * @param enable_rubberband <tt>true</tt> to enable rubberband selection.
   */
  void set_enable_rubberband(bool enable_rubberband =  true);

  /** Returns whether rows can be selected by dragging with the mouse.
   *
   * @return <tt>true</tt> if rubberband selection is enabled.
   */
  auto get_enable_rubberband() const -> bool;

  /** The list of columns.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_columns() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >;


  /** Model for the items displayed.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> > ;

/** Model for the items displayed.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >;

  /** Show separators between rows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_row_separators() -> Glib::PropertyProxy< bool > ;

/** Show separators between rows.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_row_separators() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Show separators between columns.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_column_separators() -> Glib::PropertyProxy< bool > ;

/** Show separators between columns.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_column_separators() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Sorter with the sorting choices of the user.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >;


  /** Activate rows on single click and select them on hover.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_click_activate() -> Glib::PropertyProxy< bool > ;

/** Activate rows on single click and select them on hover.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_single_click_activate() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether columns are reorderable.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() -> Glib::PropertyProxy< bool > ;

/** Whether columns are reorderable.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Allow rubberband selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_rubberband() -> Glib::PropertyProxy< bool > ;

/** Allow rubberband selection.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_enable_rubberband() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate(guint pos)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a row has been activated by the user, usually via activating
   * the GtkListBase|list.activate-item action.
   *
   * This allows for a convenient way to handle activation in a columnview.
   * See Gtk::ListItem::set_activatable() for details on how to use this
   * signal.
   *
   * @param pos Position of item to activate.
   */

  auto signal_activate() -> Glib::SignalProxy<void(guint)>;


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
   * @relates Gtk::ColumnView
   */
  GTKMM_API
  auto wrap(GtkColumnView* object, bool take_copy = false) -> Gtk::ColumnView*;
} //namespace Glib


#endif /* _GTKMM_COLUMNVIEW_H */

