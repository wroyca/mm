// SPDX-License-Identifier: LGPL-2.0-or-later

#include <iostream>
#include <libmm/cairo/path.hxx>
#include <libmm/cairo/private.hxx>

namespace Cairo
{

  Path::Path (cairo_path_t* cobject, const bool take_ownership)
    : m_cobject (nullptr)
  {
    if (take_ownership)
      m_cobject = cobject;
    else
    {
      std::cerr << "cairomm: Path::Path(): copying of the underlying "
                   "cairo_path_t* is not yet implemented."
                << std::endl;
    }
  }

  Path::~Path ()
  {
    if (m_cobject)
      cairo_path_destroy (m_cobject);
  }

} // namespace Cairo
