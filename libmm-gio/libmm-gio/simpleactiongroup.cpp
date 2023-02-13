


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/simpleactiongroup.hpp>
#include <mm/gio/private/simpleactiongroup_p.hpp>


/* Copyright (C) 2011 The giomm Development Team
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
#include <mm/gio/action.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSimpleActionGroup* object, const bool take_copy) -> RefPtr<Gio::SimpleActionGroup>
{
  return Glib::make_refptr_for_instance<Gio::SimpleActionGroup>( dynamic_cast<Gio::SimpleActionGroup*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SimpleActionGroup_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SimpleActionGroup_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_simple_action_group_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  ActionGroup::add_interface(get_type());
  ActionMap::add_interface(get_type());

  }

  return *this;
}


auto SimpleActionGroup_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SimpleActionGroup_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SimpleActionGroup((GSimpleActionGroup*)object);
}


/* The implementation: */

auto SimpleActionGroup::gobj_copy() -> GSimpleActionGroup*
{
  reference();
  return gobj();
}

SimpleActionGroup::SimpleActionGroup(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SimpleActionGroup::SimpleActionGroup(GSimpleActionGroup* castitem)
: Object((GObject*)castitem)
{}


SimpleActionGroup::SimpleActionGroup(SimpleActionGroup&& src) noexcept
: Object(std::move(src))
  , ActionGroup(std::move(src))
  , ActionMap(std::move(src))
{}

auto SimpleActionGroup::operator=(SimpleActionGroup&& src) noexcept -> SimpleActionGroup&
{
  Object::operator=(std::move(src));
  ActionGroup::operator=(std::move(src));
  ActionMap::operator=(std::move(src));
  return *this;
}


SimpleActionGroup::~SimpleActionGroup() noexcept = default;

SimpleActionGroup::CppClassType SimpleActionGroup::simpleactiongroup_class_; // initialize static member

auto SimpleActionGroup::get_type() -> GType
{
  return simpleactiongroup_class_.init().get_type();
}


auto SimpleActionGroup::get_base_type() -> GType
{
  return g_simple_action_group_get_type();
}


SimpleActionGroup::SimpleActionGroup()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(simpleactiongroup_class_.init()))
{


}

auto SimpleActionGroup::create() -> Glib::RefPtr<SimpleActionGroup>
{
  return Glib::make_refptr_for_instance<SimpleActionGroup>( new SimpleActionGroup() );
}


} // namespace Gio


