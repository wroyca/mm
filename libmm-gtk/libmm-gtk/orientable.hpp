
#ifndef _GTKMM_ORIENTABLE_H
#define _GTKMM_ORIENTABLE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 The gtkmm Development Team
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

#include <libmm-glib/interface.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkOrientableIface GtkOrientableIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkOrientable = struct _GtkOrientable;
using GtkOrientableClass = struct _GtkOrientableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Orientable_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** This interface is implemented by all widgets that can be oriented
 * horizontally or vertically. Historically, such widgets have been realized as
 * subclasses of a common base class (e.g GtkBox/GtkHBox/GtkVBox and
 * GtkScale/GtkHScale/GtkVScale). GtkOrientable is more flexible in that it
 * allows the orientation to be changed at runtime, allowing the widgets to 'flip'.
 *
 * @newin{2,16}
 */

class GTKMM_API Orientable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Orientable;
  using CppClassType = Orientable_Class;
  using BaseObjectType = GtkOrientable;
  using BaseClassType = GtkOrientableIface;

  // noncopyable
  Orientable(const Orientable&) = delete;
  auto operator=(const Orientable&) -> Orientable& = delete;

private:
  friend class Orientable_Class;
  static CppClassType orientable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Orientable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Orientable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Orientable(GtkOrientable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Orientable(Orientable&& src) noexcept;
  auto operator=(Orientable&& src) noexcept -> Orientable&;

  ~Orientable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkOrientable*       { return reinterpret_cast<GtkOrientable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkOrientable* { return reinterpret_cast<GtkOrientable*>(gobject_); }

private:


public:

  /** Sets the orientation of the @a orientable.
   *
   * @param orientation The orientable’s new orientation.
   */
  void set_orientation(Orientation orientation);

  /** Retrieves the orientation of the @a orientable.
   *
   * @return The orientation of the @a orientable.
   */
  auto get_orientation() const -> Orientation;

  /** The orientation of the orientable.
   *
   * Default value: Gtk::Orientation::HORIZONTAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_orientation() -> Glib::PropertyProxy< Orientation > ;

/** The orientation of the orientable.
   *
   * Default value: Gtk::Orientation::HORIZONTAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_orientation() const -> Glib::PropertyProxy_ReadOnly< Orientation >;


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
   * @relates Gtk::Orientable
   */
  GTKMM_API
  auto wrap(GtkOrientable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Orientable>;

} // namespace Glib


#endif /* _GTKMM_ORIENTABLE_H */

