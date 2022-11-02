// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gio/dbusinterfaceskeleton.h>
#include <mm/gio/private/dbusinterfaceskeleton_p.h>


/* Copyright (C) 2013 The giomm Development Team
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

#include <mm/gio/dbusconnection.h>
#include <mm/gio/dbusintrospection.h>
#include <mm/gio/dbusmethodinvocation.h>

using Flags = Gio::DBus::InterfaceSkeleton::Flags;

namespace
{


auto InterfaceSkeleton_signal_authorize_method_callback(GDBusInterfaceSkeleton* self, GDBusMethodInvocation* p0,void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<MethodInvocation>&)>;

  auto obj = dynamic_cast<InterfaceSkeleton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return static_cast<int>((*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
));
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto InterfaceSkeleton_signal_authorize_method_notify_callback(GDBusInterfaceSkeleton* self, GDBusMethodInvocation* p0, void* data) -> gboolean
{
  using namespace Gio::DBus;
  using SlotType = sigc::slot<void(const Glib::RefPtr<MethodInvocation>&)>;

  auto obj = dynamic_cast<InterfaceSkeleton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo InterfaceSkeleton_signal_authorize_method_info =
{
  "g_authorize_method",
  (GCallback) &InterfaceSkeleton_signal_authorize_method_callback,
  (GCallback) &InterfaceSkeleton_signal_authorize_method_notify_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::DBus::InterfaceSkeleton::Flags>::value_type() -> GType
{
  return g_dbus_interface_skeleton_flags_get_type();
}


namespace Glib
{

auto wrap(GDBusInterfaceSkeleton* object, bool take_copy) -> Glib::RefPtr<Gio::DBus::InterfaceSkeleton>
{
  return Glib::make_refptr_for_instance<Gio::DBus::InterfaceSkeleton>( dynamic_cast<Gio::DBus::InterfaceSkeleton*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto InterfaceSkeleton_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &InterfaceSkeleton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_interface_skeleton_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Interface::add_interface(get_type());

  }

  return *this;
}


void InterfaceSkeleton_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->g_authorize_method = &g_authorize_method_callback;
}


auto InterfaceSkeleton_Class::g_authorize_method_callback(GDBusInterfaceSkeleton* self, GDBusMethodInvocation* p0) -> gboolean
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
        return static_cast<int>(obj->on_authorize_method(Glib::wrap(p0, true)
));
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
  if(base && base->g_authorize_method)
    return (*base->g_authorize_method)(self, p0);

  using RType = gboolean;
  return RType();
}


auto InterfaceSkeleton_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new InterfaceSkeleton((GDBusInterfaceSkeleton*)object);
}


/* The implementation: */

auto InterfaceSkeleton::gobj_copy() -> GDBusInterfaceSkeleton*
{
  reference();
  return gobj();
}

