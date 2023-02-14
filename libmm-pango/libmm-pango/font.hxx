// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONT_H
#define _PANGOMM_FONT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-pango/coverage.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/fontmetrics.hxx>
#include <libmm-pango/glyph.hxx>
#include <libmm-pango/language.hxx>
#include <libmm-pango/rectangle.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFont = struct _PangoFont;
using PangoFontClass = struct _PangoFontClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class PANGOMM_API Font_Class;
}
#endif

namespace Pango
{

  const int SCALE = 1024;
  const double SCALE_XX_SMALL = 0.5787037037037;
  const double SCALE_X_SMALL = 0.6444444444444;
  const double SCALE_SMALL = 0.8333333333333;
  const double SCALE_MEDIUM = 1.0;
  const double SCALE_LARGE = 1.2;
  const double SCALE_X_LARGE = 1.4399999999999;
  const double SCALE_XX_LARGE = 1.728;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class PANGOMM_API FontFace;
  class PANGOMM_API FontMap;
#endif

  class PANGOMM_API Font : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Font;
    using CppClassType = Font_Class;
    using BaseObjectType = PangoFont;
    using BaseClassType = PangoFontClass;

    Font (const Font&) = delete;
    auto
    operator= (const Font&) -> Font& = delete;

  private:
    friend class Font_Class;
    static CppClassType font_class_;

  protected:
    explicit Font (const Glib::ConstructParams& construct_params);
    explicit Font (PangoFont* castitem);

#endif

  public:
    Font (Font&& src) noexcept;
    auto
    operator= (Font&& src) noexcept -> Font&;

    ~Font () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoFont*
    {
      return reinterpret_cast<PangoFont*> (gobject_);
    }

    auto
    gobj () const -> const PangoFont*
    {
      return reinterpret_cast<PangoFont*> (gobject_);
    }

    auto
    gobj_copy () -> PangoFont*;

  private:
  public:
    auto
    describe () const -> FontDescription;

    auto
    describe_with_absolute_size () const -> FontDescription;

    auto
    get_coverage (const Language& language) const -> Glib::RefPtr<Coverage>;

    auto
    get_metrics () const -> FontMetrics;

    auto
    get_metrics (const Language& language) const -> FontMetrics;

    void
    get_glyph_extents (Glyph glyph,
                       Rectangle& ink_rect,
                       Rectangle& logical_rect) const;

    auto
    get_font_map () -> Glib::RefPtr<FontMap>;

    auto
    get_font_map () const -> Glib::RefPtr<const FontMap>;

    auto
    get_face () -> Glib::RefPtr<FontFace>;

    auto
    get_face () const -> Glib::RefPtr<const FontFace>;

    auto
    has_char (gunichar wc) const -> bool;

    auto
    get_glyph_ink_extents (Glyph glyph) const -> Rectangle;

    auto
    get_glyph_logical_extents (Glyph glyph) const -> Rectangle;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoFont* object, bool take_copy = false) -> Glib::RefPtr<Pango::Font>;
} // namespace Glib

#endif
