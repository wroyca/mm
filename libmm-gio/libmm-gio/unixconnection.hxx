
#ifndef _GIOMM_UNIXCONNECTION_H
#define _GIOMM_UNIXCONNECTION_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-glib/object.hxx>
#include <libmm-gio/socketconnection.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixConnection = struct _GUnixConnection;
using GUnixConnectionClass = struct _GUnixConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API UnixConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/**
 * A Unix domain SocketConnection
 *
 * This is the subclass of SocketConnection that is created
 * for UNIX domain sockets.
 *
 * It contains functions to do some of the unix socket specific
 * functionallity like passing file descriptors.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API UnixConnection : public Gio::SocketConnection
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UnixConnection;
  using CppClassType = UnixConnection_Class;
  using BaseObjectType = GUnixConnection;
  using BaseClassType = GUnixConnectionClass;

  // noncopyable
  UnixConnection(const UnixConnection&) = delete;
  auto operator=(const UnixConnection&) -> UnixConnection& = delete;

private:  friend class UnixConnection_Class;
  static CppClassType unixconnection_class_;

protected:
  explicit UnixConnection(const Glib::ConstructParams& construct_params);
  explicit UnixConnection(GUnixConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UnixConnection(UnixConnection&& src) noexcept;
  auto operator=(UnixConnection&& src) noexcept -> UnixConnection&;

  ~UnixConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GUnixConnection*       { return reinterpret_cast<GUnixConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GUnixConnection* { return reinterpret_cast<GUnixConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GUnixConnection*;

private:

    //This is not available on Win32.
//This source file will not be compiled on Win32,
//and no class defined in it will be registered by wrap_init().


public:

  /** Passes a file descriptor to the receiving side of the
   * connection. The receiving end has to call g_unix_connection_receive_fd()
   * to accept the file descriptor.
   *
   * As well as sending the fd this also writes a single byte to the
   * stream, as this is required for fd passing to work on some
   * implementations.
   *
   * @newin{2,22}
   *
   * @param fd A file descriptor.
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A <tt>true</tt> on success, <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto send_fd(int fd, const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A send_fd() convenience overload.
  auto send_fd(int fd) -> bool;

  /** Receives a file descriptor from the sending end of the connection.
   * The sending end has to call g_unix_connection_send_fd() for this
   * to work.
   *
   * As well as reading the fd this also reads a single byte from the
   * stream, as this is required for fd passing to work on some
   * implementations.
   *
   * @newin{2,22}
   *
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A file descriptor on success, -1 on error.
   *
   * @throws Glib::Error
   */
  auto receive_fd(const Glib::RefPtr<Cancellable>& cancellable) -> int;

  /// A receive_fd() convenience overload.
  auto receive_fd() -> int;


  /** Receives credentials from the sending end of the connection.  The
   * sending end has to call g_unix_connection_send_credentials() (or
   * similar) for this to work.
   *
   * As well as reading the credentials this also reads (and discards) a
   * single byte from the stream, as this is required for credentials
   * passing to work on some implementations.
   *
   * This method can be expected to be available on the following platforms:
   *
   * - Linux since GLib 2.26
   * - FreeBSD since GLib 2.26
   * - GNU/kFreeBSD since GLib 2.36
   * - Solaris, Illumos and OpenSolaris since GLib 2.40
   * - GNU/Hurd since GLib 2.40
   *
   * Other ways to exchange credentials with a foreign peer includes the
   * UnixCredentialsMessage type and g_socket_get_credentials() function.
   *
   * @newin{2,26}
   *
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Received credentials on success (free with
   * Glib::object_unref()), <tt>nullptr</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto receive_credentials(const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Credentials>;

  /// A receive_credentials() convenience overload.
  auto receive_credentials() -> Glib::RefPtr<Credentials>;

  /** Receives credentials from the sending end of the connection.  The
   * sending end has to call g_unix_connection_send_credentials() (or
   * similar) for this to work.
   *
   * As well as reading the credentials this also reads (and discards) a
   * single byte from the stream, as this is required for credentials
   * passing to work on some implementations.
   *
   * This method can be expected to be available on the following platforms:
   *
   * - Linux since GLib 2.26
   * - FreeBSD since GLib 2.26
   * - GNU/kFreeBSD since GLib 2.36
   * - Solaris, Illumos and OpenSolaris since GLib 2.40
   * - GNU/Hurd since GLib 2.40
   *
   * Other ways to exchange credentials with a foreign peer includes the
   * UnixCredentialsMessage type and g_socket_get_credentials() function.
   *
   * @newin{2,26}
   *
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return Received credentials on success (free with
   * Glib::object_unref()), <tt>nullptr</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto receive_credentials(const Glib::RefPtr<Cancellable>& cancellable) const -> Glib::RefPtr<const Credentials>;

  /// A receive_credentials() convenience overload.
  auto receive_credentials() const -> Glib::RefPtr<const Credentials>;

  /**  Asynchronously receive credentials.
   * For more details, see receive_credentials() which is the synchronous
   * version of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call
   * receive_credentials_finish() to get the result of the operation.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @newin{2,36}
   */
  void receive_credentials_async(const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable);


  /// A non-cancellable version of receive_credentials_async().
  void receive_credentials_async(const SlotAsyncReady& slot);


  /** Finishes an asynchronous receive credentials operation started with
   * g_unix_connection_receive_credentials_async().
   *
   * @newin{2,32}
   *
   * @param result A AsyncResult.
   * @return A Credentials, or <tt>nullptr</tt> on error.
   * Free the returned object with Glib::object_unref().
   *
   * @throws Glib::Error
   */
  auto receive_credentials_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<Credentials>;


  /** Passes the credentials of the current user the receiving side
   * of the connection. The receiving end has to call
   * g_unix_connection_receive_credentials() (or similar) to accept the
   * credentials.
   *
   * As well as sending the credentials this also writes a single NUL
   * byte to the stream, as this is required for credentials passing to
   * work on some implementations.
   *
   * This method can be expected to be available on the following platforms:
   *
   * - Linux since GLib 2.26
   * - FreeBSD since GLib 2.26
   * - GNU/kFreeBSD since GLib 2.36
   * - Solaris, Illumos and OpenSolaris since GLib 2.40
   * - GNU/Hurd since GLib 2.40
   *
   * Other ways to exchange credentials with a foreign peer includes the
   * UnixCredentialsMessage type and g_socket_get_credentials() function.
   *
   * @newin{2,26}
   *
   * @param cancellable A Cancellable or <tt>nullptr</tt>.
   * @return <tt>true</tt> on success, <tt>false</tt> if @a error is set.
   *
   * @throws Glib::Error
   */
  auto send_credentials(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A send_credentials() convenience overload.
  auto send_credentials() -> bool;

  /**  Asynchronously send credentials.
   * For more details, see send_credentials() which is the synchronous version
   * of this call.
   *
   * When the operation is finished, @a slot will be called. You can then call
   * send_credentials_finish() to get the result of the operation.
   *
   * @param slot A SlotAsyncReady to call when the request is satisfied.
   * @param cancellable A Cancellable object.
   * @newin{2,36}
   */
  void send_credentials_async(const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable);


  /// A non-cancellable version of send_credentials_async().
  void send_credentials_async(const SlotAsyncReady& slot);


  /** Finishes an asynchronous send credentials operation started with
   * g_unix_connection_send_credentials_async().
   *
   * @newin{2,32}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> if the operation was successful, otherwise <tt>false</tt>.
   *
   * @throws Glib::Error
   */
  auto send_credentials_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


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
   * @relates Gio::UnixConnection
   */
  GIOMM_API
  auto wrap(GUnixConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixConnection>;
}


#endif /* _GIOMM_UNIXCONNECTION_H */

