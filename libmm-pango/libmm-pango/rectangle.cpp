


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/rectangle.hpp>
#include <libmm-pango/rectangle_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

namespace Pango
{

Rectangle::Rectangle()
{
  gobject_.x = gobject_.y = 0;
  gobject_.width = gobject_.height = 0;
}

Rectangle::Rectangle(const int x, const int y, const int width, const int height)
{
  gobject_.x = x;
  gobject_.y = y;
  gobject_.width = width;
  gobject_.height = height;
}

Rectangle::Rectangle(const PangoRectangle* src)
{
  gobject_.x = src->x;
  gobject_.y = src->y;
  gobject_.width = src->width;
  gobject_.height = src->height;
}

auto Rectangle::equal(const Rectangle& rhs) const -> bool
{
  return get_x() == rhs.get_x() && get_y() == rhs.get_y() &&
    get_width() == rhs.get_width() && get_height() == rhs.get_height();
}

} /* namespace Pango */


namespace Glib
{

auto wrap(PangoRectangle* object) -> Pango::Rectangle&
{
  return *reinterpret_cast<Pango::Rectangle*>(object);
}

auto wrap(const PangoRectangle* object) -> const Pango::Rectangle&
{
  return *reinterpret_cast<const Pango::Rectangle*>(object);
}

} /* namespace Glib */

namespace
{
} // anonymous namespace


namespace Pango
{


} // namespace Pango


