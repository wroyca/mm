// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CALENDAR_H
#define _GTKMM_CALENDAR_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/datetime.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCalendar = struct _GtkCalendar;
using GtkCalendarClass = struct _GtkCalendarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Calendar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Calendar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Calendar CppObjectType;
    typedef Calendar_Class CppClassType;
    typedef GtkCalendar BaseObjectType;
    typedef GtkCalendarClass BaseClassType;
#endif

    Calendar (Calendar&& src) noexcept;
    auto
    operator= (Calendar&& src) noexcept -> Calendar&;

    Calendar (const Calendar&) = delete;
    auto
    operator= (const Calendar&) -> Calendar& = delete;

    ~Calendar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Calendar_Class;
    static CppClassType calendar_class_;

  protected:
    explicit Calendar (const Glib::ConstructParams& construct_params);
    explicit Calendar (GtkCalendar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCalendar*
    {
      return reinterpret_cast<GtkCalendar*> (gobject_);
    }

    auto
    gobj () const -> const GtkCalendar*
    {
      return reinterpret_cast<GtkCalendar*> (gobject_);
    }

  private:
  public:
    Calendar ();

    auto
    select_day (const Glib::DateTime& day) -> void;

    auto
    mark_day (guint day) -> void;

    auto
    unmark_day (guint day) -> void;

    auto
    clear_marks () -> void;

    auto
    set_show_week_numbers (bool value = true) -> void;

    auto
    get_show_week_numbers () const -> bool;

    auto
    set_show_heading (bool value = true) -> void;

    auto
    get_show_heading () const -> bool;

    auto
    set_show_day_names (bool value = true) -> void;

    auto
    get_show_day_names () const -> bool;

    auto
    get_date () const -> Glib::DateTime;

    auto
    get_day_is_marked (guint day) const -> bool;

    auto
    signal_day_selected () -> Glib::SignalProxy<void ()>;

    auto
    signal_prev_month () -> Glib::SignalProxy<void ()>;

    auto
    signal_next_month () -> Glib::SignalProxy<void ()>;

    auto
    signal_prev_year () -> Glib::SignalProxy<void ()>;

    auto
    signal_next_year () -> Glib::SignalProxy<void ()>;

    auto
    property_year () -> Glib::PropertyProxy<int>;

    auto
    property_year () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_month () -> Glib::PropertyProxy<int>;

    auto
    property_month () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_day () -> Glib::PropertyProxy<int>;

    auto
    property_day () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_show_heading () -> Glib::PropertyProxy<bool>;

    auto
    property_show_heading () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_day_names () -> Glib::PropertyProxy<bool>;

    auto
    property_show_day_names () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_week_numbers () -> Glib::PropertyProxy<bool>;

    auto
    property_show_week_numbers () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkCalendar* object, bool take_copy = false) -> Gtk::Calendar*;
} // namespace Glib

#endif
