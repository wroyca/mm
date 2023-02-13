
#ifndef _GTKMM_GESTURELONGPRESS_H
#define _GTKMM_GESTURELONGPRESS_H


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

#include <libmm-gtk/gesturesingle.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureLongPress = struct _GtkGestureLongPress;
using GtkGestureLongPressClass = struct _GtkGestureLongPressClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GestureLongPress_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** "Press and Hold" gesture.
 *
 * This is a Gesture implementation able to recognize
 * long presses, triggering signal_pressed() after the
 * timeout is exceeded.
 *
 * If the touchpoint is lifted before the timeout passes, or if it drifts
 * too far of the initial press point, signal_cancelled() will be emitted.
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GTKMM_API GestureLongPress : public GestureSingle
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GestureLongPress;
  using CppClassType = GestureLongPress_Class;
  using BaseObjectType = GtkGestureLongPress;
  using BaseClassType = GtkGestureLongPressClass;

  // noncopyable
  GestureLongPress(const GestureLongPress&) = delete;
  auto operator=(const GestureLongPress&) -> GestureLongPress& = delete;

private:  friend class GestureLongPress_Class;
  static CppClassType gesturelongpress_class_;

protected:
  explicit GestureLongPress(const Glib::ConstructParams& construct_params);
  explicit GestureLongPress(GtkGestureLongPress* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GestureLongPress(GestureLongPress&& src) noexcept;
  auto operator=(GestureLongPress&& src) noexcept -> GestureLongPress&;

  ~GestureLongPress() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGestureLongPress*       { return reinterpret_cast<GtkGestureLongPress*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGestureLongPress* { return reinterpret_cast<GtkGestureLongPress*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGestureLongPress*;

private:


protected:
  /** Constructs a Gesture that recognizes long presses.
   */
  GestureLongPress();

public:
  /** Creates a Gesture that recognizes long presses.
   *
   * @newin{3,14}
   *
   * @return A RefPtr to a new GestureLongPress.
   */

  static auto create() -> Glib::RefPtr<GestureLongPress>;


  /** Applies the given delay factor.
   *
   * The default long press time will be multiplied by this value.
   * Valid values are in the range [0.5..2.0].
   *
   * @param delay_factor The delay factor to apply.
   */
  void set_delay_factor(double delay_factor);

  /** Returns the delay factor.
   *
   * @return The delay factor.
   */
  auto get_delay_factor() const -> double;

  // no_default_handler because GtkGestureLongPressClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pressed(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a press goes unmoved/unreleased longer than
   * what the GTK defaults tell.
   *
   * @param x The X coordinate where the press happened, relative to the widget allocation.
   * @param y The Y coordinate where the press happened, relative to the widget allocation.
   */

  auto signal_pressed() -> Glib::SignalProxy<void(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%cancelled()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever a press moved too far, or was released
   * before signal_pressed() happened.
   */

  auto signal_cancelled() -> Glib::SignalProxy<void()>;


  /** Factor by which to modify the default timeout.
   *
   * @newin{3,20}
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_delay_factor() -> Glib::PropertyProxy< double > ;

/** Factor by which to modify the default timeout.
   *
   * @newin{3,20}
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_delay_factor() const -> Glib::PropertyProxy_ReadOnly< double >;


  // GestureLongPress has no methods


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
   * @relates Gtk::GestureLongPress
   */
  GTKMM_API
  auto wrap(GtkGestureLongPress* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureLongPress>;
}


#endif /* _GTKMM_GESTURELONGPRESS_H */

