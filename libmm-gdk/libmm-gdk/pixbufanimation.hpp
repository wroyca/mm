
#ifndef _GDKMM_PIXBUFANIMATION_H
#define _GDKMM_PIXBUFANIMATION_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <mm/glib/object.hpp>
#include <mm/gio/asyncresult.hpp>
#include <mm/gdk/pixbuf.hpp>
#include <mm/gdk/pixbufanimationiter.hpp>
#include <gdk-pixbuf/gdk-pixbuf.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufAnimation = struct _GdkPixbufAnimation;
using GdkPixbufAnimationClass = struct _GdkPixbufAnimationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API PixbufAnimation_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

/** The gdk-pixbuf library provides a simple mechanism to load and represent animations.
 * An animation is conceptually a series of frames to be displayed over time.
 * Each frame is the same size. The animation may not be represented as a series of frames internally;
 * for example, it may be stored as a sprite and instructions for moving the sprite around a background.
 * To display an animation you don't need to understand its representation, however; you just ask
 * gdk-pixbuf what should be displayed at a given point in time.
 */

class GDKMM_API PixbufAnimation : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = PixbufAnimation;
  using CppClassType = PixbufAnimation_Class;
  using BaseObjectType = GdkPixbufAnimation;
  using BaseClassType = GdkPixbufAnimationClass;

  // noncopyable
  PixbufAnimation(const PixbufAnimation&) = delete;
  auto operator=(const PixbufAnimation&) -> PixbufAnimation& = delete;

private:  friend class PixbufAnimation_Class;
  static CppClassType pixbufanimation_class_;

