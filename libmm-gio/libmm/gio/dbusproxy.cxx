// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusproxy.hxx>
#include <libmm/gio/dbusproxy_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/vectorutils.hxx>

namespace gio::DBus
{

  using MapChangedProperties = Proxy::MapChangedProperties;

  Proxy::Proxy (const glib::RefPtr<Connection>& connection,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-connection",
                                     glib::unwrap (connection),
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Proxy::Proxy (const glib::RefPtr<Connection>& connection,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const SlotAsyncReady& slot,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-connection",
                                     glib::unwrap (connection),
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init_async (slot);
  }

  Proxy::Proxy (const glib::RefPtr<Connection>& connection,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const glib::RefPtr<Cancellable>& cancellable,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-connection",
                                     glib::unwrap (connection),
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init (cancellable);
  }

  Proxy::Proxy (const glib::RefPtr<Connection>& connection,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-connection",
                                     glib::unwrap (connection),
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init ();
  }

  Proxy::Proxy (const BusType bus_type,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-bus-type",
                                     bus_type,
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init_async (slot, cancellable);
  }

  Proxy::Proxy (const BusType bus_type,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const SlotAsyncReady& slot,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-bus-type",
                                     bus_type,
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init_async (slot);
  }

  Proxy::Proxy (const BusType bus_type,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const glib::RefPtr<Cancellable>& cancellable,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-bus-type",
                                     bus_type,
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init (cancellable);
  }

  Proxy::Proxy (const BusType bus_type,
                const glib::ustring& name,
                const glib::ustring& object_path,
                const glib::ustring& interface_name,
                const glib::RefPtr<InterfaceInfo>& info,
                const ProxyFlags flags)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (proxy_class_.init (),
                                     "g-bus-type",
                                     bus_type,
                                     "g-flags",
                                     flags,
                                     "g-interface-info",
                                     glib::unwrap (info),
                                     "g-name",
                                     c_str_or_nullptr (name),
                                     "g-object-path",
                                     c_str_or_nullptr (object_path),
                                     "g-interface-name",
                                     c_str_or_nullptr (interface_name),
                                     nullptr))
  {
    init ();
  }

  auto
  Proxy::create (const glib::RefPtr<Connection>& connection,
                 const glib::ustring& name,
                 const glib::ustring& object_path,
                 const glib::ustring& interface_name,
                 const SlotAsyncReady& slot,
                 const glib::RefPtr<Cancellable>& cancellable,
                 const glib::RefPtr<InterfaceInfo>& info,
                 const ProxyFlags flags) -> void
  {
    Proxy (connection,
           name,
           object_path,
           interface_name,
           slot,
           cancellable,
           info,
           flags);
  }

  auto
  Proxy::create (const glib::RefPtr<Connection>& connection,
                 const glib::ustring& name,
                 const glib::ustring& object_path,
                 const glib::ustring& interface_name,
                 const SlotAsyncReady& slot,
                 const glib::RefPtr<InterfaceInfo>& info,
                 const ProxyFlags flags) -> void
  {
    Proxy (connection, name, object_path, interface_name, slot, info, flags);
  }

  auto
  Proxy::create_sync (const glib::RefPtr<Connection>& connection,
                      const glib::ustring& name,
                      const glib::ustring& object_path,
                      const glib::ustring& interface_name,
                      const glib::RefPtr<Cancellable>& cancellable,
                      const glib::RefPtr<InterfaceInfo>& info,
                      const ProxyFlags flags) -> glib::RefPtr<Proxy>
  {
    return glib::make_refptr_for_instance<Proxy> (new Proxy (connection,
                                                             name,
                                                             object_path,
                                                             interface_name,
                                                             cancellable,
                                                             info,
                                                             flags));
  }

  auto
  Proxy::create_sync (const glib::RefPtr<Connection>& connection,
                      const glib::ustring& name,
                      const glib::ustring& object_path,
                      const glib::ustring& interface_name,
                      const glib::RefPtr<InterfaceInfo>& info,
                      const ProxyFlags flags) -> glib::RefPtr<Proxy>
  {
    return glib::make_refptr_for_instance<Proxy> (
        new Proxy (connection, name, object_path, interface_name, info, flags));
  }

  auto
  Proxy::create_for_bus (const BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const SlotAsyncReady& slot,
                         const glib::RefPtr<Cancellable>& cancellable,
                         const glib::RefPtr<InterfaceInfo>& info,
                         const ProxyFlags flags) -> void
  {
    Proxy (bus_type,
           name,
           object_path,
           interface_name,
           slot,
           cancellable,
           info,
           flags);
  }

