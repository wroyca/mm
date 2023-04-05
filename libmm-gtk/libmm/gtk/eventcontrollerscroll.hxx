// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLERSCROLL_H
#define _GTKMM_EVENTCONTROLLERSCROLL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerScroll = struct _GtkEventControllerScroll;
using GtkEventControllerScrollClass = struct _GtkEventControllerScrollClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EventControllerScroll_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT EventControllerScroll : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventControllerScroll;
    using CppClassType = EventControllerScroll_Class;
    using BaseObjectType = GtkEventControllerScroll;
    using BaseClassType = GtkEventControllerScrollClass;

    EventControllerScroll (const EventControllerScroll&) = delete;
    auto
    operator= (const EventControllerScroll&) -> EventControllerScroll& = delete;

  private:
    friend class EventControllerScroll_Class;
    static CppClassType eventcontrollerscroll_class_;

  protected:
    explicit EventControllerScroll (
        const glib::ConstructParams& construct_params);
    explicit EventControllerScroll (GtkEventControllerScroll* castitem);

#endif

  public:
    EventControllerScroll (EventControllerScroll&& src) noexcept;
    auto
    operator= (EventControllerScroll&& src) noexcept -> EventControllerScroll&;

    ~EventControllerScroll () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventControllerScroll*
    {
      return reinterpret_cast<GtkEventControllerScroll*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventControllerScroll*
    {
      return reinterpret_cast<GtkEventControllerScroll*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventControllerScroll*;

  private:
  protected:
    EventControllerScroll ();

  public:
    enum class Flags
    {
      NONE = 0x0,
      VERTICAL = 1 << 0,
      HORIZONTAL = 1 << 1,
      DISCRETE = 1 << 2,
      KINETIC = 1 << 3,
      BOTH_AXES = 0x3
    };

    static auto
    create () -> glib::RefPtr<EventControllerScroll>;

    auto
    set_flags (Flags flags) -> void;

    auto
    get_flags () const -> Flags;

    auto
    get_unit () const -> gdk::ScrollUnit;

    auto
    property_flags () -> glib::PropertyProxy<Flags>;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    signal_scroll_begin () -> glib::SignalProxy<void ()>;

    auto
    signal_scroll () -> glib::SignalProxy<bool (double, double)>;

    auto
    signal_scroll_end () -> glib::SignalProxy<void ()>;

    auto
    signal_decelerate () -> glib::SignalProxy<void (double, double)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace gtk
{

  inline auto
  operator| (EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  {
    return static_cast<EventControllerScroll::Flags> (
        static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  {
    return static_cast<EventControllerScroll::Flags> (
        static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (EventControllerScroll::Flags lhs, EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags
  {
    return static_cast<EventControllerScroll::Flags> (
        static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(EventControllerScroll::Flags flags) -> EventControllerScroll::Flags
  {
    return static_cast<EventControllerScroll::Flags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (EventControllerScroll::Flags& lhs,
              EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  {
    return (lhs = static_cast<EventControllerScroll::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (EventControllerScroll::Flags& lhs,
              EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  {
    return (lhs = static_cast<EventControllerScroll::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (EventControllerScroll::Flags& lhs,
              EventControllerScroll::Flags rhs) -> EventControllerScroll::Flags&
  {
    return (lhs = static_cast<EventControllerScroll::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::EventControllerScroll::Flags>
    : public glib::Value_Flags<gtk::EventControllerScroll::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEventControllerScroll* object, bool take_copy = false) -> glib::RefPtr<gtk::EventControllerScroll>;
} // namespace glib

#endif
