// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusobjectmanagerclient.hxx>
#include <libmm/gio/dbusobjectmanagerclient_p.hxx>

#include <gio/gio.h>

namespace
{
  auto
  get_proxy_type_callback (GDBusObjectManagerClient* manager,
                           const gchar* object_path,
                           const gchar* interface_name,
                           const gpointer user_data) -> GType
  {
    const auto slot_proxy_type =
        static_cast<gio::DBus::ObjectManagerClient::SlotProxyType*> (user_data);
    try
    {
      return (*slot_proxy_type) (
          glib::wrap (manager, true),
          glib::convert_const_gchar_ptr_to_ustring (object_path),
          glib::convert_const_gchar_ptr_to_ustring (interface_name));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return 0;
  }

} // namespace

namespace gio::DBus
{
  using MapChangedProperties = ObjectManagerClient::MapChangedProperties;
  using Flags = ObjectManagerClient::Flags;

  ObjectManagerClient::ObjectManagerClient (
      const glib::RefPtr<Connection>& connection,
      const glib::ustring& name,
      const glib::ustring& object_path,
      const SlotAsyncReady& slot_async_ready,
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotProxyType& slot_proxy_type,
      const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (
          objectmanagerclient_class_.init (),
          "connection",
          glib::unwrap (connection),
          "flags",
          flags,
          "name",
          c_str_or_nullptr (name),
          "object-path",
          c_str_or_nullptr (object_path),
          "get-proxy-type-func",
          slot_proxy_type ? get_proxy_type_callback : nullptr,
          "get-proxy-type-user-data",
          slot_proxy_type ? new SlotProxyType (slot_proxy_type) : nullptr,
          "get-proxy-type-destroy-notify",
          slot_proxy_type ? glib::destroy_notify_delete<SlotProxyType> :
                            nullptr,
          nullptr))
  {
    if (slot_async_ready)
    {
      if (cancellable)
        init_async (slot_async_ready, cancellable);
      else
        init_async (slot_async_ready);
    }
    else
    {
      if (cancellable)
        init (cancellable);
      else
        init ();
    }
  }

  ObjectManagerClient::ObjectManagerClient (
      const BusType bus_type,
      const glib::ustring& name,
      const glib::ustring& object_path,
      const SlotAsyncReady& slot_async_ready,
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotProxyType& slot_proxy_type,
      const Flags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (
          objectmanagerclient_class_.init (),
          "bus-type",
          bus_type,
          "flags",
          flags,
          "name",
          c_str_or_nullptr (name),
          "object-path",
          c_str_or_nullptr (object_path),
          "get-proxy-type-func",
          slot_proxy_type ? get_proxy_type_callback : nullptr,
          "get-proxy-type-user-data",
          slot_proxy_type ? new SlotProxyType (slot_proxy_type) : nullptr,
          "get-proxy-type-destroy-notify",
          slot_proxy_type ? glib::destroy_notify_delete<SlotProxyType> :
                            nullptr,
          nullptr))
  {
    if (slot_async_ready)
    {
      if (cancellable)
        init_async (slot_async_ready, cancellable);
      else
        init_async (slot_async_ready);
    }
    else
    {
      if (cancellable)
        init (cancellable);
      else
        init ();
    }
  }

  auto
  ObjectManagerClient::create (const glib::RefPtr<Connection>& connection,
                               const glib::ustring& name,
                               const glib::ustring& object_path,
                               const SlotAsyncReady& slot_async_ready,
                               const glib::RefPtr<Cancellable>& cancellable,
                               const SlotProxyType& slot_proxy_type,
                               const Flags flags) -> void
  {
    ObjectManagerClient (connection,
                         name,
                         object_path,
                         slot_async_ready,
                         cancellable,
                         slot_proxy_type,
                         flags);
  }

  auto
  ObjectManagerClient::create_sync (
      const glib::RefPtr<Connection>& connection,
      const glib::ustring& name,
      const glib::ustring& object_path,
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotProxyType& slot_proxy_type,
      const Flags flags) -> glib::RefPtr<ObjectManagerClient>
  {
    return glib::make_refptr_for_instance<ObjectManagerClient> (
        new ObjectManagerClient (connection,
                                 name,
                                 object_path,
                                 {},
                                 cancellable,
                                 slot_proxy_type,
                                 flags));
  }

  auto
  ObjectManagerClient::create_for_bus (
      const BusType bus_type,
      const glib::ustring& name,
      const glib::ustring& object_path,
      const SlotAsyncReady& slot_async_ready,
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotProxyType& slot_proxy_type,
      const Flags flags) -> void
  {
    ObjectManagerClient (bus_type,
                         name,
                         object_path,
                         slot_async_ready,
                         cancellable,
                         slot_proxy_type,
                         flags);
  }

