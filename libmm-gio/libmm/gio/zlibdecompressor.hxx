// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ZLIBDECOMPRESSOR_H
#define _GIOMM_ZLIBDECOMPRESSOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/converter.hxx>
#include <libmm/gio/zlibcompressor.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GZlibDecompressor = struct _GZlibDecompressor;
using GZlibDecompressorClass = struct _GZlibDecompressorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ZlibDecompressor_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileInfo;

  class LIBMM_GIO_SYMEXPORT ZlibDecompressor : public glib::Object,
                                     public Converter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ZlibDecompressor;
    using CppClassType = ZlibDecompressor_Class;
    using BaseObjectType = GZlibDecompressor;
    using BaseClassType = GZlibDecompressorClass;

    ZlibDecompressor (const ZlibDecompressor&) = delete;
    auto
    operator= (const ZlibDecompressor&) -> ZlibDecompressor& = delete;

  private:
    friend class ZlibDecompressor_Class;
    static CppClassType zlibdecompressor_class_;

  protected:
    explicit ZlibDecompressor (const glib::ConstructParams& construct_params);
    explicit ZlibDecompressor (GZlibDecompressor* castitem);

#endif

  public:
    ZlibDecompressor (ZlibDecompressor&& src) noexcept;
    auto
    operator= (ZlibDecompressor&& src) noexcept -> ZlibDecompressor&;

    ~ZlibDecompressor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GZlibDecompressor*
    {
      return reinterpret_cast<GZlibDecompressor*> (gobject_);
    }

    auto
    gobj () const -> const GZlibDecompressor*
    {
      return reinterpret_cast<GZlibDecompressor*> (gobject_);
    }

    auto
    gobj_copy () -> GZlibDecompressor*;

  private:
  protected:
    explicit ZlibDecompressor (ZlibCompressorFormat format);

  public:
    static auto
    create (ZlibCompressorFormat format) -> glib::RefPtr<ZlibDecompressor>;

    auto
    get_file_info () -> glib::RefPtr<FileInfo>;

    auto
    get_file_info () const -> glib::RefPtr<const FileInfo>;

    auto
    property_file_info () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileInfo>>;

    auto
    property_format () const
        -> glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GZlibDecompressor* object, bool take_copy = false) -> glib::RefPtr<gio::ZlibDecompressor>;
} // namespace glib

#endif
