


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/grid.hpp>
#include <libmm-gtk/grid_p.hpp>


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

auto wrap(GtkGrid* object, const bool take_copy) -> Gtk::Grid*
{
  return dynamic_cast<Gtk::Grid *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Grid_Class::init() -> const Class&
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


auto Grid_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Grid_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Grid((GtkGrid*)o));

}


/* The implementation: */

Grid::Grid(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Grid::Grid(GtkGrid* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Grid::Grid(Grid&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto Grid::operator=(Grid&& src) noexcept -> Grid&
{
  Widget::operator=(std::move(src));
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
ObjectBase(nullptr),
Widget(Glib::ConstructParams(grid_class_.init()))
{


}

auto Grid::attach (Widget &child, const int column, const int row, const int width, const int height) -> void
{
  gtk_grid_attach(gobj(), child.gobj(), column, row, width, height);
}

auto Grid::attach_next_to (
  Widget &child, Widget &sibling, PositionType side, const int width, const int height) -> void
{
  gtk_grid_attach_next_to(gobj(), child.gobj(), sibling.gobj(), static_cast<GtkPositionType>(side), width, height);
}

auto Grid::attach_next_to (Widget &child, PositionType side, const int width, const int height) -> void
{
  gtk_grid_attach_next_to(gobj(), child.gobj(), nullptr, static_cast<GtkPositionType>(side), width, height);
}

auto Grid::get_child_at(
  const int column, const int row) -> Widget*
{
  return Glib::wrap(gtk_grid_get_child_at(gobj(), column, row));
}

auto Grid::get_child_at(
  const int column, const int row) const -> const Widget*
{
  return Glib::wrap(gtk_grid_get_child_at(const_cast<GtkGrid*>(gobj()), column, row));
}

auto Grid::remove (Widget &child) -> void
{
  gtk_grid_remove(gobj(), child.gobj());
}

auto Grid::insert_row (
  const int position) -> void
{
  gtk_grid_insert_row(gobj(), position);
}

auto Grid::insert_column (
  const int position) -> void
{
  gtk_grid_insert_column(gobj(), position);
}

auto Grid::remove_row (
  const int position) -> void
{
  gtk_grid_remove_row(gobj(), position);
}

auto Grid::remove_column (
  const int position) -> void
{
  gtk_grid_remove_column(gobj(), position);
}

auto Grid::insert_next_to (Widget &sibling, PositionType side) -> void
{
  gtk_grid_insert_next_to(gobj(), sibling.gobj(), static_cast<GtkPositionType>(side));
}

auto Grid::set_row_homogeneous (
  const bool homogeneous) -> void
{
  gtk_grid_set_row_homogeneous(gobj(), homogeneous);
}

auto Grid::get_row_homogeneous() const -> bool
{
  return gtk_grid_get_row_homogeneous(const_cast<GtkGrid*>(gobj()));
}

auto Grid::set_row_spacing (
  const guint spacing) -> void
{
  gtk_grid_set_row_spacing(gobj(), spacing);
}

auto Grid::get_row_spacing() const -> guint
{
  return gtk_grid_get_row_spacing(const_cast<GtkGrid*>(gobj()));
}

auto Grid::set_column_homogeneous (
  const bool homogeneous) -> void
{
  gtk_grid_set_column_homogeneous(gobj(), homogeneous);
}

auto Grid::get_column_homogeneous() const -> bool
{
  return gtk_grid_get_column_homogeneous(const_cast<GtkGrid*>(gobj()));
}

auto Grid::set_column_spacing (
  const guint spacing) -> void
{
  gtk_grid_set_column_spacing(gobj(), spacing);
}

auto Grid::get_column_spacing() const -> guint
{
  return gtk_grid_get_column_spacing(const_cast<GtkGrid*>(gobj()));
}

auto Grid::set_row_baseline_position (
  const int row, BaselinePosition pos) -> void
{
  gtk_grid_set_row_baseline_position(gobj(), row, static_cast<GtkBaselinePosition>(pos));
}

auto Grid::get_row_baseline_position(
  const int row) const -> BaselinePosition
{
  return static_cast<BaselinePosition>(gtk_grid_get_row_baseline_position(const_cast<GtkGrid*>(gobj()), row));
}

auto Grid::set_baseline_row (
  const int row) -> void
{
  gtk_grid_set_baseline_row(gobj(), row);
}

auto Grid::get_baseline_row() const -> int
{
  return gtk_grid_get_baseline_row(const_cast<GtkGrid*>(gobj()));
}

auto Grid::query_child (
  const Widget &child, int &column, int &row, int &width, int &height) const -> void
{
  gtk_grid_query_child(const_cast<GtkGrid*>(gobj()), const_cast<GtkWidget*>(child.gobj()), &column, &row, &width, &height);
}


auto Grid::property_row_spacing() -> Glib::PropertyProxy< guint >
{
  return {this, "row-spacing"};
}

auto Grid::property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "row-spacing"};
}

auto Grid::property_column_spacing() -> Glib::PropertyProxy< guint >
{
  return {this, "column-spacing"};
}

auto Grid::property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "column-spacing"};
}

auto Grid::property_row_homogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "row-homogeneous"};
}

auto Grid::property_row_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "row-homogeneous"};
}

auto Grid::property_column_homogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "column-homogeneous"};
}

auto Grid::property_column_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "column-homogeneous"};
}

auto Grid::property_baseline_row() -> Glib::PropertyProxy< int >
{
  return {this, "baseline-row"};
}

auto Grid::property_baseline_row() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "baseline-row"};
}


} // namespace Gtk


