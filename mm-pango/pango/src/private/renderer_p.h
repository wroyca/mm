// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _PANGOMM_RENDERER_P_H
#define _PANGOMM_RENDERER_P_H


#include <glibmm/private/object_p.h>
#include <pango/pango.h>

#include <glibmm/class.h>

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

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static void draw_glyphs_vfunc_callback(PangoRenderer* self, PangoFont* font, PangoGlyphString* glyphs, int x, int y);
  static void draw_rectangle_vfunc_callback(PangoRenderer* self, PangoRenderPart part, int x, int y, int width, int height);
  static void draw_error_underline_vfunc_callback(PangoRenderer* self, int x, int y, int width, int height);
  static void draw_shape_vfunc_callback(PangoRenderer* self, PangoAttrShape* attr, int x, int y);
  static void draw_trapezoid_vfunc_callback(PangoRenderer* self, PangoRenderPart part, double y1, double x11, double x21, double y2, double x12, double x22);
  static void draw_glyph_vfunc_callback(PangoRenderer* self, PangoFont* font, PangoGlyph glyph, double x, double y);
  static void part_changed_vfunc_callback(PangoRenderer* self, PangoRenderPart part);
  static void begin_vfunc_callback(PangoRenderer* self);
  static void end_vfunc_callback(PangoRenderer* self);
  static void prepare_run_vfunc_callback(PangoRenderer* self, PangoGlyphItem* run);
  static void draw_glyph_item_vfunc_callback(PangoRenderer* self, const char* text, PangoGlyphItem* glyph_item, int x, int y);
};


} // namespace Pango


#endif /* _PANGOMM_RENDERER_P_H */

