
#ifndef _PANGOMM_RENDERER_P_H
#define _PANGOMM_RENDERER_P_H


#include <libmm-glib/object_p.hxx>
#include <pango/pango.h>

#include <libmm-glib/class.hxx>

namespace Pango
{

class PANGOMM_API Renderer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Renderer;
  using BaseObjectType = PangoRenderer;
  using BaseClassType = PangoRendererClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Renderer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto draw_glyphs_vfunc_callback (
    PangoRenderer *self, PangoFont *font, PangoGlyphString *glyphs, int x, int y) -> void;
  static auto draw_rectangle_vfunc_callback (
    PangoRenderer *self, PangoRenderPart part, int x, int y, int width, int height) -> void;
  static auto draw_error_underline_vfunc_callback (
    PangoRenderer *self, int x, int y, int width, int height) -> void;
  static auto draw_shape_vfunc_callback (
    PangoRenderer *self, PangoAttrShape *attr, int x, int y) -> void;
  static auto draw_trapezoid_vfunc_callback (
    PangoRenderer *self, PangoRenderPart part, double y1, double x11, double x21, double y2,
    double x12, double x22) -> void;
  static auto draw_glyph_vfunc_callback (
    PangoRenderer *self, PangoFont *font, PangoGlyph glyph, double x, double y) -> void;
  static auto part_changed_vfunc_callback (PangoRenderer *self, PangoRenderPart part) -> void;
  static auto begin_vfunc_callback (PangoRenderer *self) -> void;
  static auto end_vfunc_callback (PangoRenderer *self) -> void;
  static auto prepare_run_vfunc_callback (PangoRenderer *self, PangoGlyphItem *run) -> void;
  static auto draw_glyph_item_vfunc_callback (
    PangoRenderer *self, const char *text, PangoGlyphItem *glyph_item, int x, int y) -> void;
};


} // namespace Pango


#endif /* _PANGOMM_RENDERER_P_H */