InterfaceSkeleton::InterfaceSkeleton(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

InterfaceSkeleton::InterfaceSkeleton(GDBusInterfaceSkeleton* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


InterfaceSkeleton::InterfaceSkeleton(InterfaceSkeleton&& src) noexcept
: Glib::Object(std::move(src))
  , Interface(std::move(src))
{}

auto InterfaceSkeleton::operator=(InterfaceSkeleton&& src) noexcept -> InterfaceSkeleton&
{
  Glib::Object::operator=(std::move(src));
  Interface::operator=(std::move(src));
  return *this;
}


InterfaceSkeleton::~InterfaceSkeleton() noexcept
{}


InterfaceSkeleton::CppClassType InterfaceSkeleton::interfaceskeleton_class_; // initialize static member

auto InterfaceSkeleton::get_type() -> GType
{
  return interfaceskeleton_class_.init().get_type();
}


auto InterfaceSkeleton::get_base_type() -> GType
{
  return g_dbus_interface_skeleton_get_type();
}


void InterfaceSkeleton::flush()
{
  g_dbus_interface_skeleton_flush(gobj());
}

auto InterfaceSkeleton::get_info() -> Glib::RefPtr<InterfaceInfo>
{
  return Glib::wrap(g_dbus_interface_skeleton_get_info(gobj()));
}

auto InterfaceSkeleton::get_info() const -> Glib::RefPtr<const InterfaceInfo>
{
  return const_cast<InterfaceSkeleton*>(this)->get_info();
}

auto InterfaceSkeleton::get_properties() const -> Glib::VariantBase
{
  return Glib::wrap(g_dbus_interface_skeleton_get_properties(const_cast<GDBusInterfaceSkeleton*>(gobj())), false);
}

void InterfaceSkeleton::export_interface_skeleton(const Glib::RefPtr<Connection>& connection, const Glib::ustring& object_path)
{
  GError* gerror = nullptr;
  g_dbus_interface_skeleton_export(gobj(), Glib::unwrap(connection), object_path.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void InterfaceSkeleton::unexport()
{
  g_dbus_interface_skeleton_unexport(gobj());
}

void InterfaceSkeleton::unexport_from_connection(const Glib::RefPtr<Connection>& connection)
{
  g_dbus_interface_skeleton_unexport_from_connection(gobj(), Glib::unwrap(connection));
}

auto InterfaceSkeleton::get_connection() -> Glib::RefPtr<Connection>
{
  return Glib::wrap(g_dbus_interface_skeleton_get_connection(gobj()));
}

auto InterfaceSkeleton::get_connection() const -> Glib::RefPtr<const Connection>
{
  return const_cast<InterfaceSkeleton*>(this)->get_connection();
}

auto InterfaceSkeleton::get_connections() -> std::vector< Glib::RefPtr<Connection> >
{
  return Glib::ListHandler< Glib::RefPtr<Connection> >::list_to_vector(g_dbus_interface_skeleton_get_connections(gobj()), Glib::OWNERSHIP_DEEP);
}

auto InterfaceSkeleton::get_connections() const -> std::vector< Glib::RefPtr<const Connection> >
{
  return Glib::ListHandler< Glib::RefPtr<const Connection> >::list_to_vector(g_dbus_interface_skeleton_get_connections(const_cast<GDBusInterfaceSkeleton*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto InterfaceSkeleton::has_connection(const Glib::RefPtr<const Connection>& connection) const -> bool
{
  return g_dbus_interface_skeleton_has_connection(const_cast<GDBusInterfaceSkeleton*>(gobj()), const_cast<GDBusConnection*>(Glib::unwrap(connection)));
}

auto InterfaceSkeleton::get_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_interface_skeleton_get_object_path(const_cast<GDBusInterfaceSkeleton*>(gobj())));
}

auto InterfaceSkeleton::get_flags() const -> Flags
{
  return static_cast<Flags>(g_dbus_interface_skeleton_get_flags(const_cast<GDBusInterfaceSkeleton*>(gobj())));
}

void InterfaceSkeleton::set_flags(Flags flags)
{
  g_dbus_interface_skeleton_set_flags(gobj(), static_cast<GDBusInterfaceSkeletonFlags>(flags));
}


auto InterfaceSkeleton::signal_authorize_method() -> Glib::SignalProxy<bool(const Glib::RefPtr<MethodInvocation>&)>
{
  return Glib::SignalProxy<bool(const Glib::RefPtr<MethodInvocation>&) >(this, &InterfaceSkeleton_signal_authorize_method_info);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
  "Type Flags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto InterfaceSkeleton::property_g_flags() -> Glib::PropertyProxy< Flags >
{
  return Glib::PropertyProxy< Flags >(this, "g-flags");
}

auto InterfaceSkeleton::property_g_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >
{
  return Glib::PropertyProxy_ReadOnly< Flags >(this, "g-flags");
}


auto Gio::DBus::InterfaceSkeleton::on_authorize_method(const Glib::RefPtr<MethodInvocation>& invocation) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->g_authorize_method)
    return (*base->g_authorize_method)(gobj(),Glib::unwrap(invocation));

  using RType = bool;
  return RType();
}


} // namespace Gio

