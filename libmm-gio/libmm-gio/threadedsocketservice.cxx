

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/threadedsocketservice.hxx>
#include <libmm-gio/threadedsocketservice_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{
}

namespace
{

  auto
  ThreadedSocketService_signal_run_callback (GThreadedSocketService* self,
                                             GSocketConnection* p0,
                                             GObject* p1,
                                             void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<SocketConnection>&,
                                      const Glib::RefPtr<Glib::Object>&)>;

    const auto obj = dynamic_cast<ThreadedSocketService*> (
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
  ThreadedSocketService_signal_run_notify_callback (
      GThreadedSocketService* self,
      GSocketConnection* p0,
      GObject* p1,
      void* data) -> gboolean
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::RefPtr<SocketConnection>&,
                                      const Glib::RefPtr<Glib::Object>&)>;

    const auto obj = dynamic_cast<ThreadedSocketService*> (
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

  const Glib::SignalProxyInfo ThreadedSocketService_signal_run_info = {
      "run",
      (GCallback) &ThreadedSocketService_signal_run_callback,
      (GCallback) &ThreadedSocketService_signal_run_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GThreadedSocketService* object, const bool take_copy) -> RefPtr<Gio::ThreadedSocketService>
  {
    return Glib::make_refptr_for_instance<Gio::ThreadedSocketService> (
        dynamic_cast<Gio::ThreadedSocketService*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  ThreadedSocketService_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ThreadedSocketService_Class::class_init_function;

      register_derived_type (g_threaded_socket_service_get_type ());
    }

    return *this;
  }

  auto
  ThreadedSocketService_Class::class_init_function (void* g_class,
                                                    void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->run = &run_callback;
  }

  auto
  ThreadedSocketService_Class::run_callback (GThreadedSocketService* self,
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
          return obj->on_run (Glib::wrap (p0, true), Glib::wrap (p1, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->run)
      return (*base->run) (self, p0, p1);

    using RType = gboolean;
    return RType ();
  }

  auto
  ThreadedSocketService_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ThreadedSocketService ((GThreadedSocketService*) object);
  }

  auto
  ThreadedSocketService::gobj_copy () -> GThreadedSocketService*
  {
    reference ();
    return gobj ();
  }

  ThreadedSocketService::ThreadedSocketService (
      const Glib::ConstructParams& construct_params)
    : SocketService (construct_params)
  {
  }

  ThreadedSocketService::ThreadedSocketService (
      GThreadedSocketService* castitem)
    : SocketService ((GSocketService*) castitem)
  {
  }

  ThreadedSocketService::ThreadedSocketService (
      ThreadedSocketService&& src) noexcept
    : SocketService (std::move (src))
  {
  }

  auto
  ThreadedSocketService::operator= (ThreadedSocketService&& src) noexcept -> ThreadedSocketService&
  {
    SocketService::operator= (std::move (src));
    return *this;
  }

  ThreadedSocketService::~ThreadedSocketService () noexcept = default;

  ThreadedSocketService::CppClassType
      ThreadedSocketService::threadedsocketservice_class_;

  auto
  ThreadedSocketService::get_type () -> GType
  {
    return threadedsocketservice_class_.init ().get_type ();
  }

  auto
  ThreadedSocketService::get_base_type () -> GType
  {
    return g_threaded_socket_service_get_type ();
  }

  ThreadedSocketService::ThreadedSocketService (const int max_threads)
    : ObjectBase (nullptr),
      SocketService (
          Glib::ConstructParams (threadedsocketservice_class_.init (),
                                 "max_threads",
                                 max_threads,
                                 nullptr))
  {
  }

  auto
  ThreadedSocketService::create (const int max_threads) -> Glib::RefPtr<ThreadedSocketService>
  {
    return Glib::make_refptr_for_instance<ThreadedSocketService> (
        new ThreadedSocketService (max_threads));
  }

  auto
  ThreadedSocketService::signal_run () -> Glib::SignalProxy<bool (const Glib::RefPtr<SocketConnection>&,
                                 const Glib::RefPtr<Object>&)>
  {
    return {this, &ThreadedSocketService_signal_run_info};
  }

  auto
  ThreadedSocketService::property_max_threads () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "max-threads"};
  }

  auto
  ThreadedSocketService::on_run (
      const Glib::RefPtr<SocketConnection>& connection,
      const Glib::RefPtr<Object>& source_object) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->run)
      return (*base->run) (gobj (),
                           Glib::unwrap (connection),
                           Glib::unwrap (source_object));

    using RType = bool;
    return RType ();
  }

} // namespace Gio
