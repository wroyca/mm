
#ifndef _GIOMM_SOCKET_H
#define _GIOMM_SOCKET_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 Jonathon Jongsma
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

#include <mm/glib/iochannel.hpp>
#include <mm/glib/object.hpp>
#include <mm/gio/initable.hpp>
#include <mm/gio/credentials.hpp>
#include <mm/gio/socketconnectable.hpp>
#include <mm/gio/socketaddress.hpp>
#include <mm/gio/enums.hpp>
#include <mm/gio/inetaddress.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocket = struct _GSocket;
using GSocketClass = struct _GSocketClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Socket_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class SocketSource;


/** @defgroup NetworkIO Portable Network I/O Functionality
 */

/** Low-level socket object
 *
 * A Socket is a low-level networking primitive. It is a more or less direct
 * mapping of the BSD socket API in a portable GObject based API. It supports
 * both the UNIX socket implementations and winsock2 on Windows.
 *
 * Socket is the platform independent base upon which the higher level network
 * primitives are based. Applications are not typically meant to use it
 * directly, but rather through classes like SocketClient, SocketService and
 * SocketConnection. However there may be cases where direct use of Socket is
 * useful.
 *
 * Socket implements the Initable interface, and since initialization can fail,
 * the constructor may throw an exception.
 *
 * Sockets operate in two general modes, blocking or non-blocking. When in
 * blocking mode all operations block until the requested operation is finished
 * or there is an error. In non-blocking mode all calls that would block return
 * immediately with a Gio::Error::WOULD_BLOCK error. To know when a call would
 * successfully run you can call condition_check(), or condition_wait(). You can
 * also use create_source() and attach it to a Glib::MainContext to get
 * callbacks when I/O is possible. Note that all sockets are always set to non
 * blocking mode in the system, and blocking mode is emulated in Socket.
 *
 * When working in non-blocking mode applications should always be able to
 * handle getting a Gio::Error::WOULD_BLOCK error even when some other function
 * said that I/O was possible. This can easily happen in case of a race
 * condition in the application, but it can also happen for other reasons. For
 * instance, on Windows a socket is always seen as writable until a write
 * returns Gio::Error::WOULD_BLOCK.
 *
 * Sockets can be either connection oriented or datagram based. For connection
 * oriented types you must first establish a connection by either connecting to
 * an address or accepting a connection from another address. For connectionless
 * socket types the target/source address is specified or received in each I/O
 * operation.
 *
 * All socket file descriptors are set to be close-on-exec.
 *
 * Note that creating a Socket causes the signal SIGPIPE to be ignored for the
 * remainder of the program. If you are writing a command-line utility that uses
 * Socket, you may need to take into account the fact that your program will not
 * automatically be killed if it tries to write to stdout after it has been
 * closed.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API Socket : public Glib::Object, public Initable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Socket;
  using CppClassType = Socket_Class;
  using BaseObjectType = GSocket;
  using BaseClassType = GSocketClass;

  // noncopyable
  Socket(const Socket&) = delete;
  auto operator=(const Socket&) -> Socket& = delete;

private:  friend class Socket_Class;
  static CppClassType socket_class_;

protected:
  explicit Socket(const Glib::ConstructParams& construct_params);
  explicit Socket(GSocket* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Socket(Socket&& src) noexcept;
  auto operator=(Socket&& src) noexcept -> Socket&;

  ~Socket() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSocket*       { return reinterpret_cast<GSocket*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSocket* { return reinterpret_cast<GSocket*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSocket*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Type INVALID
   * Type unknown or wrong.
   *
   *  @var Type STREAM
   * Reliable connection-based byte streams (e.g. TCP).
   *
   *  @var Type DATAGRAM
   * Connectionless, unreliable datagram passing.
   * (e.g. UDP).
   *
   *  @var Type SEQPACKET
   * Reliable connection-based passing of datagrams
   * of fixed maximum length (e.g. SCTP).
   *
   *  @enum Type
   *
   * Flags used when creating a Socket. Some protocols may not implement
   * all the socket types.
   *
   * @newin{2,22}
   *
   * @ingroup giommEnums
   */
  enum class Type
  {
    INVALID,
    STREAM,
    DATAGRAM,
    SEQPACKET
  };


  /**
   *  @var Protocol UNKNOWN
   * The protocol type is unknown.
   *
   *  @var Protocol DEFAULT
   * The default protocol for the family/type.
   *
   *  @var Protocol TCP
   * TCP over IP.
   *
   *  @var Protocol UDP
   * UDP over IP.
   *
   *  @var Protocol SCTP
   * SCTP over IP.
   *
   *  @enum Protocol
   *
   * A protocol identifier is specified when creating a Socket, which is a
   * family/type specific identifier, where 0 means the default protocol for
   * the particular family/type.
   *
   * This enum contains a set of commonly available and used protocols. You
   * can also pass any other identifiers handled by the platform in order to
   * use protocols not listed here.
   *
   * @newin{2,22}
   *
   * @ingroup giommEnums
   */
  enum class Protocol
  {
    UNKNOWN = -1,
    DEFAULT = 0,
    TCP = 6,
    UDP = 17,
    SCTP = 132
  };


  /**
   *  @var MsgFlags NONE
   * No flags.
   *
   *  @var MsgFlags OOB
   * Request to send/receive out of band data.
   *
   *  @var MsgFlags PEEK
   * Read data from the socket without removing it from
   * the queue.
   *
   *  @var MsgFlags DONTROUTE
   * Don't use a gateway to send out the packet,
   * only send to hosts on directly connected networks.
   *
   *  @enum MsgFlags
   *
   * Flags used in g_socket_receive_message() and g_socket_send_message().
   * The flags listed in the enum are some commonly available flags, but the
   * values used for them are the same as on the platform, and any other flags
   * are passed in/out as is. So to use a platform specific flag, just include
   * the right system header and pass in the flag.
   *
   * @newin{2,22}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Socket::MsgFlags operator|(Socket::MsgFlags, Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags operator&(Socket::MsgFlags, Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags operator^(Socket::MsgFlags, Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags operator~(Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags& operator|=(Socket::MsgFlags&, Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags& operator&=(Socket::MsgFlags&, Socket::MsgFlags)</tt><br>
   * <tt>Socket::MsgFlags& operator^=(Socket::MsgFlags&, Socket::MsgFlags)</tt><br>
   */
  enum class MsgFlags
  {
    NONE = 0x0,
    OOB = GLIB_SYSDEF_MSG_OOB,
    PEEK = GLIB_SYSDEF_MSG_PEEK,
    DONTROUTE = GLIB_SYSDEF_MSG_DONTROUTE
  };


