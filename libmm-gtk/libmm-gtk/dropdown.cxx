


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/dropdown.hpp>
#include <libmm-gtk/dropdown_p.hpp>


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
#include <libmm-gtk/stringlist.hpp>

namespace Gtk
{

DropDown::DropDown(const std::vector<Glib::ustring>& strings)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(dropdown_class_.init(), "model",StringList::create(strings)->gobj(), nullptr))
{}

}

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkDropDown* object, const bool take_copy) -> Gtk::DropDown*
{
  return dynamic_cast<Gtk::DropDown *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto DropDown_Class::init() -> const Class&
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


auto DropDown_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DropDown_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new DropDown((GtkDropDown*)o));

}


/* The implementation: */

DropDown::DropDown(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

DropDown::DropDown(GtkDropDown* castitem)
: Widget((GtkWidget*)castitem)
{
  }


DropDown::DropDown(DropDown&& src) noexcept
: Widget(std::move(src))
{}

auto DropDown::operator=(DropDown&& src) noexcept -> DropDown&
{
  Widget::operator=(std::move(src));
  return *this;
}

DropDown::~DropDown() noexcept
{
  destroy_();
}

DropDown::CppClassType DropDown::dropdown_class_; // initialize static member

auto DropDown::get_type() -> GType
{
  return dropdown_class_.init().get_type();
}


auto DropDown::get_base_type() -> GType
{
  return gtk_drop_down_get_type();
}


DropDown::DropDown(const Glib::RefPtr<Gio::ListModel>& model, const Glib::RefPtr<Expression<Glib::ustring>>& expression)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(dropdown_class_.init(), "model", Glib::unwrap(model), "expression", expression ? expression->gobj() : nullptr, nullptr))
{


}

auto DropDown::set_model (const Glib::RefPtr <Gio::ListModel> &model) -> void
{
  gtk_drop_down_set_model(gobj(), Glib::unwrap(model));
}

auto DropDown::get_model() -> Glib::RefPtr<Gio::ListModel>
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::get_model() const -> Glib::RefPtr<const Gio::ListModel>
{
  return const_cast<DropDown*>(this)->get_model();
}

auto DropDown::set_selected (
  const guint position) -> void
{
  gtk_drop_down_set_selected(gobj(), position);
}

auto DropDown::get_selected() const -> guint
{
  return gtk_drop_down_get_selected(const_cast<GtkDropDown*>(gobj()));
}

auto DropDown::get_selected_item() -> Glib::RefPtr<ObjectBase>
{
  auto retvalue = Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_drop_down_get_selected_item(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::get_selected_item() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<DropDown*>(this)->get_selected_item();
}

auto DropDown::set_factory (const Glib::RefPtr <ListItemFactory> &factory) -> void
{
  gtk_drop_down_set_factory(gobj(), Glib::unwrap(factory));
}

auto DropDown::get_factory() -> Glib::RefPtr<ListItemFactory>
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::get_factory() const -> Glib::RefPtr<const ListItemFactory>
{
  return const_cast<DropDown*>(this)->get_factory();
}

auto DropDown::set_list_factory (const Glib::RefPtr <ListItemFactory> &factory) -> void
{
  gtk_drop_down_set_list_factory(gobj(), Glib::unwrap(factory));
}

auto DropDown::get_list_factory() -> Glib::RefPtr<ListItemFactory>
{
  auto retvalue = Glib::wrap(gtk_drop_down_get_list_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::get_list_factory() const -> Glib::RefPtr<const ListItemFactory>
{
  return const_cast<DropDown*>(this)->get_list_factory();
}

auto DropDown::set_expression (const Glib::RefPtr <Expression <Glib::ustring>> &expression) -> void
{
  gtk_drop_down_set_expression(gobj(), expression ? expression->gobj() : nullptr);
}

auto DropDown::get_expression() -> Glib::RefPtr<Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_drop_down_get_expression(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::get_expression() const -> Glib::RefPtr<const Expression<Glib::ustring>>
{
  auto retvalue = Glib::wrap<Glib::ustring>(gtk_drop_down_get_expression(const_cast<GtkDropDown*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropDown::set_enable_search (
  const bool enable_search) -> void
{
  gtk_drop_down_set_enable_search(gobj(), enable_search);
}

auto DropDown::get_enable_search() const -> bool
{
  return gtk_drop_down_get_enable_search(const_cast<GtkDropDown*>(gobj()));
}

auto DropDown::set_show_arrow (
  const bool show_arrow) -> void
{
  gtk_drop_down_set_show_arrow(gobj(), show_arrow);
}

auto DropDown::set_show_arrow() const -> bool
{
  return gtk_drop_down_get_show_arrow(const_cast<GtkDropDown*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropDown::property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

auto DropDown::property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropDown::property_list_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >
{
  return {this, "list-factory"};
}

auto DropDown::property_list_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >
{
  return {this, "list-factory"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropDown::property_model() -> Glib::PropertyProxy< Glib::RefPtr<Gio::ListModel> >
{
  return {this, "model"};
}

auto DropDown::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >
{
  return {this, "model"};
}

auto DropDown::property_selected() -> Glib::PropertyProxy< guint >
{
  return {this, "selected"};
}

auto DropDown::property_selected() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "selected"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropDown::property_selected_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ObjectBase> >
{
  return {this, "selected-item"};
}

auto DropDown::property_enable_search() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-search"};
}

auto DropDown::property_enable_search() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-search"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Expression<Glib::ustring>>>::value,
  "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropDown::property_expression() -> Glib::PropertyProxy< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto DropDown::property_expression() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Expression<Glib::ustring>> >
{
  return {this, "expression"};
}

auto DropDown::property_show_arrow() -> Glib::PropertyProxy< bool >
{
  return {this, "show-arrow"};
}

auto DropDown::property_show_arrow() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-arrow"};
}


} // namespace Gtk


