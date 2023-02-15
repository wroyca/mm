// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tlsclientconnection.hxx>
#include <libmm-gio/tlsclientconnection_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/tlsclientconnectionimpl.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GTlsClientConnection* object, const bool take_copy) -> RefPtr<Gio::TlsClientConnection>
  {
    return Glib::make_refptr_for_instance<Gio::TlsClientConnection> (
        Glib::wrap_auto_interface<Gio::TlsClientConnection> ((GObject*) object,
                                                             take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  TlsClientConnection_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsClientConnection_Class::iface_init_function;

      gtype_ = g_tls_client_connection_get_type ();
    }

    return *this;
  }

  auto
  TlsClientConnection_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  TlsClientConnection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TlsClientConnection ((GTlsClientConnection*) object);
  }

  TlsClientConnection::TlsClientConnection ()
    : Interface (tlsclientconnection_class_.init ())
  {
  }

  TlsClientConnection::TlsClientConnection (GTlsClientConnection* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  TlsClientConnection::TlsClientConnection (
      const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  TlsClientConnection::TlsClientConnection (TlsClientConnection&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  TlsClientConnection::operator= (TlsClientConnection&& src) noexcept -> TlsClientConnection&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  TlsClientConnection::~TlsClientConnection () noexcept = default;

  auto
  TlsClientConnection::add_interface (const GType gtype_implementer) -> void
  {
    tlsclientconnection_class_.init ().add_interface (gtype_implementer);
  }

  TlsClientConnection::CppClassType
      TlsClientConnection::tlsclientconnection_class_;

  auto
  TlsClientConnection::get_type () -> GType
  {
    return tlsclientconnection_class_.init ().get_type ();
  }

  auto
  TlsClientConnection::get_base_type () -> GType
  {
    return g_tls_client_connection_get_type ();
  }

  auto
  TlsClientConnection::create (
      const Glib::RefPtr<IOStream>& base_io_stream,
      const Glib::RefPtr<const SocketConnectable>& server_identity) -> Glib::RefPtr<TlsClientConnectionImpl>
  {
    GError* gerror = nullptr;
    auto retvalue = std::dynamic_pointer_cast<TlsClientConnectionImpl> (
        Glib::wrap (G_TLS_CONNECTION (g_tls_client_connection_new (
            Glib::unwrap (base_io_stream),
            const_cast<GSocketConnectable*> (Glib::unwrap (server_identity)),
            &gerror))));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsClientConnection::create (const Glib::RefPtr<IOStream>& base_io_stream) -> Glib::RefPtr<TlsClientConnectionImpl>
  {
    GError* gerror = nullptr;
    auto retvalue = std::dynamic_pointer_cast<TlsClientConnectionImpl> (
        Glib::wrap (G_TLS_CONNECTION (
            g_tls_client_connection_new (Glib::unwrap (base_io_stream),
                                         nullptr,
                                         &gerror))));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  TlsClientConnection::set_server_identity (
      const Glib::RefPtr<SocketConnectable>& identity) -> void
  {
    g_tls_client_connection_set_server_identity (gobj (),
                                                 Glib::unwrap (identity));
  }

  auto
  TlsClientConnection::get_server_identity () -> Glib::RefPtr<SocketConnectable>
  {
    auto retvalue =
        Glib::wrap (g_tls_client_connection_get_server_identity (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TlsClientConnection::get_server_identity () const -> Glib::RefPtr<const SocketConnectable>
  {
    return const_cast<TlsClientConnection*> (this)->get_server_identity ();
  }

#ifndef GIOMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  TlsClientConnection::set_validation_flags (TlsCertificateFlags flags) -> void
  {
    g_tls_client_connection_set_validation_flags (
        gobj (),
        static_cast<GTlsCertificateFlags> (flags));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GIOMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  TlsClientConnection::get_validation_flags () const -> TlsCertificateFlags
  {
    return static_cast<TlsCertificateFlags> (
        g_tls_client_connection_get_validation_flags (
            const_cast<GTlsClientConnection*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  TlsClientConnection::get_accepted_cas () -> std::vector<Glib::RefPtr<Glib::ByteArray>>
  {
    return Glib::ListHandler<Glib::RefPtr<Glib::ByteArray>>::list_to_vector (
        g_tls_client_connection_get_accepted_cas (gobj ()),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  TlsClientConnection::get_accepted_cas () const -> std::vector<Glib::RefPtr<const Glib::ByteArray>>
  {
    return Glib::ListHandler<Glib::RefPtr<const Glib::ByteArray>>::
        list_to_vector (g_tls_client_connection_get_accepted_cas (
                            const_cast<GTlsClientConnection*> (gobj ())),
                        Glib::OWNERSHIP_DEEP);
  }

  auto
  TlsClientConnection::copy_session_state (
      const Glib::RefPtr<TlsClientConnection>& source) -> void
  {
    g_tls_client_connection_copy_session_state (gobj (), Glib::unwrap (source));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<SocketConnectable>>::value,
      "Type Glib::RefPtr<SocketConnectable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsClientConnection::property_server_identity () -> Glib::PropertyProxy<Glib::RefPtr<SocketConnectable>>
  {
    return {this, "server-identity"};
  }

  auto
  TlsClientConnection::property_server_identity () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SocketConnectable>>
  {
    return {this, "server-identity"};
  }

#ifndef GIOMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TlsCertificateFlags>::value,
      "Type TlsCertificateFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TlsClientConnection::property_validation_flags () -> Glib::PropertyProxy<TlsCertificateFlags>
  {
    return {this, "validation-flags"};
  }
#endif

#ifndef GIOMM_DISABLE_DEPRECATED

  auto
  TlsClientConnection::property_validation_flags () const -> Glib::PropertyProxy_ReadOnly<TlsCertificateFlags>
  {
    return {this, "validation-flags"};
  }
#endif

} // namespace Gio
