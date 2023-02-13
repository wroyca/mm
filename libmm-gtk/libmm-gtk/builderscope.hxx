
#ifndef _GTKMM_BUILDERSCOPE_H
#define _GTKMM_BUILDERSCOPE_H

#include <libmm-gtk/mm-gtkconfig.hxx>


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


#include <libmm-glib/interface.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkBuilderScopeInterface GtkBuilderScopeInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilderScope = struct _GtkBuilderScope;
using GtkBuilderScopeClass = struct _GtkBuilderScopeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API BuilderScope_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/** Bindings for Gtk::Builder.
 *
 * gtkmm applications probably don't need this interface.
 *
 * %Gtk::BuilderScope is an interface to provide support to Gtk::Builder, primarily
 * for looking up programming-language-specific values for strings that are
 * given in a Gtk::Builder UI file.
 *
 * @see Gtk::Builder
 * @newin{3,98}
 */

class GTKMM_API BuilderScope : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BuilderScope;
  using CppClassType = BuilderScope_Class;
  using BaseObjectType = GtkBuilderScope;
  using BaseClassType = GtkBuilderScopeInterface;

  // noncopyable
  BuilderScope(const BuilderScope&) = delete;
  auto operator=(const BuilderScope&) -> BuilderScope& = delete;

private:
  friend class BuilderScope_Class;
  static CppClassType builderscope_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  BuilderScope();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit BuilderScope(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit BuilderScope(GtkBuilderScope* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BuilderScope(BuilderScope&& src) noexcept;
  auto operator=(BuilderScope&& src) noexcept -> BuilderScope&;

  ~BuilderScope() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBuilderScope*       { return reinterpret_cast<GtkBuilderScope*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBuilderScope* { return reinterpret_cast<GtkBuilderScope*>(gobject_); }

private:


protected:


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::BuilderScope
   */
  GTKMM_API
  auto wrap(GtkBuilderScope* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BuilderScope>;

} // namespace Glib


#endif /* _GTKMM_BUILDERSCOPE_H */

