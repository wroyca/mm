
#ifndef _GDKMM_TOPLEVELSIZE_H
#define _GDKMM_TOPLEVELSIZE_H

#include <mm/gdk/mm-gdkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <gdk/gdk.h>


namespace Gdk
{

/** Information for computing toplevel size.
 *
 * The %Gdk::ToplevelSize struct contains information that may be useful
 * for users of Gdk::Toplevel to compute a surface size. It also carries
 * information back with the computational result.
 *
 * @newin{3,98}
 */
class GDKMM_API ToplevelSize
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ToplevelSize;
  using BaseObjectType = GdkToplevelSize;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  explicit ToplevelSize(GdkToplevelSize* gobject);

  // Not copyable
  ToplevelSize(const ToplevelSize& other) = delete;
  auto operator=(const ToplevelSize& other) -> ToplevelSize& = delete;

  // Movable
  ToplevelSize(ToplevelSize&& other) noexcept;
  auto operator=(ToplevelSize&& other) noexcept -> ToplevelSize&;

  ~ToplevelSize() noexcept;

  /** Checks if this instance is valid.
   * It is valid if and only if it contains a pointer to a GdkToplevelSize.
   * For instance,
   * @code
   * if (size)
   *   do_something()
   * @endcode
   */
  explicit operator bool() const;

  /// Provides access to the underlying C object.
  auto gobj() -> GdkToplevelSize* { return gobject_; }
  /// Provides access to the underlying C object.
  auto gobj() const -> const GdkToplevelSize* { return gobject_; }


  /** Retrieves the bounds the toplevel is placed within.
   *
   * The bounds represent the largest size a toplevel may have while still being
   * able to fit within some type of boundary. Depending on the backend, this may
   * be equivalent to the dimensions of the work area or the monitor on which the
   * window is being presented on, or something else that limits the way a
   * toplevel can be presented.
   *
   * @param bounds_width Return location for width.
   * @param bounds_height Return location for height.
   */
  void get_bounds(int& bounds_width, int& bounds_height) const;

  /** Sets the size the toplevel prefers to be resized to.
   *
   * The size should be within the bounds (see
   * get_bounds()). The set size should
   * be considered as a hint, and should not be assumed to be
   * respected by the windowing system, or backend.
   *
   * @param width The width.
   * @param height The height.
   */
  void set_size(int width, int height);

  /** Sets the minimum size of the toplevel.
   *
   * The minimum size corresponds to the limitations the toplevel can be shrunk
   * to, without resulting in incorrect painting. A user of a `Gdk::Toplevel` should
   * calculate these given both the existing size, and the bounds retrieved from
   * the `Gdk::ToplevelSize` object.
   *
   * The minimum size should be within the bounds (see
   * get_bounds()).
   *
   * @param min_width The minimum width.
   * @param min_height The minimum height.
   */
  void set_min_size(int min_width, int min_height);

  /** Sets the shadows size of the toplevel.
   *
   * The shadow width corresponds to the part of the computed surface size
   * that would consist of the shadow margin surrounding the window, would
   * there be any.
   *
   * @param left Width of the left part of the shadow.
   * @param right Width of the right part of the shadow.
   * @param top Height of the top part of the shadow.
   * @param bottom Height of the bottom part of the shadow.
   */
  void set_shadow_width(int left, int right, int top, int bottom);

protected:
  // The Gdk::ToplevelSize instance does not own the wrapped GdkToplevelSize instance.
  // GdkToplevelSize is a private gtk struct with no public create,
  // copy or free functions.
  GdkToplevelSize* gobject_;


};

} // namespace Gdk


#endif /* _GDKMM_TOPLEVELSIZE_H */

