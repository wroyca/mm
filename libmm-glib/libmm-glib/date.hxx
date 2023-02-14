
#ifndef _GLIBMM_DATE_H
#define _GLIBMM_DATE_H

#include <ctime>
#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  struct tm;
}
#endif

namespace Glib
{

  class GLIBMM_API Date
  {
  public:
    using Day = guint8;
    using Year = guint16;

    enum class Month
    {
      BAD_MONTH,
      JANUARY,
      FEBRUARY,
      MARCH,
      APRIL,
      MAY,
      JUNE,
      JULY,
      AUGUST,
      SEPTEMBER,
      OCTOBER,
      NOVEMBER,
      DECEMBER
    };

    enum class Weekday
    {
      BAD_WEEKDAY,
      MONDAY,
      TUESDAY,
      WEDNESDAY,
      THURSDAY,
      FRIDAY,
      SATURDAY,
      SUNDAY
    };

    enum class DMY
    {
      DAY,
      MONTH,
      YEAR
    };

    static const Day BAD_DAY = 0;
    static const Year BAD_YEAR = 0;
    static const guint32 BAD_JULIAN = 0;

    Date ();

    Date (Day day, Month month, Year year);

    explicit Date (guint32 julian_day);

    explicit Date (const GDate& castitem);

    Date (const Date& other);

    auto
    operator= (const Date& other) -> Date&;

    auto
    gobj () -> GDate*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GDate*
    {
      return &gobject_;
    }

  private:
    GDate gobject_;

  public:
    void
    clear ();

    void
    set_parse (const Glib::ustring& str);

    void
    set_time (std::time_t timet);

    void
    set_time_current ();

    void
    set_month (Month month);

    void
    set_day (Day day);

    void
    set_year (Year year);

    void
    set_dmy (Day day, Month month, Year year);

    void
    set_julian (guint32 julian_day);

    auto
    add_days (int n_days) -> Date&;

    auto
    subtract_days (int n_days) -> Date&;

    auto
    add_months (int n_months) -> Date&;

    auto
    subtract_months (int n_months) -> Date&;

    auto
    add_years (int n_years) -> Date&;

    auto
    subtract_years (int n_years) -> Date&;

    auto
    days_between (const Date& rhs) const -> int;

    auto
    compare (const Date& rhs) const -> int;

    auto
    clamp (const Date& min_date, const Date& max_date) -> Date&;

    auto
    clamp_min (const Date& min_date) -> Date&;

    auto
    clamp_max (const Date& max_date) -> Date&;

    void
    order (Date& other);

    auto
    get_weekday () const -> Weekday;

    auto
    get_weekday_as_int () const -> int;

    auto
    get_month () const -> Month;

    auto
    get_month_as_int () const -> int;

    auto
    get_year () const -> Year;

    auto
    get_day () const -> Day;

    auto
    get_julian () const -> guint32;

    auto
    get_day_of_year () const -> unsigned int;

    auto
    get_monday_week_of_year () const -> unsigned int;

    auto
    get_sunday_week_of_year () const -> unsigned int;

    auto
    get_iso8601_week_of_year () const -> unsigned int;

    auto
    is_first_of_month () const -> bool;

    auto
    is_last_of_month () const -> bool;

    static auto
    get_days_in_month (Month month, Year year) -> guint8;

    static auto
    get_monday_weeks_in_year (Year year) -> guint8;

    static auto
    get_sunday_weeks_in_year (Year year) -> guint8;

    static auto
    is_leap_year (Year year) -> bool;

    auto
    format_string (const Glib::ustring& format) const -> Glib::ustring;

    void
    to_struct_tm (struct tm& dest) const;

    auto
    valid () const -> bool;

    static auto
    valid_day (Day day) -> bool;

    static auto
    valid_month (Month month) -> bool;

    static auto
    valid_year (Year year) -> bool;

    static auto
    valid_weekday (Weekday weekday) -> bool;

    static auto
    valid_julian (guint32 julian_day) -> bool;

    static auto
    valid_dmy (Day day, Month month, Year year) -> bool;
  };

  inline auto
  operator== (const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) == 0);
  }

  inline auto
  operator!= (const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) != 0);
  }

  inline auto
  operator<(const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) < 0);
  }

  inline auto
  operator> (const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) > 0);
  }

  inline auto
  operator<= (const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) <= 0);
  }

  inline auto
  operator>= (const Date& lhs, const Date& rhs) -> bool
  {
    return (lhs.compare (rhs) >= 0);
  }

} // namespace Glib

#endif
