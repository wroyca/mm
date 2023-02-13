


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dataoutputstream.hxx>
#include <libmm-gio/dataoutputstream_p.hxx>


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

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDataOutputStream* object, const bool take_copy) -> RefPtr<Gio::DataOutputStream>
{
  return Glib::make_refptr_for_instance<Gio::DataOutputStream>( dynamic_cast<Gio::DataOutputStream*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto DataOutputStream_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DataOutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_data_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Seekable::add_interface(get_type());

  }

  return *this;
}


auto DataOutputStream_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DataOutputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DataOutputStream((GDataOutputStream*)object);
}


/* The implementation: */

auto DataOutputStream::gobj_copy() -> GDataOutputStream*
{
  reference();
  return gobj();
}

DataOutputStream::DataOutputStream(const Glib::ConstructParams& construct_params)
: FilterOutputStream(construct_params)
{

}

DataOutputStream::DataOutputStream(GDataOutputStream* castitem)
: FilterOutputStream((GFilterOutputStream*)castitem)
{}


DataOutputStream::DataOutputStream(DataOutputStream&& src) noexcept
: FilterOutputStream(std::move(src))
  , Seekable(std::move(src))
{}

auto DataOutputStream::operator=(DataOutputStream&& src) noexcept -> DataOutputStream&
{
  FilterOutputStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


DataOutputStream::~DataOutputStream() noexcept = default;

DataOutputStream::CppClassType DataOutputStream::dataoutputstream_class_; // initialize static member

auto DataOutputStream::get_type() -> GType
{
  return dataoutputstream_class_.init().get_type();
}


auto DataOutputStream::get_base_type() -> GType
{
  return g_data_output_stream_get_type();
}


DataOutputStream::DataOutputStream(const Glib::RefPtr<OutputStream>& base_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
FilterOutputStream(Glib::ConstructParams(dataoutputstream_class_.init(), "base_stream", Glib::unwrap(base_stream), nullptr))
{


}

auto DataOutputStream::create(const Glib::RefPtr<OutputStream>& base_stream) -> Glib::RefPtr<DataOutputStream>
{
  return Glib::make_refptr_for_instance<DataOutputStream>( new DataOutputStream(base_stream) );
}

auto DataOutputStream::set_byte_order (DataStreamByteOrder order) -> void
{
  g_data_output_stream_set_byte_order(gobj(), static_cast<GDataStreamByteOrder>(order));
}

auto DataOutputStream::get_byte_order() const -> DataStreamByteOrder
{
  return static_cast<DataStreamByteOrder>(g_data_output_stream_get_byte_order(const_cast<GDataOutputStream*>(gobj())));
}

auto DataOutputStream::put_byte(
  const guchar data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_byte(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_byte(
  const guchar data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_byte(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int16(
  const gint16 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int16(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int16(
  const gint16 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int16(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint16(
  const guint16 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint16(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint16(
  const guint16 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint16(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int32(
  const gint32 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int32(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int32(
  const gint32 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int32(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint32(
  const guint32 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint32(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint32(
  const guint32 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint32(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int64(
  const gint64 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int64(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_int64(
  const gint64 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_int64(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint64(
  const guint64 data, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint64(gobj(), data, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_uint64(
  const guint64 data) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_uint64(gobj(), data, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_string(const std::string& str, const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_string(gobj(), str.c_str(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto DataOutputStream::put_string(const std::string& str) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_data_output_stream_put_string(gobj(), str.c_str(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<DataStreamByteOrder>::value,
  "Type DataStreamByteOrder cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DataOutputStream::property_byte_order() -> Glib::PropertyProxy< DataStreamByteOrder >
{
  return {this, "byte-order"};
}

auto DataOutputStream::property_byte_order() const -> Glib::PropertyProxy_ReadOnly< DataStreamByteOrder >
{
  return {this, "byte-order"};
}


} // namespace Gio


