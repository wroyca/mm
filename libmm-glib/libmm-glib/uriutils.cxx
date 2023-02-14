// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/uriutils.hxx>
#include <libmm-glib/uriutils_p.hxx>

#include <glib.h>
#include <libmm-glib/utility.hxx>

namespace Glib
{

  auto
  uri_unescape_string (const std::string& escaped_string,
                       const std::string& illegal_characters) -> std::string
  {
    gchar* cresult = g_uri_unescape_string (escaped_string.c_str (),
                                            illegal_characters.c_str ());
    return convert_return_gchar_ptr_to_stdstring (cresult);
  }

  auto
  uri_parse_scheme (const std::string& uri) -> std::string
  {
    return convert_return_gchar_ptr_to_stdstring (
        g_uri_parse_scheme (uri.c_str ()));
  }

  auto
  uri_escape_string (const std::string& unescaped,
                     const std::string& reserved_chars_allowed,
                     const bool allow_utf8) -> std::string
  {
    gchar* cresult = g_uri_escape_string (unescaped.c_str (),
                                          reserved_chars_allowed.c_str (),
                                          allow_utf8);
    return convert_return_gchar_ptr_to_stdstring (cresult);
  }

} // namespace Glib

namespace
{
}
