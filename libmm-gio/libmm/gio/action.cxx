// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/action.hxx>
#include <libmm/gio/action_p.hxx>

#include <gio/gio.h>

namespace gio
{

  auto
  Action::activate () -> void
  {
    g_action_activate (gobj (), nullptr);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GAction* object, const bool take_copy) -> RefPtr<gio::Action>
  {
    return glib::make_refptr_for_instance<gio::Action> (
        glib::wrap_auto_interface<gio::Action> ((GObject*) object, take_copy));
  }

} // namespace glib

namespace gio
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
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          static auto quark_return_value =
              g_quark_from_static_string ("gio::Action::get_name_vfunc");

          auto return_value = static_cast<glib::ustring*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new glib::ustring ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &glib::destroy_notify_delete<glib::ustring>);
          }

          *return_value = obj->get_name_vfunc ();
          return (*return_value).c_str ();
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

    if (base && base->get_name)
      return (*base->get_name) (self);

    using RType = const gchar*;
    return RType ();
  }

  auto
  Action_Class::get_parameter_type_vfunc_callback (GAction* self) -> const GVariantType*
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
          static auto quark_return_value = g_quark_from_static_string (
              "gio::Action::get_parameter_type_vfunc");

          auto return_value = static_cast<glib::VariantType*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new glib::VariantType ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &glib::destroy_notify_delete<glib::VariantType>);
          }

          *return_value = obj->get_parameter_type_vfunc ();
          return (*return_value).gobj ();
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

    if (base && base->get_parameter_type)
      return (*base->get_parameter_type) (self);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  Action_Class::get_state_type_vfunc_callback (GAction* self) -> const GVariantType*
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
          static auto quark_return_value =
              g_quark_from_static_string ("gio::Action::get_state_type_vfunc");

          auto return_value = static_cast<glib::VariantType*> (
              g_object_get_qdata (obj_base->gobj (), quark_return_value));
          if (!return_value)
          {
            return_value = new glib::VariantType ();
            g_object_set_qdata_full (
                obj_base->gobj (),
                quark_return_value,
                return_value,
                &glib::destroy_notify_delete<glib::VariantType>);
          }

          *return_value = obj->get_state_type_vfunc ();
          return (*return_value).gobj ();
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

    if (base && base->get_state_type)
      return (*base->get_state_type) (self);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  Action_Class::get_state_hint_vfunc_callback (GAction* self) -> GVariant*
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
          return unwrap_copy (obj->get_state_hint_vfunc ());
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

    if (base && base->get_state_hint)
      return (*base->get_state_hint) (self);

    using RType = GVariant*;
    return RType ();
  }

  auto
  Action_Class::get_enabled_vfunc_callback (GAction* self) -> gboolean
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
          return obj->get_enabled_vfunc ();
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

    if (base && base->get_enabled)
      return (*base->get_enabled) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  Action_Class::get_state_vfunc_callback (GAction* self) -> GVariant*
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
          return unwrap_copy (obj->get_state_vfunc ());
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

    if (base && base->get_state)
      return (*base->get_state) (self);

    using RType = GVariant*;
    return RType ();
  }

  auto
  Action_Class::change_state_vfunc_callback (GAction* self, GVariant* value) -> void
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
          obj->change_state_vfunc (glib::wrap (value, true));
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

    if (base && base->change_state)
      (*base->change_state) (self, value);
  }

  auto
  Action_Class::activate_vfunc_callback (GAction* self, GVariant* parameter) -> void
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
          obj->activate_vfunc (glib::wrap (parameter, true));
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

    if (base && base->activate)
      (*base->activate) (self, parameter);
  }

  auto
  Action_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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

  Action::Action (const glib::Interface_Class& interface_class)
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
  Action::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_action_get_name (const_cast<GAction*> (gobj ())));
  }

  auto
  Action::get_parameter_type () const -> glib::VariantType
  {
    return glib::wrap (const_cast<GVariantType*> (g_action_get_parameter_type (
                           const_cast<GAction*> (gobj ()))),
                       true);
  }

  auto
  Action::get_state_type () const -> glib::VariantType
  {
    return glib::wrap (const_cast<GVariantType*> (g_action_get_state_type (
                           const_cast<GAction*> (gobj ()))),
                       true);
  }

  auto
  Action::get_state_hint_variant () const -> glib::VariantContainerBase
  {
    return glib::VariantContainerBase (
        g_action_get_state_hint (const_cast<GAction*> (gobj ())),
        false);
  }

  auto
  Action::get_enabled () const -> bool
  {
    return g_action_get_enabled (const_cast<GAction*> (gobj ()));
  }

  auto
  Action::change_state_variant (const glib::VariantBase& value) -> void
  {
    g_action_change_state (gobj (), const_cast<GVariant*> (value.gobj ()));
  }

  auto
  Action::get_state_variant () const -> glib::VariantBase
  {
    return glib::wrap (g_action_get_state (const_cast<GAction*> (gobj ())),
                       false);
  }

  auto
  Action::activate_variant (const glib::VariantBase& parameter) -> void
  {
    g_action_activate (gobj (), const_cast<GVariant*> (parameter.gobj ()));
  }

  auto
  Action::name_is_valid (const glib::ustring& action_name) -> bool
  {
    return g_action_name_is_valid (action_name.c_str ());
  }

  auto
  Action::parse_detailed_name_variant (const glib::ustring& detailed_name,
                                       glib::ustring& action_name,
                                       glib::VariantBase& target_value) -> void
  {
    GError* gerror = nullptr;
    gchar* g_action_name = nullptr;
    GVariant* g_target_value = nullptr;
    g_action_parse_detailed_name (detailed_name.c_str (),
                                  &g_action_name,
                                  &g_target_value,
                                  &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    action_name = glib::convert_return_gchar_ptr_to_ustring (g_action_name);
    target_value = glib::wrap (g_target_value);
  }

  auto
  Action::print_detailed_name_variant (const glib::ustring& action_name,
                                       const glib::VariantBase& target_value) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_action_print_detailed_name (
            action_name.c_str (),
            const_cast<GVariant*> (target_value.gobj ())));
  }

  auto
  Action::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  auto
  Action::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Action::property_parameter_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "parameter-type"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantBase>::value,
      "Type glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Action::property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>
  {
    return {this, "state"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantType>::value,
      "Type glib::VariantType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Action::property_state_type () const -> glib::PropertyProxy_ReadOnly<glib::VariantType>
  {
    return {this, "state-type"};
  }

  auto
  Action::get_name_vfunc () const -> glib::ustring
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_name)
    {
      glib::ustring retval (glib::convert_const_gchar_ptr_to_ustring (
          (*base->get_name) (const_cast<GAction*> (gobj ()))));
      return retval;
    }

    using RType = glib::ustring;
    return {};
  }

  auto
  Action::get_parameter_type_vfunc () const -> glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_parameter_type)
    {
      glib::VariantType retval (glib::wrap (
          const_cast<GVariantType*> (
              (*base->get_parameter_type) (const_cast<GAction*> (gobj ()))),
          true));
      return retval;
    }

    using RType = glib::VariantType;
    return {};
  }

  auto
  Action::get_state_type_vfunc () const -> glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state_type)
    {
      glib::VariantType retval (glib::wrap (
          const_cast<GVariantType*> (
              (*base->get_state_type) (const_cast<GAction*> (gobj ()))),
          true));
      return retval;
    }

    using RType = glib::VariantType;
    return {};
  }

  auto
  Action::get_state_hint_vfunc () const -> glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state_hint)
    {
      glib::VariantBase retval (
          glib::wrap ((*base->get_state_hint) (const_cast<GAction*> (gobj ())),
                      false));
      return retval;
    }

    using RType = glib::VariantBase;
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
  Action::get_state_vfunc () const -> glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_state)
    {
      glib::VariantBase retval (
          glib::wrap ((*base->get_state) (const_cast<GAction*> (gobj ())),
                      false));
      return retval;
    }

    using RType = glib::VariantBase;
    return {};
  }

  auto
  Action::change_state_vfunc (const glib::VariantBase& value) -> void
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
  Action::activate_vfunc (const glib::VariantBase& parameter) -> void
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

} // namespace gio
