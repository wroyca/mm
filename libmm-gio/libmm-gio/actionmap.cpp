


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/actionmap.hpp>
#include <mm/gio/private/actionmap_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/gio/action.hpp>
#include <mm/gio/simpleaction.hpp>

namespace Gio
{

auto
ActionMap::add_action(const Glib::ustring& name) -> Glib::RefPtr<SimpleAction>
{
  auto action = SimpleAction::create(name);
  add_action(action);
  return action;
}

auto
ActionMap::add_action(const Glib::ustring& name, const ActivateSlot& slot) -> Glib::RefPtr<SimpleAction>
{
  auto action = add_action(name);
  action->signal_activate().connect(hide(slot));
  return action;
}

auto
ActionMap::add_action_with_parameter(
  const Glib::ustring& name, const Glib::VariantType& parameter_type, const ActivateWithParameterSlot& slot) -> Glib::RefPtr<SimpleAction>
{
  auto action = SimpleAction::create(name, parameter_type);
  action->signal_activate().connect(slot);
  add_action(action);
  return action;
}

auto
ActionMap::add_action_bool(const Glib::ustring& name, const bool state) -> Glib::RefPtr<SimpleAction>
{
  auto action = SimpleAction::create_bool(name, state);
  add_action(action);
  return action;
}

// TODO: Use a slot that takes a bool?
auto
ActionMap::add_action_bool(const Glib::ustring& name, const ActivateSlot& slot, const bool state) -> Glib::RefPtr<SimpleAction>
{
  auto action = add_action_bool(name, state);
  action->signal_activate().connect(hide(slot));
  return action;
}

// TODO: Use a slot that takes a string?
auto
ActionMap::add_action_radio_string(const Glib::ustring& name, const Glib::ustring& state) -> Glib::RefPtr<SimpleAction>
{
  auto action = SimpleAction::create_radio_string(name, state);
  add_action(action);
  return action;
}

namespace
{

// Handle the normal activate signal, calling instead a slot that takes the specific type:
auto on_action_radio_string (
  const Glib::VariantBase &parameter,
  const ActionMap::ActivateWithStringParameterSlot &slot) -> void
{
  const auto variantDerived = Glib::VariantBase::cast_dynamic<Glib::Variant<Glib::ustring>>(parameter);
  const auto str = variantDerived.get();
  slot(str);
}

} // anonymous namespace

auto
ActionMap::add_action_radio_string(const Glib::ustring& name,
  const ActivateWithStringParameterSlot& slot, const Glib::ustring& state) -> Glib::RefPtr<SimpleAction>
{
  auto action = add_action_radio_string(name, state);
  action->signal_activate().connect(bind(ptr_fun(&on_action_radio_string), slot));
  return action;
}

namespace
{

// Handle the normal activate signal, calling instead a slot that takes the specific type:
auto on_action_radio_int (
  const Glib::VariantBase &parameter,
  const ActionMap::ActivateWithIntParameterSlot &slot) -> void
{
  const auto variantDerived = Glib::VariantBase::cast_dynamic<Glib::Variant<int>>(parameter);
  const auto str = variantDerived.get();
  slot(str);
}

} // anonymous namespace

// TODO: Use a slot that takes an integer?
auto
ActionMap::add_action_radio_integer(const Glib::ustring& name, const gint32 state) -> Glib::RefPtr<SimpleAction>
{
  auto action = SimpleAction::create_radio_integer(name, state);
  add_action(action);
  return action;
}

auto
ActionMap::add_action_radio_integer(
  const Glib::ustring& name, const ActivateWithIntParameterSlot& slot, const gint32 state) -> Glib::RefPtr<SimpleAction>
{
  auto action = add_action_radio_integer(name, state);
  action->signal_activate().connect(bind(ptr_fun(&on_action_radio_int), slot));
  return action;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GActionMap* object, const bool take_copy) -> RefPtr<Gio::ActionMap>
{
  return Glib::make_refptr_for_instance<Gio::ActionMap>( Glib::wrap_auto_interface<Gio::ActionMap> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto ActionMap_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ActionMap_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_action_map_get_type();
  }

  return *this;
}

auto ActionMap_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->lookup_action = &lookup_action_vfunc_callback;
  klass->add_action = &add_action_vfunc_callback;
  klass->remove_action = &remove_action_vfunc_callback;

}

