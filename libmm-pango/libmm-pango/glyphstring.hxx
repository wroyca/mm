// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_GLYPHSTRING_H
#define _PANGOMM_GLYPHSTRING_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/context.hxx>
#include <libmm-pango/font.hxx>
#include <libmm-pango/glyph.hxx>
#include <libmm-pango/item.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoGlyphString PangoGlyphString;
}
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT GlyphString
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GlyphString;
    using BaseObjectType = PangoGlyphString;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    GlyphString ();

    explicit GlyphString (PangoGlyphString* gobject, bool make_a_copy = true);

    GlyphString (const GlyphString& other);
    auto
    operator= (const GlyphString& other) -> GlyphString&;

    GlyphString (GlyphString&& other) noexcept;
    auto
    operator= (GlyphString&& other) noexcept -> GlyphString&;

    ~GlyphString () noexcept;

    auto
    swap (GlyphString& other) noexcept -> void;

    auto
    gobj () -> PangoGlyphString*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoGlyphString*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoGlyphString*;

  protected:
    PangoGlyphString* gobject_;

  private:
  public:
    GlyphString (const Glib::ustring& text, const Analysis& analysis);

    GlyphString (const Glib::ustring& item_text,
                 const Glib::ustring& paragraph_text,
                 const Analysis& analysis,
                 ShapeFlags flags = ShapeFlags::NONE);

    auto
    set_size (int new_len) -> void;

    auto
    get_extents (const Glib::RefPtr<const Font>& font,
                 Rectangle& ink_rect,
                 Rectangle& logical_rect) const -> void;

    auto
    get_extents (int start,
                 int end,
                 const Glib::RefPtr<const Font>& font,
                 Rectangle& ink_rect,
                 Rectangle& logical_rect) const -> void;

    auto
    get_width () const -> int;

    auto
    get_ink_extents (const Glib::RefPtr<const Font>& font) const -> Rectangle;

    auto
    get_ink_extents (int start,
                     int end,
                     const Glib::RefPtr<const Font>& font) const -> Rectangle;

    auto
    get_logical_extents (const Glib::RefPtr<const Font>& font) const
        -> Rectangle;

    auto
    get_logical_extents (int start,
                         int end,
                         const Glib::RefPtr<const Font>& font) const
        -> Rectangle;

    auto
    get_logical_widths (const Glib::ustring& text, int embedding_level) const
        -> std::vector<int>;

    auto
    index_to_x (const Glib::ustring& text,
                const Analysis& analysis,
                int index,
                bool trailing) const -> int;

    auto
    x_to_index (const Glib::ustring& text,
                const Analysis& analysis,
                int x_pos,
                int& index,
                bool& trailing) const -> void;

    auto
    get_glyphs () const -> std::vector<GlyphInfo>;
  };

} // namespace Pango

namespace Pango
{

  inline auto
  swap (GlyphString& lhs, GlyphString& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoGlyphString* object, bool take_copy = false) -> Pango::GlyphString;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::GlyphString>
    : public Glib::Value_Boxed<Pango::GlyphString>
  {
  };
#endif

} // namespace Glib

#endif
