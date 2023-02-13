
#ifndef _GIOMM_DBUSOBJECTMANAGER_H
#define _GIOMM_DBUSOBJECTMANAGER_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-glib/interface.hxx>
#include <libmm-glib/ustring.hxx>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusObjectManagerIface GDBusObjectManagerIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManager = struct _GDBusObjectManager;
using GDBusObjectManagerClass = struct _GDBusObjectManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API ObjectManager_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
class GIOMM_API Interface;
class GIOMM_API Object;


/** Base type for D-Bus object managers.
 *
 * The %Gio::DBus::ObjectManager type is the base type for service- and
 * client-side implementations of the standardized
 * <a href="http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-objectmanager">
 * org.freedesktop.DBus.ObjectManager</a> interface.
 *
 * See Gio::DBus::ObjectManagerClient for the client-side implementation
 * and Gio::DBus::ObjectManagerServer for the service-side implementation.
 *
 * @newin{2,62}
 * @ingroup DBus
 */

class GIOMM_API ObjectManager : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ObjectManager;
  using CppClassType = ObjectManager_Class;
  using BaseObjectType = GDBusObjectManager;
  using BaseClassType = GDBusObjectManagerIface;

  // noncopyable
  ObjectManager(const ObjectManager&) = delete;
  auto operator=(const ObjectManager&) -> ObjectManager& = delete;

private:
  friend class ObjectManager_Class;
  static CppClassType objectmanager_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ObjectManager();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ObjectManager(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ObjectManager(GDBusObjectManager* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ObjectManager(ObjectManager&& src) noexcept;
  auto operator=(ObjectManager&& src) noexcept -> ObjectManager&;

  ~ObjectManager() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusObjectManager*       { return reinterpret_cast<GDBusObjectManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusObjectManager* { return reinterpret_cast<GDBusObjectManager*>(gobject_); }

private:


public:

  /** Gets the object path that @a manager is for.
   *
   * @newin{2,30}
   *
   * @return A string owned by @a manager. Do not free.
   */
  auto get_object_path() const -> Glib::ustring;


  /** Gets all DBusObject objects known to @a manager.
   *
   * @newin{2,30}
   *
   * @return A list of
   * DBusObject objects.
   */
  auto get_objects() -> std::vector<Glib::RefPtr<Gio::DBus::Object>>;


  /** Gets all DBusObject objects known to @a manager.
   *
   * @newin{2,30}
   *
   * @return A list of
   * DBusObject objects.
   */
  auto get_objects() const -> std::vector<Glib::RefPtr<const Gio::DBus::Object>>;


  /** Gets the DBusObject at @a object_path, if any.
   *
   * @newin{2,30}
   *
   * @param object_path Object path to look up.
   * @return A DBusObject or <tt>nullptr</tt>. Free with
   * Glib::object_unref().
   */
  auto get_object(const Glib::ustring& object_path) -> Glib::RefPtr<Gio::DBus::Object>;

  /** Gets the DBusObject at @a object_path, if any.
   *
   * @newin{2,30}
   *
   * @param object_path Object path to look up.
   * @return A DBusObject or <tt>nullptr</tt>. Free with
   * Glib::object_unref().
   */
  auto get_object(const Glib::ustring& object_path) const -> Glib::RefPtr<const Gio::DBus::Object>;


  /** Gets the interface proxy for @a interface_name at @a object_path, if
   * any.
   *
   * @newin{2,30}
   *
   * @param object_path Object path to look up.
   * @param interface_name D-Bus interface name to look up.
   * @return A DBusInterface instance or <tt>nullptr</tt>. Free
   * with Glib::object_unref().
   */
  auto get_interface(const Glib::ustring& object_path, const Glib::ustring& interface_name) -> Glib::RefPtr<Gio::DBus::Interface>;

  /** Gets the interface proxy for @a interface_name at @a object_path, if
   * any.
   *
   * @newin{2,30}
   *
   * @param object_path Object path to look up.
   * @param interface_name D-Bus interface name to look up.
   * @return A DBusInterface instance or <tt>nullptr</tt>. Free
   * with Glib::object_unref().
   */
  auto get_interface(const Glib::ustring& object_path, const Glib::ustring& interface_name) const -> Glib::RefPtr<const Gio::DBus::Interface>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%object_added(const Glib::RefPtr<Gio::DBus::Object>& object)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a object is added to @a manager.
   *
   * @newin{2,30}
   *
   * @param object The DBusObject that was added.
   */

  auto signal_object_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%object_removed(const Glib::RefPtr<Gio::DBus::Object>& object)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a object is removed from @a manager.
   *
   * @newin{2,30}
   *
   * @param object The DBusObject that was removed.
   */

  auto signal_object_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&)>;


  // The parameter name 'interface' can cause compilation errors with MinGW.
  // See https://bugzilla.gnome.org/show_bug.cgi?id=735137
  // The parameter name in glib is 'interface'.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%interface_added(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a iface is added to @a object.
   *
   * This signal exists purely as a convenience to avoid having to
   * connect signals to all objects managed by @a manager.
   *
   * @newin{2,30}
   *
   * @param object The DBusObject on which an interface was added.
   * @param iface The DBusInterface that was added.
   */

  auto signal_interface_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%interface_removed(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a iface has been removed from @a object.
   *
   * This signal exists purely as a convenience to avoid having to
   * connect signals to all objects managed by @a manager.
   *
   * @newin{2,30}
   *
   * @param object The DBusObject on which an interface was removed.
   * @param iface The DBusInterface that was removed.
   */

  auto signal_interface_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>;


protected:


    virtual auto get_object_path_vfunc() const -> Glib::ustring;


    virtual auto get_objects_vfunc() const -> std::vector<Glib::RefPtr<Gio::DBus::Object>>;


  // Can't use refreturn_ctype here. It generates a call to Glib::unwrap_copy(), which
  // can't be used for Glib::Interface classes. They have no gobj_copy() method.


    virtual auto get_object_vfunc(const Glib::ustring& object_path) const -> Glib::RefPtr<Gio::DBus::Object>;


    virtual auto get_interface_vfunc(const Glib::ustring& object_path, const Glib::ustring& interface_name) const -> Glib::RefPtr<Gio::DBus::Interface>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_object_added().
  virtual void on_object_added(const Glib::RefPtr<Gio::DBus::Object>& object);
  /// This is a default handler for the signal signal_object_removed().
  virtual void on_object_removed(const Glib::RefPtr<Gio::DBus::Object>& object);
  /// This is a default handler for the signal signal_interface_added().
  virtual void on_interface_added(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface);
  /// This is a default handler for the signal signal_interface_removed().
  virtual void on_interface_removed(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface);


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
   * @relates Gio::DBus::ObjectManager
   */
  GIOMM_API
  auto wrap(GDBusObjectManager* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManager>;

} // namespace Glib


#endif /* _GIOMM_DBUSOBJECTMANAGER_H */

