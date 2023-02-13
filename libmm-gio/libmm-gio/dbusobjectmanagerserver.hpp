
#ifndef _GIOMM_DBUSOBJECTMANAGERSERVER_H
#define _GIOMM_DBUSOBJECTMANAGERSERVER_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/dbusobjectmanager.hpp>
#include <libmm-gio/dbusconnection.hpp>
#include <libmm-gio/dbusobjectskeleton.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerServer = struct _GDBusObjectManagerServer;
using GDBusObjectManagerServerClass = struct _GDBusObjectManagerServerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API ObjectManagerServer_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
//The GMMPROC_EXTRA_NAMESPACE() macro is a hint to generate_wrap_init.pl to put it in the DBus sub-namespace


/** Service-side object manager.
 *
 * %Gio::DBus::ObjectManagerServer is used to export Gio::DBus::Object instances using
 * the standardized
 * <a href="http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-objectmanager">
 * org.freedesktop.DBus.ObjectManager</a> interface.
 * For example, remote D-Bus clients can get all objects
 * and properties in a single call. Additionally, any change in the
 * object hierarchy is broadcast using signals. This means that D-Bus
 * clients can keep caches up to date by only listening to D-Bus signals.
 *
 * The recommended path to export an object manager at is the path form of the
 * well-known name of a D-Bus service, or below. For example, if a D-Bus service
 * is available at the well-known name `net.example.ExampleService1`, the object
 * manager should typically be exported at `/net/example/ExampleService1`, or
 * below (to allow for multiple object managers in a service).
 *
 * It is supported, but not recommended, to export an object manager at the root
 * path, `/`.
 *
 * See Gio::DBus::ObjectManagerClient for the client-side code that is
 * intended to be used with %ObjectManagerServer or any D-Bus
 * object implementing the org.freedesktop.DBus.ObjectManager interface.
 *
 * @newin{2,62}
 * @ingroup DBus
 */

class GIOMM_API ObjectManagerServer : public Glib::Object, public ObjectManager
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ObjectManagerServer;
  using CppClassType = ObjectManagerServer_Class;
  using BaseObjectType = GDBusObjectManagerServer;
  using BaseClassType = GDBusObjectManagerServerClass;

  // noncopyable
  ObjectManagerServer(const ObjectManagerServer&) = delete;
  auto operator=(const ObjectManagerServer&) -> ObjectManagerServer& = delete;

private:  friend class ObjectManagerServer_Class;
  static CppClassType objectmanagerserver_class_;

protected:
  explicit ObjectManagerServer(const Glib::ConstructParams& construct_params);
  explicit ObjectManagerServer(GDBusObjectManagerServer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ObjectManagerServer(ObjectManagerServer&& src) noexcept;
  auto operator=(ObjectManagerServer&& src) noexcept -> ObjectManagerServer&;

  ~ObjectManagerServer() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusObjectManagerServer*       { return reinterpret_cast<GDBusObjectManagerServer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusObjectManagerServer* { return reinterpret_cast<GDBusObjectManagerServer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusObjectManagerServer*;

private:


protected:
    explicit ObjectManagerServer(const Glib::ustring& object_path);


public:
  /** Creates a new %Gio::DBus::ObjectManagerServer object.
   *
   * The returned server isn't yet exported on any connection. To do so,
   * use set_connection(). Normally you want to export all of your objects
   * before doing so to avoid Gio::DBus::ObjectManager::signal_interface_added()
   * signals being emitted.
   *
   * @param object_path The object path to export the manager object at.
   * @return A new %Gio::DBus::ObjectManagerServer object.
   */

  static auto create(const Glib::ustring& object_path) -> Glib::RefPtr<ObjectManagerServer>;


  /** Gets the Gio::DBus::Connection used by @a manager.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection object or <tt>nullptr</tt> if
   *  @a manager isn't exported on a connection. The returned object should
   * be freed with Glib::object_unref().
   */
  auto get_connection() -> Glib::RefPtr<Connection>;

  /** Gets the Gio::DBus::Connection used by @a manager.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection object or <tt>nullptr</tt> if
   *  @a manager isn't exported on a connection. The returned object should
   * be freed with Glib::object_unref().
   */
  auto get_connection() const -> Glib::RefPtr<const Connection>;

  /** Exports all objects managed by @a manager on @a connection. If
   *  @a connection is <tt>nullptr</tt>, stops exporting objects.
   *
   * @param connection A Gio::DBus::Connection or <tt>nullptr</tt>.
   */
  void set_connection(const Glib::RefPtr<Connection>& connection);

  // The method can't be called export(). 'export' is a keyword in C++.

  /** Exports @a object on @a manager.
   *
   * If there is already a DBusObject exported at the object path,
   * then the old object is removed.
   *
   * The object path for @a object must be in the hierarchy rooted by the
   * object path for @a manager.
   *
   * Note that @a manager will take a reference on @a object for as long as
   * it is exported.
   *
   * @newin{2,30}
   *
   * @param object A DBusObjectSkeleton.
   */
  void export_object(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object);

  /** Like g_dbus_object_manager_server_export() but appends a string of
   * the form _N (with N being a natural number) to @a object's object path
   * if an object with the given path already exists. As such, the
   * DBusObjectProxy::property_g_object_path() property of @a object may be modified.
   *
   * @newin{2,30}
   *
   * @param object An object.
   */
  void export_uniquely(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object);

  /** Returns whether @a object is currently exported on @a manager.
   *
   * @newin{2,34}
   *
   * @param object An object.
   * @return <tt>true</tt> if @a object is exported.
   */
  auto is_exported(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object) const -> bool;

  /** If @a manager has an object at @a path, removes the object. Otherwise
   * does nothing.
   *
   * Note that @a object_path must be in the hierarchy rooted by the
   * object path for @a manager.
   *
   * @newin{2,30}
   *
   * @param object_path An object path.
   * @return <tt>true</tt> if object at @a object_path was removed, <tt>false</tt> otherwise.
   */
  auto unexport(const Glib::ustring& object_path) -> bool;

 /** The Gio::DBus::Connection to export objects on.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_connection() -> Glib::PropertyProxy< Glib::RefPtr<Connection> > ;

/** The Gio::DBus::Connection to export objects on.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >;

 /** The object path to register the manager object at.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gio::DBus::ObjectManagerServer
   */
  GIOMM_API
  auto wrap(GDBusObjectManagerServer* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManagerServer>;
}


#endif /* _GIOMM_DBUSOBJECTMANAGERSERVER_H */

