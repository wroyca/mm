
#ifndef _GLIBMM_DATE_H
#define _GLIBMM_DATE_H


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


#include <libmm-glib/mm-glibconfig.hpp>
#include <libmm-glib/ustring.hpp>
#include <glib.h>
#include <ctime>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { struct tm; }
#endif

namespace Glib
{

/** Julian calendar date.
 */
class GLIBMM_API Date
{
public:
  using Day = guint8 ;
  using Year = guint16;

  /** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var Month BAD_MONTH
 * Invalid value.
 *
 *  @var Month JANUARY
 * January.
 *
 *  @var Month FEBRUARY
 * February.
 *
 *  @var Month MARCH
 * March.
 *
 *  @var Month APRIL
 * April.
 *
 *  @var Month MAY
 * May.
 *
 *  @var Month JUNE
 * June.
 *
 *  @var Month JULY
 * July.
 *
 *  @var Month AUGUST
 * August.
 *
 *  @var Month SEPTEMBER
 * September.
 *
 *  @var Month OCTOBER
 * October.
 *
 *  @var Month NOVEMBER
 * November.
 *
 *  @var Month DECEMBER
 * December.
 *
 *  @enum Month
 *
 * Enumeration representing a month; values are Glib::Date::JANUARY,
 * Glib::Date::FEBRUARY, etc. Glib::Date::BAD_MONTH is the invalid value.
 *
 * @ingroup glibmmEnums
 */
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


  /**
 *  @var Weekday BAD_WEEKDAY
 * Invalid value.
 *
 *  @var Weekday MONDAY
 * Monday.
 *
 *  @var Weekday TUESDAY
 * Tuesday.
 *
 *  @var Weekday WEDNESDAY
 * Wednesday.
 *
 *  @var Weekday THURSDAY
 * Thursday.
 *
 *  @var Weekday FRIDAY
 * Friday.
 *
 *  @var Weekday SATURDAY
 * Saturday.
 *
 *  @var Weekday SUNDAY
 * Sunday.
 *
 *  @enum Weekday
 *
 * Enumeration representing a day of the week; Glib::Date::MONDAY,
 * Glib::Date::TUESDAY, etc. Glib::Date::BAD_WEEKDAY is an invalid weekday.
 *
 * @ingroup glibmmEnums
 */
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


  /**
 *  @var DMY DAY
 * A day.
 *
 *  @var DMY MONTH
 * A month.
 *
 *  @var DMY YEAR
 * A year.
 *
 *  @enum DMY
 *
 * This enumeration isn't used in the API, but may be useful if you need
 * to mark a number as a day, month, or year.
 *
 * @ingroup glibmmEnums
 */
enum class DMY
{
  DAY,
  MONTH,
  YEAR
};


  static const Day     BAD_DAY    = 0;
  static const Year    BAD_YEAR   = 0;
  static const guint32 BAD_JULIAN = 0;

  /** Construct an undefined date.
   */
  Date();

  /** Construct a date with the given day, month and year.
   * @param day The day.
   * @param month The month.
   * @param year The year.
   */
  Date(Day day, Month month, Year year);

  /** Construct a date from a julian day.
   * @param julian_day The julian day (guint32).
   */
  explicit Date(guint32 julian_day);

  /** Construct a Glib::Date by copying the contents of a GDate.
   * @param castitem The GDate.
   *
   * @newin{2,18}
   */
  explicit Date(const GDate& castitem);

  /** Construct a Glib::Date from another.
   * @param other the other Glib::Date.
   *
   * @newin{2,18}
   */
  Date(const Date& other);

  /** Assign another date to this one. For example:
   * @code
   * ...
   * Glib::Date my_date;
   * my_date = other_date;
   * @endcode
   *
   * @param other The other Glib::Date.
   *
   * @newin{2,18}
   */
  auto operator=(const Date& other) -> Date&;

