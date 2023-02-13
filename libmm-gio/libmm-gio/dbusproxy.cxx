


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusproxy.hxx>
#include <libmm-gio/dbusproxy_p.hxx>


/* Copyright (C) 2010 The giomm Development Team
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
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/vectorutils.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/slot_async.hxx>

namespace Gio::DBus
{

// Help the generate code:
using MapChangedProperties = Proxy::MapChangedProperties;

Proxy::Proxy(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-connection",Glib::unwrap(connection),"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init_async(slot, cancellable);
}

Proxy::Proxy(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name, const SlotAsyncReady& slot,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-connection",Glib::unwrap(connection),"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init_async(slot);
}

Proxy::Proxy(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-connection",Glib::unwrap(connection),"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init(cancellable);
}

Proxy::Proxy(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-connection",Glib::unwrap(connection),"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init();
}

Proxy::Proxy(
  const BusType bus_type, const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::ustring& interface_name, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-bus-type",bus_type,"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init_async(slot, cancellable);
}

Proxy::Proxy(
  const BusType bus_type, const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::ustring& interface_name, const SlotAsyncReady& slot,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-bus-type",bus_type,"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init_async(slot);
}

Proxy::Proxy(
  const BusType bus_type, const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::ustring& interface_name, const Glib::RefPtr<Cancellable>& cancellable,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-bus-type",bus_type,"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init(cancellable);
}

Proxy::Proxy(
  const BusType bus_type, const Glib::ustring& name, const Glib::ustring& object_path,
  const Glib::ustring& interface_name, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(proxy_class_.init(), "g-bus-type",bus_type,"g-flags",flags,"g-interface-info",Glib::unwrap(info),"g-name", c_str_or_nullptr(name),"g-object-path", c_str_or_nullptr(object_path),"g-interface-name", c_str_or_nullptr(interface_name), nullptr))
{
  init();
}

auto Proxy::create (
  const Glib::RefPtr <Connection> &connection, const Glib::ustring &name,
  const Glib::ustring &object_path, const Glib::ustring &interface_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const Glib::RefPtr <InterfaceInfo> &info, const ProxyFlags flags) -> void
{
  Proxy(connection, name, object_path, interface_name, slot, cancellable, info, flags);
}

auto Proxy::create (
  const Glib::RefPtr <Connection> &connection, const Glib::ustring &name,
  const Glib::ustring &object_path, const Glib::ustring &interface_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <InterfaceInfo> &info, const ProxyFlags flags) -> void
{
  Proxy(connection, name, object_path, interface_name, slot, info, flags);
}

auto
Proxy::create_sync(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags) -> Glib::RefPtr<Proxy>
{
  return Glib::make_refptr_for_instance<Proxy>(
    new Proxy(connection, name, object_path, interface_name, cancellable, info, flags));
}

auto
Proxy::create_sync(const Glib::RefPtr<Connection>& connection, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags) -> Glib::RefPtr<Proxy>
{
  return Glib::make_refptr_for_instance<Proxy>(new Proxy(connection, name, object_path, interface_name, info, flags));
}

auto Proxy::create_for_bus (
  const BusType bus_type, const Glib::ustring &name, const Glib::ustring &object_path,
  const Glib::ustring &interface_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const Glib::RefPtr <InterfaceInfo> &info, const ProxyFlags flags) -> void
{
  Proxy(bus_type, name, object_path, interface_name, slot, cancellable, info, flags);
}

auto Proxy::create_for_bus (
  const BusType bus_type, const Glib::ustring &name, const Glib::ustring &object_path,
  const Glib::ustring &interface_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <InterfaceInfo> &info, const ProxyFlags flags) -> void
{
  Proxy(bus_type, name, object_path, interface_name, slot, info, flags);
}

auto
Proxy::create_for_bus_sync(
  const BusType bus_type, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags) -> Glib::RefPtr<Proxy>
{
  return Glib::make_refptr_for_instance<Proxy>(
    new Proxy(bus_type, name, object_path, interface_name, cancellable, info, flags));
}

auto
Proxy::create_for_bus_sync(
  const BusType bus_type, const Glib::ustring& name,
  const Glib::ustring& object_path, const Glib::ustring& interface_name,
  const Glib::RefPtr<InterfaceInfo>& info, const ProxyFlags flags) -> Glib::RefPtr<Proxy>
{
  return Glib::make_refptr_for_instance<Proxy>(new Proxy(bus_type, name, object_path, interface_name, info, flags));
}

auto Proxy::get_cached_property (
  Glib::VariantBase &property, const Glib::ustring &property_name) const -> void
{
  const GVariant* const g_variant =
    g_dbus_proxy_get_cached_property(const_cast<GDBusProxy*>(gobj()), property_name.c_str());

  property.init(g_variant, false /* no extra reference needed */);
}

} // namespace Gio

