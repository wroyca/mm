#pragma once

#include <iosfwd>
#include <string>

#include <libmm-adw/export.hxx>

namespace mm_adw
{

  LIBMM_ADW_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
