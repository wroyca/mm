// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_REFPTR_H
#define __CAIROMM_REFPTR_H

#include <memory>

namespace cairo
{

  template <typename T_CppObject>
  using RefPtr = std::shared_ptr<T_CppObject>;

  template <typename T_CppObject>
  auto
  make_refptr_for_instance (T_CppObject* object) -> RefPtr<T_CppObject>
  {
    return RefPtr<T_CppObject> (object);
  }

} // namespace cairo

#endif
