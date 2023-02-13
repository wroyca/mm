
#ifndef _GIOMM_PERMISSION_P_H
#define _GIOMM_PERMISSION_P_H


#include <libmm-glib/object_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API Permission_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Permission;
  using BaseObjectType = GPermission;
  using BaseClassType = GPermissionClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Permission;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto acquire_vfunc_callback (
    GPermission *self, GCancellable *cancellable, GError **error) -> gboolean;
  static auto acquire_async_vfunc_callback (
    GPermission *self, GCancellable *cancellable, GAsyncReadyCallback callback,
    gpointer user_data) -> void;
  static auto acquire_finish_vfunc_callback (
    GPermission *self, GAsyncResult *result, GError **error) -> gboolean;
  static auto release_vfunc_callback (
    GPermission *self, GCancellable *cancellable, GError **error) -> gboolean;
  static auto release_async_vfunc_callback (
    GPermission *self, GCancellable *cancellable, GAsyncReadyCallback callback,
    gpointer user_data) -> void;
  static auto release_finish_vfunc_callback (
    GPermission *self, GAsyncResult *result, GError **error) -> gboolean;
};


} // namespace Gio


#endif /* _GIOMM_PERMISSION_P_H */
