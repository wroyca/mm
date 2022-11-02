// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/grid.hpp>
#include <mm/gtk/private/grid_p.hpp>


/*
 * Copyright 2010 The gtkmm Development Team
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

namespace Gtk
{

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkGrid* object, bool take_copy) -> Gtk::Grid*
{
  return dynamic_cast<Gtk::Grid *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Grid_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Grid_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_grid_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


void Grid_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Grid_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Grid((GtkGrid*)(o)));

}


/* The implementation: */

Grid::Grid(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Grid::Grid(GtkGrid* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


Grid::Grid(Grid&& src) noexcept
: Gtk::Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto Grid::operator=(Grid&& src) noexcept -> Grid&
{
  Gtk::Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

Grid::~Grid() noexcept
{
  destroy_();
}

Grid::CppClassType Grid::grid_class_; // initialize static member

auto Grid::get_type() -> GType
{
  return grid_class_.init().get_type();
}


auto Grid::get_base_type() -> GType
{
  return gtk_grid_get_type();
}


Grid::Grid()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(grid_class_.init()))
{


}

void Grid::attach(Widget& child, int column, int row, int width, int height)
{
  gtk_grid_attach(gobj(), (child).gobj(), column, row, width, height);
}

void Grid::attach_next_to(Widget& child, Widget& sibling, PositionType side, int width, int height)
{
  gtk_grid_attach_next_to(gobj(), (child).gobj(), (sibling).gobj(), static_cast<GtkPositionType>(side), width, height);
}

void Grid::attach_next_to(Widget& child, PositionType side, int width, int height)
{
  gtk_grid_attach_next_to(gobj(), (child).gobj(), nullptr, static_cast<GtkPositionType>(side), width, height);
}

auto Grid::get_child_at(int column, int row) -> Widget*
{
  return Glib::wrap(gtk_grid_get_child_at(gobj(), column, row));
}

auto Grid::get_child_at(int column, int row) const -> const Widget*
{
  return Glib::wrap(gtk_grid_get_child_at(const_cast<GtkGrid*>(gobj()), column, row));
}

void Grid::remove(Widget& child)
{
  gtk_grid_remove(gobj(), (child).gobj());
}

void Grid::insert_row(int position)
{
  gtk_grid_insert_row(gobj(), position);
}

void Grid::insert_column(int position)
{
  gtk_grid_insert_column(gobj(), position);
}

void Grid::remove_row(int position)
{
  gtk_grid_remove_row(gobj(), position);
}

void Grid::remove_column(int position)
{
  gtk_grid_remove_column(gobj(), position);
}

void Grid::insert_next_to(Widget& sibling, PositionType side)
{
  gtk_grid_insert_next_to(gobj(), (sibling).gobj(), static_cast<GtkPositionType>(side));
}

void Grid::set_row_homogeneous(bool homogeneous)
{
  gtk_grid_set_row_homogeneous(gobj(), static_cast<int>(homogeneous));
}

auto Grid::get_row_homogeneous() const -> bool
{
  return gtk_grid_get_row_homogeneous(const_cast<GtkGrid*>(gobj()));
}

void Grid::set_row_spacing(guint spacing)
{
  gtk_grid_set_row_spacing(gobj(), spacing);
}

auto Grid::get_row_spacing() const -> guint
{
  return gtk_grid_get_row_spacing(const_cast<GtkGrid*>(gobj()));
}

void Grid::set_column_homogeneous(bool homogeneous)
{
  gtk_grid_set_column_homogeneous(gobj(), static_cast<int>(homogeneous));
}

auto Grid::get_column_homogeneous() const -> bool
{
  return gtk_grid_get_column_homogeneous(const_cast<GtkGrid*>(gobj()));
}

void Grid::set_column_spacing(guint spacing)
{
  gtk_grid_set_column_spacing(gobj(), spacing);
}

auto Grid::get_column_spacing() const -> guint
{
  return gtk_grid_get_column_spacing(const_cast<GtkGrid*>(gobj()));
}

void Grid::set_row_baseline_position(int row, BaselinePosition pos)
{
  gtk_grid_set_row_baseline_position(gobj(), row, static_cast<GtkBaselinePosition>(pos));
}

auto Grid::get_row_baseline_position(int row) const -> BaselinePosition
{
  return static_cast<BaselinePosition>(gtk_grid_get_row_baseline_position(const_cast<GtkGrid*>(gobj()), row));
}

void Grid::set_baseline_row(int row)
{
  gtk_grid_set_baseline_row(gobj(), row);
}

auto Grid::get_baseline_row() const -> int
{
  return gtk_grid_get_baseline_row(const_cast<GtkGrid*>(gobj()));
}

void Grid::query_child(const Widget& child, int& column, int& row, int& width, int& height) const
{
  gtk_grid_query_child(const_cast<GtkGrid*>(gobj()), const_cast<GtkWidget*>((child).gobj()), &(column), &(row), &(width), &(height));
}


auto Grid::property_row_spacing() -> Glib::PropertyProxy< guint >
{
  return Glib::PropertyProxy< guint >(this, "row-spacing");
}

auto Grid::property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "row-spacing");
}

auto Grid::property_column_spacing() -> Glib::PropertyProxy< guint >
{
  return Glib::PropertyProxy< guint >(this, "column-spacing");
}

auto Grid::property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "column-spacing");
}

auto Grid::property_row_homogeneous() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "row-homogeneous");
}

auto Grid::property_row_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "row-homogeneous");
}

auto Grid::property_column_homogeneous() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "column-homogeneous");
}

auto Grid::property_column_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "column-homogeneous");
}

auto Grid::property_baseline_row() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "baseline-row");
}

auto Grid::property_baseline_row() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "baseline-row");
}


} // namespace Gtk


