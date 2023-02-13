


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treelistrow.hxx>
#include <libmm-gtk/treelistrow_p.hxx>


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

auto wrap(GtkTreeListRow* object, const bool take_copy) -> RefPtr<Gtk::TreeListRow>
{
  return Glib::make_refptr_for_instance<Gtk::TreeListRow>( dynamic_cast<Gtk::TreeListRow*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TreeListRow_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeListRow_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_tree_list_row_get_type();

  }

  return *this;
}


auto TreeListRow_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeListRow_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeListRow((GtkTreeListRow*)object);
}


/* The implementation: */

auto TreeListRow::gobj_copy() -> GtkTreeListRow*
{
  reference();
  return gobj();
}

TreeListRow::TreeListRow(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TreeListRow::TreeListRow(GtkTreeListRow* castitem)
: Object((GObject*)castitem)
{}


TreeListRow::TreeListRow(TreeListRow&& src) noexcept
: Object(std::move(src))
{}

auto TreeListRow::operator=(TreeListRow&& src) noexcept -> TreeListRow&
{
  Object::operator=(std::move(src));
  return *this;
}


TreeListRow::~TreeListRow() noexcept = default;

TreeListRow::CppClassType TreeListRow::treelistrow_class_; // initialize static member

auto TreeListRow::get_type() -> GType
{
  return treelistrow_class_.init().get_type();
}


auto TreeListRow::get_base_type() -> GType
{
  return gtk_tree_list_row_get_type();
}


auto TreeListRow::get_item() -> Glib::RefPtr<ObjectBase>
{
  return Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_tree_list_row_get_item(gobj()))));
}

auto TreeListRow::get_item() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<TreeListRow*>(this)->get_item();
}

auto TreeListRow::set_expanded (
  const bool expanded) -> void
{
  gtk_tree_list_row_set_expanded(gobj(), expanded);
}

auto TreeListRow::get_expanded() const -> bool
{
  return gtk_tree_list_row_get_expanded(const_cast<GtkTreeListRow*>(gobj()));
}

auto TreeListRow::is_expandable() const -> bool
{
  return gtk_tree_list_row_is_expandable(const_cast<GtkTreeListRow*>(gobj()));
}

auto TreeListRow::get_position() const -> guint
{
  return gtk_tree_list_row_get_position(const_cast<GtkTreeListRow*>(gobj()));
}

auto TreeListRow::get_depth() const -> guint
{
  return gtk_tree_list_row_get_depth(const_cast<GtkTreeListRow*>(gobj()));
}

auto TreeListRow::get_children() -> Glib::RefPtr<Gio::ListModel>
{
  auto retvalue = Glib::wrap(gtk_tree_list_row_get_children(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeListRow::get_children() const -> Glib::RefPtr<const Gio::ListModel>
{
  return const_cast<TreeListRow*>(this)->get_children();
}

auto TreeListRow::get_parent() -> Glib::RefPtr<TreeListRow>
{
  return Glib::wrap(gtk_tree_list_row_get_parent(gobj()));
}

auto TreeListRow::get_parent() const -> Glib::RefPtr<const TreeListRow>
{
  return const_cast<TreeListRow*>(this)->get_parent();
}

auto TreeListRow::get_child_row(
  const guint position) -> Glib::RefPtr<TreeListRow>
{
  return Glib::wrap(gtk_tree_list_row_get_child_row(gobj(), position));
}

auto TreeListRow::get_child_row(
  const guint position) const -> Glib::RefPtr<const TreeListRow>
{
  return const_cast<TreeListRow*>(this)->get_child_row(position);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeListRow::property_children() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >
{
  return {this, "children"};
}

auto TreeListRow::property_depth() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "depth"};
}

auto TreeListRow::property_expandable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "expandable"};
}

auto TreeListRow::property_expanded() -> Glib::PropertyProxy< bool >
{
  return {this, "expanded"};
}

auto TreeListRow::property_expanded() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "expanded"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeListRow::property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ObjectBase> >
{
  return {this, "item"};
}


} // namespace Gtk


