// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusobjectskeleton.hxx>
#include <libmm/gio/dbusobjectskeleton_p.hxx>

#include <gio/gio.h>

namespace
{

  auto
  ObjectSkeleton_signal_authorize_method_callback (GDBusObjectSkeleton* self,
                                                   GDBusInterfaceSkeleton* p0,
                                                   GDBusMethodInvocation* p1,
                                                   void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<bool (const glib::RefPtr<InterfaceSkeleton>&,
                                      const glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<ObjectSkeleton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                                   glib::wrap (p1, true));
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
  ObjectSkeleton_signal_authorize_method_notify_callback (
      GDBusObjectSkeleton* self,
      GDBusInterfaceSkeleton* p0,
      GDBusMethodInvocation* p1,
      void* data) -> gboolean
  {
    using namespace gio::DBus;
    using SlotType = sigc::slot<void (const glib::RefPtr<InterfaceSkeleton>&,
                                      const glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<ObjectSkeleton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                            glib::wrap (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo ObjectSkeleton_signal_authorize_method_info = {
      "authorize-method",
      (GCallback) &ObjectSkeleton_signal_authorize_method_callback,
      (GCallback) &ObjectSkeleton_signal_authorize_method_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GDBusObjectSkeleton* object, const bool take_copy) -> RefPtr<gio::DBus::ObjectSkeleton>
  {
    return glib::make_refptr_for_instance<gio::DBus::ObjectSkeleton> (
        dynamic_cast<gio::DBus::ObjectSkeleton*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  ObjectSkeleton_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ObjectSkeleton_Class::class_init_function;

      register_derived_type (g_dbus_object_skeleton_get_type ());

      Object::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ObjectSkeleton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->authorize_method = &authorize_method_callback;
  }

  auto
  ObjectSkeleton_Class::authorize_method_callback (GDBusObjectSkeleton* self,
                                                   GDBusInterfaceSkeleton* p0,
                                                   GDBusMethodInvocation* p1) -> gboolean
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
          return obj->on_authorize_method (glib::wrap (p0, true),
                                           glib::wrap (p1, true));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->authorize_method)
      return (*base->authorize_method) (self, p0, p1);

    using RType = gboolean;
    return RType ();
  }

  auto
  ObjectSkeleton_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ObjectSkeleton ((GDBusObjectSkeleton*) object);
  }

  auto
  ObjectSkeleton::gobj_copy () -> GDBusObjectSkeleton*
  {
    reference ();
    return gobj ();
  }

  ObjectSkeleton::ObjectSkeleton (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ObjectSkeleton::ObjectSkeleton (GDBusObjectSkeleton* castitem)
    : glib::Object ((GObject*) castitem)
  {
  }

  ObjectSkeleton::ObjectSkeleton (ObjectSkeleton&& src) noexcept
    : glib::Object (std::move (src)),
      DBus::Object (std::move (src))
  {
  }

  auto
  ObjectSkeleton::operator= (ObjectSkeleton&& src) noexcept -> ObjectSkeleton&
  {
    glib::Object::operator= (std::move (src));
    DBus::Object::operator= (std::move (src));
    return *this;
  }

  ObjectSkeleton::~ObjectSkeleton () noexcept = default;

  ObjectSkeleton::CppClassType ObjectSkeleton::objectskeleton_class_;

  auto
  ObjectSkeleton::get_type () -> GType
  {
    return objectskeleton_class_.init ().get_type ();
  }

  auto
  ObjectSkeleton::get_base_type () -> GType
  {
    return g_dbus_object_skeleton_get_type ();
  }

  ObjectSkeleton::ObjectSkeleton (const glib::ustring& object_path)
    : ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (objectskeleton_class_.init (),
                                           "object_path",
                                           object_path.c_str (),
                                           nullptr))
  {
  }

  auto
  ObjectSkeleton::create (const glib::ustring& object_path) -> glib::RefPtr<ObjectSkeleton>
  {
    return glib::make_refptr_for_instance<ObjectSkeleton> (
        new ObjectSkeleton (object_path));
  }

  auto
  ObjectSkeleton::flush () -> void
  {
    g_dbus_object_skeleton_flush (gobj ());
  }

  auto
  ObjectSkeleton::add_interface (const glib::RefPtr<InterfaceSkeleton>& iface) -> void
  {
    g_dbus_object_skeleton_add_interface (gobj (), glib::unwrap (iface));
  }

  auto
  ObjectSkeleton::remove_interface (
      const glib::RefPtr<InterfaceSkeleton>& iface) -> void
  {
    g_dbus_object_skeleton_remove_interface (gobj (), glib::unwrap (iface));
  }

  auto
  ObjectSkeleton::remove_interface (const glib::ustring& interface_name) -> void
  {
    g_dbus_object_skeleton_remove_interface_by_name (gobj (),
                                                     interface_name.c_str ());
  }

  auto
  ObjectSkeleton::set_object_path (const glib::ustring& object_path) -> void
  {
    g_dbus_object_skeleton_set_object_path (gobj (), object_path.c_str ());
  }

  auto
  ObjectSkeleton::signal_authorize_method () -> glib::SignalProxy<bool (const glib::RefPtr<InterfaceSkeleton>&,
                                 const glib::RefPtr<MethodInvocation>&)>
  {
    return {this, &ObjectSkeleton_signal_authorize_method_info};
  }

  auto
  ObjectSkeleton::property_g_object_path () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "g-object-path"};
  }

  auto
  ObjectSkeleton::property_g_object_path () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "g-object-path"};
  }

  auto
  ObjectSkeleton::on_authorize_method (
      const glib::RefPtr<InterfaceSkeleton>& iface,
      const glib::RefPtr<MethodInvocation>& invocation) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->authorize_method)
      return (*base->authorize_method) (gobj (),
                                        glib::unwrap (iface),
                                        glib::unwrap (invocation));

    using RType = bool;
    return RType ();
  }

} // namespace gio::DBus
