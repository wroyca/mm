// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSDATABASE_H
#define _GIOMM_TLSDATABASE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/enums.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsDatabase = struct _GTlsDatabase;
using GTlsDatabaseClass = struct _GTlsDatabaseClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT TlsDatabase_Class;
}
#endif

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT ByteArray;

}

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;
  class LIBMM_GIO_SYMEXPORT SocketConnectable;
  class LIBMM_GIO_SYMEXPORT TlsCertificate;
  class LIBMM_GIO_SYMEXPORT TlsInteraction;

  class LIBMM_GIO_SYMEXPORT TlsDatabase : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsDatabase;
    using CppClassType = TlsDatabase_Class;
    using BaseObjectType = GTlsDatabase;
    using BaseClassType = GTlsDatabaseClass;

    TlsDatabase (const TlsDatabase&) = delete;
    auto
    operator= (const TlsDatabase&) -> TlsDatabase& = delete;

  private:
    friend class TlsDatabase_Class;
    static CppClassType tlsdatabase_class_;

  protected:
    explicit TlsDatabase (const Glib::ConstructParams& construct_params);
    explicit TlsDatabase (GTlsDatabase* castitem);

#endif

  public:
    TlsDatabase (TlsDatabase&& src) noexcept;
    auto
    operator= (TlsDatabase&& src) noexcept -> TlsDatabase&;

    ~TlsDatabase () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsDatabase*
    {
      return reinterpret_cast<GTlsDatabase*> (gobject_);
    }

    auto
    gobj () const -> const GTlsDatabase*
    {
      return reinterpret_cast<GTlsDatabase*> (gobject_);
    }

    auto
    gobj_copy () -> GTlsDatabase*;

  private:
  protected:
    TlsDatabase ();

  public:
    enum class VerifyFlags
    {
      NONE = 0x0
    };

    enum class LookupFlags
    {
      NONE = 0x0,
      KEYPAIR = 0x1
    };

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<const SocketConnectable>& identity,
                  const Glib::RefPtr<TlsInteraction>& interaction,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<const SocketConnectable>& identity,
                  const Glib::RefPtr<TlsInteraction>& interaction,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<const SocketConnectable>& identity,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<const SocketConnectable>& identity,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<TlsInteraction>& interaction,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<TlsInteraction>& interaction,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  const Glib::RefPtr<Cancellable>& cancellable,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain (const Glib::RefPtr<TlsCertificate>& chain,
                  const Glib::ustring& purpose,
                  VerifyFlags flags = VerifyFlags::NONE) const
        -> TlsCertificateFlags;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<const SocketConnectable>& identity,
                        const Glib::RefPtr<TlsInteraction>& interaction,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<const SocketConnectable>& identity,
                        const Glib::RefPtr<TlsInteraction>& interaction,
                        const SlotAsyncReady& slot,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<const SocketConnectable>& identity,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<const SocketConnectable>& identity,
                        const SlotAsyncReady& slot,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<TlsInteraction>& interaction,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<TlsInteraction>& interaction,
                        const SlotAsyncReady& slot,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_async (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const SlotAsyncReady& slot,
                        VerifyFlags flags = VerifyFlags::NONE) const -> void;

    auto
    verify_chain_finish (const Glib::RefPtr<AsyncResult>& result)
        -> TlsCertificateFlags;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_issuer (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_issuer_async (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_issuer_async (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_issuer_async (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_issuer_async (
        const Glib::RefPtr<const TlsCertificate>& certificate,
        const SlotAsyncReady& slot,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_issuer_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        LookupFlags flags = LookupFlags::NONE)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) const
        -> std::vector<Glib::RefPtr<const TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE) const
        -> std::vector<Glib::RefPtr<const TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) const
        -> std::vector<Glib::RefPtr<const TlsCertificate>>;

    auto
    lookup_certificates_issued_by (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        LookupFlags flags = LookupFlags::NONE) const
        -> std::vector<Glib::RefPtr<const TlsCertificate>>;

    auto
    lookup_certificates_issued_by_async (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificates_issued_by_async (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificates_issued_by_async (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificates_issued_by_async (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const SlotAsyncReady& slot,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificates_issued_by_finish (
        const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    create_certificate_handle (
        const Glib::RefPtr<const TlsCertificate>& certificate) const
        -> Glib::ustring;

    auto
    lookup_certificate_for_handle (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_for_handle (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE) -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_for_handle (const Glib::ustring& handle,
                                   const Glib::RefPtr<Cancellable>& cancellable,
                                   LookupFlags flags = LookupFlags::NONE)
        -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_for_handle (const Glib::ustring& handle,
                                   LookupFlags flags = LookupFlags::NONE)
        -> Glib::RefPtr<TlsCertificate>;

    auto
    lookup_certificate_for_handle (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_for_handle (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_for_handle (const Glib::ustring& handle,
                                   const Glib::RefPtr<Cancellable>& cancellable,
                                   LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_for_handle (const Glib::ustring& handle,
                                   LookupFlags flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const TlsCertificate>;

    auto
    lookup_certificate_for_handle_async (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_for_handle_async (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_for_handle_async (
        const Glib::ustring& handle,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags = LookupFlags::NONE) -> void;

    auto
    lookup_certificate_for_handle_async (const Glib::ustring& handle,
                                         const SlotAsyncReady& slot,
                                         LookupFlags flags = LookupFlags::NONE)
        -> void;

    auto
    lookup_certificate_for_handle_finish (
        const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<TlsCertificate>;

  protected:
    virtual auto
    verify_chain_vfunc (const Glib::RefPtr<TlsCertificate>& chain,
                        const Glib::ustring& purpose,
                        const Glib::RefPtr<const SocketConnectable>& identity,
                        const Glib::RefPtr<TlsInteraction>& interaction,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        VerifyFlags flags) const -> TlsCertificateFlags;

    virtual auto
    verify_chain_async_vfunc (
        const Glib::RefPtr<TlsCertificate>& chain,
        const Glib::ustring& purpose,
        const Glib::RefPtr<const SocketConnectable>& identity,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        VerifyFlags flags) const -> void;

    virtual auto
    verify_chain_finish_vfunc (const Glib::RefPtr<AsyncResult>& result)
        -> TlsCertificateFlags;

    virtual auto
    create_certificate_handle_vfunc (
        const Glib::RefPtr<const TlsCertificate>& certificate) const
        -> Glib::ustring;

    virtual auto
    lookup_certificate_for_handle_vfunc (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> Glib::RefPtr<TlsCertificate>;

    virtual auto
    lookup_certificate_for_handle_async_vfunc (
        const Glib::ustring& handle,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> void;

    virtual auto
    lookup_certificate_for_handle_finish_vfunc (
        const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<TlsCertificate>;

    virtual auto
    lookup_certificate_issuer_vfunc (
        const Glib::RefPtr<TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> Glib::RefPtr<TlsCertificate>;

    virtual auto
    lookup_certificate_issuer_async_vfunc (
        const Glib::RefPtr<TlsCertificate>& certificate,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> void;

    virtual auto
    lookup_certificate_issuer_finish_vfunc (
        const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<TlsCertificate>;

    virtual auto
    lookup_certificates_issued_by_vfunc (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> std::vector<Glib::RefPtr<TlsCertificate>>;

    virtual auto
    lookup_certificates_issued_by_async_vfunc (
        const Glib::RefPtr<Glib::ByteArray>& issuer_raw_dn,
        const Glib::RefPtr<TlsInteraction>& interaction,
        const SlotAsyncReady& slot,
        const Glib::RefPtr<Cancellable>& cancellable,
        LookupFlags flags) -> void;

    virtual auto
    lookup_certificates_issued_by_finish_vfunc (
        const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Gio
{

  inline auto
  operator| (TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  {
    return static_cast<TlsDatabase::VerifyFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  {
    return static_cast<TlsDatabase::VerifyFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TlsDatabase::VerifyFlags lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags
  {
    return static_cast<TlsDatabase::VerifyFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TlsDatabase::VerifyFlags flags) -> TlsDatabase::VerifyFlags
  {
    return static_cast<TlsDatabase::VerifyFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  {
    return (lhs = static_cast<TlsDatabase::VerifyFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  {
    return (lhs = static_cast<TlsDatabase::VerifyFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TlsDatabase::VerifyFlags& lhs, TlsDatabase::VerifyFlags rhs) -> TlsDatabase::VerifyFlags&
  {
    return (lhs = static_cast<TlsDatabase::VerifyFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsDatabase::VerifyFlags>
    : public Glib::Value_Flags<Gio::TlsDatabase::VerifyFlags>
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
  operator| (TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  {
    return static_cast<TlsDatabase::LookupFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  {
    return static_cast<TlsDatabase::LookupFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TlsDatabase::LookupFlags lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags
  {
    return static_cast<TlsDatabase::LookupFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TlsDatabase::LookupFlags flags) -> TlsDatabase::LookupFlags
  {
    return static_cast<TlsDatabase::LookupFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  {
    return (lhs = static_cast<TlsDatabase::LookupFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  {
    return (lhs = static_cast<TlsDatabase::LookupFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TlsDatabase::LookupFlags& lhs, TlsDatabase::LookupFlags rhs) -> TlsDatabase::LookupFlags&
  {
    return (lhs = static_cast<TlsDatabase::LookupFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsDatabase::LookupFlags>
    : public Glib::Value_Flags<Gio::TlsDatabase::LookupFlags>
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
  wrap (GTlsDatabase* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsDatabase>;
} // namespace Glib

#endif
