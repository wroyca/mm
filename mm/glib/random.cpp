/* random.cc
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

#include <mm/glib/mm-glib.hpp>

namespace Glib
{

Rand::Rand() : gobject_(g_rand_new())
{
}

Rand::Rand(guint32 seed) : gobject_(g_rand_new_with_seed(seed))
{
}

Rand::~Rand() noexcept
{
  g_rand_free(gobject_);
}

auto Rand::set_seed (guint32 seed) -> void
{
  g_rand_set_seed(gobject_, seed);
}

auto
Rand::get_bool() -> bool
{
  return g_rand_boolean(gobject_);
}

auto
Rand::get_int() -> guint32
{
  return g_rand_int(gobject_);
}

auto
Rand::get_int_range(gint32 begin, gint32 end) -> gint32
{
  return g_rand_int_range(gobject_, begin, end);
}

auto
Rand::get_double() -> double
{
  return g_rand_double(gobject_);
}

auto
Rand::get_double_range(double begin, double end) -> double
{
  return g_rand_double_range(gobject_, begin, end);
}

} // namespace Glib
