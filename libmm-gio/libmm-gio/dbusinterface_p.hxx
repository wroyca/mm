// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACE_P_H
#define _GIOMM_DBUSINTERFACE_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

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

      auto
      init () -> const Glib::Interface_Class&;

      static auto
      iface_init_function (void* g_iface, void* iface_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
      static auto
      get_info_vfunc_callback (GDBusInterface* self) -> GDBusInterfaceInfo*;
      static auto
      get_object_vfunc_callback (GDBusInterface* self) -> GDBusObject*;
      static auto
      set_object_vfunc_callback (GDBusInterface* self, GDBusObject* object)
          -> void;
      static auto
      dup_object_vfunc_callback (GDBusInterface* self) -> GDBusObject*;
    };

  } // namespace DBus

} // namespace Gio

#endif
