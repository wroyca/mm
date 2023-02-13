
#ifndef _GIOMM_TLSCONNECTION_H
#define _GIOMM_TLSCONNECTION_H

#include <libmm-gio/gioconfig.hpp>


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


#include <libmm-gio/iostream.hpp>
#include <libmm-gio/tlscertificate.hpp>
#include <libmm-gio/asyncresult.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsConnection = struct _GTlsConnection;
using GTlsConnectionClass = struct _GTlsConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var TlsProtocolVersion UNKNOWN
 * No protocol version or unknown protocol version.
 *
 *  @var TlsProtocolVersion SSL_3_0
 * SSL 3.0, which is insecure and should not be used.
 *
 *  @var TlsProtocolVersion TLS_1_0
 * TLS 1.0, which is insecure and should not be used.
 *
 *  @var TlsProtocolVersion TLS_1_1
 * TLS 1.1, which is insecure and should not be used.
 *
 *  @var TlsProtocolVersion TLS_1_2
 * TLS 1.2, defined by [RFC 5246](https://datatracker.ietf.org/doc/html/rfc5246).
 *
 *  @var TlsProtocolVersion TLS_1_3
 * TLS 1.3, defined by [RFC 8446](https://datatracker.ietf.org/doc/html/rfc8446).
 *
 *  @var TlsProtocolVersion DTLS_1_0
 * DTLS 1.0, which is insecure and should not be used.
 *
 *  @var TlsProtocolVersion DTLS_1_2
 * DTLS 1.2, defined by [RFC 6347](https://datatracker.ietf.org/doc/html/rfc6347).
 *
 *  @enum TlsProtocolVersion
 *
 * The TLS or DTLS protocol version used by a TlsConnection or
 * DtlsConnection. The integer values of these versions are sequential
 * to ensure newer known protocol versions compare greater than older
 * known versions. Any known DTLS protocol version will compare greater
 * than any SSL or TLS protocol version. The protocol version may be
 * Gio::TlsProtocolVersion::UNKNOWN if the TLS backend supports a newer
 * protocol version that GLib does not yet know about. This means that
 * it's possible for an unknown DTLS protocol version to compare less
 * than the TLS protocol versions.
 *
 * @newin{2,70}
 *
 * @ingroup giommEnums
 */
enum class TlsProtocolVersion
{
  UNKNOWN = 0,
  SSL_3_0 = 1,
  TLS_1_0 = 2,
  TLS_1_1 = 3,
  TLS_1_2 = 4,
  TLS_1_3 = 5,
  DTLS_1_0 = 201,
  DTLS_1_2 = 202
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsProtocolVersion> : public Glib::Value_Enum<Gio::TlsProtocolVersion>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


class GIOMM_API Cancellable;
class GIOMM_API TlsDatabase;
class GIOMM_API TlsInteraction;

/** TLS connection type.
 * %TlsConnection is the base TLS connection class type, which wraps an IOStream
 * and provides TLS encryption on top of it. Its subclasses that implement
 * TlsClientConnection and TlsServerConnection, implement client-side and
 * server-side TLS, respectively.
 * @newin{2,36}
 */

class GIOMM_API TlsConnection : public IOStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsConnection;
  using CppClassType = TlsConnection_Class;
  using BaseObjectType = GTlsConnection;
  using BaseClassType = GTlsConnectionClass;

  // noncopyable
  TlsConnection(const TlsConnection&) = delete;
  auto operator=(const TlsConnection&) -> TlsConnection& = delete;

private:  friend class TlsConnection_Class;
  static CppClassType tlsconnection_class_;

protected:
  explicit TlsConnection(const Glib::ConstructParams& construct_params);
  explicit TlsConnection(GTlsConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsConnection(TlsConnection&& src) noexcept;
  auto operator=(TlsConnection&& src) noexcept -> TlsConnection&;

  ~TlsConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsConnection*       { return reinterpret_cast<GTlsConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsConnection* { return reinterpret_cast<GTlsConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTlsConnection*;

private:


protected:
  TlsConnection();

public:

  /** This sets the certificate that @a conn will present to its peer
   * during the TLS handshake. For a TlsServerConnection, it is
   * mandatory to set this, and that will normally be done at construct
   * time.
   *
   * For a TlsClientConnection, this is optional. If a handshake fails
   * with Gio::TlsError::CERTIFICATE_REQUIRED, that means that the server
   * requires a certificate, and if you try connecting again, you should
   * call this method first. You can call
   * g_tls_client_connection_get_accepted_cas() on the failed connection
   * to get a list of Certificate Authorities that the server will
   * accept certificates from.
   *
   * (It is also possible that a server will allow the connection with
   * or without a certificate; in that case, if you don't provide a
   * certificate, you can tell that the server requested one by the fact
   * that g_tls_client_connection_get_accepted_cas() will return
   * non-<tt>nullptr</tt>.)
   *
   * @newin{2,28}
   *
   * @param certificate The certificate to use for @a conn.
   */
  void set_certificate(const Glib::RefPtr<TlsCertificate>& certificate);


  /** Gets @a conn's certificate, as set by
   * g_tls_connection_set_certificate().
   *
   * @newin{2,28}
   *
   * @return  @a conn's certificate, or <tt>nullptr</tt>.
   */
  auto get_certificate() -> Glib::RefPtr<TlsCertificate>;

  /** Gets @a conn's certificate, as set by
   * g_tls_connection_set_certificate().
   *
   * @newin{2,28}
   *
   * @return  @a conn's certificate, or <tt>nullptr</tt>.
   */
  auto get_certificate() const -> Glib::RefPtr<const TlsCertificate>;


  /** Gets @a conn's peer's certificate after the handshake has completed
   * or failed. (It is not set during the emission of
   * TlsConnection::signal_accept_certificate().)
   *
   * @newin{2,28}
   *
   * @return  @a conn's peer's certificate, or <tt>nullptr</tt>.
   */
  auto get_peer_certificate() -> Glib::RefPtr<TlsCertificate>;

  /** Gets @a conn's peer's certificate after the handshake has completed
   * or failed. (It is not set during the emission of
   * TlsConnection::signal_accept_certificate().)
   *
   * @newin{2,28}
   *
   * @return  @a conn's peer's certificate, or <tt>nullptr</tt>.
   */
  auto get_peer_certificate() const -> Glib::RefPtr<const TlsCertificate>;


  /** Gets the errors associated with validating @a conn's peer's
   * certificate, after the handshake has completed or failed. (It is
   * not set during the emission of TlsConnection::signal_accept_certificate().)
   *
   * See TlsConnection::property_peer_certificate_errors() for more information.
   *
   * @newin{2,28}
   *
   * @return  @a conn's peer's certificate errors.
   */
  auto get_peer_certificate_errors() const -> TlsCertificateFlags;


  /** Sets whether or not @a conn expects a proper TLS close notification
   * before the connection is closed. If this is <tt>true</tt> (the default),
   * then @a conn will expect to receive a TLS close notification from its
   * peer before the connection is closed, and will return a
   * Gio::TlsError::EOF error if the connection is closed without proper
   * notification (since this may indicate a network error, or
   * man-in-the-middle attack).
   *
   * In some protocols, the application will know whether or not the
   * connection was closed cleanly based on application-level data
   * (because the application-level data includes a length field, or is
   * somehow self-delimiting); in this case, the close notify is
   * redundant and sometimes omitted. (TLS 1.1 explicitly allows this;
   * in TLS 1.0 it is technically an error, but often done anyway.) You
   * can use g_tls_connection_set_require_close_notify() to tell @a conn
   * to allow an "unannounced" connection close, in which case the close
   * will show up as a 0-length read, as in a non-TLS
   * SocketConnection, and it is up to the application to check that
   * the data has been fully received.
   *
   * Note that this only affects the behavior when the peer closes the
   * connection; when the application calls g_io_stream_close() itself
   * on @a conn, this will send a close notification regardless of the
   * setting of this property. If you explicitly want to do an unclean
   * close, you can close @a conn's TlsConnection::property_base_io_stream() rather
   * than closing @a conn itself, but note that this may only be done when no other
   * operations are pending on @a conn or the base I/O stream.
   *
   * @newin{2,28}
   *
   * @param require_close_notify Whether or not to require close notification.
   */
  void set_require_close_notify(bool require_close_notify =  true);

  /** Tests whether or not @a conn expects a proper TLS close notification
   * when the connection is closed. See
   * g_tls_connection_set_require_close_notify() for details.
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if @a conn requires a proper TLS close
   * notification.
   */
  auto get_require_close_notify() const -> bool;


  /** Gets the certificate database that @a conn uses to verify
   * peer certificates. See g_tls_connection_set_database().
   *
   * @newin{2,30}
   *
   * @return The certificate database that @a conn uses or <tt>nullptr</tt>.
   */
  auto get_database() -> Glib::RefPtr<TlsDatabase>;

  /** Gets the certificate database that @a conn uses to verify
   * peer certificates. See g_tls_connection_set_database().
   *
   * @newin{2,30}
   *
   * @return The certificate database that @a conn uses or <tt>nullptr</tt>.
   */
  auto get_database() const -> Glib::RefPtr<const TlsDatabase>;


  /** Sets the certificate database that is used to verify peer certificates.
   * This is set to the default database by default. See
   * g_tls_backend_get_default_database(). If set to <tt>nullptr</tt>, then
   * peer certificate validation will always set the
   * Gio::TlsCertificateFlags::UNKNOWN_CA error (meaning
   * TlsConnection::signal_accept_certificate() will always be emitted on
   * client-side connections, unless that bit is not set in
   * TlsClientConnection::property_validation_flags()).
   *
   * There are nonintuitive security implications when using a non-default
   * database. See TlsConnection::property_database() for details.
   *
   * @newin{2,30}
   *
   * @param database A TlsDatabase.
   */
  void set_database(const Glib::RefPtr<TlsDatabase>& database);


  /** Get the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords. If <tt>nullptr</tt> is returned, then
   * no user interaction will occur for this connection.
   *
   * @newin{2,30}
   *
   * @return The interaction object.
   */
  auto get_interaction() -> Glib::RefPtr<TlsInteraction>;

  /** Get the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords. If <tt>nullptr</tt> is returned, then
   * no user interaction will occur for this connection.
   *
   * @newin{2,30}
   *
   * @return The interaction object.
   */
  auto get_interaction() const -> Glib::RefPtr<const TlsInteraction>;


  /** Set the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords.
   *
   * The @a interaction argument will normally be a derived subclass of
   * TlsInteraction. <tt>nullptr</tt> can also be provided if no user interaction
   * should occur for this connection.
   *
   * @newin{2,30}
   *
   * @param interaction An interaction object, or <tt>nullptr</tt>.
   */
  void set_interaction(const Glib::RefPtr<TlsInteraction>& interaction);


  /** Attempts a TLS handshake on @a conn.
   *
   * On the client side, it is never necessary to call this method;
   * although the connection needs to perform a handshake after
   * connecting (or after sending a "STARTTLS"-type command),
   * TlsConnection will handle this for you automatically when you try
   * to send or receive data on the connection. You can call
   * g_tls_connection_handshake() manually if you want to know whether
   * the initial handshake succeeded or failed (as opposed to just
   * immediately trying to use @a conn to read or write, in which case,
   * if it fails, it may not be possible to tell if it failed before or
   * after completing the handshake), but beware that servers may reject
   * client authentication after the handshake has completed, so a
   * successful handshake does not indicate the connection will be usable.
   *
   * Likewise, on the server side, although a handshake is necessary at
   * the beginning of the communication, you do not need to call this
   * function explicitly unless you want clearer error reporting.
   *
   * Previously, calling g_tls_connection_handshake() after the initial
   * handshake would trigger a rehandshake; however, this usage was
   * deprecated in GLib 2.60 because rehandshaking was removed from the
   * TLS protocol in TLS 1.3. Since GLib 2.64, calling this function after
   * the initial handshake will no longer do anything.
   *
   * When using a TlsConnection created by SocketClient, the
   * SocketClient performs the initial handshake, so calling this
   * function manually is not recommended.
   *
   * TlsConnection::accept_certificate may be emitted during the
   * handshake.
   *
   * @newin{2,28}
   *
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return Success or failure.
   *
   * @throws Glib::Error
   */
  auto handshake(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

  /// A handshake() convenience overload.
  auto handshake() -> bool;


  /** Asynchronously performs a TLS handshake on @a conn. See
   * g_tls_connection_handshake() for more information.
   *
   * @newin{2,28}
   *
   * @param io_priority The [I/O priority][io-priority] of the request.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the handshake is complete.
   */
  void handshake_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority =  Glib::PRIORITY_DEFAULT);

  /// A handshake_async() convenience overload.
  void handshake_async(const SlotAsyncReady& slot, int io_priority =  Glib::PRIORITY_DEFAULT);

  /** Finish an asynchronous TLS handshake operation. See
   * g_tls_connection_handshake() for more information.
   *
   * @newin{2,28}
   *
   * @param result A AsyncResult.
   * @return <tt>true</tt> on success, <tt>false</tt> on failure, in which
   * case @a error will be set.
   *
   * @throws Glib::Error
   */
  auto handshake_finish(const Glib::RefPtr<AsyncResult>& result) -> bool;


  /** Returns the current TLS protocol version, which may be
   * Gio::TlsProtocolVersion::UNKNOWN if the connection has not handshaked, or
   * has been closed, or if the TLS backend has implemented a protocol version
   * that is not a recognized TlsProtocolVersion.
   *
   * @newin{2,70}
   *
   * @return The current TLS protocol version.
   */
  auto get_protocol_version() const -> TlsProtocolVersion;

  /** Returns the name of the current TLS ciphersuite, or <tt>nullptr</tt> if the
   * connection has not handshaked or has been closed. Beware that the TLS
   * backend may use any of multiple different naming conventions, because
   * OpenSSL and GnuTLS have their own ciphersuite naming conventions that
   * are different from each other and different from the standard, IANA-
   * registered ciphersuite names. The ciphersuite name is intended to be
   * displayed to the user for informative purposes only, and parsing it
   * is not recommended.
   *
   * @newin{2,70}
   *
   * @return The name of the current TLS ciphersuite, or <tt>nullptr</tt>.
   */
  auto get_ciphersuite_name() const -> Glib::ustring;


  /** Used by TlsConnection implementations to emit the
   * TlsConnection::signal_accept_certificate() signal.
   *
   * @newin{2,28}
   *
   * @param peer_cert The peer's TlsCertificate.
   * @param errors The problems with @a peer_cert.
   * @return <tt>true</tt> if one of the signal handlers has returned
   * <tt>true</tt> to accept @a peer_cert.
   */
  auto emit_accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors) -> bool;

  /** The IOStream that the connection wraps. The connection holds a reference
   * to this stream, and may run operations on the stream from other threads
   * throughout its lifetime. Consequently, after the IOStream has been
   * constructed, application code may only run its own operations on this
   * stream when no IOStream operations are running.
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_base_io_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<IOStream> >;


  /** The connection's certificate; see
   * g_tls_connection_set_certificate().
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_certificate() -> Glib::PropertyProxy< Glib::RefPtr<TlsCertificate> > ;

/** The connection's certificate; see
   * g_tls_connection_set_certificate().
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_certificate() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsCertificate> >;

  /** The certificate database to use when verifying this TLS connection.
   * If no certificate database is set, then the default database will be
   * used. See g_tls_backend_get_default_database().
   *
   * When using a non-default database, TlsConnection must fall back to using
   * the TlsDatabase to perform certificate verification using
   * g_tls_database_verify_chain(), which means certificate verification will
   * not be able to make use of TLS session context. This may be less secure.
   * For example, if you create your own TlsDatabase that just wraps the
   * default TlsDatabase, you might expect that you have not changed anything,
   * but this is not true because you may have altered the behavior of
   * TlsConnection by causing it to use g_tls_database_verify_chain(). See the
   * documentation of g_tls_database_verify_chain() for more details on specific
   * security checks that may not be performed. Accordingly, setting a
   * non-default database is discouraged except for specialty applications with
   * unusual security requirements.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_database() -> Glib::PropertyProxy< Glib::RefPtr<TlsDatabase> > ;

/** The certificate database to use when verifying this TLS connection.
   * If no certificate database is set, then the default database will be
   * used. See g_tls_backend_get_default_database().
   *
   * When using a non-default database, TlsConnection must fall back to using
   * the TlsDatabase to perform certificate verification using
   * g_tls_database_verify_chain(), which means certificate verification will
   * not be able to make use of TLS session context. This may be less secure.
   * For example, if you create your own TlsDatabase that just wraps the
   * default TlsDatabase, you might expect that you have not changed anything,
   * but this is not true because you may have altered the behavior of
   * TlsConnection by causing it to use g_tls_database_verify_chain(). See the
   * documentation of g_tls_database_verify_chain() for more details on specific
   * security checks that may not be performed. Accordingly, setting a
   * non-default database is discouraged except for specialty applications with
   * unusual security requirements.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_database() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsDatabase> >;

  /** A TlsInteraction object to be used when the connection or certificate
   * database need to interact with the user. This will be used to prompt the
   * user for passwords where necessary.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_interaction() -> Glib::PropertyProxy< Glib::RefPtr<TlsInteraction> > ;

/** A TlsInteraction object to be used when the connection or certificate
   * database need to interact with the user. This will be used to prompt the
   * user for passwords where necessary.
   *
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_interaction() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsInteraction> >;

  /** The connection's peer's certificate, after the TLS handshake has
   * completed or failed. Note in particular that this is not yet set
   * during the emission of TlsConnection::signal_accept_certificate().
   *
   * (You can watch for a Object::signal_notify() signal on this property to
   * detect when a handshake has occurred.)
   *
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_peer_certificate() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsCertificate> >;


  /** The errors noticed while verifying
   * TlsConnection::property_peer_certificate(). Normally this should be 0, but
   * it may not be if TlsClientConnection::property_validation_flags() is not
   * Gio::TlsCertificateFlags::VALIDATE_ALL, or if
   * TlsConnection::signal_accept_certificate() overrode the default
   * behavior.
   *
   * GLib guarantees that if certificate verification fails, at least
   * one error will be set, but it does not guarantee that all possible
   * errors will be set. Accordingly, you may not safely decide to
   * ignore any particular type of error. For example, it would be
   * incorrect to mask Gio::TlsCertificateFlags::EXPIRED if you want to allow
   * expired certificates, because this could potentially be the only
   * error flag set even if other problems exist with the certificate.
   *
   * @newin{2,28}
   *
   * Default value: Gio::TlsCertificateFlags::NO_FLAGS
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_peer_certificate_errors() const -> Glib::PropertyProxy_ReadOnly< TlsCertificateFlags >;


  /** Whether or not proper TLS close notification is required.
   * See g_tls_connection_set_require_close_notify().
   *
   * @newin{2,28}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_require_close_notify() -> Glib::PropertyProxy< bool > ;

/** Whether or not proper TLS close notification is required.
   * See g_tls_connection_set_require_close_notify().
   *
   * @newin{2,28}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_require_close_notify() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The TLS protocol version in use. See g_tls_connection_get_protocol_version().
   *
   * @newin{2,70}
   *
   * Default value: Gio::TlsProtocolVersion::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_protocol_version() const -> Glib::PropertyProxy_ReadOnly< TlsProtocolVersion >;


  /** The name of the TLS ciphersuite in use. See g_tls_connection_get_ciphersuite_name().
   *
   * @newin{2,70}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ciphersuite_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors)</tt>
   *
   * Flags: Run Last
   *
   * Emitted during the TLS handshake after the peer certificate has
   * been received. You can examine @a peer_cert's certification path by
   * calling g_tls_certificate_get_issuer() on it.
   *
   * For a client-side connection, @a peer_cert is the server's
   * certificate, and the signal will only be emitted if the
   * certificate was not acceptable according to @a conn's
   * TlsClientConnection::property_validation()_flags. If you would like the
   * certificate to be accepted despite @a errors, return <tt>true</tt> from the
   * signal handler. Otherwise, if no handler accepts the certificate,
   * the handshake will fail with Gio::TlsError::BAD_CERTIFICATE.
   *
   * GLib guarantees that if certificate verification fails, this signal
   * will be emitted with at least one error will be set in @a errors, but
   * it does not guarantee that all possible errors will be set.
   * Accordingly, you may not safely decide to ignore any particular
   * type of error. For example, it would be incorrect to ignore
   * Gio::TlsCertificateFlags::EXPIRED if you want to allow expired
   * certificates, because this could potentially be the only error flag
   * set even if other problems exist with the certificate.
   *
   * For a server-side connection, @a peer_cert is the certificate
   * presented by the client, if this was requested via the server's
   * TlsServerConnection::property_authentication()_mode. On the server side,
   * the signal is always emitted when the client presents a
   * certificate, and the certificate will only be accepted if a
   * handler returns <tt>true</tt>.
   *
   * Note that if this signal is emitted as part of asynchronous I/O
   * in the main thread, then you should not attempt to interact with
   * the user before returning from the signal handler. If you want to
   * let the user decide whether or not to accept the certificate, you
   * would have to return <tt>false</tt> from the signal handler on the first
   * attempt, and then after the connection attempt returns a
   * Gio::TlsError::BAD_CERTIFICATE, you can interact with the user, and
   * if the user decides to accept the certificate, remember that fact,
   * create a new connection, and return <tt>true</tt> from the signal handler
   * the next time.
   *
   * If you are doing I/O in another thread, you do not
   * need to worry about this, and can simply block in the signal
   * handler until the UI thread returns an answer.
   *
   * @newin{2,28}
   *
   * @param peer_cert The peer's TlsCertificate.
   * @param errors The problems with @a peer_cert.
   * @return <tt>true</tt> to accept @a peer_cert (which will also
   * immediately end the signal emission). <tt>false</tt> to allow the signal
   * emission to continue, which will cause the handshake to fail if
   * no one else overrides it.
   */

  auto signal_accept_certificate() -> Glib::SignalProxy<bool(const Glib::RefPtr<const TlsCertificate>&, TlsCertificateFlags)>;


protected:
  /// @throws Glib::Error.
  virtual auto handshake_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    virtual void handshake_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority);


  /// @throws Glib::Error.
  virtual auto handshake_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> bool;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_accept_certificate().
  virtual auto on_accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors) -> bool;


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
   * @relates Gio::TlsConnection
   */
  GIOMM_API
  auto wrap(GTlsConnection* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsConnection>;
}


#endif /* _GIOMM_TLSCONNECTION_H */

