
#ifndef _GTKMM_DRAGICON_H
#define _GTKMM_DRAGICON_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/native.hpp>
#include <mm/gtk/root.hpp>
#include <mm/gdk/drag.hpp>
#include <mm/gdk/paintable.hpp>
#include <mm/glib/value.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API DragIcon_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A toplevel to use as drag icon.
 *
 * %Gtk::DragIcon is a Gtk::Root implementation with the sole purpose
 * to serve as a drag icon during DND operations. A drag icon moves
 * with the pointer during a drag operation and is destroyed when
 * the drag ends.
 *
 * To set up a drag icon and associate it with an ongoing drag operation,
 * use get_for_drag() to get the icon for a drag. You can
 * then use it like any other widget and use set_child() to
 * set whatever widget should be used for the drag icon.
 *
 * Keep in mind that drag icons do not allow user input.
 *
 * @ingroup Widgets
 * @newin{3,98}
 */

class GTKMM_API DragIcon : public Widget, public Native, public Root
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef DragIcon CppObjectType;
  typedef DragIcon_Class CppClassType;
  typedef GtkDragIcon BaseObjectType;
  typedef GtkDragIconClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  DragIcon(DragIcon&& src) noexcept;
  auto operator=(DragIcon&& src) noexcept -> DragIcon&;

  // noncopyable
  DragIcon(const DragIcon&) = delete;
  auto operator=(const DragIcon&) -> DragIcon& = delete;

  ~DragIcon() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class DragIcon_Class;
  static CppClassType dragicon_class_;

protected:
  explicit DragIcon(const Glib::ConstructParams& construct_params);
  explicit DragIcon(GtkDragIcon* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkDragIcon*       { return reinterpret_cast<GtkDragIcon*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkDragIcon* { return reinterpret_cast<GtkDragIcon*>(gobject_); }

private:


public:

  /** Gets the `Gtk::DragIcon` in use with @a drag.
   *
   * If no drag icon exists yet, a new one will be created
   * and shown.
   *
   * @param drag A `Gdk::Drag`.
   * @return The `Gtk::DragIcon`.
   */
  static auto get_for_drag(const Glib::RefPtr<Gdk::Drag>& drag) -> DragIcon*;


  /** Sets the widget to display as the drag icon.
   *
   * @param child A `Gtk::Widget`.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the widget currently used as drag icon.
   *
   * @return The drag icon.
   */
  auto get_child() -> Widget*;

  /** Gets the widget currently used as drag icon.
   *
   * @return The drag icon.
   */
  auto get_child() const -> const Widget*;


  /** Creates a `Gtk::DragIcon` that shows @a paintable, and associates
   * it with the drag operation.
   *
   * The hotspot position on the paintable is aligned with the
   * hotspot of the cursor.
   *
   * @param drag A `Gdk::Drag`.
   * @param paintable A `Gdk::Paintable` to display.
   * @param hot_x X coordinate of the hotspot.
   * @param hot_y Y coordinate of the hotspot.
   */
  static void set_from_paintable(const Glib::RefPtr<Gdk::Drag>& drag, const Glib::RefPtr<Gdk::Paintable>& paintable, int hot_x, int hot_y);


  /** Creates a widget that can be used as a drag icon for the given
   *  @a value.
   *
   * Supported types include strings, `GdkRGBA` and `Gtk::TextBuffer`.
   * If GTK does not know how to create a widget for a given value,
   * it will return <tt>nullptr</tt>.
   *
   * This method is used to set the default drag icon on drag-and-drop
   * operations started by `Gtk::DragSource`, so you don't need to set
   * a drag icon using this function there.
   *
   * @param value A `Glib::Value`.
   * @return A new `Gtk::Widget`
   * for displaying @a value as a drag icon.
   */
  static auto create_widget_for_value(const Glib::ValueBase& value) -> Widget*;

  /** The widget to display as drag icon.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The widget to display as drag icon.
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
   * @relates Gtk::DragIcon
   */
  GTKMM_API
  auto wrap(GtkDragIcon* object, bool take_copy = false) -> Gtk::DragIcon*;
} //namespace Glib


#endif /* _GTKMM_DRAGICON_H */

