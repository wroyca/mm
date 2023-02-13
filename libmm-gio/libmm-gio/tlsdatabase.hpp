
#ifndef _GIOMM_TLSDATABASE_H
#define _GIOMM_TLSDATABASE_H


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

#include <libmm-glib/object.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsDatabase = struct _GTlsDatabase;
using GTlsDatabaseClass = struct _GTlsDatabaseClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsDatabase_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

// Forward declaration.
class GLIBMM_API ByteArray;

}

namespace Gio
{

class GIOMM_API Cancellable;
class GIOMM_API SocketConnectable;
class GIOMM_API TlsCertificate;
class GIOMM_API TlsInteraction;

/** TlsDatabase - TLS database type.
 * TlsDatabase is used to lookup certificates and other information from a
 * certificate or key store. It is an abstract base class which TLS library
 * specific subtypes override.
 *
 * Most common client applications will not directly interact with TlsDatabase.
 * It is used internally by TlsConnection.
 * @newin{2,36}
 */

class GIOMM_API TlsDatabase : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsDatabase;
  using CppClassType = TlsDatabase_Class;
  using BaseObjectType = GTlsDatabase;
  using BaseClassType = GTlsDatabaseClass;

  // noncopyable
  TlsDatabase(const TlsDatabase&) = delete;
  auto operator=(const TlsDatabase&) -> TlsDatabase& = delete;

private:  friend class TlsDatabase_Class;
  static CppClassType tlsdatabase_class_;

protected:
  explicit TlsDatabase(const Glib::ConstructParams& construct_params);
  explicit TlsDatabase(GTlsDatabase* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsDatabase(TlsDatabase&& src) noexcept;
  auto operator=(TlsDatabase&& src) noexcept -> TlsDatabase&;

  ~TlsDatabase() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsDatabase*       { return reinterpret_cast<GTlsDatabase*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsDatabase* { return reinterpret_cast<GTlsDatabase*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTlsDatabase*;

private:


protected:
  TlsDatabase();

public:
  //TODO?: Have a constant for the C macro G_TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER (which is a string)?
  //TODO?: Have a constant for the C macro G_TLS_DATABASE_PURPOSE_AUTHENTICATE_CLIENT (which is a string)?

  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var VerifyFlags NONE
   * No verification flags.
   *
   *  @enum VerifyFlags
   *
   * Flags for g_tls_database_verify_chain().
   *
   * @newin{2,30}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>TlsDatabase::VerifyFlags operator|(TlsDatabase::VerifyFlags, TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags operator&(TlsDatabase::VerifyFlags, TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags operator^(TlsDatabase::VerifyFlags, TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags operator~(TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags& operator|=(TlsDatabase::VerifyFlags&, TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags& operator&=(TlsDatabase::VerifyFlags&, TlsDatabase::VerifyFlags)</tt><br>
   * <tt>TlsDatabase::VerifyFlags& operator^=(TlsDatabase::VerifyFlags&, TlsDatabase::VerifyFlags)</tt><br>
   */
  enum class VerifyFlags
  {
    NONE = 0x0
  };


  /**
   *  @var LookupFlags NONE
   * No lookup flags.
   *
   *  @var LookupFlags KEYPAIR
   * Restrict lookup to certificates that have
   * a private key.
   *
   *  @enum LookupFlags
   *
   * Flags for g_tls_database_lookup_certificate_for_handle(),
   * g_tls_database_lookup_certificate_issuer(),
   * and g_tls_database_lookup_certificates_issued_by().
   *
   * @newin{2,30}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>TlsDatabase::LookupFlags operator|(TlsDatabase::LookupFlags, TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags operator&(TlsDatabase::LookupFlags, TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags operator^(TlsDatabase::LookupFlags, TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags operator~(TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags& operator|=(TlsDatabase::LookupFlags&, TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags& operator&=(TlsDatabase::LookupFlags&, TlsDatabase::LookupFlags)</tt><br>
   * <tt>TlsDatabase::LookupFlags& operator^=(TlsDatabase::LookupFlags&, TlsDatabase::LookupFlags)</tt><br>
   */
  enum class LookupFlags
  {
    NONE = 0x0,
    KEYPAIR = 0x1
  };


  /** Determines the validity of a certificate chain, outside the context
   * of a TLS session.
   *
   *  @a chain is a chain of TlsCertificate objects each pointing to the next
   * certificate in the chain by its TlsCertificate::property_issuer() property.
   *
   *  @a purpose describes the purpose (or usage) for which the certificate
   * is being used. Typically @a purpose will be set to G_TLS_DATABASE_PURPOSE_AUTHENTICATE_SERVER
   * which means that the certificate is being used to authenticate a server
   * (and we are acting as the client).
   *
   * The @a identity is used to ensure the server certificate is valid for
   * the expected peer identity. If the identity does not match the
   * certificate, Gio::TlsCertificateFlags::BAD_IDENTITY will be set in the
   * return value. If @a identity is <tt>nullptr</tt>, that bit will never be set in
   * the return value. The peer identity may also be used to check for
   * pinned certificates (trust exceptions) in the database. These may
   * override the normal verification process on a host-by-host basis.
   *
   * Currently there are no @a flags, and Gio::TlsDatabaseVerifyFlags::NONE should be
   * used.
   *
   * If @a chain is found to be valid, then the return value will be 0. If
   *  @a chain is found to be invalid, then the return value will indicate at
   * least one problem found. If the function is unable to determine
   * whether @a chain is valid (for example, because @a cancellable is
   * triggered before it completes) then the return value will be
   * Gio::TlsCertificateFlags::GENERIC_ERROR and @a error will be set accordingly.
   *  @a error is not set when @a chain is successfully analyzed but found to
   * be invalid.
   *
   * GLib guarantees that if certificate verification fails, at least one
   * error will be set in the return value, but it does not guarantee
   * that all possible errors will be set. Accordingly, you may not safely
   * decide to ignore any particular type of error. For example, it would
   * be incorrect to mask Gio::TlsCertificateFlags::EXPIRED if you want to allow
   * expired certificates, because this could potentially be the only
   * error flag set even if other problems exist with the certificate.
   *
   * Prior to GLib 2.48, GLib's default TLS backend modified @a chain to
   * represent the certification path built by TlsDatabase during
   * certificate verification by adjusting the TlsCertificate::property_issuer()
   * property of each certificate in @a chain. Since GLib 2.48, this no
   * longer occurs, so you cannot rely on TlsCertificate::property_issuer() to
   * represent the actual certification path used during certificate
   * verification.
   *
   * Because TLS session context is not used, TlsDatabase may not
   * perform as many checks on the certificates as TlsConnection would.
   * For example, certificate constraints may not be honored, and
   * revocation checks may not be performed. The best way to verify TLS
   * certificates used by a TLS connection is to let TlsConnection
   * handle the verification.
   *
   * The TLS backend may attempt to look up and add missing certificates
   * to the chain. This may involve HTTP requests to download missing
   * certificates.
   *
   * This function can block. Use g_tls_database_verify_chain_async() to
   * perform the verification operation asynchronously.
   *
   * @newin{2,30}
   *
   * @param chain A TlsCertificate chain.
   * @param purpose The purpose that this certificate chain will be used for.
   * @param identity The expected peer identity.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Additional verify flags.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return The appropriate TlsCertificateFlags which represents the
   * result of verification.
   *
   * @throws Glib::Error
   */
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /// A verify_chain() convenience overload.
  auto verify_chain(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, VerifyFlags flags =  VerifyFlags::NONE) const -> TlsCertificateFlags;

  /** Asynchronously determines the validity of a certificate chain after
   * looking up and adding any missing certificates to the chain. See
   * g_tls_database_verify_chain() for more information.
   *
   * @newin{2,30}
   *
   * @param chain A TlsCertificate chain.
   * @param purpose The purpose that this certificate chain will be used for.
   * @param identity The expected peer identity.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Additional verify flags.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const SlotAsyncReady& slot, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags =  VerifyFlags::NONE) const;

  /// A verify_chain_async() convenience overload.
  void verify_chain_async(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const SlotAsyncReady& slot, VerifyFlags flags =  VerifyFlags::NONE) const;

  /** Finish an asynchronous verify chain operation. See
   * g_tls_database_verify_chain() for more information.
   *
   * If @a chain is found to be valid, then the return value will be 0. If
   *  @a chain is found to be invalid, then the return value will indicate
   * the problems found. If the function is unable to determine whether
   *  @a chain is valid or not (eg, because @a cancellable is triggered
   * before it completes) then the return value will be
   * Gio::TlsCertificateFlags::GENERIC_ERROR and @a error will be set
   * accordingly. @a error is not set when @a chain is successfully analyzed
   * but found to be invalid.
   *
   * @newin{2,30}
   *
   * @param result A AsyncResult.
   * @return The appropriate TlsCertificateFlags which represents the
   * result of verification.
   *
   * @throws Glib::Error
   */
  auto verify_chain_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags;


  /** Look up the issuer of @a certificate in the database. The
   * TlsCertificate::property_issuer() property of @a certificate is not modified, and
   * the two certificates are not hooked into a chain.
   *
   * This function can block. Use g_tls_database_lookup_certificate_issuer_async()
   * to perform the lookup operation asynchronously.
   *
   * Beware this function cannot be used to build certification paths. The
   * issuer certificate returned by this function may not be the same as
   * the certificate that would actually be used to construct a valid
   * certification path during certificate verification.
   * [RFC 4158](https://datatracker.ietf.org/doc/html/rfc4158) explains
   * why an issuer certificate cannot be naively assumed to be part of the
   * the certification path (though GLib's TLS backends may not follow the
   * path building strategies outlined in this RFC). Due to the complexity
   * of certification path building, GLib does not provide any way to know
   * which certification path will actually be used when verifying a TLS
   * certificate. Accordingly, this function cannot be used to make
   * security-related decisions. Only GLib itself should make security
   * decisions about TLS certificates.
   *
   * @newin{2,30}
   *
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>nullptr</tt>. Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /** Look up the issuer of @a certificate in the database. The
   * TlsCertificate::property_issuer() property of @a certificate is not modified, and
   * the two certificates are not hooked into a chain.
   *
   * This function can block. Use g_tls_database_lookup_certificate_issuer_async()
   * to perform the lookup operation asynchronously.
   *
   * Beware this function cannot be used to build certification paths. The
   * issuer certificate returned by this function may not be the same as
   * the certificate that would actually be used to construct a valid
   * certification path during certificate verification.
   * [RFC 4158](https://datatracker.ietf.org/doc/html/rfc4158) explains
   * why an issuer certificate cannot be naively assumed to be part of the
   * the certification path (though GLib's TLS backends may not follow the
   * path building strategies outlined in this RFC). Due to the complexity
   * of certification path building, GLib does not provide any way to know
   * which certification path will actually be used when verifying a TLS
   * certificate. Accordingly, this function cannot be used to make
   * security-related decisions. Only GLib itself should make security
   * decisions about TLS certificates.
   *
   * @newin{2,30}
   *
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>nullptr</tt>. Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_issuer() convenience overload.
  auto lookup_certificate_issuer(const Glib::RefPtr<const TlsCertificate>& certificate, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;


  /** Asynchronously look up the issuer of @a certificate in the database. See
   * g_tls_database_lookup_certificate_issuer() for more information.
   *
   * @newin{2,30}
   *
   * @param certificate A TlsCertificate.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_issuer_async() convenience overload.
  void lookup_certificate_issuer_async(const Glib::RefPtr<const TlsCertificate>& certificate, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /** Finish an asynchronous lookup issuer operation. See
   * g_tls_database_lookup_certificate_issuer() for more information.
   *
   * @newin{2,30}
   *
   * @param result A AsyncResult.
   * @return A newly allocated issuer TlsCertificate,
   * or <tt>nullptr</tt>. Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_issuer_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>;


  /** Look up certificates issued by this issuer in the database.
   *
   * This function can block, use g_tls_database_lookup_certificates_issued_by_async() to perform
   * the lookup operation asynchronously.
   *
   * @newin{2,30}
   *
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated list of TlsCertificate
   * objects.
   *
   * @throws Glib::Error
   */
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> std::vector< Glib::RefPtr<TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) -> std::vector< Glib::RefPtr<TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> std::vector< Glib::RefPtr<TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, LookupFlags flags =  LookupFlags::NONE) -> std::vector< Glib::RefPtr<TlsCertificate> >;


  /** Look up certificates issued by this issuer in the database.
   *
   * This function can block, use g_tls_database_lookup_certificates_issued_by_async() to perform
   * the lookup operation asynchronously.
   *
   * @newin{2,30}
   *
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated list of TlsCertificate
   * objects.
   *
   * @throws Glib::Error
   */
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> std::vector< Glib::RefPtr<const TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) const -> std::vector< Glib::RefPtr<const TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> std::vector< Glib::RefPtr<const TlsCertificate> >;

  /// A lookup_certificates_issued_by() convenience overload.
  auto lookup_certificates_issued_by(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, LookupFlags flags =  LookupFlags::NONE) const -> std::vector< Glib::RefPtr<const TlsCertificate> >;


  /** Asynchronously look up certificates issued by this issuer in the database. See
   * g_tls_database_lookup_certificates_issued_by() for more information.
   *
   * The database may choose to hold a reference to the issuer byte array for the duration
   * of of this asynchronous operation. The byte array should not be modified during
   * this time.
   *
   * @newin{2,30}
   *
   * @param issuer_raw_dn A ByteArray which holds the DER encoded issuer DN.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup operation.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificates_issued_by_async() convenience overload.
  void lookup_certificates_issued_by_async(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /** Finish an asynchronous lookup of certificates. See
   * g_tls_database_lookup_certificates_issued_by() for more information.
   *
   * @newin{2,30}
   *
   * @param result A AsyncResult.
   * @return A newly allocated list of TlsCertificate
   * objects.
   *
   * @throws Glib::Error
   */
  auto lookup_certificates_issued_by_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector< Glib::RefPtr<TlsCertificate> >;


  /** Create a handle string for the certificate. The database will only be able
   * to create a handle for certificates that originate from the database. In
   * cases where the database cannot create a handle for a certificate, <tt>nullptr</tt>
   * will be returned.
   *
   * This handle should be stable across various instances of the application,
   * and between applications. If a certificate is modified in the database,
   * then it is not guaranteed that this handle will continue to point to it.
   *
   * @newin{2,30}
   *
   * @param certificate Certificate for which to create a handle.
   * @return A newly allocated string containing the
   * handle.
   */
  auto create_certificate_handle(const Glib::RefPtr<const TlsCertificate>& certificate) const -> Glib::ustring;


  /** Look up a certificate by its handle.
   *
   * The handle should have been created by calling
   * g_tls_database_create_certificate_handle() on a TlsDatabase object of
   * the same TLS backend. The handle is designed to remain valid across
   * instantiations of the database.
   *
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>nullptr</tt> will be returned.
   *
   * This function can block, use g_tls_database_lookup_certificate_for_handle_async() to perform
   * the lookup operation asynchronously.
   *
   * @newin{2,30}
   *
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated
   * TlsCertificate, or <tt>nullptr</tt>. Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, LookupFlags flags =  LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

  /** Look up a certificate by its handle.
   *
   * The handle should have been created by calling
   * g_tls_database_create_certificate_handle() on a TlsDatabase object of
   * the same TLS backend. The handle is designed to remain valid across
   * instantiations of the database.
   *
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>nullptr</tt> will be returned.
   *
   * This function can block, use g_tls_database_lookup_certificate_for_handle_async() to perform
   * the lookup operation asynchronously.
   *
   * @newin{2,30}
   *
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A newly allocated
   * TlsCertificate, or <tt>nullptr</tt>. Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;

  /// A lookup_certificate_for_handle() convenience overload.
  auto lookup_certificate_for_handle(const Glib::ustring& handle, LookupFlags flags =  LookupFlags::NONE) const -> Glib::RefPtr<const TlsCertificate>;


  /** Asynchronously look up a certificate by its handle in the database. See
   * g_tls_database_lookup_certificate_for_handle() for more information.
   *
   * @newin{2,30}
   *
   * @param handle A certificate handle.
   * @param interaction Used to interact with the user if necessary.
   * @param flags Flags which affect the lookup.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the operation completes.
   */
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags =  LookupFlags::NONE);

  /// A lookup_certificate_for_handle_async() convenience overload.
  void lookup_certificate_for_handle_async(const Glib::ustring& handle, const SlotAsyncReady& slot, LookupFlags flags =  LookupFlags::NONE);

  /** Finish an asynchronous lookup of a certificate by its handle. See
   * g_tls_database_lookup_certificate_for_handle() for more information.
   *
   * If the handle is no longer valid, or does not point to a certificate in
   * this database, then <tt>nullptr</tt> will be returned.
   *
   * @newin{2,30}
   *
   * @param result A AsyncResult.
   * @return A newly allocated TlsCertificate object.
   * Use Glib::object_unref() to release the certificate.
   *
   * @throws Glib::Error
   */
  auto lookup_certificate_for_handle_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>;

protected:


  /// @throws Glib::Error.
  virtual auto verify_chain_vfunc(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags) const -> TlsCertificateFlags;

    virtual void verify_chain_async_vfunc(const Glib::RefPtr<TlsCertificate>& chain, const Glib::ustring& purpose, const Glib::RefPtr<const SocketConnectable>& identity, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, VerifyFlags flags) const;


  /// @throws Glib::Error.
  virtual auto verify_chain_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> TlsCertificateFlags;


    virtual auto create_certificate_handle_vfunc(const Glib::RefPtr<const TlsCertificate>& certificate) const -> Glib::ustring;


  /// @throws Glib::Error.
  virtual auto lookup_certificate_for_handle_vfunc(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags) -> Glib::RefPtr<TlsCertificate>;

    virtual void lookup_certificate_for_handle_async_vfunc(const Glib::ustring& handle, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags);

  /// @throws Glib::Error.
  virtual auto lookup_certificate_for_handle_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>;


  /// @throws Glib::Error.
  virtual auto lookup_certificate_issuer_vfunc(const Glib::RefPtr<TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags) -> Glib::RefPtr<TlsCertificate>;

    virtual void lookup_certificate_issuer_async_vfunc(const Glib::RefPtr<TlsCertificate>& certificate, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags);

  /// @throws Glib::Error.
  virtual auto lookup_certificate_issuer_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<TlsCertificate>;


  /// @throws Glib::Error.
  virtual auto lookup_certificates_issued_by_vfunc(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags) -> std::vector< Glib::RefPtr<TlsCertificate> >;

    virtual void lookup_certificates_issued_by_async_vfunc(const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn, const Glib::RefPtr<TlsInteraction>& interaction, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, LookupFlags flags);

  /// @throws Glib::Error.
  virtual auto lookup_certificates_issued_by_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> std::vector< Glib::RefPtr<TlsCertificate> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  { return static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  { return static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  { return static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(TlsDatabase::VerifyFlags flags) -> TlsDatabase::VerifyFlags
  { return static_cast<TlsDatabase::VerifyFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  { return (lhs = static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  { return (lhs = static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  { return (lhs = static_cast<TlsDatabase::VerifyFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsDatabase::VerifyFlags> : public Glib::Value_Flags<Gio::TlsDatabase::VerifyFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  { return static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  { return static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  { return static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(TlsDatabase::LookupFlags flags) -> TlsDatabase::LookupFlags
  { return static_cast<TlsDatabase::LookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  { return (lhs = static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  { return (lhs = static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  { return (lhs = static_cast<TlsDatabase::LookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsDatabase::LookupFlags> : public Glib::Value_Flags<Gio::TlsDatabase::LookupFlags>
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
   * @relates Gio::TlsDatabase
   */
  GIOMM_API
  auto wrap(GTlsDatabase* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsDatabase>;
}


#endif /* _GIOMM_TLSDATABASE_H */

