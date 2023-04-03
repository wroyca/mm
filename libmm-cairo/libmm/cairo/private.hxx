// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_PRIVATE_H
#define __CAIROMM_PRIVATE_H

#include <libmm/cairo/enums.hxx>
#include <libmm/cairo/exception.hxx>
#include <string>

#ifndef DOXYGEN_IGNORE_THIS
namespace Cairo
{

  auto
  throw_exception (ErrorStatus status) -> void;

  inline auto
  check_status_and_throw_exception (ErrorStatus status) -> void
  {
    if (status != CAIRO_STATUS_SUCCESS)
      throw_exception (status);
  }

  template <class T>
  auto
  check_object_status_and_throw_exception (const T& object) -> void
  {
    check_status_and_throw_exception (object.get_status ());
  }

} // namespace Cairo
#endif

#endif
