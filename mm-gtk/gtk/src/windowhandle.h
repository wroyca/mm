// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_WINDOWHANDLE_H
#define _GTKMM_WINDOWHANDLE_H


#include <glibmm/ustring.h>
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

#include <gtkmm/widget.h>


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
  WindowHandle& operator=(WindowHandle&& src) noexcept;

  // noncopyable
  WindowHandle(const WindowHandle&) = delete;
  WindowHandle& operator=(const WindowHandle&) = delete;

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
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkWindowHandle*       gobj()       { return reinterpret_cast<GtkWindowHandle*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkWindowHandle* gobj() const { return reinterpret_cast<GtkWindowHandle*>(gobject_); }

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
  Widget* get_child();
  
  /** Gets the child widget of @a self.
   * 
   * @return The child widget of @a self.
   */
  const Widget* get_child() const;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Widget* > property_child() ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Widget* > property_child() const;


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
  Gtk::WindowHandle* wrap(GtkWindowHandle* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_WINDOWHANDLE_H */

