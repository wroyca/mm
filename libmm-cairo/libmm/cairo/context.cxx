// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/context.hxx>
#include <libmm/cairo/context_private.hxx>
#include <libmm/cairo/mm-cairoconfig.hxx>
#include <libmm/cairo/private.hxx>
#include <libmm/cairo/scaledfont.hxx>
#include <libmm/cairo/script_surface.hxx>
#include <libmm/cairo/surface.hxx>

#include <cmath>

using namespace cairo::Private;

namespace cairo
{

  Context::Context (const RefPtr<Surface>& target)
    : m_cobject (nullptr)
  {
    m_cobject = cairo_create (target->cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::create (const RefPtr<Surface>& target) -> RefPtr<Context>
  {
    return make_refptr_for_instance<Context> (new Context (target));
  }

  Context::Context (cairo_t* cobject, const bool has_reference)
    : m_cobject (nullptr)
  {
    if (has_reference)
      m_cobject = cobject;
    else
      m_cobject = cairo_reference (cobject);
  }

  Context::~Context ()
  {
    if (m_cobject)
      cairo_destroy (m_cobject);
  }

  auto
  Context::reference () const -> void
  {
    cairo_reference (const_cast<cobject*> (cobj ()));
  }

  auto
  Context::unreference () const -> void
  {
    cairo_destroy (const_cast<cobject*> (cobj ()));
  }

  auto
  Context::save () -> void
  {
    cairo_save (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::restore () -> void
  {
    cairo_restore (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_operator (Operator op) -> void
  {
    cairo_set_operator (cobj (), static_cast<cairo_operator_t> (op));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_source (const RefPtr<const Pattern>& source) -> void
  {
    cairo_set_source (cobj (), const_cast<cairo_pattern_t*> (source->cobj ()));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_source_rgb (const double red,
                           const double green,
                           const double blue) -> void
  {
    cairo_set_source_rgb (cobj (), red, green, blue);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_source_rgba (const double red,
                            const double green,
                            const double blue,
                            const double alpha) -> void
  {
    cairo_set_source_rgba (cobj (), red, green, blue, alpha);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_source (const RefPtr<Surface>& surface,
                       const double x,
                       const double y) -> void
  {
    cairo_set_source_surface (cobj (), surface->cobj (), x, y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_tolerance (const double tolerance) -> void
  {
    cairo_set_tolerance (cobj (), tolerance);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_antialias (Antialias antialias) -> void
  {
    cairo_set_antialias (cobj (), static_cast<cairo_antialias_t> (antialias));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_fill_rule (FillRule fill_rule) -> void
  {
    cairo_set_fill_rule (cobj (), static_cast<cairo_fill_rule_t> (fill_rule));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_line_width (const double width) -> void
  {
    cairo_set_line_width (cobj (), width);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_line_cap (LineCap line_cap) -> void
  {
    cairo_set_line_cap (cobj (), static_cast<cairo_line_cap_t> (line_cap));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_line_join (LineJoin line_join) -> void
  {
    cairo_set_line_join (cobj (), static_cast<cairo_line_join_t> (line_join));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_dash (const std::valarray<double>& dashes, const double offset) -> void
  {
    std::vector<double> v (dashes.size ());
    for (size_t i = 0; i < dashes.size (); ++i)
      v[i] = dashes[i];

    set_dash (v, offset);
  }

  auto
  Context::set_dash (const std::vector<double>& dashes, const double offset) -> void
  {
    cairo_set_dash (cobj (),
                    dashes.empty () ? nullptr : &dashes[0],
                    dashes.size (),
                    offset);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::unset_dash () -> void
  {
    cairo_set_dash (cobj (), nullptr, 0, 0.0);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_miter_limit (const double limit) -> void
  {
    cairo_set_miter_limit (cobj (), limit);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::translate (const double tx, const double ty) -> void
  {
    cairo_translate (cobj (), tx, ty);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::scale (const double sx, const double sy) -> void
  {
    cairo_scale (cobj (), sx, sy);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rotate (const double angle_radians) -> void
  {
    cairo_rotate (cobj (), angle_radians);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rotate_degrees (const double angle_degrees) -> void
  {
    cairo_rotate (cobj (), angle_degrees * M_PI / 180.0);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::transform (const Matrix& matrix) -> void
  {
    cairo_transform (cobj (), &matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_matrix (const Matrix& matrix) -> void
  {
    cairo_set_matrix (cobj (), &matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_identity_matrix () -> void
  {
    cairo_identity_matrix (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::user_to_device (double& x, double& y) const -> void
  {
    cairo_user_to_device (const_cast<cobject*> (cobj ()), &x, &y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::user_to_device_distance (double& dx, double& dy) const -> void
  {
    cairo_user_to_device_distance (const_cast<cobject*> (cobj ()), &dx, &dy);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::device_to_user (double& x, double& y) const -> void
  {
    cairo_device_to_user (const_cast<cobject*> (cobj ()), &x, &y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::device_to_user_distance (double& dx, double& dy) const -> void
  {
    cairo_device_to_user_distance (const_cast<cobject*> (cobj ()), &dx, &dy);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::begin_new_path () -> void
  {
    cairo_new_path (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::begin_new_sub_path () -> void
  {
    cairo_new_sub_path (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::move_to (const double x, const double y) -> void
  {
    cairo_move_to (cobj (), x, y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::line_to (const double x, const double y) -> void
  {
    cairo_line_to (cobj (), x, y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::curve_to (const double x1,
                     const double y1,
                     const double x2,
                     const double y2,
                     const double x3,
                     const double y3) -> void
  {
    cairo_curve_to (cobj (), x1, y1, x2, y2, x3, y3);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::arc (const double xc,
                const double yc,
                const double radius,
                const double angle1,
                const double angle2) -> void
  {
    cairo_arc (cobj (), xc, yc, radius, angle1, angle2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::arc_negative (const double xc,
                         const double yc,
                         const double radius,
                         const double angle1,
                         const double angle2) -> void
  {
    cairo_arc_negative (cobj (), xc, yc, radius, angle1, angle2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rel_move_to (const double dx, const double dy) -> void
  {
    cairo_rel_move_to (cobj (), dx, dy);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rel_line_to (const double dx, const double dy) -> void
  {
    cairo_rel_line_to (cobj (), dx, dy);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rel_curve_to (const double dx1,
                         const double dy1,
                         const double dx2,
                         const double dy2,
                         const double dx3,
                         const double dy3) -> void
  {
    cairo_rel_curve_to (cobj (), dx1, dy1, dx2, dy2, dx3, dy3);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::rectangle (const double x,
                      const double y,
                      const double width,
                      const double height) -> void
  {
    cairo_rectangle (cobj (), x, y, width, height);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::close_path () -> void
  {
    cairo_close_path (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::paint () -> void
  {
    cairo_paint (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::paint_with_alpha (const double alpha) -> void
  {
    cairo_paint_with_alpha (cobj (), alpha);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::mask (const RefPtr<const Pattern>& pattern) -> void
  {
    cairo_mask (cobj (), const_cast<cairo_pattern_t*> (pattern->cobj ()));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::mask (const RefPtr<const Surface>& surface,
                 const double surface_x,
                 const double surface_y) -> void
  {
    cairo_mask_surface (cobj (),
                        const_cast<cairo_surface_t*> (surface->cobj ()),
                        surface_x,
                        surface_y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::stroke () -> void
  {
    cairo_stroke (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::stroke_preserve () -> void
  {
    cairo_stroke_preserve (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::fill () -> void
  {
    cairo_fill (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::fill_preserve () -> void
  {
    cairo_fill_preserve (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::copy_page () -> void
  {
    cairo_copy_page (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::show_page () -> void
  {
    cairo_show_page (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::in_stroke (const double x, const double y) const -> bool
  {
    const bool result = cairo_in_stroke (const_cast<cobject*> (cobj ()), x, y);
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::in_fill (const double x, const double y) const -> bool
  {
    const bool result = cairo_in_fill (const_cast<cobject*> (cobj ()), x, y);
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::in_clip (const double x, const double y) const -> bool
  {
    const bool result = cairo_in_clip (const_cast<cobject*> (cobj ()), x, y);
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_stroke_extents (double& x1,
                               double& y1,
                               double& x2,
                               double& y2) const -> void
  {
    cairo_stroke_extents (const_cast<cobject*> (cobj ()), &x1, &y1, &x2, &y2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_fill_extents (double& x1,
                             double& y1,
                             double& x2,
                             double& y2) const -> void
  {
    cairo_fill_extents (const_cast<cobject*> (cobj ()), &x1, &y1, &x2, &y2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::reset_clip () -> void
  {
    cairo_reset_clip (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::clip () -> void
  {
    cairo_clip (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::clip_preserve () -> void
  {
    cairo_clip_preserve (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_clip_extents (double& x1,
                             double& y1,
                             double& x2,
                             double& y2) const -> void
  {
    cairo_clip_extents (const_cast<cobject*> (cobj ()), &x1, &y1, &x2, &y2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::copy_clip_rectangle_list (std::vector<Rectangle>& rectangles) const -> void
  {
    cairo_rectangle_list_t* c_list = nullptr;

    c_list = cairo_copy_clip_rectangle_list (const_cast<cobject*> (cobj ()));

    check_status_and_throw_exception (c_list->status);
    check_object_status_and_throw_exception (*this);

    rectangles.assign (c_list->rectangles,
                       c_list->rectangles + c_list->num_rectangles);

    cairo_rectangle_list_destroy (c_list);
  }

  auto
  Context::select_font_face (const std::string& family,
                             ToyFontFace::Slant slant,
                             ToyFontFace::Weight weight) -> void
  {
    cairo_select_font_face (cobj (),
                            family.c_str (),
                            static_cast<cairo_font_slant_t> (slant),
                            static_cast<cairo_font_weight_t> (weight));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_font_size (const double size) -> void
  {
    cairo_set_font_size (cobj (), size);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_font_matrix (const Matrix& matrix) -> void
  {
    cairo_set_font_matrix (cobj (), &matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_font_matrix (Matrix& matrix) const -> void
  {
    cairo_get_font_matrix (const_cast<cobject*> (cobj ()), &matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_font_options (const FontOptions& options) -> void
  {
    cairo_set_font_options (cobj (), options.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_font_options (FontOptions& options) const -> void
  {
    cairo_get_font_options (const_cast<cobject*> (cobj ()), options.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_scaled_font (const RefPtr<const ScaledFont>& scaled_font) -> void
  {
    cairo_set_scaled_font (cobj (), scaled_font->cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_scaled_font () -> RefPtr<ScaledFont>
  {
    const auto font = cairo_get_scaled_font (cobj ());
    check_object_status_and_throw_exception (*this);
    return make_refptr_for_instance<ScaledFont> (new ScaledFont (font, false));
  }

  auto
  Context::show_text (const std::string& utf8) -> void
  {
    cairo_show_text (cobj (), utf8.c_str ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::show_text_glyphs (const std::string& utf8,
                             const std::vector<Glyph>& glyphs,
                             const std::vector<TextCluster>& clusters,
                             TextClusterFlags cluster_flags) -> void
  {
    cairo_show_text_glyphs (
        cobj (),
        utf8.c_str (),
        utf8.size (),
        glyphs.empty () ? nullptr : &glyphs[0],
        glyphs.size (),
        clusters.empty () ? nullptr : &clusters[0],
        clusters.size (),
        static_cast<cairo_text_cluster_flags_t> (cluster_flags));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::show_glyphs (const std::vector<Glyph>& glyphs) -> void
  {
    cairo_show_glyphs (cobj (),
                       glyphs.empty () ? nullptr : &glyphs[0],
                       glyphs.size ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_font_face () -> RefPtr<FontFace>
  {
    const auto cfontface = cairo_get_font_face (cobj ());
    check_object_status_and_throw_exception (*this);
    return make_refptr_for_instance<FontFace> (new FontFace (cfontface, false));
  }

  auto
  Context::get_font_face () const -> RefPtr<const FontFace>
  {
    const auto cfontface = cairo_get_font_face (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return make_refptr_for_instance<const FontFace> (
        new FontFace (cfontface, false));
  }

  auto
  Context::get_font_extents (FontExtents& extents) const -> void
  {
    cairo_font_extents (const_cast<cobject*> (cobj ()), &extents);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::set_font_face (const RefPtr<const FontFace>& font_face) -> void
  {
    cairo_set_font_face (cobj (),
                         const_cast<cairo_font_face_t*> (font_face->cobj ()));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_text_extents (const std::string& utf8,
                             TextExtents& extents) const -> void
  {
    cairo_text_extents (const_cast<cobject*> (cobj ()),
                        utf8.c_str (),
                        &extents);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_glyph_extents (const std::vector<Glyph>& glyphs,
                              TextExtents& extents) const -> void
  {
    cairo_glyph_extents (const_cast<cobject*> (cobj ()),
                         glyphs.empty () ? nullptr : &glyphs[0],
                         glyphs.size (),
                         &extents);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::text_path (const std::string& utf8) -> void
  {
    cairo_text_path (cobj (), utf8.c_str ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::glyph_path (const std::vector<Glyph>& glyphs) -> void
  {
    cairo_glyph_path (cobj (),
                      glyphs.empty () ? nullptr : &glyphs[0],
                      glyphs.size ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_operator () const -> Operator
  {
    const auto result = static_cast<Operator> (
        cairo_get_operator (const_cast<cobject*> (cobj ())));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  static auto
  get_pattern_wrapper (cairo_pattern_t* pattern) -> RefPtr<Pattern>
  {
    const auto pattern_type = cairo_pattern_get_type (pattern);
    switch (pattern_type)
    {
      case CAIRO_PATTERN_TYPE_SOLID:
        return make_refptr_for_instance<SolidPattern> (
            new SolidPattern (pattern, false));
        break;
      case CAIRO_PATTERN_TYPE_SURFACE:
        return make_refptr_for_instance<SurfacePattern> (
            new SurfacePattern (pattern, false));
        break;
      case CAIRO_PATTERN_TYPE_LINEAR:
        return make_refptr_for_instance<LinearGradient> (
            new LinearGradient (pattern, false));
        break;
      case CAIRO_PATTERN_TYPE_RADIAL:
        return make_refptr_for_instance<RadialGradient> (
            new RadialGradient (pattern, false));
        break;
      default:
        return make_refptr_for_instance<Pattern> (new Pattern (pattern, false));
    }
  }

  auto
  Context::get_source () -> RefPtr<Pattern>
  {
    const auto pattern = cairo_get_source (cobj ());
    check_object_status_and_throw_exception (*this);
    return get_pattern_wrapper (pattern);
  }

  auto
  Context::get_source () const -> RefPtr<const Pattern>
  {
    const auto pattern = cairo_get_source (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return get_pattern_wrapper (pattern);
  }

  auto
  Context::get_source_for_surface () -> RefPtr<SurfacePattern>
  {
    const auto pattern = cairo_get_source (cobj ());
    check_object_status_and_throw_exception (*this);
    const auto pattern_type = cairo_pattern_get_type (pattern);
    if (pattern_type != CAIRO_PATTERN_TYPE_SURFACE)
      return {};
    return make_refptr_for_instance<SurfacePattern> (
        new SurfacePattern (pattern, false));
  }

  auto
  Context::get_source_for_surface () const -> RefPtr<const SurfacePattern>
  {
    return const_cast<Context*> (this)->get_source_for_surface ();
  }

  auto
  Context::get_tolerance () const -> double
  {
    const auto result = cairo_get_tolerance (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_antialias () const -> Antialias
  {
    const auto result = static_cast<Antialias> (
        cairo_get_antialias (const_cast<cobject*> (cobj ())));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::has_current_point () const -> bool
  {
    return cairo_has_current_point (const_cast<cobject*> (cobj ()));
  }

  auto
  Context::get_current_point (double& x, double& y) const -> void
  {
    cairo_get_current_point (const_cast<cobject*> (cobj ()), &x, &y);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_fill_rule () const -> FillRule
  {
    const auto result = static_cast<FillRule> (
        cairo_get_fill_rule (const_cast<cobject*> (cobj ())));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_line_width () const -> double
  {
    const auto result = cairo_get_line_width (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_line_cap () const -> LineCap
  {
    const auto result = static_cast<LineCap> (
        cairo_get_line_cap (const_cast<cobject*> (cobj ())));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_line_join () const -> LineJoin
  {
    const auto result = static_cast<LineJoin> (
        cairo_get_line_join (const_cast<cobject*> (cobj ())));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_miter_limit () const -> double
  {
    const auto result = cairo_get_miter_limit (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return result;
  }

  auto
  Context::get_dash (std::vector<double>& dashes, double& offset) const -> void
  {
    const auto cnt = cairo_get_dash_count (const_cast<cobject*> (cobj ()));
    const auto dash_array = new double[cnt];
    cairo_get_dash (const_cast<cobject*> (cobj ()), dash_array, &offset);
    check_object_status_and_throw_exception (*this);
    dashes.assign (dash_array, dash_array + cnt);
    delete[] dash_array;
  }

  auto
  Context::get_matrix (Matrix& matrix) -> void
  {
    cairo_get_matrix (cobj (), &matrix);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_matrix () const -> Matrix
  {
    Matrix m;
    cairo_get_matrix (const_cast<cobject*> (cobj ()), &m);
    check_object_status_and_throw_exception (*this);
    return m;
  }

  static auto
  get_surface_wrapper (cairo_surface_t* surface) -> RefPtr<Surface>
  {
    const auto surface_type = cairo_surface_get_type (surface);
    switch (surface_type)
    {
      case CAIRO_SURFACE_TYPE_IMAGE:
        return make_refptr_for_instance<ImageSurface> (
            new ImageSurface (surface, false));
        break;
#if CAIRO_HAS_PDF_SURFACE
      case CAIRO_SURFACE_TYPE_PDF:
        return make_refptr_for_instance<PdfSurface> (
            new PdfSurface (surface, false));
        break;
#endif
#if CAIRO_HAS_PS_SURFACE
      case CAIRO_SURFACE_TYPE_PS:
        return make_refptr_for_instance<PsSurface> (
            new PsSurface (surface, false));
        break;
#endif
#if CAIRO_HAS_XLIB_SURFACE
      case CAIRO_SURFACE_TYPE_XLIB:
        return wrap_surface_xlib (surface);
        break;
#endif
#if CAIRO_HAS_GLITZ_SURFACE
      case CAIRO_SURFACE_TYPE_GLITZ:
        return make_refptr_for_instance<GlitzSurface> (
            new GlitzSurface (surface, false));
        break;
#endif
#if CAIRO_HAS_QUARTZ_SURFACE
      case CAIRO_SURFACE_TYPE_QUARTZ:
        return wrap_surface_quartz (surface);
        break;
#endif
#if CAIRO_HAS_SCRIPT_SURFACE
      case CAIRO_SURFACE_TYPE_SCRIPT:
        return make_refptr_for_instance<ScriptSurface> (
            new ScriptSurface (surface, false));
        break;
#endif
#if CAIRO_HAS_WIN32_SURFACE
      case CAIRO_SURFACE_TYPE_WIN32:
        return wrap_surface_win32 (surface);
        break;
#endif
#if CAIRO_HAS_SVG_SURFACE
      case CAIRO_SURFACE_TYPE_SVG:
        return make_refptr_for_instance<SvgSurface> (
            new SvgSurface (surface, false));
        break;
#endif

      case CAIRO_SURFACE_TYPE_DIRECTFB:
      case CAIRO_SURFACE_TYPE_OS2:
      case CAIRO_SURFACE_TYPE_BEOS:
      case CAIRO_SURFACE_TYPE_XCB:
      default:
        return make_refptr_for_instance<Surface> (new Surface (surface, false));
    }
  }

  auto
  Context::get_target () -> RefPtr<Surface>
  {
    const auto surface = cairo_get_target (cobj ());
    check_object_status_and_throw_exception (*this);
    return get_surface_wrapper (surface);
  }

  auto
  Context::get_target () const -> RefPtr<const Surface>
  {
    const auto surface = cairo_get_target (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return get_surface_wrapper (surface);
  }

  auto
  Context::copy_path () const -> Path*
  {
    const auto cresult = cairo_copy_path (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return new Path (cresult, true);
  }

  auto
  Context::get_path_extents (double& x1,
                             double& y1,
                             double& x2,
                             double& y2) const -> void
  {
    cairo_path_extents (const_cast<cobject*> (cobj ()), &x1, &y1, &x2, &y2);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::copy_path_flat () const -> Path*
  {
    const auto cresult = cairo_copy_path_flat (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return new Path (cresult, true);
  }

  auto
  Context::append_path (const Path& path) -> void
  {
    cairo_append_path (cobj (), path.cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::push_group () -> void
  {
    cairo_push_group (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::push_group_with_content (Content content) -> void
  {
    cairo_push_group_with_content (cobj (),
                                   static_cast<cairo_content_t> (content));
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::pop_group () -> RefPtr<Pattern>
  {
    const auto pattern = cairo_pop_group (cobj ());
    check_object_status_and_throw_exception (*this);
    return get_pattern_wrapper (pattern);
  }

  auto
  Context::pop_group_to_source () -> void
  {
    cairo_pop_group_to_source (cobj ());
    check_object_status_and_throw_exception (*this);
  }

  auto
  Context::get_group_target () -> RefPtr<Surface>
  {
    const auto surface = cairo_get_group_target (cobj ());

    if (!surface)
    {
      throw_exception (CAIRO_STATUS_NULL_POINTER);
    }

    return get_surface_wrapper (surface);
  }

  auto
  Context::get_group_target () const -> RefPtr<const Surface>
  {
    const auto surface =
        cairo_get_group_target (const_cast<cobject*> (cobj ()));

    if (!surface)
    {
      throw_exception (CAIRO_STATUS_NULL_POINTER);
    }

    return get_surface_wrapper (surface);
  }

  SaveGuard::SaveGuard (const RefPtr<Context>& context)
    : ctx_{context}
  {
    if (ctx_)
      ctx_->save ();
  }

  SaveGuard::~SaveGuard ()
  {
    if (ctx_)
      ctx_->restore ();
  }

} // namespace cairo
