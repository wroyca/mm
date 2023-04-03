// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_VOLUME_H
#define _GIOMM_VOLUME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/file.hxx>
#include <libmm/gio/mount.hxx>
#include <libmm/gio/mountoperation.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GVolumeIface GGVolumeIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GVolume = struct _GVolume;
using GVolumeClass = struct _GVolumeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Volume_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT File;
  class LIBMM_GIO_SYMEXPORT Drive;

  class LIBMM_GIO_SYMEXPORT Volume : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Volume;
    using CppClassType = Volume_Class;
    using BaseObjectType = GVolume;
    using BaseClassType = GVolumeIface;

    Volume (const Volume&) = delete;
    auto
    operator= (const Volume&) -> Volume& = delete;

  private:
    friend class Volume_Class;
    static CppClassType volume_class_;

#endif
  protected:
    Volume ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Volume (const Glib::Interface_Class& interface_class);

  public:
    explicit Volume (GVolume* castitem);

  protected:
#endif

  public:
    Volume (Volume&& src) noexcept;
    auto
    operator= (Volume&& src) noexcept -> Volume&;

    ~Volume () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GVolume*
    {
      return reinterpret_cast<GVolume*> (gobject_);
    }

    auto
    gobj () const -> const GVolume*
    {
      return reinterpret_cast<GVolume*> (gobject_);
    }

  private:
  public:
    auto
    get_name () const -> std::string;

    auto
    get_uuid () const -> std::string;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> Glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_drive () -> Glib::RefPtr<Drive>;

    auto
    get_drive () const -> Glib::RefPtr<const Drive>;

    auto
    get_mount () -> Glib::RefPtr<Mount>;

    auto
    get_mount () const -> Glib::RefPtr<const Mount>;

    auto
    can_mount () const -> bool;

    auto
    can_eject () const -> bool;

    auto
    should_automount () const -> bool;

    auto
    mount (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount (const Glib::RefPtr<MountOperation>& mount_operation,
           Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount (Mount::MountFlags flags = Mount::MountFlags::NONE) -> void;

    auto
    mount_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    eject (const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const SlotAsyncReady& slot,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_identifier (const std::string& kind) const -> std::string;

    auto
    enumerate_identifiers () const -> std::vector<Glib::ustring>;

    auto
    get_activation_root () -> Glib::RefPtr<File>;

    auto
    get_activation_root () const -> Glib::RefPtr<const File>;

    auto
    sort_key () -> Glib::ustring;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_removed () -> Glib::SignalProxy<void ()>;

  protected:
  public:
  public:
  protected:
    virtual auto
    on_changed () -> void;

    virtual auto
    on_removed () -> void;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GVolume* object, bool take_copy) -> Glib::RefPtr<Gio::Volume>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<Glib::RefPtr<Gio::Volume>>
    {
      using CppType = Glib::RefPtr<Gio::Volume>;
      using CType = GVolume*;
      using CTypeNonConst = GVolume*;

      static auto
      to_c_type (const CppType& item) -> CType
      {
        return Glib::unwrap (item);
      }

      static auto
      to_cpp_type (const CType& item) -> CppType
      {
        return Glib::wrap (item, true);
      }

      static auto
      release_c_type (CType item) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, item);
        g_object_unref (item);
      }
    };

  } // namespace Container_Helpers
} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GVolume* object, bool take_copy = false) -> Glib::RefPtr<Gio::Volume>;

} // namespace Glib

#endif
