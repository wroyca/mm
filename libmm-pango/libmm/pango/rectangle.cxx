// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/rectangle.hxx>
#include <libmm/pango/rectangle_p.hxx>

namespace pango
{

  Rectangle::Rectangle ()
  {
    gobject_.x = gobject_.y = 0;
    gobject_.width = gobject_.height = 0;
  }

  Rectangle::Rectangle (const int x,
                        const int y,
                        const int width,
                        const int height)
  {
    gobject_.x = x;
    gobject_.y = y;
    gobject_.width = width;
    gobject_.height = height;
  }

  Rectangle::Rectangle (const PangoRectangle* src)
  {
    gobject_.x = src->x;
    gobject_.y = src->y;
    gobject_.width = src->width;
    gobject_.height = src->height;
  }

  auto
  Rectangle::equal (const Rectangle& rhs) const -> bool
  {
    return get_x () == rhs.get_x () && get_y () == rhs.get_y () &&
           get_width () == rhs.get_width () &&
           get_height () == rhs.get_height ();
  }

} // namespace pango

namespace glib
{

  auto
  wrap (PangoRectangle* object) -> pango::Rectangle&
  {
    return *reinterpret_cast<pango::Rectangle*> (object);
  }

  auto
  wrap (const PangoRectangle* object) -> const pango::Rectangle&
  {
    return *reinterpret_cast<const pango::Rectangle*> (object);
  }

} // namespace glib

namespace
{
}

namespace pango
{

}
