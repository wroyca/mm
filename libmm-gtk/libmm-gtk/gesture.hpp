
#ifndef _GTKMM_GESTURE_H
#define _GTKMM_GESTURE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The gtkmm Development Team
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

#include <vector>
#include <libmm-gtk/eventcontroller.hpp>
#include <libmm-gdk/event.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGesture = struct _GtkGesture;
using GtkGestureClass = struct _GtkGestureClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Gesture_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API Device;
}

namespace Gtk
{
/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var EventSequenceState NONE
 * The sequence is handled, but not grabbed.
 *
 *  @var EventSequenceState CLAIMED
 * The sequence is handled and grabbed.
 *
 *  @var EventSequenceState DENIED
 * The sequence is denied.
 *
 *  @enum EventSequenceState
 *
 * Describes the state of a Gdk::EventSequence in a Gtk::Gesture.
 *
 * @ingroup gtkmmEnums
 */
enum class EventSequenceState
{
  NONE,
  CLAIMED,
  DENIED
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::EventSequenceState> : public Glib::Value_Enum<Gtk::EventSequenceState>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Abstract base class for gestures.
 *
 * This is the base object for gesture recognition. Although this
 * object is quite generalized to serve as a base for multi-touch gestures,
 * it is suitable to implement single-touch and pointer-based gestures (using
 * the special Gdk::EventSequence value for these).
 *
 * The number of touches that a Gesture need to be recognized is controlled
 * by the n-points property. If a gesture is keeping track of less
 * or more than that number of sequences, it won't check whether the gesture
 * is recognized.
 *
 * As soon as the gesture has the expected number of touches, it will check
 * regularly if it is recognized, the criteria to consider a gesture as
 * "recognized" is left to Gesture subclasses.
 *
 * A recognized gesture will then emit the following signals:
 * - signal_begin() when the gesture is recognized.
 * - A number of signal_update(), whenever an input event is processed.
 * - signal_end() when the gesture is no longer recognized.
 *
 * <h2>Event propagation</h2>
 *
 * In order to receive events, a gesture needs to set a propagation phase
 * through EventController::set_propagation_phase().
 *
 * In the capture phase, events are propagated from the toplevel down to the
 * target widget, and gestures that are attached to containers above the widget
 * get a chance to interact with the event before it reaches the target.
 *
 * In the bubble phase, events are propagated up from the target widget to the
 * toplevel, and gestures that are attached to containers above the widget get
 * a chance to interact with events that have not been handled yet.
 *
 * <h2>States of a sequence</h2>
 *
 * Whenever input interaction happens, a single event may trigger a cascade of
 * Gesture%s, both across the parents of the widget receiving the
 * event and parallelly within an individual widget. It is a responsibility of the
 * widgets using those gestures to set the state of touch sequences accordingly
 * in order to enable cooperation of gestures around the Gdk::EventSequence%s
 * triggering those.
 *
 * Within a widget, gestures can be grouped through group().
 * Grouped gestures synchronize the state of sequences, so calling
 * set_sequence_state() on one will effectively propagate
 * the state throughout the group.
 *
 * By default, all sequences start out in the Gtk::EventSequenceState::NONE state.
 * Sequences in this state trigger the gesture event handler, but event
 * propagation will continue unstopped by gestures.
 *
 * If a sequence enters into the Gtk::EventSequenceState::DENIED state, the gesture
 * group will effectively ignore the sequence, letting events go unstopped
 * through the gesture, but the "slot" will still remain occupied while
 * the touch is active.
 *
 * If a sequence enters in the Gtk::EventSequenceState::CLAIMED state, the gesture
 * group will grab all interaction on the sequence, by:
 * - Setting the same sequence to Gtk::EventSequenceState::DENIED on every other gesture
 *   group within the widget, and every gesture on parent widgets in the propagation
 *   chain.
 * - emitting signal_cancel() on every gesture in widgets underneath in the
 *   propagation chain.
 * - Stopping event propagation after the gesture group handles the event.
 *
 * @note If a sequence is set early to Gtk::EventSequenceState::CLAIMED on
 * Gdk::Event::Type::TOUCH_BEGIN/Gdk::Event::Type::BUTTON_PRESS (so those events are captured before
 * reaching the event widget, this implies Gtk::PropagationPhase::CAPTURE), one similar
 * event will be emulated if the sequence changes to Gtk::EventSequenceState::DENIED.
 * This way event coherence is preserved before event propagation is unstopped
 * again.
 *
 * Sequence states can't be changed freely, see set_sequence_state()
 * to know about the possible lifetimes of a Gdk::EventSequence.
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GTKMM_API Gesture : public EventController
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Gesture;
  using CppClassType = Gesture_Class;
  using BaseObjectType = GtkGesture;
  using BaseClassType = GtkGestureClass;

