/* Copyright (C) 2017 The gtkmm Development Team
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

#include <libmm-gdk/cairoutils.hxx>

namespace Gdk::Cairo
{

auto wrap(cairo_t* cobject, const bool has_reference) -> ::Cairo::RefPtr< ::Cairo::Context>
{
  return ::Cairo::make_refptr_for_instance< ::Cairo::Context>(cobject ? new ::Cairo::Context(cobject, has_reference) : nullptr);
}

auto wrap(cairo_region_t* cobject, const bool has_reference) -> ::Cairo::RefPtr< ::Cairo::Region>
{
  return ::Cairo::make_refptr_for_instance< ::Cairo::Region>(cobject ? new ::Cairo::Region(cobject, has_reference) : nullptr);
}

} // namespace Gdk
