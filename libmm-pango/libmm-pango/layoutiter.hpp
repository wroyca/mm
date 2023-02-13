
#ifndef _PANGOMM_LAYOUTITER_H
#define _PANGOMM_LAYOUTITER_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* layoutiter.h
 *
 * Copyright 2001-2002 The gtkmm Development Team
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

#include <libmm-pango/layoutline.hpp>
#include <libmm-pango/glyphitem.hpp>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoLayoutIter PangoLayoutIter; }
#endif

namespace Pango
{

/** A Pango::LayoutIter can be used to iterate over the visual extents of a Pango::Layout.
 */
class PANGOMM_API LayoutIter
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = LayoutIter;
  using BaseObjectType = PangoLayoutIter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  LayoutIter();

  explicit LayoutIter(PangoLayoutIter* gobject, bool make_a_copy = true);

  LayoutIter(const LayoutIter& other);
  auto operator=(const LayoutIter& other) -> LayoutIter&;

  LayoutIter(LayoutIter&& other) noexcept;
  auto operator=(LayoutIter&& other) noexcept -> LayoutIter&;

  ~LayoutIter() noexcept;

  void swap(LayoutIter& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoLayoutIter*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoLayoutIter* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoLayoutIter*;

protected:
  PangoLayoutIter* gobject_;

private:


public:


  /** Gets the current byte index.
   *
   * Note that iterating forward by char moves in visual order,
   * not logical order, so indexes may not be sequential. Also,
   * the index may be equal to the length of the text in the
   * layout, if on the <tt>nullptr</tt> run (see get_run()).
   *
   * @return Current byte index.
   */
  auto get_index() const -> int;


  /** Gets the current run.
   *
   * When iterating by run, at the end of each line, there's a position with
   * a <tt>nullptr</tt> run, so this function can return an invalid GlyphItem.
   * The <tt>nullptr</tt> run at the end of each line ensures that all lines have
   * at least one run, even lines consisting of only a newline.
   *
   * @return The current run.
   */
  auto get_run() const -> GlyphItem;


  /** Gets the current line.
   *
   * Use the faster get_const_line() if you do not plan
   * to modify the contents of the line (glyphs, glyph widths, etc.).
   *
   * @return The current line.
   */
  auto get_line() -> Glib::RefPtr<LayoutLine>;


  /** Gets the current line for read-only access.
   *
   * @return The current line, that should not be modified.
   */
  auto get_line() const -> Glib::RefPtr<const LayoutLine>;


  /** Gets the current line for read-only access.
   *
   * This is a faster alternative to get_line(), but the user is not expected
   * to modify the contents of the line (glyphs, glyph widths, etc.).
   *
   * @newin{2,50}
   *
   * @return The current line, that should not be modified.
   */
  auto get_const_line() const -> Glib::RefPtr<const LayoutLine>;


  /** Determines whether @a iter is on the last line of the layout.
   *
   * @return <tt>true</tt> if @a iter is on the last line.
   */
  auto at_last_line() const -> bool;


  /** Gets the layout associated with a `Pango::LayoutIter`.
   *
   * @newin{1,20}
   *
   * @return The layout associated with @a iter.
   */
  auto get_layout() -> Glib::RefPtr<Layout>;

  /** Gets the layout associated with a `Pango::LayoutIter`.
   *
   * @newin{1,20}
   *
   * @return The layout associated with @a iter.
   */
  auto get_layout() const -> Glib::RefPtr<const Layout>;


  /** Moves @a iter forward to the next character in visual order.
   *
   * If @a iter was already at the end of the layout, returns <tt>false</tt>.
   *
   * @return Whether motion was possible.
   */
  auto next_char() -> bool;

  /** Moves @a iter forward to the next cluster in visual order.
   *
   * If @a iter was already at the end of the layout, returns <tt>false</tt>.
   *
   * @return Whether motion was possible.
   */
  auto next_cluster() -> bool;

  /** Moves @a iter forward to the next run in visual order.
   *
   * If @a iter was already at the end of the layout, returns <tt>false</tt>.
   *
   * @return Whether motion was possible.
   */
  auto next_run() -> bool;

  /** Moves @a iter forward to the start of the next line.
   *
   * If @a iter is already on the last line, returns <tt>false</tt>.
   *
   * @return Whether motion was possible.
   */
  auto next_line() -> bool;

  /** Gets the extents of the current character, in layout coordinates (origin is the top left of the entire layout).
   * Only logical extents can sensibly be obtained for characters; ink extents make sense only down to the level of clusters.
   * @return The logical extents of the current character.
   */
  auto get_char_extents() const -> Rectangle;


  /** Gets the extents of the current cluster, in layout coordinates.
   *
   * Layout coordinates have the origin at the top left of the entire layout.
   *
   * @param ink_rect Rectangle to fill with ink extents.
   * @param logical_rect Rectangle to fill with logical extents.
   */
  void get_cluster_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Gets the ink extents of the current cluster, in layout coordinates (origin is the top left of the entire layout).
   * @return The extents of the current cluster as drawn.
   */
  auto get_cluster_ink_extents() const -> Rectangle;

  /** Gets the logical extents of the current cluster, in layout coordinates (origin is the top left of the entire layout).
   * @return The logical extents of the current cluster.
   */
  auto get_cluster_logical_extents() const -> Rectangle;


  /** Gets the extents of the current run in layout coordinates.
   *
   * Layout coordinates have the origin at the top left of the entire layout.
   *
   * @param ink_rect Rectangle to fill with ink extents.
   * @param logical_rect Rectangle to fill with logical extents.
   */
  void get_run_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Gets the ink extents of the current run in layout coordinates (origin is the top left of the entire layout).
   * @return The extents of the current run as drawn.
   */
  auto get_run_ink_extents() const -> Rectangle;

  /** Gets the logical extents of the current run in layout coordinates (origin is the top left of the entire layout).
   * @return The logical extents of the current run.
   */
  auto get_run_logical_extents() const -> Rectangle;


  /** Obtains the extents of the current line.
   *
   * Extents are in layout coordinates (origin is the top-left corner
   * of the entire `Pango::Layout`). Thus the extents returned by this
   * function will be the same width/height but not at the same x/y
   * as the extents returned from Pango::LayoutLine::get_extents().
   *
   * @param ink_rect Rectangle to fill with ink extents.
   * @param logical_rect Rectangle to fill with logical extents.
   */
  void get_line_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Obtains the ink extents of the current line.
   * @return The extents of the current line as drawn.
   */
  auto get_line_ink_extents() const -> Rectangle;

  /** Obtains the logical extents of the current line.
   * @return The logical extents of the current line.
   */
  auto get_line_logical_extents() const -> Rectangle;


  /** Divides the vertical space in the `Pango::Layout` being iterated over
   * between the lines in the layout, and returns the space belonging to
   * the current line.
   *
   * A line's range includes the line's logical extents. plus half of the
   * spacing above and below the line, if set_spacing()
   * has been called to set layout spacing. The Y positions are in layout
   * coordinates (origin at top left of the entire layout).
   *
   * @note Since 1.44, Pango uses line heights for placing lines, and there
   * may be gaps between the ranges returned by this function.
   *
   * @param y0 Start of line.
   * @param y1 End of line.
   */
  void get_line_yrange(int& y0, int& y1) const;


  /** Obtains the extents of the `Pango::Layout` being iterated over.
   *
   * @param ink_rect Rectangle to fill with ink extents.
   * @param logical_rect Rectangle to fill with logical extents.
   */
  void get_layout_extents(Rectangle& ink_rect, Rectangle& logical_rect) const;

  /** Obtains the ink extents of the Pango::Layout being iterated over.
   * @return The extents of the layout as drawn.
   */
  auto get_layout_ink_extents() const -> Rectangle;

  /** Obtains the logical extents of the Pango::Layout being iterated over.
   * @return The logical extents of the layout.
   */
  auto get_layout_logical_extents() const -> Rectangle;


  /** Gets the Y position of the current line's baseline, in layout
   * coordinates.
   *
   * Layout coordinates have the origin at the top left of the entire layout.
   *
   * @return Baseline of current line.
   */
  auto get_baseline() const -> int;


};

} //namespace Pango


namespace Pango
{

/** @relates Pango::LayoutIter
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(LayoutIter& lhs, LayoutIter& rhs) noexcept
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
 * @relates Pango::LayoutIter
 */
PANGOMM_API
auto wrap(PangoLayoutIter* object, bool take_copy = false) -> Pango::LayoutIter;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::LayoutIter> : public Glib::Value_Boxed<Pango::LayoutIter>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_LAYOUTITER_H */

