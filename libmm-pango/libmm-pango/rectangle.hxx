
#ifndef _PANGOMM_RECTANGLE_H
#define _PANGOMM_RECTANGLE_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <pango/pango.h>

namespace Pango
{

  class PANGOMM_API Rectangle
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

    void
    set_x (int x)
    {
      gobject_.x = x;
    }

    void
    set_y (int y)
    {
      gobject_.y = y;
    }

    void
    set_width (int w)
    {
      gobject_.width = w;
    }

    void
    set_height (int h)
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

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoRectangle* object) -> Pango::Rectangle&;

  PANGOMM_API
  auto
  wrap (const PangoRectangle* object) -> const Pango::Rectangle&;

} // namespace Glib

#endif
