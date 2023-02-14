

#ifndef __CAIROMM_FONTFACE_H
#define __CAIROMM_FONTFACE_H

#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/refptr.hxx>
#include <libmm-cairo/types.hxx>
#include <string>
#include <vector>

#include <cairo.h>
#ifdef CAIRO_HAS_FT_FONT
  #include <cairo-ft.h>
#endif

namespace Cairo
{

  class CAIROMM_API ScaledFont;
  class CAIROMM_API Context;

  class CAIROMM_API FontFace
  {
  protected:
  public:
    explicit FontFace (cairo_font_face_t* cobject, bool has_reference = false);

    FontFace (const FontFace&) = delete;
    auto
    operator= (const FontFace&) -> FontFace& = delete;

    virtual ~FontFace ();

    auto
    get_type () const -> FontType;

    typedef cairo_font_face_t cobject;

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
      return cairo_font_face_status (const_cast<cairo_font_face_t*> (cobj ()));
    }
#endif

    void
    reference () const;
    void
    unreference () const;

  protected:
    cobject* m_cobject;
  };

  class CAIROMM_API ToyFontFace : public FontFace
  {
  public:
    enum class Slant
    {
      NORMAL = CAIRO_FONT_SLANT_NORMAL,

      ITALIC = CAIRO_FONT_SLANT_ITALIC,

      OBLIQUE = CAIRO_FONT_SLANT_OBLIQUE
    };

    enum class Weight
    {
      NORMAL = CAIRO_FONT_WEIGHT_NORMAL,

      BOLD = CAIRO_FONT_WEIGHT_BOLD
    };

    static auto
    create (const std::string& family, Slant slant, Weight weight)
        -> RefPtr<ToyFontFace>;

    auto
    get_family () const -> std::string;

    auto
    get_slant () const -> Slant;

    auto
    get_weight () const -> Weight;

  protected:
    ToyFontFace (const std::string& family, Slant slant, Weight weight);
  };

  class CAIROMM_API UserFontFace : public FontFace
  {
  public:
    ~UserFontFace () override;

  protected:
    virtual auto
    init (const RefPtr<ScaledFont>& scaled_font,
          const RefPtr<Context>& cr,
          FontExtents& extents) -> ErrorStatus;

    virtual auto
    unicode_to_glyph (const RefPtr<ScaledFont>& scaled_font,
                      unsigned long unicode,
                      unsigned long& glyph) -> ErrorStatus;

    virtual auto
    render_glyph (const RefPtr<ScaledFont>& scaled_font,
                  unsigned long glyph,
                  const RefPtr<Context>& cr,
                  TextExtents& metrics) -> ErrorStatus = 0;

    virtual auto
    text_to_glyphs (const RefPtr<ScaledFont>& scaled_font,
                    const std::string& utf8,
                    std::vector<Glyph>& glyphs,
                    std::vector<TextCluster>& clusters,
                    TextClusterFlags& cluster_flags) -> ErrorStatus;

    UserFontFace ();

  private:
    static auto
    init_cb (cairo_scaled_font_t* scaled_font,
             cairo_t* cr,
             cairo_font_extents_t* metrics) -> cairo_status_t;

    static auto
    unicode_to_glyph_cb (cairo_scaled_font_t* scaled_font,
                         unsigned long unicode,
                         unsigned long* glyph) -> cairo_status_t;

    static auto
    render_glyph_cb (cairo_scaled_font_t* scaled_font,
                     unsigned long glyph,
                     cairo_t* cr,
                     cairo_text_extents_t* metrics) -> cairo_status_t;

    static auto
    text_to_glyphs_cb (cairo_scaled_font_t* scaled_font,
                       const char* utf8,
                       int utf8_len,
                       cairo_glyph_t** glyphs,
                       int* num_glyphs,
                       cairo_text_cluster_t** clusters,
                       int* num_clusters,
                       cairo_text_cluster_flags_t* cluster_flags)
        -> cairo_status_t;
  };

#ifdef CAIRO_HAS_FT_FONT

  class CAIROMM_API FtFontFace : public FontFace
  {
  public:
    static auto
    create (FT_Face face, int load_flags) -> RefPtr<FtFontFace>;

  #ifdef CAIRO_HAS_FC_FONT

    static auto
    create (FcPattern* pattern) -> RefPtr<FtFontFace>;
  #endif

    void
    set_synthesize (FtSynthesize synth_flags);

    void
    unset_synthesize (FtSynthesize synth_flags);

    auto
    get_synthesize () const -> FtSynthesize;

  protected:
    FtFontFace (FT_Face face, int load_flags);
  #ifdef CAIRO_HAS_FC_FONT
    FtFontFace (FcPattern* pattern);
  #endif
  };

#endif

} // namespace Cairo

#endif
