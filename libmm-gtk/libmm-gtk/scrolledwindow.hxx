
#ifndef _GTKMM_SCROLLEDWINDOW_H
#define _GTKMM_SCROLLEDWINDOW_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScrolledWindow = struct _GtkScrolledWindow;
using GtkScrolledWindowClass = struct _GtkScrolledWindowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ScrolledWindow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class Adjustment;
class Scrollbar;

/** Adds scrollbars to its child widget.
 *
 * This container accepts a single child widget. It adds scrollbars to the child widget and optionally draws a beveled frame around the child widget.
 * The scrolled window can work in two ways:
 * <OL>
 * <LI>Some widgets have native scrolling support; these widgets handle certain Gtk::Adjustment signals. Widgets with native scroll support include Gtk::TreeView, Gtk::TextView, and Gtk::Layout.</LI>
 * <LI>For widgets that lack native scrolling support, such as Gtk::Grid, Gtk::Box, and so on, the widget will be placed inside a Gtk::Viewport.</LI>
 * </OL>
 *
 * The position of the scrollbars is controlled by the scroll adjustments. See Gtk::Adjustment for the fields in an adjustment - for Gtk::Scrollbar, used by Gtk::ScrolledWindow,
 * the "value" field represents the position of the scrollbar, which must be between the "lower" field and "upper - page_size."
 * The "page_size" field represents the size of the visible scrollable area.
 * The "step_increment" and "page_increment" fields are used when the user asks to step down (using the small stepper arrows) or page down (using for example the PageDown key).
 *
 * If a Gtk::ScrolledWindow doesn't behave quite as you would like, or doesn't have exactly the right layout, it's very possible to set up your own scrolling with Gtk::Scrollbar and, for example, a Gtk::Grid.
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API ScrolledWindow : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ScrolledWindow CppObjectType;
  typedef ScrolledWindow_Class CppClassType;
  typedef GtkScrolledWindow BaseObjectType;
  typedef GtkScrolledWindowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ScrolledWindow(ScrolledWindow&& src) noexcept;
  auto operator=(ScrolledWindow&& src) noexcept -> ScrolledWindow&;

  // noncopyable
  ScrolledWindow(const ScrolledWindow&) = delete;
  auto operator=(const ScrolledWindow&) -> ScrolledWindow& = delete;

  ~ScrolledWindow() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ScrolledWindow_Class;
  static CppClassType scrolledwindow_class_;

protected:
  explicit ScrolledWindow(const Glib::ConstructParams& construct_params);
  explicit ScrolledWindow(GtkScrolledWindow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkScrolledWindow*       { return reinterpret_cast<GtkScrolledWindow*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkScrolledWindow* { return reinterpret_cast<GtkScrolledWindow*>(gobject_); }

private:


public:
  ScrolledWindow();


  /** Sets the `Gtk::Adjustment` for the horizontal scrollbar.
   *
   * @param hadjustment The `Gtk::Adjustment` to use, or <tt>nullptr</tt> to create a new one.
   */
  void set_hadjustment(const Glib::RefPtr<Adjustment>& hadjustment);

  /** Sets the `Gtk::Adjustment` for the vertical scrollbar.
   *
   * @param vadjustment The `Gtk::Adjustment` to use, or <tt>nullptr</tt> to create a new one.
   */
  void set_vadjustment(const Glib::RefPtr<Adjustment>& vadjustment);


  /** Returns the horizontal scrollbar’s adjustment.
   *
   * This is the adjustment used to connect the horizontal scrollbar
   * to the child widget’s horizontal scroll functionality.
   *
   * @return The horizontal `Gtk::Adjustment`.
   */
  auto get_hadjustment() -> Glib::RefPtr<Adjustment>;

  /** Returns the horizontal scrollbar’s adjustment.
   *
   * This is the adjustment used to connect the horizontal scrollbar
   * to the child widget’s horizontal scroll functionality.
   *
   * @return The horizontal `Gtk::Adjustment`.
   */
  auto get_hadjustment() const -> Glib::RefPtr<const Adjustment>;

  /** Returns the vertical scrollbar’s adjustment.
   *
   * This is the adjustment used to connect the vertical
   * scrollbar to the child widget’s vertical scroll functionality.
   *
   * @return The vertical `Gtk::Adjustment`.
   */
  auto get_vadjustment() -> Glib::RefPtr<Adjustment>;

  /** Returns the vertical scrollbar’s adjustment.
   *
   * This is the adjustment used to connect the vertical
   * scrollbar to the child widget’s vertical scroll functionality.
   *
   * @return The vertical `Gtk::Adjustment`.
   */
  auto get_vadjustment() const -> Glib::RefPtr<const Adjustment>;


  /** Sets the scrollbar policy for the horizontal and vertical scrollbars.
   *
   * The policy determines when the scrollbar should appear; it is a value
   * from the Gtk::PolicyType enumeration. If Gtk::PolicyType::ALWAYS, the
   * scrollbar is always present; if Gtk::PolicyType::NEVER, the scrollbar is
   * never present; if Gtk::PolicyType::AUTOMATIC, the scrollbar is present only
   * if needed (that is, if the slider part of the bar would be smaller
   * than the trough — the display is larger than the page size).
   *
   * @param hscrollbar_policy Policy for horizontal bar.
   * @param vscrollbar_policy Policy for vertical bar.
   */
  void set_policy(PolicyType hscrollbar_policy, PolicyType vscrollbar_policy);

  /** Retrieves the current policy values for the horizontal and vertical
   * scrollbars.
   *
   * See set_policy().
   *
   * @param hscrollbar_policy Location to store the policy
   * for the horizontal scrollbar.
   * @param vscrollbar_policy Location to store the policy
   * for the vertical scrollbar.
   */
  void get_policy(PolicyType& hscrollbar_policy, PolicyType& vscrollbar_policy) const;


  /** Sets the placement of the contents with respect to the scrollbars
   * for the scrolled window.
   *
   * The default is Gtk::CornerType::TOP_LEFT, meaning the child is
   * in the top left, with the scrollbars underneath and to the right.
   * Other values in Gtk::CornerType are Gtk::CornerType::TOP_RIGHT,
   * Gtk::CornerType::BOTTOM_LEFT, and Gtk::CornerType::BOTTOM_RIGHT.
   *
   * See also get_placement() and
   * unset_placement().
   *
   * @param window_placement Position of the child window.
   */
  void set_placement(CornerType window_placement);

  /** Unsets the placement of the contents with respect to the scrollbars.
   *
   * If no window placement is set for a scrolled window,
   * it defaults to Gtk::CornerType::TOP_LEFT.
   */
  void unset_placement();

  /** Gets the placement of the contents with respect to the scrollbars.
   *
   * @return The current placement value.
   */
  auto get_placement() const -> CornerType;


  /** Changes the frame drawn around the contents of @a scrolled_window.
   *
   * @param has_frame Whether to draw a frame around scrolled window contents.
   */
  void set_has_frame(bool has_frame =  true);

  /** Gets whether the scrolled window draws a frame.
   *
   * @return <tt>true</tt> if the @a scrolled_window has a frame.
   */
  auto get_has_frame() const -> bool;


  /** Returns the vertical scrollbar of @a scrolled_window.
   *
   * @return The vertical scrollbar of the scrolled window.
   */
  auto get_vscrollbar() -> Scrollbar*;

  /** Returns the vertical scrollbar of @a scrolled_window.
   *
   * @return The vertical scrollbar of the scrolled window.
   */
  auto get_vscrollbar() const -> const Scrollbar*;


  /** Returns the horizontal scrollbar of @a scrolled_window.
   *
   * @return The horizontal scrollbar of the scrolled window.
   */
  auto get_hscrollbar() -> Scrollbar*;

  /** Returns the horizontal scrollbar of @a scrolled_window.
   *
   * @return The horizontal scrollbar of the scrolled window.
   */
  auto get_hscrollbar() const -> const Scrollbar*;


  /** Gets the minimum content width of @a scrolled_window.
   *
   * @return The minimum content width.
   */
  auto get_min_content_width() const -> int;

  /** Sets the minimum width that @a scrolled_window should keep visible.
   *
   * Note that this can and (usually will) be smaller than the minimum
   * size of the content.
   *
   * It is a programming error to set the minimum content width to a
   * value greater than property_max_content_width().
   *
   * @param width The minimal content width.
   */
  void set_min_content_width(int width);

  /** Gets the minimal content height of @a scrolled_window.
   *
   * @return The minimal content height.
   */
  auto get_min_content_height() const -> int;

  /** Sets the minimum height that @a scrolled_window should keep visible.
   *
   * Note that this can and (usually will) be smaller than the minimum
   * size of the content.
   *
   * It is a programming error to set the minimum content height to a
   * value greater than property_max_content_height().
   *
   * @param height The minimal content height.
   */
  void set_min_content_height(int height);


  /** Turns kinetic scrolling on or off.
   *
   * Kinetic scrolling only applies to devices with source
   * Gdk::InputSource::TOUCHSCREEN.
   *
   * @param kinetic_scrolling <tt>true</tt> to enable kinetic scrolling.
   */
  void set_kinetic_scrolling(bool kinetic_scrolling =  true);

  /** Returns the specified kinetic scrolling behavior.
   *
   * @return The scrolling behavior flags.
   */
  auto get_kinetic_scrolling() const -> bool;


  /** Enables or disables overlay scrolling for this scrolled window.
   *
   * @param overlay_scrolling Whether to enable overlay scrolling.
   */
  void set_overlay_scrolling(bool overlay_scrolling =  true);

  /** Returns whether overlay scrolling is enabled for this scrolled window.
   *
   * @return <tt>true</tt> if overlay scrolling is enabled.
   */
  auto get_overlay_scrolling() const -> bool;


  /** Sets the maximum width that @a scrolled_window should keep visible.
   *
   * The @a scrolled_window will grow up to this width before it starts
   * scrolling the content.
   *
   * It is a programming error to set the maximum content width to a
   * value smaller than property_min_content_width().
   *
   * @param width The maximum content width.
   */
  void set_max_content_width(int width);

  /** Returns the maximum content width set.
   *
   * @return The maximum content width, or -1.
   */
  auto get_max_content_width() const -> int;

  /** Sets the maximum height that @a scrolled_window should keep visible.
   *
   * The @a scrolled_window will grow up to this height before it starts
   * scrolling the content.
   *
   * It is a programming error to set the maximum content height to a value
   * smaller than property_min_content_height().
   *
   * @param height The maximum content height.
   */
  void set_max_content_height(int height);

  /** Returns the maximum content height set.
   *
   * @return The maximum content height, or -1.
   */
  auto get_max_content_height() const -> int;


  /** Sets whether the natural width of the child should be calculated
   * and propagated through the scrolled window’s requested natural width.
   *
   * @param propagate Whether to propagate natural width.
   */
  void set_propagate_natural_width(bool propagate =  true);

  /** Reports whether the natural width of the child will be calculated
   * and propagated through the scrolled window’s requested natural width.
   *
   * @return Whether natural width propagation is enabled.
   */
  auto get_propagate_natural_width() const -> bool;

  /** Sets whether the natural height of the child should be calculated
   * and propagated through the scrolled window’s requested natural height.
   *
   * @param propagate Whether to propagate natural height.
   */
  void set_propagate_natural_height(bool propagate =  true);

  /** Reports whether the natural height of the child will be calculated
   * and propagated through the scrolled window’s requested natural height.
   *
   * @return Whether natural height propagation is enabled.
   */
  auto get_propagate_natural_height() const -> bool;


  /** Sets the child widget of @a scrolled_window.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a scrolled_window.
   *
   * @return The child widget of @a scrolled_window.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a scrolled_window.
   *
   * @return The child widget of @a scrolled_window.
   */
  auto get_child() const -> const Widget*;

  //Keybinding signals:


  // no_default_handler because the wrapped C signals have no default handlers.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%edge_overshot(Gtk::PositionType pos)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever user initiated scrolling makes the scrolled
   * window firmly surpass the limits defined by the adjustment
   * in that orientation.
   *
   * A similar behavior without edge resistance is provided by the
   * signal_edge_reached() signal.
   *
   * @note The @a pos argument is LTR/RTL aware, so callers should be
   * aware too if intending to provide behavior on horizontal edges.
   *
   * @param pos Edge side that was hit.
   */

  auto signal_edge_overshot() -> Glib::SignalProxy<void(Gtk::PositionType)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%edge_reached(Gtk::PositionType pos)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever user-initiated scrolling makes the scrolled
   * window exactly reach the lower or upper limits defined by the
   * adjustment in that orientation.
   *
   * A similar behavior with edge resistance is provided by the
   * signal_edge_overshot() signal.
   *
   * @note The @a pos argument is LTR/RTL aware, so callers should be
   * aware too if intending to provide behavior on horizontal edges.
   *
   * @param pos Edge side that was reached.
   */

  auto signal_edge_reached() -> Glib::SignalProxy<void(Gtk::PositionType)>;


  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> > ;

