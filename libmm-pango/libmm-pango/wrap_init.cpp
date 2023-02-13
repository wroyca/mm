

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/mm-glib.hpp>
#include <libmm-pango/wrap_init.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <libmm-pango/attributes.hpp>
#include <libmm-pango/attriter.hpp>
#include <libmm-pango/attrlist.hpp>
#include <libmm-pango/cairofontmap.hpp>
#include <libmm-pango/color.hpp>
#include <libmm-pango/context.hpp>
#include <libmm-pango/coverage.hpp>
#include <libmm-pango/font.hpp>
#include <libmm-pango/fontdescription.hpp>
#include <libmm-pango/fontface.hpp>
#include <libmm-pango/fontfamily.hpp>
#include <libmm-pango/fontmap.hpp>
#include <libmm-pango/fontmetrics.hpp>
#include <libmm-pango/fontset.hpp>
#include <libmm-pango/glyph.hpp>
#include <libmm-pango/glyphitem.hpp>
#include <libmm-pango/glyphstring.hpp>
#include <libmm-pango/item.hpp>
#include <libmm-pango/language.hpp>
#include <libmm-pango/layout.hpp>
#include <libmm-pango/layoutiter.hpp>
#include <libmm-pango/layoutline.hpp>
#include <libmm-pango/rectangle.hpp>
#include <libmm-pango/renderer.hpp>
#include <libmm-pango/tabarray.hpp>

extern "C"
{
//Declarations of the *_get_type() functions:

auto pango_context_get_type(void) -> GType;
auto pango_font_get_type(void) -> GType;
auto pango_font_face_get_type(void) -> GType;
auto pango_font_family_get_type(void) -> GType;
auto pango_font_map_get_type(void) -> GType;
auto pango_fontset_get_type(void) -> GType;
auto pango_layout_get_type(void) -> GType;
auto pango_renderer_get_type(void) -> GType;

//Declarations of the *_error_quark() functions:

} // extern "C"

namespace Pango {

//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

class Context_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Font_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontFace_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontFamily_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontMap_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Fontset_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Layout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Renderer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };

auto wrap_init () -> void
{
  // Register Error domains in the main namespace:

  // Map gtypes to gtkmm wrapper-creation functions:
  wrap_register(pango_context_get_type(), &Context_Class::wrap_new);
  wrap_register(pango_font_get_type(), &Font_Class::wrap_new);
  wrap_register(pango_font_face_get_type(), &FontFace_Class::wrap_new);
  wrap_register(pango_font_family_get_type(), &FontFamily_Class::wrap_new);
  wrap_register(pango_font_map_get_type(), &FontMap_Class::wrap_new);
  wrap_register(pango_fontset_get_type(), &Fontset_Class::wrap_new);
  wrap_register(pango_layout_get_type(), &Layout_Class::wrap_new);
  wrap_register(pango_renderer_get_type(), &Renderer_Class::wrap_new);

  // Register the gtkmm gtypes:
  g_type_ensure(Context::get_type());
  g_type_ensure(Font::get_type());
  g_type_ensure(FontFace::get_type());
  g_type_ensure(FontFamily::get_type());
  g_type_ensure(FontMap::get_type());
  g_type_ensure(Fontset::get_type());
  g_type_ensure(Layout::get_type());
  g_type_ensure(Renderer::get_type());

} // wrap_init()

} // Pango

