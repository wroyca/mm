// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEPERMISSION_P_H
#define _GIOMM_SIMPLEPERMISSION_P_H

#include <libmm/gio/permission_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SimplePermission_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SimplePermission;
    using BaseObjectType = GSimplePermission;
    using BaseClassType = GSimplePermissionClass;
    using CppClassParent = Permission_Class;
    using BaseClassParent = GPermissionClass;

    friend class SimplePermission;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gio

#endif
