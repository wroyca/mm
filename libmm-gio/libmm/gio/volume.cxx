// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/volume.hxx>
#include <libmm/gio/volume_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/drive.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  auto
  Volume::mount (const glib::RefPtr<MountOperation>& mount_operation,
                 const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 Mount::MountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_mount (gobj (),
                    static_cast<GMountMountFlags> (flags),
                    glib::unwrap (mount_operation),
                    glib::unwrap (cancellable),
                    &SignalProxy_async_callback,
                    slot_copy);
  }

  auto
  Volume::mount (const glib::RefPtr<MountOperation>& mount_operation,
                 const SlotAsyncReady& slot,
                 Mount::MountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_mount (gobj (),
                    static_cast<GMountMountFlags> (flags),
                    glib::unwrap (mount_operation),
                    nullptr,
                    &SignalProxy_async_callback,
                    slot_copy);
  }

  auto
  Volume::mount (const glib::RefPtr<MountOperation>& mount_operation,
                 Mount::MountFlags flags) -> void
  {
    g_volume_mount (gobj (),
                    static_cast<GMountMountFlags> (flags),
                    glib::unwrap (mount_operation),
                    nullptr,
                    nullptr,
                    nullptr);
  }

  auto
  Volume::mount (Mount::MountFlags flags) -> void
  {
    g_volume_mount (gobj (),
                    static_cast<GMountMountFlags> (flags),
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr);
  }

  auto
  Volume::eject (const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 Mount::UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   nullptr,
                                   glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Volume::eject (const SlotAsyncReady& slot, Mount::UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   nullptr,
                                   nullptr,
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Volume::eject (Mount::UnmountFlags flags) -> void
  {
    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   nullptr,
                                   nullptr,
                                   nullptr,
                                   nullptr);
  }

  auto
  Volume::eject (const glib::RefPtr<MountOperation>& mount_operation,
                 const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 Mount::UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   glib::unwrap (mount_operation),
                                   glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Volume::eject (const glib::RefPtr<MountOperation>& mount_operation,
                 const SlotAsyncReady& slot,
                 Mount::UnmountFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   glib::unwrap (mount_operation),
                                   nullptr,
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Volume::eject (const glib::RefPtr<MountOperation>& mount_operation,
                 Mount::UnmountFlags flags) -> void
  {
    g_volume_eject_with_operation (gobj (),
                                   static_cast<GMountUnmountFlags> (flags),
                                   glib::unwrap (mount_operation),
                                   nullptr,
                                   nullptr,
                                   nullptr);
  }

} // namespace gio

namespace
{

  const glib::SignalProxyInfo Volume_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  const glib::SignalProxyInfo Volume_signal_removed_info = {
      "removed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GVolume* object, const bool take_copy) -> RefPtr<gio::Volume>
  {
    return glib::make_refptr_for_instance<gio::Volume> (
        glib::wrap_auto_interface<gio::Volume> ((GObject*) object, take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  Volume_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Volume_Class::iface_init_function;

      gtype_ = g_drive_get_type ();
    }

    return *this;
  }

  auto
  Volume_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->changed = &changed_callback;
    klass->removed = &removed_callback;
  }

  auto
  Volume_Class::changed_callback (GVolume* self) -> void
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
  Volume_Class::removed_callback (GVolume* self) -> void
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
          obj->on_removed ();
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

    if (base && base->removed)
      (*base->removed) (self);
  }

  auto
  Volume_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Volume ((GVolume*) object);
  }

  Volume::Volume ()
    : Interface (volume_class_.init ())
  {
  }

  Volume::Volume (GVolume* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Volume::Volume (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Volume::Volume (Volume&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Volume::operator= (Volume&& src) noexcept -> Volume&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Volume::~Volume () noexcept = default;

  auto
  Volume::add_interface (const GType gtype_implementer) -> void
  {
    volume_class_.init ().add_interface (gtype_implementer);
  }

  Volume::CppClassType Volume::volume_class_;

  auto
  Volume::get_type () -> GType
  {
    return volume_class_.init ().get_type ();
  }

  auto
  Volume::get_base_type () -> GType
  {
    return g_drive_get_type ();
  }

  auto
  Volume::get_name () const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_volume_get_name (const_cast<GVolume*> (gobj ())));
  }

  auto
  Volume::get_uuid () const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_volume_get_uuid (const_cast<GVolume*> (gobj ())));
  }

  auto
  Volume::get_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_volume_get_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Volume::get_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<Volume*> (this)->get_icon ();
  }

  auto
  Volume::get_symbolic_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_volume_get_symbolic_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Volume::get_symbolic_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<Volume*> (this)->get_symbolic_icon ();
  }

  auto
  Volume::get_drive () -> glib::RefPtr<Drive>
  {
    auto retvalue = glib::wrap (g_volume_get_drive (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Volume::get_drive () const -> glib::RefPtr<const Drive>
  {
    return const_cast<Volume*> (this)->get_drive ();
  }

  auto
  Volume::get_mount () -> glib::RefPtr<Mount>
  {
    auto retvalue = glib::wrap (g_volume_get_mount (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Volume::get_mount () const -> glib::RefPtr<const Mount>
  {
    return const_cast<Volume*> (this)->get_mount ();
  }

  auto
  Volume::can_mount () const -> bool
  {
    return g_volume_can_mount (const_cast<GVolume*> (gobj ()));
  }

  auto
  Volume::can_eject () const -> bool
  {
    return g_volume_can_eject (const_cast<GVolume*> (gobj ()));
  }

  auto
  Volume::should_automount () const -> bool
  {
    return g_volume_should_automount (const_cast<GVolume*> (gobj ()));
  }

  auto
  Volume::mount_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_volume_mount_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Volume::eject_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_volume_eject_with_operation_finish (
        gobj (),
        glib::unwrap (result),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Volume::get_identifier (const std::string& kind) const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_volume_get_identifier (const_cast<GVolume*> (gobj ()),
                                 kind.c_str ()));
  }

  auto
  Volume::enumerate_identifiers () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_volume_enumerate_identifiers (const_cast<GVolume*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Volume::get_activation_root () -> glib::RefPtr<File>
  {
    return glib::wrap (g_volume_get_activation_root (gobj ()));
  }

  auto
  Volume::get_activation_root () const -> glib::RefPtr<const File>
  {
    return glib::wrap (
        g_volume_get_activation_root (const_cast<GVolume*> (gobj ())));
  }

  auto
  Volume::sort_key () -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_volume_get_sort_key (gobj ()));
  }

  auto
  Volume::signal_changed () -> glib::SignalProxy<void ()>
  {
    return {this, &Volume_signal_changed_info};
  }

  auto
  Volume::signal_removed () -> glib::SignalProxy<void ()>
  {
    return {this, &Volume_signal_removed_info};
  }

  auto
  Volume::on_changed () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  Volume::on_removed () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->removed)
      (*base->removed) (gobj ());
  }

} // namespace gio
