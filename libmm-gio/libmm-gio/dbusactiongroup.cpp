


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusactiongroup.hpp>
#include <mm/gio/private/dbusactiongroup_p.hpp>


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

#include <gio/gio.h>
#include <mm/gio/dbusconnection.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDBusActionGroup* object, const bool take_copy) -> RefPtr<Gio::DBus::ActionGroup>
{
  return Glib::make_refptr_for_instance<Gio::DBus::ActionGroup>( dynamic_cast<Gio::DBus::ActionGroup*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto ActionGroup_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ActionGroup_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_action_group_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::ActionGroup::add_interface(get_type());
    RemoteActionGroup::add_interface(get_type());

  }

  return *this;
}


auto ActionGroup_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ActionGroup_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ActionGroup((GDBusActionGroup*)object);
}


/* The implementation: */

auto ActionGroup::gobj_copy() -> GDBusActionGroup*
{
  reference();
  return gobj();
}

ActionGroup::ActionGroup(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ActionGroup::ActionGroup(GDBusActionGroup* castitem)
: Object((GObject*)castitem)
{}


ActionGroup::ActionGroup(ActionGroup&& src) noexcept
: Object(std::move(src))
  , Gio::ActionGroup(std::move(src))
  ,
  RemoteActionGroup(std::move(src))
{}

auto ActionGroup::operator=(ActionGroup&& src) noexcept -> ActionGroup&
{
  Object::operator=(std::move(src));
  Gio::ActionGroup::operator=(std::move(src));
  RemoteActionGroup::operator=(std::move(src));
  return *this;
}


ActionGroup::~ActionGroup() noexcept = default;

ActionGroup::CppClassType ActionGroup::actiongroup_class_; // initialize static member

auto ActionGroup::get_type() -> GType
{
  return actiongroup_class_.init().get_type();
}


auto ActionGroup::get_base_type() -> GType
{
  return g_dbus_action_group_get_type();
}


ActionGroup::ActionGroup()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(actiongroup_class_.init()))
{


}

auto ActionGroup::get(const Glib::RefPtr<Connection>& connection, const Glib::ustring& bus_name, const Glib::ustring& object_path) -> Glib::RefPtr<ActionGroup>
{
  return Glib::wrap(g_dbus_action_group_get(Glib::unwrap(connection), bus_name.c_str(), object_path.c_str()));
}


} // namespace Gio


