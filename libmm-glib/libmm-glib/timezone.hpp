
#ifndef _GLIBMM_TIMEZONE_H
#define _GLIBMM_TIMEZONE_H


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


#include <libmm-glib/mm-glibconfig.hpp>
#include <libmm-glib/ustring.hpp>
#include <libmm-glib/value.hpp>
#include <glib.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTimeZone GTimeZone;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GTimeZone GTimeZone; }
#endif

namespace Glib
{

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var TimeType STANDARD
 * The time is in local standard time.
 *
 *  @var TimeType DAYLIGHT
 * The time is in local daylight time.
 *
 *  @var TimeType UNIVERSAL
 * The time is in UTC.
 *
 *  @enum TimeType
 *
 * Disambiguates a given time in two ways.
 *
 * First, specifies if the given time is in universal or local time.
 *
 * Second, if the time is in local time, specifies if it is local
 * standard time or local daylight time.  This is important for the case
 * where the same local time occurs twice (during daylight savings time
 * transitions, for example).
 *
 * @ingroup glibmmEnums
 */
enum class TimeType
{
  STANDARD,
  DAYLIGHT,
  UNIVERSAL
};


/** TimeZone - A structure representing a time zone.
 * TimeZone is a structure that represents a time zone, at no particular point
 * in time. It is immutable.
 *
 * A time zone contains a number of intervals. Each interval has an
 * abbreviation to describe it, an offet to UTC and a flag indicating if the
 * daylight savings time is in effect during that interval. A time zone always
 * has at least one interval -- interval 0.
 *
 * Every UTC time is contained within exactly one interval, but a given local
 * time may be contained within zero, one or two intervals (due to
 * incontinuities associated with daylight savings time).
 *
 * An interval may refer to a specific period of time (eg: the duration of
 * daylight savings time during 2010) or it may refer to many periods of time
 * that share the same properties (eg: all periods of daylight savings time).
 * It is also possible (usually for political reasons) that some properties
 * (like the abbreviation) change between intervals without other properties
 * changing.
 * @newin{2,30}
 */
class GLIBMM_API TimeZone
{
  // GTimeZone is refcounted, but Glib::TimeZone is not.
  // GTimeZone is immutable. Therefore, there is no problem having several
  // Glib::TimeZone instances wrap the same GTimeZone, and it's easier to use
  // Glib::TimeZone without Glib::RefPtr.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TimeZone;
  using BaseObjectType = GTimeZone;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  TimeZone();

  explicit TimeZone(GTimeZone* gobject, bool make_a_copy = true);

  TimeZone(const TimeZone& other);
  auto operator=(const TimeZone& other) -> TimeZone&;

  TimeZone(TimeZone&& other) noexcept;
  auto operator=(TimeZone&& other) noexcept -> TimeZone&;

  ~TimeZone() noexcept;

