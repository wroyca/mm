// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURE_H
#define _GTKMM_GESTURE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/event.hxx>
#include <libmm/gtk/eventcontroller.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGesture = struct _GtkGesture;
using GtkGestureClass = struct _GtkGestureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Gesture_Class;
}
#endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT Device;
}

namespace gtk
{

  enum class EventSequenceState
  {
    NONE,
    CLAIMED,
    DENIED
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::EventSequenceState>
    : public glib::Value_Enum<gtk::EventSequenceState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Gesture : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Gesture;
    using CppClassType = Gesture_Class;
    using BaseObjectType = GtkGesture;
    using BaseClassType = GtkGestureClass;

    Gesture (const Gesture&) = delete;
    auto
    operator= (const Gesture&) -> Gesture& = delete;

  private:
    friend class Gesture_Class;
    static CppClassType gesture_class_;

  protected:
    explicit Gesture (const glib::ConstructParams& construct_params);
    explicit Gesture (GtkGesture* castitem);

#endif

  public:
    Gesture (Gesture&& src) noexcept;
    auto
    operator= (Gesture&& src) noexcept -> Gesture&;

    ~Gesture () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGesture*
    {
      return reinterpret_cast<GtkGesture*> (gobject_);
    }

    auto
    gobj () const -> const GtkGesture*
    {
      return reinterpret_cast<GtkGesture*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGesture*;

  private:
  protected:
    Gesture ();

  public:
    auto
    get_device () -> glib::RefPtr<gdk::Device>;

    auto
    get_device () const -> glib::RefPtr<const gdk::Device>;

    auto
    set_state (EventSequenceState state) -> bool;

    auto
    get_sequence_state (gdk::EventSequence* sequence) const
        -> EventSequenceState;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_sequence_state (gdk::EventSequence* sequence, EventSequenceState state)
        -> bool;
#endif

    auto
    get_sequences () const -> std::vector<const gdk::EventSequence*>;

    auto
    get_last_updated_sequence () -> gdk::EventSequence*;

    auto
    get_last_updated_sequence () const -> const gdk::EventSequence*;

    auto
    handles_sequence (gdk::EventSequence* sequence) const -> bool;

    auto
    get_last_event (gdk::EventSequence* sequence) -> glib::RefPtr<gdk::Event>;

    auto
    get_last_event (gdk::EventSequence* sequence) const
        -> glib::RefPtr<const gdk::Event>;

    auto
    get_point (gdk::EventSequence* sequence, double& x, double& y) const
        -> bool;

    auto
    get_bounding_box (gdk::Rectangle& rect) const -> bool;

    auto
    get_bounding_box_center (double& x, double& y) const -> bool;

    auto
    is_active () const -> bool;

    auto
    is_recognized () const -> bool;

    auto
    group (const glib::RefPtr<Gesture>& group_gesture) -> void;

    auto
    ungroup () -> void;

    auto
    get_group () -> std::vector<glib::RefPtr<Gesture>>;

    auto
    get_group () const -> std::vector<glib::RefPtr<const Gesture>>;

    auto
    is_grouped_with (const glib::RefPtr<Gesture>& other) const -> bool;

    auto
    signal_begin () -> glib::SignalProxy<void (gdk::EventSequence*)>;

    auto
    signal_end () -> glib::SignalProxy<void (gdk::EventSequence*)>;

    auto
    signal_update () -> glib::SignalProxy<void (gdk::EventSequence*)>;

    auto
    signal_cancel () -> glib::SignalProxy<void (gdk::EventSequence*)>;

    auto
    signal_sequence_state_changed ()
        -> glib::SignalProxy<void (gdk::EventSequence*, EventSequenceState)>;

    auto
    property_n_points () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGesture* object, bool take_copy = false) -> glib::RefPtr<gtk::Gesture>;
} // namespace glib

#endif