protected:
  Socket(SocketFamily family, Type type, Protocol protocol,
         const Glib::RefPtr<Cancellable>& cancellable);

  Socket(int fd, const Glib::RefPtr<Cancellable>& cancellable);

public:

  /** Creates a new Socket with the defined family, type and protocol.
   * If @a protocol is 0 (Gio::Socket::Protocol::DEFAULT) the default protocol type
   * for the family and type is used.
   *
   * The @a protocol is a family and type specific int that specifies what
   * kind of protocol to use. Gio::Socket::Protocol lists several common ones.
   * Many families only support one protocol, and use 0 for this, others
   * support several and using 0 means to use the default protocol for
   * the family and type.
   *
   * The protocol id is passed directly to the operating
   * system, so you can use protocols not listed in Gio::Socket::Protocol if you
   * know the protocol number used for it.
   *
   * @newin{2,22}
   *
   * @param family The socket family to use, e.g. Gio::SocketFamily::IPV4.
   * @param type The socket type to use.
   * @param protocol The id of the protocol to use, or 0 for default.
   * @return A Socket or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   */


  /** @param cancellable A Cancellable object which can be used to cancel the operation.
   * @throw Glib::Error
   */
  static auto
  create(SocketFamily family, Type type, Protocol protocol,
         const Glib::RefPtr<Cancellable>& cancellable = {}) -> Glib::RefPtr<Socket>;

  // gmmproc thinks that this function should be wrapped in this class because
  // its only parameter is a GSocket.  In fact, it is wrapped in the
  // SocketConnection class.


  /** Creates a new Socket from a native file descriptor
   * or winsock SOCKET handle.
   *
   * This reads all the settings from the file descriptor so that
   * all properties should work. Note that the file descriptor
   * will be set to non-blocking mode, independent on the blocking
   * mode of the Socket.
   *
   * On success, the returned Socket takes ownership of @a fd. On failure, the
   * caller must close @a fd themselves.
   *
   * Since GLib 2.46, it is no longer a fatal error to call this on a non-socket
   * descriptor.  Instead, a GError will be set with code Gio::Error::FAILED
   *
   * @newin{2,22}
   *
   * @param fd A native socket file descriptor.
   * @return A Socket or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   */

  /** @param cancellable A Cancellable object which can be used to cancel the operation.
   * @throw Glib::Error
   */
  static auto create_from_fd(int fd, const Glib::RefPtr<Cancellable>&
                                             cancellable = {}) -> Glib::RefPtr<Socket>;


  /** When a socket is created it is attached to an address family, but it doesn't
   * have an address in this family. Socket::bind() assigns the address (sometimes
   * called name) of the socket.
   *
   * It is generally required to bind to a local address before you can receive
   * connections. (See Socket::listen() and Socket::accept()). In certain situations,
   * you may also want to bind a socket that will be used to initiate connections,
   * though this is not normally required.
   *
   * If socket is a TCP socket, then @a allow_reuse controls the setting of the SO_REUSEADDR
   * socket option; normally it should be <tt>true</tt> for server sockets (sockets that you
   * will eventually call Socket::accept() on), and <tt>false</tt> for client sockets.
   * (Failing to set this flag on a server socket may cause Socket::bind() to
   * throw Gio::Error with ADDRESS_IN_USE if the server program
   * is stopped and then immediately restarted.)
   *
   * If socket is a UDP socket, then @a allow_reuse determines whether or not
   * other UDP sockets can be bound to the same address at the same time. In particular,
   * you can have several UDP sockets bound to the same address, and they will all
   * receive all of the multicast and broadcast packets sent to that address.
   * (The behavior of unicast UDP packets to an address with multiple listeners is not defined.)
   *
   * @param address a SocketAddress specifying the local address.
   * @param allow_reuse whether to allow reusing this address
   *
   * @throw Gio::Error
   */
  void bind(const Glib::RefPtr<SocketAddress>& address, bool allow_reuse);


  /** Marks the socket as a server socket - a socket that is used to accept
   * incoming requests using Socket::accept().
   *
   * Before calling this the socket must be bound to a local address using Socket::bind().
   *
   * To set the maximum amount of outstanding clients, use Socket::set_listen_backlog().
   *
   * @throw Gio::Error
   */
  void listen();


  /** Accept incoming connections on a connection-based socket. This removes the
   * first outstanding connection request from the listening socket and creates
   * a GSocket object for it.
   *
   * The socket must be bound to a local address with g_socket_bind() and must
   * be listening for incoming connections (Socket::listen()).
   *
   * If there are no outstanding connections then the operation will block or
   * throw Gio::Error with ERROR_WOULD_BLOCK if non-blocking
   * I/O is enabled. To be notified of an incoming connection, wait for the
   * Glib::IO_IN condition.
   *
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   *
   * @return a Gio::Socket
   *
   * @throw Gio::Error
   */
  auto accept(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Socket>;

  /// A accept() convenience overload.
  auto accept() -> Glib::RefPtr<Socket>;


  /** Connect the socket to the specified remote address.
   *
   * For connection oriented socket this generally means we attempt to make a
   * connection to the address . For a connection-less socket it sets the default
   * address for Socket::send() and discards all incoming datagrams from other sources.
   *
   * Generally connection oriented sockets can only connect once, but
   * connection-less sockets can connect multiple times to change the default address.
   *
   * If the connect call needs to do network I/O it will block, unless non-blocking
   * I/O is enabled. Then Gio::Error with ERROR_PENDING is thrown
   * and the user can be notified of the connection finishing by waiting for the
   * Glib::IO_OUT condition. The result of the connection must then be checked
   * with Socket::check_connect_result().
   *
   * @param address	a SocketAddress specifying the remote address.
   * @param cancellable	A Cancellable object which can be used to cancel the operation.
   *
   * @throw Gio::Error
   */
  void connect(const Glib::RefPtr<SocketAddress>& address, const Glib::RefPtr<Cancellable>& cancellable);

  /// A connect() convenience overload.
  void connect(const Glib::RefPtr<SocketAddress>& address);

  // FIXME: it doesn't really seem like this is a proper use of exceptions...

  /** Checks and resets the pending connect error for the socket.
   * This is used to check for errors when g_socket_connect() is
   * used in non-blocking mode.
   *
   * @newin{2,22}
   *
   *
   * @throws Glib::Error
   */
  void check_connect_result();

  // TODO: std::string overload?

  /** Receive data (up to @a size bytes) from a socket. This is mainly used by
   * connection-oriented sockets; it is identical to g_socket_receive_from()
   * with @a address set to <tt>nullptr</tt>.
   *
   * For Gio::Socket::Type::DATAGRAM and Gio::Socket::Type::SEQPACKET sockets,
   * g_socket_receive() will always read either 0 or 1 complete messages from
   * the socket. If the received message is too large to fit in @a buffer, then
   * the data beyond @a size bytes will be discarded, without any explicit
   * indication that this has occurred.
   *
   * For Gio::Socket::Type::STREAM sockets, g_socket_receive() can return any
   * number of bytes, up to @a size. If more than @a size bytes have been
   * received, the additional data will be returned in future calls to
   * g_socket_receive().
   *
   * If the socket is in blocking mode the call will block until there
   * is some data to receive, the connection is closed, or there is an
   * error. If there is no data available and the socket is in
   * non-blocking mode, a Gio::Error::WOULD_BLOCK error will be
   * returned. To be notified when data is available, wait for the
   * Glib::IOCondition::IN condition.
   *
   * On error -1 is returned and @a error is set accordingly.
   *
   * @newin{2,22}
   *
   * @param buffer A buffer to read data into (which should be at least @a size bytes long).
   * @param size The number of bytes you want to read from the socket.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Number of bytes read, or 0 if the connection was closed by
   * the peer, or -1 on error.
   *
   * @throws Glib::Error
   */
  auto receive(char* buffer, gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A receive() convenience overload.
  auto receive(char* buffer, gsize size) -> gssize;


  auto receive_from(Glib::RefPtr<SocketAddress>& address, char* buffer, gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;
  auto receive_from(Glib::RefPtr<SocketAddress>& address, char* buffer, gsize size) -> gssize;
  // TODO: wrap g_socket_receive_message -- figure out this GInputVector thing
  // TODO: std::string overload?


  /** Tries to send @a size bytes from @a buffer on the socket. This is
   * mainly used by connection-oriented sockets; it is identical to
   * g_socket_send_to() with @a address set to <tt>nullptr</tt>.
   *
   * If the socket is in blocking mode the call will block until there is
   * space for the data in the socket queue. If there is no space available
   * and the socket is in non-blocking mode a Gio::Error::WOULD_BLOCK error
   * will be returned. To be notified when space is available, wait for the
   * Glib::IOCondition::OUT condition. Note though that you may still receive
   * Gio::Error::WOULD_BLOCK from g_socket_send() even if you were previously
   * notified of a Glib::IOCondition::OUT condition. (On Windows in particular, this is
   * very common due to the way the underlying APIs work.)
   *
   * On error -1 is returned and @a error is set accordingly.
   *
   * @newin{2,22}
   *
   * @param buffer The buffer
   * containing the data to send.
   * @param size The number of bytes to send.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Number of bytes written (which may be less than @a size), or -1
   * on error.
   *
   * @throws Glib::Error
   */
  auto send(const gchar* buffer, gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A send() convenience overload.
  auto send(const gchar* buffer, gsize size) -> gssize;

  // TODO: std::string overload?

  /** Tries to send @a size bytes from @a buffer to @a address. If @a address is
   * <tt>nullptr</tt> then the message is sent to the default receiver (set by
   * g_socket_connect()).
   *
   * See g_socket_send() for additional information.
   *
   * @newin{2,22}
   *
   * @param address A SocketAddress, or <tt>nullptr</tt>.
   * @param buffer The buffer
   * containing the data to send.
   * @param size The number of bytes to send.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Number of bytes written (which may be less than @a size), or -1
   * on error.
   *
   * @throws Glib::Error
   */
  auto send_to(const Glib::RefPtr<SocketAddress>& address, const char* buffer, gsize size, const Glib::RefPtr<Cancellable>& cancellable) -> gssize;

  /// A send_to() convenience overload.
  auto send_to(const Glib::RefPtr<SocketAddress>& address, const char* buffer, gsize size) -> gssize;

  // TODO: wrap g_socket_send_message -- figure out this GOutputVector thing

  /** Closes the socket, shutting down any active connection.
   *
   * Closing a socket does not wait for all outstanding I/O operations
   * to finish, so the caller should not rely on them to be guaranteed
   * to complete even if the close returns with no error.
   *
   * Once the socket is closed, all other operations will return
   * Gio::Error::CLOSED. Closing a socket multiple times will not
   * return an error.
   *
   * Sockets will be automatically closed when the last reference
   * is dropped, but you might want to call this function to make sure
   * resources are released as early as possible.
   *
   * Beware that due to the way that TCP works, it is possible for
   * recently-sent data to be lost if either you close a socket while the
   * Glib::IOCondition::IN condition is set, or else if the remote connection tries to
   * send something to you after you close the socket but before it has
   * finished reading all of the data you sent. There is no easy generic
   * way to avoid this problem; the easiest fix is to design the network
   * protocol such that the client will never send data "out of turn".
   * Another solution is for the server to half-close the connection by
   * calling g_socket_shutdown() with only the @a shutdown_write flag set,
   * and then wait for the client to notice this and close its side of the
   * connection, after which the server can safely call g_socket_close().
   * (This is what TcpConnection does if you call
   * g_tcp_connection_set_graceful_disconnect(). But of course, this
   * only works if the client will close its connection after the server
   * does.)
   *
   * @newin{2,22}
   *
   *
   * @throws Glib::Error
   */
  void close();

  /** Checks whether a socket is closed.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if socket is closed, <tt>false</tt> otherwise.
   */
  auto is_closed() -> bool;

  /** Creates a SocketSource that can be attached to a Glib::MainContext to monitor
   * for the availability of the specified @a condition on the socket.
   *
   * Create a slot from a function to be called when @a condition is met
   * for the socket with sigc::ptr_fun() or sigc::mem_fun() and pass
   * it into the connect() function of the returned SocketSource object.
   * Polling of the socket will start when you attach a Glib::MainContext
   * object to the returned SocketSource object using its attach() function.
   *
   * It is meaningless to specify Glib::IO_ERR or Glib::IO_HUP in @a condition;
   * these conditions will always be reported output if they are true.
   *
   * @a cancellable can be used to cancel the source, which will
   * cause the source to trigger, reporting the current condition (which
   * is likely 0 unless cancellation happened at the same time as a
   * condition change). You can check for this in the callback using
   * Cancellable::is_cancelled().
   *
   * If the socket has a timeout set, and it is reached before @a condition
   * occurs, the source will then trigger anyway, reporting Glib::IO_IN or
   * Glib::IO_OUT depending on @a condition. However, the socket will have been
   * marked as having had a timeout, and so the next Socket I/O method
   * you call will then fail with a Gio::IO_ERROR_TIMED_OUT.
   *
   * Gio::signal_socket().connect() is a simpler interface to the same functionality.
   *
   * @newin{2,42}
   *
   * @param condition A Glib::IOCondition mask to monitor.
   * @param cancellable A Cancellable. The default value means the source is not cancellable.
   * @return A newly allocated SocketSource.
   */
  auto create_source(Glib::IOCondition condition, const Glib::RefPtr<Cancellable>& cancellable = {}) -> Glib::RefPtr<SocketSource>;


  /** Shut down part or all of a full-duplex connection.
   *
   * If @a shutdown_read is <tt>true</tt> then the receiving side of the connection
   * is shut down, and further reading is disallowed.
   *
   * If @a shutdown_write is <tt>true</tt> then the sending side of the connection
   * is shut down, and further writing is disallowed.
   *
   * It is allowed for both @a shutdown_read and @a shutdown_write to be <tt>true</tt>.
   *
   * One example where it is useful to shut down only one side of a connection is
   * graceful disconnect for TCP connections where you close the sending side,
   * then wait for the other side to close the connection, thus ensuring that the
   * other side saw all sent data.
   *
   * @newin{2,22}
   *
   * @param shutdown_read Whether to shut down the read side.
   * @param shutdown_write Whether to shut down the write side.
   *
   * @throws Glib::Error
   */
  void shutdown(bool shutdown_read, bool shutdown_write);

  /** Check whether the socket is connected. This is only useful for
   * connection-oriented sockets.
   *
   * If using g_socket_shutdown(), this function will return <tt>true</tt> until the
   * socket has been shut down for reading and writing. If you do a non-blocking
   * connect, this function will not return <tt>true</tt> until after you call
   * g_socket_check_connect_result().
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if socket is connected, <tt>false</tt> otherwise.
   */
  auto is_connected() -> bool;


  /** Get the amount of data pending in the OS input buffer, without blocking.
   *
   * If @a socket is a UDP or SCTP socket, this will return the size of
   * just the next packet, even if additional packets are buffered after
   * that one.
   *
   * Note that on Windows, this function is rather inefficient in the
   * UDP case, and so if you know any plausible upper bound on the size
   * of the incoming packet, it is better to just do a
   * g_socket_receive() with a buffer of that size, rather than calling
   * g_socket_get_available_bytes() first and then doing a receive of
   * exactly the right size.
   *
   * @newin{2,32}
   *
   * @return The number of bytes that can be read from the socket
   * without blocking or truncating, or -1 on error.
   */
  auto get_available_bytes() const -> gssize;


  /** Checks on the readiness of @a socket to perform operations.
   * The operations specified in @a condition are checked for and masked
   * against the currently-satisfied conditions on @a socket. The result
   * is returned.
   *
   * Note that on Windows, it is possible for an operation to return
   * Gio::Error::WOULD_BLOCK even immediately after
   * g_socket_condition_check() has claimed that the socket is ready for
   * writing. Rather than calling g_socket_condition_check() and then
   * writing to the socket if it succeeds, it is generally better to
   * simply try writing to the socket right away, and try again later if
   * the initial attempt returns Gio::Error::WOULD_BLOCK.
   *
   * It is meaningless to specify Glib::IOCondition::ERR or Glib::IOCondition::HUP in condition;
   * these conditions will always be set in the output if they are true.
   *
   * This call never blocks.
   *
   * @newin{2,22}
   *
   * @param condition A IOCondition mask to check.
   * @return The @a GIOCondition mask of the current state.
   */
  auto condition_check(Glib::IOCondition condition) -> Glib::IOCondition;


  /** Waits for @a condition to become true on @a socket. When the condition
   * is met, <tt>true</tt> is returned.
   *
   * If @a cancellable is cancelled before the condition is met, or if the
   * socket has a timeout set and it is reached before the condition is
   * met, then <tt>false</tt> is returned and @a error, if non-<tt>nullptr</tt>, is set to
   * the appropriate value (Gio::Error::CANCELLED or
   * Gio::Error::TIMED_OUT).
   *
   * See also g_socket_condition_timed_wait().
   *
   * @newin{2,22}
   *
   * @param condition A IOCondition mask to wait for.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   *
   * @throws Glib::Error
   */
  void condition_wait(Glib::IOCondition condition, const Glib::RefPtr<Cancellable>& cancellable);

  /// A condition_wait() convenience overload.
  void condition_wait(Glib::IOCondition condition);


  /** Waits for up to @a timeout microseconds for @a condition to become true
   * on @a socket. If the condition is met, <tt>true</tt> is returned.
   *
   * If @a cancellable is cancelled before the condition is met, or if
   *  @a timeout (or the socket's Socket::property_timeout()) is reached before the
   * condition is met, then <tt>false</tt> is returned and @a error, if non-<tt>nullptr</tt>,
   * is set to the appropriate value (Gio::Error::CANCELLED or
   * Gio::Error::TIMED_OUT).
   *
   * If you don't want a timeout, use g_socket_condition_wait().
   * (Alternatively, you can pass -1 for @a timeout.)
   *
   * Note that although @a timeout is in microseconds for consistency with
   * other GLib APIs, this function actually only has millisecond
   * resolution, and the behavior is undefined if @a timeout is not an
   * exact number of milliseconds.
   *
   * @newin{2,32}
   *
   * @param condition A IOCondition mask to wait for.
   * @param timeout The maximum time (in microseconds) to wait, or -1.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   *
   * @throws Glib::Error
   */
  void condition_timed_wait(Glib::IOCondition condition, gint64 timeout, const Glib::RefPtr<Cancellable>& cancellable);

  /// A condition_timed_wait() convenience overload.
  void condition_timed_wait(Glib::IOCondition condition, gint64 timeout);


  /** Sets the maximum number of outstanding connections allowed
   * when listening on this socket. If more clients than this are
   * connecting to the socket and the application is not handling them
   * on time then the new connections will be refused.
   *
   * Note that this must be called before g_socket_listen() and has no
   * effect if called after that.
   *
   * @newin{2,22}
   *
   * @param backlog The maximum number of pending connections.
   */
  void set_listen_backlog(int backlog);

  /** Gets the listen backlog setting of the socket. For details on this,
   * see g_socket_set_listen_backlog().
   *
   * @newin{2,22}
   *
   * @return The maximum number of pending connections.
   */
  auto get_listen_backlog() const -> int;

  /** Sets the blocking mode of the socket. In blocking mode
   * all operations (which don’t take an explicit blocking parameter) block until
   * they succeed or there is an error. In
   * non-blocking mode all functions return results immediately or
   * with a Gio::Error::WOULD_BLOCK error.
   *
   * All sockets are created in blocking mode. However, note that the
   * platform level socket is always non-blocking, and blocking mode
   * is a GSocket level feature.
   *
   * @newin{2,22}
   *
   * @param blocking Whether to use blocking I/O or not.
   */
  void set_blocking(bool blocking);

  /** Gets the blocking mode of the socket. For details on blocking I/O,
   * see g_socket_set_blocking().
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if blocking I/O is used, <tt>false</tt> otherwise.
   */
  auto get_blocking() const -> bool;

  /** Sets or unsets the SO_KEEPALIVE flag on the underlying socket. When
   * this flag is set on a socket, the system will attempt to verify that the
   * remote socket endpoint is still present if a sufficiently long period of
   * time passes with no data being exchanged. If the system is unable to
   * verify the presence of the remote endpoint, it will automatically close
   * the connection.
   *
   * This option is only functional on certain kinds of sockets. (Notably,
   * Gio::Socket::Protocol::TCP sockets.)
   *
   * The exact time between pings is system- and protocol-dependent, but will
   * normally be at least two hours. Most commonly, you would set this flag
   * on a server socket if you want to allow clients to remain idle for long
   * periods of time, but also want to ensure that connections are eventually
   * garbage-collected if clients crash or become unreachable.
   *
   * @newin{2,22}
   *
   * @param keepalive Value for the keepalive flag.
   */
  void set_keepalive(bool keepalive);

  /** Gets the keepalive mode of the socket. For details on this,
   * see g_socket_set_keepalive().
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if keepalive is active, <tt>false</tt> otherwise.
   */
  auto get_keepalive() const -> bool;

  /** Gets the socket family of the socket.
   *
   * @newin{2,22}
   *
   * @return A SocketFamily.
   */
  auto get_family() const -> SocketFamily;

  /** Returns the underlying OS socket object. On unix this
   * is a socket file descriptor, and on Windows this is
   * a Winsock2 SOCKET handle. This may be useful for
   * doing platform specific or otherwise unusual operations
   * on the socket.
   *
   * @newin{2,22}
   *
   * @return The file descriptor of the socket.
   */
  auto get_fd() const -> int;

  /** Try to get the local address of a bound socket. This is only
   * useful if the socket has been bound to a local address,
   * either explicitly or implicitly when connecting.
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_local_address() const -> Glib::RefPtr<SocketAddress>;

  /** Try to get the remote address of a connected socket. This is only
   * useful for connection oriented sockets that have been connected.
   *
   * @newin{2,22}
   *
   * @return A SocketAddress or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_remote_address() const -> Glib::RefPtr<SocketAddress>;

  /** Gets the socket protocol id the socket was created with.
   * In case the protocol is unknown, -1 is returned.
   *
   * @newin{2,22}
   *
   * @return A protocol id, or -1 if unknown.
   */
  auto get_protocol() const -> Protocol;

  /** Gets the socket type of the socket.
   *
   * @newin{2,22}
   *
   * @return A Gio::Socket::Type.
   */
  auto get_socket_type() const -> Type;

  /** Checks if a socket is capable of speaking IPv4.
   *
   * IPv4 sockets are capable of speaking IPv4.  On some operating systems
   * and under some combinations of circumstances IPv6 sockets are also
   * capable of speaking IPv4.  See RFC 3493 section 3.7 for more
   * information.
   *
   * No other types of sockets are currently considered as being capable
   * of speaking IPv4.
   *
   * @newin{2,22}
   *
   * @return <tt>true</tt> if this socket can be used with IPv4.
   */
  auto speaks_ipv4() const -> bool;


  /** Returns the credentials of the foreign process connected to this
   * socket, if any (e.g.\ it is only supported for Gio::SocketFamily::UNIX
   * sockets).
   *
   * If this operation isn't supported on the OS, the method fails with
   * the Gio::Error::NOT_SUPPORTED error. On Linux this is implemented
   * by reading the SO_PEERCRED option on the underlying socket.
   *
   * This method can be expected to be available on the following platforms:
   *
   * - Linux since GLib 2.26
   * - OpenBSD since GLib 2.30
   * - Solaris, Illumos and OpenSolaris since GLib 2.40
   * - NetBSD since GLib 2.42
   * - macOS, tvOS, iOS since GLib 2.66
   *
   * Other ways to obtain credentials from a foreign peer includes the
   * UnixCredentialsMessage type and
   * g_unix_connection_send_credentials() /
   * g_unix_connection_receive_credentials() functions.
   *
   * @newin{2,26}
   *
   * @return <tt>nullptr</tt> if @a error is set, otherwise a Credentials object
   * that must be freed with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_credentials() -> Glib::RefPtr<Credentials>;

  /** Returns the credentials of the foreign process connected to this
   * socket, if any (e.g.\ it is only supported for Gio::SocketFamily::UNIX
   * sockets).
   *
   * If this operation isn't supported on the OS, the method fails with
   * the Gio::Error::NOT_SUPPORTED error. On Linux this is implemented
   * by reading the SO_PEERCRED option on the underlying socket.
   *
   * This method can be expected to be available on the following platforms:
   *
   * - Linux since GLib 2.26
   * - OpenBSD since GLib 2.30
   * - Solaris, Illumos and OpenSolaris since GLib 2.40
   * - NetBSD since GLib 2.42
   * - macOS, tvOS, iOS since GLib 2.66
   *
   * Other ways to obtain credentials from a foreign peer includes the
   * UnixCredentialsMessage type and
   * g_unix_connection_send_credentials() /
   * g_unix_connection_receive_credentials() functions.
   *
   * @newin{2,26}
   *
   * @return <tt>nullptr</tt> if @a error is set, otherwise a Credentials object
   * that must be freed with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto get_credentials() const -> Glib::RefPtr<const Credentials>;


  /** Gets the timeout setting of the socket. For details on this, see
   * g_socket_set_timeout().
   *
   * @newin{2,26}
   *
   * @return The timeout in seconds.
   */
  auto get_timeout() const -> guint;

  /** Sets the time in seconds after which I/O operations on @a socket will
   * time out if they have not yet completed.
   *
   * On a blocking socket, this means that any blocking Socket
   * operation will time out after @a timeout seconds of inactivity,
   * returning Gio::Error::TIMED_OUT.
   *
   * On a non-blocking socket, calls to g_socket_condition_wait() will
   * also fail with Gio::Error::TIMED_OUT after the given time. Sources
   * created with g_socket_create_source() will trigger after
   *  @a timeout seconds of inactivity, with the requested condition
   * set, at which point calling g_socket_receive(), g_socket_send(),
   * g_socket_check_connect_result(), etc, will fail with
   * Gio::Error::TIMED_OUT.
   *
   * If @a timeout is 0 (the default), operations will never time out
   * on their own.
   *
   * Note that if an I/O operation is interrupted by a signal, this may
   * cause the timeout to be reset.
   *
   * @newin{2,26}
   *
   * @param timeout The timeout for @a socket, in seconds, or 0 for none.
   */
  void set_timeout(guint timeout);


  /** This behaves exactly the same as g_socket_receive(), except that
   * the choice of blocking or non-blocking behavior is determined by
   * the @a blocking argument rather than by @a socket's properties.
   *
   * @newin{2,26}
   *
   * @param buffer A buffer to read data into (which should be at least @a size bytes long).
   * @param size The number of bytes you want to read from the socket.
   * @param blocking Whether to do blocking or non-blocking I/O.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Number of bytes read, or 0 if the connection was closed by
   * the peer, or -1 on error.
   */

  auto receive_with_blocking(gchar* buffer, gsize size, bool blocking, const Glib::RefPtr<Cancellable>& cancellable = {}) -> gssize;


  /** This behaves exactly the same as g_socket_send(), except that
   * the choice of blocking or non-blocking behavior is determined by
   * the @a blocking argument rather than by @a socket's properties.
   *
   * @newin{2,26}
   *
   * @param buffer The buffer
   * containing the data to send.
   * @param size The number of bytes to send.
   * @param blocking Whether to do blocking or non-blocking I/O.
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Number of bytes written (which may be less than @a size), or -1
   * on error.
   */

  auto send_with_blocking(gchar* buffer, gsize size, bool blocking, const Glib::RefPtr<Cancellable>& cancellable = {}) -> gssize;


  /** Gets the value of an integer-valued option on @a socket, as with
   * getsockopt(). (If you need to fetch a  non-integer-valued option,
   * you will need to call getsockopt() directly.)
   *
   * The [<gio/gnetworking.h>][gio-gnetworking.h]
   * header pulls in system headers that will define most of the
   * standard/portable socket options. For unusual socket protocols or
   * platform-dependent options, you may need to include additional
   * headers.
   *
   * Note that even for socket options that are a single byte in size,
   *  @a value is still a pointer to a <tt>int</tt> variable, not a #guchar;
   * g_socket_get_option() will handle the conversion internally.
   *
   * @newin{2,36}
   *
   * @param level The "API level" of the option (eg, `SOL_SOCKET`).
   * @param optname The "name" of the option (eg, `SO_BROADCAST`).
   * @param value Return location for the option value.
   * @return Success or failure. On failure, @a error will be set, and
   * the system error value (`errno` or WSAGetLastError()) will still
   * be set to the result of the getsockopt() call.
   *
   * @throws Glib::Error
   */
  auto get_option(int level, int optname, int& value) const -> bool;

  /** Sets the value of an integer-valued option on @a socket, as with
   * setsockopt(). (If you need to set a non-integer-valued option,
   * you will need to call setsockopt() directly.)
   *
   * The [<gio/gnetworking.h>][gio-gnetworking.h]
   * header pulls in system headers that will define most of the
   * standard/portable socket options. For unusual socket protocols or
   * platform-dependent options, you may need to include additional
   * headers.
   *
   * @newin{2,36}
   *
   * @param level The "API level" of the option (eg, `SOL_SOCKET`).
   * @param optname The "name" of the option (eg, `SO_BROADCAST`).
   * @param value The value to set the option to.
   * @return Success or failure. On failure, @a error will be set, and
   * the system error value (`errno` or WSAGetLastError()) will still
   * be set to the result of the setsockopt() call.
   *
   * @throws Glib::Error
   */
  auto set_option(int level, int optname, int value) -> bool;


  /** Gets the unicast time-to-live setting on @a socket; see
   * g_socket_set_ttl() for more details.
   *
   * @newin{2,32}
   *
   * @return The time-to-live setting on @a socket.
   */
  auto get_ttl() const -> guint;

  /** Sets the time-to-live for outgoing unicast packets on @a socket.
   * By default the platform-specific default value is used.
   *
   * @newin{2,32}
   *
   * @param ttl The time-to-live value for all unicast packets on @a socket.
   */
  void set_ttl(guint ttl);


  /** Gets the broadcast setting on @a socket; if <tt>true</tt>,
   * it is possible to send packets to broadcast
   * addresses.
   *
   * @newin{2,32}
   *
   * @return The broadcast setting on @a socket.
   */
  auto get_broadcast() const -> bool;

  /** Sets whether @a socket should allow sending to broadcast addresses.
   * This is <tt>false</tt> by default.
   *
   * @newin{2,32}
   *
   * @param broadcast Whether @a socket should allow sending to broadcast
   * addresses.
   */
  void set_broadcast(bool broadcast);


  /** Gets the multicast loopback setting on @a socket; if <tt>true</tt> (the
   * default), outgoing multicast packets will be looped back to
   * multicast listeners on the same host.
   *
   * @newin{2,32}
   *
   * @return The multicast loopback setting on @a socket.
   */
  auto get_multicast_loopback() const -> bool;

  /** Sets whether outgoing multicast packets will be received by sockets
   * listening on that multicast address on the same host. This is <tt>true</tt>
   * by default.
   *
   * @newin{2,32}
   *
   * @param loopback Whether @a socket should receive messages sent to its
   * multicast groups from the local host.
   */
  void set_multicast_loopback(bool loopback);

  /** Gets the multicast time-to-live setting on @a socket; see
   * g_socket_set_multicast_ttl() for more details.
   *
   * @newin{2,32}
   *
   * @return The multicast time-to-live setting on @a socket.
   */
  auto get_multicast_ttl() const -> guint;

  /** Sets the time-to-live for outgoing multicast datagrams on @a socket.
   * By default, this is 1, meaning that multicast packets will not leave
   * the local network.
   *
   * @newin{2,32}
   *
   * @param ttl The time-to-live value for all multicast datagrams on @a socket.
   */
  void set_multicast_ttl(guint ttl);


  /** Registers @a socket to receive multicast messages sent to @a group.
   *  @a socket must be a Gio::Socket::Type::DATAGRAM socket, and must have
   * been bound to an appropriate interface and port with
   * g_socket_bind().
   *
   * If @a iface is <tt>nullptr</tt>, the system will automatically pick an interface
   * to bind to based on @a group.
   *
   * If @a source_specific is <tt>true</tt>, source-specific multicast as defined
   * in RFC 4604 is used. Note that on older platforms this may fail
   * with a Gio::Error::NOT_SUPPORTED error.
   *
   * To bind to a given source-specific multicast address, use
   * g_socket_join_multicast_group_ssm() instead.
   *
   * @newin{2,32}
   *
   * @param group A InetAddress specifying the group address to join.
   * @param iface Name of the interface to use, or <tt>nullptr</tt>.
   * @param source_specific <tt>true</tt> if source-specific multicast should be used.
   * @return <tt>true</tt> on success, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto join_multicast_group(const Glib::RefPtr<InetAddress>& group, bool source_specific, const std::string& iface) -> bool;

  /// A join_multicast_group() convenience overload.
  auto join_multicast_group(const Glib::RefPtr<InetAddress>& group, bool source_specific) -> bool;

  /** Removes @a socket from the multicast group defined by @a group, @a iface,
   * and @a source_specific (which must all have the same values they had
   * when you joined the group).
   *
   *  @a socket remains bound to its address and port, and can still receive
   * unicast messages after calling this.
   *
   * To unbind to a given source-specific multicast address, use
   * g_socket_leave_multicast_group_ssm() instead.
   *
   * @newin{2,32}
   *
   * @param group A InetAddress specifying the group address to leave.
   * @param iface Interface used.
   * @param source_specific <tt>true</tt> if source-specific multicast was used.
   * @return <tt>true</tt> on success, <tt>false</tt> on error.
   *
   * @throws Glib::Error
   */
  auto leave_multicast_group(const Glib::RefPtr<InetAddress>& group, bool source_specific, const std::string& iface) -> bool;

  /// A leave_multicast_group() convenience overload.
  auto leave_multicast_group(const Glib::RefPtr<InetAddress>& group, bool source_specific) -> bool;


  /** Whether or not I/O on this socket is blocking.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_blocking() -> Glib::PropertyProxy< bool > ;

/** Whether or not I/O on this socket is blocking.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_blocking() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The sockets address family.
   *
   * Default value: Gio::SocketFamily::INVALID
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >;


  /** The sockets file descriptor.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fd() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Keep connection alive by sending periodic pings.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keepalive() -> Glib::PropertyProxy< bool > ;

/** Keep connection alive by sending periodic pings.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keepalive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Outstanding connections in the listen queue.
   *
   * Default value: 10
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_listen_backlog() -> Glib::PropertyProxy< int > ;

/** Outstanding connections in the listen queue.
   *
   * Default value: 10
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_listen_backlog() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The local address the socket is bound to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_local_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketAddress> >;


  /** The remote address the socket is connected to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_remote_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketAddress> >;


  /** The timeout in seconds on socket I/O
   *
   * @newin{2,26}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_timeout() -> Glib::PropertyProxy< guint > ;

/** The timeout in seconds on socket I/O
   *
   * @newin{2,26}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** The id of the protocol to use, or -1 for unknown.
   *
   * Default value: Gio::Socket::Protocol::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_protocol() const -> Glib::PropertyProxy_ReadOnly< Protocol >;


  /** Whether the socket should allow sending to broadcast addresses.
   *
   * @newin{2,32}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_broadcast() -> Glib::PropertyProxy< bool > ;

/** Whether the socket should allow sending to broadcast addresses.
   *
   * @newin{2,32}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_broadcast() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The sockets type.
   *
   * Default value: Gio::Socket::Type::STREAM
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_type() const -> Glib::PropertyProxy_ReadOnly< Type >;


  /** Time-to-live for outgoing unicast packets
   *
   * @newin{2,32}
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ttl() -> Glib::PropertyProxy< guint > ;

/** Time-to-live for outgoing unicast packets
   *
   * @newin{2,32}
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ttl() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** Whether outgoing multicast packets loop back to the local host.
   *
   * @newin{2,32}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_multicast_loopback() -> Glib::PropertyProxy< bool > ;

/** Whether outgoing multicast packets loop back to the local host.
   *
   * @newin{2,32}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_multicast_loopback() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Time-to-live out outgoing multicast packets
   *
   * @newin{2,32}
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_multicast_ttl() -> Glib::PropertyProxy< guint > ;

/** Time-to-live out outgoing multicast packets
   *
   * @newin{2,32}
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_multicast_ttl() const -> Glib::PropertyProxy_ReadOnly< guint >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Socket::Type> : public Glib::Value_Enum<Gio::Socket::Type>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Socket::Protocol> : public Glib::Value_Enum<Gio::Socket::Protocol>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  { return static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  { return static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Socket::MsgFlags lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags
  { return static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Socket::MsgFlags flags) -> Socket::MsgFlags
  { return static_cast<Socket::MsgFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  { return (lhs = static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  { return (lhs = static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Socket::MsgFlags& lhs, Socket::MsgFlags rhs) -> Socket::MsgFlags&
  { return (lhs = static_cast<Socket::MsgFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Socket::MsgFlags> : public Glib::Value_Flags<Gio::Socket::MsgFlags>
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
   * @relates Gio::Socket
   */
  GIOMM_API
  auto wrap(GSocket* object, bool take_copy = false) -> Glib::RefPtr<Gio::Socket>;
}


#endif /* _GIOMM_SOCKET_H */

