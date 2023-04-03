// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_ATTRLIST_H
#define _PANGOMM_ATTRLIST_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/pango/attributes.hxx>
#include <libmm/pango/attriter.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoAttrList PangoAttrList;
}
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT AttrList
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrList;
    using BaseObjectType = PangoAttrList;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    AttrList ();

    explicit AttrList (PangoAttrList* gobject, bool make_a_copy = true);

    AttrList (const AttrList& other);
    auto
    operator= (const AttrList& other) -> AttrList&;

    AttrList (AttrList&& other) noexcept;
    auto
    operator= (AttrList&& other) noexcept -> AttrList&;

    ~AttrList () noexcept;

    auto
    swap (AttrList& other) noexcept -> void;

    auto
    gobj () -> PangoAttrList*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoAttrList*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoAttrList*;

  protected:
    PangoAttrList* gobject_;

  private:
  public:
    explicit AttrList (const Glib::ustring& markup_text,
                       gunichar accel_marker = 0);

    AttrList (const Glib::ustring& markup_text,
              gunichar accel_marker,
              Glib::ustring& text,
              gunichar& accel_char);

    explicit operator bool () const;

    auto
    insert (Attribute& attr) -> void;

    auto
    insert_before (Attribute& attr) -> void;

    auto
    change (Attribute& attr) -> void;

    auto
    splice (AttrList& other, int pos, int len) -> void;

    auto
    update (int pos, int remove, int add) -> void;

    auto
    get_attributes () const -> std::vector<Attribute>;

    auto
    equal (const AttrList& other_list) const -> bool;

    auto
    to_string () const -> Glib::ustring;

    static auto
    from_string (const Glib::ustring& text) -> AttrList;

    auto
    get_iter () -> AttrIter;
  };

} // namespace Pango

namespace Pango
{

  inline auto
  swap (AttrList& lhs, AttrList& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrList* object, bool take_copy = false) -> Pango::AttrList;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::AttrList>
    : public Glib::Value_Boxed<Pango::AttrList>
  {
  };
#endif

} // namespace Glib

#endif
