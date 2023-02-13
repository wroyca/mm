

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <mm/glib/mm-glib.hpp>
#include <mm/pango/wrap_init.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <mm/pango/attributes.hpp>
#include <mm/pango/attriter.hpp>
#include <mm/pango/attrlist.hpp>
#include <mm/pango/cairofontmap.hpp>
#include <mm/pango/color.hpp>
#include <mm/pango/context.hpp>
#include <mm/pango/coverage.hpp>
#include <mm/pango/font.hpp>
#include <mm/pango/fontdescription.hpp>
#include <mm/pango/fontface.hpp>
#include <mm/pango/fontfamily.hpp>
#include <mm/pango/fontmap.hpp>
#include <mm/pango/fontmetrics.hpp>
#include <mm/pango/fontset.hpp>
#include <mm/pango/glyph.hpp>
#include <mm/pango/glyphitem.hpp>
#include <mm/pango/glyphstring.hpp>
#include <mm/pango/item.hpp>
#include <mm/pango/language.hpp>
#include <mm/pango/layout.hpp>
#include <mm/pango/layoutiter.hpp>
#include <mm/pango/layoutline.hpp>
#include <mm/pango/rectangle.hpp>
#include <mm/pango/renderer.hpp>
#include <mm/pango/tabarray.hpp>

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

