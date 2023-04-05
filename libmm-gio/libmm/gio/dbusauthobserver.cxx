// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusauthobserver_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/credentials.hxx>
#include <libmm/glib/exceptionhandler.hxx>

using Credentials = gio::Credentials;
using IOStream = gio::IOStream;

namespace gio
{

}

namespace
{

  auto
  AuthObserver_signal_authorize_authenticated_peer_callback (
      GDBusAuthObserver* self,
      GIOStream* p0,
      GCredentials* p1,
      void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<bool (const glib::RefPtr<const IOStream>&,
                                      const glib::RefPtr<const Credentials>&)>;

    const auto obj = dynamic_cast<AuthObserver*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                                   glib::wrap (p1, true));
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
  AuthObserver_signal_authorize_authenticated_peer_notify_callback (
      GDBusAuthObserver* self,
      GIOStream* p0,
      GCredentials* p1,
      void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<const IOStream>&,
                                      const glib::RefPtr<const Credentials>&)>;

    const auto obj = dynamic_cast<AuthObserver*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                            glib::wrap (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo AuthObserver_signal_authorize_authenticated_peer_info =
      {"authorize-authenticated-peer",
       (GCallback) &AuthObserver_signal_authorize_authenticated_peer_callback,
       (GCallback) &AuthObserver_signal_authorize_authenticated_peer_notify_callback};

  auto
  AuthObserver_signal_allow_mechanism_callback (GDBusAuthObserver* self,
                                                const gchar* p0,
                                                void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<bool (const std::string&)>;

    const auto obj = dynamic_cast<AuthObserver*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_stdstring (p0));
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
  AuthObserver_signal_allow_mechanism_notify_callback (GDBusAuthObserver* self,
                                                       const gchar* p0,
                                                       void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const std::string&)>;

    const auto obj = dynamic_cast<AuthObserver*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_stdstring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo AuthObserver_signal_allow_mechanism_info = {
      "allow_mechanism",
      (GCallback) &AuthObserver_signal_allow_mechanism_callback,
      (GCallback) &AuthObserver_signal_allow_mechanism_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GDBusAuthObserver* object, const bool take_copy) -> RefPtr<gio::DBus::AuthObserver>
  {
    return glib::make_refptr_for_instance<gio::DBus::AuthObserver> (
        dynamic_cast<gio::DBus::AuthObserver*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  AuthObserver_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AuthObserver_Class::class_init_function;

      register_derived_type (g_dbus_auth_observer_get_type ());
    }

    return *this;
  }

  auto
  AuthObserver_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AuthObserver_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AuthObserver ((GDBusAuthObserver*) object);
  }

  auto
  AuthObserver::gobj_copy () -> GDBusAuthObserver*
  {
    reference ();
    return gobj ();
  }

  AuthObserver::AuthObserver (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  AuthObserver::AuthObserver (GDBusAuthObserver* castitem)
    : Object ((GObject*) castitem)
  {
  }

  AuthObserver::AuthObserver (AuthObserver&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  AuthObserver::operator= (AuthObserver&& src) noexcept -> AuthObserver&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  AuthObserver::~AuthObserver () noexcept = default;

  AuthObserver::CppClassType AuthObserver::authobserver_class_;

  auto
  AuthObserver::get_type () -> GType
  {
    return authobserver_class_.init ().get_type ();
  }

  auto
  AuthObserver::get_base_type () -> GType
  {
    return g_dbus_auth_observer_get_type ();
  }

  AuthObserver::AuthObserver ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (authobserver_class_.init ()))
  {
  }

  auto
  AuthObserver::create () -> glib::RefPtr<AuthObserver>
  {
    return glib::make_refptr_for_instance<AuthObserver> (new AuthObserver ());
  }

  auto
  AuthObserver::authorize_authenticated_peer (
      const glib::RefPtr<const IOStream>& stream,
      const glib::RefPtr<const Credentials>& credentials) -> bool
  {
    return g_dbus_auth_observer_authorize_authenticated_peer (
        gobj (),
        const_cast<GIOStream*> (glib::unwrap (stream)),
        const_cast<GCredentials*> (glib::unwrap<Credentials> (credentials)));
  }

  auto
  AuthObserver::allow_mechanism (const std::string& mechanism) -> bool
  {
    return g_dbus_auth_observer_allow_mechanism (gobj (), mechanism.c_str ());
  }

  auto
  AuthObserver::signal_authorize_authenticated_peer () -> glib::SignalProxy<bool (const glib::RefPtr<const IOStream>&,
                                 const glib::RefPtr<const Credentials>&)>
  {
    return {this, &AuthObserver_signal_authorize_authenticated_peer_info};
  }

  auto
  AuthObserver::signal_allow_mechanism () -> glib::SignalProxy<bool (const std::string&)>
  {
    return {this, &AuthObserver_signal_allow_mechanism_info};
  }

} // namespace gio::DBus
