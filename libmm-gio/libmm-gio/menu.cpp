


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/menu.hpp>
#include <mm/gio/private/menu_p.hpp>


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

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GMenu* object, const bool take_copy) -> RefPtr<Gio::Menu>
{
  return Glib::make_refptr_for_instance<Gio::Menu>( dynamic_cast<Gio::Menu*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Menu_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Menu_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_menu_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Menu_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Menu_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Menu((GMenu*)object);
}


/* The implementation: */

auto Menu::gobj_copy() -> GMenu*
{
  reference();
  return gobj();
}

Menu::Menu(const Glib::ConstructParams& construct_params)
: MenuModel(construct_params)
{

}

Menu::Menu(GMenu* castitem)
: MenuModel((GMenuModel*)castitem)
{}


Menu::Menu(Menu&& src) noexcept
: MenuModel(std::move(src))
{}

auto Menu::operator=(Menu&& src) noexcept -> Menu&
{
  MenuModel::operator=(std::move(src));
  return *this;
}


Menu::~Menu() noexcept = default;

Menu::CppClassType Menu::menu_class_; // initialize static member

auto Menu::get_type() -> GType
{
  return menu_class_.init().get_type();
}


auto Menu::get_base_type() -> GType
{
  return g_menu_get_type();
}


Menu::Menu()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
MenuModel(Glib::ConstructParams(menu_class_.init()))
{


}

auto Menu::create() -> Glib::RefPtr<Menu>
{
  return Glib::make_refptr_for_instance<Menu>( new Menu() );
}

auto Menu::freeze () -> void
{
  g_menu_freeze(gobj());
}

auto Menu::insert_item (
  const int position, const Glib::RefPtr <const MenuItem> &item) -> void
{
  g_menu_insert_item(gobj(), position, const_cast<GMenuItem*>(Glib::unwrap(item)));
}

auto Menu::prepend_item (const Glib::RefPtr <const MenuItem> &item) -> void
{
  g_menu_prepend_item(gobj(), const_cast<GMenuItem*>(Glib::unwrap(item)));
}

auto Menu::append_item (const Glib::RefPtr <const MenuItem> &item) -> void
{
  g_menu_append_item(gobj(), const_cast<GMenuItem*>(Glib::unwrap(item)));
}

auto Menu::remove (
  const int position) -> void
{
  g_menu_remove(gobj(), position);
}

auto Menu::remove_all () -> void
{
  g_menu_remove_all(gobj());
}

auto Menu::insert (
  const int position, const Glib::ustring &label, const Glib::ustring &detailed_action) -> void
{
  g_menu_insert(gobj(), position, label.c_str(), detailed_action.empty() ? nullptr : detailed_action.c_str());
}

auto Menu::insert (
  const int position, const Glib::ustring &label) -> void
{
  g_menu_insert(gobj(), position, label.c_str(), nullptr);
}

auto Menu::prepend (const Glib::ustring &label, const Glib::ustring &detailed_action) -> void
{
  g_menu_prepend(gobj(), label.c_str(), detailed_action.empty() ? nullptr : detailed_action.c_str());
}

auto Menu::prepend (const Glib::ustring &label) -> void
{
  g_menu_prepend(gobj(), label.c_str(), nullptr);
}

auto Menu::append (const Glib::ustring &label, const Glib::ustring &detailed_action) -> void
{
  g_menu_append(gobj(), label.c_str(), detailed_action.empty() ? nullptr : detailed_action.c_str());
}

auto Menu::append (const Glib::ustring &label) -> void
{
  g_menu_append(gobj(), label.c_str(), nullptr);
}

auto Menu::insert_section (
  const int position, const Glib::ustring &label, const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_insert_section(gobj(), position, label.empty() ? nullptr : label.c_str(), Glib::unwrap(section));
}

auto Menu::insert_section (
  const int position, const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_insert_section(gobj(), position, nullptr, Glib::unwrap(section));
}

auto Menu::prepend_section (
  const Glib::ustring &label, const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_prepend_section(gobj(), label.empty() ? nullptr : label.c_str(), Glib::unwrap(section));
}

auto Menu::prepend_section (const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_prepend_section(gobj(), nullptr, Glib::unwrap(section));
}

auto Menu::append_section (
  const Glib::ustring &label, const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_append_section(gobj(), label.empty() ? nullptr : label.c_str(), Glib::unwrap(section));
}

auto Menu::append_section (const Glib::RefPtr <MenuModel> &section) -> void
{
  g_menu_append_section(gobj(), nullptr, Glib::unwrap(section));
}

auto Menu::insert_submenu (
  const int position, const Glib::ustring &label, const Glib::RefPtr <MenuModel> &submenu) -> void
{
  g_menu_insert_submenu(gobj(), position, label.c_str(), Glib::unwrap(submenu));
}

auto Menu::prepend_submenu (
  const Glib::ustring &label, const Glib::RefPtr <MenuModel> &submenu) -> void
{
  g_menu_prepend_submenu(gobj(), label.c_str(), Glib::unwrap(submenu));
}

auto Menu::append_submenu (
  const Glib::ustring &label, const Glib::RefPtr <MenuModel> &submenu) -> void
{
  g_menu_append_submenu(gobj(), label.c_str(), Glib::unwrap(submenu));
}


} // namespace Gio


