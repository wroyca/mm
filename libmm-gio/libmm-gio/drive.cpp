


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/drive.hpp>
#include <libmm-gio/drive_p.hpp>


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
#include <libmm-gio/volume.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/slot_async.hpp>

using StartStopType = Gio::Drive::StartStopType;

namespace Gio
{

auto Drive::eject (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    nullptr, // mount_operation
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto Drive::eject (const SlotAsyncReady &slot, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    nullptr, // mount_operation
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto Drive::eject (
  const Glib::RefPtr <MountOperation> &mount_operation, const SlotAsyncReady &slot,
  const Glib::RefPtr <Cancellable> &cancellable, Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation), Glib::unwrap(cancellable), &SignalProxy_async_callback,
    slot_copy);
}

auto Drive::eject (
  const Glib::RefPtr <MountOperation> &mount_operation, const SlotAsyncReady &slot,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation),
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto Drive::eject (
  const Glib::RefPtr <MountOperation> &mount_operation, Mount::UnmountFlags flags) -> void
{
  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    Glib::unwrap(mount_operation),
    nullptr, // cancellable
    nullptr, // callback
    nullptr); // user_data
}

auto Drive::eject (Mount::UnmountFlags flags) -> void
{
  g_drive_eject_with_operation(gobj(), static_cast<GMountUnmountFlags>(flags),
    nullptr, // mount_operation
    nullptr, // cancellable
    nullptr, // callback
    nullptr); // user_data
}

