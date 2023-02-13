#pragma once

#include <iosfwd>
#include <string>

#include <libmm-gio/export.hxx>

namespace mm_gio
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBMM_GIO_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
