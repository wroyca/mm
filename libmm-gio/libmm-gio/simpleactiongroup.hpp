
#ifndef _GIOMM_SIMPLEACTIONGROUP_H
#define _GIOMM_SIMPLEACTIONGROUP_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The giomm Development Team
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


#include <mm/gio/actionmap.hpp>
#include <mm/gio/actiongroup.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimpleActionGroup = struct _GSimpleActionGroup;
using GSimpleActionGroupClass = struct _GSimpleActionGroupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SimpleActionGroup_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API Action;

/** SimpleActionGroup - A simple ActionGroup implementation.
 * SimpleActionGroup is a hash table filled with Action objects, implementing
 * the ActionGroup interface.
 *
 * @newin{2,32}
 */

class GIOMM_API SimpleActionGroup : public Glib::Object,
                                    public ActionGroup,
                                    public ActionMap
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SimpleActionGroup;
  using CppClassType = SimpleActionGroup_Class;
  using BaseObjectType = GSimpleActionGroup;
  using BaseClassType = GSimpleActionGroupClass;

  // noncopyable
  SimpleActionGroup(const SimpleActionGroup&) = delete;
  auto operator=(const SimpleActionGroup&) -> SimpleActionGroup& = delete;

private:  friend class SimpleActionGroup_Class;
  static CppClassType simpleactiongroup_class_;

protected:
  explicit SimpleActionGroup(const Glib::ConstructParams& construct_params);
  explicit SimpleActionGroup(GSimpleActionGroup* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SimpleActionGroup(SimpleActionGroup&& src) noexcept;
  auto operator=(SimpleActionGroup&& src) noexcept -> SimpleActionGroup&;

  ~SimpleActionGroup() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSimpleActionGroup*       { return reinterpret_cast<GSimpleActionGroup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSimpleActionGroup* { return reinterpret_cast<GSimpleActionGroup*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSimpleActionGroup*;

private:


protected:
  SimpleActionGroup();

public:

  /** Creates a new, empty, SimpleActionGroup.
   *
   * @newin{2,28}
   *
   * @return A new SimpleActionGroup.
   */


  static auto create() -> Glib::RefPtr<SimpleActionGroup>;


   // deprecated


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
   * @relates Gio::SimpleActionGroup
   */
  GIOMM_API
  auto wrap(GSimpleActionGroup* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimpleActionGroup>;
}


#endif /* _GIOMM_SIMPLEACTIONGROUP_H */

