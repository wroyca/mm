// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/treeviewcolumn.hpp>
#include <mm/gtk/private/treeviewcolumn_p.hpp>

#include <gtk/gtk.h>

/* Copyright 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>
#include <mm/gtk/cellarea.hpp>
#include <mm/gtk/treeview_private.hpp>

using Sizing = Gtk::TreeViewColumn::Sizing;

namespace Gtk
{

// Only necessary because of the templated ctor, see .hg file.
auto TreeViewColumn::class_init_() -> const Glib::Class&
{
  return treeviewcolumn_class_.init();
}

TreeViewColumn::TreeViewColumn(const Glib::ustring& title)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Object(Glib::ConstructParams(treeviewcolumn_class_.init(), "title",title.c_str(), nullptr))
{}

TreeViewColumn::TreeViewColumn(const Glib::ustring& title, Gtk::CellRenderer& cell)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Object(Glib::ConstructParams(treeviewcolumn_class_.init(), "title",title.c_str(), nullptr))
{
  //This is equivalent to _gtk_tree_view_column_new_with_attributes().
  //You will also need to call add_atrribute(), or set_renderer() a few times.

  pack_start(cell, true);
}

void TreeViewColumn::add_attribute(Gtk::CellRenderer& cell, const Glib::ustring& property_name,
                                   const TreeModelColumnBase& column)
{
  gtk_tree_view_column_add_attribute(gobj(),
      (GtkCellRenderer*) cell.gobj(), property_name.c_str(), column.index());
}

void TreeViewColumn::add_attribute(const Glib::PropertyProxy_Base& property,
                                   const TreeModelColumnBase& column)
{
  gtk_tree_view_column_add_attribute(gobj(),
      (GtkCellRenderer*) property.get_object()->gobj(), property.get_name(), column.index());
}

void TreeViewColumn::set_renderer(Gtk::CellRenderer& renderer, const TreeModelColumnBase& column)
{
  add_attribute(renderer._property_renderable(), column);
}


void TreeViewColumn::set_cell_data_func(CellRenderer& cell_renderer, const SlotTreeCellData& slot)
{
  //Create a copy of the slot. A pointer to this will be passed through the callback's data parameter.
  //It will be deleted when TreeView_Private::SignalProxy_CellData_gtk_callback_destroy() is called.
  auto slot_copy = new SlotTreeCellData(slot);

  gtk_tree_view_column_set_cell_data_func(
      gobj(), cell_renderer.gobj(),
      &TreeView_Private::SignalProxy_CellData_gtk_callback, slot_copy,
      &TreeView_Private::SignalProxy_CellData_gtk_callback_destroy);
}

void TreeViewColumn::unset_cell_data_func(CellRenderer& cell_renderer)
{
  gtk_tree_view_column_set_cell_data_func(gobj(), cell_renderer.gobj(), nullptr, nullptr, nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo TreeViewColumn_signal_clicked_info =
{
  "clicked",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::TreeViewColumn::Sizing>::value_type() -> GType
{
  return gtk_tree_view_column_sizing_get_type();
}


namespace Glib
{

auto wrap(GtkTreeViewColumn* object, bool take_copy) -> Gtk::TreeViewColumn*
{
  return dynamic_cast<Gtk::TreeViewColumn *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto TreeViewColumn_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeViewColumn_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_view_column_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  Buildable::add_interface(get_type());

  }

  return *this;
}


void TreeViewColumn_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TreeViewColumn_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new TreeViewColumn((GtkTreeViewColumn*)(o)));

}


/* The implementation: */

TreeViewColumn::TreeViewColumn(const Glib::ConstructParams& construct_params)
:
  Object(construct_params)
{
  }

TreeViewColumn::TreeViewColumn(GtkTreeViewColumn* castitem)
:
  Object((GObject*)(castitem))
{
  }


TreeViewColumn::TreeViewColumn(TreeViewColumn&& src) noexcept
: Object(std::move(src))
  , CellLayout(std::move(src))
  , Buildable(std::move(src))
{}

