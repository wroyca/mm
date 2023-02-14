// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_RECTANGLE_H
#define _GDKMM_RECTANGLE_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm-glib/value.hxx>

namespace Gdk
{

  class GDKMM_API Rectangle
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
    void
    set_x (const int& value);
    auto
    get_y () const -> int;
    void
    set_y (const int& value);
    auto
    get_width () const -> int;
    void
    set_width (const int& value);
    auto
    get_height () const -> int;
    void
    set_height (const int& value);
  };

  GDKMM_API
  auto
  join (const Rectangle& src1, const Rectangle& src2) -> Rectangle;

  GDKMM_API
  auto
  intersect (const Rectangle& src1, const Rectangle& src2) -> Rectangle;

  GDKMM_API
  auto
  intersect (const Rectangle& src1,
             const Rectangle& src2,
             bool& rectangles_intersect) -> Rectangle;

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkRectangle* object) -> Gdk::Rectangle&;

  GDKMM_API
  auto
  wrap (const GdkRectangle* object) -> const Gdk::Rectangle&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GDKMM_API Value<Gdk::Rectangle>
    : public Glib::Value_Boxed<Gdk::Rectangle>
  {
  };
#endif

} // namespace Glib

#endif
