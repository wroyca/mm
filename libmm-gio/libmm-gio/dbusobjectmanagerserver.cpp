


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusobjectmanagerserver.hpp>
#include <mm/gio/private/dbusobjectmanagerserver_p.hpp>


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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDBusObjectManagerServer* object, const bool take_copy) -> RefPtr<Gio::DBus::ObjectManagerServer>
{
  return Glib::make_refptr_for_instance<Gio::DBus::ObjectManagerServer>( dynamic_cast<Gio::DBus::ObjectManagerServer*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto ObjectManagerServer_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ObjectManagerServer_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_object_manager_server_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
    ObjectManager::add_interface(get_type());

  }

  return *this;
}


auto ObjectManagerServer_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ObjectManagerServer_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ObjectManagerServer((GDBusObjectManagerServer*)object);
}


/* The implementation: */

auto ObjectManagerServer::gobj_copy() -> GDBusObjectManagerServer*
{
  reference();
  return gobj();
}

ObjectManagerServer::ObjectManagerServer(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ObjectManagerServer::ObjectManagerServer(GDBusObjectManagerServer* castitem)
: Object((GObject*)castitem)
{}


ObjectManagerServer::ObjectManagerServer(ObjectManagerServer&& src) noexcept
: Object(std::move(src))
  ,
  ObjectManager(std::move(src))
{}

auto ObjectManagerServer::operator=(ObjectManagerServer&& src) noexcept -> ObjectManagerServer&
{
  Object::operator=(std::move(src));
  ObjectManager::operator=(std::move(src));
  return *this;
}


ObjectManagerServer::~ObjectManagerServer() noexcept = default;

ObjectManagerServer::CppClassType ObjectManagerServer::objectmanagerserver_class_; // initialize static member

auto ObjectManagerServer::get_type() -> GType
{
  return objectmanagerserver_class_.init().get_type();
}


auto ObjectManagerServer::get_base_type() -> GType
{
  return g_dbus_object_manager_server_get_type();
}


ObjectManagerServer::ObjectManagerServer(const Glib::ustring& object_path)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(objectmanagerserver_class_.init(), "object_path", object_path.c_str(), nullptr))
{


}

auto ObjectManagerServer::create(const Glib::ustring& object_path) -> Glib::RefPtr<ObjectManagerServer>
{
  return Glib::make_refptr_for_instance<ObjectManagerServer>( new ObjectManagerServer(object_path) );
}

auto ObjectManagerServer::get_connection() -> Glib::RefPtr<Connection>
{
  return Glib::wrap(g_dbus_object_manager_server_get_connection(gobj()));
}

auto ObjectManagerServer::get_connection() const -> Glib::RefPtr<const Connection>
{
  return const_cast<ObjectManagerServer*>(this)->get_connection();
}

auto ObjectManagerServer::set_connection (const Glib::RefPtr <Connection> &connection) -> void
{
  g_dbus_object_manager_server_set_connection(gobj(), Glib::unwrap(connection));
}

auto ObjectManagerServer::export_object (
  const Glib::RefPtr <ObjectSkeleton> &object) -> void
{
  g_dbus_object_manager_server_export(gobj(), Glib::unwrap(object));
}

auto ObjectManagerServer::export_uniquely (
  const Glib::RefPtr <ObjectSkeleton> &object) -> void
{
  g_dbus_object_manager_server_export_uniquely(gobj(), Glib::unwrap(object));
}

auto ObjectManagerServer::is_exported(const Glib::RefPtr<ObjectSkeleton>& object) const -> bool
{
  return g_dbus_object_manager_server_is_exported(const_cast<GDBusObjectManagerServer*>(gobj()), Glib::unwrap(object));
}

auto ObjectManagerServer::unexport(const Glib::ustring& object_path) -> bool
{
  return g_dbus_object_manager_server_unexport(gobj(), object_path.c_str());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Connection>>::value,
  "Type Glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ObjectManagerServer::property_connection() -> Glib::PropertyProxy< Glib::RefPtr<Connection> >
{
  return {this, "connection"};
}

auto ObjectManagerServer::property_connection() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >
{
  return {this, "connection"};
}

auto ObjectManagerServer::property_object_path() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "object-path"};
}


} // namespace Gio


