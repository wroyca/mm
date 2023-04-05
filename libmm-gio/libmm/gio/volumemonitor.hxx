// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_VOLUMEMONITOR_H
#define _GIOMM_VOLUMEMONITOR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/drive.hxx>
#include <libmm/gio/mount.hxx>
#include <libmm/gio/volume.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GVolumeMonitor = struct _GVolumeMonitor;
using GVolumeMonitorClass = struct _GVolumeMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT VolumeMonitor_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT VolumeMonitor : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = VolumeMonitor;
    using CppClassType = VolumeMonitor_Class;
    using BaseObjectType = GVolumeMonitor;
    using BaseClassType = GVolumeMonitorClass;

    VolumeMonitor (const VolumeMonitor&) = delete;
    auto
    operator= (const VolumeMonitor&) -> VolumeMonitor& = delete;

  private:
    friend class VolumeMonitor_Class;
    static CppClassType volumemonitor_class_;

  protected:
    explicit VolumeMonitor (const glib::ConstructParams& construct_params);
    explicit VolumeMonitor (GVolumeMonitor* castitem);

#endif

  public:
    VolumeMonitor (VolumeMonitor&& src) noexcept;
    auto
    operator= (VolumeMonitor&& src) noexcept -> VolumeMonitor&;

    ~VolumeMonitor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GVolumeMonitor*
    {
      return reinterpret_cast<GVolumeMonitor*> (gobject_);
    }

    auto
    gobj () const -> const GVolumeMonitor*
    {
      return reinterpret_cast<GVolumeMonitor*> (gobject_);
    }

    auto
    gobj_copy () -> GVolumeMonitor*;

  private:
  protected:
  public:
    static auto
    get () -> glib::RefPtr<VolumeMonitor>;

    auto
    get_connected_drives () -> std::vector<glib::RefPtr<Drive>>;

    auto
    get_volumes () -> std::vector<glib::RefPtr<Volume>>;

    auto
    get_mounts () -> std::vector<glib::RefPtr<Mount>>;

    auto
    get_volume_for_uuid (const std::string& uuid) -> glib::RefPtr<Volume>;

    auto
    get_mount_for_uuid (const std::string& uuid) -> glib::RefPtr<Mount>;

    auto
    signal_volume_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>;

    auto
    signal_volume_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>;

    auto
    signal_volume_changed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>;

    auto
    signal_mount_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>;

    auto
    signal_mount_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>;

    auto
    signal_mount_pre_unmount ()
        -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>;

    auto
    signal_mount_changed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>;

    auto
    signal_drive_connected ()
        -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>;

    auto
    signal_drive_disconnected ()
        -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>;

    auto
    signal_drive_changed ()
        -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>;

    auto
    signal_drive_eject_button ()
        -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>;

    auto
    signal_drive_stop_button ()
        -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>;

  protected:
  public:
  public:
  protected:
    virtual auto
    on_volume_added (const glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_volume_removed (const glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_volume_changed (const glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_mount_added (const glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_removed (const glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_pre_unmount (const glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_changed (const glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_drive_connected (const glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_disconnected (const glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_changed (const glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_eject_button (const glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_stop_button (const glib::RefPtr<Drive>& drive) -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GVolumeMonitor* object, bool take_copy = false) -> glib::RefPtr<gio::VolumeMonitor>;
} // namespace glib

#endif
