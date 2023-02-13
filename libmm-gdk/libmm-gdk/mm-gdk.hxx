#pragma once

#include <iosfwd>
#include <string>

#include <libmm-gdk/export.hxx>

namespace mm_gdk
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBMM_GDK_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
