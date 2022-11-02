// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusobjectmanager.hpp>
#include <mm/gio/private/dbusobjectmanager_p.hpp>


/* Copyright (C) 2019 The giomm Development Team
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
#include <mm/gio/dbusobject.hpp>
#include <mm/gio/dbusinterface.hpp>

namespace
{
// Used in call to g_list_copy_deep().
auto list_copy_ref(const void* src, void* /* data */) -> void*
{
  return g_object_ref(const_cast<void*>(src));
}

// Define some replacements for Glib::unwrap_copy().
// Can't use the template function in glibmm/wrap.h, because interface classes
// don't override Glib::ObjectBase::gobj_copy(), which returns a GObject*.
auto local_unwrap_copy(const Glib::RefPtr<Gio::DBus::Object>& ptr) -> GDBusObject*
{
  return ptr ? reinterpret_cast<GDBusObject*>(ptr->gobj_copy()) : nullptr;
}

auto local_unwrap_copy(const Glib::RefPtr<Gio::DBus::Interface>& ptr) -> GDBusInterface*
{
  return ptr ? reinterpret_cast<GDBusInterface*>(ptr->gobj_copy()) : nullptr;
}

} // anonymous namespace

namespace
{


void ObjectManager_signal_object_added_callback(GDBusObjectManager* self, GDBusObject* p0,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::DBus::Object>&)>;

  auto obj = dynamic_cast<ObjectManager*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo ObjectManager_signal_object_added_info =
{
  "object-added",
  (GCallback) &ObjectManager_signal_object_added_callback,
  (GCallback) &ObjectManager_signal_object_added_callback
};


void ObjectManager_signal_object_removed_callback(GDBusObjectManager* self, GDBusObject* p0,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::DBus::Object>&)>;

  auto obj = dynamic_cast<ObjectManager*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo ObjectManager_signal_object_removed_info =
{
  "object-removed",
  (GCallback) &ObjectManager_signal_object_removed_callback,
  (GCallback) &ObjectManager_signal_object_removed_callback
};


void ObjectManager_signal_interface_added_callback(GDBusObjectManager* self, GDBusObject* p0,GDBusInterface* p1,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>;

  auto obj = dynamic_cast<ObjectManager*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ObjectManager_signal_interface_added_info =
{
  "interface-added",
  (GCallback) &ObjectManager_signal_interface_added_callback,
  (GCallback) &ObjectManager_signal_interface_added_callback
};


void ObjectManager_signal_interface_removed_callback(GDBusObjectManager* self, GDBusObject* p0,GDBusInterface* p1,void* data)
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>;

  auto obj = dynamic_cast<ObjectManager*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ObjectManager_signal_interface_removed_info =
{
  "interface-removed",
  (GCallback) &ObjectManager_signal_interface_removed_callback,
  (GCallback) &ObjectManager_signal_interface_removed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GDBusObjectManager* object, bool take_copy) -> Glib::RefPtr<Gio::DBus::ObjectManager>
{
  return Glib::make_refptr_for_instance<Gio::DBus::ObjectManager>( dynamic_cast<Gio::DBus::ObjectManager*> (Glib::wrap_auto_interface<Gio::DBus::ObjectManager> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio::DBus
{


/* The *_Class implementation: */

auto ObjectManager_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ObjectManager_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_dbus_object_manager_get_type();
  }

  return *this;
}

void ObjectManager_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_object_path = &get_object_path_vfunc_callback;
  klass->get_objects = &get_objects_vfunc_callback;
  klass->get_object = &get_object_vfunc_callback;
  klass->get_interface = &get_interface_vfunc_callback;

  klass->object_added = &object_added_callback;
  klass->object_removed = &object_removed_callback;
  klass->interface_added = &interface_added_callback;
  klass->interface_removed = &interface_removed_callback;
}

auto ObjectManager_Class::get_object_path_vfunc_callback(GDBusObjectManager* self) -> const gchar*
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        static auto quark_return_value = g_quark_from_static_string("Gio::DBus::ObjectManager::get_object_path_vfunc");

        auto return_value = static_cast<Glib::ustring*>(g_object_get_qdata(obj_base->gobj(), quark_return_value));
        if (!return_value)
        {
          return_value = new Glib::ustring();
          g_object_set_qdata_full(obj_base->gobj(), quark_return_value, return_value,
          &Glib::destroy_notify_delete<Glib::ustring>);
        }
        // Keep a copy of the return value. The caller is not expected
        // to free the object that the returned pointer points to.
        *return_value = obj->get_object_path_vfunc();
        return (*return_value).c_str();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_object_path)
    return (*base->get_object_path)(self);

  using RType = const gchar*;
  return RType();
}
auto ObjectManager_Class::get_objects_vfunc_callback(GDBusObjectManager* self) -> GList*
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return g_list_copy_deep(Glib::ListHandler<Glib::RefPtr<Gio::DBus::Object>>::vector_to_list(obj->get_objects_vfunc()).data(), list_copy_ref, nullptr);
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_objects)
    return (*base->get_objects)(self);

  using RType = GList*;
  return RType();
}
auto ObjectManager_Class::get_object_vfunc_callback(GDBusObjectManager* self, const gchar* object_path) -> GDBusObject*
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return local_unwrap_copy(obj->get_object_vfunc(Glib::convert_const_gchar_ptr_to_ustring(object_path)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_object)
    return (*base->get_object)(self, object_path);

  using RType = GDBusObject*;
  return RType();
}
auto ObjectManager_Class::get_interface_vfunc_callback(GDBusObjectManager* self, const gchar* object_path, const gchar* interface_name) -> GDBusInterface*
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        return local_unwrap_copy(obj->get_interface_vfunc(Glib::convert_const_gchar_ptr_to_ustring(object_path)
, Glib::convert_const_gchar_ptr_to_ustring(interface_name)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_interface)
    return (*base->get_interface)(self, object_path, interface_name);

  using RType = GDBusInterface*;
  return RType();
}

