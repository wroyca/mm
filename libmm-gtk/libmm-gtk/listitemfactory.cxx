


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/listitemfactory.hpp>
#include <libmm-gtk/listitemfactory_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkListItemFactory* object, const bool take_copy) -> RefPtr<Gtk::ListItemFactory>
{
  return Glib::make_refptr_for_instance<Gtk::ListItemFactory>( dynamic_cast<Gtk::ListItemFactory*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ListItemFactory_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListItemFactory_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_item_factory_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ListItemFactory_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListItemFactory_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ListItemFactory((GtkListItemFactory*)object);
}


/* The implementation: */

auto ListItemFactory::gobj_copy() -> GtkListItemFactory*
{
  reference();
  return gobj();
}

ListItemFactory::ListItemFactory(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ListItemFactory::ListItemFactory(GtkListItemFactory* castitem)
: Object((GObject*)castitem)
{}


ListItemFactory::ListItemFactory(ListItemFactory&& src) noexcept
: Object(std::move(src))
{}

auto ListItemFactory::operator=(ListItemFactory&& src) noexcept -> ListItemFactory&
{
  Object::operator=(std::move(src));
  return *this;
}


ListItemFactory::~ListItemFactory() noexcept = default;

ListItemFactory::CppClassType ListItemFactory::listitemfactory_class_; // initialize static member

auto ListItemFactory::get_type() -> GType
{
  return listitemfactory_class_.init().get_type();
}


auto ListItemFactory::get_base_type() -> GType
{
  return gtk_list_item_factory_get_type();
}


} // namespace Gtk


