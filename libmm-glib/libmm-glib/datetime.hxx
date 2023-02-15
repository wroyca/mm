// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_DATETIME_H
#define _GLIBMM_DATETIME_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/timezone.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDateTime GDateTime;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GDateTime GDateTime;
}
#endif

namespace Glib
{

  using TimeSpan = GTimeSpan;

  class GLIBMM_API DateTime
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DateTime;
    using BaseObjectType = GDateTime;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    DateTime ();

    explicit DateTime (GDateTime* gobject, bool make_a_copy = true);

    DateTime (const DateTime& other);
    auto
    operator= (const DateTime& other) -> DateTime&;

    DateTime (DateTime&& other) noexcept;
    auto
    operator= (DateTime&& other) noexcept -> DateTime&;

    ~DateTime () noexcept;

    auto
    swap (DateTime& other) noexcept -> void;

    auto
    gobj () -> GDateTime*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GDateTime*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GDateTime*;

  protected:
    GDateTime* gobject_;

  private:
  public:
    static auto
    create_now (const TimeZone& tz) -> DateTime;

    static auto
    create_now_local () -> DateTime;

    static auto
    create_now_utc () -> DateTime;

    static auto
    create_now_local (gint64 t) -> DateTime;

    static auto
    create_now_utc (gint64 t) -> DateTime;

    static auto
    create_from_iso8601 (const Glib::ustring& text, const TimeZone& default_tz)
        -> DateTime;

    static auto
    create_from_iso8601 (const Glib::ustring& text) -> DateTime;

    static auto
    create (const TimeZone& tz,
            int year,
            int month,
            int day,
            int hour,
            int minute,
            double seconds) -> DateTime;

    static auto
    create_local (int year,
                  int month,
                  int day,
                  int hour,
                  int minute,
                  double seconds) -> DateTime;

    static auto
    create_utc (int year,
                int month,
                int day,
                int hour,
                int minute,
                double seconds) -> DateTime;

    explicit operator bool () const;

    auto
    add (TimeSpan timespan) const -> DateTime;

    auto
    add_years (int years) const -> DateTime;

    auto
    add_months (int months) const -> DateTime;

    auto
    add_weeks (int weeks) const -> DateTime;

    auto
    add_days (int days) const -> DateTime;

    auto
    add_hours (int hours) const -> DateTime;

    auto
    add_minutes (int minutes) const -> DateTime;

    auto
    add_seconds (double seconds) const -> DateTime;

    auto
    add_full (int years,
              int months,
              int days,
              int hours,
              int minutes,
              double seconds) const -> DateTime;

    auto
    difference (const DateTime& other) const -> TimeSpan;

    auto
    compare (const DateTime& other) const -> int;

    auto
    hash () const -> guint;

    auto
    equal (const DateTime& other) const -> bool;

    auto
    get_ymd (int& year, int& month, int& day) const -> void;

    auto
    get_year () const -> int;

    auto
    get_month () const -> int;

    auto
    get_day_of_month () const -> int;

    auto
    get_week_numbering_year () const -> int;

    auto
    get_week_of_year () const -> int;

    auto
    get_day_of_week () const -> int;

    auto
    get_day_of_year () const -> int;

    auto
    get_hour () const -> int;

    auto
    get_minute () const -> int;

    auto
    get_second () const -> int;

    auto
    get_microsecond () const -> int;

    auto
    get_seconds () const -> double;

    auto
    to_unix () const -> gint64;

    auto
    get_utc_offset () const -> TimeSpan;

    auto
    get_timezone () const -> TimeZone;

    auto
    get_timezone_abbreviation () const -> Glib::ustring;

    auto
    is_daylight_savings () const -> bool;

    auto
    to_timezone (const TimeZone& tz) const -> DateTime;

    auto
    to_local () const -> DateTime;

    auto
    to_utc () const -> DateTime;

    auto
    format (const Glib::ustring& format_str) const -> Glib::ustring;

    auto
    format_iso8601 () const -> Glib::ustring;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  swap (DateTime& lhs, DateTime& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GDateTime* object, bool take_copy = false) -> Glib::DateTime;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GLIBMM_API Value<Glib::DateTime>
    : public Glib::Value_Boxed<Glib::DateTime>
  {
  };
#endif

} // namespace Glib

#endif
