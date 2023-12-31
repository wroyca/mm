// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_ATTRITER_H
#define _PANGOMM_ATTRITER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/pango/attributes.hxx>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT AttrIter
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrIter;
    using BaseObjectType = PangoAttrIterator;
#endif

  private:
  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef int difference_type;

  protected:
    AttrIter ();

  public:
    explicit AttrIter (PangoAttrIterator* castitem, bool take_copy = true);
    AttrIter (const AttrIter& src);

    ~AttrIter ();

    auto
    operator= (const AttrIter& src) -> AttrIter&;

    auto
    operator++ () -> AttrIter&;

    auto
    operator++ (int) -> const AttrIter;

    explicit operator bool () const;

    auto
    next () -> bool;

    auto
    get_range (int& start, int& end) const -> void;

    auto
    get_attribute (AttrType type) const -> Attribute;

    auto
    get_font_desc () const -> FontDescription;

    auto
    get_language () const -> Language;

    auto
    get_extra_attrs () const -> std::vector<Attribute>;

    auto
    get_attrs () const -> std::vector<Attribute>;

    auto
    gobj () -> PangoAttrIterator*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoAttrIterator*
    {
      return gobject_;
    }

  protected:
    PangoAttrIterator* gobject_;
  };

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrIterator* object, bool take_copy = false) -> pango::AttrIter;

} // namespace glib

#endif
