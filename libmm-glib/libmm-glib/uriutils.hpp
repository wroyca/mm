
#ifndef _GLIBMM_URIUTILS_H
#define _GLIBMM_URIUTILS_H


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


#include <libmm-glib/mm-glibconfig.hpp>
#include <string>

namespace Glib
{

/** @defgroup UriUtils URI Utilities
 * Various uri-related functions.
 */

//Note that the illegal_characters and reserved_chars_allowed parameters are bytes and may not be UTF-8
//so they are not Glib::ustring. See http://bugzilla.gnome.org/show_bug.cgi?id=508773

/** Unescapes a whole escaped string.
 * If any of the characters in @a illegal_characters or the character zero appears
 * as an escaped character in @a escaped_string then that is an error and an empty string
 * will be returned. This is useful it you want to avoid, for instance, having a
 * slash being expanded in an escaped path element, which might confuse pathname
 * handling.
 *
 * @param escaped_string An escaped string to be unescaped.
 * @param illegal_characters An optional string of illegal characters not to be allowed.
 * @result An unescaped version of @a escaped_string.
 *
 * @ingroup UriUtils
 * @newin{2,16}
 */
GLIBMM_API
auto uri_unescape_string(const std::string& escaped_string, const std::string& illegal_characters = {}) -> std::string;

//TODO: Use iterator?
//char *   g_uri_unescape_segment      (const char *escaped_string,
//				      const char *escaped_string_end,
//				      const char *illegal_characters);

/** Gets the scheme portion of a URI. RFC 3986 decodes the scheme as:
 * @code
 * URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ]
 * @endcode
 * Common schemes include "file", "http", "svn+ssh", etc.
 *
 * @param uri
 * @result The "Scheme" component of the URI, or an empty string on error.
 *
 * @ingroup UriUtils
 * @newin{2,16}
 */
GLIBMM_API
auto uri_parse_scheme(const std::string& uri) -> std::string;

/** Escapes a string for use in a URI.
 *
 * Normally all characters that are not "unreserved" (i.e. ASCII alphanumerical
 * characters plus dash, dot, underscore and tilde) are escaped.
 * But if you specify characters in @a reserved_chars_allowed they are not
 * escaped. This is useful for the "reserved" characters in the URI
 * specification, since those are allowed unescaped in some portions of
 * a URI.
 *
 * @param unescaped The unescaped input string.
 * @param reserved_chars_allowed A string of reserved characters that are allowed to be used.
 * @param allow_utf8 true if the result can include UTF-8 characters.
 * @result An escaped version of @a unescaped.
 *
 * @ingroup UriUtils
 * @newin{2,16}
 */
GLIBMM_API
auto uri_escape_string(const std::string& unescaped, const std::string& reserved_chars_allowed = {}, bool allow_utf8 = true) -> std::string;

} // namespace Glib


#endif /* _GLIBMM_URIUTILS_H */

