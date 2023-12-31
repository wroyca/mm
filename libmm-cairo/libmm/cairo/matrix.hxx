// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_MATRIX_H
#define __CAIROMM_MATRIX_H

#include <libmm/cairo/mm-cairoconfig.hxx>

#include <cairo.h>

namespace cairo
{

  class LIBMM_CAIRO_SYMEXPORT Matrix : public cairo_matrix_t
  {
  public:
    Matrix ();

    Matrix (double xx, double yx, double xy, double yy, double x0, double y0);

    auto
    translate (double tx, double ty) -> void;

    auto
    scale (double sx, double sy) -> void;

    auto
    rotate (double radians) -> void;

    auto
    invert () -> void;

    auto
    multiply (Matrix& a, Matrix& b) -> void;

    auto
    transform_distance (double& dx, double& dy) const -> void;

    auto
    transform_point (double& x, double& y) const -> void;
  };

  LIBMM_CAIRO_SYMEXPORT
  auto
  identity_matrix () -> Matrix;

  LIBMM_CAIRO_SYMEXPORT
  auto
  translation_matrix (double tx, double ty) -> Matrix;

  LIBMM_CAIRO_SYMEXPORT
  auto
  scaling_matrix (double sx, double sy) -> Matrix;

  LIBMM_CAIRO_SYMEXPORT
  auto
  rotation_matrix (double radians) -> Matrix;

  LIBMM_CAIRO_SYMEXPORT
  auto
  operator* (const Matrix& a, const Matrix& b) -> Matrix;

} // namespace cairo

#endif
