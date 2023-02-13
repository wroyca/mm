
#ifndef _GTKMM_GRIDVIEW_H
#define _GTKMM_GRIDVIEW_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/listbase.hpp>
#include <libmm-gtk/selectionmodel.hpp>
#include <libmm-gtk/listitemfactory.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGridView = struct _GtkGridView;
using GtkGridViewClass = struct _GtkGridViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GridView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget for displaying grids.
 *
 * %Gtk::GridView is a widget to present a view into a large dynamic grid of items.
 *
 * %Gtk::GridView uses its factory to generate one child widget for each visible item
 * and shows them in a grid. The orientation of the grid view determines if the
 * grid reflows vertically or horizontally.
 *
 * %Gtk::GridView allows the user to select items according to the selection
 * characteristics of the model. For models that allow multiple selected items,
 * it is possible to turn on _rubberband selection_, using set_enable_rubberband().
 *
 * @see Gtk::SelectionModel, Gtk::ListView, Gtk::ColumnView
 *
 * @ingroup Widgets
 *
 * @newin{3,98}
 */

class GTKMM_API GridView : public ListBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef GridView CppObjectType;
  typedef GridView_Class CppClassType;
  typedef GtkGridView BaseObjectType;
  typedef GtkGridViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  GridView(GridView&& src) noexcept;
  auto operator=(GridView&& src) noexcept -> GridView&;

  // noncopyable
  GridView(const GridView&) = delete;
  auto operator=(const GridView&) -> GridView& = delete;

  ~GridView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class GridView_Class;
  static CppClassType gridview_class_;

protected:
  explicit GridView(const Glib::ConstructParams& construct_params);
  explicit GridView(GtkGridView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkGridView*       { return reinterpret_cast<GtkGridView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGridView* { return reinterpret_cast<GtkGridView*>(gobject_); }

private:


public:
    explicit GridView(const Glib::RefPtr<SelectionModel>& model =  {}, const Glib::RefPtr<ListItemFactory>& factory =  {});


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

  /** Sets the imodel to use.
   *
   * This must be a Gtk::SelectionModel.
   *
   * @param model The model to use.
   */
  void set_model(const Glib::RefPtr<SelectionModel>& model);

  /** Sets the `Gtk::ListItemFactory` to use for populating list items.
   *
   * @param factory The factory to use.
   */
  void set_factory(const Glib::RefPtr<ListItemFactory>& factory);

  /** Gets the factory that's currently used to populate list items.
   *
   * @return The factory in use.
   */
  auto get_factory() -> Glib::RefPtr<ListItemFactory>;

  /** Gets the factory that's currently used to populate list items.
   *
   * @return The factory in use.
   */
  auto get_factory() const -> Glib::RefPtr<const ListItemFactory>;

  /** Gets the minimum number of columns that the grid will use.
   *
   * @return The minimum number of columns.
   */
  auto get_min_columns() const -> guint;

  /** Sets the minimum number of columns to use.
   *
   * This number must be at least 1.
   *
   * If @a min_columns is smaller than the minimum set via
   * set_max_columns(), that value is ignored.
   *
   * @param min_columns The minimum number of columns.
   */
  void set_min_columns(guint min_columns);

  /** Gets the maximum number of columns that the grid will use.
   *
   * @return The maximum number of columns.
   */
  auto get_max_columns() const -> guint;

  /** Sets the maximum number of columns to use.
   *
   * This number must be at least 1.
   *
   * If @a max_columns is smaller than the minimum set via
   * set_min_columns(), that value is used instead.
   *
   * @param max_columns The maximum number of columns.
   */
  void set_max_columns(guint max_columns);

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

  /** Sets whether items should be activated on single click and
   * selected on hover.
   *
   * @param single_click_activate <tt>true</tt> to activate items on single click.
   */
  void set_single_click_activate(bool single_click_activate =  true);

  /** Returns whether items will be activated on single click and
   * selected on hover.
   *
   * @return <tt>true</tt> if items are activated on single click.
   */
  auto get_single_click_activate() const -> bool;

  /** Factory for populating list items.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > ;

/** Factory for populating list items.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >;

  /** Maximum number of columns per row.
   *
   * If this number is smaller than property_min_columns(),
   * that value is used instead.
   *
   * Default value: 7
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_columns() -> Glib::PropertyProxy< guint > ;

/** Maximum number of columns per row.
   *
   * If this number is smaller than property_min_columns(),
   * that value is used instead.
   *
   * Default value: 7
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_columns() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Minimum number of columns per row.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_columns() -> Glib::PropertyProxy< guint > ;

/** Minimum number of columns per row.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_columns() const -> Glib::PropertyProxy_ReadOnly< guint >;

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


  // no_default_handler because GtkGridViewClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate(guint position)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a cell has been activated by the user,
   * usually via activating the GtkGridView|list.activate-item action.
   *
   * This allows for a convenient way to handle activation in a gridview.
   * See Gtk::ListItem::property_activatable() for details on how to use
   * this signal.
   *
   * @param position Position of item to activate.
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
   * @relates Gtk::GridView
   */
  GTKMM_API
  auto wrap(GtkGridView* object, bool take_copy = false) -> Gtk::GridView*;
} //namespace Glib


#endif /* _GTKMM_GRIDVIEW_H */

