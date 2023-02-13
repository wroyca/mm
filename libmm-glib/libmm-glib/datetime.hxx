
#ifndef _GLIBMM_DATETIME_H
#define _GLIBMM_DATETIME_H


/* Copyright (C) 2011 The glibmm Development Team
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


#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/timezone.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>
#include <glib.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDateTime GDateTime;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GDateTime GDateTime; }
#endif

namespace Glib
{

/** A value representing an interval of time, in microseconds.  As GTimeSpan,
 * its underlying type is gint64.
 */
using TimeSpan = GTimeSpan;

/** DateTime - A structure representing Date and Time.
 * DateTime is a structure that combines a Gregorian date and time into a
 * single structure. It provides many conversion and methods to manipulate
 * dates and times. Time precision is provided down to microseconds and the
 * time can range (proleptically) from 0001-01-01 00:00:00 to 9999-12-31
 * 23:59:59.999999. DateTime follows POSIX time in the sense that it is
 * oblivious to leap seconds.
 *
 * DateTime is an immutable object; once it has been created it cannot be
 * modified further. All modifiers will create a new DateTime. Nearly all such
 * functions can fail due to the date or time going out of range, in which case
 * <tt>0</tt> will be returned.
 *
 * Many parts of the API may produce non-obvious results. As an example, adding
 * two months to January 31st will yield March 31st whereas adding one month
 * and then one month again will yield either March 28th or March 29th. Also
 * note that adding 24 hours is not always the same as adding one day (since
 * days containing daylight savings time transitions are either 23 or 25 hours
 * in length).
 * @newin{2,30}
 */
class GLIBMM_API DateTime
{
  // GDateTime is refcounted, but Glib::DateTime is not.
  // GDateTime is immutable. Therefore, there is no problem having several
  // Glib::DateTime instances wrap the same GDateTime, and it's easier to use
  // Glib::DateTime without Glib::RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = DateTime;
  using BaseObjectType = GDateTime;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  DateTime();

  explicit DateTime(GDateTime* gobject, bool make_a_copy = true);

  DateTime(const DateTime& other);
  auto operator=(const DateTime& other) -> DateTime&;

  DateTime(DateTime&& other) noexcept;
  auto operator=(DateTime&& other) noexcept -> DateTime&;

  ~DateTime() noexcept;

