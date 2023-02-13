


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/uriutils.hpp>
#include <mm/glib/private/uriutils_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <glib.h>
#include <mm/glib/utility.hpp>

namespace Glib
{

auto
uri_unescape_string(const std::string& escaped_string, const std::string& illegal_characters) -> std::string
{
  gchar* cresult = g_uri_unescape_string(escaped_string.c_str(), illegal_characters.c_str());
  return convert_return_gchar_ptr_to_stdstring(cresult);
}

auto
uri_parse_scheme(const std::string& uri) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_uri_parse_scheme(uri.c_str()));
}

auto
uri_escape_string(
  const std::string& unescaped, const std::string& reserved_chars_allowed, const bool allow_utf8) -> std::string
{
  gchar* cresult =
    g_uri_escape_string(unescaped.c_str(), reserved_chars_allowed.c_str(), allow_utf8);
  return convert_return_gchar_ptr_to_stdstring(cresult);
}

} // namespace Glib

namespace
{
} // anonymous namespace


