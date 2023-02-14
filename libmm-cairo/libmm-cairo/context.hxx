// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_CONTEXT_H
#define __CAIROMM_CONTEXT_H

#include <cairo.h>
#include <libmm-cairo/fontface.hxx>
#include <libmm-cairo/matrix.hxx>
#include <libmm-cairo/path.hxx>
#include <libmm-cairo/pattern.hxx>
#include <libmm-cairo/scaledfont.hxx>
#include <libmm-cairo/surface.hxx>
#include <libmm-cairo/types.hxx>
#include <utility>
#include <valarray>
#include <vector>

namespace Cairo
{

  class CAIROMM_API Context
  {
  protected:
    explicit Context (const RefPtr<Surface>& target);

  public:
    enum class Operator
    {
      CLEAR = CAIRO_OPERATOR_CLEAR,

      SOURCE = CAIRO_OPERATOR_SOURCE,

      OVER = CAIRO_OPERATOR_OVER,

      IN = CAIRO_OPERATOR_IN,

      OUT = CAIRO_OPERATOR_OUT,

      ATOP = CAIRO_OPERATOR_ATOP,

      DEST = CAIRO_OPERATOR_DEST,

      DEST_OVER = CAIRO_OPERATOR_DEST_OVER,

      DEST_IN = CAIRO_OPERATOR_DEST_IN,

      DEST_OUT = CAIRO_OPERATOR_DEST_OUT,

      DEST_ATOP = CAIRO_OPERATOR_DEST_ATOP,

      XOR = CAIRO_OPERATOR_XOR,

      ADD = CAIRO_OPERATOR_ADD,

      SATURATE = CAIRO_OPERATOR_SATURATE
    };

    enum class FillRule
    {
      WINDING = CAIRO_FILL_RULE_WINDING,

      EVEN_ODD = CAIRO_FILL_RULE_EVEN_ODD
    };

    enum class LineCap
    {
      BUTT = CAIRO_LINE_CAP_BUTT,

      ROUND = CAIRO_LINE_CAP_ROUND,

      SQUARE = CAIRO_LINE_CAP_SQUARE
    };

    enum class LineJoin
    {
      MITER = CAIRO_LINE_JOIN_MITER,

      ROUND = CAIRO_LINE_JOIN_ROUND,

      BEVEL = CAIRO_LINE_JOIN_BEVEL
    };

    explicit Context (cairo_t* cobject, bool has_reference = false);

    Context (const Context&) = delete;
    auto
    operator= (const Context&) -> Context& = delete;

    static auto
    create (const RefPtr<Surface>& target) -> RefPtr<Context>;

    virtual ~Context ();

    void
    save ();

    void
    restore ();

    void
    set_operator (Operator op);

    void
    set_source (const RefPtr<const Pattern>& source);

    void
    set_source_rgb (double red, double green, double blue);

    void
    set_source_rgba (double red, double green, double blue, double alpha);

    void
    set_source (const RefPtr<Surface>& surface, double x, double y);

    void
    set_tolerance (double tolerance);

    void
    set_antialias (Antialias antialias);

    void
    set_fill_rule (FillRule fill_rule);

    void
    set_line_width (double width);

    void
    set_line_cap (LineCap line_cap);

    void
    set_line_join (LineJoin line_join);

    void
    set_dash (const std::valarray<double>& dashes, double offset);

    void
    set_dash (const std::vector<double>& dashes, double offset);

    void
    unset_dash ();

    void
    set_miter_limit (double limit);

    void
    translate (double tx, double ty);

    void
    scale (double sx, double sy);

    void
    rotate (double angle_radians);

    void
    rotate_degrees (double angle_degres);

    void
    transform (const Matrix& matrix);

    void
    set_matrix (const Matrix& matrix);

    void
    set_identity_matrix ();

    void
    user_to_device (double& x, double& y) const;

    void
    user_to_device_distance (double& dx, double& dy) const;

    void
    device_to_user (double& x, double& y) const;

    void
    device_to_user_distance (double& dx, double& dy) const;

    void
    begin_new_path ();

    void
    begin_new_sub_path ();

    void
    move_to (double x, double y);

    void
    line_to (double x, double y);

    void
    curve_to (double x1, double y1, double x2, double y2, double x3, double y3);

    void
    arc (double xc, double yc, double radius, double angle1, double angle2);

    void
    arc_negative (double xc,
                  double yc,
                  double radius,
                  double angle1,
                  double angle2);

    void
    rel_move_to (double dx, double dy);

    void
    rel_line_to (double dx, double dy);

    void
    rel_curve_to (double dx1,
                  double dy1,
                  double dx2,
                  double dy2,
                  double dx3,
                  double dy3);

    void
    rectangle (double x, double y, double width, double height);

    void
    close_path ();

    void
    paint ();

    void
    paint_with_alpha (double alpha);

