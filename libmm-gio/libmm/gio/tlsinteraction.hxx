// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSINTERACTION_H
#define _GIOMM_TLSINTERACTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/tlsconnection.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsInteraction = struct _GTlsInteraction;
using GTlsInteractionClass = struct _GTlsInteractionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TlsInteraction_Class;
}
#endif

namespace gio
{

  enum class TlsInteractionResult
  {
    UNHANDLED,
    HANDLED,
    FAILED
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::TlsInteractionResult>
    : public glib::Value_Enum<gio::TlsInteractionResult>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  enum class TlsCertificateRequestFlags
  {
    NONE = 0x0
  };

  inline auto
  operator| (TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  {
    return static_cast<TlsCertificateRequestFlags> (
        static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  {
    return static_cast<TlsCertificateRequestFlags> (
        static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  {
    return static_cast<TlsCertificateRequestFlags> (
        static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TlsCertificateRequestFlags flags) -> TlsCertificateRequestFlags
  {
    return static_cast<TlsCertificateRequestFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  {
    return (lhs = static_cast<TlsCertificateRequestFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  {
    return (lhs = static_cast<TlsCertificateRequestFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  {
    return (lhs = static_cast<TlsCertificateRequestFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::TlsCertificateRequestFlags>
    : public glib::Value_Flags<gio::TlsCertificateRequestFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;
  class LIBMM_GIO_SYMEXPORT TlsPassword;

  class LIBMM_GIO_SYMEXPORT TlsInteraction : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsInteraction;
    using CppClassType = TlsInteraction_Class;
    using BaseObjectType = GTlsInteraction;
    using BaseClassType = GTlsInteractionClass;

    TlsInteraction (const TlsInteraction&) = delete;
    auto
    operator= (const TlsInteraction&) -> TlsInteraction& = delete;

  private:
    friend class TlsInteraction_Class;
    static CppClassType tlsinteraction_class_;

  protected:
    explicit TlsInteraction (const glib::ConstructParams& construct_params);
    explicit TlsInteraction (GTlsInteraction* castitem);

#endif

  public:
    TlsInteraction (TlsInteraction&& src) noexcept;
    auto
    operator= (TlsInteraction&& src) noexcept -> TlsInteraction&;

    ~TlsInteraction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsInteraction*
    {
      return reinterpret_cast<GTlsInteraction*> (gobject_);
    }

    auto
    gobj () const -> const GTlsInteraction*
    {
      return reinterpret_cast<GTlsInteraction*> (gobject_);
    }

    auto
    gobj_copy () -> GTlsInteraction*;

  private:
  protected:
    TlsInteraction ();

  public:
    auto
    ask_password (const glib::RefPtr<TlsPassword>& password,
                  const glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    ask_password (const glib::RefPtr<TlsPassword>& password)
        -> TlsInteractionResult;

    auto
    ask_password_async (const glib::RefPtr<TlsPassword>& password,
                        const SlotAsyncReady& slot,
                        const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    ask_password_async (const glib::RefPtr<TlsPassword>& password,
                        const SlotAsyncReady& slot) -> void;

    auto
    ask_password_async (const glib::RefPtr<TlsPassword>& password,
                        const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    ask_password_async (const glib::RefPtr<TlsPassword>& password) -> void;

    auto
    ask_password_finish (const glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

    auto
    invoke_ask_password (const glib::RefPtr<TlsPassword>& password,
                         const glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    invoke_ask_password (const glib::RefPtr<TlsPassword>& password)
        -> TlsInteractionResult;

    auto
    invoke_request_certificate (const glib::RefPtr<TlsConnection>& connection,
                                TlsCertificateRequestFlags flags,
                                const glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    invoke_request_certificate (const glib::RefPtr<TlsConnection>& connection,
                                TlsCertificateRequestFlags flags)
        -> TlsInteractionResult;

    auto
    request_certificate (const glib::RefPtr<TlsConnection>& connection,
                         TlsCertificateRequestFlags flags,
                         const glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    request_certificate (const glib::RefPtr<TlsConnection>& connection,
                         TlsCertificateRequestFlags flags)
        -> TlsInteractionResult;

    auto
    request_certificate_async (const glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const SlotAsyncReady& slot,
                               const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    request_certificate_async (const glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const SlotAsyncReady& slot) -> void;

    auto
    request_certificate_async (const glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    request_certificate_async (const glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags) -> void;

    auto
    request_certificate_finish (const glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

  protected:
    virtual auto
    ask_password_vfunc (const glib::RefPtr<TlsPassword>& password,
                        const glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    virtual auto
    ask_password_async_vfunc (const glib::RefPtr<TlsPassword>& password,
                              const SlotAsyncReady& slot,
                              const glib::RefPtr<Cancellable>& cancellable)
        -> void;

    virtual auto
    ask_password_finish_vfunc (const glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsInteraction* object, bool take_copy = false) -> glib::RefPtr<gio::TlsInteraction>;
} // namespace glib

#endif
