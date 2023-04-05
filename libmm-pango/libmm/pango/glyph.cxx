// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/glyph.hxx>
#include <libmm/pango/glyph_p.hxx>

namespace pango
{

  GlyphInfo::GlyphInfo ()
  {
    gobject_.glyph = 0;
  }

  GlyphGeometry::GlyphGeometry ()
  {
    gobject_.width = gobject_.x_offset = gobject_.y_offset = 0;
  }

  GlyphGeometry::GlyphGeometry (const PangoGlyphGeometry* src)
  {
    gobject_.width = src->width;
    gobject_.x_offset = src->x_offset;
    gobject_.y_offset = src->y_offset;
  }

} // namespace pango

namespace glib
{

  auto
  wrap (PangoGlyphInfo* object) -> pango::GlyphInfo&
  {
    return *reinterpret_cast<pango::GlyphInfo*> (object);
  }

  auto
  wrap (const PangoGlyphInfo* object) -> const pango::GlyphInfo&
  {
    return *reinterpret_cast<const pango::GlyphInfo*> (object);
  }

  auto
  wrap (PangoGlyphGeometry* object) -> pango::GlyphGeometry&
  {
    return *reinterpret_cast<pango::GlyphGeometry*> (object);
  }

  auto
  wrap (const PangoGlyphGeometry* object) -> const pango::GlyphGeometry&
  {
    return *reinterpret_cast<const pango::GlyphGeometry*> (object);
  }

} // namespace glib

namespace
{
}

namespace pango
{

  auto
  GlyphInfo::get_glyph () const -> Glyph
  {
    return gobj ()->glyph;
  }

  auto
  GlyphInfo::get_geometry () const -> GlyphGeometry
  {
    return GlyphGeometry (&gobj ()->geometry);
  }

  auto
  GlyphInfo::get_attr () const -> GlyphVisAttr
  {
    return gobj ()->attr;
  }

} // namespace pango

namespace pango
{

  auto
  GlyphGeometry::get_width () const -> GlyphUnit
  {
    return gobj ()->width;
  }

  auto
  GlyphGeometry::get_x_offset () const -> GlyphUnit
  {
    return gobj ()->x_offset;
  }

  auto
  GlyphGeometry::get_y_offset () const -> GlyphUnit
  {
    return gobj ()->y_offset;
  }

} // namespace pango
