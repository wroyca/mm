
#ifndef _GIOMM_DBUSMENUMODEL_H
#define _GIOMM_DBUSMENUMODEL_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gio/menumodel.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMenuModel = struct _GDBusMenuModel;
using GDBusMenuModelClass = struct _GDBusMenuModelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API MenuModel_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{

class GIOMM_API Connection;


/** MenuModel - A D-Bus Gio::MenuModel implementation.
 * MenuModel is an implementation of Gio::MenuModel that can be used as a proxy
 * for a menu model that is exported over D-Bus with
 * Gio::DBus::Connection::export_menu_model().
 * @newin{2,32}
 */

class GIOMM_API MenuModel : public ::Gio::MenuModel
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MenuModel;
  using CppClassType = MenuModel_Class;
  using BaseObjectType = GDBusMenuModel;
  using BaseClassType = GDBusMenuModelClass;

  // noncopyable
  MenuModel(const MenuModel&) = delete;
  auto operator=(const MenuModel&) -> MenuModel& = delete;

private:  friend class MenuModel_Class;
  static CppClassType menumodel_class_;

protected:
  explicit MenuModel(const Glib::ConstructParams& construct_params);
  explicit MenuModel(GDBusMenuModel* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MenuModel(MenuModel&& src) noexcept;
  auto operator=(MenuModel&& src) noexcept -> MenuModel&;

  ~MenuModel() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusMenuModel*       { return reinterpret_cast<GDBusMenuModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusMenuModel* { return reinterpret_cast<GDBusMenuModel*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusMenuModel*;

private:


protected:
  MenuModel();

public:


  /** Obtains a DBusMenuModel for the menu model which is exported
   * at the given @a bus_name and @a object_path.
   *
   * The thread default main context is taken at the time of this call.
   * All signals on the menu model (and any linked models) are reported
   * with respect to this context.  All calls on the returned menu model
   * (and linked models) must also originate from this same context, with
   * the thread default main context unchanged.
   *
   * @newin{2,32}
   *
   * @param connection A Gio::DBus::Connection.
   * @param bus_name The bus name which exports the menu model
   * or <tt>nullptr</tt> if @a connection is not a message bus connection.
   * @param object_path The object path at which the menu model is exported.
   * @return A DBusMenuModel object. Free with
   * Glib::object_unref().
   */
  static auto get(const Glib::RefPtr<Connection>& connection, const Glib::ustring& bus_name, const Glib::ustring& object_path) -> Glib::RefPtr<MenuModel>;


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
   * @relates Gio::DBus::MenuModel
   */
  GIOMM_API
  auto wrap(GDBusMenuModel* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::MenuModel>;
}


#endif /* _GIOMM_DBUSMENUMODEL_H */