  auto
  Proxy::create_for_bus (const BusType bus_type,
                         const glib::ustring& name,
                         const glib::ustring& object_path,
                         const glib::ustring& interface_name,
                         const SlotAsyncReady& slot,
                         const glib::RefPtr<InterfaceInfo>& info,
                         const ProxyFlags flags) -> void
  {
    Proxy (bus_type, name, object_path, interface_name, slot, info, flags);
  }

  auto
  Proxy::create_for_bus_sync (const BusType bus_type,
                              const glib::ustring& name,
                              const glib::ustring& object_path,
                              const glib::ustring& interface_name,
                              const glib::RefPtr<Cancellable>& cancellable,
                              const glib::RefPtr<InterfaceInfo>& info,
                              const ProxyFlags flags) -> glib::RefPtr<Proxy>
  {
    return glib::make_refptr_for_instance<Proxy> (new Proxy (bus_type,
                                                             name,
                                                             object_path,
                                                             interface_name,
                                                             cancellable,
                                                             info,
                                                             flags));
  }

  auto
  Proxy::create_for_bus_sync (const BusType bus_type,
                              const glib::ustring& name,
                              const glib::ustring& object_path,
                              const glib::ustring& interface_name,
                              const glib::RefPtr<InterfaceInfo>& info,
                              const ProxyFlags flags) -> glib::RefPtr<Proxy>
  {
    return glib::make_refptr_for_instance<Proxy> (
        new Proxy (bus_type, name, object_path, interface_name, info, flags));
  }

  auto
  Proxy::get_cached_property (glib::VariantBase& property,
                              const glib::ustring& property_name) const -> void
  {
    const GVariant* const g_variant = g_dbus_proxy_get_cached_property (
        const_cast<GDBusProxy*> (gobj ()),
        property_name.c_str ());

    property.init (g_variant, false);
  }

} // namespace gio::DBus

namespace
{

  auto
  Proxy_signal_properties_changed_callback (GDBusProxy* self,
                                            GVariant* p0,
                                            const gchar* const* p1,
                                            void* data) -> void
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const MapChangedProperties&,
                                      const std::vector<glib::ustring>&)>;

    const auto obj = dynamic_cast<Proxy*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::Variant<MapChangedProperties> (p0, true).get (),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p1,
                  glib::OWNERSHIP_NONE));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo Proxy_signal_properties_changed_info = {
      "g-properties-changed",
      (GCallback) &Proxy_signal_properties_changed_callback,
      (GCallback) &Proxy_signal_properties_changed_callback};

  auto
  Proxy_signal_signal_callback (GDBusProxy* self,
                                const gchar* p0,
                                const gchar* p1,
                                GVariant* p2,
                                void* data) -> void
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::ustring&,
                                      const glib::ustring&,
                                      const glib::VariantContainerBase&)>;

    const auto obj = dynamic_cast<Proxy*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              glib::convert_const_gchar_ptr_to_ustring (p1),
              glib::VariantContainerBase (p2, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo Proxy_signal_signal_info = {
      "g-signal",
      (GCallback) &Proxy_signal_signal_callback,
      (GCallback) &Proxy_signal_signal_callback};

} // namespace

