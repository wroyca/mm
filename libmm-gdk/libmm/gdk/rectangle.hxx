// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_RECTANGLE_H
#define _GDKMM_RECTANGLE_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/glib/value.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Rectangle
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Rectangle;
    using BaseObjectType = GdkRectangle;
#endif

    Rectangle (const Rectangle& other) noexcept;
    auto
    operator= (const Rectangle& other) noexcept -> Rectangle&;

    Rectangle (Rectangle&& other) noexcept;
    auto
    operator= (Rectangle&& other) noexcept -> Rectangle&;

    static auto
    get_type () -> GType G_GNUC_CONST;

    Rectangle ();

    explicit Rectangle (const GdkRectangle* gobject);

    auto
    gobj () -> GdkRectangle*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GdkRectangle*
    {
      return &gobject_;
    }

  protected:
    GdkRectangle gobject_;

  private:
  public:
    Rectangle (int x, int y, int width, int height);

    auto
    operator== (const Rectangle& src) const -> bool;

    auto
    join (const Rectangle& src2) -> Rectangle&;

    auto
    intersect (const Rectangle& src2) -> Rectangle&;

    auto
    intersect (const Rectangle& src2, bool& rectangles_intersect) -> Rectangle&;

    auto
    intersects (const Rectangle& src2) const -> bool;

    auto
    has_zero_area () const -> bool;

    auto
    contains_point (int x, int y) const -> bool;

    auto
    get_x () const -> int;
    auto
    set_x (const int& value) -> void;
    auto
    get_y () const -> int;
    auto
    set_y (const int& value) -> void;
    auto
    get_width () const -> int;
    auto
    set_width (const int& value) -> void;
    auto
    get_height () const -> int;
    auto
    set_height (const int& value) -> void;
  };

  LIBMM_GDK_SYMEXPORT auto
  join (const Rectangle& src1, const Rectangle& src2) -> Rectangle;

  LIBMM_GDK_SYMEXPORT auto
  intersect (const Rectangle& src1, const Rectangle& src2) -> Rectangle;

  LIBMM_GDK_SYMEXPORT auto
  intersect (const Rectangle& src1,
             const Rectangle& src2,
             bool& rectangles_intersect) -> Rectangle;

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkRectangle* object) -> gdk::Rectangle&;

  LIBMM_GDK_SYMEXPORT auto
  wrap (const GdkRectangle* object) -> const gdk::Rectangle&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Rectangle>
    : public glib::Value_Boxed<gdk::Rectangle>
  {
  };
#endif

} // namespace glib

#endif