  /// Provides access to the underlying C instance.
  auto       gobj() -> GDate*       { return &gobject_; }

  /// Provides access to the underlying C instance.
  auto gobj() const -> const GDate* { return &gobject_; }

private:
  GDate gobject_;

public:
  /** Clear the date. The cleared dates will not represent an existing date,
   * but will not contain garbage.
   */
  void clear();

  /** Parses a user-inputted string str, and try to figure out what date it represents, taking the current locale into account. If the string is successfully parsed, the date will be valid after the call. Otherwise, it will be invalid.
   * This function is not appropriate for file formats and the like; it isn't very precise, and its exact behavior varies with the locale. It's intended to be a heuristic routine that guesses what the user means by a given string (and it does work pretty well in that capacity).
   * @param str String to parse.
   */
  void set_parse (const Glib::ustring& str);

  /** Sets the value of a date from a <type>std::time_t</type> value.
   *
   * @param timet std::time_t value to set
   *
   * @see set_time_current()
   *
   * Since: 2.10
   */
  void set_time(std::time_t timet);

  /** Set this Glib::Date to the current time.
   */
  void set_time_current();

  /** Sets the month of the year. If the resulting day-month-year triplet is invalid, the date will be invalid.
   * @param month Month to set.
   */
  void set_month(Month month);

  /** Sets the day of the month. If the resulting day-month-year triplet is invalid, the date will be invalid.
   * @param day Day to set.
   */
  void set_day(Day day);

  /** Sets the year. If the resulting day-month-year triplet is invalid, the date will be invalid.
   * @param year Year to set.
   */
  void set_year(Year year);

  /** Sets the value of a day, month, and year.. If the resulting day-month-year triplet is invalid, the date will be invalid.
   * @param day Day to set.
   * @param month Month to set.
   * @param year Year to set.
   */
  void set_dmy(Day day, Month month, Year year);

  /** Sets the value of a GDate from a Julian day number.
   * @param julian_day Julian day to set.
   */
   void set_julian(guint32 julian_day);

  /** Add a number of days to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.add_days(2).add_months(3).add_years(17);
   * @endcode
   *
   * @param n_days Days to add.
   * @return Resulting Date
   */
  auto add_days(int n_days) -> Date&;

  /** Subtract n_days to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.subtract_days(2).subtract_months(3).subtract_years(17);
   * @endcode
   *
   * @param n_days Days to subtract.
   * @return Resulting Date
   */
  auto subtract_days(int n_days) -> Date&;

  /** Add n_months to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.add_years(2).add_months(3).add_days(17);
   * @endcode
   *
   * @param n_months Months to add.
   * @return Resulting Date
   */
  auto add_months(int n_months) -> Date&;

  /** Subtract n_months to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.subtract_years(2).subtract_months(3).subtract_days(17);
   * @endcode
   *
   * @param n_months Months to subtract.
   * @return Resulting Date
   */
  auto subtract_months(int n_months) -> Date&;

  /** Add n_days to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.add_years(2).add_months(3).add_days(17);
   * @endcode
   *
   * @param n_years Years to add.
   * @return Resulting Date
   */
  auto add_years(int n_years) -> Date&;

  /** Subtract n_years to a Date.
   * This method returns a reference to the object itself, so you can write code such as:
   * @code
   * somedate.subtract_years(2).subtract_months(3).subtract_days(17);
   * @endcode
   *
   * @param n_years Years to subtract.
   * @return Resulting Date
   */
  auto subtract_years(int n_years) -> Date&;

  /** Calculate days between two dates.
   * @param rhs Date.
   * @return Numbers of days.
   */
  auto days_between(const Date& rhs) const -> int;

  /** Compare two dates.
   * @param rhs Date to compare.
   * @return Result of comparition.
   */
  auto compare(const Date& rhs) const -> int;

