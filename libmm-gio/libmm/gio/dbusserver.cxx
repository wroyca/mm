// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusserver.hxx>
#include <libmm/gio/dbusserver_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>

using Flags = gio::DBus::Server::Flags;

namespace gio::DBus
{

  Server::Server (const std::string& address,
                  const std::string& guid,
                  const glib::RefPtr<AuthObserver>& observer,
                  const glib::RefPtr<Cancellable>& cancellable,
                  const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (server_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init (cancellable);
  }

  Server::Server (const std::string& address,
                  const std::string& guid,
                  const glib::RefPtr<Cancellable>& cancellable,
                  const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (server_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init (cancellable);
  }

  Server::Server (const std::string& address,
                  const std::string& guid,
                  const glib::RefPtr<AuthObserver>& observer,
                  const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (server_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "authentication-observer",
                                     glib::unwrap (observer),
                                     nullptr))
  {
    init ();
  }

  Server::Server (const std::string& address,
                  const std::string& guid,
                  const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (server_class_.init (),
                                     "address",
                                     glib::c_str_or_nullptr (address),
                                     "flags",
                                     flags,
                                     "guid",
                                     glib::c_str_or_nullptr (guid),
                                     "authentication-observer",
                                     nullptr,
                                     nullptr))
  {
    init ();
  }

  auto
  Server::create_sync (const std::string& address,
                       const std::string& guid,
                       const glib::RefPtr<AuthObserver>& observer,
                       const glib::RefPtr<Cancellable>& cancellable,
                       const Flags flags) -> glib::RefPtr<Server>
  {
    return glib::make_refptr_for_instance<Server> (
        new Server (address, guid, observer, cancellable, flags));
  }

  auto
  Server::create_sync (const std::string& address,
                       const std::string& guid,
                       const glib::RefPtr<Cancellable>& cancellable,
                       const Flags flags) -> glib::RefPtr<Server>
  {
    return glib::make_refptr_for_instance<Server> (
        new Server (address, guid, cancellable, flags));
  }

  auto
  Server::create_sync (const std::string& address,
                       const std::string& guid,
                       const glib::RefPtr<AuthObserver>& observer,
                       const Flags flags) -> glib::RefPtr<Server>
  {
    return glib::make_refptr_for_instance<Server> (
        new Server (address, guid, observer, flags));
  }

  auto
  Server::create_sync (const std::string& address,
                       const std::string& guid,
                       const Flags flags) -> glib::RefPtr<Server>
  {
    return glib::make_refptr_for_instance<Server> (
        new Server (address, guid, flags));
  }

} // namespace gio::DBus

namespace
{

  auto
  Server_signal_new_connection_callback (GDBusServer* self,
                                         GDBusConnection* p0,
                                         void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<bool (const glib::RefPtr<Connection>&)>;

    const auto obj = dynamic_cast<Server*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  Server_signal_new_connection_notify_callback (GDBusServer* self,
                                                GDBusConnection* p0,
                                                void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<Connection>&)>;

    const auto obj = dynamic_cast<Server*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo Server_signal_new_connection_info = {
      "new-connection",
      (GCallback) &Server_signal_new_connection_callback,
      (GCallback) &Server_signal_new_connection_notify_callback};

} // namespace

auto
glib::Value<gio::DBus::Server::Flags>::value_type () -> GType
{
  return g_dbus_server_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GDBusServer* object, const bool take_copy) -> RefPtr<gio::DBus::Server>
  {
    return glib::make_refptr_for_instance<gio::DBus::Server> (
        dynamic_cast<gio::DBus::Server*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  Server_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Server_Class::class_init_function;

      register_derived_type (g_dbus_server_get_type ());

      Initable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Server_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Server_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Server ((GDBusServer*) object);
  }

  auto
  Server::gobj_copy () -> GDBusServer*
  {
    reference ();
    return gobj ();
  }

  Server::Server (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Server::Server (GDBusServer* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Server::Server (Server&& src) noexcept
    : Object (std::move (src)),
      Initable (std::move (src))
  {
  }

  auto
  Server::operator= (Server&& src) noexcept -> Server&
  {
    Object::operator= (std::move (src));
    Initable::operator= (std::move (src));
    return *this;
  }

  Server::~Server () noexcept = default;

  Server::CppClassType Server::server_class_;

  auto
  Server::get_type () -> GType
  {
    return server_class_.init ().get_type ();
  }

  auto
  Server::get_base_type () -> GType
  {
    return g_dbus_server_get_type ();
  }

  auto
  Server::start () -> void
  {
    g_dbus_server_start (gobj ());
  }

  auto
  Server::stop () -> void
  {
    g_dbus_server_stop (gobj ());
  }

  auto
  Server::is_active () const -> bool
  {
    return g_dbus_server_is_active (const_cast<GDBusServer*> (gobj ()));
  }

  auto
  Server::get_guid () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_dbus_server_get_guid (const_cast<GDBusServer*> (gobj ())));
  }

  auto
  Server::get_flags () const -> Flags
  {
    return static_cast<Flags> (
        g_dbus_server_get_flags (const_cast<GDBusServer*> (gobj ())));
  }

  auto
  Server::get_client_address () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_dbus_server_get_client_address (const_cast<GDBusServer*> (gobj ())));
  }

  auto
  Server::signal_new_connection () -> glib::SignalProxy<bool (const glib::RefPtr<Connection>&)>
  {
    return {this, &Server_signal_new_connection_info};
  }

  auto
  Server::property_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "active"};
  }

  auto
  Server::property_address () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "address"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<AuthObserver>>::value,
      "Type glib::RefPtr<AuthObserver> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Server::property_authentication_observer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<AuthObserver>>
  {
    return {this, "authentication-observer"};
  }

  auto
  Server::property_client_address () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "client-address"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Server::property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>
  {
    return {this, "flags"};
  }

  auto
  Server::property_guid () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "guid"};
  }

} // namespace gio::DBus
