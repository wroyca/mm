// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_TIMEZONE_H
#define _GLIBMM_TIMEZONE_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GTimeZone GTimeZone;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GTimeZone GTimeZone;
}
#endif

namespace Glib
{

  enum class TimeType
  {
    STANDARD,
    DAYLIGHT,
    UNIVERSAL
  };

  class GLIBMM_API TimeZone
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

    void
    swap (TimeZone& other) noexcept;

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
    create (const Glib::ustring& identifier) -> TimeZone;
#endif

    static auto
    create_identifier (const Glib::ustring& identifier) -> TimeZone;

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
    get_abbreviation (int interval) const -> Glib::ustring;

    auto
    get_offset (int interval) const -> gint32;

    auto
    is_dst (int interval) const -> bool;

    auto
    get_identifier () const -> Glib::ustring;
  };

} // namespace Glib

namespace Glib
{

  inline void
  swap (TimeZone& lhs, TimeZone& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GTimeZone* object, bool take_copy = false) -> Glib::TimeZone;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GLIBMM_API Value<Glib::TimeZone>
    : public Glib::Value_Boxed<Glib::TimeZone>
  {
  };
#endif

} // namespace Glib

#endif
