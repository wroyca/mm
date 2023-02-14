
#ifndef _GIOMM_ZLIBDECOMPRESSOR_H
#define _GIOMM_ZLIBDECOMPRESSOR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/converter.hxx>
#include <libmm-gio/zlibcompressor.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GZlibDecompressor = struct _GZlibDecompressor;
using GZlibDecompressorClass = struct _GZlibDecompressorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API ZlibDecompressor_Class;
}
#endif

namespace Gio
{

  class GIOMM_API FileInfo;

  class GIOMM_API ZlibDecompressor : public Glib::Object,
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
    explicit ZlibDecompressor (const Glib::ConstructParams& construct_params);
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
    create (ZlibCompressorFormat format) -> Glib::RefPtr<ZlibDecompressor>;

    auto
    get_file_info () -> Glib::RefPtr<FileInfo>;

    auto
    get_file_info () const -> Glib::RefPtr<const FileInfo>;

    auto
    property_file_info () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileInfo>>;

    auto
    property_format () const
        -> Glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GZlibDecompressor* object, bool take_copy = false) -> Glib::RefPtr<Gio::ZlibDecompressor>;
} // namespace Glib

#endif
