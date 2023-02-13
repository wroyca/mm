
#ifndef _GIOMM_DBUSOBJECTMANAGERCLIENT_H
#define _GIOMM_DBUSOBJECTMANAGERCLIENT_H


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
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/dbusobjectmanager.hpp>
#include <libmm-gio/initable.hpp>
#include <libmm-gio/asyncinitable.hpp>
#include <libmm-gio/dbusconnection.hpp>
#include <libmm-gio/dbusobjectproxy.hpp>
#include <libmm-gio/dbusproxy.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerClient = struct _GDBusObjectManagerClient;
using GDBusObjectManagerClientClass = struct _GDBusObjectManagerClientClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API ObjectManagerClient_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
//The GMMPROC_EXTRA_NAMESPACE() macro is a hint to generate_wrap_init.pl to put it in the DBus sub-namespace


/** Client-side object manager.
 *
 * %Gio::DBus::ObjectManagerClient is used to create, monitor and delete object
 * proxies for remote objects exported by a Gio::DBus::ObjectManagerServer (or any
 * code implementing the
 * <a href="http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-objectmanager">
 * org.freedesktop.DBus.ObjectManager</a> interface.
 *
 * Once an instance of this type has been created, you can connect to
 * Gio::DBus::ObjectManager::signal_object_added() and
 * Gio::DBus::ObjectManager::signal_object_removed() and inspect the
 * Gio::DBus::Object objects returned by Gio::DBus::ObjectManager::get_objects().
 *
 * If the name for a %Gio::DBus::ObjectManagerClient is not owned by anyone at
 * object construction time, the default behavior is to request the
 * message bus to launch an owner for the name. This behavior can be
 * disabled using the Gio::DBus::ObjectManagerClient::Flags::DO_NOT_AUTO_START
 * flag. It's also worth noting that this only works if the name of
 * interest is activatable in the first place. E.g. in some cases it
 * is not possible to launch an owner for the requested name. In this
 * case, %ObjectManagerClient object construction still succeeds but
 * there will be no object proxies
 * (e.g. get_objects() returns an empty vector) and
 * property_name_owner() is an empty string.
 *
 * The owner of the requested name can come and go (for example
 * consider a system service being restarted) – %ObjectManagerClient
 * handles this case too; simply connect to property_name_owner().signal_changed()
 * to watch for changes on property_name_owner().
 * When the name owner vanishes, the behavior is that
 * property_name_owner() is set to an empty string (this includes
 * emission of signal_changed()) and then
 * signal_object_removed() signals are synthesized
 * for all currently existing object proxies. Since
 * property_name_owner() is an empty string when this happens, you can
 * use this information to disambiguate a synthesized signal from a
 * genuine signal caused by object removal on the remote
 * Gio::DBus::ObjectManager. Similarly, when a new name owner appears,
 * signal_object_added() signals are synthesized
 * while property_namename_owner() is still an empty string. Only when all
 * object proxies have been added, property_name_owner()
 * is set to the new name owner (this includes emission of the
 * signal_changed()). Furthermore, you are guaranteed that
 * property_name_owner() will alternate between a name owner
 * (e.g. `:1.42`) and an empty string even in the case where
 * the name of interest is atomically replaced.
 *
 * Ultimately, %ObjectManagerClient is used to obtain Gio::DBus::Proxy
 * instances. All signals (including the
 * org.freedesktop.DBus.Properties::PropertiesChanged signal)
 * delivered to Gio::DBus::Proxy instances are guaranteed to originate
 * from the name owner. This guarantee along with the behavior
 * described above, means that certain race conditions including the
 * "half the proxy is from the old owner and the other half is from
 * the new owner" problem cannot happen.
 *
 * To avoid having the application connect to signals on the returned
 * Gio::DBus::Object and Gio::DBus::Proxy objects,
 * Gio::DBus::Object::signal_interface_added(),
 * Gio::DBus::Object::signal_interface_removed(),
 * Gio::DBus::Proxy::signal_properties_changed() and
 * Gio::DBus::Proxy::signal_signal()
 * are also emitted on the %ObjectManagerClient instance managing these
 * objects. The signals emitted are
 * signal_interface_added(), signal_interface_removed(),
 * signal_interface_proxy_properties_changed() and
 * signal_interface_proxy_signal().
 *
 * Note that all callbacks and signals are emitted in the
 * thread-default main context
 * that the %ObjectManagerClient object was constructed
 * in. Additionally, the Gio::DBus::ObjectProxy and Gio::DBus::Proxy objects
 * originating from the %ObjectManagerClient object will be created in
 * the same context and, consequently, will deliver signals in the
 * same main loop.
 *
 * @newin{2,62}
 * @ingroup DBus
 */

