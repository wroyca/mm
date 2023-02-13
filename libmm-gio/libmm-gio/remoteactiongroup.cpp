


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/remoteactiongroup.hpp>
#include <mm/gio/private/remoteactiongroup_p.hpp>


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

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GRemoteActionGroup* object, const bool take_copy) -> RefPtr<Gio::RemoteActionGroup>
{
  return Glib::make_refptr_for_instance<Gio::RemoteActionGroup>( Glib::wrap_auto_interface<Gio::RemoteActionGroup> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto RemoteActionGroup_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &RemoteActionGroup_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_remote_action_group_get_type();
  }

  return *this;
}

auto RemoteActionGroup_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->activate_action_full = &activate_action_full_vfunc_callback;
  klass->change_action_state_full = &change_action_state_full_vfunc_callback;

}

auto RemoteActionGroup_Class::activate_action_full_vfunc_callback (
  GRemoteActionGroup *self, const gchar *action_name, GVariant *parameter,
  GVariant *platform_data) -> void
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
        obj->activate_action_full_vfunc(Glib::convert_const_gchar_ptr_to_ustring(action_name)
, Glib::wrap(parameter, true)
, Glib::wrap(platform_data, true)
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
  if(base && base->activate_action_full)
    (*base->activate_action_full)(self, action_name, parameter, platform_data);
}
auto RemoteActionGroup_Class::change_action_state_full_vfunc_callback (
  GRemoteActionGroup *self, const gchar *action_name, GVariant *value,
  GVariant *platform_data) -> void
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
        obj->change_action_state_full_vfunc(Glib::convert_const_gchar_ptr_to_ustring(action_name)
, Glib::wrap(value, true)
, Glib::wrap(platform_data, true)
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
  if(base && base->change_action_state_full)
    (*base->change_action_state_full)(self, action_name, value, platform_data);
}


auto RemoteActionGroup_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new RemoteActionGroup((GRemoteActionGroup*)object);
}


/* The implementation: */

RemoteActionGroup::RemoteActionGroup()
: Interface(remoteactiongroup_class_.init())
{}

RemoteActionGroup::RemoteActionGroup(GRemoteActionGroup* castitem)
: Interface((GObject*)castitem)
{}

RemoteActionGroup::RemoteActionGroup(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

RemoteActionGroup::RemoteActionGroup(RemoteActionGroup&& src) noexcept
: Interface(std::move(src))
{}

auto RemoteActionGroup::operator=(RemoteActionGroup&& src) noexcept -> RemoteActionGroup&
{
  Interface::operator=(std::move(src));
  return *this;
}

RemoteActionGroup::~RemoteActionGroup() noexcept = default;

// static
auto RemoteActionGroup::add_interface (
  const GType gtype_implementer) -> void
{
  remoteactiongroup_class_.init().add_interface(gtype_implementer);
}

RemoteActionGroup::CppClassType RemoteActionGroup::remoteactiongroup_class_; // initialize static member

auto RemoteActionGroup::get_type() -> GType
{
  return remoteactiongroup_class_.init().get_type();
}


auto RemoteActionGroup::get_base_type() -> GType
{
  return g_remote_action_group_get_type();
}


auto RemoteActionGroup::activate_action (
  const Glib::ustring &action_name, const Glib::VariantBase &parameter,
  const Glib::VariantBase &platform_data) -> void
{
  g_remote_action_group_activate_action_full(gobj(), action_name.c_str(), const_cast<GVariant*>(parameter.gobj()), const_cast<GVariant*>(platform_data.gobj()));
}

auto RemoteActionGroup::change_action_state (
  const Glib::ustring &action_name, const Glib::VariantBase &value,
  const Glib::VariantBase &platform_data) -> void
{
  g_remote_action_group_change_action_state_full(gobj(), action_name.c_str(), const_cast<GVariant*>(value.gobj()), const_cast<GVariant*>(platform_data.gobj()));
}


auto RemoteActionGroup::activate_action_full_vfunc (
  const Glib::ustring &action_name, const Glib::VariantBase &parameter,
  const Glib::VariantBase &platform_data) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->activate_action_full)
  {
    (*base->activate_action_full)(gobj(),action_name.c_str(),const_cast<GVariant*>(parameter.gobj()),const_cast<GVariant*>(platform_data.gobj()));
  }
}
auto RemoteActionGroup::change_action_state_full_vfunc (
  const Glib::ustring &action_name, const Glib::VariantBase &value,
  const Glib::VariantBase &platform_data) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->change_action_state_full)
  {
    (*base->change_action_state_full)(gobj(),action_name.c_str(),const_cast<GVariant*>(value.gobj()),const_cast<GVariant*>(platform_data.gobj()));
  }
}


} // namespace Gio


