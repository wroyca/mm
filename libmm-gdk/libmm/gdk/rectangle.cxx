// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/rectangle.hxx>
#include <libmm/gdk/rectangle_p.hxx>

#include <cstring>

namespace gdk
{

  Rectangle::Rectangle (int x, int y, int width, int height)
  {
    gobject_.x = x;
    gobject_.y = y;
    gobject_.width = width;
    gobject_.height = height;
  }

  auto
  Rectangle::operator== (const Rectangle& src) const -> bool
  {
    if (!gobj () && !src.gobj ())
      return true;
    else if (!gobj () || !src.gobj ())
      return false;

    return gdk_rectangle_equal (gobj (), src.gobj ());
  }

  auto
  Rectangle::join (const Rectangle& src2) -> Rectangle&
  {
    gdk_rectangle_union (&gobject_,
                         const_cast<GdkRectangle*> (&src2.gobject_),
                         &gobject_);
    return *this;
  }

  auto
  Rectangle::intersect (const Rectangle& src2) -> Rectangle&
  {
    gdk_rectangle_intersect (&gobject_,
                             const_cast<GdkRectangle*> (&src2.gobject_),
                             &gobject_);
    return *this;
  }

  auto
  Rectangle::intersect (const Rectangle& src2, bool& rectangles_intersect) -> Rectangle&
  {
    rectangles_intersect = gdk_rectangle_intersect (
        &gobject_,
        const_cast<GdkRectangle*> (&src2.gobject_),
        &gobject_);
    return *this;
  }

  auto
  Rectangle::intersects (const Rectangle& src2) const -> bool
  {
    return gdk_rectangle_intersect (&gobject_, &src2.gobject_, nullptr);
  }

  auto
  Rectangle::has_zero_area () const -> bool
  {
    return (gobject_.width == 0 || gobject_.height == 0);
  }

  auto
  join (const Rectangle& src1, const Rectangle& src2) -> Rectangle
  {
    Rectangle dest;
    gdk_rectangle_union (src1.gobj (), src2.gobj (), dest.gobj ());
    return dest;
  }

  auto
  intersect (const Rectangle& src1, const Rectangle& src2) -> Rectangle
  {
    Rectangle dest;
    gdk_rectangle_intersect (src1.gobj (), src2.gobj (), dest.gobj ());
    return dest;
  }

  auto
  intersect (const Rectangle& src1,
             const Rectangle& src2,
             bool& rectangles_intersect) -> Rectangle
  {
    Rectangle dest;
    rectangles_intersect =
        gdk_rectangle_intersect (src1.gobj (), src2.gobj (), dest.gobj ());
    return dest;
  }

} // namespace gdk

namespace
{
}

namespace glib
{

  auto
  wrap (GdkRectangle* object) -> gdk::Rectangle&
  {
    return *reinterpret_cast<gdk::Rectangle*> (object);
  }

  auto
  wrap (const GdkRectangle* object) -> const gdk::Rectangle&
  {
    return *reinterpret_cast<const gdk::Rectangle*> (object);
  }

} // namespace glib

namespace gdk
{

  Rectangle::Rectangle (const Rectangle& other) noexcept
    : gobject_ (other.gobject_)
  {
  }

  auto
  Rectangle::operator= (const Rectangle& other) noexcept -> Rectangle&
  {
    gobject_ = other.gobject_;
    return *this;
  }

  Rectangle::Rectangle (Rectangle&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
  }

  auto
  Rectangle::operator= (Rectangle&& other) noexcept -> Rectangle&
  {
    gobject_ = std::move (other.gobject_);
    return *this;
  }

  auto
  Rectangle::get_type () -> GType
  {
    return gdk_rectangle_get_type ();
  }

  Rectangle::Rectangle ()
  {
    std::memset (&gobject_, 0, sizeof (GdkRectangle));
  }

  Rectangle::Rectangle (const GdkRectangle* gobject)
  {
    if (gobject)
      gobject_ = *gobject;
    else
      std::memset (&gobject_, 0, sizeof (GdkRectangle));
  }

  auto
  Rectangle::contains_point (int x, int y) const -> bool
  {
    return gdk_rectangle_contains_point (const_cast<GdkRectangle*> (gobj ()),
                                         x,
                                         y);
  }

  auto
  Rectangle::get_x () const -> int
  {
    return gobj ()->x;
  }

  auto
  Rectangle::set_x (const int& value) -> void
  {
    gobj ()->x = value;
  }

  auto
  Rectangle::get_y () const -> int
  {
    return gobj ()->y;
  }

  auto
  Rectangle::set_y (const int& value) -> void
  {
    gobj ()->y = value;
  }

  auto
  Rectangle::get_width () const -> int
  {
    return gobj ()->width;
  }

  auto
  Rectangle::set_width (const int& value) -> void
  {
    gobj ()->width = value;
  }

  auto
  Rectangle::get_height () const -> int
  {
    return gobj ()->height;
  }

  auto
  Rectangle::set_height (const int& value) -> void
  {
    gobj ()->height = value;
  }

} // namespace gdk
