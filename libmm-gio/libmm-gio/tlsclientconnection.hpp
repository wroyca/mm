
#ifndef _GIOMM_TLSCLIENTCONNECTION_H
#define _GIOMM_TLSCLIENTCONNECTION_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The giomm Development Team
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

#include <libmm-glib/interface.hpp>
#include <libmm-gio/enums.hpp>
#include <libmm-gio/iostream.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTlsClientConnectionInterface GTlsClientConnectionInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsClientConnection = struct _GTlsClientConnection;
using GTlsClientConnectionClass = struct _GTlsClientConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsClientConnection_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{
class GLIBMM_API ByteArray;
}

namespace Gio
{

class GIOMM_API SocketConnectable;
class GIOMM_API TlsClientConnectionImpl;

// See https://bugzilla.gnome.org/show_bug.cgi?id=776537
// especially the last paragraph of comment 6.

/** TLS client-side connection.
 * %TlsClientConnection is the client-side subclass of TlsConnection,
 * representing a client-side TLS connection.
 * @newin{2,36}
 */

class GIOMM_API TlsClientConnection : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsClientConnection;
  using CppClassType = TlsClientConnection_Class;
  using BaseObjectType = GTlsClientConnection;
  using BaseClassType = GTlsClientConnectionInterface;

