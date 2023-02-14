

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/glyphitem.hxx>
#include <libmm-pango/glyphitem_p.hxx>

#include <libmm-pango/glyphstring.hxx>
#include <libmm-pango/item.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoGlyphItem* object, const bool take_copy) -> Pango::GlyphItem
  {
    return Pango::GlyphItem (object, take_copy);
  }

} // namespace Glib

namespace Pango
{

  auto
  GlyphItem::get_type () -> GType
  {
    return pango_glyph_item_get_type ();
  }

  GlyphItem::GlyphItem ()
    : gobject_ (nullptr)
  {
  }

  GlyphItem::GlyphItem (const GlyphItem& other)
    : gobject_ (other.gobject_ ? pango_glyph_item_copy (other.gobject_) :
                                 nullptr)
  {
  }

  GlyphItem::GlyphItem (GlyphItem&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  GlyphItem::operator= (GlyphItem&& other) noexcept -> GlyphItem&
  {
    GlyphItem temp (std::move (other));
    swap (temp);
    return *this;
  }

  GlyphItem::GlyphItem (PangoGlyphItem* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? pango_glyph_item_copy (gobject) :
                                         gobject)
  {
  }

  auto
  GlyphItem::operator= (const GlyphItem& other) -> GlyphItem&
  {
    GlyphItem temp (other);
    swap (temp);
    return *this;
  }

  GlyphItem::~GlyphItem () noexcept
  {
    if (gobject_)
      pango_glyph_item_free (gobject_);
  }

  auto
  GlyphItem::swap (GlyphItem& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  GlyphItem::gobj_copy () const -> PangoGlyphItem*
  {
    return pango_glyph_item_copy (gobject_);
  }

  auto
  GlyphItem::split (const Glib::ustring& text, const int split_index) -> GlyphItem
  {
    return Glib::wrap (
        pango_glyph_item_split (gobj (), text.c_str (), split_index));
  }

  auto
  GlyphItem::letter_space (const Glib::ustring& text,
                           const LogAttr& log_attrs,
                           const int letter_spacing) -> void
  {
    pango_glyph_item_letter_space (gobj (),
                                   text.c_str (),
                                   &const_cast<LogAttr&> (log_attrs),
                                   letter_spacing);
  }

  auto
  GlyphItem::get_item () const -> Item
  {
    return Item (gobj ()->item);
  }

  auto
  GlyphItem::get_glyphs () const -> GlyphString
  {
    return GlyphString (gobj ()->glyphs);
  }

} // namespace Pango
