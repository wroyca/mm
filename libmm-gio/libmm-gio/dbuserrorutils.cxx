


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbuserrorutils.hxx>
#include <libmm-gio/dbuserrorutils_p.hxx>


/* Copyright (C) 2010 The giomm Development Team
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

#include <gio/gio.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/utility.hxx>

namespace Gio::DBus::ErrorUtils
{

auto
is_remote_error(const Glib::Error& error) -> bool
{
  return static_cast<bool>(g_dbus_error_is_remote_error(error.gobj()));
}

auto
get_remote_error(const Glib::Error& error) -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_error_get_remote_error(error.gobj()));
}

auto
strip_remote_error(Glib::Error& error) -> bool
{
  return static_cast<bool>(g_dbus_error_strip_remote_error(error.gobj()));
}

} // namespace Gio

namespace
{
} // anonymous namespace


