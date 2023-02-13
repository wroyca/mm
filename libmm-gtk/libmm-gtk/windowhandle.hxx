
#ifndef _GTKMM_WINDOWHANDLE_H
#define _GTKMM_WINDOWHANDLE_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API WindowHandle_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A titlebar area widget.
 *
 * %Gtk::WindowHandle is a titlebar area widget. When added into a window, it can
 * be dragged to move the window, and handles right click, double click and
 * middle click as expected of a titlebar.
 *
 * @see Gtk::Window, Gtk::HeaderBar
 *
 * @ingroup Containers
 * @newin{3,98}
 */

class GTKMM_API WindowHandle : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef WindowHandle CppObjectType;
  typedef WindowHandle_Class CppClassType;
  typedef GtkWindowHandle BaseObjectType;
  typedef GtkWindowHandleClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  WindowHandle(WindowHandle&& src) noexcept;
  auto operator=(WindowHandle&& src) noexcept -> WindowHandle&;

  // noncopyable
  WindowHandle(const WindowHandle&) = delete;
  auto operator=(const WindowHandle&) -> WindowHandle& = delete;

  ~WindowHandle() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class WindowHandle_Class;
  static CppClassType windowhandle_class_;

protected:
  explicit WindowHandle(const Glib::ConstructParams& construct_params);
  explicit WindowHandle(GtkWindowHandle* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkWindowHandle*       { return reinterpret_cast<GtkWindowHandle*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWindowHandle* { return reinterpret_cast<GtkWindowHandle*>(gobject_); }

private:


public:
  /** Create a new %WindowHandle widget.
   */
  WindowHandle();


  /** Sets the child widget of @a self.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a self.
   *
   * @return The child widget of @a self.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a self.
   *
   * @return The child widget of @a self.
   */
  auto get_child() const -> const Widget*;

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


  // Gtk::WindowHandle has no signals nor vfuncs.


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
   * @relates Gtk::WindowHandle
   */
  GTKMM_API
  auto wrap(GtkWindowHandle* object, bool take_copy = false) -> Gtk::WindowHandle*;
} //namespace Glib


#endif /* _GTKMM_WINDOWHANDLE_H */

