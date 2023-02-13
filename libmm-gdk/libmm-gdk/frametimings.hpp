
#ifndef _GDKMM_FRAMETIMINGS_H
#define _GDKMM_FRAMETIMINGS_H

#include <libmm-gdk/mm-gdkconfig.hpp>


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


#include <libmm-glib/refptr.hpp>


extern "C" typedef struct _GdkFrameTimings GdkFrameTimings;

namespace Gdk
{

/** Object holding timing information for a single frame.
 *
 * A %Gdk::FrameTimings object holds timing information for a single frame
 * of the application’s displays. To retrieve %Gdk::FrameTimings objects,
 * use Gdk::FrameClock::get_timings() or Gdk::FrameClock::get_current_timings().
 * The information in %Gdk::FrameTimings is useful for precise synchronization
 * of video with the event or audio streams, and for measuring
 * quality metrics for the application’s display, such as latency and jitter.
 *
 * @newin{3,24}
 */
class GDKMM_API FrameTimings final
{
  // GdkFrameTimings is registered as a boxed type, but it has custom
  // reference-counting instead of copy/free functions, so we use it via RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = FrameTimings;
  using BaseObjectType = GdkFrameTimings;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkFrameTimings*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkFrameTimings*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkFrameTimings*;

  FrameTimings() = delete;

  // noncopyable
  FrameTimings(const FrameTimings&) = delete;
  auto operator=(const FrameTimings&) -> FrameTimings& = delete;

protected:
  // Do not derive this.  Gdk::FrameTimings can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Gets the frame counter value of the `Gdk::FrameClock` when
   * this frame was drawn.
   *
   * @return The frame counter value for this frame.
   */
  auto get_frame_counter() const -> gint64;

  /** Returns whether @a timings are complete.
   *
   * The timing information in a `Gdk::FrameTimings` is filled in
   * incrementally as the frame as drawn and passed off to the
   * window system for processing and display to the user. The
   * accessor functions for `Gdk::FrameTimings` can return 0 to
   * indicate an unavailable value for two reasons: either because
   * the information is not yet available, or because it isn't
   * available at all.
   *
   * Once this function returns <tt>true</tt> for a frame, you can be
   * certain that no further values will become available and be
   * stored in the `Gdk::FrameTimings`.
   *
   * @return <tt>true</tt> if all information that will be available
   * for the frame has been filled in.
   */
  auto get_complete() const -> bool;

  /** Returns the frame time for the frame.
   *
   * This is the time value that is typically used to time
   * animations for the frame. See Gdk::FrameClock::get_frame_time().
   *
   * @return The frame time for the frame, in the timescale
   * of Glib::get_monotonic_time().
   */
  auto get_frame_time() const -> gint64;

  /** Reurns the presentation time.
   *
   * This is the time at which the frame became visible to the user.
   *
   * @return The time the frame was displayed to the user, in the
   * timescale of Glib::get_monotonic_time(), or 0 if no presentation
   * time is available. See get_complete().
   */
  auto get_presentation_time() const -> gint64;

  /** Gets the natural interval between presentation times for
   * the display that this frame was displayed on.
   *
   * Frame presentation usually happens during the “vertical
   * blanking interval”.
   *
   * @return The refresh interval of the display, in microseconds,
   * or 0 if the refresh interval is not available.
   * See get_complete().
   */
  auto get_refresh_interval() const -> gint64;

  /** Gets the predicted time at which this frame will be displayed.
   *
   * Although no predicted time may be available, if one is available,
   * it will be available while the frame is being generated, in contrast
   * to get_presentation_time(), which is only
   * available after the frame has been presented.
   *
   * In general, if you are simply animating, you should use
   * Gdk::FrameClock::get_frame_time() rather than this function,
   * but this function is useful for applications that want exact control
   * over latency. For example, a movie player may want this information
   * for Audio/Video synchronization.
   *
   * @return The predicted time at which the frame will be presented,
   * in the timescale of Glib::get_monotonic_time(), or 0 if no predicted
   * presentation time is available.
   */
  auto get_predicted_presentation_time() const -> gint64;


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
 * @relates Gdk::FrameTimings
 */
GDKMM_API
auto wrap(GdkFrameTimings* object, bool take_copy = false) -> Glib::RefPtr<Gdk::FrameTimings>;

} // namespace Glib


#endif /* _GDKMM_FRAMETIMINGS_H */