void ObjectManager_Class::object_added_callback(GDBusObjectManager* self, GDBusObject* p0)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->on_object_added(Glib::wrap(p0, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->object_added)
    (*base->object_added)(self, p0);
}
void ObjectManager_Class::object_removed_callback(GDBusObjectManager* self, GDBusObject* p0)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->on_object_removed(Glib::wrap(p0, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->object_removed)
    (*base->object_removed)(self, p0);
}
void ObjectManager_Class::interface_added_callback(GDBusObjectManager* self, GDBusObject* p0, GDBusInterface* p1)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->on_interface_added(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->interface_added)
    (*base->interface_added)(self, p0, p1);
}
void ObjectManager_Class::interface_removed_callback(GDBusObjectManager* self, GDBusObject* p0, GDBusInterface* p1)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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
        obj->on_interface_removed(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->interface_removed)
    (*base->interface_removed)(self, p0, p1);
}


auto ObjectManager_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ObjectManager((GDBusObjectManager*)(object));
}


/* The implementation: */

ObjectManager::ObjectManager()
:
  Glib::Interface(objectmanager_class_.init())
{}

ObjectManager::ObjectManager(GDBusObjectManager* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

ObjectManager::ObjectManager(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

ObjectManager::ObjectManager(ObjectManager&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto ObjectManager::operator=(ObjectManager&& src) noexcept -> ObjectManager&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

ObjectManager::~ObjectManager() noexcept
{}

// static
void ObjectManager::add_interface(GType gtype_implementer)
{
  objectmanager_class_.init().add_interface(gtype_implementer);
}

ObjectManager::CppClassType ObjectManager::objectmanager_class_; // initialize static member

auto ObjectManager::get_type() -> GType
{
  return objectmanager_class_.init().get_type();
}


auto ObjectManager::get_base_type() -> GType
{
  return g_dbus_object_manager_get_type();
}


auto ObjectManager::get_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_object_manager_get_object_path(const_cast<GDBusObjectManager*>(gobj())));
}

auto ObjectManager::get_objects() -> std::vector<Glib::RefPtr<Gio::DBus::Object>>
{
  return Glib::ListHandler<Glib::RefPtr<Gio::DBus::Object>>::list_to_vector(g_dbus_object_manager_get_objects(gobj()), Glib::OWNERSHIP_DEEP);
}

auto ObjectManager::get_objects() const -> std::vector<Glib::RefPtr<const Gio::DBus::Object>>
{
  return Glib::ListHandler<Glib::RefPtr<const Gio::DBus::Object>>::list_to_vector(g_dbus_object_manager_get_objects(const_cast<GDBusObjectManager*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto ObjectManager::get_object(const Glib::ustring& object_path) -> Glib::RefPtr<Gio::DBus::Object>
{
  return Glib::wrap(g_dbus_object_manager_get_object(gobj(), object_path.c_str()));
}

auto ObjectManager::get_object(const Glib::ustring& object_path) const -> Glib::RefPtr<const Gio::DBus::Object>
{
  return const_cast<ObjectManager*>(this)->get_object(object_path);
}

auto ObjectManager::get_interface(const Glib::ustring& object_path, const Glib::ustring& interface_name) -> Glib::RefPtr<Gio::DBus::Interface>
{
  return Glib::wrap(g_dbus_object_manager_get_interface(gobj(), object_path.c_str(), interface_name.c_str()));
}

auto ObjectManager::get_interface(const Glib::ustring& object_path, const Glib::ustring& interface_name) const -> Glib::RefPtr<const Gio::DBus::Interface>
{
  return const_cast<ObjectManager*>(this)->get_interface(object_path, interface_name);
}


auto ObjectManager::signal_object_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&) >(this, &ObjectManager_signal_object_added_info);
}


auto ObjectManager::signal_object_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&) >(this, &ObjectManager_signal_object_removed_info);
}


