


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/item.hpp>
#include <mm/pango/private/item_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <mm/pango/font.hpp>
#include <mm/pango/attributes.hpp>
#include <mm/pango/glyphstring.hpp>

namespace Pango
{

Analysis::Analysis() = default;

Analysis::Analysis(const PangoAnalysis* src)
:
  gobject_ (*src)
{}

auto Analysis::get_extra_attrs() const -> std::vector<Attribute>
{
  using SListHandler_Attribute = Glib::SListHandler<Attribute, AttributeTraits>;
  return SListHandler_Attribute::slist_to_vector(gobj()->extra_attrs, Glib::OWNERSHIP_NONE);
}


Item::Item(const Item& src)
:
  gobject_ (src.gobject_ ? pango_item_copy(src.gobject_) : nullptr)
{}

Item::Item(PangoItem* castitem, const bool make_a_copy)
{
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.

  if(make_a_copy)
  {
    if(castitem)
      gobject_ = pango_item_copy(castitem);
    else
      gobject_ = nullptr;
  }
  else
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
}

auto Item::operator=(const Item& src) -> Item&
{
  auto* const new_gobject = src.gobject_ ? pango_item_copy(src.gobject_) : nullptr;

  if(gobject_)
    pango_item_free(gobject_);
  gobject_ = new_gobject;

  return *this;
}

Item::~Item()
{
  if(gobject_)
    pango_item_free(gobject_);
}

auto Item::gobj_copy() const -> PangoItem*
{
  return pango_item_copy(gobject_);
}

auto Item::get_analysis() const -> Analysis
{
  return Analysis(&gobj()->analysis);
}

auto Item::get_segment(const Glib::ustring& text) const -> Glib::ustring
{
  const char *const start = text.data() + gobj()->offset;
  return {start, start + gobj()->length};
}

auto Item::shape(const Glib::ustring& text) const -> GlyphString
{
  return GlyphString(text, get_analysis());
}

auto Item::shape(const Glib::ustring& item_text,
  const Glib::ustring& paragraph_text, const ShapeFlags flags) const -> GlyphString
{
  return GlyphString(item_text, paragraph_text, get_analysis(), flags);
}

} /* namespace Pango */


namespace Glib
{

auto wrap(PangoAnalysis* object) -> Pango::Analysis&
{
  return *reinterpret_cast<Pango::Analysis*>(object);
}

auto wrap(const PangoAnalysis* object) -> const Pango::Analysis&
{
  return *reinterpret_cast<const Pango::Analysis*>(object);
}

auto wrap(PangoItem* object, const bool take_copy) -> Pango::Item
{
  return Pango::Item(object, take_copy);
}

} /* namespace Glib */

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::ShapeFlags>::value_type() -> GType
{
  return pango_shape_flags_get_type();
}


namespace Pango
{


auto Analysis::get_font() -> Glib::RefPtr<Font>
{
  Glib::RefPtr<Font> ref_ptr(Glib::wrap(gobj()->font));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

auto Analysis::get_font() const -> Glib::RefPtr<const Font>
{
  Glib::RefPtr<const Font> ref_ptr(Glib::wrap(gobj()->font));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

auto Analysis::get_level() const -> guint8
{
  return gobj()->level;
}

auto Analysis::get_language() const -> Language
{
  return Language(gobj()->language);
}


} // namespace Pango


namespace Pango
{


auto Item::split(
  const int split_index, const int split_offset) -> Item
{
  return Item(pango_item_split(gobj(), split_index, split_offset));
}

auto Item::get_offset() const -> int
{
  return gobj()->offset;
}

auto Item::get_length() const -> int
{
  return gobj()->length;
}

auto Item::get_num_chars() const -> int
{
  return gobj()->num_chars;
}


} // namespace Pango