auto TreeViewColumn::operator=(TreeViewColumn&& src) noexcept -> TreeViewColumn&
{
  Object::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}

TreeViewColumn::~TreeViewColumn() noexcept
{
  destroy_();
}

TreeViewColumn::CppClassType TreeViewColumn::treeviewcolumn_class_; // initialize static member

auto TreeViewColumn::get_type() -> GType
{
  return treeviewcolumn_class_.init().get_type();
}


auto TreeViewColumn::get_base_type() -> GType
{
  return gtk_tree_view_column_get_type();
}


TreeViewColumn::TreeViewColumn()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Object(Glib::ConstructParams(treeviewcolumn_class_.init()))
{


}

void TreeViewColumn::pack_start(CellRenderer& cell, bool expand)
{
  gtk_tree_view_column_pack_start(gobj(), (cell).gobj(), static_cast<int>(expand));
}

void TreeViewColumn::pack_end(CellRenderer& cell, bool expand)
{
  gtk_tree_view_column_pack_end(gobj(), (cell).gobj(), static_cast<int>(expand));
}

void TreeViewColumn::clear()
{
  gtk_tree_view_column_clear(gobj());
}

void TreeViewColumn::add_attribute(CellRenderer& cell_renderer, const Glib::ustring& attribute, int column)
{
  gtk_tree_view_column_add_attribute(gobj(), (cell_renderer).gobj(), attribute.c_str(), column);
}

void TreeViewColumn::clear_attributes(CellRenderer& cell_renderer)
{
  gtk_tree_view_column_clear_attributes(gobj(), (cell_renderer).gobj());
}

void TreeViewColumn::set_spacing(int spacing)
{
  gtk_tree_view_column_set_spacing(gobj(), spacing);
}

