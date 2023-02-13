
#ifndef _GIOMM_DBUSOBJECTMANAGER_P_H
#define _GIOMM_DBUSOBJECTMANAGER_P_H


#include <mm/glib/private/interface_p.hpp>
#include <gio/gio.h>

#include <mm/glib/private/interface_p.hpp>

namespace Gio
{

namespace DBus
{

class GIOMM_API ObjectManager_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ObjectManager;
  using BaseObjectType = GDBusObjectManager;
  using BaseClassType = GDBusObjectManagerIface;
  using CppClassParent = Interface_Class;

  friend class ObjectManager;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto object_added_callback (GDBusObjectManager *self, GDBusObject *p0) -> void;
  static auto object_removed_callback (GDBusObjectManager *self, GDBusObject *p0) -> void;
  static auto interface_added_callback (
    GDBusObjectManager *self, GDBusObject *p0, GDBusInterface *p1) -> void;
  static auto interface_removed_callback (
    GDBusObjectManager *self, GDBusObject *p0, GDBusInterface *p1) -> void;

  //Callbacks (virtual functions):
  static auto get_object_path_vfunc_callback (GDBusObjectManager *self) -> const gchar*;
  static auto get_objects_vfunc_callback (GDBusObjectManager *self) -> GList*;
  static auto get_object_vfunc_callback (
    GDBusObjectManager *self, const gchar *object_path) -> GDBusObject*;
  static auto get_interface_vfunc_callback (
    GDBusObjectManager *self, const gchar *object_path,
    const gchar *interface_name) -> GDBusInterface*;
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECTMANAGER_P_H */

