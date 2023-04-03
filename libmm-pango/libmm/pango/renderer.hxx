// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_RENDERER_H
#define _PANGOMM_RENDERER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/pango/context.hxx>
#include <libmm/pango/glyphitem.hxx>
#include <libmm/pango/glyphstring.hxx>
#include <libmm/pango/layout.hxx>
#include <libmm/pango/layoutline.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoRenderer = struct _PangoRenderer;
using PangoRendererClass = struct _PangoRendererClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class LIBMM_PANGO_SYMEXPORT Renderer_Class;
}
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT Renderer : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Renderer;
    using CppClassType = Renderer_Class;
    using BaseObjectType = PangoRenderer;
    using BaseClassType = PangoRendererClass;

    Renderer (const Renderer&) = delete;
    auto
    operator= (const Renderer&) -> Renderer& = delete;

  private:
    friend class Renderer_Class;
    static CppClassType renderer_class_;

  protected:
    explicit Renderer (const Glib::ConstructParams& construct_params);
    explicit Renderer (PangoRenderer* castitem);

#endif

  public:
    Renderer (Renderer&& src) noexcept;
    auto
    operator= (Renderer&& src) noexcept -> Renderer&;

    ~Renderer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoRenderer*
    {
      return reinterpret_cast<PangoRenderer*> (gobject_);
    }

    auto
    gobj () const -> const PangoRenderer*
    {
      return reinterpret_cast<PangoRenderer*> (gobject_);
    }

    auto
    gobj_copy () -> PangoRenderer*;

  private:
  public:
    enum class Part
    {
      FOREGROUND,
      BACKGROUND,
      UNDERLINE,
      STRIKETHROUGH,
      OVERLINE
    };

    auto
    draw_layout (const Glib::RefPtr<Layout>& layout, int x, int y) -> void;

    auto
    draw_layout_line (const Glib::RefPtr<LayoutLine>& line, int x, int y)
        -> void;

    auto
    draw_glyphs (const Glib::RefPtr<Font>& font,
                 const GlyphString& glyphs,
                 int x,
                 int y) -> void;

    auto
    draw_glyph_item (const Glib::ustring& text,
                     const GlyphItem& glyph_item,
                     int x,
                     int y) -> void;

    auto
    draw_rectangle (Part part, int x, int y, int width, int height) -> void;

    auto
    draw_error_underline (int x, int y, int width, int height) -> void;

    auto
    draw_trapezoid (Part part,
                    double y1,
                    double x11,
                    double x21,
                    double y2,
                    double x12,
                    double x22) -> void;

    auto
    draw_glyph (const Glib::RefPtr<Font>& font, Glyph glyph, double x, double y)
        -> void;

    auto
    activate () -> void;

    auto
    deactivate () -> void;

    auto
    part_changed (Part part) -> void;

    auto
    set_color (Part part, const Color& color) -> void;

    auto
    get_color (Part part) const -> Color;

    auto
    set_alpha (Part part, guint16 alpha) -> void;

    auto
    get_alpha (Part part) const -> guint16;

    auto
    set_matrix (const Matrix& matrix) -> void;

    auto
    get_matrix () const -> Matrix;

    auto
    get_layout () -> Glib::RefPtr<Layout>;

    auto
    get_layout () const -> Glib::RefPtr<const Layout>;

    auto
    get_layout_line () -> Glib::RefPtr<LayoutLine>;

    auto
    get_layout_line () const -> Glib::RefPtr<const LayoutLine>;

  protected:
    virtual auto
    draw_glyphs_vfunc (const Glib::RefPtr<Font>& font,
                       const GlyphString& glyphs,
                       int x,
                       int y) -> void;

    virtual auto
    draw_rectangle_vfunc (Part part, int x, int y, int width, int height)
        -> void;

    virtual auto
    draw_error_underline_vfunc (int x, int y, int width, int height) -> void;

    virtual auto
    draw_shape_vfunc (const AttrShape& attr, int x, int y) -> void;

    virtual auto
    draw_trapezoid_vfunc (Part part,
                          double y1,
                          double x11,
                          double x21,
                          double y2,
                          double x12,
                          double x22) -> void;

    virtual auto
    draw_glyph_vfunc (const Glib::RefPtr<Font>& font,
                      Glyph glyph,
                      double x,
                      double y) -> void;

    virtual auto
    part_changed_vfunc (Part part) -> void;

    virtual auto
    begin_vfunc () -> void;

    virtual auto
    end_vfunc () -> void;

    virtual auto
    prepare_run_vfunc (const GlyphItem& run) -> void;

    virtual auto
    draw_glyph_item_vfunc (const Glib::ustring& text,
                           const GlyphItem& glyph_item,
                           int x,
                           int y) -> void;

  public:
  public:
  protected:
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::Renderer::Part>
    : public Glib::Value_Enum<Pango::Renderer::Part>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoRenderer* object, bool take_copy = false) -> Glib::RefPtr<Pango::Renderer>;
} // namespace Glib

#endif
