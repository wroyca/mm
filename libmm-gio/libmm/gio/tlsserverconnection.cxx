// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/tlsserverconnection.hxx>
#include <libmm/gio/tlsserverconnection_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/tlsserverconnectionimpl.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GTlsServerConnection* object, const bool take_copy) -> RefPtr<gio::TlsServerConnection>
  {
    return glib::make_refptr_for_instance<gio::TlsServerConnection> (
        glib::wrap_auto_interface<gio::TlsServerConnection> ((GObject*) object,
                                                             take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  TlsServerConnection_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TlsServerConnection_Class::iface_init_function;

      gtype_ = g_tls_server_connection_get_type ();
    }

    return *this;
  }

  auto
  TlsServerConnection_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  TlsServerConnection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TlsServerConnection ((GTlsServerConnection*) object);
  }

  TlsServerConnection::TlsServerConnection ()
    : Interface (tlsserverconnection_class_.init ())
  {
  }

  TlsServerConnection::TlsServerConnection (GTlsServerConnection* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  TlsServerConnection::TlsServerConnection (
      const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  TlsServerConnection::TlsServerConnection (TlsServerConnection&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  TlsServerConnection::operator= (TlsServerConnection&& src) noexcept -> TlsServerConnection&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  TlsServerConnection::~TlsServerConnection () noexcept = default;

  auto
  TlsServerConnection::add_interface (const GType gtype_implementer) -> void
  {
    tlsserverconnection_class_.init ().add_interface (gtype_implementer);
  }

  TlsServerConnection::CppClassType
      TlsServerConnection::tlsserverconnection_class_;

  auto
  TlsServerConnection::get_type () -> GType
  {
    return tlsserverconnection_class_.init ().get_type ();
  }

  auto
  TlsServerConnection::get_base_type () -> GType
  {
    return g_tls_server_connection_get_type ();
  }

  auto
  TlsServerConnection::create (const glib::RefPtr<IOStream>& base_io_stream,
                               const glib::RefPtr<TlsCertificate>& certificate) -> glib::RefPtr<TlsServerConnectionImpl>
  {
    GError* gerror = nullptr;
    auto retvalue = std::dynamic_pointer_cast<TlsServerConnectionImpl> (
        glib::wrap (G_TLS_CONNECTION (
            g_tls_server_connection_new (glib::unwrap (base_io_stream),
                                         glib::unwrap (certificate),
                                         &gerror))));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          TlsAuthenticationMode>::value,
      "Type TlsAuthenticationMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TlsServerConnection::property_authentication_mode () -> glib::PropertyProxy<TlsAuthenticationMode>
  {
    return {this, "authentication-mode"};
  }

  auto
  TlsServerConnection::property_authentication_mode () const -> glib::PropertyProxy_ReadOnly<TlsAuthenticationMode>
  {
    return {this, "authentication-mode"};
  }

} // namespace gio
