


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/iostream.hpp>
#include <libmm-gio/iostream_p.hpp>


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
#include <libmm-glib/error.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/slot_async.hpp>

namespace Gio
{

auto IOStream::close_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_io_stream_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto IOStream::close_async (const SlotAsyncReady &slot, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_io_stream_close_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

auto IOStream::splice_async (
  const Glib::RefPtr <IOStream> &stream2, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, SpliceFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_io_stream_splice_async(gobj(), Glib::unwrap(stream2), static_cast<GIOStreamSpliceFlags>(flags),
    io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto IOStream::splice_async (
  const Glib::RefPtr <IOStream> &stream2, const SlotAsyncReady &slot,
  SpliceFlags flags, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_io_stream_splice_async(gobj(), Glib::unwrap(stream2), static_cast<GIOStreamSpliceFlags>(flags),
    io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GIOStream* object, const bool take_copy) -> RefPtr<Gio::IOStream>
{
  return Glib::make_refptr_for_instance<Gio::IOStream>( dynamic_cast<Gio::IOStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto IOStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &IOStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_io_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto IOStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto IOStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new IOStream((GIOStream*)object);
}


/* The implementation: */

auto IOStream::gobj_copy() -> GIOStream*
{
  reference();
  return gobj();
}

IOStream::IOStream(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

IOStream::IOStream(GIOStream* castitem)
: Object((GObject*)castitem)
{}


IOStream::IOStream(IOStream&& src) noexcept
: Object(std::move(src))
{}

auto IOStream::operator=(IOStream&& src) noexcept -> IOStream&
{
  Object::operator=(std::move(src));
  return *this;
}


IOStream::~IOStream() noexcept = default;

IOStream::CppClassType IOStream::iostream_class_; // initialize static member

auto IOStream::get_type() -> GType
{
  return iostream_class_.init().get_type();
}


auto IOStream::get_base_type() -> GType
{
  return g_io_stream_get_type();
}


auto IOStream::splice_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_io_stream_splice_finish(Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto IOStream::get_input_stream() -> Glib::RefPtr<InputStream>
{
  auto retvalue = Glib::wrap(g_io_stream_get_input_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto IOStream::get_output_stream() -> Glib::RefPtr<OutputStream>
{
  auto retvalue = Glib::wrap(g_io_stream_get_output_stream(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto IOStream::close(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_io_stream_close(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto IOStream::close() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_io_stream_close(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto IOStream::close_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_io_stream_close_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto IOStream::is_closed() const -> bool
{
  return g_io_stream_is_closed(const_cast<GIOStream*>(gobj()));
}

auto IOStream::has_pending() const -> bool
{
  return g_io_stream_has_pending(const_cast<GIOStream*>(gobj()));
}

auto IOStream::set_pending() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_io_stream_set_pending(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto IOStream::clear_pending () -> void
{
  g_io_stream_clear_pending(gobj());
}


} // namespace Gio


