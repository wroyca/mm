


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/columnviewcolumn.hxx>
#include <libmm-gtk/columnviewcolumn_p.hxx>


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
#include <libmm-gtk/columnview.hxx>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkColumnViewColumn* object, const bool take_copy) -> RefPtr<Gtk::ColumnViewColumn>
{
  return Glib::make_refptr_for_instance<Gtk::ColumnViewColumn>( dynamic_cast<Gtk::ColumnViewColumn*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto ColumnViewColumn_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ColumnViewColumn_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_column_view_column_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ColumnViewColumn_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ColumnViewColumn_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ColumnViewColumn((GtkColumnViewColumn*)object);
}


/* The implementation: */

auto ColumnViewColumn::gobj_copy() -> GtkColumnViewColumn*
{
  reference();
  return gobj();
}

ColumnViewColumn::ColumnViewColumn(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ColumnViewColumn::ColumnViewColumn(GtkColumnViewColumn* castitem)
: Object((GObject*)castitem)
{}


ColumnViewColumn::ColumnViewColumn(ColumnViewColumn&& src) noexcept
: Object(std::move(src))
{}

auto ColumnViewColumn::operator=(ColumnViewColumn&& src) noexcept -> ColumnViewColumn&
{
  Object::operator=(std::move(src));
  return *this;
}


ColumnViewColumn::~ColumnViewColumn() noexcept = default;

ColumnViewColumn::CppClassType ColumnViewColumn::columnviewcolumn_class_; // initialize static member

auto ColumnViewColumn::get_type() -> GType
{
  return columnviewcolumn_class_.init().get_type();
}


auto ColumnViewColumn::get_base_type() -> GType
{
  return gtk_column_view_column_get_type();
}


ColumnViewColumn::ColumnViewColumn(const Glib::ustring& title, const Glib::RefPtr<ListItemFactory>& factory)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(columnviewcolumn_class_.init(), "title", title.c_str(), "factory", Glib::unwrap(factory), nullptr))
{


}

auto ColumnViewColumn::create(const Glib::ustring& title, const Glib::RefPtr<ListItemFactory>& factory) -> Glib::RefPtr<ColumnViewColumn>
{
  return Glib::make_refptr_for_instance<ColumnViewColumn>( new ColumnViewColumn(title, factory) );
}

auto ColumnViewColumn::get_column_view() -> ColumnView*
{
  return Glib::wrap(gtk_column_view_column_get_column_view(gobj()));
}

auto ColumnViewColumn::get_column_view() const -> const ColumnView*
{
  return const_cast<ColumnViewColumn*>(this)->get_column_view();
}

auto ColumnViewColumn::set_factory (const Glib::RefPtr <ListItemFactory> &factory) -> void
{
  gtk_column_view_column_set_factory(gobj(), Glib::unwrap(factory));
}

auto ColumnViewColumn::get_factory() -> Glib::RefPtr<ListItemFactory>
{
  auto retvalue = Glib::wrap(gtk_column_view_column_get_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnViewColumn::get_factory() const -> Glib::RefPtr<const ListItemFactory>
{
  return const_cast<ColumnViewColumn*>(this)->get_factory();
}

auto ColumnViewColumn::set_title (const Glib::ustring &title) -> void
{
  gtk_column_view_column_set_title(gobj(), title.c_str());
}

auto ColumnViewColumn::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_column_view_column_get_title(const_cast<GtkColumnViewColumn*>(gobj())));
}

auto ColumnViewColumn::set_sorter (const Glib::RefPtr <Sorter> &sorter) -> void
{
  gtk_column_view_column_set_sorter(gobj(), Glib::unwrap(sorter));
}

auto ColumnViewColumn::get_sorter() -> Glib::RefPtr<Sorter>
{
  auto retvalue = Glib::wrap(gtk_column_view_column_get_sorter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnViewColumn::get_sorter() const -> Glib::RefPtr<const Sorter>
{
  return const_cast<ColumnViewColumn*>(this)->get_sorter();
}

auto ColumnViewColumn::set_visible (
  const bool visible) -> void
{
  gtk_column_view_column_set_visible(gobj(), visible);
}

auto ColumnViewColumn::get_visible() const -> bool
{
  return gtk_column_view_column_get_visible(const_cast<GtkColumnViewColumn*>(gobj()));
}

auto ColumnViewColumn::set_header_menu (const Glib::RefPtr <Gio::MenuModel> &model) -> void
{
  gtk_column_view_column_set_header_menu(gobj(), Glib::unwrap(model));
}

auto ColumnViewColumn::get_header_menu() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_column_view_column_get_header_menu(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnViewColumn::get_header_menu() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<ColumnViewColumn*>(this)->get_header_menu();
}

auto ColumnViewColumn::set_fixed_width (
  const int fixed_width) -> void
{
  gtk_column_view_column_set_fixed_width(gobj(), fixed_width);
}

auto ColumnViewColumn::get_fixed_width() const -> int
{
  return gtk_column_view_column_get_fixed_width(const_cast<GtkColumnViewColumn*>(gobj()));
}

auto ColumnViewColumn::set_resizable (
  const bool resizable) -> void
{
  gtk_column_view_column_set_resizable(gobj(), resizable);
}

auto ColumnViewColumn::get_resizable() const -> bool
{
  return gtk_column_view_column_get_resizable(const_cast<GtkColumnViewColumn*>(gobj()));
}

auto ColumnViewColumn::set_expand (
  const bool expand) -> void
{
  gtk_column_view_column_set_expand(gobj(), expand);
}

auto ColumnViewColumn::get_expand() const -> bool
{
  return gtk_column_view_column_get_expand(const_cast<GtkColumnViewColumn*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ColumnView*>::value,
  "Type ColumnView* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnViewColumn::property_column_view() const -> Glib::PropertyProxy_ReadOnly< ColumnView* >
{
  return {this, "column-view"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnViewColumn::property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

auto ColumnViewColumn::property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

auto ColumnViewColumn::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto ColumnViewColumn::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Sorter>>::value,
  "Type Glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnViewColumn::property_sorter() -> Glib::PropertyProxy< Glib::RefPtr<Sorter> >
{
  return {this, "sorter"};
}

auto ColumnViewColumn::property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >
{
  return {this, "sorter"};
}

auto ColumnViewColumn::property_visible() -> Glib::PropertyProxy< bool >
{
  return {this, "visible"};
}

auto ColumnViewColumn::property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "visible"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnViewColumn::property_header_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "header-menu"};
}

auto ColumnViewColumn::property_header_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "header-menu"};
}

auto ColumnViewColumn::property_resizable() -> Glib::PropertyProxy< bool >
{
  return {this, "resizable"};
}

auto ColumnViewColumn::property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "resizable"};
}

auto ColumnViewColumn::property_expand() -> Glib::PropertyProxy< bool >
{
  return {this, "expand"};
}

auto ColumnViewColumn::property_expand() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "expand"};
}

auto ColumnViewColumn::property_fixed_width() -> Glib::PropertyProxy< int >
{
  return {this, "fixed-width"};
}

auto ColumnViewColumn::property_fixed_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "fixed-width"};
}


} // namespace Gtk

