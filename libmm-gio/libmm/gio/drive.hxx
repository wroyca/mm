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
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Drive_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Drive : public Glib::Interface
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

    explicit Drive (const Glib::Interface_Class& interface_class);

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
    get_name () const -> Glib::ustring;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> Glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> Glib::RefPtr<const Icon>;

    auto
    has_volumes () const -> bool;

    auto
    get_volumes () -> std::vector<Glib::RefPtr<Volume>>;

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
           const Glib::RefPtr<Cancellable>& cancellable,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject (const SlotAsyncReady& slot,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
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
    eject (Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    eject_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    poll_for_media (const SlotAsyncReady& slot,
                    const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    poll_for_media (const SlotAsyncReady& slot) -> void;

    auto
    poll_for_media () -> void;

    auto
    poll_for_media_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_identifier (const std::string& kind) const -> std::string;

    auto
    enumerate_identifiers () const -> std::vector<Glib::ustring>;

    auto
    start (const Glib::RefPtr<MountOperation>& mount_operation,
           const Glib::RefPtr<Cancellable>& cancellable,
           const SlotAsyncReady& slot,
           StartFlags flags = StartFlags::NONE) -> void;

    auto
    start (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           StartFlags flags = StartFlags::NONE) -> void;

    auto
    start_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    can_start () const -> bool;

    auto
    can_start_degraded () const -> bool;

    auto
    stop (const Glib::RefPtr<MountOperation>& mount_operation,
          const Glib::RefPtr<Cancellable>& cancellable,
          const SlotAsyncReady& slot,
          Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    stop (const Glib::RefPtr<MountOperation>& mount_operation,
          const SlotAsyncReady& slot,
          Mount::UnmountFlags flags = Mount::UnmountFlags::NONE) -> void;

    auto
    stop_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    can_stop () const -> bool;

    auto
    get_start_stop_type () const -> StartStopType;

    auto
    get_sort_key () const -> Glib::ustring;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_disconnected () -> Glib::SignalProxy<void ()>;

    auto
    signal_eject_button () -> Glib::SignalProxy<void ()>;

    auto
    signal_stop_button () -> Glib::SignalProxy<void ()>;

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

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDrive* object, bool take_copy) -> Glib::RefPtr<Gio::Drive>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<Glib::RefPtr<Gio::Drive>>
    {
      using CppType = Glib::RefPtr<Gio::Drive>;
      using CType = GDrive*;
      using CTypeNonConst = GDrive*;

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

namespace Gio
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
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Drive::StartFlags>
    : public Glib::Value_Flags<Gio::Drive::StartFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Drive::StartStopType>
    : public Glib::Value_Enum<Gio::Drive::StartStopType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDrive* object, bool take_copy = false) -> Glib::RefPtr<Gio::Drive>;

} // namespace Glib

#endif
