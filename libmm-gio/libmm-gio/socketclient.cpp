


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/socketclient.hpp>
#include <libmm-gio/socketclient_p.hpp>


/* Copyright (C) 2010 Jonathon Jongsma
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
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto SocketClient::connect_async (
  const Glib::RefPtr <SocketConnectable> &connectable,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_async(
    gobj(), connectable->gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_async (
  const Glib::RefPtr <SocketConnectable> &connectable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_async(
    gobj(), connectable->gobj(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_host_async (
  const Glib::ustring &host_and_port, const guint16 default_port,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_host_async(gobj(), host_and_port.c_str(), default_port,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_host_async (
  const Glib::ustring &host_and_port, const guint16 default_port, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_host_async(
    gobj(), host_and_port.c_str(), default_port, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_service_async (
  const Glib::ustring &domain, const Glib::ustring &service,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_service_async(gobj(), domain.c_str(), service.c_str(),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_service_async (
  const Glib::ustring &domain, const Glib::ustring &service, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_service_async(
    gobj(), domain.c_str(), service.c_str(), nullptr, &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_uri_async (
  const Glib::ustring &uri, const guint16 default_port,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_uri_async(gobj(), uri.c_str(), default_port, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto SocketClient::connect_to_uri_async (
  const Glib::ustring &uri, const guint16 default_port, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_socket_client_connect_to_uri_async(
    gobj(), uri.c_str(), default_port, nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{


auto SocketClient_signal_event_callback (
  GSocketClient *self, GSocketClientEvent p0, GSocketConnectable *p1, GIOStream *p2,
  void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(SocketClientEvent, const Glib::RefPtr<SocketConnectable>&, const Glib::RefPtr<IOStream>&)>;

  const auto obj = dynamic_cast<SocketClient*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<SocketClientEvent>(p0)
, Glib::wrap(p1, true)
, Glib::wrap(p2, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SocketClient_signal_event_info =
{
  "event",
  (GCallback) &SocketClient_signal_event_callback,
  (GCallback) &SocketClient_signal_event_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::SocketClientEvent>::value_type() -> GType
{
  return g_socket_client_event_get_type();
}


namespace Glib
{

auto wrap(GSocketClient* object, const bool take_copy) -> RefPtr<Gio::SocketClient>
{
  return Glib::make_refptr_for_instance<Gio::SocketClient>( dynamic_cast<Gio::SocketClient*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SocketClient_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketClient_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_client_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SocketClient_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->event = &event_callback;
}


auto SocketClient_Class::event_callback (
  GSocketClient *self, GSocketClientEvent p0, GSocketConnectable *p1, GIOStream *p2) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_event(static_cast<SocketClientEvent>(p0)
, Glib::wrap(p1, true)
, Glib::wrap(p2, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->event)
    (*base->event)(self, p0, p1, p2);
}


auto SocketClient_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketClient((GSocketClient*)object);
}


/* The implementation: */

auto SocketClient::gobj_copy() -> GSocketClient*
{
  reference();
  return gobj();
}

SocketClient::SocketClient(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SocketClient::SocketClient(GSocketClient* castitem)
: Object((GObject*)castitem)
{}


SocketClient::SocketClient(SocketClient&& src) noexcept
: Object(std::move(src))
{}

auto SocketClient::operator=(SocketClient&& src) noexcept -> SocketClient&
{
  Object::operator=(std::move(src));
  return *this;
}


SocketClient::~SocketClient() noexcept = default;

SocketClient::CppClassType SocketClient::socketclient_class_; // initialize static member

auto SocketClient::get_type() -> GType
{
  return socketclient_class_.init().get_type();
}


auto SocketClient::get_base_type() -> GType
{
  return g_socket_client_get_type();
}


SocketClient::SocketClient()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(socketclient_class_.init()))
{


}

auto SocketClient::create() -> Glib::RefPtr<SocketClient>
{
  return Glib::make_refptr_for_instance<SocketClient>( new SocketClient() );
}

auto SocketClient::get_family() const -> SocketFamily
{
  return static_cast<SocketFamily>(g_socket_client_get_family(const_cast<GSocketClient*>(gobj())));
}

