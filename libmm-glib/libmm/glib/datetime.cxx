// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/datetime.hxx>
#include <libmm/glib/datetime_p.hxx>

#include <libmm/glib/utility.hxx>
#include <libmm/glib/wrap.hxx>

namespace Glib
{

  DateTime::operator bool () const
  {
    return gobject_ != nullptr;
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GDateTime* object, const bool take_copy) -> DateTime
  {
    return DateTime (object, take_copy);
  }

} // namespace Glib

namespace Glib
{

  auto
  DateTime::get_type () -> GType
  {
    return g_date_time_get_type ();
  }

  DateTime::DateTime ()
    : gobject_ (nullptr)
  {
  }

  DateTime::DateTime (const DateTime& other)
    : gobject_ (other.gobject_ ? g_date_time_ref (other.gobject_) : nullptr)
  {
  }

  DateTime::DateTime (DateTime&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  DateTime::operator= (DateTime&& other) noexcept -> DateTime&
  {
    DateTime temp (std::move (other));
    swap (temp);
    return *this;
  }

  DateTime::DateTime (GDateTime* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? g_date_time_ref (gobject) : gobject)
  {
  }

  auto
  DateTime::operator= (const DateTime& other) -> DateTime&
  {
    DateTime temp (other);
    swap (temp);
    return *this;
  }

  DateTime::~DateTime () noexcept
  {
    if (gobject_)
      g_date_time_unref (gobject_);
  }

  auto
  DateTime::swap (DateTime& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  DateTime::gobj_copy () const -> GDateTime*
  {
    return g_date_time_ref (gobject_);
  }

  auto
  DateTime::create_now (const TimeZone& tz) -> DateTime
  {
    return wrap (g_date_time_new_now (const_cast<GTimeZone*> (tz.gobj ())));
  }

  auto
  DateTime::create_now_local () -> DateTime
  {
    return wrap (g_date_time_new_now_local ());
  }

  auto
  DateTime::create_now_utc () -> DateTime
  {
    return wrap (g_date_time_new_now_utc ());
  }

  auto
  DateTime::create_now_local (const gint64 t) -> DateTime
  {
    return wrap (g_date_time_new_from_unix_local (t));
  }

  auto
  DateTime::create_now_utc (const gint64 t) -> DateTime
  {
    return wrap (g_date_time_new_from_unix_utc (t));
  }

  auto
  DateTime::create_from_iso8601 (const ustring& text,
                                 const TimeZone& default_tz) -> DateTime
  {
    return wrap (g_date_time_new_from_iso8601 (
        text.c_str (),
        const_cast<GTimeZone*> (default_tz.gobj ())));
  }

  auto
  DateTime::create_from_iso8601 (const ustring& text) -> DateTime
  {
    return wrap (g_date_time_new_from_iso8601 (text.c_str (), nullptr));
  }

  auto
  DateTime::create (const TimeZone& tz,
                    const int year,
                    const int month,
                    const int day,
                    const int hour,
                    const int minute,
                    const double seconds) -> DateTime
  {
    return wrap (g_date_time_new (const_cast<GTimeZone*> (tz.gobj ()),
                                  year,
                                  month,
                                  day,
                                  hour,
                                  minute,
                                  seconds));
  }

  auto
  DateTime::create_local (const int year,
                          const int month,
                          const int day,
                          const int hour,
                          const int minute,
                          const double seconds) -> DateTime
  {
    return wrap (
        g_date_time_new_local (year, month, day, hour, minute, seconds));
  }

  auto
  DateTime::create_utc (const int year,
                        const int month,
                        const int day,
                        const int hour,
                        const int minute,
                        const double seconds) -> DateTime
  {
    return wrap (g_date_time_new_utc (year, month, day, hour, minute, seconds));
  }

  auto
  DateTime::add (const TimeSpan timespan) const -> DateTime
  {
    return wrap (g_date_time_add (const_cast<GDateTime*> (gobj ()), timespan));
  }

  auto
  DateTime::add_years (const int years) const -> DateTime
  {
    return wrap (
        g_date_time_add_years (const_cast<GDateTime*> (gobj ()), years));
  }

  auto
  DateTime::add_months (const int months) const -> DateTime
  {
    return wrap (
        g_date_time_add_months (const_cast<GDateTime*> (gobj ()), months));
  }

  auto
  DateTime::add_weeks (const int weeks) const -> DateTime
  {
    return wrap (
        g_date_time_add_weeks (const_cast<GDateTime*> (gobj ()), weeks));
  }

  auto
  DateTime::add_days (const int days) const -> DateTime
  {
    return wrap (g_date_time_add_days (const_cast<GDateTime*> (gobj ()), days));
  }

  auto
  DateTime::add_hours (const int hours) const -> DateTime
  {
    return wrap (
        g_date_time_add_hours (const_cast<GDateTime*> (gobj ()), hours));
  }

  auto
  DateTime::add_minutes (const int minutes) const -> DateTime
  {
    return wrap (
        g_date_time_add_minutes (const_cast<GDateTime*> (gobj ()), minutes));
  }

  auto
  DateTime::add_seconds (const double seconds) const -> DateTime
  {
    return wrap (
        g_date_time_add_seconds (const_cast<GDateTime*> (gobj ()), seconds));
  }

  auto
  DateTime::add_full (const int years,
                      const int months,
                      const int days,
                      const int hours,
                      const int minutes,
                      const double seconds) const -> DateTime
  {
    return wrap (g_date_time_add_full (const_cast<GDateTime*> (gobj ()),
                                       years,
                                       months,
                                       days,
                                       hours,
                                       minutes,
                                       seconds));
  }

  auto
  DateTime::difference (const DateTime& other) const -> TimeSpan
  {
    return g_date_time_difference (const_cast<GDateTime*> (gobj ()),
                                   const_cast<GDateTime*> (other.gobj ()));
  }

  auto
  DateTime::compare (const DateTime& other) const -> int
  {
    return g_date_time_compare (gobj (), other.gobj ());
  }

  auto
  DateTime::hash () const -> guint
  {
    return g_date_time_hash (gobj ());
  }

  auto
  DateTime::equal (const DateTime& other) const -> bool
  {
    return g_date_time_equal (gobj (), other.gobj ());
  }

  auto
  DateTime::get_ymd (int& year, int& month, int& day) const -> void
  {
    g_date_time_get_ymd (const_cast<GDateTime*> (gobj ()), &year, &month, &day);
  }

  auto
  DateTime::get_year () const -> int
  {
    return g_date_time_get_year (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_month () const -> int
  {
    return g_date_time_get_month (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_day_of_month () const -> int
  {
    return g_date_time_get_day_of_month (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_week_numbering_year () const -> int
  {
    return g_date_time_get_week_numbering_year (
        const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_week_of_year () const -> int
  {
    return g_date_time_get_week_of_year (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_day_of_week () const -> int
  {
    return g_date_time_get_day_of_week (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_day_of_year () const -> int
  {
    return g_date_time_get_day_of_year (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_hour () const -> int
  {
    return g_date_time_get_hour (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_minute () const -> int
  {
    return g_date_time_get_minute (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_second () const -> int
  {
    return g_date_time_get_second (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_microsecond () const -> int
  {
    return g_date_time_get_microsecond (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_seconds () const -> double
  {
    return g_date_time_get_seconds (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::to_unix () const -> gint64
  {
    return g_date_time_to_unix (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_utc_offset () const -> TimeSpan
  {
    return g_date_time_get_utc_offset (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::get_timezone () const -> TimeZone
  {
    return wrap (g_date_time_get_timezone (const_cast<GDateTime*> (gobj ())),
                 true);
  }

  auto
  DateTime::get_timezone_abbreviation () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_date_time_get_timezone_abbreviation (
            const_cast<GDateTime*> (gobj ())));
  }

  auto
  DateTime::is_daylight_savings () const -> bool
  {
    return g_date_time_is_daylight_savings (const_cast<GDateTime*> (gobj ()));
  }

  auto
  DateTime::to_timezone (const TimeZone& tz) const -> DateTime
  {
    return wrap (g_date_time_to_timezone (const_cast<GDateTime*> (gobj ()),
                                          const_cast<GTimeZone*> (tz.gobj ())));
  }

  auto
  DateTime::to_local () const -> DateTime
  {
    return wrap (g_date_time_to_local (const_cast<GDateTime*> (gobj ())));
  }

  auto
  DateTime::to_utc () const -> DateTime
  {
    return wrap (g_date_time_to_utc (const_cast<GDateTime*> (gobj ())));
  }

  auto
  DateTime::format (const ustring& format_str) const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_date_time_format (const_cast<GDateTime*> (gobj ()),
                            format_str.c_str ()));
  }

  auto
  DateTime::format_iso8601 () const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_date_time_format_iso8601 (const_cast<GDateTime*> (gobj ())));
  }

} // namespace Glib