  auto
  ObjectManagerClient::create_for_bus_sync (
      const BusType bus_type,
      const glib::ustring& name,
      const glib::ustring& object_path,
      const glib::RefPtr<Cancellable>& cancellable,
      const SlotProxyType& slot_proxy_type,
      const Flags flags) -> glib::RefPtr<ObjectManagerClient>
  {
    return glib::make_refptr_for_instance<ObjectManagerClient> (
        new ObjectManagerClient (bus_type,
                                 name,
                                 object_path,
                                 {},
                                 cancellable,
                                 slot_proxy_type,
                                 flags));
  }

} // namespace gio::DBus

namespace
{

  auto
  ObjectManagerClient_signal_interface_proxy_signal_callback (
      GDBusObjectManagerClient* self,
      GDBusObjectProxy* p0,
      GDBusProxy* p1,
      const gchar* p2,
      const gchar* p3,
      GVariant* p4,
      void* data) -> void
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<ObjectProxy>&,
                                      const glib::RefPtr<Proxy>&,
                                      const glib::ustring&,
                                      const glib::ustring&,
                                      const glib::VariantContainerBase&)>;

    const auto obj = dynamic_cast<ObjectManagerClient*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              glib::wrap (p1, true),
              glib::convert_const_gchar_ptr_to_ustring (p2),
              glib::convert_const_gchar_ptr_to_ustring (p3),
              glib::VariantContainerBase (p4, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo
      ObjectManagerClient_signal_interface_proxy_signal_info = {
          "interface-proxy-signal",
          (GCallback) &ObjectManagerClient_signal_interface_proxy_signal_callback,
          (GCallback) &ObjectManagerClient_signal_interface_proxy_signal_callback};

  auto
  ObjectManagerClient_signal_interface_proxy_properties_changed_callback (
      GDBusObjectManagerClient* self,
      GDBusObjectProxy* p0,
      GDBusProxy* p1,
      GVariant* p2,
      const gchar* const* p3,
      void* data) -> void
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<ObjectProxy>&,
                                      const glib::RefPtr<Proxy>&,
                                      const MapChangedProperties&,
                                      const std::vector<glib::ustring>&)>;

    const auto obj = dynamic_cast<ObjectManagerClient*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              glib::wrap (p1, true),
              glib::Variant<MapChangedProperties> (p2, true).get (),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p3,
                  glib::OWNERSHIP_NONE));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo
      ObjectManagerClient_signal_interface_proxy_properties_changed_info = {
          "interface-proxy-properties-changed",
          (GCallback) &ObjectManagerClient_signal_interface_proxy_properties_changed_callback,
          (GCallback) &ObjectManagerClient_signal_interface_proxy_properties_changed_callback};

} // namespace

