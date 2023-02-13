
#ifndef _GTKMM_CELLRENDERER_H
#define _GTKMM_CELLRENDERER_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/celleditable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRenderer = struct _GtkCellRenderer;
using GtkCellRendererClass = struct _GtkCellRendererClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRenderer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Snapshot;

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var CellRendererState SELECTED
 * The cell is currently selected, and
 * probably has a selection colored background to render to.
 *
 *  @var CellRendererState PRELIT
 * The mouse is hovering over the cell.
 *
 *  @var CellRendererState INSENSITIVE
 * The cell is drawn in an insensitive manner.
 *
 *  @var CellRendererState SORTED
 * The cell is in a sorted row.
 *
 *  @var CellRendererState FOCUSED
 * The cell is in the focus row.
 *
 *  @var CellRendererState EXPANDABLE
 * The cell is in a row that can be expanded.
 *
 *  @var CellRendererState EXPANDED
 * The cell is in a row that is expanded.
 *
 *  @enum CellRendererState
 *
 * Tells how a cell is to be rendered.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>CellRendererState operator|(CellRendererState, CellRendererState)</tt><br>
 * <tt>CellRendererState operator&(CellRendererState, CellRendererState)</tt><br>
 * <tt>CellRendererState operator^(CellRendererState, CellRendererState)</tt><br>
 * <tt>CellRendererState operator~(CellRendererState)</tt><br>
 * <tt>CellRendererState& operator|=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>CellRendererState& operator&=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>CellRendererState& operator^=(CellRendererState&, CellRendererState)</tt><br>
 */
enum class CellRendererState
{
  SELECTED = 1 << 0,
  PRELIT = 1 << 1,
  INSENSITIVE = 1 << 2,
  SORTED = 1 << 3,
  FOCUSED = 1 << 4,
  EXPANDABLE = 1 << 5,
  EXPANDED = 1 << 6
};

