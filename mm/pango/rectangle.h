// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _PANGOMM_RECTANGLE_H
#define _PANGOMM_RECTANGLE_H

#include <mm/pango/mm-pangoconfig.h>


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
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


#include <pango/pango.h>


namespace Pango
{

/** A Pango::Rectangle represents a rectangle.
 * It is frequently used to represent the logical or ink extents of a single glyph or section of text.
 * The coordinate system for each rectangle has its origin at the base line and the horizontal
 * origin of the character with increasing coordinates extending to the right and down.
 * get_ascent(), get_descent(), get_lbearing(), and get_rbearing() can be used to convert
 * from the extents rectangle to more traditional font metrics.
 * The units of rectangles usually are in 1/Pango::SCALE of a device unit.
 */
class PANGOMM_API Rectangle
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Rectangle;
  using BaseObjectType = PangoRectangle;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  Rectangle();
  Rectangle(int x, int y, int width, int height);
  explicit Rectangle(const PangoRectangle* src);

  /** Sets the X coordinate of the left side of the rectangle.
   * @param x The new X coordinate.
   */
  void set_x(int x)        { gobject_.x = x; }

  /** Sets the Y coordinate of the top side of the rectangle.
   * @param y The new Y coordinate.
   */
  void set_y(int y)        { gobject_.y = y; }

  /** Sets the width of the rectangle.
   * @param w The new width.
   */
  void set_width(int w)    { gobject_.width = w; }

  /** Sets the height of the rectangle.
   * @param h The new height.
   */
  void set_height(int h)   { gobject_.height = h; }

  /** Gets the X coordinate of the left side of the rectangle.
   * @return The X coordinate.
   */
  auto get_x() const -> int        { return gobject_.x; }

  /** Gets the Y coordinate of the top side of the rectangle.
   * @return The Y coordinate.
   */
  auto get_y() const -> int        { return gobject_.y; }

  /** Gets the width of the rectangle.
   * @return The width.
   */
  auto get_width() const -> int    { return gobject_.width; }

  /** Gets the height of the rectangle.
   * @return The height.
   */
  auto get_height() const -> int   { return gobject_.height; }

  /** Extracts the ascent from a Pango::Rectangle representing glyph extents.
   * The ascent is the distance from the baseline to the highest point of the character.
   * This is positive if the glyph ascends above the baseline.
   * @return The ascent of the character.
   */
  auto get_ascent() const -> int   { return PANGO_ASCENT(*gobj()); }

  /** Extracts the descent from a Pango::Rectangle representing glyph extents.
   * The descent is the distance from the baseline to the lowest point of the character.
   * This is positive if the glyph descends below the baseline.
   * @return The descent of the character.
   */
  auto get_descent() const -> int  { return PANGO_DESCENT(*gobj()); }

  /** Extracts the left bearing from a Pango::Rectangle representing glyph extents.
   * The left bearing is the distance from the horizontal origin to the farthest left point of the character.
   * This is positive for characters drawn completely to the right of the glyph origin.
   * @return The left bearing of the character.
   */
  auto get_lbearing() const -> int { return PANGO_LBEARING(*gobj()); }

  /** Extracts the right bearing from a Pango::Rectangle representing glyph extents.
   * The right bearing is the distance from the horizontal origin to the farthest right point of the character.
   * This is positive except for characters drawn completely to the left of the horizontal origin.
   * @return The right bearing of the character.
   */
  auto get_rbearing() const -> int { return PANGO_RBEARING(*gobj()); }

  /** Checks for equality of two Pango::Rectangles.
   * @param rhs The Pango::Rectangle to compare with.
   * @return true if @a rhs is equal with the rectangle.
   */
  auto equal(const Rectangle& rhs) const -> bool;

  /// Provides access to the underlying C GObject.
  auto       gobj() -> PangoRectangle*       { return &gobject_; }
  /// Provides access to the underlying C GObject.
  auto gobj() const -> const PangoRectangle* { return &gobject_; }

protected:
  PangoRectangle gobject_;


};

/** @relates Pango::Rectangle */
inline auto operator==(const Rectangle& lhs, const Rectangle& rhs) -> bool
  { return lhs.equal(rhs); }

/** @relates Pango::Rectangle */
inline auto operator!=(const Rectangle& lhs, const Rectangle& rhs) -> bool
  { return !lhs.equal(rhs); }

} /* namespace Pango */


namespace Glib
{

/** @relates Pango::Rectangle */
PANGOMM_API
auto wrap(PangoRectangle* object) -> Pango::Rectangle&;

/** @relates Pango::Rectangle */
PANGOMM_API
auto wrap(const PangoRectangle* object) -> const Pango::Rectangle&;

} /* namespace Glib */


#endif /* _PANGOMM_RECTANGLE_H */
