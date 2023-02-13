
#ifndef _GTKMM_MEDIASTREAM_H
#define _GTKMM_MEDIASTREAM_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
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


#include <libmm-glib/object.hpp>
#include <libmm-gdk/paintable.hpp>
#include <libmm-gdk/surface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMediaStream = struct _GtkMediaStream;
using GtkMediaStreamClass = struct _GtkMediaStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MediaStream_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{
class GTKMM_API Error;
}

namespace Gtk
{

/** Display media in GTK.
 *
 * %MediaStream is the integration point for media playback inside GTK.
 *
 * Apart from application-facing API for stream playback, %MediaStream
 * has a number of APIs that are only useful for implementations and should
 * not be used in applications:
 *  prepared(),
 *  unprepared(),
 *  update(),
 *  ended(),
 *  seek_success(),
 *  seek_failed(),
 *  set_error().
 *
 * @see Gdk::Paintable
 *
 * @newin{3,94}
 */

class GTKMM_API MediaStream : public Glib::Object, public Gdk::Paintable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MediaStream;
  using CppClassType = MediaStream_Class;
  using BaseObjectType = GtkMediaStream;
  using BaseClassType = GtkMediaStreamClass;

  // noncopyable
  MediaStream(const MediaStream&) = delete;
  auto operator=(const MediaStream&) -> MediaStream& = delete;

private:  friend class MediaStream_Class;
  static CppClassType mediastream_class_;

protected:
  explicit MediaStream(const Glib::ConstructParams& construct_params);
  explicit MediaStream(GtkMediaStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MediaStream(MediaStream&& src) noexcept;
  auto operator=(MediaStream&& src) noexcept -> MediaStream&;

  ~MediaStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMediaStream*       { return reinterpret_cast<GtkMediaStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMediaStream* { return reinterpret_cast<GtkMediaStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMediaStream*;

private:


public:

  /** Returns whether the stream has finished initializing.
   *
   * At this point the existence of audio and video is known.
   *
   * @return <tt>true</tt> if the stream is prepared.
   */
  auto is_prepared() const -> bool;


  /** If the stream is in an error state, returns the `GError`
   * explaining that state.
   *
   * Any type of error can be reported here depending on the
   * implementation of the media stream.
   *
   * A media stream in an error cannot be operated on, calls
   * like play() or
   * seek() will not have any effect.
   *
   * `Gtk::MediaStream` itself does not provide a way to unset
   * an error, but implementations may provide options. For example,
   * a Gtk::MediaFile will unset errors when a new source is
   * set, e.g. with Gtk::MediaFile::set_file().
   *
   * @return <tt>nullptr</tt> if not in an
   * error state or the `GError` of the stream.
   */
  auto get_error() const -> Glib::Error;

  /** Returns whether the stream has audio.
   *
   * @return <tt>true</tt> if the stream has audio.
   */
  auto has_audio() const -> bool;

  /** Returns whether the stream has video.
   *
   * @return <tt>true</tt> if the stream has video.
   */
  auto has_video() const -> bool;

  /** Starts playing the stream.
   *
   * If the stream is in error or already playing, do nothing.
   */
  void play();

  /** Pauses playback of the stream.
   *
   * If the stream is not playing, do nothing.
   */
  void pause();

  /** Return whether the stream is currently playing.
   *
   * @return <tt>true</tt> if the stream is playing.
   */
  auto get_playing() const -> bool;

  /** Starts or pauses playback of the stream.
   *
   * @param playing Whether to start or pause playback.
   */
  void set_playing(bool playing =  true);

  /** Returns whether the streams playback is finished.
   *
   * @return <tt>true</tt> if playback is finished.
   */
  auto get_ended() const -> bool;

  /** Returns the current presentation timestamp in microseconds.
   *
   * @return The timestamp in microseconds.
   */
  auto get_timestamp() const -> gint64;

  /** Gets the duration of the stream.
   *
   * If the duration is not known, 0 will be returned.
   *
   * @return The duration of the stream or 0 if not known.
   */
  auto get_duration() const -> gint64;

  /** Checks if a stream may be seekable.
   *
   * This is meant to be a hint. Streams may not allow seeking even if
   * this function returns <tt>true</tt>. However, if this function returns
   * <tt>false</tt>, streams are guaranteed to not be seekable and user interfaces
   * may hide controls that allow seeking.
   *
   * It is allowed to call seek() on a non-seekable
   * stream, though it will not do anything.
   *
   * @return <tt>true</tt> if the stream may support seeking.
   */
  auto is_seekable() const -> bool;

  /** Checks if there is currently a seek operation going on.
   *
   * @return <tt>true</tt> if a seek operation is ongoing.
   */
  auto is_seeking() const -> bool;

  /** Start a seek operation on @a self to @a timestamp.
   *
   * If @a timestamp is out of range, it will be clamped.
   *
   * Seek operations may not finish instantly. While a
   * seek operation is in process, the property_seeking()
   * property will be set.
   *
   * When calling seek() during an
   * ongoing seek operation, the new seek will override
   * any pending seek.
   *
   * @param timestamp Timestamp to seek to.
   */
  void seek(gint64 timestamp);

  /** Returns whether the stream is set to loop.
   *
   * See set_loop() for details.
   *
   * @return <tt>true</tt> if the stream should loop.
   */
  auto get_loop() const -> bool;

  /** Sets whether the stream should loop.
   *
   * In this case, it will attempt to restart playback
   * from the beginning instead of stopping at the end.
   *
   * Not all streams may support looping, in particular
   * non-seekable streams. Those streams will ignore the
   * loop setting and just end.
   *
   * @param loop <tt>true</tt> if the stream should loop.
   */
  void set_loop(bool loop =  true);

  /** Returns whether the audio for the stream is muted.
   *
   * See set_muted() for details.
   *
   * @return <tt>true</tt> if the stream is muted.
   */
  auto get_muted() const -> bool;

  /** Sets whether the audio stream should be muted.
   *
   * Muting a stream will cause no audio to be played, but it
   * does not modify the volume. This means that muting and
   * then unmuting the stream will restore the volume settings.
   *
   * If the stream has no audio, calling this function will
   * still work but it will not have an audible effect.
   *
   * @param muted <tt>true</tt> if the stream should be muted.
   */
  void set_muted(bool muted =  true);

  /** Returns the volume of the audio for the stream.
   *
   * See set_volume() for details.
   *
   * @return Volume of the stream from 0.0 to 1.0.
   */
  auto get_volume() const -> double;

  /** Sets the volume of the audio stream.
   *
   * This function call will work even if the stream is muted.
   *
   * The given @a volume should range from 0.0 for silence to 1.0
   * for as loud as possible. Values outside of this range will
   * be clamped to the nearest value.
   *
   * If the stream has no audio or is muted, calling this function
   * will still work but it will not have an immediate audible effect.
   * When the stream is unmuted, the new volume setting will take effect.
   *
   * @param volume New volume of the stream from 0.0 to 1.0.
   */
  void set_volume(double volume);

  /** Called by users to attach the media stream to a `Gdk::Surface` they manage.
   *
   * The stream can then access the resources of @a surface for its
   * rendering purposes. In particular, media streams might want to
   * create a `Gdk::GLContext` or sync to the `Gdk::FrameClock`.
   *
   * Whoever calls this function is responsible for calling
   * unrealize() before either the stream
   * or @a surface get destroyed.
   *
   * Multiple calls to this function may happen from different
   * users of the video, even with the same @a surface. Each of these
   * calls must be followed by its own call to
   * unrealize().
   *
   * It is not required to call this function to make a media stream work.
   *
   * @param surface A `Gdk::Surface`.
   */
  void realize(const Glib::RefPtr<Gdk::Surface>& surface);

  /** Undoes a previous call to realize().
   *
   * This causes the stream to release all resources it had
   * allocated from @a surface.
   *
   * @param surface The `Gdk::Surface` the stream was realized with.
   */
  void unrealize(const Glib::RefPtr<Gdk::Surface>& surface);

  // For implementations only


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Same as stream_prepared().
   *
   * Deprecated: 4.4: Use stream_prepared() instead.
   *
   * @deprecated Use stream_prepared() instead.
   *
   * @param has_audio <tt>true</tt> if the stream should advertise audio support.
   * @param has_video <tt>true</tt> if the stream should advertise video support.
   * @param seekable <tt>true</tt> if the stream should advertise seekability.
   * @param duration The duration of the stream or 0 if unknown.
   */
  void prepared(bool has_audio, bool has_video, bool seekable, gint64 duration);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Same as stream_unprepared().
   *
   * Deprecated: 4.4: Use stream_unprepared() instead.
   *
   * @deprecated Use stream_unprepared() instead.
   */
  void unprepared();
#endif // GTKMM_DISABLE_DEPRECATED


  /** Called by `Gtk::MediaStream` implementations to advertise the stream
   * being ready to play and providing details about the stream.
   *
   * Note that the arguments are hints. If the stream implementation
   * cannot determine the correct values, it is better to err on the
   * side of caution and return <tt>true</tt>. User interfaces will use those
   * values to determine what controls to show.
   *
   * This function may not be called again until the stream has been
   * reset via stream_unprepared().
   *
   * @newin{4,4}
   *
   * @param has_audio <tt>true</tt> if the stream should advertise audio support.
   * @param has_video <tt>true</tt> if the stream should advertise video support.
   * @param seekable <tt>true</tt> if the stream should advertise seekability.
   * @param duration The duration of the stream or 0 if unknown.
   */
  void stream_prepared(bool has_audio, bool has_video, bool seekable, gint64 duration);

  /** Resets a given media stream implementation.
   *
   * stream_prepared() can then be called again.
   *
   * This function will also reset any error state the stream was in.
   *
   * @newin{4,4}
   */
  void stream_unprepared();


  /** Media stream implementations should regularly call this
   * function to update the timestamp reported by the stream.
   *
   * It is up to implementations to call this at the frequency
   * they deem appropriate.
   *
   * The media stream must be prepared when this function is called.
   *
   * @param timestamp The new timestamp.
   */
  void update(gint64 timestamp);


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Pauses the media stream and marks it as ended.
   *
   * This is a hint only, calls to play()
   * may still happen.
   *
   * The media stream must be prepared when this function is called.
   *
   * Deprecated: 4.4: Use stream_ended() instead
   *
   * @deprecated Use stream_ended() instead.
   */
  void ended();
#endif // GTKMM_DISABLE_DEPRECATED


  /** Pauses the media stream and marks it as ended.
   *
   * This is a hint only, calls to play()
   * may still happen.
   *
   * The media stream must be prepared when this function is called.
   *
   * @newin{4,4}
   */
  void stream_ended();


  /** Ends a seek operation started via GtkMediaStream.seek() successfully.
   *
   * This function will unset the GtkMediaStream:ended property
   * if it was set.
   *
   * See seek_failed() for the other way of
   * ending a seek.
   */
  void seek_success();

  /** Ends a seek operation started via GtkMediaStream.seek() as a failure.
   *
   * This will not cause an error on the stream and will assume that
   * playback continues as if no seek had happened.
   *
   * See seek_success() for the other way of
   * ending a seek.
   */
  void seek_failed();


  /** Sets @a self into an error state.
   *
   * This will pause the stream (you can check for an error
   * via get_error() in your
   * GtkMediaStream.pause() implementation), abort pending
   * seeks and mark the stream as prepared.
   *
   * if the stream is already in an error state, this call
   * will be ignored and the existing error will be retained.
   *
   * To unset an error, the stream must be reset via a call to
   * unprepared().
   *
   * @param error The `GError` to set.
   */
  void set_error(const Glib::Error& error);


  /** Whether the stream has finished initializing and existence of
   * audio and video is known.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_prepared() -> Glib::PropertyProxy< bool > ;

/** Whether the stream has finished initializing and existence of
   * audio and video is known.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_prepared() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** <tt>nullptr</tt> for a properly working stream or the `GError`
   * that the stream is in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_error() const -> Glib::PropertyProxy_ReadOnly< Glib::Error >;


  /** Whether the stream contains audio.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_audio() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the stream contains video.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_video() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the stream is currently playing.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_playing() -> Glib::PropertyProxy< bool > ;

/** Whether the stream is currently playing.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_playing() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Set when playback has finished.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_ended() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The current presentation timestamp in microseconds.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_timestamp() const -> Glib::PropertyProxy_ReadOnly< gint64 >;


  /** The stream's duration in microseconds or 0 if unknown.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_duration() const -> Glib::PropertyProxy_ReadOnly< gint64 >;


  /** Set unless the stream is known to not support seeking.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_seekable() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Set while a seek is in progress.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_seeking() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Try to restart the media from the beginning once it ended.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_loop() -> Glib::PropertyProxy< bool > ;

/** Try to restart the media from the beginning once it ended.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_loop() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the audio stream should be muted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_muted() -> Glib::PropertyProxy< bool > ;

/** Whether the audio stream should be muted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_muted() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Volume of the audio stream.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_volume() -> Glib::PropertyProxy< double > ;

/** Volume of the audio stream.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_volume() const -> Glib::PropertyProxy_ReadOnly< double >;


protected:
    virtual auto play_vfunc() -> bool;

    virtual void pause_vfunc();

    virtual void seek_vfunc(gint64 timestamp);

    virtual void update_audio_vfunc(bool muted, double volume);


    virtual void realize_vfunc(const Glib::RefPtr<Gdk::Surface>& surface);

    virtual void unrealize_vfunc(const Glib::RefPtr<Gdk::Surface>& surface);


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
   * @relates Gtk::MediaStream
   */
  GTKMM_API
  auto wrap(GtkMediaStream* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MediaStream>;
}


#endif /* _GTKMM_MEDIASTREAM_H */

