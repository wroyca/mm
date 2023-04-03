// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/glyphstring.hxx>
#include <libmm/pango/glyphstring_p.hxx>

#include <libmm/glib/utility.hxx>
#include <pango/pangocairo.h>

namespace Pango
{

  GlyphString::GlyphString (const Glib::ustring& text, const Analysis& analysis)
    : gobject_ (pango_glyph_string_new ())
  {
    pango_shape (text.c_str (), text.bytes (), analysis.gobj (), gobj ());
  }

  GlyphString::GlyphString (const Glib::ustring& item_text,
                            const Glib::ustring& paragraph_text,
                            const Analysis& analysis,
                            ShapeFlags flags)
    : gobject_ (pango_glyph_string_new ())
  {
    pango_shape_with_flags (item_text.c_str (),
                            item_text.bytes (),
                            paragraph_text.c_str (),
                            paragraph_text.bytes (),
                            analysis.gobj (),
                            gobj (),
                            static_cast<PangoShapeFlags> (flags));
  }

  auto
  GlyphString::get_ink_extents (const Glib::RefPtr<const Font>& font) const -> Rectangle
  {
    Rectangle ink_rect;
    pango_glyph_string_extents (const_cast<PangoGlyphString*> (gobj ()),
                                const_cast<PangoFont*> (font->gobj ()),
                                ink_rect.gobj (),
                                0);
    return ink_rect;
  }

  auto
  GlyphString::get_ink_extents (const int start,
                                const int end,
                                const Glib::RefPtr<const Font>& font) const -> Rectangle
  {
    Rectangle ink_rect;
    pango_glyph_string_extents_range (const_cast<PangoGlyphString*> (gobj ()),
                                      start,
                                      end,
                                      const_cast<PangoFont*> (font->gobj ()),
                                      ink_rect.gobj (),
                                      0);
    return ink_rect;
  }

  auto
  GlyphString::get_logical_extents (const Glib::RefPtr<const Font>& font) const -> Rectangle
  {
    Rectangle logical_rect;
    pango_glyph_string_extents (const_cast<PangoGlyphString*> (gobj ()),
                                const_cast<PangoFont*> (font->gobj ()),
                                0,
                                logical_rect.gobj ());
    return logical_rect;
  }

  auto
  GlyphString::get_logical_extents (const int start,
                                    const int end,
                                    const Glib::RefPtr<const Font>& font) const -> Rectangle
  {
    Rectangle logical_rect;
    pango_glyph_string_extents_range (const_cast<PangoGlyphString*> (gobj ()),
                                      start,
                                      end,
                                      const_cast<PangoFont*> (font->gobj ()),
                                      0,
                                      logical_rect.gobj ());
    return logical_rect;
  }

  auto
  GlyphString::get_logical_widths (const Glib::ustring& text,
                                   const int embedding_level) const -> std::vector<int>
  {
    int* logical_widths = g_new (int, text.length ());
    pango_glyph_string_get_logical_widths (
        const_cast<PangoGlyphString*> (gobj ()),
        text.c_str (),
        text.bytes (),
        embedding_level,
        logical_widths);
    return Glib::ArrayHandler<int>::array_to_vector (logical_widths,
                                                     text.length (),
                                                     Glib::OWNERSHIP_SHALLOW);
  }

  auto
  GlyphString::index_to_x (const Glib::ustring& text,
                           const Analysis& analysis,
                           const int index,
                           const bool trailing) const -> int
  {
    int x_pos;
    pango_glyph_string_index_to_x (
        const_cast<PangoGlyphString*> (gobj ()),
        text.c_str (),
        text.bytes (),
        const_cast<PangoAnalysis*> (analysis.gobj ()),
        index,
        trailing,
        &x_pos);
    return x_pos;
  }

  auto
  GlyphString::x_to_index (const Glib::ustring& text,
                           const Analysis& analysis,
                           const int x_pos,
                           int& index,
                           bool& trailing) const -> void
  {
    gboolean trailing_temp = FALSE;
    pango_glyph_string_x_to_index (
        const_cast<PangoGlyphString*> (gobj ()),
        text.c_str (),
        text.bytes (),
        const_cast<PangoAnalysis*> (analysis.gobj ()),
        x_pos,
        &index,
        &trailing_temp);
    trailing = trailing_temp;
  }

  auto
  GlyphString::get_glyphs () const -> std::vector<GlyphInfo>
  {
    return Glib::ArrayHandler<GlyphInfo>::array_to_vector (
        reinterpret_cast<GlyphInfo*> (gobj ()->glyphs),
        gobj ()->num_glyphs,
        Glib::OWNERSHIP_NONE);
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoGlyphString* object, const bool take_copy) -> Pango::GlyphString
  {
    return Pango::GlyphString (object, take_copy);
  }

} // namespace Glib

namespace Pango
{

  auto
  GlyphString::get_type () -> GType
  {
    return pango_glyph_string_get_type ();
  }

  GlyphString::GlyphString ()
    : gobject_ (pango_glyph_string_new ())
  {
  }

  GlyphString::GlyphString (const GlyphString& other)
    : gobject_ (other.gobject_ ? pango_glyph_string_copy (other.gobject_) :
                                 nullptr)
  {
  }

  GlyphString::GlyphString (GlyphString&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  GlyphString::operator= (GlyphString&& other) noexcept -> GlyphString&
  {
    GlyphString temp (std::move (other));
    swap (temp);
    return *this;
  }

  GlyphString::GlyphString (PangoGlyphString* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? pango_glyph_string_copy (gobject) :
                                         gobject)
  {
  }

  auto
  GlyphString::operator= (const GlyphString& other) -> GlyphString&
  {
    GlyphString temp (other);
    swap (temp);
    return *this;
  }

  GlyphString::~GlyphString () noexcept
  {
    if (gobject_)
      pango_glyph_string_free (gobject_);
  }

  auto
  GlyphString::swap (GlyphString& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  GlyphString::gobj_copy () const -> PangoGlyphString*
  {
    return pango_glyph_string_copy (gobject_);
  }

  auto
  GlyphString::set_size (const int new_len) -> void
  {
    pango_glyph_string_set_size (gobj (), new_len);
  }

  auto
  GlyphString::get_extents (const Glib::RefPtr<const Font>& font,
                            Rectangle& ink_rect,
                            Rectangle& logical_rect) const -> void
  {
    pango_glyph_string_extents (
        const_cast<PangoGlyphString*> (gobj ()),
        const_cast<PangoFont*> (Glib::unwrap<Font> (font)),
        ink_rect.gobj (),
        logical_rect.gobj ());
  }

  auto
  GlyphString::get_extents (const int start,
                            const int end,
                            const Glib::RefPtr<const Font>& font,
                            Rectangle& ink_rect,
                            Rectangle& logical_rect) const -> void
  {
    pango_glyph_string_extents_range (
        const_cast<PangoGlyphString*> (gobj ()),
        start,
        end,
        const_cast<PangoFont*> (Glib::unwrap<Font> (font)),
        ink_rect.gobj (),
        logical_rect.gobj ());
  }

  auto
  GlyphString::get_width () const -> int
  {
    return pango_glyph_string_get_width (
        const_cast<PangoGlyphString*> (gobj ()));
  }

} // namespace Pango
