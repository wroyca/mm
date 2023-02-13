#pragma once

#include <iosfwd>
#include <string>

#include <libmm-cairo/export.hxx>

namespace mm_cairo
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBMM_CAIRO_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
