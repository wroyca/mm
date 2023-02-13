
#ifndef _GTKMM_GESTURESTYLUS_H
#define _GTKMM_GESTURESTYLUS_H


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

#include <libmm-gtk/gesturesingle.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/timecoord.hxx>
#include <optional>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureStylus = struct _GtkGestureStylus;
using GtkGestureStylusClass = struct _GtkGestureStylusClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GestureStylus_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GTKMM_API DeviceTool;
}

namespace Gtk
{
/** Gesture for stylus input.
 *
 * %Gtk::GestureStylus is a Gtk::Gesture implementation specific to stylus
 * input. The provided signals just provide the basic information.
 *
 * @newin{3,94}
 *
 * @ingroup Gestures
 */

class GTKMM_API GestureStylus : public GestureSingle
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GestureStylus;
  using CppClassType = GestureStylus_Class;
  using BaseObjectType = GtkGestureStylus;
  using BaseClassType = GtkGestureStylusClass;

  // noncopyable
  GestureStylus(const GestureStylus&) = delete;
  auto operator=(const GestureStylus&) -> GestureStylus& = delete;

private:  friend class GestureStylus_Class;
  static CppClassType gesturestylus_class_;

protected:
  explicit GestureStylus(const Glib::ConstructParams& construct_params);
  explicit GestureStylus(GtkGestureStylus* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GestureStylus(GestureStylus&& src) noexcept;
  auto operator=(GestureStylus&& src) noexcept -> GestureStylus&;

  ~GestureStylus() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGestureStylus*       { return reinterpret_cast<GtkGestureStylus*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGestureStylus* { return reinterpret_cast<GtkGestureStylus*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGestureStylus*;

private:


protected:
  /** Constructs a %GestureStylus.
   */
  GestureStylus();

public:
  /** Creates a %GestureStylus.
   *
   * @return A RefPtr to a new %GestureStylus.
   */

  static auto create() -> Glib::RefPtr<GestureStylus>;


  /** Returns the current value for the requested @a axis.
   * This function must be called from either the signal_down(),
   * signal_motion(), signal_up() or signal_proximity() signal handlers.
   *
   * @param axis Requested device axis.
   * @return The current value for the axis, if any.
   */
  auto get_axis(Gdk::AxisUse axis) const -> std::optional<double>;


  /** Returns the current values for the requested @a axes.
   * This function must be called from either the signal_down(),
   * signal_motion(), signal_up() or signal_proximity() signal handlers.
   *
   * @param axes Vector of requested axes.
   *        Don't include Gdk::AxisUse::IGNORE in the vector. The underlying
   *        GTK+ function would interpret it as an end-of-array mark.
   * @return The current values for the axes.
   *         If there are no values, an empty vector is returned.
   */
  auto get_axes(const std::vector<Gdk::AxisUse>& axes) const -> std::vector<double>;

  /** By default, GTK+ will limit rate of input events. On stylus input where
   * accuracy of strokes is paramount, this function returns the accumulated
   * coordinate/timing state before the emission of the current signal_motion() signal.
   *
   * This function may only be called within a signal_motion()
   * signal handler, the state given in this signal and obtainable through
   * get_axis() call expresses the latest (most up-to-date) state in motion history.
   *
   * @return Coordinates and times for the backlog events in chronological order.
   *         If there is no backlog to unfold in the current state, an empty
   *         vector is returned.
   */
  auto get_backlog() const -> std::vector<Gdk::TimeCoord>;


  /** Returns the Gdk::DeviceTool currently driving input through this gesture.
   * This function must be called from either the signal_down(),
   * signal_motion(), signal_up() or signal_proximity() signal handlers.
   *
   * @return The current stylus tool.
   */
  auto get_device_tool() -> Glib::RefPtr<Gdk::DeviceTool>;

  /** Returns the Gdk::DeviceTool currently driving input through this gesture.
   * This function must be called from either the signal_down(),
   * signal_motion(), signal_up() or signal_proximity() signal handlers.
   *
   * @return The current stylus tool.
   */
  auto get_device_tool() const -> Glib::RefPtr<const Gdk::DeviceTool>;

  // no_default_handler because GtkGestureStylusClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%proximity(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the stylus is in proximity of the device.
   *
   * @param x The X coordinate of the stylus event.
   * @param y The Y coordinate of the stylus event.
   */

  auto signal_proximity() -> Glib::SignalProxy<void(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%down(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the stylus touches the device.
   *
   * @param x The X coordinate of the stylus event.
   * @param y The Y coordinate of the stylus event.
   */

  auto signal_down() -> Glib::SignalProxy<void(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%motion(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the stylus moves while touching the device.
   *
   * @param x The X coordinate of the stylus event.
   * @param y The Y coordinate of the stylus event.
   */

  auto signal_motion() -> Glib::SignalProxy<void(double, double)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%up(double x, double y)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the stylus no longer touches the device.
   *
   * @param x The X coordinate of the stylus event.
   * @param y The Y coordinate of the stylus event.
   */

  auto signal_up() -> Glib::SignalProxy<void(double, double)>;


  // GestureStylus has no properties


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
   * @relates Gtk::GestureStylus
   */
  GTKMM_API
  auto wrap(GtkGestureStylus* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureStylus>;
}


#endif /* _GTKMM_GESTURESTYLUS_H */
