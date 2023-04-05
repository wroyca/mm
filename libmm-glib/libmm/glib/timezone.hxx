// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_TIMEZONE_H
#define _GLIBMM_TIMEZONE_H

#include <glib.h>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTimeZone GTimeZone;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GTimeZone GTimeZone;
}
#endif

namespace glib
{

  enum class TimeType
  {
    STANDARD,
    DAYLIGHT,
    UNIVERSAL
  };

  class LIBMM_GLIB_SYMEXPORT TimeZone
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TimeZone;
    using BaseObjectType = GTimeZone;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    TimeZone ();

    explicit TimeZone (GTimeZone* gobject, bool make_a_copy = true);

    TimeZone (const TimeZone& other);
    auto
    operator= (const TimeZone& other) -> TimeZone&;

    TimeZone (TimeZone&& other) noexcept;
    auto
    operator= (TimeZone&& other) noexcept -> TimeZone&;

    ~TimeZone () noexcept;

    auto
    swap (TimeZone& other) noexcept -> void;

    auto
    gobj () -> GTimeZone*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GTimeZone*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GTimeZone*;

  protected:
    GTimeZone* gobject_;

  private:
  public:
#ifndef GLIBMM_DISABLE_DEPRECATED

    static auto
    create (const glib::ustring& identifier) -> TimeZone;
#endif

    static auto
    create_identifier (const glib::ustring& identifier) -> TimeZone;

    static auto
    create_local () -> TimeZone;

    static auto
    create_utc () -> TimeZone;

    explicit operator bool () const;

    auto
    find_interval (TimeType type, gint64 time) const -> int;

    auto
    adjust_time (TimeType type, gint64& time) const -> int;

    auto
    get_abbreviation (int interval) const -> glib::ustring;

    auto
    get_offset (int interval) const -> gint32;

    auto
    is_dst (int interval) const -> bool;

    auto
    get_identifier () const -> glib::ustring;
  };

} // namespace glib

namespace glib
{

  inline auto
  swap (TimeZone& lhs, TimeZone& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace glib

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GTimeZone* object, bool take_copy = false) -> glib::TimeZone;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GLIB_SYMEXPORT Value<glib::TimeZone>
    : public glib::Value_Boxed<glib::TimeZone>
  {
  };
#endif

} // namespace glib

#endif
