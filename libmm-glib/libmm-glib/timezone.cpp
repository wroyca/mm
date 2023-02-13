


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/timezone.hpp>
#include <mm/glib/private/timezone_p.hpp>


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

#include <mm/glib/utility.hpp>

namespace Glib
{

TimeZone::operator bool() const
{
  return gobject_ != nullptr;
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GTimeZone* object, const bool take_copy) -> TimeZone
{
  return TimeZone(object, take_copy);
}

} // namespace Glib


namespace Glib
{


// static
auto TimeZone::get_type() -> GType
{
  return g_time_zone_get_type();
}

TimeZone::TimeZone()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

TimeZone::TimeZone(const TimeZone& other)
:
  gobject_ (other.gobject_ ? g_time_zone_ref(other.gobject_) : nullptr)
{}

TimeZone::TimeZone(TimeZone&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto TimeZone::operator=(TimeZone&& other) noexcept -> TimeZone&
{
  TimeZone temp (std::move(other));
  swap(temp);
  return *this;
}

TimeZone::TimeZone(GTimeZone* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? g_time_zone_ref(gobject) : gobject)
{}

auto TimeZone::operator=(const TimeZone& other) -> TimeZone&
{
  TimeZone temp (other);
  swap(temp);
  return *this;
}

TimeZone::~TimeZone() noexcept
{
  if(gobject_)
    g_time_zone_unref(gobject_);
}

auto TimeZone::swap (TimeZone &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto TimeZone::gobj_copy() const -> GTimeZone*
{
  return g_time_zone_ref(gobject_);
}


#ifndef GLIBMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto TimeZone::create(const ustring & identifier) -> TimeZone
{
  return wrap(g_time_zone_new(identifier.c_str()));
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GLIBMM_DISABLE_DEPRECATED

auto TimeZone::create_identifier(const ustring & identifier) -> TimeZone
{
  return wrap(g_time_zone_new_identifier(identifier.c_str()));
}

auto TimeZone::create_local() -> TimeZone
{
  return wrap(g_time_zone_new_local());
}

auto TimeZone::create_utc() -> TimeZone
{
  return wrap(g_time_zone_new_utc());
}

auto TimeZone::find_interval(TimeType type, const gint64 time) const -> int
{
  return g_time_zone_find_interval(const_cast<GTimeZone*>(gobj()), static_cast<GTimeType>(type), time);
}

auto TimeZone::adjust_time(TimeType type, gint64& time) const -> int
{
  return g_time_zone_adjust_time(const_cast<GTimeZone*>(gobj()), static_cast<GTimeType>(type), &time);
}

auto TimeZone::get_abbreviation(
  const int interval) const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_time_zone_get_abbreviation(const_cast<GTimeZone*>(gobj()), interval));
}

auto TimeZone::get_offset(
  const int interval) const -> gint32
{
  return g_time_zone_get_offset(const_cast<GTimeZone*>(gobj()), interval);
}

auto TimeZone::is_dst(
  const int interval) const -> bool
{
  return g_time_zone_is_dst(const_cast<GTimeZone*>(gobj()), interval);
}

auto TimeZone::get_identifier() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_time_zone_get_identifier(const_cast<GTimeZone*>(gobj())));
}


} // namespace Glib


