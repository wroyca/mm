// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/dataoutputstream.h>
#include <giomm/private/dataoutputstream_p.h>


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
#include <glibmm/error.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::DataOutputStream> wrap(GDataOutputStream* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gio::DataOutputStream>( dynamic_cast<Gio::DataOutputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& DataOutputStream_Class::init()
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


void DataOutputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* DataOutputStream_Class::wrap_new(GObject* object)
{
  return new DataOutputStream((GDataOutputStream*)object);
}


/* The implementation: */

GDataOutputStream* DataOutputStream::gobj_copy()
{
  reference();
  return gobj();
}

DataOutputStream::DataOutputStream(const Glib::ConstructParams& construct_params)
:
  Gio::FilterOutputStream(construct_params)
{

}

DataOutputStream::DataOutputStream(GDataOutputStream* castitem)
:
  Gio::FilterOutputStream((GFilterOutputStream*)(castitem))
{}


DataOutputStream::DataOutputStream(DataOutputStream&& src) noexcept
: Gio::FilterOutputStream(std::move(src))
  , Seekable(std::move(src))
{}

DataOutputStream& DataOutputStream::operator=(DataOutputStream&& src) noexcept
{
  Gio::FilterOutputStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


DataOutputStream::~DataOutputStream() noexcept
{}


DataOutputStream::CppClassType DataOutputStream::dataoutputstream_class_; // initialize static member

GType DataOutputStream::get_type()
{
  return dataoutputstream_class_.init().get_type();
}


GType DataOutputStream::get_base_type()
{
  return g_data_output_stream_get_type();
}


DataOutputStream::DataOutputStream(const Glib::RefPtr<OutputStream>& base_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::FilterOutputStream(Glib::ConstructParams(dataoutputstream_class_.init(), "base_stream", const_cast<GOutputStream*>(Glib::unwrap(base_stream)), nullptr))
{
  

}

Glib::RefPtr<DataOutputStream> DataOutputStream::create(const Glib::RefPtr<OutputStream>& base_stream)
{
  return Glib::make_refptr_for_instance<DataOutputStream>( new DataOutputStream(base_stream) );
}

void DataOutputStream::set_byte_order(DataStreamByteOrder order)
{
  g_data_output_stream_set_byte_order(gobj(), static_cast<GDataStreamByteOrder>(order));
}

DataStreamByteOrder DataOutputStream::get_byte_order() const
{
  return static_cast<DataStreamByteOrder>(g_data_output_stream_get_byte_order(const_cast<GDataOutputStream*>(gobj())));
}

bool DataOutputStream::put_byte(guchar data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_byte(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_byte(guchar data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_byte(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int16(gint16 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int16(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int16(gint16 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int16(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint16(guint16 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint16(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint16(guint16 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint16(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int32(gint32 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int32(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int32(gint32 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int32(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint32(guint32 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint32(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint32(guint32 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint32(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int64(gint64 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int64(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_int64(gint64 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_int64(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint64(guint64 data, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint64(gobj(), data, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_uint64(guint64 data)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_uint64(gobj(), data, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_string(const std::string& str, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_string(gobj(), str.c_str(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool DataOutputStream::put_string(const std::string& str)
{
  GError* gerror = nullptr;
  auto retvalue = g_data_output_stream_put_string(gobj(), str.c_str(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<DataStreamByteOrder>::value,
  "Type DataStreamByteOrder cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< DataStreamByteOrder > DataOutputStream::property_byte_order() 
{
  return Glib::PropertyProxy< DataStreamByteOrder >(this, "byte-order");
}

Glib::PropertyProxy_ReadOnly< DataStreamByteOrder > DataOutputStream::property_byte_order() const
{
  return Glib::PropertyProxy_ReadOnly< DataStreamByteOrder >(this, "byte-order");
}


} // namespace Gio


