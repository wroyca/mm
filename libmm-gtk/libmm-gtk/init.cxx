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

#include <libmm-gtk/init.hpp>
#include <libmm-glib/init.hpp>
#include <libmm-gio/init.hpp>
#include <libmm-pango/wrap_init.hpp>
#include <libmm-gdk/wrap_init.hpp>
#include <libmm-gtk/wrap_init.hpp>

namespace Gtk
{

auto init_gtkmm_internals () -> void
{
  static bool init_done = false;

  if (!init_done)
  {
    Glib::init();
    Gio::init();

    // Populate the map of GTypes to C++ wrap_new() functions.
    Pango::wrap_init();
    Gdk::wrap_init();
    wrap_init();

    init_done = true;
  }
}

} // namespace Gtk
