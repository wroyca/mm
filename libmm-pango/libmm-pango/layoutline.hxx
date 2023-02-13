
#ifndef _PANGOMM_LAYOUTLINE_H
#define _PANGOMM_LAYOUTLINE_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* layoutline.h
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

#include <libmm-glib/refptr.hxx>
#include <libmm-pango/rectangle.hxx>
#include <libmm-cairo/context.hxx>
#include <pango/pango.h>


namespace Pango
{

class PANGOMM_API Layout;

/** A Pango::LayoutLine represents one of the lines resulting from laying out a paragraph via Pango::Layout.
 * Pango::LayoutLine objects are obtained by calling Pango::Layout::get_line()
 * and are only valid until the text, attributes, or settings of the parent Pango::Layout are modified.
 * Routines for rendering Pango::Layout objects are provided in code specific to each rendering system.
 */
class PANGOMM_API LayoutLine final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = LayoutLine;
  using BaseObjectType = PangoLayoutLine;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoLayoutLine*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoLayoutLine*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoLayoutLine*;

  LayoutLine() = delete;

  // noncopyable
  LayoutLine(const LayoutLine&) = delete;
  auto operator=(const LayoutLine&) -> LayoutLine& = delete;

protected:
  // Do not derive this.  Pango::LayoutLine can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


  /** Converts from x offset to the byte index of the corresponding character
   * within the text of the layout.
   *
   * If @a x_pos is outside the line, @a index and @a trailing will point to the very
   * first or very last position in the line. This determination is based on the
   * resolved direction of the paragraph; for example, if the resolved direction
   * is right-to-left, then an X position to the right of the line (after it)
   * results in 0 being stored in @a index and @a trailing. An X position to the
   * left of the line results in @a index pointing to the (logical) last grapheme
   * in the line and @a trailing being set to the number of characters in that
   * grapheme. The reverse is true for a left-to-right line.
   *
   * @param x_pos The X offset (in Pango units) from the left edge of the line.
   * @param index Location to store calculated byte index for the grapheme
   * in which the user clicked.
   * @param trailing Location to store an integer indicating where in the
   * grapheme the user clicked. It will either be zero, or the number of
   * characters in the grapheme. 0 represents the leading edge of the grapheme.
   * @return <tt>false</tt> if @a x_pos was outside the line, <tt>true</tt> if inside.
   */
  auto x_to_index(int x_pos, int& index, int& trailing) const -> bool;

  /** Converts an index within a line to a @a x position.
   * @param index Byte offset of a grapheme within the layout.
   * @param trailing  A boolean indicating the edge of the grapheme to retrieve the position of. If <tt>false</tt>, the trailing edge of the grapheme, if <tt>true</tt> the leading of the grapheme.
   * @return The x offset (in thousands of a device unit).
   */
  auto index_to_x(int index, bool trailing) const -> int;


  /** Get a list of visual ranges corresponding to a given logical range.
   * This list is not necessarily minimal - there may be consecutive ranges which are adjacent.
   * The ranges will be sorted from left to right. The ranges are with respect to the
   * left edge of the entire layout, not with respect to the line.
   * @param start_index The start byte index of the logical range.
   * If the value of @a start_index is less than the start index for the line,
   * then the first range will extend all the way to the leading edge of the layout.
   * Otherwise it will start at the leading edge of the first character.
   * @param end_index The end byte index of the logical range.
   * If the value of @a end_index is greater than the end index for the line,
   * then the last range will extend all the way to the trailing edge of the layout.
   * Otherwise, it will end at the trailing edge of the last character.
   * @return An array of ranges represented by pairs of integers marking the start and end pixel coordinates of the ranges.
   */
  auto get_x_ranges(int start_index, int end_index) const -> std::vector<std::pair<int,int> >;


  /** Compute the logical and ink extents of a layout line. See the documentation
   * for Pango::Font::get_glyph_extents() for details about the interpretation
   * of the rectangles.
   *
   * @param ink_rect Rectangle used to store the extents of the glyph string as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph string.
   */
  void get_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Compute the ink extents of a layout line.
   * @return The extents of the layout line as drawn.
   */
  auto get_ink_extents() const -> Rectangle;

  /** Compute the logical extents of a layout line.
   * @return The logical extents of the layout line.
   */
  auto get_logical_extents() const -> Rectangle;


  /** Compute the logical and ink extents of a layout line. See the documentation
   * for Pango::Font::get_glyph_extents() for details about the interpretation
   * of the rectangles. The returned rectangles are in device units, as
   * opposed to get_extents(), which returns the extents in
   * units of device unit / PANGO_SCALE.
   *
   * @param ink_rect Rectangle used to store the extents of the glyph string as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph string.
   */
  void get_pixel_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Compute the ink extents of a layout line in device units.
   * @return The extents of the layout line as drawn.
   */
  auto get_pixel_ink_extents() const -> Rectangle;

  /** Compute the logical extents of a layout line in device units.
   * @return The logical extents of the layout line.
   */
  auto get_pixel_logical_extents() const -> Rectangle;

  /** Draws this LayoutLine in the specified Cairo context.
   * The origin of the glyphs (the left edge of the line) will
   * be drawn at the current point of the cairo context.
   *
   * @param context A Cairo context.
   */
  void show_in_cairo_context(const Cairo::RefPtr<Cairo::Context>& context);

  /** Adds the text in this LayoutLine to the current path in the
   * specified Cairo @a context. The origin of the glyphs (the left edge
   * of the line) will be at the current point of the cairo context.
   *
   * @param context A Cairo context.
   */
  void add_to_cairo_context(const Cairo::RefPtr<Cairo::Context>& context);

  auto get_layout() -> Glib::RefPtr<Pango::Layout>;
  auto get_layout() const -> Glib::RefPtr<const Pango::Layout>;
  //_MEMBER_SET_GOBJECT(layout, layout, Pango::Layout, PangoLayout*)
  auto get_length() const -> int;
  auto get_start_index() const -> int;


};

} // namespace Pango


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Pango::LayoutLine
 */
PANGOMM_API
auto wrap(PangoLayoutLine* object, bool take_copy = false) -> Glib::RefPtr<Pango::LayoutLine>;

} // namespace Glib


#endif /* _PANGOMM_LAYOUTLINE_H */

