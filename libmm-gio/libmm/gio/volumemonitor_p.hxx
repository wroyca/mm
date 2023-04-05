// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_VOLUMEMONITOR_P_H
#define _GIOMM_VOLUMEMONITOR_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT VolumeMonitor_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VolumeMonitor;
    using BaseObjectType = GVolumeMonitor;
    using BaseClassType = GVolumeMonitorClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class VolumeMonitor;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    volume_added_callback (GVolumeMonitor* self, GVolume* p0) -> void;
    static auto
    volume_removed_callback (GVolumeMonitor* self, GVolume* p0) -> void;
    static auto
    volume_changed_callback (GVolumeMonitor* self, GVolume* p0) -> void;
    static auto
    mount_added_callback (GVolumeMonitor* self, GMount* p0) -> void;
    static auto
    mount_removed_callback (GVolumeMonitor* self, GMount* p0) -> void;
    static auto
    mount_pre_unmount_callback (GVolumeMonitor* self, GMount* p0) -> void;
    static auto
    mount_changed_callback (GVolumeMonitor* self, GMount* p0) -> void;
    static auto
    drive_connected_callback (GVolumeMonitor* self, GDrive* p0) -> void;
    static auto
    drive_disconnected_callback (GVolumeMonitor* self, GDrive* p0) -> void;
    static auto
    drive_changed_callback (GVolumeMonitor* self, GDrive* p0) -> void;
    static auto
    drive_eject_button_callback (GVolumeMonitor* self, GDrive* p0) -> void;
    static auto
    drive_stop_button_callback (GVolumeMonitor* self, GDrive* p0) -> void;
  };

} // namespace gio

#endif