auto Drive::poll_for_media (
  const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_poll_for_media(gobj(), Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto Drive::poll_for_media (const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_poll_for_media(gobj(),
    nullptr, // cancellable
    &SignalProxy_async_callback, slot_copy);
}

auto Drive::poll_for_media () -> void
{
  g_drive_poll_for_media(gobj(),
    nullptr, // cancellable
    nullptr, nullptr);
}

auto Drive::stop (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_stop(gobj(), static_cast<GMountUnmountFlags>(flags), Glib::unwrap(mount_operation),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto Drive::stop (
  const Glib::RefPtr <MountOperation> &mount_operation, const SlotAsyncReady &slot,
  Mount::UnmountFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_stop(gobj(), static_cast<GMountUnmountFlags>(flags), Glib::unwrap(mount_operation),
    nullptr, &SignalProxy_async_callback, slot_copy);
}

auto Drive::start (
  const Glib::RefPtr <MountOperation> &mount_operation,
  const Glib::RefPtr <Cancellable> &cancellable, const SlotAsyncReady &slot,
  StartFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_start(gobj(), static_cast<GDriveStartFlags>(flags), Glib::unwrap(mount_operation),
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto Drive::start (
  const Glib::RefPtr <MountOperation> &mount_operation, const SlotAsyncReady &slot,
  StartFlags flags) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_drive_start(gobj(), static_cast<GDriveStartFlags>(flags), Glib::unwrap(mount_operation),
    nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{


const Glib::SignalProxyInfo Drive_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Drive_signal_disconnected_info =
{
  "disconnected",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Drive_signal_eject_button_info =
{
  "eject_button",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Drive_signal_stop_button_info =
{
  "stop_button",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::Drive::StartFlags>::value_type() -> GType
{
  return g_drive_start_flags_get_type();
}

// static
auto Glib::Value<Gio::Drive::StartStopType>::value_type() -> GType
{
  return g_drive_start_stop_type_get_type();
}


namespace Glib
{

auto wrap(GDrive* object, const bool take_copy) -> RefPtr<Gio::Drive>
{
  return Glib::make_refptr_for_instance<Gio::Drive>( Glib::wrap_auto_interface<Gio::Drive> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto Drive_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Drive_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_drive_get_type();
  }

  return *this;
}

auto Drive_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


  klass->changed = &changed_callback;
  klass->disconnected = &disconnected_callback;
  klass->eject_button = &eject_button_callback;
  klass->stop_button = &stop_button_callback;
}


auto Drive_Class::changed_callback (GDrive *self) -> void
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
        obj->on_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}
auto Drive_Class::disconnected_callback (GDrive *self) -> void
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
        obj->on_disconnected();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->disconnected)
    (*base->disconnected)(self);
}
auto Drive_Class::eject_button_callback (GDrive *self) -> void
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
        obj->on_eject_button();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->eject_button)
    (*base->eject_button)(self);
}
auto Drive_Class::stop_button_callback (GDrive *self) -> void
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
        obj->on_stop_button();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->stop_button)
    (*base->stop_button)(self);
}


auto Drive_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Drive((GDrive*)object);
}


/* The implementation: */

Drive::Drive()
: Interface(drive_class_.init())
{}

Drive::Drive(GDrive* castitem)
: Interface((GObject*)castitem)
{}

Drive::Drive(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Drive::Drive(Drive&& src) noexcept
: Interface(std::move(src))
{}

auto Drive::operator=(Drive&& src) noexcept -> Drive&
{
  Interface::operator=(std::move(src));
  return *this;
}

Drive::~Drive() noexcept = default;

// static
auto Drive::add_interface (
  const GType gtype_implementer) -> void
{
  drive_class_.init().add_interface(gtype_implementer);
}

Drive::CppClassType Drive::drive_class_; // initialize static member

auto Drive::get_type() -> GType
{
  return drive_class_.init().get_type();
}


auto Drive::get_base_type() -> GType
{
  return g_drive_get_type();
}


auto Drive::get_name() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_drive_get_name(const_cast<GDrive*>(gobj())));
}

auto Drive::get_icon() -> Glib::RefPtr<Icon>
{
  auto retvalue = Glib::wrap(g_drive_get_icon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drive::get_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<Drive*>(this)->get_icon();
}

auto Drive::get_symbolic_icon() -> Glib::RefPtr<Icon>
{
  auto retvalue = Glib::wrap(g_drive_get_symbolic_icon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drive::get_symbolic_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<Drive*>(this)->get_symbolic_icon();
}

auto Drive::has_volumes() const -> bool
{
  return g_drive_has_volumes(const_cast<GDrive*>(gobj()));
}

auto Drive::get_volumes() -> std::vector<Glib::RefPtr<Volume>>
{
  return Glib::ListHandler<Glib::RefPtr<Volume>>::list_to_vector(g_drive_get_volumes(gobj()), Glib::OWNERSHIP_DEEP);
}

auto Drive::is_media_removable() const -> bool
{
  return g_drive_is_media_removable(const_cast<GDrive*>(gobj()));
}

auto Drive::is_removable() const -> bool
{
  return g_drive_is_removable(const_cast<GDrive*>(gobj()));
}

auto Drive::has_media() const -> bool
{
  return g_drive_has_media(const_cast<GDrive*>(gobj()));
}

auto Drive::is_media_check_automatic() const -> bool
{
  return g_drive_is_media_check_automatic(const_cast<GDrive*>(gobj()));
}

auto Drive::can_poll_for_media() const -> bool
{
  return g_drive_can_poll_for_media(const_cast<GDrive*>(gobj()));
}

auto Drive::can_eject() const -> bool
{
  return g_drive_can_eject(const_cast<GDrive*>(gobj()));
}

auto Drive::eject_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_drive_eject_with_operation_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Drive::poll_for_media_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_drive_poll_for_media_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Drive::get_identifier(const std::string& kind) const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_drive_get_identifier(const_cast<GDrive*>(gobj()), kind.c_str()));
}

auto Drive::enumerate_identifiers() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_drive_enumerate_identifiers(const_cast<GDrive*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto Drive::start_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_drive_start_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Drive::can_start() const -> bool
{
  return g_drive_can_start(const_cast<GDrive*>(gobj()));
}

auto Drive::can_start_degraded() const -> bool
{
  return g_drive_can_start_degraded(const_cast<GDrive*>(gobj()));
}

auto Drive::stop_finish(const Glib::RefPtr<AsyncResult>& result) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_drive_stop_finish(gobj(), Glib::unwrap(result), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Drive::can_stop() const -> bool
{
  return g_drive_can_stop(const_cast<GDrive*>(gobj()));
}

auto Drive::get_start_stop_type() const -> StartStopType
{
  return static_cast<StartStopType>(g_drive_get_start_stop_type(const_cast<GDrive*>(gobj())));
}

auto Drive::get_sort_key() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_drive_get_sort_key(const_cast<GDrive*>(gobj())));
}


auto Drive::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &Drive_signal_changed_info};
}


auto Drive::signal_disconnected() -> Glib::SignalProxy<void()>
{
  return {this, &Drive_signal_disconnected_info};
}


auto Drive::signal_eject_button() -> Glib::SignalProxy<void()>
{
  return {this, &Drive_signal_eject_button_info};
}


auto Drive::signal_stop_button() -> Glib::SignalProxy<void()>
{
  return {this, &Drive_signal_stop_button_info};
}


auto Drive::on_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->changed)
    (*base->changed)(gobj());
}
auto Drive::on_disconnected () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->disconnected)
    (*base->disconnected)(gobj());
}
auto Drive::on_eject_button () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->eject_button)
    (*base->eject_button)(gobj());
}
auto Drive::on_stop_button () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->stop_button)
    (*base->stop_button)(gobj());
}


} // namespace Gio


