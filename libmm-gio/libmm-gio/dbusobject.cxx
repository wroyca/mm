

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusobject.hxx>
#include <libmm-gio/dbusobject_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/dbusinterface.hxx>
#include <libmm-glib/vectorutils.hxx>

namespace
{

  auto
  list_copy_ref (const void* src, void*) -> void*
  {
    return g_object_ref (const_cast<void*> (src));
  }

  auto
  local_unwrap_copy (const Glib::RefPtr<Gio::DBus::Interface>& ptr) -> GDBusInterface*
  {
    return ptr ? reinterpret_cast<GDBusInterface*> (ptr->gobj_copy ()) :
                 nullptr;
  }
} // namespace

namespace
{

  auto
  Object_signal_interface_added_callback (GDBusObject* self,
                                          GDBusInterface* p0,
                                          void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Interface>&)>;

    const auto obj = dynamic_cast<Object*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo Object_signal_interface_added_info = {
      "interface_added",
      (GCallback) &Object_signal_interface_added_callback,
      (GCallback) &Object_signal_interface_added_callback};

  auto
  Object_signal_interface_removed_callback (GDBusObject* self,
                                            GDBusInterface* p0,
                                            void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Interface>&)>;

    const auto obj = dynamic_cast<Object*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo Object_signal_interface_removed_info = {
      "interface_removed",
      (GCallback) &Object_signal_interface_removed_callback,
      (GCallback) &Object_signal_interface_removed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GDBusObject* object, const bool take_copy) -> RefPtr<Gio::DBus::Object>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::Object> (
        Glib::wrap_auto_interface<Gio::DBus::Object> ((GObject*) object,
                                                      take_copy));
  }

} // namespace Glib

namespace Gio::DBus
{

  auto
  Object_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Object_Class::iface_init_function;

