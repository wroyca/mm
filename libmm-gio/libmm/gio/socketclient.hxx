// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCLIENT_H
#define _GIOMM_SOCKETCLIENT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/enums.hxx>
#include <libmm/gio/proxyresolver.hxx>
#include <libmm/gio/socket.hxx>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/gio/socketconnection.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketClient = struct _GSocketClient;
using GSocketClientClass = struct _GSocketClientClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketClient_Class;
}
#endif

namespace gio
{

  enum class SocketClientEvent
  {
    RESOLVING,
    RESOLVED,
    CONNECTING,
    CONNECTED,
    PROXY_NEGOTIATING,
    PROXY_NEGOTIATED,
    TLS_HANDSHAKING,
    TLS_HANDSHAKED,
    COMPLETE
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::SocketClientEvent>
    : public glib::Value_Enum<gio::SocketClientEvent>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketClient : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketClient;
    using CppClassType = SocketClient_Class;
    using BaseObjectType = GSocketClient;
    using BaseClassType = GSocketClientClass;

    SocketClient (const SocketClient&) = delete;
    auto
    operator= (const SocketClient&) -> SocketClient& = delete;

  private:
    friend class SocketClient_Class;
    static CppClassType socketclient_class_;

  protected:
    explicit SocketClient (const glib::ConstructParams& construct_params);
    explicit SocketClient (GSocketClient* castitem);

#endif

  public:
    SocketClient (SocketClient&& src) noexcept;
    auto
    operator= (SocketClient&& src) noexcept -> SocketClient&;

    ~SocketClient () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketClient*
    {
      return reinterpret_cast<GSocketClient*> (gobject_);
    }

    auto
    gobj () const -> const GSocketClient*
    {
      return reinterpret_cast<GSocketClient*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketClient*;

  private:
  protected:
    SocketClient ();

  public:
    static auto
    create () -> glib::RefPtr<SocketClient>;

    auto
    get_family () const -> SocketFamily;

    auto
    set_family (SocketFamily family) -> void;

    auto
    get_socket_type () const -> Socket::Type;

    auto
    set_socket_type (Socket::Type type) -> void;

    auto
    get_protocol () const -> Socket::Protocol;

    auto
    set_protocol (Socket::Protocol protocol) -> void;

    auto
    get_local_address () -> glib::RefPtr<SocketAddress>;

    auto
    get_local_address () const -> glib::RefPtr<const SocketAddress>;

    auto
    set_local_address (const glib::RefPtr<SocketAddress>& address) -> void;

    auto
    connect (const glib::RefPtr<SocketConnectable>& connectable,
             const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect (const glib::RefPtr<SocketConnectable>& connectable)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_host (const glib::ustring& host_and_port,
                     guint16 default_port,
                     const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_host (const glib::ustring& host_and_port, guint16 default_port)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_service (const glib::ustring& domain,
                        const glib::ustring& service,
                        const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_service (const glib::ustring& domain,
                        const glib::ustring& service)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri (const glib::ustring& uri,
                    guint16 default_port,
                    const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri (const glib::ustring& uri, guint16 default_port)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_async (const glib::RefPtr<SocketConnectable>& connectable,
                   const glib::RefPtr<Cancellable>& cancellable,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_async (const glib::RefPtr<SocketConnectable>& connectable,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_host_async (const glib::ustring& host_and_port,
                           guint16 default_port,
                           const glib::RefPtr<Cancellable>& cancellable,
                           const SlotAsyncReady& slot) -> void;

    auto
    connect_to_host_async (const glib::ustring& host_and_port,
                           guint16 default_port,
                           const SlotAsyncReady& slot) -> void;

    auto
    connect_to_host_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_service_async (const glib::ustring& domain,
                              const glib::ustring& service,
                              const glib::RefPtr<Cancellable>& cancellable,
                              const SlotAsyncReady& slot) -> void;

    auto
    connect_to_service_async (const glib::ustring& domain,
                              const glib::ustring& service,
                              const SlotAsyncReady& slot) -> void;

    auto
    connect_to_service_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri_async (const glib::ustring& uri,
                          guint16 default_port,
                          const glib::RefPtr<Cancellable>& cancellable,
                          const SlotAsyncReady& slot) -> void;

    auto
    connect_to_uri_async (const glib::ustring& uri,
                          guint16 default_port,
                          const SlotAsyncReady& slot) -> void;

    auto
    connect_to_uri_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketConnection>;

    auto
    get_enable_proxy () const -> bool;

    auto
    set_enable_proxy (bool enable) -> void;

    auto
    get_tls () const -> bool;

    auto
    set_tls (bool tls = true) -> void;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    get_tls_validation_flags () const -> TlsCertificateFlags;
#endif

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    set_tls_validation_flags (TlsCertificateFlags flags) -> void;
#endif

    auto
    get_proxy_resolver () -> glib::RefPtr<ProxyResolver>;

    auto
    get_proxy_resolver () const -> glib::RefPtr<const ProxyResolver>;

    auto
    set_proxy_resolver (const glib::RefPtr<ProxyResolver>& proxy_resolver)
        -> void;

    auto
    get_timeout () const -> guint;

    auto
    set_timeout (guint timeout) -> void;

    auto
    add_application_proxy (const glib::ustring& protocol) -> void;

    auto
    property_family () -> glib::PropertyProxy<SocketFamily>;

    auto
    property_family () const -> glib::PropertyProxy_ReadOnly<SocketFamily>;

    auto
    property_local_address ()
        -> glib::PropertyProxy<glib::RefPtr<SocketAddress>>;

    auto
    property_local_address () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SocketAddress>>;

    auto
    property_protocol () -> glib::PropertyProxy<Socket::Protocol>;

    auto
    property_protocol () const
        -> glib::PropertyProxy_ReadOnly<Socket::Protocol>;

    auto
    property_type () -> glib::PropertyProxy<Socket::Type>;

    auto
    property_type () const -> glib::PropertyProxy_ReadOnly<Socket::Type>;

    auto
    property_timeout () -> glib::PropertyProxy<guint>;

    auto
    property_timeout () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_enable_proxy () -> glib::PropertyProxy<bool>;

    auto
    property_enable_proxy () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tls () -> glib::PropertyProxy<bool>;

    auto
    property_tls () const -> glib::PropertyProxy_ReadOnly<bool>;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    property_tls_validation_flags ()
        -> glib::PropertyProxy<TlsCertificateFlags>;

    auto
    property_tls_validation_flags () const
        -> glib::PropertyProxy_ReadOnly<TlsCertificateFlags>;

#endif

    auto
    property_proxy_resolver ()
        -> glib::PropertyProxy<glib::RefPtr<ProxyResolver>>;

    auto
    property_proxy_resolver () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ProxyResolver>>;

    auto
    signal_event ()
        -> glib::SignalProxy<void (SocketClientEvent,
                                   const glib::RefPtr<SocketConnectable>&,
                                   const glib::RefPtr<IOStream>&)>;

  public:
  public:
  protected:
    virtual auto
    on_event (SocketClientEvent event,
              const glib::RefPtr<SocketConnectable>& connectable,
              const glib::RefPtr<IOStream>& connection) -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketClient* object, bool take_copy = false) -> glib::RefPtr<gio::SocketClient>;
} // namespace glib

#endif
