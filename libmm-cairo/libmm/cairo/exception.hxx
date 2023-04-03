// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIRO_EXCEPTION_H
#define __CAIRO_EXCEPTION_H

#include <libmm/cairo/mm-cairoconfig.hxx>

#include <libmm/cairo/enums.hxx>
#include <stdexcept>

namespace Cairo
{

  class logic_error : public std::logic_error
  {
  public:
    LIBMM_CAIRO_SYMEXPORT explicit logic_error (ErrorStatus status);
    LIBMM_CAIRO_SYMEXPORT ~logic_error () noexcept override;

    LIBMM_CAIRO_SYMEXPORT auto
    get_status_code () const -> ErrorStatus;

  private:
    ErrorStatus m_status;
  };

} // namespace Cairo

#endif
