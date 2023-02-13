
#ifndef _GIOMM_VOLUMEMONITOR_H
#define _GIOMM_VOLUMEMONITOR_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/gio/drive.hpp>
#include <mm/gio/volume.hpp>
#include <mm/gio/mount.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GVolumeMonitor = struct _GVolumeMonitor;
using GVolumeMonitorClass = struct _GVolumeMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API VolumeMonitor_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Monitors a file or directory for changes.
 * VolumeMonitor is for listing the user-interesting devices and volumes on the
 * computer. In other words, what a file selector or file manager would show in
 * a sidebar.
 *
 * @newin{2,16}
 */

class GIOMM_API VolumeMonitor : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = VolumeMonitor;
  using CppClassType = VolumeMonitor_Class;
  using BaseObjectType = GVolumeMonitor;
  using BaseClassType = GVolumeMonitorClass;

  // noncopyable
  VolumeMonitor(const VolumeMonitor&) = delete;
  auto operator=(const VolumeMonitor&) -> VolumeMonitor& = delete;

private:  friend class VolumeMonitor_Class;
  static CppClassType volumemonitor_class_;

protected:
  explicit VolumeMonitor(const Glib::ConstructParams& construct_params);
  explicit VolumeMonitor(GVolumeMonitor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  VolumeMonitor(VolumeMonitor&& src) noexcept;
  auto operator=(VolumeMonitor&& src) noexcept -> VolumeMonitor&;

  ~VolumeMonitor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GVolumeMonitor*       { return reinterpret_cast<GVolumeMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GVolumeMonitor* { return reinterpret_cast<GVolumeMonitor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GVolumeMonitor*;

private:

protected:

public:


  /** Gets the volume monitor used by gio.
   *
   * @return A reference to the VolumeMonitor used by gio. Call
   * Glib::object_unref() when done with it.
   */
  static auto get() -> Glib::RefPtr<VolumeMonitor>;


  /** Gets a list of drives connected to the system.
   *
   * @return A List of connected Drive objects.
   */
  auto get_connected_drives() -> std::vector<Glib::RefPtr<Drive>>;


  /** Gets a list of the volumes on the system.
   *
   * @return A List of Volume objects.
   */
  auto get_volumes() -> std::vector<Glib::RefPtr<Volume>>;


  /** Gets a list of the mounts on the system.
   *
   * @return A List of Mount objects.
   */
  auto get_mounts() -> std::vector<Glib::RefPtr<Mount>>;


  /** Finds a Volume object by its UUID (see g_volume_get_uuid())
   *
   * @param uuid The UUID to look for.
   * @return A Volume or <tt>nullptr</tt> if no such volume is available.
   * Free the returned object with Glib::object_unref().
   */
  auto get_volume_for_uuid(const std::string& uuid) -> Glib::RefPtr<Volume>;

  /** Finds a Mount object by its UUID (see g_mount_get_uuid())
   *
   * @param uuid The UUID to look for.
   * @return A Mount or <tt>nullptr</tt> if no such mount is available.
   * Free the returned object with Glib::object_unref().
   */
  auto get_mount_for_uuid(const std::string& uuid) -> Glib::RefPtr<Mount>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_added(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mountable volume is added to the system.
   *
   * @param volume A Volume that was added.
   */

  auto signal_volume_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_removed(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mountable volume is removed from the system.
   *
   * @param volume A Volume that was removed.
   */

  auto signal_volume_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%volume_changed(const Glib::RefPtr<Volume>& volume)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when mountable volume is changed.
   *
   * @param volume A Volume that changed.
   */

  auto signal_volume_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_added(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mount is added.
   *
   * @param mount A Mount that was added.
   */

  auto signal_mount_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_removed(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mount is removed.
   *
   * @param mount A Mount that was removed.
   */

  auto signal_mount_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_pre_unmount(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Flags: Run Last
   *
   * May be emitted when a mount is about to be removed.
   *
   * This signal depends on the backend and is only emitted if
   * GIO was used to unmount.
   *
   * @param mount A Mount that is being unmounted.
   */

  auto signal_mount_pre_unmount() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%mount_changed(const Glib::RefPtr<Mount>& mount)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a mount changes.
   *
   * @param mount A Mount that changed.
   */

  auto signal_mount_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_connected(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a drive is connected to the system.
   *
   * @param drive A Drive that was connected.
   */

  auto signal_drive_connected() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_disconnected(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a drive is disconnected from the system.
   *
   * @param drive A Drive that was disconnected.
   */

  auto signal_drive_disconnected() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_changed(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when a drive changes.
   *
   * @param drive The drive that changed.
   */

  auto signal_drive_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_eject_button(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the eject button is pressed on @a drive.
   *
   * @newin{2,18}
   *
   * @param drive The drive where the eject button was pressed.
   */

  auto signal_drive_eject_button() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%drive_stop_button(const Glib::RefPtr<Drive>& drive)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the stop button is pressed on @a drive.
   *
   * @newin{2,22}
   *
   * @param drive The drive where the stop button was pressed.
   */

  auto signal_drive_stop_button() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>;


protected:
  //TODO: Use ListHandler?
  //_WRAP_VFUNC(GList* get_volumes(), get_volumes)
  //_WRAP_VFUNC(GList* get_mounts(), get_mounts)


  //_WRAP_VFUNC(Glib::RefPtr<Volume> get_volume_for_uuid(const std::string& uuid), get_volume_for_uuid)


  //_WRAP_VFUNC(Glib::RefPtr<Mount> get_mount_for_uuid(const std::string& uuid), get_mount_for_uuid)

  //There are no properties.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_volume_added().
  virtual void on_volume_added(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_volume_removed().
  virtual void on_volume_removed(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_volume_changed().
  virtual void on_volume_changed(const Glib::RefPtr<Volume>& volume);
  /// This is a default handler for the signal signal_mount_added().
  virtual void on_mount_added(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_removed().
  virtual void on_mount_removed(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_pre_unmount().
  virtual void on_mount_pre_unmount(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_mount_changed().
  virtual void on_mount_changed(const Glib::RefPtr<Mount>& mount);
  /// This is a default handler for the signal signal_drive_connected().
  virtual void on_drive_connected(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_disconnected().
  virtual void on_drive_disconnected(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_changed().
  virtual void on_drive_changed(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_eject_button().
  virtual void on_drive_eject_button(const Glib::RefPtr<Drive>& drive);
  /// This is a default handler for the signal signal_drive_stop_button().
  virtual void on_drive_stop_button(const Glib::RefPtr<Drive>& drive);


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::VolumeMonitor
   */
  GIOMM_API
  auto wrap(GVolumeMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::VolumeMonitor>;
}


#endif /* _GIOMM_VOLUMEMONITOR_H */

