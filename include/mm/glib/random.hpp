#ifndef _GLIBMM_RANDOM_H
#define _GLIBMM_RANDOM_H

/* random.h
 *
 * Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/mm-glibconfig.hpp>
#include <glib.h>

extern "C" {
using GRand = struct _GRand;
}

namespace Glib
{

/** @defgroup Random Random Numbers
 * Pseudo random number generator.
 * @{
 */

class GLIBMM_API Rand
{
public:
  Rand();
  explicit Rand(guint32 seed);
  ~Rand() noexcept;

  // noncopyable
  Rand(const Rand&) = delete;
  auto operator=(const Rand&) -> Rand& = delete;

  void set_seed(guint32 seed);

  auto get_bool() -> bool;

  auto get_int() -> guint32;
  auto get_int_range(gint32 begin, gint32 end) -> gint32;

  auto get_double() -> double;
  auto get_double_range(double begin, double end) -> double;

  auto gobj() -> GRand* { return gobject_; }
  auto gobj() const -> const GRand* { return gobject_; }

private:
  GRand* gobject_;
};

/** @} group Random */

} // namespace Glib

#endif /* _GLIBMM_RANDOM_H */
