
#ifndef _GIOMM_MENULINKITER_H
#define _GIOMM_MENULINKITER_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuLinkIter = struct _GMenuLinkIter;
using GMenuLinkIterClass = struct _GMenuLinkIterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API MenuLinkIter_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API MenuModel;

/** MenuLinkIter - A menu link iterator.
 * @newin{2,32}
 */

class GIOMM_API MenuLinkIter : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MenuLinkIter;
  using CppClassType = MenuLinkIter_Class;
  using BaseObjectType = GMenuLinkIter;
  using BaseClassType = GMenuLinkIterClass;

  // noncopyable
  MenuLinkIter(const MenuLinkIter&) = delete;
  auto operator=(const MenuLinkIter&) -> MenuLinkIter& = delete;

private:  friend class MenuLinkIter_Class;
  static CppClassType menulinkiter_class_;

protected:
  explicit MenuLinkIter(const Glib::ConstructParams& construct_params);
  explicit MenuLinkIter(GMenuLinkIter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MenuLinkIter(MenuLinkIter&& src) noexcept;
  auto operator=(MenuLinkIter&& src) noexcept -> MenuLinkIter&;

  ~MenuLinkIter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GMenuLinkIter*       { return reinterpret_cast<GMenuLinkIter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GMenuLinkIter* { return reinterpret_cast<GMenuLinkIter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GMenuLinkIter*;

private:


protected:
  MenuLinkIter();

public:

  /** Gets the name of the link at the current iterator position.
   *
   * The iterator is not advanced.
   *
   * @newin{2,32}
   *
   * @return The type of the link.
   */
  auto get_name() const -> Glib::ustring;


  /** This function combines g_menu_link_iter_next() with
   * g_menu_link_iter_get_name() and g_menu_link_iter_get_value().
   *
   * First the iterator is advanced to the next (possibly first) link.
   * If that fails, then <tt>false</tt> is returned and there are no other effects.
   *
   * If successful, @a out_link and @a value are set to the name and MenuModel
   * of the link that has just been advanced to.  At this point,
   * g_menu_link_iter_get_name() and g_menu_link_iter_get_value() will return the
   * same values again.
   *
   * The value returned in @a out_link remains valid for as long as the iterator
   * remains at the current position.  The value returned in @a value must
   * be unreffed using Glib::object_unref() when it is no longer in use.
   *
   * @newin{2,32}
   *
   * @param out_link The name of the link.
   * @param value The linked MenuModel.
   * @return <tt>true</tt> on success, or <tt>false</tt> if there is no additional link.
   */

  auto get_next(Glib::ustring& out_link, Glib::RefPtr<MenuModel>& value) -> bool;


  /** Gets the linked MenuModel at the current iterator position.
   *
   * The iterator is not advanced.
   *
   * @newin{2,32}
   *
   * @return The MenuModel that is linked to.
   */
  auto get_value() -> Glib::RefPtr<MenuModel>;

  /** Gets the linked MenuModel at the current iterator position.
   *
   * The iterator is not advanced.
   *
   * @newin{2,32}
   *
   * @return The MenuModel that is linked to.
   */
  auto get_value() const -> Glib::RefPtr<const MenuModel>;


  /** Attempts to advance the iterator to the next (possibly first)
   * link.
   *
   * <tt>true</tt> is returned on success, or <tt>false</tt> if there are no more links.
   *
   * You must call this function when you first acquire the iterator to
   * advance it to the first link (and determine if the first link exists
   * at all).
   *
   * @newin{2,32}
   *
   * @return <tt>true</tt> on success, or <tt>false</tt> when there are no more links.
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
   * @relates Gio::MenuLinkIter
   */
  GIOMM_API
  auto wrap(GMenuLinkIter* object, bool take_copy = false) -> Glib::RefPtr<Gio::MenuLinkIter>;
}


#endif /* _GIOMM_MENULINKITER_H */