      gtype_ = g_dbus_object_get_type ();
    }

    return *this;
  }

  auto
  Object_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_object_path = &get_object_path_vfunc_callback;
    klass->get_interfaces = &get_interfaces_vfunc_callback;
    klass->get_interface = &get_interface_vfunc_callback;

    klass->interface_added = &interface_added_callback;
    klass->interface_removed = &interface_removed_callback;
  }

  auto
  Object_Class::get_object_path_vfunc_callback (GDBusObject* self) -> const gchar*
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
          static auto quark_return_value = g_quark_from_static_string (
              "Gio::DBus::Object::get_object_path_vfunc");

          auto return_value = static_cast<Glib::ustring*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::ustring ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::ustring>);
          }

          *return_value = obj->get_object_path_vfunc ();
          return (*return_value).c_str ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_object_path)
      return (*base->get_object_path) (self);

    using RType = const gchar*;
    return RType ();
  }

  auto
  Object_Class::get_interfaces_vfunc_callback (GDBusObject* self) -> GList*
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
          return g_list_copy_deep (
              Glib::ListHandler<Glib::RefPtr<Interface>>::vector_to_list (
                  obj->get_interfaces_vfunc ())
                  .data (),
              list_copy_ref,
              nullptr);
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_interfaces)
      return (*base->get_interfaces) (self);

    using RType = GList*;
    return RType ();
  }

  auto
  Object_Class::get_interface_vfunc_callback (GDBusObject* self,
                                              const gchar* interface_name) -> GDBusInterface*
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
          return local_unwrap_copy (obj->get_interface_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (interface_name)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_interface)
      return (*base->get_interface) (self, interface_name);

    using RType = GDBusInterface*;
    return RType ();
  }

  auto
  Object_Class::interface_added_callback (GDBusObject* self, GDBusInterface* p0) -> void
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
          obj->on_interface_added (Glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->interface_added)
      (*base->interface_added) (self, p0);
  }

  auto
  Object_Class::interface_removed_callback (GDBusObject* self,
                                            GDBusInterface* p0) -> void
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
          obj->on_interface_removed (Glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->interface_removed)
      (*base->interface_removed) (self, p0);
  }

  auto
  Object_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Object ((GDBusObject*) object);
  }

  Object::Object ()
    : Interface (object_class_.init ())
  {
  }

  Object::Object (GDBusObject* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Object::Object (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Object::Object (Object&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Object::operator= (Object&& src) noexcept -> Object&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Object::~Object () noexcept = default;

  auto
  Object::add_interface (const GType gtype_implementer) -> void
  {
    object_class_.init ().add_interface (gtype_implementer);
  }

  Object::CppClassType Object::object_class_;

  auto
  Object::get_type () -> GType
  {
    return object_class_.init ().get_type ();
  }

  auto
  Object::get_base_type () -> GType
  {
    return g_dbus_object_get_type ();
  }

  auto
  Object::get_object_path () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_object_get_object_path (const_cast<GDBusObject*> (gobj ())));
  }

  auto
  Object::get_interfaces () -> std::vector<Glib::RefPtr<DBus::Interface>>
  {
    return Glib::ListHandler<Glib::RefPtr<DBus::Interface>>::list_to_vector (
        g_dbus_object_get_interfaces (gobj ()),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  Object::get_interfaces () const -> std::vector<Glib::RefPtr<const DBus::Interface>>
  {
    return Glib::ListHandler<Glib::RefPtr<const DBus::Interface>>::
        list_to_vector (
            g_dbus_object_get_interfaces (const_cast<GDBusObject*> (gobj ())),
            Glib::OWNERSHIP_DEEP);
  }

  auto
  Object::get_interface (const Glib::ustring& interface_name) -> Glib::RefPtr<DBus::Interface>
  {
    return Glib::wrap (
        g_dbus_object_get_interface (gobj (), interface_name.c_str ()));
  }

  auto
  Object::get_interface (const Glib::ustring& interface_name) const -> Glib::RefPtr<const DBus::Interface>
  {
    return const_cast<Object*> (this)->get_interface (interface_name);
  }

  auto
  Object::signal_interface_added () -> Glib::SignalProxy<void (const Glib::RefPtr<DBus::Interface>&)>
  {
    return {this, &Object_signal_interface_added_info};
  }

  auto
  Object::signal_interface_removed () -> Glib::SignalProxy<void (const Glib::RefPtr<DBus::Interface>&)>
  {
    return {this, &Object_signal_interface_removed_info};
  }

  auto
  Object::on_interface_added (const Glib::RefPtr<DBus::Interface>& iface) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->interface_added)
      (*base->interface_added) (gobj (), Glib::unwrap (iface));
  }

  auto
  Object::on_interface_removed (const Glib::RefPtr<DBus::Interface>& iface) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->interface_removed)
      (*base->interface_removed) (gobj (), Glib::unwrap (iface));
  }

  auto
  Object::get_object_path_vfunc () const -> Glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_object_path)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_object_path) (const_cast<GDBusObject*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return {};
  }

  auto
  Object::get_interfaces_vfunc () const -> std::vector<Glib::RefPtr<DBus::Interface>>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_interfaces)
    {
      std::vector<Glib::RefPtr<DBus::Interface>> retval (
          Glib::ListHandler<Glib::RefPtr<DBus::Interface>>::list_to_vector (
              (*base->get_interfaces) (const_cast<GDBusObject*> (gobj ())),
              Glib::OWNERSHIP_DEEP));
      return retval;
    }

    using RType = std::vector<Glib::RefPtr<DBus::Interface>>;
    return {};
  }

  auto
  Object::get_interface_vfunc (const Glib::ustring& interface_name) const -> Glib::RefPtr<DBus::Interface>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_interface)
    {
      Glib::RefPtr<DBus::Interface> retval (Glib::wrap (
          (*base->get_interface) (const_cast<GDBusObject*> (gobj ()),
                                  interface_name.c_str ())));
      return retval;
    }

    using RType = Glib::RefPtr<DBus::Interface>;
    return {};
  }

} // namespace Gio::DBus
