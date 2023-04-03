// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DATAINPUTSTREAM_H
#define _GIOMM_DATAINPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/bufferedinputstream.hxx>
#include <libmm/gio/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDataInputStream = struct _GDataInputStream;
using GDataInputStreamClass = struct _GDataInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT DataInputStream_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT DataInputStream : public Gio::BufferedInputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DataInputStream;
    using CppClassType = DataInputStream_Class;
    using BaseObjectType = GDataInputStream;
    using BaseClassType = GDataInputStreamClass;

    DataInputStream (const DataInputStream&) = delete;
    auto
    operator= (const DataInputStream&) -> DataInputStream& = delete;

  private:
    friend class DataInputStream_Class;
    static CppClassType datainputstream_class_;

  protected:
    explicit DataInputStream (const Glib::ConstructParams& construct_params);
    explicit DataInputStream (GDataInputStream* castitem);

#endif

  public:
    DataInputStream (DataInputStream&& src) noexcept;
    auto
    operator= (DataInputStream&& src) noexcept -> DataInputStream&;

    ~DataInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDataInputStream*
    {
      return reinterpret_cast<GDataInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GDataInputStream*
    {
      return reinterpret_cast<GDataInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GDataInputStream*;

  private:
  protected:
    explicit DataInputStream (const Glib::RefPtr<InputStream>& base_stream);

  public:
    static auto
    create (const Glib::RefPtr<InputStream>& base_stream)
        -> Glib::RefPtr<DataInputStream>;

    auto
    set_byte_order (DataStreamByteOrder order) -> void;

    auto
    get_byte_order () const -> DataStreamByteOrder;

    auto
    set_newline_type (DataStreamNewlineType type) -> void;

    auto
    get_newline_type () const -> DataStreamNewlineType;

    auto
    read_byte (const Glib::RefPtr<Cancellable>& cancellable) -> guchar;

    auto
    read_byte () -> guchar;

    auto
    read_int16 (const Glib::RefPtr<Cancellable>& cancellable) -> gint16;

    auto
    read_int16 () -> gint16;

    auto
    read_uint16 (const Glib::RefPtr<Cancellable>& cancellable) -> guint16;

    auto
    read_uint16 () -> guint16;

    auto
    read_int32 (const Glib::RefPtr<Cancellable>& cancellable) -> gint32;

    auto
    read_int32 () -> gint32;

    auto
    read_uint32 (const Glib::RefPtr<Cancellable>& cancellable) -> guint32;

    auto
    read_uint32 () -> guint32;

    auto
    read_int64 (const Glib::RefPtr<Cancellable>& cancellable) -> gint64;

    auto
    read_int64 () -> gint64;

    auto
    read_uint64 (const Glib::RefPtr<Cancellable>& cancellable) -> guint64;

    auto
    read_uint64 () -> guint64;

    auto
    read_line (std::string& line, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    read_line (std::string& line) -> bool;

    auto
    read_line_utf8 (std::string& line,
                    const Glib::RefPtr<Cancellable>& cancellable,
                    gsize& length) -> void;

    auto
    read_line_utf8 (std::string& line,
                    const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    read_line_utf8 (std::string& line, gsize& length) -> void;

    auto
    read_line_utf8 (std::string& line) -> void;

    auto
    read_line_async (const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    read_line_finish (const Glib::RefPtr<AsyncResult>& result,
                      std::string& data) -> bool;

    auto
    read_line_finish_utf8 (const Glib::RefPtr<AsyncResult>& result,
                           std::string& data,
                           gsize& length) -> void;

    auto
    read_line_finish_utf8 (const Glib::RefPtr<AsyncResult>& result,
                           std::string& data) -> void;

    auto
    read_upto (std::string& data,
               const std::string& stop_chars,
               const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    read_upto (std::string& data, const std::string& stop_chars) -> bool;

    auto
    read_upto_async (const std::string& stop_chars,
                     const SlotAsyncReady& slot,
                     const Glib::RefPtr<Cancellable>& cancellable,
                     int io_priority = Glib::PRIORITY_DEFAULT) -> void;

    auto
    read_upto_finish (const Glib::RefPtr<AsyncResult>& result,
                      std::string& data) -> bool;

    auto
    property_byte_order () -> Glib::PropertyProxy<DataStreamByteOrder>;

    auto
    property_byte_order () const
        -> Glib::PropertyProxy_ReadOnly<DataStreamByteOrder>;

    auto
    property_newline_type () -> Glib::PropertyProxy<DataStreamNewlineType>;

    auto
    property_newline_type () const
        -> Glib::PropertyProxy_ReadOnly<DataStreamNewlineType>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDataInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::DataInputStream>;
} // namespace Glib

#endif
