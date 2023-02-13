


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/outputstream.hpp>
#include <libmm-gio/outputstream_p.hpp>


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
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/slot_async.hpp>

using SpliceFlags = Gio::OutputStream::SpliceFlags;

namespace Gio
{

auto OutputStream::write_async (
  const void *buffer, const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::write_async (
  const void *buffer, const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::write_all_async (
  const void *buffer, const gsize count, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_all_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::write_all_async (
  const void *buffer, const gsize count, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_all_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::splice_async (
  const Glib::RefPtr <InputStream> &source, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, SpliceFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_splice_async(gobj(), Glib::unwrap(source),
    static_cast<GOutputStreamSpliceFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::splice_async (
  const Glib::RefPtr <InputStream> &source, const SlotAsyncReady &slot,
  SpliceFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_splice_async(gobj(), Glib::unwrap(source),
    static_cast<GOutputStreamSpliceFlags>(flags), io_priority, nullptr, &SignalProxy_async_callback,
    slot_copy);
}

auto OutputStream::flush_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_flush_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::flush_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_flush_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::close_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::close_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_close_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
OutputStream::write(const std::string& buffer, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const gssize retvalue = g_output_stream_write(
    gobj(), buffer.data(), buffer.size(), Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
OutputStream::write(const std::string& buffer) -> gssize
{
  GError* gerror = nullptr;
  const gssize retvalue = g_output_stream_write(gobj(), buffer.data(), buffer.size(), nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
OutputStream::write_all(
  const std::string& buffer, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_output_stream_write_all(
    gobj(), buffer.data(), buffer.size(), &bytes_written, Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
OutputStream::write_all(const std::string& buffer, gsize& bytes_written) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = g_output_stream_write_all(
    gobj(), buffer.data(), buffer.size(), &bytes_written, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto OutputStream::write_bytes_async (
  const Glib::RefPtr <const Glib::Bytes> &bytes,
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_bytes_async(gobj(), const_cast<GBytes*>(unwrap(bytes)), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto OutputStream::write_bytes_async (
  const Glib::RefPtr <const Glib::Bytes> &bytes, const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_bytes_async(gobj(), const_cast<GBytes*>(unwrap(bytes)), io_priority,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto
OutputStream::splice(const Glib::RefPtr<InputStream>& source,
  const Glib::RefPtr<Cancellable>& cancellable, SpliceFlags flags) -> gssize
{
  GError* gerror = nullptr;
  const gssize retvalue = g_output_stream_splice(gobj(), Glib::unwrap(source),
                                                 (GOutputStreamSpliceFlags)flags, Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto
OutputStream::splice(const Glib::RefPtr<InputStream>& source, SpliceFlags flags) -> gssize
{
  GError* gerror = nullptr;
  const gssize retvalue = g_output_stream_splice(
    gobj(), Glib::unwrap(source), (GOutputStreamSpliceFlags)flags, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GOutputStream* object, const bool take_copy) -> RefPtr<Gio::OutputStream>
{
  return Glib::make_refptr_for_instance<Gio::OutputStream>( dynamic_cast<Gio::OutputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto OutputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &OutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto OutputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->write_fn = &write_fn_vfunc_callback;
  klass->splice = &splice_vfunc_callback;
  klass->flush = &flush_vfunc_callback;
  klass->close_fn = &close_fn_vfunc_callback;

}

auto OutputStream_Class::write_fn_vfunc_callback(GOutputStream* self, const void* buffer, const gsize count, GCancellable* cancellable, GError** error) -> gssize
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
        return obj->write_vfunc(buffer, count, Glib::wrap(cancellable, true)
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
  if(base && base->write_fn)
    return (*base->write_fn)(self, buffer, count, cancellable, error);

  using RType = gssize;
  return RType();
}
auto OutputStream_Class::splice_vfunc_callback(GOutputStream* self, GInputStream* source, GOutputStreamSpliceFlags flags, GCancellable* cancellable, GError** error) -> gssize
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
        return obj->splice_vfunc(Glib::wrap(source, true)
, Glib::wrap(cancellable, true)
, static_cast<SpliceFlags>(flags)
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
  if(base && base->splice)
    return (*base->splice)(self, source, flags, cancellable, error);

  using RType = gssize;
  return RType();
}
auto OutputStream_Class::flush_vfunc_callback(GOutputStream* self, GCancellable* cancellable, GError** error) -> gboolean
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
        return obj->flush_vfunc(Glib::wrap(cancellable, true)
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
  if(base && base->flush)
    return (*base->flush)(self, cancellable, error);

  using RType = gboolean;
  return RType();
}
auto OutputStream_Class::close_fn_vfunc_callback(GOutputStream* self, GCancellable* cancellable, GError** error) -> gboolean
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


auto OutputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new OutputStream((GOutputStream*)object);
}


/* The implementation: */

auto OutputStream::gobj_copy() -> GOutputStream*
{
  reference();
  return gobj();
}

OutputStream::OutputStream(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

OutputStream::OutputStream(GOutputStream* castitem)
: Object((GObject*)castitem)
{}


OutputStream::OutputStream(OutputStream&& src) noexcept
: Object(std::move(src))
{}

auto OutputStream::operator=(OutputStream&& src) noexcept -> OutputStream&
{
  Object::operator=(std::move(src));
  return *this;
}


OutputStream::~OutputStream() noexcept = default;

OutputStream::CppClassType OutputStream::outputstream_class_; // initialize static member

auto OutputStream::get_type() -> GType
{
  return outputstream_class_.init().get_type();
}


auto OutputStream::get_base_type() -> GType
{
  return g_output_stream_get_type();
}


OutputStream::OutputStream()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(outputstream_class_.init()))
{


}

auto OutputStream::write(const void* buffer, const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write(gobj(), buffer, count, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write(const void* buffer, const gsize count) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write(gobj(), buffer, count, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_all(const void* buffer, const gsize count, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_all(gobj(), buffer, count, &bytes_written, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_all(const void* buffer, const gsize count, gsize& bytes_written) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_all(gobj(), buffer, count, &bytes_written, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_bytes(gobj(), const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_bytes(gobj(), const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_bytes_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_bytes_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::flush(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_flush(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::flush() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_flush(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::close(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_close(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::close() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_close(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::write_all_finish(const Glib::RefPtr<AsyncResult>& result, gsize& bytes_written) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_write_all_finish(gobj(), Glib::unwrap(result), &bytes_written, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::splice_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_splice_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::flush_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_flush_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::close_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_close_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::is_closed() const -> bool
{
  return g_output_stream_is_closed(const_cast<GOutputStream*>(gobj()));
}

auto OutputStream::is_closing() const -> bool
{
  return g_output_stream_is_closing(const_cast<GOutputStream*>(gobj()));
}

auto OutputStream::has_pending() const -> bool
{
  return g_output_stream_has_pending(const_cast<GOutputStream*>(gobj()));
}

auto OutputStream::set_pending() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_output_stream_set_pending(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto OutputStream::clear_pending () -> void
{
  g_output_stream_clear_pending(gobj());
}


auto OutputStream::write_vfunc(const void* buffer, const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->write_fn)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->write_fn)(gobj(),buffer,count,Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}
auto OutputStream::splice_vfunc(const Glib::RefPtr<InputStream>& source, const Glib::RefPtr<Cancellable>& cancellable, SpliceFlags flags) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->splice)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->splice)(gobj(),Glib::unwrap(source),static_cast<GOutputStreamSpliceFlags>(flags),Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}
auto OutputStream::flush_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->flush)
  {
    GError* gerror = nullptr;
    const bool retval((*base->flush)(gobj(),Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}
auto OutputStream::close_vfunc(const Glib::RefPtr<Cancellable>& cancellable) -> bool
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


