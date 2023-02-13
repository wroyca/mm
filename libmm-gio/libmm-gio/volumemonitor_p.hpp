
#ifndef _GIOMM_VOLUMEMONITOR_P_H
#define _GIOMM_VOLUMEMONITOR_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API VolumeMonitor_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VolumeMonitor;
  using BaseObjectType = GVolumeMonitor;
  using BaseClassType = GVolumeMonitorClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class VolumeMonitor;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto volume_added_callback (GVolumeMonitor *self, GVolume *p0) -> void;
  static auto volume_removed_callback (GVolumeMonitor *self, GVolume *p0) -> void;
  static auto volume_changed_callback (GVolumeMonitor *self, GVolume *p0) -> void;
  static auto mount_added_callback (GVolumeMonitor *self, GMount *p0) -> void;
  static auto mount_removed_callback (GVolumeMonitor *self, GMount *p0) -> void;
  static auto mount_pre_unmount_callback (GVolumeMonitor *self, GMount *p0) -> void;
  static auto mount_changed_callback (GVolumeMonitor *self, GMount *p0) -> void;
  static auto drive_connected_callback (GVolumeMonitor *self, GDrive *p0) -> void;
  static auto drive_disconnected_callback (GVolumeMonitor *self, GDrive *p0) -> void;
  static auto drive_changed_callback (GVolumeMonitor *self, GDrive *p0) -> void;
  static auto drive_eject_button_callback (GVolumeMonitor *self, GDrive *p0) -> void;
  static auto drive_stop_button_callback (GVolumeMonitor *self, GDrive *p0) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gio


#endif /* _GIOMM_VOLUMEMONITOR_P_H */