auto TreeViewColumn::get_spacing() const -> int
{
  return gtk_tree_view_column_get_spacing(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_visible(bool visible)
{
  gtk_tree_view_column_set_visible(gobj(), static_cast<int>(visible));
}

auto TreeViewColumn::get_visible() const -> bool
{
  return gtk_tree_view_column_get_visible(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_resizable(bool resizable)
{
  gtk_tree_view_column_set_resizable(gobj(), static_cast<int>(resizable));
}

auto TreeViewColumn::get_resizable() const -> bool
{
  return gtk_tree_view_column_get_resizable(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_sizing(Sizing type)
{
  gtk_tree_view_column_set_sizing(gobj(), static_cast<GtkTreeViewColumnSizing>(type));
}

auto TreeViewColumn::get_sizing() -> Sizing
{
  return static_cast<Sizing>(gtk_tree_view_column_get_sizing(gobj()));
}

auto TreeViewColumn::get_x_offset() const -> int
{
  return gtk_tree_view_column_get_x_offset(const_cast<GtkTreeViewColumn*>(gobj()));
}

auto TreeViewColumn::get_width() const -> int
{
  return gtk_tree_view_column_get_width(const_cast<GtkTreeViewColumn*>(gobj()));
}

auto TreeViewColumn::get_fixed_width() const -> int
{
  return gtk_tree_view_column_get_fixed_width(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_fixed_width(int fixed_width)
{
  gtk_tree_view_column_set_fixed_width(gobj(), fixed_width);
}

void TreeViewColumn::set_min_width(int min_width)
{
  gtk_tree_view_column_set_min_width(gobj(), min_width);
}

auto TreeViewColumn::get_min_width() const -> int
{
  return gtk_tree_view_column_get_min_width(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_max_width(int max_width)
{
  gtk_tree_view_column_set_max_width(gobj(), max_width);
}

auto TreeViewColumn::get_max_width() const -> int
{
  return gtk_tree_view_column_get_max_width(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::clicked()
{
  gtk_tree_view_column_clicked(gobj());
}

void TreeViewColumn::set_title(const Glib::ustring& title)
{
  gtk_tree_view_column_set_title(gobj(), title.c_str());
}

auto TreeViewColumn::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_tree_view_column_get_title(const_cast<GtkTreeViewColumn*>(gobj())));
}

void TreeViewColumn::set_expand(bool expand)
{
  gtk_tree_view_column_set_expand(gobj(), static_cast<int>(expand));
}

auto TreeViewColumn::get_expand() const -> bool
{
  return gtk_tree_view_column_get_expand(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_clickable(bool clickable)
{
  gtk_tree_view_column_set_clickable(gobj(), static_cast<int>(clickable));
}

auto TreeViewColumn::get_clickable() const -> bool
{
  return gtk_tree_view_column_get_clickable(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_widget(Gtk::Widget& widget)
{
  gtk_tree_view_column_set_widget(gobj(), (widget).gobj());
}

auto TreeViewColumn::get_widget() -> Widget*
{
  return Glib::wrap(gtk_tree_view_column_get_widget(gobj()));
}

auto TreeViewColumn::get_widget() const -> const Widget*
{
  return Glib::wrap(gtk_tree_view_column_get_widget(const_cast<GtkTreeViewColumn*>(gobj())));
}

void TreeViewColumn::set_alignment(float xalign)
{
  gtk_tree_view_column_set_alignment(gobj(), xalign);
}

void TreeViewColumn::set_alignment(Align xalign)
{
  gtk_tree_view_column_set_alignment(gobj(), _gtkmm_align_float_from_enum(xalign));
}

auto TreeViewColumn::get_alignment() const -> float
{
  return gtk_tree_view_column_get_alignment(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_reorderable(bool reorderable)
{
  gtk_tree_view_column_set_reorderable(gobj(), static_cast<int>(reorderable));
}

auto TreeViewColumn::get_reorderable() const -> bool
{
  return gtk_tree_view_column_get_reorderable(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_sort_column(const TreeModelColumnBase& sort_column_id)
{
  gtk_tree_view_column_set_sort_column_id(gobj(), (sort_column_id).index());
}

void TreeViewColumn::set_sort_column(int sort_column_id)
{
  gtk_tree_view_column_set_sort_column_id(gobj(), sort_column_id);
}

auto TreeViewColumn::get_sort_column_id() const -> int
{
  return gtk_tree_view_column_get_sort_column_id(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_sort_indicator(bool setting)
{
  gtk_tree_view_column_set_sort_indicator(gobj(), static_cast<int>(setting));
}

auto TreeViewColumn::get_sort_indicator() const -> bool
{
  return gtk_tree_view_column_get_sort_indicator(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::set_sort_order(SortType order)
{
  gtk_tree_view_column_set_sort_order(gobj(), static_cast<GtkSortType>(order));
}

auto TreeViewColumn::get_sort_order() const -> SortType
{
  return static_cast<SortType>(gtk_tree_view_column_get_sort_order(const_cast<GtkTreeViewColumn*>(gobj())));
}

void TreeViewColumn::cell_set_cell_data(const Glib::RefPtr<TreeModel>& tree_model, const TreeModel::iterator& iter, bool is_expander, bool is_expanded)
{
  gtk_tree_view_column_cell_set_cell_data(gobj(), Glib::unwrap(tree_model), const_cast<GtkTreeIter*>((iter).gobj()), static_cast<int>(is_expander), static_cast<int>(is_expanded));
}

void TreeViewColumn::cell_get_size(int& x_offset, int& y_offset, int& width, int& height) const
{
  gtk_tree_view_column_cell_get_size(const_cast<GtkTreeViewColumn*>(gobj()), &(x_offset), &(y_offset), &(width), &(height));
}

auto TreeViewColumn::cell_is_visible() const -> bool
{
  return gtk_tree_view_column_cell_is_visible(const_cast<GtkTreeViewColumn*>(gobj()));
}

void TreeViewColumn::focus_cell(CellRenderer& cell)
{
  gtk_tree_view_column_focus_cell(gobj(), (cell).gobj());
}

auto TreeViewColumn::get_cell_position(const CellRenderer& cell_renderer, int& start_pos, int& width) const -> bool
{
  return gtk_tree_view_column_cell_get_position(const_cast<GtkTreeViewColumn*>(gobj()), const_cast<GtkCellRenderer*>((cell_renderer).gobj()), &(start_pos), &(width));
}

void TreeViewColumn::queue_resize()
{
  gtk_tree_view_column_queue_resize(gobj());
}

auto TreeViewColumn::get_tree_view() -> TreeView*
{
  auto retvalue = Glib::wrap((GtkTreeView*)(gtk_tree_view_column_get_tree_view(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeViewColumn::get_tree_view() const -> const TreeView*
{
  return const_cast<TreeViewColumn*>(this)->get_tree_view();
}

auto TreeViewColumn::get_button() -> Button*
{
  auto retvalue = Glib::wrap((GtkButton*)(gtk_tree_view_column_get_button(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TreeViewColumn::get_button() const -> const Button*
{
  return const_cast<TreeViewColumn*>(this)->get_button();
}


auto TreeViewColumn::signal_clicked() -> Glib::SignalProxy<void()>
{
  return Glib::SignalProxy<void() >(this, &TreeViewColumn_signal_clicked_info);
}


auto TreeViewColumn::property_visible() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "visible");
}

auto TreeViewColumn::property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "visible");
}

auto TreeViewColumn::property_resizable() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "resizable");
}

auto TreeViewColumn::property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "resizable");
}

auto TreeViewColumn::property_x_offset() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "x-offset");
}

auto TreeViewColumn::property_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "width");
}

auto TreeViewColumn::property_spacing() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "spacing");
}

auto TreeViewColumn::property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "spacing");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Sizing>::value,
  "Type Sizing cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeViewColumn::property_sizing() -> Glib::PropertyProxy< Sizing >
{
  return Glib::PropertyProxy< Sizing >(this, "sizing");
}

auto TreeViewColumn::property_sizing() const -> Glib::PropertyProxy_ReadOnly< Sizing >
{
  return Glib::PropertyProxy_ReadOnly< Sizing >(this, "sizing");
}

auto TreeViewColumn::property_fixed_width() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "fixed-width");
}

auto TreeViewColumn::property_fixed_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "fixed-width");
}

auto TreeViewColumn::property_min_width() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "min-width");
}

auto TreeViewColumn::property_min_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "min-width");
}

auto TreeViewColumn::property_max_width() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "max-width");
}

auto TreeViewColumn::property_max_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "max-width");
}

auto TreeViewColumn::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "title");
}

auto TreeViewColumn::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "title");
}

