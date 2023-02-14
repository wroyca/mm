

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/item.hxx>
#include <libmm-pango/item_p.hxx>

#include <libmm-pango/attributes.hxx>
#include <libmm-pango/font.hxx>
#include <libmm-pango/glyphstring.hxx>

namespace Pango
{

  Analysis::Analysis () = default;

  Analysis::Analysis (const PangoAnalysis* src)
    : gobject_ (*src)
  {
  }

  auto
  Analysis::get_extra_attrs () const -> std::vector<Attribute>
  {
    using SListHandler_Attribute =
        Glib::SListHandler<Attribute, AttributeTraits>;
    return SListHandler_Attribute::slist_to_vector (gobj ()->extra_attrs,
                                                    Glib::OWNERSHIP_NONE);
  }

  Item::Item (const Item& src)
    : gobject_ (src.gobject_ ? pango_item_copy (src.gobject_) : nullptr)
  {
  }

  Item::Item (PangoItem* castitem, const bool make_a_copy)
  {
    if (make_a_copy)
    {
      if (castitem)
        gobject_ = pango_item_copy (castitem);
      else
        gobject_ = nullptr;
    }
    else
    {
      gobject_ = castitem;
    }
  }

  auto
  Item::operator= (const Item& src) -> Item&
  {
    auto* const new_gobject = src.gobject_ ? pango_item_copy (src.gobject_) :
                                             nullptr;

    if (gobject_)
      pango_item_free (gobject_);
    gobject_ = new_gobject;

    return *this;
  }

  Item::~Item ()
  {
    if (gobject_)
      pango_item_free (gobject_);
  }

  auto
  Item::gobj_copy () const -> PangoItem*
  {
    return pango_item_copy (gobject_);
  }

  auto
  Item::get_analysis () const -> Analysis
  {
    return Analysis (&gobj ()->analysis);
  }

  auto
  Item::get_segment (const Glib::ustring& text) const -> Glib::ustring
  {
    const char* const start = text.data () + gobj ()->offset;
    return {start, start + gobj ()->length};
  }

  auto
  Item::shape (const Glib::ustring& text) const -> GlyphString
  {
    return GlyphString (text, get_analysis ());
  }

  auto
  Item::shape (const Glib::ustring& item_text,
               const Glib::ustring& paragraph_text,
               const ShapeFlags flags) const -> GlyphString
  {
    return GlyphString (item_text, paragraph_text, get_analysis (), flags);
  }

} // namespace Pango

namespace Glib
{

  auto
  wrap (PangoAnalysis* object) -> Pango::Analysis&
  {
    return *reinterpret_cast<Pango::Analysis*> (object);
  }

  auto
  wrap (const PangoAnalysis* object) -> const Pango::Analysis&
  {
    return *reinterpret_cast<const Pango::Analysis*> (object);
  }

  auto
  wrap (PangoItem* object, const bool take_copy) -> Pango::Item
  {
    return Pango::Item (object, take_copy);
  }

} // namespace Glib

namespace
{
}

auto
Glib::Value<Pango::ShapeFlags>::value_type () -> GType
{
  return pango_shape_flags_get_type ();
}

namespace Pango
{

  auto
  Analysis::get_font () -> Glib::RefPtr<Font>
  {
    Glib::RefPtr<Font> ref_ptr (Glib::wrap (gobj ()->font));

    if (ref_ptr)
      ref_ptr->reference ();

    return ref_ptr;
  }

  auto
  Analysis::get_font () const -> Glib::RefPtr<const Font>
  {
    Glib::RefPtr<const Font> ref_ptr (Glib::wrap (gobj ()->font));

    if (ref_ptr)
      ref_ptr->reference ();

    return ref_ptr;
  }

  auto
  Analysis::get_level () const -> guint8
  {
    return gobj ()->level;
  }

  auto
  Analysis::get_language () const -> Language
  {
    return Language (gobj ()->language);
  }

} // namespace Pango

namespace Pango
{

  auto
  Item::split (const int split_index, const int split_offset) -> Item
  {
    return Item (pango_item_split (gobj (), split_index, split_offset));
  }

  auto
  Item::get_offset () const -> int
  {
    return gobj ()->offset;
  }

  auto
  Item::get_length () const -> int
  {
    return gobj ()->length;
  }

  auto
  Item::get_num_chars () const -> int
  {
    return gobj ()->num_chars;
  }

} // namespace Pango
