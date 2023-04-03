// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_STRINGUTILS_H
#define _GLIBMM_STRINGUTILS_H

#include <libmm/glib/ustring.hxx>

namespace Glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  str_has_prefix (const std::string& str, const std::string& prefix) -> bool;

  LIBMM_GLIB_SYMEXPORT
  auto
  str_has_suffix (const std::string& str, const std::string& suffix) -> bool;

  namespace Ascii
  {

    LIBMM_GLIB_SYMEXPORT
    auto
    strtod (const std::string& str) -> double;

    LIBMM_GLIB_SYMEXPORT
    auto
    strtod (const std::string& str,
            std::string::size_type& end_index,
            std::string::size_type start_index = 0) -> double;

    LIBMM_GLIB_SYMEXPORT
    auto
    dtostr (double d) -> std::string;

  } // namespace Ascii

  LIBMM_GLIB_SYMEXPORT
  auto
  strescape (const std::string& source) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  strescape (const std::string& source, const std::string& exceptions) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  strcompress (const std::string& source) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  strerror (int errnum) -> Glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  strsignal (int signum) -> Glib::ustring;

} // namespace Glib

#endif
