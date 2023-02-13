
#ifndef _GDKMM_TEXTURE_H
#define _GDKMM_TEXTURE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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

#include <libmm-glib/object.hpp>
#include <libmm-gdk/paintable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkTexture = struct _GdkTexture;
using GdkTextureClass = struct _GdkTextureClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Texture_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{
class GDKMM_API Bytes;
}
namespace Gio
{
class GDKMM_API File;
}

namespace Gdk
{
class GDKMM_API Pixbuf;

class TextureError : public Glib::Error
{
public:
  /**  @var Code TOO_LARGE
   * Not enough memory to handle this image.
   *
   *  @var Code CORRUPT_IMAGE
   * The image data appears corrupted.
   *
   *  @var Code UNSUPPORTED_CONTENT
   * The image contains features
   * that cannot be loaded.
   *
   *  @var Code UNSUPPORTED_FORMAT
   * The image format is not supported.
   *
   *  @enum Code
   *
   * Possible errors that can be returned by `Gdk::Texture` constructors.
   *
   * @newin{4,6}
   */
  enum Code
  {
    TOO_LARGE,
    CORRUPT_IMAGE,
    UNSUPPORTED_CONTENT,
    UNSUPPORTED_FORMAT
  };

  GDKMM_API TextureError(Code error_code, const Glib::ustring& error_message);
  GDKMM_API explicit TextureError(GError* gobject);
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
class GDKMM_API Value<Gdk::TextureError::Code> : public Glib::Value_Enum<Gdk::TextureError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** Pixel data.
 *
 * %Gdk::Texture is the basic element used to refer to pixel data.
 * It is primarily meant for pixel data that will not change over
 * multiple frames, and will be used for a long time.
 *
 * There are various ways to create %Gdk::Texture objects from a
 * Gdk::Pixbuf, or a %Cairo surface, or other pixel data.
 *
 * The ownership of the pixel data is transferred to the %Gdk::Texture
 * instance; you can only make a copy of it, via download().
 *
 * %Gdk::Texture is an immutable object: That means you cannot change
 * anything about it.
 *
 * @newin{3,94}
 */

class GDKMM_API Texture : public Glib::Object, public Paintable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Texture;
  using CppClassType = Texture_Class;
  using BaseObjectType = GdkTexture;
  using BaseClassType = GdkTextureClass;

