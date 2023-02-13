
#ifndef _GIOMM_DBUSSERVER_H
#define _GIOMM_DBUSSERVER_H


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
#include <libmm-gio/dbusconnection.hpp>
#include <libmm-gio/dbusauthobserver.hpp>
#include <libmm-gio/initable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusServer = struct _GDBusServer;
using GDBusServerClass = struct _GDBusServerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{ class GIOMM_API Server_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio::DBus
{


//TODO: Add example from the C API in class docs.
/** This is a helper for listening to and accepting D-Bus connections.
 * Since Server derives from Initiable, its constructors can
 * throw an exception if construction fails.
 *
 * This can be used to create a new D-Bus server, allowing two
 * peers to use the D-Bus protocol for their own specialized communication.
 * A server instance provided in this way will not perform message routing or
 * implement the org.freedesktop.DBus interface.
 *
 * To just export an object on a well-known name on a message bus, such as the
 * session or system bus, you should instead use Gio::DBus::own_name().
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class GIOMM_API Server : public Glib::Object, public Initable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Server;
  using CppClassType = Server_Class;
  using BaseObjectType = GDBusServer;
  using BaseClassType = GDBusServerClass;

  // noncopyable
  Server(const Server&) = delete;
  auto operator=(const Server&) -> Server& = delete;

private:  friend class Server_Class;
  static CppClassType server_class_;

protected:
  explicit Server(const Glib::ConstructParams& construct_params);
  explicit Server(GDBusServer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Server(Server&& src) noexcept;
  auto operator=(Server&& src) noexcept -> Server&;

  ~Server() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDBusServer*       { return reinterpret_cast<GDBusServer*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDBusServer* { return reinterpret_cast<GDBusServer*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDBusServer*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags set.
   *
   *  @var Flags RUN_IN_THREAD
   * All Gio::DBus::Server::signal_new_connection()
   * signals will run in separated dedicated threads (see signal for
   * details).
   *
   *  @var Flags AUTHENTICATION_ALLOW_ANONYMOUS
   * Allow the anonymous
   * authentication method.
   *
   *  @var Flags AUTHENTICATION_REQUIRE_SAME_USER
   * Require the UID of the
   * peer to be the same as the UID of the server when authenticating. (Since: 2.68).
   *
   *  @enum Flags
   *
   * Flags used when creating a Gio::DBus::Server.
   *
   * @newin{2,26}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Server::Flags operator|(Server::Flags, Server::Flags)</tt><br>
   * <tt>Server::Flags operator&(Server::Flags, Server::Flags)</tt><br>
   * <tt>Server::Flags operator^(Server::Flags, Server::Flags)</tt><br>
   * <tt>Server::Flags operator~(Server::Flags)</tt><br>
   * <tt>Server::Flags& operator|=(Server::Flags&, Server::Flags)</tt><br>
   * <tt>Server::Flags& operator&=(Server::Flags&, Server::Flags)</tt><br>
   * <tt>Server::Flags& operator^=(Server::Flags&, Server::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    RUN_IN_THREAD = (1<<0),
    AUTHENTICATION_ALLOW_ANONYMOUS = (1<<1),
    AUTHENTICATION_REQUIRE_SAME_USER = (1<<2)
  };


protected:
  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    Flags flags);

  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    Flags flags);

  Server(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    Flags flags);

  Server(const std::string& address,
    const std::string& guid,
    Flags flags);

public:


  /** Creates a new D-Bus server that listens on the first address in
   *  @a address that works.
   *
   * Once constructed, you can use g_dbus_server_get_client_address() to
   * get a D-Bus address string that clients can use to connect.
   *
   * To have control over the available authentication mechanisms and
   * the users that are authorized to connect, it is strongly recommended
   * to provide a non-<tt>nullptr</tt> Gio::DBus::AuthObserver.
   *
   * Connect to the Gio::DBus::Server::signal_new_connection() signal to handle
   * incoming connections.
   *
   * The returned Gio::DBus::Server isn't active - you have to start it with
   * g_dbus_server_start().
   *
   * Gio::DBus::Server is used in this [example][gdbus-peer-to-peer].
   *
   * This is a synchronous failable constructor. There is currently no
   * asynchronous version.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags from the Gio::DBus::Server::Flags enumeration.
   * @param guid A D-Bus GUID.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Server or <tt>nullptr</tt> if @a error is set. Free with
   * Glib::object_unref().
   */

  /// @throw Glib::Error.
  static auto create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    const Glib::RefPtr<Cancellable>& cancellable,
    Flags flags = Gio::DBus::Server::Flags::NONE) -> Glib::RefPtr<Server>;


  /** Creates a new D-Bus server that listens on the first address in
   *  @a address that works.
   *
   * Once constructed, you can use g_dbus_server_get_client_address() to
   * get a D-Bus address string that clients can use to connect.
   *
   * To have control over the available authentication mechanisms and
   * the users that are authorized to connect, it is strongly recommended
   * to provide a non-<tt>nullptr</tt> Gio::DBus::AuthObserver.
   *
   * Connect to the Gio::DBus::Server::signal_new_connection() signal to handle
   * incoming connections.
   *
   * The returned Gio::DBus::Server isn't active - you have to start it with
   * g_dbus_server_start().
   *
   * Gio::DBus::Server is used in this [example][gdbus-peer-to-peer].
   *
   * This is a synchronous failable constructor. There is currently no
   * asynchronous version.
   *
   * @newin{2,26}
   *
   * @param address A D-Bus address.
   * @param flags Flags from the Gio::DBus::Server::Flags enumeration.
   * @param guid A D-Bus GUID.
   * @param observer A Gio::DBus::AuthObserver or <tt>nullptr</tt>.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return A Gio::DBus::Server or <tt>nullptr</tt> if @a error is set. Free with
   * Glib::object_unref().
   */

  /// @throw Glib::Error.
  static auto create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<Cancellable>& cancellable,
    Flags flags = Gio::DBus::Server::Flags::NONE) -> Glib::RefPtr<Server>;

  /// Non-cancellable version of create_sync().
  static auto create_sync(const std::string& address,
    const std::string& guid,
    const Glib::RefPtr<AuthObserver>& observer,
    Flags flags = Gio::DBus::Server::Flags::NONE) -> Glib::RefPtr<Server>;

  /// Non-cancellable version of create_sync().
  static auto create_sync(const std::string& address,
    const std::string& guid,
    Flags flags = Gio::DBus::Server::Flags::NONE) -> Glib::RefPtr<Server>;


  /** Starts @a server.
   *
   * @newin{2,26}
   */
  void start();

  /** Stops @a server.
   *
   * @newin{2,26}
   */
  void stop();

  /** Gets whether @a server is active.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if server is active, <tt>false</tt> otherwise.
   */
  auto is_active() const -> bool;

  /** Gets the GUID for @a server, as provided to g_dbus_server_new_sync().
   *
   * @newin{2,26}
   *
   * @return A D-Bus GUID. Do not free this string, it is owned by @a server.
   */
  auto get_guid() const -> std::string;

  /** Gets the flags for @a server.
   *
   * @newin{2,26}
   *
   * @return A set of flags from the Gio::DBus::Server::Flags enumeration.
   */
  auto get_flags() const -> Flags;

  /** Gets a
   * [D-Bus address](https://dbus.freedesktop.org/doc/dbus-specification.html#addresses)
   * string that can be used by clients to connect to @a server.
   *
   * This is valid and non-empty if initializing the Gio::DBus::Server succeeded.
   *
   * @newin{2,26}
   *
   * @return A D-Bus address string. Do not free, the string is owned
   * by @a server.
   */
  auto get_client_address() const -> std::string;

  /** Whether the server is currently active.
   *
   * @newin{2,26}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The D-Bus address to listen on.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_address() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /** A Gio::DBus::AuthObserver object to assist in the authentication process or <tt>nullptr</tt>.
   *
   * @newin{2,26}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_authentication_observer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<AuthObserver> >;


  /** The D-Bus address that clients can use.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_client_address() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /** Flags from the Gio::DBus::Server::Flags enumeration.
   *
   * @newin{2,26}
   *
   * Default value: Gio::DBus::Server::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;


  /** The GUID of the server.
   *
   * See Gio::DBus::Connection::property_guid() for more details.
   *
   * @newin{2,26}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_guid() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%new_connection(const Glib::RefPtr<Connection>& connection)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a new authenticated connection has been made. Use
   * g_dbus_connection_get_peer_credentials() to figure out what
   * identity (if any), was authenticated.
   *
   * If you want to accept the connection, take a reference to the
   *  @a connection object and return <tt>true</tt>. When you are done with the
   * connection call g_dbus_connection_close() and give up your
   * reference. Note that the other peer may disconnect at any time -
   * a typical thing to do when accepting a connection is to listen to
   * the Gio::DBus::Connection::signal_closed() signal.
   *
   * If Gio::DBus::Server::property_flags() contains Gio::DBus::Server::Flags::RUN_IN_THREAD
   * then the signal is emitted in a new thread dedicated to the
   * connection. Otherwise the signal is emitted in the
   * [thread-default main context][g-main-context-push-thread-default]
   * of the thread that @a server was constructed in.
   *
   * You are guaranteed that signal handlers for this signal runs
   * before incoming messages on @a connection are processed. This means
   * that it's suitable to call g_dbus_connection_register_object() or
   * similar from the signal handler.
   *
   * @newin{2,26}
   *
   * @param connection A Gio::DBus::Connection for the new connection.
   * @return <tt>true</tt> to claim @a connection, <tt>false</tt> to let other handlers
   * run.
   */

  auto signal_new_connection() -> Glib::SignalProxy<bool(const Glib::RefPtr<Connection>&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio

namespace Gio::DBus
{

/** @ingroup giommEnums */
inline auto operator|(Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  { return static_cast<Server::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  { return static_cast<Server::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Server::Flags lhs, Server::Flags rhs) -> Server::Flags
  { return static_cast<Server::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Server::Flags flags) -> Server::Flags
  { return static_cast<Server::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  { return (lhs = static_cast<Server::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  { return (lhs = static_cast<Server::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Server::Flags& lhs, Server::Flags rhs) -> Server::Flags&
  { return (lhs = static_cast<Server::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::DBus::Server::Flags> : public Glib::Value_Flags<Gio::DBus::Server::Flags>
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
   * @relates Gio::DBus::Server
   */
  GIOMM_API
  auto wrap(GDBusServer* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Server>;
}


#endif /* _GIOMM_DBUSSERVER_H */

