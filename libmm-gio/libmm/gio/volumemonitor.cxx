// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/volumemonitor.hxx>
#include <libmm/gio/volumemonitor_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

}

namespace
{

  auto
  VolumeMonitor_signal_volume_added_callback (GVolumeMonitor* self,
                                              GVolume* p0,
                                              void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Volume>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_volume_added_info = {
      "volume_added",
      (GCallback) &VolumeMonitor_signal_volume_added_callback,
      (GCallback) &VolumeMonitor_signal_volume_added_callback};

  auto
  VolumeMonitor_signal_volume_removed_callback (GVolumeMonitor* self,
                                                GVolume* p0,
                                                void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Volume>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_volume_removed_info = {
      "volume_removed",
      (GCallback) &VolumeMonitor_signal_volume_removed_callback,
      (GCallback) &VolumeMonitor_signal_volume_removed_callback};

  auto
  VolumeMonitor_signal_volume_changed_callback (GVolumeMonitor* self,
                                                GVolume* p0,
                                                void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Volume>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_volume_changed_info = {
      "volume_changed",
      (GCallback) &VolumeMonitor_signal_volume_changed_callback,
      (GCallback) &VolumeMonitor_signal_volume_changed_callback};

  auto
  VolumeMonitor_signal_mount_added_callback (GVolumeMonitor* self,
                                             GMount* p0,
                                             void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Mount>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_mount_added_info = {
      "mount_added",
      (GCallback) &VolumeMonitor_signal_mount_added_callback,
      (GCallback) &VolumeMonitor_signal_mount_added_callback};

  auto
  VolumeMonitor_signal_mount_removed_callback (GVolumeMonitor* self,
                                               GMount* p0,
                                               void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Mount>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_mount_removed_info = {
      "mount_removed",
      (GCallback) &VolumeMonitor_signal_mount_removed_callback,
      (GCallback) &VolumeMonitor_signal_mount_removed_callback};

  auto
  VolumeMonitor_signal_mount_pre_unmount_callback (GVolumeMonitor* self,
                                                   GMount* p0,
                                                   void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Mount>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_mount_pre_unmount_info = {
      "mount_pre_unmount",
      (GCallback) &VolumeMonitor_signal_mount_pre_unmount_callback,
      (GCallback) &VolumeMonitor_signal_mount_pre_unmount_callback};

  auto
  VolumeMonitor_signal_mount_changed_callback (GVolumeMonitor* self,
                                               GMount* p0,
                                               void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Mount>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_mount_changed_info = {
      "mount_changed",
      (GCallback) &VolumeMonitor_signal_mount_changed_callback,
      (GCallback) &VolumeMonitor_signal_mount_changed_callback};

  auto
  VolumeMonitor_signal_drive_connected_callback (GVolumeMonitor* self,
                                                 GDrive* p0,
                                                 void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Drive>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_drive_connected_info = {
      "drive_connected",
      (GCallback) &VolumeMonitor_signal_drive_connected_callback,
      (GCallback) &VolumeMonitor_signal_drive_connected_callback};

  auto
  VolumeMonitor_signal_drive_disconnected_callback (GVolumeMonitor* self,
                                                    GDrive* p0,
                                                    void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Drive>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_drive_disconnected_info = {
      "drive_disconnected",
      (GCallback) &VolumeMonitor_signal_drive_disconnected_callback,
      (GCallback) &VolumeMonitor_signal_drive_disconnected_callback};

  auto
  VolumeMonitor_signal_drive_changed_callback (GVolumeMonitor* self,
                                               GDrive* p0,
                                               void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Drive>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_drive_changed_info = {
      "drive_changed",
      (GCallback) &VolumeMonitor_signal_drive_changed_callback,
      (GCallback) &VolumeMonitor_signal_drive_changed_callback};

  auto
  VolumeMonitor_signal_drive_eject_button_callback (GVolumeMonitor* self,
                                                    GDrive* p0,
                                                    void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Drive>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_drive_eject_button_info = {
      "drive_eject_button",
      (GCallback) &VolumeMonitor_signal_drive_eject_button_callback,
      (GCallback) &VolumeMonitor_signal_drive_eject_button_callback};

  auto
  VolumeMonitor_signal_drive_stop_button_callback (GVolumeMonitor* self,
                                                   GDrive* p0,
                                                   void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::RefPtr<Drive>&)>;

    const auto obj = dynamic_cast<VolumeMonitor*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo VolumeMonitor_signal_drive_stop_button_info = {
      "drive_stop_button",
      (GCallback) &VolumeMonitor_signal_drive_stop_button_callback,
      (GCallback) &VolumeMonitor_signal_drive_stop_button_callback};

} // namespace

namespace glib
{

  auto
  wrap (GVolumeMonitor* object, const bool take_copy) -> RefPtr<gio::VolumeMonitor>
  {
    return glib::make_refptr_for_instance<gio::VolumeMonitor> (
        dynamic_cast<gio::VolumeMonitor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  VolumeMonitor_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &VolumeMonitor_Class::class_init_function;

      register_derived_type (g_volume_monitor_get_type ());
    }

    return *this;
  }

  auto
  VolumeMonitor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->volume_added = &volume_added_callback;
    klass->volume_removed = &volume_removed_callback;
    klass->volume_changed = &volume_changed_callback;
    klass->mount_added = &mount_added_callback;
    klass->mount_removed = &mount_removed_callback;
    klass->mount_pre_unmount = &mount_pre_unmount_callback;
    klass->mount_changed = &mount_changed_callback;
    klass->drive_connected = &drive_connected_callback;
    klass->drive_disconnected = &drive_disconnected_callback;
    klass->drive_changed = &drive_changed_callback;
    klass->drive_eject_button = &drive_eject_button_callback;
    klass->drive_stop_button = &drive_stop_button_callback;
  }

  auto
  VolumeMonitor_Class::volume_added_callback (GVolumeMonitor* self, GVolume* p0) -> void
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
          obj->on_volume_added (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->volume_added)
      (*base->volume_added) (self, p0);
  }

  auto
  VolumeMonitor_Class::volume_removed_callback (GVolumeMonitor* self,
                                                GVolume* p0) -> void
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
          obj->on_volume_removed (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->volume_removed)
      (*base->volume_removed) (self, p0);
  }

  auto
  VolumeMonitor_Class::volume_changed_callback (GVolumeMonitor* self,
                                                GVolume* p0) -> void
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
          obj->on_volume_changed (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->volume_changed)
      (*base->volume_changed) (self, p0);
  }

  auto
  VolumeMonitor_Class::mount_added_callback (GVolumeMonitor* self, GMount* p0) -> void
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
          obj->on_mount_added (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mount_added)
      (*base->mount_added) (self, p0);
  }

  auto
  VolumeMonitor_Class::mount_removed_callback (GVolumeMonitor* self, GMount* p0) -> void
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
          obj->on_mount_removed (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mount_removed)
      (*base->mount_removed) (self, p0);
  }

  auto
  VolumeMonitor_Class::mount_pre_unmount_callback (GVolumeMonitor* self,
                                                   GMount* p0) -> void
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
          obj->on_mount_pre_unmount (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mount_pre_unmount)
      (*base->mount_pre_unmount) (self, p0);
  }

  auto
  VolumeMonitor_Class::mount_changed_callback (GVolumeMonitor* self, GMount* p0) -> void
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
          obj->on_mount_changed (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mount_changed)
      (*base->mount_changed) (self, p0);
  }

  auto
  VolumeMonitor_Class::drive_connected_callback (GVolumeMonitor* self,
                                                 GDrive* p0) -> void
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
          obj->on_drive_connected (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->drive_connected)
      (*base->drive_connected) (self, p0);
  }

  auto
  VolumeMonitor_Class::drive_disconnected_callback (GVolumeMonitor* self,
                                                    GDrive* p0) -> void
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
          obj->on_drive_disconnected (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->drive_disconnected)
      (*base->drive_disconnected) (self, p0);
  }

  auto
  VolumeMonitor_Class::drive_changed_callback (GVolumeMonitor* self, GDrive* p0) -> void
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
          obj->on_drive_changed (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->drive_changed)
      (*base->drive_changed) (self, p0);
  }

