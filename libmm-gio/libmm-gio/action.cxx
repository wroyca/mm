// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/action.hxx>
#include <libmm-gio/action_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  auto
  Action::activate () -> void
  {
    g_action_activate (gobj (), nullptr);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GAction* object, const bool take_copy) -> RefPtr<Gio::Action>
  {
    return Glib::make_refptr_for_instance<Gio::Action> (
        Glib::wrap_auto_interface<Gio::Action> ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  Action_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Action_Class::iface_init_function;

      gtype_ = g_action_get_type ();
    }

    return *this;
  }

  auto
  Action_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_name = &get_name_vfunc_callback;
    klass->get_parameter_type = &get_parameter_type_vfunc_callback;
    klass->get_state_type = &get_state_type_vfunc_callback;
    klass->get_state_hint = &get_state_hint_vfunc_callback;
    klass->get_enabled = &get_enabled_vfunc_callback;
    klass->get_state = &get_state_vfunc_callback;
    klass->change_state = &change_state_vfunc_callback;
    klass->activate = &activate_vfunc_callback;
  }

  auto
  Action_Class::get_name_vfunc_callback (GAction* self) -> const gchar*
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
          static auto quark_return_value =
              g_quark_from_static_string ("Gio::Action::get_name_vfunc");

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

          *return_value = obj->get_name_vfunc ();
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

    if (base && base->get_name)
      return (*base->get_name) (self);

    using RType = const gchar*;
    return RType ();
  }

  auto
  Action_Class::get_parameter_type_vfunc_callback (GAction* self) -> const GVariantType*
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
              "Gio::Action::get_parameter_type_vfunc");

          auto return_value = static_cast<Glib::VariantType*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::VariantType ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::VariantType>);
          }

          *return_value = obj->get_parameter_type_vfunc ();
          return (*return_value).gobj ();
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

    if (base && base->get_parameter_type)
      return (*base->get_parameter_type) (self);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  Action_Class::get_state_type_vfunc_callback (GAction* self) -> const GVariantType*
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
          static auto quark_return_value =
              g_quark_from_static_string ("Gio::Action::get_state_type_vfunc");

          auto return_value = static_cast<Glib::VariantType*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new Glib::VariantType ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &Glib::destroy_notify_delete<Glib::VariantType>);
          }

          *return_value = obj->get_state_type_vfunc ();
          return (*return_value).gobj ();
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

    if (base && base->get_state_type)
      return (*base->get_state_type) (self);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  Action_Class::get_state_hint_vfunc_callback (GAction* self) -> GVariant*
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
          return unwrap_copy (obj->get_state_hint_vfunc ());
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

    if (base && base->get_state_hint)
      return (*base->get_state_hint) (self);

    using RType = GVariant*;
    return RType ();
  }

  auto
  Action_Class::get_enabled_vfunc_callback (GAction* self) -> gboolean
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
          return obj->get_enabled_vfunc ();
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

    if (base && base->get_enabled)
      return (*base->get_enabled) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  Action_Class::get_state_vfunc_callback (GAction* self) -> GVariant*
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
          return unwrap_copy (obj->get_state_vfunc ());
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

    if (base && base->get_state)
      return (*base->get_state) (self);

    using RType = GVariant*;
    return RType ();
  }

  auto
  Action_Class::change_state_vfunc_callback (GAction* self, GVariant* value) -> void
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
          obj->change_state_vfunc (Glib::wrap (value, true));
          return;
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

    if (base && base->change_state)
      (*base->change_state) (self, value);
  }

  auto
  Action_Class::activate_vfunc_callback (GAction* self, GVariant* parameter) -> void
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
          obj->activate_vfunc (Glib::wrap (parameter, true));
          return;
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

    if (base && base->activate)
      (*base->activate) (self, parameter);
  }

  auto
  Action_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Action ((GAction*) object);
  }

  Action::Action ()
    : Interface (action_class_.init ())
  {
  }

  Action::Action (GAction* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Action::Action (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Action::Action (Action&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Action::operator= (Action&& src) noexcept -> Action&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Action::~Action () noexcept = default;

  auto
  Action::add_interface (const GType gtype_implementer) -> void
  {
    action_class_.init ().add_interface (gtype_implementer);
  }

  Action::CppClassType Action::action_class_;

  auto
  Action::get_type () -> GType
  {
    return action_class_.init ().get_type ();
  }

  auto
  Action::get_base_type () -> GType
  {
    return g_action_get_type ();
  }

  auto
  Action::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_action_get_name (const_cast<GAction*> (gobj ())));
  }

  auto
  Action::get_parameter_type () const -> Glib::VariantType
  {
    return Glib::wrap (const_cast<GVariantType*> (g_action_get_parameter_type (
                           const_cast<GAction*> (gobj ()))),
                       true);
  }

  auto
  Action::get_state_type () const -> Glib::VariantType
  {
    return Glib::wrap (const_cast<GVariantType*> (g_action_get_state_type (
                           const_cast<GAction*> (gobj ()))),
                       true);
  }

  auto
  Action::get_state_hint_variant () const -> Glib::VariantContainerBase
  {
    return Glib::VariantContainerBase (
        g_action_get_state_hint (const_cast<GAction*> (gobj ())),
        false);
  }

  auto
  Action::get_enabled () const -> bool
  {
    return g_action_get_enabled (const_cast<GAction*> (gobj ()));
  }

  auto
  Action::change_state_variant (const Glib::VariantBase& value) -> void
  {
    g_action_change_state (gobj (), const_cast<GVariant*> (value.gobj ()));
  }

  auto
  Action::get_state_variant () const -> Glib::VariantBase
  {
    return Glib::wrap (g_action_get_state (const_cast<GAction*> (gobj ())),
                       false);
  }

  auto
  Action::activate_variant (const Glib::VariantBase& parameter) -> void
  {
    g_action_activate (gobj (), const_cast<GVariant*> (parameter.gobj ()));
  }

  auto
  Action::name_is_valid (const Glib::ustring& action_name) -> bool
  {
    return g_action_name_is_valid (action_name.c_str ());
  }

  auto
  Action::parse_detailed_name_variant (const Glib::ustring& detailed_name,
                                       Glib::ustring& action_name,
                                       Glib::VariantBase& target_value) -> void
  {
    GError* gerror = nullptr;
    gchar* g_action_name = nullptr;
    GVariant* g_target_value = nullptr;
    g_action_parse_detailed_name (detailed_name.c_str (),
                                  &g_action_name,
                                  &g_target_value,
                                  &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    action_name = Glib::convert_return_gchar_ptr_to_ustring (g_action_name);
    target_value = Glib::wrap (g_target_value);
  }

  auto
  Action::print_detailed_name_variant (const Glib::ustring& action_name,
                                       const Glib::VariantBase& target_value) -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_action_print_detailed_name (
            action_name.c_str (),
            const_cast<GVariant*> (target_value.gobj ())));
  }

  auto
  Action::property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  auto
  Action::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
      "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Action::property_parameter_type () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>
  {
    return {this, "parameter-type"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
      "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Action::property_state () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>
  {
    return {this, "state"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantType>::value,
      "Type Glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Action::property_state_type () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>
  {
    return {this, "state-type"};
  }

  auto
  Action::get_name_vfunc () const -> Glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_name)
    {
      Glib::ustring retval (Glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_name) (const_cast<GAction*> (gobj ()))));
      return retval;
    }

    using RType = Glib::ustring;
    return {};
  }

  auto
  Action::get_parameter_type_vfunc () const -> Glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_parameter_type)
    {
      Glib::VariantType retval (Glib::wrap (
          const_cast<GVariantType*> (
              (*base->get_parameter_type) (const_cast<GAction*> (gobj ()))),
          true));
      return retval;
    }

    using RType = Glib::VariantType;
    return {};
  }

  auto
  Action::get_state_type_vfunc () const -> Glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state_type)
    {
      Glib::VariantType retval (Glib::wrap (
          const_cast<GVariantType*> (
              (*base->get_state_type) (const_cast<GAction*> (gobj ()))),
          true));
      return retval;
    }

    using RType = Glib::VariantType;
    return {};
  }

  auto
  Action::get_state_hint_vfunc () const -> Glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state_hint)
    {
      Glib::VariantBase retval (
          Glib::wrap ((*base->get_state_hint) (const_cast<GAction*> (gobj ())),
                      false));
      return retval;
    }

    using RType = Glib::VariantBase;
    return {};
  }

  auto
  Action::get_enabled_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_enabled)
    {
      const bool retval ((*base->get_enabled) (const_cast<GAction*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Action::get_state_vfunc () const -> Glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state)
    {
      Glib::VariantBase retval (
          Glib::wrap ((*base->get_state) (const_cast<GAction*> (gobj ())),
                      false));
      return retval;
    }

    using RType = Glib::VariantBase;
    return {};
  }

  auto
  Action::change_state_vfunc (const Glib::VariantBase& value) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->change_state)
    {
      (*base->change_state) (gobj (), const_cast<GVariant*> (value.gobj ()));
    }
  }

  auto
  Action::activate_vfunc (const Glib::VariantBase& parameter) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->activate)
    {
      (*base->activate) (gobj (), const_cast<GVariant*> (parameter.gobj ()));
    }
  }

} // namespace Gio
