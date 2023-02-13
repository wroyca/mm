
#ifndef _PANGOMM_GLYPHITEM_H
#define _PANGOMM_GLYPHITEM_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* glyphitem.h
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

#include <libmm-pango/attributes.hxx> //For LogAttr.
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoGlyphItem PangoGlyphItem; }
#endif

namespace Pango
{

class PANGOMM_API Item;
class PANGOMM_API GlyphString;

/** A %Pango::GlyphItem is a pair of a Pango::Item and the glyphs
 * resulting from shaping the text corresponding to an item.
 *
 * As an example of the usage of %Pango::GlyphItem, the results
 * of shaping text with Pango::Layout is a list of Pango::LayoutLine,
 * each of which contains a list of Pango::GlyphItem.
 *
 * For backward compatibility PangoLayoutRun is an alias for PangoGlyphItem
 * in pango's C code. There is no Pango::LayoutRun in this version of pangomm.
 *
 * @newin{2,48}
 */
class PANGOMM_API GlyphItem
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = GlyphItem;
  using BaseObjectType = PangoGlyphItem;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  GlyphItem();

  explicit GlyphItem(PangoGlyphItem* gobject, bool make_a_copy = true);

  GlyphItem(const GlyphItem& other);
  auto operator=(const GlyphItem& other) -> GlyphItem&;

  GlyphItem(GlyphItem&& other) noexcept;
  auto operator=(GlyphItem&& other) noexcept -> GlyphItem&;

  ~GlyphItem() noexcept;

  void swap(GlyphItem& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoGlyphItem*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoGlyphItem* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoGlyphItem*;

protected:
  PangoGlyphItem* gobject_;

private:


public:
  // pango_glyph_item_split() returns a newly created PangoGlyphItem. Don't take a copy.


  /** Modifies @a orig to cover only the text after @a split_index, and
   * returns a new item that covers the text before @a split_index that
   * used to be in @a orig.
   *
   * You can think of @a split_index as the length of the returned item.
   *  @a split_index may not be 0, and it may not be greater than or equal
   * to the length of @a orig (that is, there must be at least one byte
   * assigned to each item, you can't create a zero-length item).
   *
   * This function is similar in function to Pango::Item::split() (and uses
   * it internally.)
   *
   * @newin{1,2}
   *
   * @param text Text to which positions in @a orig apply.
   * @param split_index Byte index of position to split item, relative to the
   * start of the item.
   * @return The newly allocated item representing text before
   *  @a split_index, which should be freed
   * with free().
   */
  auto split(const Glib::ustring& text, int split_index) -> GlyphItem;

  //This takes ownership of the GlyphItem, which is strange:
  // _WRAP_METHOD(GSList* apply_attrs(const Glib::ustring& text, const AttrList& list), pango_glyph_item_apply_attrs)

  /** Adds spacing between the graphemes of @a glyph_item to
   * give the effect of typographic letter spacing.
   *
   * @newin{1,6}
   *
   * @param text Text that @a glyph_item corresponds to
   * (glyph_item->item->offset is an offset from the
   * start of @a text).
   * @param log_attrs Logical attributes for the item
   * (the first logical attribute refers to the position
   * before the first character in the item).
   * @param letter_spacing Amount of letter spacing to add
   * in Pango units. May be negative, though too large
   * negative values will give ugly results.
   */
  void letter_space(const Glib::ustring& text, const LogAttr& log_attrs, int letter_spacing =  0);

  /** Gets the Pango::Item object that provides information about the segment of text in this run.
   * @return A Pango::Item object.
   */
  auto get_item() const -> Item;

  /** Gets the string of glyphs obtained by shaping the text for this item.
   * @return A Pango::GlyphString object.
   */
  auto get_glyphs() const -> GlyphString;


};

} /* namespace Pango */


namespace Pango
{

/** @relates Pango::GlyphItem
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(GlyphItem& lhs, GlyphItem& rhs) noexcept
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
 * @relates Pango::GlyphItem
 */
PANGOMM_API
auto wrap(PangoGlyphItem* object, bool take_copy = false) -> Pango::GlyphItem;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::GlyphItem> : public Glib::Value_Boxed<Pango::GlyphItem>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_GLYPHITEM_H */

