
#ifndef _GIOMM_DATAOUTPUTSTREAM_H
#define _GIOMM_DATAOUTPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/enums.hxx>
#include <libmm-gio/filteroutputstream.hxx>
#include <libmm-gio/seekable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDataOutputStream = struct _GDataOutputStream;
using GDataOutputStreamClass = struct _GDataOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API DataOutputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API DataOutputStream : public Gio::FilterOutputStream,
                                     public Gio::Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DataOutputStream;
    using CppClassType = DataOutputStream_Class;
    using BaseObjectType = GDataOutputStream;
    using BaseClassType = GDataOutputStreamClass;

    DataOutputStream (const DataOutputStream&) = delete;
    auto
    operator= (const DataOutputStream&) -> DataOutputStream& = delete;

  private:
    friend class DataOutputStream_Class;
    static CppClassType dataoutputstream_class_;

  protected:
    explicit DataOutputStream (const Glib::ConstructParams& construct_params);
    explicit DataOutputStream (GDataOutputStream* castitem);

#endif

  public:
    DataOutputStream (DataOutputStream&& src) noexcept;
    auto
    operator= (DataOutputStream&& src) noexcept -> DataOutputStream&;

    ~DataOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDataOutputStream*
    {
      return reinterpret_cast<GDataOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GDataOutputStream*
    {
      return reinterpret_cast<GDataOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GDataOutputStream*;

  private:
  protected:
    explicit DataOutputStream (const Glib::RefPtr<OutputStream>& base_stream);

  public:
    static auto
    create (const Glib::RefPtr<OutputStream>& base_stream)
        -> Glib::RefPtr<DataOutputStream>;

    void
    set_byte_order (DataStreamByteOrder order);

    auto
    get_byte_order () const -> DataStreamByteOrder;

    auto
    put_byte (guchar data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_byte (guchar data) -> bool;

    auto
    put_int16 (gint16 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_int16 (gint16 data) -> bool;

    auto
    put_uint16 (guint16 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_uint16 (guint16 data) -> bool;

    auto
    put_int32 (gint32 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_int32 (gint32 data) -> bool;

    auto
    put_uint32 (guint32 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_uint32 (guint32 data) -> bool;

    auto
    put_int64 (gint64 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_int64 (gint64 data) -> bool;

    auto
    put_uint64 (guint64 data, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    put_uint64 (guint64 data) -> bool;

    auto
    put_string (const std::string& str,
                const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    put_string (const std::string& str) -> bool;

    auto
    property_byte_order () -> Glib::PropertyProxy<DataStreamByteOrder>;

    auto
    property_byte_order () const
        -> Glib::PropertyProxy_ReadOnly<DataStreamByteOrder>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDataOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::DataOutputStream>;
} // namespace Glib

#endif
