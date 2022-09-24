// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_VIEWPORT_H
#define _GTKMM_VIEWPORT_H


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2002 The gtkmm Development Team
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

#include <mm/gtk/widget.h>
#include <mm/gtk/scrollable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkViewport = struct _GtkViewport;
using GtkViewportClass = struct _GtkViewportClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Viewport_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk {

/** An adapter which makes widgets scrollable.
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Viewport
 : public Widget,
   public Scrollable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Viewport CppObjectType;
  typedef Viewport_Class CppClassType;
  typedef GtkViewport BaseObjectType;
  typedef GtkViewportClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Viewport(Viewport&& src) noexcept;
  auto operator=(Viewport&& src) noexcept -> Viewport&;

  // noncopyable
  Viewport(const Viewport&) = delete;
  auto operator=(const Viewport&) -> Viewport& = delete;

  ~Viewport() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Viewport_Class;
  static CppClassType viewport_class_;

protected:
  explicit Viewport(const Glib::ConstructParams& construct_params);
  explicit Viewport(GtkViewport* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkViewport*       { return reinterpret_cast<GtkViewport*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkViewport* { return reinterpret_cast<GtkViewport*>(gobject_); }

private:


public:

    explicit Viewport(const Glib::RefPtr<Adjustment>& hadjustment, const Glib::RefPtr<Adjustment>& vadjustment);


  /** Sets whether the viewport should automatically scroll
   * to keep the focused child in view.
   *
   * @param scroll_to_focus Whether to keep the focus widget scrolled to view.
   */
  void set_scroll_to_focus(bool scroll_to_focus =  true);

  /** Gets whether the viewport is scrolling to keep the focused
   * child in view.
   *
   * @return <tt>true</tt> if the viewport keeps the focus child scrolled to view.
   */
  auto get_scroll_to_focus() const -> bool;


  /** Sets the child widget of @a viewport.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a viewport.
   *
   * @return The child widget of @a viewport.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a viewport.
   *
   * @return The child widget of @a viewport.
   */
  auto get_child() const -> const Widget*;

  /** Whether to scroll when the focus changes.
   *
   * Before 4.6.2, this property was mistakenly defaulting to <tt>false</tt>, so if your
   * code needs to work with older versions, consider setting it explicitly to
   * <tt>true</tt>.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scroll_to_focus() -> Glib::PropertyProxy< bool > ;

/** Whether to scroll when the focus changes.
   *
   * Before 4.6.2, this property was mistakenly defaulting to <tt>false</tt>, so if your
   * code needs to work with older versions, consider setting it explicitly to
   * <tt>true</tt>.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_scroll_to_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;

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

}  //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Viewport
   */
  GTKMM_API
  auto wrap(GtkViewport* object, bool take_copy = false) -> Gtk::Viewport*;
} //namespace Glib


#endif /* _GTKMM_VIEWPORT_H */

