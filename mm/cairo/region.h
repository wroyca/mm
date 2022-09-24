/* Copyright (C) 2010 The cairomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __CAIROMM_REGION_H
#define __CAIROMM_REGION_H

#include <mm/cairo/types.h>
#include <mm/cairo/enums.h>
#include <mm/cairo/refptr.h>
#include <cairo.h>
#include <vector>

namespace Cairo
{

/**
 * A simple graphical data type representing an area of integer-aligned
 * rectangles. They are often used on raster surfaces to track areas of
 * interest, such as change or clip areas
 *
 * It allows set-theoretical operations like union and intersect to be performed
 * on them.
 *
 * @since: 1.10
 **/
class CAIROMM_API Region
{
private:

  Region();

  explicit Region(const RectangleInt& rectangle);

  explicit Region(const std::vector<RectangleInt>& rects);
  Region(const RectangleInt *rects, int count);

public:
  //TODO: Documentation
  enum class Overlap
  {
      /**
       * Completely inside region
       */
      IN = CAIRO_REGION_OVERLAP_IN,

      /**
       * Completely outside region
       */
      OUT = CAIRO_REGION_OVERLAP_OUT,

      /**
       * Partly inside region
       */
      REGION_OVERLAP_PART = CAIRO_REGION_OVERLAP_PART
  };

  /** Create a C++ wrapper for the C instance. This C++ instance should then be given to a RefPtr.
   * @param cobject The C instance.
   * @param has_reference Whether we already have a reference. Otherwise, the constructor will take an extra reference.
   */
  explicit Region(cairo_region_t* cobject, bool has_reference = false);

  /** Creates an empty Region object */
  static auto create() -> RefPtr<Region>;
  /** Creates a Region object containing @a rectangle */
  static auto create(const RectangleInt& rectangle) -> RefPtr<Region>;
  /** Creates a Region object containing the union of all given @a rects */
  static auto create(const std::vector<RectangleInt>& rects) -> RefPtr<Region>;
  /** Creates a Region object containing the union of all given @a rects */
  static auto create(const RectangleInt *rects, int count) -> RefPtr<Region>;

  /** allocates a new region object copied from the original */
  auto copy() const -> RefPtr<Region>;

  virtual ~Region();

  /** Gets the bounding rectangle of the region */
  auto get_extents() const -> RectangleInt;

  /** Gets the number of rectangles contained in the region */
  auto get_num_rectangles() const -> int;

  /** Gets the nth rectangle from the region */
  auto get_rectangle(int nth_rectangle) const -> RectangleInt;

  /** Checks whether the region is empty */
  auto empty() const -> bool;

  /** Checks whether @a rectangle is inside, outside, or partially contained in
   * the region
   */
  auto contains_rectangle(const RectangleInt& rectangle) const -> Overlap;

  /** Checks whether (x,y) is contained in the region */
  auto contains_point(int x, int y) const -> bool;

  /** Translates the region by (dx,dy) */
  void translate(int dx, int dy);

  /** Subtracts @a other from this region */
  void subtract(const RefPtr<Region>& other);

  /** Subtracts @a rectangle from this region */
  void subtract(const RectangleInt& rectangle);

  /** Sets the region to the intersection of this region with @a other */
  void intersect(const RefPtr<Region>& other);

  /** Sets the region to the intersection of this region with @a rectangle */
  void intersect(const RectangleInt& rectangle);

  //We don't call this method union() because that is a C++ keyword.

  /** Sets this region to the union of the region with @a other */
  void do_union(const RefPtr<Region>& other);

  /** Sets this region to the union of the region with @a rectangle */
  void do_union(const RectangleInt& rectangle);

  /** Sets this region to the exclusive difference of the region with @a other.
   * That is, the region will contain all areas that are in the original region
   * or in @a other, but not in both */
  void do_xor(const RefPtr<Region>& other);

  /** Sets this region to the exclusive difference of the region with @a
   * rectangle.  That is, the region will contain all areas that are in the
   * original region or in @a rectangle, but not in both */
  void do_xor(const RectangleInt& rectangle);



  typedef cairo_region_t cobject;

  inline auto cobj() -> cobject* { return m_cobject; }
  inline auto cobj() const -> const cobject* { return m_cobject; }

  #ifndef DOXYGEN_IGNORE_THIS
  ///For use only by the cairomm implementation.
  inline auto get_status() const -> ErrorStatus
  { return cairo_region_status(const_cast<cairo_region_t*>(cobj())); }
  #endif //DOXYGEN_IGNORE_THIS

  void reference() const;
  void unreference() const;

protected:

  cobject* m_cobject;
};

} // namespace Cairo

#endif //__CAIROMM_REGION_H

// vim: ts=2 sw=2 et
