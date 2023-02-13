
#ifndef _GTKMM_BUILDERCSCOPE_H
#define _GTKMM_BUILDERCSCOPE_H


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

#include <mm/glib/object.hpp>
#include <mm/gtk/builderscope.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilderCScope = struct _GtkBuilderCScope;
using GtkBuilderCScopeClass = struct _GtkBuilderCScopeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API BuilderCScope_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/** Bindings for Gtk::Builder.
 *
 * gtkmm applications probably don't need this class.
 *
 * %Gtk::BuilderCScope provides support to Gtk::Builder, primarily
 * for looking up programming-language-specific values for strings that are
 * given in a Gtk::Builder UI file.
 *
 * @see Gtk::Builder
 * @newin{3,98}
 */

class GTKMM_API BuilderCScope : public Glib::Object, public BuilderScope
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BuilderCScope;
  using CppClassType = BuilderCScope_Class;
  using BaseObjectType = GtkBuilderCScope;
  using BaseClassType = GtkBuilderCScopeClass;

  // noncopyable
  BuilderCScope(const BuilderCScope&) = delete;
  auto operator=(const BuilderCScope&) -> BuilderCScope& = delete;

private:  friend class BuilderCScope_Class;
  static CppClassType buildercscope_class_;

protected:
  explicit BuilderCScope(const Glib::ConstructParams& construct_params);
  explicit BuilderCScope(GtkBuilderCScope* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BuilderCScope(BuilderCScope&& src) noexcept;
  auto operator=(BuilderCScope&& src) noexcept -> BuilderCScope&;

  ~BuilderCScope() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBuilderCScope*       { return reinterpret_cast<GtkBuilderCScope*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBuilderCScope* { return reinterpret_cast<GtkBuilderCScope*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkBuilderCScope*;

private:


protected:
  BuilderCScope();

public:

  static auto create() -> Glib::RefPtr<BuilderCScope>;


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
   * @relates Gtk::BuilderCScope
   */
  GTKMM_API
  auto wrap(GtkBuilderCScope* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BuilderCScope>;
}


#endif /* _GTKMM_BUILDERCSCOPE_H */