auto
glib::Value<gio::DBus::ProxyFlags>::value_type () -> GType
{
  return g_dbus_proxy_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GDBusProxy* object, const bool take_copy) -> RefPtr<gio::DBus::Proxy>
  {
    return glib::make_refptr_for_instance<gio::DBus::Proxy> (
        dynamic_cast<gio::DBus::Proxy*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  Proxy_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Proxy_Class::class_init_function;

      register_derived_type (g_dbus_proxy_get_type ());

      Initable::add_interface (get_type ());
      AsyncInitable::add_interface (get_type ());
      Interface::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Proxy_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->g_properties_changed = &g_properties_changed_callback;
    klass->g_signal = &g_signal_callback;
  }

  auto
  Proxy_Class::g_properties_changed_callback (GDBusProxy* self,
                                              GVariant* p0,
                                              const gchar* const* p1) -> void
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
          obj->on_properties_changed (
              glib::Variant<MapChangedProperties> (p0, true).get (),
              glib::ArrayHandler<glib::ustring>::array_to_vector (
                  p1,
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

    if (base && base->g_properties_changed)
      (*base->g_properties_changed) (self, p0, p1);
  }

  auto
  Proxy_Class::g_signal_callback (GDBusProxy* self,
                                  const gchar* p0,
                                  const gchar* p1,
                                  GVariant* p2) -> void
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
          obj->on_signal (glib::convert_const_gchar_ptr_to_ustring (p0),
                          glib::convert_const_gchar_ptr_to_ustring (p1),
                          glib::VariantContainerBase (p2, true));
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

    if (base && base->g_signal)
      (*base->g_signal) (self, p0, p1, p2);
  }

  auto
  Proxy_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Proxy ((GDBusProxy*) object);
  }

  auto
  Proxy::gobj_copy () -> GDBusProxy*
  {
    reference ();
    return gobj ();
  }

  Proxy::Proxy (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Proxy::Proxy (GDBusProxy* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Proxy::Proxy (Proxy&& src) noexcept
    : Object (std::move (src)),
      Initable (std::move (src)),
      AsyncInitable (std::move (src)),
      DBus::Interface (std::move (src))
  {
  }

  auto
  Proxy::operator= (Proxy&& src) noexcept -> Proxy&
  {
    Object::operator= (std::move (src));
    Initable::operator= (std::move (src));
    AsyncInitable::operator= (std::move (src));
    DBus::Interface::operator= (std::move (src));
    return *this;
  }

  Proxy::~Proxy () noexcept = default;

  Proxy::CppClassType Proxy::proxy_class_;

  auto
  Proxy::get_type () -> GType
  {
    return proxy_class_.init ().get_type ();
  }

  auto
  Proxy::get_base_type () -> GType
  {
    return g_dbus_proxy_get_type ();
  }

  auto
  Proxy::create_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Proxy>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_dbus_proxy_new_finish (glib::unwrap (res), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::create_for_bus_finish (const glib::RefPtr<AsyncResult>& res) -> glib::RefPtr<Proxy>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        g_dbus_proxy_new_for_bus_finish (glib::unwrap (res), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::get_flags () const -> ProxyFlags
  {
    return static_cast<ProxyFlags> (
        g_dbus_proxy_get_flags (const_cast<GDBusProxy*> (gobj ())));
  }

  auto
  Proxy::get_connection () -> glib::RefPtr<Connection>
  {
    auto retvalue = glib::wrap (g_dbus_proxy_get_connection (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Proxy::get_connection () const -> glib::RefPtr<const Connection>
  {
    return const_cast<Proxy*> (this)->get_connection ();
  }

  auto
  Proxy::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_proxy_get_name (const_cast<GDBusProxy*> (gobj ())));
  }

  auto
  Proxy::get_name_owner () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_dbus_proxy_get_name_owner (const_cast<GDBusProxy*> (gobj ())));
  }

  auto
  Proxy::get_object_path () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_proxy_get_object_path (const_cast<GDBusProxy*> (gobj ())));
  }

  auto
  Proxy::get_interface_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_proxy_get_interface_name (const_cast<GDBusProxy*> (gobj ())));
  }

  auto
  Proxy::get_default_timeout () const -> int
  {
    return g_dbus_proxy_get_default_timeout (const_cast<GDBusProxy*> (gobj ()));
  }

  auto
  Proxy::set_default_timeout (const int timeout_msec) -> void
  {
    g_dbus_proxy_set_default_timeout (gobj (), timeout_msec);
  }

  auto
  Proxy::set_cached_property (const glib::ustring& property_name,
                              const glib::VariantBase& value) -> void
  {
    g_dbus_proxy_set_cached_property (gobj (),
                                      property_name.c_str (),
                                      const_cast<GVariant*> (value.gobj ()));
  }

  auto
  Proxy::get_cached_property_names () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_dbus_proxy_get_cached_property_names (
            const_cast<GDBusProxy*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Proxy::set_interface_info (const glib::RefPtr<InterfaceInfo>& info) -> void
  {
    g_dbus_proxy_set_interface_info (gobj (), glib::unwrap (info));
  }

  auto
  Proxy::get_interface_info () -> glib::RefPtr<InterfaceInfo>
  {
    auto retvalue = glib::wrap (g_dbus_proxy_get_interface_info (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Proxy::get_interface_info () const -> glib::RefPtr<const InterfaceInfo>
  {
    return const_cast<Proxy*> (this)->get_interface_info ();
  }

  auto
  Proxy::call (const glib::ustring& method_name,
               const SlotAsyncReady& slot,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::VariantContainerBase& parameters,
               const int timeout_msec,
               CallFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_proxy_call (gobj (),
                       method_name.c_str (),
                       const_cast<GVariant*> (parameters.gobj ()),
                       static_cast<GDBusCallFlags> (flags),
                       timeout_msec,
                       glib::unwrap (cancellable),
                       &SignalProxy_async_callback,
                       slot_copy);
  }

  auto
  Proxy::call (const glib::ustring& method_name,
               const SlotAsyncReady& slot,
               const glib::VariantContainerBase& parameters,
               const int timeout_msec,
               CallFlags flags) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_proxy_call (gobj (),
                       method_name.c_str (),
                       const_cast<GVariant*> (parameters.gobj ()),
                       static_cast<GDBusCallFlags> (flags),
                       timeout_msec,
                       nullptr,
                       &SignalProxy_async_callback,
                       slot_copy);
  }

  auto
  Proxy::call (const glib::ustring& method_name,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::VariantContainerBase& parameters,
               const int timeout_msec,
               CallFlags flags) -> void
  {
    g_dbus_proxy_call (gobj (),
                       method_name.c_str (),
                       const_cast<GVariant*> (parameters.gobj ()),
                       static_cast<GDBusCallFlags> (flags),
                       timeout_msec,
                       glib::unwrap (cancellable),
                       nullptr,
                       nullptr);
  }

  auto
  Proxy::call (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const int timeout_msec,
               CallFlags flags) -> void
  {
    g_dbus_proxy_call (gobj (),
                       method_name.c_str (),
                       const_cast<GVariant*> (parameters.gobj ()),
                       static_cast<GDBusCallFlags> (flags),
                       timeout_msec,
                       nullptr,
                       nullptr,
                       nullptr);
  }

  auto
  Proxy::call_finish (const glib::RefPtr<AsyncResult>& res) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_finish (gobj (), glib::unwrap (res), &gerror),
        false);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::call_sync (const glib::ustring& method_name,
                    const glib::RefPtr<Cancellable>& cancellable,
                    const glib::VariantContainerBase& parameters,
                    const int timeout_msec,
                    CallFlags flags) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_sync (gobj (),
                                method_name.c_str (),
                                const_cast<GVariant*> (parameters.gobj ()),
                                static_cast<GDBusCallFlags> (flags),
                                timeout_msec,
                                glib::unwrap (cancellable),
                                &gerror),
        false);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Proxy::call_sync (const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const int timeout_msec,
                    CallFlags flags) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_sync (gobj (),
                                method_name.c_str (),
                                const_cast<GVariant*> (parameters.gobj ()),
                                static_cast<GDBusCallFlags> (flags),
                                timeout_msec,
                                nullptr,
                                &gerror),
        false);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

