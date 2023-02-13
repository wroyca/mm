


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/attrlist.hpp>
#include <libmm-pango/attrlist_p.hpp>


/*
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

using SListHandler_Attribute = Glib::SListHandler<Attribute, AttributeTraits>;

AttrList::AttrList(const Glib::ustring& markup_text, const gunichar accel_marker)
{
  const gboolean bTest = pango_parse_markup(markup_text.c_str(), -1 /* means null-terminated */, accel_marker,
                                            &gobject_, 0, 0, 0);
  if(bTest == FALSE)
    gobject_ = nullptr;
}

AttrList::operator bool() const
{
  return gobj() != nullptr;
}

AttrList::AttrList(const Glib::ustring& markup_text, const gunichar accel_marker, Glib::ustring& text, gunichar& accel_char)
{
  //initialize output parameters:
  text.erase();
  accel_char = 0;

  gchar* pchText = nullptr;
  const gboolean bTest = pango_parse_markup(markup_text.c_str(), -1 /* means null-terminated */, accel_marker,
                                            &gobject_, &pchText, &accel_char, 0);
  if(bTest == FALSE)
  {
    gobject_ = nullptr;
  }
  else
  {
    text = pchText;
    g_free(pchText);
  }
}

auto AttrList::insert (Attribute &attr) -> void
{
  pango_attr_list_insert(gobj(), pango_attribute_copy(attr.gobj()));
}

auto AttrList::insert_before (Attribute &attr) -> void
{
  pango_attr_list_insert_before(gobj(), pango_attribute_copy(attr.gobj()));
}

auto AttrList::change (Attribute &attr) -> void
{
  pango_attr_list_change(gobj(), pango_attribute_copy(attr.gobj()));
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoAttrList* object, const bool take_copy) -> Pango::AttrList
{
  return Pango::AttrList(object, take_copy);
}

} // namespace Glib


namespace Pango
{


// static
auto AttrList::get_type() -> GType
{
  return pango_attr_list_get_type();
}

AttrList::AttrList()
:
  gobject_ (pango_attr_list_new())
{}

AttrList::AttrList(const AttrList& other)
:
  gobject_ (other.gobject_ ? pango_attr_list_copy(other.gobject_) : nullptr)
{}

AttrList::AttrList(AttrList&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto AttrList::operator=(AttrList&& other) noexcept -> AttrList&
{
  AttrList temp (std::move(other));
  swap(temp);
  return *this;
}

AttrList::AttrList(PangoAttrList* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? pango_attr_list_copy(gobject) : gobject)
{}

auto AttrList::operator=(const AttrList& other) -> AttrList&
{
  AttrList temp (other);
  swap(temp);
  return *this;
}

AttrList::~AttrList() noexcept
{
  if(gobject_)
    pango_attr_list_unref(gobject_);
}

auto AttrList::swap (AttrList &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto AttrList::gobj_copy() const -> PangoAttrList*
{
  return pango_attr_list_copy(gobject_);
}


auto AttrList::splice (AttrList &other, const int pos, const int len) -> void
{
  pango_attr_list_splice(gobj(), other.gobj(), pos, len);
}

auto AttrList::update (
  const int pos, const int remove, const int add) -> void
{
  pango_attr_list_update(gobj(), pos, remove, add);
}

auto AttrList::get_attributes() const -> std::vector<Attribute>
{
  return SListHandler_Attribute::slist_to_vector(pango_attr_list_get_attributes(const_cast<PangoAttrList*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto AttrList::equal(const AttrList& other_list) const -> bool
{
  return pango_attr_list_equal(const_cast<PangoAttrList*>(gobj()), const_cast<PangoAttrList*>(other_list.gobj()));
}

auto AttrList::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(pango_attr_list_to_string(const_cast<PangoAttrList*>(gobj())));
}

auto AttrList::from_string(const Glib::ustring& text) -> AttrList
{
  return AttrList(pango_attr_list_from_string(text.c_str()), false);
}

auto AttrList::get_iter() -> AttrIter
{
  return Glib::wrap(pango_attr_list_get_iterator(gobj()));
}


} // namespace Pango


