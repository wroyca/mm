/* Copyright (C) 2008 Jonathon Jongsma
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
#include <mm/cairo/matrix.hpp>
#include <mm/cairo/private.hpp>

namespace Cairo
{

Matrix::Matrix() = default;

Matrix::Matrix(const double xx, const double yx, const double xy, const double yy, const double x0, const double y0)
{
  cairo_matrix_init(this, xx, yx, xy, yy, x0, y0);
}

auto identity_matrix() -> Matrix
{
  Matrix m;
  cairo_matrix_init_identity(&m);
  return m;
}

auto translation_matrix(
  const double tx, const double ty) -> Matrix
{
  Matrix m;
  cairo_matrix_init_translate(&m, tx, ty);
  return m;
}

auto scaling_matrix(
  const double sx, const double sy) -> Matrix
{
  Matrix m;
  cairo_matrix_init_scale(&m, sx, sy);
  return m;
}

auto rotation_matrix(
  const double radians) -> Matrix
{
  Matrix m;
  cairo_matrix_init_rotate(&m, radians);
  return m;
}

auto Matrix::translate (
  const double tx, const double ty) -> void
{
  cairo_matrix_translate(this, tx, ty);
}

auto Matrix::scale (
  const double sx, const double sy) -> void
{
  cairo_matrix_scale(this, sx, sy);
}

auto Matrix::rotate (
  const double radians) -> void
{
  cairo_matrix_rotate(this, radians);
}

auto Matrix::invert () -> void
{
  const auto status = cairo_matrix_invert(this);
  check_status_and_throw_exception(status);
}

// throws exception
auto Matrix::multiply (Matrix &a, Matrix &b) -> void
{
  cairo_matrix_multiply(this, &a, &b);
}

auto Matrix::transform_distance (double &dx, double &dy) const -> void
{
  cairo_matrix_transform_distance(this, &dx, &dy);
}

auto Matrix::transform_point (double &x, double &y) const -> void
{
  cairo_matrix_transform_point(this, &x, &y);
}

auto operator*(const Matrix& a, const Matrix& b) -> Matrix
{
  Matrix m;
  cairo_matrix_multiply(&m, &a, &b);
  return m;
}

} // namespace Cairo
