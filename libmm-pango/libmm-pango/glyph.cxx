// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/glyph.hxx>
#include <libmm-pango/glyph_p.hxx>

namespace Pango
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

} // namespace Pango

namespace Glib
{

  auto
  wrap (PangoGlyphInfo* object) -> Pango::GlyphInfo&
  {
    return *reinterpret_cast<Pango::GlyphInfo*> (object);
  }

  auto
  wrap (const PangoGlyphInfo* object) -> const Pango::GlyphInfo&
  {
    return *reinterpret_cast<const Pango::GlyphInfo*> (object);
  }

  auto
  wrap (PangoGlyphGeometry* object) -> Pango::GlyphGeometry&
  {
    return *reinterpret_cast<Pango::GlyphGeometry*> (object);
  }

  auto
  wrap (const PangoGlyphGeometry* object) -> const Pango::GlyphGeometry&
  {
    return *reinterpret_cast<const Pango::GlyphGeometry*> (object);
  }

} // namespace Glib

namespace
{
}

namespace Pango
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

} // namespace Pango

namespace Pango
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

} // namespace Pango
