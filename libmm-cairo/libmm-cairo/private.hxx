

#ifndef __CAIROMM_PRIVATE_H
#define __CAIROMM_PRIVATE_H

#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/exception.hxx>
#include <string>

#ifndef DOXYGEN_IGNORE_THIS
namespace Cairo
{

  void
  throw_exception (ErrorStatus status);

  inline void
  check_status_and_throw_exception (ErrorStatus status)
  {
    if (status != CAIRO_STATUS_SUCCESS)
      throw_exception (status);
  }

  template <class T>
  void
  check_object_status_and_throw_exception (const T& object)
  {
    check_status_and_throw_exception (object.get_status ());
  }

} // namespace Cairo
#endif

#endif
