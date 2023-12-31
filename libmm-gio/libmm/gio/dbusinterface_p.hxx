// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACE_P_H
#define _GIOMM_DBUSINTERFACE_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT Interface_Class : public glib::Interface_Class
    {
    public:
      using CppObjectType = Interface;
      using BaseObjectType = GDBusInterface;
      using BaseClassType = GDBusInterfaceIface;
      using CppClassParent = glib::Interface_Class;

      friend class Interface;

      auto
      init () -> const glib::Interface_Class&;

      static auto
      iface_init_function (void* g_iface, void* iface_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

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

} // namespace gio

#endif
