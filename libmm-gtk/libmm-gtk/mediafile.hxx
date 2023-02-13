
#ifndef _GTKMM_MEDIAFILE_H
#define _GTKMM_MEDIAFILE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

#include <libmm-gtk/mediastream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaFile = struct _GtkMediaFile;
using GtkMediaFileClass = struct _GtkMediaFileClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MediaFile_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GTKMM_API File;
class GTKMM_API InputStream;
}

namespace Gtk
{

/** Open media files for use in GTK.
 *
 * %MediaFile is the implementation for media file usage with MediaStream.
 *
 * This provides a simple way to play back video files with GTK.
 *
 * GTK+ provides a GIO extension point for %Gtk::MediaFile implementations
 * to allow for external implementations using various media frameworks.
 * GTK+ itself includes implementations using GStreamer and ffmpeg.
 *
 * @see Gtk:MediaStream, Gtk::Video
 *
 * @newin{3,94}
 */

class GTKMM_API MediaFile : public Gtk::MediaStream
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MediaFile;
  using CppClassType = MediaFile_Class;
  using BaseObjectType = GtkMediaFile;
  using BaseClassType = GtkMediaFileClass;

  // noncopyable
  MediaFile(const MediaFile&) = delete;
  auto operator=(const MediaFile&) -> MediaFile& = delete;

private:  friend class MediaFile_Class;
  static CppClassType mediafile_class_;

protected:
  explicit MediaFile(const Glib::ConstructParams& construct_params);
  explicit MediaFile(GtkMediaFile* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MediaFile(MediaFile&& src) noexcept;
  auto operator=(MediaFile&& src) noexcept -> MediaFile&;

  ~MediaFile() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMediaFile*       { return reinterpret_cast<GtkMediaFile*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMediaFile* { return reinterpret_cast<GtkMediaFile*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMediaFile*;

private:


protected:
  MediaFile();

public:


  // All gdk_media_file_new_*() functions do more than call g_object_new().

  /** Creates a new empty media file.
   *
   * @return A new `Gtk::MediaFile`.
   */
  static auto create() -> Glib::RefPtr<MediaFile>;

  /** Creates a new media file for the given filename.
   *
   * This is a utility function that converts the given @a filename
   * to a `Gio::File` and calls new_for_file().
   *
   * @param filename Filename to open.
   * @return A new `Gtk::MediaFile` playing @a filename.
   */
  static auto create_for_filename(const std::string& filename) -> Glib::RefPtr<MediaFile>;

  /** Creates a new new media file for the given resource.
   *
   * This is a utility function that converts the given @a resource
   * to a `Gio::File` and calls new_for_file().
   *
   * @param resource_path Resource path to open.
   * @return A new `Gtk::MediaFile` playing @a resource_path.
   */
  static auto create_for_resource(const std::string& resource_path) -> Glib::RefPtr<MediaFile>;

  /** Creates a new media file to play @a file.
   *
   * @param file The file to play.
   * @return A new `Gtk::MediaFile` playing @a file.
   */
  static auto create(const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<MediaFile>;

  /** Creates a new media file to play @a stream.
   *
   * If you want the resulting media to be seekable,
   * the stream should implement the `Gio::Seekable` interface.
   *
   * @param stream The stream to play.
   * @return A new `Gtk::MediaFile`.
   */
  static auto create(const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<MediaFile>;


  /** Resets the media file to be empty.
   */
  void clear();

  /** Sets the `GtkMediaFile to play the given file.
   *
   * This is a utility function that converts the given @a filename
   * to a `Gio::File` and calls set_file().
   *
   * @param filename Name of file to play.
   */
  void set_filename(const std::string& filename);

  /** Sets the `GtkMediaFile to play the given resource.
   *
   * This is a utility function that converts the given @a resource_path
   * to a `Gio::File` and calls set_file().
   *
   * @param resource_path Path to resource to play.
   */
  void set_resource(const std::string& resource_path);


  /** Sets the `Gtk::MediaFile` to play the given file.
   *
   * If any file is still playing, stop playing it.
   *
   * @param file The file to play.
   */
  void set_file(const Glib::RefPtr<Gio::File>& file);

  /** Returns the file that @a self is currently playing from.
   *
   * When @a self is not playing or not playing from a file,
   * <tt>nullptr</tt> is returned.
   *
   * @return The currently playing file.
   */
  auto get_file() -> Glib::RefPtr<Gio::File>;

  /** Returns the file that @a self is currently playing from.
   *
   * When @a self is not playing or not playing from a file,
   * <tt>nullptr</tt> is returned.
   *
   * @return The currently playing file.
   */
  auto get_file() const -> Glib::RefPtr<const Gio::File>;


  /** Sets the `Gtk::MediaFile` to play the given stream.
   *
   * If anything is still playing, stop playing it.
   *
   * Full control about the @a stream is assumed for the duration of
   * playback. The stream will not be closed.
   *
   * @param stream The stream to play from.
   */
  void set_input_stream(const Glib::RefPtr<Gio::InputStream>& stream);

  /** Returns the stream that @a self is currently playing from.
   *
   * When @a self is not playing or not playing from a stream,
   * <tt>nullptr</tt> is returned.
   *
   * @return The currently playing stream.
   */
  auto get_input_stream() -> Glib::RefPtr<Gio::InputStream>;

  /** Returns the stream that @a self is currently playing from.
   *
   * When @a self is not playing or not playing from a stream,
   * <tt>nullptr</tt> is returned.
   *
   * @return The currently playing stream.
   */
  auto get_input_stream() const -> Glib::RefPtr<const Gio::InputStream>;

  /** The file being played back or <tt>nullptr</tt> if not playing a file.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() -> Glib::PropertyProxy< Glib::RefPtr<Gio::File> > ;

/** The file being played back or <tt>nullptr</tt> if not playing a file.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::File> >;

  /** The stream being played back or <tt>nullptr</tt> if not playing a stream.
   *
   * This is <tt>nullptr</tt> when playing a file.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_stream() -> Glib::PropertyProxy< Glib::RefPtr<Gio::InputStream> > ;

/** The stream being played back or <tt>nullptr</tt> if not playing a stream.
   *
   * This is <tt>nullptr</tt> when playing a file.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_input_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::InputStream> >;


protected:
    virtual void open_vfunc();

    virtual void close_vfunc();


  // There are no signals.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MediaFile
   */
  GTKMM_API
  auto wrap(GtkMediaFile* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MediaFile>;
}


#endif /* _GTKMM_MEDIAFILE_H */

