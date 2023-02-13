
#ifndef _GTKMM_GESTUREPAN_H
#define _GTKMM_GESTUREPAN_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/gesturedrag.hpp>
#include <mm/gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGesturePan = struct _GtkGesturePan;
using GtkGesturePanClass = struct _GtkGesturePanClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GesturePan_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var PanDirection LEFT
 * Panned towards the left.
 *
 *  @var PanDirection RIGHT
 * Panned towards the right.
 *
 *  @var PanDirection UP
 * Panned upwards.
 *
 *  @var PanDirection DOWN
 * Panned downwards.
 *
 *  @enum PanDirection
 *
 * Describes the panning direction of a Gtk::GesturePan.
 *
 * @ingroup gtkmmEnums
 */
enum class PanDirection
{
  LEFT,
  RIGHT,
  UP,
  DOWN
};


} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PanDirection> : public Glib::Value_Enum<Gtk::PanDirection>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Pan gesture.
 *
 * This is a Gesture implementation able to recognize
 * pan gestures. Those are drags that are locked to happen along one
 * axis. The axis that a GesturePan handles is defined at
 * construct time, and can be changed through set_orientation().
 *
 * When the gesture starts to be recognized, GesturePan will
 * attempt to determine as early as possible whether the sequence
 * is moving in the expected direction, and denying the sequence if
 * this does not happen.
 *
 * Once a panning gesture along the expected axis is recognized,
 * signal_pan() will be emitted as input events
 * are received, containing the offset in the given axis.
 *
 * @newin{3,14}
 *
 * @ingroup Gestures
 */

class GTKMM_API GesturePan : public GestureDrag
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GesturePan;
  using CppClassType = GesturePan_Class;
  using BaseObjectType = GtkGesturePan;
  using BaseClassType = GtkGesturePanClass;

  // noncopyable
  GesturePan(const GesturePan&) = delete;
  auto operator=(const GesturePan&) -> GesturePan& = delete;

private:  friend class GesturePan_Class;
  static CppClassType gesturepan_class_;

protected:
  explicit GesturePan(const Glib::ConstructParams& construct_params);
  explicit GesturePan(GtkGesturePan* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GesturePan(GesturePan&& src) noexcept;
  auto operator=(GesturePan&& src) noexcept -> GesturePan&;

  ~GesturePan() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGesturePan*       { return reinterpret_cast<GtkGesturePan*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGesturePan* { return reinterpret_cast<GtkGesturePan*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGesturePan*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because this constructor shall only be used by derived classes.
   */
  GesturePan();

  /** Constructs a Gesture that recognizes pan gestures.
   */
    explicit GesturePan(Orientation orientation);


public:
  /** Creates a Gesture that recognizes pan gestures.
   *
   * @newin{3,14}
   *
   * @param orientation Expected orientation.
   * @return A RefPtr to a new GesturePan.
   */

  static auto create(Orientation orientation) -> Glib::RefPtr<GesturePan>;


  /** Returns the orientation of the pan gestures that this @a gesture expects.
   *
   * @return The expected orientation for pan gestures.
   */
  auto get_orientation() const -> Orientation;

  /** Sets the orientation to be expected on pan gestures.
   *
   * @param orientation Expected orientation.
   */
  void set_orientation(Orientation orientation);

  // no_default_handler because GtkGesturePanClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pan(PanDirection direction, double offset)</tt>
   *
   * Flags: Run Last
   *
   * Emitted once a panning gesture along the expected axis is detected.
   *
   * @param direction Current direction of the pan gesture.
   * @param offset Offset along the gesture orientation.
   */

  auto signal_pan() -> Glib::SignalProxy<void(PanDirection, double)>;


  /** The expected orientation of pan gestures.
   *
   * Default value: Gtk::Orientation::HORIZONTAL
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_orientation() -> Glib::PropertyProxy< Orientation > ;

/** The expected orientation of pan gestures.
   *
   * Default value: Gtk::Orientation::HORIZONTAL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_orientation() const -> Glib::PropertyProxy_ReadOnly< Orientation >;


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
   * @relates Gtk::GesturePan
   */
  GTKMM_API
  auto wrap(GtkGesturePan* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GesturePan>;
}


#endif /* _GTKMM_GESTUREPAN_H */

