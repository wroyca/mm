// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_GLYPHITEM_H
#define _PANGOMM_GLYPHITEM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/pango/attributes.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoGlyphItem PangoGlyphItem;
}
#endif

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Item;
  class LIBMM_PANGO_SYMEXPORT GlyphString;

  class LIBMM_PANGO_SYMEXPORT GlyphItem
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

    auto
    swap (GlyphItem& other) noexcept -> void;

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
    split (const glib::ustring& text, int split_index) -> GlyphItem;

    auto
    letter_space (const glib::ustring& text,
                  const LogAttr& log_attrs,
                  int letter_spacing = 0) -> void;

    auto
    get_item () const -> Item;

    auto
    get_glyphs () const -> GlyphString;
  };

} // namespace pango

namespace pango
{

  inline auto
  swap (GlyphItem& lhs, GlyphItem& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoGlyphItem* object, bool take_copy = false) -> pango::GlyphItem;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::GlyphItem>
    : public glib::Value_Boxed<pango::GlyphItem>
  {
  };
#endif

} // namespace glib

#endif
