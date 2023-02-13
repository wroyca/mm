
#ifndef _GDKMM_PIXBUFLOADER_H
#define _GDKMM_PIXBUFLOADER_H


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

#include <libmm-glib/object.hxx>
#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/pixbufanimation.hxx>
#include <libmm-gdk/pixbufformat.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufLoader = struct _GdkPixbufLoader;
using GdkPixbufLoaderClass = struct _GdkPixbufLoaderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API PixbufLoader_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{


class GDKMM_API PixbufLoader : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PixbufLoader;
  using CppClassType = PixbufLoader_Class;
  using BaseObjectType = GdkPixbufLoader;
  using BaseClassType = GdkPixbufLoaderClass;

  // noncopyable
  PixbufLoader(const PixbufLoader&) = delete;
  auto operator=(const PixbufLoader&) -> PixbufLoader& = delete;

private:  friend class PixbufLoader_Class;
  static CppClassType pixbufloader_class_;

protected:
  explicit PixbufLoader(const Glib::ConstructParams& construct_params);
  explicit PixbufLoader(GdkPixbufLoader* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PixbufLoader(PixbufLoader&& src) noexcept;
  auto operator=(PixbufLoader&& src) noexcept -> PixbufLoader&;

  ~PixbufLoader() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkPixbufLoader*       { return reinterpret_cast<GdkPixbufLoader*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkPixbufLoader* { return reinterpret_cast<GdkPixbufLoader*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkPixbufLoader*;

private:

protected:

  /** Constructs a pixbuf loader object.
   */
  PixbufLoader();

  /** Constructs a pixbuf loader object for a specific image type.
   * Constructs a new pixbuf loader object that always attempts to parse image
   * data as if it were an image of type @a image_type, instead of identifying
   * the type automatically. Useful if you want an error if the image isn't the
   * expected type, for loading image formats that can't be reliably identified
   * by looking at the data, or if the user manually forces a specific type.
   *
   * The image_type can be one of the types returned by Gdk::Pixbuf::get_formats(), or a MIME type.
   *
   * Common MIME Types are listed here
   * http://www.iana.org/assignments/media-types/
   * and here:
   * http://www.freedesktop.org/Software/shared-mime-info
   *
   * The list of non-mime-type image formats depends on what image loaders
   * are installed, but typically "png", "jpeg", "gif", "tiff" and
   * "xpm" are among the supported formats. To obtain the full list of
   * supported image formats, call PixbufFormat::get_name() on each
   * of the PixbufFormats returned by Gdk::Pixbuf::get_formats().
   *
   * @param image_type Name of the image format to be loaded with the image.
   * @param mime_type If this is true then the image_type is a MIME type.
   * @throw Gdk::PixbufError
   */
  explicit PixbufLoader(const Glib::ustring& image_type, bool mime_type = false);

public:

  /** Creates a new pixbuf loader object.
   * @return A newly-created pixbuf loader.
   */

  static auto create() -> Glib::RefPtr<PixbufLoader>;


   /** Constructs a pixbuf loader object for a specific image type.
   * Constructs a new pixbuf loader object that always attempts to parse image
   * data as if it were an image of type @a image_type, instead of identifying
   * the type automatically. Useful if you want an error if the image isn't the
   * expected type, for loading image formats that can't be reliably identified
   * by looking at the data, or if the user manually forces a specific type.
   *
   * The image_type can be one of the types returned by Gdk::Pixbuf::get_formats(), or a MIME type.
   *
   * Common MIME Types are listed here
   * http://www.iana.org/assignments/media-types/
   * and here:
   * http://www.freedesktop.org/Software/shared-mime-info
   *
   * The list of non-mime-type image formats depends on what image loaders
   * are installed, but typically "png", "jpeg", "gif", "tiff" and
   * "xpm" are among the supported formats. To obtain the full list of
   * supported image formats, call PixbufFormat::get_name() on each
   * of the PixbufFormats returned by Gdk::Pixbuf::get_formats().
   *
   * @param image_type Name of the image format to be loaded with the image.
   * @param mime_type If this is true then the image_type is a MIME type.
   * @throw Gdk::PixbufError
   */

  static auto create(const Glib::ustring& image_type, bool mime_type =  false) -> Glib::RefPtr<PixbufLoader>;


  /** Causes the image to be scaled while it is loaded.
   *
   * The desired image size can be determined relative to the original
   * size of the image by calling set_size() from a
   * signal handler for the signal_size_prepared() signal.
   *
   * Attempts to set the desired image size  are ignored after the
   * emission of the signal_size_prepared() signal.
   *
   * @newin{2,2}
   *
   * @param width The desired width of the image being loaded.
   * @param height The desired height of the image being loaded.
   */
  void set_size(int width, int height);


  /** Causes the pixbuf loader to parse the next @a count bytes of an image.
   * It will return if the data was loaded successfully, and throw an exception
   * if an error occurred. In the latter case, the loader will be closed, and
   * will not accept further writes.
   * @param buf Pointer to image data.
   * @param count Length of the @a buf buffer in bytes.
   * @throw Gdk::PixbufError
   * @throw Glib::FileError
   */
  void write(const guint8* buf, gsize count);


  /** Informs a pixbuf loader that no further writes with PixbufLoader::write()
   * will occur, so that it can free its internal loading structures.  Also,
   * tries to parse any data that hasn't yet been parsed; if the remaining data
   * is partial or corrupt, an exception will be thrown. If you're just
   * cancelling a load rather than expecting it to be finished, writing an
   * empty <tt>catch()</tt> block to ignore errors is reasonable.
   * @throw Gdk::PixbufError
   * @throw Glib::FileError
   */
  void close();


  /** Queries the Gdk::Pixbuf that a pixbuf loader is currently creating.
   *
   * In general it only makes sense to call this function after the
   * GdkPixbuf::PixbufLoader::signal_area_prepared() signal has been
   * emitted by the loader; this means that enough data has been read
   * to know the size of the image that will be allocated.
   *
   * If the loader has not received enough data via write(),
   * then this function returns <tt>nullptr</tt>.
   *
   * The returned pixbuf will be the same in all future calls to the loader,
   * so if you want to keep using it, you should acquire a reference to it.
   *
   * Additionally, if the loader is an animation, it will return the "static
   * image" of the animation (see Gdk::PixbufAnimation::get_static_image()).
   *
   * @return The pixbuf that the loader is
   * creating.
   */
  auto get_pixbuf() -> Glib::RefPtr<Gdk::Pixbuf>;

  /** Queries the Gdk::PixbufAnimation that a pixbuf loader is currently creating.
   *
   * In general it only makes sense to call this function after the
   * GdkPixbuf::PixbufLoader::signal_area_prepared() signal has been emitted by
   * the loader.
   *
   * If the loader doesn't have enough bytes yet, and hasn't emitted the `area-prepared`
   * signal, this function will return <tt>nullptr</tt>.
   *
   * @return The animation that the loader is
   * currently loading.
   */
  auto get_animation() -> Glib::RefPtr<Gdk::PixbufAnimation>;


  /** Obtains the available information about the format of the
   * currently loading image file.
   *
   * @newin{2,2}
   *
   * @return A Gdk::PixbufFormat.
   */
  auto get_format() const -> PixbufFormat;


  /** This signal is emitted when the pixbuf loader has allocated the
   * pixbuf in the desired size.  After this signal is emitted,
   * applications can call get_pixbuf() to fetch
   * the partially-loaded pixbuf.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%area_prepared()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when the pixbuf loader has allocated the
   * pixbuf in the desired size.
   *
   * After this signal is emitted, applications can call
   * Gdk::PixbufLoader::get_pixbuf() to fetch the partially-loaded
   * pixbuf.
   */

  auto signal_area_prepared() -> Glib::SignalProxy<void()>;


  /** This signal is emitted when a significant area of the image being
   * loaded has been updated.  Normally it means that a complete
   * scanline has been read in, but it could be a different area as
   * well.  Applications can use this signal to know when to repaint
   * areas of an image that is being loaded.
   *
   * @param X offset of upper-left corner of the updated area.
   * @param y Y offset of upper-left corner of the updated area.
   * @param width Width of updated area.
   * @param height Height of updated area.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%area_updated(int x, int y, int width, int height)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when a significant area of the image being
   * loaded has been updated.
   *
   * Normally it means that a complete scanline has been read in, but
   * it could be a different area as well.
   *
   * Applications can use this signal to know when to repaint
   * areas of an image that is being loaded.
   *
   * @param x X offset of upper-left corner of the updated area.
   * @param y Y offset of upper-left corner of the updated area.
   * @param width Width of updated area.
   * @param height Height of updated area.
   */

  auto signal_area_updated() -> Glib::SignalProxy<void(int, int, int, int)>;


  /** This signal is emitted when close() is called.
   * It can be used by different parts of an application to receive
   * notification when an image loader is closed by the code that
   * drives it.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%closed()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when Gdk::PixbufLoader::close() is called.
   *
   * It can be used by different parts of an application to receive
   * notification when an image loader is closed by the code that
   * drives it.
   */

  auto signal_closed() -> Glib::SignalProxy<void()>;


  /** This signal is emitted when the pixbuf loader has been fed the
   * initial amount of data that is required to figure out the size
   * of the image that it will create.  Applications can call
   * set_size() in response to this signal to set
   * the desired size to which the image should be scaled.
   *
   * @param width The original width of the image.
   * @param height The original height of the image
   *
   * @par Slot Prototype:
   * <tt>void on_my_%size_prepared(int width, int height)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when the pixbuf loader has been fed the
   * initial amount of data that is required to figure out the size
   * of the image that it will create.
   *
   * Applications can call Gdk::PixbufLoader::set_size() in response
   * to this signal to set the desired size to which the image
   * should be scaled.
   *
   * @param width The original width of the image.
   * @param height The original height of the image.
   */

  auto signal_size_prepared() -> Glib::SignalProxy<void(int, int)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_area_prepared().
  virtual void on_area_prepared();
  /// This is a default handler for the signal signal_area_updated().
  virtual void on_area_updated(int x, int y, int width, int height);
  /// This is a default handler for the signal signal_closed().
  virtual void on_closed();
  /// This is a default handler for the signal signal_size_prepared().
  virtual void on_size_prepared(int width, int height);


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
   * @relates Gdk::PixbufLoader
   */
  GDKMM_API
  auto wrap(GdkPixbufLoader* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PixbufLoader>;
}


#endif /* _GDKMM_PIXBUFLOADER_H */

