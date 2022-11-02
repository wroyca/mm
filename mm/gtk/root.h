// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_ROOT_H
#define _GTKMM_ROOT_H

#include <mm/gtk/mm-gtkconfig.h>


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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


#include <mm/glib/interface.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkRootInterface GtkRootInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRoot = struct _GtkRoot;
using GtkRootClass = struct _GtkRootClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Root_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API Display;
class GTKMM_API Surface;
}

namespace Gtk
{
class GTKMM_API Widget;

/** Interface for root widgets.
 *
 * %Gtk::Root is the interface implemented by all widgets that can act as a toplevel
 * widget to a hierarchy of widgets. The root widget takes care of providing the
 * connection to the windowing system and manages layout, drawing and event delivery
 * for its widget hierarchy.
 *
 * The obvious example of a %Gtk::Root is Gtk::Window.
 *
 * @see Gtk::Window
 * @newin{3,96}
 */

class GTKMM_API Root : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Root;
  using CppClassType = Root_Class;
  using BaseObjectType = GtkRoot;
  using BaseClassType = GtkRootInterface;

  // noncopyable
  Root(const Root&) = delete;
  auto operator=(const Root&) -> Root& = delete;

private:
  friend class Root_Class;
  static CppClassType root_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Root();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Root(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Root(GtkRoot* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Root(Root&& src) noexcept;
  auto operator=(Root&& src) noexcept -> Root&;

  ~Root() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkRoot*       { return reinterpret_cast<GtkRoot*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkRoot* { return reinterpret_cast<GtkRoot*>(gobject_); }

private:


public:

  /** Returns the display that this `Gtk::Root` is on.
   *
   * @return The display of @a root.
   */
  auto get_display() -> Glib::RefPtr<Gdk::Display>;

  /** Returns the display that this `Gtk::Root` is on.
   *
   * @return The display of @a root.
   */
  auto get_display() const -> Glib::RefPtr<const Gdk::Display>;


  /** If @a focus is not the current focus widget, and is focusable, sets
   * it as the focus widget for the root.
   *
   * To set the focus to a particular widget in the root, it is usually
   * more convenient to use Gtk::Widget::grab_focus() instead of this function.
   *
   * @param focus Widget to be the new focus widget.
   */
  void set_focus(Widget& focus);

  /** Unsets the focus widget for the root.
   */
  void unset_focus();


  /** Retrieves the current focused widget within the root.
   *
   * Note that this is the widget that would have the focus
   * if the root is active; if the root is not focused then
   * `gtk_widget_has_focus (widget)` will be <tt>false</tt> for the
   * widget.
   *
   * @return The currently focused widget.
   */
  auto get_focus() -> Widget*;

  /** Retrieves the current focused widget within the root.
   *
   * Note that this is the widget that would have the focus
   * if the root is active; if the root is not focused then
   * `gtk_widget_has_focus (widget)` will be <tt>false</tt> for the
   * widget.
   *
   * @return The currently focused widget.
   */
  auto get_focus() const -> const Widget*;


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
   * @relates Gtk::Root
   */
  GTKMM_API
  auto wrap(GtkRoot* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Root>;

} // namespace Glib


#endif /* _GTKMM_ROOT_H */
