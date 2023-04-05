// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusinterfaceskeleton.hxx>
#include <libmm/gio/dbusinterfaceskeleton_p.hxx>

#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>

using Flags = gio::DBus::InterfaceSkeleton::Flags;

namespace
{

  auto
  InterfaceSkeleton_signal_authorize_method_callback (
      GDBusInterfaceSkeleton* self,
      GDBusMethodInvocation* p0,
      void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<bool (const glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<InterfaceSkeleton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  InterfaceSkeleton_signal_authorize_method_notify_callback (
      GDBusInterfaceSkeleton* self,
      GDBusMethodInvocation* p0,
      void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<InterfaceSkeleton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo InterfaceSkeleton_signal_authorize_method_info = {
      "g_authorize_method",
      (GCallback) &InterfaceSkeleton_signal_authorize_method_callback,
      (GCallback) &InterfaceSkeleton_signal_authorize_method_notify_callback};

} // namespace

auto
glib::Value<gio::DBus::InterfaceSkeleton::Flags>::value_type () -> GType
{
  return g_dbus_interface_skeleton_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GDBusInterfaceSkeleton* object, const bool take_copy) -> RefPtr<gio::DBus::InterfaceSkeleton>
  {
    return glib::make_refptr_for_instance<gio::DBus::InterfaceSkeleton> (
        dynamic_cast<gio::DBus::InterfaceSkeleton*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  InterfaceSkeleton_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &InterfaceSkeleton_Class::class_init_function;

      register_derived_type (g_dbus_interface_skeleton_get_type ());

      Interface::add_interface (get_type ());
    }

    return *this;
  }

  auto
  InterfaceSkeleton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->g_authorize_method = &g_authorize_method_callback;
  }

  auto
  InterfaceSkeleton_Class::g_authorize_method_callback (
      GDBusInterfaceSkeleton* self,
      GDBusMethodInvocation* p0) -> gboolean
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
          return obj->on_authorize_method (glib::wrap (p0, true));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->g_authorize_method)
      return (*base->g_authorize_method) (self, p0);

