


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/dbusobject.hpp>
#include <libmm-gio/dbusobject_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
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
#include <libmm-gio/dbusinterface.hpp>
#include <libmm-glib/vectorutils.hpp>

namespace
{
// Used in call to g_list_copy_deep().
auto list_copy_ref(const void* src, void* /* data */) -> void*
{
  return g_object_ref(const_cast<void*>(src));
}

// Define a replacement for Glib::unwrap_copy().
// Can't use the template function in glibmm/wrap.h, because interface classes
// don't override Glib::ObjectBase::gobj_copy(), which returns a GObject*.
auto local_unwrap_copy(const Glib::RefPtr<Gio::DBus::Interface>& ptr) -> GDBusInterface*
{
  return ptr ? reinterpret_cast<GDBusInterface*>(ptr->gobj_copy()) : nullptr;
}
} // anonymous namespace

namespace
{


auto Object_signal_interface_added_callback (
  GDBusObject *self, GDBusInterface *p0, void *data) -> void
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Interface>&)>;

  const auto obj = dynamic_cast<Object*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Object_signal_interface_added_info =
{
  "interface_added",
  (GCallback) &Object_signal_interface_added_callback,
  (GCallback) &Object_signal_interface_added_callback
};


auto Object_signal_interface_removed_callback (
  GDBusObject *self, GDBusInterface *p0, void *data) -> void
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Interface>&)>;

  const auto obj = dynamic_cast<Object*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo Object_signal_interface_removed_info =
{
  "interface_removed",
  (GCallback) &Object_signal_interface_removed_callback,
  (GCallback) &Object_signal_interface_removed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GDBusObject* object, const bool take_copy) -> RefPtr<Gio::DBus::Object>
{
  return Glib::make_refptr_for_instance<Gio::DBus::Object>( Glib::wrap_auto_interface<Gio::DBus::Object> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio::DBus
{


/* The *_Class implementation: */

auto Object_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Object_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_dbus_object_get_type();
  }

  return *this;
}

auto Object_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_object_path = &get_object_path_vfunc_callback;
  klass->get_interfaces = &get_interfaces_vfunc_callback;
  klass->get_interface = &get_interface_vfunc_callback;

  klass->interface_added = &interface_added_callback;
  klass->interface_removed = &interface_removed_callback;
}

auto Object_Class::get_object_path_vfunc_callback(GDBusObject* self) -> const gchar*
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
        static auto quark_return_value = g_quark_from_static_string("Gio::DBus::Object::get_object_path_vfunc");

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

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_object_path)
    return (*base->get_object_path)(self);

  using RType = const gchar*;
  return RType();
}
auto Object_Class::get_interfaces_vfunc_callback(GDBusObject* self) -> GList*
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
        return g_list_copy_deep(Glib::ListHandler<Glib::RefPtr<Interface>>::vector_to_list(obj->get_interfaces_vfunc()).data(), list_copy_ref, nullptr);
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_interfaces)
    return (*base->get_interfaces)(self);

  using RType = GList*;
  return RType();
}
auto Object_Class::get_interface_vfunc_callback(GDBusObject* self, const gchar* interface_name) -> GDBusInterface*
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
        return local_unwrap_copy(obj->get_interface_vfunc(Glib::convert_const_gchar_ptr_to_ustring(interface_name)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_interface)
    return (*base->get_interface)(self, interface_name);

  using RType = GDBusInterface*;
  return RType();
}

auto Object_Class::interface_added_callback (GDBusObject *self, GDBusInterface *p0) -> void
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
        obj->on_interface_added(Glib::wrap(p0, true)
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
    (*base->interface_added)(self, p0);
}
auto Object_Class::interface_removed_callback (GDBusObject *self, GDBusInterface *p0) -> void
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
        obj->on_interface_removed(Glib::wrap(p0, true)
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
    (*base->interface_removed)(self, p0);
}


auto Object_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Object((GDBusObject*)object);
}


