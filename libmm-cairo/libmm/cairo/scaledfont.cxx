// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/fontface.hxx>
#include <libmm/cairo/private.hxx>
#include <libmm/cairo/scaledfont.hxx>

namespace cairo
{

  ScaledFont::ScaledFont (cobject* cobj, const bool has_reference)
    : m_cobject (nullptr)
  {
    if (has_reference)
      m_cobject = cobj;
    else
      m_cobject = cairo_scaled_font_reference (cobj);
  }

  ScaledFont::ScaledFont (const RefPtr<FontFace>& font_face,
                          const Matrix& font_matrix,
                          const Matrix& ctm,
                          const FontOptions& options)
    : m_cobject (nullptr)
  {
    m_cobject = cairo_scaled_font_create (font_face->cobj (),
                                          &font_matrix,
                                          &ctm,
                                          options.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  ScaledFont::~ScaledFont ()
  {
    if (cobj ())
      cairo_scaled_font_destroy (cobj ());
  }

  auto
  ScaledFont::create (const RefPtr<FontFace>& font_face,
                      const Matrix& font_matrix,
                      const Matrix& ctm,
                      const FontOptions& options) -> RefPtr<ScaledFont>
  {
    return make_refptr_for_instance<ScaledFont> (
        new ScaledFont (font_face, font_matrix, ctm, options));
  }

  auto
  ScaledFont::get_extents (FontExtents& extents) const -> void
  {
    cairo_scaled_font_extents (m_cobject, &extents);
    check_object_status_and_throw_exception (*this);
  }

  auto
  ScaledFont::get_font_face () const -> RefPtr<FontFace>
  {
    const auto face = cairo_scaled_font_get_font_face (m_cobject);
    check_object_status_and_throw_exception (*this);
    return make_refptr_for_instance<FontFace> (new FontFace (face, false));
  }

  auto
  ScaledFont::get_font_options (FontOptions& options) const -> void
  {
    cairo_scaled_font_get_font_options (m_cobject, options.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  ScaledFont::get_font_matrix (Matrix& font_matrix) const -> void
  {
    cairo_scaled_font_get_font_matrix (m_cobject, &font_matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  ScaledFont::get_ctm (Matrix& ctm) const -> void
  {
    cairo_scaled_font_get_ctm (m_cobject, &ctm);
    check_object_status_and_throw_exception (*this);
  }

  auto
  ScaledFont::get_type () const -> FontType
  {
    auto font_type = cairo_scaled_font_get_type (m_cobject);
    check_object_status_and_throw_exception (*this);
    return static_cast<FontType> (font_type);
  }

  auto
  ScaledFont::text_to_glyphs (const double x,
                              const double y,
                              const std::string& utf8,
                              std::vector<Glyph>& glyphs,
                              std::vector<TextCluster>& clusters,
                              TextClusterFlags& cluster_flags) -> void
  {
    int num_glyphs = -1;
    int num_clusters = -1;
    cairo_glyph_t* c_glyphs = nullptr;
    cairo_text_cluster_t* c_clusters = nullptr;
    const auto status = cairo_scaled_font_text_to_glyphs (
        cobj (),
        x,
        y,
        utf8.c_str (),
        utf8.size (),
        &c_glyphs,
        &num_glyphs,
        &c_clusters,
        &num_clusters,
        reinterpret_cast<cairo_text_cluster_flags_t*> (&cluster_flags));
    if (num_glyphs > 0 && c_glyphs)
    {
      glyphs.assign (c_glyphs, c_glyphs + num_glyphs);
      cairo_glyph_free (c_glyphs);
    }
    if (num_clusters > 0 && c_clusters)
    {
      clusters.assign (c_clusters, c_clusters + num_clusters);
      cairo_text_cluster_free (c_clusters);
    }
    check_status_and_throw_exception (status);
    check_object_status_and_throw_exception (*this);
  }

  auto
  ScaledFont::get_scale_matrix (Matrix& scale_matrix) const -> void
  {
    cairo_scaled_font_get_scale_matrix (
        const_cast<cairo_scaled_font_t*> (cobj ()),
        &scale_matrix);
    check_object_status_and_throw_exception (*this);
  }

#ifdef CAIRO_HAS_FT_FONT
  FtScaledFont::FtScaledFont (const RefPtr<FtFontFace>& font_face,
                              const Matrix& font_matrix,
                              const Matrix& ctm,
                              const FontOptions& options)
    : ScaledFont (font_face, font_matrix, ctm, options)
  {
    check_object_status_and_throw_exception (*this);
  }

  auto
  FtScaledFont::create (const RefPtr<FtFontFace>& font_face,
                        const Matrix& font_matrix,
                        const Matrix& ctm,
                        const FontOptions& options) -> RefPtr<FtScaledFont>
  {
    return make_refptr_for_instance<FtScaledFont> (
        new FtScaledFont (font_face, font_matrix, ctm, options));
  }

  auto
  FtScaledFont::lock_face () -> FT_Face
  {
    const auto face = cairo_ft_scaled_font_lock_face (cobj ());
    check_object_status_and_throw_exception (*this);
    return face;
  }

  auto
  FtScaledFont::unlock_face () -> void
  {
    cairo_ft_scaled_font_unlock_face (cobj ());
    check_object_status_and_throw_exception (*this);
  }
#endif

} // namespace cairo
