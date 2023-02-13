


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/snapshot.hpp>
#include <mm/gdk/private/snapshot_p.hpp>


/* Copyright (C) 2018 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gdk/gdk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkSnapshot* object, const bool take_copy) -> RefPtr<Gdk::Snapshot>
{
  return Glib::make_refptr_for_instance<Gdk::Snapshot>( dynamic_cast<Gdk::Snapshot*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Snapshot_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Snapshot_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_snapshot_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Snapshot_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Snapshot_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Snapshot((GdkSnapshot*)object);
}


/* The implementation: */

auto Snapshot::gobj_copy() -> GdkSnapshot*
{
  reference();
  return gobj();
}

Snapshot::Snapshot(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Snapshot::Snapshot(GdkSnapshot* castitem)
: Object((GObject*)castitem)
{}


Snapshot::Snapshot(Snapshot&& src) noexcept
: Object(std::move(src))
{}

auto Snapshot::operator=(Snapshot&& src) noexcept -> Snapshot&
{
  Object::operator=(std::move(src));
  return *this;
}


Snapshot::~Snapshot() noexcept = default;

Snapshot::CppClassType Snapshot::snapshot_class_; // initialize static member

auto Snapshot::get_type() -> GType
{
  return snapshot_class_.init().get_type();
}


auto Snapshot::get_base_type() -> GType
{
  return gdk_snapshot_get_type();
}


} // namespace Gdk


