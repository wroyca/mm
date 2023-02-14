
#ifndef _GIOMM_DRIVE_P_H
#define _GIOMM_DRIVE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API Drive_Class : public Glib::Interface_Class
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
    wrap_new (GObject*) -> Glib::ObjectBase*;

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

} // namespace Gio

#endif
