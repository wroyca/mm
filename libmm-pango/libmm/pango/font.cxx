// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/font.hxx>
#include <libmm/pango/font_p.hxx>

#include <libmm/pango/fontface.hxx>
#include <libmm/pango/fontmap.hxx>

namespace pango
{

  auto
  Font::get_metrics () const -> FontMetrics
  {
    return FontMetrics (
        pango_font_get_metrics (const_cast<PangoFont*> (gobj ()), 0));
  }

  auto
  Font::get_glyph_ink_extents (const Glyph glyph) const -> Rectangle
  {
    Rectangle ink_rect;
    pango_font_get_glyph_extents (const_cast<PangoFont*> (gobj ()),
                                  glyph,
                                  ink_rect.gobj (),
                                  0);
    return ink_rect;
  }

  auto
  Font::get_glyph_logical_extents (const Glyph glyph) const -> Rectangle
  {
    Rectangle logical_rect;
    pango_font_get_glyph_extents (const_cast<PangoFont*> (gobj ()),
                                  glyph,
                                  0,
                                  logical_rect.gobj ());
    return logical_rect;
  }

} // namespace pango

namespace
{
}

namespace glib
{

  auto
  wrap (PangoFont* object, const bool take_copy) -> RefPtr<pango::Font>
  {
    return glib::make_refptr_for_instance<pango::Font> (
        dynamic_cast<pango::Font*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace pango
{

  auto
  Font_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Font_Class::class_init_function;

      register_derived_type (pango_font_get_type ());
    }

    return *this;
  }

  auto
  Font_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Font_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Font ((PangoFont*) object);
  }

  auto
  Font::gobj_copy () -> PangoFont*
  {
    reference ();
    return gobj ();
  }

  Font::Font (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Font::Font (PangoFont* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Font::Font (Font&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Font::operator= (Font&& src) noexcept -> Font&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Font::~Font () noexcept = default;

  Font::CppClassType Font::font_class_;

  auto
  Font::get_type () -> GType
  {
    return font_class_.init ().get_type ();
  }

  auto
  Font::get_base_type () -> GType
  {
    return pango_font_get_type ();
  }

  auto
  Font::describe () const -> FontDescription
  {
    return FontDescription (
        pango_font_describe (const_cast<PangoFont*> (gobj ())));
  }

  auto
  Font::describe_with_absolute_size () const -> FontDescription
  {
    return FontDescription (pango_font_describe_with_absolute_size (
        const_cast<PangoFont*> (gobj ())));
  }

  auto
  Font::get_coverage (const Language& language) const -> glib::RefPtr<Coverage>
  {
    return glib::wrap (pango_font_get_coverage (
        const_cast<PangoFont*> (gobj ()),
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  Font::get_metrics (const Language& language) const -> FontMetrics
  {
    return FontMetrics (
        pango_font_get_metrics (const_cast<PangoFont*> (gobj ()),
                                const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  Font::get_glyph_extents (const Glyph glyph,
                           Rectangle& ink_rect,
                           Rectangle& logical_rect) const -> void
  {
    pango_font_get_glyph_extents (const_cast<PangoFont*> (gobj ()),
                                  glyph,
                                  ink_rect.gobj (),
                                  logical_rect.gobj ());
  }

  auto
  Font::get_font_map () -> glib::RefPtr<FontMap>
  {
    return glib::wrap (pango_font_get_font_map (gobj ()));
  }

  auto
  Font::get_font_map () const -> glib::RefPtr<const FontMap>
  {
    return const_cast<Font*> (this)->get_font_map ();
  }

  auto
  Font::get_face () -> glib::RefPtr<FontFace>
  {
    auto retvalue = glib::wrap (pango_font_get_face (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Font::get_face () const -> glib::RefPtr<const FontFace>
  {
    return const_cast<Font*> (this)->get_face ();
  }

  auto
  Font::has_char (const gunichar wc) const -> bool
  {
    return pango_font_has_char (const_cast<PangoFont*> (gobj ()), wc);
  }

} // namespace pango
