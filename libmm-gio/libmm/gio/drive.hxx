// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DRIVE_H
#define _GIOMM_DRIVE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/icon.hxx>
#include <libmm/gio/mount.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDriveIface GDriveIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDrive = struct _GDrive;
using GDriveClass = struct _GDriveClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Drive_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Drive : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Drive;
    using CppClassType = Drive_Class;
    using BaseObjectType = GDrive;
    using BaseClassType = GDriveIface;

    Drive (const Drive&) = delete;
    auto
    operator= (const Drive&) -> Drive& = delete;

  private:
    friend class Drive_Class;
    static CppClassType drive_class_;

#endif
  protected:
    Drive ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Drive (const glib::Interface_Class& interface_class);

  public:
    explicit Drive (GDrive* castitem);

  protected:
#endif

  public:
    Drive (Drive&& src) noexcept;
    auto
    operator= (Drive&& src) noexcept -> Drive&;

    ~Drive () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDrive*
    {
      return reinterpret_cast<GDrive*> (gobject_);
    }

    auto
    gobj () const -> const GDrive*
    {
      return reinterpret_cast<GDrive*> (gobject_);
    }

  private:
  public:
    enum class StartFlags
    {
      NONE = 0x0
    };

    enum class StartStopType
    {
      UNKNOWN,
      SHUTDOWN,
      NETWORK,
      MULTIDISK,
      PASSWORD
    };

    auto
    get_name () const -> glib::ustring;

    auto
    get_icon () -> glib::RefPtr<Icon>;

    auto
    get_icon () const -> glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> glib::RefPtr<const Icon>;

    auto
    has_volumes () const -> bool;

    auto
    get_volumes () -> std::vector<glib::RefPtr<Volume>>;

    auto
    is_media_removable () const -> bool;

    auto
    is_removable () const -> bool;

    auto
    has_media () const -> bool;

    auto
    is_media_check_automatic () const -> bool;

    auto
    can_poll_for_media () const -> bool;

    auto
    can_eject () const -> bool;

    auto
    eject (const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject (const SlotAsyncReady& slot,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject (Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    poll_for_media (const SlotAsyncReady& slot,
                    const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    poll_for_media (const SlotAsyncReady& slot) -> void;

    auto
    poll_for_media () -> void;

    auto
    poll_for_media_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_identifier (const std::string& kind) const -> std::string;

    auto
    enumerate_identifiers () const -> std::vector<glib::ustring>;

    auto
    start (const glib::RefPtr<MountOperation>& mount_operation,
           const glib::RefPtr<Cancellable>& cancellable,
           const SlotAsyncReady& slot,
           StartFlags flags = StartFlags::NONE) -> void;

    auto
    start (const glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           StartFlags flags = StartFlags::NONE) -> void;

    auto
    start_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    can_start () const -> bool;

    auto
    can_start_degraded () const -> bool;

    auto
    stop (const glib::RefPtr<MountOperation>& mount_operation,
          const glib::RefPtr<Cancellable>& cancellable,
          const SlotAsyncReady& slot,
          Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    stop (const glib::RefPtr<MountOperation>& mount_operation,
          const SlotAsyncReady& slot,
          Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    stop_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    can_stop () const -> bool;

    auto
    get_start_stop_type () const -> StartStopType;

    auto
    get_sort_key () const -> glib::ustring;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_disconnected () -> glib::SignalProxy<void ()>;

    auto
    signal_eject_button () -> glib::SignalProxy<void ()>;

    auto
    signal_stop_button () -> glib::SignalProxy<void ()>;

  protected:
  public:
  public:
  protected:
    virtual auto
    on_changed () -> void;

    virtual auto
    on_disconnected () -> void;

    virtual auto
    on_eject_button () -> void;

    virtual auto
    on_stop_button () -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDrive* object, bool take_copy) -> glib::RefPtr<gio::Drive>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<glib::RefPtr<gio::Drive>>
    {
      using CppType = glib::RefPtr<gio::Drive>;
      using CType = GDrive*;
      using CTypeNonConst = GDrive*;

      static auto
      to_c_type (const CppType& item) -> CType
      {
        return glib::unwrap (item);
      }

      static auto
      to_cpp_type (const CType& item) -> CppType
      {
        return glib::wrap (item, true);
      }

      static auto
      release_c_type (CType item) -> void
      {
        GLIBMM_DEBUG_UNREFERENCE (nullptr, item);
        g_object_unref (item);
      }
    };

  } // namespace Container_Helpers
} // namespace glib

namespace gio
{

  inline auto
  operator| (Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  {
    return static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  {
    return static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Drive::StartFlags lhs, Drive::StartFlags rhs) -> Drive::StartFlags
  {
    return static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Drive::StartFlags flags) -> Drive::StartFlags
  {
    return static_cast<Drive::StartFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  {
    return (lhs = static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  {
    return (lhs = static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Drive::StartFlags& lhs, Drive::StartFlags rhs) -> Drive::StartFlags&
  {
    return (lhs = static_cast<Drive::StartFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }
} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Drive::StartFlags>
    : public glib::Value_Flags<gio::Drive::StartFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Drive::StartStopType>
    : public glib::Value_Enum<gio::Drive::StartStopType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDrive* object, bool take_copy = false) -> glib::RefPtr<gio::Drive>;

} // namespace glib

#endif
