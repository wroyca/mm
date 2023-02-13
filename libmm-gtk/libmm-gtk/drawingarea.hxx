
#ifndef _GTKMM_DRAWINGAREA_H
#define _GTKMM_DRAWINGAREA_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDrawingArea = struct _GtkDrawingArea;
using GtkDrawingAreaClass = struct _GtkDrawingAreaClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DrawingArea_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget for custom user interface elements.
 *
 * The %DrawingArea widget is used for creating custom user interface
 * elements. It’s essentially a blank widget; you can draw on it. After
 * creating a drawing area, the application may want to connect to:
 *
 * - Mouse and button press signals to respond to input from
 *   the user. (Use Gtk::Widget::add_events() to enable events
 *   you wish to receive.)
 *
 * - Gtk::Widget::signal_realize() to take any necessary actions
 *   when the widget is instantiated on a particular display.
 *   (Create GDK resources in response to this signal.)
 *
 * - Gtk::Widget::signal_size_allocate() to take any necessary
 *   actions when the widget changes size.
 *
 * - Call set_draw_func() to handle redrawing the contents of the widget.
 *
 * The following code portion demonstrates using a drawing
 * area to display a circle in the normal widget foreground color.
 *
 * Note that GDK automatically clears the exposed area before causing a
 * redraw, and that drawing is implicitly clipped to the exposed
 * area. If you want to have a theme-provided background, you need
 * to call Gtk::StyleContext::render_background() in your draw function.
 *
 * Simple %DrawingArea usage:
 * @code
 * class MyDrawingArea : public Gtk::DrawingArea
 * {
 * public:
 *   MyDrawingArea()
 *   {
 *     set_draw_func(sigc::mem_fun(*this, &MyDrawingArea::on_draw));
 *   }
 *
 *   void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
 *   {
 *     auto style_context = get_style_context();
 *
 *     style_context->render_background(cr, 0, 0, width, height);
 *
 *     cr->arc(width / 2.0, height / 2.0, std::min(width, height) / 2.0, 0, 2 * M_PI);
 *
 *     auto color = style_context->get_color();
 *     Gdk::Cairo::set_source_rgba(cr, color);
 *
 *     cr->fill();
 *   }
 * //...
 * }; // end MyDrawingArea
 *
 * //...
 * auto area = Gtk::manage(new MyDrawingArea)
 * area->set_content_width(100);
 * area->set_content_height(100);
 * @endcode
 *
 * The draw function is normally called when a drawing area first comes
 * onscreen, or when it’s covered by another window and then uncovered.
 * You can also force a redraw by adding to the “damage region” of the
 * drawing area’s window using Gtk::Widget::queue_draw_region(),
 * Gtk::Widget::queue_draw_area() or Gtk::Widget::queue_draw().
 * This will cause the drawing area to call the draw function again.
 *
 * To receive mouse events on a drawing area, you will need to use
 * event controllers. To receive keyboard events, you will need to set
 * the “can-focus” property on the drawing area, and you should probably
 * draw some user-visible indication that the drawing is focused.
 *
 * @ingroup Widgets
 */

class GTKMM_API DrawingArea : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef DrawingArea CppObjectType;
  typedef DrawingArea_Class CppClassType;
  typedef GtkDrawingArea BaseObjectType;
  typedef GtkDrawingAreaClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  DrawingArea(DrawingArea&& src) noexcept;
  auto operator=(DrawingArea&& src) noexcept -> DrawingArea&;

  // noncopyable
  DrawingArea(const DrawingArea&) = delete;
  auto operator=(const DrawingArea&) -> DrawingArea& = delete;

  ~DrawingArea() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class DrawingArea_Class;
  static CppClassType drawingarea_class_;

protected:
  explicit DrawingArea(const Glib::ConstructParams& construct_params);
  explicit DrawingArea(GtkDrawingArea* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkDrawingArea*       { return reinterpret_cast<GtkDrawingArea*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDrawingArea* { return reinterpret_cast<GtkDrawingArea*>(gobject_); }

private:


public:
  DrawingArea();

/** Whenever the drawing area needs to redraw, this slot will be called.
 *
 * For instance:
 * @code
 * void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
 * @endcode
 *
 * This slot should exclusively redraw the contents of the drawing area
 * and must not call any widget functions that cause changes.
 *
 * @param cr The context to draw to.
 * @param width The actual width of the contents. This value will be at least
 *   as wide as property_content_width().
 * @param height The actual height of the contents. This value will be at least
 *   as high as property_content_height().
 *
 * @newin{3,90}
 */
  using SlotDraw = sigc::slot<void(const Cairo::RefPtr<Cairo::Context>&, int, int)>;


  /** Sets the desired width of the contents of the drawing area.
   *
   * Note that because widgets may be allocated larger sizes than they
   * requested, it is possible that the actual width passed to your draw
   * function is larger than the width set here. You can use
   * Gtk::Widget::set_halign() to avoid that.
   *
   * If the width is set to 0 (the default), the drawing area may disappear.
   *
   * @param width The width of contents.
   */
  void set_content_width(int width);

  /** Retrieves the content width of the `Gtk::DrawingArea`.
   *
   * @return The width requested for content of the drawing area.
   */
  auto get_content_width() const -> int;

  /** Sets the desired height of the contents of the drawing area.
   *
   * Note that because widgets may be allocated larger sizes than they
   * requested, it is possible that the actual height passed to your draw
   * function is larger than the height set here. You can use
   * Gtk::Widget::set_valign() to avoid that.
   *
   * If the height is set to 0 (the default), the drawing area may disappear.
   *
   * @param width The height of contents.
   */
  void set_content_height(int width);

  /** Retrieves the content height of the `Gtk::DrawingArea`.
   *
   * @return The height requested for content of the drawing area.
   */
  auto get_content_height() const -> int;

  /** Sets a draw function.
   *
   * Setting a draw function is the main thing you want to do when using a drawing
   * area. It is called whenever GTK needs to draw the contents of the drawing area
   * to the screen.
   *
   * The draw function will be called during the drawing stage of GTK. In the
   * drawing stage it is not allowed to change properties of any GTK widgets or call
   * any functions that would cause any properties to be changed.
   * You should restrict yourself exclusively to drawing your contents in the draw
   * function.
   *
   * If what you are drawing does change, call Gtk::Widget::queue_draw() on the
   * drawing area. This will call a redraw and will call @a slot again.
   *
   * @newin{3,90}
   *
   * @param slot Callback that lets you draw the drawing area's contents.
   */
  void set_draw_func(const SlotDraw& slot);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%resize(int width, int height)</tt>
   *
   * Flags: Run Last
   *
   * Emitted once when the widget is realized, and then each time the widget
   * is changed while realized.
   *
   * This is useful in order to keep state up to date with the widget size,
   * like for instance a backing surface.
   *
   * @param width The width of the viewport.
   * @param height The height of the viewport.
   */

  auto signal_resize() -> Glib::SignalProxy<void(int, int)>;


  /** The content width.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_width() -> Glib::PropertyProxy< int > ;

/** The content width.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The content height.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_height() -> Glib::PropertyProxy< int > ;

/** The content height.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content_height() const -> Glib::PropertyProxy_ReadOnly< int >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_resize().
  virtual void on_resize(int width, int height);


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
   * @relates Gtk::DrawingArea
   */
  GTKMM_API
  auto wrap(GtkDrawingArea* object, bool take_copy = false) -> Gtk::DrawingArea*;
} //namespace Glib


#endif /* _GTKMM_DRAWINGAREA_H */

