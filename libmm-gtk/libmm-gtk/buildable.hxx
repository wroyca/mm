
#ifndef _GTKMM_BUILDABLE_H
#define _GTKMM_BUILDABLE_H

#include <libmm-gtk/mm-gtkconfig.hpp>


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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkBuildableIface GtkBuildableIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuildable = struct _GtkBuildable;
using GtkBuildableClass = struct _GtkBuildableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Buildable_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A base class for objects that can be built by Gtk::Builder.
 *
 * Buildable allows objects to extend and customize thier deserialization from Gtk::Builder UI descriptions.
 * The interface includes methods for setting names and properties of objects, parsing custom tags and constructing child objects.
 *
 * All gtkmm widgets, and many non-widget objects, derive from this base class.
 * The main user of this interface is Gtk::Builder. There should be very little need for applications to call any of Buildable's methods.
 *
 * @newin{3,0}
 */

class GTKMM_API Buildable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Buildable;
  using CppClassType = Buildable_Class;
  using BaseObjectType = GtkBuildable;
  using BaseClassType = GtkBuildableIface;

  // noncopyable
  Buildable(const Buildable&) = delete;
  auto operator=(const Buildable&) -> Buildable& = delete;

private:
  friend class Buildable_Class;
  static CppClassType buildable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Buildable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Buildable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Buildable(GtkBuildable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Buildable(Buildable&& src) noexcept;
  auto operator=(Buildable&& src) noexcept -> Buildable&;

  ~Buildable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBuildable*       { return reinterpret_cast<GtkBuildable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBuildable* { return reinterpret_cast<GtkBuildable*>(gobject_); }

private:


public:

  /** Gets the ID of the @a buildable object.
   *
   * `Gtk::Builder` sets the name based on the ID attribute
   * of the <object> tag used to construct the @a buildable.
   *
   * @return The ID of the buildable object.
   */
  auto get_buildable_id() const -> Glib::ustring;

  //TODO: Properties, signals, vfuncs.


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
   * @relates Gtk::Buildable
   */
  GTKMM_API
  auto wrap(GtkBuildable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Buildable>;

} // namespace Glib


#endif /* _GTKMM_BUILDABLE_H */