class GIOMM_API ObjectManagerClient
: public Glib::Object,
  public Initable,
  public AsyncInitable,
  public ObjectManager
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ObjectManagerClient;
  using CppClassType = ObjectManagerClient_Class;
  using BaseObjectType = GDBusObjectManagerClient;
  using BaseClassType = GDBusObjectManagerClientClass;

  // noncopyable
  ObjectManagerClient(const ObjectManagerClient&) = delete;
  auto operator=(const ObjectManagerClient&) -> ObjectManagerClient& = delete;

private:  friend class ObjectManagerClient_Class;
  static CppClassType objectmanagerclient_class_;

protected:
  explicit ObjectManagerClient(const Glib::ConstructParams& construct_params);
  explicit ObjectManagerClient(GDBusObjectManagerClient* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ObjectManagerClient(ObjectManagerClient&& src) noexcept;
  auto operator=(ObjectManagerClient&& src) noexcept -> ObjectManagerClient&;

  ~ObjectManagerClient() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusObjectManagerClient*       { return reinterpret_cast<GDBusObjectManagerClient*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusObjectManagerClient* { return reinterpret_cast<GDBusObjectManagerClient*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusObjectManagerClient*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags set.
   *
   *  @var Flags DO_NOT_AUTO_START
   * If not set and the
   * manager is for a well-known name, then request the bus to launch
   * an owner for the name if no-one owns the name. This flag can only
   * be used in managers for well-known names.
   *
   *  @enum Flags
   *
   * Flags used when constructing a DBusObjectManagerClient.
   *
   * @newin{2,30}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>ObjectManagerClient::Flags operator|(ObjectManagerClient::Flags, ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags operator&(ObjectManagerClient::Flags, ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags operator^(ObjectManagerClient::Flags, ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags operator~(ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags& operator|=(ObjectManagerClient::Flags&, ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags& operator&=(ObjectManagerClient::Flags&, ObjectManagerClient::Flags)</tt><br>
   * <tt>ObjectManagerClient::Flags& operator^=(ObjectManagerClient::Flags&, ObjectManagerClient::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    DO_NOT_AUTO_START = (1<<0)
  };


  /** A slot that will be called to determine the GType to use for an interface proxy
   * (if interface_name is not an empty string) or object proxy (if interface_name is
   * an empty string).
   *
   * This function is called in the thread-default main loop that @a manager was constructed in.
   *
   * For instance:
   * @code
   * GType on_proxy_type(const Glib::RefPtr<Gio::DBus::ObjectManagerClient>& manager,
   *       const Glib::ustring& object_path, const Glib::ustring& interface_name);
   * @endcode
   *
   * @param manager A Gio::DBus::ObjectManagerClient.
   * @param object_path The object path of the remote object.
   * @param interface_name The interface name of the remote object, or an empty
   *        string if a GDBusObjectProxy GType is requested.
   * @returns A GType to use for the remote object. The returned type must be
   *          a GDBusProxy or GDBusObjectProxy-derived type.
   */
  using SlotProxyType = sigc::slot<GType(const Glib::RefPtr<Gio::DBus::ObjectManagerClient>&,
        const Glib::ustring&, const Glib::ustring&)>;

protected:
  ObjectManagerClient(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const SlotAsyncReady& slot_async_ready,
    const Glib::RefPtr<Cancellable>& cancellable,
    const SlotProxyType& slot_proxy_type, Flags flags);

  ObjectManagerClient(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const SlotAsyncReady& slot_async_ready,
    const Glib::RefPtr<Cancellable>& cancellable,
    const SlotProxyType& slot_proxy_type, Flags flags);


public:
  /** Creates a new %Gio::DBus::ObjectManagerClient object.
   *
   * This is an asynchronous failable constructor. When the result is
   * ready, @a slot_async_ready will be invoked in the
   * thread-default main context of the thread you are calling this method from.
   * You can then call create_finish() to get the result.
   * See create_sync() for the synchronous version.
   *
   * @param connection A Gio::DBus::Connection.
   * @param name The owner of the control object (unique or well-known name).
   * @param object_path The object path of the control object.
   * @param slot_async_ready A SlotAsyncReady slot to call when the request is satisfied.
   * @param cancellable A Cancellable or an empty Glib::RefPtr.
   * @param slot_proxy_type A SlotProxyType slot, or an empty slot to always construct
   *        GDBusProxy or GDBusObjectProxy proxies.
   * @param flags Zero or more flags from the Gio::DBus::ObjectManagerClient::Flags enumeration.
   */
  static void create(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const SlotAsyncReady& slot_async_ready,
    const Glib::RefPtr<Cancellable>& cancellable = {},
    const SlotProxyType& slot_proxy_type = {},
    Flags flags = Flags::NONE);

  // g_dbus_object_manager_client_new_finish() and g_dbus_object_manager_client_new_for_bus_finish()
  // return GDBusObjectManager pointers, although they are GDBusObjectManagerClient pointers.


  /** Finishes an operation started with create().
   *
   * @param res An AsyncResult obtained from the SlotAsyncReady passed to create().
   * @return A %Gio::DBus::ObjectManagerClient object. If an error has occurred,
   *         a Glib::Error is thrown and nothing is returned.
   * @throw Glib::Error.
   */
  static auto create_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

  /** Creates a new %Gio::DBus::ObjectManagerClient object.
   *
   * This is a synchronous failable constructor - the calling thread is
   * blocked until a reply is received. See create() for the asynchronous version.
   *
   * @param connection A Gio::DBus::Connection.
   * @param name The owner of the control object (unique or well-known name).
   * @param object_path The object path of the control object.
   * @param cancellable A Cancellable or an empty Glib::RefPtr.
   * @param slot_proxy_type A SlotProxyType slot, or an empty slot to always construct
   *        GDBusProxy or GDBusObjectProxy proxies.
   * @param flags Zero or more flags from the Gio::DBus::ObjectManagerClient::Flags enumeration.
   * @throw Glib::Error
   */
  static auto create_sync(
    const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::RefPtr<Cancellable>& cancellable = {},
    const SlotProxyType& slot_proxy_type = {},
    Flags flags = Flags::NONE) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

  /** Creates a new %Gio::DBus::ObjectManagerClient object.
   *
   * Like create() but takes a Gio::DBus::BusType instead of a Gio::DBus::Connection.
   *
   * This is an asynchronous failable constructor. When the result is
   * ready, @a slot_async_ready will be invoked in the
   * thread-default main context of the thread you are calling this method from.
   * You can then call create_for_bus_finish() to get the result.
   * See create_for_bus_sync() for the synchronous version.
   *
   * @param bus_type A Gio::DBus::BusType.
   * @param name The owner of the control object (unique or well-known name).
   * @param object_path The object path of the control object.
   * @param slot_async_ready A SlotAsyncReady slot to call when the request is satisfied.
   * @param cancellable A Cancellable or an empty Glib::RefPtr.
   * @param slot_proxy_type A SlotProxyType slot, or an empty slot to always construct
   *        GDBusProxy or GDBusObjectProxy proxies.
   * @param flags Zero or more flags from the Gio::DBus::ObjectManagerClient::Flags enumeration.
   */
  static void create_for_bus(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const SlotAsyncReady& slot_async_ready,
    const Glib::RefPtr<Cancellable>& cancellable = {},
    const SlotProxyType& slot_proxy_type = {},
    Flags flags = Flags::NONE);


  /** Finishes an operation started with create_for_bus().
   *
   * @param res An AsyncResult obtained from the SlotAsyncReady passed to create_for_bus().
   * @return A %Gio::DBus::ObjectManagerClient object. If an error has occurred,
   *         a Glib::Error is thrown and nothing is returned.
   * @throw Glib::Error.
   */
  static auto create_for_bus_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;

  /** Creates a new %Gio::DBus::ObjectManagerClient object.
   *
   * Like create_sync() but takes a Gio::DBus::BusType instead of a
   * Gio::DBus::Connection.
   *
   * This is a synchronous failable constructor - the calling thread is
   * blocked until a reply is received. See create_for_bus()
   * for the asynchronous version.
   *
   * @param bus_type A Gio::DBus::BusType.
   * @param name The owner of the control object (unique or well-known name).
   * @param object_path The object path of the control object.
   * @param cancellable A Cancellable or an empty Glib::RefPtr.
   * @param slot_proxy_type A SlotProxyType slot, or an empty slot to always construct
   *        GDBusProxy or GDBusObjectProxy proxies.
   * @param flags Zero or more flags from the Gio::DBus::ObjectManagerClient::Flags enumeration.
   * @throw Glib::Error
   */
  static auto create_for_bus_sync(
    BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::RefPtr<Cancellable>& cancellable = {},
    const SlotProxyType& slot_proxy_type = {},
    Flags flags = Flags::NONE) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;


  /** Gets the Gio::DBus::Connection used by @a manager.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection object. Do not free,
   * the object belongs to @a manager.
   */
  auto get_connection() -> Glib::RefPtr<Connection>;

  /** Gets the Gio::DBus::Connection used by @a manager.
   *
   * @newin{2,30}
   *
   * @return A Gio::DBus::Connection object. Do not free,
   * the object belongs to @a manager.
   */
  auto get_connection() const -> Glib::RefPtr<const Connection>;


  /** Gets the flags that @a manager was constructed with.
   *
   * @newin{2,30}
   *
   * @return Zero of more flags from the DBusObjectManagerClientFlags
   * enumeration.
   */
  auto get_flags() const -> Flags;


  /** Gets the name that @a manager is for, or <tt>nullptr</tt> if not a message bus
   * connection.
   *
   * @newin{2,30}
   *
   * @return A unique or well-known name. Do not free, the string
   * belongs to @a manager.
   */
  auto get_name() const -> Glib::ustring;

  /** The unique name that owns the name that @a manager is for or <tt>nullptr</tt> if
   * no-one currently owns that name. You can connect to the
   * Object::signal_notify() signal to track changes to the
   * DBusObjectManagerClient::property_name_owner() property.
   *
   * @newin{2,30}
   *
   * @return The name owner or <tt>nullptr</tt> if no name owner
   * exists.
   */
  auto get_name_owner() const -> Glib::ustring;

 /** The Gio::DBus::Connection to use.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >;


 /** Flags from the DBusObjectManagerClientFlags enumeration.
   *
   * @newin{2,30}
   *
   * Default value: Gio::DBus::ObjectManagerClient::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;


 /** The object path the manager is for.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 /** The well-known name or unique name that the manager is for.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 /** The unique name that owns DBusObjectManagerClient::property_name() or <tt>nullptr</tt> if
   * no-one is currently owning the name. Connect to the
   * Object::signal_notify() signal to track changes to this property.
   *
   * @newin{2,30}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_name_owner() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 //_WRAP_PROPERTY("bus-type", BusType) // write-only construct-only
 // The get-proxy-type-func, get-proxy-type-user-data and get-proxy-type-destroy-notify properties
 // can't be wrapped individually. Perhaps add set_slot_proxy_type() and get_slot_proxy_type() methods?


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%interface_proxy_signal(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a D-Bus signal is received on @a interface_proxy.
   *
   * This signal exists purely as a convenience to avoid having to
   * connect signals to all interface proxies managed by @a manager.
   *
   * This signal is emitted in the
   * [thread-default main context][g-main-context-push-thread-default]
   * that @a manager was constructed in.
   *
   * @newin{2,30}
   *
   * @param object_proxy The DBusObjectProxy on which an interface is emitting a D-Bus signal.
   * @param interface_proxy The Gio::DBus::Proxy that is emitting a D-Bus signal.
   * @param sender_name The sender of the signal or <tt>nullptr</tt> if the connection is not a bus connection.
   * @param signal_name The signal name.
   * @param parameters A Variant tuple with parameters for the signal.
   */

  auto signal_interface_proxy_signal() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::ObjectProxy>&, const Glib::RefPtr<Gio::DBus::Proxy>&, const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>;


  using MapChangedProperties = std::map<Glib::ustring, Glib::VariantBase>;

  // The DBus API ensures that the variant changed_properties is of type "DICT<STRING,VARIANT>"


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%interface_proxy_properties_changed(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const MapChangedProperties& changed_properties, const std::vector<Glib::ustring>& invalidated_properties)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when one or more D-Bus properties on proxy changes. The
   * local cache has already been updated when this signal fires. Note
   * that both @a changed_properties and @a invalidated_properties are
   * guaranteed to never be <tt>nullptr</tt> (either may be empty though).
   *
   * This signal exists purely as a convenience to avoid having to
   * connect signals to all interface proxies managed by @a manager.
   *
   * This signal is emitted in the
   * [thread-default main context][g-main-context-push-thread-default]
   * that @a manager was constructed in.
   *
   * @newin{2,30}
   *
   * @param object_proxy The DBusObjectProxy on which an interface has properties that are changing.
   * @param interface_proxy The Gio::DBus::Proxy that has properties that are changing.
   * @param changed_properties A Variant containing the properties that changed (type: `a{sv}`).
   * @param invalidated_properties A <tt>nullptr</tt> terminated
   * array of properties that were invalidated.
   */

  auto signal_interface_proxy_properties_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::ObjectProxy>&, const Glib::RefPtr<Gio::DBus::Proxy>&, const MapChangedProperties&, const std::vector<Glib::ustring>&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_interface_proxy_signal().
  virtual void on_interface_proxy_signal(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters);
  /// This is a default handler for the signal signal_interface_proxy_properties_changed().
  virtual void on_interface_proxy_properties_changed(const Glib::RefPtr<Gio::DBus::ObjectProxy>& object_proxy, const Glib::RefPtr<Gio::DBus::Proxy>& interface_proxy, const MapChangedProperties& changed_properties, const std::vector<Glib::ustring>& invalidated_properties);


};

} // namespace Gio

namespace Gio::DBus
{

/** @ingroup giommEnums */
inline auto operator|(ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  { return static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  { return static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(ObjectManagerClient::Flags lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags
  { return static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(ObjectManagerClient::Flags flags) -> ObjectManagerClient::Flags
  { return static_cast<ObjectManagerClient::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  { return (lhs = static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  { return (lhs = static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(ObjectManagerClient::Flags& lhs, ObjectManagerClient::Flags rhs) -> ObjectManagerClient::Flags&
  { return (lhs = static_cast<ObjectManagerClient::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::ObjectManagerClient::Flags> : public Glib::Value_Flags<Gio::DBus::ObjectManagerClient::Flags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DBus::ObjectManagerClient
   */
  GIOMM_API
  auto wrap(GDBusObjectManagerClient* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManagerClient>;
}


#endif /* _GIOMM_DBUSOBJECTMANAGERCLIENT_H */

