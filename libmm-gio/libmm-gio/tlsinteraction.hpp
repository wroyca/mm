
#ifndef _GIOMM_TLSINTERACTION_H
#define _GIOMM_TLSINTERACTION_H


#include <libmm-glib/ustring.hpp>
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

#include <libmm-glib/object.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/tlsconnection.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsInteraction = struct _GTlsInteraction;
using GTlsInteractionClass = struct _GTlsInteractionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API TlsInteraction_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var TlsInteractionResult UNHANDLED
 * The interaction was unhandled (i.e.\ not
 * implemented).
 *
 *  @var TlsInteractionResult HANDLED
 * The interaction completed, and resulting data
 * is available.
 *
 *  @var TlsInteractionResult FAILED
 * The interaction has failed, or was cancelled.
 * and the operation should be aborted.
 *
 *  @enum TlsInteractionResult
 *
 * TlsInteractionResult is returned by various functions in TlsInteraction
 * when finishing an interaction request.
 *
 * @newin{2,30}
 *
 * @ingroup giommEnums
 */
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
class GIOMM_API Value<Gio::TlsInteractionResult> : public Glib::Value_Enum<Gio::TlsInteractionResult>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/**
 *  @var TlsCertificateRequestFlags NONE
 * No flags.
 *
 *  @enum TlsCertificateRequestFlags
 *
 * Flags for g_tls_interaction_request_certificate(),
 * g_tls_interaction_request_certificate_async(), and
 * g_tls_interaction_invoke_request_certificate().
 *
 * @newin{2,40}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>TlsCertificateRequestFlags operator|(TlsCertificateRequestFlags, TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags operator&(TlsCertificateRequestFlags, TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags operator^(TlsCertificateRequestFlags, TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags operator~(TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags& operator|=(TlsCertificateRequestFlags&, TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags& operator&=(TlsCertificateRequestFlags&, TlsCertificateRequestFlags)</tt><br>
 * <tt>TlsCertificateRequestFlags& operator^=(TlsCertificateRequestFlags&, TlsCertificateRequestFlags)</tt><br>
 */
enum class TlsCertificateRequestFlags
{
  NONE = 0x0
};

