// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_RENDERER_P_H
#define _PANGOMM_RENDERER_P_H

#include <libmm/glib/object_p.hxx>
#include <pango/pango.h>

#include <libmm/glib/class.hxx>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Renderer_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Renderer;
    using BaseObjectType = PangoRenderer;
    using BaseClassType = PangoRendererClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Renderer;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    draw_glyphs_vfunc_callback (PangoRenderer* self,
                                PangoFont* font,
                                PangoGlyphString* glyphs,
                                int x,
                                int y) -> void;
    static auto
    draw_rectangle_vfunc_callback (PangoRenderer* self,
                                   PangoRenderPart part,
                                   int x,
                                   int y,
                                   int width,
                                   int height) -> void;
    static auto
    draw_error_underline_vfunc_callback (PangoRenderer* self,
                                         int x,
                                         int y,
                                         int width,
                                         int height) -> void;
    static auto
    draw_shape_vfunc_callback (PangoRenderer* self,
                               PangoAttrShape* attr,
                               int x,
                               int y) -> void;
    static auto
    draw_trapezoid_vfunc_callback (PangoRenderer* self,
                                   PangoRenderPart part,
                                   double y1,
                                   double x11,
                                   double x21,
                                   double y2,
                                   double x12,
                                   double x22) -> void;
    static auto
    draw_glyph_vfunc_callback (PangoRenderer* self,
                               PangoFont* font,
                               PangoGlyph glyph,
                               double x,
                               double y) -> void;
    static auto
    part_changed_vfunc_callback (PangoRenderer* self, PangoRenderPart part)
        -> void;
    static auto
    begin_vfunc_callback (PangoRenderer* self) -> void;
    static auto
    end_vfunc_callback (PangoRenderer* self) -> void;
    static auto
    prepare_run_vfunc_callback (PangoRenderer* self, PangoGlyphItem* run)
        -> void;
    static auto
    draw_glyph_item_vfunc_callback (PangoRenderer* self,
                                    const char* text,
                                    PangoGlyphItem* glyph_item,
                                    int x,
                                    int y) -> void;
  };

} // namespace pango

#endif
