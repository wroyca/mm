// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/popovermenubar.h>
#include <mm/gtk/private/popovermenubar_p.h>


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

auto wrap(GtkPopoverMenuBar* object, bool take_copy) -> Gtk::PopoverMenuBar*
{
  return dynamic_cast<Gtk::PopoverMenuBar *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto PopoverMenuBar_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PopoverMenuBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_popover_menu_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void PopoverMenuBar_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PopoverMenuBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new PopoverMenuBar((GtkPopoverMenuBar*)(o)));

}


/* The implementation: */

PopoverMenuBar::PopoverMenuBar(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

PopoverMenuBar::PopoverMenuBar(GtkPopoverMenuBar* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


PopoverMenuBar::PopoverMenuBar(PopoverMenuBar&& src) noexcept
: Gtk::Widget(std::move(src))
{}

auto PopoverMenuBar::operator=(PopoverMenuBar&& src) noexcept -> PopoverMenuBar&
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

PopoverMenuBar::~PopoverMenuBar() noexcept
{
  destroy_();
}

PopoverMenuBar::CppClassType PopoverMenuBar::popovermenubar_class_; // initialize static member

auto PopoverMenuBar::get_type() -> GType
{
  return popovermenubar_class_.init().get_type();
}


auto PopoverMenuBar::get_base_type() -> GType
{
  return gtk_popover_menu_bar_get_type();
}


PopoverMenuBar::PopoverMenuBar(const Glib::RefPtr<Gio::MenuModel>& menu_model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(popovermenubar_class_.init(), "menu_model", Glib::unwrap(menu_model), nullptr))
{


}

void PopoverMenuBar::set_menu_model(const Glib::RefPtr<Gio::MenuModel>& model)
{
  gtk_popover_menu_bar_set_menu_model(gobj(), Glib::unwrap(model));
}

auto PopoverMenuBar::get_menu_model() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_popover_menu_bar_get_menu_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PopoverMenuBar::get_menu_model() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<PopoverMenuBar*>(this)->get_menu_model();
}

auto PopoverMenuBar::add_child(Widget& child, const Glib::ustring& id) -> bool
{
  return gtk_popover_menu_bar_add_child(gobj(), (child).gobj(), id.c_str());
}

auto PopoverMenuBar::remove_child(Widget& child) -> bool
{
  return gtk_popover_menu_bar_remove_child(gobj(), (child).gobj());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PopoverMenuBar::property_menu_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}

auto PopoverMenuBar::property_menu_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >(this, "menu-model");
}


} // namespace Gtk

