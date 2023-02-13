


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/tlsserverconnection.hpp>
#include <mm/gio/private/tlsserverconnection_p.hpp>


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
#include <mm/gio/tlsserverconnectionimpl.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GTlsServerConnection* object, const bool take_copy) -> RefPtr<Gio::TlsServerConnection>
{
  return Glib::make_refptr_for_instance<Gio::TlsServerConnection>( Glib::wrap_auto_interface<Gio::TlsServerConnection> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto TlsServerConnection_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TlsServerConnection_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_tls_server_connection_get_type();
  }

  return *this;
}

auto TlsServerConnection_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto TlsServerConnection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TlsServerConnection((GTlsServerConnection*)object);
}


/* The implementation: */

TlsServerConnection::TlsServerConnection()
: Interface(tlsserverconnection_class_.init())
{}

TlsServerConnection::TlsServerConnection(GTlsServerConnection* castitem)
: Interface((GObject*)castitem)
{}

TlsServerConnection::TlsServerConnection(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

TlsServerConnection::TlsServerConnection(TlsServerConnection&& src) noexcept
: Interface(std::move(src))
{}

auto TlsServerConnection::operator=(TlsServerConnection&& src) noexcept -> TlsServerConnection&
{
  Interface::operator=(std::move(src));
  return *this;
}

TlsServerConnection::~TlsServerConnection() noexcept = default;

// static
auto TlsServerConnection::add_interface (
  const GType gtype_implementer) -> void
{
  tlsserverconnection_class_.init().add_interface(gtype_implementer);
}

TlsServerConnection::CppClassType TlsServerConnection::tlsserverconnection_class_; // initialize static member

auto TlsServerConnection::get_type() -> GType
{
  return tlsserverconnection_class_.init().get_type();
}


auto TlsServerConnection::get_base_type() -> GType
{
  return g_tls_server_connection_get_type();
}


auto TlsServerConnection::create(const Glib::RefPtr<IOStream>& base_io_stream, const Glib::RefPtr<TlsCertificate>& certificate) -> Glib::RefPtr<TlsServerConnectionImpl>
{
  GError* gerror = nullptr;
  auto retvalue = std::dynamic_pointer_cast<TlsServerConnectionImpl>(Glib::wrap(G_TLS_CONNECTION(g_tls_server_connection_new(Glib::unwrap(base_io_stream), Glib::unwrap(certificate), & gerror))));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TlsAuthenticationMode>::value,
  "Type TlsAuthenticationMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TlsServerConnection::property_authentication_mode() -> Glib::PropertyProxy< TlsAuthenticationMode >
{
  return {this, "authentication-mode"};
}

auto TlsServerConnection::property_authentication_mode() const -> Glib::PropertyProxy_ReadOnly< TlsAuthenticationMode >
{
  return {this, "authentication-mode"};
}


} // namespace Gio