  /** If date is prior to min_date, sets date equal to min_date.
   * If date falls after max_date, sets date equal to max_date. All dates must be valid.
   * See also clamp_min() and clamp_max().
   * This method returns a reference to the object itself.
   * @param min_date Date minimum value.
   * @param max_date Date maximum value.
   * @return Date in interval.
   */
  auto clamp(const Date& min_date, const Date& max_date) -> Date&;

  /** If date is prior to min_date, sets date equal to min_date.
   * See also clamp(), and clamp_max().
   * This method returns a reference to the object itself.
   * @param min_date Date minimum value.
   * @return Date in interval.
   */
  auto clamp_min(const Date& min_date) -> Date&;

  /** If date falls after max_date, sets date equal to max_date.
   * See also clamp(), and clamp_min().
   * This method returns a reference to the object itself.
   * @param max_date Date maximum value.
   * @return Date in interval.
   */
  auto clamp_max(const Date& max_date) -> Date&;

  /** Checks if date is less than or equal to other date, and swap the values if this is not the case.
   * @param other Date ro compare.
   * @return Date.
   */
  void order(Date& other);

  /** Returns the day of the week for a Date. The date must be valid.
   * @return Day of the week as a Date::Weekday.
   */
  auto get_weekday() const -> Weekday;

  /** Returns the day of the week for a Date. The date must be valid.
   * @return Day of the week as an int. Monday=1 .. Sunday=7.
   */
  auto get_weekday_as_int() const -> int;

  /** Returns the month of the year. The date must be valid.
   * @return Month of the year as a Date::Month.
   */
  auto        get_month()               const -> Month;

  /** Returns the month of the year. The date must be valid.
   * @return Month of the year as an int. January=1 .. December=12.
   */
  auto          get_month_as_int()        const -> int;

  /** Returns the year of a Date. The date must be valid.
   * @return Year in which the date falls.
   */
  auto         get_year()                const -> Year;

  /** Returns the day of the month. The date must be valid.
   * @return Day of the month..
   */
  auto          get_day()                 const -> Day;

  /** Returns the Julian day or "serial number" of the Date.
   * The Julian day is simply the number of days since January 1, Year 1;
   * i.e., January 1, Year 1 is Julian day 1; January 2, Year 1 is Julian day 2, etc.
   * The date must be valid.
   * @return Julian day.
   */
  auto      get_julian()              const -> guint32;

  /** Returns the day of the year, where Jan 1 is the first day of the year.
   * The date must be valid.
   * @return Julian day.
   */
  auto get_day_of_year()         const -> unsigned int;

  /** Returns the week of the year, where weeks are understood to start on Monday.
   * If the date is before the first Monday of the year, return 0.
   * The date must be valid.
   * @return Week of the year.
   */
  auto get_monday_week_of_year() const -> unsigned int;

  /** Returns the week of the year during which this date falls, if weeks are understood to being on Sunday.
   * Can return 0 if the day is before the first Sunday of the year.
   * The date must be valid.
   * @return Week of the year.
   */
  auto get_sunday_week_of_year() const -> unsigned int;

  /** Returns the week of the year, where weeks are interpreted according to ISO 8601.
   * The date must be valid.
   * @return ISO 8601 week number of the year.
   *
   * @newin{2,22}
   */
  auto get_iso8601_week_of_year() const -> unsigned int;

  /** Returns true if the date is on the first of a month.
   * The date must be valid.
   * @return true if the date is the first of the month.
   */
  auto         is_first_of_month()       const -> bool;

  /** Returns true if the date is the last day of the month.
   * The date must be valid.
   * @return true if the date is the last day of the month.
   */
  auto         is_last_of_month()        const -> bool;

  /** Returns the number of days in a month, taking leap years into account.
   * @param month Month.
   * @param year Year.
   * @return Number of days in month during the year.
   */
  static auto get_days_in_month(Month month, Year year) -> guint8;