/** @ingroup giommEnums */
inline auto operator|(TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  { return static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  { return static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(TlsCertificateRequestFlags lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags
  { return static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(TlsCertificateRequestFlags flags) -> TlsCertificateRequestFlags
  { return static_cast<TlsCertificateRequestFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  { return (lhs = static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  { return (lhs = static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(TlsCertificateRequestFlags& lhs, TlsCertificateRequestFlags rhs) -> TlsCertificateRequestFlags&
  { return (lhs = static_cast<TlsCertificateRequestFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::TlsCertificateRequestFlags> : public Glib::Value_Flags<Gio::TlsCertificateRequestFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


class GIOMM_API Cancellable;
class GIOMM_API TlsPassword;

/** TlsInteraction - Interaction with the user during TLS operations.
 * TlsInteraction provides a mechanism for the TLS connection and database code
 * to interact with the user. It can be used to ask the user for passwords.
 *
 * To use a TlsInteraction with a TLS connection use
 * Gio::TlsConnection::set_interaction().
 *
 * Callers should instantiate a derived class that implements the various
 * interaction methods to show the required dialogs.
 *
 * Callers should use the 'invoke' functions like invoke_ask_password() to run
 * interaction methods. These functions make sure that the interaction is
 * invoked in the main loop and not in the current thread, if the current
 * thread is not running the main loop.
 *
 * Derived classes can choose to implement whichever interactions methods
 * they'd like to support by overriding those virtual methods. Any interactions
 * not implemented will return Gio::TLS_INTERACTION_UNHANDLED. If a derived
 * class implements an async method, it must also implement the corresponding
 * finish method.
 * @newin{2,36}
 */

class GIOMM_API TlsInteraction : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsInteraction;
  using CppClassType = TlsInteraction_Class;
  using BaseObjectType = GTlsInteraction;
  using BaseClassType = GTlsInteractionClass;

  // noncopyable
  TlsInteraction(const TlsInteraction&) = delete;
  auto operator=(const TlsInteraction&) -> TlsInteraction& = delete;

private:  friend class TlsInteraction_Class;
  static CppClassType tlsinteraction_class_;

protected:
  explicit TlsInteraction(const Glib::ConstructParams& construct_params);
  explicit TlsInteraction(GTlsInteraction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsInteraction(TlsInteraction&& src) noexcept;
  auto operator=(TlsInteraction&& src) noexcept -> TlsInteraction&;

  ~TlsInteraction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GTlsInteraction*       { return reinterpret_cast<GTlsInteraction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GTlsInteraction* { return reinterpret_cast<GTlsInteraction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GTlsInteraction*;

private:


protected:
  TlsInteraction();

public:

  /** Run synchronous interaction to ask the user for a password. In general,
   * g_tls_interaction_invoke_ask_password() should be used instead of this
   * function.
   *
   * Derived subclasses usually implement a password prompt, although they may
   * also choose to provide a password from elsewhere. The @a password value will
   * be filled in and then @a callback will be called. Alternatively the user may
   * abort this password request, which will usually abort the TLS connection.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code. Certain implementations may
   * not support immediate cancellation.
   *
   * @newin{2,30}
   *
   * @param password A TlsPassword object.
   * @param cancellable An optional Cancellable cancellation object.
   * @return The status of the ask password interaction.
   *
   * @throws Glib::Error
   */
  auto ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult;

  /// A ask_password() convenience overload.
  auto ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult;

  /** Run asynchronous interaction to ask the user for a password. In general,
   * g_tls_interaction_invoke_ask_password() should be used instead of this
   * function.
   *
   * Derived subclasses usually implement a password prompt, although they may
   * also choose to provide a password from elsewhere. The @a password value will
   * be filled in and then @a slot will be called. Alternatively the user may
   * abort this password request, which will usually abort the TLS connection.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code. Certain implementations may
   * not support immediate cancellation.
   *
   * Certain implementations may not support immediate cancellation.
   *
   * @newin{2,30}
   *
   * @param password A TlsPassword object.
   * @param cancellable An optional Cancellable cancellation object.
   * @param slot Will be called when the interaction completes.
   */
  void ask_password_async(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// A ask_password_async() convenience overload.
  void ask_password_async(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot);

  /// A ask_password_async() convenience overload.
  void ask_password_async(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable);

  /// A ask_password_async() convenience overload.
  void ask_password_async(const Glib::RefPtr<TlsPassword>& password);

  /** Complete an ask password user interaction request. This should be once
   * the g_tls_interaction_ask_password_async() completion callback is called.
   *
   * If Gio::TlsInteractionResult::HANDLED is returned, then the TlsPassword passed
   * to g_tls_interaction_ask_password() will have its password filled in.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code.
   *
   * @newin{2,30}
   *
   * @param result The result passed to the callback.
   * @return The status of the ask password interaction.
   *
   * @throws Glib::Error
   */
  auto ask_password_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult;

  /** Invoke the interaction to ask the user for a password. It invokes this
   * interaction in the main loop, specifically the MainContext returned by
   * Glib::main_context_get_thread_default() when the interaction is created. This
   * is called by called by TlsConnection or TlsDatabase to ask the user
   * for a password.
   *
   * Derived subclasses usually implement a password prompt, although they may
   * also choose to provide a password from elsewhere. The @a password value will
   * be filled in and then @a callback will be called. Alternatively the user may
   * abort this password request, which will usually abort the TLS connection.
   *
   * The implementation can either be a synchronous (eg: modal dialog) or an
   * asynchronous one (eg: modeless dialog). This function will take care of
   * calling which ever one correctly.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code. Certain implementations may
   * not support immediate cancellation.
   *
   * @newin{2,30}
   *
   * @param password A TlsPassword object.
   * @param cancellable An optional Cancellable cancellation object.
   * @return The status of the ask password interaction.
   *
   * @throws Glib::Error
   */
  auto invoke_ask_password(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult;

  /// A invoke_ask_password() convenience overload.
  auto invoke_ask_password(const Glib::RefPtr<TlsPassword>& password) -> TlsInteractionResult;


  /** Invoke the interaction to ask the user to choose a certificate to
   * use with the connection. It invokes this interaction in the main
   * loop, specifically the MainContext returned by
   * Glib::main_context_get_thread_default() when the interaction is
   * created. This is called by called by TlsConnection when the peer
   * requests a certificate during the handshake.
   *
   * Derived subclasses usually implement a certificate selector,
   * although they may also choose to provide a certificate from
   * elsewhere. Alternatively the user may abort this certificate
   * request, which may or may not abort the TLS connection.
   *
   * The implementation can either be a synchronous (eg: modal dialog) or an
   * asynchronous one (eg: modeless dialog). This function will take care of
   * calling which ever one correctly.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code. Certain implementations may
   * not support immediate cancellation.
   *
   * @newin{2,40}
   *
   * @param connection A TlsConnection object.
   * @param flags Flags providing more information about the request.
   * @param cancellable An optional Cancellable cancellation object.
   * @return The status of the certificate request interaction.
   *
   * @throws Glib::Error
   */
  auto invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult;

  /// A invoke_request_certificate() convenience overload.
  auto invoke_request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult;


  /** Run synchronous interaction to ask the user to choose a certificate to use
   * with the connection. In general, g_tls_interaction_invoke_request_certificate()
   * should be used instead of this function.
   *
   * Derived subclasses usually implement a certificate selector, although they may
   * also choose to provide a certificate from elsewhere. Alternatively the user may
   * abort this certificate request, which will usually abort the TLS connection.
   *
   * If Gio::TlsInteractionResult::HANDLED is returned, then the TlsConnection
   * passed to g_tls_interaction_request_certificate() will have had its
   * TlsConnection::property_certificate() filled in.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code. Certain implementations may
   * not support immediate cancellation.
   *
   * @newin{2,40}
   *
   * @param connection A TlsConnection object.
   * @param flags Flags providing more information about the request.
   * @param cancellable An optional Cancellable cancellation object.
   * @return The status of the request certificate interaction.
   *
   * @throws Glib::Error
   */
  auto request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult;

  /// A request_certificate() convenience overload.
  auto request_certificate(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags) -> TlsInteractionResult;


  /** Run asynchronous interaction to ask the user for a certificate to use with
   * the connection. In general, g_tls_interaction_invoke_request_certificate() should
   * be used instead of this function.
   *
   * Derived subclasses usually implement a certificate selector, although they may
   * also choose to provide a certificate from elsewhere. @a slot will be called
   * when the operation completes. Alternatively the user may abort this certificate
   * request, which will usually abort the TLS connection.
   *
   * @newin{2,40}
   *
   * @param connection A TlsConnection object.
   * @param flags Flags providing more information about the request.
   * @param cancellable An optional Cancellable cancellation object.
   * @param slot Will be called when the interaction completes.
   */
  void request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// A request_certificate_async() convenience overload.
  void request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const SlotAsyncReady& slot);

  /// A request_certificate_async() convenience overload.
  void request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags, const Glib::RefPtr<Cancellable>& cancellable);

  /// A request_certificate_async() convenience overload.
  void request_certificate_async(const Glib::RefPtr<TlsConnection>& connection, TlsCertificateRequestFlags flags);


  /** Complete a request certificate user interaction request. This should be once
   * the g_tls_interaction_request_certificate_async() completion callback is called.
   *
   * If Gio::TlsInteractionResult::HANDLED is returned, then the TlsConnection
   * passed to g_tls_interaction_request_certificate_async() will have had its
   * TlsConnection::property_certificate() filled in.
   *
   * If the interaction is cancelled by the cancellation object, or by the
   * user then Gio::TlsInteractionResult::FAILED will be returned with an error that
   * contains a Gio::Error::CANCELLED error code.
   *
   * @newin{2,40}
   *
   * @param result The result passed to the callback.
   * @return The status of the request certificate interaction.
   *
   * @throws Glib::Error
   */
  auto request_certificate_finish(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult;

protected:


  /// @throws Glib::Error.
  virtual auto ask_password_vfunc(const Glib::RefPtr<TlsPassword>& password, const Glib::RefPtr<Cancellable>& cancellable) -> TlsInteractionResult;

    virtual void ask_password_async_vfunc(const Glib::RefPtr<TlsPassword>& password, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);


  /// @throws Glib::Error.
  virtual auto ask_password_finish_vfunc(const Glib::RefPtr<AsyncResult>& result) -> TlsInteractionResult;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::TlsInteraction
   */
  GIOMM_API
  auto wrap(GTlsInteraction* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsInteraction>;
}


#endif /* _GIOMM_TLSINTERACTION_H */

