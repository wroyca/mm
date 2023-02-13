
#ifndef _GTKMM_CELLVIEW_H
#define _GTKMM_CELLVIEW_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2004 The gtkmm Development Team
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
#include <libmm-gtk/celllayout.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gtk/treepath.hpp>
#include <libmm-gtk/cellrenderer.hpp>
#include <libmm-gtk/cellarea.hpp>
#include <libmm-gtk/cellareacontext.hpp>
#include <libmm-gtk/orientable.hpp>
#include <libmm-gdk/texture.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellView = struct _GtkCellView;
using GtkCellViewClass = struct _GtkCellViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellView_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget displaying a single row of a TreeModel.
 * A CellView displays a single row of a TreeModel, using cell renderers just like TreeView. CellView doesn't support some of the more
 * complex features of GtkTreeView, like cell editing and drag and drop.
 *
 * @ingroup Widgets
 */

class GTKMM_API CellView :
  public Widget,
  public CellLayout,
  public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellView CppObjectType;
  typedef CellView_Class CppClassType;
  typedef GtkCellView BaseObjectType;
  typedef GtkCellViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellView(CellView&& src) noexcept;
  auto operator=(CellView&& src) noexcept -> CellView&;

  // noncopyable
  CellView(const CellView&) = delete;
  auto operator=(const CellView&) -> CellView& = delete;

  ~CellView() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellView_Class;
  static CppClassType cellview_class_;

protected:
  explicit CellView(const Glib::ConstructParams& construct_params);
  explicit CellView(GtkCellView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellView*       { return reinterpret_cast<GtkCellView*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellView* { return reinterpret_cast<GtkCellView*>(gobject_); }

private:


public:
  CellView();

  /** Creates a new CellView widget, adds a CellRendererText to it, and makes it show the text.
   * Optionally, the text can be marked up with the Pango text markup language.
   *
   * @param text The text to display in the cell view
   * @param use_markup Whether the @a text uses Pango text markup language.
   */
  explicit CellView(const Glib::ustring& text, bool use_markup = false);


  /** Creates a new %CellView widget, adds a CellRendererPixbuf to it, and makes it show the texure.
   *
   * @param texture The image to display in the cell view.
   */
  explicit CellView(const Glib::RefPtr<Gdk::Texture>& texture);


  /** Sets the model for @a cell_view.  If @a cell_view already has a model
   * set, it will remove it before setting the new model. Use unset_model() to
   * unset the old model.
   *
   * @newin{2,6}
   *
   * @param model A `Gtk::TreeModel`.
   */
  void set_model(const Glib::RefPtr<TreeModel>& model);

  /** Remove the model from the CellView.
   *
   * @see set_model().
   *
   * @newin{2,16}
   */
  void unset_model();


  /** Returns the model for @a cell_view. If no model is used <tt>nullptr</tt> is
   * returned.
   *
   * @return A `Gtk::TreeModel` used.
   */
  auto get_model() -> Glib::RefPtr<TreeModel>;

  /** Returns the model for @a cell_view. If no model is used <tt>nullptr</tt> is
   * returned.
   *
   * @return A `Gtk::TreeModel` used.
   */
  auto get_model() const -> Glib::RefPtr<const TreeModel>;


  /** Sets the row of the model that is currently displayed
   * by the `Gtk::CellView`. If the path is unset, then the
   * contents of the cellview “stick” at their last value;
   * this is not normally a desired result, but may be
   * a needed intermediate state if say, the model for
   * the `Gtk::CellView` becomes temporarily empty.
   *
   * @param path A `Gtk::TreePath` or <tt>nullptr</tt> to unset.
   */
  void set_displayed_row(const TreeModel::Path& path);

  /** Returns a `Gtk::TreePath` referring to the currently
   * displayed row. If no row is currently displayed,
   * <tt>nullptr</tt> is returned.
   *
   * @return The currently displayed row.
   */
  auto get_displayed_row() const -> TreeModel::Path;


  /** Gets whether @a cell_view is configured to draw all of its
   * cells in a sensitive state.
   *
   * @return Whether @a cell_view draws all of its
   * cells in a sensitive state.
   */
  auto get_draw_sensitive() const -> bool;

  /** Sets whether @a cell_view should draw all of its
   * cells in a sensitive state, this is used by `Gtk::ComboBox` menus
   * to ensure that rows with insensitive cells that contain
   * children appear sensitive in the parent menu item.
   *
   * @param draw_sensitive Whether to draw all cells in a sensitive state.
   */
  void set_draw_sensitive(bool draw_sensitive =  true);

  /** Gets whether @a cell_view is configured to request space
   * to fit the entire `Gtk::TreeModel`.
   *
   * @return Whether @a cell_view requests space to fit
   * the entire `Gtk::TreeModel`.
   */
  auto get_fit_model() const -> bool;

  /** Sets whether @a cell_view should request space to fit the entire `Gtk::TreeModel`.
   *
   * This is used by `Gtk::ComboBox` to ensure that the cell view displayed on
   * the combo box’s button always gets enough space and does not resize
   * when selection changes.
   *
   * @param fit_model Whether @a cell_view should request space for the whole model.
   */
  void set_fit_model(bool fit_model =  true);

  /** The model for cell view
   *
   * since 2.10
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> > ;

/** The model for cell view
   *
   * since 2.10
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >;

  /** The `Gtk::CellArea` rendering cells
   *
   * If no area is specified when creating the cell view with gtk_cell_view_new_with_context()
   * a horizontally oriented `Gtk::CellArea`Box will be used.
   *
   * since 3.0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >;


  /** The `Gtk::CellAreaContext` used to compute the geometry of the cell view.
   *
   * A group of cell views can be assigned the same context in order to
   * ensure the sizes and cell alignments match across all the views with
   * the same context.
   *
   * `Gtk::ComboBox` menus uses this to assign the same context to all cell views
   * in the menu items for a single menu (each submenu creates its own
   * context since the size of each submenu does not depend on parent
   * or sibling menus).
   *
   * since 3.0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_area_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> >;


  /** Whether all cells should be draw as sensitive for this view regardless
   * of the actual cell properties (used to make menus with submenus appear
   * sensitive when the items in submenus might be insensitive).
   *
   * since 3.0
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_draw_sensitive() -> Glib::PropertyProxy< bool > ;

/** Whether all cells should be draw as sensitive for this view regardless
   * of the actual cell properties (used to make menus with submenus appear
   * sensitive when the items in submenus might be insensitive).
   *
   * since 3.0
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_draw_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the view should request enough space to always fit
   * the size of every row in the model (used by the combo box to
   * ensure the combo box size doesn't change when different items
   * are selected).
   *
   * since 3.0
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fit_model() -> Glib::PropertyProxy< bool > ;

/** Whether the view should request enough space to always fit
   * the size of every row in the model (used by the combo box to
   * ensure the combo box size doesn't change when different items
   * are selected).
   *
   * since 3.0
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fit_model() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::CellView
   */
  GTKMM_API
  auto wrap(GtkCellView* object, bool take_copy = false) -> Gtk::CellView*;
} //namespace Glib


#endif /* _GTKMM_CELLVIEW_H */

