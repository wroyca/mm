// SPDX-License-Identifier: LGPL-2.0-or-later

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/pango/wrap_init.hxx>

#include <libmm/pango/attributes.hxx>
#include <libmm/pango/attriter.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/cairofontmap.hxx>
#include <libmm/pango/color.hxx>
#include <libmm/pango/context.hxx>
#include <libmm/pango/coverage.hxx>
#include <libmm/pango/font.hxx>
#include <libmm/pango/fontdescription.hxx>
#include <libmm/pango/fontface.hxx>
#include <libmm/pango/fontfamily.hxx>
#include <libmm/pango/fontmap.hxx>
#include <libmm/pango/fontmetrics.hxx>
#include <libmm/pango/fontset.hxx>
#include <libmm/pango/glyph.hxx>
#include <libmm/pango/glyphitem.hxx>
#include <libmm/pango/glyphstring.hxx>
#include <libmm/pango/item.hxx>
#include <libmm/pango/language.hxx>
#include <libmm/pango/layout.hxx>
#include <libmm/pango/layoutiter.hxx>
#include <libmm/pango/layoutline.hxx>
#include <libmm/pango/rectangle.hxx>
#include <libmm/pango/renderer.hxx>
#include <libmm/pango/tabarray.hxx>

extern "C"
{
  auto
  pango_context_get_type (void) -> GType;
  auto
  pango_font_get_type (void) -> GType;
  auto
  pango_font_face_get_type (void) -> GType;
  auto
  pango_font_family_get_type (void) -> GType;
  auto
  pango_font_map_get_type (void) -> GType;
  auto
  pango_fontset_get_type (void) -> GType;
  auto
  pango_layout_get_type (void) -> GType;
  auto
  pango_renderer_get_type (void) -> GType;
}

namespace pango
{

  class Context_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Font_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FontFace_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FontFamily_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FontMap_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Fontset_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Layout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Renderer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  auto
  wrap_init () -> void
  {
    wrap_register (pango_context_get_type (), &Context_Class::wrap_new);
    wrap_register (pango_font_get_type (), &Font_Class::wrap_new);
    wrap_register (pango_font_face_get_type (), &FontFace_Class::wrap_new);
    wrap_register (pango_font_family_get_type (), &FontFamily_Class::wrap_new);
    wrap_register (pango_font_map_get_type (), &FontMap_Class::wrap_new);
    wrap_register (pango_fontset_get_type (), &Fontset_Class::wrap_new);
    wrap_register (pango_layout_get_type (), &Layout_Class::wrap_new);
    wrap_register (pango_renderer_get_type (), &Renderer_Class::wrap_new);

    g_type_ensure (Context::get_type ());
    g_type_ensure (Font::get_type ());
    g_type_ensure (FontFace::get_type ());
    g_type_ensure (FontFamily::get_type ());
    g_type_ensure (FontMap::get_type ());
    g_type_ensure (Fontset::get_type ());
    g_type_ensure (Layout::get_type ());
    g_type_ensure (Renderer::get_type ());
  }

} // namespace pango
