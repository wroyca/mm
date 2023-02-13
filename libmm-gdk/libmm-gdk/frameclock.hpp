
#ifndef _GDKMM_FRAMECLOCK_H
#define _GDKMM_FRAMECLOCK_H


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
#include <libmm-gdk/frametimings.hpp>


extern "C" typedef struct _GdkFrameClock GdkFrameClock;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkFrameClock = struct _GdkFrameClock;
using GdkFrameClockClass = struct _GdkFrameClockClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API FrameClock_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
/** Synchronizes painting to a surface.
 *
 * A %Gdk::FrameClock tells the application when to update and repaint
 * a surface. This may be synced to the vertical refresh rate of the
 * monitor, for example. Even when the frame clock uses a simple timer
 * rather than a hardware-based vertical sync, the frame clock helps
 * because it ensures everything paints at the same time (reducing the
 * total number of frames). The frame clock can also automatically
 * stop painting when it knows the frames will not be visible, or
 * scale back animation framerates.
 *
 * %Gdk::FrameClock is designed to be compatible with an OpenGL-based
 * implementation or with mozRequestAnimationFrame in Firefox,
 * for example.
 *
 * A frame clock is idle until someone requests a frame with
 * request_phase(). At some later point that makes
 * sense for the synchronization being implemented, the clock will
 * process a frame and emit signals for each phase that has been
 * requested. (See the signals of the %Gdk::FrameClock class for
 * documentation of the phases. Gdk::FrameClock::Phase::UPDATE and the
 * signal_update() signal are most interesting for application
 * writers, and are used to update the animations, using the frame time
 * given by get_frame_time().
 *
 * The frame time is reported in microseconds and generally in the same
 * timescale as g_get_monotonic_time(), however, it is not the same
 * as g_get_monotonic_time(). The frame time does not advance during
 * the time a frame is being painted, and outside of a frame, an attempt
 * is made so that all calls to get_frame_time() that
 * are called at a “similar” time get the same value. This means that
 * if different animations are timed by looking at the difference in
 * time between an initial value from get_frame_time()
 * and the value inside the signal_update() signal of the clock,
 * they will stay exactly synchronized.
 *
 * @newin{3,24}
 */

class GDKMM_API FrameClock : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FrameClock;
  using CppClassType = FrameClock_Class;
  using BaseObjectType = GdkFrameClock;
  using BaseClassType = GdkFrameClockClass;

  // noncopyable
  FrameClock(const FrameClock&) = delete;
  auto operator=(const FrameClock&) -> FrameClock& = delete;

private:  friend class FrameClock_Class;
  static CppClassType frameclock_class_;

