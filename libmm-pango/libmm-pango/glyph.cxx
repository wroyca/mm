


#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/glyph.hxx>
#include <libmm-pango/glyph_p.hxx>


/*
 * Copyright 2001      Free Software Foundation
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

GlyphInfo::GlyphInfo()
{
  gobject_.glyph = 0;
}


GlyphGeometry::GlyphGeometry()
{
  gobject_.width = gobject_.x_offset = gobject_.y_offset = 0;
}

GlyphGeometry::GlyphGeometry(const PangoGlyphGeometry* src)
{
  gobject_.width = src->width;
  gobject_.x_offset = src->x_offset;
  gobject_.y_offset = src->y_offset;
}


/*GlyphVisAttr::GlyphVisAttr()
{
  gobject_.is_cluster_start = 0;
}

GlyphVisAttr::GlyphVisAttr(const PangoGlyphVisAttr* src)
{
  gobject_.is_cluster_start = src->is_cluster_start;
}*/

} //namespace Pango


namespace Glib
{

auto wrap(PangoGlyphInfo* object) -> Pango::GlyphInfo&
{
  return *reinterpret_cast<Pango::GlyphInfo*>(object);
}

auto wrap(const PangoGlyphInfo* object) -> const Pango::GlyphInfo&
{
  return *reinterpret_cast<const Pango::GlyphInfo*>(object);
}

auto wrap(PangoGlyphGeometry* object) -> Pango::GlyphGeometry&
{
  return *reinterpret_cast<Pango::GlyphGeometry*>(object);
}

auto wrap(const PangoGlyphGeometry* object) -> const Pango::GlyphGeometry&
{
  return *reinterpret_cast<const Pango::GlyphGeometry*>(object);
}

/*Pango::GlyphVisAttr& wrap(PangoGlyphVisAttr* object)
{
  return *reinterpret_cast<Pango::GlyphVisAttr*>(object);
}

const Pango::GlyphVisAttr& wrap(const PangoGlyphVisAttr* object)
{
  return *reinterpret_cast<const Pango::GlyphVisAttr*>(object);
}*/

} //namespace Glib

namespace
{
} // anonymous namespace


namespace Pango
{


auto GlyphInfo::get_glyph() const -> Glyph
{
  return gobj()->glyph;
}

auto GlyphInfo::get_geometry() const -> GlyphGeometry
{
  return GlyphGeometry(&gobj()->geometry);
}

auto GlyphInfo::get_attr() const -> GlyphVisAttr
{
  return gobj()->attr;
}


} // namespace Pango


namespace Pango
{


auto GlyphGeometry::get_width() const -> GlyphUnit
{
  return gobj()->width;
}

auto GlyphGeometry::get_x_offset() const -> GlyphUnit
{
  return gobj()->x_offset;
}

auto GlyphGeometry::get_y_offset() const -> GlyphUnit
{
  return gobj()->y_offset;
}


} // namespace Pango


