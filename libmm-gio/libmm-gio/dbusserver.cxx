


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusserver.hxx>
#include <libmm-gio/dbusserver_p.hxx>


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
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusauthobserver.hxx>

using Flags = Gio::DBus::Server::Flags;

namespace Gio::DBus
{

Server::Server(const std::string& address, const std::string& guid,
  const Glib::RefPtr<AuthObserver>& observer, const Glib::RefPtr<Cancellable>& cancellable, const Flags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(server_class_.init(), "address",Glib::c_str_or_nullptr(address),"flags",flags,"guid",Glib::c_str_or_nullptr(guid),"authentication-observer",Glib::unwrap(observer), nullptr))
{
  init(cancellable);
}

Server::Server(const std::string& address, const std::string& guid,
  const Glib::RefPtr<Cancellable>& cancellable, const Flags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(server_class_.init(), "address",Glib::c_str_or_nullptr(address),"flags",flags,"guid",Glib::c_str_or_nullptr(guid),"authentication-observer",nullptr, nullptr))
{
  init(cancellable);
}

Server::Server(const std::string& address, const std::string& guid,
  const Glib::RefPtr<AuthObserver>& observer, const Flags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(server_class_.init(), "address",Glib::c_str_or_nullptr(address),"flags",flags,"guid",Glib::c_str_or_nullptr(guid),"authentication-observer",Glib::unwrap(observer), nullptr))
{
  init();
}

Server::Server(const std::string& address, const std::string& guid, const Flags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(server_class_.init(), "address",Glib::c_str_or_nullptr(address),"flags",flags,"guid",Glib::c_str_or_nullptr(guid),"authentication-observer",nullptr, nullptr))
{
  init();
}

auto
Server::create_sync(const std::string& address, const std::string& guid,
  const Glib::RefPtr<AuthObserver>& observer, const Glib::RefPtr<Cancellable>& cancellable, const Flags flags) -> Glib::RefPtr<Server>
{
  return Glib::make_refptr_for_instance<Server>(new Server(address, guid, observer, cancellable, flags));
}

auto
Server::create_sync(const std::string& address, const std::string& guid,
  const Glib::RefPtr<Cancellable>& cancellable, const Flags flags) -> Glib::RefPtr<Server>
{
  return Glib::make_refptr_for_instance<Server>(new Server(address, guid, cancellable, flags));
}

auto
Server::create_sync(const std::string& address, const std::string& guid,
  const Glib::RefPtr<AuthObserver>& observer, const Flags flags) -> Glib::RefPtr<Server>
{
  return Glib::make_refptr_for_instance<Server>(new Server(address, guid, observer, flags));
}

auto
Server::create_sync(const std::string& address, const std::string& guid, const Flags flags) -> Glib::RefPtr<Server>
{
  return Glib::make_refptr_for_instance<Server>(new Server(address, guid, flags));
}

} // namespace Gio

namespace
{


auto Server_signal_new_connection_callback(GDBusServer* self, GDBusConnection* p0,void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<Connection>&)>;

  const auto obj = dynamic_cast<Server*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto Server_signal_new_connection_notify_callback(GDBusServer* self, GDBusConnection* p0, void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Connection>&)>;

  const auto obj = dynamic_cast<Server*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo Server_signal_new_connection_info =
{
  "new-connection",
  (GCallback) &Server_signal_new_connection_callback,
  (GCallback) &Server_signal_new_connection_notify_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::DBus::Server::Flags>::value_type() -> GType
{
  return g_dbus_server_flags_get_type();
}


namespace Glib
{

auto wrap(GDBusServer* object, const bool take_copy) -> RefPtr<Gio::DBus::Server>
{
  return Glib::make_refptr_for_instance<Gio::DBus::Server>( dynamic_cast<Gio::DBus::Server*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto Server_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Server_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_server_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Initable::add_interface(get_type());

  }

  return *this;
}


auto Server_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Server_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Server((GDBusServer*)object);
}


/* The implementation: */

auto Server::gobj_copy() -> GDBusServer*
{
  reference();
  return gobj();
}

Server::Server(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Server::Server(GDBusServer* castitem)
: Object((GObject*)castitem)
{}


Server::Server(Server&& src) noexcept
: Object(std::move(src))
  , Initable(std::move(src))
{}

auto Server::operator=(Server&& src) noexcept -> Server&
{
  Object::operator=(std::move(src));
  Initable::operator=(std::move(src));
  return *this;
}


Server::~Server() noexcept = default;

Server::CppClassType Server::server_class_; // initialize static member

auto Server::get_type() -> GType
{
  return server_class_.init().get_type();
}


auto Server::get_base_type() -> GType
{
  return g_dbus_server_get_type();
}


auto Server::start () -> void
{
  g_dbus_server_start(gobj());
}

auto Server::stop () -> void
{
  g_dbus_server_stop(gobj());
}

auto Server::is_active() const -> bool
{
  return g_dbus_server_is_active(const_cast<GDBusServer*>(gobj()));
}

auto Server::get_guid() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_dbus_server_get_guid(const_cast<GDBusServer*>(gobj())));
}

auto Server::get_flags() const -> Flags
{
  return static_cast<Flags>(g_dbus_server_get_flags(const_cast<GDBusServer*>(gobj())));
}

auto Server::get_client_address() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_dbus_server_get_client_address(const_cast<GDBusServer*>(gobj())));
}


auto Server::signal_new_connection() -> Glib::SignalProxy<bool(const Glib::RefPtr<Connection>&)>
{
  return {this, &Server_signal_new_connection_info};
}


auto Server::property_active() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "active"};
}

auto Server::property_address() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "address"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<AuthObserver>>::value,
  "Type Glib::RefPtr<AuthObserver> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Server::property_authentication_observer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<AuthObserver> >
{
  return {this, "authentication-observer"};
}

auto Server::property_client_address() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "client-address"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
  "Type Flags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Server::property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >
{
  return {this, "flags"};
}

auto Server::property_guid() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "guid"};
}


} // namespace Gio


