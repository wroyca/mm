
#ifndef _GTKMM_GESTURECLICK_H
#define _GTKMM_GESTURECLICK_H


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

#include <libmm-gtk/gesturesingle.hpp>
#include <libmm-gdk/rectangle.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureClick = struct _GtkGestureClick;
using GtkGestureClickClass = struct _GtkGestureClickClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GestureClick_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Multipress gesture.
 *
 * This is a Gesture implementation able to recognize
 * multiple clicks on a nearby zone, which can be listened for through
 * signal_pressed(). Whenever time or distance between
 * clicks exceed the GTK+ defaults, signal_stopped() is emitted,
 * and the click counter is reset.
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GTKMM_API GestureClick : public GestureSingle
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GestureClick;
  using CppClassType = GestureClick_Class;
  using BaseObjectType = GtkGestureClick;
  using BaseClassType = GtkGestureClickClass;

  // noncopyable
  GestureClick(const GestureClick&) = delete;
  auto operator=(const GestureClick&) -> GestureClick& = delete;

private:  friend class GestureClick_Class;
  static CppClassType gestureclick_class_;

protected:
  explicit GestureClick(const Glib::ConstructParams& construct_params);
  explicit GestureClick(GtkGestureClick* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GestureClick(GestureClick&& src) noexcept;
  auto operator=(GestureClick&& src) noexcept -> GestureClick&;

  ~GestureClick() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGestureClick*       { return reinterpret_cast<GtkGestureClick*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGestureClick* { return reinterpret_cast<GtkGestureClick*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGestureClick*;

private:


protected:
  /** Constructs a Gesture that recognizes single and multiple presses.
   */
  GestureClick();

public:
  /** Creates a Gesture that recognizes single and multiple presses.
   *
   * @newin{3,14}
   *
   * @return A RefPtr to a new GestureClick.
   */

  static auto create() -> Glib::RefPtr<GestureClick>;


  // no_default_handler because GtkGestureClickClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pressed(int n_press, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a button or touch press happens.
   *
   * @param n_press How many touch/button presses happened with this one.
   * @param x The X coordinate, in widget allocation coordinates.
   * @param y The Y coordinate, in widget allocation coordinates.
   */

  auto signal_pressed() -> Glib::SignalProxy<void(int, double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%released(int n_press, double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a button or touch is released.
   *
   *  @a n_press will report the number of press that is paired to
   * this event, note that signal_stopped() may
   * have been emitted between the press and its release, @a n_press
   * will only start over at the next press.
   *
   * @param n_press Number of press that is paired with this release.
   * @param x The X coordinate, in widget allocation coordinates.
   * @param y The Y coordinate, in widget allocation coordinates.
   */

  auto signal_released() -> Glib::SignalProxy<void(int, double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%stopped()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever any time/distance threshold has been exceeded.
   */

  auto signal_stopped() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%unpaired_release(double x, double y, guint button, Gdk::EventSequence* sequence)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the gesture receives a release
   * event that had no previous corresponding press.
   *
   * Due to implicit grabs, this can only happen on situations
   * where input is grabbed elsewhere mid-press or the pressed
   * widget voluntarily relinquishes its implicit grab.
   *
   * @param x X coordinate of the event.
   * @param y Y coordinate of the event.
   * @param button Button being released.
   * @param sequence Sequence being released.
   */

  auto signal_unpaired_release() -> Glib::SignalProxy<void(double, double, guint, Gdk::EventSequence*)>;


  // GestureMultiPress has no properties


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
   * @relates Gtk::GestureClick
   */
  GTKMM_API
  auto wrap(GtkGestureClick* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureClick>;
}


#endif /* _GTKMM_GESTURECLICK_H */

