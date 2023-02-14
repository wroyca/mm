// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_OBJECT_P_H
#define _GLIBMM_OBJECT_P_H

#include <libmm-glib/class.hxx>

namespace Glib
{

  class GLIBMM_API Object_Class : public Class
  {
  public:
    using CppObjectType = Object;
    using BaseObjectType = GObject;
    using BaseClassType = GObjectClass;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    auto
    init () -> const Class&;

    static auto
    wrap_new (GObject*) -> Object*;
  };

} // namespace Glib

#endif