namespace
{


auto Proxy_signal_properties_changed_callback (
  GDBusProxy *self, GVariant *p0, const gchar *const*p1, void *data) -> void
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const MapChangedProperties&, const std::vector<Glib::ustring>&)>;

  const auto obj = dynamic_cast<Proxy*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::Variant<MapChangedProperties>(p0, true).get()
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p1, Glib::OWNERSHIP_NONE)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Proxy_signal_properties_changed_info =
{
  "g-properties-changed",
  (GCallback) &Proxy_signal_properties_changed_callback,
  (GCallback) &Proxy_signal_properties_changed_callback
};


auto Proxy_signal_signal_callback (
  GDBusProxy *self, const gchar *p0, const gchar *p1, GVariant *p2, void *data) -> void
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>;

  const auto obj = dynamic_cast<Proxy*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
, Glib::VariantContainerBase(p2, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Proxy_signal_signal_info =
{
  "g-signal",
  (GCallback) &Proxy_signal_signal_callback,
  (GCallback) &Proxy_signal_signal_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::DBus::ProxyFlags>::value_type() -> GType
{
  return g_dbus_proxy_flags_get_type();
}


namespace Glib
{

auto wrap(GDBusProxy* object, const bool take_copy) -> RefPtr<Gio::DBus::Proxy>
{
  return Glib::make_refptr_for_instance<Gio::DBus::Proxy>( dynamic_cast<Gio::DBus::Proxy*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto Proxy_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Proxy_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_proxy_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Initable::add_interface(get_type());
  AsyncInitable::add_interface(get_type());
    Interface::add_interface(get_type());

  }

  return *this;
}


auto Proxy_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->g_properties_changed = &g_properties_changed_callback;
  klass->g_signal = &g_signal_callback;
}


auto Proxy_Class::g_properties_changed_callback (
  GDBusProxy *self, GVariant *p0, const gchar *const*p1) -> void
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
        obj->on_properties_changed(Glib::Variant<MapChangedProperties>(p0, true).get()
, Glib::ArrayHandler<Glib::ustring>::array_to_vector(p1, Glib::OWNERSHIP_NONE)
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
  if(base && base->g_properties_changed)
    (*base->g_properties_changed)(self, p0, p1);
}
auto Proxy_Class::g_signal_callback (
  GDBusProxy *self, const gchar *p0, const gchar *p1, GVariant *p2) -> void
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
        obj->on_signal(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
, Glib::VariantContainerBase(p2, true)
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
  if(base && base->g_signal)
    (*base->g_signal)(self, p0, p1, p2);
}


auto Proxy_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Proxy((GDBusProxy*)object);
}


/* The implementation: */

auto Proxy::gobj_copy() -> GDBusProxy*
{
  reference();
  return gobj();
}

Proxy::Proxy(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Proxy::Proxy(GDBusProxy* castitem)
: Object((GObject*)castitem)
{}


Proxy::Proxy(Proxy&& src) noexcept
: Object(std::move(src))
  , Initable(std::move(src))
  , AsyncInitable(std::move(src))
  , DBus::Interface(std::move(src))
{}

auto Proxy::operator=(Proxy&& src) noexcept -> Proxy&
{
  Object::operator=(std::move(src));
  Initable::operator=(std::move(src));
  AsyncInitable::operator=(std::move(src));
  DBus::Interface::operator=(std::move(src));
  return *this;
}


Proxy::~Proxy() noexcept = default;

Proxy::CppClassType Proxy::proxy_class_; // initialize static member

auto Proxy::get_type() -> GType
{
  return proxy_class_.init().get_type();
}


auto Proxy::get_base_type() -> GType
{
  return g_dbus_proxy_get_type();
}


auto Proxy::create_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Proxy>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_dbus_proxy_new_finish(Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Proxy::create_for_bus_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Proxy>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_dbus_proxy_new_for_bus_finish(Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Proxy::get_flags() const -> ProxyFlags
{
  return static_cast<ProxyFlags>(g_dbus_proxy_get_flags(const_cast<GDBusProxy*>(gobj())));
}

auto Proxy::get_connection() -> Glib::RefPtr<Connection>
{
  auto retvalue = Glib::wrap(g_dbus_proxy_get_connection(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Proxy::get_connection() const -> Glib::RefPtr<const Connection>
{
  return const_cast<Proxy*>(this)->get_connection();
}

auto Proxy::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_proxy_get_name(const_cast<GDBusProxy*>(gobj())));
}

auto Proxy::get_name_owner() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_dbus_proxy_get_name_owner(const_cast<GDBusProxy*>(gobj())));
}

auto Proxy::get_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_proxy_get_object_path(const_cast<GDBusProxy*>(gobj())));
}

auto Proxy::get_interface_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_proxy_get_interface_name(const_cast<GDBusProxy*>(gobj())));
}

