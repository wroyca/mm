
#ifndef _GTKMM_GESTURESINGLE_H
#define _GTKMM_GESTURESINGLE_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/gesture.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureSingle = struct _GtkGestureSingle;
using GtkGestureSingleClass = struct _GtkGestureSingleClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GestureSingle_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Abstract base class for mouse/single-touch gestures.
 *
 * This is a subclass of Gesture, optimized (although
 * not restricted) for dealing with mouse and single-touch gestures. Under
 * interaction, these gestures stick to the first interacting sequence, which
 * is accessible through get_current_sequence() while the
 * gesture is being interacted with.
 *
 * By default gestures only react to touch events. set_touch_only()
 * can be used to change this default behavior. Callers may also specify
 * a mouse button number to interact with through set_button().
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GTKMM_API GestureSingle : public Gesture
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GestureSingle;
  using CppClassType = GestureSingle_Class;
  using BaseObjectType = GtkGestureSingle;
  using BaseClassType = GtkGestureSingleClass;

  // noncopyable
  GestureSingle(const GestureSingle&) = delete;
  auto operator=(const GestureSingle&) -> GestureSingle& = delete;

private:  friend class GestureSingle_Class;
  static CppClassType gesturesingle_class_;

protected:
  explicit GestureSingle(const Glib::ConstructParams& construct_params);
  explicit GestureSingle(GtkGestureSingle* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GestureSingle(GestureSingle&& src) noexcept;
  auto operator=(GestureSingle&& src) noexcept -> GestureSingle&;

  ~GestureSingle() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGestureSingle*       { return reinterpret_cast<GtkGestureSingle*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGestureSingle* { return reinterpret_cast<GtkGestureSingle*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGestureSingle*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because only derived classes shall be created.
   */
  GestureSingle();

public:
  // No create() because only derived classes shall be instantiated.


  /** Returns <tt>true</tt> if the gesture is only triggered by touch events.
   *
   * @return <tt>true</tt> if the gesture only handles touch events.
   */
  auto get_touch_only() const -> bool;

  /** Sets whether to handle only touch events.
   *
   * If @a touch_only is <tt>true</tt>, @a gesture will only handle events of type
   * Gdk::EventType::TOUCH_BEGIN, Gdk::EventType::TOUCH_UPDATE or Gdk::EventType::TOUCH_END. If <tt>false</tt>,
   * mouse events will be handled too.
   *
   * @param touch_only Whether @a gesture handles only touch events.
   */
  void set_touch_only(bool touch_only =  true);

  /** Gets whether a gesture is exclusive.
   *
   * For more information, see set_exclusive().
   *
   * @return Whether the gesture is exclusive.
   */
  auto get_exclusive() const -> bool;

  /** Sets whether @a gesture is exclusive.
   *
   * An exclusive gesture will only handle pointer and "pointer emulated"
   * touch events, so at any given time, there is only one sequence able
   * to interact with those.
   *
   * @param exclusive <tt>true</tt> to make @a gesture exclusive.
   */
  void set_exclusive(bool exclusive =  true) const;

  /** Returns the button number @a gesture listens for.
   *
   * If this is 0, the gesture reacts to any button press.
   *
   * @return The button number, or 0 for any button.
   */
  auto get_button() const -> unsigned int;

  /** Sets the button number @a gesture listens to.
   *
   * If non-0, every button press from a different button
   * number will be ignored. Touch events implicitly match
   * with button 1.
   *
   * @param button Button number to listen to, or 0 for any button.
   */
  void set_button(unsigned int button =  0);

  /** Returns the button number currently interacting
   * with @a gesture, or 0 if there is none.
   *
   * @return The current button number.
   */
  auto get_current_button() const -> unsigned int;

  /** Returns the event sequence currently interacting with @a gesture.
   *
   * This is only meaningful if is_active()
   * returns <tt>true</tt>.
   *
   * @return The current sequence.
   */
  auto get_current_sequence() -> Gdk::EventSequence*;

  /** Returns the event sequence currently interacting with @a gesture.
   *
   * This is only meaningful if is_active()
   * returns <tt>true</tt>.
   *
   * @return The current sequence.
   */
  auto get_current_sequence() const -> const Gdk::EventSequence*;

  /** Whether the gesture handles only touch events.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_touch_only() -> Glib::PropertyProxy< bool > ;

/** Whether the gesture handles only touch events.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_touch_only() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the gesture is exclusive.
   *
   * Exclusive gestures only listen to pointer and pointer emulated events.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_exclusive() -> Glib::PropertyProxy< bool > ;

/** Whether the gesture is exclusive.
   *
   * Exclusive gestures only listen to pointer and pointer emulated events.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_exclusive() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Mouse button number to listen to, or 0 to listen for any button.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_button() -> Glib::PropertyProxy< unsigned int > ;

/** Mouse button number to listen to, or 0 to listen for any button.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_button() const -> Glib::PropertyProxy_ReadOnly< unsigned int >;


  // GestureSingle has no signals


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
   * @relates Gtk::GestureSingle
   */
  GTKMM_API
  auto wrap(GtkGestureSingle* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureSingle>;
}


#endif /* _GTKMM_GESTURESINGLE_H */