auto SocketClient::set_family (SocketFamily family) -> void
{
  g_socket_client_set_family(gobj(), static_cast<GSocketFamily>(family));
}

auto SocketClient::get_socket_type() const -> Socket::Type
{
  return static_cast<Socket::Type>(g_socket_client_get_socket_type(const_cast<GSocketClient*>(gobj())));
}

auto SocketClient::set_socket_type (Socket::Type type) -> void
{
  g_socket_client_set_socket_type(gobj(), static_cast<GSocketType>(type));
}

auto SocketClient::get_protocol() const -> Socket::Protocol
{
  return static_cast<Socket::Protocol>(g_socket_client_get_protocol(const_cast<GSocketClient*>(gobj())));
}

auto SocketClient::set_protocol (Socket::Protocol protocol) -> void
{
  g_socket_client_set_protocol(gobj(), static_cast<GSocketProtocol>(protocol));
}

auto SocketClient::get_local_address() -> Glib::RefPtr<SocketAddress>
{
  return Glib::wrap(g_socket_client_get_local_address(gobj()));
}

auto SocketClient::get_local_address() const -> Glib::RefPtr<const SocketAddress>
{
  return const_cast<SocketClient*>(this)->get_local_address();
}

auto SocketClient::set_local_address (const Glib::RefPtr <SocketAddress> &address) -> void
{
  g_socket_client_set_local_address(gobj(), Glib::unwrap(address));
}

