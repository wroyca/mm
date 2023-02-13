


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/date.hxx>
#include <libmm-glib/date_p.hxx>


/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include <glib/gtestutils.h> //For g_assert() in glib >= 2.15.0
//#include <glib/gmessages.h> //For g_assert() in glib < 2.15.0
#include <glib.h> //For g_assert() in all versions of glib.

#include <algorithm>

#include <libmm-glib/convert.hxx>
#include <libmm-glib/utility.hxx>

namespace Glib
{

Date::Date()
{
  g_date_clear(&gobject_, 1);
}

Date::Date(const Day day, Month month, const Year year)
{
  g_date_clear(&gobject_, 1);
  g_date_set_dmy(&gobject_, day, (GDateMonth)month, year);
}

Date::Date(const guint32 julian_day)
{
  g_date_clear(&gobject_, 1);
  g_date_set_julian(&gobject_, julian_day);
}

Date::Date(const GDate& castitem) : gobject_(castitem)
{
}

Date::Date(const Date& other)
{
  g_date_clear(&gobject_, 1);
  if (g_date_valid(&other.gobject_))
    g_date_set_julian(&gobject_, other.get_julian());
}

auto
Date::operator=(const Date& other) -> Date&
{
  if (&other != this && g_date_valid(&other.gobject_))
    g_date_set_julian(&gobject_, other.get_julian());

  return *this;
}

auto Date::clear () -> void
{
  g_date_clear(&gobject_, 1);
}

auto Date::set_parse (const ustring &str) -> void
{
  g_date_set_parse(&gobject_, str.c_str());
}

auto Date::set_time (
  const std::time_t timet) -> void
{
  g_date_set_time_t(&gobject_, timet);
}

auto Date::set_time_current () -> void
{
  // As suggested in the C documentation:
  g_date_set_time_t(&gobject_, time(nullptr));
}

auto Date::set_month (
  Month month) -> void
{
  g_date_set_month(&gobject_, (GDateMonth)month);
}

auto Date::set_day (
  const Day day) -> void
{
  g_date_set_day(&gobject_, day);
}

auto Date::set_year (
  const Year year) -> void
{
  g_date_set_year(&gobject_, year);
}

auto Date::set_dmy (
  const Day day, Month month, const Year year) -> void
{
  g_date_set_dmy(&gobject_, day, (GDateMonth)month, year);
}

auto Date::set_julian (
  const guint32 julian_day) -> void
{
  g_date_set_julian(&gobject_, julian_day);
}

auto
Date::add_days(
  const int n_days) -> Date&
{
  if (n_days >= 0)
    g_date_add_days(&gobject_, n_days);
  else
    g_date_subtract_days(&gobject_, -n_days);
  return *this;
}

auto
Date::subtract_days(
  const int n_days) -> Date&
{
  if (n_days >= 0)
    g_date_subtract_days(&gobject_, n_days);
  else
    g_date_add_days(&gobject_, -n_days);
  return *this;
}

auto
Date::add_months(
  const int n_months) -> Date&
{
  if (n_months >= 0)
    g_date_add_months(&gobject_, n_months);
  else
    g_date_subtract_months(&gobject_, -n_months);
  return *this;
}

auto
Date::subtract_months(
  const int n_months) -> Date&
{
  if (n_months >= 0)
    g_date_subtract_months(&gobject_, n_months);
  else
    g_date_add_months(&gobject_, -n_months);
  return *this;
}

auto
Date::add_years(
  const int n_years) -> Date&
{
  if (n_years >= 0)
    g_date_add_years(&gobject_, n_years);
  else
    g_date_subtract_years(&gobject_, -n_years);
  return *this;
}

auto
Date::subtract_years(
  const int n_years) -> Date&
{
  if (n_years >= 0)
    g_date_subtract_years(&gobject_, n_years);
  else
    g_date_add_years(&gobject_, -n_years);
  return *this;
}

auto
Date::days_between(const Date& rhs) const -> int
{
  return g_date_days_between(&gobject_, &rhs.gobject_);
}

auto
Date::compare(const Date& rhs) const -> int
{
  return g_date_compare(&gobject_, &rhs.gobject_);
}

auto
Date::clamp(const Date& min_date, const Date& max_date) -> Date&
{
  g_date_clamp(&gobject_, &min_date.gobject_, &max_date.gobject_);
  return *this;
}

auto
Date::clamp_min(const Date& min_date) -> Date&
{
  g_date_clamp(&gobject_, &min_date.gobject_, nullptr /* see the C docs */);
  return *this;
}

auto
Date::clamp_max(const Date& max_date) -> Date&
{
  g_date_clamp(&gobject_, nullptr /* see the C docs */, &max_date.gobject_);
  return *this;
}

auto Date::order (Date &other) -> void
{
  g_date_order(&gobject_, &other.gobject_);
}

auto
Date::get_weekday() const -> Weekday
{
  return (Weekday)g_date_get_weekday(&gobject_);
}

auto Date::get_weekday_as_int() const -> int
{
  return g_date_get_weekday(&gobject_);
}

auto
Date::get_month() const -> Month
{
  return (Month)g_date_get_month(&gobject_);
}

auto Date::get_month_as_int() const -> int
{
  return g_date_get_month(&gobject_);
}

auto
Date::get_year() const -> Year
{
  return g_date_get_year(&gobject_);
}

auto
Date::get_day() const -> Day
{
  return g_date_get_day(&gobject_);
}

auto
Date::get_julian() const -> guint32
{
  return g_date_get_julian(&gobject_);
}

auto
Date::get_day_of_year() const -> unsigned int
{
  return g_date_get_day_of_year(&gobject_);
}

auto
Date::get_monday_week_of_year() const -> unsigned int
{
  return g_date_get_monday_week_of_year(&gobject_);
}

auto
Date::get_sunday_week_of_year() const -> unsigned int
{
  return g_date_get_sunday_week_of_year(&gobject_);
}

auto
Date::get_iso8601_week_of_year() const -> unsigned int
{
  return g_date_get_iso8601_week_of_year(&gobject_);
}

auto
Date::is_first_of_month() const -> bool
{
  return g_date_is_first_of_month(&gobject_);
}

auto
Date::is_last_of_month() const -> bool
{
  return g_date_is_last_of_month(&gobject_);
}

// static
auto
Date::get_days_in_month(
  Month month, const Year year) -> guint8
{
  return g_date_get_days_in_month((GDateMonth)month, year);
}

// static
auto
Date::get_monday_weeks_in_year(
  const Year year) -> guint8
{
  return g_date_get_monday_weeks_in_year(year);
}

// static
auto
Date::get_sunday_weeks_in_year(
  const Year year) -> guint8
{
  return g_date_get_sunday_weeks_in_year(year);
}

// static
auto
Date::is_leap_year(
  const Year year) -> bool
{
  return g_date_is_leap_year(year);
}

auto
Date::format_string(const ustring & format) const -> ustring
{
  struct tm tm_data;
  g_date_to_struct_tm(&gobject_, &tm_data);

  const auto locale_format = locale_from_utf8(format);

  gsize bufsize = std::max<gsize>(2 * locale_format.size(), 128);

  do
  {
    const auto buf = make_unique_ptr_gfree(static_cast<char*>(g_malloc(bufsize)));

    // Set the first byte to something other than '\0', to be able to
    // recognize whether strftime actually failed or just returned "".
    buf.get()[0] = '\1';
    const auto len = strftime(buf.get(), bufsize, locale_format.c_str(), &tm_data);

    if (len != 0 || buf.get()[0] == '\0')
    {
      g_assert(len < bufsize);
      return locale_to_utf8(std::string(buf.get(), len));
    }
  } while ((bufsize *= 2) <= 65536);

  // This error is quite unlikely (unless strftime is buggy).
  g_warning("Glib::Date::format_string(): maximum size of strftime buffer exceeded, giving up");

  return {};
}

auto Date::to_struct_tm (struct tm &dest) const -> void
{
  g_date_to_struct_tm(&gobject_, &dest);
}

auto
Date::valid() const -> bool
{
  return g_date_valid(&gobject_);
}

// static
auto
Date::valid_day(
  const Day day) -> bool
{
  return g_date_valid_day(day);
}

// static
auto
Date::valid_month(
  Month month) -> bool
{
  return g_date_valid_month((GDateMonth)month);
}

// static
auto
Date::valid_year(
  const Year year) -> bool
{
  return g_date_valid_year(year);
}

// static
auto
Date::valid_weekday(
  Weekday weekday) -> bool
{
  return g_date_valid_weekday((GDateWeekday)weekday);
}

// static
auto
Date::valid_julian(
  const guint32 julian_day) -> bool
{
  return g_date_valid_julian(julian_day);
}

// static
auto
Date::valid_dmy(
  const Day day, Month month, const Year year) -> bool
{
  return g_date_valid_dmy(day, (GDateMonth)month, year);
}

} // namespace Glib

namespace
{
} // anonymous namespace


