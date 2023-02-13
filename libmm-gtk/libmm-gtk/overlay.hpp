
#ifndef _GTKMM_OVERLAY_H
#define _GTKMM_OVERLAY_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2014 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkOverlay = struct _GtkOverlay;
using GtkOverlayClass = struct _GtkOverlayClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Overlay_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container which overlays widgets on top of each other.
 *
 * Gtk::Overlay is a container which contains a single main child, on top
 * of which it can place “overlay” widgets. The
 * position of each overlay widget is determined by its Gtk::Widget:halign
 * and Gtk::Widget:valign properties. E.g. a widget with both alignments
 * set to Gtk::Align::START will be placed at the top left corner of the
 * main widget, whereas an overlay with halign set to Gtk::Align::CENTER
 * and valign set to Gtk::Align::END will be placed a the bottom edge of
 * the main widget, horizontally centered. The position can be adjusted
 * by setting the margin properties of the child to non-zero values.
 *
 * More complicated placement of overlays is possible by connecting
 * to the Gtk::Overlay::get-child-position signal.
 *
 * The Gtk::Overlay implementation of the Gtk::Buildable interface
 * supports placing a child as an overlay by specifying “overlay” as
 * the “type” attribute of a `<child>` element.
 *
 * @ingroup Containers
 * @newin{3,14}
 */


class GTKMM_API Overlay
  : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Overlay CppObjectType;
  typedef Overlay_Class CppClassType;
  typedef GtkOverlay BaseObjectType;
  typedef GtkOverlayClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Overlay(Overlay&& src) noexcept;
  auto operator=(Overlay&& src) noexcept -> Overlay&;

  // noncopyable
  Overlay(const Overlay&) = delete;
  auto operator=(const Overlay&) -> Overlay& = delete;

  ~Overlay() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Overlay_Class;
  static CppClassType overlay_class_;

protected:
  explicit Overlay(const Glib::ConstructParams& construct_params);
  explicit Overlay(GtkOverlay* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkOverlay*       { return reinterpret_cast<GtkOverlay*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkOverlay* { return reinterpret_cast<GtkOverlay*>(gobject_); }

private:

public:

  /** Creates a new Overlay.
   */
  Overlay();


  /** Adds @a widget to @a overlay.
   *
   * The widget will be stacked on top of the main widget
   * added with set_child().
   *
   * The position at which @a widget is placed is determined
   * from its Gtk::Widget::property_halign() and
   * Gtk::Widget::property_valign() properties.
   *
   * @param widget A `Gtk::Widget` to be added to the container.
   */
  void add_overlay(Gtk::Widget& widget);

  /** Removes an overlay that was added with add_overlay().
   *
   * @param widget A `Gtk::Widget` to be removed.
   */
  void remove_overlay(Gtk::Widget& widget);


  /** Sets the child widget of @a overlay.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a overlay.
   *
   * @return The child widget of @a overlay.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a overlay.
   *
   * @return The child widget of @a overlay.
   */
  auto get_child() const -> const Widget*;


  /** Gets whether @a widget's size is included in the measurement of
   *  @a overlay.
   *
   * @param widget An overlay child of `Gtk::Overlay`.
   * @return Whether the widget is measured.
   */
  auto get_measure_overlay(Widget& widget) const -> bool;

  /** Sets whether @a widget is included in the measured size of @a overlay.
   *
   * The overlay will request the size of the largest child that has
   * this property set to <tt>true</tt>. Children who are not included may
   * be drawn outside of @a overlay's allocation if they are too large.
   *
   * @param widget An overlay child of `Gtk::Overlay`.
   * @param measure Whether the child should be measured.
   */
  void set_measure_overlay(Widget& widget, bool measure =  true);

  /** Gets whether @a widget should be clipped within the parent.
   *
   * @param widget An overlay child of `Gtk::Overlay`.
   * @return Whether the widget is clipped within the parent.
   */
  auto get_clip_overlay(const Widget& widget) const -> bool;

  /** Sets whether @a widget should be clipped within the parent.
   *
   * @param widget An overlay child of `Gtk::Overlay`.
   * @param clip_overlay Whether the child should be clipped.
   */
  void set_clip_overlay(const Widget& widget, bool clip_overlay =  true);

  // no_default_handler because GtkOverlayClass is private.


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%get_child_position(Gtk::Widget* widget, Gdk::Rectangle& allocation)</tt>
   *
   * Flags: Run Last
   *
   * Emitted to determine the position and size of any overlay
   * child widgets.
   *
   * A handler for this signal should fill @a allocation with
   * the desired position and size for @a widget, relative to
   * the 'main' child of @a overlay.
   *
   * The default handler for this signal uses the @a widget's
   * halign and valign properties to determine the position
   * and gives the widget its natural size (except that an
   * alignment of Gtk::Align::FILL will cause the overlay to
   * be full-width/height). If the main child is a
   * `Gtk::ScrolledWindow`, the overlays are placed relative
   * to its contents.
   *
   * @param widget The child widget to position.
   * @param allocation Return
   * location for the allocation.
   * @return <tt>true</tt> if the @a allocation has been filled.
   */

  auto signal_get_child_position() -> Glib::SignalProxy<bool(Gtk::Widget*, Gdk::Rectangle&)>;


  /**
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/**
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

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Overlay
   */
  GTKMM_API
  auto wrap(GtkOverlay* object, bool take_copy = false) -> Gtk::Overlay*;
} //namespace Glib


#endif /* _GTKMM_OVERLAY_H */