  void swap(DateTime& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDateTime*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDateTime* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDateTime*;

protected:
  GDateTime* gobject_;

private:


public:

  /** Creates a DateTime corresponding to this exact instant in the given
   * time zone @a tz.  The time is as accurate as the system allows, to a
   * maximum accuracy of 1 microsecond.
   *
   * This function will always succeed unless GLib is still being used after the
   * year 9999.
   *
   * You should release the return value by calling g_date_time_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @param tz A TimeZone.
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_now(const TimeZone& tz) -> DateTime;

  /** Creates a DateTime corresponding to this exact instant in the local
   * time zone.
   *
   * This is equivalent to calling g_date_time_new_now() with the time
   * zone returned by g_time_zone_new_local().
   *
   * @newin{2,26}
   *
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_now_local() -> DateTime;

  /** Creates a DateTime corresponding to this exact instant in UTC.
   *
   * This is equivalent to calling g_date_time_new_now() with the time
   * zone returned by g_time_zone_new_utc().
   *
   * @newin{2,26}
   *
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_now_utc() -> DateTime;


  /** Creates a DateTime corresponding to the given Unix time @a t in the
   * local time zone.
   *
   * Unix time is the number of seconds that have elapsed since 1970-01-01
   * 00:00:00 UTC, regardless of the local time offset.
   *
   * This call can fail (returning <tt>nullptr</tt>) if @a t represents a time outside
   * of the supported range of DateTime.
   *
   * You should release the return value by calling g_date_time_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @param t The Unix time.
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_now_local(gint64 t) -> DateTime;

  /** Creates a DateTime corresponding to the given Unix time @a t in UTC.
   *
   * Unix time is the number of seconds that have elapsed since 1970-01-01
   * 00:00:00 UTC.
   *
   * This call can fail (returning <tt>nullptr</tt>) if @a t represents a time outside
   * of the supported range of DateTime.
   *
   * You should release the return value by calling g_date_time_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @param t The Unix time.
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_now_utc(gint64 t) -> DateTime;


  /** Creates a DateTime corresponding to the given
   * [ISO 8601 formatted string](https://en.wikipedia.org/wiki/ISO_8601)
   *  @a text. ISO 8601 strings of the form <date><sep><time><tz> are supported, with
   * some extensions from [RFC 3339](https://tools.ietf.org/html/rfc3339) as
   * mentioned below.
   *
   * Note that as DateTime "is oblivious to leap seconds", leap seconds information
   * in an ISO-8601 string will be ignored, so a `23:59:60` time would be parsed as
   * `23:59:59`.
   *
   * <sep> is the separator and can be either 'T', 't' or ' '. The latter two
   * separators are an extension from
   * [RFC 3339](https://tools.ietf.org/html/rfc3339#section-5.6).
   *
   * <date> is in the form:
   *
   * - `YYYY-MM-DD` - Year/month/day, e.g. 2016-08-24.
   * - `YYYYMMDD` - Same as above without dividers.
   * - `YYYY-DDD` - Ordinal day where DDD is from 001 to 366, e.g. 2016-237.
   * - `YYYYDDD` - Same as above without dividers.
   * - `YYYY-Www-D` - Week day where ww is from 01 to 52 and D from 1-7,
   * e.g. 2016-W34-3.
   * - `YYYYWwwD` - Same as above without dividers.
   *
   * <time> is in the form:
   *
   * - `hh:mm:ss(.sss)` - Hours, minutes, seconds (subseconds), e.g. 22:10:42.123.
   * - `hhmmss(.sss)` - Same as above without dividers.
   *
   * <tz> is an optional timezone suffix of the form:
   *
   * - `Z` - UTC.
   * - `+hh:mm` or `-hh:mm` - Offset from UTC in hours and minutes, e.g. +12:00.
   * - `+hh` or `-hh` - Offset from UTC in hours, e.g. +12.
   *
   * If the timezone is not provided in @a text it must be provided in @a default_tz
   * (this field is otherwise ignored).
   *
   * This call can fail (returning <tt>nullptr</tt>) if @a text is not a valid ISO 8601
   * formatted string.
   *
   * You should release the return value by calling g_date_time_unref()
   * when you are done with it.
   *
   * @newin{2,56}
   *
   * @param text An ISO 8601 formatted time string.
   * @param default_tz A TimeZone to use if the text doesn't contain a
   * timezone, or <tt>nullptr</tt>.
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create_from_iso8601(const Glib::ustring& text, const TimeZone& default_tz) -> DateTime;

  /// A create_from_iso8601() convenience overload.
  static auto create_from_iso8601(const Glib::ustring& text) -> DateTime;

  /** Creates a new DateTime corresponding to the given date and time in
   * the time zone @a tz.
   *
   * The @a year must be between 1 and 9999, @a month between 1 and 12 and @a day
   * between 1 and 28, 29, 30 or 31 depending on the month and the year.
   *
   *  @a hour must be between 0 and 23 and @a minute must be between 0 and 59.
   *
   *  @a seconds must be at least 0.0 and must be strictly less than 60.0.
   * It will be rounded down to the nearest microsecond.
   *
   * If the given time is not representable in the given time zone (for
   * example, 02:30 on March 14th 2010 in Toronto, due to daylight savings
   * time) then the time will be rounded up to the nearest existing time
   * (in this case, 03:00).  If this matters to you then you should verify
   * the return value for containing the same as the numbers you gave.
   *
   * In the case that the given time is ambiguous in the given time zone
   * (for example, 01:30 on November 7th 2010 in Toronto, due to daylight
   * savings time) then the time falling within standard (ie:
   * non-daylight) time is taken.
   *
   * It not considered a programmer error for the values to this function
   * to be out of range, but in the case that they are, the function will
   * return <tt>nullptr</tt>.
   *
   * You should release the return value by calling g_date_time_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @param tz A TimeZone.
   * @param year The year component of the date.
   * @param month The month component of the date.
   * @param day The day component of the date.
   * @param hour The hour component of the date.
   * @param minute The minute component of the date.
   * @param seconds The number of seconds past the minute.
   * @return A new DateTime, or <tt>nullptr</tt>.
   */
  static auto create(const TimeZone& tz, int year, int month, int day, int hour, int minute, double seconds) -> DateTime;

  /** Creates a new DateTime corresponding to the given date and time in
   * the local time zone.
   *
   * This call is equivalent to calling g_date_time_new() with the time
   * zone returned by g_time_zone_new_local().
   *
   * @newin{2,26}
   *
   * @param year The year component of the date.
   * @param month The month component of the date.
   * @param day The day component of the date.
   * @param hour The hour component of the date.
   * @param minute The minute component of the date.
   * @param seconds The number of seconds past the minute.
   * @return A DateTime, or <tt>nullptr</tt>.
   */
  static auto create_local(int year, int month, int day, int hour, int minute, double seconds) -> DateTime;

  /** Creates a new DateTime corresponding to the given date and time in
   * UTC.
   *
   * This call is equivalent to calling g_date_time_new() with the time
   * zone returned by g_time_zone_new_utc().
   *
   * @newin{2,26}
   *
   * @param year The year component of the date.
   * @param month The month component of the date.
   * @param day The day component of the date.
   * @param hour The hour component of the date.
   * @param minute The minute component of the date.
   * @param seconds The number of seconds past the minute.
   * @return A DateTime, or <tt>nullptr</tt>.
   */
  static auto create_utc(int year, int month, int day, int hour, int minute, double seconds) -> DateTime;

  /** Returns true if the %DateTime object is valid.
   * This will return false, for instance, if the @a text in create_from_iso8601()
   * is not a valid ISO 8601 formatted string.
   */
  explicit operator bool() const;


  /** Creates a copy of @a datetime and adds the specified timespan to the copy.
   *
   * @newin{2,26}
   *
   * @param timespan A TimeSpan.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add(TimeSpan timespan) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of years to the
   * copy. Add negative values to subtract years.
   *
   * As with g_date_time_add_months(), if the resulting date would be 29th
   * February on a non-leap year, the day will be clamped to 28th February.
   *
   * @newin{2,26}
   *
   * @param years The number of years.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_years(int years) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of months to the
   * copy. Add negative values to subtract months.
   *
   * The day of the month of the resulting DateTime is clamped to the number
   * of days in the updated calendar month. For example, if adding 1 month to
   * 31st January 2018, the result would be 28th February 2018. In 2020 (a leap
   * year), the result would be 29th February.
   *
   * @newin{2,26}
   *
   * @param months The number of months.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_months(int months) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of weeks to the
   * copy. Add negative values to subtract weeks.
   *
   * @newin{2,26}
   *
   * @param weeks The number of weeks.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_weeks(int weeks) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of days to the
   * copy. Add negative values to subtract days.
   *
   * @newin{2,26}
   *
   * @param days The number of days.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_days(int days) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of hours.
   * Add negative values to subtract hours.
   *
   * @newin{2,26}
   *
   * @param hours The number of hours to add.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_hours(int hours) const -> DateTime;

  /** Creates a copy of @a datetime adding the specified number of minutes.
   * Add negative values to subtract minutes.
   *
   * @newin{2,26}
   *
   * @param minutes The number of minutes to add.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_minutes(int minutes) const -> DateTime;

  /** Creates a copy of @a datetime and adds the specified number of seconds.
   * Add negative values to subtract seconds.
   *
   * @newin{2,26}
   *
   * @param seconds The number of seconds to add.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_seconds(double seconds) const -> DateTime;

  /** Creates a new DateTime adding the specified values to the current date and
   * time in @a datetime. Add negative values to subtract.
   *
   * @newin{2,26}
   *
   * @param years The number of years to add.
   * @param months The number of months to add.
   * @param days The number of days to add.
   * @param hours The number of hours to add.
   * @param minutes The number of minutes to add.
   * @param seconds The number of seconds to add.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto add_full(int years, int months, int days, int hours, int minutes, double seconds) const -> DateTime;


  /** Calculates the difference in time between @a *this and @a other.  The
   * TimeSpan that is returned is effectively @a *this - @a other.
   *
   * @newin{2,26}
   *
   * @param other The other DateTime.
   * @return The difference between the two DateTime, as a time
   * span expressed in microseconds.
   */
  auto difference(const DateTime& other) const -> TimeSpan;


  /** A comparison function for DateTimes that is suitable
   * as a CompareFunc.
   *
   * @newin{2,26}
   *
   * @param other The DateTime to compare with.
   * @return -1, 0 or 1 if @a *this is less than, equal to or greater
   * than @a other.
   */
  auto compare(const DateTime& other) const -> int;


  /** Hashes @a datetime into a <tt>unsigned int</tt>, suitable for use within HashTable.
   *
   * @newin{2,26}
   *
   * @return A <tt>unsigned int</tt> containing the hash.
   */
  auto hash() const -> guint;


  /** Checks to see if @a *this and @a other are equal.
   *
   * Equal here means that they represent the same moment after converting
   * them to the same time zone.
   *
   * @newin{2,26}
   *
   * @param other The DateTime to compare with.
   * @return <tt>true</tt> if @a *this and @a other are equal.
   */
  auto equal(const DateTime& other) const -> bool;


  /** Retrieves the Gregorian day, month, and year of a given DateTime.
   *
   * @newin{2,26}
   *
   * @param year The return location for the gregorian year, or <tt>nullptr</tt>.
   * @param month The return location for the month of the year, or <tt>nullptr</tt>.
   * @param day The return location for the day of the month, or <tt>nullptr</tt>.
   */
  void get_ymd(int& year, int& month, int& day) const;

  /** Retrieves the year represented by @a datetime in the Gregorian calendar.
   *
   * @newin{2,26}
   *
   * @return The year represented by @a datetime.
   */
  auto get_year() const -> int;

  /** Retrieves the month of the year represented by @a datetime in the Gregorian
   * calendar.
   *
   * @newin{2,26}
   *
   * @return The month represented by @a datetime.
   */
  auto get_month() const -> int;

  /** Retrieves the day of the month represented by @a datetime in the gregorian
   * calendar.
   *
   * @newin{2,26}
   *
   * @return The day of the month.
   */
  auto get_day_of_month() const -> int;

  /** Returns the ISO 8601 week-numbering year in which the week containing
   *  @a datetime falls.
   *
   * This function, taken together with g_date_time_get_week_of_year() and
   * g_date_time_get_day_of_week() can be used to determine the full ISO
   * week date on which @a datetime falls.
   *
   * This is usually equal to the normal Gregorian year (as returned by
   * g_date_time_get_year()), except as detailed below:
   *
   * For Thursday, the week-numbering year is always equal to the usual
   * calendar year.  For other days, the number is such that every day
   * within a complete week (Monday to Sunday) is contained within the
   * same week-numbering year.
   *
   * For Monday, Tuesday and Wednesday occurring near the end of the year,
   * this may mean that the week-numbering year is one greater than the
   * calendar year (so that these days have the same week-numbering year
   * as the Thursday occurring early in the next year).
   *
   * For Friday, Saturday and Sunday occurring near the start of the year,
   * this may mean that the week-numbering year is one less than the
   * calendar year (so that these days have the same week-numbering year
   * as the Thursday occurring late in the previous year).
   *
   * An equivalent description is that the week-numbering year is equal to
   * the calendar year containing the majority of the days in the current
   * week (Monday to Sunday).
   *
   * Note that January 1 0001 in the proleptic Gregorian calendar is a
   * Monday, so this function never returns 0.
   *
   * @newin{2,26}
   *
   * @return The ISO 8601 week-numbering year for @a datetime.
   */
  auto get_week_numbering_year() const -> int;

  /** Returns the ISO 8601 week number for the week containing @a datetime.
   * The ISO 8601 week number is the same for every day of the week (from
   * Moday through Sunday).  That can produce some unusual results
   * (described below).
   *
   * The first week of the year is week 1.  This is the week that contains
   * the first Thursday of the year.  Equivalently, this is the first week
   * that has more than 4 of its days falling within the calendar year.
   *
   * The value 0 is never returned by this function.  Days contained
   * within a year but occurring before the first ISO 8601 week of that
   * year are considered as being contained in the last week of the
   * previous year.  Similarly, the final days of a calendar year may be
   * considered as being part of the first ISO 8601 week of the next year
   * if 4 or more days of that week are contained within the new year.
   *
   * @newin{2,26}
   *
   * @return The ISO 8601 week number for @a datetime.
   */
  auto get_week_of_year() const -> int;

  /** Retrieves the ISO 8601 day of the week on which @a datetime falls (1 is
   * Monday, 2 is Tuesday... 7 is Sunday).
   *
   * @newin{2,26}
   *
   * @return The day of the week.
   */
  auto get_day_of_week() const -> int;

  /** Retrieves the day of the year represented by @a datetime in the Gregorian
   * calendar.
   *
   * @newin{2,26}
   *
   * @return The day of the year.
   */
  auto get_day_of_year() const -> int;

  /** Retrieves the hour of the day represented by @a datetime
   *
   * @newin{2,26}
   *
   * @return The hour of the day.
   */
  auto get_hour() const -> int;

  /** Retrieves the minute of the hour represented by @a datetime
   *
   * @newin{2,26}
   *
   * @return The minute of the hour.
   */
  auto get_minute() const -> int;

  /** Retrieves the second of the minute represented by @a datetime
   *
   * @newin{2,26}
   *
   * @return The second represented by @a datetime.
   */
  auto get_second() const -> int;

  /** Retrieves the microsecond of the date represented by @a datetime
   *
   * @newin{2,26}
   *
   * @return The microsecond of the second.
   */
  auto get_microsecond() const -> int;

  /** Retrieves the number of seconds since the start of the last minute,
   * including the fractional part.
   *
   * @newin{2,26}
   *
   * @return The number of seconds.
   */
  auto get_seconds() const -> double;

  /** Gives the Unix time corresponding to @a datetime, rounding down to the
   * nearest second.
   *
   * Unix time is the number of seconds that have elapsed since 1970-01-01
   * 00:00:00 UTC, regardless of the time zone associated with @a datetime.
   *
   * @newin{2,26}
   *
   * @return The Unix time corresponding to @a datetime.
   */
  auto to_unix() const -> gint64;

  /** Determines the offset to UTC in effect at the time and in the time
   * zone of @a datetime.
   *
   * The offset is the number of microseconds that you add to UTC time to
   * arrive at local time for the time zone (ie: negative numbers for time
   * zones west of GMT, positive numbers for east).
   *
   * If @a datetime represents UTC time, then the offset is always zero.
   *
   * @newin{2,26}
   *
   * @return The number of microseconds that should be added to UTC to
   * get the local time.
   */
  auto get_utc_offset() const -> TimeSpan;


  /** Get the time zone for this @a datetime.
   *
   * @newin{2,60}
   *
   * @return The time zone.
   */
  auto get_timezone() const -> TimeZone;

  /** Determines the time zone abbreviation to be used at the time and in
   * the time zone of @a datetime.
   *
   * For example, in Toronto this is currently "EST" during the winter
   * months and "EDT" during the summer months when daylight savings
   * time is in effect.
   *
   * @newin{2,26}
   *
   * @return The time zone abbreviation. The returned
   * string is owned by the DateTime and it should not be
   * modified or freed.
   */
  auto get_timezone_abbreviation() const -> Glib::ustring;

  /** Determines if daylight savings time is in effect at the time and in
   * the time zone of @a datetime.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if daylight savings time is in effect.
   */
  auto is_daylight_savings() const -> bool;

  /** Create a new DateTime corresponding to the same instant in time as
   *  @a datetime, but in the time zone @a tz.
   *
   * This call can fail in the case that the time goes out of bounds.  For
   * example, converting 0001-01-01 00:00:00 UTC to a time zone west of
   * Greenwich will fail (due to the year 0 being out of range).
   *
   * @newin{2,26}
   *
   * @param tz The new TimeZone.
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto to_timezone(const TimeZone& tz) const -> DateTime;

  /** Creates a new DateTime corresponding to the same instant in time as
   *  @a datetime, but in the local time zone.
   *
   * This call is equivalent to calling g_date_time_to_timezone() with the
   * time zone returned by g_time_zone_new_local().
   *
   * @newin{2,26}
   *
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto to_local() const -> DateTime;

  /** Creates a new DateTime corresponding to the same instant in time as
   *  @a datetime, but in UTC.
   *
   * This call is equivalent to calling g_date_time_to_timezone() with the
   * time zone returned by g_time_zone_new_utc().
   *
   * @newin{2,26}
   *
   * @return The newly created DateTime which
   * should be freed with g_date_time_unref(), or <tt>nullptr</tt>.
   */
  auto to_utc() const -> DateTime;

  /** Creates a newly allocated string representing the requested @a format_str.
   *
   * The format strings understood by this function are a subset of the
   * strftime() format language as specified by C99.  The \\%D, \\%U and \\%W
   * conversions are not supported, nor is the 'E' modifier.  The GNU
   * extensions \\%k, \\%l, \\%s and \\%P are supported, however, as are the
   * '0', '_' and '-' modifiers. The Python extension \\%f is also supported.
   *
   * In contrast to strftime(), this function always produces a UTF-8
   * string, regardless of the current locale.  Note that the rendering of
   * many formats is locale-dependent and may not match the strftime()
   * output exactly.
   *
   * The following format specifiers are supported:
   *
   * - \\%a: the abbreviated weekday name according to the current locale
   * - \\%A: the full weekday name according to the current locale
   * - \\%b: the abbreviated month name according to the current locale
   * - \\%B: the full month name according to the current locale
   * - \\%c: the preferred date and time representation for the current locale
   * - \\%C: the century number (year/100) as a 2-digit integer (00-99)
   * - \\%d: the day of the month as a decimal number (range 01 to 31)
   * - \\%e: the day of the month as a decimal number (range 1 to 31);
   * single digits are preceded by a figure space
   * - \\%F: equivalent to `%Y-%m-%d` (the ISO 8601 date format)
   * - \\%g: the last two digits of the ISO 8601 week-based year as a
   * decimal number (00-99). This works well with \\%V and \\%u.
   * - \\%G: the ISO 8601 week-based year as a decimal number. This works
   * well with \\%V and \\%u.
   * - \\%h: equivalent to \\%b
   * - \\%H: the hour as a decimal number using a 24-hour clock (range 00 to 23)
   * - \\%I: the hour as a decimal number using a 12-hour clock (range 01 to 12)
   * - \\%j: the day of the year as a decimal number (range 001 to 366)
   * - \\%k: the hour (24-hour clock) as a decimal number (range 0 to 23);
   * single digits are preceded by a figure space
   * - \\%l: the hour (12-hour clock) as a decimal number (range 1 to 12);
   * single digits are preceded by a figure space
   * - \\%m: the month as a decimal number (range 01 to 12)
   * - \\%M: the minute as a decimal number (range 00 to 59)
   * - \\%f: the microsecond as a decimal number (range 000000 to 999999)
   * - \\%p: either "AM" or "PM" according to the given time value, or the
   * corresponding  strings for the current locale.  Noon is treated as
   * "PM" and midnight as "AM". Use of this format specifier is discouraged, as
   * many locales have no concept of AM/PM formatting. Use \\%c or \\%X instead.
   * - \\%P: like \\%p but lowercase: "am" or "pm" or a corresponding string for
   * the current locale. Use of this format specifier is discouraged, as
   * many locales have no concept of AM/PM formatting. Use \\%c or \\%X instead.
   * - \\%r: the time in a.m. or p.m. notation. Use of this format specifier is
   * discouraged, as many locales have no concept of AM/PM formatting. Use \\%c
   * or \\%X instead.
   * - \\%R: the time in 24-hour notation (\\%H:\\%M)
   * - \\%s: the number of seconds since the Epoch, that is, since 1970-01-01
   * 00:00:00 UTC
   * - \\%S: the second as a decimal number (range 00 to 60)
   * - \\%t: a tab character
   * - \\%T: the time in 24-hour notation with seconds (\\%H:\\%M:\\%S)
   * - \\%u: the ISO 8601 standard day of the week as a decimal, range 1 to 7,
   * Monday being 1. This works well with \\%G and \\%V.
   * - \\%V: the ISO 8601 standard week number of the current year as a decimal
   * number, range 01 to 53, where week 1 is the first week that has at
   * least 4 days in the new year. See g_date_time_get_week_of_year().
   * This works well with \\%G and \\%u.
   * - \\%w: the day of the week as a decimal, range 0 to 6, Sunday being 0.
   * This is not the ISO 8601 standard format -- use \\%u instead.
   * - \\%x: the preferred date representation for the current locale without
   * the time
   * - \\%X: the preferred time representation for the current locale without
   * the date
   * - \\%y: the year as a decimal number without the century
   * - \\%Y: the year as a decimal number including the century
   * - \\%z: the time zone as an offset from UTC (+hhmm)
   * - \\%:z: the time zone as an offset from UTC (+hh:mm).
   * This is a gnulib strftime() extension. Since: 2.38
   * - \\%::z: the time zone as an offset from UTC (+hh:mm:ss). This is a
   * gnulib strftime() extension. Since: 2.38
   * - \\%:::z: the time zone as an offset from UTC, with : to necessary
   * precision (e.g., -04, +05:30). This is a gnulib strftime() extension. Since: 2.38
   * - \\%Z: the time zone or name or abbreviation
   * - \\%\\%: a literal \\% character
   *
   * Some conversion specifications can be modified by preceding the
   * conversion specifier by one or more modifier characters. The
   * following modifiers are supported for many of the numeric
   * conversions:
   *
   * - O: Use alternative numeric symbols, if the current locale supports those.
   * - _: Pad a numeric result with spaces. This overrides the default padding
   * for the specifier.
   * - -: Do not pad a numeric result. This overrides the default padding
   * for the specifier.
   * - 0: Pad a numeric result with zeros. This overrides the default padding
   * for the specifier.
   *
   * Additionally, when O is used with B, b, or h, it produces the alternative
   * form of a month name. The alternative form should be used when the month
   * name is used without a day number (e.g., standalone). It is required in
   * some languages (Baltic, Slavic, Greek, and more) due to their grammatical
   * rules. For other languages there is no difference. \\%OB is a GNU and BSD
   * strftime() extension expected to be added to the future POSIX specification,
   * \\%Ob and \\%Oh are GNU strftime() extensions. @newin{2,56}
   *
   * @newin{2,26}
   *
   * @param format_str A valid UTF-8 string, containing the format for the
   * DateTime.
   * @return A newly allocated string formatted to
   * the requested format or <tt>nullptr</tt> in the case that there was an error (such
   * as a format specifier not being supported in the current locale).
   */
  auto format(const Glib::ustring& format_str) const -> Glib::ustring;

  /** Format @a datetime in [ISO 8601 format](https://en.wikipedia.org/wiki/ISO_8601),
   * including the date, time and time zone, and return that as a UTF-8 encoded
   * string.
   *
   * Since GLib 2.66, this will output to sub-second precision if needed.
   *
   * @newin{2,62}
   *
   * @return A newly allocated string formatted in
   * ISO 8601 format or <tt>nullptr</tt> in the case that there was an error.
   */
  auto format_iso8601() const -> Glib::ustring;


};

} // namespace Glib


namespace Glib
{

/** @relates Glib::DateTime
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(DateTime& lhs, DateTime& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Glib

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Glib::DateTime
 */
GLIBMM_API
auto wrap(GDateTime* object, bool take_copy = false) -> Glib::DateTime;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GLIBMM_API Value<Glib::DateTime> : public Glib::Value_Boxed<Glib::DateTime>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GLIBMM_DATETIME_H */

