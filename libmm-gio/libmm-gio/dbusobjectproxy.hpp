
#ifndef _GIOMM_DBUSOBJECTPROXY_H
#define _GIOMM_DBUSOBJECTPROXY_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The giomm Development Team
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

#include <mm/glib/object.hpp>
#include <mm/gio/dbusobject.hpp>
#include <mm/gio/dbusconnection.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectProxy = struct _GDBusObjectProxy;
using GDBusObjectProxyClass = struct _GDBusObjectProxyClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API ObjectProxy_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
//The GMMPROC_EXTRA_NAMESPACE() macro is a hint to generate_wrap_init.pl to put it in the DBus sub-namespace


/** Client-side D-Bus object.
 *
 * A %Gio::DBus::ObjectProxy is an object used to represent a remote object
 * with one or more D-Bus interfaces. Normally, you don't instantiate
 * a %Gio::DBus::ObjectProxy yourself - typically Gio::DBus::ObjectManagerClient
 * is used to obtain it.
 *
 * @newin{2,62}
 * @ingroup DBus
 */

class GIOMM_API ObjectProxy : public Glib::Object, public Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ObjectProxy;
  using CppClassType = ObjectProxy_Class;
  using BaseObjectType = GDBusObjectProxy;
  using BaseClassType = GDBusObjectProxyClass;

  // noncopyable
  ObjectProxy(const ObjectProxy&) = delete;
  auto operator=(const ObjectProxy&) -> ObjectProxy& = delete;

private:  friend class ObjectProxy_Class;
  static CppClassType objectproxy_class_;

protected:
  explicit ObjectProxy(const Glib::ConstructParams& construct_params);
  explicit ObjectProxy(GDBusObjectProxy* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ObjectProxy(ObjectProxy&& src) noexcept;
  auto operator=(ObjectProxy&& src) noexcept -> ObjectProxy&;

  ~ObjectProxy() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusObjectProxy*       { return reinterpret_cast<GDBusObjectProxy*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusObjectProxy* { return reinterpret_cast<GDBusObjectProxy*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusObjectProxy*;

private:


protected:
    explicit ObjectProxy(const Glib::RefPtr<Connection>& connection, const Glib::ustring& object_path);


public:
  /** Creates a new %Gio::DBus::ObjectProxy for the given connection and
   * object path.
   *
   * @param connection A %Gio::DBus::Connection.
   * @param object_path The object path.
   * @return A new %Gio::DBus::ObjectProxy.
   */

  static auto create(const Glib::RefPtr<Connection>& connection, const Glib::ustring& object_path) -> Glib::RefPtr<ObjectProxy>;


  /** Gets the connection that @a proxy is for.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection. Do not free, the
   * object is owned by @a proxy.
   */
  auto get_connection() -> Glib::RefPtr<Connection>;

  /** Gets the connection that @a proxy is for.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection. Do not free, the
   * object is owned by @a proxy.
   */
  auto get_connection() const -> Glib::RefPtr<const Connection>;

 /** The connection of the proxy.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >;


 /** The object path of the proxy.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gio::DBus::ObjectProxy
   */
  GIOMM_API
  auto wrap(GDBusObjectProxy* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectProxy>;
}


#endif /* _GIOMM_DBUSOBJECTPROXY_H */

