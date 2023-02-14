// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_STRINGUTILS_H
#define _GLIBMM_STRINGUTILS_H

#include <libmm-glib/ustring.hxx>

namespace Glib
{

  GLIBMM_API
  auto
  str_has_prefix (const std::string& str, const std::string& prefix) -> bool;

  GLIBMM_API
  auto
  str_has_suffix (const std::string& str, const std::string& suffix) -> bool;

  namespace Ascii
  {

    GLIBMM_API
    auto
    strtod (const std::string& str) -> double;

    GLIBMM_API
    auto
    strtod (const std::string& str,
            std::string::size_type& end_index,
            std::string::size_type start_index = 0) -> double;

    GLIBMM_API
    auto
    dtostr (double d) -> std::string;

  } // namespace Ascii

  GLIBMM_API
  auto
  strescape (const std::string& source) -> std::string;

  GLIBMM_API
  auto
  strescape (const std::string& source, const std::string& exceptions) -> std::string;

  GLIBMM_API
  auto
  strcompress (const std::string& source) -> std::string;

  GLIBMM_API
  auto
  strerror (int errnum) -> Glib::ustring;

  GLIBMM_API
  auto
  strsignal (int signum) -> Glib::ustring;

} // namespace Glib

#endif
