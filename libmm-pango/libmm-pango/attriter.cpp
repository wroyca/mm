


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/attriter.hpp>
#include <mm/pango/private/attriter_p.hpp>


/*
 *
 * Copyright 1998-1999 The Gtk-- Development Team
 * Copyright 2001      Free Software Foundation
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

namespace Pango
{

AttrIter::AttrIter()
:
  gobject_(0)
{}

AttrIter::AttrIter(const AttrIter& src)
:
  gobject_(src.gobject_ ? pango_attr_iterator_copy(src.gobject_) : nullptr)
{}

AttrIter::AttrIter(PangoAttrIterator* castitem, const bool take_copy)
{
  if(take_copy)
  {
    if(castitem)
      gobject_ = pango_attr_iterator_copy(castitem);
    else
      gobject_ = nullptr;
  }
  else
  {
    gobject_ = castitem;
  }
}

AttrIter::~AttrIter()
{
  if(gobject_)
     pango_attr_iterator_destroy(gobject_);
}

auto AttrIter::operator=(const AttrIter& src) -> AttrIter&
{
  auto* const new_gobject = src.gobject_ ? pango_attr_iterator_copy(src.gobject_) : nullptr;

  if(gobject_)
     pango_attr_iterator_destroy(gobject_);
  gobject_ = new_gobject;

  return *this;
}

auto AttrIter::operator++() -> AttrIter&
{
  next();
  return *this;
}

auto AttrIter::operator++(int) -> const AttrIter
{
  AttrIter previous(*this);
  next();
  return previous;
}

/* operator bool() cannot be implemented to work properly if a Pango::AttrIter is created
 * from an already invalid PangoAttrIterator* because there is no way to validate it.
 * Otherwise the iterator can only become invalid after some call to Pango::AttrIter::next()
 * in which case gobject_ is destroyed thus marking the iterator as invalid.
 */
AttrIter::operator bool() const
{
  return gobject_ != nullptr;
}

auto AttrIter::next() -> bool
{
  if(!pango_attr_iterator_next(gobj()))
  {
    pango_attr_iterator_destroy(gobject_);
    gobject_ = nullptr; // Mark as invalid. There is no other way to determine whether the iterator is valid later.
    return false;
  }
  else
    return true;
}

auto AttrIter::get_font_desc() const -> FontDescription
{
  FontDescription desc;
  pango_attr_iterator_get_font(const_cast<PangoAttrIterator*>(gobj()), desc.gobj(), 0, 0);

  // See pango ref docs for pango_attr_iterator_get_font.
  pango_font_description_set_family(desc.gobj(), pango_font_description_get_family(desc.gobj()));

  return desc;
}

auto AttrIter::get_language() const -> Language
{
  FontDescription desc;
  PangoLanguage* language = nullptr;

  pango_attr_iterator_get_font(const_cast<PangoAttrIterator*>(gobj()), desc.gobj(), &language, 0);

  return Language(language, true);
}

using SListHandler_Attribute = Glib::SListHandler<Attribute, AttributeTraits>;

auto AttrIter::get_extra_attrs() const -> std::vector<Attribute>
{
  FontDescription desc;
  GSList* extra_attrs = nullptr;

  pango_attr_iterator_get_font(const_cast<PangoAttrIterator*>(gobj()), desc.gobj(), 0, &extra_attrs);

  return SListHandler_Attribute::slist_to_vector(extra_attrs, Glib::OWNERSHIP_DEEP);
}

auto AttrIter::get_attrs() const -> std::vector<Attribute>
{
  const auto attrs = pango_attr_iterator_get_attrs( const_cast<PangoAttrIterator*>(gobj()) );
  return SListHandler_Attribute::slist_to_vector(attrs, Glib::OWNERSHIP_DEEP);
}


} /* namespace Pango */


namespace Glib
{

auto wrap(PangoAttrIterator* object, const bool take_copy) -> Pango::AttrIter
{
  return Pango::AttrIter(object, take_copy);
}

} /* namespace Glib */


namespace
{
} // anonymous namespace


namespace Pango
{


auto AttrIter::get_range (int &start, int &end) const -> void
{
  pango_attr_iterator_range(const_cast<PangoAttrIterator*>(gobj()), &start, &end);
}

auto AttrIter::get_attribute(AttrType type) const -> Attribute
{
  return Attribute(pango_attr_iterator_get(const_cast<PangoAttrIterator*>(gobj()), static_cast<PangoAttrType>(type)));
}


} // namespace Pango


