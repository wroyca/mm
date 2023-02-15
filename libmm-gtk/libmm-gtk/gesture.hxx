// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURE_H
#define _GTKMM_GESTURE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/event.hxx>
#include <libmm-gtk/eventcontroller.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGesture = struct _GtkGesture;
using GtkGestureClass = struct _GtkGestureClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Gesture_Class;
}
#endif

namespace Gdk
{
  class LIBMM_GTK_SYMEXPORT Device;
}

namespace Gtk
{

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
  class LIBMM_GTK_SYMEXPORT Value<Gtk::EventSequenceState>
    : public Glib::Value_Enum<Gtk::EventSequenceState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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
    explicit Gesture (const Glib::ConstructParams& construct_params);
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
    get_device () -> Glib::RefPtr<Gdk::Device>;

    auto
    get_device () const -> Glib::RefPtr<const Gdk::Device>;

    auto
    set_state (EventSequenceState state) -> bool;

    auto
    get_sequence_state (Gdk::EventSequence* sequence) const
        -> EventSequenceState;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_sequence_state (Gdk::EventSequence* sequence, EventSequenceState state)
        -> bool;
#endif

    auto
    get_sequences () const -> std::vector<const Gdk::EventSequence*>;

    auto
    get_last_updated_sequence () -> Gdk::EventSequence*;

    auto
    get_last_updated_sequence () const -> const Gdk::EventSequence*;

    auto
    handles_sequence (Gdk::EventSequence* sequence) const -> bool;

    auto
    get_last_event (Gdk::EventSequence* sequence) -> Glib::RefPtr<Gdk::Event>;

    auto
    get_last_event (Gdk::EventSequence* sequence) const
        -> Glib::RefPtr<const Gdk::Event>;

    auto
    get_point (Gdk::EventSequence* sequence, double& x, double& y) const
        -> bool;

    auto
    get_bounding_box (Gdk::Rectangle& rect) const -> bool;

    auto
    get_bounding_box_center (double& x, double& y) const -> bool;

    auto
    is_active () const -> bool;

    auto
    is_recognized () const -> bool;

    auto
    group (const Glib::RefPtr<Gesture>& group_gesture) -> void;

    auto
    ungroup () -> void;

    auto
    get_group () -> std::vector<Glib::RefPtr<Gesture>>;

    auto
    get_group () const -> std::vector<Glib::RefPtr<const Gesture>>;

    auto
    is_grouped_with (const Glib::RefPtr<Gesture>& other) const -> bool;

    auto
    signal_begin () -> Glib::SignalProxy<void (Gdk::EventSequence*)>;

    auto
    signal_end () -> Glib::SignalProxy<void (Gdk::EventSequence*)>;

    auto
    signal_update () -> Glib::SignalProxy<void (Gdk::EventSequence*)>;

    auto
    signal_cancel () -> Glib::SignalProxy<void (Gdk::EventSequence*)>;

    auto
    signal_sequence_state_changed ()
        -> Glib::SignalProxy<void (Gdk::EventSequence*, EventSequenceState)>;

    auto
    property_n_points () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGesture* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Gesture>;
} // namespace Glib

#endif
