// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/popovermenu.h>
#include <mm/gtk/private/popovermenu_p.h>


/* Copyright (C) 2015 The gtkmm Development Team
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

namespace Gtk
{
// Delegating constructor.
PopoverMenu::PopoverMenu(const Glib::RefPtr<Gio::MenuModel>& model, Flags flags)
:
  PopoverMenu((GtkPopoverMenu*)gtk_popover_menu_new_from_model_full(
    Glib::unwrap(model), static_cast<GtkPopoverMenuFlags>(flags)))
{
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::PopoverMenu::Flags>::value_type() -> GType
{
  return gtk_popover_menu_flags_get_type();
}


namespace Glib
{

auto wrap(GtkPopoverMenu* object, bool take_copy) -> Gtk::PopoverMenu*
{
  return dynamic_cast<Gtk::PopoverMenu *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto PopoverMenu_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PopoverMenu_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_popover_menu_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void PopoverMenu_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PopoverMenu_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new PopoverMenu((GtkPopoverMenu*)(o)));

}


/* The implementation: */

PopoverMenu::PopoverMenu(const Glib::ConstructParams& construct_params)
:
  Gtk::Popover(construct_params)
{
  }

PopoverMenu::PopoverMenu(GtkPopoverMenu* castitem)
:
  Gtk::Popover((GtkPopover*)(castitem))
{
  }


PopoverMenu::PopoverMenu(PopoverMenu&& src) noexcept
: Gtk::Popover(std::move(src))
{}

auto PopoverMenu::operator=(PopoverMenu&& src) noexcept -> PopoverMenu&
{
  Gtk::Popover::operator=(std::move(src));
  return *this;
}

PopoverMenu::~PopoverMenu() noexcept
{
  destroy_();
}

PopoverMenu::CppClassType PopoverMenu::popovermenu_class_; // initialize static member

auto PopoverMenu::get_type() -> GType
{
  return popovermenu_class_.init().get_type();
}


auto PopoverMenu::get_base_type() -> GType
{
  return gtk_popover_menu_get_type();
}


void PopoverMenu::set_menu_model(const Glib::RefPtr<Gio::MenuModel>& model)
{
  gtk_popover_menu_set_menu_model(gobj(), Glib::unwrap(model));
}

auto PopoverMenu::get_menu_model() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_popover_menu_get_menu_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PopoverMenu::get_menu_model() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<PopoverMenu*>(this)->get_menu_model();
}

auto PopoverMenu::add_child(Widget& child, const Glib::ustring& id) -> bool
{
  return gtk_popover_menu_add_child(gobj(), (child).gobj(), id.c_str());
}

auto PopoverMenu::remove_child(Widget& child) -> bool
{
  return gtk_popover_menu_remove_child(gobj(), (child).gobj());
}


auto PopoverMenu::property_visible_submenu() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "visible-submenu");
}

auto PopoverMenu::property_visible_submenu() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "visible-submenu");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PopoverMenu::property_menu_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}

auto PopoverMenu::property_menu_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}


} // namespace Gtk

