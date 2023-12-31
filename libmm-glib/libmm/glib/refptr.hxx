// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_REFPTR_H
#define _GLIBMM_REFPTR_H

#include <glib.h>
#include <libmm/glib/mm-glibconfig.hxx>
#include <memory>

namespace glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <class T_CppObject>
  auto
  RefPtrDeleter (T_CppObject* object) -> void
  {
    if (!object)
      return;

    object->unreference ();
  }
#endif

  template <class T_CppObject>
  using RefPtr = std::shared_ptr<T_CppObject>;

  template <class T_CppObject>
  auto
  make_refptr_for_instance (T_CppObject* object) -> RefPtr<T_CppObject>
  {
    return RefPtr<T_CppObject> (object, &RefPtrDeleter<T_CppObject>);
  }

} // namespace glib

#endif
