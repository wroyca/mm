
#ifndef _GIOMM_SOCKETCONNECTION_H
#define _GIOMM_SOCKETCONNECTION_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 Jonathon Jongsma
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
#include <libmm-gio/iostream.hpp>
#include <libmm-gio/enums.hpp>
#include <libmm-gio/socket.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketConnection = struct _GSocketConnection;
using GSocketConnectionClass = struct _GSocketConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API SocketConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/**
 * A socket connection
 *
 * @see IOStream, SocketClient, SocketListener
 *
 * SocketConnection is a IOStream for a connected socket. They
 * can be created either by SocketClient when connecting to a host,
 * or by SocketListener when accepting a new client.
 *
 * The type of the SocketConnection object returned from these calls
 * depends on the type of the underlying socket that is in use. For
 * instance, for a TCP/IP connection it will be a TcpConnection.
 *
 * Chosing what type of object to construct is done with the socket
 * connection factory, and it is possible for 3rd parties to register
 * custom socket connection types for specific combination of socket
 * family/type/protocol using g_socket_connection_factory_register_type().
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API SocketConnection : public Gio::IOStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SocketConnection;
  using CppClassType = SocketConnection_Class;
  using BaseObjectType = GSocketConnection;
  using BaseClassType = GSocketConnectionClass;

  // noncopyable
  SocketConnection(const SocketConnection&) = delete;
  auto operator=(const SocketConnection&) -> SocketConnection& = delete;

private:  friend class SocketConnection_Class;
  static CppClassType socketconnection_class_;

protected:
  explicit SocketConnection(const Glib::ConstructParams& construct_params);
  explicit SocketConnection(GSocketConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SocketConnection(SocketConnection&& src) noexcept;
  auto operator=(SocketConnection&& src) noexcept -> SocketConnection&;

  ~SocketConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocketConnection*       { return reinterpret_cast<GSocketConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocketConnection* { return reinterpret_cast<GSocketConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocketConnection*;

private:


public:

  /** Connect @a connection to the specified remote address.
   *
   * @newin{2,32}
   *
   * @param address A SocketAddress specifying the remote address.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the connection succeeded, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto connect(const Glib::RefPtr<SocketAddress>& address, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A connect() convenience overload.
  auto connect(const Glib::RefPtr<SocketAddress>& address) -> bool;

  /**  Asynchronously connect this connection to the specified remote address.
   * This clears the "blocking" flag on this connection's underlying socket if
   * it is currently set.
   *
   * Use connect_finish() to retrieve the result.
   *
   * @param address A SocketAddress specifying the remote address.
   * @param slot A SlotAsyncReady slot.
   * @param cancellable A Cancellable.
   * @newin{2,36}
   */
  void connect_async(const Glib::RefPtr<SocketAddress>& address,
    const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);


  /// A non-cancellable version of connect_async().
  void connect_async(const Glib::RefPtr<SocketAddress>& address,
    const SlotAsyncReady& slot);


  /** Gets the result of a g_socket_connection_connect_async() call.
   *
   * @newin{2,32}
   *
   * @param result The AsyncResult.
   * @return <tt>true</tt> if the connection succeeded, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto connect_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Checks if @a connection is connected. This is equivalent to calling
   * g_socket_is_connected() on @a connection's underlying Socket.
   *
   * @newin{2,32}
   *
   * @return Whether @a connection is connected.
   */
  auto is_connected() const -> bool;


  /** Gets the underlying Socket object of the connection.
   * This can be useful if you want to do something unusual on it
   * not supported by the SocketConnection APIs.
   *
   * @newin{2,22}
   *
   * @return A Socket or <tt>nullptr</tt> on error.
   */
  auto get_socket() -> Glib::RefPtr<Socket>;

  /** Gets the underlying Socket object of the connection.
   * This can be useful if you want to do something unusual on it
   * not supported by the SocketConnection APIs.
   *
   * @newin{2,22}
   *
   * @return A Socket or <tt>nullptr</tt> on error.
   */
  auto get_socket() const -> Glib::RefPtr<const Socket>;

  /** Try to get the local address of a socket connection.
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_local_address() -> Glib::RefPtr<SocketAddress>;

  /** Try to get the local address of a socket connection.
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_local_address() const -> Glib::RefPtr<const SocketAddress>;

  /** Try to get the remote address of a socket connection.
   *
   * Since GLib 2.40, when used with g_socket_client_connect() or
   * g_socket_client_connect_async(), during emission of
   * Gio::SocketClientEvent::CONNECTING, this function will return the remote
   * address that will be used for the connection.  This allows
   * applications to print e.g. "Connecting to example.com
   * (10.42.77.3)...".
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_remote_address() -> Glib::RefPtr<SocketAddress>;

  /** Try to get the remote address of a socket connection.
   *
   * Since GLib 2.40, when used with g_socket_client_connect() or
   * g_socket_client_connect_async(), during emission of
   * Gio::SocketClientEvent::CONNECTING, this function will return the remote
   * address that will be used for the connection.  This allows
   * applications to print e.g. "Connecting to example.com
   * (10.42.77.3)...".
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_remote_address() const -> Glib::RefPtr<const SocketAddress>;

  // Not sure that registering new GTypes with the factory is useful for the C++ binding
  //_WRAP_METHOD(void factory_register_type(GType g_type, GSocketFamily family, GSocketType type, gint protocol);
  //_WRAP_METHOD(GType factory_lookup_type(GSocketFamily family, GSocketType type, gint protocol_id);


  /** Creates a SocketConnection subclass of the right type for
   *  @a socket.
   *
   * @newin{2,22}
   *
   * @param socket A Socket.
   * @return A SocketConnection.
   */
  static auto create(const Glib::RefPtr<Socket>& socket) -> Glib::RefPtr<SocketConnection>;

  /** The underlying GSocket.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_socket() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Socket> >;


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
   * @relates Gio::SocketConnection
   */
  GIOMM_API
  auto wrap(GSocketConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketConnection>;
}


#endif /* _GIOMM_SOCKETCONNECTION_H */