    void
    mask (const RefPtr<const Pattern>& pattern);

    void
    mask (const RefPtr<const Surface>& surface,
          double surface_x,
          double surface_y);

    void
    stroke ();

    void
    stroke_preserve ();

    void
    fill ();

    void
    fill_preserve ();

    void
    copy_page ();

    void
    show_page ();

    auto
    in_stroke (double x, double y) const -> bool;

    auto
    in_fill (double x, double y) const -> bool;

    auto
    in_clip (double x, double y) const -> bool;

    void
    get_stroke_extents (double& x1, double& y1, double& x2, double& y2) const;

    void
    get_fill_extents (double& x1, double& y1, double& x2, double& y2) const;

    void
    reset_clip ();

    void
    clip ();

    void
    clip_preserve ();

    void
    get_clip_extents (double& x1, double& y1, double& x2, double& y2) const;

    void
    copy_clip_rectangle_list (std::vector<Rectangle>& rectangles) const;

    void
    select_font_face (const std::string& family,
                      ToyFontFace::Slant slant,
                      ToyFontFace::Weight weight);

    void
    set_font_size (double size);

    void
    set_font_matrix (const Matrix& matrix);

    void
    get_font_matrix (Matrix& matrix) const;

    void
    set_font_options (const FontOptions& options);

    void
    get_font_options (FontOptions& options) const;

    void
    set_scaled_font (const RefPtr<const ScaledFont>& scaled_font);

    auto
    get_scaled_font () -> RefPtr<ScaledFont>;

    void
    show_text (const std::string& utf8);

    void
    show_glyphs (const std::vector<Glyph>& glyphs);

    void
    show_text_glyphs (const std::string& utf8,
                      const std::vector<Glyph>& glyphs,
                      const std::vector<TextCluster>& clusters,
                      TextClusterFlags cluster_flags);

    auto
    get_font_face () -> RefPtr<FontFace>;
    auto
    get_font_face () const -> RefPtr<const FontFace>;

    void
    get_font_extents (FontExtents& extents) const;

    void
    set_font_face (const RefPtr<const FontFace>& font_face);

    void
    get_text_extents (const std::string& utf8, TextExtents& extents) const;

    void
    get_glyph_extents (const std::vector<Glyph>& glyphs,
                       TextExtents& extents) const;

    void
    text_path (const std::string& utf8);

    void
    glyph_path (const std::vector<Glyph>& glyphs);

    auto
    get_operator () const -> Operator;

    auto
    get_source () -> RefPtr<Pattern>;
    auto
    get_source () const -> RefPtr<const Pattern>;

    auto
    get_source_for_surface () -> RefPtr<SurfacePattern>;
    auto
    get_source_for_surface () const -> RefPtr<const SurfacePattern>;

    auto
    get_tolerance () const -> double;

    auto
    get_antialias () const -> Antialias;

    void
    get_current_point (double& x, double& y) const;

    auto
    has_current_point () const -> bool;

    auto
    get_fill_rule () const -> FillRule;

    auto
    get_line_width () const -> double;

    auto
    get_line_cap () const -> LineCap;

    auto
    get_line_join () const -> LineJoin;

    auto
    get_miter_limit () const -> double;

    void
    get_dash (std::vector<double>& dashes, double& offset) const;

    void
    get_matrix (Matrix& matrix);

    auto
    get_matrix () const -> Matrix;

    auto
    get_target () -> RefPtr<Surface>;
    auto
    get_target () const -> RefPtr<const Surface>;

    auto
    copy_path () const -> Path*;

    void
    get_path_extents (double& x1, double& y1, double& x2, double& y2) const;

    auto
    copy_path_flat () const -> Path*;

    void
    append_path (const Path& path);

    void
    push_group ();

    void
    push_group_with_content (Content content);

    auto
    pop_group () -> RefPtr<Pattern>;

    void
    pop_group_to_source ();

    auto
    get_group_target () -> RefPtr<Surface>;

    auto
    get_group_target () const -> RefPtr<const Surface>;

    typedef cairo_t cobject;

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
      return cairo_status (const_cast<cairo_t*> (cobj ()));
    }

    void
    reference () const;
    void
    unreference () const;
#endif

  protected:
    cobject* m_cobject;
  };

  class SaveGuard final
  {
  public:
    CAIROMM_API explicit SaveGuard (const RefPtr<Context>& context);

#ifndef DOXYGEN_IGNORE_THIS

    SaveGuard (const SaveGuard&) = delete;
    auto
    operator= (const SaveGuard&) -> SaveGuard& = delete;

    SaveGuard (SaveGuard&&) = delete;
    auto
    operator= (SaveGuard&&) -> SaveGuard& = delete;
#endif

    CAIROMM_API ~SaveGuard ();

  private:
    RefPtr<Context> ctx_;
  };

} // namespace Cairo

#endif
