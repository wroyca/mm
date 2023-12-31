// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/calendar.hxx>
#include <libmm/gtk/calendar_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace
{

  static const glib::SignalProxyInfo Calendar_signal_day_selected_info = {
      "day_selected",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Calendar_signal_prev_month_info = {
      "prev_month",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Calendar_signal_next_month_info = {
      "next_month",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Calendar_signal_prev_year_info = {
      "prev_year",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Calendar_signal_next_year_info = {
      "next_year",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkCalendar* object, bool take_copy) -> gtk::Calendar*
  {
    return dynamic_cast<gtk::Calendar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Calendar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Calendar_Class::class_init_function;

      register_derived_type (gtk_calendar_get_type ());
    }

    return *this;
  }

  auto
  Calendar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Calendar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Calendar ((GtkCalendar*) (o)));
  }

  Calendar::Calendar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Calendar::Calendar (GtkCalendar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Calendar::Calendar (Calendar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Calendar::operator= (Calendar&& src) noexcept -> Calendar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Calendar::~Calendar () noexcept
  {
    destroy_ ();
  }

  Calendar::CppClassType Calendar::calendar_class_;

  auto
  Calendar::get_type () -> GType
  {
    return calendar_class_.init ().get_type ();
  }

  auto
  Calendar::get_base_type () -> GType
  {
    return gtk_calendar_get_type ();
  }

  Calendar::Calendar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (calendar_class_.init ()))
  {
  }

  auto
  Calendar::select_day (const glib::DateTime& day) -> void
  {
    gtk_calendar_select_day (gobj (), const_cast<GDateTime*> (day.gobj ()));
  }

  auto
  Calendar::mark_day (guint day) -> void
  {
    gtk_calendar_mark_day (gobj (), day);
  }

  auto
  Calendar::unmark_day (guint day) -> void
  {
    gtk_calendar_unmark_day (gobj (), day);
  }

  auto
  Calendar::clear_marks () -> void
  {
    gtk_calendar_clear_marks (gobj ());
  }

  auto
  Calendar::set_show_week_numbers (bool value) -> void
  {
    gtk_calendar_set_show_week_numbers (gobj (), static_cast<int> (value));
  }

  auto
  Calendar::get_show_week_numbers () const -> bool
  {
    return gtk_calendar_get_show_week_numbers (
        const_cast<GtkCalendar*> (gobj ()));
  }

  auto
  Calendar::set_show_heading (bool value) -> void
  {
    gtk_calendar_set_show_heading (gobj (), static_cast<int> (value));
  }

  auto
  Calendar::get_show_heading () const -> bool
  {
    return gtk_calendar_get_show_heading (const_cast<GtkCalendar*> (gobj ()));
  }

  auto
  Calendar::set_show_day_names (bool value) -> void
  {
    gtk_calendar_set_show_day_names (gobj (), static_cast<int> (value));
  }

  auto
  Calendar::get_show_day_names () const -> bool
  {
    return gtk_calendar_get_show_day_names (const_cast<GtkCalendar*> (gobj ()));
  }

  auto
  Calendar::get_date () const -> glib::DateTime
  {
    return glib::wrap (
        gtk_calendar_get_date (const_cast<GtkCalendar*> (gobj ())));
  }

  auto
  Calendar::get_day_is_marked (guint day) const -> bool
  {
    return gtk_calendar_get_day_is_marked (const_cast<GtkCalendar*> (gobj ()),
                                           day);
  }

  auto
  Calendar::signal_day_selected () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &Calendar_signal_day_selected_info);
  }

  auto
  Calendar::signal_prev_month () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Calendar_signal_prev_month_info);
  }

  auto
  Calendar::signal_next_month () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Calendar_signal_next_month_info);
  }

  auto
  Calendar::signal_prev_year () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Calendar_signal_prev_year_info);
  }

  auto
  Calendar::signal_next_year () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Calendar_signal_next_year_info);
  }

  auto
  Calendar::property_year () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "year");
  }

  auto
  Calendar::property_year () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "year");
  }

  auto
  Calendar::property_month () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "month");
  }

  auto
  Calendar::property_month () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "month");
  }

  auto
  Calendar::property_day () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "day");
  }

  auto
  Calendar::property_day () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "day");
  }

  auto
  Calendar::property_show_heading () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-heading");
  }

  auto
  Calendar::property_show_heading () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-heading");
  }

  auto
  Calendar::property_show_day_names () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-day-names");
  }

  auto
  Calendar::property_show_day_names () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-day-names");
  }

  auto
  Calendar::property_show_week_numbers () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-week-numbers");
  }

  auto
  Calendar::property_show_week_numbers () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-week-numbers");
  }

} // namespace gtk
