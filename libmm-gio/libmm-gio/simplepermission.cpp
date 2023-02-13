


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/simplepermission.hpp>
#include <mm/gio/private/simplepermission_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSimplePermission* object, const bool take_copy) -> RefPtr<Gio::SimplePermission>
{
  return Glib::make_refptr_for_instance<Gio::SimplePermission>( dynamic_cast<Gio::SimplePermission*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SimplePermission_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SimplePermission_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_simple_permission_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SimplePermission_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SimplePermission_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SimplePermission((GSimplePermission*)object);
}


/* The implementation: */

auto SimplePermission::gobj_copy() -> GSimplePermission*
{
  reference();
  return gobj();
}

SimplePermission::SimplePermission(const Glib::ConstructParams& construct_params)
: Permission(construct_params)
{

}

SimplePermission::SimplePermission(GSimplePermission* castitem)
: Permission((GPermission*)castitem)
{}


SimplePermission::SimplePermission(SimplePermission&& src) noexcept
: Permission(std::move(src))
{}

auto SimplePermission::operator=(SimplePermission&& src) noexcept -> SimplePermission&
{
  Permission::operator=(std::move(src));
  return *this;
}


SimplePermission::~SimplePermission() noexcept = default;

SimplePermission::CppClassType SimplePermission::simplepermission_class_; // initialize static member

auto SimplePermission::get_type() -> GType
{
  return simplepermission_class_.init().get_type();
}


auto SimplePermission::get_base_type() -> GType
{
  return g_simple_permission_get_type();
}


SimplePermission::SimplePermission(const bool allowed)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Permission(Glib::ConstructParams(simplepermission_class_.init(), "allowed", allowed, nullptr))
{


}

auto SimplePermission::create(
  const bool allowed) -> Glib::RefPtr<SimplePermission>
{
  return Glib::make_refptr_for_instance<SimplePermission>( new SimplePermission(allowed) );
}


} // namespace Gio


