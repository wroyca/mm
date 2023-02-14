// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_GLYPH_H
#define _PANGOMM_GLYPH_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <pango/pango.h>

namespace Pango
{

  class PANGOMM_API GlyphInfo;
  class PANGOMM_API GlyphGeometry;

  typedef PangoGlyph Glyph;

  typedef PangoGlyphUnit GlyphUnit;

  typedef PangoGlyphVisAttr GlyphVisAttr;

  class PANGOMM_API GlyphInfo
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GlyphInfo;
    using BaseObjectType = PangoGlyphInfo;
#endif

  private:
  public:
    GlyphInfo ();

    auto
    get_glyph () const -> Glyph;

    auto
    get_geometry () const -> GlyphGeometry;

    auto
    get_attr () const -> GlyphVisAttr;

    auto
    gobj () -> PangoGlyphInfo*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const PangoGlyphInfo*
    {
      return &gobject_;
    }

  protected:
    PangoGlyphInfo gobject_;
  };

  class PANGOMM_API GlyphGeometry
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GlyphGeometry;
    using BaseObjectType = PangoGlyphGeometry;
#endif

  private:
  public:
    GlyphGeometry ();
    explicit GlyphGeometry (const PangoGlyphGeometry* src);

    auto
    get_width () const -> GlyphUnit;

    auto
    get_x_offset () const -> GlyphUnit;

    auto
    get_y_offset () const -> GlyphUnit;

    auto
    gobj () -> PangoGlyphGeometry*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const PangoGlyphGeometry*
    {
      return &gobject_;
    }

  protected:
    PangoGlyphGeometry gobject_;
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoGlyphInfo* object) -> Pango::GlyphInfo&;

  PANGOMM_API
  auto
  wrap (const PangoGlyphInfo* object) -> const Pango::GlyphInfo&;

  PANGOMM_API
  auto
  wrap (PangoGlyphGeometry* object) -> Pango::GlyphGeometry&;

  PANGOMM_API
  auto
  wrap (const PangoGlyphGeometry* object) -> const Pango::GlyphGeometry&;

} // namespace Glib

#endif
