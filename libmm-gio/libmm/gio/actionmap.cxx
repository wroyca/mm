// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/actionmap.hxx>
#include <libmm/gio/actionmap_p.hxx>

#include <libmm/gio/action.hxx>
#include <libmm/gio/simpleaction.hxx>

namespace gio
{

  auto
  ActionMap::add_action (const glib::ustring& name) -> glib::RefPtr<SimpleAction>
  {
    auto action = SimpleAction::create (name);
    add_action (action);
    return action;
  }

  auto
  ActionMap::add_action (const glib::ustring& name, const ActivateSlot& slot) -> glib::RefPtr<SimpleAction>
  {
    auto action = add_action (name);
    action->signal_activate ().connect (hide (slot));
    return action;
  }

  auto
  ActionMap::add_action_with_parameter (const glib::ustring& name,
                                        const glib::VariantType& parameter_type,
                                        const ActivateWithParameterSlot& slot) -> glib::RefPtr<SimpleAction>
  {
    auto action = SimpleAction::create (name, parameter_type);
    action->signal_activate ().connect (slot);
    add_action (action);
    return action;
  }

  auto
  ActionMap::add_action_bool (const glib::ustring& name, const bool state) -> glib::RefPtr<SimpleAction>
  {
    auto action = SimpleAction::create_bool (name, state);
    add_action (action);
    return action;
  }

  auto
  ActionMap::add_action_bool (const glib::ustring& name,
                              const ActivateSlot& slot,
                              const bool state) -> glib::RefPtr<SimpleAction>
  {
    auto action = add_action_bool (name, state);
    action->signal_activate ().connect (hide (slot));
    return action;
  }

  auto
  ActionMap::add_action_radio_string (const glib::ustring& name,
                                      const glib::ustring& state) -> glib::RefPtr<SimpleAction>
  {
    auto action = SimpleAction::create_radio_string (name, state);
    add_action (action);
    return action;
  }

  namespace
  {

    auto
    on_action_radio_string (
        const glib::VariantBase& parameter,
        const ActionMap::ActivateWithStringParameterSlot& slot) -> void
    {
      const auto variantDerived =
          glib::VariantBase::cast_dynamic<glib::Variant<glib::ustring>> (
              parameter);
      const auto str = variantDerived.get ();
      slot (str);
    }

  } // namespace

  auto
  ActionMap::add_action_radio_string (
      const glib::ustring& name,
      const ActivateWithStringParameterSlot& slot,
      const glib::ustring& state) -> glib::RefPtr<SimpleAction>
  {
    auto action = add_action_radio_string (name, state);
    action->signal_activate ().connect (
        bind (ptr_fun (&on_action_radio_string), slot));
    return action;
  }

  namespace
  {

    auto
    on_action_radio_int (const glib::VariantBase& parameter,
                         const ActionMap::ActivateWithIntParameterSlot& slot)
        -> void
    {
      const auto variantDerived =
          glib::VariantBase::cast_dynamic<glib::Variant<int>> (parameter);
      const auto str = variantDerived.get ();
      slot (str);
    }

  } // namespace

  auto
  ActionMap::add_action_radio_integer (const glib::ustring& name,
                                       const gint32 state) -> glib::RefPtr<SimpleAction>
  {
    auto action = SimpleAction::create_radio_integer (name, state);
    add_action (action);
    return action;
  }

  auto
  ActionMap::add_action_radio_integer (const glib::ustring& name,
                                       const ActivateWithIntParameterSlot& slot,
                                       const gint32 state) -> glib::RefPtr<SimpleAction>
  {
    auto action = add_action_radio_integer (name, state);
    action->signal_activate ().connect (
        bind (ptr_fun (&on_action_radio_int), slot));
    return action;
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GActionMap* object, const bool take_copy) -> RefPtr<gio::ActionMap>
  {
    return glib::make_refptr_for_instance<gio::ActionMap> (
        glib::wrap_auto_interface<gio::ActionMap> ((GObject*) object,
                                                   take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  ActionMap_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionMap_Class::iface_init_function;

      gtype_ = g_action_map_get_type ();
    }

    return *this;
  }

  auto
  ActionMap_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->lookup_action = &lookup_action_vfunc_callback;
    klass->add_action = &add_action_vfunc_callback;
    klass->remove_action = &remove_action_vfunc_callback;
  }

