


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/cancellable_p.hxx>


/* Copyright (C) 2007 The gtkmm Development Team
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

extern "C" {

auto delete_slot (
  const gpointer data) -> void
{
  const Cancellable::SlotCancelledCallback* callback =
    reinterpret_cast<Cancellable::SlotCancelledCallback*>(data);
  delete callback;
}

auto slot_cancelled_proxy (GCancellable * /*cancellable*/, const gpointer data) -> void
{
  const Cancellable::SlotCancelledCallback* callback =
    reinterpret_cast<Cancellable::SlotCancelledCallback*>(data);
  (*callback)();
}

} // extern "C"

auto
Cancellable::connect(const SlotCancelledCallback& slot) -> gulong
{
  const auto slot_copy = new SlotCancelledCallback(slot);
  return g_cancellable_connect(gobj(), G_CALLBACK(slot_cancelled_proxy), slot_copy, &delete_slot);
}

} // namespace Gio

namespace
{


const Glib::SignalProxyInfo Cancellable_signal_cancelled_info =
{
  "cancelled",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GCancellable* object, const bool take_copy) -> RefPtr<Gio::Cancellable>
{
  return Glib::make_refptr_for_instance<Gio::Cancellable>( dynamic_cast<Gio::Cancellable*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Cancellable_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Cancellable_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_cancellable_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Cancellable_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->cancelled = &cancelled_callback;
}


auto Cancellable_Class::cancelled_callback (GCancellable *self) -> void
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
        obj->on_cancelled();
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
  if(base && base->cancelled)
    (*base->cancelled)(self);
}


auto Cancellable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Cancellable((GCancellable*)object);
}


/* The implementation: */

auto Cancellable::gobj_copy() -> GCancellable*
{
  reference();
  return gobj();
}

Cancellable::Cancellable(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Cancellable::Cancellable(GCancellable* castitem)
: Object((GObject*)castitem)
{}


Cancellable::Cancellable(Cancellable&& src) noexcept
: Object(std::move(src))
{}

auto Cancellable::operator=(Cancellable&& src) noexcept -> Cancellable&
{
  Object::operator=(std::move(src));
  return *this;
}


Cancellable::~Cancellable() noexcept = default;

Cancellable::CppClassType Cancellable::cancellable_class_; // initialize static member

auto Cancellable::get_type() -> GType
{
  return cancellable_class_.init().get_type();
}


auto Cancellable::get_base_type() -> GType
{
  return g_cancellable_get_type();
}


Cancellable::Cancellable()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(cancellable_class_.init()))
{


}

auto Cancellable::create() -> Glib::RefPtr<Cancellable>
{
  return Glib::make_refptr_for_instance<Cancellable>( new Cancellable() );
}

auto Cancellable::is_cancelled() const -> bool
{
  return g_cancellable_is_cancelled(const_cast<GCancellable*>(gobj()));
}

auto Cancellable::get_fd() const -> int
{
  return g_cancellable_get_fd(const_cast<GCancellable*>(gobj()));
}

auto Cancellable::make_pollfd(GPollFD* pollfd) -> bool
{
  return g_cancellable_make_pollfd(gobj(), pollfd);
}

auto Cancellable::release_fd () -> void
{
  g_cancellable_release_fd(gobj());
}

auto Cancellable::cancel () -> void
{
  g_cancellable_cancel(gobj());
}

auto Cancellable::get_current() -> Glib::RefPtr<Cancellable>
{

  auto retvalue = Glib::wrap(g_cancellable_get_current());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto Cancellable::push_current () -> void
{
  g_cancellable_push_current(gobj());
}

auto Cancellable::pop_current () -> void
{
  g_cancellable_pop_current(gobj());
}

auto Cancellable::reset () -> void
{
  g_cancellable_reset(gobj());
}

auto Cancellable::disconnect (
  const gulong handler_id) -> void
{
  g_cancellable_disconnect(gobj(), handler_id);
}


auto Cancellable::signal_cancelled() -> Glib::SignalProxy<void()>
{
  return {this, &Cancellable_signal_cancelled_info};
}


auto Cancellable::on_cancelled () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->cancelled)
    (*base->cancelled)(gobj());
}


} // namespace Gio


