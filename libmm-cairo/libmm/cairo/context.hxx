// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_CONTEXT_H
#define __CAIROMM_CONTEXT_H

#include <cairo.h>
#include <libmm/cairo/fontface.hxx>
#include <libmm/cairo/matrix.hxx>
#include <libmm/cairo/path.hxx>
#include <libmm/cairo/pattern.hxx>
#include <libmm/cairo/scaledfont.hxx>
#include <libmm/cairo/surface.hxx>
#include <libmm/cairo/types.hxx>
#include <utility>
#include <valarray>
#include <vector>

namespace cairo
{

  class LIBMM_CAIRO_SYMEXPORT Context
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

    auto
    save () -> void;

    auto
    restore () -> void;

    auto
    set_operator (Operator op) -> void;

    auto
    set_source (const RefPtr<const Pattern>& source) -> void;

    auto
    set_source_rgb (double red, double green, double blue) -> void;

    auto
    set_source_rgba (double red, double green, double blue, double alpha)
        -> void;

    auto
    set_source (const RefPtr<Surface>& surface, double x, double y) -> void;

    auto
    set_tolerance (double tolerance) -> void;

    auto
    set_antialias (Antialias antialias) -> void;

    auto
    set_fill_rule (FillRule fill_rule) -> void;

    auto
    set_line_width (double width) -> void;

    auto
    set_line_cap (LineCap line_cap) -> void;

    auto
    set_line_join (LineJoin line_join) -> void;

    auto
    set_dash (const std::valarray<double>& dashes, double offset) -> void;

    auto
    set_dash (const std::vector<double>& dashes, double offset) -> void;

    auto
    unset_dash () -> void;

    auto
    set_miter_limit (double limit) -> void;

    auto
    translate (double tx, double ty) -> void;

    auto
    scale (double sx, double sy) -> void;

    auto
    rotate (double angle_radians) -> void;

    auto
    rotate_degrees (double angle_degres) -> void;

    auto
    transform (const Matrix& matrix) -> void;

    auto
    set_matrix (const Matrix& matrix) -> void;

    auto
    set_identity_matrix () -> void;

    auto
    user_to_device (double& x, double& y) const -> void;

    auto
    user_to_device_distance (double& dx, double& dy) const -> void;

    auto
    device_to_user (double& x, double& y) const -> void;

    auto
    device_to_user_distance (double& dx, double& dy) const -> void;

    auto
    begin_new_path () -> void;

    auto
    begin_new_sub_path () -> void;

    auto
    move_to (double x, double y) -> void;

    auto
    line_to (double x, double y) -> void;

    auto
    curve_to (double x1, double y1, double x2, double y2, double x3, double y3)
        -> void;

    auto
    arc (double xc, double yc, double radius, double angle1, double angle2)
        -> void;

    auto
    arc_negative (double xc,
                  double yc,
                  double radius,
                  double angle1,
                  double angle2) -> void;

    auto
    rel_move_to (double dx, double dy) -> void;

    auto
    rel_line_to (double dx, double dy) -> void;

    auto
    rel_curve_to (double dx1,
                  double dy1,
                  double dx2,
                  double dy2,
                  double dx3,
                  double dy3) -> void;

    auto
    rectangle (double x, double y, double width, double height) -> void;

    auto
    close_path () -> void;

    auto
    paint () -> void;

    auto
    paint_with_alpha (double alpha) -> void;

    auto
    mask (const RefPtr<const Pattern>& pattern) -> void;

    auto
    mask (const RefPtr<const Surface>& surface,
          double surface_x,
          double surface_y) -> void;

    auto
    stroke () -> void;

    auto
    stroke_preserve () -> void;

    auto
    fill () -> void;

    auto
    fill_preserve () -> void;

    auto
    copy_page () -> void;

    auto
    show_page () -> void;

    auto
    in_stroke (double x, double y) const -> bool;

    auto
    in_fill (double x, double y) const -> bool;