  auto
  ActionMap_Class::lookup_action_vfunc_callback (GActionMap* self,
                                                 const gchar* action_name) -> GAction*
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
          return glib::unwrap (obj->lookup_action_vfunc (
              glib::convert_const_gchar_ptr_to_ustring (action_name)));
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

    if (base && base->lookup_action)
      return (*base->lookup_action) (self, action_name);

    using RType = GAction*;
    return RType ();
  }

  auto
  ActionMap_Class::add_action_vfunc_callback (GActionMap* self, GAction* action) -> void
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
          obj->add_action_vfunc (glib::wrap (action, true));
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

    if (base && base->add_action)
      (*base->add_action) (self, action);
  }

  auto
  ActionMap_Class::remove_action_vfunc_callback (GActionMap* self,
                                                 const gchar* action_name) -> void
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
          obj->remove_action_vfunc (
              glib::convert_const_gchar_ptr_to_ustring (action_name));
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

    if (base && base->remove_action)
      (*base->remove_action) (self, action_name);
  }

  auto
  ActionMap_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ActionMap ((GActionMap*) object);
  }

  ActionMap::ActionMap ()
    : Interface (actionmap_class_.init ())
  {
  }

  ActionMap::ActionMap (GActionMap* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ActionMap::ActionMap (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ActionMap::ActionMap (ActionMap&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ActionMap::operator= (ActionMap&& src) noexcept -> ActionMap&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ActionMap::~ActionMap () noexcept = default;

  auto
  ActionMap::add_interface (const GType gtype_implementer) -> void
  {
    actionmap_class_.init ().add_interface (gtype_implementer);
  }

  ActionMap::CppClassType ActionMap::actionmap_class_;

  auto
  ActionMap::get_type () -> GType
  {
    return actionmap_class_.init ().get_type ();
  }

  auto
  ActionMap::get_base_type () -> GType
  {
    return g_action_map_get_type ();
  }

  auto
  ActionMap::add_action (const glib::RefPtr<Action>& action) -> void
  {
    g_action_map_add_action (gobj (), glib::unwrap (action));
  }

  auto
  ActionMap::remove_action (const glib::ustring& action_name) -> void
  {
    g_action_map_remove_action (gobj (), action_name.c_str ());
  }

  auto
  ActionMap::lookup_action (const glib::ustring& action_name) -> glib::RefPtr<Action>
  {
    auto retvalue =
        glib::wrap (g_action_map_lookup_action (gobj (), action_name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ActionMap::lookup_action (const glib::ustring& action_name) const -> glib::RefPtr<const Action>
  {
    return const_cast<ActionMap*> (this)->lookup_action (action_name);
  }

  auto
  ActionMap::lookup_action_vfunc (const glib::ustring& name) const -> glib::RefPtr<Action>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->lookup_action)
    {
      glib::RefPtr<Action> retval (
          glib::wrap ((*base->lookup_action) (const_cast<GActionMap*> (gobj ()),
                                              name.c_str ()),
                      true));
      return retval;
    }

    using RType = glib::RefPtr<Action>;
    return {};
  }

  auto
  ActionMap::add_action_vfunc (const glib::RefPtr<Action>& action) const -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->add_action)
    {
      (*base->add_action) (const_cast<GActionMap*> (gobj ()),
                           glib::unwrap (action));
    }
  }

  auto
  ActionMap::remove_action_vfunc (const glib::ustring& name) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->remove_action)
    {
      (*base->remove_action) (gobj (), name.c_str ());
    }
  }

} // namespace gio
