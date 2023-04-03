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
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT TlsInteraction_Class;
}
#endif

namespace Gio
{

  enum class TlsInteractionResult
  {
    UNHANDLED,
    HANDLED,
    FAILED
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsInteractionResult>
    : public Glib::Value_Enum<Gio::TlsInteractionResult>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
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

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::TlsCertificateRequestFlags>
    : public Glib::Value_Flags<Gio::TlsCertificateRequestFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;
  class LIBMM_GIO_SYMEXPORT TlsPassword;

  class LIBMM_GIO_SYMEXPORT TlsInteraction : public Glib::Object
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
    explicit TlsInteraction (const Glib::ConstructParams& construct_params);
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
    ask_password (const Glib::RefPtr<TlsPassword>& password,
                  const Glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    ask_password (const Glib::RefPtr<TlsPassword>& password)
        -> TlsInteractionResult;

    auto
    ask_password_async (const Glib::RefPtr<TlsPassword>& password,
                        const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    ask_password_async (const Glib::RefPtr<TlsPassword>& password,
                        const SlotAsyncReady& slot) -> void;

    auto
    ask_password_async (const Glib::RefPtr<TlsPassword>& password,
                        const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    ask_password_async (const Glib::RefPtr<TlsPassword>& password) -> void;

    auto
    ask_password_finish (const Glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

    auto
    invoke_ask_password (const Glib::RefPtr<TlsPassword>& password,
                         const Glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    invoke_ask_password (const Glib::RefPtr<TlsPassword>& password)
        -> TlsInteractionResult;

    auto
    invoke_request_certificate (const Glib::RefPtr<TlsConnection>& connection,
                                TlsCertificateRequestFlags flags,
                                const Glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    invoke_request_certificate (const Glib::RefPtr<TlsConnection>& connection,
                                TlsCertificateRequestFlags flags)
        -> TlsInteractionResult;

    auto
    request_certificate (const Glib::RefPtr<TlsConnection>& connection,
                         TlsCertificateRequestFlags flags,
                         const Glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    auto
    request_certificate (const Glib::RefPtr<TlsConnection>& connection,
                         TlsCertificateRequestFlags flags)
        -> TlsInteractionResult;

    auto
    request_certificate_async (const Glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const SlotAsyncReady& slot,
                               const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    request_certificate_async (const Glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const SlotAsyncReady& slot) -> void;

    auto
    request_certificate_async (const Glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags,
                               const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    auto
    request_certificate_async (const Glib::RefPtr<TlsConnection>& connection,
                               TlsCertificateRequestFlags flags) -> void;

    auto
    request_certificate_finish (const Glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

  protected:
    virtual auto
    ask_password_vfunc (const Glib::RefPtr<TlsPassword>& password,
                        const Glib::RefPtr<Cancellable>& cancellable)
        -> TlsInteractionResult;

    virtual auto
    ask_password_async_vfunc (const Glib::RefPtr<TlsPassword>& password,
                              const SlotAsyncReady& slot,
                              const Glib::RefPtr<Cancellable>& cancellable)
        -> void;

    virtual auto
    ask_password_finish_vfunc (const Glib::RefPtr<AsyncResult>& result)
        -> TlsInteractionResult;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsInteraction* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsInteraction>;
} // namespace Glib

#endif