/**
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >;

  /** When the horizontal scrollbar is displayed.
   *
   * Use Gtk::ScrolledWindow::set_policy() to set
   * this property.
   *
   * Default value: Gtk::PolicyType::AUTOMATIC
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hscrollbar_policy() -> Glib::PropertyProxy< PolicyType > ;

/** When the horizontal scrollbar is displayed.
   *
   * Use Gtk::ScrolledWindow::set_policy() to set
   * this property.
   *
   * Default value: Gtk::PolicyType::AUTOMATIC
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hscrollbar_policy() const -> Glib::PropertyProxy_ReadOnly< PolicyType >;

  /** When the vertical scrollbar is displayed.
   *
   * Use Gtk::ScrolledWindow::set_policy() to set
   * this property.
   *
   * Default value: Gtk::PolicyType::AUTOMATIC
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vscrollbar_policy() -> Glib::PropertyProxy< PolicyType > ;

/** When the vertical scrollbar is displayed.
   *
   * Use Gtk::ScrolledWindow::set_policy() to set
   * this property.
   *
   * Default value: Gtk::PolicyType::AUTOMATIC
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_vscrollbar_policy() const -> Glib::PropertyProxy_ReadOnly< PolicyType >;

  /** Where the contents are located with respect to the scrollbars.
   *
   * Default value: Gtk::CornerType::TOP_LEFT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_window_placement() -> Glib::PropertyProxy< CornerType > ;

/** Where the contents are located with respect to the scrollbars.
   *
   * Default value: Gtk::CornerType::TOP_LEFT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_window_placement() const -> Glib::PropertyProxy_ReadOnly< CornerType >;

  /** Whether to draw a frame around the contents.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() -> Glib::PropertyProxy< bool > ;

/** Whether to draw a frame around the contents.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The minimum content width of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_content_width() -> Glib::PropertyProxy< int > ;

/** The minimum content width of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_content_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The minimum content height of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_content_height() -> Glib::PropertyProxy< int > ;

/** The minimum content height of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_content_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether kinetic scrolling is enabled or not.
   *
   * Kinetic scrolling only applies to devices with source Gdk::InputSource::TOUCHSCREEN.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_kinetic_scrolling() -> Glib::PropertyProxy< bool > ;

/** Whether kinetic scrolling is enabled or not.
   *
   * Kinetic scrolling only applies to devices with source Gdk::InputSource::TOUCHSCREEN.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_kinetic_scrolling() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether overlay scrolling is enabled or not.
   *
   * If it is, the scrollbars are only added as traditional widgets
   * when a mouse is present. Otherwise, they are overlaid on top of
   * the content, as narrow indicators.
   *
   * Note that overlay scrolling can also be globally disabled, with
   * the Gtk::Settings::property_gtk_overlay_scrolling() setting.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overlay_scrolling() -> Glib::PropertyProxy< bool > ;

/** Whether overlay scrolling is enabled or not.
   *
   * If it is, the scrollbars are only added as traditional widgets
   * when a mouse is present. Otherwise, they are overlaid on top of
   * the content, as narrow indicators.
   *
   * Note that overlay scrolling can also be globally disabled, with
   * the Gtk::Settings::property_gtk_overlay_scrolling() setting.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_overlay_scrolling() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The maximum content width of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_content_width() -> Glib::PropertyProxy< int > ;

/** The maximum content width of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_content_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The maximum content height of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_content_height() -> Glib::PropertyProxy< int > ;

/** The maximum content height of @a scrolled_window.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_content_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the natural width of the child should be calculated and propagated
   * through the scrolled window’s requested natural width.
   *
   * This is useful in cases where an attempt should be made to allocate exactly
   * enough space for the natural size of the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_natural_width() -> Glib::PropertyProxy< bool > ;

/** Whether the natural width of the child should be calculated and propagated
   * through the scrolled window’s requested natural width.
   *
   * This is useful in cases where an attempt should be made to allocate exactly
   * enough space for the natural size of the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_natural_width() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the natural height of the child should be calculated and propagated
   * through the scrolled window’s requested natural height.
   *
   * This is useful in cases where an attempt should be made to allocate exactly
   * enough space for the natural size of the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_natural_height() -> Glib::PropertyProxy< bool > ;

/** Whether the natural height of the child should be calculated and propagated
   * through the scrolled window’s requested natural height.
   *
   * This is useful in cases where an attempt should be made to allocate exactly
   * enough space for the natural size of the child.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_propagate_natural_height() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ScrolledWindow
   */
  GTKMM_API
  auto wrap(GtkScrolledWindow* object, bool take_copy = false) -> Gtk::ScrolledWindow*;
} //namespace Glib


#endif /* _GTKMM_SCROLLEDWINDOW_H */