auto TreeViewColumn::property_expand() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "expand");
}

auto TreeViewColumn::property_expand() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "expand");
}

auto TreeViewColumn::property_clickable() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "clickable");
}

auto TreeViewColumn::property_clickable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "clickable");
}

auto TreeViewColumn::property_widget() -> Glib::PropertyProxy< Widget* >
{
  return Glib::PropertyProxy< Widget* >(this, "widget");
}

auto TreeViewColumn::property_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "widget");
}

auto TreeViewColumn::property_alignment() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "alignment");
}

auto TreeViewColumn::property_alignment() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "alignment");
}

auto TreeViewColumn::property_reorderable() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "reorderable");
}

auto TreeViewColumn::property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "reorderable");
}

auto TreeViewColumn::property_sort_indicator() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "sort-indicator");
}

auto TreeViewColumn::property_sort_indicator() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "sort-indicator");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
  "Type SortType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeViewColumn::property_sort_order() -> Glib::PropertyProxy< SortType >
{
  return Glib::PropertyProxy< SortType >(this, "sort-order");
}

auto TreeViewColumn::property_sort_order() const -> Glib::PropertyProxy_ReadOnly< SortType >
{
  return Glib::PropertyProxy_ReadOnly< SortType >(this, "sort-order");
}

auto TreeViewColumn::property_sort_column_id() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "sort-column-id");
}

auto TreeViewColumn::property_sort_column_id() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "sort-column-id");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellArea>>::value,
  "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TreeViewColumn::property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >(this, "cell-area");
}


} // namespace Gtk