/* The implementation: */

Object::Object()
: Interface(object_class_.init())
{}

Object::Object(GDBusObject* castitem)
: Interface((GObject*)castitem)
{}

Object::Object(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Object::Object(Object&& src) noexcept
: Interface(std::move(src))
{}

auto Object::operator=(Object&& src) noexcept -> Object&
{
  Interface::operator=(std::move(src));
  return *this;
}

Object::~Object() noexcept = default;

// static
auto Object::add_interface (
  const GType gtype_implementer) -> void
{
  object_class_.init().add_interface(gtype_implementer);
}

Object::CppClassType Object::object_class_; // initialize static member

auto Object::get_type() -> GType
{
  return object_class_.init().get_type();
}


auto Object::get_base_type() -> GType
{
  return g_dbus_object_get_type();
}


auto Object::get_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_object_get_object_path(const_cast<GDBusObject*>(gobj())));
}

auto Object::get_interfaces() -> std::vector<Glib::RefPtr<DBus::Interface>>
{
  return Glib::ListHandler<Glib::RefPtr<DBus::Interface>>::list_to_vector(g_dbus_object_get_interfaces(gobj()), Glib::OWNERSHIP_DEEP);
}

auto Object::get_interfaces() const -> std::vector<Glib::RefPtr<const DBus::Interface>>
{
  return Glib::ListHandler<Glib::RefPtr<const DBus::Interface>>::list_to_vector(g_dbus_object_get_interfaces(const_cast<GDBusObject*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto Object::get_interface(const Glib::ustring& interface_name) -> Glib::RefPtr<DBus::Interface>
{
  return Glib::wrap(g_dbus_object_get_interface(gobj(), interface_name.c_str()));
}

auto Object::get_interface(const Glib::ustring& interface_name) const -> Glib::RefPtr<const DBus::Interface>
{
  return const_cast<Object*>(this)->get_interface(interface_name);
}


auto Object::signal_interface_added() -> Glib::SignalProxy<void(const Glib::RefPtr<DBus::Interface>&)>
{
  return {this, &Object_signal_interface_added_info};
}


auto Object::signal_interface_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<DBus::Interface>&)>
{
  return {this, &Object_signal_interface_removed_info};
}


auto Object::on_interface_added (
  const Glib::RefPtr <DBus::Interface> &iface) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->interface_added)
    (*base->interface_added)(gobj(),Glib::unwrap(iface));
}
auto Object::on_interface_removed (
  const Glib::RefPtr <DBus::Interface> &iface) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->interface_removed)
    (*base->interface_removed)(gobj(),Glib::unwrap(iface));
}

auto Object::get_object_path_vfunc() const -> Glib::ustring
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_object_path)
  {
    Glib::ustring retval(Glib::convert_const_gchar_ptr_to_ustring((*base->get_object_path)(const_cast<GDBusObject*>(gobj()))));
    return retval;
  }

  using RType = Glib::ustring;
  return {};
}
auto Object::get_interfaces_vfunc() const -> std::vector<Glib::RefPtr<DBus::Interface>>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_interfaces)
  {
    std::vector<Glib::RefPtr<DBus::Interface>> retval(Glib::ListHandler<Glib::RefPtr<DBus::Interface>>::list_to_vector((*base->get_interfaces)(const_cast<GDBusObject*>(gobj())), Glib::OWNERSHIP_DEEP));
    return retval;
  }

  using RType = std::vector<Glib::RefPtr<DBus::Interface>>;
  return {};
}
auto Object::get_interface_vfunc(const Glib::ustring& interface_name) const -> Glib::RefPtr<DBus::Interface>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_interface)
  {
    Glib::RefPtr<DBus::Interface> retval(Glib::wrap((*base->get_interface)(const_cast<GDBusObject*>(gobj()),interface_name.c_str())));
    return retval;
  }

  using RType = Glib::RefPtr<DBus::Interface>;
  return {};
}


} // namespace Gio


