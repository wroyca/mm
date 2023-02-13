


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/treeexpander.hpp>
#include <libmm-gtk/treeexpander_p.hpp>


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

auto TreeExpander::unset_child () -> void
{
  gtk_tree_expander_set_child(gobj(), nullptr);
}

auto TreeExpander::unset_list_row () -> void
{
  gtk_tree_expander_set_list_row(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeExpander* object, const bool take_copy) -> Gtk::TreeExpander*
{
  return dynamic_cast<Gtk::TreeExpander *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto TreeExpander_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeExpander_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_tree_expander_get_type();

  }

  return *this;
}


auto TreeExpander_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeExpander_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new TreeExpander((GtkTreeExpander*)o));

}


/* The implementation: */

TreeExpander::TreeExpander(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

TreeExpander::TreeExpander(GtkTreeExpander* castitem)
: Widget((GtkWidget*)castitem)
{
  }


TreeExpander::TreeExpander(TreeExpander&& src) noexcept
: Widget(std::move(src))
{}

auto TreeExpander::operator=(TreeExpander&& src) noexcept -> TreeExpander&
{
  Widget::operator=(std::move(src));
  return *this;
}

TreeExpander::~TreeExpander() noexcept
{
  destroy_();
}

TreeExpander::CppClassType TreeExpander::treeexpander_class_; // initialize static member

auto TreeExpander::get_type() -> GType
{
  return treeexpander_class_.init().get_type();
}


auto TreeExpander::get_base_type() -> GType
{
  return gtk_tree_expander_get_type();
}


TreeExpander::TreeExpander()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(treeexpander_class_.init()))
{


}

auto TreeExpander::get_child() -> Widget*
{
  return Glib::wrap(gtk_tree_expander_get_child(gobj()));
}

auto TreeExpander::get_child() const -> const Widget*
{
  return const_cast<TreeExpander*>(this)->get_child();
}

auto TreeExpander::set_child (Widget &widget) -> void
{
  gtk_tree_expander_set_child(gobj(), widget.gobj());
}

auto TreeExpander::get_item() -> Glib::RefPtr<ObjectBase>
{
  return Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_tree_expander_get_item(gobj()))));
}

auto TreeExpander::get_item() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<TreeExpander*>(this)->get_item();
}

auto TreeExpander::get_list_row() -> Glib::RefPtr<TreeListRow>
{
  auto retvalue = Glib::wrap(gtk_tree_expander_get_list_row(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeExpander::get_list_row() const -> Glib::RefPtr<const TreeListRow>
{
  return const_cast<TreeExpander*>(this)->get_list_row();
}

auto TreeExpander::set_list_row (const Glib::RefPtr <TreeListRow> &list_row) -> void
{
  gtk_tree_expander_set_list_row(gobj(), Glib::unwrap(list_row));
}

auto TreeExpander::get_indent_for_icon() const -> bool
{
  return gtk_tree_expander_get_indent_for_icon(const_cast<GtkTreeExpander*>(gobj()));
}

auto TreeExpander::set_indent_for_icon (
  const bool indent_for_icon) -> void
{
  gtk_tree_expander_set_indent_for_icon(gobj(), indent_for_icon);
}


auto TreeExpander::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto TreeExpander::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeExpander::property_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ObjectBase> >
{
  return {this, "item"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeListRow>>::value,
  "Type Glib::RefPtr<TreeListRow> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeExpander::property_list_row() -> Glib::PropertyProxy< Glib::RefPtr<TreeListRow> >
{
  return {this, "list-row"};
}

auto TreeExpander::property_list_row() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeListRow> >
{
  return {this, "list-row"};
}

auto TreeExpander::property_indent_for_icon() -> Glib::PropertyProxy< bool >
{
  return {this, "indent-for-icon"};
}

auto TreeExpander::property_indent_for_icon() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "indent-for-icon"};
}


} // namespace Gtk


