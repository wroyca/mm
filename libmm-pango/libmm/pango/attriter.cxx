// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/attriter.hxx>
#include <libmm/pango/attriter_p.hxx>

namespace pango
{

  AttrIter::AttrIter ()
    : gobject_ (0)
  {
  }

  AttrIter::AttrIter (const AttrIter& src)
    : gobject_ (src.gobject_ ? pango_attr_iterator_copy (src.gobject_) :
                               nullptr)
  {
  }

  AttrIter::AttrIter (PangoAttrIterator* castitem, const bool take_copy)
  {
    if (take_copy)
    {
      if (castitem)
        gobject_ = pango_attr_iterator_copy (castitem);
      else
        gobject_ = nullptr;
    }
    else
    {
      gobject_ = castitem;
    }
  }

  AttrIter::~AttrIter ()
  {
    if (gobject_)
      pango_attr_iterator_destroy (gobject_);
  }

  auto
  AttrIter::operator= (const AttrIter& src) -> AttrIter&
  {
    auto* const new_gobject =
        src.gobject_ ? pango_attr_iterator_copy (src.gobject_) : nullptr;

    if (gobject_)
      pango_attr_iterator_destroy (gobject_);
    gobject_ = new_gobject;

    return *this;
  }

  auto
  AttrIter::operator++ () -> AttrIter&
  {
    next ();
    return *this;
  }

  auto
  AttrIter::operator++ (int) -> const AttrIter
  {
    AttrIter previous (*this);
    next ();
    return previous;
  }

  AttrIter::operator bool () const
  {
    return gobject_ != nullptr;
  }

  auto
  AttrIter::next () -> bool
  {
    if (!pango_attr_iterator_next (gobj ()))
    {
      pango_attr_iterator_destroy (gobject_);
      gobject_ = nullptr;
      return false;
    }
    else
      return true;
  }

  auto
  AttrIter::get_font_desc () const -> FontDescription
  {
    FontDescription desc;
    pango_attr_iterator_get_font (const_cast<PangoAttrIterator*> (gobj ()),
                                  desc.gobj (),
                                  0,
                                  0);

    pango_font_description_set_family (
        desc.gobj (),
        pango_font_description_get_family (desc.gobj ()));

    return desc;
  }

  auto
  AttrIter::get_language () const -> Language
  {
    FontDescription desc;
    PangoLanguage* language = nullptr;

    pango_attr_iterator_get_font (const_cast<PangoAttrIterator*> (gobj ()),
                                  desc.gobj (),
                                  &language,
                                  0);

    return Language (language, true);
  }

  using SListHandler_Attribute = glib::SListHandler<Attribute, AttributeTraits>;

  auto
  AttrIter::get_extra_attrs () const -> std::vector<Attribute>
  {
    FontDescription desc;
    GSList* extra_attrs = nullptr;

    pango_attr_iterator_get_font (const_cast<PangoAttrIterator*> (gobj ()),
                                  desc.gobj (),
                                  0,
                                  &extra_attrs);

    return SListHandler_Attribute::slist_to_vector (extra_attrs,
                                                    glib::OWNERSHIP_DEEP);
  }

  auto
  AttrIter::get_attrs () const -> std::vector<Attribute>
  {
    const auto attrs = pango_attr_iterator_get_attrs (
        const_cast<PangoAttrIterator*> (gobj ()));
    return SListHandler_Attribute::slist_to_vector (attrs,
                                                    glib::OWNERSHIP_DEEP);
  }

} // namespace pango

namespace glib
{

  auto
  wrap (PangoAttrIterator* object, const bool take_copy) -> pango::AttrIter
  {
    return pango::AttrIter (object, take_copy);
  }

} // namespace glib

namespace
{
}

namespace pango
{

  auto
  AttrIter::get_range (int& start, int& end) const -> void
  {
    pango_attr_iterator_range (const_cast<PangoAttrIterator*> (gobj ()),
                               &start,
                               &end);
  }

  auto
  AttrIter::get_attribute (AttrType type) const -> Attribute
  {
    return Attribute (
        pango_attr_iterator_get (const_cast<PangoAttrIterator*> (gobj ()),
                                 static_cast<PangoAttrType> (type)));
  }

} // namespace pango
