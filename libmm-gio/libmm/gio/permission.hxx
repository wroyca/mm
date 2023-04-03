// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_PERMISSION_H
#define _GIOMM_PERMISSION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPermission = struct _GPermission;
using GPermissionClass = struct _GPermissionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Permission_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Permission : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Permission;
    using CppClassType = Permission_Class;
    using BaseObjectType = GPermission;
    using BaseClassType = GPermissionClass;

    Permission (const Permission&) = delete;
    auto
    operator= (const Permission&) -> Permission& = delete;

  private:
    friend class Permission_Class;
    static CppClassType permission_class_;

  protected:
    explicit Permission (const Glib::ConstructParams& construct_params);
    explicit Permission (GPermission* castitem);

#endif

  public:
    Permission (Permission&& src) noexcept;
    auto
    operator= (Permission&& src) noexcept -> Permission&;

    ~Permission () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GPermission*
    {
      return reinterpret_cast<GPermission*> (gobject_);
    }

    auto
    gobj () const -> const GPermission*
    {
      return reinterpret_cast<GPermission*> (gobject_);
    }

    auto
    gobj_copy () -> GPermission*;

  private:
  public:
    auto
    acquire (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    acquire () -> bool;

    auto
    acquire_async (const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    acquire_async (const SlotAsyncReady& slot) -> void;

    auto
    acquire_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    release (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    release () -> bool;

    auto
    release_async (const SlotAsyncReady& slot,
                   const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    release_async (const SlotAsyncReady& slot) -> void;

    auto
    release_finish (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    get_allowed () const -> bool;

    auto
    get_can_acquire () const -> bool;

    auto
    get_can_release () const -> bool;

    auto
    property_allowed () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_acquire () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_release () const -> Glib::PropertyProxy_ReadOnly<bool>;

  protected:
    Permission ();

    virtual auto
    acquire_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    virtual auto
    acquire_async_vfunc (const SlotAsyncReady& slot,
                         const Glib::RefPtr<Cancellable>& cancellable) -> void;

    virtual auto
    acquire_finish_vfunc (const Glib::RefPtr<AsyncResult>& result) -> bool;

    virtual auto
    release_vfunc (const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    virtual auto
    release_async_vfunc (const SlotAsyncReady& slot,
                         const Glib::RefPtr<Cancellable>& cancellable) -> void;

    virtual auto
    release_finish_vfunc (const Glib::RefPtr<AsyncResult>& result) -> bool;

    auto
    impl_update (bool allowed, bool can_acquire, bool can_release) -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GPermission* object, bool take_copy = false) -> Glib::RefPtr<Gio::Permission>;
} // namespace Glib

#endif