#ifdef G_OS_UNIX
  void
  Proxy::call (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const SlotAsyncReady& slot,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::RefPtr<UnixFDList>& fd_list,
               int timeout_msec,
               CallFlags flags)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_proxy_call_with_unix_fd_list (
        gobj (),
        method_name.c_str (),
        const_cast<GVariant*> ((parameters).gobj ()),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &SignalProxy_async_callback,
        slot_copy);
  }
#endif

#ifdef G_OS_UNIX
  void
  Proxy::call (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const SlotAsyncReady& slot,
               const glib::RefPtr<UnixFDList>& fd_list,
               int timeout_msec,
               CallFlags flags)
  {
    auto slot_copy = new SlotAsyncReady (slot);

    g_dbus_proxy_call_with_unix_fd_list (
        gobj (),
        method_name.c_str (),
        const_cast<GVariant*> ((parameters).gobj ()),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        nullptr,
        &SignalProxy_async_callback,
        slot_copy);
  }
#endif

#ifdef G_OS_UNIX
  void
  Proxy::call (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<Cancellable>& cancellable,
               const glib::RefPtr<UnixFDList>& fd_list,
               int timeout_msec,
               CallFlags flags)
  {
    g_dbus_proxy_call_with_unix_fd_list (
        gobj (),
        method_name.c_str (),
        const_cast<GVariant*> ((parameters).gobj ()),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        nullptr,
        nullptr);
  }
#endif

#ifdef G_OS_UNIX
  void
  Proxy::call (const glib::ustring& method_name,
               const glib::VariantContainerBase& parameters,
               const glib::RefPtr<UnixFDList>& fd_list,
               int timeout_msec,
               CallFlags flags)
  {
    g_dbus_proxy_call_with_unix_fd_list (
        gobj (),
        method_name.c_str (),
        const_cast<GVariant*> ((parameters).gobj ()),
        static_cast<GDBusCallFlags> (flags),
        timeout_msec,
        glib::unwrap (fd_list),
        nullptr,
        nullptr,
        nullptr);
  }
#endif

