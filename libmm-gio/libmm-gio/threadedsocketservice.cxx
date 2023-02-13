


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/threadedsocketservice.hxx>
#include <libmm-gio/threadedsocketservice_p.hxx>


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
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{
} // namespace Gio

namespace
{


auto ThreadedSocketService_signal_run_callback(GThreadedSocketService* self, GSocketConnection* p0,GObject* p1,void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<SocketConnection>&, const Glib::RefPtr<Glib::Object>&)>;

  const auto obj = dynamic_cast<ThreadedSocketService*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

auto ThreadedSocketService_signal_run_notify_callback(GThreadedSocketService* self, GSocketConnection* p0,GObject* p1, void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<SocketConnection>&, const Glib::RefPtr<Glib::Object>&)>;

  const auto obj = dynamic_cast<ThreadedSocketService*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo ThreadedSocketService_signal_run_info =
{
  "run",
  (GCallback) &ThreadedSocketService_signal_run_callback,
  (GCallback) &ThreadedSocketService_signal_run_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GThreadedSocketService* object, const bool take_copy) -> RefPtr<Gio::ThreadedSocketService>
{
  return Glib::make_refptr_for_instance<Gio::ThreadedSocketService>( dynamic_cast<Gio::ThreadedSocketService*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ThreadedSocketService_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ThreadedSocketService_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_threaded_socket_service_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ThreadedSocketService_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->run = &run_callback;
}


auto ThreadedSocketService_Class::run_callback(GThreadedSocketService* self, GSocketConnection* p0, GObject* p1) -> gboolean
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
        return obj->on_run(Glib::wrap(p0, true)
                           , Glib::wrap(p1, true)
        );
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
  if(base && base->run)
    return (*base->run)(self, p0, p1);

  using RType = gboolean;
  return RType();
}


auto ThreadedSocketService_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ThreadedSocketService((GThreadedSocketService*)object);
}


/* The implementation: */

auto ThreadedSocketService::gobj_copy() -> GThreadedSocketService*
{
  reference();
  return gobj();
}

ThreadedSocketService::ThreadedSocketService(const Glib::ConstructParams& construct_params)
: SocketService(construct_params)
{

}

ThreadedSocketService::ThreadedSocketService(GThreadedSocketService* castitem)
: SocketService((GSocketService*)castitem)
{}


ThreadedSocketService::ThreadedSocketService(ThreadedSocketService&& src) noexcept
: SocketService(std::move(src))
{}

auto ThreadedSocketService::operator=(ThreadedSocketService&& src) noexcept -> ThreadedSocketService&
{
  SocketService::operator=(std::move(src));
  return *this;
}


ThreadedSocketService::~ThreadedSocketService() noexcept = default;

ThreadedSocketService::CppClassType ThreadedSocketService::threadedsocketservice_class_; // initialize static member

auto ThreadedSocketService::get_type() -> GType
{
  return threadedsocketservice_class_.init().get_type();
}


auto ThreadedSocketService::get_base_type() -> GType
{
  return g_threaded_socket_service_get_type();
}


ThreadedSocketService::ThreadedSocketService(const int max_threads)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
SocketService(Glib::ConstructParams(threadedsocketservice_class_.init(), "max_threads", max_threads, nullptr))
{


}

auto ThreadedSocketService::create(
  const int max_threads) -> Glib::RefPtr<ThreadedSocketService>
{
  return Glib::make_refptr_for_instance<ThreadedSocketService>( new ThreadedSocketService(max_threads) );
}


auto ThreadedSocketService::signal_run() -> Glib::SignalProxy<bool(const Glib::RefPtr<SocketConnection>&, const Glib::RefPtr<Object>&)>
{
  return {this, &ThreadedSocketService_signal_run_info};
}


auto ThreadedSocketService::property_max_threads() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-threads"};
}


auto ThreadedSocketService::on_run(const Glib::RefPtr<SocketConnection>& connection, const Glib::RefPtr<Object>& source_object) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->run)
    return (*base->run)(gobj(),Glib::unwrap(connection),Glib::unwrap(source_object));

  using RType = bool;
  return RType();
}


} // namespace Gio


