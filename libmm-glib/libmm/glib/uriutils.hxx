// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_URIUTILS_H
#define _GLIBMM_URIUTILS_H

#include <libmm/glib/mm-glibconfig.hxx>
#include <string>

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  uri_unescape_string (const std::string& escaped_string,
                       const std::string& illegal_characters = {}) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  uri_parse_scheme (const std::string& uri) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  uri_escape_string (const std::string& unescaped,
                     const std::string& reserved_chars_allowed = {},
                     bool allow_utf8 = true) -> std::string;

} // namespace glib

#endif