  void swap(TimeZone& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GTimeZone*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GTimeZone* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GTimeZone*;

protected:
  GTimeZone* gobject_;

private:


public:

#ifndef GLIBMM_DISABLE_DEPRECATED

  /** A version of g_time_zone_new_identifier() which returns the UTC time zone
   * if @a identifier could not be parsed or loaded.
   *
   * If you need to check whether @a identifier was loaded successfully, use
   * g_time_zone_new_identifier().
   *
   * Deprecated: 2.68: Use g_time_zone_new_identifier() instead, as it provides
   * error reporting. Change your code to handle a potentially <tt>nullptr</tt> return
   * value.
   *
   * @newin{2,26}
   *
   * @deprecated Use create_identifier() instead.
   *
   * @param identifier A timezone identifier.
   * @return The requested timezone.
   */
  static auto create(const Glib::ustring& identifier) -> TimeZone;
#endif // GLIBMM_DISABLE_DEPRECATED


  /** Creates a TimeZone corresponding to @a identifier. If @a identifier cannot be
   * parsed or loaded, <tt>nullptr</tt> is returned.
   *
   *  @a identifier can either be an RFC3339/ISO 8601 time offset or
   * something that would pass as a valid value for the `TZ` environment
   * variable (including <tt>nullptr</tt>).
   *
   * In Windows, @a identifier can also be the unlocalized name of a time
   * zone for standard time, for example "Pacific Standard Time".
   *
   * Valid RFC3339 time offsets are `"Z"` (for UTC) or
   * `"±hh:mm"`.  ISO 8601 additionally specifies
   * `"±hhmm"` and `"±hh"`.  Offsets are
   * time values to be added to Coordinated Universal Time (UTC) to get
   * the local time.
   *
   * In UNIX, the `TZ` environment variable typically corresponds
   * to the name of a file in the zoneinfo database, an absolute path to a file
   * somewhere else, or a string in
   * "std offset [dst [offset],start[/time],end[/time]]" (POSIX) format.
   * There  are  no spaces in the specification. The name of standard
   * and daylight savings time zone must be three or more alphabetic
   * characters. Offsets are time values to be added to local time to
   * get Coordinated Universal Time (UTC) and should be
   * `"[±]hh[[:]mm[:ss]]"`.  Dates are either
   * `"Jn"` (Julian day with n between 1 and 365, leap
   * years not counted), `"n"` (zero-based Julian day
   * with n between 0 and 365) or `"Mm.w.d"` (day d
   * (0 <= d <= 6) of week w (1 <= w <= 5) of month m (1 <= m <= 12), day
   * 0 is a Sunday).  Times are in local wall clock time, the default is
   * 02:00:00.
   *
   * In Windows, the "tzn[+|–]hh[:mm[:ss]][dzn]" format is used, but also
   * accepts POSIX format.  The Windows format uses US rules for all time
   * zones; daylight savings time is 60 minutes behind the standard time
   * with date and time of change taken from Pacific Standard Time.
   * Offsets are time values to be added to the local time to get
   * Coordinated Universal Time (UTC).
   *
   * g_time_zone_new_local() calls this function with the value of the
   * `TZ` environment variable. This function itself is independent of
   * the value of `TZ`, but if @a identifier is <tt>nullptr</tt> then `/etc/localtime`
   * will be consulted to discover the correct time zone on UNIX and the
   * registry will be consulted or GetTimeZoneInformation() will be used
   * to get the local time zone on Windows.
   *
   * If intervals are not available, only time zone rules from `TZ`
   * environment variable or other means, then they will be computed
   * from year 1900 to 2037.  If the maximum year for the rules is
   * available and it is greater than 2037, then it will followed
   * instead.
   *
   * See
   * [RFC3339 §5.6](http://tools.ietf.org/html/rfc3339#section-5.6)
   * for a precise definition of valid RFC3339 time offsets
   * (the `time-offset` expansion) and ISO 8601 for the
   * full list of valid time offsets.  See
   * [The GNU C Library manual](http://www.gnu.org/s/libc/manual/html_node/TZ-Variable.html)
   * for an explanation of the possible
   * values of the `TZ` environment variable. See
   * [Microsoft Time Zone Index Values](http://msdn.microsoft.com/en-us/library/ms912391%28v=winembedded.11%29.aspx)
   * for the list of time zones on Windows.
   *
   * You should release the return value by calling g_time_zone_unref()
   * when you are done with it.
   *
   * @newin{2,70}
   *
   * @param identifier A timezone identifier.
   * @return The requested timezone, or <tt>nullptr</tt> on
   * failure.
   */
  static auto create_identifier(const Glib::ustring& identifier) -> TimeZone;

  /** Creates a TimeZone corresponding to local time.  The local time
   * zone may change between invocations to this function; for example,
   * if the system administrator changes it.
   *
   * This is equivalent to calling g_time_zone_new() with the value of
   * the `TZ` environment variable (including the possibility of <tt>nullptr</tt>).
   *
   * You should release the return value by calling g_time_zone_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @return The local timezone.
   */
  static auto create_local() -> TimeZone;

  /** Creates a TimeZone corresponding to UTC.
   *
   * This is equivalent to calling g_time_zone_new() with a value like
   * "Z", "UTC", "+00", etc.
   *
   * You should release the return value by calling g_time_zone_unref()
   * when you are done with it.
   *
   * @newin{2,26}
   *
   * @return The universal timezone.
   */
  static auto create_utc() -> TimeZone;

  /** Returns true if the %TimeZone object is valid.
   * This will return false, for instance, if create_identifier()
   * has been called with an @a identifier that cannot be parsed or loaded.
   * @newin{2,70}
   */
  explicit operator bool() const;


  /** Finds an interval within @a tz that corresponds to the given @a time.
   * The meaning of @a time depends on @a type.
   *
   * If @a type is Glib::TimeType::UNIVERSAL then this function will always
   * succeed (since universal time is monotonic and continuous).
   *
   * Otherwise @a time is treated as local time.  The distinction between
   * Glib::TimeType::STANDARD and Glib::TimeType::DAYLIGHT is ignored except in
   * the case that the given @a time is ambiguous.  In Toronto, for example,
   * 01:30 on November 7th 2010 occurred twice (once inside of daylight
   * savings time and the next, an hour later, outside of daylight savings
   * time).  In this case, the different value of @a type would result in a
   * different interval being returned.
   *
   * It is still possible for this function to fail.  In Toronto, for
   * example, 02:00 on March 14th 2010 does not exist (due to the leap
   * forward to begin daylight savings time).  -1 is returned in that
   * case.
   *
   * @newin{2,26}
   *
   * @param type The TimeType of @a time.
   * @param time A number of seconds since January 1, 1970.
   * @return The interval containing @a time, or -1 in case of failure.
   */
  auto find_interval(TimeType type, gint64 time) const -> int;

  /** Finds an interval within @a tz that corresponds to the given @a time,
   * possibly adjusting @a time if required to fit into an interval.
   * The meaning of @a time depends on @a type.
   *
   * This function is similar to g_time_zone_find_interval(), with the
   * difference that it always succeeds (by making the adjustments
   * described below).
   *
   * In any of the cases where g_time_zone_find_interval() succeeds then
   * this function returns the same value, without modifying @a time.
   *
   * This function may, however, modify @a time in order to deal with
   * non-existent times.  If the non-existent local @a time of 02:30 were
   * requested on March 14th 2010 in Toronto then this function would
   * adjust @a time to be 03:00 and return the interval containing the
   * adjusted time.
   *
   * @newin{2,26}
   *
   * @param type The TimeType of @a time.
   * @param time A pointer to a number of seconds since January 1, 1970.
   * @return The interval containing @a time, never -1.
   */
  auto adjust_time(TimeType type, gint64& time) const -> int;

  /** Determines the time zone abbreviation to be used during a particular
   *  @a interval of time in the time zone @a tz.
   *
   * For example, in Toronto this is currently "EST" during the winter
   * months and "EDT" during the summer months when daylight savings time
   * is in effect.
   *
   * @newin{2,26}
   *
   * @param interval An interval within the timezone.
   * @return The time zone abbreviation, which belongs to @a tz.
   */
  auto get_abbreviation(int interval) const -> Glib::ustring;

  /** Determines the offset to UTC in effect during a particular @a interval
   * of time in the time zone @a tz.
   *
   * The offset is the number of seconds that you add to UTC time to
   * arrive at local time for @a tz (ie: negative numbers for time zones
   * west of GMT, positive numbers for east).
   *
   * @newin{2,26}
   *
   * @param interval An interval within the timezone.
   * @return The number of seconds that should be added to UTC to get the
   * local time in @a tz.
   */
  auto get_offset(int interval) const -> gint32;

  /** Determines if daylight savings time is in effect during a particular
   *  @a interval of time in the time zone @a tz.
   *
   * @newin{2,26}
   *
   * @param interval An interval within the timezone.
   * @return <tt>true</tt> if daylight savings time is in effect.
   */
  auto is_dst(int interval) const -> bool;

  /** Get the identifier of this TimeZone, as passed to g_time_zone_new().
   * If the identifier passed at construction time was not recognised, `UTC` will
   * be returned. If it was <tt>nullptr</tt>, the identifier of the local timezone at
   * construction time will be returned.
   *
   * The identifier will be returned in the same format as provided at
   * construction time: if provided as a time offset, that will be returned by
   * this function.
   *
   * @newin{2,60}
   *
   * @return Identifier for this timezone.
   */
  auto get_identifier() const -> Glib::ustring;


};

} // namespace Glib


namespace Glib
{

/** @relates Glib::TimeZone
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(TimeZone& lhs, TimeZone& rhs) noexcept
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
 * @relates Glib::TimeZone
 */
GLIBMM_API
auto wrap(GTimeZone* object, bool take_copy = false) -> Glib::TimeZone;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GLIBMM_API Value<Glib::TimeZone> : public Glib::Value_Boxed<Glib::TimeZone>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GLIBMM_TIMEZONE_H */