auto Proxy::get_default_timeout() const -> int
{
  return g_dbus_proxy_get_default_timeout(const_cast<GDBusProxy*>(gobj()));
}

auto Proxy::set_default_timeout (
  const int timeout_msec) -> void
{
  g_dbus_proxy_set_default_timeout(gobj(), timeout_msec);
}

auto Proxy::set_cached_property (
  const Glib::ustring &property_name, const Glib::VariantBase &value) -> void
{
  g_dbus_proxy_set_cached_property(gobj(), property_name.c_str(), const_cast<GVariant*>(value.gobj()));
}

auto Proxy::get_cached_property_names() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_dbus_proxy_get_cached_property_names(const_cast<GDBusProxy*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto Proxy::set_interface_info (const Glib::RefPtr <InterfaceInfo> &info) -> void
{
  g_dbus_proxy_set_interface_info(gobj(), Glib::unwrap(info));
}

auto Proxy::get_interface_info() -> Glib::RefPtr<InterfaceInfo>
{
  auto retvalue = Glib::wrap(g_dbus_proxy_get_interface_info(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Proxy::get_interface_info() const -> Glib::RefPtr<const InterfaceInfo>
{
  return const_cast<Proxy*>(this)->get_interface_info();
}

auto Proxy::call (
  const Glib::ustring &method_name, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const Glib::VariantContainerBase &parameters, const int timeout_msec, CallFlags flags) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_dbus_proxy_call(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto Proxy::call (
  const Glib::ustring &method_name, const SlotAsyncReady &slot,
  const Glib::VariantContainerBase &parameters, const int timeout_msec, CallFlags flags) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_dbus_proxy_call(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto Proxy::call (
  const Glib::ustring &method_name, const Glib::RefPtr <Cancellable> &cancellable,
  const Glib::VariantContainerBase &parameters, const int timeout_msec, CallFlags flags) -> void
{
  g_dbus_proxy_call(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(cancellable), nullptr, nullptr);
}

auto Proxy::call (
  const Glib::ustring &method_name, const Glib::VariantContainerBase &parameters, const int timeout_msec,
  CallFlags flags) -> void
{
  g_dbus_proxy_call(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, nullptr, nullptr, nullptr);
}

auto Proxy::call_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_finish(gobj(), Glib::unwrap(res), &gerror), false);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Proxy::call_sync(const Glib::ustring& method_name, const Glib::RefPtr<Cancellable>& cancellable, const Glib::VariantContainerBase& parameters, const int timeout_msec, CallFlags flags) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_sync(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(cancellable), &gerror), false);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Proxy::call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const int timeout_msec, CallFlags flags) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_sync(gobj(), method_name.c_str(), const_cast<GVariant*>(parameters.gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, nullptr, &gerror), false);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

#ifdef G_OS_UNIX
void Proxy::call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec, CallFlags flags)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_dbus_proxy_call_with_unix_fd_list(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &SignalProxy_async_callback, slot_copy);
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
void Proxy::call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const SlotAsyncReady& slot, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec, CallFlags flags)
{
  // Create a copy of the slot.
  auto slot_copy = new SlotAsyncReady(slot);

  g_dbus_proxy_call_with_unix_fd_list(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), nullptr, &SignalProxy_async_callback, slot_copy);
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
void Proxy::call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec, CallFlags flags)
{
  g_dbus_proxy_call_with_unix_fd_list(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), const_cast<GCancellable*>(Glib::unwrap(cancellable)), nullptr, nullptr);
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
void Proxy::call(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list, int timeout_msec, CallFlags flags)
{
  g_dbus_proxy_call_with_unix_fd_list(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), nullptr, nullptr, nullptr);
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Proxy::call_finish(const Glib::RefPtr<AsyncResult>& res, Glib::RefPtr<UnixFDList>& out_fd_list) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  GUnixFDList* g_out_fd_list = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_with_unix_fd_list_finish(gobj(), &g_out_fd_list, Glib::unwrap(res), &(gerror)), false);
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
out_fd_list = Glib::wrap(g_out_fd_list);
  return retvalue;
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Proxy::call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<Cancellable>& cancellable, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, int timeout_msec, CallFlags flags) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  GUnixFDList* g_out_fd_list = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_with_unix_fd_list_sync(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), &g_out_fd_list, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)), false);
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
out_fd_list = Glib::wrap(g_out_fd_list);
  return retvalue;
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Proxy::call_sync(const Glib::ustring& method_name, const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list, Glib::RefPtr<UnixFDList>& out_fd_list, int timeout_msec, CallFlags flags) -> Glib::VariantContainerBase
{
  GError* gerror = nullptr;
  GUnixFDList* g_out_fd_list = nullptr;
  auto retvalue = Glib::VariantContainerBase(g_dbus_proxy_call_with_unix_fd_list_sync(gobj(), method_name.c_str(), const_cast<GVariant*>((parameters).gobj()), static_cast<GDBusCallFlags>(flags), timeout_msec, Glib::unwrap(fd_list), &g_out_fd_list, nullptr, &(gerror)), false);
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
out_fd_list = Glib::wrap(g_out_fd_list);
  return retvalue;
}
#endif // G_OS_UNIX


