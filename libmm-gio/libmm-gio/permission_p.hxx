// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PERMISSION_P_H
#define _GIOMM_PERMISSION_P_H

#include <gio/gio.h>
#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Permission_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Permission;
    using BaseObjectType = GPermission;
    using BaseClassType = GPermissionClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Permission;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    acquire_vfunc_callback (GPermission* self,
                            GCancellable* cancellable,
                            GError** error) -> gboolean;
    static auto
    acquire_async_vfunc_callback (GPermission* self,
                                  GCancellable* cancellable,
                                  GAsyncReadyCallback callback,
                                  gpointer user_data) -> void;
    static auto
    acquire_finish_vfunc_callback (GPermission* self,
                                   GAsyncResult* result,
                                   GError** error) -> gboolean;
    static auto
    release_vfunc_callback (GPermission* self,
                            GCancellable* cancellable,
                            GError** error) -> gboolean;
    static auto
    release_async_vfunc_callback (GPermission* self,
                                  GCancellable* cancellable,
                                  GAsyncReadyCallback callback,
                                  gpointer user_data) -> void;
    static auto
    release_finish_vfunc_callback (GPermission* self,
                                   GAsyncResult* result,
                                   GError** error) -> gboolean;
  };

} // namespace Gio

#endif
