// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_GLYPH_H
#define _PANGOMM_GLYPH_H

#include <libmm/pango/mm-pangoconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <pango/pango.h>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT GlyphInfo;
  class LIBMM_PANGO_SYMEXPORT GlyphGeometry;

  typedef PangoGlyph Glyph;

  typedef PangoGlyphUnit GlyphUnit;

  typedef PangoGlyphVisAttr GlyphVisAttr;

  class LIBMM_PANGO_SYMEXPORT GlyphInfo
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

  class LIBMM_PANGO_SYMEXPORT GlyphGeometry
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

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoGlyphInfo* object) -> pango::GlyphInfo&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (const PangoGlyphInfo* object) -> const pango::GlyphInfo&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoGlyphGeometry* object) -> pango::GlyphGeometry&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (const PangoGlyphGeometry* object) -> const pango::GlyphGeometry&;

} // namespace glib

#endif
