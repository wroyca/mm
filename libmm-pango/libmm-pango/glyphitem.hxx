// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_GLYPHITEM_H
#define _PANGOMM_GLYPHITEM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-pango/attributes.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoGlyphItem PangoGlyphItem;
}
#endif

namespace Pango
{

  class PANGOMM_API Item;
  class PANGOMM_API GlyphString;

  class PANGOMM_API GlyphItem
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GlyphItem;
    using BaseObjectType = PangoGlyphItem;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    GlyphItem ();

    explicit GlyphItem (PangoGlyphItem* gobject, bool make_a_copy = true);

    GlyphItem (const GlyphItem& other);
    auto
    operator= (const GlyphItem& other) -> GlyphItem&;

    GlyphItem (GlyphItem&& other) noexcept;
    auto
    operator= (GlyphItem&& other) noexcept -> GlyphItem&;

    ~GlyphItem () noexcept;

    void
    swap (GlyphItem& other) noexcept;

    auto
    gobj () -> PangoGlyphItem*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoGlyphItem*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoGlyphItem*;

  protected:
    PangoGlyphItem* gobject_;

  private:
  public:
    auto
    split (const Glib::ustring& text, int split_index) -> GlyphItem;

    void
    letter_space (const Glib::ustring& text,
                  const LogAttr& log_attrs,
                  int letter_spacing = 0);

    auto
    get_item () const -> Item;

    auto
    get_glyphs () const -> GlyphString;
  };

} // namespace Pango

namespace Pango
{

  inline void
  swap (GlyphItem& lhs, GlyphItem& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoGlyphItem* object, bool take_copy = false) -> Pango::GlyphItem;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::GlyphItem>
    : public Glib::Value_Boxed<Pango::GlyphItem>
  {
  };
#endif

} // namespace Glib

#endif