auto Proxy::signal_properties_changed() -> Glib::SignalProxy<void(const MapChangedProperties&, const std::vector<Glib::ustring>&)>
{
  return {this, &Proxy_signal_properties_changed_info};
}


auto Proxy::signal_signal() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>
{
  return {this, &Proxy_signal_signal_info};
}

auto Proxy::signal_signal(const Glib::ustring& signal_name) -> Glib::SignalProxyDetailed<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>
{
  return Glib::SignalProxyDetailed<void(const Glib::ustring&, const Glib::ustring&, const Glib::VariantContainerBase&)>(this, &Proxy_signal_signal_info, signal_name);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Connection>>::value,
  "Type Glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Proxy::property_g_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >
{
  return {this, "g-connection"};
}

auto Proxy::property_g_default_timeout() -> Glib::PropertyProxy< int >
{
  return {this, "g-default-timeout"};
}

auto Proxy::property_g_default_timeout() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "g-default-timeout"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ProxyFlags>::value,
  "Type ProxyFlags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Proxy::property_g_flags() const -> Glib::PropertyProxy_ReadOnly< ProxyFlags >
{
  return {this, "g-flags"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<InterfaceInfo>>::value,
  "Type Glib::RefPtr<InterfaceInfo> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Proxy::property_g_interface_info() -> Glib::PropertyProxy< Glib::RefPtr<InterfaceInfo> >
{
  return {this, "g-interface-info"};
}

auto Proxy::property_g_interface_info() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<InterfaceInfo> >
{
  return {this, "g-interface-info"};
}

auto Proxy::property_g_interface_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "g-interface-name"};
}

auto Proxy::property_g_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "g-name"};
}

auto Proxy::property_g_name_owner() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "g-name-owner"};
}

auto Proxy::property_g_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "g-object-path"};
}


auto Proxy::on_properties_changed (
  const MapChangedProperties &changed_properties,
  const std::vector <Glib::ustring> &invalidated_properties) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->g_properties_changed)
    (*base->g_properties_changed)(gobj(),Glib::Variant<MapChangedProperties>::create(changed_properties).gobj(),Glib::ArrayHandler<Glib::ustring>::vector_to_array(invalidated_properties).data());
}
auto Proxy::on_signal (
  const Glib::ustring &sender_name, const Glib::ustring &signal_name,
  const Glib::VariantContainerBase &parameters) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->g_signal)
    (*base->g_signal)(gobj(),sender_name.c_str(),signal_name.c_str(),const_cast<GVariant*>(parameters.gobj()));
}


} // namespace Gio


