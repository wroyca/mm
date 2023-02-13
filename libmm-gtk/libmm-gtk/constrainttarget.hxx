
#ifndef _GTKMM_CONSTRAINTTARGET_H
#define _GTKMM_CONSTRAINTTARGET_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/interface.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkConstraintTargetInterface GtkConstraintTargetInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkConstraintTarget = struct _GtkConstraintTarget;
using GtkConstraintTargetClass = struct _GtkConstraintTargetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ConstraintTarget_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Helper interface for Gtk::Constraint.
 *
 * The %ConstraintTarget interface is implemented by objects that
 * can be used as source or target in Gtk::Constraints. Besides
 * Gtk::Widget, it is also implemented by Gtk::ConstraintGuide.
 *
 * @newin{3,96}
 */

class GTKMM_API ConstraintTarget : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ConstraintTarget;
  using CppClassType = ConstraintTarget_Class;
  using BaseObjectType = GtkConstraintTarget;
  using BaseClassType = GtkConstraintTargetInterface;

  // noncopyable
  ConstraintTarget(const ConstraintTarget&) = delete;
  auto operator=(const ConstraintTarget&) -> ConstraintTarget& = delete;

private:
  friend class ConstraintTarget_Class;
  static CppClassType constrainttarget_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ConstraintTarget();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ConstraintTarget(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ConstraintTarget(GtkConstraintTarget* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ConstraintTarget(ConstraintTarget&& src) noexcept;
  auto operator=(ConstraintTarget&& src) noexcept -> ConstraintTarget&;

  ~ConstraintTarget() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkConstraintTarget*       { return reinterpret_cast<GtkConstraintTarget*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkConstraintTarget* { return reinterpret_cast<GtkConstraintTarget*>(gobject_); }

private:


public:
  // Nothing!


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
   * @relates Gtk::ConstraintTarget
   */
  GTKMM_API
  auto wrap(GtkConstraintTarget* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintTarget>;

} // namespace Glib


#endif /* _GTKMM_CONSTRAINTTARGET_H */

