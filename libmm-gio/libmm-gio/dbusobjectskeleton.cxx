

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusobjectskeleton.hxx>
#include <libmm-gio/dbusobjectskeleton_p.hxx>

#include <gio/gio.h>

namespace
{

  auto
  ObjectSkeleton_signal_authorize_method_callback (GDBusObjectSkeleton* self,
                                                   GDBusInterfaceSkeleton* p0,
                                                   GDBusMethodInvocation* p1,
                                                   void* data) -> gboolean
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<InterfaceSkeleton>&,
                                      const Glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<ObjectSkeleton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                                   Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<InterfaceSkeleton>&,
                                      const Glib::RefPtr<MethodInvocation>&)>;

    const auto obj = dynamic_cast<ObjectSkeleton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo ObjectSkeleton_signal_authorize_method_info = {
      "authorize-method",
      (GCallback) &ObjectSkeleton_signal_authorize_method_callback,
      (GCallback) &ObjectSkeleton_signal_authorize_method_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GDBusObjectSkeleton* object, const bool take_copy) -> RefPtr<Gio::DBus::ObjectSkeleton>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::ObjectSkeleton> (
        dynamic_cast<Gio::DBus::ObjectSkeleton*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio::DBus
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
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->on_authorize_method (Glib::wrap (p0, true),
                                           Glib::wrap (p1, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
  ObjectSkeleton_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ObjectSkeleton ((GDBusObjectSkeleton*) object);
  }

  auto
  ObjectSkeleton::gobj_copy () -> GDBusObjectSkeleton*
  {
    reference ();
    return gobj ();
  }

  ObjectSkeleton::ObjectSkeleton (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ObjectSkeleton::ObjectSkeleton (GDBusObjectSkeleton* castitem)
    : Glib::Object ((GObject*) castitem)
  {
  }

  ObjectSkeleton::ObjectSkeleton (ObjectSkeleton&& src) noexcept
    : Glib::Object (std::move (src)),
      DBus::Object (std::move (src))
  {
  }

  auto
  ObjectSkeleton::operator= (ObjectSkeleton&& src) noexcept -> ObjectSkeleton&
  {
    Glib::Object::operator= (std::move (src));
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

  ObjectSkeleton::ObjectSkeleton (const Glib::ustring& object_path)
    : ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (objectskeleton_class_.init (),
                                           "object_path",
                                           object_path.c_str (),
                                           nullptr))
  {
  }

  auto
  ObjectSkeleton::create (const Glib::ustring& object_path) -> Glib::RefPtr<ObjectSkeleton>
  {
    return Glib::make_refptr_for_instance<ObjectSkeleton> (
        new ObjectSkeleton (object_path));
  }

  auto
  ObjectSkeleton::flush () -> void
  {
    g_dbus_object_skeleton_flush (gobj ());
  }

  auto
  ObjectSkeleton::add_interface (const Glib::RefPtr<InterfaceSkeleton>& iface) -> void
  {
    g_dbus_object_skeleton_add_interface (gobj (), Glib::unwrap (iface));
  }

  auto
  ObjectSkeleton::remove_interface (
      const Glib::RefPtr<InterfaceSkeleton>& iface) -> void
  {
    g_dbus_object_skeleton_remove_interface (gobj (), Glib::unwrap (iface));
  }

  auto
  ObjectSkeleton::remove_interface (const Glib::ustring& interface_name) -> void
  {
    g_dbus_object_skeleton_remove_interface_by_name (gobj (),
                                                     interface_name.c_str ());
  }

  auto
  ObjectSkeleton::set_object_path (const Glib::ustring& object_path) -> void
  {
    g_dbus_object_skeleton_set_object_path (gobj (), object_path.c_str ());
  }

  auto
  ObjectSkeleton::signal_authorize_method () -> Glib::SignalProxy<bool (const Glib::RefPtr<InterfaceSkeleton>&,
                                 const Glib::RefPtr<MethodInvocation>&)>
  {
    return {this, &ObjectSkeleton_signal_authorize_method_info};
  }

  auto
  ObjectSkeleton::property_g_object_path () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "g-object-path"};
  }

  auto
  ObjectSkeleton::property_g_object_path () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "g-object-path"};
  }

  auto
  ObjectSkeleton::on_authorize_method (
      const Glib::RefPtr<InterfaceSkeleton>& iface,
      const Glib::RefPtr<MethodInvocation>& invocation) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->authorize_method)
      return (*base->authorize_method) (gobj (),
                                        Glib::unwrap (iface),
                                        Glib::unwrap (invocation));

    using RType = bool;
    return RType ();
  }

} // namespace Gio::DBus