    using RType = gboolean;
    return RType ();
  }

  auto
  InterfaceSkeleton_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new InterfaceSkeleton ((GDBusInterfaceSkeleton*) object);
  }

  auto
  InterfaceSkeleton::gobj_copy () -> GDBusInterfaceSkeleton*
  {
    reference ();
    return gobj ();
  }

  InterfaceSkeleton::InterfaceSkeleton (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  InterfaceSkeleton::InterfaceSkeleton (GDBusInterfaceSkeleton* castitem)
    : Object ((GObject*) castitem)
  {
  }

  InterfaceSkeleton::InterfaceSkeleton (InterfaceSkeleton&& src) noexcept
    : Object (std::move (src)),
      Interface (std::move (src))
  {
  }

  auto
  InterfaceSkeleton::operator= (InterfaceSkeleton&& src) noexcept -> InterfaceSkeleton&
  {
    Object::operator= (std::move (src));
    Interface::operator= (std::move (src));
    return *this;
  }

  InterfaceSkeleton::~InterfaceSkeleton () noexcept = default;

  InterfaceSkeleton::CppClassType InterfaceSkeleton::interfaceskeleton_class_;

  auto
  InterfaceSkeleton::get_type () -> GType
  {
    return interfaceskeleton_class_.init ().get_type ();
  }

  auto
  InterfaceSkeleton::get_base_type () -> GType
  {
    return g_dbus_interface_skeleton_get_type ();
  }

  auto
  InterfaceSkeleton::flush () -> void
  {
    g_dbus_interface_skeleton_flush (gobj ());
  }

  auto
  InterfaceSkeleton::get_info () -> glib::RefPtr<InterfaceInfo>
  {
    return glib::wrap (g_dbus_interface_skeleton_get_info (gobj ()));
  }

  auto
  InterfaceSkeleton::get_info () const -> glib::RefPtr<const InterfaceInfo>
  {
    return const_cast<InterfaceSkeleton*> (this)->get_info ();
  }

  auto
  InterfaceSkeleton::get_properties () const -> glib::VariantBase
  {
    return glib::wrap (g_dbus_interface_skeleton_get_properties (
                           const_cast<GDBusInterfaceSkeleton*> (gobj ())),
                       false);
  }

  auto
  InterfaceSkeleton::export_interface_skeleton (
      const glib::RefPtr<Connection>& connection,
      const glib::ustring& object_path) -> void
  {
    GError* gerror = nullptr;
    g_dbus_interface_skeleton_export (gobj (),
                                      glib::unwrap (connection),
                                      object_path.c_str (),
                                      &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  InterfaceSkeleton::unexport () -> void
  {
    g_dbus_interface_skeleton_unexport (gobj ());
  }

  auto
  InterfaceSkeleton::unexport_from_connection (
      const glib::RefPtr<Connection>& connection) -> void
  {
    g_dbus_interface_skeleton_unexport_from_connection (
        gobj (),
        glib::unwrap (connection));
  }

  auto
  InterfaceSkeleton::get_connection () -> glib::RefPtr<Connection>
  {
    return glib::wrap (g_dbus_interface_skeleton_get_connection (gobj ()));
  }

  auto
  InterfaceSkeleton::get_connection () const -> glib::RefPtr<const Connection>
  {
    return const_cast<InterfaceSkeleton*> (this)->get_connection ();
  }

  auto
  InterfaceSkeleton::get_connections () -> std::vector<glib::RefPtr<Connection>>
  {
    return glib::ListHandler<glib::RefPtr<Connection>>::list_to_vector (
        g_dbus_interface_skeleton_get_connections (gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  InterfaceSkeleton::get_connections () const -> std::vector<glib::RefPtr<const Connection>>
  {
    return glib::ListHandler<glib::RefPtr<const Connection>>::list_to_vector (
        g_dbus_interface_skeleton_get_connections (
            const_cast<GDBusInterfaceSkeleton*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  InterfaceSkeleton::has_connection (
      const glib::RefPtr<const Connection>& connection) const -> bool
  {
    return g_dbus_interface_skeleton_has_connection (
        const_cast<GDBusInterfaceSkeleton*> (gobj ()),
        const_cast<GDBusConnection*> (glib::unwrap (connection)));
  }

  auto
  InterfaceSkeleton::get_object_path () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_interface_skeleton_get_object_path (
            const_cast<GDBusInterfaceSkeleton*> (gobj ())));
  }

  auto
  InterfaceSkeleton::get_flags () const -> Flags
  {
    return static_cast<Flags> (g_dbus_interface_skeleton_get_flags (
        const_cast<GDBusInterfaceSkeleton*> (gobj ())));
  }

  auto
  InterfaceSkeleton::set_flags (Flags flags) -> void
  {
    g_dbus_interface_skeleton_set_flags (
        gobj (),
        static_cast<GDBusInterfaceSkeletonFlags> (flags));
  }

  auto
  InterfaceSkeleton::signal_authorize_method () -> glib::SignalProxy<bool (const glib::RefPtr<MethodInvocation>&)>
  {
    return {this, &InterfaceSkeleton_signal_authorize_method_info};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  InterfaceSkeleton::property_g_flags () -> glib::PropertyProxy<Flags>
  {
    return {this, "g-flags"};
  }

  auto
  InterfaceSkeleton::property_g_flags () const -> glib::PropertyProxy_ReadOnly<Flags>
  {
    return {this, "g-flags"};
  }

  auto
  InterfaceSkeleton::on_authorize_method (
      const glib::RefPtr<MethodInvocation>& invocation) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->g_authorize_method)
      return (*base->g_authorize_method) (gobj (), glib::unwrap (invocation));

    using RType = bool;
    return RType ();
  }

} // namespace gio::DBus
