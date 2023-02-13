
#ifndef _GIOMM_MENUATTRIBUTEITER_H
#define _GIOMM_MENUATTRIBUTEITER_H

#include <libmm-gio/gioconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#include <libmm-glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuAttributeIter = struct _GMenuAttributeIter;
using GMenuAttributeIterClass = struct _GMenuAttributeIterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API MenuAttributeIter_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** MenuAttributeIter - A menu attribute iterator.
 * @newin{2,32}
 */

class GIOMM_API MenuAttributeIter : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MenuAttributeIter;
  using CppClassType = MenuAttributeIter_Class;
  using BaseObjectType = GMenuAttributeIter;
  using BaseClassType = GMenuAttributeIterClass;

  // noncopyable
  MenuAttributeIter(const MenuAttributeIter&) = delete;
  auto operator=(const MenuAttributeIter&) -> MenuAttributeIter& = delete;

private:  friend class MenuAttributeIter_Class;
  static CppClassType menuattributeiter_class_;

protected:
  explicit MenuAttributeIter(const Glib::ConstructParams& construct_params);
  explicit MenuAttributeIter(GMenuAttributeIter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MenuAttributeIter(MenuAttributeIter&& src) noexcept;
  auto operator=(MenuAttributeIter&& src) noexcept -> MenuAttributeIter&;

  ~MenuAttributeIter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMenuAttributeIter*       { return reinterpret_cast<GMenuAttributeIter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMenuAttributeIter* { return reinterpret_cast<GMenuAttributeIter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GMenuAttributeIter*;

private:


protected:
  MenuAttributeIter();

public:

  /** This function combines g_menu_attribute_iter_next() with
   * g_menu_attribute_iter_get_name() and g_menu_attribute_iter_get_value().
   *
   * First the iterator is advanced to the next (possibly first) attribute.
   * If that fails, then <tt>false</tt> is returned and there are no other
   * effects.
   *
   * If successful, @a name and @a value are set to the name and value of the
   * attribute that has just been advanced to.  At this point,
   * g_menu_attribute_iter_get_name() and g_menu_attribute_iter_get_value() will
   * return the same values again.
   *
   * The value returned in @a name remains valid for as long as the iterator
   * remains at the current position.  The value returned in @a value must
   * be unreffed using Glib::variant_unref() when it is no longer in use.
   *
   * @newin{2,32}
   *
   * @param out_name The type of the attribute.
   * @param value The attribute value.
   * @return <tt>true</tt> on success, or <tt>false</tt> if there is no additional
   * attribute.
   */

  auto get_next(Glib::ustring& out_name, Glib::VariantBase& value) -> bool;


  /** Gets the name of the attribute at the current iterator position, as
   * a string.
   *
   * The iterator is not advanced.
   *
   * @newin{2,32}
   *
   * @return The name of the attribute.
   */
  auto get_name() const -> Glib::ustring;


  /** Gets the value of the attribute at the current iterator position.
   *
   * The iterator is not advanced.
   *
   * @newin{2,32}
   *
   * @return The value of the current attribute.
   */
  auto get_value() const -> Glib::VariantBase;


  /** Attempts to advance the iterator to the next (possibly first)
   * attribute.
   *
   * <tt>true</tt> is returned on success, or <tt>false</tt> if there are no more
   * attributes.
   *
   * You must call this function when you first acquire the iterator
   * to advance it to the first attribute (and determine if the first
   * attribute exists at all).
   *
   * @newin{2,32}
   *
   * @return <tt>true</tt> on success, or <tt>false</tt> when there are no more attributes.
   */
  auto next() -> bool;


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
   * @relates Gio::MenuAttributeIter
   */
  GIOMM_API
  auto wrap(GMenuAttributeIter* object, bool take_copy = false) -> Glib::RefPtr<Gio::MenuAttributeIter>;
}


#endif /* _GIOMM_MENUATTRIBUTEITER_H */