  // noncopyable
  Texture(const Texture&) = delete;
  auto operator=(const Texture&) -> Texture& = delete;

private:  friend class Texture_Class;
  static CppClassType texture_class_;

protected:
  explicit Texture(const Glib::ConstructParams& construct_params);
  explicit Texture(GdkTexture* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Texture(Texture&& src) noexcept;
  auto operator=(Texture&& src) noexcept -> Texture&;

  ~Texture() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkTexture*       { return reinterpret_cast<GdkTexture*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkTexture* { return reinterpret_cast<GdkTexture*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkTexture*;

private:


protected:
  Texture();

public:
  // All gdk_texture_new_*() functions do more than call g_object_new().

  /** Creates a new texture object representing the `Gdk::Pixbuf`.
   *
   * This function is threadsafe, so that you can e.g. use GTask
   * and Gio::Task::run_in_thread() to avoid blocking the main thread
   * while loading a big image.
   *
   * @param pixbuf A `Gdk::Pixbuf`.
   * @return A new `Gdk::Texture`.
   */
  static auto create_for_pixbuf(const Glib::RefPtr<Pixbuf>& pixbuf) -> Glib::RefPtr<Texture>;

  /** Creates a new texture by loading an image from a resource.
   *
   * The file format is detected automatically. The supported formats
   * are PNG and JPEG, though more formats might be available.
   *
   * It is a fatal error if @a resource_path does not specify a valid
   * image resource and the program will abort if that happens.
   * If you are unsure about the validity of a resource, use
   * new_from_file() to load it.
   *
   * This function is threadsafe, so that you can e.g. use GTask
   * and Gio::Task::run_in_thread() to avoid blocking the main thread
   * while loading a big image.
   *
   * @param resource_path The path of the resource file.
   * @return A newly-created `Gdk::Texture`.
   */
  static auto create_from_resource(const std::string& resource_path) -> Glib::RefPtr<Texture>;

  /** Creates a new texture by loading an image from a file.
   *
   * The file format is detected automatically. The supported formats
   * are PNG and JPEG, though more formats might be available.
   *
   * If <tt>nullptr</tt> is returned, then @a error will be set.
   *
   * This function is threadsafe, so that you can e.g. use GTask
   * and Gio::Task::run_in_thread() to avoid blocking the main thread
   * while loading a big image.
   *
   * @param file `File` to load.
   * @return A newly-created `Gdk::Texture`.
   *
   * @throws Glib::Error
   */
  static auto create_from_file(const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<Texture>;

  /** Creates a new texture by loading an image from a file.
   *
   * The file format is detected automatically. The supported formats
   * are PNG and JPEG, though more formats might be available.
   *
   * If <tt>nullptr</tt> is returned, then @a error will be set.
   *
   * This function is threadsafe, so that you can e.g. use GTask
   * and Gio::Task::run_in_thread() to avoid blocking the main thread
   * while loading a big image.
   *
   * @newin{4,6}
   *
   * @param path The filename to load.
   * @return A newly-created `Gdk::Texture`.
   *
   * @throws Glib::Error
   */
  static auto create_from_filename(const std::string& path) -> Glib::RefPtr<Texture>;

  /** Creates a new texture by loading an image from memory,
   *
   * The file format is detected automatically. The supported formats
   * are PNG and JPEG, though more formats might be available.
   *
   * If <tt>nullptr</tt> is returned, then @a error will be set.
   *
   * This function is threadsafe, so that you can e.g. use GTask
   * and Gio::Task::run_in_thread() to avoid blocking the main thread
   * while loading a big image.
   *
   * @newin{4,6}
   *
   * @param bytes A `Glib::Bytes` containing the data to load.
   * @return A newly-created `Gdk::Texture`.
   *
   * @throws Glib::Error
   */
  static auto create_from_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes) -> Glib::RefPtr<Texture>;


  /** Returns the width of @a texture, in pixels.
   *
   * @return The width of the `Gdk::Texture`.
   */
  auto get_width() const -> int;

  /** Returns the height of the @a texture, in pixels.
   *
   * @return The height of the `Gdk::Texture`.
   */
  auto get_height() const -> int;

  /** Downloads the @a texture into local memory.
   *
   * This may be an expensive operation, as the actual texture data
   * may reside on a GPU or on a remote display server.
   *
   * The data format of the downloaded data is equivalent to
   * Cairo::Surface::Format::ARGB32, so every downloaded pixel requires
   * 4 bytes of memory.
   *
   * Downloading a texture into a Cairo image surface:
   *
   * [C example ellipted]
   *
   * @param data Pointer to enough memory to be filled with the
   * downloaded data of @a texture.
   * @param stride Rowstride in bytes.
   */
  void download(guchar* data, gsize stride) const;
  //TODO: When we can break ABI, change to const std::string& filename

  /** Store the given @a texture to the @a filename as a PNG file.
   *
   * This is a utility function intended for debugging and testing.
   * If you want more control over formats, proper error handling or
   * want to store to a Gio::File or other location, you might want to
   * use save_to_png_bytes() or look into the
   * gdk-pixbuf library.
   *
   * @param filename The filename to store to.
   * @return <tt>true</tt> if saving succeeded, <tt>false</tt> on failure.
   */
  auto save_to_png(const Glib::ustring& filename) const -> bool;

  /** Store the given @a texture in memory as a PNG file.
   *
   * Use new_from_bytes() to read it back.
   *
   * If you want to serialize a texture, this is a convenient and
   * portable way to do that.
   *
   * If you need more control over the generated image, such as
   * attaching metadata, you should look into an image handling
   * library such as the gdk-pixbuf library.
   *
   * If you are dealing with high dynamic range float data, you
   * might also want to consider save_to_tiff_bytes()
   * instead.
   *
   * @newin{4,6}
   *
   * @return A newly allocated `Glib::Bytes` containing PNG data.
   */
  auto save_to_png_bytes() const -> Glib::RefPtr<Glib::Bytes>;

  /** Store the given @a texture to the @a filename as a TIFF file.
   *
   * GTK will attempt to store data without loss.
   * @newin{4,6}
   *
   * @param filename The filename to store to.
   * @return <tt>true</tt> if saving succeeded, <tt>false</tt> on failure.
   */
  auto save_to_tiff(const std::string& filename) const -> bool;

  /** Store the given @a texture in memory as a TIFF file.
   *
   * Use new_from_bytes() to read it back.
   *
   * This function is intended to store a representation of the
   * texture's data that is as accurate as possible. This is
   * particularly relevant when working with high dynamic range
   * images and floating-point texture data.
   *
   * If that is not your concern and you are interested in a
   * smaller size and a more portable format, you might want to
   * use save_to_png_bytes().
   *
   * @newin{4,6}
   *
   * @return A newly allocated `Glib::Bytes` containing TIFF data.
   */
  auto save_to_tiff_bytes() const -> Glib::RefPtr<Glib::Bytes>;

  /** The width of the texture, in pixels.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_width() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The height of the texture, in pixels.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_height() const -> Glib::PropertyProxy_ReadOnly< int >;


  // There are no public signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Texture
   */
  GDKMM_API
  auto wrap(GdkTexture* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Texture>;
}


#endif /* _GDKMM_TEXTURE_H */

