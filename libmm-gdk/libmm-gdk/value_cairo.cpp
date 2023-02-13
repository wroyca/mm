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

#include <libmm-gdk/value_cairo.hpp>
#include <cairo-gobject.h>

namespace Gdk::Cairo
{

template <>
auto get_base_type<::Cairo::Region>() -> GType { return CAIRO_GOBJECT_TYPE_REGION; }

template <>
auto get_base_type<::Cairo::Surface>() -> GType { return CAIRO_GOBJECT_TYPE_SURFACE; }

} //namespace Gdk
