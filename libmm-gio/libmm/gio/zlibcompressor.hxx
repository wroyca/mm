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
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT ZlibCompressor_Class;
}
#endif

namespace Gio
{

  enum class ZlibCompressorFormat
  {
    ZLIB,
    GZIP,
    RAW
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::ZlibCompressorFormat>
    : public Glib::Value_Enum<Gio::ZlibCompressorFormat>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT FileInfo;

  class LIBMM_GIO_SYMEXPORT ZlibCompressor : public Glib::Object,
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
    explicit ZlibCompressor (const Glib::ConstructParams& construct_params);
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
        -> Glib::RefPtr<ZlibCompressor>;

    auto
    get_file_info () -> Glib::RefPtr<FileInfo>;

    auto
    get_file_info () const -> Glib::RefPtr<const FileInfo>;

    auto
    set_file_info (const Glib::RefPtr<FileInfo>& file_info) -> void;

    auto
    property_file_info () -> Glib::PropertyProxy<Glib::RefPtr<FileInfo>>;

    auto
    property_file_info () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileInfo>>;

    auto
    property_format () const
        -> Glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>;

    auto
    property_level () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GZlibCompressor* object, bool take_copy = false) -> Glib::RefPtr<Gio::ZlibCompressor>;
} // namespace Glib

#endif
