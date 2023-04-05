// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DRIVE_P_H
#define _GIOMM_DRIVE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Drive_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Drive;
    using BaseObjectType = GDrive;
    using BaseClassType = GDriveIface;
    using CppClassParent = Interface_Class;

    friend class Drive;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GDrive* self) -> void;
    static auto
    disconnected_callback (GDrive* self) -> void;
    static auto
    eject_button_callback (GDrive* self) -> void;
    static auto
    stop_button_callback (GDrive* self) -> void;
  };

} // namespace gio

#endif
