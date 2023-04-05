// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CALENDAR_H
#define _GTKMM_CALENDAR_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/datetime.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCalendar = struct _GtkCalendar;
using GtkCalendarClass = struct _GtkCalendarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Calendar_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Calendar : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class Calendar_Class;
    static CppClassType calendar_class_;

  protected:
    explicit Calendar (const glib::ConstructParams& construct_params);
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
    select_day (const glib::DateTime& day) -> void;

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
    get_date () const -> glib::DateTime;

    auto
    get_day_is_marked (guint day) const -> bool;

    auto
    signal_day_selected () -> glib::SignalProxy<void ()>;

    auto
    signal_prev_month () -> glib::SignalProxy<void ()>;

    auto
    signal_next_month () -> glib::SignalProxy<void ()>;

    auto
    signal_prev_year () -> glib::SignalProxy<void ()>;

    auto
    signal_next_year () -> glib::SignalProxy<void ()>;

    auto
    property_year () -> glib::PropertyProxy<int>;

    auto
    property_year () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_month () -> glib::PropertyProxy<int>;

    auto
    property_month () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_day () -> glib::PropertyProxy<int>;

    auto
    property_day () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_show_heading () -> glib::PropertyProxy<bool>;

    auto
    property_show_heading () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_day_names () -> glib::PropertyProxy<bool>;

    auto
    property_show_day_names () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_week_numbers () -> glib::PropertyProxy<bool>;

    auto
    property_show_week_numbers () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCalendar* object, bool take_copy = false) -> gtk::Calendar*;
} // namespace glib

#endif
