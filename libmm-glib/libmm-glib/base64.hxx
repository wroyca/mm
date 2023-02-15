// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BASE64_H
#define _GLIBMM_BASE64_H

#include <libmm-glib/mm-glibconfig.hxx>

#include <glib.h>
#include <string>

namespace Glib::Base64
{

  LIBMM_GLIB_SYMEXPORT
  auto
  encode (const std::string& source, bool break_lines = false) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  decode (const std::string& source) -> std::string;
} // namespace Glib::Base64

#endif
