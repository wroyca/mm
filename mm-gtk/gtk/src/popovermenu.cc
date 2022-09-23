// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/popovermenu.h>
#include <gtkmm/private/popovermenu_p.h>


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
GType Glib::Value<Gtk::PopoverMenu::Flags>::value_type()
{
  return gtk_popover_menu_flags_get_type();
}


namespace Glib
{

Gtk::PopoverMenu* wrap(GtkPopoverMenu* object, bool take_copy)
{
  return dynamic_cast<Gtk::PopoverMenu *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& PopoverMenu_Class::init()
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


Glib::ObjectBase* PopoverMenu_Class::wrap_new(GObject* o)
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

PopoverMenu& PopoverMenu::operator=(PopoverMenu&& src) noexcept
{
  Gtk::Popover::operator=(std::move(src));
  return *this;
}

PopoverMenu::~PopoverMenu() noexcept
{
  destroy_();
}

PopoverMenu::CppClassType PopoverMenu::popovermenu_class_; // initialize static member

GType PopoverMenu::get_type()
{
  return popovermenu_class_.init().get_type();
}


GType PopoverMenu::get_base_type()
{
  return gtk_popover_menu_get_type();
}


void PopoverMenu::set_menu_model(const Glib::RefPtr<Gio::MenuModel>& model)
{
  gtk_popover_menu_set_menu_model(gobj(), Glib::unwrap(model));
}

Glib::RefPtr<Gio::MenuModel> PopoverMenu::get_menu_model()
{
  auto retvalue = Glib::wrap(gtk_popover_menu_get_menu_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gio::MenuModel> PopoverMenu::get_menu_model() const
{
  return const_cast<PopoverMenu*>(this)->get_menu_model();
}

bool PopoverMenu::add_child(Widget& child, const Glib::ustring& id)
{
  return gtk_popover_menu_add_child(gobj(), (child).gobj(), id.c_str());
}

bool PopoverMenu::remove_child(Widget& child)
{
  return gtk_popover_menu_remove_child(gobj(), (child).gobj());
}


Glib::PropertyProxy< Glib::ustring > PopoverMenu::property_visible_submenu() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "visible-submenu");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > PopoverMenu::property_visible_submenu() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "visible-submenu");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > PopoverMenu::property_menu_model() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> > PopoverMenu::property_menu_model() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}


} // namespace Gtk


