// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TIMECOORD_H
#define _GDKMM_TIMECOORD_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>

namespace Gdk
{

  class GDKMM_API TimeCoord
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TimeCoord;
    using BaseObjectType = GdkTimeCoord;
#endif

  private:
  public:
    explicit TimeCoord (GdkTimeCoord* gobject, bool make_a_copy = true);

    TimeCoord (const TimeCoord& other);
    auto
    operator= (const TimeCoord& other) -> TimeCoord&;

    TimeCoord (TimeCoord&& other) noexcept;
    auto
    operator= (TimeCoord&& other) noexcept -> TimeCoord&;

    ~TimeCoord () noexcept;

    auto
    get_time () const -> guint32;

    auto
    get_value_at_axis (guint index) const -> double;

    auto
    gobj () -> GdkTimeCoord*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GdkTimeCoord*
    {
      return gobject_;
    }

  protected:
    GdkTimeCoord* gobject_;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  struct TimeCoordPtrTraits
  {
    using CppType = Gdk::TimeCoord;
    using CType = GdkTimeCoord*;
    using CTypeNonConst = GdkTimeCoord*;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return const_cast<CType> (obj.gobj ());
    }

    static auto
    to_c_type (const CType& obj) -> CType
    {
      return obj;
    }

    static auto
    to_cpp_type (const CType& obj) -> CppType
    {
      return CppType (const_cast<CType> (obj));
    }

    static auto
    release_c_type (const CType& obj) -> void
    {
      g_free (const_cast<CType> (obj));
    }
  };

  struct TimeCoordTraits
  {
    using CppType = Gdk::TimeCoord;
    using CType = GdkTimeCoord;
    using CTypeNonConst = GdkTimeCoord;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return *obj.gobj ();
    }

    static auto
    to_c_type (const CType& obj) -> CType
    {
      return obj;
    }

    static auto
    to_cpp_type (const CType& obj) -> CppType
    {
      return CppType (const_cast<CType*> (&obj), true);
    }

    static auto
    release_c_type (const CType&) -> void
    {
    }
  };
#endif

} // namespace Gdk

#endif
