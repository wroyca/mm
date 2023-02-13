


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/calendar.hxx>
#include <libmm-gtk/calendar_p.hxx>

#include <gtk/gtk.h>

/*
 * Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

namespace
{


const Glib::SignalProxyInfo Calendar_signal_day_selected_info =
{
  "day_selected",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Calendar_signal_prev_month_info =
{
  "prev_month",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Calendar_signal_next_month_info =
{
  "next_month",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Calendar_signal_prev_year_info =
{
  "prev_year",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Calendar_signal_next_year_info =
{
  "next_year",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkCalendar* object, const bool take_copy) -> Gtk::Calendar*
{
  return dynamic_cast<Gtk::Calendar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Calendar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Calendar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_calendar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Calendar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Calendar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Calendar((GtkCalendar*)o));

}


/* The implementation: */

Calendar::Calendar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Calendar::Calendar(GtkCalendar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Calendar::Calendar(Calendar&& src) noexcept
: Widget(std::move(src))
{}

auto Calendar::operator=(Calendar&& src) noexcept -> Calendar&
{
  Widget::operator=(std::move(src));
  return *this;
}

Calendar::~Calendar() noexcept
{
  destroy_();
}

Calendar::CppClassType Calendar::calendar_class_; // initialize static member

auto Calendar::get_type() -> GType
{
  return calendar_class_.init().get_type();
}


auto Calendar::get_base_type() -> GType
{
  return gtk_calendar_get_type();
}


Calendar::Calendar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(calendar_class_.init()))
{


}

auto Calendar::select_day (const Glib::DateTime &day) -> void
{
  gtk_calendar_select_day(gobj(), const_cast<GDateTime*>(day.gobj()));
}

auto Calendar::mark_day (
  const guint day) -> void
{
  gtk_calendar_mark_day(gobj(), day);
}

auto Calendar::unmark_day (
  const guint day) -> void
{
  gtk_calendar_unmark_day(gobj(), day);
}

auto Calendar::clear_marks () -> void
{
  gtk_calendar_clear_marks(gobj());
}

auto Calendar::set_show_week_numbers (
  const bool value) -> void
{
  gtk_calendar_set_show_week_numbers(gobj(), value);
}

auto Calendar::get_show_week_numbers() const -> bool
{
  return gtk_calendar_get_show_week_numbers(const_cast<GtkCalendar*>(gobj()));
}

auto Calendar::set_show_heading (
  const bool value) -> void
{
  gtk_calendar_set_show_heading(gobj(), value);
}

auto Calendar::get_show_heading() const -> bool
{
  return gtk_calendar_get_show_heading(const_cast<GtkCalendar*>(gobj()));
}

auto Calendar::set_show_day_names (
  const bool value) -> void
{
  gtk_calendar_set_show_day_names(gobj(), value);
}

auto Calendar::get_show_day_names() const -> bool
{
  return gtk_calendar_get_show_day_names(const_cast<GtkCalendar*>(gobj()));
}

auto Calendar::get_date() const -> Glib::DateTime
{
  return Glib::wrap(gtk_calendar_get_date(const_cast<GtkCalendar*>(gobj())));
}

auto Calendar::get_day_is_marked(
  const guint day) const -> bool
{
  return gtk_calendar_get_day_is_marked(const_cast<GtkCalendar*>(gobj()), day);
}


auto Calendar::signal_day_selected() -> Glib::SignalProxy<void()>
{
  return {this, &Calendar_signal_day_selected_info};
}


auto Calendar::signal_prev_month() -> Glib::SignalProxy<void()>
{
  return {this, &Calendar_signal_prev_month_info};
}


auto Calendar::signal_next_month() -> Glib::SignalProxy<void()>
{
  return {this, &Calendar_signal_next_month_info};
}


auto Calendar::signal_prev_year() -> Glib::SignalProxy<void()>
{
  return {this, &Calendar_signal_prev_year_info};
}


auto Calendar::signal_next_year() -> Glib::SignalProxy<void()>
{
  return {this, &Calendar_signal_next_year_info};
}


auto Calendar::property_year() -> Glib::PropertyProxy< int >
{
  return {this, "year"};
}

auto Calendar::property_year() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "year"};
}

auto Calendar::property_month() -> Glib::PropertyProxy< int >
{
  return {this, "month"};
}

auto Calendar::property_month() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "month"};
}

auto Calendar::property_day() -> Glib::PropertyProxy< int >
{
  return {this, "day"};
}

auto Calendar::property_day() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "day"};
}

auto Calendar::property_show_heading() -> Glib::PropertyProxy< bool >
{
  return {this, "show-heading"};
}

auto Calendar::property_show_heading() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-heading"};
}

auto Calendar::property_show_day_names() -> Glib::PropertyProxy< bool >
{
  return {this, "show-day-names"};
}

auto Calendar::property_show_day_names() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-day-names"};
}

auto Calendar::property_show_week_numbers() -> Glib::PropertyProxy< bool >
{
  return {this, "show-week-numbers"};
}

auto Calendar::property_show_week_numbers() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-week-numbers"};
}


} // namespace Gtk


