// SPDX-License-Identifier: LGPL-2.0-or-later

#include <iostream>
#include <libmm-cairo/exception.hxx>
#include <libmm-cairo/mm-cairoconfig.hxx>
#include <libmm-cairo/private.hxx>
#include <stdexcept>

namespace Cairo
{

#ifdef CAIROMM_EXCEPTIONS_ENABLED
  auto
  throw_exception (const ErrorStatus status) -> void
  {
    switch (status)
    {
      case CAIRO_STATUS_SUCCESS:
        break;

      case CAIRO_STATUS_NO_MEMORY:
        throw std::bad_alloc ();
        break;

      case CAIRO_STATUS_INVALID_RESTORE:
      case CAIRO_STATUS_INVALID_POP_GROUP:
      case CAIRO_STATUS_NO_CURRENT_POINT:
      case CAIRO_STATUS_INVALID_MATRIX:
      case CAIRO_STATUS_INVALID_STRING:
      case CAIRO_STATUS_SURFACE_FINISHED:
        throw logic_error (status);
        break;

      case CAIRO_STATUS_NULL_POINTER:
      case CAIRO_STATUS_INVALID_PATH_DATA:
      case CAIRO_STATUS_SURFACE_TYPE_MISMATCH:
        throw logic_error (status);
        break;

      case CAIRO_STATUS_READ_ERROR:
      case CAIRO_STATUS_WRITE_ERROR:
      {
        const char* error_message = cairo_status_to_string (status);
        throw std::ios_base::failure (error_message ? error_message :
                                                      std::string ());
      }
      break;

      default:
        throw logic_error (status);
        break;
    }
  }
#else
  void
  throw_exception (ErrorStatus)
  {
  }
#endif

} // namespace Cairo
