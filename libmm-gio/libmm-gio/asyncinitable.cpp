


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/asyncinitable.hpp>
#include <libmm-gio/asyncinitable_p.hpp>


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
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/cancellable.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto AsyncInitable::init_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_async_initable_init_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto AsyncInitable::init_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_async_initable_init_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto AsyncInitable_Class::init_async_vfunc_callback (
  GAsyncInitable *self, const int io_priority,
  GCancellable *cancellable, const GAsyncReadyCallback callback, const gpointer user_data) -> void
{
  const auto obj_base =
    Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if (obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if (obj) // This can be nullptr during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Get the slot.
        const SlotAsyncReady * the_slot = static_cast<SlotAsyncReady *>(user_data);

        // Call the virtual member method, which derived classes might override.
        obj->init_async_vfunc(*the_slot, Glib::wrap(cancellable, true), io_priority);
        return;
      }
      catch (...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent( // Get the parent interface of the interface (The original
                                  // underlying C interface).
      g_type_interface_peek(
        G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
      ));

  // Call the original underlying C function:
  if (base && base->init_async)
    (*base->init_async)(self, io_priority, cancellable, callback, user_data);
}
auto AsyncInitable::init_async_vfunc (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent( // Get the parent interface of the interface (The original
                                  // underlying C interface).
      g_type_interface_peek(
        G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
      ));

  if (base && base->init_async)
  {
    (*base->init_async)(gobj(), io_priority, Glib::unwrap(cancellable),
      &SignalProxy_async_callback, const_cast<SlotAsyncReady*>(&slot));
  }
}
auto
AsyncInitable_Class::init_finish_vfunc_callback(
  GAsyncInitable* self, GAsyncResult* res, GError** error) -> gboolean
{
  const auto obj_base =
    Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if (obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if (obj) // This can be nullptr during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->init_finish_vfunc(Glib::wrap(res, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent( // Get the parent interface of the interface (The original
                                  // underlying C interface).
      g_type_interface_peek(
        G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
      ));

  // Call the original underlying C function:
  if (base && base->init_finish)
    return (*base->init_finish)(self, res, error);

  using RType = gboolean;
  return RType();
}
auto AsyncInitable::init_finish_vfunc(const Glib::RefPtr<AsyncResult>& res) -> bool
{
  const auto base = static_cast<BaseClassType*>(
    g_type_interface_peek_parent( // Get the parent interface of the interface (The original
                                  // underlying C interface).
      g_type_interface_peek(
        G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
      ));

  if (base && base->init_finish)
  {
    GError* gerror = nullptr;

    bool const result = (*base->init_finish)(gobj(), Glib::unwrap(res), &gerror);

    if (gerror)
      Glib::Error::throw_exception(gerror);

    return result;
  }

  using RType = bool;
  return RType();
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GAsyncInitable* object, const bool take_copy) -> RefPtr<Gio::AsyncInitable>
{
  return Glib::make_refptr_for_instance<Gio::AsyncInitable>( Glib::wrap_auto_interface<Gio::AsyncInitable> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto AsyncInitable_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &AsyncInitable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_async_initable_get_type();
  }

  return *this;
}

auto AsyncInitable_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->init_async = &init_async_vfunc_callback;
  klass->init_finish = &init_finish_vfunc_callback;

}


auto AsyncInitable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AsyncInitable((GAsyncInitable*)object);
}


/* The implementation: */

AsyncInitable::AsyncInitable()
: Interface(asyncinitable_class_.init())
{}

AsyncInitable::AsyncInitable(GAsyncInitable* castitem)
: Interface((GObject*)castitem)
{}

AsyncInitable::AsyncInitable(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

AsyncInitable::AsyncInitable(AsyncInitable&& src) noexcept
: Interface(std::move(src))
{}

auto AsyncInitable::operator=(AsyncInitable&& src) noexcept -> AsyncInitable&
{
  Interface::operator=(std::move(src));
  return *this;
}

AsyncInitable::~AsyncInitable() noexcept = default;

// static
auto AsyncInitable::add_interface (
  const GType gtype_implementer) -> void
{
  asyncinitable_class_.init().add_interface(gtype_implementer);
}

AsyncInitable::CppClassType AsyncInitable::asyncinitable_class_; // initialize static member

auto AsyncInitable::get_type() -> GType
{
  return asyncinitable_class_.init().get_type();
}


auto AsyncInitable::get_base_type() -> GType
{
  return g_async_initable_get_type();
}


auto AsyncInitable::init_finish(const Glib::RefPtr<AsyncResult>& res) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_async_initable_init_finish(gobj(), Glib::unwrap(res), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto AsyncInitable::create_finish(const Glib::RefPtr<AsyncResult>& res) -> Glib::RefPtr<Glib::Object>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_async_initable_new_finish(gobj(), Glib::unwrap(res), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


