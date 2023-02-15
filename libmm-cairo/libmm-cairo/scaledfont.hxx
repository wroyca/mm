// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_SCALEDFONT_H
#define __CAIROMM_SCALEDFONT_H

#include <libmm-cairo/fontface.hxx>
#include <libmm-cairo/fontoptions.hxx>
#include <libmm-cairo/matrix.hxx>
#include <libmm-cairo/refptr.hxx>
#include <libmm-cairo/types.hxx>
#include <vector>

#ifdef CAIRO_HAS_FT_FONT
  #include <cairo-ft.h>
#endif

namespace Cairo
{

  class LIBMM_CAIRO_SYMEXPORT ScaledFont
  {
  public:
    typedef cairo_scaled_font_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_scaled_font_status (
          const_cast<cairo_scaled_font_t*> (cobj ()));
    }

    auto
    reference () const -> void
    {
      cairo_scaled_font_reference (m_cobject);
    }

    auto
    unreference () const -> void
    {
      cairo_scaled_font_destroy (m_cobject);
    }
#endif

    explicit ScaledFont (cobject* cobj, bool has_reference = false);

    ScaledFont (const ScaledFont&) = delete;
    auto
    operator= (const ScaledFont&) -> ScaledFont& = delete;

    virtual ~ScaledFont ();

    static auto
    create (const RefPtr<FontFace>& font_face,
            const Matrix& font_matrix,
            const Matrix& ctm,
            const FontOptions& options = FontOptions ()) -> RefPtr<ScaledFont>;

    auto
    get_extents (FontExtents& extents) const -> void;

    auto
    get_text_extents (const std::string& utf8, TextExtents& extents) const
        -> void;

    auto
    get_glyph_extents (const std::vector<Glyph>& glyphs, TextExtents& extents)
        -> void;

    auto
    get_font_face () const -> RefPtr<FontFace>;

    auto
    get_font_options (FontOptions& options) const -> void;

    auto
    get_font_matrix (Matrix& font_matrix) const -> void;

    auto
    get_ctm (Matrix& ctm) const -> void;

    auto
    get_type () const -> FontType;

    auto
    text_to_glyphs (double x,
                    double y,
                    const std::string& utf8,
                    std::vector<Glyph>& glyphs,
                    std::vector<TextCluster>& clusters,
                    TextClusterFlags& cluster_flags) -> void;

    auto
    get_scale_matrix (Matrix& scale_matrix) const -> void;

  protected:
    ScaledFont (const RefPtr<FontFace>& font_face,
                const Matrix& font_matrix,
                const Matrix& ctm,
                const FontOptions& options = FontOptions ());

    cobject* m_cobject;
  };

#ifdef CAIRO_HAS_FT_FONT

  class LIBMM_CAIRO_SYMEXPORT FtScaledFont : public ScaledFont
  {
  public:
    static auto
    create (const RefPtr<FtFontFace>& font_face,
            const Matrix& font_matrix,
            const Matrix& ctm,
            const FontOptions& options = FontOptions ())
        -> RefPtr<FtScaledFont>;

    auto
    lock_face () -> FT_Face;

    auto
    unlock_face () -> void;

  protected:
    FtScaledFont (const RefPtr<FtFontFace>& font_face,
                  const Matrix& font_matrix,
                  const Matrix& ctm,
                  const FontOptions& options = FontOptions ());
  };
#endif

} // namespace Cairo

#endif