#ifdef G_OS_UNIX
  auto
  Proxy::call_finish (const glib::RefPtr<AsyncResult>& res,
                      glib::RefPtr<UnixFDList>& out_fd_list) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_with_unix_fd_list_finish (gobj (),
                                                    &g_out_fd_list,
                                                    glib::unwrap (res),
                                                    &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Proxy::call_sync (const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const glib::RefPtr<Cancellable>& cancellable,
                    const glib::RefPtr<UnixFDList>& fd_list,
                    glib::RefPtr<UnixFDList>& out_fd_list,
                    int timeout_msec,
                    CallFlags flags) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_with_unix_fd_list_sync (
            gobj (),
            method_name.c_str (),
            const_cast<GVariant*> ((parameters).gobj ()),
            static_cast<GDBusCallFlags> (flags),
            timeout_msec,
            glib::unwrap (fd_list),
            &g_out_fd_list,
            const_cast<GCancellable*> (glib::unwrap (cancellable)),
            &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

#ifdef G_OS_UNIX
  auto
  Proxy::call_sync (const glib::ustring& method_name,
                    const glib::VariantContainerBase& parameters,
                    const glib::RefPtr<UnixFDList>& fd_list,
                    glib::RefPtr<UnixFDList>& out_fd_list,
                    int timeout_msec,
                    CallFlags flags) -> glib::VariantContainerBase
  {
    GError* gerror = nullptr;
    GUnixFDList* g_out_fd_list = nullptr;
    auto retvalue = glib::VariantContainerBase (
        g_dbus_proxy_call_with_unix_fd_list_sync (
            gobj (),
            method_name.c_str (),
            const_cast<GVariant*> ((parameters).gobj ()),
            static_cast<GDBusCallFlags> (flags),
            timeout_msec,
            glib::unwrap (fd_list),
            &g_out_fd_list,
            nullptr,
            &(gerror)),
        false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_fd_list = glib::wrap (g_out_fd_list);
    return retvalue;
  }
#endif

  auto
  Proxy::signal_properties_changed () -> glib::SignalProxy<void (const MapChangedProperties&,
                                 const std::vector<glib::ustring>&)>
  {
    return {this, &Proxy_signal_properties_changed_info};
  }

  auto
  Proxy::signal_signal () -> glib::SignalProxy<void (const glib::ustring&,
                                 const glib::ustring&,
                                 const glib::VariantContainerBase&)>
  {
    return {this, &Proxy_signal_signal_info};
  }

  auto
  Proxy::signal_signal (const glib::ustring& signal_name) -> glib::SignalProxyDetailed<void (const glib::ustring&,
                                         const glib::ustring&,
                                         const glib::VariantContainerBase&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&,
                                           const glib::ustring&,
                                           const glib::VariantContainerBase&)> (
        this,
        &Proxy_signal_signal_info,
        signal_name);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Connection>>::value,
      "Type glib::RefPtr<Connection> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Proxy::property_g_connection () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>
  {
    return {this, "g-connection"};
  }

  auto
  Proxy::property_g_default_timeout () -> glib::PropertyProxy<int>
  {
    return {this, "g-default-timeout"};
  }

  auto
  Proxy::property_g_default_timeout () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "g-default-timeout"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ProxyFlags>::value,
      "Type ProxyFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Proxy::property_g_flags () const -> glib::PropertyProxy_ReadOnly<ProxyFlags>
  {
    return {this, "g-flags"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<InterfaceInfo>>::value,
      "Type glib::RefPtr<InterfaceInfo> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Proxy::property_g_interface_info () -> glib::PropertyProxy<glib::RefPtr<InterfaceInfo>>
  {
    return {this, "g-interface-info"};
  }

  auto
  Proxy::property_g_interface_info () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InterfaceInfo>>
  {
    return {this, "g-interface-info"};
  }

  auto
  Proxy::property_g_interface_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-interface-name"};
  }

  auto
  Proxy::property_g_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-name"};
  }

  auto
  Proxy::property_g_name_owner () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-name-owner"};
  }

  auto
  Proxy::property_g_object_path () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-object-path"};
  }

  auto
  Proxy::on_properties_changed (
      const MapChangedProperties& changed_properties,
      const std::vector<glib::ustring>& invalidated_properties) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->g_properties_changed)
      (*base->g_properties_changed) (
          gobj (),
          glib::Variant<MapChangedProperties>::create (changed_properties)
              .gobj (),
          glib::ArrayHandler<glib::ustring>::vector_to_array (
              invalidated_properties)
              .data ());
  }

  auto
  Proxy::on_signal (const glib::ustring& sender_name,
                    const glib::ustring& signal_name,
                    const glib::VariantContainerBase& parameters) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->g_signal)
      (*base->g_signal) (gobj (),
                         sender_name.c_str (),
                         signal_name.c_str (),
                         const_cast<GVariant*> (parameters.gobj ()));
  }

} // namespace gio::DBus
