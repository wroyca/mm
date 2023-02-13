


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/bufferedinputstream.hpp>
#include <libmm-gio/bufferedinputstream_p.hpp>


/* Copyright (C) 2008 The gtkmm Development Team
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
#include <libmm-gio/slot_async.hpp>

namespace Gio
{
auto
BufferedInputStream::create_sized(const Glib::RefPtr<InputStream>& base_stream, const gsize buffer_size) -> Glib::RefPtr<BufferedInputStream>
{
  return Glib::make_refptr_for_instance<BufferedInputStream>(new BufferedInputStream(base_stream, buffer_size));
}

auto BufferedInputStream::fill_async (
  const SlotAsyncReady &slot, const gssize count,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_buffered_input_stream_fill_async(
    gobj(), count, io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto BufferedInputStream::fill_async (
  const SlotAsyncReady &slot, const gssize count, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_buffered_input_stream_fill_async(
    gobj(), count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GBufferedInputStream* object, const bool take_copy) -> RefPtr<Gio::BufferedInputStream>
{
  return Glib::make_refptr_for_instance<Gio::BufferedInputStream>( dynamic_cast<Gio::BufferedInputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto BufferedInputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &BufferedInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_buffered_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Seekable::add_interface(get_type());

  }

  return *this;
}


auto BufferedInputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->fill = &fill_vfunc_callback;

}

auto BufferedInputStream_Class::fill_vfunc_callback(GBufferedInputStream* self, const gssize count, GCancellable* cancellable, GError** error) -> gssize
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
        return obj->fill_vfunc(count, Glib::wrap(cancellable, true)
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
  if(base && base->fill)
    return (*base->fill)(self, count, cancellable, error);

  using RType = gssize;
  return RType();
}


auto BufferedInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new BufferedInputStream((GBufferedInputStream*)object);
}


/* The implementation: */

auto BufferedInputStream::gobj_copy() -> GBufferedInputStream*
{
  reference();
  return gobj();
}

BufferedInputStream::BufferedInputStream(const Glib::ConstructParams& construct_params)
: FilterInputStream(construct_params)
{

}

BufferedInputStream::BufferedInputStream(GBufferedInputStream* castitem)
: FilterInputStream((GFilterInputStream*)castitem)
{}


BufferedInputStream::BufferedInputStream(BufferedInputStream&& src) noexcept
: FilterInputStream(std::move(src))
  , Seekable(std::move(src))
{}

auto BufferedInputStream::operator=(BufferedInputStream&& src) noexcept -> BufferedInputStream&
{
  FilterInputStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


BufferedInputStream::~BufferedInputStream() noexcept = default;

BufferedInputStream::CppClassType BufferedInputStream::bufferedinputstream_class_; // initialize static member

auto BufferedInputStream::get_type() -> GType
{
  return bufferedinputstream_class_.init().get_type();
}


auto BufferedInputStream::get_base_type() -> GType
{
  return g_buffered_input_stream_get_type();
}


BufferedInputStream::BufferedInputStream(const Glib::RefPtr<InputStream>& base_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
FilterInputStream(Glib::ConstructParams(bufferedinputstream_class_.init(), "base_stream", Glib::unwrap(base_stream), nullptr))
{


}

BufferedInputStream::BufferedInputStream(const Glib::RefPtr<InputStream>& base_stream, const gsize buffer_size)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
FilterInputStream(Glib::ConstructParams(bufferedinputstream_class_.init(), "base_stream", Glib::unwrap(base_stream), "buffer_size", buffer_size, nullptr))
{


}

auto BufferedInputStream::create(const Glib::RefPtr<InputStream>& base_stream) -> Glib::RefPtr<BufferedInputStream>
{
  return Glib::make_refptr_for_instance<BufferedInputStream>( new BufferedInputStream(base_stream) );
}

auto BufferedInputStream::get_buffer_size() const -> gsize
{
  return g_buffered_input_stream_get_buffer_size(const_cast<GBufferedInputStream*>(gobj()));
}

auto BufferedInputStream::set_buffer_size (
  const gsize size) -> void
{
  g_buffered_input_stream_set_buffer_size(gobj(), size);
}

auto BufferedInputStream::get_available() const -> gsize
{
  return g_buffered_input_stream_get_available(const_cast<GBufferedInputStream*>(gobj()));
}

auto BufferedInputStream::peek(void* buffer, const gsize offset, const gsize count) const -> gsize
{
  return g_buffered_input_stream_peek(const_cast<GBufferedInputStream*>(gobj()), buffer, offset, count);
}

auto BufferedInputStream::peek_buffer(gsize& count) const -> const void*
{
  return g_buffered_input_stream_peek_buffer(const_cast<GBufferedInputStream*>(gobj()), &count);
}

auto BufferedInputStream::fill(
  const gssize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_buffered_input_stream_fill(gobj(), count, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto BufferedInputStream::fill(
  const gssize count) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_buffered_input_stream_fill(gobj(), count, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto BufferedInputStream::fill_finish(const Glib::RefPtr<AsyncResult>& result) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_buffered_input_stream_fill_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto BufferedInputStream::read_byte(const Glib::RefPtr<Cancellable>& cancellable) -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_buffered_input_stream_read_byte(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto BufferedInputStream::read_byte() -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_buffered_input_stream_read_byte(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


auto BufferedInputStream::property_buffer_size() -> Glib::PropertyProxy< guint >
{
  return {this, "buffer-size"};
}

auto BufferedInputStream::property_buffer_size() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "buffer-size"};
}


auto BufferedInputStream::fill_vfunc(
  const gssize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->fill)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->fill)(gobj(),count,Glib::unwrap(cancellable),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}


} // namespace Gio


