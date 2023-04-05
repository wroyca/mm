// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/timezone.hxx>
#include <libmm/glib/timezone_p.hxx>

#include <libmm/glib/utility.hxx>

namespace glib
{

  TimeZone::operator bool () const
  {
    return gobject_ != nullptr;
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  wrap (GTimeZone* object, const bool take_copy) -> TimeZone
  {
    return TimeZone (object, take_copy);
  }

} // namespace glib

namespace glib
{

  auto
  TimeZone::get_type () -> GType
  {
    return g_time_zone_get_type ();
  }

  TimeZone::TimeZone ()
    : gobject_ (nullptr)
  {
  }

  TimeZone::TimeZone (const TimeZone& other)
    : gobject_ (other.gobject_ ? g_time_zone_ref (other.gobject_) : nullptr)
  {
  }

  TimeZone::TimeZone (TimeZone&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  TimeZone::operator= (TimeZone&& other) noexcept -> TimeZone&
  {
    TimeZone temp (std::move (other));
    swap (temp);
    return *this;
  }

  TimeZone::TimeZone (GTimeZone* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? g_time_zone_ref (gobject) : gobject)
  {
  }

  auto
  TimeZone::operator= (const TimeZone& other) -> TimeZone&
  {
    TimeZone temp (other);
    swap (temp);
    return *this;
  }

  TimeZone::~TimeZone () noexcept
  {
    if (gobject_)
      g_time_zone_unref (gobject_);
  }

  auto
  TimeZone::swap (TimeZone& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  TimeZone::gobj_copy () const -> GTimeZone*
  {
    return g_time_zone_ref (gobject_);
  }

#ifndef GLIBMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  TimeZone::create (const ustring& identifier) -> TimeZone
  {
    return wrap (g_time_zone_new (identifier.c_str ()));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  TimeZone::create_identifier (const ustring& identifier) -> TimeZone
  {
    return wrap (g_time_zone_new_identifier (identifier.c_str ()));
  }

  auto
  TimeZone::create_local () -> TimeZone
  {
    return wrap (g_time_zone_new_local ());
  }

  auto
  TimeZone::create_utc () -> TimeZone
  {
    return wrap (g_time_zone_new_utc ());
  }

  auto
  TimeZone::find_interval (TimeType type, const gint64 time) const -> int
  {
    return g_time_zone_find_interval (const_cast<GTimeZone*> (gobj ()),
                                      static_cast<GTimeType> (type),
                                      time);
  }

  auto
  TimeZone::adjust_time (TimeType type, gint64& time) const -> int
  {
    return g_time_zone_adjust_time (const_cast<GTimeZone*> (gobj ()),
                                    static_cast<GTimeType> (type),
                                    &time);
  }

  auto
  TimeZone::get_abbreviation (const int interval) const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_time_zone_get_abbreviation (const_cast<GTimeZone*> (gobj ()),
                                      interval));
  }

  auto
  TimeZone::get_offset (const int interval) const -> gint32
  {
    return g_time_zone_get_offset (const_cast<GTimeZone*> (gobj ()), interval);
  }

  auto
  TimeZone::is_dst (const int interval) const -> bool
  {
    return g_time_zone_is_dst (const_cast<GTimeZone*> (gobj ()), interval);
  }

  auto
  TimeZone::get_identifier () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_time_zone_get_identifier (const_cast<GTimeZone*> (gobj ())));
  }

} // namespace glib
