// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCLIENT_H
#define _GIOMM_SOCKETCLIENT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/enums.hxx>
#include <libmm-gio/proxyresolver.hxx>
#include <libmm-gio/socket.hxx>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/socketconnection.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketClient = struct _GSocketClient;
using GSocketClientClass = struct _GSocketClientClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT SocketClient_Class;
}
#endif

namespace Gio
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

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::SocketClientEvent>
    : public Glib::Value_Enum<Gio::SocketClientEvent>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SocketClient : public Glib::Object
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
    explicit SocketClient (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<SocketClient>;

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
    get_local_address () -> Glib::RefPtr<SocketAddress>;

    auto
    get_local_address () const -> Glib::RefPtr<const SocketAddress>;

    auto
    set_local_address (const Glib::RefPtr<SocketAddress>& address) -> void;

    auto
    connect (const Glib::RefPtr<SocketConnectable>& connectable,
             const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect (const Glib::RefPtr<SocketConnectable>& connectable)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_host (const Glib::ustring& host_and_port,
                     guint16 default_port,
                     const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_host (const Glib::ustring& host_and_port, guint16 default_port)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_service (const Glib::ustring& domain,
                        const Glib::ustring& service,
                        const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_service (const Glib::ustring& domain,
                        const Glib::ustring& service)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri (const Glib::ustring& uri,
                    guint16 default_port,
                    const Glib::RefPtr<Cancellable>& cancellable)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri (const Glib::ustring& uri, guint16 default_port)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_async (const Glib::RefPtr<SocketConnectable>& connectable,
                   const Glib::RefPtr<Cancellable>& cancellable,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_async (const Glib::RefPtr<SocketConnectable>& connectable,
                   const SlotAsyncReady& slot) -> void;

    auto
    connect_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_host_async (const Glib::ustring& host_and_port,
                           guint16 default_port,
                           const Glib::RefPtr<Cancellable>& cancellable,
                           const SlotAsyncReady& slot) -> void;

    auto
    connect_to_host_async (const Glib::ustring& host_and_port,
                           guint16 default_port,
                           const SlotAsyncReady& slot) -> void;

    auto
    connect_to_host_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_service_async (const Glib::ustring& domain,
                              const Glib::ustring& service,
                              const Glib::RefPtr<Cancellable>& cancellable,
                              const SlotAsyncReady& slot) -> void;

    auto
    connect_to_service_async (const Glib::ustring& domain,
                              const Glib::ustring& service,
                              const SlotAsyncReady& slot) -> void;

    auto
    connect_to_service_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<SocketConnection>;

    auto
    connect_to_uri_async (const Glib::ustring& uri,
                          guint16 default_port,
                          const Glib::RefPtr<Cancellable>& cancellable,
                          const SlotAsyncReady& slot) -> void;

    auto
    connect_to_uri_async (const Glib::ustring& uri,
                          guint16 default_port,
                          const SlotAsyncReady& slot) -> void;

    auto
    connect_to_uri_finish (const Glib::RefPtr<AsyncResult>& result)
        -> Glib::RefPtr<SocketConnection>;

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
    get_proxy_resolver () -> Glib::RefPtr<ProxyResolver>;

    auto
    get_proxy_resolver () const -> Glib::RefPtr<const ProxyResolver>;

    auto
    set_proxy_resolver (const Glib::RefPtr<ProxyResolver>& proxy_resolver)
        -> void;

    auto
    get_timeout () const -> guint;

    auto
    set_timeout (guint timeout) -> void;

    auto
    add_application_proxy (const Glib::ustring& protocol) -> void;

    auto
    property_family () -> Glib::PropertyProxy<SocketFamily>;

    auto
    property_family () const -> Glib::PropertyProxy_ReadOnly<SocketFamily>;

    auto
    property_local_address ()
        -> Glib::PropertyProxy<Glib::RefPtr<SocketAddress>>;

    auto
    property_local_address () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SocketAddress>>;

    auto
    property_protocol () -> Glib::PropertyProxy<Socket::Protocol>;

    auto
    property_protocol () const
        -> Glib::PropertyProxy_ReadOnly<Socket::Protocol>;

    auto
    property_type () -> Glib::PropertyProxy<Socket::Type>;

    auto
    property_type () const -> Glib::PropertyProxy_ReadOnly<Socket::Type>;

    auto
    property_timeout () -> Glib::PropertyProxy<guint>;

    auto
    property_timeout () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_enable_proxy () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_proxy () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tls () -> Glib::PropertyProxy<bool>;

    auto
    property_tls () const -> Glib::PropertyProxy_ReadOnly<bool>;

#ifndef GIOMM_DISABLE_DEPRECATED

    auto
    property_tls_validation_flags ()
        -> Glib::PropertyProxy<TlsCertificateFlags>;

    auto
    property_tls_validation_flags () const
        -> Glib::PropertyProxy_ReadOnly<TlsCertificateFlags>;

#endif

    auto
    property_proxy_resolver ()
        -> Glib::PropertyProxy<Glib::RefPtr<ProxyResolver>>;

    auto
    property_proxy_resolver () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ProxyResolver>>;

    auto
    signal_event ()
        -> Glib::SignalProxy<void (SocketClientEvent,
                                   const Glib::RefPtr<SocketConnectable>&,
                                   const Glib::RefPtr<IOStream>&)>;

  public:
  public:
  protected:
    virtual auto
    on_event (SocketClientEvent event,
              const Glib::RefPtr<SocketConnectable>& connectable,
              const Glib::RefPtr<IOStream>& connection) -> void;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketClient* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketClient>;
} // namespace Glib

#endif
