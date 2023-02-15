// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/actiongroup.hxx>
#include <libmm-gio/actiongroup_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/vectorutils.hxx>

namespace Gio
{

}

namespace
{

  auto
  ActionGroup_signal_action_added_callback (GActionGroup* self,
                                            const gchar* p0,
                                            void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    const auto obj = dynamic_cast<ActionGroup*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo ActionGroup_signal_action_added_info = {
      "action-added",
      (GCallback) &ActionGroup_signal_action_added_callback,
      (GCallback) &ActionGroup_signal_action_added_callback};

  auto
  ActionGroup_signal_action_enabled_changed_callback (GActionGroup* self,
                                                      const gchar* p0,
                                                      const gboolean p1,
                                                      void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::ustring&, bool)>;

    const auto obj = dynamic_cast<ActionGroup*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (Glib::convert_const_gchar_ptr_to_ustring (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo ActionGroup_signal_action_enabled_changed_info = {
      "action-enabled-changed",
      (GCallback) &ActionGroup_signal_action_enabled_changed_callback,
      (GCallback) &ActionGroup_signal_action_enabled_changed_callback};

  auto
  ActionGroup_signal_action_removed_callback (GActionGroup* self,
                                              const gchar* p0,
                                              void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    const auto obj = dynamic_cast<ActionGroup*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo ActionGroup_signal_action_removed_info = {
      "action-removed",
      (GCallback) &ActionGroup_signal_action_removed_callback,
      (GCallback) &ActionGroup_signal_action_removed_callback};

  auto
  ActionGroup_signal_action_state_changed_callback (GActionGroup* self,
                                                    const gchar* p0,
                                                    GVariant* p1,
                                                    void* data) -> void
  {
    using namespace Gio;
    using SlotType =
        sigc::slot<void (const Glib::ustring&, const Glib::VariantBase&)>;

    const auto obj = dynamic_cast<ActionGroup*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0),
              Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo ActionGroup_signal_action_state_changed_info = {
      "action-state-changed",
      (GCallback) &ActionGroup_signal_action_state_changed_callback,
      (GCallback) &ActionGroup_signal_action_state_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GActionGroup* object, const bool take_copy) -> RefPtr<Gio::ActionGroup>
  {
    return Glib::make_refptr_for_instance<Gio::ActionGroup> (
        Glib::wrap_auto_interface<Gio::ActionGroup> ((GObject*) object,
                                                     take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  ActionGroup_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionGroup_Class::iface_init_function;

      gtype_ = g_action_group_get_type ();
    }

    return *this;
  }

  auto
  ActionGroup_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->has_action = &has_action_vfunc_callback;
    klass->list_actions = &list_actions_vfunc_callback;
    klass->get_action_enabled = &get_action_enabled_vfunc_callback;
    klass->get_action_parameter_type =
        &get_action_parameter_type_vfunc_callback;
    klass->get_action_state_type = &get_action_state_type_vfunc_callback;
    klass->get_action_state_hint = &get_action_state_hint_vfunc_callback;
    klass->get_action_state = &get_action_state_vfunc_callback;
    klass->change_action_state = &change_action_state_vfunc_callback;
    klass->activate_action = &activate_action_vfunc_callback;

    klass->action_added = &action_added_callback;
    klass->action_enabled_changed = &action_enabled_changed_callback;
    klass->action_removed = &action_removed_callback;
    klass->action_state_changed = &action_state_changed_callback;
  }

  auto
  ActionGroup_Class::has_action_vfunc_callback (GActionGroup* self,
                                                const gchar* action_name) -> gboolean
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
          return obj->has_action_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name));
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

    if (base && base->has_action)
      return (*base->has_action) (self, action_name);

    using RType = gboolean;
    return RType ();
  }

  auto
  ActionGroup_Class::list_actions_vfunc_callback (GActionGroup* self) -> gchar**
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
          return g_strdupv (const_cast<gchar**> (
              Glib::ArrayHandler<Glib::ustring>::vector_to_array (
                  obj->list_actions_vfunc ())
                  .data ()));
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

    if (base && base->list_actions)
      return (*base->list_actions) (self);

    using RType = gchar**;
    return RType ();
  }

