// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/actionable.hxx>
#include <libmm/gtk/actionable_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkActionable* object, bool take_copy) -> Glib::RefPtr<Gtk::Actionable>
  {
    return Glib::make_refptr_for_instance<Gtk::Actionable> (
        dynamic_cast<Gtk::Actionable*> (
            Glib::wrap_auto_interface<Gtk::Actionable> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Actionable_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Actionable_Class::iface_init_function;

      gtype_ = gtk_actionable_get_type ();
    }

    return *this;
  }

  auto
  Actionable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_action_name = &get_action_name_vfunc_callback;
    klass->set_action_name = &set_action_name_vfunc_callback;
    klass->get_action_target_value = &get_action_target_value_vfunc_callback;
    klass->set_action_target_value = &set_action_target_value_vfunc_callback;
  }

  auto
  Actionable_Class::get_action_name_vfunc_callback (GtkActionable* self) -> const gchar*
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value = g_quark_from_static_string (
              "Gtk::Actionable::get_action_name_vfunc");

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

          *return_value = obj->get_action_name_vfunc ();
          return (*return_value).empty () ? nullptr : (*return_value).c_str ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_action_name)
      return (*base->get_action_name) (self);

    using RType = const gchar*;
    return RType ();
  }

  auto
  Actionable_Class::set_action_name_vfunc_callback (GtkActionable* self,
                                                    const gchar* action_name) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->set_action_name_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->set_action_name)
      (*base->set_action_name) (self, action_name);
  }

  auto
  Actionable_Class::get_action_target_value_vfunc_callback (GtkActionable* self) -> GVariant*
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value = g_quark_from_static_string (
              "Gtk::Actionable::get_action_target_value_vfunc");

          auto return_value = static_cast<Glib::VariantBase*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::VariantBase ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::VariantBase>);
          }

          *return_value = obj->get_action_target_value_vfunc ();
          return (*return_value).gobj ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_action_target_value)
      return (*base->get_action_target_value) (self);

    using RType = GVariant*;
    return RType ();
  }

  auto
  Actionable_Class::set_action_target_value_vfunc_callback (
      GtkActionable* self,
      GVariant* action_target_value) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->set_action_target_value_vfunc (
              Glib::wrap (action_target_value, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->set_action_target_value)
      (*base->set_action_target_value) (self, action_target_value);
  }

  auto
  Actionable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Actionable ((GtkActionable*) (object));
  }

  Actionable::Actionable ()
    : Glib::Interface (actionable_class_.init ())
  {
  }

  Actionable::Actionable (GtkActionable* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Actionable::Actionable (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Actionable::Actionable (Actionable&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Actionable::operator= (Actionable&& src) noexcept -> Actionable&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Actionable::~Actionable () noexcept {}

  auto
  Actionable::add_interface (GType gtype_implementer) -> void
  {
    actionable_class_.init ().add_interface (gtype_implementer);
  }

  Actionable::CppClassType Actionable::actionable_class_;

  auto
  Actionable::get_type () -> GType
  {
    return actionable_class_.init ().get_type ();
  }

  auto
  Actionable::get_base_type () -> GType
  {
    return gtk_actionable_get_type ();
  }

  auto
  Actionable::get_action_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_actionable_get_action_name (const_cast<GtkActionable*> (gobj ())));
  }

  auto
  Actionable::set_action_name (const Glib::ustring& action_name) -> void
  {
    gtk_actionable_set_action_name (gobj (), action_name.c_str ());
  }

  auto
  Actionable::get_action_target_value () -> Glib::VariantBase
  {
    return Glib::wrap (gtk_actionable_get_action_target_value (gobj ()), true);
  }

  auto
  Actionable::get_action_target_value () const -> const Glib::VariantBase
  {
    return const_cast<Actionable*> (this)->get_action_target_value ();
  }

  auto
  Actionable::set_action_target_value (const Glib::VariantBase& target_value) -> void
  {
    gtk_actionable_set_action_target_value (
        gobj (),
        const_cast<GVariant*> ((target_value).gobj ()));
  }

  auto
  Actionable::set_detailed_action_name (
      const Glib::ustring& detailed_action_name) -> void
  {
    gtk_actionable_set_detailed_action_name (gobj (),
                                             detailed_action_name.c_str ());
  }

  auto
  Actionable::property_action_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "action-name");
  }

  auto
  Actionable::property_action_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "action-name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
      "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Actionable::property_action_target () -> Glib::PropertyProxy<Glib::VariantBase>
  {
    return Glib::PropertyProxy<Glib::VariantBase> (this, "action-target");
  }

  auto
  Actionable::property_action_target () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::VariantBase> (this,
                                                            "action-target");
  }

  auto
  Gtk::Actionable::get_action_name_vfunc () const -> Glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_action_name)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_action_name) (const_cast<GtkActionable*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return RType ();
  }

  auto
  Gtk::Actionable::set_action_name_vfunc (const Glib::ustring& action_name) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_action_name)
    {
      (*base->set_action_name) (gobj (), action_name.c_str ());
    }
  }

  auto
  Gtk::Actionable::get_action_target_value_vfunc () const -> Glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_action_target_value)
    {
      Glib::VariantBase retval (
          Glib::wrap ((*base->get_action_target_value) (
                          const_cast<GtkActionable*> (gobj ())),
                      true));
      return retval;
    }

    using RType = Glib::VariantBase;
    return RType ();
  }

  auto
  Gtk::Actionable::set_action_target_value_vfunc (
      const Glib::VariantBase& action_target_value) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_action_target_value)
    {
      (*base->set_action_target_value) (
          gobj (),
          const_cast<GVariant*> ((action_target_value).gobj ()));
    }
  }

} // namespace Gtk