  auto
  VolumeMonitor_Class::drive_eject_button_callback (GVolumeMonitor* self,
                                                    GDrive* p0) -> void
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
          obj->on_drive_eject_button (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->drive_eject_button)
      (*base->drive_eject_button) (self, p0);
  }

  auto
  VolumeMonitor_Class::drive_stop_button_callback (GVolumeMonitor* self,
                                                   GDrive* p0) -> void
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
          obj->on_drive_stop_button (glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->drive_stop_button)
      (*base->drive_stop_button) (self, p0);
  }

  auto
  VolumeMonitor_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new VolumeMonitor ((GVolumeMonitor*) object);
  }

  auto
  VolumeMonitor::gobj_copy () -> GVolumeMonitor*
  {
    reference ();
    return gobj ();
  }

  VolumeMonitor::VolumeMonitor (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  VolumeMonitor::VolumeMonitor (GVolumeMonitor* castitem)
    : Object ((GObject*) castitem)
  {
  }

  VolumeMonitor::VolumeMonitor (VolumeMonitor&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  VolumeMonitor::operator= (VolumeMonitor&& src) noexcept -> VolumeMonitor&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  VolumeMonitor::~VolumeMonitor () noexcept = default;

  VolumeMonitor::CppClassType VolumeMonitor::volumemonitor_class_;

  auto
  VolumeMonitor::get_type () -> GType
  {
    return volumemonitor_class_.init ().get_type ();
  }

  auto
  VolumeMonitor::get_base_type () -> GType
  {
    return g_volume_monitor_get_type ();
  }

  auto
  VolumeMonitor::get () -> glib::RefPtr<VolumeMonitor>
  {
    return glib::wrap (g_volume_monitor_get ());
  }

  auto
  VolumeMonitor::get_connected_drives () -> std::vector<glib::RefPtr<Drive>>
  {
    return glib::ListHandler<glib::RefPtr<Drive>>::list_to_vector (
        g_volume_monitor_get_connected_drives (gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  VolumeMonitor::get_volumes () -> std::vector<glib::RefPtr<Volume>>
  {
    return glib::ListHandler<glib::RefPtr<Volume>>::list_to_vector (
        g_volume_monitor_get_volumes (gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  VolumeMonitor::get_mounts () -> std::vector<glib::RefPtr<Mount>>
  {
    return glib::ListHandler<glib::RefPtr<Mount>>::list_to_vector (
        g_volume_monitor_get_mounts (gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  VolumeMonitor::get_volume_for_uuid (const std::string& uuid) -> glib::RefPtr<Volume>
  {
    auto retvalue = glib::wrap (
        g_volume_monitor_get_volume_for_uuid (gobj (), uuid.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  VolumeMonitor::get_mount_for_uuid (const std::string& uuid) -> glib::RefPtr<Mount>
  {
    auto retvalue = glib::wrap (
        g_volume_monitor_get_mount_for_uuid (gobj (), uuid.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  VolumeMonitor::signal_volume_added () -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>
  {
    return {this, &VolumeMonitor_signal_volume_added_info};
  }

  auto
  VolumeMonitor::signal_volume_removed () -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>
  {
    return {this, &VolumeMonitor_signal_volume_removed_info};
  }

  auto
  VolumeMonitor::signal_volume_changed () -> glib::SignalProxy<void (const glib::RefPtr<Volume>&)>
  {
    return {this, &VolumeMonitor_signal_volume_changed_info};
  }

  auto
  VolumeMonitor::signal_mount_added () -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>
  {
    return {this, &VolumeMonitor_signal_mount_added_info};
  }

  auto
  VolumeMonitor::signal_mount_removed () -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>
  {
    return {this, &VolumeMonitor_signal_mount_removed_info};
  }

  auto
  VolumeMonitor::signal_mount_pre_unmount () -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>
  {
    return {this, &VolumeMonitor_signal_mount_pre_unmount_info};
  }

  auto
  VolumeMonitor::signal_mount_changed () -> glib::SignalProxy<void (const glib::RefPtr<Mount>&)>
  {
    return {this, &VolumeMonitor_signal_mount_changed_info};
  }

  auto
  VolumeMonitor::signal_drive_connected () -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>
  {
    return {this, &VolumeMonitor_signal_drive_connected_info};
  }

  auto
  VolumeMonitor::signal_drive_disconnected () -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>
  {
    return {this, &VolumeMonitor_signal_drive_disconnected_info};
  }

  auto
  VolumeMonitor::signal_drive_changed () -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>
  {
    return {this, &VolumeMonitor_signal_drive_changed_info};
  }

  auto
  VolumeMonitor::signal_drive_eject_button () -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>
  {
    return {this, &VolumeMonitor_signal_drive_eject_button_info};
  }

  auto
  VolumeMonitor::signal_drive_stop_button () -> glib::SignalProxy<void (const glib::RefPtr<Drive>&)>
  {
    return {this, &VolumeMonitor_signal_drive_stop_button_info};
  }

  auto
  VolumeMonitor::on_volume_added (const glib::RefPtr<Volume>& volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->volume_added)
      (*base->volume_added) (gobj (), glib::unwrap (volume));
  }

  auto
  VolumeMonitor::on_volume_removed (const glib::RefPtr<Volume>& volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->volume_removed)
      (*base->volume_removed) (gobj (), glib::unwrap (volume));
  }

  auto
  VolumeMonitor::on_volume_changed (const glib::RefPtr<Volume>& volume) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->volume_changed)
      (*base->volume_changed) (gobj (), glib::unwrap (volume));
  }

  auto
  VolumeMonitor::on_mount_added (const glib::RefPtr<Mount>& mount) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mount_added)
      (*base->mount_added) (gobj (), glib::unwrap (mount));
  }

  auto
  VolumeMonitor::on_mount_removed (const glib::RefPtr<Mount>& mount) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mount_removed)
      (*base->mount_removed) (gobj (), glib::unwrap (mount));
  }

  auto
  VolumeMonitor::on_mount_pre_unmount (const glib::RefPtr<Mount>& mount) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mount_pre_unmount)
      (*base->mount_pre_unmount) (gobj (), glib::unwrap (mount));
  }

  auto
  VolumeMonitor::on_mount_changed (const glib::RefPtr<Mount>& mount) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mount_changed)
      (*base->mount_changed) (gobj (), glib::unwrap (mount));
  }

  auto
  VolumeMonitor::on_drive_connected (const glib::RefPtr<Drive>& drive) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->drive_connected)
      (*base->drive_connected) (gobj (), glib::unwrap (drive));
  }

  auto
  VolumeMonitor::on_drive_disconnected (const glib::RefPtr<Drive>& drive) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->drive_disconnected)
      (*base->drive_disconnected) (gobj (), glib::unwrap (drive));
  }

  auto
  VolumeMonitor::on_drive_changed (const glib::RefPtr<Drive>& drive) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->drive_changed)
      (*base->drive_changed) (gobj (), glib::unwrap (drive));
  }

  auto
  VolumeMonitor::on_drive_eject_button (const glib::RefPtr<Drive>& drive) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->drive_eject_button)
      (*base->drive_eject_button) (gobj (), glib::unwrap (drive));
  }

  auto
  VolumeMonitor::on_drive_stop_button (const glib::RefPtr<Drive>& drive) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->drive_stop_button)
      (*base->drive_stop_button) (gobj (), glib::unwrap (drive));
  }

} // namespace gio
