
#ifndef _GDKMM_MEMORYTEXTURE_H
#define _GDKMM_MEMORYTEXTURE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gdk/texture.hxx>
#include <libmm-glib/bytes.hxx>
#include <gdk/gdk.h> // For GDK_MEMORY_DEFAULT


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkMemoryTexture = struct _GdkMemoryTexture;
using GdkMemoryTextureClass = struct _GdkMemoryTextureClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API MemoryTexture_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
/** A Gdk::Texture representing image data in memory.
 *
 * @newin{3,98}
 */

class GDKMM_API MemoryTexture : public Gdk::Texture
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MemoryTexture;
  using CppClassType = MemoryTexture_Class;
  using BaseObjectType = GdkMemoryTexture;
  using BaseClassType = GdkMemoryTextureClass;

  // noncopyable
  MemoryTexture(const MemoryTexture&) = delete;
  auto operator=(const MemoryTexture&) -> MemoryTexture& = delete;

private:  friend class MemoryTexture_Class;
  static CppClassType memorytexture_class_;

protected:
  explicit MemoryTexture(const Glib::ConstructParams& construct_params);
  explicit MemoryTexture(GdkMemoryTexture* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MemoryTexture(MemoryTexture&& src) noexcept;
  auto operator=(MemoryTexture&& src) noexcept -> MemoryTexture&;

  ~MemoryTexture() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkMemoryTexture*       { return reinterpret_cast<GdkMemoryTexture*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkMemoryTexture* { return reinterpret_cast<GdkMemoryTexture*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkMemoryTexture*;

private:


protected:
  MemoryTexture();

public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /**
   *  @var Format B8G8R8A8_PREMULTIPLIED
   * 4 bytes; for blue, green, red, alpha.
   * The color values are premultiplied with the alpha value.
   *
   *  @var Format A8R8G8B8_PREMULTIPLIED
   * 4 bytes; for alpha, red, green, blue.
   * The color values are premultiplied with the alpha value.
   *
   *  @var Format R8G8B8A8_PREMULTIPLIED
   * 4 bytes; for red, green, blue, alpha
   * The color values are premultiplied with the alpha value.
   *
   *  @var Format B8G8R8A8
   * 4 bytes; for blue, green, red, alpha.
   *
   *  @var Format A8R8G8B8
   * 4 bytes; for alpha, red, green, blue.
   *
   *  @var Format R8G8B8A8
   * 4 bytes; for red, green, blue, alpha.
   *
   *  @var Format A8B8G8R8
   * 4 bytes; for alpha, blue, green, red.
   *
   *  @var Format R8G8B8
   * 3 bytes; for red, green, blue. The data is opaque.
   *
   *  @var Format B8G8R8
   * 3 bytes; for blue, green, red. The data is opaque.
   *
   *  @var Format R16G16B16
   * 3 guint16 values; for red, green, blue. @newin{4,6}
   *
   *  @var Format R16G16B16A16_PREMULTIPLIED
   * 4 guint16 values; for red, green,
   * blue, alpha. The color values are premultiplied with the alpha value.
   * @newin{4,6}
   *
   *  @var Format R16G16B16A16
   * 4 guint16 values; for red, green, blue, alpha.
   * @newin{4,6}
   *
   *  @var Format R16G16B16_FLOAT
   * 3 half-float values; for red, green, blue.
   * The data is opaque. @newin{4,6}
   *
   *  @var Format R16G16B16A16_FLOAT_PREMULTIPLIED
   * 4 half-float values; for
   * red, green, blue and alpha. The color values are premultiplied with
   * the alpha value. @newin{4,6}
   *
   *  @var Format R16G16B16A16_FLOAT
   * 4 half-float values; for red, green,
   * blue and alpha. @newin{4,6}
   *
   *  @var Format B32G32R32_FLOAT
   * 3 float values; for blue, green, red.
   * The data is opaque. @newin{4,6}
   *
   *  @var Format R32G32B32A32_FLOAT_PREMULTIPLIED
   * 4 float values; for
   * red, green, blue and alpha. The color values are premultiplied with
   * the alpha value. @newin{4,6}
   *
   *  @var Format R32G32B32A32_FLOAT
   * 4 float values; for red, green, blue and
   * alpha. @newin{4,6}
   *
   *  @var Format N_FORMATS
   * The number of formats. This value will change as
   * more formats get added, so do not rely on its concrete integer.
   *
   *  @enum Format
   *
   * `Gdk::MemoryFormat` describes formats that image data can have in memory.
   *
   * It describes formats by listing the contents of the memory passed to it.
   * So GDK_MEMORY_A8R8G8B8 will be 1 byte (8 bits) of alpha, followed by a
   * byte each of red, green and blue. It is not endian-dependent, so
   * CAIRO_FORMAT_ARGB32 is represented by different `Gdk::MemoryFormats`
   * on architectures with different endiannesses.
   *
   * Its naming is modelled after
   * [VkFormat](https://www.khronos.org/registry/vulkan/specs/1.0/html/vkspec.htmlVkFormat)
   * for details).
   *
   * @ingroup gdkmmEnums
   */
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


  /** Default memory format used by GTK.
   *
   * It is the format provided by Gdk::Texture::download().
   * It is equal to Cairo::Surface::Format::ARGB32.
   *
   * Be aware that unlike the Format values, this format is
   * different for different endianness.
   */
  static const Format DEFAULT_FORMAT = static_cast<Format>(GDK_MEMORY_DEFAULT);

  // gdk_memory_texture_new() does more than call g_object_new().

  /** Creates a new texture for a blob of image data.
   *
   * The `Glib::Bytes` must contain @a stride × @a height pixels
   * in the given format.
   *
   * @param width The width of the texture.
   * @param height The height of the texture.
   * @param format The format of the data.
   * @param bytes The `Glib::Bytes` containing the pixel data.
   * @param stride Rowstride for the data.
   * @return A newly-created `Gdk::Texture`.
   */
  static auto create(int width, int height, Format format, const Glib::RefPtr<const Glib::Bytes>& bytes, gsize stride) -> Glib::RefPtr<Texture>;

  // There are no public signals, properties or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::MemoryTexture::Format> : public Glib::Value_Enum<Gdk::MemoryTexture::Format>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::MemoryTexture
   */
  GDKMM_API
  auto wrap(GdkMemoryTexture* object, bool take_copy = false) -> Glib::RefPtr<Gdk::MemoryTexture>;
}


#endif /* _GDKMM_MEMORYTEXTURE_H */

