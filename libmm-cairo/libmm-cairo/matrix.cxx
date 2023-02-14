
#include <libmm-cairo/matrix.hxx>
#include <libmm-cairo/private.hxx>

namespace Cairo
{

  Matrix::Matrix () = default;

  Matrix::Matrix (const double xx,
                  const double yx,
                  const double xy,
                  const double yy,
                  const double x0,
                  const double y0)
  {
    cairo_matrix_init (this, xx, yx, xy, yy, x0, y0);
  }

  auto
  identity_matrix () -> Matrix
  {
    Matrix m;
    cairo_matrix_init_identity (&m);
    return m;
  }

  auto
  translation_matrix (const double tx, const double ty) -> Matrix
  {
    Matrix m;
    cairo_matrix_init_translate (&m, tx, ty);
    return m;
  }

  auto
  scaling_matrix (const double sx, const double sy) -> Matrix
  {
    Matrix m;
    cairo_matrix_init_scale (&m, sx, sy);
    return m;
  }

  auto
  rotation_matrix (const double radians) -> Matrix
  {
    Matrix m;
    cairo_matrix_init_rotate (&m, radians);
    return m;
  }

  auto
  Matrix::translate (const double tx, const double ty) -> void
  {
    cairo_matrix_translate (this, tx, ty);
  }

  auto
  Matrix::scale (const double sx, const double sy) -> void
  {
    cairo_matrix_scale (this, sx, sy);
  }

  auto
  Matrix::rotate (const double radians) -> void
  {
    cairo_matrix_rotate (this, radians);
  }

  auto
  Matrix::invert () -> void
  {
    const auto status = cairo_matrix_invert (this);
    check_status_and_throw_exception (status);
  }

  auto
  Matrix::multiply (Matrix& a, Matrix& b) -> void
  {
    cairo_matrix_multiply (this, &a, &b);
  }

  auto
  Matrix::transform_distance (double& dx, double& dy) const -> void
  {
    cairo_matrix_transform_distance (this, &dx, &dy);
  }

  auto
  Matrix::transform_point (double& x, double& y) const -> void
  {
    cairo_matrix_transform_point (this, &x, &y);
  }

  auto
  operator* (const Matrix& a, const Matrix& b) -> Matrix
  {
    Matrix m;
    cairo_matrix_multiply (&m, &a, &b);
    return m;
  }

} // namespace Cairo
