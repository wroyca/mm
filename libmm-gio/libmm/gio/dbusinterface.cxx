// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusinterface.hxx>
#include <libmm/gio/dbusinterface_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusobject.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GDBusInterface* object, const bool take_copy) -> RefPtr<gio::DBus::Interface>
  {
    return glib::make_refptr_for_instance<gio::DBus::Interface> (
        glib::wrap_auto_interface<gio::DBus::Interface> ((GObject*) object,
                                                         take_copy));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  Interface_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Interface_Class::iface_init_function;

      gtype_ = g_dbus_interface_get_type ();
    }

    return *this;
  }

  auto
  Interface_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_info = &get_info_vfunc_callback;
    klass->get_object = &get_object_vfunc_callback;
    klass->set_object = &set_object_vfunc_callback;
    klass->dup_object = &dup_object_vfunc_callback;
  }

  auto
  Interface_Class::get_info_vfunc_callback (GDBusInterface* self) -> GDBusInterfaceInfo*
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
          return glib::unwrap (obj->get_info_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_info)
      return (*base->get_info) (self);

    using RType = GDBusInterfaceInfo*;
    return RType ();
  }

  auto
  Interface_Class::get_object_vfunc_callback (GDBusInterface* self) -> GDBusObject*
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
          return glib::unwrap (obj->get_object_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_object)
      return (*base->get_object) (self);

    using RType = GDBusObject*;
    return RType ();
  }

  auto
  Interface_Class::set_object_vfunc_callback (GDBusInterface* self,
                                              GDBusObject* object) -> void
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
          obj->set_object_vfunc (glib::wrap (object, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->set_object)
      (*base->set_object) (self, object);
  }

  auto
  Interface_Class::dup_object_vfunc_callback (GDBusInterface* self) -> GDBusObject*
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
          return glib::unwrap (obj->dup_object_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->dup_object)
      return (*base->dup_object) (self);

    using RType = GDBusObject*;
    return RType ();
  }

  auto
  Interface_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Interface ((GDBusInterface*) object);
  }

  Interface::Interface ()
    : glib::Interface (interface_class_.init ())
  {
  }

  Interface::Interface (GDBusInterface* castitem)
    : glib::Interface ((GObject*) castitem)
  {
  }

  Interface::Interface (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Interface::Interface (Interface&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Interface::operator= (Interface&& src) noexcept -> Interface&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Interface::~Interface () noexcept = default;

  auto
  Interface::add_interface (const GType gtype_implementer) -> void
  {
    interface_class_.init ().add_interface (gtype_implementer);
  }

  Interface::CppClassType Interface::interface_class_;

  auto
  Interface::get_type () -> GType
  {
    return interface_class_.init ().get_type ();
  }

  auto
  Interface::get_base_type () -> GType
  {
    return g_dbus_interface_get_type ();
  }

  auto
  Interface::get_info () -> glib::RefPtr<InterfaceInfo>
  {
    return glib::wrap (g_dbus_interface_get_info (gobj ()));
  }

  auto
  Interface::get_info () const -> glib::RefPtr<const InterfaceInfo>
  {
    return const_cast<Interface*> (this)->get_info ();
  }

  auto
  Interface::get_object () -> glib::RefPtr<Object>
  {
    return glib::wrap (g_dbus_interface_get_object (gobj ()));
  }

  auto
  Interface::get_object () const -> glib::RefPtr<const Object>
  {
    return const_cast<Interface*> (this)->get_object ();
  }

  auto
  Interface::dup_object () -> glib::RefPtr<Object>
  {
    return glib::wrap (g_dbus_interface_dup_object (gobj ()));
  }

  auto
  Interface::dup_object () const -> glib::RefPtr<const Object>
  {
    return const_cast<Interface*> (this)->dup_object ();
  }

  auto
  Interface::set_object (const glib::RefPtr<Object>& object) -> void
  {
    g_dbus_interface_set_object (gobj (), glib::unwrap (object));
  }

  auto
  Interface::get_info_vfunc () const -> glib::RefPtr<InterfaceInfo>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_info)
    {
      glib::RefPtr<InterfaceInfo> retval (glib::wrap (
          (*base->get_info) (const_cast<GDBusInterface*> (gobj ()))));
      return retval;
    }

    using RType = glib::RefPtr<InterfaceInfo>;
    return {};
  }

  auto
  Interface::get_object_vfunc () const -> glib::RefPtr<Object>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_object)
    {
      glib::RefPtr<Object> retval (glib::wrap (
          (*base->get_object) (const_cast<GDBusInterface*> (gobj ()))));
      return retval;
    }

    using RType = glib::RefPtr<Object>;
    return {};
  }

  auto
  Interface::set_object_vfunc (const glib::RefPtr<Object>& object) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->set_object)
    {
      (*base->set_object) (gobj (), glib::unwrap (object));
    }
  }

  auto
  Interface::dup_object_vfunc () const -> glib::RefPtr<Object>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->dup_object)
    {
      glib::RefPtr<Object> retval (glib::wrap (
          (*base->dup_object) (const_cast<GDBusInterface*> (gobj ()))));
      return retval;
    }

    using RType = glib::RefPtr<Object>;
    return {};
  }

} // namespace gio::DBus
