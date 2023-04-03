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
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT VolumeMonitor_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT VolumeMonitor : public Glib::Object
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
    explicit VolumeMonitor (const Glib::ConstructParams& construct_params);
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
    get () -> Glib::RefPtr<VolumeMonitor>;

    auto
    get_connected_drives () -> std::vector<Glib::RefPtr<Drive>>;

    auto
    get_volumes () -> std::vector<Glib::RefPtr<Volume>>;

    auto
    get_mounts () -> std::vector<Glib::RefPtr<Mount>>;

    auto
    get_volume_for_uuid (const std::string& uuid) -> Glib::RefPtr<Volume>;

    auto
    get_mount_for_uuid (const std::string& uuid) -> Glib::RefPtr<Mount>;

    auto
    signal_volume_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Volume>&)>;

    auto
    signal_volume_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Volume>&)>;

    auto
    signal_volume_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Volume>&)>;

    auto
    signal_mount_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Mount>&)>;

    auto
    signal_mount_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Mount>&)>;

    auto
    signal_mount_pre_unmount ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Mount>&)>;

    auto
    signal_mount_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Mount>&)>;

    auto
    signal_drive_connected ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Drive>&)>;

    auto
    signal_drive_disconnected ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Drive>&)>;

    auto
    signal_drive_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Drive>&)>;

    auto
    signal_drive_eject_button ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Drive>&)>;

    auto
    signal_drive_stop_button ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Drive>&)>;

  protected:
  public:
  public:
  protected:
    virtual auto
    on_volume_added (const Glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_volume_removed (const Glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_volume_changed (const Glib::RefPtr<Volume>& volume) -> void;

    virtual auto
    on_mount_added (const Glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_removed (const Glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_pre_unmount (const Glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_mount_changed (const Glib::RefPtr<Mount>& mount) -> void;

    virtual auto
    on_drive_connected (const Glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_disconnected (const Glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_changed (const Glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_eject_button (const Glib::RefPtr<Drive>& drive) -> void;

    virtual auto
    on_drive_stop_button (const Glib::RefPtr<Drive>& drive) -> void;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GVolumeMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::VolumeMonitor>;
} // namespace Glib

#endif
