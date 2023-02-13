#pragma once

#include <iosfwd>
#include <string>

#include <libmm-pango/export.hxx>

namespace mm_pango
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBMM_PANGO_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
