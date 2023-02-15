// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MOUNT_H
#define _GIOMM_MOUNT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/mountoperation.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GMountIface GMountIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMount = struct _GMount;
using GMountClass = struct _GMountClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Mount_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT File;
  class LIBMM_GIO_SYMEXPORT Drive;
  class LIBMM_GIO_SYMEXPORT Volume;

  class LIBMM_GIO_SYMEXPORT Mount : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Mount;
    using CppClassType = Mount_Class;
    using BaseObjectType = GMount;
    using BaseClassType = GMountIface;

    Mount (const Mount&) = delete;
    auto
    operator= (const Mount&) -> Mount& = delete;

  private:
    friend class Mount_Class;
    static CppClassType mount_class_;

#endif
  protected:
    Mount ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Mount (const Glib::Interface_Class& interface_class);

  public:
    explicit Mount (GMount* castitem);

  protected:
#endif

  public:
    Mount (Mount&& src) noexcept;
    auto
    operator= (Mount&& src) noexcept -> Mount&;

    ~Mount () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMount*
    {
      return reinterpret_cast<GMount*> (gobject_);
    }

    auto
    gobj () const -> const GMount*
    {
      return reinterpret_cast<GMount*> (gobject_);
    }

  private:
  public:
    enum class UnmountFlags
    {
      NONE = 0x0,
      FORCE = (1 << 0)
    };

    enum class MountFlags
    {
      NONE = 0x0
    };

    auto
    get_root () -> Glib::RefPtr<File>;

    auto
    get_root () const -> Glib::RefPtr<const File>;

    auto
    get_name () const -> std::string;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> Glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_uuid () const -> std::string;

    auto
    get_volume () -> Glib::RefPtr<Volume>;

    auto
    get_volume () const -> Glib::RefPtr<const Volume>;

    auto
    get_drive () -> Glib::RefPtr<Drive>;

    auto
    get_drive () const -> Glib::RefPtr<const Drive>;

    auto
    can_unmount () const -> bool;

    auto
    can_eject () const -> bool;

    auto
    unmount (const SlotAsyncReady& slot,
             const Glib::RefPtr<Cancellable>& cancellable,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const SlotAsyncReady& slot,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const Glib::RefPtr<MountOperation>& mount_operation,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const Glib::RefPtr<MountOperation>& mount_operation,
             const SlotAsyncReady& slot,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const Glib::RefPtr<MountOperation>& mount_operation,
             const SlotAsyncReady& slot,
             const Glib::RefPtr<Cancellable>& cancellable,
             UnmountFlags flags = UnmountFlags::NONE) -> void;

    auto
    unmount_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    remount (const Glib::RefPtr<MountOperation>& operation,
             const SlotAsyncReady& slot,
             const Glib::RefPtr<Cancellable>& cancellable,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (const Glib::RefPtr<MountOperation>& operation,
             const SlotAsyncReady& slot,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (const Glib::RefPtr<MountOperation>& operation,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    eject (const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE)
        -> void;
    auto
    eject (UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           const Glib::RefPtr<Cancellable>& cancellable,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const Glib::RefPtr<MountOperation>& mount_operation,
           UnmountFlags flags = UnmountFlags::NONE) -> void;

    auto
    eject_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    guess_content_type (const SlotAsyncReady& slot,
                        const Glib::RefPtr<Cancellable>& cancellable,
                        bool force_rescan = true) -> void;

    auto
    guess_content_type (const SlotAsyncReady& slot, bool force_rescan = true)
        -> void;

    auto
    guess_content_type (bool force_rescan = true) -> void;

    auto
    guess_content_type_sync (const Glib::RefPtr<Cancellable>& cancellable,
                             bool force_rescan = true) -> void;
    auto
    guess_content_type_sync (bool force_rescan = true) -> void;

    auto
    guess_content_type_finish (const Glib::RefPtr<AsyncResult>& result)
        -> std::vector<Glib::ustring>;

    auto
    is_shadowed () const -> bool;

    auto
    shadow () -> void;

    auto
    unshadow () -> void;

    auto
    get_default_location () const -> Glib::RefPtr<File>;

    auto
    get_sort_key () const -> Glib::ustring;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_unmounted () -> Glib::SignalProxy<void ()>;

    auto
    signal_pre_unmount () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_changed () -> void;

    virtual auto
    on_unmounted () -> void;

    virtual auto
    on_pre_unmount () -> void;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMount* object, bool take_copy) -> Glib::RefPtr<Gio::Mount>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<Glib::RefPtr<Gio::Mount>>
    {
      using CppType = Glib::RefPtr<Gio::Mount>;
      using CType = GMount*;
      using CTypeNonConst = GMount*;

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
  operator| (Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  {
    return static_cast<Mount::UnmountFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  {
    return static_cast<Mount::UnmountFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Mount::UnmountFlags lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags
  {
    return static_cast<Mount::UnmountFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Mount::UnmountFlags flags) -> Mount::UnmountFlags
  {
    return static_cast<Mount::UnmountFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  {
    return (lhs = static_cast<Mount::UnmountFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  {
    return (lhs = static_cast<Mount::UnmountFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Mount::UnmountFlags& lhs, Mount::UnmountFlags rhs) -> Mount::UnmountFlags&
  {
    return (lhs = static_cast<Mount::UnmountFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Gio
{

  inline auto
  operator| (Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  {
    return static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  {
    return static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Mount::MountFlags lhs, Mount::MountFlags rhs) -> Mount::MountFlags
  {
    return static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Mount::MountFlags flags) -> Mount::MountFlags
  {
    return static_cast<Mount::MountFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  {
    return (lhs = static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  {
    return (lhs = static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Mount::MountFlags& lhs, Mount::MountFlags rhs) -> Mount::MountFlags&
  {
    return (lhs = static_cast<Mount::MountFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }
} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMount* object, bool take_copy = false) -> Glib::RefPtr<Gio::Mount>;

} // namespace Glib

#endif
