#ifndef _GLIBMM_REFPTR_H
#define _GLIBMM_REFPTR_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <memory>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <class T_CppObject>
  void
  RefPtrDeleter (T_CppObject* object)
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

} // namespace Glib

#endif
