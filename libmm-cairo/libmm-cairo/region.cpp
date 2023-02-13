/* Copyright (C) 2005 The cairomm Development Team
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

#include <mm/cairo/region.hpp>
#include <mm/cairo/private.hpp>
#include <algorithm>

namespace Cairo
{

Region::Region()
: m_cobject(cairo_region_create())
{
  check_object_status_and_throw_exception (*this);
}

Region::Region(const RectangleInt& rectangle)
: m_cobject(cairo_region_create_rectangle(&rectangle))
{
  check_object_status_and_throw_exception (*this);
}

// less efficient but convenient
Region::Region(const std::vector<RectangleInt>& rects) :
  m_cobject(nullptr)
{
  auto *carray = new RectangleInt[rects.size()];
  std::copy(rects.begin(), rects.end(), carray);
  m_cobject = cairo_region_create_rectangles (carray, rects.size());

  delete[] carray;

  check_object_status_and_throw_exception (*this);
}

// less convenient but more efficient
Region::Region(const RectangleInt *rects, const int count) :
  m_cobject(cairo_region_create_rectangles (rects, count))
{
  check_object_status_and_throw_exception (*this);
}

Region::Region(cairo_region_t* cobject, const bool has_reference)
: m_cobject(nullptr)
{
  if(has_reference)
    m_cobject = cobject;
  else
    m_cobject = cairo_region_reference(cobject);

  check_object_status_and_throw_exception (*this);
}

auto Region::create() -> RefPtr<Region>
{
  return make_refptr_for_instance<Region>(new Region());
}

auto Region::create(const RectangleInt& rectangle) -> RefPtr<Region>
{
  return make_refptr_for_instance<Region>(new Region(rectangle));
}

auto Region::create(const std::vector<RectangleInt>& rects) -> RefPtr<Region>
{
  return make_refptr_for_instance<Region>(new Region(rects));
}

auto Region::create(const RectangleInt *rects, const int count) -> RefPtr<Region>
{
  return make_refptr_for_instance<Region>(new Region(rects, count));
}

auto Region::copy() const -> RefPtr<Region>
{
  return make_refptr_for_instance<Region>(new Region (cairo_region_copy (m_cobject), true));
}

Region::~Region()
{
  if(m_cobject)
    cairo_region_destroy(m_cobject);
}

auto Region::reference () const -> void
{
 cairo_region_reference(m_cobject);
}

auto Region::unreference () const -> void
{
  cairo_region_destroy(m_cobject);
}

auto Region::get_extents() const -> RectangleInt
{
  RectangleInt result;
  cairo_region_get_extents(m_cobject, &result);
  return result;
}

auto Region::get_num_rectangles() const -> int
{
  return cairo_region_num_rectangles(m_cobject);
}

auto Region::get_rectangle(
  const int nth_rectangle) const -> RectangleInt
{
  RectangleInt result;
  cairo_region_get_rectangle(m_cobject, nth_rectangle, &result);
  return result;
}

auto Region::empty() const -> bool
{
  return cairo_region_is_empty(m_cobject);
}

auto Region::contains_rectangle(const RectangleInt& rectangle) const -> Overlap
{
  return (Overlap)cairo_region_contains_rectangle(m_cobject, &rectangle);
}

auto Region::contains_point(
  const int x, const int y) const -> bool
{
  return cairo_region_contains_point(m_cobject, x, y);
}

auto Region::translate (
  const int dx, const int dy) -> void
{
  cairo_region_translate(m_cobject, dx, dy);
}

auto Region::subtract (const RefPtr <Region> &other) -> void
{
  const auto status = cairo_region_subtract(m_cobject, other ? other->cobj() : nullptr);
  check_status_and_throw_exception (status);
}

auto Region::subtract (const RectangleInt &rectangle) -> void
{
  const auto status = cairo_region_subtract_rectangle(m_cobject, &rectangle);
  check_status_and_throw_exception (status);
}

auto Region::intersect (const RefPtr <Region> &other) -> void
{
  const auto status = cairo_region_intersect(m_cobject, other ? other->cobj() : nullptr);
  check_status_and_throw_exception (status);
}

auto Region::intersect (const RectangleInt &rectangle) -> void
{
  const auto status = cairo_region_intersect_rectangle(m_cobject, &rectangle);
  check_status_and_throw_exception (status);
}

auto Region::do_union (const RefPtr <Region> &other) -> void
{
  const auto status = cairo_region_union(m_cobject, other ? other->cobj() : nullptr);
  check_status_and_throw_exception (status);
}

auto Region::do_union (const RectangleInt &rectangle) -> void
{
  const auto status = cairo_region_union_rectangle(m_cobject, &rectangle);
  check_status_and_throw_exception (status);
}

auto Region::do_xor (const RefPtr <Region> &other) -> void
{
  const auto status = cairo_region_xor(m_cobject, other ? other->cobj() : nullptr);
  check_status_and_throw_exception (status);
}

auto Region::do_xor (const RectangleInt &rectangle) -> void
{
  const auto status = cairo_region_xor_rectangle(m_cobject, &rectangle);
  check_status_and_throw_exception (status);
}


} //namespace Cairo

// vim: ts=2 sw=2 et
