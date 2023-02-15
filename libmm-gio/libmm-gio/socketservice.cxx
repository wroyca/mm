// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketservice.hxx>
#include <libmm-gio/socketservice_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{
}

namespace
{

  auto
  SocketService_signal_incoming_callback (GSocketService* self,
                                          GSocketConnection* p0,
                                          GObject* p1,
                                          void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<SocketConnection>&,
                                      const Glib::RefPtr<Glib::Object>&)>;

    const auto obj = dynamic_cast<SocketService*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                                   Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  SocketService_signal_incoming_notify_callback (GSocketService* self,
                                                 GSocketConnection* p0,
                                                 GObject* p1,
                                                 void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::RefPtr<SocketConnection>&,
                                      const Glib::RefPtr<Glib::Object>&)>;

    const auto obj = dynamic_cast<SocketService*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo SocketService_signal_incoming_info = {
      "incoming",
      (GCallback) &SocketService_signal_incoming_callback,
      (GCallback) &SocketService_signal_incoming_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GSocketService* object, const bool take_copy) -> RefPtr<Gio::SocketService>
  {
    return Glib::make_refptr_for_instance<Gio::SocketService> (
        dynamic_cast<Gio::SocketService*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketService_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketService_Class::class_init_function;

      register_derived_type (g_socket_service_get_type ());
    }

    return *this;
  }

  auto
  SocketService_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->incoming = &incoming_callback;
  }

  auto
  SocketService_Class::incoming_callback (GSocketService* self,
                                          GSocketConnection* p0,
                                          GObject* p1) -> gboolean
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->on_incoming (Glib::wrap (p0, true),
                                   Glib::wrap (p1, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->incoming)
      return (*base->incoming) (self, p0, p1);

    using RType = gboolean;
    return RType ();
  }

  auto
  SocketService_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketService ((GSocketService*) object);
  }

  auto
  SocketService::gobj_copy () -> GSocketService*
  {
    reference ();
    return gobj ();
  }

  SocketService::SocketService (const Glib::ConstructParams& construct_params)
    : SocketListener (construct_params)
  {
  }

  SocketService::SocketService (GSocketService* castitem)
    : SocketListener ((GSocketListener*) castitem)
  {
  }

  SocketService::SocketService (SocketService&& src) noexcept
    : SocketListener (std::move (src))
  {
  }

  auto
  SocketService::operator= (SocketService&& src) noexcept -> SocketService&
  {
    SocketListener::operator= (std::move (src));
    return *this;
  }

  SocketService::~SocketService () noexcept = default;

  SocketService::CppClassType SocketService::socketservice_class_;

  auto
  SocketService::get_type () -> GType
  {
    return socketservice_class_.init ().get_type ();
  }

  auto
  SocketService::get_base_type () -> GType
  {
    return g_socket_service_get_type ();
  }

  SocketService::SocketService ()
    : ObjectBase (nullptr),
      SocketListener (Glib::ConstructParams (socketservice_class_.init ()))
  {
  }

  auto
  SocketService::create () -> Glib::RefPtr<SocketService>
  {
    return Glib::make_refptr_for_instance<SocketService> (new SocketService ());
  }

  auto
  SocketService::start () -> void
  {
    g_socket_service_start (gobj ());
  }

  auto
  SocketService::stop () -> void
  {
    g_socket_service_stop (gobj ());
  }

  auto
  SocketService::is_active () -> bool
  {
    return g_socket_service_is_active (gobj ());
  }

  auto
  SocketService::signal_incoming () -> Glib::SignalProxy<bool (const Glib::RefPtr<SocketConnection>&,
                                 const Glib::RefPtr<Object>&)>
  {
    return {this, &SocketService_signal_incoming_info};
  }

  auto
  SocketService::property_active () -> Glib::PropertyProxy<bool>
  {
    return {this, "active"};
  }

  auto
  SocketService::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "active"};
  }

  auto
  SocketService::on_incoming (const Glib::RefPtr<SocketConnection>& connection,
                              const Glib::RefPtr<Object>& source_object) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->incoming)
      return (*base->incoming) (gobj (),
                                Glib::unwrap (connection),
                                Glib::unwrap (source_object));

    using RType = bool;
    return RType ();
  }

} // namespace Gio
