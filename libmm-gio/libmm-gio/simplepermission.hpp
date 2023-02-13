
#ifndef _GIOMM_SIMPLEPERMISSION_H
#define _GIOMM_SIMPLEPERMISSION_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The giomm Development Team
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

#include <mm/gio/permission.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimplePermission = struct _GSimplePermission;
using GSimplePermissionClass = struct _GSimplePermissionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SimplePermission_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A Permission that doesn't change value.
 *
 * SimplePermission is a trivial implementation of Permission that
 * represents a permission that is either always or never allowed.  The
 * value is given at construction and doesn't change.
 *
 * Calling Permission::acquire() or Permission::release() will result
 * in errors.
 */

class GIOMM_API SimplePermission : public Permission
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SimplePermission;
  using CppClassType = SimplePermission_Class;
  using BaseObjectType = GSimplePermission;
  using BaseClassType = GSimplePermissionClass;

  // noncopyable
  SimplePermission(const SimplePermission&) = delete;
  auto operator=(const SimplePermission&) -> SimplePermission& = delete;

private:  friend class SimplePermission_Class;
  static CppClassType simplepermission_class_;

protected:
  explicit SimplePermission(const Glib::ConstructParams& construct_params);
  explicit SimplePermission(GSimplePermission* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SimplePermission(SimplePermission&& src) noexcept;
  auto operator=(SimplePermission&& src) noexcept -> SimplePermission&;

  ~SimplePermission() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSimplePermission*       { return reinterpret_cast<GSimplePermission*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSimplePermission* { return reinterpret_cast<GSimplePermission*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSimplePermission*;

private:


protected:

    explicit SimplePermission(bool allowed);


public:


  static auto create(bool allowed) -> Glib::RefPtr<SimplePermission>;


  // SimplePermission has no properties nor signals.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::SimplePermission
   */
  GIOMM_API
  auto wrap(GSimplePermission* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimplePermission>;
}


#endif /* _GIOMM_SIMPLEPERMISSION_H */

