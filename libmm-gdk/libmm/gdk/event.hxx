// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_EVENT_H
#define _GDKMM_EVENT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/timecoord.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/value.hxx>

#if defined(DELETE) && !defined(GTKMM_MACRO_SHADOW_DELETE)
enum
{
  GTKMM_MACRO_DEFINITION_DELETE = DELETE
};

  #undef DELETE

enum
{
  DELETE = GTKMM_MACRO_DEFINITION_DELETE
};

  #define DELETE                    DELETE
  #define GTKMM_MACRO_SHADOW_DELETE 1
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT DeviceTool;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Drop;
  class LIBMM_GDK_SYMEXPORT Seat;
  class LIBMM_GDK_SYMEXPORT Surface;

  enum class KeyMatch
  {
    NONE,
    PARTIAL,
    EXACT
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::KeyMatch> : public glib::Value_Enum<gdk::KeyMatch>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  struct EventSequence;

  class LIBMM_GDK_SYMEXPORT Event final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Event;
    using BaseObjectType = GdkEvent;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkEvent*;

    auto
    gobj () const -> const GdkEvent*;

    auto
    gobj_copy () const -> GdkEvent*;

    Event () = delete;

    Event (const Event&) = delete;
    auto
    operator= (const Event&) -> Event& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    enum class Type
    {
      DELETE,
      MOTION_NOTIFY,
      BUTTON_PRESS,
      BUTTON_RELEASE,
      KEY_PRESS,
      KEY_RELEASE,
      ENTER_NOTIFY,
      LEAVE_NOTIFY,
      FOCUS_CHANGE,
      PROXIMITY_IN,
      PROXIMITY_OUT,
      DRAG_ENTER,
      DRAG_LEAVE,
      DRAG_MOTION,
      DROP_START,
      SCROLL,
      GRAB_BROKEN,
      TOUCH_BEGIN,
      TOUCH_UPDATE,
      TOUCH_END,
      TOUCH_CANCEL,
      TOUCHPAD_SWIPE,
      TOUCHPAD_PINCH,
      PAD_BUTTON_PRESS,
      PAD_BUTTON_RELEASE,
      PAD_RING,
      PAD_STRIP,
      PAD_GROUP_MODE,
      TOUCHPAD_HOLD,
      EVENT_LAST
    };

    auto
    get_event_type () const -> Type;

    auto
    get_surface () -> glib::RefPtr<Surface>;

    auto
    get_surface () const -> glib::RefPtr<const Surface>;

    auto
    get_seat () -> glib::RefPtr<Seat>;

    auto
    get_seat () const -> glib::RefPtr<const Seat>;

    auto
    get_device () -> glib::RefPtr<Device>;

    auto
    get_device () const -> glib::RefPtr<const Device>;

    auto
    get_device_tool () -> glib::RefPtr<DeviceTool>;

    auto
    get_device_tool () const -> glib::RefPtr<const DeviceTool>;

    auto
    get_time () const -> guint32;

    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_event_sequence () const -> const EventSequence*;

    auto
    get_modifier_state () const -> ModifierType;

    auto
    get_position (double& x, double& y) const -> bool;

    auto
    get_axes () const -> std::vector<double>;

    auto
    get_axis (gdk::AxisUse axis_use, double& value) const -> bool;

    auto
    get_pointer_emulated () const -> bool;

    auto
    get_button () const -> guint;

    auto
    get_direction () const -> ScrollDirection;

    auto
    get_deltas (double& delta_x, double& delta_y) const -> void;

    auto
    get_scroll_unit () const -> ScrollUnit;

    auto
    is_scroll_stop () const -> bool;

    auto
    get_keyval () const -> guint;

    auto
    get_keycode () const -> guint;

    auto
    get_consumed_modifiers () const -> ModifierType;

    auto
    get_layout () const -> guint;

    auto
    get_level () const -> guint;

    auto
    is_modifier () const -> bool;

    auto
    get_focus_in () const -> bool;

    auto
    get_touch_emulating_pointer () const -> bool;

    auto
    get_crossing_mode () const -> CrossingMode;

    auto
    get_crossing_detail () const -> NotifyType;

    auto
    get_crossing_focus () const -> bool;

    auto
    get_touchpad_gesture_phase () const -> TouchpadGesturePhase;

    auto
    get_touchpad_n_fingers () const -> guint;

    auto
    get_touchpad_deltas (double& dx, double& dy) const -> void;

    auto
    get_touchpad_pinch_angle_delta () const -> double;

    auto
    get_touchpad_pinch_scale () const -> double;

    auto
    get_pad_button () const -> guint;

    auto
    get_pad_axis_value (guint& index, double& value) const -> void;

    auto
    get_pad_group_mode (guint& group, guint& mode) const -> void;

    auto
    get_dnd_drop () -> glib::RefPtr<Drop>;

    auto
    get_dnd_drop () const -> glib::RefPtr<const Drop>;

    auto
    get_grab_broken_grab_surface () -> glib::RefPtr<Surface>;

    auto
    get_grab_broken_grab_surface () const -> glib::RefPtr<const Surface>;

    auto
    get_grab_broken_implicit () const -> bool;

    auto
    get_history () const -> std::vector<TimeCoord>;

    auto
    triggers_context_menu () const -> bool;

    auto
    get_distance (const glib::RefPtr<const Event>& event2,
                  double& distance) const -> bool;

    auto
    get_angle (const glib::RefPtr<const Event>& event2, double& angle) const
        -> bool;

    auto
    get_center (const glib::RefPtr<const Event>& event2,
                double& x,
                double& y) const -> bool;

    auto
    matches (guint keyval, ModifierType modifiers) const -> KeyMatch;

    auto
    get_match (guint& keyval, ModifierType& modifiers) const -> bool;
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Event::Type>
    : public glib::Value_Enum<gdk::Event::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkEvent* object, bool take_copy = false) -> glib::RefPtr<gdk::Event>;

} // namespace glib

#endif
