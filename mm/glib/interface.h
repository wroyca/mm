#ifndef _GLIBMM_INTERFACE_H
#define _GLIBMM_INTERFACE_H

/* Copyright 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/object.h>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class GLIBMM_API Interface_Class;
#endif

// There is no base GInterface struct in Glib, though there is G_TYPE_INTERFACE enum value.
class GLIBMM_API Interface : virtual public Glib::ObjectBase
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Interface;
  using CppClassType = Interface_Class;
  using BaseClassType = GTypeInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** A Default constructor.
   */
  Interface();

  Interface(Interface&& src) noexcept;
  auto operator=(Interface&& src) noexcept -> Interface&;

  /** Called by constructors of derived classes. Provide the result of
   * the Class object's init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Interface(const Glib::Interface_Class& interface_class);

  /** Called by constructors of derived classes.
   *
   * @param castitem A C instance that will be wrapped by the new
   * C++ instance. This does not take a reference, so call reference()
   * if necessary.
   */
  explicit Interface(GObject* castitem);
  ~Interface() noexcept override;

  // noncopyable
  Interface(const Interface&) = delete;
  auto operator=(const Interface&) -> Interface& = delete;

// void add_interface(GType gtype_implementer);

// Hook for translating API
// static Glib::Interface* wrap_new(GTypeInterface*);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_type() -> GType G_GNUC_CONST;
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  inline auto gobj() -> GObject* { return gobject_; }
  inline auto gobj() const -> const GObject* { return gobject_; }
};

auto wrap_interface(GObject* object, bool take_copy = false) -> RefPtr<ObjectBase>;

} // namespace Glib

#endif /* _GLIBMM_INTERFACE_H */
