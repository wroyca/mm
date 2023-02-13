


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/datainputstream.hxx>
#include <libmm-gio/datainputstream_p.hxx>


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
#include <libmm-glib/error.hxx>
#include <libmm-gio/slot_async.hxx>

namespace Gio
{

auto
DataInputStream::read_line(std::string& line, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  char* c_line = g_data_input_stream_read_line(gobj(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  if (c_line)
  {
    line = c_line;
    g_free(c_line);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

auto
DataInputStream::read_line(std::string& line) -> bool
{
  GError* gerror = nullptr;
  char* c_line = g_data_input_stream_read_line(gobj(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  if (c_line)
  {
    line = c_line;
    g_free(c_line);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

auto DataInputStream::read_line_async (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_data_input_stream_read_line_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto
DataInputStream::read_line_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data) -> bool
{
  GError* gerror = nullptr;
  gsize size = 0;
  gchar* buffer =
    g_data_input_stream_read_line_finish(gobj(), Glib::unwrap(result), &size, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  bool retval = false;
  if (buffer && size)
  {
    retval = buffer != nullptr;
    data = std::string(buffer, size);
    g_free(buffer);
  }

  return retval;
}

auto
DataInputStream::read_upto(
  std::string& data, const std::string& stop_chars, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_upto(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

/** non-cancellable version of read_upto()
 */
auto
DataInputStream::read_upto(std::string& data, const std::string& stop_chars) -> bool
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_upto(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }

  // end of stream reached, return failure status
  return false;
}

auto DataInputStream::read_upto_async (
  const std::string &stop_chars, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, const int io_priority) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_data_input_stream_read_upto_async(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto
DataInputStream::read_upto_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data) -> bool
{
  GError* gerror = nullptr;
  gsize size = 0;
  gchar* buffer =
    g_data_input_stream_read_upto_finish(gobj(), Glib::unwrap(result), &size, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  bool retval = false;
  if (buffer && size)
  {
    retval = buffer != nullptr;
    data = std::string(buffer, size);
    g_free(buffer);
  }

  return retval;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDataInputStream* object, const bool take_copy) -> RefPtr<Gio::DataInputStream>
{
  return Glib::make_refptr_for_instance<Gio::DataInputStream>( dynamic_cast<Gio::DataInputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto DataInputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DataInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_data_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DataInputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DataInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DataInputStream((GDataInputStream*)object);
}


/* The implementation: */

auto DataInputStream::gobj_copy() -> GDataInputStream*
{
  reference();
  return gobj();
}

DataInputStream::DataInputStream(const Glib::ConstructParams& construct_params)
: BufferedInputStream(construct_params)
{

}

DataInputStream::DataInputStream(GDataInputStream* castitem)
: BufferedInputStream((GBufferedInputStream*)castitem)
{}


DataInputStream::DataInputStream(DataInputStream&& src) noexcept
: BufferedInputStream(std::move(src))
{}

auto DataInputStream::operator=(DataInputStream&& src) noexcept -> DataInputStream&
{
  BufferedInputStream::operator=(std::move(src));
  return *this;
}


DataInputStream::~DataInputStream() noexcept = default;

DataInputStream::CppClassType DataInputStream::datainputstream_class_; // initialize static member

auto DataInputStream::get_type() -> GType
{
  return datainputstream_class_.init().get_type();
}


auto DataInputStream::get_base_type() -> GType
{
  return g_data_input_stream_get_type();
}


DataInputStream::DataInputStream(const Glib::RefPtr<InputStream>& base_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
BufferedInputStream(Glib::ConstructParams(datainputstream_class_.init(), "base_stream", Glib::unwrap(base_stream), nullptr))
{


}

auto DataInputStream::create(const Glib::RefPtr<InputStream>& base_stream) -> Glib::RefPtr<DataInputStream>
{
  return Glib::make_refptr_for_instance<DataInputStream>( new DataInputStream(base_stream) );
}

auto DataInputStream::set_byte_order (DataStreamByteOrder order) -> void
{
  g_data_input_stream_set_byte_order(gobj(), static_cast<GDataStreamByteOrder>(order));
}

auto DataInputStream::get_byte_order() const -> DataStreamByteOrder
{
  return static_cast<DataStreamByteOrder>(g_data_input_stream_get_byte_order(const_cast<GDataInputStream*>(gobj())));
}

auto DataInputStream::set_newline_type (DataStreamNewlineType type) -> void
{
  g_data_input_stream_set_newline_type(gobj(), static_cast<GDataStreamNewlineType>(type));
}

auto DataInputStream::get_newline_type() const -> DataStreamNewlineType
{
  return static_cast<DataStreamNewlineType>(g_data_input_stream_get_newline_type(const_cast<GDataInputStream*>(gobj())));
}

auto DataInputStream::read_byte(const Glib::RefPtr<Cancellable>& cancellable) -> guchar
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_byte(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_byte() -> guchar
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_byte(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int16(const Glib::RefPtr<Cancellable>& cancellable) -> gint16
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int16(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int16() -> gint16
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int16(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint16(const Glib::RefPtr<Cancellable>& cancellable) -> guint16
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint16(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint16() -> guint16
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint16(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int32(const Glib::RefPtr<Cancellable>& cancellable) -> gint32
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int32(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int32() -> gint32
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int32(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint32(const Glib::RefPtr<Cancellable>& cancellable) -> guint32
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint32(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint32() -> guint32
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint32(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int64(const Glib::RefPtr<Cancellable>& cancellable) -> gint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int64(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_int64() -> gint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_int64(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint64(const Glib::RefPtr<Cancellable>& cancellable) -> guint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint64(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_uint64() -> guint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_input_stream_read_uint64(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataInputStream::read_line_utf8 (
  std::string &line, const Glib::RefPtr <Cancellable> &cancellable, gsize &length) -> void
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), &length, Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto DataInputStream::read_line_utf8 (
  std::string &line, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), nullptr, Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto DataInputStream::read_line_utf8 (std::string &line, gsize &length) -> void
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), &length, nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto DataInputStream::read_line_utf8 (std::string &line) -> void
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), nullptr, nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto DataInputStream::read_line_finish_utf8 (
  const Glib::RefPtr <AsyncResult> &result, std::string &data, gsize &length) -> void
{
  GError* gerror = nullptr;
  data = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_finish_utf8(gobj(), Glib::unwrap(result), &length, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto DataInputStream::read_line_finish_utf8 (
  const Glib::RefPtr <AsyncResult> &result, std::string &data) -> void
{
  GError* gerror = nullptr;
  data = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_finish_utf8(gobj(), Glib::unwrap(result), nullptr, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<DataStreamByteOrder>::value,
  "Type DataStreamByteOrder cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DataInputStream::property_byte_order() -> Glib::PropertyProxy< DataStreamByteOrder >
{
  return {this, "byte-order"};
}

auto DataInputStream::property_byte_order() const -> Glib::PropertyProxy_ReadOnly< DataStreamByteOrder >
{
  return {this, "byte-order"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<DataStreamNewlineType>::value,
  "Type DataStreamNewlineType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DataInputStream::property_newline_type() -> Glib::PropertyProxy< DataStreamNewlineType >
{
  return {this, "newline-type"};
}

auto DataInputStream::property_newline_type() const -> Glib::PropertyProxy_ReadOnly< DataStreamNewlineType >
{
  return {this, "newline-type"};
}


} // namespace Gio


