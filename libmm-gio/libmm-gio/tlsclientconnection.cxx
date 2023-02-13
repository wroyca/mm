


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/tlsclientconnection.hxx>
#include <libmm-gio/tlsclientconnection_p.hxx>


/* Copyright (C) 2013 The giomm Development Team
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

#include <gio/gio.h>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/tlsclientconnectionimpl.hxx>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GTlsClientConnection* object, const bool take_copy) -> RefPtr<Gio::TlsClientConnection>
{
  return Glib::make_refptr_for_instance<Gio::TlsClientConnection>( Glib::wrap_auto_interface<Gio::TlsClientConnection> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto TlsClientConnection_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TlsClientConnection_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_tls_client_connection_get_type();
  }

  return *this;
}

auto TlsClientConnection_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto TlsClientConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TlsClientConnection((GTlsClientConnection*)object);
}


/* The implementation: */

TlsClientConnection::TlsClientConnection()
: Interface(tlsclientconnection_class_.init())
{}

TlsClientConnection::TlsClientConnection(GTlsClientConnection* castitem)
: Interface((GObject*)castitem)
{}

TlsClientConnection::TlsClientConnection(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

TlsClientConnection::TlsClientConnection(TlsClientConnection&& src) noexcept
: Interface(std::move(src))
{}

auto TlsClientConnection::operator=(TlsClientConnection&& src) noexcept -> TlsClientConnection&
{
  Interface::operator=(std::move(src));
  return *this;
}

TlsClientConnection::~TlsClientConnection() noexcept = default;

// static
auto TlsClientConnection::add_interface (
  const GType gtype_implementer) -> void
{
  tlsclientconnection_class_.init().add_interface(gtype_implementer);
}

TlsClientConnection::CppClassType TlsClientConnection::tlsclientconnection_class_; // initialize static member

auto TlsClientConnection::get_type() -> GType
{
  return tlsclientconnection_class_.init().get_type();
}


auto TlsClientConnection::get_base_type() -> GType
{
  return g_tls_client_connection_get_type();
}


auto TlsClientConnection::create(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<const SocketConnectable>& server_identity) -> Glib::RefPtr<TlsClientConnectionImpl>
{
  GError* gerror = nullptr;
  auto retvalue = std::dynamic_pointer_cast<TlsClientConnectionImpl>(Glib::wrap(G_TLS_CONNECTION(g_tls_client_connection_new(Glib::unwrap(base_io_stream), const_cast<GSocketConnectable*>(Glib::unwrap(server_identity)), & gerror))));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsClientConnection::create(const Glib::RefPtr<IOStream>& base_io_stream) -> Glib::RefPtr<TlsClientConnectionImpl>
{
  GError* gerror = nullptr;
  auto retvalue = std::dynamic_pointer_cast<TlsClientConnectionImpl>(Glib::wrap(G_TLS_CONNECTION(g_tls_client_connection_new(Glib::unwrap(base_io_stream), nullptr, & gerror))));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto TlsClientConnection::set_server_identity (
  const Glib::RefPtr <SocketConnectable> &identity) -> void
{
  g_tls_client_connection_set_server_identity(gobj(), Glib::unwrap(identity));
}

auto TlsClientConnection::get_server_identity() -> Glib::RefPtr<SocketConnectable>
{
  auto retvalue = Glib::wrap(g_tls_client_connection_get_server_identity(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TlsClientConnection::get_server_identity() const -> Glib::RefPtr<const SocketConnectable>
{
  return const_cast<TlsClientConnection*>(this)->get_server_identity();
}

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto TlsClientConnection::set_validation_flags (TlsCertificateFlags flags) -> void
{
  g_tls_client_connection_set_validation_flags(gobj(), static_cast<GTlsCertificateFlags>(flags));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto TlsClientConnection::get_validation_flags() const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_tls_client_connection_get_validation_flags(const_cast<GTlsClientConnection*>(gobj())));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

auto TlsClientConnection::get_accepted_cas() -> std::vector< Glib::RefPtr<Glib::ByteArray> >
{
  return Glib::ListHandler< Glib::RefPtr<Glib::ByteArray> >::list_to_vector(g_tls_client_connection_get_accepted_cas(gobj()), Glib::OWNERSHIP_DEEP);
}

auto TlsClientConnection::get_accepted_cas() const -> std::vector< Glib::RefPtr<const Glib::ByteArray> >
{
  return Glib::ListHandler< Glib::RefPtr<const Glib::ByteArray> >::list_to_vector(g_tls_client_connection_get_accepted_cas(const_cast<GTlsClientConnection*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto TlsClientConnection::copy_session_state (
  const Glib::RefPtr <TlsClientConnection> &source) -> void
{
  g_tls_client_connection_copy_session_state(gobj(), Glib::unwrap(source));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SocketConnectable>>::value,
  "Type Glib::RefPtr<SocketConnectable> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsClientConnection::property_server_identity() -> Glib::PropertyProxy< Glib::RefPtr<SocketConnectable> >
{
  return {this, "server-identity"};
}

auto TlsClientConnection::property_server_identity() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketConnectable> >
{
  return {this, "server-identity"};
}

#ifndef GIOMM_DISABLE_DEPRECATED

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TlsCertificateFlags>::value,
  "Type TlsCertificateFlags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsClientConnection::property_validation_flags() -> Glib::PropertyProxy< TlsCertificateFlags >
{
  return {this, "validation-flags"};
}
#endif // GIOMM_DISABLE_DEPRECATED


#ifndef GIOMM_DISABLE_DEPRECATED

auto TlsClientConnection::property_validation_flags() const -> Glib::PropertyProxy_ReadOnly< TlsCertificateFlags >
{
  return {this, "validation-flags"};
}
#endif // GIOMM_DISABLE_DEPRECATED


} // namespace Gio


