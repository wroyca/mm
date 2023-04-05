// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_RESOLVER_H
#define _GIOMM_RESOLVER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/inetaddress.hxx>
#include <libmm/gio/srvtarget.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GResolver = struct _GResolver;
using GResolverClass = struct _GResolverClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Resolver_Class;
}
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT VariantContainerBase;

}

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Resolver : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Resolver;
    using CppClassType = Resolver_Class;
    using BaseObjectType = GResolver;
    using BaseClassType = GResolverClass;

    Resolver (const Resolver&) = delete;
    auto
    operator= (const Resolver&) -> Resolver& = delete;

  private:
    friend class Resolver_Class;
    static CppClassType resolver_class_;

  protected:
    explicit Resolver (const glib::ConstructParams& construct_params);
    explicit Resolver (GResolver* castitem);

#endif

  public:
    Resolver (Resolver&& src) noexcept;
    auto
    operator= (Resolver&& src) noexcept -> Resolver&;

    ~Resolver () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GResolver*
    {
      return reinterpret_cast<GResolver*> (gobject_);
    }

    auto
    gobj () const -> const GResolver*
    {
      return reinterpret_cast<GResolver*> (gobject_);
    }

    auto
    gobj_copy () -> GResolver*;

  private:
  protected:
  public:
    enum class RecordType
    {
      SRV = 1,
      MX,
      TXT,
      SOA,
      NS
    };

    enum class NameLookupFlags
    {
      DEFAULT = 0x0,
      IPV4_ONLY = 1 << 0,
      IPV6_ONLY = 1 << 1
    };

    static auto
    get_default () -> glib::RefPtr<Resolver>;

    static auto
    set_default (const glib::RefPtr<Resolver>& resolver) -> void;

    auto
    lookup_by_name (const glib::ustring& hostname,
                    const glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name (const glib::ustring& hostname)
        -> std::vector<glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_async (const glib::ustring& hostname,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_by_name_async (const glib::ustring& hostname,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_by_name_finish (const glib::RefPtr<AsyncResult>& result)
        -> std::vector<glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_with_flags (
        const glib::ustring& hostname,
        NameLookupFlags flags,
        const glib::RefPtr<Cancellable>& cancellable = {})
        -> std::vector<glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_with_flags_async (
        const glib::ustring& hostname,
        NameLookupFlags flags,
        const SlotAsyncReady& slot,
        const glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    auto
    lookup_by_name_with_flags_finish (const glib::RefPtr<AsyncResult>& result)
        -> std::vector<glib::RefPtr<InetAddress>>;

    auto
    lookup_by_address (const glib::RefPtr<InetAddress>& address,
                       const glib::RefPtr<Cancellable>& cancellable)
        -> glib::ustring;

    auto
    lookup_by_address (const glib::RefPtr<InetAddress>& address)
        -> glib::ustring;

    auto
    lookup_by_address_async (const glib::RefPtr<InetAddress>& address,
                             const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    lookup_by_address_async (const glib::RefPtr<InetAddress>& address,
                             const SlotAsyncReady& slot) -> void;

    auto
    lookup_by_address_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::ustring;

    auto
    lookup_service (const glib::ustring& service,
                    const glib::ustring& protocol,
                    const glib::ustring& domain,
                    const glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<SrvTarget>;

    auto
    lookup_service (const glib::ustring& service,
                    const glib::ustring& protocol,
                    const glib::ustring& domain) -> std::vector<SrvTarget>;

    auto
    lookup_service_async (const glib::ustring& service,
                          const glib::ustring& protocol,
                          const glib::ustring& domain,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_service_async (const glib::ustring& service,
                          const glib::ustring& protocol,
                          const glib::ustring& domain,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_service_finish (const glib::RefPtr<AsyncResult>& result)
        -> std::vector<SrvTarget>;

    auto
    lookup_records (const glib::ustring& rrname,
                    RecordType record_type,
                    const glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<glib::VariantContainerBase>;

    auto
    lookup_records (const glib::ustring& rrname, RecordType record_type)
        -> std::vector<glib::VariantContainerBase>;

    auto
    lookup_records_async (const glib::ustring& rrname,
                          RecordType record_type,
                          const SlotAsyncReady& slot,
                          const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_records_async (const glib::ustring& rrname,
                          RecordType record_type,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_records_finish (const glib::RefPtr<AsyncResult>& result)
        -> std::vector<glib::VariantContainerBase>;

    auto
    signal_reload () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_reload () -> void;
  };

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_to_ascii (const glib::ustring& hostname) -> std::string;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_to_unicode (const glib::ustring& hostname) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_non_ascii (const glib::ustring& hostname) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_ascii_encoded (const glib::ustring& hostname) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_ip_address (const glib::ustring& hostname) -> bool;

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Resolver::RecordType>
    : public glib::Value_Enum<gio::Resolver::RecordType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  inline auto
  operator| (Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  {
    return static_cast<Resolver::NameLookupFlags> (static_cast<unsigned> (lhs) |
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  {
    return static_cast<Resolver::NameLookupFlags> (static_cast<unsigned> (lhs) &
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Resolver::NameLookupFlags lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags
  {
    return static_cast<Resolver::NameLookupFlags> (static_cast<unsigned> (lhs) ^
                                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Resolver::NameLookupFlags flags) -> Resolver::NameLookupFlags
  {
    return static_cast<Resolver::NameLookupFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  {
    return (lhs = static_cast<Resolver::NameLookupFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  {
    return (lhs = static_cast<Resolver::NameLookupFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Resolver::NameLookupFlags& lhs, Resolver::NameLookupFlags rhs) -> Resolver::NameLookupFlags&
  {
    return (lhs = static_cast<Resolver::NameLookupFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Resolver::NameLookupFlags>
    : public glib::Value_Flags<gio::Resolver::NameLookupFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GResolver* object, bool take_copy = false) -> glib::RefPtr<gio::Resolver>;
} // namespace glib

#endif
