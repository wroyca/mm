
#ifndef _GIOMM_TLSPASSWORD_H
#define _GIOMM_TLSPASSWORD_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsPassword = struct _GTlsPassword;
using GTlsPasswordClass = struct _GTlsPasswordClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsPassword_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


/** TlsPassword - TLS Passwords for prompting.
 * Holds a password used in TLS.
 * @newin{2,36}
 */

class GIOMM_API TlsPassword : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsPassword;
  using CppClassType = TlsPassword_Class;
  using BaseObjectType = GTlsPassword;
  using BaseClassType = GTlsPasswordClass;

  // noncopyable
  TlsPassword(const TlsPassword&) = delete;
  auto operator=(const TlsPassword&) -> TlsPassword& = delete;

private:  friend class TlsPassword_Class;
  static CppClassType tlspassword_class_;

protected:
  explicit TlsPassword(const Glib::ConstructParams& construct_params);
  explicit TlsPassword(GTlsPassword* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsPassword(TlsPassword&& src) noexcept;
  auto operator=(TlsPassword&& src) noexcept -> TlsPassword&;

  ~TlsPassword() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsPassword*       { return reinterpret_cast<GTlsPassword*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsPassword* { return reinterpret_cast<GTlsPassword*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTlsPassword*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Flags NONE
   * No flags.
   *
   *  @var Flags RETRY
   * The password was wrong, and the user should retry.
   *
   *  @var Flags MANY_TRIES
   * Hint to the user that the password has been
   * wrong many times, and the user may not have many chances left.
   *
   *  @var Flags FINAL_TRY
   * Hint to the user that this is the last try to get
   * this password right.
   *
   *  @var Flags PKCS11_USER
   * For PKCS #11, the user PIN is required.
   * @newin{2,70}
   *
   *  @var Flags PKCS11_SECURITY_OFFICER
   * For PKCS #11, the security officer
   * PIN is required. @newin{2,70}
   *
   *  @var Flags PKCS11_CONTEXT_SPECIFIC
   * For PKCS #11, the context-specific
   * PIN is required. @newin{2,70}
   *
   *  @enum Flags
   *
   * Various flags for the password.
   *
   * @newin{2,30}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>TlsPassword::Flags operator|(TlsPassword::Flags, TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags operator&(TlsPassword::Flags, TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags operator^(TlsPassword::Flags, TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags operator~(TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags& operator|=(TlsPassword::Flags&, TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags& operator&=(TlsPassword::Flags&, TlsPassword::Flags)</tt><br>
   * <tt>TlsPassword::Flags& operator^=(TlsPassword::Flags&, TlsPassword::Flags)</tt><br>
   */
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
    explicit TlsPassword(const Glib::ustring& description, Flags flags =  Flags::NONE);


public:

  /** Create a new TlsPassword object.
   *
   * @param flags The password flags.
   * @param description Description of what the password is for.
   * @return The newly allocated password object.
   */


  static auto create(const Glib::ustring& description, Flags flags =  Flags::NONE) -> Glib::RefPtr<TlsPassword>;


  /** Get the password value. If @a length is not <tt>nullptr</tt> then it will be
   * filled in with the length of the password value. (Note that the
   * password value is not nul-terminated, so you can only pass <tt>nullptr</tt>
   * for @a length in contexts where you know the password will have a
   * certain fixed length.)
   *
   * @newin{2,30}
   *
   * @param length Location to place the length of the password.
   * @return The password value (owned by the password object).
   */
  auto get_value(gsize& length) const -> const guchar*;

  /// A get_value() convenience overload.
  auto get_value() const -> const guchar*;


  /** Set the value for this password. The @a value will be copied by the password
   * object.
   *
   * Specify the @a length, for a non-nul-terminated password. Pass -1 as
   *  @a length if using a nul-terminated password, and @a length will be
   * calculated automatically. (Note that the terminating nul is not
   * considered part of the password in this case.)
   *
   * @newin{2,30}
   *
   * @param value The new password value.
   * @param length The length of the password, or -1.
   */
  void set_value(const guchar* value, gssize length =  -1);
  // This function does not copy the value as g_tls_password_set_value() does.
  // It keeps a reference to the original value and expects it to be freed
  // later in a specified GDestroyNotify callback.  Ignore it for now.


  /** Get a description string about what the password will be used for.
   *
   * @newin{2,30}
   *
   * @return The description of the password.
   */
  auto get_description() const -> Glib::ustring;

  /** Set a description string about what the password will be used for.
   *
   * @newin{2,30}
   *
   * @param description The description of the password.
   */
  void set_description(const Glib::ustring& description);


  /** Get flags about the password.
   *
   * @newin{2,30}
   *
   * @return The flags about the password.
   */
  auto get_flags() const -> Flags;

  /** Set flags about the password.
   *
   * @newin{2,30}
   *
   * @param flags The flags about the password.
   */
  void set_flags(Flags flags);


  /** Get a user readable translated warning. Usually this warning is a
   * representation of the password flags returned from
   * g_tls_password_get_flags().
   *
   * @newin{2,30}
   *
   * @return The warning.
   */
  auto get_warning() const -> Glib::ustring;

  /** Set a user readable translated warning. Usually this warning is a
   * representation of the password flags returned from
   * g_tls_password_get_flags().
   *
   * @newin{2,30}
   *
   * @param warning The user readable warning.
   */
  void set_warning(const Glib::ustring& warning);

  /** Description of what the password is for.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_description() -> Glib::PropertyProxy< Glib::ustring > ;

/** Description of what the password is for.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_description() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Flags about the password.
   *
   * Default value: Gio::TlsPassword::Flags::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() -> Glib::PropertyProxy< Flags > ;

/** Flags about the password.
   *
   * Default value: Gio::TlsPassword::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;

  /** Warning about the password.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_warning() -> Glib::PropertyProxy< Glib::ustring > ;

/** Warning about the password.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_warning() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


protected:


    virtual auto get_value_vfunc(gsize& length) const -> const guchar*;


  //TODO? (See g_tls_password_set_value_full() comment above): _WRAP_VFUNC(void set_value(guchar* value, gssize length, GDestroyNotify destroy), "set_value")


    virtual auto get_default_warning_vfunc() const -> Glib::ustring;


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
inline auto operator|(TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  { return static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  { return static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(TlsPassword::Flags lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags
  { return static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(TlsPassword::Flags flags) -> TlsPassword::Flags
  { return static_cast<TlsPassword::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  { return (lhs = static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  { return (lhs = static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(TlsPassword::Flags& lhs, TlsPassword::Flags rhs) -> TlsPassword::Flags&
  { return (lhs = static_cast<TlsPassword::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsPassword::Flags> : public Glib::Value_Flags<Gio::TlsPassword::Flags>
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
   * @relates Gio::TlsPassword
   */
  GIOMM_API
  auto wrap(GTlsPassword* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsPassword>;
}


#endif /* _GIOMM_TLSPASSWORD_H */

