


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/listitem.hpp>
#include <libmm-gtk/listitem_p.hpp>


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

namespace Gtk
{

auto ListItem::unset_child () -> void
{
  gtk_list_item_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkListItem* object, const bool take_copy) -> RefPtr<Gtk::ListItem>
{
  return Glib::make_refptr_for_instance<Gtk::ListItem>( dynamic_cast<Gtk::ListItem*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ListItem_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListItem_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_item_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ListItem_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListItem_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ListItem((GtkListItem*)object);
}


/* The implementation: */

auto ListItem::gobj_copy() -> GtkListItem*
{
  reference();
  return gobj();
}

ListItem::ListItem(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ListItem::ListItem(GtkListItem* castitem)
: Object((GObject*)castitem)
{}


ListItem::ListItem(ListItem&& src) noexcept
: Object(std::move(src))
{}

auto ListItem::operator=(ListItem&& src) noexcept -> ListItem&
{
  Object::operator=(std::move(src));
  return *this;
}


ListItem::~ListItem() noexcept = default;

ListItem::CppClassType ListItem::listitem_class_; // initialize static member

auto ListItem::get_type() -> GType
{
  return listitem_class_.init().get_type();
}


auto ListItem::get_base_type() -> GType
{
  return gtk_list_item_get_type();
}


auto ListItem::get_item() -> Glib::RefPtr<ObjectBase>
{
  auto retvalue = Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_list_item_get_item(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ListItem::get_item() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<ListItem*>(this)->get_item();
}

auto ListItem::get_position() const -> guint
{
  return gtk_list_item_get_position(const_cast<GtkListItem*>(gobj()));
}

auto ListItem::get_selected() const -> bool
{
  return gtk_list_item_get_selected(const_cast<GtkListItem*>(gobj()));
}

auto ListItem::get_selectable() const -> bool
{
  return gtk_list_item_get_selectable(const_cast<GtkListItem*>(gobj()));
}

auto ListItem::set_selectable (
  const bool selectable) -> void
{
  gtk_list_item_set_selectable(gobj(), selectable);
}

auto ListItem::get_activatable() const -> bool
{
  return gtk_list_item_get_activatable(const_cast<GtkListItem*>(gobj()));
}

auto ListItem::set_activatable (
  const bool activatable) -> void
{
  gtk_list_item_set_activatable(gobj(), activatable);
}

auto ListItem::set_child (Widget &child) -> void
{
  gtk_list_item_set_child(gobj(), child.gobj());
}

auto ListItem::get_child() -> Widget*
{
  return Glib::wrap(gtk_list_item_get_child(gobj()));
}

auto ListItem::get_child() const -> const Widget*
{
  return const_cast<ListItem*>(this)->get_child();
}


auto ListItem::property_activatable() -> Glib::PropertyProxy< bool >
{
  return {this, "activatable"};
}

auto ListItem::property_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activatable"};
}

auto ListItem::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto ListItem::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ListItem::property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ObjectBase> >
{
  return {this, "item"};
}

auto ListItem::property_position() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "position"};
}

auto ListItem::property_selectable() -> Glib::PropertyProxy< bool >
{
  return {this, "selectable"};
}

auto ListItem::property_selectable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "selectable"};
}

auto ListItem::property_selected() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "selected"};
}


} // namespace Gtk


