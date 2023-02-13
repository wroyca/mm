
#ifndef _GIOMM_DBUSCONNECTION_H
#define _GIOMM_DBUSCONNECTION_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/initable.hpp>
#include <libmm-gio/asyncinitable.hpp>
#include <libmm-gio/dbusauthobserver.hpp>
#include <libmm-gio/dbusmethodinvocation.hpp>
#include <libmm-gio/dbusintrospection.hpp>
#include <libmm-gio/iostream.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/credentials.hpp>
#include <libmm-gio/dbusmessage.hpp>
#include <libmm-gio/dbussubtreevtable.hpp>
#include <gio/gio.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusConnection = struct _GDBusConnection;
using GDBusConnectionClass = struct _GDBusConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API Connection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API ActionGroup;
class GIOMM_API MenuModel;
class GIOMM_API UnixFDList;


namespace DBus
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var BusType STARTER
 * An alias for the message bus that activated the process, if any.
 *
 *  @var BusType NONE
 * Not a message bus.
 *
 *  @var BusType SYSTEM
 * The system-wide message bus.
 *
 *  @var BusType SESSION
 * The login session message bus.
 *
 *  @enum BusType
 *
 * An enumeration for well-known message buses.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 */
enum class BusType
{
  STARTER = -1,
  NONE,
  SYSTEM,
  SESSION
};


} // namespace DBus

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::BusType> : public Glib::Value_Enum<Gio::DBus::BusType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio::DBus
{

/**
 *  @var CallFlags NONE
 * No flags set.
 *
 *  @var CallFlags NO_AUTO_START
 * The bus must not launch
 * an owner for the destination name in response to this method
 * invocation.
 *
 *  @var CallFlags ALLOW_INTERACTIVE_AUTHORIZATION
 * The caller is prepared to
 * wait for interactive authorization. @newin{2,46}
 *
 *  @enum CallFlags
 *
 * Flags used in g_dbus_connection_call() and similar APIs.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>CallFlags operator|(CallFlags, CallFlags)</tt><br>
 * <tt>CallFlags operator&(CallFlags, CallFlags)</tt><br>
 * <tt>CallFlags operator^(CallFlags, CallFlags)</tt><br>
 * <tt>CallFlags operator~(CallFlags)</tt><br>
 * <tt>CallFlags& operator|=(CallFlags&, CallFlags)</tt><br>
 * <tt>CallFlags& operator&=(CallFlags&, CallFlags)</tt><br>
 * <tt>CallFlags& operator^=(CallFlags&, CallFlags)</tt><br>
 */
enum class CallFlags
{
  NONE = 0x0,
  NO_AUTO_START = (1<<0),
  ALLOW_INTERACTIVE_AUTHORIZATION = (1<<1)
};

/** @ingroup giommEnums */
inline auto operator|(CallFlags lhs, CallFlags rhs) -> CallFlags
  { return static_cast<CallFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(CallFlags lhs, CallFlags rhs) -> CallFlags
  { return static_cast<CallFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(CallFlags lhs, CallFlags rhs) -> CallFlags
  { return static_cast<CallFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(CallFlags flags) -> CallFlags
  { return static_cast<CallFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(CallFlags& lhs, CallFlags rhs) -> CallFlags&
  { return (lhs = static_cast<CallFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(CallFlags& lhs, CallFlags rhs) -> CallFlags&
  { return (lhs = static_cast<CallFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(CallFlags& lhs, CallFlags rhs) -> CallFlags&
  { return (lhs = static_cast<CallFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var ConnectionFlags NONE
 * No flags set.
 *
 *  @var ConnectionFlags AUTHENTICATION_CLIENT
 * Perform authentication against server.
 *
 *  @var ConnectionFlags AUTHENTICATION_SERVER
 * Perform authentication against client.
 *
 *  @var ConnectionFlags AUTHENTICATION_ALLOW_ANONYMOUS
 * When
 * authenticating as a server, allow the anonymous authentication
 * method.
 *
 *  @var ConnectionFlags MESSAGE_BUS_CONNECTION
 * Pass this flag if connecting to a peer that is a
 * message bus. This means that the Hello() method will be invoked as part of the connection setup.
 *
 *  @var ConnectionFlags DELAY_MESSAGE_PROCESSING
 * If set, processing of D-Bus messages is
 * delayed until g_dbus_connection_start_message_processing() is called.
 *
 *  @var ConnectionFlags AUTHENTICATION_REQUIRE_SAME_USER
 * When authenticating
 * as a server, require the UID of the peer to be the same as the UID of the server. (Since: 2.68).
 *
 *  @var ConnectionFlags CROSS_NAMESPACE
 * When authenticating, try to use
 * protocols that work across a Linux user namespace boundary, even if this
 * reduces interoperability with older D-Bus implementations. This currently
 * affects client-side `EXTERNAL` authentication, for which this flag makes
 * connections to a server in another user namespace succeed, but causes
 * a deadlock when connecting to a GDBus server older than 2.73.3. @newin{2,74}
 *
 *  @enum ConnectionFlags
 *
 * Flags used when creating a new Gio::DBus::Connection.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>ConnectionFlags operator|(ConnectionFlags, ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags operator&(ConnectionFlags, ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags operator^(ConnectionFlags, ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags operator~(ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags& operator|=(ConnectionFlags&, ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags& operator&=(ConnectionFlags&, ConnectionFlags)</tt><br>
 * <tt>ConnectionFlags& operator^=(ConnectionFlags&, ConnectionFlags)</tt><br>
 */
enum class ConnectionFlags
{
  NONE = 0x0,
  AUTHENTICATION_CLIENT = (1<<0),
  AUTHENTICATION_SERVER = (1<<1),
  AUTHENTICATION_ALLOW_ANONYMOUS = (1<<2),
  MESSAGE_BUS_CONNECTION = (1<<3),
  DELAY_MESSAGE_PROCESSING = (1<<4),
  AUTHENTICATION_REQUIRE_SAME_USER = (1<<5),
  CROSS_NAMESPACE = (1<<6)
};

/** @ingroup giommEnums */
inline auto operator|(ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  { return static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  { return static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(ConnectionFlags lhs, ConnectionFlags rhs) -> ConnectionFlags
  { return static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(ConnectionFlags flags) -> ConnectionFlags
  { return static_cast<ConnectionFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  { return (lhs = static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  { return (lhs = static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(ConnectionFlags& lhs, ConnectionFlags rhs) -> ConnectionFlags&
  { return (lhs = static_cast<ConnectionFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::ConnectionFlags> : public Glib::Value_Flags<Gio::DBus::ConnectionFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio::DBus
{

/**
 *  @var SendMessageFlags NONE
 * No flags set.
 *
 *  @var SendMessageFlags PRESERVE_SERIAL
 * Do not automatically
 * assign a serial number from the Gio::DBus::Connection object when
 * sending a message.
 *
 *  @enum SendMessageFlags
 *
 * Flags used when sending DBusMessages on a Gio::DBus::Connection.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>SendMessageFlags operator|(SendMessageFlags, SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags operator&(SendMessageFlags, SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags operator^(SendMessageFlags, SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags operator~(SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags& operator|=(SendMessageFlags&, SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags& operator&=(SendMessageFlags&, SendMessageFlags)</tt><br>
 * <tt>SendMessageFlags& operator^=(SendMessageFlags&, SendMessageFlags)</tt><br>
 */
enum class SendMessageFlags
{
  NONE = 0x0,
  PRESERVE_SERIAL = (1<<0)
};

/** @ingroup giommEnums */
inline auto operator|(SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  { return static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  { return static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(SendMessageFlags lhs, SendMessageFlags rhs) -> SendMessageFlags
  { return static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(SendMessageFlags flags) -> SendMessageFlags
  { return static_cast<SendMessageFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  { return (lhs = static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  { return (lhs = static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(SendMessageFlags& lhs, SendMessageFlags rhs) -> SendMessageFlags&
  { return (lhs = static_cast<SendMessageFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var SignalFlags NONE
 * No flags set.
 *
 *  @var SignalFlags NO_MATCH_RULE
 * Don't actually send the AddMatch
 * D-Bus call for this signal subscription.  This gives you more control
 * over which match rules you add (but you must add them manually).
 *
 *  @var SignalFlags MATCH_ARG0_NAMESPACE
 * Match first arguments that
 * contain a bus or interface name with the given namespace.
 *
 *  @var SignalFlags MATCH_ARG0_PATH
 * Match first arguments that
 * contain an object path that is either equivalent to the given path,
 * or one of the paths is a subpath of the other.
 *
 *  @enum SignalFlags
 *
 * Flags used when subscribing to signals via g_dbus_connection_signal_subscribe().
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>SignalFlags operator|(SignalFlags, SignalFlags)</tt><br>
 * <tt>SignalFlags operator&(SignalFlags, SignalFlags)</tt><br>
 * <tt>SignalFlags operator^(SignalFlags, SignalFlags)</tt><br>
 * <tt>SignalFlags operator~(SignalFlags)</tt><br>
 * <tt>SignalFlags& operator|=(SignalFlags&, SignalFlags)</tt><br>
 * <tt>SignalFlags& operator&=(SignalFlags&, SignalFlags)</tt><br>
 * <tt>SignalFlags& operator^=(SignalFlags&, SignalFlags)</tt><br>
 */
enum class SignalFlags
{
  NONE = 0x0,
  NO_MATCH_RULE = (1<<0),
  MATCH_ARG0_NAMESPACE = (1<<1),
  MATCH_ARG0_PATH = (1<<2)
};

/** @ingroup giommEnums */
inline auto operator|(SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  { return static_cast<SignalFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  { return static_cast<SignalFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(SignalFlags lhs, SignalFlags rhs) -> SignalFlags
  { return static_cast<SignalFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(SignalFlags flags) -> SignalFlags
  { return static_cast<SignalFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  { return (lhs = static_cast<SignalFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  { return (lhs = static_cast<SignalFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(SignalFlags& lhs, SignalFlags rhs) -> SignalFlags&
  { return (lhs = static_cast<SignalFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 *  @var SubtreeFlags NONE
 * No flags set.
 *
 *  @var SubtreeFlags DISPATCH_TO_UNENUMERATED_NODES
 * Method calls to objects not in the enumerated range
 * will still be dispatched. This is useful if you want
 * to dynamically spawn objects in the subtree.
 *
 *  @enum SubtreeFlags
 *
 * Flags passed to g_dbus_connection_register_subtree().
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>SubtreeFlags operator|(SubtreeFlags, SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags operator&(SubtreeFlags, SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags operator^(SubtreeFlags, SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags operator~(SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags& operator|=(SubtreeFlags&, SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags& operator&=(SubtreeFlags&, SubtreeFlags)</tt><br>
 * <tt>SubtreeFlags& operator^=(SubtreeFlags&, SubtreeFlags)</tt><br>
 */
enum class SubtreeFlags
{
  NONE = 0x0,
  DISPATCH_TO_UNENUMERATED_NODES = (1<<0)
};

/** @ingroup giommEnums */
inline auto operator|(SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  { return static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  { return static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(SubtreeFlags lhs, SubtreeFlags rhs) -> SubtreeFlags
  { return static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(SubtreeFlags flags) -> SubtreeFlags
  { return static_cast<SubtreeFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  { return (lhs = static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  { return (lhs = static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(SubtreeFlags& lhs, SubtreeFlags rhs) -> SubtreeFlags&
  { return (lhs = static_cast<SubtreeFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** @defgroup DBus D-Bus API
 *
 * API to use D-Bus services as a client or to implement a D-Bus service.
 * To write client code, see Gio::DBus::Proxy.
 * To export objects on the bus for other clients, see Gio::DBus::own_name(), for instance.
 */

//TODO: Add example from C API in class docs.
/** A D-Bus Connection.
 * The Connection type is used for D-Bus connections to remote peers such
 * as a message buses. It is a low-level API that offers a lot of flexibility.
 * For instance, it lets you establish a connection over any transport that
 * can by represented as an IOStream.
 *
 * This class is rarely used directly in D-Bus clients. If you are writing a
 * D-Bus client, it is often easier to use the Gio::DBus::own_name(),
 * Gio::DBus::watch_name() or Gio::DBus::Proxy::create_for_bus() APIs.
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class GIOMM_API Connection
: public Glib::Object, public Initable, public AsyncInitable
{
protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Connection;
  using CppClassType = Connection_Class;
  using BaseObjectType = GDBusConnection;
  using BaseClassType = GDBusConnectionClass;

  // noncopyable
  Connection(const Connection&) = delete;
  auto operator=(const Connection&) -> Connection& = delete;

private:  friend class Connection_Class;
  static CppClassType connection_class_;

protected:
  explicit Connection(const Glib::ConstructParams& construct_params);
  explicit Connection(GDBusConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Connection(Connection&& src) noexcept;
  auto operator=(Connection&& src) noexcept -> Connection&;

  ~Connection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusConnection*       { return reinterpret_cast<GDBusConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusConnection* { return reinterpret_cast<GDBusConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusConnection*;

private:


protected:

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const SlotAsyncReady& slot,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    ConnectionFlags flags);

  Connection(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const SlotAsyncReady& slot,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags);

  Connection(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    ConnectionFlags flags);

  Connection(const std::string& address,
    ConnectionFlags flags);

public:

  /** Signature for slot used in signal_subscribe().
   *  For example,
   * @code
   * void on_signal(const Glib::RefPtr<Connection>& connection, const
   * Glib::ustring& sender_name, const Glib::ustring& object_path, const
   * Glib::ustring& object_path, const Glib::ustring& interface_name, const
   * Glib::ustring& signal_name, const Glib::VariantContainerBase& parameters);.
   * @endcode
   */
  using SlotSignal = sigc::slot<void(const Glib::RefPtr<Connection>&,
    const Glib::ustring&, const Glib::ustring&, const Glib::ustring&,
    const Glib::ustring&, const Glib::VariantContainerBase&)>;

  /** Signature for slot used in add_filter().
   *  For example,
   * @code
   * Glib::RefPtr<Message> on_message_filter(const
   * Glib::RefPtr<Connection> connection, const Glib::RefPtr<Message>&
   * message, bool incoming);.
   * @endcode
   *
   * A filter function is passed a Message and expected to return a
   * Message too. Passive filter functions that don't modify the message
   * can simply return the message object.  Filter functions that wants to
   * drop a message can simply return <tt>0</tt>.  And filter function may
   * modify a message by copying it and return the copy.
   */
  using SlotMessageFilter = sigc::slot<Glib::RefPtr<Message>(
    const Glib::RefPtr<Connection>&,
    const Glib::RefPtr<Message>&, bool)>;

  /** Asynchronously connects to the message bus specified by @a bus_type.
   *
   * When the operation is finished, @a slot will be invoked. You can then
   * call get_finish() to get the result of the operation.
   *
   * This is a asynchronous failable function. See get_sync() for the
   * synchronous version.
   *
   * @param bus_type A BusType.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   *
   * @newin{2,28}
   */
  static void get(BusType bus_type, const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable);


  /** Non-cancellable version of get().
   */
  static void get(BusType bus_type, const SlotAsyncReady& slot);


  /** Finishes an operation started with g_bus_get().
   *
   * The returned object is a singleton, that is, shared with other
   * callers of g_bus_get() and g_bus_get_sync() for @a bus_type. In the
   * event that you need a private message bus connection, use
   * g_dbus_address_get_for_bus_sync() and
   * g_dbus_connection_new_for_address() with
   * G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT and
   * G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION flags.
   *
   * Note that the returned Gio::DBus::Connection object will (usually) have
   * the Gio::DBus::Connection::property_exit_on_close() property set to <tt>true</tt>.
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady passed
   * to g_bus_get().
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  static auto get_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>;


  /** Synchronously connects to the message bus specified by @a bus_type.
   * Note that the returned object may shared with other callers,
   * e.g. if two separate parts of a process calls this function with
   * the same @a bus_type, they will share the same object.
   *
   * This is a synchronous failable function. See g_bus_get() and
   * g_bus_get_finish() for the asynchronous version.
   *
   * The returned object is a singleton, that is, shared with other
   * callers of g_bus_get() and g_bus_get_sync() for @a bus_type. In the
   * event that you need a private message bus connection, use
   * g_dbus_address_get_for_bus_sync() and
   * g_dbus_connection_new_for_address() with
   * G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT and
   * G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION flags.
   *
   * Note that the returned Gio::DBus::Connection object will (usually) have
   * the Gio::DBus::Connection::property_exit_on_close() property set to <tt>true</tt>.
   *
   * @newin{2,26}
   *
   * @param bus_type A BusType.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  static auto get_sync(BusType bus_type, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Connection>;

  /// A get_sync() convenience overload.
  static auto get_sync(BusType bus_type) -> Glib::RefPtr<Connection>;


  /** Asynchronously sets up a D-Bus connection for exchanging D-Bus messages
   * with the end represented by @a stream.
   *
   * If @a stream is a SocketConnection, then the corresponding Socket
   * will be put into non-blocking mode.
   *
   * The D-Bus connection will interact with @a stream from a worker thread.
   * As a result, the caller should not interact with @a stream after this
   * method has been called, except by calling Glib::object_unref() on it.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * When the operation is finished, @a slot will be invoked. You can
   * then call g_dbus_connection_new_finish() to get the result of the
   * operation.
   *
   * This is an asynchronous failable constructor. See
   * g_dbus_connection_new_sync() for the synchronous
   * version.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream.
   * @param guid The GUID to use if authenticating as a server or <tt>nullptr</tt>.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param user_data The data to pass to @a slot.
   */

  static void create(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);


  /** Asynchronously sets up a D-Bus connection for exchanging D-Bus messages
   * with the end represented by @a stream.
   *
   * If @a stream is a SocketConnection, then the corresponding Socket
   * will be put into non-blocking mode.
   *
   * The D-Bus connection will interact with @a stream from a worker thread.
   * As a result, the caller should not interact with @a stream after this
   * method has been called, except by calling Glib::object_unref() on it.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * When the operation is finished, @a slot will be invoked. You can
   * then call g_dbus_connection_new_finish() to get the result of the
   * operation.
   *
   * This is an asynchronous failable constructor. See
   * g_dbus_connection_new_sync() for the synchronous
   * version.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream.
   * @param guid The GUID to use if authenticating as a server or <tt>nullptr</tt>.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param user_data The data to pass to @a slot.
   */

  static void create(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

  /// Non-cancellable version of create().
  static void create(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

  /// Non-cancellable version of create().
  static void create(const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const SlotAsyncReady& slot,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);


  /** Finishes an operation started with g_dbus_connection_new().
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady
   * passed to g_dbus_connection_new().
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set. Free
   * with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  static auto create_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>;


  /** Asynchronously connects and sets up a D-Bus client connection for
   * exchanging D-Bus messages with an endpoint specified by @a address
   * which must be in the
   * [D-Bus address format](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses).
   *
   * This constructor can only be used to initiate client-side
   * connections - use g_dbus_connection_new() if you need to act as the
   * server. In particular, @a flags cannot contain the
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER,
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_ALLOW_ANONYMOUS or
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_REQUIRE_SAME_USER flags.
   *
   * When the operation is finished, @a slot will be invoked. You can
   * then call g_dbus_connection_new_for_address_finish() to get the result of
   * the operation.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * This is an asynchronous failable constructor. See
   * g_dbus_connection_new_for_address_sync() for the synchronous
   * version.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param user_data The data to pass to @a slot.
   */

  static void create_for_address(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);


  /** Asynchronously connects and sets up a D-Bus client connection for
   * exchanging D-Bus messages with an endpoint specified by @a address
   * which must be in the
   * [D-Bus address format](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses).
   *
   * This constructor can only be used to initiate client-side
   * connections - use g_dbus_connection_new() if you need to act as the
   * server. In particular, @a flags cannot contain the
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER,
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_ALLOW_ANONYMOUS or
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_REQUIRE_SAME_USER flags.
   *
   * When the operation is finished, @a slot will be invoked. You can
   * then call g_dbus_connection_new_for_address_finish() to get the result of
   * the operation.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * This is an asynchronous failable constructor. See
   * g_dbus_connection_new_for_address_sync() for the synchronous
   * version.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param user_data The data to pass to @a slot.
   */

  static void create_for_address(const std::string& address,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

  /// Non-cancellable version of create_for_address().
  static void create_for_address(const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const SlotAsyncReady& slot,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);

  /// Non-cancellable version of create_for_address().
  static void create_for_address(const std::string& address,
    const SlotAsyncReady& slot,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE);


  /** Finishes an operation started with g_dbus_connection_new_for_address().
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady passed
   * to g_dbus_connection_new().
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  static auto create_for_address_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Connection>;


  /** Synchronously sets up a D-Bus connection for exchanging D-Bus messages
   * with the end represented by @a stream.
   *
   * If @a stream is a SocketConnection, then the corresponding Socket
   * will be put into non-blocking mode.
   *
   * The D-Bus connection will interact with @a stream from a worker thread.
   * As a result, the caller should not interact with @a stream after this
   * method has been called, except by calling Glib::object_unref() on it.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * This is a synchronous failable constructor. See
   * g_dbus_connection_new() for the asynchronous version.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream.
   * @param guid The GUID to use if authenticating as a server or <tt>nullptr</tt>.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */

  static auto create_sync(
    const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;


  /** Synchronously sets up a D-Bus connection for exchanging D-Bus messages
   * with the end represented by @a stream.
   *
   * If @a stream is a SocketConnection, then the corresponding Socket
   * will be put into non-blocking mode.
   *
   * The D-Bus connection will interact with @a stream from a worker thread.
   * As a result, the caller should not interact with @a stream after this
   * method has been called, except by calling Glib::object_unref() on it.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * This is a synchronous failable constructor. See
   * g_dbus_connection_new() for the asynchronous version.
   *
   * @newin{2,26}
   *
   * @param stream A IOStream.
   * @param guid The GUID to use if authenticating as a server or <tt>nullptr</tt>.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */

  static auto create_sync(
    const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;

  /// Non-cancellable version of create_sync().
  static auto create_sync(
    const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;

  /// Non-cancellable version of create_sync().
  static auto create_sync(
    const Glib::RefPtr<IOStream>& stream,
    const std::string& guid,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;


  /** Synchronously connects and sets up a D-Bus client connection for
   * exchanging D-Bus messages with an endpoint specified by @a address
   * which must be in the
   * [D-Bus address format](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses).
   *
   * This constructor can only be used to initiate client-side
   * connections - use g_dbus_connection_new_sync() if you need to act
   * as the server. In particular, @a flags cannot contain the
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER,
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_ALLOW_ANONYMOUS or
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_REQUIRE_SAME_USER flags.
   *
   * This is a synchronous failable constructor. See
   * g_dbus_connection_new_for_address() for the asynchronous version.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */

  static auto create_for_address_sync(
    const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;


  /** Synchronously connects and sets up a D-Bus client connection for
   * exchanging D-Bus messages with an endpoint specified by @a address
   * which must be in the
   * [D-Bus address format](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses).
   *
   * This constructor can only be used to initiate client-side
   * connections - use g_dbus_connection_new_sync() if you need to act
   * as the server. In particular, @a flags cannot contain the
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER,
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_ALLOW_ANONYMOUS or
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_REQUIRE_SAME_USER flags.
   *
   * This is a synchronous failable constructor. See
   * g_dbus_connection_new_for_address() for the asynchronous version.
   *
   * If @a observer is not <tt>nullptr</tt> it may be used to control the
   * authentication process.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags describing how to make the connection.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Connection or <tt>nullptr</tt> if @a error is set.
   * Free with Glib::object_unref().
   *
   * @throws Glib::Error
   */

  static auto create_for_address_sync(
    const std::string& address,
    const Glib::RefPtr<Cancellable>& cancellable,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;

  /// Non-cancellable version of create_for_address_sync().
  static auto create_for_address_sync(
    const std::string& address,
    const Glib::RefPtr<AuthObserver>& observer,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;

  /// Non-cancellable version of create_for_address_sync().
  static auto create_for_address_sync(
    const std::string& address,
    ConnectionFlags flags = Gio::DBus::ConnectionFlags::NONE) -> Glib::RefPtr<Connection>;

  /** Closes the connection. Note that this never causes the process to exit
   * (this might only happen if the other end of a shared message bus
   * connection disconnects, see property_exit_on_close()).
   *
   * Once the connection is closed, operations such as sending a message will
   * return with the error Gio::IO_ERROR_CLOSED. Closing a connection will not
   * automatically flush the connection so queued messages may be lost. Use
   * flush() if you need such guarantees.
   *
   * If the connection is already closed, this method fails with
   * Gio::IO_ERROR_CLOSED.
   *
   * When the connection has been closed, the "closed" signal is emitted in
   * the thread-default main loop of the thread that connection was
   * constructed in.
   *
   * This is an asynchronous method.  See close_sync() for the synchronous
   * version.
   *
   * @newin{2,28}
   */
  void close();

  /** Closes the connection. Note that this never causes the process to exit
   * (this might only happen if the other end of a shared message bus
   * connection disconnects, see property_exit_on_close()).
   *
   * Once the connection is closed, operations such as sending a message will
   * return with the error Gio::IO_ERROR_CLOSED. Closing a connection will not
   * automatically flush the connection so queued messages may be lost. Use
   * flush() if you need such guarantees.
   *
   * If the connection is already closed, this method fails with
   * Gio::IO_ERROR_CLOSED.
   *
   * When the connection has been closed, the "closed" signal is emitted in
   * the thread-default main loop of the thread that connection was
   * constructed in.
   *
   * This is an asynchronous method. When the operation is finished, @a slot
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call close_finish() to get the
   * result of the operation. See close_sync() for the synchronous version.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   *
   * @newin{2,28}
   */
  void close(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Closes the connection. Note that this never causes the process to exit
   * (this might only happen if the other end of a shared message bus
   * connection disconnects, see property_exit_on_close()).
   *
   * Once the connection is closed, operations such as sending a message will
   * return with the error Gio::IO_ERROR_CLOSED. Closing a connection will not
   * automatically flush the connection so queued messages may be lost. Use
   * flush() if you need such guarantees.
   *
   * If the connection is already closed, this method fails with
   * Gio::IO_ERROR_CLOSED.
   *
   * When the connection has been closed, the "closed" signal is emitted in
   * the thread-default main loop of the thread that connection was
   * constructed in.
   *
   * This is an asynchronous method. When the operation is finished, @a slot
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call close_finish() to get the
   * result of the operation. See close_sync() for the synchronous version.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   *
   * @newin{2,28}
   */
  void close(const SlotAsyncReady& slot);


  /** Finishes an operation started with g_dbus_connection_close().
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady passed
   * to g_dbus_connection_close().
   * @return <tt>true</tt> if the operation succeeded, <tt>false</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto close_finish(const Glib::RefPtr<AsyncResult>& res) -> bool;


  /** Synchronously closes @a connection. The calling thread is blocked
   * until this is done. See g_dbus_connection_close() for the
   * asynchronous version of this method and more details about what it
   * does.
   *
   * @newin{2,26}
   *
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   *
   * @throws Glib::Error
   */
  void close_sync(const Glib::RefPtr<Cancellable>& cancellable);

  /// A close_sync() convenience overload.
  void close_sync();

  /** Asynchronously flushes the connection, that is, writes all queued
   * outgoing message to the transport and then flushes the transport (using
   * Gio::OutputStream::flush_async()). This is useful in programs that wants
   * to emit a D-Bus signal and then exit immediately. Without flushing the
   * connection, there is no guarantee that the message has been sent to the
   * networking buffers in the OS kernel.
   *
   * This is an asynchronous method. See flush_sync() for the synchronous
   * version.
   *
   * @newin{2,28}
   */
  void flush();

  /** Asynchronously flushes the connection, that is, writes all queued
   * outgoing message to the transport and then flushes the transport (using
   * Gio::OutputStream::flush_async()). This is useful in programs that wants
   * to emit a D-Bus signal and then exit immediately. Without flushing the
   * connection, there is no guarantee that the message has been sent to the
   * networking buffers in the OS kernel.
   *
   * This is an asynchronous method. When the operation is finished, @a slot
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call flush_finish() to get the
   * result of the operation. See flush_sync() for the synchronous version.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   *
   * @newin{2,28}
   */
  void flush(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Asynchronously flushes the connection, that is, writes all queued
   * outgoing message to the transport and then flushes the transport (using
   * Gio::OutputStream::flush_async()). This is useful in programs that wants
   * to emit a D-Bus signal and then exit immediately. Without flushing the
   * connection, there is no guarantee that the message has been sent to the
   * networking buffers in the OS kernel.
   *
   * This is an asynchronous method. When the operation is finished, @a slot
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call flush_finish() to get the
   * result of the operation. See flush_sync() for the synchronous version.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   *
   * @newin{2,28}
   */
  void flush(const SlotAsyncReady& slot);


  /** Finishes an operation started with g_dbus_connection_flush().
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady passed
   * to g_dbus_connection_flush().
   * @return <tt>true</tt> if the operation succeeded, <tt>false</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto flush_finish(const Glib::RefPtr<AsyncResult>& res) -> bool;


  /** Synchronously flushes @a connection. The calling thread is blocked
   * until this is done. See g_dbus_connection_flush() for the
   * asynchronous version of this method and more details about what it
   * does.
   *
   * @newin{2,26}
   *
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   *
   * @throws Glib::Error
   */
  void flush_sync(const Glib::RefPtr<Cancellable>& cancellable);

  /// A flush_sync() convenience overload.
  void flush_sync();


  /** Gets whether the process is terminated when @a connection is
   * closed by the remote peer. See
   * Gio::DBus::Connection::property_exit_on_close() for more details.
   *
   * @newin{2,26}
   *
   * @return Whether the process is terminated when @a connection is
   * closed by the remote peer.
   */
  auto get_exit_on_close() const -> bool;

  /** Sets whether the process should be terminated when @a connection is
   * closed by the remote peer. See Gio::DBus::Connection::property_exit_on_close() for
   * more details.
   *
   * Note that this function should be used with care. Most modern UNIX
   * desktops tie the notion of a user session with the session bus, and expect
   * all of a user's applications to quit when their bus connection goes away.
   * If you are setting @a exit_on_close to <tt>false</tt> for the shared session
   * bus connection, you should make sure that your application exits
   * when the user session ends.
   *
   * @newin{2,26}
   *
   * @param exit_on_close Whether the process should be terminated
   * when @a connection is closed by the remote peer.
   */
  void set_exit_on_close(bool exit_on_close =  true);

  //TODO: In the C API, out_serial is volatile, but gmmproc can't parse that.


  /** Asynchronously sends @a message to the peer represented by @a connection.
   *
   * Unless @a flags contain the
   * Gio::DBus::SendMessageFlags::PRESERVE_SERIAL flag, the serial number
   * will be assigned by @a connection and set on @a message via
   * g_dbus_message_set_serial(). If @a out_serial is not <tt>nullptr</tt>, then the
   * serial number used will be written to this location prior to
   * submitting the message to the underlying transport. While it has a `volatile`
   * qualifier, this is a historical artifact and the argument passed to it should
   * not be `volatile`.
   *
   * If @a connection is closed then the operation will fail with
   * Gio::Error::CLOSED. If @a message is not well-formed,
   * the operation fails with Gio::Error::INVALID_ARGUMENT.
   *
   * See this [server][gdbus-server] and [client][gdbus-unix-fd-client]
   * for an example of how to use this low-level API to send and receive
   * UNIX file descriptors.
   *
   * Note that @a message must be unlocked, unless @a flags contain the
   * Gio::DBus::SendMessageFlags::PRESERVE_SERIAL flag.
   *
   * @newin{2,26}
   *
   * @param message A Gio::DBus::Message.
   * @param flags Flags affecting how the message is sent.
   * @param out_serial Return location for serial number assigned
   * to @a message when sending it or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the message was well-formed and queued for
   * transmission, <tt>false</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto send_message(const Glib::RefPtr<Message>& message, SendMessageFlags flags, guint32& out_serial) -> bool;

  /// A send_message() without an "out_serial" parameter.
  auto send_message(const Glib::RefPtr<Message>& message,
    SendMessageFlags flags = Gio::DBus::SendMessageFlags::NONE) -> bool;

  /** Asynchronously sends message to the peer represented by the connection.
   *
   * Unless flags contain the Gio::DBus::SendMessageFlags::PRESERVE_SERIAL
   * flag, the serial number will be assigned by the connection and set on
   * message via Gio::DBus::Message::set_serial().
   *
   * If the connection is closed then the operation will fail with
   * Gio::IO_ERROR_CLOSED. If @a cancellable is canceled, the operation will
   * fail with Gio::IO_ERROR_CANCELLED. If @a message is not well-formed, the
   * operation fails with Gio::IO_ERROR_INVALID_ARGUMENT.
   *
   * This is an asynchronous method. When the operation is finished, @a slot
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call
   * send_message_with_reply_finish() to get the result of the operation. See
   * send_message_with_reply_sync() for the synchronous version.
   *
   * Note that message must be unlocked, unless flags contain the
   * Gio::DBus::SendMessageFlags::PRESERVE_SERIAL flag.
   *
   * See the C API docs for examples.
   *
   * @param message A Message.
   * @param timeout_msec The timeout in milliseconds or -1 to use the default
   * timeout.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   *
   * @newin{2,28}
   */
  void send_message_with_reply(const Glib::RefPtr<Message>& message,
    int timeout_msec,
    const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable);


  /** Non-cancellable version of send_message_with_reply().
   */
  void send_message_with_reply(const Glib::RefPtr<Message>& message,
    int timeout_msec,
    const SlotAsyncReady& slot);


  /** Finishes an operation started with g_dbus_connection_send_message_with_reply().
   *
   * Note that @a error is only set if a local in-process error
   * occurred. That is to say that the returned Gio::DBus::Message object may
   * be of type Gio::DBus::MessageType::ERROR. Use
   * g_dbus_message_to_gerror() to transcode this to a Error.
   *
   * See this [server][gdbus-server] and [client][gdbus-unix-fd-client]
   * for an example of how to use this low-level API to send and receive
   * UNIX file descriptors.
   *
   * @newin{2,26}
   *
   * @param res A AsyncResult obtained from the SlotAsyncReady passed to
   * g_dbus_connection_send_message_with_reply().
   * @return A locked Gio::DBus::Message or <tt>nullptr</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto send_message_with_reply_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Message>;

  /** Synchronously sends @a message to the peer represented by the connection
   * and blocks the calling thread until a reply is received or the timeout is
   * reached. See send_message_with_reply() for the asynchronous version of
   * this method.
   *
   * Unless flags contain the Gio::DBus::SendMessageFlags::PRESERVE_SERIAL
   * flag, the serial number will be assigned by the connection and set on
   * message via Gio::DBus::Message::set_serial().
   *
   * If the connection is closed then the operation will fail with
   * Gio::IO_ERROR_CLOSED. If @a cancellable is canceled, the operation will
   * fail with Gio::IO_ERROR_CANCELLED. If @a message is not well-formed, the
   * operation fails with Gio::IO_ERROR_INVALID_ARGUMENT.
   *
   * Note that a Glib::Error is thrown if a local in-process error occured.
   * That is to say that the returned Message object may be of type
   * G_DBUS_MESSAGE_TYPE_ERROR. Use Gio::DBus::Message::to_exception() to
   * transcode this to a Glib::Error.
   *
   * See the C API docs for examples.
   *
   * Note that message must be unlocked, unless flags contain the
   * Gio::DBus::SendMessageFlags::PRESERVE_SERIAL flag.
   *
   * @param message A Message.
   * @param cancellable A Cancellable.
   * @param timeout_msec The timeout in milliseconds or -1 to use the default
   * timeout.
   * @return A locked Message that is the reply to @a message or
   * <tt>0</tt> if a Glib::Error is thrown.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  auto send_message_with_reply_sync(
    const Glib::RefPtr<Message>& message,
    const Glib::RefPtr<Cancellable>& cancellable,
    gint timeout_msec) -> Glib::RefPtr<Message>;


  /// A non-cancellable version of send_message_with_reply_sync().
  auto send_message_with_reply_sync(
    const Glib::RefPtr<Message>& message,
    gint timeout_msec) -> Glib::RefPtr<Message>;


  /** If @a connection was created with
   * Gio::DBus::ConnectionFlags::DELAY_MESSAGE_PROCESSING, this method
   * starts processing messages. Does nothing on if @a connection wasn't
   * created with this flag or if the method has already been called.
   *
   * @newin{2,26}
   */
  void start_message_processing();

  /** Gets whether @a connection is closed.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if the connection is closed, <tt>false</tt> otherwise.
   */
  auto is_closed() const -> bool;


  /** Gets the underlying stream used for IO.
   *
   * While the Gio::DBus::Connection is active, it will interact with this
   * stream from a worker thread, so it is not safe to interact with
   * the stream directly.
   *
   * @newin{2,26}
   *
   * @return The stream used for IO.
   */
  auto get_stream() -> Glib::RefPtr<IOStream>;

  /** Gets the underlying stream used for IO.
   *
   * While the Gio::DBus::Connection is active, it will interact with this
   * stream from a worker thread, so it is not safe to interact with
   * the stream directly.
   *
   * @newin{2,26}
   *
   * @return The stream used for IO.
   */
  auto get_stream() const -> Glib::RefPtr<const IOStream>;


  /** The GUID of the peer performing the role of server when
   * authenticating. See Gio::DBus::Connection::property_guid() for more details.
   *
   * @newin{2,26}
   *
   * @return The GUID. Do not free this string, it is owned by
   *  @a connection.
   */
  auto get_guid() const -> std::string;

  /** Gets the unique name of @a connection as assigned by the message
   * bus. This can also be used to figure out if @a connection is a
   * message bus connection.
   *
   * @newin{2,26}
   *
   * @return The unique name or <tt>nullptr</tt> if @a connection is not a message
   * bus connection. Do not free this string, it is owned by
   *  @a connection.
   */
  auto get_unique_name() const -> Glib::ustring;


  /** Gets the capabilities negotiated with the remote peer
   *
   * @newin{2,26}
   *
   * @return Zero or more flags from the DBusCapabilityFlags enumeration.
   */
  auto get_capabilities() const -> CapabilityFlags;

  /** Gets the flags used to construct this connection
   *
   * @newin{2,60}
   *
   * @return Zero or more flags from the DBusConnectionFlags enumeration.
   */
  auto get_flags() const -> ConnectionFlags;


  /** Gets the credentials of the authenticated peer. This will always
   * return <tt>nullptr</tt> unless @a connection acted as a server
   * (e.g. Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER was passed)
   * when set up and the client passed credentials as part of the
   * authentication process.
   *
   * In a message bus setup, the message bus is always the server and
   * each application is a client. So this method will always return
   * <tt>nullptr</tt> for message bus clients.
   *
   * @newin{2,26}
   *
   * @return A Credentials or <tt>nullptr</tt> if not
   * available. Do not free this object, it is owned by @a connection.
   */
  auto get_peer_credentials() -> Glib::RefPtr<Credentials>;

  /** Gets the credentials of the authenticated peer. This will always
   * return <tt>nullptr</tt> unless @a connection acted as a server
   * (e.g. Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER was passed)
   * when set up and the client passed credentials as part of the
   * authentication process.
   *
   * In a message bus setup, the message bus is always the server and
   * each application is a client. So this method will always return
   * <tt>nullptr</tt> for message bus clients.
   *
   * @newin{2,26}
   *
   * @return A Credentials or <tt>nullptr</tt> if not
   * available. Do not free this object, it is owned by @a connection.
   */
  auto get_peer_credentials() const -> Glib::RefPtr<const Credentials>;


  /** Retrieves the last serial number assigned to a Gio::DBus::Message on
   * the current thread. This includes messages sent via both low-level
   * API such as g_dbus_connection_send_message() as well as
   * high-level API such as g_dbus_connection_emit_signal(),
   * g_dbus_connection_call() or g_dbus_proxy_call().
   *
   * @newin{2,34}
   *
   * @return The last used serial or zero when no message has been sent
   * within the current thread.
   */
  auto get_last_serial() const -> guint32;

  /** Asynchronously invokes the @a method_name method on the @a
   * interface_name D-Bus interface on the remote object at @a object_path
   * owned by @a bus_name.
   *
   * If the connection is closed then the operation will fail with
   * Gio::IO_ERROR_CLOSED. If @a cancellable is cancelled, the operation will
   * fail with Gio::IO_ERROR_CANCELLED. If @a parameters contains a value not
   * compatible with the D-Bus protocol, the operation fails with
   * Gio::IO_ERROR_INVALID_ARGUMENT.
   *
   * If @a reply_type is non-<tt>0</tt> then the reply will be checked for
   * having this type and an error will be raised if it does not match. Said
   * another way, if you give a @a reply_type then any non-<tt>0</tt> return
   * value will be of this type.
   *
   * This is an asynchronous method. When the operation is finished, callback
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call call_finish() to get the
   * result of the operation.  See call_sync() for the synchronous version of
   * this function.
   *
   * @param object_path Path of remote object.
   * @param interface_name D-Bus interface to invoke method on.
   * @param method_name The name of the method to invoke.
   * @param parameters A Glib::VariantContainerBase tuple with parameters for the
   * method or <tt>0</tt> if not passing parameters.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   * @param bus_name A unique or well-known bus name or an empty string if the
   * connection is not a message bus connection.
   * @param timeout_msec The timeout in milliseconds, -1 to use the default
   * timeout or G_MAXINT for no timeout.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param reply_type The expected type of the reply, or <tt>0</tt>.
   * @newin{2,28}
   */
  void call(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const SlotAsyncReady&               slot,
    const Glib::RefPtr<Cancellable>&    cancellable,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {});


  /// A non-cancellable version of call().
  void call(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const SlotAsyncReady&               slot,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {});


  /** Finishes an operation started with call().
   * @param res A AsyncResult obtained from the SlotAsyncReady passed to
   * call().
   * @result A Variant tuple with return values.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  auto call_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::VariantContainerBase;

  /** Synchronously invokes the @a method_name method on the @a interface_name
   * D-Bus interface on the remote object at @a object_path owned by @a
   * bus_name.
   *
   * If the connection is closed then the operation will fail with
   * Gio::IO_ERROR_CLOSED. If @a cancellable is cancelled, the operation will
   * fail with Gio::IO_ERROR_CANCELLED. If @a parameters contains a value not
   * compatible with the D-Bus protocol, the operation fails with
   * Gio::IO_ERROR_INVALID_ARGUMENT.
   *
   * If @a reply_type is non-<tt>0</tt> then the reply will be checked for
   * having this type and an error will be raised if it does not match. Said
   * another way, if you give a @a reply_type then any non-<tt>0</tt> return
   * value will be of this type.
   *
   * The calling thread is blocked until a reply is received. See call() for
   * the asynchronous version of this method.
   *
   * @param object_path Path of remote object.
   * @param interface_name D-Bus interface to invoke method on.
   * @param method_name The name of the method to invoke.
   * @param parameters A Glib::VariantContainerBase tuple with parameters for the
   * method or <tt>0</tt> if not passing parameters.
   * @param cancellable A Cancellable.
   * @param bus_name A unique or well-known bus name or an empty string if the
   * connection is not a message bus connection.
   * @param timeout_msec The timeout in milliseconds, -1 to use the default
   * timeout or G_MAXINT for no timeout.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param reply_type The expected type of the reply, or <tt>0</tt>.
   * @result A Variant tuple with return values.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  auto call_sync(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const Glib::RefPtr<Cancellable>&    cancellable,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {}) -> Glib::VariantContainerBase;


  /// A non-cancellable version of call_sync().
  auto call_sync(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {}) -> Glib::VariantContainerBase;

#ifdef G_OS_UNIX
  /** Like call() but also takes a GUnixFDList object.
   * This method is only available on UNIX.
   *
   * This is an asynchronous method. When the operation is finished, callback
   * will be invoked in the thread-default main loop of the thread you are
   * calling this method from. You can then call call_with_unix_fd_finish() to
   * get the result of the operation. See call_sync() for the synchronous
   * version of this function.
   *
   * @param object_path Path of remote object.
   * @param interface_name D-Bus interface to invoke method on.
   * @param method_name The name of the method to invoke.
   * @param parameters A Glib::VariantContainerBase tuple with parameters for the
   * method or <tt>0</tt> if not passing parameters.
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable.
   * @param fd_list A UnixFDList.
   * @param bus_name A unique or well-known bus name or an empty string if the
   * connection is not a message bus connection.
   * @param timeout_msec The timeout in milliseconds, -1 to use the default
   * timeout or G_MAXINT for no timeout.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param reply_type The expected type of the reply, or <tt>0</tt>.
   * @newin{2,34}
   */
  void call(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const SlotAsyncReady&               slot,
    const Glib::RefPtr<Cancellable>&    cancellable,
    const Glib::RefPtr<UnixFDList>&     fd_list,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {});


  /** A non-cancellable version of call() (with a UnixFDList).
   * @newin{2,34}
   */
  void call(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                method_name,
    const Glib::VariantContainerBase&   parameters,
    const SlotAsyncReady&               slot,
    const Glib::RefPtr<UnixFDList>&     fd_list,
    const Glib::ustring&                bus_name = {},
    int                                 timeout_msec = -1,
    CallFlags                           flags = Gio::DBus::CallFlags::NONE,
    const Glib::VariantType&            reply_type = {});
#endif // G_OS_UNIX


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

  /** Like g_dbus_connection_call_sync() but also takes and returns UnixFDList objects.
   * See g_dbus_connection_call_with_unix_fd_list() and
   * g_dbus_connection_call_with_unix_fd_list_finish() for more details.
   *
   * This method is only available on UNIX.
   *
   * @newin{2,30}
   *
   * @param bus_name A unique or well-known bus name or <tt>nullptr</tt>
   * if @a connection is not a message bus connection.
   * @param object_path Path of remote object.
   * @param interface_name D-Bus interface to invoke method on.
   * @param method_name The name of the method to invoke.
   * @param parameters A Variant tuple with parameters for
   * the method or <tt>nullptr</tt> if not passing parameters.
   * @param reply_type The expected type of the reply, or <tt>nullptr</tt>.
   * @param flags Flags from the Gio::DBus::CallFlags enumeration.
   * @param timeout_msec The timeout in milliseconds, -1 to use the default
   * timeout or G_MAXINT for no timeout.
   * @param fd_list A UnixFDList or <tt>nullptr</tt>.
   * @param out_fd_list Return location for a UnixFDList or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return <tt>nullptr</tt> if @a error is set. Otherwise a non-floating
   * Variant tuple with return values. Free with Glib::variant_unref().
   *
   * @throws Glib::Error
   */
  auto call_sync(const Glib::ustring& object_path, const Glib::ustring& interface_name, const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, const Glib::ustring& bus_name =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE, const Glib::VariantType& reply_type =  {}) -> Glib::VariantContainerBase;
#endif //  G_OS_UNIX

#ifdef  G_OS_UNIX


  /// A call_sync() convenience overload.
  auto call_sync(const Glib::ustring& object_path, const Glib::ustring& interface_name, const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, const Glib::ustring& bus_name =  {}, int timeout_msec =  -1, CallFlags flags =  Gio::DBus::CallFlags::NONE, const Glib::VariantType& reply_type =  {}) -> Glib::VariantContainerBase;
#endif //  G_OS_UNIX


  /** Emits a signal.
   *
   * This can only fail if @a parameters is not compatible with the D-Bus
   * protocol.
   *
   * @param object_path Path of remote object.
   * @param interface_name D-Bus interface to emit a signal on.
   * @param signal_name The name of the signal to emit.
   * @param destination_bus_name The unique bus name for the destination for
   * the signal or an empty string to emit to all listeners.
   * @param parameters A Glib::VariantContainerBase tuple with parameters for the
   * signal or <tt>0</tt> if not passing parameters.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  void emit_signal(
    const Glib::ustring&                object_path,
    const Glib::ustring&                interface_name,
    const Glib::ustring&                signal_name,
    const Glib::ustring&                destination_bus_name = {},
    const Glib::VariantContainerBase&   parameters = {});


  /** Subscribes to signals on the connection and invokes @a slot with a
   * whenever the signal is received. Note that @a slot will be invoked in the
   * thread-default main loop of the thread you are calling this method from.
   *
   * If the connection is not a message bus connection, @a sender must be
   * <tt>0</tt>.
   *
   * If @a sender is a well-known name note that @a slot is invoked with the
   * unique name for the owner of @a sender, not the well-known name as one
   * would expect. This is because the message bus rewrites the name. As such,
   * to avoid certain race conditions, users should be tracking the name owner
   * of the well-known name and use that when processing the received signal.
   *
   * @param slot Slot to invoke when there is a signal matching the requested
   * data.
   * @param sender Sender name to match on (unique or well-known name) or
   * <tt>0</tt> to listen from all senders.
   * @param interface_name D-Bus interface name to match on or <tt>0</tt> to
   * match on all interfaces.
   * @param member D-Bus signal name to match on or <tt>0</tt> to match on all
   * signals.
   * @param object_path Object path to match on or <tt>0</tt> to match on all
   * object paths.
   * @param arg0 Contents of first string argument to match on or <tt>0</tt>
   * to match on all kinds of arguments.
   * @param flags Flags describing how to subscribe to the signal (currently
   * unused).
   * @return A subscription identifier that can be used with
   * signal_unsubscribe().
   * @newin{2,28}
   */
  auto signal_subscribe(
    const SlotSignal& slot,
    const Glib::ustring& sender = {},
    const Glib::ustring& interface_name = {},
    const Glib::ustring& member = {},
    const Glib::ustring& object_path = {},
    const Glib::ustring& arg0 = {},
    SignalFlags flags = Gio::DBus::SignalFlags::NONE) -> guint;


  /** Unsubscribes from signals.
   *
   * Note that there may still be D-Bus traffic to process (relating to this
   * signal subscription) in the current thread-default MainContext after this
   * function has returned. You should continue to iterate the MainContext
   * until the DestroyNotify function passed to
   * g_dbus_connection_signal_subscribe() is called, in order to avoid memory
   * leaks through callbacks queued on the MainContext after it’s stopped being
   * iterated.
   * Alternatively, any idle source with a priority lower than G_PRIORITY_DEFAULT
   * that was scheduled after unsubscription, also indicates that all resources
   * of this subscription are released.
   *
   * @newin{2,26}
   *
   * @param subscription_id A subscription id obtained from
   * g_dbus_connection_signal_subscribe().
   */
  void signal_unsubscribe(guint subscription_id);

  /** Adds a message filter. Filters are handlers that are run on all incoming
   * and outgoing messages, prior to standard dispatch. Filters are run in the
   * order that they were added. The same handler can be added as a filter
   * more than once, in which case it will be run more than once. Filters
   * added during a filter slot won't be run on the message being processed.
   * Filter slots are allowed to modify and even drop messages.
   *
   * Note that filters are run in a dedicated message handling thread so they
   * can't block and, generally, can't do anything but signal a worker thread.
   * Also note that filters are rarely needed - use API such as
   * send_message_with_reply(), signal_subscribe() or call() instead.
   *
   * If a filter consumes an incoming message the message is not dispatched
   * anywhere else - not even the standard dispatch machinery (that API such
   * as signal_subscribe() and send_message_with_reply() relies on) will see
   * the message. Similary, if a filter consumes an outgoing message, the
   * message will not be sent to the other peer.
   *
   * @param slot A filter slot.
   * @return A filter identifier that can be used with remove_filter().
   * @newin{2,28}
   */
  auto add_filter(const SlotMessageFilter& slot) -> guint;


  /** Removes a filter.
   *
   * Note that since filters run in a different thread, there is a race
   * condition where it is possible that the filter will be running even
   * after calling g_dbus_connection_remove_filter(), so you cannot just
   * free data that the filter might be using. Instead, you should pass
   * a DestroyNotify to g_dbus_connection_add_filter(), which will be
   * called when it is guaranteed that the data is no longer needed.
   *
   * @newin{2,26}
   *
   * @param filter_id An identifier obtained from g_dbus_connection_add_filter().
   */
  void remove_filter(guint filter_id);

  /** Registers slots for exported objects at @a object_path with the D-Bus
   * interface that is described in @a interface_info.
   *
   * Calls to slots in @a vtable will happen in the thread-default main loop
   * of the thread you are calling this method from.
   *
   * Note that all Glib::VariantBase values passed to functions in @a vtable
   * will match the signature given in @a interface_info - if a remote caller
   * passes incorrect values, the @c org.freedesktop.DBus.Error.InvalidArgs is
   * returned to the remote caller.
   *
   * Additionally, if the remote caller attempts to invoke methods or access
   * properties not mentioned in @a interface_info the
   * @c org.freedesktop.DBus.Error.UnknownMethod resp.
   * @c org.freedesktop.DBus.Error.InvalidArgs errors are returned to the
   * caller.
   *
   * It is considered a programming error if the SlotDBusInterfaceGetProperty
   * slot in @a vtable returns a Glib::VariantBase of incorrect type.
   *
   * If an existing slot is already registered at @a object_path and @a
   * interface_name, then a Glib::Error is thrown.
   *
   * GDBus automatically implements the standard D-Bus interfaces
   * org.freedesktop.DBus.Properties, org.freedesktop.DBus.Introspectable and
   * org.freedesktop.Peer, so you don't have to implement those for the
   * objects you export. You can implement org.freedesktop.DBus.Properties
   * yourself, e.g. to handle getting and setting of properties
   * asynchronously.
   *
   * @param object_path The object path to register at.
   * @param interface_info Introspection data for the interface.
   * @param vtable An InterfaceVTable to call into.
   * @return A registration id (never 0) that can be used with
   * unregister_object() if no Glib::Error is thrown.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  auto register_object(const Glib::ustring& object_path,
    const Glib::RefPtr<InterfaceInfo>& interface_info,
    const InterfaceVTable& vtable) -> guint;


  /** Registers exported objects at @a object_path with the D-Bus
   * interface that is described in @a interface_info. This method overload,
   * which does not take a VTable, is useful for
   * <a href="http://en.wikipedia.org/wiki/Marker_interface_pattern">marker
   * interfaces</a>.
   *
   * If an existing slot is already registered at @a object_path and @a
   * interface_name, then a Glib::Error is thrown.
   *
   * GDBus automatically implements the standard D-Bus interfaces
   * org.freedesktop.DBus.Properties, org.freedesktop.DBus.Introspectable and
   * org.freedesktop.Peer, so you don't have to implement those for the
   * objects you export.
   *
   * @param object_path The object path to register at.
   * @param interface_info Introspection data for the interface.
   * @return A registration id (never 0) that can be used with
   * unregister_object() if no Glib::Error is thrown.
   * @throw Glib::Error.
   * @newin{2,28}
   */
  auto register_object(const Glib::ustring& object_path,
    const Glib::RefPtr<InterfaceInfo>& interface_info) -> guint;


  /** Unregisters an object.
   *
   * @newin{2,26}
   *
   * @param registration_id A registration id obtained from
   * g_dbus_connection_register_object().
   * @return <tt>true</tt> if the object was unregistered, <tt>false</tt> otherwise.
   */
  auto unregister_object(guint registration_id) -> bool;

  /** Registers a whole subtree of “dynamic” objects.
   *
   * Copies of the enumerate and introspection slots usted to create @a vtable
   * are used to convey, to remote callers, what nodes exist in the subtree
   * rooted by @a object_path.
   *
   * When handling remote calls into any node in the subtree, first the
   * enumerate slot is used to check if the node exists. If the node
   * exists or the Gio::DBus::SubtreeFlags::DISPATCH_TO_UNENUMERATED_NODES flag
   * is set the introspection slot is used to check if the node supports the
   * requested method. If so, the dispatch function is used to determine where
   * to dispatch the call. The collected InterfaceVTable will be used to
   * call into the interface vtable for processing the request.
   *
   * All calls into user-provided code will be invoked in the thread-default
   * main loop of the thread you are calling this method from.
   *
   * If an existing subtree is already registered at @a object_path or then
   * a Glib::Error is thrown.
   *
   * Note that it is valid to register regular objects (using
   * register_object()) in a subtree registered with register_subtree() - if
   * so, the subtree handler is tried as the last resort. One way to think
   * about a subtree handler is to consider it a “fallback handler” for object
   * paths not registered via register_object().
   *
   *
   * @param object_path The object path to register the subtree at.
   * @param vtable A SubtreeVTable to enumerate, introspect and dispatch
   * nodes in the subtree.
   * @param flags Flags used to fine tune the behavior of the subtree.
   * @return A subtree registration id (never 0) that can be used with
   * unregister_subtree() if no Glib::Error is thrown.
   *
   * @newin{2,28}
   */
  auto register_subtree(const Glib::ustring& object_path,
    const SubtreeVTable& vtable,
    SubtreeFlags flags = Gio::DBus::SubtreeFlags::NONE) -> guint;


  /** Unregisters a subtree.
   *
   * @newin{2,26}
   *
   * @param registration_id A subtree registration id obtained from
   * g_dbus_connection_register_subtree().
   * @return <tt>true</tt> if the subtree was unregistered, <tt>false</tt> otherwise.
   */
  auto unregister_subtree(guint registration_id) -> bool;


  /** Exports @a action_group on @a connection at @a object_path.
   *
   * The implemented D-Bus API should be considered private.  It is
   * subject to change in the future.
   *
   * A given object path can only have one action group exported on it.
   * If this constraint is violated, the export will fail and 0 will be
   * returned (with @a error set accordingly).
   *
   * You can unexport the action group using
   * g_dbus_connection_unexport_action_group() with the return value of
   * this function.
   *
   * The thread default main context is taken at the time of this call.
   * All incoming action activations and state change requests are
   * reported from this context.  Any changes on the action group that
   * cause it to emit signals must also come from this same context.
   * Since incoming action activations and state change requests are
   * rather likely to cause changes on the action group, this effectively
   * limits a given action group to being exported from only one main
   * context.
   *
   * @newin{2,32}
   *
   * @param object_path A D-Bus object path.
   * @param action_group A ActionGroup.
   * @return The ID of the export (never zero), or 0 in case of failure.
   *
   * @throws Glib::Error
   */
  auto export_action_group(const Glib::ustring& object_path, const Glib::RefPtr<ActionGroup>& action_group) -> guint;

  /** Reverses the effect of a previous call to
   * g_dbus_connection_export_action_group().
   *
   * It is an error to call this function with an ID that wasn't returned
   * from g_dbus_connection_export_action_group() or to call it with the
   * same ID more than once.
   *
   * @newin{2,32}
   *
   * @param export_id The ID from g_dbus_connection_export_action_group().
   */
  void unexport_action_group(guint export_id);


  /** Exports @a menu on @a connection at @a object_path.
   *
   * The implemented D-Bus API should be considered private.
   * It is subject to change in the future.
   *
   * An object path can only have one menu model exported on it. If this
   * constraint is violated, the export will fail and 0 will be
   * returned (with @a error set accordingly).
   *
   * You can unexport the menu model using
   * g_dbus_connection_unexport_menu_model() with the return value of
   * this function.
   *
   * @newin{2,32}
   *
   * @param object_path A D-Bus object path.
   * @param menu A MenuModel.
   * @return The ID of the export (never zero), or 0 in case of failure.
   *
   * @throws Glib::Error
   */
  auto export_menu_model(const Glib::ustring& object_path, const Glib::RefPtr<MenuModel>& menu) -> guint;

  /** Reverses the effect of a previous call to
   * g_dbus_connection_export_menu_model().
   *
   * It is an error to call this function with an ID that wasn't returned
   * from g_dbus_connection_export_menu_model() or to call it with the
   * same ID more than once.
   *
   * @newin{2,32}
   *
   * @param export_id The ID from g_dbus_connection_export_menu_model().
   */
  void unexport_menu_model(guint export_id);

  //_WRAP_PROPERTY("address", std::string) // write-only construct-only
  //_WRAP_PROPERTY("authentication-observer", Glib::RefPtr<AuthObserver>) // write-only construct-only
  /** Flags from the DBusCapabilityFlags enumeration
   * representing connection features negotiated with the other peer.
   *
   * @newin{2,26}
   *
   * Default value: Gio::DBus::CapabilityFlags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_capabilities() const -> Glib::PropertyProxy_ReadOnly< CapabilityFlags >;


  /** A boolean specifying whether the connection has been closed.
   *
   * @newin{2,26}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_closed() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** A boolean specifying whether the process will be terminated (by
   * calling `raise(SIGTERM)`) if the connection is closed by the
   * remote peer.
   *
   * Note that Gio::DBus::Connection objects returned by g_bus_get_finish()
   * and g_bus_get_sync() will (usually) have this property set to <tt>true</tt>.
   *
   * @newin{2,26}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_exit_on_close() -> Glib::PropertyProxy< bool > ;

/** A boolean specifying whether the process will be terminated (by
   * calling `raise(SIGTERM)`) if the connection is closed by the
   * remote peer.
   *
   * Note that Gio::DBus::Connection objects returned by g_bus_get_finish()
   * and g_bus_get_sync() will (usually) have this property set to <tt>true</tt>.
   *
   * @newin{2,26}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_exit_on_close() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Flags from the DBusConnectionFlags enumeration.
   *
   * @newin{2,60}
   *
   * Default value: Gio::DBus::ConnectionFlags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< ConnectionFlags >;


  /** The GUID of the peer performing the role of server when
   * authenticating.
   *
   * If you are constructing a Gio::DBus::Connection and pass
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_SERVER in the
   * Gio::DBus::Connection::property_flags() property then you **must** also set this
   * property to a valid guid.
   *
   * If you are constructing a Gio::DBus::Connection and pass
   * Gio::DBus::ConnectionFlags::AUTHENTICATION_CLIENT in the
   * Gio::DBus::Connection::property_flags() property you will be able to read the GUID
   * of the other peer here after the connection has been successfully
   * initialized.
   *
   * Note that the
   * [D-Bus specification](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses)
   * uses the term ‘UUID’ to refer to this, whereas GLib consistently uses the
   * term ‘GUID’ for historical reasons.
   *
   * Despite its name, the format of Gio::DBus::Connection::property_guid() does not follow
   * [RFC 4122](https://datatracker.ietf.org/doc/html/rfc4122) or the Microsoft
   * GUID format.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_guid() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /** The underlying IOStream used for I/O.
   *
   * If this is passed on construction and is a SocketConnection,
   * then the corresponding Socket will be put into non-blocking mode.
   *
   * While the Gio::DBus::Connection is active, it will interact with this
   * stream from a worker thread, so it is not safe to interact with
   * the stream directly.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<IOStream> >;


  /** The unique name as assigned by the message bus or <tt>nullptr</tt> if the
   * connection is not open or not a message bus connection.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_unique_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%closed(bool remote_peer_vanished, const Glib::Error& error)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the connection is closed.
   *
   * The cause of this event can be
   *
   * - If g_dbus_connection_close() is called. In this case
   *  @a remote_peer_vanished is set to <tt>false</tt> and @a error is <tt>nullptr</tt>.
   *
   * - If the remote peer closes the connection. In this case
   *  @a remote_peer_vanished is set to <tt>true</tt> and @a error is set.
   *
   * - If the remote peer sends invalid or malformed data. In this
   * case @a remote_peer_vanished is set to <tt>false</tt> and @a error is set.
   *
   * Upon receiving this signal, you should give up your reference to
   *  @a connection. You are guaranteed that this signal is emitted only
   * once.
   *
   * @newin{2,26}
   *
   * @param remote_peer_vanished <tt>true</tt> if @a connection is closed because the
   * remote peer closed its end of the connection.
   * @param error A Error with more details about the event or <tt>nullptr</tt>.
   */

  auto signal_closed() -> Glib::SignalProxy<void(bool, const Glib::Error&)>;


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
   * @relates Gio::DBus::Connection
   */
  GIOMM_API
  auto wrap(GDBusConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Connection>;
}


#endif /* _GIOMM_DBUSCONNECTION_H */

