


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusutils.hpp>
#include <mm/gio/private/dbusutils_p.hpp>


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
#include <mm/glib/utility.hpp>

namespace Gio::DBus
{

auto
generate_guid() -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_dbus_generate_guid());
}

auto
is_guid(const std::string& string) -> bool
{
  return static_cast<bool>(g_dbus_is_guid(string.c_str()));
}

auto
is_name(const Glib::ustring& string) -> bool
{
  return static_cast<bool>(g_dbus_is_name(string.c_str()));
}

auto
is_unique_name(const Glib::ustring& string) -> bool
{
  return static_cast<bool>(g_dbus_is_unique_name(string.c_str()));
}

auto
is_member_name(const Glib::ustring& string) -> bool
{
  return static_cast<bool>(g_dbus_is_member_name(string.c_str()));
}

auto
is_interface_name(const Glib::ustring& string) -> bool
{
  return static_cast<bool>(g_dbus_is_interface_name(string.c_str()));
}

} // namespace Gio

namespace
{
} // anonymous namespace


