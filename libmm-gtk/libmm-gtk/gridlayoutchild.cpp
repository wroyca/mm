


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/gridlayoutchild.hpp>
#include <libmm-gtk/gridlayoutchild_p.hpp>


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

auto wrap(GtkGridLayoutChild* object, const bool take_copy) -> RefPtr<Gtk::GridLayoutChild>
{
  return Glib::make_refptr_for_instance<Gtk::GridLayoutChild>( dynamic_cast<Gtk::GridLayoutChild*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto GridLayoutChild_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GridLayoutChild_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_grid_layout_child_get_type();

  }

  return *this;
}


auto GridLayoutChild_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GridLayoutChild_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new GridLayoutChild((GtkGridLayoutChild*)object);
}


/* The implementation: */

auto GridLayoutChild::gobj_copy() -> GtkGridLayoutChild*
{
  reference();
  return gobj();
}

GridLayoutChild::GridLayoutChild(const Glib::ConstructParams& construct_params)
:
  LayoutChild(construct_params)
{

}

GridLayoutChild::GridLayoutChild(GtkGridLayoutChild* castitem)
:
  LayoutChild((GtkLayoutChild*)castitem)
{}


GridLayoutChild::GridLayoutChild(GridLayoutChild&& src) noexcept
: LayoutChild(std::move(src))
{}

auto GridLayoutChild::operator=(GridLayoutChild&& src) noexcept -> GridLayoutChild&
{
  LayoutChild::operator=(std::move(src));
  return *this;
}


GridLayoutChild::~GridLayoutChild() noexcept = default;

GridLayoutChild::CppClassType GridLayoutChild::gridlayoutchild_class_; // initialize static member

auto GridLayoutChild::get_type() -> GType
{
  return gridlayoutchild_class_.init().get_type();
}


auto GridLayoutChild::get_base_type() -> GType
{
  return gtk_grid_layout_child_get_type();
}


GridLayoutChild::GridLayoutChild()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  LayoutChild(Glib::ConstructParams(gridlayoutchild_class_.init()))
{


}

auto GridLayoutChild::set_row (
  const int row) -> void
{
  gtk_grid_layout_child_set_row(gobj(), row);
}

auto GridLayoutChild::get_row() const -> int
{
  return gtk_grid_layout_child_get_row(const_cast<GtkGridLayoutChild*>(gobj()));
}

auto GridLayoutChild::set_column (
  const int column) -> void
{
  gtk_grid_layout_child_set_column(gobj(), column);
}

auto GridLayoutChild::get_column() const -> int
{
  return gtk_grid_layout_child_get_column(const_cast<GtkGridLayoutChild*>(gobj()));
}

auto GridLayoutChild::set_column_span (
  const int span) -> void
{
  gtk_grid_layout_child_set_column_span(gobj(), span);
}

auto GridLayoutChild::get_column_span() const -> int
{
  return gtk_grid_layout_child_get_column_span(const_cast<GtkGridLayoutChild*>(gobj()));
}

auto GridLayoutChild::set_row_span (
  const int span) -> void
{
  gtk_grid_layout_child_set_row_span(gobj(), span);
}

auto GridLayoutChild::get_row_span() const -> int
{
  return gtk_grid_layout_child_get_row_span(const_cast<GtkGridLayoutChild*>(gobj()));
}


auto GridLayoutChild::property_column() -> Glib::PropertyProxy< int >
{
  return {this, "column"};
}

auto GridLayoutChild::property_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "column"};
}

auto GridLayoutChild::property_row() -> Glib::PropertyProxy< int >
{
  return {this, "row"};
}

auto GridLayoutChild::property_row() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "row"};
}

auto GridLayoutChild::property_column_span() -> Glib::PropertyProxy< int >
{
  return {this, "column-span"};
}

auto GridLayoutChild::property_column_span() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "column-span"};
}

auto GridLayoutChild::property_row_span() -> Glib::PropertyProxy< int >
{
  return {this, "row-span"};
}

auto GridLayoutChild::property_row_span() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "row-span"};
}


} // namespace Gtk


