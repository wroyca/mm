// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusobjectproxy.hxx>
#include <libmm/gio/dbusobjectproxy_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GDBusObjectProxy* object, const bool take_copy) -> RefPtr<gio::DBus::ObjectProxy>
  {
    return glib::make_refptr_for_instance<gio::DBus::ObjectProxy> (
        dynamic_cast<gio::DBus::ObjectProxy*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  ObjectProxy_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ObjectProxy_Class::class_init_function;

      register_derived_type (g_dbus_object_proxy_get_type ());

      Object::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ObjectProxy_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ObjectProxy_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ObjectProxy ((GDBusObjectProxy*) object);
  }

  auto
  ObjectProxy::gobj_copy () -> GDBusObjectProxy*
  {
    reference ();
    return gobj ();
  }

  ObjectProxy::ObjectProxy (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ObjectProxy::ObjectProxy (GDBusObjectProxy* castitem)
    : glib::Object ((GObject*) castitem)
  {
  }

  ObjectProxy::ObjectProxy (ObjectProxy&& src) noexcept
    : glib::Object (std::move (src)),
      DBus::Object (std::move (src))
  {
  }

  auto
  ObjectProxy::operator= (ObjectProxy&& src) noexcept -> ObjectProxy&
  {
    glib::Object::operator= (std::move (src));
    DBus::Object::operator= (std::move (src));
    return *this;
  }

  ObjectProxy::~ObjectProxy () noexcept = default;

  ObjectProxy::CppClassType ObjectProxy::objectproxy_class_;

  auto
  ObjectProxy::get_type () -> GType
  {
    return objectproxy_class_.init ().get_type ();
  }

  auto
  ObjectProxy::get_base_type () -> GType
  {
    return g_dbus_object_proxy_get_type ();
  }

  ObjectProxy::ObjectProxy (const glib::RefPtr<Connection>& connection,
                            const glib::ustring& object_path)
    : ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (objectproxy_class_.init (),
                                           "connection",
                                           glib::unwrap (connection),
                                           "object_path",
                                           object_path.c_str (),
                                           nullptr))
  {
  }

  auto
  ObjectProxy::create (const glib::RefPtr<Connection>& connection,
                       const glib::ustring& object_path) -> glib::RefPtr<ObjectProxy>
  {
    return glib::make_refptr_for_instance<ObjectProxy> (
        new ObjectProxy (connection, object_path));
  }

  auto
  ObjectProxy::get_connection () -> glib::RefPtr<Connection>
  {
    auto retvalue = glib::wrap (g_dbus_object_proxy_get_connection (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ObjectProxy::get_connection () const -> glib::RefPtr<const Connection>
  {
    return const_cast<ObjectProxy*> (this)->get_connection ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Connection>>::value,
      "Type glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ObjectProxy::property_g_connection () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>
  {
    return {this, "g-connection"};
  }

  auto
  ObjectProxy::property_g_object_path () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-object-path"};
  }

} // namespace gio::DBus
