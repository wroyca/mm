// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/datainputstream.hxx>
#include <libmm/gio/datainputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{

  auto
  DataInputStream::read_line (std::string& line,
                              const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    char* c_line = g_data_input_stream_read_line (gobj (),
                                                  nullptr,
                                                  glib::unwrap (cancellable),
                                                  &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    if (c_line)
    {
      line = c_line;
      g_free (c_line);
      return true;
    }

    return false;
  }

  auto
  DataInputStream::read_line (std::string& line) -> bool
  {
    GError* gerror = nullptr;
    char* c_line =
        g_data_input_stream_read_line (gobj (), nullptr, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    if (c_line)
    {
      line = c_line;
      g_free (c_line);
      return true;
    }

    return false;
  }

  auto
  DataInputStream::read_line_async (
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_data_input_stream_read_line_async (gobj (),
                                         io_priority,
                                         glib::unwrap (cancellable),
                                         &SignalProxy_async_callback,
                                         slot_copy);
  }

  auto
  DataInputStream::read_line_finish (const glib::RefPtr<AsyncResult>& result,
                                     std::string& data) -> bool
  {
    GError* gerror = nullptr;
    gsize size = 0;
    gchar* buffer = g_data_input_stream_read_line_finish (gobj (),
                                                          glib::unwrap (result),
                                                          &size,
                                                          &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    bool retval = false;
    if (buffer && size)
    {
      retval = buffer != nullptr;
      data = std::string (buffer, size);
      g_free (buffer);
    }

    return retval;
  }

  auto
  DataInputStream::read_upto (std::string& data,
                              const std::string& stop_chars,
                              const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    char* c_str = g_data_input_stream_read_upto (gobj (),
                                                 stop_chars.c_str (),
                                                 -1,
                                                 nullptr,
                                                 glib::unwrap (cancellable),
                                                 &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    if (c_str)
    {
      data = c_str;
      g_free (c_str);
      return true;
    }

    return false;
  }

  auto
  DataInputStream::read_upto (std::string& data, const std::string& stop_chars) -> bool
  {
    GError* gerror = nullptr;
    char* c_str = g_data_input_stream_read_upto (gobj (),
                                                 stop_chars.c_str (),
                                                 -1,
                                                 nullptr,
                                                 nullptr,
                                                 &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);

    if (c_str)
    {
      data = c_str;
      g_free (c_str);
      return true;
    }

    return false;
  }

  auto
  DataInputStream::read_upto_async (
      const std::string& stop_chars,
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_data_input_stream_read_upto_async (gobj (),
                                         stop_chars.c_str (),
                                         -1,
                                         io_priority,
                                         glib::unwrap (cancellable),
                                         &SignalProxy_async_callback,
                                         slot_copy);
  }

  auto
  DataInputStream::read_upto_finish (const glib::RefPtr<AsyncResult>& result,
                                     std::string& data) -> bool
  {
    GError* gerror = nullptr;
    gsize size = 0;
    gchar* buffer = g_data_input_stream_read_upto_finish (gobj (),
                                                          glib::unwrap (result),
                                                          &size,
                                                          &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);

    bool retval = false;
    if (buffer && size)
    {
      retval = buffer != nullptr;
      data = std::string (buffer, size);
      g_free (buffer);
    }

    return retval;
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GDataInputStream* object, const bool take_copy) -> RefPtr<gio::DataInputStream>
  {
    return glib::make_refptr_for_instance<gio::DataInputStream> (
        dynamic_cast<gio::DataInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  DataInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DataInputStream_Class::class_init_function;

      register_derived_type (g_data_input_stream_get_type ());
    }

    return *this;
  }

  auto
  DataInputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DataInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DataInputStream ((GDataInputStream*) object);
  }

  auto
  DataInputStream::gobj_copy () -> GDataInputStream*
  {
    reference ();
    return gobj ();
  }

  DataInputStream::DataInputStream (
      const glib::ConstructParams& construct_params)
    : BufferedInputStream (construct_params)
  {
  }

  DataInputStream::DataInputStream (GDataInputStream* castitem)
    : BufferedInputStream ((GBufferedInputStream*) castitem)
  {
  }

  DataInputStream::DataInputStream (DataInputStream&& src) noexcept
    : BufferedInputStream (std::move (src))
  {
  }

  auto
  DataInputStream::operator= (DataInputStream&& src) noexcept -> DataInputStream&
  {
    BufferedInputStream::operator= (std::move (src));
    return *this;
  }

  DataInputStream::~DataInputStream () noexcept = default;

  DataInputStream::CppClassType DataInputStream::datainputstream_class_;

  auto
  DataInputStream::get_type () -> GType
  {
    return datainputstream_class_.init ().get_type ();
  }

  auto
  DataInputStream::get_base_type () -> GType
  {
    return g_data_input_stream_get_type ();
  }

  DataInputStream::DataInputStream (
      const glib::RefPtr<InputStream>& base_stream)
    : ObjectBase (nullptr),
      BufferedInputStream (
          glib::ConstructParams (datainputstream_class_.init (),
                                 "base_stream",
                                 glib::unwrap (base_stream),
                                 nullptr))
  {
  }

  auto
  DataInputStream::create (const glib::RefPtr<InputStream>& base_stream) -> glib::RefPtr<DataInputStream>
  {
    return glib::make_refptr_for_instance<DataInputStream> (
        new DataInputStream (base_stream));
  }

  auto
  DataInputStream::set_byte_order (DataStreamByteOrder order) -> void
  {
    g_data_input_stream_set_byte_order (
        gobj (),
        static_cast<GDataStreamByteOrder> (order));
  }

  auto
  DataInputStream::get_byte_order () const -> DataStreamByteOrder
  {
    return static_cast<DataStreamByteOrder> (
        g_data_input_stream_get_byte_order (
            const_cast<GDataInputStream*> (gobj ())));
  }

  auto
  DataInputStream::set_newline_type (DataStreamNewlineType type) -> void
  {
    g_data_input_stream_set_newline_type (
        gobj (),
        static_cast<GDataStreamNewlineType> (type));
  }

  auto
  DataInputStream::get_newline_type () const -> DataStreamNewlineType
  {
    return static_cast<DataStreamNewlineType> (
        g_data_input_stream_get_newline_type (
            const_cast<GDataInputStream*> (gobj ())));
  }

  auto
  DataInputStream::read_byte (const glib::RefPtr<Cancellable>& cancellable) -> guchar
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_byte (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_byte () -> guchar
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_byte (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int16 (const glib::RefPtr<Cancellable>& cancellable) -> gint16
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_int16 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int16 () -> gint16
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_int16 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint16 (const glib::RefPtr<Cancellable>& cancellable) -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_uint16 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint16 () -> guint16
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_uint16 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int32 (const glib::RefPtr<Cancellable>& cancellable) -> gint32
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_int32 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int32 () -> gint32
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_int32 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint32 (const glib::RefPtr<Cancellable>& cancellable) -> guint32
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_uint32 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint32 () -> guint32
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_uint32 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int64 (const glib::RefPtr<Cancellable>& cancellable) -> gint64
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_int64 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_int64 () -> gint64
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_int64 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint64 (const glib::RefPtr<Cancellable>& cancellable) -> guint64
  {
    GError* gerror = nullptr;
    const auto retvalue = g_data_input_stream_read_uint64 (
        gobj (),
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_uint64 () -> guint64
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_data_input_stream_read_uint64 (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  DataInputStream::read_line_utf8 (std::string& line,
                                   const glib::RefPtr<Cancellable>& cancellable,
                                   gsize& length) -> void
  {
    GError* gerror = nullptr;
    line = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_utf8 (gobj (),
                                            &length,
                                            glib::unwrap (cancellable),
                                            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  DataInputStream::read_line_utf8 (std::string& line,
                                   const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    line = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_utf8 (gobj (),
                                            nullptr,
                                            glib::unwrap (cancellable),
                                            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  DataInputStream::read_line_utf8 (std::string& line, gsize& length) -> void
  {
    GError* gerror = nullptr;
    line = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_utf8 (gobj (),
                                            &length,
                                            nullptr,
                                            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  DataInputStream::read_line_utf8 (std::string& line) -> void
  {
    GError* gerror = nullptr;
    line = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_utf8 (gobj (),
                                            nullptr,
                                            nullptr,
                                            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  DataInputStream::read_line_finish_utf8 (
      const glib::RefPtr<AsyncResult>& result,
      std::string& data,
      gsize& length) -> void
  {
    GError* gerror = nullptr;
    data = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_finish_utf8 (gobj (),
                                                   glib::unwrap (result),
                                                   &length,
                                                   &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  DataInputStream::read_line_finish_utf8 (
      const glib::RefPtr<AsyncResult>& result,
      std::string& data) -> void
  {
    GError* gerror = nullptr;
    data = glib::convert_return_gchar_ptr_to_stdstring (
        g_data_input_stream_read_line_finish_utf8 (gobj (),
                                                   glib::unwrap (result),
                                                   nullptr,
                                                   &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<DataStreamByteOrder>::value,
      "Type DataStreamByteOrder cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DataInputStream::property_byte_order () -> glib::PropertyProxy<DataStreamByteOrder>
  {
    return {this, "byte-order"};
  }

  auto
  DataInputStream::property_byte_order () const -> glib::PropertyProxy_ReadOnly<DataStreamByteOrder>
  {
    return {this, "byte-order"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          DataStreamNewlineType>::value,
      "Type DataStreamNewlineType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DataInputStream::property_newline_type () -> glib::PropertyProxy<DataStreamNewlineType>
  {
    return {this, "newline-type"};
  }

  auto
  DataInputStream::property_newline_type () const -> glib::PropertyProxy_ReadOnly<DataStreamNewlineType>
  {
    return {this, "newline-type"};
  }

} // namespace gio
