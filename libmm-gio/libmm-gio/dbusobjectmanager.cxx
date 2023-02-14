

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusobjectmanager.hxx>
#include <libmm-gio/dbusobjectmanager_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/dbusinterface.hxx>
#include <libmm-gio/dbusobject.hxx>

namespace
{

  auto
  list_copy_ref (const void* src, void*) -> void*
  {
    return g_object_ref (const_cast<void*> (src));
  }

  auto
  local_unwrap_copy (const Glib::RefPtr<Gio::DBus::Object>& ptr) -> GDBusObject*
  {
    return ptr ? reinterpret_cast<GDBusObject*> (ptr->gobj_copy ()) : nullptr;
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
  ObjectManager_signal_object_added_callback (GDBusObjectManager* self,
                                              GDBusObject* p0,
                                              void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Object>&)>;

    const auto obj = dynamic_cast<ObjectManager*> (
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

  const Glib::SignalProxyInfo ObjectManager_signal_object_added_info = {
      "object-added",
      (GCallback) &ObjectManager_signal_object_added_callback,
      (GCallback) &ObjectManager_signal_object_added_callback};

  auto
  ObjectManager_signal_object_removed_callback (GDBusObjectManager* self,
                                                GDBusObject* p0,
                                                void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Object>&)>;

    const auto obj = dynamic_cast<ObjectManager*> (
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

  const Glib::SignalProxyInfo ObjectManager_signal_object_removed_info = {
      "object-removed",
      (GCallback) &ObjectManager_signal_object_removed_callback,
      (GCallback) &ObjectManager_signal_object_removed_callback};

  auto
  ObjectManager_signal_interface_added_callback (GDBusObjectManager* self,
                                                 GDBusObject* p0,
                                                 GDBusInterface* p1,
                                                 void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Object>&,
                                      const Glib::RefPtr<Interface>&)>;

    const auto obj = dynamic_cast<ObjectManager*> (
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
  }

  const Glib::SignalProxyInfo ObjectManager_signal_interface_added_info = {
      "interface-added",
      (GCallback) &ObjectManager_signal_interface_added_callback,
      (GCallback) &ObjectManager_signal_interface_added_callback};

  auto
  ObjectManager_signal_interface_removed_callback (GDBusObjectManager* self,
                                                   GDBusObject* p0,
                                                   GDBusInterface* p1,
                                                   void* data) -> void
  {
    using namespace Gio::DBus;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Object>&,
                                      const Glib::RefPtr<Interface>&)>;

    const auto obj = dynamic_cast<ObjectManager*> (
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
  }

  const Glib::SignalProxyInfo ObjectManager_signal_interface_removed_info = {
      "interface-removed",
      (GCallback) &ObjectManager_signal_interface_removed_callback,
      (GCallback) &ObjectManager_signal_interface_removed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GDBusObjectManager* object, const bool take_copy) -> RefPtr<Gio::DBus::ObjectManager>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::ObjectManager> (
        Glib::wrap_auto_interface<Gio::DBus::ObjectManager> ((GObject*) object,
                                                             take_copy));
  }

} // namespace Glib

namespace Gio::DBus
{

  auto
  ObjectManager_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ObjectManager_Class::iface_init_function;

      gtype_ = g_dbus_object_manager_get_type ();
    }

    return *this;
  }

  auto
  ObjectManager_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_object_path = &get_object_path_vfunc_callback;
    klass->get_objects = &get_objects_vfunc_callback;
    klass->get_object = &get_object_vfunc_callback;
    klass->get_interface = &get_interface_vfunc_callback;

