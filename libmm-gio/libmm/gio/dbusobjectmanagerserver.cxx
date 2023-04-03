// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusobjectmanagerserver.hxx>
#include <libmm/gio/dbusobjectmanagerserver_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GDBusObjectManagerServer* object, const bool take_copy) -> RefPtr<Gio::DBus::ObjectManagerServer>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::ObjectManagerServer> (
        dynamic_cast<Gio::DBus::ObjectManagerServer*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio::DBus
{

  auto
  ObjectManagerServer_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ObjectManagerServer_Class::class_init_function;

      register_derived_type (g_dbus_object_manager_server_get_type ());

      ObjectManager::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ObjectManagerServer_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ObjectManagerServer_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ObjectManagerServer ((GDBusObjectManagerServer*) object);
  }

  auto
  ObjectManagerServer::gobj_copy () -> GDBusObjectManagerServer*
  {
    reference ();
    return gobj ();
  }

  ObjectManagerServer::ObjectManagerServer (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ObjectManagerServer::ObjectManagerServer (GDBusObjectManagerServer* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ObjectManagerServer::ObjectManagerServer (ObjectManagerServer&& src) noexcept
    : Object (std::move (src)),
      ObjectManager (std::move (src))
  {
  }

  auto
  ObjectManagerServer::operator= (ObjectManagerServer&& src) noexcept -> ObjectManagerServer&
  {
    Object::operator= (std::move (src));
    ObjectManager::operator= (std::move (src));
    return *this;
  }

  ObjectManagerServer::~ObjectManagerServer () noexcept = default;

  ObjectManagerServer::CppClassType
      ObjectManagerServer::objectmanagerserver_class_;

  auto
  ObjectManagerServer::get_type () -> GType
  {
    return objectmanagerserver_class_.init ().get_type ();
  }

  auto
  ObjectManagerServer::get_base_type () -> GType
  {
    return g_dbus_object_manager_server_get_type ();
  }

  ObjectManagerServer::ObjectManagerServer (const Glib::ustring& object_path)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (objectmanagerserver_class_.init (),
                                     "object_path",
                                     object_path.c_str (),
                                     nullptr))
  {
  }

  auto
  ObjectManagerServer::create (const Glib::ustring& object_path) -> Glib::RefPtr<ObjectManagerServer>
  {
    return Glib::make_refptr_for_instance<ObjectManagerServer> (
        new ObjectManagerServer (object_path));
  }

  auto
  ObjectManagerServer::get_connection () -> Glib::RefPtr<Connection>
  {
    return Glib::wrap (g_dbus_object_manager_server_get_connection (gobj ()));
  }

  auto
  ObjectManagerServer::get_connection () const -> Glib::RefPtr<const Connection>
  {
    return const_cast<ObjectManagerServer*> (this)->get_connection ();
  }

  auto
  ObjectManagerServer::set_connection (
      const Glib::RefPtr<Connection>& connection) -> void
  {
    g_dbus_object_manager_server_set_connection (gobj (),
                                                 Glib::unwrap (connection));
  }

  auto
  ObjectManagerServer::export_object (
      const Glib::RefPtr<ObjectSkeleton>& object) -> void
  {
    g_dbus_object_manager_server_export (gobj (), Glib::unwrap (object));
  }

  auto
  ObjectManagerServer::export_uniquely (
      const Glib::RefPtr<ObjectSkeleton>& object) -> void
  {
    g_dbus_object_manager_server_export_uniquely (gobj (),
                                                  Glib::unwrap (object));
  }

  auto
  ObjectManagerServer::is_exported (
      const Glib::RefPtr<ObjectSkeleton>& object) const -> bool
  {
    return g_dbus_object_manager_server_is_exported (
        const_cast<GDBusObjectManagerServer*> (gobj ()),
        Glib::unwrap (object));
  }

  auto
  ObjectManagerServer::unexport (const Glib::ustring& object_path) -> bool
  {
    return g_dbus_object_manager_server_unexport (gobj (),
                                                  object_path.c_str ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Connection>>::value,
      "Type Glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ObjectManagerServer::property_connection () -> Glib::PropertyProxy<Glib::RefPtr<Connection>>
  {
    return {this, "connection"};
  }

  auto
  ObjectManagerServer::property_connection () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>
  {
    return {this, "connection"};
  }

  auto
  ObjectManagerServer::property_object_path () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "object-path"};
  }

} // namespace Gio::DBus
