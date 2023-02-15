// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSPASSWORD_H
#define _GIOMM_TLSPASSWORD_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsPassword = struct _GTlsPassword;
using GTlsPasswordClass = struct _GTlsPasswordClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API TlsPassword_Class;
}
#endif

namespace Gio
{

  class GIOMM_API TlsPassword : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsPassword;
    using CppClassType = TlsPassword_Class;
    using BaseObjectType = GTlsPassword;
    using BaseClassType = GTlsPasswordClass;

    TlsPassword (const TlsPassword&) = delete;
    auto
    operator= (const TlsPassword&) -> TlsPassword& = delete;

  private:
    friend class TlsPassword_Class;
    static CppClassType tlspassword_class_;

  protected:
    explicit TlsPassword (const Glib::ConstructParams& construct_params);
    explicit TlsPassword (GTlsPassword* castitem);

#endif

  public:
    TlsPassword (TlsPassword&& src) noexcept;
    auto
    operator= (TlsPassword&& src) noexcept -> TlsPassword&;

    ~TlsPassword () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsPassword*
    {
      return reinterpret_cast<GTlsPassword*> (gobject_);
    }

    auto
    gobj () const -> const GTlsPassword*
    {
      return reinterpret_cast<GTlsPassword*> (gobject_);
    }

    auto
    gobj_copy () -> GTlsPassword*;

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      RETRY = 1 << 1,
      MANY_TRIES = 1 << 2,
      FINAL_TRY = 1 << 3,
      PKCS11_USER = 1 << 4,
      PKCS11_SECURITY_OFFICER = 1 << 5,
      PKCS11_CONTEXT_SPECIFIC = 1 << 6
    };

  protected:
    explicit TlsPassword (const Glib::ustring& description,
                          Flags flags = Flags::NONE);

  public:
    static auto
    create (const Glib::ustring& description, Flags flags = Flags::NONE)
        -> Glib::RefPtr<TlsPassword>;

    auto
    get_value (gsize& length) const -> const guchar*;

    auto
    get_value () const -> const guchar*;

    auto
    set_value (const guchar* value, gssize length = -1) -> void;

    auto
    get_description () const -> Glib::ustring;

    auto
    set_description (const Glib::ustring& description) -> void;

    auto
    get_flags () const -> Flags;

    auto
    set_flags (Flags flags) -> void;

    auto
    get_warning () const -> Glib::ustring;

    auto
    set_warning (const Glib::ustring& warning) -> void;

    auto
    property_description () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_description () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_flags () -> Glib::PropertyProxy<Flags>;

    auto
    property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_warning () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_warning () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  protected:
    virtual auto
    get_value_vfunc (gsize& length) const -> const guchar*;

    virtual auto
    get_default_warning_vfunc () const -> Glib::ustring;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Gio
{

  inline auto
  operator| (TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  {
    return static_cast<TlsPassword::Flags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  {
    return static_cast<TlsPassword::Flags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  {
    return static_cast<TlsPassword::Flags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TlsPassword::Flags flags) -> TlsPassword::Flags
  {
    return static_cast<TlsPassword::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  {
    return (lhs = static_cast<TlsPassword::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  {
    return (lhs = static_cast<TlsPassword::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  {
    return (lhs = static_cast<TlsPassword::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::TlsPassword::Flags>
    : public Glib::Value_Flags<Gio::TlsPassword::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GIOMM_API
  auto
  wrap (GTlsPassword* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsPassword>;
} // namespace Glib

#endif
