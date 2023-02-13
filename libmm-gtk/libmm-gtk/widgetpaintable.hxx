
#ifndef _GTKMM_WIDGETPAINTABLE_H
#define _GTKMM_WIDGETPAINTABLE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

#include <libmm-glib/object.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API WidgetPaintable_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Drawing a widget elsewhere.
 *
 * %Gtk::WidgetPaintable is an implementation of the Gdk::Paintable interface
 * that allows displaying the contents of a Gtk::Widget.
 *
 * %WidgetPaintable will also take care of the widget not being in a
 * state where it can be drawn (like when it isn't shown) and just draw
 * nothing or where it does not have a size (like when it is hidden) and
 * report no size in that case.
 *
 * Of course, %WidgetPaintable allows you to monitor widgets for size
 * changes by emitting Gdk::Paintable::signal_invalidate_size() whenever
 * the size of the widget changes as well as for visual changes by
 * emitting Gdk::Paintable::signal_invalidate_contents() whenever the
 * widget changes.
 *
 * You can of course use a %Gtk::WidgetPaintable everywhere a
 * Gdk::Paintable is allowed, including using it on a Gtk::Picture (or one
 * of its parents) that it was set on itself via Gtk::Picture::set_paintable().
 * The paintable will take care of recursion when this happens. If you do
 * this however, ensure Gtk::Picture::property_can_shrink() is set to
 * <tt>true</tt> or you might end up with an infinitely growing widget.
 *
 * @newin{3,94}
 */

class GTKMM_API WidgetPaintable : public Glib::Object, public Gdk::Paintable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = WidgetPaintable;
  using CppClassType = WidgetPaintable_Class;
  using BaseObjectType = GtkWidgetPaintable;
  using BaseClassType = GtkWidgetPaintableClass;

  // noncopyable
  WidgetPaintable(const WidgetPaintable&) = delete;
  auto operator=(const WidgetPaintable&) -> WidgetPaintable& = delete;

private:  friend class WidgetPaintable_Class;
  static CppClassType widgetpaintable_class_;

protected:
  explicit WidgetPaintable(const Glib::ConstructParams& construct_params);
  explicit WidgetPaintable(GtkWidgetPaintable* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  WidgetPaintable(WidgetPaintable&& src) noexcept;
  auto operator=(WidgetPaintable&& src) noexcept -> WidgetPaintable&;

  ~WidgetPaintable() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkWidgetPaintable*       { return reinterpret_cast<GtkWidgetPaintable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWidgetPaintable* { return reinterpret_cast<GtkWidgetPaintable*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkWidgetPaintable*;

private:


protected:
  WidgetPaintable();
    explicit WidgetPaintable(Widget& widget);


public:

  static auto create() -> Glib::RefPtr<WidgetPaintable>;


  static auto create(Widget& widget) -> Glib::RefPtr<WidgetPaintable>;


  /** Returns the widget that is observed or <tt>nullptr</tt> if none.
   *
   * @return The observed widget.
   */
  auto get_widget() -> Widget*;

  /** Returns the widget that is observed or <tt>nullptr</tt> if none.
   *
   * @return The observed widget.
   */
  auto get_widget() const -> const Widget*;

  /** Sets the widget that should be observed.
   *
   * @param widget The widget to observe.
   */
  void set_widget(Widget& widget);
  void unset_widget();

  /** The observed widget or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_widget() -> Glib::PropertyProxy< Widget* > ;

/** The observed widget or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


  // There are no public signals or vfuncs.


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
   * @relates Gtk::WidgetPaintable
   */
  GTKMM_API
  auto wrap(GtkWidgetPaintable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::WidgetPaintable>;
}


#endif /* _GTKMM_WIDGETPAINTABLE_H */

