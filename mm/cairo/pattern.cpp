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

#include <mm/cairo/pattern.hpp>
#include <mm/cairo/private.hpp>
#include <mm/cairo/matrix.hpp>

namespace Cairo
{

Pattern::Pattern()
: m_cobject(nullptr)
{
}

Pattern::Pattern(cairo_pattern_t* cobject, bool has_reference)
: m_cobject(nullptr)
{
  if(has_reference)
    m_cobject = cobject;
  else
    m_cobject = cairo_pattern_reference(cobject);
}

Pattern::~Pattern()
{
  if(m_cobject)
    cairo_pattern_destroy(m_cobject);
}

auto Pattern::reference () const -> void
{
 cairo_pattern_reference(m_cobject);
}

auto Pattern::unreference () const -> void
{
  cairo_pattern_destroy(m_cobject);
}

auto Pattern::set_matrix (const Matrix &matrix) -> void
{
  cairo_pattern_set_matrix(m_cobject, (cairo_matrix_t*)&matrix);
  check_object_status_and_throw_exception(*this);
}

auto Pattern::get_matrix (Matrix &matrix) const -> void
{
  cairo_pattern_get_matrix(m_cobject, (cairo_matrix_t*)&matrix);
  check_object_status_and_throw_exception(*this);
}

auto Pattern::get_matrix() const -> Matrix
{
  Cairo::Matrix m;
  cairo_pattern_get_matrix(m_cobject, (cairo_matrix_t*)&m);
  check_object_status_and_throw_exception(*this);
  return m;
}

auto Pattern::get_type() const -> Pattern::Type
{
  auto pattern_type = cairo_pattern_get_type(m_cobject);
  check_object_status_and_throw_exception(*this);
  return static_cast<Type>(pattern_type);
}

auto Pattern::set_extend (Extend extend) -> void
{
  cairo_pattern_set_extend(m_cobject, (cairo_extend_t)extend);
  check_object_status_and_throw_exception(*this);
}

auto Pattern::get_extend() const -> Pattern::Extend
{
  const auto result = static_cast<Extend>(cairo_pattern_get_extend(m_cobject));
  check_object_status_and_throw_exception(*this);
  return result;
}

SolidPattern::SolidPattern(cairo_pattern_t* cobject, bool has_reference)
: Pattern(cobject, has_reference)
{
}
auto SolidPattern::get_rgba (
  double &red, double &green,
  double &blue, double &alpha) const -> void
{
  // ignore the return value since we know that this is a solid color pattern
  cairo_pattern_get_rgba(m_cobject, &red, &green, &blue, &alpha);
  check_object_status_and_throw_exception(*this);
}

SolidPattern::~SolidPattern()
{
}

auto SolidPattern::create_rgb(double red, double green, double blue) -> RefPtr<SolidPattern>
{
  auto cobject = cairo_pattern_create_rgb(red, green, blue);
  check_status_and_throw_exception(cairo_pattern_status(cobject));
  return make_refptr_for_instance<SolidPattern>(new SolidPattern(cobject, true /* has reference */));
}

auto SolidPattern::create_rgba(double red, double green, double blue, double alpha) -> RefPtr<SolidPattern>
{
  cairo_pattern_t* cobject  = cairo_pattern_create_rgba(red, green, blue, alpha);
  check_status_and_throw_exception(cairo_pattern_status(cobject));
  return make_refptr_for_instance<SolidPattern>(new SolidPattern(cobject, true /* has reference */));
}


SurfacePattern::SurfacePattern(const RefPtr<Surface>& surface)
{
  m_cobject = cairo_pattern_create_for_surface(surface->cobj());
  check_object_status_and_throw_exception(*this);
}

auto
SurfacePattern::get_surface() -> RefPtr<Surface>
{
  cairo_surface_t* surface = nullptr;
  // we can ignore the return value since we know this is a surface pattern
  cairo_pattern_get_surface(const_cast<cairo_pattern_t*>(m_cobject), &surface);
  check_object_status_and_throw_exception(*this);
  return make_refptr_for_instance<Surface>(new Surface(surface, false /* does not have reference */));
}

auto
SurfacePattern::get_surface() const -> RefPtr<const Surface>
{
  return const_cast<SurfacePattern*>(this)->get_surface();
}

auto SurfacePattern::create(const RefPtr<Surface>& surface) -> RefPtr<SurfacePattern>
{
  return make_refptr_for_instance<SurfacePattern>(new SurfacePattern(surface));
}

SurfacePattern::SurfacePattern(cairo_pattern_t* cobject, bool has_reference)
: Pattern(cobject, has_reference)
{
}

SurfacePattern::~SurfacePattern()
{
}

auto SurfacePattern::set_filter (Filter filter) -> void
{
  cairo_pattern_set_filter(m_cobject, (cairo_filter_t)filter);
  check_object_status_and_throw_exception(*this);
}

auto SurfacePattern::get_filter() const -> SurfacePattern::Filter
{
  auto result = static_cast<Filter>(cairo_pattern_get_filter(m_cobject));
  check_object_status_and_throw_exception(*this);
  return result;
}



Gradient::Gradient()
{
}

Gradient::Gradient(cairo_pattern_t* cobject, bool has_reference)
: Pattern(cobject, has_reference)
{
}

Gradient::~Gradient()
{
}

auto Gradient::add_color_stop_rgb (double offset, double red, double green, double blue) -> void
{
  cairo_pattern_add_color_stop_rgb(m_cobject, offset, red, green, blue);
  check_object_status_and_throw_exception(*this);
}

auto Gradient::add_color_stop_rgba (
  double offset, double red, double green, double blue, double alpha) -> void
{
  cairo_pattern_add_color_stop_rgba(m_cobject, offset, red, green, blue, alpha);
  check_object_status_and_throw_exception(*this);
}

auto
Gradient::get_color_stops() const -> std::vector<ColorStop>
{
  std::vector<ColorStop> stops;

  int num_stops = 0;
  // we can ignore the return value since we know this is a gradient pattern
  cairo_pattern_get_color_stop_count(m_cobject, &num_stops);
  // since we know the total number of stops, we can avoid re-allocation with
  // each addition to the vector by pre-allocating the required number
  stops.reserve(num_stops);
  for(int i = 0; i < num_stops; ++i)
  {
    ColorStop stop;
    cairo_pattern_get_color_stop_rgba(m_cobject, i, &stop.offset, &stop.red,
                                      &stop.green, &stop.blue, &stop.alpha);
    stops.push_back(stop);
  }
  return stops;
}


LinearGradient::LinearGradient(double x0, double y0, double x1, double y1)
{
  m_cobject = cairo_pattern_create_linear(x0, y0, x1, y1);
  check_object_status_and_throw_exception(*this);
}

auto LinearGradient::get_linear_points (
  double &x0, double &y0,
  double &x1, double &y1) const -> void
{
  // ignore the return value since we know that this is a linear gradient
  // pattern
  cairo_pattern_get_linear_points(m_cobject, &x0, &y0, &x1, &y1);
  check_object_status_and_throw_exception(*this);
}


auto LinearGradient::create(double x0, double y0, double x1, double y1) -> RefPtr<LinearGradient>
{
  return make_refptr_for_instance<LinearGradient>(new LinearGradient(x0, y0, x1, y1));
}

LinearGradient::LinearGradient(cairo_pattern_t* cobject, bool has_reference)
: Gradient(cobject, has_reference)
{
}

LinearGradient::~LinearGradient()
{
}


RadialGradient::RadialGradient(double cx0, double cy0, double radius0, double cx1, double cy1, double radius1)
{
  m_cobject = cairo_pattern_create_radial(cx0, cy0, radius0, cx1, cy1, radius1);
  check_object_status_and_throw_exception(*this);
}

auto RadialGradient::get_radial_circles (
  double &x0, double &y0, double &r0,
  double &x1, double &y1, double &r1) const -> void
{
  // ignore the return value since we know that this is a radial gradient
  // pattern
  cairo_pattern_get_radial_circles(const_cast<cairo_pattern_t*>(m_cobject),
                                    &x0, &y0, &r0, &x1, &y1, &r1);
  check_object_status_and_throw_exception(*this);
}


auto RadialGradient::create(double cx0, double cy0, double radius0, double cx1, double cy1, double radius1) -> RefPtr<RadialGradient>
{
  return make_refptr_for_instance<RadialGradient>(new RadialGradient(cx0, cy0, radius0, cx1, cy1, radius1));
}

RadialGradient::RadialGradient(cairo_pattern_t* cobject, bool has_reference)
: Gradient(cobject, has_reference)
{
}

RadialGradient::~RadialGradient()
{
}


} //namespace Cairo

// vim: ts=2 sw=2 et
