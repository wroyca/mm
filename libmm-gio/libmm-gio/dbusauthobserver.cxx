


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/dbusauthobserver.hpp>
#include <libmm-gio/dbusauthobserver_p.hpp>


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
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/credentials.hpp>

// To help the generated code:
using Credentials = Gio::Credentials;
using IOStream = Gio::IOStream;

namespace Gio
{

} // namespace Gio

namespace
{


auto AuthObserver_signal_authorize_authenticated_peer_callback(GDBusAuthObserver* self, GIOStream* p0,GCredentials* p1,void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<const IOStream>&, const Glib::RefPtr<const Credentials>&)>;

  const auto obj = dynamic_cast<AuthObserver*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
                                               , Glib::wrap(p1, true)
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

auto AuthObserver_signal_authorize_authenticated_peer_notify_callback(GDBusAuthObserver* self, GIOStream* p0,GCredentials* p1, void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<const IOStream>&, const Glib::RefPtr<const Credentials>&)>;

  const auto obj = dynamic_cast<AuthObserver*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
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

const Glib::SignalProxyInfo AuthObserver_signal_authorize_authenticated_peer_info =
{
  "authorize-authenticated-peer",
  (GCallback) &AuthObserver_signal_authorize_authenticated_peer_callback,
  (GCallback) &AuthObserver_signal_authorize_authenticated_peer_notify_callback
};


auto AuthObserver_signal_allow_mechanism_callback(GDBusAuthObserver* self, const gchar* p0,void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<bool(const std::string&)>;

  const auto obj = dynamic_cast<AuthObserver*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_stdstring(p0)
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

auto AuthObserver_signal_allow_mechanism_notify_callback(GDBusAuthObserver* self, const gchar* p0, void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const std::string&)>;

  const auto obj = dynamic_cast<AuthObserver*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_stdstring(p0)
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

const Glib::SignalProxyInfo AuthObserver_signal_allow_mechanism_info =
{
  "allow_mechanism",
  (GCallback) &AuthObserver_signal_allow_mechanism_callback,
  (GCallback) &AuthObserver_signal_allow_mechanism_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GDBusAuthObserver* object, const bool take_copy) -> RefPtr<Gio::DBus::AuthObserver>
{
  return Glib::make_refptr_for_instance<Gio::DBus::AuthObserver>( dynamic_cast<Gio::DBus::AuthObserver*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto AuthObserver_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AuthObserver_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_auth_observer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto AuthObserver_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AuthObserver_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AuthObserver((GDBusAuthObserver*)object);
}


/* The implementation: */

auto AuthObserver::gobj_copy() -> GDBusAuthObserver*
{
  reference();
  return gobj();
}

AuthObserver::AuthObserver(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

AuthObserver::AuthObserver(GDBusAuthObserver* castitem)
: Object((GObject*)castitem)
{}


AuthObserver::AuthObserver(AuthObserver&& src) noexcept
: Object(std::move(src))
{}

auto AuthObserver::operator=(AuthObserver&& src) noexcept -> AuthObserver&
{
  Object::operator=(std::move(src));
  return *this;
}


AuthObserver::~AuthObserver() noexcept = default;

AuthObserver::CppClassType AuthObserver::authobserver_class_; // initialize static member

auto AuthObserver::get_type() -> GType
{
  return authobserver_class_.init().get_type();
}


auto AuthObserver::get_base_type() -> GType
{
  return g_dbus_auth_observer_get_type();
}


AuthObserver::AuthObserver()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(authobserver_class_.init()))
{


}

auto AuthObserver::create() -> Glib::RefPtr<AuthObserver>
{
  return Glib::make_refptr_for_instance<AuthObserver>( new AuthObserver() );
}

auto AuthObserver::authorize_authenticated_peer(const Glib::RefPtr<const IOStream>& stream, const Glib::RefPtr<const Credentials>& credentials) -> bool
{
  return g_dbus_auth_observer_authorize_authenticated_peer(gobj(), const_cast<GIOStream*>(Glib::unwrap(stream)), const_cast<GCredentials*>(Glib::unwrap<Credentials>(credentials)));
}

auto AuthObserver::allow_mechanism(const std::string& mechanism) -> bool
{
  return g_dbus_auth_observer_allow_mechanism(gobj(), mechanism.c_str());
}


auto AuthObserver::signal_authorize_authenticated_peer() -> Glib::SignalProxy<bool(const Glib::RefPtr<const IOStream>&, const Glib::RefPtr<const Credentials>&)>
{
  return {this, &AuthObserver_signal_authorize_authenticated_peer_info};
}


auto AuthObserver::signal_allow_mechanism() -> Glib::SignalProxy<bool(const std::string&)>
{
  return {this, &AuthObserver_signal_allow_mechanism_info};
}


} // namespace Gio