auto ObjectManager::signal_interface_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&) >(this, &ObjectManager_signal_interface_added_info);
}


auto ObjectManager::signal_interface_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Gio::DBus::Object>&, const Glib::RefPtr<Gio::DBus::Interface>&) >(this, &ObjectManager_signal_interface_removed_info);
}


void Gio::DBus::ObjectManager::on_object_added(const Glib::RefPtr<Gio::DBus::Object>& object)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->object_added)
    (*base->object_added)(gobj(),Glib::unwrap(object));
}
void Gio::DBus::ObjectManager::on_object_removed(const Glib::RefPtr<Gio::DBus::Object>& object)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->object_removed)
    (*base->object_removed)(gobj(),Glib::unwrap(object));
}
void Gio::DBus::ObjectManager::on_interface_added(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->interface_added)
    (*base->interface_added)(gobj(),Glib::unwrap(object),Glib::unwrap(iface));
}
void Gio::DBus::ObjectManager::on_interface_removed(const Glib::RefPtr<Gio::DBus::Object>& object, const Glib::RefPtr<Gio::DBus::Interface>& iface)
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->interface_removed)
    (*base->interface_removed)(gobj(),Glib::unwrap(object),Glib::unwrap(iface));
}

auto Gio::DBus::ObjectManager::get_object_path_vfunc() const -> Glib::ustring
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_object_path)
  {
    Glib::ustring retval(Glib::convert_const_gchar_ptr_to_ustring((*base->get_object_path)(const_cast<GDBusObjectManager*>(gobj()))));
    return retval;
  }

  using RType = Glib::ustring;
  return RType();
}
auto Gio::DBus::ObjectManager::get_objects_vfunc() const -> std::vector<Glib::RefPtr<Gio::DBus::Object>>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_objects)
  {
    std::vector<Glib::RefPtr<Gio::DBus::Object>> retval(Glib::ListHandler<Glib::RefPtr<Gio::DBus::Object>>::list_to_vector((*base->get_objects)(const_cast<GDBusObjectManager*>(gobj())), Glib::OWNERSHIP_DEEP));
    return retval;
  }

  using RType = std::vector<Glib::RefPtr<Gio::DBus::Object>>;
  return RType();
}
auto Gio::DBus::ObjectManager::get_object_vfunc(const Glib::ustring& object_path) const -> Glib::RefPtr<Gio::DBus::Object>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_object)
  {
    Glib::RefPtr<Gio::DBus::Object> retval(Glib::wrap((*base->get_object)(const_cast<GDBusObjectManager*>(gobj()),object_path.c_str())));
    return retval;
  }

  using RType = Glib::RefPtr<Gio::DBus::Object>;
  return RType();
}
auto Gio::DBus::ObjectManager::get_interface_vfunc(const Glib::ustring& object_path, const Glib::ustring& interface_name) const -> Glib::RefPtr<Gio::DBus::Interface>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_interface)
  {
    Glib::RefPtr<Gio::DBus::Interface> retval(Glib::wrap((*base->get_interface)(const_cast<GDBusObjectManager*>(gobj()),object_path.c_str(),interface_name.c_str())));
    return retval;
  }

  using RType = Glib::RefPtr<Gio::DBus::Interface>;
  return RType();
}


} // namespace Gio


