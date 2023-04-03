// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGER_P_H
#define _GIOMM_DBUSOBJECTMANAGER_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT ObjectManager_Class : public Glib::Interface_Class
    {
    public:
      using CppObjectType = ObjectManager;
      using BaseObjectType = GDBusObjectManager;
      using BaseClassType = GDBusObjectManagerIface;
      using CppClassParent = Interface_Class;

      friend class ObjectManager;

      auto
      init () -> const Interface_Class&;

      static auto
      iface_init_function (void* g_iface, void* iface_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
      static auto
      object_added_callback (GDBusObjectManager* self, GDBusObject* p0) -> void;
      static auto
      object_removed_callback (GDBusObjectManager* self, GDBusObject* p0)
          -> void;
      static auto
      interface_added_callback (GDBusObjectManager* self,
                                GDBusObject* p0,
                                GDBusInterface* p1) -> void;
      static auto
      interface_removed_callback (GDBusObjectManager* self,
                                  GDBusObject* p0,
                                  GDBusInterface* p1) -> void;

      static auto
      get_object_path_vfunc_callback (GDBusObjectManager* self) -> const gchar*;
      static auto
      get_objects_vfunc_callback (GDBusObjectManager* self) -> GList*;
      static auto
      get_object_vfunc_callback (GDBusObjectManager* self,
                                 const gchar* object_path) -> GDBusObject*;
      static auto
      get_interface_vfunc_callback (GDBusObjectManager* self,
                                    const gchar* object_path,
                                    const gchar* interface_name)
          -> GDBusInterface*;
    };

  } // namespace DBus

} // namespace Gio

#endif
