
#ifndef _GIOMM_RESOLVER_H
#define _GIOMM_RESOLVER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2009 jonathon jongsma
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
#include <libmm-gio/inetaddress.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/srvtarget.hxx>
#include <libmm-gio/asyncresult.hxx>


// Forward declarations for classes in the Glib namespace.
#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GResolver = struct _GResolver;
using GResolverClass = struct _GResolverClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Resolver_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

class GLIBMM_API VariantContainerBase;

}

namespace Gio
{

/** Asynchronous and cancellable DNS resolver
 *
 * Resolver provides cancellable synchronous and asynchronous DNS resolution,
 * for hostnames (lookup_by_address(), lookup_by_name() and their async
 * variants) and SRV (service) records (lookup_service()).
 *
 * NetworkAddress and NetworkService provide wrappers around Resolver
 * functionality that also implement SocketConnectable, making it easy to
 * connect to a remote host/service.
 *
 * @newin{2,24}
 * @ingroup NetworkIO
 */

class GIOMM_API Resolver
: public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Resolver;
  using CppClassType = Resolver_Class;
  using BaseObjectType = GResolver;
  using BaseClassType = GResolverClass;

  // noncopyable
  Resolver(const Resolver&) = delete;
  auto operator=(const Resolver&) -> Resolver& = delete;

private:  friend class Resolver_Class;
  static CppClassType resolver_class_;

protected:
  explicit Resolver(const Glib::ConstructParams& construct_params);
  explicit Resolver(GResolver* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Resolver(Resolver&& src) noexcept;
  auto operator=(Resolver&& src) noexcept -> Resolver&;

  ~Resolver() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GResolver*       { return reinterpret_cast<GResolver*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GResolver* { return reinterpret_cast<GResolver*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GResolver*;

private:


protected:

public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var RecordType SRV
   * Look up DNS SRV records for a domain.
   *
   *  @var RecordType MX
   * Look up DNS MX records for a domain.
   *
   *  @var RecordType TXT
   * Look up DNS TXT records for a name.
   *
   *  @var RecordType SOA
   * Look up DNS SOA records for a zone.
   *
   *  @var RecordType NS
   * Look up DNS NS records for a domain.
   *
   *  @enum RecordType
   *
   * The type of record that g_resolver_lookup_records() or
   * g_resolver_lookup_records_async() should retrieve. The records are returned
   * as lists of Variant tuples. Each record type has different values in
   * the variant tuples returned.
   *
   * Gio::Resolver::RecordType::SRV records are returned as variants with the signature
   * `(qqqs)`, containing a `guint16` with the priority, a `guint16` with the
   * weight, a `guint16` with the port, and a string of the hostname.
   *
   * Gio::Resolver::RecordType::MX records are returned as variants with the signature
   * `(qs)`, representing a `guint16` with the preference, and a string containing
   * the mail exchanger hostname.
   *
   * Gio::Resolver::RecordType::TXT records are returned as variants with the signature
   * `(as)`, representing an array of the strings in the text record. Note: Most TXT
   * records only contain a single string, but
   * [RFC 1035](https://tools.ietf.org/html/rfc1035#section-3.3.14) does allow a
   * record to contain multiple strings. The RFC which defines the interpretation
   * of a specific TXT record will likely require concatenation of multiple
   * strings if they are present, as with
   * [RFC 7208](https://tools.ietf.org/html/rfc7208#section-3.3).
   *
   * Gio::Resolver::RecordType::SOA records are returned as variants with the signature
   * `(ssuuuuu)`, representing a string containing the primary name server, a
   * string containing the administrator, the serial as a `guint32`, the refresh
   * interval as a `guint32`, the retry interval as a `guint32`, the expire timeout
   * as a `guint32`, and the TTL as a `guint32`.
   *
   * Gio::Resolver::RecordType::NS records are returned as variants with the signature
   * `(s)`, representing a string of the hostname of the name server.
   *
   * @newin{2,34}
   *
   * @ingroup giommEnums
   */
  enum class RecordType
  {
    SRV = 1,
    MX,
    TXT,
    SOA,
    NS
  };


  /**
   *  @var NameLookupFlags DEFAULT
   * Default behavior (same as g_resolver_lookup_by_name()).
   *
   *  @var NameLookupFlags IPV4_ONLY
   * Only resolve ipv4 addresses.
   *
   *  @var NameLookupFlags IPV6_ONLY
   * Only resolve ipv6 addresses.
   *
   *  @enum NameLookupFlags
   *
   * Flags to modify lookup behavior.
   *
   * @newin{2,74}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Resolver::NameLookupFlags operator|(Resolver::NameLookupFlags, Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags operator&(Resolver::NameLookupFlags, Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags operator^(Resolver::NameLookupFlags, Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags operator~(Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags& operator|=(Resolver::NameLookupFlags&, Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags& operator&=(Resolver::NameLookupFlags&, Resolver::NameLookupFlags)</tt><br>
   * <tt>Resolver::NameLookupFlags& operator^=(Resolver::NameLookupFlags&, Resolver::NameLookupFlags)</tt><br>
   */
  enum class NameLookupFlags
  {
    DEFAULT = 0x0,
    IPV4_ONLY = 1 << 0,
    IPV6_ONLY = 1 << 1
  };


  static auto get_default() -> Glib::RefPtr<Resolver>;

  static void set_default(const Glib::RefPtr<Resolver>& resolver);


  // g_resolver_free_addresses is just a C convenience function


  /** Synchronously resolves @a hostname to determine its associated IP
   * address(es). @a hostname may be an ASCII-only or UTF-8 hostname, or
   * the textual form of an IP address (in which case this just becomes
   * a wrapper around g_inet_address_new_from_string()).
   *
   * On success, g_resolver_lookup_by_name() will return a non-empty List of
   * InetAddress, sorted in order of preference and guaranteed to not
   * contain duplicates. That is, if using the result to connect to
   *  @a hostname, you should attempt to connect to the first address
   * first, then the second if the first fails, etc. If you are using
   * the result to listen on a socket, it is appropriate to add each
   * result using e.g. g_socket_listener_add_address().
   *
   * If the DNS resolution fails, @a error (if non-<tt>nullptr</tt>) will be set to a
   * value from ResolverError and <tt>nullptr</tt> will be returned.
   *
   * If @a cancellable is non-<tt>nullptr</tt>, it can be used to cancel the
   * operation, in which case @a error (if non-<tt>nullptr</tt>) will be set to
   * Gio::Error::CANCELLED.
   *
   * If you are planning to connect to a socket on the resolved IP
   * address, it may be easier to create a NetworkAddress and use its
   * SocketConnectable interface.
   *
   * @newin{2,22}
   *
   * @param hostname The hostname to look up.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A non-empty List
   * of InetAddress, or <tt>nullptr</tt> on error. You
   * must unref each of the addresses and free the list when you are
   * done with it. (You can use g_resolver_free_addresses() to do this.).
   *
   * @throws Glib::Error
   */
  auto lookup_by_name(const Glib::ustring& hostname, const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::RefPtr<InetAddress>>;

  /// A lookup_by_name() convenience overload.
  auto lookup_by_name(const Glib::ustring& hostname) -> std::vector<Glib::RefPtr<InetAddress>>;

  /** Begins asynchronously resolving hostname to determine its associated IP address(es), and eventually calls @a slot, which must call
   * lookup_by_name_finish() to get the result. See lookup_by_name() for more details.
   *
   * @param hostname The hostname to look up.
   * @param slot A callback slot to call after the resolution completes.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   */
  void lookup_by_name_async(const Glib::ustring& hostname, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Begins asynchronously resolving hostname to determine its associated IP address(es), and eventually calls @a slot, which must call
   * lookup_by_name_finish() to get the result. See lookup_by_name() for more details.
   *
   * @param hostname The hostname to look up.
   * @param slot A callback slot to call after the resolution completes.
   */
  void lookup_by_name_async(const Glib::ustring& hostname, const SlotAsyncReady& slot);


  /** Retrieves the result of a call to
   * g_resolver_lookup_by_name_async().
   *
   * If the DNS resolution failed, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError. If the operation was cancelled,
   *  @a error will be set to Gio::Error::CANCELLED.
   *
   * @newin{2,22}
   *
   * @param result The result passed to your SlotAsyncReady.
   * @return A List
   * of InetAddress, or <tt>nullptr</tt> on error. See g_resolver_lookup_by_name()
   * for more details.
   *
   * @throws Glib::Error
   */
  auto lookup_by_name_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<InetAddress>>;


  /** This differs from g_resolver_lookup_by_name() in that you can modify
   * the lookup behavior with @a flags. For example this can be used to limit
   * results with Gio::Resolver::NameLookupFlags::IPV4_ONLY.
   *
   * @newin{2,74}
   *
   * @param hostname The hostname to look up.
   * @param flags Extra ResolverNameLookupFlags for the lookup.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A non-empty List
   * of InetAddress, or <tt>nullptr</tt> on error. You
   * must unref each of the addresses and free the list when you are
   * done with it. (You can use g_resolver_free_addresses() to do this.).
   *
   * @throws Glib::Error
   */
  auto lookup_by_name_with_flags(const Glib::ustring& hostname, NameLookupFlags flags, const Glib::RefPtr<Cancellable>& cancellable =  {}) -> std::vector<Glib::RefPtr<InetAddress>>;


  /** Begins asynchronously resolving @a hostname to determine its
   * associated IP address(es), and eventually calls @a slot, which
   * must call g_resolver_lookup_by_name_with_flags_finish() to get the result.
   * See g_resolver_lookup_by_name() for more details.
   *
   * @newin{2,74}
   *
   * @param hostname The hostname to look up the address of.
   * @param flags Extra ResolverNameLookupFlags for the lookup.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call after resolution completes.
   */
  void lookup_by_name_with_flags_async(const Glib::ustring& hostname, NameLookupFlags flags, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable =  {});


  /** Retrieves the result of a call to
   * g_resolver_lookup_by_name_with_flags_async().
   *
   * If the DNS resolution failed, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError. If the operation was cancelled,
   *  @a error will be set to Gio::Error::CANCELLED.
   *
   * @newin{2,74}
   *
   * @param result The result passed to your SlotAsyncReady.
   * @return A List
   * of InetAddress, or <tt>nullptr</tt> on error. See g_resolver_lookup_by_name()
   * for more details.
   *
   * @throws Glib::Error
   */
  auto lookup_by_name_with_flags_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::RefPtr<InetAddress>>;


  /** Synchronously reverse-resolves @a address to determine its
   * associated hostname.
   *
   * If the DNS resolution fails, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError.
   *
   * If @a cancellable is non-<tt>nullptr</tt>, it can be used to cancel the
   * operation, in which case @a error (if non-<tt>nullptr</tt>) will be set to
   * Gio::Error::CANCELLED.
   *
   * @newin{2,22}
   *
   * @param address The address to reverse-resolve.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A hostname (either ASCII-only, or in ASCII-encoded
   * form), or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto lookup_by_address(const Glib::RefPtr<InetAddress>& address, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::ustring;

  /// A lookup_by_address() convenience overload.
  auto lookup_by_address(const Glib::RefPtr<InetAddress>& address) -> Glib::ustring;

  /** Begins asynchronously reverse-resolving an address to determine its associated hostname, and eventually calls callback, which must call
   * lookup_by_address_finish() to get the final result.
   *
   * @param address The address to reverse-resolve.
   * @param slot A callback slot to call after the resolution completes.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   */
  void lookup_by_address_async(const Glib::RefPtr<InetAddress>& address, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Begins asynchronously reverse-resolving an address to determine its associated hostname, and eventually calls callback, which must call
   * lookup_by_address_finish() to get the final result.
   *
   * @param address The address to reverse-resolve.
   * @param slot A callback slot to call after the resolution completes.
   */
  void lookup_by_address_async(const Glib::RefPtr<InetAddress>& address, const SlotAsyncReady& slot);


  /** Retrieves the result of a previous call to
   * g_resolver_lookup_by_address_async().
   *
   * If the DNS resolution failed, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError. If the operation was cancelled,
   *  @a error will be set to Gio::Error::CANCELLED.
   *
   * @newin{2,22}
   *
   * @param result The result passed to your SlotAsyncReady.
   * @return A hostname (either ASCII-only, or in ASCII-encoded
   * form), or <tt>nullptr</tt> on error.
   *
   * @throws Glib::Error
   */
  auto lookup_by_address_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::ustring;


  /** Synchronously performs a DNS SRV lookup for the given @a service and
   *  @a protocol in the given @a domain and returns an array of SrvTarget.
   *  @a domain may be an ASCII-only or UTF-8 hostname. Note also that the
   *  @a service and @a protocol arguments do not include the leading underscore
   * that appears in the actual DNS entry.
   *
   * On success, g_resolver_lookup_service() will return a non-empty List of
   * SrvTarget, sorted in order of preference. (That is, you should
   * attempt to connect to the first target first, then the second if
   * the first fails, etc.)
   *
   * If the DNS resolution fails, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError and <tt>nullptr</tt> will be returned.
   *
   * If @a cancellable is non-<tt>nullptr</tt>, it can be used to cancel the
   * operation, in which case @a error (if non-<tt>nullptr</tt>) will be set to
   * Gio::Error::CANCELLED.
   *
   * If you are planning to connect to the service, it is usually easier
   * to create a NetworkService and use its SocketConnectable
   * interface.
   *
   * @newin{2,22}
   *
   * @param service The service type to look up (eg, "ldap").
   * @param protocol The networking protocol to use for @a service (eg, "tcp").
   * @param domain The DNS domain to look up the service in.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A non-empty List of
   * SrvTarget, or <tt>nullptr</tt> on error. You must free each of the targets and the
   * list when you are done with it. (You can use g_resolver_free_targets() to do
   * this.).
   *
   * @throws Glib::Error
   */
  auto lookup_service(const Glib::ustring& service, const Glib::ustring& protocol, const Glib::ustring& domain, const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<SrvTarget>;

  /// A lookup_service() convenience overload.
  auto lookup_service(const Glib::ustring& service, const Glib::ustring& protocol, const Glib::ustring& domain) -> std::vector<SrvTarget>;

  /** Begins asynchronously performing a DNS SRV lookup for the given service and protocol in the given domain, and eventually calls callback,
   * which must call lookup_service_finish() to get the final result. See glookup_service() for more details.
   *
   * @param service The service type to look up (eg, "ldap").
   * @param protocol The networking protocol to use for service (eg, "tcp")
   * @param domain The DNS domain to look up the service in.
   * @param slot A callback slot to call after the resolution completes.
   * @param cancellable A Cancellable object which can be used to cancel the operation.
   */
  void lookup_service_async(const Glib::ustring& service, const Glib::ustring& protocol, const Glib::ustring& domain, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /** Begins asynchronously performing a DNS SRV lookup for the given service and protocol in the given domain, and eventually calls callback,
   * which must call lookup_service_finish() to get the final result. See glookup_service() for more details.
   *
   * @param service The service type to look up (eg, "ldap").
   * @param protocol The networking protocol to use for service (eg, "tcp")
   * @param domain The DNS domain to look up the service in.
   * @param slot A callback slot to call after the resolution completes.
   */
  void lookup_service_async(const Glib::ustring& service, const Glib::ustring& protocol, const Glib::ustring& domain, const SlotAsyncReady& slot);


  /** Retrieves the result of a previous call to
   * g_resolver_lookup_service_async().
   *
   * If the DNS resolution failed, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError. If the operation was cancelled,
   *  @a error will be set to Gio::Error::CANCELLED.
   *
   * @newin{2,22}
   *
   * @param result The result passed to your SlotAsyncReady.
   * @return A non-empty List of
   * SrvTarget, or <tt>nullptr</tt> on error. See g_resolver_lookup_service() for more
   * details.
   *
   * @throws Glib::Error
   */
  auto lookup_service_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<SrvTarget>;


  /** Synchronously performs a DNS record lookup for the given @a rrname and returns
   * a list of records as Variant tuples. See Gio::Resolver::RecordType for
   * information on what the records contain for each @a record_type.
   *
   * If the DNS resolution fails, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError and <tt>nullptr</tt> will be returned.
   *
   * If @a cancellable is non-<tt>nullptr</tt>, it can be used to cancel the
   * operation, in which case @a error (if non-<tt>nullptr</tt>) will be set to
   * Gio::Error::CANCELLED.
   *
   * @newin{2,34}
   *
   * @param rrname The DNS name to look up the record for.
   * @param record_type The type of DNS record to look up.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return A non-empty List of
   * Variant, or <tt>nullptr</tt> on error. You must free each of the records and the list
   * when you are done with it. (You can use Glib::list_free_full() with
   * Glib::variant_unref() to do this.).
   *
   * @throws Glib::Error
   */
  auto lookup_records(const Glib::ustring& rrname, RecordType record_type, const Glib::RefPtr<Cancellable>& cancellable) -> std::vector<Glib::VariantContainerBase>;

  /// A lookup_records() convenience overload.
  auto lookup_records(const Glib::ustring& rrname, RecordType record_type) -> std::vector<Glib::VariantContainerBase>;

  /** Begins asynchronously performing a DNS lookup for the given @a rrname,
   * and eventually calls @a slot, which must call lookup_records_finish() to
   * get the final result. See lookup_records() for more details.
   *
   * @param rrname The DNS name to lookup the record for.
   * @param record_type The type of DNS record to lookup.
   * @param cancellable A Cancellable.
   * @param slot The slot to call after the resolution completes.
   * @newin{2,36}
   */
  void lookup_records_async(const Glib::ustring& rrname,
    RecordType record_type, const SlotAsyncReady& slot,
    const Glib::RefPtr<Cancellable>& cancellable);


  /// A non-cancellable version of lookup_records_async().
  void lookup_records_async(const Glib::ustring& rrname,
    RecordType record_type, const SlotAsyncReady& slot);


  /** Retrieves the result of a previous call to
   * g_resolver_lookup_records_async(). Returns a non-empty list of records as
   * Variant tuples. See Gio::Resolver::RecordType for information on what the
   * records contain.
   *
   * If the DNS resolution failed, @a error (if non-<tt>nullptr</tt>) will be set to
   * a value from ResolverError. If the operation was cancelled,
   *  @a error will be set to Gio::Error::CANCELLED.
   *
   * @newin{2,34}
   *
   * @param result The result passed to your SlotAsyncReady.
   * @return A non-empty List of
   * Variant, or <tt>nullptr</tt> on error. You must free each of the records and the list
   * when you are done with it. (You can use Glib::list_free_full() with
   * Glib::variant_unref() to do this.).
   *
   * @throws Glib::Error
   */
  auto lookup_records_finish(const Glib::RefPtr<AsyncResult>& result) -> std::vector<Glib::VariantContainerBase>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%reload()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the resolver notices that the system resolver
   * configuration has changed.
   */

  auto signal_reload() -> Glib::SignalProxy<void()>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_reload().
  virtual void on_reload();


};

GIOMM_API
auto hostname_to_ascii (const Glib::ustring& hostname) -> std::string;

GIOMM_API
auto hostname_to_unicode (const Glib::ustring& hostname) -> Glib::ustring;

GIOMM_API
auto hostname_is_non_ascii (const Glib::ustring& hostname) -> bool;

GIOMM_API
auto hostname_is_ascii_encoded (const Glib::ustring& hostname) -> bool;

GIOMM_API
auto hostname_is_ip_address (const Glib::ustring& hostname) -> bool;

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Resolver::RecordType> : public Glib::Value_Enum<Gio::Resolver::RecordType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  { return static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  { return static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  { return static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Resolver::NameLookupFlags flags) -> Resolver::NameLookupFlags
  { return static_cast<Resolver::NameLookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  { return (lhs = static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  { return (lhs = static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  { return (lhs = static_cast<Resolver::NameLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Resolver::NameLookupFlags> : public Glib::Value_Flags<Gio::Resolver::NameLookupFlags>
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
   * @relates Gio::Resolver
   */
  GIOMM_API
  auto wrap(GResolver* object, bool take_copy = false) -> Glib::RefPtr<Gio::Resolver>;
}


#endif /* _GIOMM_RESOLVER_H */
