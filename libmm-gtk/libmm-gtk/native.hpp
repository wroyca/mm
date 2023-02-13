
#ifndef _GTKMM_NATIVE_H
#define _GTKMM_NATIVE_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
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


#include <libmm-glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkNativeInterface GtkNativeInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNative = struct _GtkNative;
using GtkNativeClass = struct _GtkNativeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Native_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API Surface;
}

namespace Gtk
{
class GTKMM_API Widget;

/** Interface for widgets having surfaces.
 *
 * %Gtk::Native is the interface implemented by all widgets that can provide
 * a Gdk::Surface for widgets to render on.
 *
 * The obvious example of a %Gtk::Native is Gtk::Window.
 *
 * @see Gtk::Root, Gtk::Window
 * @newin{3,96}
 */

class GTKMM_API Native : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Native;
  using CppClassType = Native_Class;
  using BaseObjectType = GtkNative;
  using BaseClassType = GtkNativeInterface;

  // noncopyable
  Native(const Native&) = delete;
  auto operator=(const Native&) -> Native& = delete;

private:
  friend class Native_Class;
  static CppClassType native_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Native();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Native(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Native(GtkNative* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Native(Native&& src) noexcept;
  auto operator=(Native&& src) noexcept -> Native&;

  ~Native() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNative*       { return reinterpret_cast<GtkNative*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNative* { return reinterpret_cast<GtkNative*>(gobject_); }

private:


public:

  /** Realizes a `Gtk::Native`.
   *
   * This should only be used by subclasses.
   */
  void realize();

  /** Unrealizes a `Gtk::Native`.
   *
   * This should only be used by subclasses.
   */
  void unrealize();

  /** Finds the `Gtk::Native` associated with the surface.
   *
   * @param surface A `Gdk::Surface`.
   * @return The `Gtk::Native` that is associated with @a surface.
   */
  static auto get_for_surface(const Glib::RefPtr<const Gdk::Surface>& surface) -> Native*;


  /** Returns the surface of this `Gtk::Native`.
   *
   * @return The surface of @a self.
   */
  auto get_surface() -> Glib::RefPtr<Gdk::Surface>;

  /** Returns the surface of this `Gtk::Native`.
   *
   * @return The surface of @a self.
   */
  auto get_surface() const -> Glib::RefPtr<const Gdk::Surface>;

  //?_WRAP_METHOD(GskRenderer* get_renderer(), gtk_native_get_renderer)

  /** Retrieves the surface transform of @a self.
   *
   * This is the translation from @a self's surface coordinates into
   *  @a self's widget coordinates.
   *
   * @param x Return location for the x coordinate.
   * @param y Return location for the y coordinate.
   */
  void get_surface_transform(double& x, double& y);


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
   * @relates Gtk::Native
   */
  GTKMM_API
  auto wrap(GtkNative* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Native>;

} // namespace Glib


#endif /* _GTKMM_NATIVE_H */

