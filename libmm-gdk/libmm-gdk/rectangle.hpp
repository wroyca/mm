
#ifndef _GDKMM_RECTANGLE_H
#define _GDKMM_RECTANGLE_H

#include <mm/gdk/mm-gdkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <mm/glib/value.hpp>
#include <gdk/gdk.h>


namespace Gdk
{

/** Gdk::Rectangle is a structure holding the position and size of a rectangle.
 * The intersection of two rectangles can be computed with intersect().
 * To find the union of two rectangles use join().
 */
class GDKMM_API Rectangle
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Rectangle;
  using BaseObjectType = GdkRectangle;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Rectangle(const Rectangle& other) noexcept;
  auto operator=(const Rectangle& other) noexcept -> Rectangle&;

  Rectangle(Rectangle&& other) noexcept;
  auto operator=(Rectangle&& other) noexcept -> Rectangle&;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  Rectangle();

  explicit Rectangle(const GdkRectangle* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkRectangle*       { return &gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkRectangle* { return &gobject_; }

protected:
  GdkRectangle gobject_;

private:

public:

  /** Creates a new rectangle instance with these dimensions.
   */
  Rectangle(int x, int y, int width, int height);

  /**
   * @newin{3,20}
   */
  auto operator==(const Rectangle& src) const -> bool;


  // 'union' is a C and C++ keyword. Can't be a method name.
  /** Calculates the union of two rectangles, changing this rectangle.
   * The union of this rectangle and @a src2 is the smallest rectangle which
   * includes both this rectangle and @a src2 within it.
   *
   * This method returns a reference to this instance, allowing you to then call another method easily.
   * For instance: rect.join(src2).intersect(src3);
   *
   * @param src2 The rectangle with which to calculate the union with this rectangle.
   * @returns A reference to this rectangle.
   */
  auto join(const Rectangle& src2) -> Rectangle&;


  /** Calculates the intersection of two rectangles, changing this rectangle.
   * If the rectangles do not intersect, this rectangle's width and height are
   * set to 0 and its x and y values are undefined.
   *
   * This method returns a reference to this instance, allowing you to then call another method easily.
   * For instance: rect.intersect(src2).join(src3);
   *
   * @param src2 The rectangle with which to calculate the intersection with this rectangle.
   * @returns A reference to this rectangle.
   */
  auto intersect(const Rectangle& src2) -> Rectangle&;


  /** Calculates the intersection of two rectangles, changing this rectangle.
   * If the rectangles do not intersect, this rectangle's width and height are
   * set to 0 and its x and y values are undefined.
   *
   * This method returns a reference to this instance, allowing you to then call another method easily.
   * For instance: rect.intersect(src2, rectangles_intersect).join(src3);
   *
   * @param src2 The rectangle with which to calculate the intersection with this rectangle.
   * @param[out] rectangles_intersect This will be set to <tt>true</tt>
   *             if the rectangles intersect, else <tt>false</tt>.
   * @returns A reference to this rectangle.
   */
  auto intersect(const Rectangle& src2, bool& rectangles_intersect) -> Rectangle&;

  /** Checks whether two rectangles intersect.
   *
   * @newin{3,8}
   *
   * @param src2 The rectangle with which to check intersection with this rectangle.
   * @result Whether this rectangle intersects @a src2.
   */
  auto intersects(const Rectangle& src2) const -> bool;

  /** Checks whether either the width or height is 0.
   * @result Whether this rectangle has 0 area.
   */
  auto has_zero_area() const -> bool;


  /** Returns <tt>true</tt> if @a rect contains the point described by @a x and @a y.
   *
   * @param x X coordinate.
   * @param y Y coordinate.
   * @return <tt>true</tt> if @a rect contains the point.
   */
  auto contains_point(int x, int y) const -> bool;

  auto get_x() const -> int;
  void set_x(const int& value);
  auto get_y() const -> int;
  void set_y(const int& value);
  auto get_width() const -> int;
  void set_width(const int& value);
  auto get_height() const -> int;
  void set_height(const int& value);


};

/** Calculates the union of two rectangles.
 * The union of @a src1 and @a src2 is the smallest rectangle which
 * includes both @a src1 and @a src2 within it.
 *
 * @newin{3,8}
 *
 * @param src1 One of the rectangles.
 * @param src2 The other rectangle.
 * @returns The union of @a src1 and @a src2.
 *
 * @relates Gdk::Rectangle
 */
GDKMM_API
auto join(const Rectangle& src1, const Rectangle& src2) -> Rectangle;

/** Calculates the intersection of two rectangles.
 * If the rectangles do not intersect, the returned rectangle's width and height
 * are set to 0 and its x and y values are undefined.
 *
 * @newin{3,8}
 *
 * @param src1 One of the rectangles.
 * @param src2 The other rectangle.
 * @returns The intersection of @a src1 and @a src2.
 *
 * @relates Gdk::Rectangle
 */
GDKMM_API
auto intersect(const Rectangle& src1, const Rectangle& src2) -> Rectangle;

/** Calculates the intersection of two rectangles.
 * If the rectangles do not intersect, the returned rectangle's width and height
 * are set to 0 and its x and y values are undefined.
 *
 * @newin{3,8}
 *
 * @param src1 One of the rectangles.
 * @param src2 The other rectangle.
 * @param[out] rectangles_intersect This will be set to <tt>true</tt>
 *             if the rectangles intersect, else <tt>false</tt>.
 * @returns The intersection of @a src1 and @a src2.
 *
 * @relates Gdk::Rectangle
 */
GDKMM_API
auto intersect(const Rectangle& src1, const Rectangle& src2, bool& rectangles_intersect) -> Rectangle;

} // namespace Gdk


namespace Glib
{

/** @relates Gdk::Rectangle
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GDKMM_API
auto wrap(GdkRectangle* object) -> Gdk::Rectangle&;

/** @relates Gdk::Rectangle
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
GDKMM_API
auto wrap(const GdkRectangle* object) -> const Gdk::Rectangle&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GDKMM_API Value<Gdk::Rectangle> : public Glib::Value_Boxed<Gdk::Rectangle>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GDKMM_RECTANGLE_H */

