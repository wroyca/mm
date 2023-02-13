
#ifndef _PANGOMM_GLYPHSTRING_H
#define _PANGOMM_GLYPHSTRING_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* glyphstring.h
 *
 * Copyright (C) 1998-1999 The gtkmm Development Team
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
#include <mm/pango/glyph.hpp>
#include <mm/pango/item.hpp> // for Analysis and ShapeFlags
#include <mm/cairo/context.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoGlyphString PangoGlyphString; }
#endif

namespace Pango
{
/** A Pango::GlyphString is used to store strings of glyphs with geometry and visual attribute information.
 * It can be measured or drawn to the screen.
 */
class PANGOMM_API GlyphString
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = GlyphString;
  using BaseObjectType = PangoGlyphString;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  GlyphString();

  explicit GlyphString(PangoGlyphString* gobject, bool make_a_copy = true);

  GlyphString(const GlyphString& other);
  auto operator=(const GlyphString& other) -> GlyphString&;

  GlyphString(GlyphString&& other) noexcept;
  auto operator=(GlyphString&& other) noexcept -> GlyphString&;

  ~GlyphString() noexcept;

  void swap(GlyphString& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoGlyphString*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoGlyphString* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoGlyphString*;

protected:
  PangoGlyphString* gobject_;

private:


public:

  /** Constructs a string of glyphs from a string of characters.
   *
   * Given a segment of text and the corresponding Pango::Analysis structure
   * returned from Pango::Context::itemize(), convert the characters into glyphs.
   * You may also pass in only a substring of the item.
   *
   * It is recommended that you use the constructor with @a item_text and
   * @a paragraph_text parameters instead, since that API allows for shaping
   * interaction happening across text item boundaries.
   *
   * @param text The text to process. You must pass the same string into those
   *             member functions expecting a const Glib::ustring&.
   * @param analysis The analysis information returned from Pango::Context::itemize().
   */
  GlyphString(const Glib::ustring& text, const Analysis& analysis);

  /** Constructs a string of glyphs from a string of characters.
   *
   * Given a segment of text and the corresponding Pango::Analysis structure
   * returned from Pango::Context::itemize(), convert the characters into glyphs.
   * You may also pass in only a substring of the item.
   *
   * This is similar to the constructor with only one @a text parameter, except
   * it also takes @a flags and the full paragraph text as input, which will then
   * be used to perform certain cross-item shaping interactions. If you have
   * access to the broader text of which @a item_text is a part, provide the
   * broader text as @a paragraph_text.
   *
   * @newin{2,44}
   *
   * @param item_text Valid UTF-8 text to shape.
   * @param paragraph_text Text of the paragraph (see details).
   * @param analysis The analysis information returned from Pango::Context::itemize().
   * @param flags Flags influencing the shaping process.
   */
  GlyphString(const Glib::ustring& item_text, const Glib::ustring& paragraph_text,
    const Analysis& analysis, ShapeFlags flags = ShapeFlags::NONE);


  /** Resize a glyph string to the given length.
   *
   * @param new_len The new length of the string.
   */
  void set_size(int new_len);


  /** Compute the logical and ink extents of a glyph string. See the documentation
   * for Pango::Font::get_glyph_extents() for details about the interpretation
   * of the rectangles.
   *
   * @param font A Pango::Font.
   * @param ink_rect Rectangle used to store the extents of the glyph string as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph string.
   */
  void get_extents(const Glib::RefPtr<const Font>& font, Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Computes the extents of a sub-portion of a glyph string. The extents are
   * relative to the start of the glyph string range (the origin of their
   * coordinate system is at the start of the range, not at the start of the entire
   * glyph string).
   *
   * @param start Start index.
   * @param end End index (the range is the set of bytes with
   *               indices such that start &lt;= index &lt; end).
   * @param font A Pango::Font.
   * @param ink_rect Rectangle used to store the extents of the glyph string range as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph string range.
   */
  void get_extents(int start, int end, const Glib::RefPtr<const Font>& font, Rectangle& ink_rect, Rectangle& logical_rect) const;


  /** Computes the logical width of the glyph string.
   *
   * This can also be computed using extents().
   * However, since this only computes the width, it's much faster. This
   * is in fact only a convenience function that computes the sum of
   *  @a geometry.width for each glyph in the @a glyphs.
   *
   * @newin{1,14}
   *
   * @return The logical width of the glyph string.
   */
  auto get_width() const -> int;

  /** Computes the extents of the glyph string as drawn.
   * @param font A Pango::Font.
   * @return The extents of the glyph string as drawn.
   */
  auto get_ink_extents(const Glib::RefPtr<const Font>& font) const -> Rectangle;

  /** Computes the extents of a sub-portion of the glyph string as drawn.
   * @param start The start index.
   * @param end The end index.
   * @param font A Panog::Font
   * @return The extents of the sub-portion of the glyph string as drawn.
   */
  auto get_ink_extents(int start, int end, const Glib::RefPtr<const Font>& font) const -> Rectangle;

  /** Computes the logical extents of a sub-portion of the glyph string.
   * @param font A Pango::Font.
   * @return The logical extents of the glyph string.
   */
  auto get_logical_extents(const Glib::RefPtr<const Font>& font) const -> Rectangle;

  /** Computes the logical extents of a sub-portion of the glyph string.
   * @param start The start index.
   * @param end The end index.
   * @param font A Pango::Font.
   * @return The logical extents of the sub-portion of the glyph string.
   */
  auto get_logical_extents(int start, int end, const Glib::RefPtr<const Font>& font) const -> Rectangle;

  /** Determine the screen width corresponding to each character.
   * When multiple characters compose a single cluster, the width of the entire cluster
   * is divided equally among the characters.
   * @param text The text corresponding to the glyphs.
   * @param embedding_level The embedding level of the string.
   * @return An array of integers representing the resulting character widths.
   */
  auto get_logical_widths(const Glib::ustring& text, int embedding_level) const -> std::vector<int>;

  /** Converts from character position to x position.
   * (X position is measured from the left edge of the run). Character positions are computed by dividing up each cluster into equal portions.
   * @param text The text corresponding to the glyphs.
   * @param analysis The analysis information return from Pango::Context::itemize().
   * @param index The byte index within text.
   * @param trailing Whether we should compute the result for the beginning or end of the character.
   * @return The x position.
   */
  auto index_to_x(const Glib::ustring& text, const Analysis& analysis, int index, bool trailing) const -> int;

  /** Convert from x offset to character position.
   * Character positions are computed by dividing up each cluster into equal portions.
   * In scripts where positioning within a cluster is not allowed (such as Thai),
   * the returned value may not be a valid cursor position; the caller must combine the
   * result with the logical attributes for the text to compute the valid cursor position.
   * @param text The text corresponding to the glyphs.
   * @param analysis The analysis information return from Pango::Context::itemize().
   * @param x_pos The x offset (in thousands of a device unit).
   * @param index The location to store calculated byte index within.
   * @param trailing The location to store a boolean indicating whether the user clicked on the leading or trailing edge of the character.
   */
  void x_to_index(const Glib::ustring& text, const Analysis& analysis, int x_pos, int& index, bool& trailing) const;

  /** Gharacter positions are computed by dividing up each cluster into equal portions.
   * @return An array of Pango::GlyphInfo objects.
   */
  auto get_glyphs() const -> std::vector<GlyphInfo>;


};

} //namespace Pango


namespace Pango
{

/** @relates Pango::GlyphString
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(GlyphString& lhs, GlyphString& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Pango

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Pango::GlyphString
 */
PANGOMM_API
auto wrap(PangoGlyphString* object, bool take_copy = false) -> Pango::GlyphString;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::GlyphString> : public Glib::Value_Boxed<Pango::GlyphString>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_GLYPHSTRING_H */