    klass->object_added = &object_added_callback;
    klass->object_removed = &object_removed_callback;
    klass->interface_added = &interface_added_callback;
    klass->interface_removed = &interface_removed_callback;
  }

  auto
  ObjectManager_Class::get_object_path_vfunc_callback (GDBusObjectManager* self) -> const gchar*
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
              "Gio::DBus::ObjectManager::get_object_path_vfunc");

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
  ObjectManager_Class::get_objects_vfunc_callback (GDBusObjectManager* self) -> GList*
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
              Glib::ListHandler<Glib::RefPtr<Object>>::vector_to_list (
                  obj->get_objects_vfunc ())
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

    if (base && base->get_objects)
      return (*base->get_objects) (self);

    using RType = GList*;
    return RType ();
  }

  auto
  ObjectManager_Class::get_object_vfunc_callback (GDBusObjectManager* self,
                                                  const gchar* object_path) -> GDBusObject*
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
          return local_unwrap_copy (obj->get_object_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (object_path)));
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

    if (base && base->get_object)
      return (*base->get_object) (self, object_path);

    using RType = GDBusObject*;
    return RType ();
  }

  auto
  ObjectManager_Class::get_interface_vfunc_callback (
      GDBusObjectManager* self,
      const gchar* object_path,
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
              Glib::convert_const_gchar_ptr_to_ustring (object_path),
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
      return (*base->get_interface) (self, object_path, interface_name);

    using RType = GDBusInterface*;
    return RType ();
  }

  auto
  ObjectManager_Class::object_added_callback (GDBusObjectManager* self,
                                              GDBusObject* p0) -> void
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
          obj->on_object_added (Glib::wrap (p0, true));
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

    if (base && base->object_added)
      (*base->object_added) (self, p0);
  }

  auto
  ObjectManager_Class::object_removed_callback (GDBusObjectManager* self,
                                                GDBusObject* p0) -> void
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
          obj->on_object_removed (Glib::wrap (p0, true));
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

    if (base && base->object_removed)
      (*base->object_removed) (self, p0);
  }

  auto
  ObjectManager_Class::interface_added_callback (GDBusObjectManager* self,
                                                 GDBusObject* p0,
                                                 GDBusInterface* p1) -> void
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
          obj->on_interface_added (Glib::wrap (p0, true),
                                   Glib::wrap (p1, true));
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
      (*base->interface_added) (self, p0, p1);
  }

  auto
  ObjectManager_Class::interface_removed_callback (GDBusObjectManager* self,
                                                   GDBusObject* p0,
                                                   GDBusInterface* p1) -> void
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
          obj->on_interface_removed (Glib::wrap (p0, true),
                                     Glib::wrap (p1, true));
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
      (*base->interface_removed) (self, p0, p1);
  }

  auto
  ObjectManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ObjectManager ((GDBusObjectManager*) object);
  }

  ObjectManager::ObjectManager ()
    : Interface (objectmanager_class_.init ())
  {
  }

  ObjectManager::ObjectManager (GDBusObjectManager* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ObjectManager::ObjectManager (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ObjectManager::ObjectManager (ObjectManager&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ObjectManager::operator= (ObjectManager&& src) noexcept -> ObjectManager&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ObjectManager::~ObjectManager () noexcept = default;

  auto
  ObjectManager::add_interface (const GType gtype_implementer) -> void
  {
    objectmanager_class_.init ().add_interface (gtype_implementer);
  }

  ObjectManager::CppClassType ObjectManager::objectmanager_class_;

  auto
  ObjectManager::get_type () -> GType
  {
    return objectmanager_class_.init ().get_type ();
  }

  auto
  ObjectManager::get_base_type () -> GType
  {
    return g_dbus_object_manager_get_type ();
  }

  auto
  ObjectManager::get_object_path () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_object_manager_get_object_path (
            const_cast<GDBusObjectManager*> (gobj ())));
  }

  auto
  ObjectManager::get_objects () -> std::vector<Glib::RefPtr<Object>>
  {
    return Glib::ListHandler<Glib::RefPtr<Object>>::list_to_vector (
        g_dbus_object_manager_get_objects (gobj ()),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  ObjectManager::get_objects () const -> std::vector<Glib::RefPtr<const Object>>
  {
    return Glib::ListHandler<Glib::RefPtr<const Object>>::list_to_vector (
        g_dbus_object_manager_get_objects (
            const_cast<GDBusObjectManager*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  ObjectManager::get_object (const Glib::ustring& object_path) -> Glib::RefPtr<Object>
  {
    return Glib::wrap (
        g_dbus_object_manager_get_object (gobj (), object_path.c_str ()));
  }

  auto
  ObjectManager::get_object (const Glib::ustring& object_path) const -> Glib::RefPtr<const Object>
  {
    return const_cast<ObjectManager*> (this)->get_object (object_path);
  }

  auto
  ObjectManager::get_interface (const Glib::ustring& object_path,
                                const Glib::ustring& interface_name) -> Glib::RefPtr<DBus::Interface>
  {
    return Glib::wrap (
        g_dbus_object_manager_get_interface (gobj (),
                                             object_path.c_str (),
                                             interface_name.c_str ()));
  }

  auto
  ObjectManager::get_interface (const Glib::ustring& object_path,
                                const Glib::ustring& interface_name) const -> Glib::RefPtr<const DBus::Interface>
  {
    return const_cast<ObjectManager*> (this)->get_interface (object_path,
                                                             interface_name);
  }

  auto
  ObjectManager::signal_object_added () -> Glib::SignalProxy<void (const Glib::RefPtr<Object>&)>
  {
    return {this, &ObjectManager_signal_object_added_info};
  }

  auto
  ObjectManager::signal_object_removed () -> Glib::SignalProxy<void (const Glib::RefPtr<Object>&)>
  {
    return {this, &ObjectManager_signal_object_removed_info};
  }

  auto
  ObjectManager::signal_interface_added () -> Glib::SignalProxy<void (const Glib::RefPtr<Object>&,
                                 const Glib::RefPtr<DBus::Interface>&)>
  {
    return {this, &ObjectManager_signal_interface_added_info};
  }

  auto
  ObjectManager::signal_interface_removed () -> Glib::SignalProxy<void (const Glib::RefPtr<Object>&,
                                 const Glib::RefPtr<DBus::Interface>&)>
  {
    return {this, &ObjectManager_signal_interface_removed_info};
  }

  auto
  ObjectManager::on_object_added (const Glib::RefPtr<Object>& object) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->object_added)
      (*base->object_added) (gobj (), Glib::unwrap (object));
  }

  auto
  ObjectManager::on_object_removed (const Glib::RefPtr<Object>& object) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->object_removed)
      (*base->object_removed) (gobj (), Glib::unwrap (object));
  }

  auto
  ObjectManager::on_interface_added (const Glib::RefPtr<Object>& object,
                                     const Glib::RefPtr<DBus::Interface>& iface) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->interface_added)
      (*base->interface_added) (gobj (),
                                Glib::unwrap (object),
                                Glib::unwrap (iface));
  }

  auto
  ObjectManager::on_interface_removed (
      const Glib::RefPtr<Object>& object,
      const Glib::RefPtr<DBus::Interface>& iface) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->interface_removed)
      (*base->interface_removed) (gobj (),
                                  Glib::unwrap (object),
                                  Glib::unwrap (iface));
  }

  auto
  ObjectManager::get_object_path_vfunc () const -> Glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_object_path)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring ((
          *base->get_object_path) (const_cast<GDBusObjectManager*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return {};
  }

  auto
  ObjectManager::get_objects_vfunc () const -> std::vector<Glib::RefPtr<Object>>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_objects)
    {
      std::vector<Glib::RefPtr<Object>> retval (
          Glib::ListHandler<Glib::RefPtr<Object>>::list_to_vector (
              (*base->get_objects) (const_cast<GDBusObjectManager*> (gobj ())),
              Glib::OWNERSHIP_DEEP));
      return retval;
    }

    using RType = std::vector<Glib::RefPtr<Object>>;
    return {};
  }

  auto
  ObjectManager::get_object_vfunc (const Glib::ustring& object_path) const -> Glib::RefPtr<Object>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_object)
    {
      Glib::RefPtr<Object> retval (Glib::wrap (
          (*base->get_object) (const_cast<GDBusObjectManager*> (gobj ()),
                               object_path.c_str ())));
      return retval;
    }

    using RType = Glib::RefPtr<Object>;
    return {};
  }

  auto
  ObjectManager::get_interface_vfunc (const Glib::ustring& object_path,
                                      const Glib::ustring& interface_name) const -> Glib::RefPtr<DBus::Interface>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_interface)
    {
      Glib::RefPtr<DBus::Interface> retval (Glib::wrap (
          (*base->get_interface) (const_cast<GDBusObjectManager*> (gobj ()),
                                  object_path.c_str (),
                                  interface_name.c_str ())));
      return retval;
    }

    using RType = Glib::RefPtr<DBus::Interface>;
    return {};
  }

} // namespace Gio::DBus
