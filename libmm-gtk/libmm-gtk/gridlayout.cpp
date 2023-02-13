


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/gridlayout.hpp>
#include <mm/gtk/private/gridlayout_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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

auto wrap(GtkGridLayout* object, const bool take_copy) -> RefPtr<Gtk::GridLayout>
{
  return Glib::make_refptr_for_instance<Gtk::GridLayout>( dynamic_cast<Gtk::GridLayout*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GridLayout_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GridLayout_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_grid_layout_get_type();

  }

  return *this;
}


auto GridLayout_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GridLayout_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GridLayout((GtkGridLayout*)object);
}


/* The implementation: */

auto GridLayout::gobj_copy() -> GtkGridLayout*
{
  reference();
  return gobj();
}

GridLayout::GridLayout(const Glib::ConstructParams& construct_params)
:
  LayoutManager(construct_params)
{

}

GridLayout::GridLayout(GtkGridLayout* castitem)
:
  LayoutManager((GtkLayoutManager*)castitem)
{}


GridLayout::GridLayout(GridLayout&& src) noexcept
: LayoutManager(std::move(src))
{}

auto GridLayout::operator=(GridLayout&& src) noexcept -> GridLayout&
{
  LayoutManager::operator=(std::move(src));
  return *this;
}


GridLayout::~GridLayout() noexcept = default;

GridLayout::CppClassType GridLayout::gridlayout_class_; // initialize static member

auto GridLayout::get_type() -> GType
{
  return gridlayout_class_.init().get_type();
}


auto GridLayout::get_base_type() -> GType
{
  return gtk_grid_layout_get_type();
}


GridLayout::GridLayout()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  LayoutManager(Glib::ConstructParams(gridlayout_class_.init()))
{


}

auto GridLayout::create() -> Glib::RefPtr<GridLayout>
{
  return Glib::make_refptr_for_instance<GridLayout>( new GridLayout() );
}

auto GridLayout::set_row_homogeneous (
  const bool homogeneous) -> void
{
  gtk_grid_layout_set_row_homogeneous(gobj(), homogeneous);
}

auto GridLayout::get_row_homogeneous() const -> bool
{
  return gtk_grid_layout_get_row_homogeneous(const_cast<GtkGridLayout*>(gobj()));
}

auto GridLayout::set_row_spacing (
  const guint spacing) -> void
{
  gtk_grid_layout_set_row_spacing(gobj(), spacing);
}

auto GridLayout::get_row_spacing() const -> guint
{
  return gtk_grid_layout_get_row_spacing(const_cast<GtkGridLayout*>(gobj()));
}

auto GridLayout::set_column_homogeneous (
  const bool homogeneous) -> void
{
  gtk_grid_layout_set_column_homogeneous(gobj(), homogeneous);
}

auto GridLayout::get_column_homogeneous() const -> bool
{
  return gtk_grid_layout_get_column_homogeneous(const_cast<GtkGridLayout*>(gobj()));
}

auto GridLayout::set_column_spacing (
  const guint spacing) -> void
{
  gtk_grid_layout_set_column_spacing(gobj(), spacing);
}

auto GridLayout::get_column_spacing() const -> guint
{
  return gtk_grid_layout_get_column_spacing(const_cast<GtkGridLayout*>(gobj()));
}

auto GridLayout::set_row_baseline_position (
  const int row, BaselinePosition pos) -> void
{
  gtk_grid_layout_set_row_baseline_position(gobj(), row, static_cast<GtkBaselinePosition>(pos));
}

auto GridLayout::get_row_baseline_position(
  const int row) const -> BaselinePosition
{
  return static_cast<BaselinePosition>(gtk_grid_layout_get_row_baseline_position(const_cast<GtkGridLayout*>(gobj()), row));
}

auto GridLayout::set_baseline_row (
  const int row) -> void
{
  gtk_grid_layout_set_baseline_row(gobj(), row);
}

auto GridLayout::get_baseline_row() const -> int
{
  return gtk_grid_layout_get_baseline_row(const_cast<GtkGridLayout*>(gobj()));
}


auto GridLayout::property_row_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "row-spacing"};
}

auto GridLayout::property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "row-spacing"};
}

auto GridLayout::property_column_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "column-spacing"};
}

auto GridLayout::property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "column-spacing"};
}

auto GridLayout::property_row_homogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "row-homogeneous"};
}

auto GridLayout::property_row_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "row-homogeneous"};
}

auto GridLayout::property_column_homogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "column-homogeneous"};
}

auto GridLayout::property_column_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "column-homogeneous"};
}

auto GridLayout::property_baseline_row() -> Glib::PropertyProxy< int >
{
  return {this, "baseline-row"};
}

auto GridLayout::property_baseline_row() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "baseline-row"};
}


} // namespace Gtk