  // noncopyable
  Gesture(const Gesture&) = delete;
  auto operator=(const Gesture&) -> Gesture& = delete;

private:  friend class Gesture_Class;
  static CppClassType gesture_class_;

protected:
  explicit Gesture(const Glib::ConstructParams& construct_params);
  explicit Gesture(GtkGesture* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Gesture(Gesture&& src) noexcept;
  auto operator=(Gesture&& src) noexcept -> Gesture&;

  ~Gesture() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGesture*       { return reinterpret_cast<GtkGesture*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGesture* { return reinterpret_cast<GtkGesture*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGesture*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because only derived classes shall be created.
   */
  Gesture();

public:
  // No create() because only derived classes shall be instantiated.


  /** Returns the logical `Gdk::Device` that is currently operating
   * on @a gesture.
   *
   * This returns <tt>nullptr</tt> if the gesture is not being interacted.
   *
   * @return A `Gdk::Device`.
   */
  auto get_device() -> Glib::RefPtr<Gdk::Device>;

  /** Returns the logical `Gdk::Device` that is currently operating
   * on @a gesture.
   *
   * This returns <tt>nullptr</tt> if the gesture is not being interacted.
   *
   * @return A `Gdk::Device`.
   */
  auto get_device() const -> Glib::RefPtr<const Gdk::Device>;

  /** Sets the state of all sequences that @a gesture is currently
   * interacting with.
   *
   * See set_sequence_state() for more details
   * on sequence states.
   *
   * @param state The sequence state.
   * @return <tt>true</tt> if the state of at least one sequence
   * was changed successfully.
   */
  auto set_state(EventSequenceState state) -> bool;

  /** Returns the @a sequence state, as seen by @a gesture.
   *
   * @param sequence A `Gdk::EventSequence`.
   * @return The sequence state in @a gesture.
   */
  auto get_sequence_state(Gdk::EventSequence* sequence) const -> EventSequenceState;

  /** Sets the state of @a sequence in @a gesture.
   *
   * Sequences start in state Gtk::EventSequenceState::NONE, and whenever
   * they change state, they can never go back to that state. Likewise,
   * sequences in state Gtk::EventSequenceState::DENIED cannot turn back to
   * a not denied state. With these rules, the lifetime of an event
   * sequence is constrained to the next four:
   *
   * * None
   * * None → Denied
   * * None → Claimed
   * * None → Claimed → Denied
   *
   * @note Due to event handling ordering, it may be unsafe to set the
   * state on another gesture within a signal_begin() signal
   * handler, as the callback might be executed before the other gesture
   * knows about the sequence. A safe way to perform this could be:
   *
   *
   * [C example ellipted]
   *
   * If both gestures are in the same group, just set the state on
   * the gesture emitting the event, the sequence will be already
   * be initialized to the group's global state when the second
   * gesture processes the event.
   *
   * @param sequence A `Gdk::EventSequence`.
   * @param state The sequence state.
   * @return <tt>true</tt> if @a sequence is handled by @a gesture,
   * and the state is changed successfully.
   */
  auto set_sequence_state(Gdk::EventSequence* sequence, EventSequenceState state) -> bool;

  /** Returns the list of Gdk::EventSequence%s currently being interpreted.
   *
   * @newin{3,14}
   *
   * @return A std::vector of Gdk::EventSequence pointers.
   *         The Gdk::EventSequence%s are owned by GTK+ and must not be freed or modified.
   */
  auto get_sequences() const -> std::vector<const Gdk::EventSequence*>;


  /** Returns the `Gdk::EventSequence` that was last updated on @a gesture.
   *
   * @return The last updated sequence.
   */
  auto get_last_updated_sequence() -> Gdk::EventSequence*;

  /** Returns the `Gdk::EventSequence` that was last updated on @a gesture.
   *
   * @return The last updated sequence.
   */
  auto get_last_updated_sequence() const -> const Gdk::EventSequence*;

  /** Returns <tt>true</tt> if @a gesture is currently handling events
   * corresponding to @a sequence.
   *
   * @param sequence A `Gdk::EventSequence`.
   * @return <tt>true</tt> if @a gesture is handling @a sequence, <tt>false</tt> otherwise.
   */
  auto handles_sequence(Gdk::EventSequence* sequence) const -> bool;

  /** Returns the last event that was processed for @a sequence.
   *
   * Note that the returned pointer is only valid as long as the
   *  @a sequence is still interpreted by the @a gesture. If in doubt,
   * you should make a copy of the event.
   *
   * @param sequence A `Gdk::EventSequence`.
   * @return The last event from @a sequence.
   */
  auto get_last_event(Gdk::EventSequence* sequence) -> Glib::RefPtr<Gdk::Event>;

  /** Returns the last event that was processed for @a sequence.
   *
   * Note that the returned pointer is only valid as long as the
   *  @a sequence is still interpreted by the @a gesture. If in doubt,
   * you should make a copy of the event.
   *
   * @param sequence A `Gdk::EventSequence`.
   * @return The last event from @a sequence.
   */
  auto get_last_event(Gdk::EventSequence* sequence) const -> Glib::RefPtr<const Gdk::Event>;

  /** If @a sequence is currently being interpreted by @a gesture,
   * returns <tt>true</tt> and fills in @a x and @a y with the last coordinates
   * stored for that event sequence.
   *
   * The coordinates are always relative to the widget allocation.
   *
   * @param sequence A `Gdk::EventSequence`, or <tt>nullptr</tt> for pointer events.
   * @param x Return location for X axis of the sequence coordinates.
   * @param y Return location for Y axis of the sequence coordinates.
   * @return <tt>true</tt> if @a sequence is currently interpreted.
   */
  auto get_point(Gdk::EventSequence* sequence, double& x, double& y) const -> bool;

  /** If there are touch sequences being currently handled by @a gesture,
   * returns <tt>true</tt> and fills in @a rect with the bounding box containing
   * all active touches.
   *
   * Otherwise, <tt>false</tt> will be returned.
   *
   * @note This function will yield unexpected results on touchpad
   * gestures. Since there is no correlation between physical and
   * pixel distances, these will look as if constrained in an
   * infinitely small area, @a rect width and height will thus be 0
   * regardless of the number of touchpoints.
   *
   * @param rect Bounding box containing all active touches.
   * @return <tt>true</tt> if there are active touches, <tt>false</tt> otherwise.
   */
  auto get_bounding_box(Gdk::Rectangle& rect) const -> bool;

  /** If there are touch sequences being currently handled by @a gesture,
   * returns <tt>true</tt> and fills in @a x and @a y with the center of the bounding
   * box containing all active touches.
   *
   * Otherwise, <tt>false</tt> will be returned.
   *
   * @param x X coordinate for the bounding box center.
   * @param y Y coordinate for the bounding box center.
   * @return <tt>false</tt> if no active touches are present, <tt>true</tt> otherwise.
   */
  auto get_bounding_box_center(double& x, double& y) const -> bool;

  /** Returns <tt>true</tt> if the gesture is currently active.
   *
   * A gesture is active while there are touch sequences
   * interacting with it.
   *
   * @return <tt>true</tt> if gesture is active.
   */
  auto is_active() const -> bool;

  /** Returns <tt>true</tt> if the gesture is currently recognized.
   *
   * A gesture is recognized if there are as many interacting
   * touch sequences as required by @a gesture.
   *
   * @return <tt>true</tt> if gesture is recognized.
   */
  auto is_recognized() const -> bool;


  /** Adds @a gesture to the same group than @a group_gesture.
   *
   * Gestures are by default isolated in their own groups.
   *
   * Both gestures must have been added to the same widget before
   * they can be grouped.
   *
   * When gestures are grouped, the state of `Gdk::EventSequences`
   * is kept in sync for all of those, so calling
   * set_sequence_state(), on one will transfer
   * the same value to the others.
   *
   * Groups also perform an "implicit grabbing" of sequences, if a
   * `Gdk::EventSequence` state is set to Gtk::EventSequenceState::CLAIMED
   * on one group, every other gesture group attached to the same
   * `Gtk::Widget` will switch the state for that sequence to
   * Gtk::EventSequenceState::DENIED.
   *
   * @param group_gesture `Gtk::Gesture` to group @a gesture with.
   */
  void group(const Glib::RefPtr<Gesture>& group_gesture);

  /** Separates @a gesture into an isolated group.
   */
  void ungroup();


  /** Returns all gestures in the group of @a gesture
   *
   * @return The list
   * of `Gtk::Gesture`s.
   */
  auto get_group() -> std::vector< Glib::RefPtr<Gesture> >;


  /** Returns all gestures in the group of @a gesture
   *
   * @return The list
   * of `Gtk::Gesture`s.
   */
  auto get_group() const -> std::vector< Glib::RefPtr<const Gesture> >;


  /** Returns <tt>true</tt> if both gestures pertain to the same group.
   *
   * @param other Another `Gtk::Gesture`.
   * @return Whether the gestures are grouped.
   */
  auto is_grouped_with(const Glib::RefPtr<Gesture>& other) const -> bool;

  // no_default_handler because GtkGestureClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%begin(Gdk::EventSequence* sequence)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the gesture is recognized.
   *
   * This means the number of touch sequences matches
   * property_n_points().
   *
   * @note These conditions may also happen when an extra touch
   * (eg. a third touch on a 2-touches gesture) is lifted, in that
   * situation @a sequence won't pertain to the current set of active
   * touches, so don't rely on this being true.
   *
   * @param sequence The `Gdk::EventSequence` that made the gesture
   * to be recognized.
   */

  auto signal_begin() -> Glib::SignalProxy<void(Gdk::EventSequence*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%end(Gdk::EventSequence* sequence)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a gesture either stopped recognizing the event
   * sequences as something to be handled, or the number of touch
   * sequences became higher or lower than property_n_points().
   *
   * @note @a sequence might not pertain to the group of sequences that
   * were previously triggering recognition on @a gesture (ie. a just
   * pressed touch sequence that exceeds property_n_points()).
   * This situation may be detected by checking through
   * Gtk::Gesture::handles_sequence().
   *
   * @param sequence The `Gdk::EventSequence` that made gesture
   * recognition to finish.
   */

  auto signal_end() -> Glib::SignalProxy<void(Gdk::EventSequence*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%update(Gdk::EventSequence* sequence)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever an event is handled while the gesture is recognized.
   *
   *  @a sequence is guaranteed to pertain to the set of active touches.
   *
   * @param sequence The `Gdk::EventSequence` that was updated.
   */

  auto signal_update() -> Glib::SignalProxy<void(Gdk::EventSequence*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cancel(Gdk::EventSequence* sequence)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a sequence is cancelled.
   *
   * This usually happens on active touches when
   * Gtk::EventController::reset() is called on @a gesture
   * (manually, due to grabs...), or the individual @a sequence
   * was claimed by parent widgets' controllers (see
   * Gtk::Gesture::set_sequence_state()).
   *
   *  @a gesture must forget everything about @a sequence as in
   * response to this signal.
   *
   * @param sequence The `Gdk::EventSequence` that was cancelled.
   */

  auto signal_cancel() -> Glib::SignalProxy<void(Gdk::EventSequence*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%sequence_state_changed(Gdk::EventSequence* sequence, EventSequenceState state)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a sequence state changes.
   *
   * See Gtk::Gesture::set_sequence_state() to know
   * more about the expectable sequence lifetimes.
   *
   * @param sequence The `Gdk::EventSequence` that was cancelled.
   * @param state The new sequence state.
   */

  auto signal_sequence_state_changed() -> Glib::SignalProxy<void(Gdk::EventSequence*, EventSequenceState)>;


  /** The number of touch points that trigger
   * recognition on this gesture.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_n_points() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


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
   * @relates Gtk::Gesture
   */
  GTKMM_API
  auto wrap(GtkGesture* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Gesture>;
}


#endif /* _GTKMM_GESTURE_H */

