// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCONNECTION_H
#define _GIOMM_TLSCONNECTION_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/gio/tlscertificate.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsConnection = struct _GTlsConnection;
using GTlsConnectionClass = struct _GTlsConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TlsConnection_Class;
}
#endif

namespace gio
{

  enum class TlsProtocolVersion
  {
    UNKNOWN = 0,
    SSL_3_0 = 1,
    TLS_1_0 = 2,
    TLS_1_1 = 3,
    TLS_1_2 = 4,
    TLS_1_3 = 5,
    DTLS_1_0 = 201,
    DTLS_1_2 = 202
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::TlsProtocolVersion>
    : public glib::Value_Enum<gio::TlsProtocolVersion>
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
  class LIBMM_GIO_SYMEXPORT TlsDatabase;
  class LIBMM_GIO_SYMEXPORT TlsInteraction;

  class LIBMM_GIO_SYMEXPORT TlsConnection : public IOStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsConnection;
    using CppClassType = TlsConnection_Class;
    using BaseObjectType = GTlsConnection;
    using BaseClassType = GTlsConnectionClass;

    TlsConnection (const TlsConnection&) = delete;
    auto
    operator= (const TlsConnection&) -> TlsConnection& = delete;

  private:
    friend class TlsConnection_Class;
    static CppClassType tlsconnection_class_;

  protected:
    explicit TlsConnection (const glib::ConstructParams& construct_params);
    explicit TlsConnection (GTlsConnection* castitem);

#endif

  public:
    TlsConnection (TlsConnection&& src) noexcept;
    auto
    operator= (TlsConnection&& src) noexcept -> TlsConnection&;

    ~TlsConnection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsConnection*
    {
      return reinterpret_cast<GTlsConnection*> (gobject_);
    }

    auto
    gobj () const -> const GTlsConnection*
    {
      return reinterpret_cast<GTlsConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GTlsConnection*;

  private:
  protected:
    TlsConnection ();

  public:
    auto
    set_certificate (const glib::RefPtr<TlsCertificate>& certificate) -> void;

    auto
    get_certificate () -> glib::RefPtr<TlsCertificate>;

    auto
    get_certificate () const -> glib::RefPtr<const TlsCertificate>;

    auto
    get_peer_certificate () -> glib::RefPtr<TlsCertificate>;

    auto
    get_peer_certificate () const -> glib::RefPtr<const TlsCertificate>;

    auto
    get_peer_certificate_errors () const -> TlsCertificateFlags;

    auto
    set_require_close_notify (bool require_close_notify = true) -> void;

    auto
    get_require_close_notify () const -> bool;

    auto
    get_database () -> glib::RefPtr<TlsDatabase>;

    auto
    get_database () const -> glib::RefPtr<const TlsDatabase>;

    auto
    set_database (const glib::RefPtr<TlsDatabase>& database) -> void;

    auto
    get_interaction () -> glib::RefPtr<TlsInteraction>;

    auto
    get_interaction () const -> glib::RefPtr<const TlsInteraction>;

    auto
    set_interaction (const glib::RefPtr<TlsInteraction>& interaction) -> void;

    auto
    handshake (const glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    handshake () -> bool;

    auto
    handshake_async (const SlotAsyncReady& slot,
                     const glib::RefPtr<Cancellable>& cancellable,
                     int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    handshake_async (const SlotAsyncReady& slot,
                     int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    handshake_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_protocol_version () const -> TlsProtocolVersion;

    auto
    get_ciphersuite_name () const -> glib::ustring;

    auto
    emit_accept_certificate (
        const glib::RefPtr<const TlsCertificate>& peer_cert,
        TlsCertificateFlags errors) -> bool;

    auto
    property_base_io_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<IOStream>>;

    auto
    property_certificate ()
        -> glib::PropertyProxy<glib::RefPtr<TlsCertificate>>;

    auto
    property_certificate () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsCertificate>>;

    auto
    property_database () -> glib::PropertyProxy<glib::RefPtr<TlsDatabase>>;

    auto
    property_database () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsDatabase>>;

    auto
    property_interaction ()
        -> glib::PropertyProxy<glib::RefPtr<TlsInteraction>>;

    auto
    property_interaction () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsInteraction>>;

    auto
    property_peer_certificate () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsCertificate>>;

    auto
    property_peer_certificate_errors () const
        -> glib::PropertyProxy_ReadOnly<TlsCertificateFlags>;

    auto
    property_require_close_notify () -> glib::PropertyProxy<bool>;

    auto
    property_require_close_notify () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_protocol_version () const
        -> glib::PropertyProxy_ReadOnly<TlsProtocolVersion>;

    auto
    property_ciphersuite_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    signal_accept_certificate ()
        -> glib::SignalProxy<bool (const glib::RefPtr<const TlsCertificate>&,
                                   TlsCertificateFlags)>;

  protected:
    virtual auto
    handshake_vfunc (const glib::RefPtr<Cancellable>& cancellable) -> bool;

    virtual auto
    handshake_async_vfunc (const SlotAsyncReady& slot,
                           const glib::RefPtr<Cancellable>& cancellable,
                           int io_priority) -> void;

    virtual auto
    handshake_finish_vfunc (const glib::RefPtr<AsyncResult>& result) -> bool;

  public:
  public:
  protected:
    virtual auto
    on_accept_certificate (const glib::RefPtr<const TlsCertificate>& peer_cert,
                           TlsCertificateFlags errors) -> bool;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsConnection* object, bool take_copy = false) -> glib::RefPtr<gio::TlsConnection>;
} // namespace glib

#endif
