// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_RESOLVER_H
#define _GIOMM_RESOLVER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/inetaddress.hxx>
#include <libmm-gio/srvtarget.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GResolver = struct _GResolver;
using GResolverClass = struct _GResolverClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Resolver_Class;
}
#endif

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT VariantContainerBase;

}

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Resolver : public Glib::Object
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
    explicit Resolver (const Glib::ConstructParams& construct_params);
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
    get_default () -> Glib::RefPtr<Resolver>;

    static auto
    set_default (const Glib::RefPtr<Resolver>& resolver) -> void;

    auto
    lookup_by_name (const Glib::ustring& hostname,
                    const Glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<Glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name (const Glib::ustring& hostname)
        -> std::vector<Glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_async (const Glib::ustring& hostname,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_by_name_async (const Glib::ustring& hostname,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_by_name_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_with_flags (
        const Glib::ustring& hostname,
        NameLookupFlags flags,
        const Glib::RefPtr<Cancellable>& cancellable = {})
        -> std::vector<Glib::RefPtr<InetAddress>>;

    auto
    lookup_by_name_with_flags_async (
        const Glib::ustring& hostname,
        NameLookupFlags flags,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable = {}) -> void;

    auto
    lookup_by_name_with_flags_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::RefPtr<InetAddress>>;

    auto
    lookup_by_address (const Glib::RefPtr<InetAddress>& address,
                       const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::ustring;

    auto
    lookup_by_address (const Glib::RefPtr<InetAddress>& address)
        -> Glib::ustring;

    auto
    lookup_by_address_async (const Glib::RefPtr<InetAddress>& address,
                             const SlotAsyncReady& slot,
                             const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    lookup_by_address_async (const Glib::RefPtr<InetAddress>& address,
                             const SlotAsyncReady& slot) -> void;

    auto
    lookup_by_address_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::ustring;

    auto
    lookup_service (const Glib::ustring& service,
                    const Glib::ustring& protocol,
                    const Glib::ustring& domain,
                    const Glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<SrvTarget>;

    auto
    lookup_service (const Glib::ustring& service,
                    const Glib::ustring& protocol,
                    const Glib::ustring& domain) -> std::vector<SrvTarget>;

    auto
    lookup_service_async (const Glib::ustring& service,
                          const Glib::ustring& protocol,
                          const Glib::ustring& domain,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_service_async (const Glib::ustring& service,
                          const Glib::ustring& protocol,
                          const Glib::ustring& domain,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_service_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<SrvTarget>;

    auto
    lookup_records (const Glib::ustring& rrname,
                    RecordType record_type,
                    const Glib::RefPtr<Cancellable>& cancellable)
        -> std::vector<Glib::VariantContainerBase>;

    auto
    lookup_records (const Glib::ustring& rrname, RecordType record_type)
        -> std::vector<Glib::VariantContainerBase>;

    auto
    lookup_records_async (const Glib::ustring& rrname,
                          RecordType record_type,
                          const SlotAsyncReady& slot,
                          const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    lookup_records_async (const Glib::ustring& rrname,
                          RecordType record_type,
                          const SlotAsyncReady& slot) -> void;

    auto
    lookup_records_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::VariantContainerBase>;

    auto
    signal_reload () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_reload () -> void;
  };

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_to_ascii (const Glib::ustring& hostname) -> std::string;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_to_unicode (const Glib::ustring& hostname) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_non_ascii (const Glib::ustring& hostname) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_ascii_encoded (const Glib::ustring& hostname) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  hostname_is_ip_address (const Glib::ustring& hostname) -> bool;

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Resolver::RecordType>
    : public Glib::Value_Enum<Gio::Resolver::RecordType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
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
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Resolver::NameLookupFlags>
    : public Glib::Value_Flags<Gio::Resolver::NameLookupFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GResolver* object, bool take_copy = false) -> Glib::RefPtr<Gio::Resolver>;
} // namespace Glib

#endif