  // noncopyable
  TlsClientConnection(const TlsClientConnection&) = delete;
  auto operator=(const TlsClientConnection&) -> TlsClientConnection& = delete;

private:
  friend class TlsClientConnection_Class;
  static CppClassType tlsclientconnection_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  TlsClientConnection();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit TlsClientConnection(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit TlsClientConnection(GTlsClientConnection* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsClientConnection(TlsClientConnection&& src) noexcept;
  auto operator=(TlsClientConnection&& src) noexcept -> TlsClientConnection&;

  ~TlsClientConnection() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsClientConnection*       { return reinterpret_cast<GTlsClientConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsClientConnection* { return reinterpret_cast<GTlsClientConnection*>(gobject_); }

private:


public:
  // It's not possible to use _WRAP_CTOR/_WRAP_CREATE to wrap the new
  // function because this is an interface.


  /** Creates a new TlsClientConnection wrapping @a base_io_stream (which
   * must have pollable input and output streams) which is assumed to
   * communicate with the server identified by @a server_identity.
   *
   * See the documentation for TlsConnection::property_base_io_stream() for restrictions
   * on when application code can run operations on the @a base_io_stream after
   * this function has returned.
   *
   * @newin{2,28}
   *
   * @param base_io_stream The IOStream to wrap.
   * @param server_identity The expected identity of the server.
   * @return The new
   * TlsClientConnection, or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  static auto create(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<const SocketConnectable>& server_identity) -> Glib::RefPtr<TlsClientConnectionImpl>;

  /// A create() convenience overload.
  static auto create(const Glib::RefPtr<IOStream>& base_io_stream) -> Glib::RefPtr<TlsClientConnectionImpl>;


  /** Sets @a conn's expected server identity, which is used both to tell
   * servers on virtual hosts which certificate to present, and also
   * to let @a conn know what name to look for in the certificate when
   * performing Gio::TlsCertificateFlags::BAD_IDENTITY validation, if enabled.
   *
   * @newin{2,28}
   *
   * @param identity A SocketConnectable describing the expected server identity.
   */
  void set_server_identity(const Glib::RefPtr<SocketConnectable>& identity);


  /** Gets @a conn's expected server identity
   *
   * @newin{2,28}
   *
   * @return A SocketConnectable describing the
   * expected server identity, or <tt>nullptr</tt> if the expected identity is not
   * known.
   */
  auto get_server_identity() -> Glib::RefPtr<SocketConnectable>;

  /** Gets @a conn's expected server identity
   *
   * @newin{2,28}
   *
   * @return A SocketConnectable describing the
   * expected server identity, or <tt>nullptr</tt> if the expected identity is not
   * known.
   */
  auto get_server_identity() const -> Glib::RefPtr<const SocketConnectable>;


#ifndef GIOMM_DISABLE_DEPRECATED

  /** Sets @a conn's validation flags, to override the default set of
   * checks performed when validating a server certificate. By default,
   * Gio::TlsCertificateFlags::VALIDATE_ALL is used.
   *
   * This function does not work as originally designed and is impossible
   * to use correctly. See TlsClientConnection::property_validation_flags() for more
   * information.
   *
   * @newin{2,28}
   *
   * Deprecated: 2.72: Do not attempt to ignore validation errors.
   *
   * @deprecated Do not attempt to ignore validation errors.
   *
   * @param flags The TlsCertificateFlags to use.
   */
  void set_validation_flags(TlsCertificateFlags flags);
#endif // GIOMM_DISABLE_DEPRECATED


#ifndef GIOMM_DISABLE_DEPRECATED

  /** Gets @a conn's validation flags
   *
   * This function does not work as originally designed and is impossible
   * to use correctly. See TlsClientConnection::property_validation_flags() for more
   * information.
   *
   * @newin{2,28}
   *
   * Deprecated: 2.72: Do not attempt to ignore validation errors.
   *
   * @deprecated Do not attempt to ignore validation errors.
   *
   * @return The validation flags.
   */
  auto get_validation_flags() const -> TlsCertificateFlags;
#endif // GIOMM_DISABLE_DEPRECATED


  /** Gets the list of distinguished names of the Certificate Authorities
   * that the server will accept certificates from. This will be set
   * during the TLS handshake if the server requests a certificate.
   * Otherwise, it will be <tt>nullptr</tt>.
   *
   * Each item in the list is a ByteArray which contains the complete
   * subject DN of the certificate authority.
   *
   * @newin{2,28}
   *
   * @return The list of
   * CA DNs.
   */
  auto get_accepted_cas() -> std::vector< Glib::RefPtr<Glib::ByteArray> >;


  /** Gets the list of distinguished names of the Certificate Authorities
   * that the server will accept certificates from. This will be set
   * during the TLS handshake if the server requests a certificate.
   * Otherwise, it will be <tt>nullptr</tt>.
   *
   * Each item in the list is a ByteArray which contains the complete
   * subject DN of the certificate authority.
   *
   * @newin{2,28}
   *
   * @return The list of
   * CA DNs.
   */
  auto get_accepted_cas() const -> std::vector< Glib::RefPtr<const Glib::ByteArray> >;


  /** Possibly copies session state from one connection to another, for use
   * in TLS session resumption. This is not normally needed, but may be
   * used when the same session needs to be used between different
   * endpoints, as is required by some protocols, such as FTP over TLS.
   *  @a source should have already completed a handshake and, since TLS 1.3,
   * it should have been used to read data at least once. @a conn should not
   * have completed a handshake.
   *
   * It is not possible to know whether a call to this function will
   * actually do anything. Because session resumption is normally used
   * only for performance benefit, the TLS backend might not implement
   * this function. Even if implemented, it may not actually succeed in
   * allowing @a conn to resume @a source's TLS session, because the server
   * may not have sent a session resumption token to @a source, or it may
   * refuse to accept the token from @a conn. There is no way to know
   * whether a call to this function is actually successful.
   *
   * Using this function is not required to benefit from session
   * resumption. If the TLS backend supports session resumption, the
   * session will be resumed automatically if it is possible to do so
   * without weakening the privacy guarantees normally provided by TLS,
   * without need to call this function. For example, with TLS 1.3,
   * a session ticket will be automatically copied from any
   * TlsClientConnection that has previously received session tickets
   * from the server, provided a ticket is available that has not
   * previously been used for session resumption, since session ticket
   * reuse would be a privacy weakness. Using this function causes the
   * ticket to be copied without regard for privacy considerations.
   *
   * @newin{2,46}
   *
   * @param source A TlsClientConnection.
   */
  void copy_session_state(const Glib::RefPtr<TlsClientConnection>& source);

  // property_accepted_cas() won't work unless a Glib::Value<std::vector<Glib::RefPtr<Glib::ByteArray>>>
  // specialization is added. Workaround: Use get_accepted_cas().
  //_WRAP_PROPERTY("accepted-cas", std::vector<Glib::RefPtr<Glib::ByteArray>>)
  /** A SocketConnectable describing the identity of the server that
   * is expected on the other end of the connection.
   *
   * If the Gio::TlsCertificateFlags::BAD_IDENTITY flag is set in
   * TlsClientConnection::property_validation_flags(), this object will be used
   * to determine the expected identify of the remote end of the
   * connection; if TlsClientConnection::property_server_identity() is not set,
   * or does not match the identity presented by the server, then the
   * Gio::TlsCertificateFlags::BAD_IDENTITY validation will fail.
   *
   * In addition to its use in verifying the server certificate,
   * this is also used to give a hint to the server about what
   * certificate we expect, which is useful for servers that serve
   * virtual hosts.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_server_identity() -> Glib::PropertyProxy< Glib::RefPtr<SocketConnectable> > ;

/** A SocketConnectable describing the identity of the server that
   * is expected on the other end of the connection.
   *
   * If the Gio::TlsCertificateFlags::BAD_IDENTITY flag is set in
   * TlsClientConnection::property_validation_flags(), this object will be used
   * to determine the expected identify of the remote end of the
   * connection; if TlsClientConnection::property_server_identity() is not set,
   * or does not match the identity presented by the server, then the
   * Gio::TlsCertificateFlags::BAD_IDENTITY validation will fail.
   *
   * In addition to its use in verifying the server certificate,
   * this is also used to give a hint to the server about what
   * certificate we expect, which is useful for servers that serve
   * virtual hosts.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_server_identity() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketConnectable> >;


#ifndef GIOMM_DISABLE_DEPRECATED

/** What steps to perform when validating a certificate received from
   * a server. Server certificates that fail to validate in any of the
   * ways indicated here will be rejected unless the application
   * overrides the default via TlsConnection::signal_accept_certificate().
   *
   * GLib guarantees that if certificate verification fails, at least one
   * flag will be set, but it does not guarantee that all possible flags
   * will be set. Accordingly, you may not safely decide to ignore any
   * particular type of error. For example, it would be incorrect to mask
   * Gio::TlsCertificateFlags::EXPIRED if you want to allow expired certificates,
   * because this could potentially be the only error flag set even if
   * other problems exist with the certificate. Therefore, there is no
   * safe way to use this property. This is not a horrible problem,
   * though, because you should not be attempting to ignore validation
   * errors anyway. If you really must ignore TLS certificate errors,
   * connect to TlsConnection::signal_accept_certificate().
   *
   * @newin{2,28}
   *
   * Deprecated: 2.72: Do not attempt to ignore validation errors.
   *
   * @deprecated Do not attempt to ignore validation errors.
   *
   * Default value: Gio::TlsCertificateFlags::UNKNOWN_CA | Gio::TlsCertificateFlags::BAD_IDENTITY | Gio::TlsCertificateFlags::NOT_ACTIVATED | Gio::TlsCertificateFlags::EXPIRED | Gio::TlsCertificateFlags::REVOKED | Gio::TlsCertificateFlags::INSECURE | Gio::TlsCertificateFlags::GENERIC_ERROR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_validation_flags() -> Glib::PropertyProxy< TlsCertificateFlags > ;

/** What steps to perform when validating a certificate received from
   * a server. Server certificates that fail to validate in any of the
   * ways indicated here will be rejected unless the application
   * overrides the default via TlsConnection::signal_accept_certificate().
   *
   * GLib guarantees that if certificate verification fails, at least one
   * flag will be set, but it does not guarantee that all possible flags
   * will be set. Accordingly, you may not safely decide to ignore any
   * particular type of error. For example, it would be incorrect to mask
   * Gio::TlsCertificateFlags::EXPIRED if you want to allow expired certificates,
   * because this could potentially be the only error flag set even if
   * other problems exist with the certificate. Therefore, there is no
   * safe way to use this property. This is not a horrible problem,
   * though, because you should not be attempting to ignore validation
   * errors anyway. If you really must ignore TLS certificate errors,
   * connect to TlsConnection::signal_accept_certificate().
   *
   * @newin{2,28}
   *
   * Deprecated: 2.72: Do not attempt to ignore validation errors.
   *
   * @deprecated Do not attempt to ignore validation errors.
   *
   * Default value: Gio::TlsCertificateFlags::UNKNOWN_CA | Gio::TlsCertificateFlags::BAD_IDENTITY | Gio::TlsCertificateFlags::NOT_ACTIVATED | Gio::TlsCertificateFlags::EXPIRED | Gio::TlsCertificateFlags::REVOKED | Gio::TlsCertificateFlags::INSECURE | Gio::TlsCertificateFlags::GENERIC_ERROR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_validation_flags() const -> Glib::PropertyProxy_ReadOnly< TlsCertificateFlags >;

#endif // GIOMM_DISABLE_DEPRECATED


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
   * @relates Gio::TlsClientConnection
   */
  GIOMM_API
  auto wrap(GTlsClientConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsClientConnection>;

} // namespace Glib


#endif /* _GIOMM_TLSCLIENTCONNECTION_H */