auto SocketClient::connect(const Glib::RefPtr<SocketConnectable>& connectable, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect(gobj(), Glib::unwrap(connectable), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect(const Glib::RefPtr<SocketConnectable>& connectable) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect(gobj(), Glib::unwrap(connectable), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_host(const Glib::ustring& host_and_port, const guint16 default_port, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_host(gobj(), host_and_port.c_str(), default_port, Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_host(const Glib::ustring& host_and_port, const guint16 default_port) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_host(gobj(), host_and_port.c_str(), default_port, nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_service(const Glib::ustring& domain, const Glib::ustring& service, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_service(gobj(), domain.c_str(), service.c_str(), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_service(const Glib::ustring& domain, const Glib::ustring& service) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_service(gobj(), domain.c_str(), service.c_str(), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_uri(const Glib::ustring& uri, const guint16 default_port, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_uri(gobj(), uri.c_str(), default_port, Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_uri(const Glib::ustring& uri, const guint16 default_port) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_uri(gobj(), uri.c_str(), default_port, nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_host_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_host_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_service_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_service_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::connect_to_uri_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<SocketConnection>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_socket_client_connect_to_uri_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto SocketClient::get_enable_proxy() const -> bool
{
  return g_socket_client_get_enable_proxy(const_cast<GSocketClient*>(gobj()));
}

auto SocketClient::set_enable_proxy (
  const bool enable) -> void
{
  g_socket_client_set_enable_proxy(gobj(), enable);
}

auto SocketClient::get_tls() const -> bool
{
  return g_socket_client_get_tls(const_cast<GSocketClient*>(gobj()));
}

auto SocketClient::set_tls (
  const bool tls) -> void
{
  g_socket_client_set_tls(gobj(), tls);
}

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto SocketClient::get_tls_validation_flags() const -> TlsCertificateFlags
{
  return static_cast<TlsCertificateFlags>(g_socket_client_get_tls_validation_flags(const_cast<GSocketClient*>(gobj())));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

#ifndef GIOMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto SocketClient::set_tls_validation_flags (TlsCertificateFlags flags) -> void
{
  g_socket_client_set_tls_validation_flags(gobj(), static_cast<GTlsCertificateFlags>(flags));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED

auto SocketClient::get_proxy_resolver() -> Glib::RefPtr<ProxyResolver>
{
  auto retvalue = Glib::wrap(g_socket_client_get_proxy_resolver(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SocketClient::get_proxy_resolver() const -> Glib::RefPtr<const ProxyResolver>
{
  return const_cast<SocketClient*>(this)->get_proxy_resolver();
}

auto SocketClient::set_proxy_resolver (const Glib::RefPtr <ProxyResolver> &proxy_resolver) -> void
{
  g_socket_client_set_proxy_resolver(gobj(), Glib::unwrap(proxy_resolver));
}

auto SocketClient::get_timeout() const -> guint
{
  return g_socket_client_get_timeout(const_cast<GSocketClient*>(gobj()));
}

auto SocketClient::set_timeout (
  const guint timeout) -> void
{
  g_socket_client_set_timeout(gobj(), timeout);
}

auto SocketClient::add_application_proxy (const Glib::ustring &protocol) -> void
{
  g_socket_client_add_application_proxy(gobj(), protocol.c_str());
}


auto SocketClient::signal_event() -> Glib::SignalProxy<void(SocketClientEvent, const Glib::RefPtr<SocketConnectable>&, const Glib::RefPtr<IOStream>&)>
{
  return {this, &SocketClient_signal_event_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SocketFamily>::value,
  "Type SocketFamily cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_family() -> Glib::PropertyProxy< SocketFamily >
{
  return {this, "family"};
}

auto SocketClient::property_family() const -> Glib::PropertyProxy_ReadOnly< SocketFamily >
{
  return {this, "family"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SocketAddress>>::value,
  "Type Glib::RefPtr<SocketAddress> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_local_address() -> Glib::PropertyProxy< Glib::RefPtr<SocketAddress> >
{
  return {this, "local-address"};
}

auto SocketClient::property_local_address() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketAddress> >
{
  return {this, "local-address"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Socket::Protocol>::value,
  "Type Socket::Protocol cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_protocol() -> Glib::PropertyProxy< Socket::Protocol >
{
  return {this, "protocol"};
}

auto SocketClient::property_protocol() const -> Glib::PropertyProxy_ReadOnly< Socket::Protocol >
{
  return {this, "protocol"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Socket::Type>::value,
  "Type Socket::Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_type() -> Glib::PropertyProxy< Socket::Type >
{
  return {this, "type"};
}

auto SocketClient::property_type() const -> Glib::PropertyProxy_ReadOnly< Socket::Type >
{
  return {this, "type"};
}

auto SocketClient::property_timeout() -> Glib::PropertyProxy< guint >
{
  return {this, "timeout"};
}

auto SocketClient::property_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "timeout"};
}

auto SocketClient::property_enable_proxy() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-proxy"};
}

auto SocketClient::property_enable_proxy() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-proxy"};
}

auto SocketClient::property_tls() -> Glib::PropertyProxy< bool >
{
  return {this, "tls"};
}

auto SocketClient::property_tls() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "tls"};
}

#ifndef GIOMM_DISABLE_DEPRECATED

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TlsCertificateFlags>::value,
  "Type TlsCertificateFlags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_tls_validation_flags() -> Glib::PropertyProxy< TlsCertificateFlags >
{
  return {this, "tls-validation-flags"};
}
#endif // GIOMM_DISABLE_DEPRECATED


#ifndef GIOMM_DISABLE_DEPRECATED

auto SocketClient::property_tls_validation_flags() const -> Glib::PropertyProxy_ReadOnly< TlsCertificateFlags >
{
  return {this, "tls-validation-flags"};
}
#endif // GIOMM_DISABLE_DEPRECATED


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ProxyResolver>>::value,
  "Type Glib::RefPtr<ProxyResolver> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SocketClient::property_proxy_resolver() -> Glib::PropertyProxy< Glib::RefPtr<ProxyResolver> >
{
  return {this, "proxy-resolver"};
}

auto SocketClient::property_proxy_resolver() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ProxyResolver> >
{
  return {this, "proxy-resolver"};
}


auto SocketClient::on_event (
  SocketClientEvent event, const Glib::RefPtr <SocketConnectable> &connectable,
  const Glib::RefPtr <IOStream> &connection) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->event)
    (*base->event)(gobj(),static_cast<GSocketClientEvent>(event),Glib::unwrap(connectable),Glib::unwrap(connection));
}


} // namespace Gio


