
#ifndef _GIOMM_DBUSPROXY_H
#define _GIOMM_DBUSPROXY_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/dbusinterface.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-gio/asyncinitable.hxx>
#include <libmm-gio/dbusconnection.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusProxy = struct _GDBusProxy;
using GDBusProxyClass = struct _GDBusProxyClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API Proxy_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{
//The GMMPROC_EXTRA_NAMESPACE() macro is a hint to generate_wrap_init.pl to put it in the DBus sub-namespace


/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var ProxyFlags NONE
 * No flags set.
 *
 *  @var ProxyFlags DO_NOT_LOAD_PROPERTIES
 * Don't load properties.
 *
 *  @var ProxyFlags DO_NOT_CONNECT_SIGNALS
 * Don't connect to signals on the remote object.
 *
 *  @var ProxyFlags DO_NOT_AUTO_START
 * If the proxy is for a well-known name,
 * do not ask the bus to launch an owner during proxy initialization or a method call.
 * This flag is only meaningful in proxies for well-known names.
 *
 *  @var ProxyFlags GET_INVALIDATED_PROPERTIES
 * If set, the property value for any __invalidated property__ will be (asynchronously) retrieved upon receiving the [`PropertiesChanged`](http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-properties) D-Bus signal and the property will not cause emission of the Gio::DBus::Proxy::signal_g_properties_changed() signal. When the value is received the Gio::DBus::Proxy::signal_g_properties_changed() signal is emitted for the property along with the retrieved value. @newin{2,32}
 *
 *  @var ProxyFlags DO_NOT_AUTO_START_AT_CONSTRUCTION
 * If the proxy is for a well-known name,
 * do not ask the bus to launch an owner during proxy initialization, but allow it to be
 * autostarted by a method call. This flag is only meaningful in proxies for well-known names,
 * and only if Gio::DBus::ProxyFlags::DO_NOT_AUTO_START is not also specified.
 *
 *  @var ProxyFlags NO_MATCH_RULE
 * Don't actually send the AddMatch D-Bus
 * call for this signal subscription. This gives you more control
 * over which match rules you add (but you must add them manually). (Since: 2.72).
 *
 *  @enum ProxyFlags
 *
 * Flags used when constructing an instance of a Gio::DBus::Proxy derived class.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>ProxyFlags operator|(ProxyFlags, ProxyFlags)</tt><br>
 * <tt>ProxyFlags operator&(ProxyFlags, ProxyFlags)</tt><br>
 * <tt>ProxyFlags operator^(ProxyFlags, ProxyFlags)</tt><br>
 * <tt>ProxyFlags operator~(ProxyFlags)</tt><br>
 * <tt>ProxyFlags& operator|=(ProxyFlags&, ProxyFlags)</tt><br>
 * <tt>ProxyFlags& operator&=(ProxyFlags&, ProxyFlags)</tt><br>
 * <tt>ProxyFlags& operator^=(ProxyFlags&, ProxyFlags)</tt><br>
 */
enum class ProxyFlags
{
  NONE = 0x0,
  DO_NOT_LOAD_PROPERTIES = (1<<0),
  DO_NOT_CONNECT_SIGNALS = (1<<1),
  DO_NOT_AUTO_START = (1<<2),
  GET_INVALIDATED_PROPERTIES = (1<<3),
  DO_NOT_AUTO_START_AT_CONSTRUCTION = (1<<4),
  NO_MATCH_RULE = (1<<5)
};

/** @ingroup giommEnums */
inline auto operator|(ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  { return static_cast<ProxyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  { return static_cast<ProxyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(ProxyFlags lhs, ProxyFlags rhs) -> ProxyFlags
  { return static_cast<ProxyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(ProxyFlags flags) -> ProxyFlags
  { return static_cast<ProxyFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  { return (lhs = static_cast<ProxyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  { return (lhs = static_cast<ProxyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(ProxyFlags& lhs, ProxyFlags rhs) -> ProxyFlags&
  { return (lhs = static_cast<ProxyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::ProxyFlags> : public Glib::Value_Flags<Gio::DBus::ProxyFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio::DBus
{


/** A client-side proxy.
 * This is a base class used for proxies to access a D-Bus interface on
 * a remote object. It can be constructed for both well-known and
 * unique names.
 *
 * By default, Proxy will cache all properties (and listen to changes) of
 * the remote object, and proxy all signals that gets emitted. This behaviour
 * can be changed by passing suitable ProxyFlags when the proxy is
 * created. If the proxy is for a well-known name, the property cache is
 * flushed when the name owner vanishes and reloaded when a name owner
 * appears.
 *
 * If a Proxy is used for a well-known name, the owner of the name is
 * tracked and can be read from property_g_name_owner().
 *
 * The generic signal_properties_changed() and signal_signal() signals are
 * not very convenient to work with. Therefore, the recommended way of working
 * with proxies is to subclass Proxy, and have more natural properties and
 * signals in your derived class.
 *
 * This documentation was adapted from the C API documentation.  The C API docs
 * has more information and an example.
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class GIOMM_API Proxy
: public Glib::Object,
  public Initable,
  public AsyncInitable,
  public Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Proxy;
  using CppClassType = Proxy_Class;
  using BaseObjectType = GDBusProxy;
  using BaseClassType = GDBusProxyClass;

  // noncopyable
  Proxy(const Proxy&) = delete;
  auto operator=(const Proxy&) -> Proxy& = delete;

private:  friend class Proxy_Class;
  static CppClassType proxy_class_;

protected:
  explicit Proxy(const Glib::ConstructParams& construct_params);
  explicit Proxy(GDBusProxy* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Proxy(Proxy&& src) noexcept;
  auto operator=(Proxy&& src) noexcept -> Proxy&;

  ~Proxy() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusProxy*       { return reinterpret_cast<GDBusProxy*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusProxy* { return reinterpret_cast<GDBusProxy*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusProxy*;

private:


protected:

  Proxy(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  Proxy(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

public:


  /** Creates a proxy for accessing @a interface_name on the remote object
   * at @a object_path owned by @a name at @a connection and asynchronously
   * loads D-Bus properties unless the
   * Gio::DBus::ProxyFlags::DO_NOT_LOAD_PROPERTIES flag is used. Connect to
   * the Gio::DBus::Proxy::signal_g_properties_changed() signal to get notified about
   * property changes.
   *
   * If the Gio::DBus::ProxyFlags::DO_NOT_CONNECT_SIGNALS flag is not set, also sets up
   * match rules for signals. Connect to the Gio::DBus::Proxy::signal_g_signal() signal
   * to handle signals from the remote object.
   *
   * If both Gio::DBus::ProxyFlags::DO_NOT_LOAD_PROPERTIES and
   * Gio::DBus::ProxyFlags::DO_NOT_CONNECT_SIGNALS are set, this constructor is
   * guaranteed to complete immediately without blocking.
   *
   * If @a name is a well-known name and the
   * Gio::DBus::ProxyFlags::DO_NOT_AUTO_START and Gio::DBus::ProxyFlags::DO_NOT_AUTO_START_AT_CONSTRUCTION
   * flags aren't set and no name owner currently exists, the message bus
   * will be requested to launch a name owner for the name.
   *
   * This is a failable asynchronous constructor - when the proxy is
   * ready, @a slot will be invoked and you can use
   * g_dbus_proxy_new_finish() to get the result.
   *
   * See g_dbus_proxy_new_sync() and for a synchronous version of this constructor.
   *
   * Gio::DBus::Proxy is used in this [example][gdbus-wellknown-proxy].
   *
   * @newin{2,26}
   *
   * @param connection A Gio::DBus::Connection.
   * @param flags Flags used when constructing the proxy.
   * @param info A Gio::DBus::InterfaceInfo specifying the minimal interface that @a proxy conforms to or <tt>nullptr</tt>.
   * @param name A bus name (well-known or unique) or <tt>nullptr</tt> if @a connection is not a message bus connection.
   * @param object_path An object path.
   * @param interface_name A D-Bus interface name.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot Callback function to invoke when the proxy is ready.
   * @param user_data User data to pass to @a slot.
   */

  static void create(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  /// Non-cancellable version of create().
  static void create(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);


  /** Finishes creating a Gio::DBus::Proxy.
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady function passed to g_dbus_proxy_new().
   * @return A Gio::DBus::Proxy or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   */


  /** @throw Glib::Error.
   */
  static auto create_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Gio::DBus::Proxy>;


  /** Creates a proxy for accessing @a interface_name on the remote object
   * at @a object_path owned by @a name at @a connection and synchronously
   * loads D-Bus properties unless the
   * Gio::DBus::ProxyFlags::DO_NOT_LOAD_PROPERTIES flag is used.
   *
   * If the Gio::DBus::ProxyFlags::DO_NOT_CONNECT_SIGNALS flag is not set, also sets up
   * match rules for signals. Connect to the Gio::DBus::Proxy::signal_g_signal() signal
   * to handle signals from the remote object.
   *
   * If both Gio::DBus::ProxyFlags::DO_NOT_LOAD_PROPERTIES and
   * Gio::DBus::ProxyFlags::DO_NOT_CONNECT_SIGNALS are set, this constructor is
   * guaranteed to return immediately without blocking.
   *
   * If @a name is a well-known name and the
   * Gio::DBus::ProxyFlags::DO_NOT_AUTO_START and Gio::DBus::ProxyFlags::DO_NOT_AUTO_START_AT_CONSTRUCTION
   * flags aren't set and no name owner currently exists, the message bus
   * will be requested to launch a name owner for the name.
   *
   * This is a synchronous failable constructor. See g_dbus_proxy_new()
   * and g_dbus_proxy_new_finish() for the asynchronous version.
   *
   * Gio::DBus::Proxy is used in this [example][gdbus-wellknown-proxy].
   *
   * @newin{2,26}
   *
   * @param connection A Gio::DBus::Connection.
   * @param flags Flags used when constructing the proxy.
   * @param info A Gio::DBus::InterfaceInfo specifying the minimal interface that @a proxy conforms to or <tt>nullptr</tt>.
   * @param name A bus name (well-known or unique) or <tt>nullptr</tt> if @a connection is not a message bus connection.
   * @param object_path An object path.
   * @param interface_name A D-Bus interface name.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Proxy or <tt>nullptr</tt> if error is set.
   * Free with Glib::object_unref().
   */

  static auto
  create_sync(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;

  /// Non-cancellable version of create_sync().
  static auto
  create_sync(const Glib::RefPtr<Connection>& connection,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;


  /** Like g_dbus_proxy_new() but takes a BusType instead of a Gio::DBus::Connection.
   *
   * Gio::DBus::Proxy is used in this [example][gdbus-wellknown-proxy].
   *
   * @newin{2,26}
   *
   * @param bus_type A BusType.
   * @param flags Flags used when constructing the proxy.
   * @param info A Gio::DBus::InterfaceInfo specifying the minimal interface that @a proxy conforms to or <tt>nullptr</tt>.
   * @param name A bus name (well-known or unique).
   * @param object_path An object path.
   * @param interface_name A D-Bus interface name.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot Callback function to invoke when the proxy is ready.
   * @param user_data User data to pass to @a slot.
   */

  static void create_for_bus(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);

  /// Non-cancellable version of create_for_bus().
  static void create_for_bus(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE);


  /** Finishes creating a Gio::DBus::Proxy.
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady function passed to g_dbus_proxy_new_for_bus().
   * @return A Gio::DBus::Proxy or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   */


  /** @throw Glib::Error.
   */
  static auto create_for_bus_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Gio::DBus::Proxy>;


  /** Like g_dbus_proxy_new_sync() but takes a BusType instead of a Gio::DBus::Connection.
   *
   * Gio::DBus::Proxy is used in this [example][gdbus-wellknown-proxy].
   *
   * @newin{2,26}
   *
   * @param bus_type A BusType.
   * @param flags Flags used when constructing the proxy.
   * @param info A Gio::DBus::InterfaceInfo specifying the minimal interface
   * that @a proxy conforms to or <tt>nullptr</tt>.
   * @param name A bus name (well-known or unique).
   * @param object_path An object path.
   * @param interface_name A D-Bus interface name.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Proxy or <tt>nullptr</tt> if error is set.
   * Free with Glib::object_unref().
   */

  static auto
  create_for_bus_sync(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<Cancellable>& cancellable,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;

  /// Non-cancellable version of create_for_bus_sync().
  static auto
  create_for_bus_sync(BusType bus_type,
    const Glib::ustring& name,
    const Glib::ustring& object_path,
    const Glib::ustring& interface_name,
    const Glib::RefPtr<InterfaceInfo>& info = {},
    ProxyFlags flags = ProxyFlags::NONE) -> Glib::RefPtr<Proxy>;


  /** Gets the flags that @a proxy was constructed with.
   *
   * @newin{2,26}
   *
   * @return Flags from the Gio::DBus::ProxyFlags enumeration.
   */
  auto get_flags() const -> ProxyFlags;


  /** Gets the connection @a proxy is for.
   *
   * @newin{2,26}
   *
   * @return A Gio::DBus::Connection owned by @a proxy. Do not free.
   */
  auto get_connection() -> Glib::RefPtr<Connection>;

  /** Gets the connection @a proxy is for.
   *
   * @newin{2,26}
   *
   * @return A Gio::DBus::Connection owned by @a proxy. Do not free.
   */
  auto get_connection() const -> Glib::RefPtr<const Connection>;


  /** Gets the name that @a proxy was constructed for.
   *
   * When connected to a message bus, this will usually be non-<tt>nullptr</tt>.
   * However, it may be <tt>nullptr</tt> for a proxy that communicates using a peer-to-peer
   * pattern.
   *
   * @newin{2,26}
   *
   * @return A string owned by @a proxy. Do not free.
   */
  auto get_name() const -> Glib::ustring;

  /** The unique name that owns the name that @a proxy is for or <tt>nullptr</tt> if
   * no-one currently owns that name. You may connect to the
   * Object::signal_notify() signal to track changes to the
   * Gio::DBus::Proxy::property_g_name_owner() property.
   *
   * @newin{2,26}
   *
   * @return The name owner or <tt>nullptr</tt> if no name
   * owner exists.
   */
  auto get_name_owner() const -> Glib::ustring;

  /** Gets the object path @a proxy is for.
   *
   * @newin{2,26}
   *
   * @return A string owned by @a proxy. Do not free.
   */
  auto get_object_path() const -> Glib::ustring;

  /** Gets the D-Bus interface name @a proxy is for.
   *
   * @newin{2,26}
   *
   * @return A string owned by @a proxy. Do not free.
   */
  auto get_interface_name() const -> Glib::ustring;


  /** Gets the timeout to use if -1 (specifying default timeout) is
   * passed as @a timeout_msec in the g_dbus_proxy_call() and
   * g_dbus_proxy_call_sync() functions.
   *
   * See the Gio::DBus::Proxy::property_g_default_timeout() property for more details.
   *
   * @newin{2,26}
   *
   * @return Timeout to use for @a proxy.
   */
  auto get_default_timeout() const -> int;

  /** Sets the timeout to use if -1 (specifying default timeout) is
   * passed as @a timeout_msec in the g_dbus_proxy_call() and
   * g_dbus_proxy_call_sync() functions.
   *
   * See the Gio::DBus::Proxy::property_g_default_timeout() property for more details.
   *
   * @newin{2,26}
   *
   * @param timeout_msec Timeout in milliseconds.
   */
  void set_default_timeout(int timeout_msec =  -1);

  /** Looks up the value for a property from the cache. This call does no
   * blocking IO.
   *
   * If proxy has an expected interface (see property_g_interface_info()),
   * then @a property_name (for existence) is checked against it.
   *
   * @param property An output parameter in which to hold to the variant
   * instance that holds the value for @a property_name.
   * @param property_name Property name.
   *
   * @newin{2,28}
   */
  void get_cached_property(Glib::VariantBase& property,
    const Glib::ustring& property_name) const;


  /** If @a value is not <tt>nullptr</tt>, sets the cached value for the property with
   * name @a property_name to the value in @a value.
   *
   * If @a value is <tt>nullptr</tt>, then the cached value is removed from the
   * property cache.
   *
   * If @a proxy has an expected interface (see
   * Gio::DBus::Proxy::property_g_interface_info()) and @a property_name is referenced by
   * it, then @a value is checked against the type of the property.
   *
   * If the @a value Variant is floating, it is consumed. This allows
   * convenient 'inline' use of Glib::variant_new(), e.g.
   *
   * [C example ellipted]
   *
   * Normally you will not need to use this method since @a proxy
   * is tracking changes using the
   * `org.freedesktop.DBus.Properties.PropertiesChanged`
   * D-Bus signal. However, for performance reasons an object may
   * decide to not use this signal for some properties and instead
   * use a proprietary out-of-band mechanism to transmit changes.
   *
   * As a concrete example, consider an object with a property
   * `ChatroomParticipants` which is an array of strings. Instead of
   * transmitting the same (long) array every time the property changes,
   * it is more efficient to only transmit the delta using e.g. signals
   * `ChatroomParticipantJoined(String name)` and
   * `ChatroomParticipantParted(String name)`.
   *
   * @newin{2,26}
   *
   * @param property_name Property name.
   * @param value Value for the property or <tt>nullptr</tt> to remove it from the cache.
   */
  void set_cached_property(const Glib::ustring& property_name, const Glib::VariantBase& value);


  /** Gets the names of all cached properties on @a proxy.
   *
   * @newin{2,26}
   *
   * @return A
   * <tt>nullptr</tt>-terminated array of strings or <tt>nullptr</tt> if
   *  @a proxy has no cached properties.
   */
  auto get_cached_property_names() const -> std::vector<Glib::ustring>;


  /** Ensure that interactions with @a proxy conform to the given
   * interface. See the Gio::DBus::Proxy::property_g_interface_info() property for more
   * details.
   *
   * @newin{2,26}
   *
   * @param info Minimum interface this proxy conforms to
   * or <tt>nullptr</tt> to unset.
   */
  void set_interface_info(const Glib::RefPtr<InterfaceInfo>& info);

  /** Returns the Gio::DBus::InterfaceInfo, if any, specifying the interface
   * that @a proxy conforms to. See the Gio::DBus::Proxy::property_g_interface_info()
   * property for more details.
   *
   * @newin{2,26}
   *
   * @return A Gio::DBus::InterfaceInfo or <tt>nullptr</tt>.
   * Do not unref the returned object, it is owned by @a proxy.
   */
  auto get_interface_info() -> Glib::RefPtr<InterfaceInfo>;

  /** Returns the Gio::DBus::InterfaceInfo, if any, specifying the interface
   * that @a proxy conforms to. See the Gio::DBus::Proxy::property_g_interface_info()
   * property for more details.
   *
   * @newin{2,26}
   *
   * @return A Gio::DBus::InterfaceInfo or <tt>nullptr</tt>.
   * Do not unref the returned object, it is owned by @a proxy.
   */
  auto get_interface_info() const -> Glib::RefPtr<const InterfaceInfo>;


  /** Asynchronously invokes the @a method_name method on @a proxy.
   *
   * If @a method_name contains any dots, then @a name is split into interface and
   * method name parts. This allows using @a proxy for invoking methods on
   * other interfaces.
   *
   * If the Gio::DBus::Connection associated with @a proxy is closed then
   * the operation will fail with Gio::Error::CLOSED. If
   *  @a cancellable is canceled, the operation will fail with
   * Gio::Error::CANCELLED. If @a parameters contains a value not
   * compatible with the D-Bus protocol, the operation fails with
   * Gio::Error::INVALID_ARGUMENT.
   *
   * If the @a parameters Variant is floating, it is consumed. This allows
   * convenient 'inline' use of Glib::variant_new(), e.g.:
   *
   * [C example ellipted]
   *
   * If @a proxy has an expected interface (see
   * Gio::DBus::Proxy::property_g_interface_info()) and @a method_name is referenced by it,
   * then the return value is checked against the return type.
   *
   * This is an asynchronous method. When the operation is finished,
   *  @a slot will be invoked in the
   * [thread-default main context][g-main-context-push-thread-default]
   * of the thread you are calling this method from.
   * You can then call g_dbus_proxy_call_finish() to get the result of
   * the operation. See g_dbus_proxy_call_sync() for the synchronous
   * version of this method.
   *
   * If @a slot is <tt>nullptr</tt> then the D-Bus method call message will be sent with
   * the Gio::DBus::MessageFlags::NO_REPLY_EXPECTED flag set.
   *
   * @newin{2,26}
   *
   * @param method_name Name of method to invoke.
   * @param parameters A Variant tuple with parameters for the signal or <tt>nullptr</tt> if not passing parameters.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param timeout_msec The timeout in milliseconds (with G_MAXINT meaning
   * "infinite") or -1 to use the proxy default timeout.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied. Use another overload
   * without this parameter if your don't care about the result of the method invocation.
   */
  void call(const Glib::ustring& method_name, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);

  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const SlotAsyncReady& slot, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);

  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const Glib::RefPtr<Cancellable>& cancellable, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);

  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);


  /** Finishes an operation started with call().
   *
   * @param res An AsyncResult obtained from the SlotAsyncReady passed to
   * call().
   * @result A Variant tuple with return values.
   *
   * @throw Glib::Error.
   */
  auto call_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::VariantContainerBase;


  /** Synchronously invokes the @a method_name method on @a proxy.
   *
   * If @a method_name contains any dots, then @a name is split into interface and
   * method name parts. This allows using @a proxy for invoking methods on
   * other interfaces.
   *
   * If the Gio::DBus::Connection associated with @a proxy is disconnected then
   * the operation will fail with Gio::Error::CLOSED. If
   *  @a cancellable is canceled, the operation will fail with
   * Gio::Error::CANCELLED. If @a parameters contains a value not
   * compatible with the D-Bus protocol, the operation fails with
   * Gio::Error::INVALID_ARGUMENT.
   *
   * If the @a parameters Variant is floating, it is consumed. This allows
   * convenient 'inline' use of Glib::variant_new(), e.g.:
   *
   * [C example ellipted]
   *
   * The calling thread is blocked until a reply is received. See
   * g_dbus_proxy_call() for the asynchronous version of this
   * method.
   *
   * If @a proxy has an expected interface (see
   * Gio::DBus::Proxy::property_g_interface_info()) and @a method_name is referenced by it,
   * then the return value is checked against the return type.
   *
   * @newin{2,26}
   *
   * @param method_name Name of method to invoke.
   * @param parameters A Variant tuple with parameters for the signal
   * or <tt>nullptr</tt> if not passing parameters.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param timeout_msec The timeout in milliseconds (with G_MAXINT meaning
   * "infinite") or -1 to use the proxy default timeout.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return <tt>nullptr</tt> if @a error is set. Otherwise a Variant tuple with
   * return values. Free with Glib::variant_unref().
   *
   * @throws Glib::Error
   */
  auto call_sync(const Glib::ustring& method_name, const Glib::RefPtr<Cancellable>& cancellable, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE) -> Glib::VariantContainerBase;

  /// A call_sync() convenience overload.
  auto call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE) -> Glib::VariantContainerBase;


#ifdef  G_OS_UNIX

  /** Like g_dbus_proxy_call() but also takes a UnixFDList object.
   *
   * This method is only available on UNIX.
   *
   * @newin{2,30}
   *
   * @param method_name Name of method to invoke.
   * @param parameters A Variant tuple with parameters for the signal or <tt>nullptr</tt> if not passing parameters.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param timeout_msec The timeout in milliseconds (with G_MAXINT meaning
   * "infinite") or -1 to use the proxy default timeout.
   * @param fd_list A UnixFDList or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied. Use another overload
   * without this parameter if your don't care about the result of the method invocation.
   */
  void call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);
#endif //  G_OS_UNIX

#ifdef  G_OS_UNIX


  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const SlotAsyncReady& slot, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);
#endif //  G_OS_UNIX

#ifdef  G_OS_UNIX


  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);
#endif //  G_OS_UNIX

#ifdef  G_OS_UNIX


  /// A call() convenience overload.
  void call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE);
#endif //  G_OS_UNIX


#ifdef  G_OS_UNIX

  /** Finishes an operation started with call() (with a UnixFDList).
   * @param res A AsyncResult obtained from the SlotAsyncReady passed to
   * call().
   * @param out_fd_list Return location for a UnixFDList.
   * @result A Variant tuple with return values.
   * @throw Glib::Error.
   * @newin{2,34}
   */
  auto call_finish(const Glib::RefPtr<AsyncResult>& res, Glib::RefPtr<UnixFDList>& out_fd_list) -> Glib::VariantContainerBase;
#endif //  G_OS_UNIX


#ifdef  G_OS_UNIX

  /** Like g_dbus_proxy_call_sync() but also takes and returns UnixFDList objects.
   *
   * This method is only available on UNIX.
   *
   * @newin{2,30}
   *
   * @param method_name Name of method to invoke.
   * @param parameters A Variant tuple with parameters for the signal
   * or <tt>nullptr</tt> if not passing parameters.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param timeout_msec The timeout in milliseconds (with G_MAXINT meaning
   * "infinite") or -1 to use the proxy default timeout.
   * @param fd_list A UnixFDList or <tt>nullptr</tt>.
   * @param out_fd_list Return location for a UnixFDList or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return <tt>nullptr</tt> if @a error is set. Otherwise a Variant tuple with
   * return values. Free with Glib::variant_unref().
   *
   * @throws Glib::Error
   */
  auto call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE) -> Glib::VariantContainerBase;
#endif //  G_OS_UNIX

#ifdef  G_OS_UNIX


  /// A call_sync() convenience overload.
  auto call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE) -> Glib::VariantContainerBase;
#endif //  G_OS_UNIX


 //_WRAP_PROPERTY("g-bus-type", BusType) // write-only construct-only
 /** The Gio::DBus::Connection the proxy is for.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >;


 /** The timeout to use if -1 (specifying default timeout) is passed
   * as @a timeout_msec in the g_dbus_proxy_call() and
   * g_dbus_proxy_call_sync() functions.
   *
   * This allows applications to set a proxy-wide timeout for all
   * remote method invocations on the proxy. If this property is -1,
   * the default timeout (typically 25 seconds) is used. If set to
   * G_MAXINT, then no timeout is used.
   *
   * @newin{2,26}
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_default_timeout() -> Glib::PropertyProxy< int > ;

/** The timeout to use if -1 (specifying default timeout) is passed
   * as @a timeout_msec in the g_dbus_proxy_call() and
   * g_dbus_proxy_call_sync() functions.
   *
   * This allows applications to set a proxy-wide timeout for all
   * remote method invocations on the proxy. If this property is -1,
   * the default timeout (typically 25 seconds) is used. If set to
   * G_MAXINT, then no timeout is used.
   *
   * @newin{2,26}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_default_timeout() const -> Glib::PropertyProxy_ReadOnly< int >;

 /** Flags from the Gio::DBus::ProxyFlags enumeration.
   *
   * @newin{2,26}
   *
   * Default value: Gio::DBus::ProxyFlags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_flags() const -> Glib::PropertyProxy_ReadOnly< ProxyFlags >;


 /** Ensure that interactions with this proxy conform to the given
   * interface. This is mainly to ensure that malformed data received
   * from the other peer is ignored. The given Gio::DBus::InterfaceInfo is
   * said to be the "expected interface".
   *
   * The checks performed are:
   * - When completing a method call, if the type signature of
   * the reply message isn't what's expected, the reply is
   * discarded and the Error is set to Gio::Error::INVALID_ARGUMENT.
   *
   * - Received signals that have a type signature mismatch are dropped and
   * a warning is logged via Glib::warning().
   *
   * - Properties received via the initial `GetAll()` call or via the
   * `::PropertiesChanged` signal (on the
   * [org.freedesktop.DBus.Properties](http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-properties)
   * interface) or set using g_dbus_proxy_set_cached_property()
   * with a type signature mismatch are ignored and a warning is
   * logged via Glib::warning().
   *
   * Note that these checks are never done on methods, signals and
   * properties that are not referenced in the given
   * Gio::DBus::InterfaceInfo, since extending a D-Bus interface on the
   * service-side is not considered an ABI break.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_interface_info() -> Glib::PropertyProxy< Glib::RefPtr<InterfaceInfo> > ;

/** Ensure that interactions with this proxy conform to the given
   * interface. This is mainly to ensure that malformed data received
   * from the other peer is ignored. The given Gio::DBus::InterfaceInfo is
   * said to be the "expected interface".
   *
   * The checks performed are:
   * - When completing a method call, if the type signature of
   * the reply message isn't what's expected, the reply is
   * discarded and the Error is set to Gio::Error::INVALID_ARGUMENT.
   *
   * - Received signals that have a type signature mismatch are dropped and
   * a warning is logged via Glib::warning().
   *
   * - Properties received via the initial `GetAll()` call or via the
   * `::PropertiesChanged` signal (on the
   * [org.freedesktop.DBus.Properties](http://dbus.freedesktop.org/doc/dbus-specification.html#standard-interfaces-properties)
   * interface) or set using g_dbus_proxy_set_cached_property()
   * with a type signature mismatch are ignored and a warning is
   * logged via Glib::warning().
   *
   * Note that these checks are never done on methods, signals and
   * properties that are not referenced in the given
   * Gio::DBus::InterfaceInfo, since extending a D-Bus interface on the
   * service-side is not considered an ABI break.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_interface_info() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InterfaceInfo> >;

 /** The D-Bus interface name the proxy is for.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_interface_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 /** The well-known or unique name that the proxy is for.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 /** The unique name that owns Gio::DBus::Proxy::property_g_name() or <tt>nullptr</tt> if no-one
   * currently owns that name. You may connect to Object::signal_notify() signal to
   * track changes to this property.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_name_owner() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


 /** The object path the proxy is for.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_g_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  using MapChangedProperties = std::map<Glib::ustring, Glib::VariantBase>;

  // TODO: Should the signal names match the C API names (ie. the C API names
  // are g_signal_name while these are just signal_name).

  // The DBus API ensures that the variant changed_properties is of type "DICT<STRING,VARIANT>"


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%properties_changed(const MapChangedProperties& changed_properties, const std::vector<Glib::ustring>& invalidated_properties)</tt>
   *
   * Flags: Run Last, Must Collect
   *
   * Emitted when one or more D-Bus properties on @a proxy changes. The
   * local cache has already been updated when this signal fires. Note
   * that both @a changed_properties and @a invalidated_properties are
   * guaranteed to never be <tt>nullptr</tt> (either may be empty though).
   *
   * If the proxy has the flag
   * Gio::DBus::ProxyFlags::GET_INVALIDATED_PROPERTIES set, then
   *  @a invalidated_properties will always be empty.
   *
   * This signal corresponds to the
   * `PropertiesChanged` D-Bus signal on the
   * `org.freedesktop.DBus.Properties` interface.
   *
   * @newin{2,26}
   *
   * @param changed_properties A Variant containing the properties that changed (type: `a{sv}`).
   * @param invalidated_properties A <tt>nullptr</tt> terminated array of properties that was invalidated.
   */

  auto signal_properties_changed() -> Glib::SignalProxy<void(const MapChangedProperties&, const std::vector<Glib::ustring>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%signal(const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters)</tt>
   *
   * Flags: Run Last, Must Collect
   *
   * Emitted when a signal from the remote object and interface that @a proxy is for, has been received.
   *
   * Since 2.72 this signal supports detailed connections. You can connect to
   * the detailed signal `g-signal::x` in order to receive callbacks only when
   * signal `x` is received from the remote object.
   *
   * @newin{2,26}
   *
   * @param sender_name The sender of the signal or <tt>nullptr</tt> if the connection is not a bus connection.
   * @param signal_name The name of the signal.
   * @param parameters A Variant tuple with parameters for the signal.
   */

  auto signal_signal() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>;

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%signal(const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters)</tt>
   *
   * Flags: Run Last, Must Collect
   *
   * Emitted when a signal from the remote object and interface that @a proxy is for, has been received.
   *
   * Since 2.72 this signal supports detailed connections. You can connect to
   * the detailed signal `g-signal::x` in order to receive callbacks only when
   * signal `x` is received from the remote object.
   *
   * @newin{2,26}
   *
   * @param sender_name The sender of the signal or <tt>nullptr</tt> if the connection is not a bus connection.
   * @param signal_name The name of the signal.
   * @param parameters A Variant tuple with parameters for the signal.
   */

  auto signal_signal(const Glib::ustring& signal_name) -> Glib::SignalProxyDetailed<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_properties_changed().
  virtual void on_properties_changed(const MapChangedProperties& changed_properties, const std::vector<Glib::ustring>& invalidated_properties);
  /// This is a default handler for the signal signal_signal().
  virtual void on_signal(const Glib::ustring& sender_name, const Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters);


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
   * @relates Gio::DBus::Proxy
   */
  GIOMM_API
  auto wrap(GDBusProxy* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Proxy>;
}


#endif /* _GIOMM_DBUSPROXY_H */

