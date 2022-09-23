// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/dbusobjectmanagerserver.h>
#include <giomm/private/dbusobjectmanagerserver_p.h>


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

Glib::RefPtr<Gio::DBus::ObjectManagerServer> wrap(GDBusObjectManagerServer* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gio::DBus::ObjectManagerServer>( dynamic_cast<Gio::DBus::ObjectManagerServer*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{

namespace DBus
{


/* The *_Class implementation: */

const Glib::Class& ObjectManagerServer_Class::init()
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
  DBus::ObjectManager::add_interface(get_type());

  }

  return *this;
}


void ObjectManagerServer_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* ObjectManagerServer_Class::wrap_new(GObject* object)
{
  return new ObjectManagerServer((GDBusObjectManagerServer*)object);
}


/* The implementation: */

GDBusObjectManagerServer* ObjectManagerServer::gobj_copy()
{
  reference();
  return gobj();
}

ObjectManagerServer::ObjectManagerServer(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

ObjectManagerServer::ObjectManagerServer(GDBusObjectManagerServer* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


ObjectManagerServer::ObjectManagerServer(ObjectManagerServer&& src) noexcept
: Glib::Object(std::move(src))
  , DBus::ObjectManager(std::move(src))
{}

ObjectManagerServer& ObjectManagerServer::operator=(ObjectManagerServer&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  DBus::ObjectManager::operator=(std::move(src));
  return *this;
}


ObjectManagerServer::~ObjectManagerServer() noexcept
{}


ObjectManagerServer::CppClassType ObjectManagerServer::objectmanagerserver_class_; // initialize static member

GType ObjectManagerServer::get_type()
{
  return objectmanagerserver_class_.init().get_type();
}


GType ObjectManagerServer::get_base_type()
{
  return g_dbus_object_manager_server_get_type();
}


ObjectManagerServer::ObjectManagerServer(const Glib::ustring& object_path)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(objectmanagerserver_class_.init(), "object_path", object_path.c_str(), nullptr))
{
  

}

Glib::RefPtr<ObjectManagerServer> ObjectManagerServer::create(const Glib::ustring& object_path)
{
  return Glib::make_refptr_for_instance<ObjectManagerServer>( new ObjectManagerServer(object_path) );
}

Glib::RefPtr<Connection> ObjectManagerServer::get_connection()
{
  return Glib::wrap(g_dbus_object_manager_server_get_connection(gobj()));
}

Glib::RefPtr<const Connection> ObjectManagerServer::get_connection() const
{
  return const_cast<ObjectManagerServer*>(this)->get_connection();
}

void ObjectManagerServer::set_connection(const Glib::RefPtr<Connection>& connection)
{
  g_dbus_object_manager_server_set_connection(gobj(), Glib::unwrap(connection));
}

void ObjectManagerServer::export_object(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object)
{
  g_dbus_object_manager_server_export(gobj(), Glib::unwrap(object));
}

void ObjectManagerServer::export_uniquely(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object)
{
  g_dbus_object_manager_server_export_uniquely(gobj(), Glib::unwrap(object));
}

bool ObjectManagerServer::is_exported(const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object) const
{
  return g_dbus_object_manager_server_is_exported(const_cast<GDBusObjectManagerServer*>(gobj()), Glib::unwrap(object));
}

bool ObjectManagerServer::unexport(const Glib::ustring& object_path)
{
  return g_dbus_object_manager_server_unexport(gobj(), object_path.c_str());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Connection>>::value,
  "Type Glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<Connection> > ObjectManagerServer::property_connection() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Connection> >(this, "connection");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> > ObjectManagerServer::property_connection() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Connection> >(this, "connection");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ObjectManagerServer::property_object_path() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "object-path");
}


} // namespace DBus

} // namespace Gio


