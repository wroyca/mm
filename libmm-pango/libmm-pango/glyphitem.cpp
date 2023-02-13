


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/glyphitem.hpp>
#include <libmm-pango/glyphitem_p.hpp>


/*
 * Copyright 2002 The gtkmm Development Team
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

#include <libmm-pango/item.hpp>
#include <libmm-pango/glyphstring.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoGlyphItem* object, const bool take_copy) -> Pango::GlyphItem
{
  return Pango::GlyphItem(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
auto GlyphItem::get_type() -> GType
{
  return pango_glyph_item_get_type();
}

GlyphItem::GlyphItem()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

GlyphItem::GlyphItem(const GlyphItem& other)
:
  gobject_ (other.gobject_ ? pango_glyph_item_copy(other.gobject_) : nullptr)
{}

GlyphItem::GlyphItem(GlyphItem&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto GlyphItem::operator=(GlyphItem&& other) noexcept -> GlyphItem&
{
  GlyphItem temp (std::move(other));
  swap(temp);
  return *this;
}

GlyphItem::GlyphItem(PangoGlyphItem* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? pango_glyph_item_copy(gobject) : gobject)
{}

auto GlyphItem::operator=(const GlyphItem& other) -> GlyphItem&
{
  GlyphItem temp (other);
  swap(temp);
  return *this;
}

GlyphItem::~GlyphItem() noexcept
{
  if(gobject_)
    pango_glyph_item_free(gobject_);
}

auto GlyphItem::swap (GlyphItem &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto GlyphItem::gobj_copy() const -> PangoGlyphItem*
{
  return pango_glyph_item_copy(gobject_);
}


auto GlyphItem::split(const Glib::ustring& text, const int split_index) -> GlyphItem
{
  return Glib::wrap(pango_glyph_item_split(gobj(), text.c_str(), split_index));
}

auto GlyphItem::letter_space (
  const Glib::ustring &text, const LogAttr &log_attrs, const int letter_spacing) -> void
{
  pango_glyph_item_letter_space(gobj(), text.c_str(), &const_cast<LogAttr&>(log_attrs), letter_spacing);
}

auto GlyphItem::get_item() const -> Item
{
  return Item(gobj()->item);
}

auto GlyphItem::get_glyphs() const -> GlyphString
{
  return GlyphString(gobj()->glyphs);
}


} // namespace Pango