auto
glib::Value<gio::DBus::ObjectManagerClient::Flags>::value_type () -> GType
{
  return g_dbus_object_manager_client_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GDBusObjectManagerClient* object, const bool take_copy) -> RefPtr<gio::DBus::ObjectManagerClient>
  {
    return glib::make_refptr_for_instance<gio::DBus::ObjectManagerClient> (
        dynamic_cast<gio::DBus::ObjectManagerClient*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  ObjectManagerClient_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ObjectManagerClient_Class::class_init_function;

      register_derived_type (g_dbus_object_manager_client_get_type ());

      Initable::add_interface (get_type ());
      AsyncInitable::add_interface (get_type ());
      ObjectManager::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ObjectManagerClient_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->interface_proxy_signal = &interface_proxy_signal_callback;
    klass->interface_proxy_properties_changed =
        &interface_proxy_properties_changed_callback;
  }

  auto
  ObjectManagerClient_Class::interface_proxy_signal_callback (
      GDBusObjectManagerClient* self,
      GDBusObjectProxy* p0,
      GDBusProxy* p1,
      const gchar* p2,
      const gchar* p3,
      GVariant* p4) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_interface_proxy_signal (
              glib::wrap (p0, true),
              glib::wrap (p1, true),
              glib::convert_const_gchar_ptr_to_ustring (p2),
              glib::convert_const_gchar_ptr_to_ustring (p3),
              glib::VariantContainerBase (p4, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->interface_proxy_signal)
      (*base->interface_proxy_signal) (self, p0, p1, p2, p3, p4);
  }

  auto
  ObjectManagerClient_Class::interface_proxy_properties_changed_callback (
      GDBusObjectManagerClient* self,
      GDBusObjectProxy* p0,
      GDBusProxy* p1,
      GVariant* p2,
      const gchar* const* p3) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_interface_proxy_properties_changed (
              glib::wrap (p0, true),
              glib::wrap (p1, true),
              glib::Variant<MapChangedProperties> (p2, true).get (),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p3,
                  glib::OWNERSHIP_NONE));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->interface_proxy_properties_changed)
      (*base->interface_proxy_properties_changed) (self, p0, p1, p2, p3);
  }

  auto
  ObjectManagerClient_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ObjectManagerClient ((GDBusObjectManagerClient*) object);
  }

  auto
  ObjectManagerClient::gobj_copy () -> GDBusObjectManagerClient*
  {
    reference ();
    return gobj ();
  }

  ObjectManagerClient::ObjectManagerClient (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ObjectManagerClient::ObjectManagerClient (GDBusObjectManagerClient* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ObjectManagerClient::ObjectManagerClient (ObjectManagerClient&& src) noexcept
    : Object (std::move (src)),
      Initable (std::move (src)),
      AsyncInitable (std::move (src)),
      ObjectManager (std::move (src))
  {
  }

  auto
  ObjectManagerClient::operator= (ObjectManagerClient&& src) noexcept -> ObjectManagerClient&
  {
    Object::operator= (std::move (src));
    Initable::operator= (std::move (src));
    AsyncInitable::operator= (std::move (src));
    ObjectManager::operator= (std::move (src));
    return *this;
  }

  ObjectManagerClient::~ObjectManagerClient () noexcept = default;

  ObjectManagerClient::CppClassType
      ObjectManagerClient::objectmanagerclient_class_;

  auto
  ObjectManagerClient::get_type () -> GType
  {
    return objectmanagerclient_class_.init ().get_type ();
  }

  auto
  ObjectManagerClient::get_base_type () -> GType
  {
    return g_dbus_object_manager_client_get_type ();
  }

  auto
  ObjectManagerClient::create_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<ObjectManagerClient>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        (GDBusObjectManagerClient*) g_dbus_object_manager_client_new_finish (
            glib::unwrap (res),
            &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  ObjectManagerClient::create_for_bus_finish (
      const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<ObjectManagerClient>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        (GDBusObjectManagerClient*)
            g_dbus_object_manager_client_new_for_bus_finish (glib::unwrap (res),
                                                             &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  ObjectManagerClient::get_connection () -> glib::RefPtr<Connection>
  {
    auto retvalue =
        glib::wrap (g_dbus_object_manager_client_get_connection (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ObjectManagerClient::get_connection () const -> glib::RefPtr<const Connection>
  {
    return const_cast<ObjectManagerClient*> (this)->get_connection ();
  }

  auto
  ObjectManagerClient::get_flags () const -> Flags
  {
    return static_cast<Flags> (g_dbus_object_manager_client_get_flags (
        const_cast<GDBusObjectManagerClient*> (gobj ())));
  }

  auto
  ObjectManagerClient::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_object_manager_client_get_name (
            const_cast<GDBusObjectManagerClient*> (gobj ())));
  }

  auto
  ObjectManagerClient::get_name_owner () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_dbus_object_manager_client_get_name_owner (
            const_cast<GDBusObjectManagerClient*> (gobj ())));
  }

  auto
  ObjectManagerClient::signal_interface_proxy_signal () -> glib::SignalProxy<void (const glib::RefPtr<ObjectProxy>&,
                                 const glib::RefPtr<Proxy>&,
                                 const glib::ustring&,
                                 const glib::ustring&,
                                 const glib::VariantContainerBase&)>
  {
    return {this, &ObjectManagerClient_signal_interface_proxy_signal_info};
  }

  auto
  ObjectManagerClient::signal_interface_proxy_properties_changed () -> glib::SignalProxy<void (const glib::RefPtr<ObjectProxy>&,
                                 const glib::RefPtr<Proxy>&,
                                 const MapChangedProperties&,
                                 const std::vector<glib::ustring>&)>
  {
    return {
        this,
        &ObjectManagerClient_signal_interface_proxy_properties_changed_info};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Connection>>::value,
      "Type glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ObjectManagerClient::property_connection () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>
  {
    return {this, "connection"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ObjectManagerClient::property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>
  {
    return {this, "flags"};
  }

  auto
  ObjectManagerClient::property_object_path () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "object-path"};
  }

  auto
  ObjectManagerClient::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  ObjectManagerClient::property_name_owner () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name-owner"};
  }

  auto
  ObjectManagerClient::on_interface_proxy_signal (
      const glib::RefPtr<ObjectProxy>& object_proxy,
      const glib::RefPtr<Proxy>& interface_proxy,
      const glib::ustring& sender_name,
      const glib::ustring& signal_name,
      const glib::VariantContainerBase& parameters) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->interface_proxy_signal)
      (*base->interface_proxy_signal) (
          gobj (),
          glib::unwrap (object_proxy),
          glib::unwrap (interface_proxy),
          sender_name.c_str (),
          signal_name.c_str (),
          const_cast<GVariant*> (parameters.gobj ()));
  }

  auto
  ObjectManagerClient::on_interface_proxy_properties_changed (
      const glib::RefPtr<ObjectProxy>& object_proxy,
      const glib::RefPtr<Proxy>& interface_proxy,
      const MapChangedProperties& changed_properties,
      const std::vector<glib::ustring>& invalidated_properties) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->interface_proxy_properties_changed)
      (*base->interface_proxy_properties_changed) (
          gobj (),
          glib::unwrap (object_proxy),
          glib::unwrap (interface_proxy),
          glib::Variant<MapChangedProperties>::create (changed_properties)
              .gobj (),
          glib::ArrayHandler<glib::ustring>::vector_to_array (
              invalidated_properties)
              .data ());
  }

} // namespace gio::DBus
