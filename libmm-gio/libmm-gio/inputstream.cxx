


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/inputstream_p.hxx>


/* Copyright (C) 2007 The giomm Development Team
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
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{

auto InputStream::read_async (
  void *buffer, const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto InputStream::read_async (
  void *buffer, const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto InputStream::read_all_async (
  void *buffer, const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_all_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto InputStream::read_all_async (
  void *buffer, const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_all_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto InputStream::read_bytes_async (
  const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_bytes_async(
    gobj(), count, io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto InputStream::read_bytes_async (
  const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_read_bytes_async(
    gobj(), count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto InputStream::skip_async (
  const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_skip_async(
    gobj(), count, io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto InputStream::skip_async (
  const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_skip_async(
    gobj(), count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto InputStream::close_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto InputStream::close_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_input_stream_close_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GInputStream* object, const bool take_copy) -> RefPtr<Gio::InputStream>
{
  return Glib::make_refptr_for_instance<Gio::InputStream>( dynamic_cast<Gio::InputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto InputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &InputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto InputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->read_fn = &read_fn_vfunc_callback;
  klass->skip = &skip_vfunc_callback;
  klass->close_fn = &close_fn_vfunc_callback;

}

auto InputStream_Class::read_fn_vfunc_callback(GInputStream* self, void* buffer, const gsize count, GCancellable* cancellable, GError** error) -> gssize
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
        return obj->read_vfunc(buffer, count, Glib::wrap(cancellable, true)
);
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        return -1;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->read_fn)
    return (*base->read_fn)(self, buffer, count, cancellable, error);

  using RType = gssize;
  return RType();
}
auto InputStream_Class::skip_vfunc_callback(GInputStream* self, const gsize count, GCancellable* cancellable, GError** error) -> gssize
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
        return obj->skip_vfunc(count, Glib::wrap(cancellable, true)
);
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        return -1;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->skip)
    return (*base->skip)(self, count, cancellable, error);

  using RType = gssize;
  return RType();
}
auto InputStream_Class::close_fn_vfunc_callback(GInputStream* self, GCancellable* cancellable, GError** error) -> gboolean
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
        return obj->close_vfunc(Glib::wrap(cancellable, true)
        );
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
        return RType();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->close_fn)
    return (*base->close_fn)(self, cancellable, error);

  using RType = gboolean;
  return RType();
}


auto InputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new InputStream((GInputStream*)object);
}


/* The implementation: */

auto InputStream::gobj_copy() -> GInputStream*
{
  reference();
  return gobj();
}

InputStream::InputStream(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

InputStream::InputStream(GInputStream* castitem)
: Object((GObject*)castitem)
{}


InputStream::InputStream(InputStream&& src) noexcept
: Object(std::move(src))
{}

auto InputStream::operator=(InputStream&& src) noexcept -> InputStream&
{
  Object::operator=(std::move(src));
  return *this;
}


InputStream::~InputStream() noexcept = default;

InputStream::CppClassType InputStream::inputstream_class_; // initialize static member

auto InputStream::get_type() -> GType
{
  return inputstream_class_.init().get_type();
}


auto InputStream::get_base_type() -> GType
{
  return g_input_stream_get_type();
}


InputStream::InputStream()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(inputstream_class_.init()))
{


}

auto InputStream::read(void* buffer, const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read(gobj(), buffer, count, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read(void* buffer, const gsize count) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read(gobj(), buffer, count, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_all(void* buffer, const gsize count, gsize& bytes_read, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read_all(gobj(), buffer, count, &bytes_read, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_all(void* buffer, const gsize count, gsize& bytes_read) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read_all(gobj(), buffer, count, &bytes_read, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_bytes(
  const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<Glib::Bytes>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_input_stream_read_bytes(gobj(), count, Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_bytes_finish(const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<Glib::Bytes>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_input_stream_read_bytes_finish(gobj(), Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::skip(
  const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_skip(gobj(), count, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::skip(
  const gsize count) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_skip(gobj(), count, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::close(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_close(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::close() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_close(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::read_all_finish(const Glib::RefPtr<AsyncResult>& result, gsize& bytes_read) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_read_all_finish(gobj(), Glib::unwrap(result), &bytes_read, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::skip_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_skip_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::close_finish(const Glib::RefPtr<AsyncResult>& result) -> gboolean
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_close_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::is_closed() const -> bool
{
  return g_input_stream_is_closed(const_cast<GInputStream*>(gobj()));
}

auto InputStream::has_pending() const -> bool
{
  return g_input_stream_has_pending(const_cast<GInputStream*>(gobj()));
}

auto InputStream::set_pending() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_input_stream_set_pending(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto InputStream::clear_pending () -> void
{
  g_input_stream_clear_pending(gobj());
}


auto InputStream::read_vfunc(void* buffer, const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->read_fn)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->read_fn)(gobj(),buffer,count,Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}
auto InputStream::skip_vfunc(
  const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->skip)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->skip)(gobj(),count,Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}
auto InputStream::close_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->close_fn)
  {
    GError* gerror = nullptr;
    const bool retval((*base->close_fn)(gobj(),Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gio

