


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/csslocation.hpp>
#include <libmm-gtk/csslocation_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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

namespace Gtk
{

CssLocation::CssLocation()
: gobject_{}
{
}

CssLocation::CssLocation(const GtkCssLocation* location)
: gobject_(*location)
{
}

CssLocation::CssLocation(
  const std::size_t bytes, const std::size_t chars, const std::size_t lines, const std::size_t line_bytes, const std::size_t line_chars)
{
  gobject_.bytes = bytes;
  gobject_.chars = chars;
  gobject_.lines = lines;
  gobject_.line_bytes = line_bytes;
  gobject_.line_chars = line_chars;
}

} // namespace Gtk

namespace Glib
{

auto wrap(const GtkCssLocation* object) -> Gtk::CssLocation
{
  return {object};
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Gtk
{


auto CssLocation::get_bytes() const -> std::size_t
{
  return gobj()->bytes;
}

auto CssLocation::set_bytes (const std::size_t &value) -> void
{
  gobj()->bytes = value;
}

auto CssLocation::get_chars() const -> std::size_t
{
  return gobj()->chars;
}

auto CssLocation::set_chars (const std::size_t &value) -> void
{
  gobj()->chars = value;
}

auto CssLocation::get_lines() const -> std::size_t
{
  return gobj()->lines;
}

auto CssLocation::set_lines (const std::size_t &value) -> void
{
  gobj()->lines = value;
}

auto CssLocation::get_line_bytes() const -> std::size_t
{
  return gobj()->line_bytes;
}

auto CssLocation::set_line_bytes (const std::size_t &value) -> void
{
  gobj()->line_bytes = value;
}

auto CssLocation::get_line_chars() const -> std::size_t
{
  return gobj()->line_chars;
}

auto CssLocation::set_line_chars (const std::size_t &value) -> void
{
  gobj()->line_chars = value;
}


} // namespace Gtk


