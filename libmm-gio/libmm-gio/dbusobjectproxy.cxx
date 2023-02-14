

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusobjectproxy.hxx>
#include <libmm-gio/dbusobjectproxy_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GDBusObjectProxy* object, const bool take_copy) -> RefPtr<Gio::DBus::ObjectProxy>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::ObjectProxy> (
        dynamic_cast<Gio::DBus::ObjectProxy*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio::DBus
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
  ObjectProxy_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ObjectProxy ((GDBusObjectProxy*) object);
  }

  auto
  ObjectProxy::gobj_copy () -> GDBusObjectProxy*
  {
    reference ();
    return gobj ();
  }

  ObjectProxy::ObjectProxy (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ObjectProxy::ObjectProxy (GDBusObjectProxy* castitem)
    : Glib::Object ((GObject*) castitem)
  {
  }

  ObjectProxy::ObjectProxy (ObjectProxy&& src) noexcept
    : Glib::Object (std::move (src)),
      DBus::Object (std::move (src))
  {
  }

  auto
  ObjectProxy::operator= (ObjectProxy&& src) noexcept -> ObjectProxy&
  {
    Glib::Object::operator= (std::move (src));
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

  ObjectProxy::ObjectProxy (const Glib::RefPtr<Connection>& connection,
                            const Glib::ustring& object_path)
    : ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (objectproxy_class_.init (),
                                           "connection",
                                           Glib::unwrap (connection),
                                           "object_path",
                                           object_path.c_str (),
                                           nullptr))
  {
  }

  auto
  ObjectProxy::create (const Glib::RefPtr<Connection>& connection,
                       const Glib::ustring& object_path) -> Glib::RefPtr<ObjectProxy>
  {
    return Glib::make_refptr_for_instance<ObjectProxy> (
        new ObjectProxy (connection, object_path));
  }

  auto
  ObjectProxy::get_connection () -> Glib::RefPtr<Connection>
  {
    auto retvalue = Glib::wrap (g_dbus_object_proxy_get_connection (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ObjectProxy::get_connection () const -> Glib::RefPtr<const Connection>
  {
    return const_cast<ObjectProxy*> (this)->get_connection ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Connection>>::value,
      "Type Glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ObjectProxy::property_g_connection () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>
  {
    return {this, "g-connection"};
  }

  auto
  ObjectProxy::property_g_object_path () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "g-object-path"};
  }

} // namespace Gio::DBus