protected:
  explicit FrameClock(const Glib::ConstructParams& construct_params);
  explicit FrameClock(GdkFrameClock* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FrameClock(FrameClock&& src) noexcept;
  auto operator=(FrameClock&& src) noexcept -> FrameClock&;

  ~FrameClock() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkFrameClock*       { return reinterpret_cast<GdkFrameClock*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkFrameClock* { return reinterpret_cast<GdkFrameClock*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkFrameClock*;

private:


public:
  /** @addtogroup gdkmmEnums gdkmm Enums and Flags */

  /**
   *  @var Phase NONE
   * No phase.
   *
   *  @var Phase FLUSH_EVENTS
   * Corresponds to GdkFrameClock::flush-events. Should not be handled by applications.
   *
   *  @var Phase BEFORE_PAINT
   * Corresponds to GdkFrameClock::before-paint. Should not be handled by applications.
   *
   *  @var Phase UPDATE
   * Corresponds to GdkFrameClock::update.
   *
   *  @var Phase LAYOUT
   * Corresponds to GdkFrameClock::layout. Should not be handled by applications.
   *
   *  @var Phase PAINT
   * Corresponds to GdkFrameClock::paint.
   *
   *  @var Phase RESUME_EVENTS
   * Corresponds to GdkFrameClock::resume-events. Should not be handled by applications.
   *
   *  @var Phase AFTER_PAINT
   * Corresponds to GdkFrameClock::after-paint. Should not be handled by applications.
   *
   *  @enum Phase
   *
   * Used to represent the different paint clock phases that can be requested.
   *
   * The elements of the enumeration correspond to the signals of `Gdk::FrameClock`.
   *
   * @ingroup gdkmmEnums
   * @par Bitwise operators:
   * <tt>FrameClock::Phase operator|(FrameClock::Phase, FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase operator&(FrameClock::Phase, FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase operator^(FrameClock::Phase, FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase operator~(FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase& operator|=(FrameClock::Phase&, FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase& operator&=(FrameClock::Phase&, FrameClock::Phase)</tt><br>
   * <tt>FrameClock::Phase& operator^=(FrameClock::Phase&, FrameClock::Phase)</tt><br>
   */
  enum class Phase
  {
    NONE = 0x0,
    FLUSH_EVENTS = 1 << 0,
    BEFORE_PAINT = 1 << 1,
    UPDATE = 1 << 2,
    LAYOUT = 1 << 3,
    PAINT = 1 << 4,
    RESUME_EVENTS = 1 << 5,
    AFTER_PAINT = 1 << 6
  };


  /** Gets the time that should currently be used for animations.
   *
   * Inside the processing of a frame, it’s the time used to compute the
   * animation position of everything in a frame. Outside of a frame, it's
   * the time of the conceptual “previous frame,” which may be either
   * the actual previous frame time, or if that’s too old, an updated
   * time.
   *
   * @return A timestamp in microseconds, in the timescale of
   * of Glib::get_monotonic_time().
   */
  auto get_frame_time() const -> gint64;

  /** Asks the frame clock to run a particular phase.
   *
   * The signal corresponding the requested phase will be emitted the next
   * time the frame clock processes. Multiple calls to
   * request_phase() will be combined together
   * and only one frame processed. If you are displaying animated
   * content and want to continually request the
   * Gdk::FrameClock::Phase::UPDATE phase for a period of time,
   * you should use begin_updating() instead,
   * since this allows GTK to adjust system parameters to get maximally
   * smooth animations.
   *
   * @param phase The phase that is requested.
   */
  void request_phase(Phase phase);

  /** Starts updates for an animation.
   *
   * Until a matching call to end_updating() is made,
   * the frame clock will continually request a new frame with the
   * Gdk::FrameClock::Phase::UPDATE phase. This function may be called multiple
   * times and frames will be requested until end_updating()
   * is called the same number of times.
   */
  void begin_updating();

  /** Stops updates for an animation.
   *
   * See the documentation for begin_updating().
   */
  void end_updating();

  /** `Gdk::FrameClock` maintains a 64-bit counter that increments for
   * each frame drawn.
   *
   * @return Inside frame processing, the value of the frame counter
   * for the current frame. Outside of frame processing, the frame
   * counter for the last frame.
   */
  auto get_frame_counter() const -> gint64;

  /** Returns the frame counter for the oldest frame available in history.
   *
   * `Gdk::FrameClock` internally keeps a history of `Gdk::FrameTimings`
   * objects for recent frames that can be retrieved with
   * get_timings(). The set of stored frames
   * is the set from the counter values given by
   * get_history_start() and
   * get_frame_counter(), inclusive.
   *
   * @return The frame counter value for the oldest frame
   * that is available in the internal frame history of the
   * `Gdk::FrameClock`.
   */
  auto get_history_start() const -> gint64;

  /** Retrieves a `Gdk::FrameTimings` object holding timing information
   * for the current frame or a recent frame.
   *
   * The `Gdk::FrameTimings` object may not yet be complete: see
   * Gdk::FrameTimings::get_complete() and
   * get_history_start().
   *
   * @param frame_counter The frame counter value identifying the frame to
   * be received.
   * @return The `Gdk::FrameTimings` object
   * for the specified frame, or <tt>nullptr</tt> if it is not available.
   */
  auto get_timings(gint64 frame_counter) -> Glib::RefPtr<FrameTimings>;

  /** Retrieves a `Gdk::FrameTimings` object holding timing information
   * for the current frame or a recent frame.
   *
   * The `Gdk::FrameTimings` object may not yet be complete: see
   * Gdk::FrameTimings::get_complete() and
   * get_history_start().
   *
   * @param frame_counter The frame counter value identifying the frame to
   * be received.
   * @return The `Gdk::FrameTimings` object
   * for the specified frame, or <tt>nullptr</tt> if it is not available.
   */
  auto get_timings(gint64 frame_counter) const -> Glib::RefPtr<const FrameTimings>;

  /** Gets the frame timings for the current frame.
   *
   * @return The `Gdk::FrameTimings` for the
   * frame currently being processed, or even no frame is being
   * processed, for the previous frame. Before any frames have been
   * processed, returns <tt>nullptr</tt>.
   */
  auto get_current_timings() -> Glib::RefPtr<FrameTimings>;

  /** Gets the frame timings for the current frame.
   *
   * @return The `Gdk::FrameTimings` for the
   * frame currently being processed, or even no frame is being
   * processed, for the previous frame. Before any frames have been
   * processed, returns <tt>nullptr</tt>.
   */
  auto get_current_timings() const -> Glib::RefPtr<const FrameTimings>;

  /** Predicts a presentation time, based on history.
   *
   * Using the frame history stored in the frame clock, finds the last
   * known presentation time and refresh interval, and assuming that
   * presentation times are separated by the refresh interval,
   * predicts a presentation time that is a multiple of the refresh
   * interval after the last presentation time, and later than @a base_time.
   *
   * @param base_time Base time for determining a presentaton time.
   * @param refresh_interval_return A location to store the
   * determined refresh interval, or <tt>nullptr</tt>. A default refresh interval of
   * 1/60th of a second will be stored if no history is present.
   * @param presentation_time_return A location to store the next
   * candidate presentation time after the given base time.
   * 0 will be will be stored if no history is present.
   */
  void get_refresh_info(gint64 base_time, gint64& refresh_interval_return, gint64& presentation_time_return) const;

  /** Calculates the current frames-per-second, based on the
   * frame timings of @a frame_clock.
   *
   * @return The current fps, as a `double`.
   */
  auto get_fps() const -> double;


  // no_default_handler because the wrapped C signals have no default handlers.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%update()</tt>
   *
   * Flags: Run Last
   *
   * Emitted as the first step of toolkit and application processing
   * of the frame.
   *
   * Animations should be updated using Gdk::FrameClock::get_frame_time().
   * Applications can connect directly to this signal, or use
   * Gtk::Widget::add_tick_callback() as a more convenient interface.
   */

  auto signal_update() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%layout()</tt>
   *
   * Flags: Run Last
   *
   * Emitted as the second step of toolkit and application processing
   * of the frame.
   *
   * Any work to update sizes and positions of application elements
   * should be performed. GTK normally handles this internally.
   */

  auto signal_layout() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%paint()</tt>
   *
   * Flags: Run Last
   *
   * Emitted as the third step of toolkit and application processing
   * of the frame.
   *
   * The frame is repainted. GDK normally handles this internally and
   * emits Gdk::Surface::signal_render() signals which are turned into
   * Gtk::Widget::signal_snapshot() signals by GTK.
   */

  auto signal_paint() -> Glib::SignalProxy<void()>;


  // There are no properties or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gdk

namespace Gdk
{

/** @ingroup gdkmmEnums */
inline auto operator|(FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  { return static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator&(FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  { return static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator^(FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  { return static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdkmmEnums */
inline auto operator~(FrameClock::Phase flags) -> FrameClock::Phase
  { return static_cast<FrameClock::Phase>(~static_cast<unsigned>(flags)); }

/** @ingroup gdkmmEnums */
inline auto operator|=(FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  { return (lhs = static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator&=(FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  { return (lhs = static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdkmmEnums */
inline auto operator^=(FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  { return (lhs = static_cast<FrameClock::Phase>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::FrameClock::Phase> : public Glib::Value_Flags<Gdk::FrameClock::Phase>
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
   * @relates Gdk::FrameClock
   */
  GDKMM_API
  auto wrap(GdkFrameClock* object, bool take_copy = false) -> Glib::RefPtr<Gdk::FrameClock>;
}


#endif /* _GDKMM_FRAMECLOCK_H */

