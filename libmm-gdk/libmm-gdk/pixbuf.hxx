
#ifndef _GDKMM_PIXBUF_H
#define _GDKMM_PIXBUF_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

// This is for including the config header before any code (such as
// the #ifndef GDKMM_DISABLE_DEPRECATED in deprecated classes) is generated:


#include <vector>

#include <libmm-gdk/pixbufformat.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/loadableicon.hxx>
#include <libmm-cairo/surface.hxx>
#include <libmm-glib/error.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbuf = struct _GdkPixbuf;
using GdkPixbufClass = struct _GdkPixbufClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Pixbuf_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{


/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/**
 *  @var Colorspace RGB
 * Indicates a red/green/blue additive color space.
 *
 *  @enum Colorspace
 *
 * This enumeration defines the color spaces that are supported by
 * the gdk-pixbuf library.
 *
 * Currently only RGB is supported.
 *
 * @ingroup gdkmmEnums
 */
enum class Colorspace
{
  RGB
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::Colorspace> : public Glib::Value_Enum<Gdk::Colorspace>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{

/**
 *  @var InterpType NEAREST
 * Nearest neighbor sampling; this is the fastest
 * and lowest quality mode. Quality is normally unacceptable when scaling
 * down, but may be OK when scaling up.
 *
 *  @var InterpType TILES
 * This is an accurate simulation of the PostScript
 * image operator without any interpolation enabled.  Each pixel is
 * rendered as a tiny parallelogram of solid color, the edges of which
 * are implemented with antialiasing.  It resembles nearest neighbor for
 * enlargement, and bilinear for reduction.
 *
 *  @var InterpType BILINEAR
 * Best quality/speed balance; use this mode by
 * default. Bilinear interpolation.  For enlargement, it is
 * equivalent to point-sampling the ideal bilinear-interpolated image.
 * For reduction, it is equivalent to laying down small tiles and
 * integrating over the coverage area.
 *
 *  @var InterpType HYPER
 * This is the slowest and highest quality
 * reconstruction function. It is derived from the hyperbolic filters in
 * Wolberg's "Digital Image Warping", and is formally defined as the
 * hyperbolic-filter sampling the ideal hyperbolic-filter interpolated
 * image (the filter is designed to be idempotent for 1:1 pixel mapping).
 * **Deprecated**: this interpolation filter is deprecated, as in reality
 * it has a lower quality than the @a GDK_INTERP_BILINEAR filter
 * (Since: 2.38).
 *
 *  @enum InterpType
 *
 * Interpolation modes for scaling functions.
 *
 * The `Gdk::InterpType::NEAREST` mode is the fastest scaling method, but has
 * horrible quality when scaling down; `Gdk::InterpType::BILINEAR` is the best
 * choice if you aren't sure what to choose, it has a good speed/quality
 * balance.
 *
 * **Note**: Cubic filtering is missing from the list; hyperbolic
 * interpolation is just as fast and results in higher quality.
 *
 * @ingroup gdkmmEnums
 */
enum class InterpType
{
  NEAREST,
  TILES,
  BILINEAR,
  HYPER
};


} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::InterpType> : public Glib::Value_Enum<Gdk::InterpType>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/**  %Exception class for Gdk::Pixbuf errors.
 */
class PixbufError : public Glib::Error
{
public:
  /**  @var Code CORRUPT_IMAGE
   * An image file was broken somehow.
   *
   *  @var Code INSUFFICIENT_MEMORY
   * Not enough memory.
   *
   *  @var Code BAD_OPTION
   * A bad option was passed to a pixbuf save module.
   *
   *  @var Code UNKNOWN_TYPE
   * Unknown image type.
   *
   *  @var Code UNSUPPORTED_OPERATION
   * Don't know how to perform the
   * given operation on the type of image at hand.
   *
   *  @var Code FAILED
   * Generic failure code, something went wrong.
   *
   *  @var Code INCOMPLETE_ANIMATION
   * Only part of the animation was loaded.
   *
   *  @enum Code
   *
   * An error code in the `GDK_PIXBUF_ERROR` domain.
   *
   * Many gdk-pixbuf operations can cause errors in this domain, or in
   * the `G_FILE_ERROR` domain.
   */
  enum Code
  {
    CORRUPT_IMAGE,
    INSUFFICIENT_MEMORY,
    BAD_OPTION,
    UNKNOWN_TYPE,
    UNSUPPORTED_OPERATION,
    FAILED,
    INCOMPLETE_ANIMATION
  };

  GDKMM_API PixbufError(Code error_code, const Glib::ustring& error_message);
  GDKMM_API explicit PixbufError(GError* gobject);
  GDKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GDKMM_API static void throw_func(GError* gobject);

  friend GDKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::PixbufError::Code> : public Glib::Value_Enum<Gdk::PixbufError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


class GDKMM_API Pixbuf
  : public Glib::Object,
    public Gio::Icon,
    public Gio::LoadableIcon
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Pixbuf;
  using CppClassType = Pixbuf_Class;
  using BaseObjectType = GdkPixbuf;
  using BaseClassType = GdkPixbufClass;

  // noncopyable
  Pixbuf(const Pixbuf&) = delete;
  auto operator=(const Pixbuf&) -> Pixbuf& = delete;

private:  friend class Pixbuf_Class;
  static CppClassType pixbuf_class_;

protected:
  explicit Pixbuf(const Glib::ConstructParams& construct_params);
  explicit Pixbuf(GdkPixbuf* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Pixbuf(Pixbuf&& src) noexcept;
  auto operator=(Pixbuf&& src) noexcept -> Pixbuf&;

  ~Pixbuf() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkPixbuf*       { return reinterpret_cast<GdkPixbuf*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkPixbuf* { return reinterpret_cast<GdkPixbuf*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkPixbuf*;

private:


protected:
  /** Transfers image data from a Cairo::Surface and converts it to an RGB(A)
   * representation inside a Gdk::Pixbuf. This allows you to efficiently read
   * individual pixels from cairo surfaces.
   *
   * This will create an RGB pixbuf with 8 bits per channel.
   * The pixbuf will contain an alpha channel if the surface contains one.
   *
   * @param src Surface to copy from.
   * @param src_x Source X coordinate within the surface.
   * @param src_y Source Y coordinate within the surface.
   * @param width Width in pixels of region to get.
   * @param height Height in pixels of region to get.
   *
   * @throw Gdk::PixbufError
   *
   * @newin{2,30}
   */
  Pixbuf(const ::Cairo::RefPtr< ::Cairo::Surface>& src,
         int src_x, int src_y, int width, int height);


public:
  // Used only internally in gdk-pixbuf: _WRAP_ENUM(AlphaMode, GdkPixbufAlphaMode)
  /**
   *  @var Rotation NONE
   * No rotation.
   *
   *  @var Rotation COUNTERCLOCKWISE
   * Rotate by 90 degrees.
   *
   *  @var Rotation UPSIDEDOWN
   * Rotate by 180 degrees.
   *
   *  @var Rotation CLOCKWISE
   * Rotate by 270 degrees.
   *
   *  @enum Rotation
   *
   * The possible rotations which can be passed to Gdk::Pixbuf::rotate_simple().
   *
   * To make them easier to use, their numerical values are the actual degrees.
   *
   * @ingroup gdkmmEnums
   */
  enum class Rotation
  {
    NONE = 0,
    COUNTERCLOCKWISE = 90,
    UPSIDEDOWN = 180,
    CLOCKWISE = 270
  };


  using SlotDestroyData = sigc::slot<void(const guint8*)>;

  /** Transfers image data from a Cairo::Surface and converts it to an RGB(A)
   * representation inside a Gdk::Pixbuf. This allows you to efficiently read
   * individual pixels from cairo surfaces.
   *
   * This will create an RGB pixbuf with 8 bits per channel.
   * The pixbuf will contain an alpha channel if the surface contains one.
   *
   * @param src Surface to copy from.
   * @param src_x Source X coordinate within the surface.
   * @param src_y Source Y coordinate within the surface.
   * @param width Width in pixels of region to get.
   * @param height Height in pixels of region to get.
   *
   * @throw Gdk::PixbufError
   *
   * @newin{2,30}
   */

  static auto create(const ::Cairo::RefPtr< ::Cairo::Surface>& src, int src_x, int src_y, int width, int height) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new `Gdk::Pixbuf` with a copy of the information in the specified
   * `pixbuf`.
   *
   * Note that this does not copy the options set on the original `Gdk::Pixbuf`,
   * use copy_options() for this.
   *
   * @return A newly-created pixbuf.
   */
  auto copy() const -> Glib::RefPtr<Pixbuf>;


  /** Creates a new `Gdk::Pixbuf` structure and allocates a buffer for it.
   *
   * If the allocation of the buffer failed, this function will return <tt>nullptr</tt>.
   *
   * The buffer has an optimal rowstride. Note that the buffer is not cleared;
   * you will have to fill it completely yourself.
   *
   * @param colorspace Color space for image.
   * @param has_alpha Whether the image should have transparency information.
   * @param bits_per_sample Number of bits per color sample.
   * @param width Width of image in pixels, must be > 0.
   * @param height Height of image in pixels, must be > 0.
   * @return A newly-created pixel buffer.
   */
  static auto create(Colorspace colorspace, bool has_alpha, int bits_per_sample, int width, int height) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf which represents a sub-region of `src_pixbuf`.
   *
   * The new pixbuf shares its pixels with the original pixbuf, so
   * writing to one affects both.  The new pixbuf holds a reference to
   * `src_pixbuf`, so `src_pixbuf` will not be finalized until the new
   * pixbuf is finalized.
   *
   * Note that if `src_pixbuf` is read-only, this function will force it
   * to be mutable.
   *
   * @param src_pixbuf A `Gdk::Pixbuf`.
   * @param src_x X coord in @a src_pixbuf.
   * @param src_y Y coord in @a src_pixbuf.
   * @param width Width of region in @a src_pixbuf.
   * @param height Height of region in @a src_pixbuf.
   * @return A new pixbuf.
   */
  static auto create_subpixbuf(const Glib::RefPtr<Pixbuf>& src_pixbuf, int src_x, int src_y, int width, int height) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by loading an image from a file. The file format is detected automatically.
   * @param filename The path to the pixbuf file.
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  static auto create_from_file(const std::string& filename) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by loading an image from a file. The file format is detected automatically.
   * The image will be scaled to fit in the requested size.
   * @param filename The path to the pixbuf file.
   * @param width The desired width
   * @param height The desired height
   * @param preserve_aspect_ratio Whether the image's aspect ratio will be preserved when scaling.
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  static auto create_from_file(const std::string& filename, int width, int height, bool preserve_aspect_ratio =  true) -> Glib::RefPtr<Pixbuf>;
   //gdk_pixbuf_new_from_file_at_size() just calls gdk_pixbuf_new_from_file_at_scale().


  /** Creates a new pixbuf by loading an image from a resource. The file format is detected automatically.
   * @param resource_path The path of the resource file.
   *
   * @throw Gio::ResourceError
   * @throw Gdk::PixbufError
   *
   * @newin{3,12}
   */
  static auto create_from_resource(const std::string& resource_path) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by loading an image from a resource. The file format is detected automatically.
   * The image will be scaled to fit in the requested size, optionally
   * preserving the image's aspect ratio. When preserving the aspect ratio,
   * a @a width of -1 will cause the image to be scaled to the exact given
   * height, and a @a height of -1 will cause the image to be scaled to the
   * exact given width. When not preserving aspect ratio, a @a width or
   * @a height of -1 means to not scale the image at all in that dimension.
   * @param resource_path The path of the resource file.
   * @param width The desired width
   * @param height The desired height
   * @param preserve_aspect_ratio Whether the image's aspect ratio will be preserved when scaling.
   *
   * @throw Gio::ResourceError
   * @throw Gdk::PixbufError
   *
   * @newin{3,12}
   */
  static auto create_from_resource(const std::string& resource_path, int width, int height, bool preserve_aspect_ratio =  true) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new Gdk::Pixbuf out of in-memory image data.
   * Currently only RGB images with 8 bits per sample are supported.
   *
   * @param data %Image data in 8-bit/sample packed format.
   * @param colorspace Colorspace for the image data.
   * @param has_alpha Whether the data has an opacity channel.
   * @param bits_per_sample Number of bits per sample.
   * @param width Width of the image in pixels.
   * @param height Height of the image in pixels.
   * @param rowstride Distance in bytes between rows.
   * @return A newly-created Gdk::Pixbuf object.
   */
  static auto create_from_data(const guint8* data, Colorspace colorspace,
                                               bool has_alpha, int bits_per_sample,
                                               int width, int height, int rowstride) -> Glib::RefPtr<Pixbuf>;

  /** Creates a new Gdk::Pixbuf out of in-memory image data.
   * Currently only RGB images with 8 bits per sample are supported.
   *
   * @param data %Image data in 8-bit/sample packed format.
   * @param colorspace Colorspace for the image data.
   * @param has_alpha Whether the data has an opacity channel.
   * @param bits_per_sample Number of bits per sample.
   * @param width Width of the image in pixels.
   * @param height Height of the image in pixels.
   * @param rowstride Distance in bytes between rows.
   * @param destroy_slot Slot used to free the data when the pixbuf's
   * reference count drops to zero.
   * @return A newly-created Gdk::Pixbuf object.
   */
  static auto create_from_data(const guint8* data, Colorspace colorspace,
                                               bool has_alpha, int bits_per_sample,
                                               int width, int height, int rowstride,
                                               const SlotDestroyData& destroy_slot) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by parsing XPM data in memory.
   *
   * This data is commonly the result of including an XPM file into a
   * program's C source.
   *
   * @param data Pointer to inline XPM data.
   * @return A newly-created pixbuf.
   */
  static auto create_from_xpm_data(const char *const * data) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by loading an image from an input stream.
   *
   * The file format is detected automatically.
   *
   * If <tt>nullptr</tt> is returned, then `error` will be set.
   *
   * The `cancellable` can be used to abort the operation from another thread.
   * If the operation was cancelled, the error `Gio::Error::CANCELLED` will be
   * returned. Other possible errors are in the `GDK_PIXBUF_ERROR` and
   * `G_IO_ERROR` domains.
   *
   * The stream is not closed.
   *
   * @newin{2,14}
   *
   * @param stream A `Gio::InputStream` to load the pixbuf from.
   * @param cancellable Optional `Gio::Cancellable` object, <tt>nullptr</tt> to ignore.
   * @return A newly-created pixbuf.
   *
   * @throws Glib::Error
   */
  static auto create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream, const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>;
  static auto create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<Pixbuf>;


  /** Creates a new pixbuf by loading an image from an input stream.
   *
   * The file format is detected automatically. If <tt>nullptr</tt> is returned, then
   *  @a error will be set. The @a cancellable can be used to abort the operation
   * from another thread. If the operation was cancelled, the error
   * `Gio::Error::CANCELLED` will be returned. Other possible errors are in
   * the `GDK_PIXBUF_ERROR` and `G_IO_ERROR` domains.
   *
   * The image will be scaled to fit in the requested size, optionally
   * preserving the image's aspect ratio.
   *
   * When preserving the aspect ratio, a `width` of -1 will cause the image to be
   * scaled to the exact given height, and a `height` of -1 will cause the image
   * to be scaled to the exact given width. If both `width` and `height` are
   * given, this function will behave as if the smaller of the two values
   * is passed as -1.
   *
   * When not preserving aspect ratio, a `width` or `height` of -1 means to not
   * scale the image at all in that dimension.
   *
   * The stream is not closed.
   *
   * @newin{2,14}
   *
   * @param stream A `Gio::InputStream` to load the pixbuf from.
   * @param width The width the image should have or -1 to not constrain the width.
   * @param height The height the image should have or -1 to not constrain the height.
   * @param preserve_aspect_ratio <tt>true</tt> to preserve the image's aspect ratio.
   * @param cancellable Optional `Gio::Cancellable` object, <tt>nullptr</tt> to ignore.
   * @return A newly-created pixbuf.
   *
   * @throws Glib::Error
   */
  static auto create_from_stream_at_scale(const Glib::RefPtr<Gio::InputStream>& stream, int width, int height, bool preserve_aspect_ratio, const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>;
  static auto create_from_stream_at_scale(const Glib::RefPtr<Gio::InputStream>& stream, int width, int height, bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>;


  /** Queries the color space of a pixbuf.
   *
   * @return Color space.
   */
  auto get_colorspace() const -> Colorspace;


  /** Queries the number of channels of a pixbuf.
   *
   * @return Number of channels.
   */
  auto get_n_channels() const -> int;

  /** Queries whether a pixbuf has an alpha channel (opacity information).
   *
   * @return <tt>true</tt> if it has an alpha channel, <tt>false</tt> otherwise.
   */
  auto get_has_alpha() const -> bool;

  /** Queries the number of bits per color sample in a pixbuf.
   *
   * @return Number of bits per color sample.
   */
  auto get_bits_per_sample() const -> int;

  // Note that the const version uses gdk_pixbuf_read_pixels, not gdk_pixbuf_get_pixels(),
  // because gdk_pixbuf_get_pixels() is documented as sometimes copying data internally
  // so the caller can make changes, but a const version wouldn't ever do that.

  /** Queries a pointer to the pixel data of a pixbuf.
   *
   * This function will cause an implicit copy of the pixbuf data if the
   * pixbuf was created from read-only data.
   *
   * Please see the section on [image data](class.Pixbuf.html#image-data) for information
   * about how the pixel data is stored in memory.
   *
   * @return A pointer to the pixbuf's pixel data.
   */
  auto get_pixels() -> guint8*;

  /** Provides a read-only pointer to the raw pixel data.
   *
   * This function allows skipping the implicit copy that must be made
   * if get_pixels() is called on a read-only pixbuf.
   *
   * @newin{2,32}
   *
   * @return A read-only pointer to the raw pixel data.
   */
  auto get_pixels() const -> const guint8*;


  /** Queries a pointer to the pixel data of a pixbuf.
   *
   * This function will cause an implicit copy of the pixbuf data if the
   * pixbuf was created from read-only data.
   *
   * Please see the section on [image data](class.Pixbuf.html#image-data) for information
   * about how the pixel data is stored in memory.
   *
   * @newin{2,26}
   *
   * @param length The length of the binary data.
   * @return A pointer to the pixbuf's
   * pixel data.
   */
  auto get_pixels(guint& length) -> guint8*;

  // We hand-code this because there is no gdk_pixbuf_read_pixels_with_length().
  auto get_pixels(guint& length) const -> const guint8*;


  /** Queries the width of a pixbuf.
   *
   * @return Width in pixels.
   */
  auto get_width() const -> int;

  /** Queries the height of a pixbuf.
   *
   * @return Height in pixels.
   */
  auto get_height() const -> int;

  /** Queries the rowstride of a pixbuf, which is the number of bytes between
   * the start of a row and the start of the next row.
   *
   * @return Distance between row starts.
   */
  auto get_rowstride() const -> int;

  /** Returns the length of the pixel data, in bytes.
   *
   * @newin{2,26}
   *
   * @return The length of the pixel data.
   */
  auto get_byte_length() const -> gsize;


  /** Clears a pixbuf to the given RGBA value, converting the RGBA value into
   * the pixbuf's pixel format.
   *
   * The alpha component will be ignored if the pixbuf doesn't have an alpha
   * channel.
   *
   * @param pixel RGBA pixel to used to clear (`0xffffffff` is opaque white,
   * `0x00000000` transparent black).
   */
  void fill(guint32 pixel);

  /** Saves pixbuf to a file in format @a type.
   * By default, "jpeg", "png", "ico" and "bmp" are possible file formats to
   * save in, but more formats may be installed. The list of all writable
   * formats can be determined by using get_formats() with is_writable().
   *
   * @newin{3,6}
   *
   * @param filename The path of the file to be created.
   * @param type The file type.
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  void save(const std::string& filename, const Glib::ustring& type) const;


  /** Saves pixbuf to a file in format @a type.
   * By default, "jpeg", "png", "ico" and "bmp" are possible file formats to save in, but more formats may be installed.
   * TThe list of all writable formats can be determined by using get_formats() with
   * Gdk::PixbufFormat::is_writable().
   *
   * The @a option_keys and @a option_values, if not empty, should contain pairs of strings that modify the save parameters.
   * For example,  "quality", "100".
   *
   * Currently only a few parameters exist. JPEG images can be saved with a "quality" parameter;
   * its value should be in the range [0,100]. Text chunks can be attached to PNG images by specifying parameters of the
   * form "tEXt::key", where key is an ASCII string of length 1-79. The values are UTF-8 encoded strings. ICO images can be
   * saved in depth 16, 24, or 32, by using the "depth" parameter. When the ICO saver is given "x_hot" and "y_hot"
   * parameters, it produces a CUR instead of an ICO.
   *
   * @newin{3,6}
   *
   * @param filename The path of the file to be created.
   * @param type The file type.
   * @param option_keys
   * @param option_values
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  void save(const std::string& filename, const Glib::ustring& type,
            const std::vector<Glib::ustring>& option_keys,
            const std::vector<Glib::ustring>& option_values) const;


#if 0 //TODO:
  typedef sigc::slot<const char*(gsize)> SlotSave;

  /** @throws TODO
   */
  void save(const SlotSave& slot, const std::string& type);


  /** A map of option keys to option values.
   */
  typepdef std::map<Glib::ustring, Glib::ustring> SaveValuesMap;

  void save(const SlotSave& slot, const std::string& type, const SaveValuesMap& options);
#endif

/* TODO:
typedef gboolean (*GdkPixbufSaveFunc)   (const gchar *buf,
					 gsize count,
					 GError **error,
					 gpointer data);

gboolean gdk_pixbuf_save_to_callback    (GdkPixbuf  *pixbuf,
					 GdkPixbufSaveFunc save_func,
					 gpointer user_data,
					 const char *type,
					 GError    **error,
					 ...);

gboolean gdk_pixbuf_save_to_callbackv   (GdkPixbuf  *pixbuf,
					 GdkPixbufSaveFunc save_func,
					 gpointer user_data,
					 const char *type,
					 char      **option_keys,
					 char      **option_values,
					 GError    **error);

*/

  /** Saves the pixbuf to a new buffer in format @a type.
   * Note that the buffer is not nul-terminated and may contain embedded nulls.
   * @see save().
   *
   * @newin{3,6}
   *
   * @param buffer This will be set to the address of a new buffer.
   * @param buffer_size This will be set to the size of the @a buffer.
   * @param type Currently "jpeg", "png", "ico" or "bmp".
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  void save_to_buffer(gchar*& buffer, gsize& buffer_size,
                      const Glib::ustring& type = "png") const;

  /** Saves the pixbuf to a new buffer in format @a type.
   * Note that the buffer is not nul-terminated and may contain embedded nulls.
   * @see save().
   *
   * @newin{3,6}
   *
   * @param buffer This will be set to the address of a new buffer.
   * @param buffer_size This will be set to the size of the @a buffer.
   * @param type Currently "jpeg", "png", "ico" or "bmp".
   * @param option_keys Names of options to set.
   * @param option_values Values for named options.
   *
   * @throw Glib::FileError
   * @throw Gdk::PixbufError
   */
  void save_to_buffer(gchar*& buffer, gsize& buffer_size,
                      const Glib::ustring& type,
                      const std::vector<Glib::ustring>& option_keys,
                      const std::vector<Glib::ustring>& option_values) const;


  /** Takes an existing pixbuf and adds an alpha channel to it.
   *
   * If the existing pixbuf already had an alpha channel, the channel
   * values are copied from the original; otherwise, the alpha channel
   * is initialized to 255 (full opacity).
   *
   * If `substitute_color` is <tt>true</tt>, then the color specified by the
   * (`r`, `g`, `b`) arguments will be assigned zero opacity. That is,
   * if you pass `(255, 255, 255)` for the substitute color, all white
   * pixels will become fully transparent.
   *
   * If `substitute_color` is <tt>false</tt>, then the (`r`, `g`, `b`) arguments
   * will be ignored.
   *
   * @param substitute_color Whether to set a color to zero opacity.
   * @param r Red value to substitute.
   * @param g Green value to substitute.
   * @param b Blue value to substitute.
   * @return A newly-created pixbuf.
   */
  auto add_alpha(bool substitute_color, guint8 r, guint8 g, guint8 b) const -> Glib::RefPtr<Gdk::Pixbuf>;


  /** Copies a rectangular area from `src_pixbuf` to `dest_pixbuf`.
   *
   * Conversion of pixbuf formats is done automatically.
   *
   * If the source rectangle overlaps the destination rectangle on the
   * same pixbuf, it will be overwritten during the copy operation.
   * Therefore, you can not use this function to scroll a pixbuf.
   *
   * @param src_x Source X coordinate within @a src_pixbuf.
   * @param src_y Source Y coordinate within @a src_pixbuf.
   * @param width Width of the area to copy.
   * @param height Height of the area to copy.
   * @param dest_pixbuf Destination pixbuf.
   * @param dest_x X coordinate within @a dest_pixbuf.
   * @param dest_y Y coordinate within @a dest_pixbuf.
   */
  void copy_area(int src_x, int src_y, int width, int height, const Glib::RefPtr<Gdk::Pixbuf>& dest_pixbuf, int dest_x, int dest_y) const;


  /** Modifies saturation and optionally pixelates `src`, placing the result in
   * `dest`.
   *
   * The `src` and `dest` pixbufs must have the same image format, size, and
   * rowstride.
   *
   * The `src` and `dest` arguments may be the same pixbuf with no ill effects.
   *
   * If `saturation` is 1.0 then saturation is not changed. If it's less than 1.0,
   * saturation is reduced (the image turns toward grayscale); if greater than
   * 1.0, saturation is increased (the image gets more vivid colors).
   *
   * If `pixelate` is <tt>true</tt>, then pixels are faded in a checkerboard pattern to
   * create a pixelated image.
   *
   * @param dest Place to write modified version of @a src.
   * @param saturation Saturation factor.
   * @param pixelate Whether to pixelate.
   */
  void saturate_and_pixelate(const Glib::RefPtr<Gdk::Pixbuf>& dest, float saturation, bool pixelate) const;


  /** Creates a transformation of the source image @a src by scaling by
   *  @a scale_x and @a scale_y then translating by @a offset_x and @a offset_y,
   * then renders the rectangle ( @a dest_x, @a dest_y, @a dest_width,
   *  @a dest_height) of the resulting image onto the destination image
   * replacing the previous contents.
   *
   * Try to use scale_simple() first; this function is
   * the industrial-strength power tool you can fall back to, if
   * scale_simple() isn't powerful enough.
   *
   * If the source rectangle overlaps the destination rectangle on the
   * same pixbuf, it will be overwritten during the scaling which
   * results in rendering artifacts.
   *
   * @param dest The Gdk::Pixbuf into which to render the results.
   * @param dest_x The left coordinate for region to render.
   * @param dest_y The top coordinate for region to render.
   * @param dest_width The width of the region to render.
   * @param dest_height The height of the region to render.
   * @param offset_x The offset in the X direction (currently rounded to an integer).
   * @param offset_y The offset in the Y direction (currently rounded to an integer).
   * @param scale_x The scale factor in the X direction.
   * @param scale_y The scale factor in the Y direction.
   * @param interp_type The interpolation type for the transformation.
   */
  void scale(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type) const;


  /** Creates a transformation of the source image @a src by scaling by
   *  @a scale_x and @a scale_y then translating by @a offset_x and @a offset_y.
   *
   * This gives an image in the coordinates of the destination pixbuf.
   * The rectangle ( @a dest_x, @a dest_y, @a dest_width, @a dest_height)
   * is then alpha blended onto the corresponding rectangle of the
   * original destination image.
   *
   * When the destination rectangle contains parts not in the source
   * image, the data at the edges of the source image is replicated
   * to infinity.
   *
   * ![](composite.png)
   *
   * @param dest The Gdk::Pixbuf into which to render the results.
   * @param dest_x The left coordinate for region to render.
   * @param dest_y The top coordinate for region to render.
   * @param dest_width The width of the region to render.
   * @param dest_height The height of the region to render.
   * @param offset_x The offset in the X direction (currently rounded to an integer).
   * @param offset_y The offset in the Y direction (currently rounded to an integer).
   * @param scale_x The scale factor in the X direction.
   * @param scale_y The scale factor in the Y direction.
   * @param interp_type The interpolation type for the transformation.
   * @param overall_alpha Overall alpha for source image (0..255).
   */
  void composite(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type, int overall_alpha) const;


  /** Creates a transformation of the source image @a src by scaling by
   *  @a scale_x and @a scale_y then translating by @a offset_x and @a offset_y,
   * then alpha blends the rectangle ( @a dest_x , @a dest_y, @a dest_width,
   *  @a dest_height) of the resulting image with a checkboard of the
   * colors @a color1 and @a color2 and renders it onto the destination
   * image.
   *
   * If the source image has no alpha channel, and @a overall_alpha is 255, a fast
   * path is used which omits the alpha blending and just performs the scaling.
   *
   * See composite_color_simple() for a simpler variant of this
   * function suitable for many tasks.
   *
   * @param dest The Gdk::Pixbuf into which to render the results.
   * @param dest_x The left coordinate for region to render.
   * @param dest_y The top coordinate for region to render.
   * @param dest_width The width of the region to render.
   * @param dest_height The height of the region to render.
   * @param offset_x The offset in the X direction (currently rounded to an integer).
   * @param offset_y The offset in the Y direction (currently rounded to an integer).
   * @param scale_x The scale factor in the X direction.
   * @param scale_y The scale factor in the Y direction.
   * @param interp_type The interpolation type for the transformation.
   * @param overall_alpha Overall alpha for source image (0..255).
   * @param check_x The X offset for the checkboard (origin of checkboard is at - @a check_x, - @a check_y).
   * @param check_y The Y offset for the checkboard.
   * @param check_size The size of checks in the checkboard (must be a power of two).
   * @param color1 The color of check at upper left.
   * @param color2 The color of the other check.
   */
  void composite_color(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type, int overall_alpha, int check_x, int check_y, int check_size, guint32 color1, guint32 color2) const;


  /** Create a new pixbuf containing a copy of `src` scaled to
   * `dest_width` x `dest_height`.
   *
   * This function leaves `src` unaffected.
   *
   * The `interp_type` should be `Gdk::InterpType::NEAREST` if you want maximum
   * speed (but when scaling down `Gdk::InterpType::NEAREST` is usually unusably
   * ugly). The default `interp_type` should be `Gdk::InterpType::BILINEAR` which
   * offers reasonable quality and speed.
   *
   * You can scale a sub-portion of `src` by creating a sub-pixbuf
   * pointing into `src`; see GdkPixbuf::Pixbuf::new_subpixbuf().
   *
   * If `dest_width` and `dest_height` are equal to the width and height of
   * `src`, this function will return an unscaled copy of `src`.
   *
   * For more complicated scaling/alpha blending see GdkPixbuf::Pixbuf::scale()
   * and GdkPixbuf::Pixbuf::composite().
   *
   * @param dest_width The width of destination image.
   * @param dest_height The height of destination image.
   * @param interp_type The interpolation type for the transformation.
   * @return The new pixbuf.
   */
  auto scale_simple(int dest_width, int dest_height, InterpType interp_type) const -> Glib::RefPtr<Gdk::Pixbuf>;


  /** Creates a new pixbuf by scaling `src` to `dest_width` x `dest_height`
   * and alpha blending the result with a checkboard of colors `color1`
   * and `color2`.
   *
   * @param dest_width The width of destination image.
   * @param dest_height The height of destination image.
   * @param interp_type The interpolation type for the transformation.
   * @param overall_alpha Overall alpha for source image (0..255).
   * @param check_size The size of checks in the checkboard (must be a power of two).
   * @param color1 The color of check at upper left.
   * @param color2 The color of the other check.
   * @return The new pixbuf.
   */
  auto composite_color_simple(int dest_width, int dest_height, InterpType interp_type, int overall_alpha, int check_size, guint32 color1, guint32 color2) const -> Glib::RefPtr<Gdk::Pixbuf>;


  /** Rotates a pixbuf by a multiple of 90 degrees, and returns the
   * result in a new pixbuf.
   *
   * If `angle` is 0, this function will return a copy of `src`.
   *
   * @newin{2,6}
   *
   * @param angle The angle to rotate by.
   * @return The new pixbuf.
   */
  auto rotate_simple(Rotation angle) const -> Glib::RefPtr<Gdk::Pixbuf>;

  /** Flips a pixbuf horizontally or vertically and returns the
   * result in a new pixbuf.
   *
   * @newin{2,6}
   *
   * @param horizontal <tt>true</tt> to flip horizontally, <tt>false</tt> to flip vertically.
   * @return The new pixbuf.
   */
  auto flip(bool horizontal =  true) const -> Glib::RefPtr<Gdk::Pixbuf>;


  /** Looks up @a key in the list of options that may have been attached to the
   *  @a pixbuf when it was loaded, or that may have been attached by another
   * function using set_option().
   *
   * For instance, the ANI loader provides "Title" and "Artist" options.
   * The ICO, XBM, and XPM loaders provide "x_hot" and "y_hot" hot-spot
   * options for cursor definitions. The PNG loader provides the tEXt ancillary
   * chunk key/value pairs as options. Since 2.12, the TIFF and JPEG loaders
   * return an "orientation" option string that corresponds to the embedded
   * TIFF/Exif orientation tag (if present). Since 2.32, the TIFF loader sets
   * the "multipage" option string to "yes" when a multi-page TIFF is loaded.
   * Since 2.32 the JPEG and PNG loaders set "x-dpi" and "y-dpi" if the file
   * contains image density information in dots per inch.
   * Since 2.36.6, the JPEG loader sets the "comment" option with the comment
   * EXIF tag.
   *
   * @param key A nul-terminated string.
   * @return The value associated with `key`.
   */
  auto get_option(const Glib::ustring& key) const -> Glib::ustring;

  /** Attaches a key/value pair as an option to a `Gdk::Pixbuf`.
   *
   * If `key` already exists in the list of options attached to the `pixbuf`,
   * the new value is ignored and <tt>false</tt> is returned.
   *
   * @newin{2,2}
   *
   * @param key A nul-terminated string.
   * @param value A nul-terminated string.
   * @return <tt>true</tt> on success.
   */
  auto set_option(const Glib::ustring& key, const Glib::ustring& value) -> bool;

  /** Removes the key/value pair option attached to a `Gdk::Pixbuf`.
   *
   * @newin{2,36}
   *
   * @param key A nul-terminated string representing the key to remove.
   * @return <tt>true</tt> if an option was removed, <tt>false</tt> if not.
   */
  auto remove_option(const Glib::ustring& key) -> bool;

  /** Copies the key/value pair options attached to a `Gdk::Pixbuf` to another
   * `Gdk::Pixbuf`.
   *
   * This is useful to keep original metadata after having manipulated
   * a file. However be careful to remove metadata which you've already
   * applied, such as the "orientation" option after rotating the image.
   *
   * @newin{2,36}
   *
   * @param dest_pixbuf The destination pixbuf.
   * @return <tt>true</tt> on success.
   */
  auto copy_options(const Glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool;

  //This creates a new GdkPixbuf or returns the original with a reference.

  /** Takes an existing pixbuf and checks for the presence of an
   * associated "orientation" option.
   *
   * The orientation option may be provided by the JPEG loader (which
   * reads the exif orientation tag) or the TIFF loader (which reads
   * the TIFF orientation tag, and compensates it for the partial
   * transforms performed by libtiff).
   *
   * If an orientation option/tag is present, the appropriate transform
   * will be performed so that the pixbuf is oriented correctly.
   *
   * @newin{2,12}
   *
   * @return A newly-created pixbuf.
   */
  auto apply_embedded_orientation() -> Glib::RefPtr<Pixbuf>;

  /** Obtains the available information about the image formats supported by GdkPixbuf.
   * @result A list of PixbufFormats describing the supported image formats.
   */
  static auto get_formats() -> std::vector<PixbufFormat>;


  /** The color space of the pixbuf.
   *
   * Currently, only `Gdk::Colorspace::RGB` is supported.
   *
   * Default value: Gdk::Colorspace::RGB
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_colorspace() const -> Glib::PropertyProxy_ReadOnly< Colorspace >;


  /** The number of samples per pixel.
   *
   * Currently, only 3 or 4 samples per pixel are supported.
   *
   * Default value: 3
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_channels() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Whether the pixbuf has an alpha channel.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_alpha() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The number of bits per sample.
   *
   * Currently only 8 bit per sample are supported.
   *
   * Default value: 8
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_bits_per_sample() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The number of columns of the pixbuf.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The number of rows of the pixbuf.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The number of bytes between the start of a row and
   * the start of the next row.
   *
   * This number must (obviously) be at least as large as the
   * width of the pixbuf.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rowstride() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** A pointer to the pixel data of the pixbuf.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_pixels() const -> Glib::PropertyProxy_ReadOnly< void* >;


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
class GDKMM_API Value<Gdk::Pixbuf::Rotation> : public Glib::Value_Enum<Gdk::Pixbuf::Rotation>
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
   * @relates Gdk::Pixbuf
   */
  GDKMM_API
  auto wrap(GdkPixbuf* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Pixbuf>;
}


#endif /* _GDKMM_PIXBUF_H */

