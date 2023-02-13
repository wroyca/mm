
#ifndef _GTKMM_CELLAREA_H
#define _GTKMM_CELLAREA_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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

#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/cellareacontext.hxx>
#include <libmm-gtk/celllayout.hxx>
#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellArea = struct _GtkCellArea;
using GtkCellAreaClass = struct _GtkCellAreaClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellArea_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Snapshot;

//TODO: This documentation omits the examples from the C documentation. We should translate them to C++.
/** An abstract base class for laying out CellRenderers.
 *
 * This is an abstract base class for CellLayout widgets
 * (also referred to as "layouting widgets") to interface with an
 * arbitrary number of CellRenderers and interact with the user
 * for a given TreeModel row.
 *
 * The cell area handles events, focus navigation, drawing and
 * size requests and allocations for a given row of data.
 *
 * Usually users dont have to interact with the CellArea directly
 * unless they are implementing a cell layouting widget themselves.
 *
 * <h2>Requesting area sizes</h2>
 *
 * As outlined in Gtk::Widget's
 * geometry management description, GTK+ uses a height-for-width
 * geometry management system to compute the sizes of widgets and user
 * interfaces. CellArea uses the same semantics to calculate the
 * size of an area for an arbitrary number of TreeModel rows.
 *
 * When requesting the size of a cell area one needs to calculate
 * the size for a handful of rows, and this will be done differently by
 * different layouting widgets. For instance a TreeViewColumn
 * always lines up the areas from top to bottom while an IconView,
 * on the other hand, might enforce that all areas received the same
 * width and wrap the areas around, requesting height for more cell
 * areas when allocated less width.
 *
 * It's also important for areas to maintain some cell
 * alignments with areas rendered for adjacent rows (cells can
 * appear "columnized" inside an area even when the size of
 * cells are different in each row). For this reason the CellArea
 * uses a CellAreaContext object to store the alignments
 * and sizes along the way (as well as the overall largest minimum
 * and natural size for all the rows which have been calculated
 * with the said context).
 *
 * The CellAreaContext is an opaque object specific to the
 * CellArea which created it (see CellArea::create_context()).
 * The owning cell-layouting widget can create as many contexts as
 * it wishes to calculate sizes of rows which should receive the
 * same size in at least one orientation (horizontally or vertically).
 * However, it's important that the same CellAreaContext which
 * was used to request the sizes for a given TreeModel row be
 * used when rendering or processing events for that row.
 *
 * <h2>Cell Properties</h2>
 *
 * The CellArea introduces cell properties for CellRenderers.
 * This provides some general interfaces for defining
 * the relationship cell areas have with their cells. For instance in a
 * CellAreaBox a cell might “expand” and receive extra space when
 * the area is allocated more than its full natural request, or a cell
 * might be configured to “align” with adjacent rows which were requested
 * and rendered with the same CellAreaContext.
 *
 * To set the value of a cell property, use cell_set_property(). To obtain
 * the value of a cell property, use cell_get_property().
 *
 * @newin{3,0}
 */

class GTKMM_API CellArea
  : public Glib::Object,
    public Buildable,
    public CellLayout
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CellArea;
  using CppClassType = CellArea_Class;
  using BaseObjectType = GtkCellArea;
  using BaseClassType = GtkCellAreaClass;

  // noncopyable
  CellArea(const CellArea&) = delete;
  auto operator=(const CellArea&) -> CellArea& = delete;

private:  friend class CellArea_Class;
  static CppClassType cellarea_class_;