  auto
  ActionGroup_Class::get_action_enabled_vfunc_callback (
      GActionGroup* self,
      const gchar* action_name) -> gboolean
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
          return obj->get_action_enabled_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name));
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

    if (base && base->get_action_enabled)
      return (*base->get_action_enabled) (self, action_name);

    using RType = gboolean;
    return RType ();
  }

  auto
  ActionGroup_Class::get_action_parameter_type_vfunc_callback (
      GActionGroup* self,
      const gchar* action_name) -> const GVariantType*
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
              "Gio::ActionGroup::get_action_parameter_type_vfunc");

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

          *return_value = obj->get_action_parameter_type_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name));
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

    if (base && base->get_action_parameter_type)
      return (*base->get_action_parameter_type) (self, action_name);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  ActionGroup_Class::get_action_state_type_vfunc_callback (
      GActionGroup* self,
      const gchar* action_name) -> const GVariantType*
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
              "Gio::ActionGroup::get_action_state_type_vfunc");

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

          *return_value = obj->get_action_state_type_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name));
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

    if (base && base->get_action_state_type)
      return (*base->get_action_state_type) (self, action_name);

    using RType = const GVariantType*;
    return RType ();
  }

  auto
  ActionGroup_Class::get_action_state_hint_vfunc_callback (
      GActionGroup* self,
      const gchar* action_name) -> GVariant*
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
          return unwrap_copy (obj->get_action_state_hint_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name)));
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

    if (base && base->get_action_state_hint)
      return (*base->get_action_state_hint) (self, action_name);

    using RType = GVariant*;
    return RType ();
  }

  auto
  ActionGroup_Class::get_action_state_vfunc_callback (GActionGroup* self,
                                                      const gchar* action_name) -> GVariant*
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
          return unwrap_copy (obj->get_action_state_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name)));
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

    if (base && base->get_action_state)
      return (*base->get_action_state) (self, action_name);

    using RType = GVariant*;
    return RType ();
  }

  auto
  ActionGroup_Class::change_action_state_vfunc_callback (
      GActionGroup* self,
      const gchar* action_name,
      GVariant* value) -> void
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
          obj->change_action_state_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name),
              Glib::wrap (value, true));
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

    if (base && base->change_action_state)
      (*base->change_action_state) (self, action_name, value);
  }

  auto
  ActionGroup_Class::activate_action_vfunc_callback (GActionGroup* self,
                                                     const gchar* action_name,
                                                     GVariant* parameter) -> void
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
          obj->activate_action_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name),
              Glib::wrap (parameter, true));
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

    if (base && base->activate_action)
      (*base->activate_action) (self, action_name, parameter);
  }

  auto
  ActionGroup_Class::action_added_callback (GActionGroup* self, const gchar* p0) -> void
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
          obj->on_action_added (Glib::convert_const_gchar_ptr_to_ustring (p0));
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

    if (base && base->action_added)
      (*base->action_added) (self, p0);
  }

  auto
  ActionGroup_Class::action_enabled_changed_callback (GActionGroup* self,
                                                      const gchar* p0,
                                                      const gboolean p1) -> void
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
          obj->on_action_enabled_changed (
              Glib::convert_const_gchar_ptr_to_ustring (p0),
              p1);
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

    if (base && base->action_enabled_changed)
      (*base->action_enabled_changed) (self, p0, p1);
  }

  auto
  ActionGroup_Class::action_removed_callback (GActionGroup* self,
                                              const gchar* p0) -> void
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
          obj->on_action_removed (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
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

    if (base && base->action_removed)
      (*base->action_removed) (self, p0);
  }

  auto
  ActionGroup_Class::action_state_changed_callback (GActionGroup* self,
                                                    const gchar* p0,
                                                    GVariant* p1) -> void
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
          obj->on_action_state_changed (
              Glib::convert_const_gchar_ptr_to_ustring (p0),
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

    if (base && base->action_state_changed)
      (*base->action_state_changed) (self, p0, p1);
  }

  auto
  ActionGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ActionGroup ((GActionGroup*) object);
  }

  ActionGroup::ActionGroup ()
    : Interface (actiongroup_class_.init ())
  {
  }

  ActionGroup::ActionGroup (GActionGroup* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ActionGroup::ActionGroup (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ActionGroup::ActionGroup (ActionGroup&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ActionGroup::operator= (ActionGroup&& src) noexcept -> ActionGroup&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ActionGroup::~ActionGroup () noexcept = default;

  auto
  ActionGroup::add_interface (const GType gtype_implementer) -> void
  {
    actiongroup_class_.init ().add_interface (gtype_implementer);
  }

  ActionGroup::CppClassType ActionGroup::actiongroup_class_;

  auto
  ActionGroup::get_type () -> GType
  {
    return actiongroup_class_.init ().get_type ();
  }

  auto
  ActionGroup::get_base_type () -> GType
  {
    return g_action_group_get_type ();
  }

  auto
  ActionGroup::has_action (const Glib::ustring& action_name) const -> bool
  {
    return g_action_group_has_action (const_cast<GActionGroup*> (gobj ()),
                                      action_name.c_str ());
  }

  auto
  ActionGroup::list_actions () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        g_action_group_list_actions (const_cast<GActionGroup*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantType& parameter_type,
                             Glib::VariantBase& state_hint,
                             Glib::VariantType& state_type,
                             Glib::VariantBase& state) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_parameter_type = nullptr;
    const GVariantType* g_state_type = nullptr;
    GVariant* g_state_hint = nullptr;
    GVariant* g_state = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       &g_parameter_type,
                                                       &g_state_type,
                                                       &g_state_hint,
                                                       &g_state);
    enabled = static_cast<bool> (g_enabled);
    parameter_type = Glib::wrap (const_cast<GVariantType*> (g_parameter_type));
    state_type = Glib::wrap (const_cast<GVariantType*> (g_state_type));
    state_hint = Glib::wrap (g_state_hint);
    state = Glib::wrap (g_state);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantType& parameter_type,
                             Glib::VariantBase& state_hint,
                             Glib::VariantType& state_type) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_parameter_type = nullptr;
    const GVariantType* g_state_type = nullptr;
    GVariant* g_state_hint = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       &g_parameter_type,
                                                       &g_state_type,
                                                       &g_state_hint,
                                                       nullptr);
    enabled = static_cast<bool> (g_enabled);
    parameter_type = Glib::wrap (const_cast<GVariantType*> (g_parameter_type));
    state_type = Glib::wrap (const_cast<GVariantType*> (g_state_type));
    state_hint = Glib::wrap (g_state_hint);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantType& parameter_type,
                             Glib::VariantBase& state_hint,
                             Glib::VariantBase& state) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_parameter_type = nullptr;
    GVariant* g_state_hint = nullptr;
    GVariant* g_state = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       &g_parameter_type,
                                                       nullptr,
                                                       &g_state_hint,
                                                       &g_state);
    enabled = static_cast<bool> (g_enabled);
    parameter_type = Glib::wrap (const_cast<GVariantType*> (g_parameter_type));
    state_hint = Glib::wrap (g_state_hint);
    state = Glib::wrap (g_state);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantType& parameter_type,
                             Glib::VariantBase& state_hint) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_parameter_type = nullptr;
    GVariant* g_state_hint = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       &g_parameter_type,
                                                       nullptr,
                                                       &g_state_hint,
                                                       nullptr);
    enabled = static_cast<bool> (g_enabled);
    parameter_type = Glib::wrap (const_cast<GVariantType*> (g_parameter_type));
    state_hint = Glib::wrap (g_state_hint);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantBase& state_hint,
                             Glib::VariantType& state_type,
                             Glib::VariantBase& state) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_state_type = nullptr;
    GVariant* g_state_hint = nullptr;
    GVariant* g_state = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       nullptr,
                                                       &g_state_type,
                                                       &g_state_hint,
                                                       &g_state);
    enabled = static_cast<bool> (g_enabled);
    state_type = Glib::wrap (const_cast<GVariantType*> (g_state_type));
    state_hint = Glib::wrap (g_state_hint);
    state = Glib::wrap (g_state);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantBase& state_hint,
                             Glib::VariantType& state_type) -> bool
  {
    gboolean g_enabled = gboolean ();
    const GVariantType* g_state_type = nullptr;
    GVariant* g_state_hint = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       nullptr,
                                                       &g_state_type,
                                                       &g_state_hint,
                                                       nullptr);
    enabled = static_cast<bool> (g_enabled);
    state_type = Glib::wrap (const_cast<GVariantType*> (g_state_type));
    state_hint = Glib::wrap (g_state_hint);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantBase& state_hint,
                             Glib::VariantBase& state) -> bool
  {
    gboolean g_enabled = gboolean ();
    GVariant* g_state_hint = nullptr;
    GVariant* g_state = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       nullptr,
                                                       nullptr,
                                                       &g_state_hint,
                                                       &g_state);
    enabled = static_cast<bool> (g_enabled);
    state_hint = Glib::wrap (g_state_hint);
    state = Glib::wrap (g_state);
    return retvalue;
  }

  auto
  ActionGroup::query_action (const Glib::ustring& action_name,
                             bool& enabled,
                             Glib::VariantBase& state_hint) -> bool
  {
    gboolean g_enabled = gboolean ();
    GVariant* g_state_hint = nullptr;
    const auto retvalue = g_action_group_query_action (gobj (),
                                                       action_name.c_str (),
                                                       &g_enabled,
                                                       nullptr,
                                                       nullptr,
                                                       &g_state_hint,
                                                       nullptr);
    enabled = static_cast<bool> (g_enabled);
    state_hint = Glib::wrap (g_state_hint);
    return retvalue;
  }

  auto
  ActionGroup::get_action_enabled (const Glib::ustring& action_name) const -> bool
  {
    return g_action_group_get_action_enabled (
        const_cast<GActionGroup*> (gobj ()),
        action_name.c_str ());
  }

  auto
  ActionGroup::get_action_parameter_type (
      const Glib::ustring& action_name) const -> Glib::VariantType
  {
    return Glib::wrap (
        const_cast<GVariantType*> (g_action_group_get_action_parameter_type (
            const_cast<GActionGroup*> (gobj ()),
            action_name.c_str ())),
        true);
  }

  auto
  ActionGroup::get_action_state_type (const Glib::ustring& action_name) const -> Glib::VariantType
  {
    return Glib::wrap (
        const_cast<GVariantType*> (g_action_group_get_action_state_type (
            const_cast<GActionGroup*> (gobj ()),
            action_name.c_str ())),
        true);
  }

  auto
  ActionGroup::get_action_state_hint_variant (
      const Glib::ustring& action_name) const -> Glib::VariantContainerBase
  {
    return Glib::VariantContainerBase (g_action_group_get_action_state_hint (
                                           const_cast<GActionGroup*> (gobj ()),
                                           action_name.c_str ()),
                                       false);
  }

  auto
  ActionGroup::get_action_state_variant (const Glib::ustring& action_name) const -> Glib::VariantBase
  {
    return Glib::wrap (
        g_action_group_get_action_state (const_cast<GActionGroup*> (gobj ()),
                                         action_name.c_str ()),
        false);
  }

  auto
  ActionGroup::change_action_state (const Glib::ustring& action_name,
                                    const Glib::VariantBase& value) -> void
  {
    g_action_group_change_action_state (gobj (),
                                        action_name.c_str (),
                                        const_cast<GVariant*> (value.gobj ()));
  }

  auto
  ActionGroup::activate_action (const Glib::ustring& action_name,
                                const Glib::VariantBase& parameter) -> void
  {
    g_action_group_activate_action (gobj (),
                                    action_name.c_str (),
                                    const_cast<GVariant*> (parameter.gobj ()));
  }

  auto
  ActionGroup::activate_action (const Glib::ustring& action_name) -> void
  {
    g_action_group_activate_action (gobj (), action_name.c_str (), nullptr);
  }

  auto
  ActionGroup::action_added (const Glib::ustring& action_name) -> void
  {
    g_action_group_action_added (gobj (), action_name.c_str ());
  }

  auto
  ActionGroup::action_removed (const Glib::ustring& action_name) -> void
  {
    g_action_group_action_removed (gobj (), action_name.c_str ());
  }

  auto
  ActionGroup::action_enabled_changed (const Glib::ustring& action_name,
                                       const bool enabled) -> void
  {
    g_action_group_action_enabled_changed (gobj (),
                                           action_name.c_str (),
                                           enabled);
  }

  auto
  ActionGroup::action_state_changed (const Glib::ustring& action_name,
                                     const Glib::VariantBase& state) -> void
  {
    g_action_group_action_state_changed (gobj (),
                                         action_name.c_str (),
                                         const_cast<GVariant*> (state.gobj ()));
  }

  auto
  ActionGroup::signal_action_added (const Glib::ustring& action_name) -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>
  {
    return Glib::SignalProxyDetailed<void (const Glib::ustring&)> (
        this,
        &ActionGroup_signal_action_added_info,
        action_name);
  }

  auto
  ActionGroup::signal_action_enabled_changed (const Glib::ustring& action_name) -> Glib::SignalProxyDetailed<void (const Glib::ustring&, bool)>
  {
    return Glib::SignalProxyDetailed<void (const Glib::ustring&, bool)> (
        this,
        &ActionGroup_signal_action_enabled_changed_info,
        action_name);
  }

  auto
  ActionGroup::signal_action_removed (const Glib::ustring& action_name) -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>
  {
    return Glib::SignalProxyDetailed<void (const Glib::ustring&)> (
        this,
        &ActionGroup_signal_action_removed_info,
        action_name);
  }

  auto
  ActionGroup::signal_action_state_changed (const Glib::ustring& action_name) -> Glib::SignalProxyDetailed<void (const Glib::ustring&,
                                         const Glib::VariantBase&)>
  {
    return Glib::SignalProxyDetailed<void (const Glib::ustring&,
                                           const Glib::VariantBase&)> (
        this,
        &ActionGroup_signal_action_state_changed_info,
        action_name);
  }

  auto
  ActionGroup::on_action_added (const Glib::ustring& action_name) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->action_added)
      (*base->action_added) (gobj (), action_name.c_str ());
  }

  auto
  ActionGroup::on_action_enabled_changed (const Glib::ustring& action_name,
                                          const bool enabled) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->action_enabled_changed)
      (*base->action_enabled_changed) (gobj (),
                                       action_name.c_str (),
                                       static_cast<int> (enabled));
  }

  auto
  ActionGroup::on_action_removed (const Glib::ustring& action_name) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->action_removed)
      (*base->action_removed) (gobj (), action_name.c_str ());
  }

  auto
  ActionGroup::on_action_state_changed (const Glib::ustring& action_name,
                                        const Glib::VariantBase& value) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->action_state_changed)
      (*base->action_state_changed) (gobj (),
                                     action_name.c_str (),
                                     const_cast<GVariant*> (value.gobj ()));
  }

  auto
  ActionGroup::has_action_vfunc (const Glib::ustring& name) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->has_action)
    {
      const bool retval (
          (*base->has_action) (const_cast<GActionGroup*> (gobj ()),
                               name.c_str ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  ActionGroup::list_actions_vfunc () const -> std::vector<Glib::ustring>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->list_actions)
    {
      std::vector<Glib::ustring> retval (
          Glib::ArrayHandler<Glib::ustring>::array_to_vector (
              (*base->list_actions) (const_cast<GActionGroup*> (gobj ())),
              Glib::OWNERSHIP_DEEP));
      return retval;
    }

    using RType = std::vector<Glib::ustring>;
    return {};
  }

  auto
  ActionGroup::get_action_enabled_vfunc (const Glib::ustring& name) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_action_enabled)
    {
      const bool retval (
          (*base->get_action_enabled) (const_cast<GActionGroup*> (gobj ()),
                                       name.c_str ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  ActionGroup::get_action_parameter_type_vfunc (const Glib::ustring& name) const -> Glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_action_parameter_type)
    {
      Glib::VariantType retval (Glib::wrap (
          const_cast<GVariantType*> ((*base->get_action_parameter_type) (
              const_cast<GActionGroup*> (gobj ()),
              name.c_str ())),
          true));
      return retval;
    }

    using RType = Glib::VariantType;
    return {};
  }

  auto
  ActionGroup::get_action_state_type_vfunc (const Glib::ustring& name) const -> Glib::VariantType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_action_state_type)
    {
      Glib::VariantType retval (Glib::wrap (
          const_cast<GVariantType*> ((*base->get_action_state_type) (
              const_cast<GActionGroup*> (gobj ()),
              name.c_str ())),
          true));
      return retval;
    }

    using RType = Glib::VariantType;
    return {};
  }

  auto
  ActionGroup::get_action_state_hint_vfunc (const Glib::ustring& name) const -> Glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_action_state_hint)
    {
      Glib::VariantBase retval (Glib::wrap (
          (*base->get_action_state_hint) (const_cast<GActionGroup*> (gobj ()),
                                          name.c_str ()),
          false));
      return retval;
    }

    using RType = Glib::VariantBase;
    return {};
  }

  auto
  ActionGroup::get_action_state_vfunc (const Glib::ustring& name) const -> Glib::VariantBase
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_action_state)
    {
      Glib::VariantBase retval (Glib::wrap (
          (*base->get_action_state) (const_cast<GActionGroup*> (gobj ()),
                                     name.c_str ()),
          false));
      return retval;
    }

    using RType = Glib::VariantBase;
    return {};
  }

  auto
  ActionGroup::change_action_state_vfunc (const Glib::ustring& name,
                                          const Glib::VariantBase& value) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->change_action_state)
    {
      (*base->change_action_state) (gobj (),
                                    name.c_str (),
                                    const_cast<GVariant*> (value.gobj ()));
    }
  }

  auto
  ActionGroup::activate_action_vfunc (const Glib::ustring& name,
                                      const Glib::VariantBase& parameter) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->activate_action)
    {
      (*base->activate_action) (gobj (),
                                name.c_str (),
                                const_cast<GVariant*> (parameter.gobj ()));
    }
  }

} // namespace Gio
