
#ifndef _GIOMM_DBUSOBJECT_P_H
#define _GIOMM_DBUSOBJECT_P_H


#include <mm/glib/private/interface_p.hpp>
#include <gio/gio.h>

#include <mm/glib/private/interface_p.hpp>

namespace Gio
{

namespace DBus
{

class GIOMM_API Object_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Object;
  using BaseObjectType = GDBusObject;
  using BaseClassType = GDBusObjectIface;
  using CppClassParent = Interface_Class;

  friend class Object;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto interface_added_callback (GDBusObject *self, GDBusInterface *p0) -> void;
  static auto interface_removed_callback (GDBusObject *self, GDBusInterface *p0) -> void;

  //Callbacks (virtual functions):
  static auto get_object_path_vfunc_callback (GDBusObject *self) -> const gchar*;
  static auto get_interfaces_vfunc_callback (GDBusObject *self) -> GList*;
  static auto get_interface_vfunc_callback (
    GDBusObject *self, const gchar *interface_name) -> GDBusInterface*;
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECT_P_H */

