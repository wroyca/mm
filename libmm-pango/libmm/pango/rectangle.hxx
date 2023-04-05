// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_RECTANGLE_H
#define _PANGOMM_RECTANGLE_H

#include <libmm/pango/mm-pangoconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <pango/pango.h>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Rectangle
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Rectangle;
    using BaseObjectType = PangoRectangle;
#endif

  private:
  public:
    Rectangle ();
    Rectangle (int x, int y, int width, int height);
    explicit Rectangle (const PangoRectangle* src);

    auto
    set_x (int x) -> void
    {
      gobject_.x = x;
    }

    auto
    set_y (int y) -> void
    {
      gobject_.y = y;
    }

    auto
    set_width (int w) -> void
    {
      gobject_.width = w;
    }

    auto
    set_height (int h) -> void
    {
      gobject_.height = h;
    }

    auto
    get_x () const -> int
    {
      return gobject_.x;
    }

    auto
    get_y () const -> int
    {
      return gobject_.y;
    }

    auto
    get_width () const -> int
    {
      return gobject_.width;
    }

    auto
    get_height () const -> int
    {
      return gobject_.height;
    }

    auto
    get_ascent () const -> int
    {
      return PANGO_ASCENT (*gobj ());
    }

    auto
    get_descent () const -> int
    {
      return PANGO_DESCENT (*gobj ());
    }

    auto
    get_lbearing () const -> int
    {
      return PANGO_LBEARING (*gobj ());
    }

    auto
    get_rbearing () const -> int
    {
      return PANGO_RBEARING (*gobj ());
    }

    auto
    equal (const Rectangle& rhs) const -> bool;

    auto
    gobj () -> PangoRectangle*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const PangoRectangle*
    {
      return &gobject_;
    }

  protected:
    PangoRectangle gobject_;
  };

  inline auto
  operator== (const Rectangle& lhs, const Rectangle& rhs) -> bool
  {
    return lhs.equal (rhs);
  }

  inline auto
  operator!= (const Rectangle& lhs, const Rectangle& rhs) -> bool
  {
    return !lhs.equal (rhs);
  }

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoRectangle* object) -> pango::Rectangle&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (const PangoRectangle* object) -> const pango::Rectangle&;

} // namespace glib

#endif
