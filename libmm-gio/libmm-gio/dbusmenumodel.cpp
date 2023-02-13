


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/dbusmenumodel.hpp>
#include <libmm-gio/dbusmenumodel_p.hpp>


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
#include <libmm-gio/dbusconnection.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDBusMenuModel* object, const bool take_copy) -> RefPtr<Gio::DBus::MenuModel>
{
  return Glib::make_refptr_for_instance<Gio::DBus::MenuModel>( dynamic_cast<Gio::DBus::MenuModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto MenuModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MenuModel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_menu_model_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MenuModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MenuModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MenuModel((GDBusMenuModel*)object);
}


/* The implementation: */

auto MenuModel::gobj_copy() -> GDBusMenuModel*
{
  reference();
  return gobj();
}

MenuModel::MenuModel(const Glib::ConstructParams& construct_params)
: Gio::MenuModel(construct_params)
{

}

MenuModel::MenuModel(GDBusMenuModel* castitem)
: Gio::MenuModel((GMenuModel*)castitem)
{}


MenuModel::MenuModel(MenuModel&& src) noexcept
: Gio::MenuModel(std::move(src))
{}

auto MenuModel::operator=(MenuModel&& src) noexcept -> MenuModel&
{
  Gio::MenuModel::operator=(std::move(src));
  return *this;
}


MenuModel::~MenuModel() noexcept = default;

MenuModel::CppClassType MenuModel::menumodel_class_; // initialize static member

auto MenuModel::get_type() -> GType
{
  return menumodel_class_.init().get_type();
}


auto MenuModel::get_base_type() -> GType
{
  return g_dbus_menu_model_get_type();
}


MenuModel::MenuModel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Gio::MenuModel(Glib::ConstructParams(menumodel_class_.init()))
{


}

auto MenuModel::get(const Glib::RefPtr<Connection>& connection, const Glib::ustring& bus_name, const Glib::ustring& object_path) -> Glib::RefPtr<MenuModel>
{
  return Glib::wrap(g_dbus_menu_model_get(Glib::unwrap(connection), bus_name.c_str(), object_path.c_str()));
}


} // namespace Gio