  /** Returns the number of weeks in the year, where weeks are taken to start on Monday. Will be 52 or 53.
   * (Years always have 52 7-day periods, plus 1 or 2 extra days depending on whether it's a leap year. This function is basically telling you how many Mondays are in the year, i.e. there are 53 Mondays if one of the extra days happens to be a Monday.)
   * @param year Year to count weeks in.
   * @return Number of weeks.
   */
  static auto get_monday_weeks_in_year(Year year) -> guint8;

  /** Returns the number of weeks in the year, where weeks are taken to start on Sunday. Will be 52 or 53.
   * (Years always have 52 7-day periods, plus 1 or 2 extra days depending on whether it's a leap year. This function is basically telling you how many Sundays are in the year, i.e. there are 53 Sundays if one of the extra days happens to be a Sunday.)
   * @param year Year to count weeks in.
   * @return Number of weeks.
   */
  static auto get_sunday_weeks_in_year(Year year) -> guint8;

  /** Returns true if the year is a leap year.
   * @param year Year to check.
   * @return true if the year is a leap year.
   */
  static auto   is_leap_year(Year year) -> bool;

  /** Convert date to string.
   * @param format A format string as used by @c strftime(), in UTF-8
   * encoding.  Only date formats are allowed, the result of time formats
   * is undefined.
   * @return The formatted date string.
   * @throw Glib::ConvertError
   */
  auto format_string(const Glib::ustring& format) const -> Glib::ustring;

  /** Fills in the date-related bits of a struct tm using the date value. Initializes the non-date parts with something sane but meaningless.
   * @param dest Struct tm to fill.
   */
  void to_struct_tm(struct tm& dest) const;

  /** Returns true if the Date represents an existing day.
   * @return true if the date is valid.
   */
  auto valid() const -> bool;

  /** Returns true if the day of the month is valid (a day is valid if it's between 1 and 31 inclusive).
   * @param day Day to check.
   * @return true if the day is valid.
   */
  static auto valid_day(Day day) -> bool;

  /** Returns true if the month value is valid. The 12 Date::Month enumeration values are the only valid months.
   * @param month Month to check.
   * @return true if the month is valid.
   */
  static auto valid_month(Month month) -> bool;


  /** Returns true if the year is valid.
   * Any year greater than 0 is valid, though there is a 16-bit limit to what Date will understand.
   * @param year Year to check.
   * @return true if the year is valid.
   */
  static auto valid_year(Year year) -> bool;

  /** Returns true if the weekday is valid.
   * The 7 Date::Weekday enumeration values are the only valid.
   * @param weekday Weekday to check.
   * @return true if the weekday is valid.
   */
  static auto valid_weekday(Weekday weekday) -> bool;

  /** Returns true if the Julian day is valid.
   * Anything greater than zero is basically a valid Julian, though there is a 32-bit limit.
   * @param julian_day Julian day to check.
   * @return true if the Julian day is valid.
   */
  static auto valid_julian(guint32 julian_day) -> bool;


  /** Returns true if the day-month-year triplet forms a valid, existing day in the range of days Date understands (Year 1 or later, no more than a few thousand years in the future).
   * @param day Day to check.
   * @param month Month to check.
   * @param year Year to check.
   * @return true if the date is a valid one.
   */
  static auto valid_dmy(Day day, Month month, Year year) -> bool;
};


/** @relates Glib::Date */
inline auto operator==(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) == 0); }

/** @relates Glib::Date */
inline auto operator!=(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) != 0); }

/** @relates Glib::Date */
inline auto operator<(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) < 0); }

/** @relates Glib::Date */
inline auto operator>(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) > 0); }

/** @relates Glib::Date */
inline auto operator<=(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) <= 0); }

/** @relates Glib::Date */
inline auto operator>=(const Date& lhs, const Date& rhs) -> bool
  { return (lhs.compare(rhs) >= 0); }

} // namespace Glib


#endif /* _GLIBMM_DATE_H */