protected:
  explicit CellArea(const Glib::ConstructParams& construct_params);
  explicit CellArea(GtkCellArea* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CellArea(CellArea&& src) noexcept;
  auto operator=(CellArea&& src) noexcept -> CellArea&;

  ~CellArea() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellArea*       { return reinterpret_cast<GtkCellArea*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellArea* { return reinterpret_cast<GtkCellArea*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkCellArea*;

private:


protected:
  CellArea();
public:


  /** Adds @a renderer to @a area with the default child cell properties.
   *
   * @param renderer The `Gtk::CellRenderer` to add to @a area.
   */
  void add(CellRenderer& renderer);

  /** Removes @a renderer from @a area.
   *
   * @param renderer The `Gtk::CellRenderer` to remove from @a area.
   */
  void remove(CellRenderer& renderer);

  /** Checks if @a area contains @a renderer.
   *
   * @param renderer The `Gtk::CellRenderer` to check.
   * @return <tt>true</tt> if @a renderer is in the @a area.
   */
  auto has_renderer(CellRenderer& renderer) -> bool;

  /** For instance,
   * bool on_foreach(Gtk::CellRenderer* renderer);
   *
   * @param renderer the cell renderer to operate on
   * @returns true to stop iterating over cells.
   *
   * @newin{3,4}
   */
  typedef sigc::slot<bool(CellRenderer*)> SlotForeach;

  /** Calls the @a slot for every CellRenderer in the CellArea.
   *
   * @param slot The slot to call for every CellRenderer.
   *
   * @newin{3,4}
   */
  void foreach(const SlotForeach& slot);


  /** For instance,
   * bool on_foreach(Gtk::CellRenderer* renderer, const Gdk::Rectangle& cell_area, const Gdk::Rectangle& background_area);
   *
   * @param renderer the cell renderer to operate on
   * @param cell_area the area allocated to the @a renderer inside the rectangle provided to foreach().
   * @param background_area The background area for the @a renderer inside the background area provided to foreach().
   * @returns true to stop iterating over cells.
   *
   * @newin{3,4}
   */
  typedef sigc::slot<bool(CellRenderer*, const Gdk::Rectangle&, const Gdk::Rectangle&)> SlotForeachAlloc;

  /** Calls the @a slot for every CellRenderer in the CellArea
   * with the allocated rectangle inside the @a cell_area rectangle.
   *
   * @param context The CellAreaContext for this row of data.
   * @param widget The widget that the CellArea is rendering to.
   * @param cell_area The widget-relative coordinates and size for the CellArea.
   * @param background_area The widget-relative coordinates of the background area.
   *
   * @param slot The slot to call for every CellRenderer.
   *
   * @newin{3,4}
   */
  void foreach(const Glib::RefPtr<CellAreaContext>& context, Widget* widget, const Gdk::Rectangle& cell_area, const Gdk::Rectangle& background_area, const SlotForeachAlloc& slot);


  /** Delegates event handling to a `Gtk::CellArea`.
   *
   * @param context The `Gtk::CellArea`Context for this row of data.
   * @param widget The `Gtk::Widget` that @a area is rendering to.
   * @param gdk_event The `Gdk::Event` to handle.
   * @param cell_area The @a widget relative coordinates for @a area.
   * @param flags The `Gtk::CellRenderer`State for @a area in this row.
   * @return <tt>true</tt> if the event was handled by @a area.
   */
  auto event(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Glib::RefPtr<const Gdk::Event>& gdk_event, const Gdk::Rectangle& cell_area, GtkCellRendererState flags) -> int;


  /** Snapshots @a area’s cells according to @a area’s layout onto at
   * the given coordinates.
   *
   * @param context The `Gtk::CellArea`Context for this row of data.
   * @param widget The `Gtk::Widget` that @a area is rendering to.
   * @param snapshot The `Gtk::Snapshot` to draw to.
   * @param background_area The @a widget relative coordinates for @a area’s background.
   * @param cell_area The @a widget relative coordinates for @a area.
   * @param flags The `Gtk::CellRenderer`State for @a area in this row.
   * @param paint_focus Whether @a area should paint focus on focused cells for focused rows or not.
   */
  void snapshot(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Glib::RefPtr<Gtk::Snapshot>& snapshot, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags, bool paint_focus);


  /** Derives the allocation of @a renderer inside @a area if @a area
   * were to be renderered in @a cell_area.
   *
   * @param context The `Gtk::CellArea`Context used to hold sizes for @a area.
   * @param widget The `Gtk::Widget` that @a area is rendering on.
   * @param renderer The `Gtk::CellRenderer` to get the allocation for.
   * @param cell_area The whole allocated area for @a area in @a widget
   * for this row.
   * @param allocation Where to store the allocation for @a renderer.
   */
  void get_cell_allocation(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, CellRenderer& renderer, const Gdk::Rectangle& cell_area, Gdk::Rectangle& allocation);


  /** Gets the `Gtk::CellRenderer` at @a x and @a y coordinates inside @a area and optionally
   * returns the full cell allocation for it inside @a cell_area.
   *
   * @param context The `Gtk::CellArea`Context used to hold sizes for @a area.
   * @param widget The `Gtk::Widget` that @a area is rendering on.
   * @param cell_area The whole allocated area for @a area in @a widget
   * for this row.
   * @param x The x position.
   * @param y The y position.
   * @param alloc_area Where to store the inner allocated area of the
   * returned cell renderer.
   * @return The `Gtk::CellRenderer` at @a x and @a y.
   */
  auto get_cell_at_position(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Gdk::Rectangle& cell_area, int x, int y, Gdk::Rectangle& alloc_area) -> CellRenderer*;

  /** Gets the `Gtk::CellRenderer` at @a x and @a y coordinates inside @a area and optionally
   * returns the full cell allocation for it inside @a cell_area.
   *
   * @param context The `Gtk::CellArea`Context used to hold sizes for @a area.
   * @param widget The `Gtk::Widget` that @a area is rendering on.
   * @param cell_area The whole allocated area for @a area in @a widget
   * for this row.
   * @param x The x position.
   * @param y The y position.
   * @param alloc_area Where to store the inner allocated area of the
   * returned cell renderer.
   * @return The `Gtk::CellRenderer` at @a x and @a y.
   */
  auto get_cell_at_position(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Gdk::Rectangle& cell_area, int x, int y, Gdk::Rectangle& alloc_area) const -> const CellRenderer*;


  /** Creates a `Gtk::CellArea`Context to be used with @a area for
   * all purposes. `Gtk::CellArea`Context stores geometry information
   * for rows for which it was operated on, it is important to use
   * the same context for the same row of data at all times (i.e.
   * one should render and handle events with the same `Gtk::CellArea`Context
   * which was used to request the size of those rows of data).
   *
   * @return A newly created `Gtk::CellArea`Context which can be used with @a area.
   */
  auto create_context() const -> Glib::RefPtr<CellAreaContext>;


  /** This is sometimes needed for cases where rows need to share
   * alignments in one orientation but may be separately grouped
   * in the opposing orientation.
   *
   * For instance, `Gtk::IconView` creates all icons (rows) to have
   * the same width and the cells theirin to have the same
   * horizontal alignments. However each row of icons may have
   * a separate collective height. `Gtk::IconView` uses this to
   * request the heights of each row based on a context which
   * was already used to request all the row widths that are
   * to be displayed.
   *
   * @param context The `Gtk::CellArea`Context to copy.
   * @return A newly created `Gtk::CellArea`Context copy of @a context.
   */
  auto copy_context(const Glib::RefPtr<const CellAreaContext>& context) -> Glib::RefPtr<CellAreaContext>;


  /** Gets whether the area prefers a height-for-width layout
   * or a width-for-height layout.
   *
   * @return The `Gtk::SizeRequestMode` preferred by @a area.
   */
  auto get_request_mode() const -> SizeRequestMode;

  /** Retrieves a cell area’s initial minimum and natural width.
   *
   *  @a area will store some geometrical information in @a context along the way;
   * when requesting sizes over an arbitrary number of rows, it’s not important
   * to check the @a minimum_width and @a natural_width of this call but rather to
   * consult Gtk::CellAreaContext::get_preferred_width() after a series of
   * requests.
   *
   * @param context The `Gtk::CellArea`Context to perform this request with.
   * @param widget The `Gtk::Widget` where @a area will be rendering.
   * @param minimum_width Location to store the minimum width.
   * @param natural_width Location to store the natural width.
   */
  void get_preferred_width(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int& minimum_width, int& natural_width);

  /** Retrieves a cell area’s minimum and natural height if it would be given
   * the specified @a width.
   *
   *  @a area stores some geometrical information in @a context along the way
   * while calling get_preferred_width(). It’s important to
   * perform a series of get_preferred_width() requests with
   *  @a context first and then call get_preferred_height_for_width()
   * on each cell area individually to get the height for width of each
   * fully requested row.
   *
   * If at some point, the width of a single row changes, it should be
   * requested with get_preferred_width() again and then
   * the full width of the requested rows checked again with
   * Gtk::CellAreaContext::get_preferred_width().
   *
   * @param context The `Gtk::CellArea`Context which has already been requested for widths.
   * @param widget The `Gtk::Widget` where @a area will be rendering.
   * @param width The width for which to check the height of this area.
   * @param minimum_height Location to store the minimum height.
   * @param natural_height Location to store the natural height.
   */
  void get_preferred_height_for_width(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int width, int& minimum_height, int& natural_height);

  /** Retrieves a cell area’s initial minimum and natural height.
   *
   *  @a area will store some geometrical information in @a context along the way;
   * when requesting sizes over an arbitrary number of rows, it’s not important
   * to check the @a minimum_height and @a natural_height of this call but rather to
   * consult Gtk::CellAreaContext::get_preferred_height() after a series of
   * requests.
   *
   * @param context The `Gtk::CellArea`Context to perform this request with.
   * @param widget The `Gtk::Widget` where @a area will be rendering.
   * @param minimum_height Location to store the minimum height.
   * @param natural_height Location to store the natural height.
   */
  void get_preferred_height(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int& minimum_height, int& natural_height);

  /** Retrieves a cell area’s minimum and natural width if it would be given
   * the specified @a height.
   *
   *  @a area stores some geometrical information in @a context along the way
   * while calling get_preferred_height(). It’s important to
   * perform a series of get_preferred_height() requests with
   *  @a context first and then call get_preferred_width_for_height()
   * on each cell area individually to get the height for width of each
   * fully requested row.
   *
   * If at some point, the height of a single row changes, it should be
   * requested with get_preferred_height() again and then
   * the full height of the requested rows checked again with
   * Gtk::CellAreaContext::get_preferred_height().
   *
   * @param context The `Gtk::CellArea`Context which has already been requested for widths.
   * @param widget The `Gtk::Widget` where @a area will be rendering.
   * @param height The height for which to check the width of this area.
   * @param minimum_width Location to store the minimum width.
   * @param natural_width Location to store the natural width.
   */
  void get_preferred_width_for_height(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int height, int& minimum_width, int& natural_width);

  /** Gets the current `Gtk::TreePath` string for the currently
   * applied `Gtk::TreeIter`, this is implicitly updated when
   * apply_attributes() is called and can be
   * used to interact with renderers from `Gtk::CellArea`
   * subclasses.
   *
   * @return The current `Gtk::TreePath` string for the current
   * attributes applied to @a area. This string belongs to the area and
   * should not be freed.
   */
  auto get_current_path_string() const -> Glib::ustring;


  /** Applies any connected attributes to the renderers in
   *  @a area by pulling the values from @a tree_model.
   *
   * @param tree_model The `Gtk::TreeModel` to pull values from.
   * @param iter The `Gtk::TreeIter` in @a tree_model to apply values for.
   * @param is_expander Whether @a iter has children.
   * @param is_expanded Whether @a iter is expanded in the view and
   * children are visible.
   */
  void apply_attributes(const Glib::RefPtr<TreeModel>& tree_model, const TreeModel::iterator& iter, bool is_expander, bool is_expanded);

  /** Connects an @a attribute to apply values from @a column for the
   * `Gtk::TreeModel` in use.
   *
   * @param renderer The `Gtk::CellRenderer` to connect an attribute for.
   * @param attribute The attribute name.
   * @param column The `Gtk::TreeModel` column to fetch attribute values from.
   */
  void attribute_connect(CellRenderer& renderer, const Glib::ustring& attribute, int column);

  /** Disconnects @a attribute for the @a renderer in @a area so that
   * attribute will no longer be updated with values from the
   * model.
   *
   * @param renderer The `Gtk::CellRenderer` to disconnect an attribute for.
   * @param attribute The attribute name.
   */
  void attribute_disconnect(CellRenderer& renderer, const Glib::ustring& attribute);


  /** Returns the model column that an attribute has been mapped to,
   * or -1 if the attribute is not mapped.
   *
   * @param renderer A `Gtk::CellRenderer`.
   * @param attribute An attribute on the renderer.
   * @return The model column, or -1.
   */
  auto attribute_get_column(CellRenderer& renderer, const Glib::ustring& attribute) const -> int;

  //Ignore the C convenience functions.


  /** Sets a cell property for @a renderer in @a area.
   *
   * @param renderer A `Gtk::CellRenderer` inside @a area.
   * @param property_name The name of the cell property to set.
   * @param value The value to set the cell property to.
   */
  void cell_set_property(CellRenderer& renderer, const Glib::ustring& property_name, const Glib::ValueBase& value);

  /** Gets the value of a cell property for @a renderer in @a area.
   *
   * @param renderer A `Gtk::CellRenderer` inside @a area.
   * @param property_name The name of the property to get.
   * @param value A location to return the value.
   */
  void cell_get_property(CellRenderer& renderer, const Glib::ustring& property_name, Glib::ValueBase& value);


  /** Returns whether the area can do anything when activated,
   * after applying new attributes to @a area.
   *
   * @return Whether @a area can do anything when activated.
   */
  auto is_activatable() const -> bool;

  /** Activates @a area, usually by activating the currently focused
   * cell, however some subclasses which embed widgets in the area
   * can also activate a widget if it currently has the focus.
   *
   * @param context The `Gtk::CellArea`Context in context with the current row data.
   * @param widget The `Gtk::Widget` that @a area is rendering on.
   * @param cell_area The size and location of @a area relative to @a widget’s allocation.
   * @param flags The `Gtk::CellRenderer`State flags for @a area for this row of data.
   * @param edit_only If <tt>true</tt> then only cell renderers that are Gtk::CellRendererMode::EDITABLE
   * will be activated.
   * @return Whether @a area was successfully activated.
   */
  auto activate(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Gdk::Rectangle& cell_area, CellRendererState flags, bool edit_only) -> bool;

  /** This should be called by the @a area’s owning layout widget
   * when focus is to be passed to @a area, or moved within @a area
   * for a given @a direction and row data.
   *
   * Implementing `Gtk::CellArea` classes should implement this
   * method to receive and navigate focus in its own way particular
   * to how it lays out cells.
   *
   * @param direction The `Gtk::DirectionType`.
   * @return <tt>true</tt> if focus remains inside @a area as a result of this call.
   */
  auto focus(DirectionType direction) -> bool;

  /** Explicitly sets the currently focused cell to @a renderer.
   *
   * This is generally called by implementations of
   * `GtkCellAreaClass.focus()` or `GtkCellAreaClass.event()`,
   * however it can also be used to implement functions such
   * as Gtk::TreeView::set_cursor_on_cell().
   *
   * @param renderer The `Gtk::CellRenderer` to give focus to.
   */
  void set_focus_cell(CellRenderer& renderer);


  /** Retrieves the currently focused cell for @a area
   *
   * @return The currently focused cell in @a area.
   */
  auto get_focus_cell() -> CellRenderer*;

  /** Retrieves the currently focused cell for @a area
   *
   * @return The currently focused cell in @a area.
   */
  auto get_focus_cell() const -> const CellRenderer*;


  /** Adds @a sibling to @a renderer’s focusable area, focus will be drawn
   * around @a renderer and all of its siblings if @a renderer can
   * focus for a given row.
   *
   * Events handled by focus siblings can also activate the given
   * focusable @a renderer.
   *
   * @param renderer The `Gtk::CellRenderer` expected to have focus.
   * @param sibling The `Gtk::CellRenderer` to add to @a renderer’s focus area.
   */
  void add_focus_sibling(CellRenderer& renderer, CellRenderer& sibling);

  /** Removes @a sibling from @a renderer’s focus sibling list
   * (see add_focus_sibling()).
   *
   * @param renderer The `Gtk::CellRenderer` expected to have focus.
   * @param sibling The `Gtk::CellRenderer` to remove from @a renderer’s focus area.
   */
  void remove_focus_sibling(CellRenderer& renderer, CellRenderer& sibling);

  /** Returns whether @a sibling is one of @a renderer’s focus siblings
   * (see add_focus_sibling()).
   *
   * @param renderer The `Gtk::CellRenderer` expected to have focus.
   * @param sibling The `Gtk::CellRenderer` to check against @a renderer’s sibling list.
   * @return <tt>true</tt> if @a sibling is a focus sibling of @a renderer.
   */
  auto is_focus_sibling(CellRenderer& renderer, CellRenderer& sibling) -> bool;


  /** Gets the focus sibling cell renderers for @a renderer.
   *
   * @param renderer The `Gtk::CellRenderer` expected to have focus.
   * @return A `GList` of `Gtk::CellRenderer`s.
   * The returned list is internal and should not be freed.
   */
  auto get_focus_siblings(CellRenderer& renderer) -> std::vector<CellRenderer*>;


  /** Gets the focus sibling cell renderers for @a renderer.
   *
   * @param renderer The `Gtk::CellRenderer` expected to have focus.
   * @return A `GList` of `Gtk::CellRenderer`s.
   * The returned list is internal and should not be freed.
   */
  auto get_focus_siblings(const CellRenderer& renderer) const -> std::vector<const CellRenderer*>;


  /** Gets the `Gtk::CellRenderer` which is expected to be focusable
   * for which @a renderer is, or may be a sibling.
   *
   * This is handy for `Gtk::CellArea` subclasses when handling events,
   * after determining the renderer at the event location it can
   * then chose to activate the focus cell for which the event
   * cell may have been a sibling.
   *
   * @param renderer The `Gtk::CellRenderer`.
   * @return The `Gtk::CellRenderer`
   * for which @a renderer is a sibling.
   */
  auto get_focus_from_sibling(CellRenderer& renderer) -> CellRenderer*;

  /** Gets the `Gtk::CellRenderer` which is expected to be focusable
   * for which @a renderer is, or may be a sibling.
   *
   * This is handy for `Gtk::CellArea` subclasses when handling events,
   * after determining the renderer at the event location it can
   * then chose to activate the focus cell for which the event
   * cell may have been a sibling.
   *
   * @param renderer The `Gtk::CellRenderer`.
   * @return The `Gtk::CellRenderer`
   * for which @a renderer is a sibling.
   */
  auto get_focus_from_sibling(CellRenderer& renderer) const -> const CellRenderer*;


  /** Gets the `Gtk::CellRenderer` in @a area that is currently
   * being edited.
   *
   * @return The currently edited `Gtk::CellRenderer`.
   */
  auto get_edited_cell() -> CellRenderer*;

  /** Gets the `Gtk::CellRenderer` in @a area that is currently
   * being edited.
   *
   * @return The currently edited `Gtk::CellRenderer`.
   */
  auto get_edited_cell() const -> const CellRenderer*;


  /** Gets the `Gtk::CellEditable` widget currently used
   * to edit the currently edited cell.
   *
   * @return The currently active `Gtk::CellEditable` widget.
   */
  auto get_edit_widget() -> CellEditable*;

  /** Gets the `Gtk::CellEditable` widget currently used
   * to edit the currently edited cell.
   *
   * @return The currently active `Gtk::CellEditable` widget.
   */
  auto get_edit_widget() const -> const CellEditable*;


  /** This is used by `Gtk::CellArea` subclasses when handling events
   * to activate cells, the base `Gtk::CellArea` class activates cells
   * for keyboard events for free in its own GtkCellArea->activate()
   * implementation.
   *
   * @param widget The `Gtk::Widget` that @a area is rendering onto.
   * @param renderer The `Gtk::CellRenderer` in @a area to activate.
   * @param gdk_event The `Gdk::Event` for which cell activation should occur.
   * @param cell_area The `Gdk::Rectangle` in @a widget relative coordinates
   * of @a renderer for the current row.
   * @param flags The `Gtk::CellRenderer`State for @a renderer.
   * @return Whether cell activation was successful.
   */
  auto activate_cell(Widget& widget, CellRenderer& renderer, const Glib::RefPtr<const Gdk::Event>& gdk_event, const Gdk::Rectangle& cell_area, CellRendererState flags) -> bool;

  /** Explicitly stops the editing of the currently edited cell.
   *
   * If @a canceled is <tt>true</tt>, the currently edited cell renderer
   * will emit the signal_editing_canceled() signal, otherwise the
   * the signal_editing_done() signal will be emitted on the current
   * edit widget.
   *
   * See get_edited_cell() and get_edit_widget().
   *
   * @param canceled Whether editing was canceled.
   */
  void stop_editing(bool canceled);


  /** This is a convenience function for `Gtk::CellArea` implementations
   * to get the inner area where a given `Gtk::CellRenderer` will be
   * rendered. It removes any padding previously added by request_renderer().
   *
   * @param widget The `Gtk::Widget` that @a area is rendering onto.
   * @param cell_area The @a widget relative coordinates where one of @a area’s cells
   * is to be placed.
   * @param inner_area The return location for the inner cell area.
   */
  void inner_cell_area(Widget& widget, const Gdk::Rectangle& cell_area, Gdk::Rectangle& inner_area);


  /** This is a convenience function for `Gtk::CellArea` implementations
   * to request size for cell renderers. It’s important to use this
   * function to request size and then use inner_cell_area()
   * at render and event time since this function will add padding
   * around the cell for focus painting.
   *
   * @param renderer The `Gtk::CellRenderer` to request size for.
   * @param orientation The `Gtk::Orientation` in which to request size.
   * @param widget The `Gtk::Widget` that @a area is rendering onto.
   * @param for_size The allocation contextual size to request for, or -1 if
   * the base request for the orientation is to be returned.
   * @param minimum_size Location to store the minimum size.
   * @param natural_size Location to store the natural size.
   */
  void request_renderer(CellRenderer& renderer, Orientation orientation, Widget& widget, int for_size, int& minimum_size, int& natural_size);

protected:


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%apply_attributes(const Glib::RefPtr<TreeModel>& tree_model, const TreeModel::iterator& iter, bool is_expander, bool is_expanded)</tt>
   *
   * Flags: Run First
   *
   * This signal is emitted whenever applying attributes to @a area from @a tree_model
   *
   * @param tree_model The `Gtk::TreeModel` to apply the attributes from.
   * @param iter The `Gtk::TreeIter` indicating which row to apply the attributes of.
   * @param is_expander Whether the view shows children for this row.
   * @param is_expanded Whether the view is currently showing the children of this row.
   */

  auto signal_apply_attributes() -> Glib::SignalProxy<void(const Glib::RefPtr<TreeModel>&, const TreeModel::iterator&, bool, bool)>;


  // The add-editable, remove-editable and focus-changed signals can't have default handlers because the wrapped C signals have no default handlers.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%add_editable(CellRenderer* renderer, CellEditable* editable, const Gdk::Rectangle& cell_area, const Glib::ustring& path)</tt>
   *
   * Flags: Run First
   *
   * Indicates that editing has started on @a renderer and that @a editable
   * should be added to the owning cell-layouting widget at @a cell_area.
   *
   * @param renderer The `Gtk::CellRenderer` that started the edited.
   * @param editable The `Gtk::CellEditable` widget to add.
   * @param cell_area The `Gtk::Widget` relative `Gdk::Rectangle` coordinates
   * where @a editable should be added.
   * @param path The `Gtk::TreePath` string this edit was initiated for.
   */

  auto signal_add_editable() -> Glib::SignalProxy<void(CellRenderer*, CellEditable*, const Gdk::Rectangle&, const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%remove_editable(CellRenderer* renderer, CellEditable* editable)</tt>
   *
   * Flags: Run First
   *
   * Indicates that editing finished on @a renderer and that @a editable
   * should be removed from the owning cell-layouting widget.
   *
   * @param renderer The `Gtk::CellRenderer` that finished editeding.
   * @param editable The `Gtk::CellEditable` widget to remove.
   */

  auto signal_remove_editable() -> Glib::SignalProxy<void(CellRenderer*, CellEditable*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%focus_changed(CellRenderer* renderer, const Glib::ustring& path)</tt>
   *
   * Flags: Run First
   *
   * Indicates that focus changed on this @a area. This signal
   * is emitted either as a result of focus handling or event
   * handling.
   *
   * It's possible that the signal is emitted even if the
   * currently focused renderer did not change, this is
   * because focus may change to the same renderer in the
   * same cell area for a different row of data.
   *
   * @param renderer The `Gtk::CellRenderer` that has focus.
   * @param path The current `Gtk::TreePath` string set for @a area.
   */

  auto signal_focus_changed() -> Glib::SignalProxy<void(CellRenderer*, const Glib::ustring&)>;


    virtual void snapshot_vfunc(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, const Glib::RefPtr<Gtk::Snapshot>& snapshot, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags, bool paint_focus);


//TODO: Wrap these vfuncs, mentioned in the GtkCellAreaContext overview documentation?
//  GtkCellAreaContext *(* create_context)                 (GtkCellArea             *area);
//  GtkCellAreaContext *(* copy_context)                   (GtkCellArea             *area,

    virtual auto get_request_mode_vfunc() const -> SizeRequestMode;

    virtual void get_preferred_width_vfunc(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int& minimum_width, int& natural_width);

    virtual void get_preferred_height_for_width_vfunc(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int width, int& minimum_height, int& natural_height);

    virtual void get_preferred_height_vfunc(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int& minimum_height, int& natural_height);

    virtual void get_preferred_width_for_height_vfunc(const Glib::RefPtr<CellAreaContext>& context, Widget& widget, int height, int& minimum_width, int& natural_width);


  /** The cell in the area that currently has focus
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_cell() -> Glib::PropertyProxy< CellRenderer* > ;

/** The cell in the area that currently has focus
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_cell() const -> Glib::PropertyProxy_ReadOnly< CellRenderer* >;

  /** The cell in the area that is currently edited
   *
   * This property is read-only and only changes as
   * a result of a call Gtk::CellArea::activate_cell().
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_edited_cell() const -> Glib::PropertyProxy_ReadOnly< CellRenderer* >;


  /** The widget currently editing the edited cell
   *
   * This property is read-only and only changes as
   * a result of a call Gtk::CellArea::activate_cell().
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_edit_widget() const -> Glib::PropertyProxy_ReadOnly< CellEditable* >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_apply_attributes().
  virtual void on_apply_attributes(const Glib::RefPtr<TreeModel>& tree_model, const TreeModel::iterator& iter, bool is_expander, bool is_expanded);


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
   * @relates Gtk::CellArea
   */
  GTKMM_API
  auto wrap(GtkCellArea* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellArea>;
}


#endif /* _GTKMM_CELLAREA_H */