auto ActionMap_Class::lookup_action_vfunc_callback(GActionMap* self, const gchar* action_name) -> GAction*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return Glib::unwrap(obj->lookup_action_vfunc(Glib::convert_const_gchar_ptr_to_ustring(action_name)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->lookup_action)
    return (*base->lookup_action)(self, action_name);

  using RType = GAction*;
  return RType();
}
auto ActionMap_Class::add_action_vfunc_callback (GActionMap *self, GAction *action) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->add_action_vfunc(Glib::wrap(action, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->add_action)
    (*base->add_action)(self, action);
}
auto ActionMap_Class::remove_action_vfunc_callback (
  GActionMap *self, const gchar *action_name) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->remove_action_vfunc(Glib::convert_const_gchar_ptr_to_ustring(action_name)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->remove_action)
    (*base->remove_action)(self, action_name);
}


auto ActionMap_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ActionMap((GActionMap*)object);
}


/* The implementation: */

ActionMap::ActionMap()
: Interface(actionmap_class_.init())
{}

ActionMap::ActionMap(GActionMap* castitem)
: Interface((GObject*)castitem)
{}

ActionMap::ActionMap(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ActionMap::ActionMap(ActionMap&& src) noexcept
: Interface(std::move(src))
{}

auto ActionMap::operator=(ActionMap&& src) noexcept -> ActionMap&
{
  Interface::operator=(std::move(src));
  return *this;
}

ActionMap::~ActionMap() noexcept = default;

// static
auto ActionMap::add_interface (
  const GType gtype_implementer) -> void
{
  actionmap_class_.init().add_interface(gtype_implementer);
}

ActionMap::CppClassType ActionMap::actionmap_class_; // initialize static member

auto ActionMap::get_type() -> GType
{
  return actionmap_class_.init().get_type();
}


auto ActionMap::get_base_type() -> GType
{
  return g_action_map_get_type();
}


auto ActionMap::add_action (const Glib::RefPtr <Action> &action) -> void
{
  g_action_map_add_action(gobj(), Glib::unwrap(action));
}

auto ActionMap::remove_action (const Glib::ustring &action_name) -> void
{
  g_action_map_remove_action(gobj(), action_name.c_str());
}

auto ActionMap::lookup_action(const Glib::ustring& action_name) -> Glib::RefPtr<Action>
{
  auto retvalue = Glib::wrap(g_action_map_lookup_action(gobj(), action_name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ActionMap::lookup_action(const Glib::ustring& action_name) const -> Glib::RefPtr<const Action>
{
  return const_cast<ActionMap*>(this)->lookup_action(action_name);
}


auto ActionMap::lookup_action_vfunc(const Glib::ustring& name) const -> Glib::RefPtr<Action>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->lookup_action)
  {
    Glib::RefPtr<Action> retval(Glib::wrap((*base->lookup_action)(const_cast<GActionMap*>(gobj()),name.c_str()), true));
    return retval;
  }

  using RType = Glib::RefPtr<Action>;
  return {};
}
auto ActionMap::add_action_vfunc (const Glib::RefPtr <Action> &action) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->add_action)
  {
    (*base->add_action)(const_cast<GActionMap*>(gobj()),Glib::unwrap(action));
  }
}
auto ActionMap::remove_action_vfunc (const Glib::ustring &name) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->remove_action)
  {
    (*base->remove_action)(gobj(),name.c_str());
  }
}


} // namespace Gio


