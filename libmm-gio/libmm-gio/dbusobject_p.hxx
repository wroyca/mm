
#ifndef _GIOMM_DBUSOBJECT_P_H
#define _GIOMM_DBUSOBJECT_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

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

      auto
      init () -> const Interface_Class&;

      static auto
      iface_init_function (void* g_iface, void* iface_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
      static auto
      interface_added_callback (GDBusObject* self, GDBusInterface* p0) -> void;
      static auto
      interface_removed_callback (GDBusObject* self, GDBusInterface* p0)
          -> void;

      static auto
      get_object_path_vfunc_callback (GDBusObject* self) -> const gchar*;
      static auto
      get_interfaces_vfunc_callback (GDBusObject* self) -> GList*;
      static auto
      get_interface_vfunc_callback (GDBusObject* self,
                                    const gchar* interface_name)
          -> GDBusInterface*;
    };

  } // namespace DBus

} // namespace Gio

#endif
