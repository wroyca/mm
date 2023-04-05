// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_MEMORYTEXTURE_H
#define _GDKMM_MEMORYTEXTURE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/gdk/texture.hxx>
#include <libmm/glib/bytes.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkMemoryTexture = struct _GdkMemoryTexture;
using GdkMemoryTextureClass = struct _GdkMemoryTextureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT MemoryTexture_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT MemoryTexture : public gdk::Texture
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MemoryTexture;
    using CppClassType = MemoryTexture_Class;
    using BaseObjectType = GdkMemoryTexture;
    using BaseClassType = GdkMemoryTextureClass;

    MemoryTexture (const MemoryTexture&) = delete;
    auto
    operator= (const MemoryTexture&) -> MemoryTexture& = delete;

  private:
    friend class MemoryTexture_Class;
    static CppClassType memorytexture_class_;

  protected:
    explicit MemoryTexture (const glib::ConstructParams& construct_params);
    explicit MemoryTexture (GdkMemoryTexture* castitem);

#endif

  public:
    MemoryTexture (MemoryTexture&& src) noexcept;
    auto
    operator= (MemoryTexture&& src) noexcept -> MemoryTexture&;

    ~MemoryTexture () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkMemoryTexture*
    {
      return reinterpret_cast<GdkMemoryTexture*> (gobject_);
    }

    auto
    gobj () const -> const GdkMemoryTexture*
    {
      return reinterpret_cast<GdkMemoryTexture*> (gobject_);
    }

    auto
    gobj_copy () -> GdkMemoryTexture*;

  private:
  protected:
    MemoryTexture ();

  public:
    enum class Format
    {
      B8G8R8A8_PREMULTIPLIED,
      A8R8G8B8_PREMULTIPLIED,
      R8G8B8A8_PREMULTIPLIED,
      B8G8R8A8,
      A8R8G8B8,
      R8G8B8A8,
      A8B8G8R8,
      R8G8B8,
      B8G8R8,
      R16G16B16,
      R16G16B16A16_PREMULTIPLIED,
      R16G16B16A16,
      R16G16B16_FLOAT,
      R16G16B16A16_FLOAT_PREMULTIPLIED,
      R16G16B16A16_FLOAT,
      R32G32B32_FLOAT,
      R32G32B32A32_FLOAT_PREMULTIPLIED,
      R32G32B32A32_FLOAT,
      N_FORMATS
    };

    static const Format DEFAULT_FORMAT =
        static_cast<Format> (GDK_MEMORY_DEFAULT);

    static auto
    create (int width,
            int height,
            Format format,
            const glib::RefPtr<const glib::Bytes>& bytes,
            gsize stride) -> glib::RefPtr<Texture>;

  public:
  public:
  protected:
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::MemoryTexture::Format>
    : public glib::Value_Enum<gdk::MemoryTexture::Format>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkMemoryTexture* object, bool take_copy = false) -> glib::RefPtr<gdk::MemoryTexture>;
} // namespace glib

#endif
