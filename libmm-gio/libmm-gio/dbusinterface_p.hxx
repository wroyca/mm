
#ifndef _GIOMM_DBUSINTERFACE_P_H
#define _GIOMM_DBUSINTERFACE_P_H


#include <libmm-glib/interface_p.hpp>
#include <gio/gio.h>

#include <libmm-glib/interface_p.hpp>

namespace Gio
{

namespace DBus
{

class GIOMM_API Interface_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Interface;
  using BaseObjectType = GDBusInterface;
  using BaseClassType = GDBusInterfaceIface;
  using CppClassParent = Glib::Interface_Class;

  friend class Interface;

  auto init () -> const Glib::Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_info_vfunc_callback (GDBusInterface *self) -> GDBusInterfaceInfo*;
  static auto get_object_vfunc_callback (GDBusInterface *self) -> GDBusObject*;
  static auto set_object_vfunc_callback (GDBusInterface *self, GDBusObject *object) -> void;
  static auto dup_object_vfunc_callback (GDBusInterface *self) -> GDBusObject*;
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSINTERFACE_P_H */

