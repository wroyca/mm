// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ZLIBCOMPRESSOR_H
#define _GIOMM_ZLIBCOMPRESSOR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/converter.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GZlibCompressor = struct _GZlibCompressor;
using GZlibCompressorClass = struct _GZlibCompressorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ZlibCompressor_Class;
}
#endif

namespace gio
{

  enum class ZlibCompressorFormat
  {
    ZLIB,
    GZIP,
    RAW
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::ZlibCompressorFormat>
    : public glib::Value_Enum<gio::ZlibCompressorFormat>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileInfo;

  class LIBMM_GIO_SYMEXPORT ZlibCompressor : public glib::Object,
                                   public Converter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ZlibCompressor;
    using CppClassType = ZlibCompressor_Class;
    using BaseObjectType = GZlibCompressor;
    using BaseClassType = GZlibCompressorClass;

    ZlibCompressor (const ZlibCompressor&) = delete;
    auto
    operator= (const ZlibCompressor&) -> ZlibCompressor& = delete;

  private:
    friend class ZlibCompressor_Class;
    static CppClassType zlibcompressor_class_;

  protected:
    explicit ZlibCompressor (const glib::ConstructParams& construct_params);
    explicit ZlibCompressor (GZlibCompressor* castitem);

#endif

  public:
    ZlibCompressor (ZlibCompressor&& src) noexcept;
    auto
    operator= (ZlibCompressor&& src) noexcept -> ZlibCompressor&;

    ~ZlibCompressor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GZlibCompressor*
    {
      return reinterpret_cast<GZlibCompressor*> (gobject_);
    }

    auto
    gobj () const -> const GZlibCompressor*
    {
      return reinterpret_cast<GZlibCompressor*> (gobject_);
    }

    auto
    gobj_copy () -> GZlibCompressor*;

  private:
  protected:
    explicit ZlibCompressor (ZlibCompressorFormat format, int level);

  public:
    static auto
    create (ZlibCompressorFormat format, int level)
        -> glib::RefPtr<ZlibCompressor>;

    auto
    get_file_info () -> glib::RefPtr<FileInfo>;

    auto
    get_file_info () const -> glib::RefPtr<const FileInfo>;

    auto
    set_file_info (const glib::RefPtr<FileInfo>& file_info) -> void;

    auto
    property_file_info () -> glib::PropertyProxy<glib::RefPtr<FileInfo>>;

    auto
    property_file_info () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileInfo>>;

    auto
    property_format () const
        -> glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>;

    auto
    property_level () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GZlibCompressor* object, bool take_copy = false) -> glib::RefPtr<gio::ZlibCompressor>;
} // namespace glib

#endif