/** @ingroup gtkmmEnums */
inline auto operator|(CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(CellRendererState flags) -> CellRendererState
  { return static_cast<CellRendererState>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CellRendererState> : public Glib::Value_Flags<Gtk::CellRendererState>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**
 *  @var CellRendererMode INERT
 * The cell is just for display
 * and cannot be interacted with.  Note that this doesn’t mean that eg. the
 * row being drawn can’t be selected -- just that a particular element of
 * it cannot be individually modified.
 *
 *  @var CellRendererMode ACTIVATABLE
 * The cell can be clicked.
 *
 *  @var CellRendererMode EDITABLE
 * The cell can be edited or otherwise modified.
 *
 *  @enum CellRendererMode
 *
 * Identifies how the user can interact with a particular cell.
 *
 * @ingroup gtkmmEnums
 */
enum class CellRendererMode
{
  INERT,
  ACTIVATABLE,
  EDITABLE
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CellRendererMode> : public Glib::Value_Enum<Gtk::CellRendererMode>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** CellRenderers are used by Gtk::TreeView columns to render the Gtk::TreeModel column data appropriately.
 * They display, and allow editing of, the values of their properties.
 * In most cases, Gtk::TreeView::append_column() will automatically choose the appropriate renderer for the mode column's data type,
 * so you will rarely need to worry about these classes.
 *
 * @ingroup TreeView
 */

class GTKMM_API CellRenderer :
  public Object
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRenderer CppObjectType;
  typedef CellRenderer_Class CppClassType;
  typedef GtkCellRenderer BaseObjectType;
  typedef GtkCellRendererClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRenderer(CellRenderer&& src) noexcept;
  auto operator=(CellRenderer&& src) noexcept -> CellRenderer&;

  // noncopyable
  CellRenderer(const CellRenderer&) = delete;
  auto operator=(const CellRenderer&) -> CellRenderer& = delete;

  ~CellRenderer() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class CellRenderer_Class;
  static CppClassType cellrenderer_class_;

protected:
  explicit CellRenderer(const Glib::ConstructParams& construct_params);
  explicit CellRenderer(GtkCellRenderer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkCellRenderer*       { return reinterpret_cast<GtkCellRenderer*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCellRenderer* { return reinterpret_cast<GtkCellRenderer*>(gobject_); }

private:

public:


  /** Gets whether the cell renderer prefers a height-for-width layout
   * or a width-for-height layout.
   *
   * @return The `Gtk::SizeRequestMode` preferred by this renderer.
   */
  auto get_request_mode() const -> SizeRequestMode;

  /** Retrieves a renderer’s natural size when rendered to @a widget.
   *
   * @param widget The `Gtk::Widget` this cell will be rendering to.
   * @param minimum_width Location to store the minimum size.
   * @param natural_width Location to store the natural size.
   */
  void get_preferred_width(Widget& widget, int& minimum_width, int& natural_width) const;

  /** Retrieves a cell renderers’s minimum and natural height if it were rendered to
   *  @a widget with the specified @a width.
   *
   * @param widget The `Gtk::Widget` this cell will be rendering to.
   * @param width The size which is available for allocation.
   * @param minimum_height Location for storing the minimum size.
   * @param natural_height Location for storing the preferred size.
   */
  void get_preferred_height_for_width(Widget& widget, int width, int& minimum_height, int& natural_height) const;

  /** Retrieves a renderer’s natural size when rendered to @a widget.
   *
   * @param widget The `Gtk::Widget` this cell will be rendering to.
   * @param minimum_height Location to store the minimum size.
   * @param natural_height Location to store the natural size.
   */
  void get_preferred_height(Widget& widget, int& minimum_height, int& natural_height) const;

  /** Retrieves a cell renderers’s minimum and natural width if it were rendered to
   *  @a widget with the specified @a height.
   *
   * @param widget The `Gtk::Widget` this cell will be rendering to.
   * @param height The size which is available for allocation.
   * @param minimum_width Location for storing the minimum size.
   * @param natural_width Location for storing the preferred size.
   */
  void get_preferred_width_for_height(Widget& widget, int height, int& minimum_width, int& natural_width) const;

  /** Retrieves the minimum and natural size of a cell taking
   * into account the widget’s preference for height-for-width management.
   *
   * @param widget The `Gtk::Widget` this cell will be rendering to.
   * @param minimum_size Location for storing the minimum size.
   * @param natural_size Location for storing the natural size.
   */
  void get_preferred_size(Widget& widget, Requisition& minimum_size, Requisition& natural_size) const;

  /** Gets the aligned area used by this %CellRenderer inside @a cell_area.
   * Used for finding the appropriate edit and focus rectangle.
   *
   * @newin{3,0}
   *
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param flags Render flags.
   * @param cell_area Cell area which would be passed to snapshot().
   * @returns The space inside @a cell_area that would acually be used to render.
   */
  auto get_aligned_area(Widget& widget, CellRendererState flags, const Gdk::Rectangle& cell_area) const -> Gdk::Rectangle;


  /** Invokes the virtual render function of the `Gtk::CellRenderer`. The three
   * passed-in rectangles are areas in @a cr. Most renderers will draw within
   *  @a cell_area; the xalign, yalign, xpad, and ypad fields of the `Gtk::CellRenderer`
   * should be honored with respect to @a cell_area. @a background_area includes the
   * blank space around the cell, and also the area containing the tree expander;
   * so the @a background_area rectangles for all cells tile to cover the entire
   *  @a window.
   *
   * @param snapshot A `Gtk::Snapshot` to draw to.
   * @param widget The widget owning @a window.
   * @param background_area Entire cell area (including tree expanders and maybe
   * padding on the sides).
   * @param cell_area Area normally rendered by a cell renderer.
   * @param flags Flags that affect rendering.
   */
  void snapshot(const Glib::RefPtr<Gtk::Snapshot>& snapshot, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


  /** Passes an activate event to the cell renderer for possible processing.
   * Some cell renderers may use events; for example, `Gtk::CellRendererToggle`
   * toggles when it gets a mouse click.
   *
   * @param event A `Gdk::Event`.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location;
   * e.g. for `Gtk::TreeView`, a string representation of `Gtk::TreePath`.
   * @param background_area Background area as passed to gtk_cell_renderer_render().
   * @param cell_area Cell area as passed to gtk_cell_renderer_render().
   * @param flags Render flags.
   * @return <tt>true</tt> if the event was consumed/handled.
   */
  auto activate(const Glib::RefPtr<const Gdk::Event>& event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags) -> bool;


  /** Starts editing the contents of this @a cell, through a new `Gtk::CellEditable`
   * widget created by the `Gtk::CellRenderer`Class.start_editing virtual function.
   *
   * @param event A `Gdk::Event`.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location;
   * e.g. for `Gtk::TreeView`, a string representation of `Gtk::TreePath`.
   * @param background_area Background area as passed to gtk_cell_renderer_render().
   * @param cell_area Cell area as passed to gtk_cell_renderer_render().
   * @param flags Render flags.
   * @return A new `Gtk::CellEditable` for editing this
   *  @a cell, or <tt>nullptr</tt> if editing is not possible.
   */
  auto start_editing(const Glib::RefPtr<const Gdk::Event>& event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags =  CellRendererState(0)) -> CellEditable*;


  /** Sets the renderer size to be explicit, independent of the properties set.
   *
   * @param width The width of the cell renderer, or -1.
   * @param height The height of the cell renderer, or -1.
   */
  void set_fixed_size(int width, int height);

  /** Fills in @a width and @a height with the appropriate size of @a cell.
   *
   * @param width Location to fill in with the fixed width of the widget.
   * @param height Location to fill in with the fixed height of the widget.
   */
  void get_fixed_size(int& width, int& height) const;


  /** Sets the renderer’s alignment within its available space.
   *
   * @param xalign The x alignment of the cell renderer.
   * @param yalign The y alignment of the cell renderer.
   */
  void set_alignment(float xalign, float yalign);

  /** Fills in @a xalign and @a yalign with the appropriate values of @a cell.
   *
   * @param xalign Location to fill in with the x alignment of the cell.
   * @param yalign Location to fill in with the y alignment of the cell.
   */
  void get_alignment(float& xalign, float& yalign) const;


  /** Sets the renderer’s padding.
   *
   * @param xpad The x padding of the cell renderer.
   * @param ypad The y padding of the cell renderer.
   */
  void set_padding(int xpad, int ypad);

  /** Fills in @a xpad and @a ypad with the appropriate values of @a cell.
   *
   * @param xpad Location to fill in with the x padding of the cell.
   * @param ypad Location to fill in with the y padding of the cell.
   */
  void get_padding(int& xpad, int& ypad) const;


  /** Sets the cell renderer’s visibility.
   *
   * @param visible The visibility of the cell.
   */
  void set_visible(bool visible =  true);

  /** Returns the cell renderer’s visibility.
   *
   * @return <tt>true</tt> if the cell renderer is visible.
   */
  auto get_visible() const -> bool;

  /** Sets the cell renderer’s sensitivity.
   *
   * @param sensitive The sensitivity of the cell.
   */
  void set_sensitive(bool sensitive =  true);

  /** Returns the cell renderer’s sensitivity.
   *
   * @return <tt>true</tt> if the cell renderer is sensitive.
   */
  auto get_sensitive() const -> bool;

  /** Checks whether the cell renderer can do something when activated.
   *
   * @return <tt>true</tt> if the cell renderer can do anything when activated.
   */
  auto is_activatable() const -> bool;

  /** Sets whether the given `Gtk::CellRenderer` is an expander.
   *
   * @param is_expander Whether @a cell is an expander.
   */
  void set_is_expander(bool is_expander =  true);

  /** Checks whether the given `Gtk::CellRenderer` is an expander.
   *
   * @return <tt>true</tt> if @a cell is an expander, and <tt>false</tt> otherwise.
   */
  auto get_is_expander() const -> bool;

  /** Sets whether the given `Gtk::CellRenderer` is expanded.
   *
   * @param is_expanded Whether @a cell should be expanded.
   */
  void set_is_expanded(bool is_expanded =  true);

  /** Checks whether the given `Gtk::CellRenderer` is expanded.
   *
   * @return <tt>true</tt> if the cell renderer is expanded.
   */
  auto get_is_expanded() const -> bool;


  /** Informs the cell renderer that the editing is stopped.
   * If @a canceled is <tt>true</tt>, the cell renderer will emit the
   * `Gtk::CellRenderer`::editing-canceled signal.
   *
   * This function should be called by cell renderer implementations
   * in response to the `GtkCellEditable::editing-done` signal of
   * `Gtk::CellEditable`.
   *
   * @param canceled <tt>true</tt> if the editing has been canceled.
   */
  void stop_editing(bool canceled =  false);


  /** Translates the cell renderer state to `Gtk::StateFlags`,
   * based on the cell renderer and widget sensitivity, and
   * the given `Gtk::CellRenderer`State.
   *
   * @param widget A `Gtk::Widget`.
   * @param cell_state Cell renderer state.
   * @return The widget state flags applying to @a cell.
   */
  auto get_state(Widget& widget, CellRendererState cell_state) const -> StateFlags;

  /// A get_state() convenience overload.
  auto get_state(CellRendererState cell_state) const -> StateFlags;

  /** Returns the property that this CellRenderer renders.
   * For instance, property_text for CellRendererText, and property_active for CellRendererToggle
   * Needs to be overridden in derived classes.
   */
  virtual auto _property_renderable() -> Glib::PropertyProxy_Base;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_canceled()</tt>
   *
   * Flags: Run First
   *
   * This signal gets emitted when the user cancels the process of editing a
   * cell.  For example, an editable cell renderer could be written to cancel
   * editing when the user presses Escape.
   *
   * See also: Gtk::CellRenderer::stop_editing().
   */

  auto signal_editing_canceled() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_started(CellEditable* editable, const Glib::ustring& path)</tt>
   *
   * Flags: Run First
   *
   * This signal gets emitted when a cell starts to be edited.
   * The intended use of this signal is to do special setup
   * on @a editable, e.g. adding a `Gtk::EntryCompletion` or setting
   * up additional columns in a `Gtk::ComboBox`.
   *
   * See Gtk::CellEditable::start_editing() for information on the lifecycle of
   * the @a editable and a way to do setup that doesn’t depend on the @a renderer.
   *
   * Note that GTK doesn't guarantee that cell renderers will
   * continue to use the same kind of widget for editing in future
   * releases, therefore you should check the type of @a editable
   * before doing any specific setup, as in the following example:
   *
   * [C example ellipted]
   *
   * @param editable The `Gtk::CellEditable`.
   * @param path The path identifying the edited cell.
   */

  auto signal_editing_started() -> Glib::SignalProxy<void(CellEditable*, const Glib::ustring&)>;


  /** Default value: Gtk::CellRendererMode::INERT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() -> Glib::PropertyProxy< CellRendererMode > ;

/** Default value: Gtk::CellRendererMode::INERT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mode() const -> Glib::PropertyProxy_ReadOnly< CellRendererMode >;

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

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sensitive() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() -> Glib::PropertyProxy< float > ;

/** Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() -> Glib::PropertyProxy< float > ;

/** Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xpad() -> Glib::PropertyProxy< unsigned int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_xpad() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ypad() -> Glib::PropertyProxy< unsigned int > ;

/** Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ypad() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height() -> Glib::PropertyProxy< int > ;

/** Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_expander() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_expander() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_expanded() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_expanded() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** Cell background as a `GdkRGBA`
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA > ;

/** Cell background as a `GdkRGBA`
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_background_set() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cell_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_editing() const -> Glib::PropertyProxy_ReadOnly< bool >;


protected:
  CellRenderer();

    virtual auto get_request_mode_vfunc() const -> SizeRequestMode;

    virtual void get_preferred_width_vfunc(Widget& widget, int& minimum_width, int& natural_width) const;

    virtual void get_preferred_height_for_width_vfunc(Widget& widget, int width, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_height_vfunc(Widget& widget, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_width_for_height_vfunc(Widget& widget, int height, int& minimum_width, int& natural_width) const;


    virtual void snapshot_vfunc(const Glib::RefPtr<Gtk::Snapshot>& snapshot, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


    virtual auto activate_vfunc(const Glib::RefPtr<const Gdk::Event>& event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags) -> bool;


    virtual auto start_editing_vfunc(const Glib::RefPtr<const Gdk::Event>& event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags) -> CellEditable*;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_editing_canceled().
  virtual void on_editing_canceled();
  /// This is a default handler for the signal signal_editing_started().
  virtual void on_editing_started(CellEditable* editable, const Glib::ustring& path);


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
   * @relates Gtk::CellRenderer
   */
  GTKMM_API
  auto wrap(GtkCellRenderer* object, bool take_copy = false) -> Gtk::CellRenderer*;
} //namespace Glib


#endif /* _GTKMM_CELLRENDERER_H */