    auto
    in_clip (double x, double y) const -> bool;

    auto
    get_stroke_extents (double& x1, double& y1, double& x2, double& y2) const
        -> void;

    auto
    get_fill_extents (double& x1, double& y1, double& x2, double& y2) const
        -> void;

    auto
    reset_clip () -> void;

    auto
    clip () -> void;

    auto
    clip_preserve () -> void;

    auto
    get_clip_extents (double& x1, double& y1, double& x2, double& y2) const
        -> void;

    auto
    copy_clip_rectangle_list (std::vector<Rectangle>& rectangles) const -> void;

    auto
    select_font_face (const std::string& family,
                      ToyFontFace::Slant slant,
                      ToyFontFace::Weight weight) -> void;

    auto
    set_font_size (double size) -> void;

    auto
    set_font_matrix (const Matrix& matrix) -> void;

    auto
    get_font_matrix (Matrix& matrix) const -> void;

    auto
    set_font_options (const FontOptions& options) -> void;

    auto
    get_font_options (FontOptions& options) const -> void;

    auto
    set_scaled_font (const RefPtr<const ScaledFont>& scaled_font) -> void;

    auto
    get_scaled_font () -> RefPtr<ScaledFont>;

    auto
    show_text (const std::string& utf8) -> void;

    auto
    show_glyphs (const std::vector<Glyph>& glyphs) -> void;

    auto
    show_text_glyphs (const std::string& utf8,
                      const std::vector<Glyph>& glyphs,
                      const std::vector<TextCluster>& clusters,
                      TextClusterFlags cluster_flags) -> void;

    auto
    get_font_face () -> RefPtr<FontFace>;
    auto
    get_font_face () const -> RefPtr<const FontFace>;

    auto
    get_font_extents (FontExtents& extents) const -> void;

    auto
    set_font_face (const RefPtr<const FontFace>& font_face) -> void;

    auto
    get_text_extents (const std::string& utf8, TextExtents& extents) const
        -> void;

    auto
    get_glyph_extents (const std::vector<Glyph>& glyphs,
                       TextExtents& extents) const -> void;

    auto
    text_path (const std::string& utf8) -> void;

    auto
    glyph_path (const std::vector<Glyph>& glyphs) -> void;

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

    auto
    get_current_point (double& x, double& y) const -> void;

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

    auto
    get_dash (std::vector<double>& dashes, double& offset) const -> void;

    auto
    get_matrix (Matrix& matrix) -> void;

    auto
    get_matrix () const -> Matrix;

    auto
    get_target () -> RefPtr<Surface>;
    auto
    get_target () const -> RefPtr<const Surface>;

    auto
    copy_path () const -> Path*;

    auto
    get_path_extents (double& x1, double& y1, double& x2, double& y2) const
        -> void;

    auto
    copy_path_flat () const -> Path*;

    auto
    append_path (const Path& path) -> void;

    auto
    push_group () -> void;

    auto
    push_group_with_content (Content content) -> void;

    auto
    pop_group () -> RefPtr<Pattern>;

    auto
    pop_group_to_source () -> void;

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

    auto
    reference () const -> void;
    auto
    unreference () const -> void;
#endif

  protected:
    cobject* m_cobject;
  };

  class SaveGuard final
  {
  public:
    LIBMM_CAIRO_SYMEXPORT explicit SaveGuard (const RefPtr<Context>& context);

#ifndef DOXYGEN_IGNORE_THIS

    SaveGuard (const SaveGuard&) = delete;
    auto
    operator= (const SaveGuard&) -> SaveGuard& = delete;

    SaveGuard (SaveGuard&&) = delete;
    auto
    operator= (SaveGuard&&) -> SaveGuard& = delete;
#endif

    LIBMM_CAIRO_SYMEXPORT ~SaveGuard ();

  private:
    RefPtr<Context> ctx_;
  };

} // namespace cairo

#endif
