// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/mount.hxx>
#include <libmm/gio/mount_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/drive.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/gio/volume.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  auto
  Mount::unmount (const SlotAsyncReady& slot,
                  const glib::RefPtr<Cancellable>& cancellable,
                  UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    nullptr,
                                    glib::unwrap (cancellable),
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  Mount::unmount (const SlotAsyncReady& slot, UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    nullptr,
                                    nullptr,
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  Mount::unmount (UnmountFlags flags) -> void
  {
    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    nullptr,
                                    nullptr,
                                    nullptr,
                                    nullptr);
  }

  auto
  Mount::unmount (const glib::RefPtr<MountOperation>& mount_operation,
                  const SlotAsyncReady& slot,
                  const glib::RefPtr<Cancellable>& cancellable,
                  UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    glib::unwrap (mount_operation),
                                    glib::unwrap (cancellable),
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  Mount::unmount (const glib::RefPtr<MountOperation>& mount_operation,
                  const SlotAsyncReady& slot,
                  UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    glib::unwrap (mount_operation),
                                    nullptr,
                                    &SignalProxy_async_callback,
                                    slot_copy);
  }

  auto
  Mount::unmount (const glib::RefPtr<MountOperation>& mount_operation,
                  UnmountFlags flags) -> void
  {
    g_mount_unmount_with_operation (gobj (),
                                    GMountUnmountFlags (flags),
                                    glib::unwrap (mount_operation),
                                    nullptr,
                                    nullptr,
                                    nullptr);
  }

  auto
  Mount::remount (const glib::RefPtr<MountOperation>& operation,
                  const SlotAsyncReady& slot,
                  const glib::RefPtr<Cancellable>& cancellable,
                  MountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_remount (gobj (),
                     static_cast<GMountMountFlags> (flags),
                     glib::unwrap (operation),
                     glib::unwrap (cancellable),
                     &SignalProxy_async_callback,
                     slot_copy);
  }

  auto
  Mount::remount (const glib::RefPtr<MountOperation>& operation,
                  const SlotAsyncReady& slot,
                  MountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_remount (gobj (),
                     static_cast<GMountMountFlags> (flags),
                     glib::unwrap (operation),
                     nullptr,
                     &SignalProxy_async_callback,
                     slot_copy);
  }

  auto
  Mount::remount (const glib::RefPtr<MountOperation>& operation,
                  MountFlags flags) -> void
  {
    g_mount_remount (gobj (),
                     static_cast<GMountMountFlags> (flags),
                     glib::unwrap (operation),
                     nullptr,
                     nullptr,
                     nullptr);
  }

  auto
  Mount::remount (MountFlags flags) -> void
  {
    g_mount_remount (gobj (),
                     static_cast<GMountMountFlags> (flags),
                     nullptr,
                     nullptr,
                     nullptr,
                     nullptr);
  }

  auto
  Mount::eject (const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  nullptr,
                                  glib::unwrap (cancellable),
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  Mount::eject (const SlotAsyncReady& slot, UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  nullptr,
                                  nullptr,
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  Mount::eject (UnmountFlags flags) -> void
  {
    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  nullptr,
                                  nullptr,
                                  nullptr,
                                  nullptr);
  }

  auto
  Mount::eject (const glib::RefPtr<MountOperation>& mount_operation,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  glib::unwrap (mount_operation),
                                  glib::unwrap (cancellable),
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  Mount::eject (const glib::RefPtr<MountOperation>& mount_operation,
                const SlotAsyncReady& slot,
                UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  glib::unwrap (mount_operation),
                                  nullptr,
                                  &SignalProxy_async_callback,
                                  slot_copy);
  }

  auto
  Mount::eject (const glib::RefPtr<MountOperation>& mount_operation,
                UnmountFlags flags) -> void
  {
    g_mount_eject_with_operation (gobj (),
                                  GMountUnmountFlags (flags),
                                  glib::unwrap (mount_operation),
                                  nullptr,
                                  nullptr,
                                  nullptr);
  }

  auto
  Mount::guess_content_type (const SlotAsyncReady& slot,
                             const glib::RefPtr<Cancellable>& cancellable,
                             const bool force_rescan) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_guess_content_type (gobj (),
                                force_rescan,
                                glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Mount::guess_content_type (const SlotAsyncReady& slot,
                             const bool force_rescan) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_mount_guess_content_type (gobj (),
                                force_rescan,
                                nullptr,
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  Mount::guess_content_type (const bool force_rescan) -> void
  {
    g_mount_guess_content_type (gobj (),
                                force_rescan,
                                nullptr,
                                nullptr,
                                nullptr);
  }

  auto
  Mount::guess_content_type_sync (const glib::RefPtr<Cancellable>& cancellable,
                                  const bool force_rescan) -> void
  {
    GError* gerror = nullptr;
    g_mount_guess_content_type_sync (gobj (),
                                     force_rescan,
                                     glib::unwrap (cancellable),
                                     &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  Mount::guess_content_type_sync (const bool force_rescan) -> void
  {
    GError* gerror = nullptr;
    g_mount_guess_content_type_sync (gobj (), force_rescan, nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

} // namespace gio

namespace
{

  const glib::SignalProxyInfo Mount_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  const glib::SignalProxyInfo Mount_signal_unmounted_info = {
      "unmounted",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  const glib::SignalProxyInfo Mount_signal_pre_unmount_info = {
      "pre_unmount",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GMount* object, const bool take_copy) -> RefPtr<gio::Mount>
  {
    return glib::make_refptr_for_instance<gio::Mount> (
        glib::wrap_auto_interface<gio::Mount> ((GObject*) object, take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  Mount_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Mount_Class::iface_init_function;

      gtype_ = g_mount_get_type ();
    }

    return *this;
  }

  auto
  Mount_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->changed = &changed_callback;
    klass->unmounted = &unmounted_callback;
    klass->pre_unmount = &pre_unmount_callback;
  }

  auto
  Mount_Class::changed_callback (GMount* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  Mount_Class::unmounted_callback (GMount* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_unmounted ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->unmounted)
      (*base->unmounted) (self);
  }

  auto
  Mount_Class::pre_unmount_callback (GMount* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_pre_unmount ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->pre_unmount)
      (*base->pre_unmount) (self);
  }

  auto
  Mount_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Mount ((GMount*) object);
  }

  Mount::Mount ()
    : Interface (mount_class_.init ())
  {
  }

  Mount::Mount (GMount* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Mount::Mount (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Mount::Mount (Mount&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Mount::operator= (Mount&& src) noexcept -> Mount&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Mount::~Mount () noexcept = default;

  auto
  Mount::add_interface (const GType gtype_implementer) -> void
  {
    mount_class_.init ().add_interface (gtype_implementer);
  }

  Mount::CppClassType Mount::mount_class_;

  auto
  Mount::get_type () -> GType
  {
    return mount_class_.init ().get_type ();
  }

  auto
  Mount::get_base_type () -> GType
  {
    return g_mount_get_type ();
  }

  auto
  Mount::get_root () -> glib::RefPtr<File>
  {
    auto retvalue = glib::wrap (g_mount_get_root (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Mount::get_root () const -> glib::RefPtr<const File>
  {
    return const_cast<Mount*> (this)->get_root ();
  }

  auto
  Mount::get_name () const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_mount_get_name (const_cast<GMount*> (gobj ())));
  }

  auto
  Mount::get_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_mount_get_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Mount::get_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<Mount*> (this)->get_icon ();
  }

  auto
  Mount::get_symbolic_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_mount_get_symbolic_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Mount::get_symbolic_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<Mount*> (this)->get_symbolic_icon ();
  }

  auto
  Mount::get_uuid () const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_mount_get_uuid (const_cast<GMount*> (gobj ())));
  }

  auto
  Mount::get_volume () -> glib::RefPtr<Volume>
  {
    auto retvalue = glib::wrap (g_mount_get_volume (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Mount::get_volume () const -> glib::RefPtr<const Volume>
  {
    return const_cast<Mount*> (this)->get_volume ();
  }

  auto
  Mount::get_drive () -> glib::RefPtr<Drive>
  {
    auto retvalue = glib::wrap (g_mount_get_drive (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Mount::get_drive () const -> glib::RefPtr<const Drive>
  {
    return const_cast<Mount*> (this)->get_drive ();
  }

  auto
  Mount::can_unmount () const -> bool
  {
    return g_mount_can_unmount (const_cast<GMount*> (gobj ()));
  }

  auto
  Mount::can_eject () const -> bool
  {
    return g_mount_can_eject (const_cast<GMount*> (gobj ()));
  }

  auto
  Mount::unmount_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_mount_unmount_with_operation_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Mount::remount_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_mount_remount_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Mount::eject_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_mount_eject_with_operation_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Mount::guess_content_type_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_mount_guess_content_type_finish (gobj (),
                                           glib::unwrap (result),
                                           &gerror),
        glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Mount::is_shadowed () const -> bool
  {
    return g_mount_is_shadowed (const_cast<GMount*> (gobj ()));
  }

  auto
  Mount::shadow () -> void
  {
    g_mount_shadow (gobj ());
  }

  auto
  Mount::unshadow () -> void
  {
    g_mount_unshadow (gobj ());
  }

  auto
  Mount::get_default_location () const -> glib::RefPtr<File>
  {
    return glib::wrap (
        g_mount_get_default_location (const_cast<GMount*> (gobj ())));
  }

  auto
  Mount::get_sort_key () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_mount_get_sort_key (const_cast<GMount*> (gobj ())));
  }

  auto
  Mount::signal_changed () -> glib::SignalProxy<void ()>
  {
    return {this, &Mount_signal_changed_info};
  }

  auto
  Mount::signal_unmounted () -> glib::SignalProxy<void ()>
  {
    return {this, &Mount_signal_unmounted_info};
  }

  auto
  Mount::signal_pre_unmount () -> glib::SignalProxy<void ()>
  {
    return {this, &Mount_signal_pre_unmount_info};
  }

  auto
  Mount::on_changed () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  Mount::on_unmounted () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->unmounted)
      (*base->unmounted) (gobj ());
  }

  auto
  Mount::on_pre_unmount () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->pre_unmount)
      (*base->pre_unmount) (gobj ());
  }

} // namespace gio
