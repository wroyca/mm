// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/dropdown.h>
#include <gtkmm/private/dropdown_p.h>


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
#include <gtkmm/stringlist.h>

namespace Gtk
{

DropDown::DropDown(const std::vector<Glib::ustring>& strings)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(dropdown_class_.init(), "model",StringList::create(strings)->gobj(), nullptr))
{}

}

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::DropDown* wrap(GtkDropDown* object, bool take_copy)
{
  return dynamic_cast<Gtk::DropDown *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& DropDown_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DropDown_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_drop_down_get_type();

  }

  return *this;
}


void DropDown_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* DropDown_Class::wrap_new(GObject* o)
{
  return manage(new DropDown((GtkDropDown*)(o)));

}


/* The implementation: */

DropDown::DropDown(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

DropDown::DropDown(GtkDropDown* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


DropDown::DropDown(DropDown&& src) noexcept
: Gtk::Widget(std::move(src))
{}

DropDown& DropDown::operator=(DropDown&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

DropDown::~DropDown() noexcept
{
  destroy_();
}

DropDown::CppClassType DropDown::dropdown_class_; // initialize static member

GType DropDown::get_type()
{
  return dropdown_class_.init().get_type();
}


GType DropDown::get_base_type()
{
  return gtk_drop_down_get_type();
}


DropDown::DropDown(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Expression<Glib::ustring>>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(dropdown_class_.init(), "model", Glib::unwrap(model), "expression", ((expression) ? (expression)->gobj() : nullptr), nullptr))
{
  

}

void DropDown::set_model(const Glib::RefPtr<Gio::ListModel>& model)
{
  gtk_drop_down_set_model(gobj(), Glib::unwrap(model));
}

Glib::RefPtr<Gio::ListModel> DropDown::get_model()
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Gio::ListModel> DropDown::get_model() const
{
  return const_cast<DropDown*>(this)->get_model();
}

void DropDown::set_selected(guint position)
{
  gtk_drop_down_set_selected(gobj(), position);
}

guint DropDown::get_selected() const
{
  return gtk_drop_down_get_selected(const_cast<GtkDropDown*>(gobj()));
}

Glib::RefPtr<Glib::ObjectBase> DropDown::get_selected_item()
{
  auto retvalue = Glib::make_refptr_for_instance<Glib::ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_drop_down_get_selected_item(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Glib::ObjectBase> DropDown::get_selected_item() const
{
  return const_cast<DropDown*>(this)->get_selected_item();
}

void DropDown::set_factory(const Glib::RefPtr<ListItemFactory>& factory)
{
  gtk_drop_down_set_factory(gobj(), Glib::unwrap(factory));
}

Glib::RefPtr<ListItemFactory> DropDown::get_factory()
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ListItemFactory> DropDown::get_factory() const
{
  return const_cast<DropDown*>(this)->get_factory();
}

void DropDown::set_list_factory(const Glib::RefPtr<ListItemFactory>& factory)
{
  gtk_drop_down_set_list_factory(gobj(), Glib::unwrap(factory));
}

Glib::RefPtr<ListItemFactory> DropDown::get_list_factory()
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_list_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ListItemFactory> DropDown::get_list_factory() const
{
  return const_cast<DropDown*>(this)->get_list_factory();
}

void DropDown::set_expression(const Glib::RefPtr<Expression<Glib::ustring>>& expression)
{
  gtk_drop_down_set_expression(gobj(), ((expression) ? (expression)->gobj() : nullptr));
}

Glib::RefPtr<Expression<Glib::ustring>> DropDown::get_expression()
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_drop_down_get_expression(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Expression<Glib::ustring>> DropDown::get_expression() const
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_drop_down_get_expression(const_cast<GtkDropDown*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

void DropDown::set_enable_search(bool enable_search)
{
  gtk_drop_down_set_enable_search(gobj(), static_cast<int>(enable_search));
}

bool DropDown::get_enable_search() const
{
  return gtk_drop_down_get_enable_search(const_cast<GtkDropDown*>(gobj()));
}

void DropDown::set_show_arrow(bool show_arrow)
{
  gtk_drop_down_set_show_arrow(gobj(), static_cast<int>(show_arrow));
}

bool DropDown::set_show_arrow() const
{
  return gtk_drop_down_get_show_arrow(const_cast<GtkDropDown*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > DropDown::property_factory() 
{
  return Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >(this, "factory");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> > DropDown::property_factory() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >(this, "factory");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> > DropDown::property_list_factory() 
{
  return Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >(this, "list-factory");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> > DropDown::property_list_factory() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >(this, "list-factory");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> > DropDown::property_model() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> >(this, "model");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> > DropDown::property_model() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >(this, "model");
}

Glib::PropertyProxy< guint > DropDown::property_selected() 
{
  return Glib::PropertyProxy< guint >(this, "selected");
}

Glib::PropertyProxy_ReadOnly< guint > DropDown::property_selected() const
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "selected");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> > DropDown::property_selected_item() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Glib::ObjectBase> >(this, "selected-item");
}

Glib::PropertyProxy< bool > DropDown::property_enable_search() 
{
  return Glib::PropertyProxy< bool >(this, "enable-search");
}

Glib::PropertyProxy_ReadOnly< bool > DropDown::property_enable_search() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "enable-search");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Expression<Glib::ustring>>>::value,
  "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> > DropDown::property_expression() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> >(this, "expression");
}

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> > DropDown::property_expression() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >(this, "expression");
}

Glib::PropertyProxy< bool > DropDown::property_show_arrow() 
{
  return Glib::PropertyProxy< bool >(this, "show-arrow");
}

Glib::PropertyProxy_ReadOnly< bool > DropDown::property_show_arrow() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "show-arrow");
}


} // namespace Gtk


