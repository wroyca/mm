// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MOUNT_H
#define _GIOMM_MOUNT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gio/mountoperation.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GMountIface GMountIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMount = struct _GMount;
using GMountClass = struct _GMountClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Mount_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT File;
  class LIBMM_GIO_SYMEXPORT Drive;
  class LIBMM_GIO_SYMEXPORT Volume;

  class LIBMM_GIO_SYMEXPORT Mount : public glib::Interface
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

    explicit Mount (const glib::Interface_Class& interface_class);

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
    get_root () -> glib::RefPtr<File>;

    auto
    get_root () const -> glib::RefPtr<const File>;

    auto
    get_name () const -> std::string;

    auto
    get_icon () -> glib::RefPtr<Icon>;

    auto
    get_icon () const -> glib::RefPtr<const Icon>;

    auto
    get_symbolic_icon () -> glib::RefPtr<Icon>;

    auto
    get_symbolic_icon () const -> glib::RefPtr<const Icon>;

    auto
    get_uuid () const -> std::string;

    auto
    get_volume () -> glib::RefPtr<Volume>;

    auto
    get_volume () const -> glib::RefPtr<const Volume>;

    auto
    get_drive () -> glib::RefPtr<Drive>;

    auto
    get_drive () const -> glib::RefPtr<const Drive>;

    auto
    can_unmount () const -> bool;

    auto
    can_eject () const -> bool;

    auto
    unmount (const SlotAsyncReady& slot,
             const glib::RefPtr<Cancellable>& cancellable,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const SlotAsyncReady& slot,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const glib::RefPtr<MountOperation>& mount_operation,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const glib::RefPtr<MountOperation>& mount_operation,
             const SlotAsyncReady& slot,
             UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    unmount (const glib::RefPtr<MountOperation>& mount_operation,
             const SlotAsyncReady& slot,
             const glib::RefPtr<Cancellable>& cancellable,
             UnmountFlags flags = UnmountFlags::NONE) -> void;

    auto
    unmount_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    remount (const glib::RefPtr<MountOperation>& operation,
             const SlotAsyncReady& slot,
             const glib::RefPtr<Cancellable>& cancellable,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (const glib::RefPtr<MountOperation>& operation,
             const SlotAsyncReady& slot,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (const glib::RefPtr<MountOperation>& operation,
             MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount (MountFlags flags = MountFlags::NONE) -> void;

    auto
    remount_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    eject (const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const SlotAsyncReady& slot, UnmountFlags flags = UnmountFlags::NONE)
        -> void;
    auto
    eject (UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           const glib::RefPtr<Cancellable>& cancellable,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           const SlotAsyncReady& slot,
           UnmountFlags flags = UnmountFlags::NONE) -> void;
    auto
    eject (const glib::RefPtr<MountOperation>& mount_operation,
           UnmountFlags flags = UnmountFlags::NONE) -> void;

    auto
    eject_finish (const glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    guess_content_type (const SlotAsyncReady& slot,
                        const glib::RefPtr<Cancellable>& cancellable,
                        bool force_rescan = true) -> void;

    auto
    guess_content_type (const SlotAsyncReady& slot, bool force_rescan = true)
        -> void;

    auto
    guess_content_type (bool force_rescan = true) -> void;

    auto
    guess_content_type_sync (const glib::RefPtr<Cancellable>& cancellable,
                             bool force_rescan = true) -> void;
    auto
    guess_content_type_sync (bool force_rescan = true) -> void;

    auto
    guess_content_type_finish (const glib::RefPtr<AsyncResult>& result)
        -> std::vector<glib::ustring>;

    auto
    is_shadowed () const -> bool;

    auto
    shadow () -> void;

    auto
    unshadow () -> void;

    auto
    get_default_location () const -> glib::RefPtr<File>;

    auto
    get_sort_key () const -> glib::ustring;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_unmounted () -> glib::SignalProxy<void ()>;

    auto
    signal_pre_unmount () -> glib::SignalProxy<void ()>;

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

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMount* object, bool take_copy) -> glib::RefPtr<gio::Mount>;

  namespace Container_Helpers
  {

    template <>
    struct TypeTraits<glib::RefPtr<gio::Mount>>
    {
      using CppType = glib::RefPtr<gio::Mount>;
      using CType = GMount*;
      using CTypeNonConst = GMount*;

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
} // namespace gio

namespace gio
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
} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMount* object, bool take_copy = false) -> glib::RefPtr<gio::Mount>;

} // namespace glib

#endif
