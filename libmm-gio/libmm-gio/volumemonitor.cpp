


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/volumemonitor.hpp>
#include <mm/gio/private/volumemonitor_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <mm/glib/exceptionhandler.hpp>

namespace Gio
{

} // namespace Gio

namespace
{


auto VolumeMonitor_signal_volume_added_callback (
  GVolumeMonitor *self, GVolume *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Volume>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_volume_added_info =
{
  "volume_added",
  (GCallback) &VolumeMonitor_signal_volume_added_callback,
  (GCallback) &VolumeMonitor_signal_volume_added_callback
};


auto VolumeMonitor_signal_volume_removed_callback (
  GVolumeMonitor *self, GVolume *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Volume>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_volume_removed_info =
{
  "volume_removed",
  (GCallback) &VolumeMonitor_signal_volume_removed_callback,
  (GCallback) &VolumeMonitor_signal_volume_removed_callback
};


auto VolumeMonitor_signal_volume_changed_callback (
  GVolumeMonitor *self, GVolume *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Volume>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_volume_changed_info =
{
  "volume_changed",
  (GCallback) &VolumeMonitor_signal_volume_changed_callback,
  (GCallback) &VolumeMonitor_signal_volume_changed_callback
};


auto VolumeMonitor_signal_mount_added_callback (
  GVolumeMonitor *self, GMount *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Mount>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_mount_added_info =
{
  "mount_added",
  (GCallback) &VolumeMonitor_signal_mount_added_callback,
  (GCallback) &VolumeMonitor_signal_mount_added_callback
};


auto VolumeMonitor_signal_mount_removed_callback (
  GVolumeMonitor *self, GMount *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Mount>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_mount_removed_info =
{
  "mount_removed",
  (GCallback) &VolumeMonitor_signal_mount_removed_callback,
  (GCallback) &VolumeMonitor_signal_mount_removed_callback
};


auto VolumeMonitor_signal_mount_pre_unmount_callback (
  GVolumeMonitor *self, GMount *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Mount>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_mount_pre_unmount_info =
{
  "mount_pre_unmount",
  (GCallback) &VolumeMonitor_signal_mount_pre_unmount_callback,
  (GCallback) &VolumeMonitor_signal_mount_pre_unmount_callback
};


auto VolumeMonitor_signal_mount_changed_callback (
  GVolumeMonitor *self, GMount *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Mount>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_mount_changed_info =
{
  "mount_changed",
  (GCallback) &VolumeMonitor_signal_mount_changed_callback,
  (GCallback) &VolumeMonitor_signal_mount_changed_callback
};


auto VolumeMonitor_signal_drive_connected_callback (
  GVolumeMonitor *self, GDrive *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Drive>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_drive_connected_info =
{
  "drive_connected",
  (GCallback) &VolumeMonitor_signal_drive_connected_callback,
  (GCallback) &VolumeMonitor_signal_drive_connected_callback
};


auto VolumeMonitor_signal_drive_disconnected_callback (
  GVolumeMonitor *self, GDrive *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Drive>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_drive_disconnected_info =
{
  "drive_disconnected",
  (GCallback) &VolumeMonitor_signal_drive_disconnected_callback,
  (GCallback) &VolumeMonitor_signal_drive_disconnected_callback
};


auto VolumeMonitor_signal_drive_changed_callback (
  GVolumeMonitor *self, GDrive *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Drive>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_drive_changed_info =
{
  "drive_changed",
  (GCallback) &VolumeMonitor_signal_drive_changed_callback,
  (GCallback) &VolumeMonitor_signal_drive_changed_callback
};


auto VolumeMonitor_signal_drive_eject_button_callback (
  GVolumeMonitor *self, GDrive *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Drive>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_drive_eject_button_info =
{
  "drive_eject_button",
  (GCallback) &VolumeMonitor_signal_drive_eject_button_callback,
  (GCallback) &VolumeMonitor_signal_drive_eject_button_callback
};


auto VolumeMonitor_signal_drive_stop_button_callback (
  GVolumeMonitor *self, GDrive *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Drive>&)>;

  const auto obj = dynamic_cast<VolumeMonitor*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo VolumeMonitor_signal_drive_stop_button_info =
{
  "drive_stop_button",
  (GCallback) &VolumeMonitor_signal_drive_stop_button_callback,
  (GCallback) &VolumeMonitor_signal_drive_stop_button_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GVolumeMonitor* object, const bool take_copy) -> RefPtr<Gio::VolumeMonitor>
{
  return Glib::make_refptr_for_instance<Gio::VolumeMonitor>( dynamic_cast<Gio::VolumeMonitor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto VolumeMonitor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &VolumeMonitor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_volume_monitor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto VolumeMonitor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


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


auto VolumeMonitor_Class::volume_added_callback (GVolumeMonitor *self, GVolume *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_volume_added(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->volume_added)
    (*base->volume_added)(self, p0);
}
auto VolumeMonitor_Class::volume_removed_callback (GVolumeMonitor *self, GVolume *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_volume_removed(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->volume_removed)
    (*base->volume_removed)(self, p0);
}
auto VolumeMonitor_Class::volume_changed_callback (GVolumeMonitor *self, GVolume *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_volume_changed(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->volume_changed)
    (*base->volume_changed)(self, p0);
}
auto VolumeMonitor_Class::mount_added_callback (GVolumeMonitor *self, GMount *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_mount_added(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->mount_added)
    (*base->mount_added)(self, p0);
}
auto VolumeMonitor_Class::mount_removed_callback (GVolumeMonitor *self, GMount *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_mount_removed(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->mount_removed)
    (*base->mount_removed)(self, p0);
}
auto VolumeMonitor_Class::mount_pre_unmount_callback (GVolumeMonitor *self, GMount *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_mount_pre_unmount(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->mount_pre_unmount)
    (*base->mount_pre_unmount)(self, p0);
}
auto VolumeMonitor_Class::mount_changed_callback (GVolumeMonitor *self, GMount *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_mount_changed(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->mount_changed)
    (*base->mount_changed)(self, p0);
}
auto VolumeMonitor_Class::drive_connected_callback (GVolumeMonitor *self, GDrive *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_drive_connected(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->drive_connected)
    (*base->drive_connected)(self, p0);
}
auto VolumeMonitor_Class::drive_disconnected_callback (GVolumeMonitor *self, GDrive *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_drive_disconnected(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->drive_disconnected)
    (*base->drive_disconnected)(self, p0);
}
auto VolumeMonitor_Class::drive_changed_callback (GVolumeMonitor *self, GDrive *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_drive_changed(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->drive_changed)
    (*base->drive_changed)(self, p0);
}
auto VolumeMonitor_Class::drive_eject_button_callback (GVolumeMonitor *self, GDrive *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_drive_eject_button(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->drive_eject_button)
    (*base->drive_eject_button)(self, p0);
}
auto VolumeMonitor_Class::drive_stop_button_callback (GVolumeMonitor *self, GDrive *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_drive_stop_button(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->drive_stop_button)
    (*base->drive_stop_button)(self, p0);
}


auto VolumeMonitor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new VolumeMonitor((GVolumeMonitor*)object);
}


/* The implementation: */

auto VolumeMonitor::gobj_copy() -> GVolumeMonitor*
{
  reference();
  return gobj();
}

VolumeMonitor::VolumeMonitor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

VolumeMonitor::VolumeMonitor(GVolumeMonitor* castitem)
: Object((GObject*)castitem)
{}


VolumeMonitor::VolumeMonitor(VolumeMonitor&& src) noexcept
: Object(std::move(src))
{}

auto VolumeMonitor::operator=(VolumeMonitor&& src) noexcept -> VolumeMonitor&
{
  Object::operator=(std::move(src));
  return *this;
}


VolumeMonitor::~VolumeMonitor() noexcept = default;

VolumeMonitor::CppClassType VolumeMonitor::volumemonitor_class_; // initialize static member

auto VolumeMonitor::get_type() -> GType
{
  return volumemonitor_class_.init().get_type();
}


auto VolumeMonitor::get_base_type() -> GType
{
  return g_volume_monitor_get_type();
}


auto VolumeMonitor::get() -> Glib::RefPtr<VolumeMonitor>
{
  return Glib::wrap(g_volume_monitor_get());
}

auto VolumeMonitor::get_connected_drives() -> std::vector<Glib::RefPtr<Drive>>
{
  return Glib::ListHandler<Glib::RefPtr<Drive>>::list_to_vector(g_volume_monitor_get_connected_drives(gobj()), Glib::OWNERSHIP_DEEP);
}

auto VolumeMonitor::get_volumes() -> std::vector<Glib::RefPtr<Volume>>
{
  return Glib::ListHandler<Glib::RefPtr<Volume>>::list_to_vector(g_volume_monitor_get_volumes(gobj()), Glib::OWNERSHIP_DEEP);
}

auto VolumeMonitor::get_mounts() -> std::vector<Glib::RefPtr<Mount>>
{
  return Glib::ListHandler<Glib::RefPtr<Mount>>::list_to_vector(g_volume_monitor_get_mounts(gobj()), Glib::OWNERSHIP_DEEP);
}

auto VolumeMonitor::get_volume_for_uuid(const std::string& uuid) -> Glib::RefPtr<Volume>
{
  auto retvalue = Glib::wrap(g_volume_monitor_get_volume_for_uuid(gobj(), uuid.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto VolumeMonitor::get_mount_for_uuid(const std::string& uuid) -> Glib::RefPtr<Mount>
{
  auto retvalue = Glib::wrap(g_volume_monitor_get_mount_for_uuid(gobj(), uuid.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


auto VolumeMonitor::signal_volume_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>
{
  return {this, &VolumeMonitor_signal_volume_added_info};
}


auto VolumeMonitor::signal_volume_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>
{
  return {this, &VolumeMonitor_signal_volume_removed_info};
}


auto VolumeMonitor::signal_volume_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Volume>&)>
{
  return {this, &VolumeMonitor_signal_volume_changed_info};
}


auto VolumeMonitor::signal_mount_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>
{
  return {this, &VolumeMonitor_signal_mount_added_info};
}


auto VolumeMonitor::signal_mount_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>
{
  return {this, &VolumeMonitor_signal_mount_removed_info};
}


auto VolumeMonitor::signal_mount_pre_unmount() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>
{
  return {this, &VolumeMonitor_signal_mount_pre_unmount_info};
}


auto VolumeMonitor::signal_mount_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Mount>&)>
{
  return {this, &VolumeMonitor_signal_mount_changed_info};
}


auto VolumeMonitor::signal_drive_connected() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>
{
  return {this, &VolumeMonitor_signal_drive_connected_info};
}


auto VolumeMonitor::signal_drive_disconnected() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>
{
  return {this, &VolumeMonitor_signal_drive_disconnected_info};
}


auto VolumeMonitor::signal_drive_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>
{
  return {this, &VolumeMonitor_signal_drive_changed_info};
}


auto VolumeMonitor::signal_drive_eject_button() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>
{
  return {this, &VolumeMonitor_signal_drive_eject_button_info};
}


auto VolumeMonitor::signal_drive_stop_button() -> Glib::SignalProxy<void(const Glib::RefPtr<Drive>&)>
{
  return {this, &VolumeMonitor_signal_drive_stop_button_info};
}


auto VolumeMonitor::on_volume_added (const Glib::RefPtr <Volume> &volume) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->volume_added)
    (*base->volume_added)(gobj(),Glib::unwrap(volume));
}
auto VolumeMonitor::on_volume_removed (const Glib::RefPtr <Volume> &volume) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->volume_removed)
    (*base->volume_removed)(gobj(),Glib::unwrap(volume));
}
auto VolumeMonitor::on_volume_changed (const Glib::RefPtr <Volume> &volume) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->volume_changed)
    (*base->volume_changed)(gobj(),Glib::unwrap(volume));
}
auto VolumeMonitor::on_mount_added (const Glib::RefPtr <Mount> &mount) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->mount_added)
    (*base->mount_added)(gobj(),Glib::unwrap(mount));
}
auto VolumeMonitor::on_mount_removed (const Glib::RefPtr <Mount> &mount) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->mount_removed)
    (*base->mount_removed)(gobj(),Glib::unwrap(mount));
}
auto VolumeMonitor::on_mount_pre_unmount (const Glib::RefPtr <Mount> &mount) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->mount_pre_unmount)
    (*base->mount_pre_unmount)(gobj(),Glib::unwrap(mount));
}
auto VolumeMonitor::on_mount_changed (const Glib::RefPtr <Mount> &mount) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->mount_changed)
    (*base->mount_changed)(gobj(),Glib::unwrap(mount));
}
auto VolumeMonitor::on_drive_connected (const Glib::RefPtr <Drive> &drive) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->drive_connected)
    (*base->drive_connected)(gobj(),Glib::unwrap(drive));
}
auto VolumeMonitor::on_drive_disconnected (const Glib::RefPtr <Drive> &drive) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->drive_disconnected)
    (*base->drive_disconnected)(gobj(),Glib::unwrap(drive));
}
auto VolumeMonitor::on_drive_changed (const Glib::RefPtr <Drive> &drive) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->drive_changed)
    (*base->drive_changed)(gobj(),Glib::unwrap(drive));
}
auto VolumeMonitor::on_drive_eject_button (const Glib::RefPtr <Drive> &drive) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->drive_eject_button)
    (*base->drive_eject_button)(gobj(),Glib::unwrap(drive));
}
auto VolumeMonitor::on_drive_stop_button (const Glib::RefPtr <Drive> &drive) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->drive_stop_button)
    (*base->drive_stop_button)(gobj(),Glib::unwrap(drive));
}


} // namespace Gio


