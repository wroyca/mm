// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusobjectmanagerserver.hxx>
#include <libmm/gio/dbusobjectmanagerserver_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GDBusObjectManagerServer* object, const bool take_copy) -> RefPtr<gio::DBus::ObjectManagerServer>
  {
    return glib::make_refptr_for_instance<gio::DBus::ObjectManagerServer> (
        dynamic_cast<gio::DBus::ObjectManagerServer*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
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
  ObjectManagerServer_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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

  ObjectManagerServer::ObjectManagerServer (const glib::ustring& object_path)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (objectmanagerserver_class_.init (),
                                     "object_path",
                                     object_path.c_str (),
                                     nullptr))
  {
  }

  auto
  ObjectManagerServer::create (const glib::ustring& object_path) -> glib::RefPtr<ObjectManagerServer>
  {
    return glib::make_refptr_for_instance<ObjectManagerServer> (
        new ObjectManagerServer (object_path));
  }

  auto
  ObjectManagerServer::get_connection () -> glib::RefPtr<Connection>
  {
    return glib::wrap (g_dbus_object_manager_server_get_connection (gobj ()));
  }

  auto
  ObjectManagerServer::get_connection () const -> glib::RefPtr<const Connection>
  {
    return const_cast<ObjectManagerServer*> (this)->get_connection ();
  }

  auto
  ObjectManagerServer::set_connection (
      const glib::RefPtr<Connection>& connection) -> void
  {
    g_dbus_object_manager_server_set_connection (gobj (),
                                                 glib::unwrap (connection));
  }

  auto
  ObjectManagerServer::export_object (
      const glib::RefPtr<ObjectSkeleton>& object) -> void
  {
    g_dbus_object_manager_server_export (gobj (), glib::unwrap (object));
  }

  auto
  ObjectManagerServer::export_uniquely (
      const glib::RefPtr<ObjectSkeleton>& object) -> void
  {
    g_dbus_object_manager_server_export_uniquely (gobj (),
                                                  glib::unwrap (object));
  }

  auto
  ObjectManagerServer::is_exported (
      const glib::RefPtr<ObjectSkeleton>& object) const -> bool
  {
    return g_dbus_object_manager_server_is_exported (
        const_cast<GDBusObjectManagerServer*> (gobj ()),
        glib::unwrap (object));
  }

  auto
  ObjectManagerServer::unexport (const glib::ustring& object_path) -> bool
  {
    return g_dbus_object_manager_server_unexport (gobj (),
                                                  object_path.c_str ());
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Connection>>::value,
      "Type glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ObjectManagerServer::property_connection () -> glib::PropertyProxy<glib::RefPtr<Connection>>
  {
    return {this, "connection"};
  }

  auto
  ObjectManagerServer::property_connection () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>
  {
    return {this, "connection"};
  }

  auto
  ObjectManagerServer::property_object_path () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "object-path"};
  }

} // namespace gio::DBus