protected:
  explicit PixbufAnimation(const Glib::ConstructParams& construct_params);
  explicit PixbufAnimation(GdkPixbufAnimation* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  PixbufAnimation(PixbufAnimation&& src) noexcept;
  auto operator=(PixbufAnimation&& src) noexcept -> PixbufAnimation&;

  ~PixbufAnimation() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkPixbufAnimation*       { return reinterpret_cast<GdkPixbufAnimation*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkPixbufAnimation* { return reinterpret_cast<GdkPixbufAnimation*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkPixbufAnimation*;

private:


protected:

public:

  /** Creates a new animation by loading it from a file.
   *
   * The file format is detected automatically.
   *
   * If the file's format does not support multi-frame images, then an animation
   * with a single frame will be created.
   *
   * Possible errors are in the `GDK_PIXBUF_ERROR` and `G_FILE_ERROR` domains.
   *
   * @param filename Name of file to load, in the GLib file
   * name encoding.
   * @return A newly-created animation.
   *
   * @throws Glib::Error
   */
  static auto create_from_file(const std::string& filename) -> Glib::RefPtr<PixbufAnimation>;

  /** Creates a new animation by loading it from an input stream.
   *
   * The file format is detected automatically.
   *
   * If <tt>nullptr</tt> is returned, then @a error will be set.
   *
   * The @a cancellable can be used to abort the operation from another thread.
   * If the operation was cancelled, the error `Gio::Error::CANCELLED` will be
   * returned. Other possible errors are in the `GDK_PIXBUF_ERROR` and
   * `G_IO_ERROR` domains.
   *
   * The stream is not closed.
   *
   * @newin{4,4}
   *
   * @param stream A `Gio::InputStream` to load the pixbuf from.
   * @param cancellable Optional `Gio::Cancellable` object.
   * @return A newly-created animation.
   *
   * @throws Glib::Error
   */
  static auto create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream, const Glib::RefPtr<Gio::Cancellable>& cancellable =  {}) -> Glib::RefPtr<PixbufAnimation>;

  /** Creates a new animation by asynchronously loading an image from an input stream.
   *
   * For more details see new_from_stream(), which is the synchronous
   * version of this function.
   *
   * When the operation is finished, `callback` will be called in the main thread.
   * You can then call new_from_stream_finish() to get the
   * result of the operation.
   *
   * @newin{4,4}
   *
   * @param stream A Gio::InputStream from which to load the animation.
   * @param cancellable Optional Gio::Cancellable object.
   * @param slot A `SlotAsyncReady` to call when the pixbuf is loaded.
   */
  static void create_from_stream_async(const Glib::RefPtr<Gio::InputStream>& stream, const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable =  {});

  /** Finishes an asynchronous pixbuf animation creation operation started with
   * gdk_pixbuf_pixbuf_animation_new_from_stream_async().
   *
   * @newin{4,4}
   *
   * @param result A Gio::AsyncResult.
   * @return The newly created animation.
   *
   * @throws Glib::Error
   */
  static auto create_from_stream_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::RefPtr<PixbufAnimation>;

  /** Creates a new pixbuf animation by loading an image from an resource.
   *
   * The file format is detected automatically. If <tt>nullptr</tt> is returned, then
   *  @a error will be set.
   *
   * @newin{4,4}
   *
   * @param resource_path The path of the resource file.
   * @return A newly-created animation.
   *
   * @throws Glib::Error
   */
  static auto create_from_resource(const std::string& resource_path) -> Glib::RefPtr<PixbufAnimation>;


  /** Queries the width of the bounding box of a pixbuf animation.
   *
   * @return Width of the bounding box of the animation.
   */
  auto get_width() const -> int;

  /** Queries the height of the bounding box of a pixbuf animation.
   *
   * @return Height of the bounding box of the animation.
   */
  auto get_height() const -> int;

  /** Checks whether the animation is a static image.
   *
   * If you load a file with new_from_file() and it
   * turns out to be a plain, unanimated image, then this function will
   * return <tt>true</tt>. Use get_static_image() to retrieve
   * the image.
   *
   * @return <tt>true</tt> if the "animation" was really just an image.
   */
  auto is_static_image() const -> bool;

  /** Retrieves a static image for the animation.
   *
   * If an animation is really just a plain image (has only one frame),
   * this function returns that image.
   *
   * If the animation is an animation, this function returns a reasonable
   * image to use as a static unanimated image, which might be the first
   * frame, or something more sophisticated depending on the file format.
   *
   * If an animation hasn't loaded any frames yet, this function will
   * return <tt>nullptr</tt>.
   *
   * @return Unanimated image representing the animation.
   */
  auto get_static_image() -> Glib::RefPtr<Pixbuf>;

  /** Get an iterator for displaying an animation.
   * The iterator provides the frames that should be displayed at a given time.
   *
   * @a start_time would normally come from g_get_real_time(), and marks
   * the beginning of animation playback. After creating an iterator, you
   * should immediately display the pixbuf returned by
   * Gdk::PixbufAnimationIter::get_pixbuf(). Then, you should install
   * a timeout (with Glib::signal_timeout().connect()) or by some other mechanism
   * ensure that you'll update the image after
   * Gdk::PixbufAnimationIter::get_delay_time() milliseconds. Each time
   * the image is updated, you should reinstall the timeout with the new,
   * possibly-changed delay time.
   *
   * As a shortcut, the default value of @a start_time is g_get_real_time().
   *
   * To update the image (i.e. possibly change the result of
   * Gdk::PixbufAnimationIter::get_pixbuf() to a new frame of the animation),
   * call Gdk::PixbufAnimationIter::advance().
   *
   * If you're using Gdk::PixbufLoader, in addition to updating the image
   * after the delay time, you should also update it whenever you
   * receive the area_updated signal and
   * Gdk::PixbufAnimationIter::on_currently_loading_frame() returns
   * <tt>true</tt>. In this case, the frame currently being fed into the loader
   * has received new data, so needs to be refreshed. The delay time for
   * a frame may also be modified after an area_updated signal, for
   * example if the delay time for a frame is encoded in the data after
   * the frame itself. So your timeout should be reinstalled after any
   * area_updated signal.
   *
   * A delay time of -1 is possible, indicating "infinite."
   *
   * @param start_time Time when the animation starts playing.
   * @return An iterator to move over the animation.
   */
  auto get_iter(gint64 start_time = g_get_real_time()) -> Glib::RefPtr<PixbufAnimationIter>;


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
   * @relates Gdk::PixbufAnimation
   */
  GDKMM_API
  auto wrap(GdkPixbufAnimation* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PixbufAnimation>;
}


#endif /* _GDKMM_PIXBUFANIMATION_H */

