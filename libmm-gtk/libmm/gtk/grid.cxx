// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/grid.hxx>
#include <libmm/gtk/grid_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GtkGrid* object, bool take_copy) -> gtk::Grid*
  {
    return dynamic_cast<gtk::Grid*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Grid_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Grid_Class::class_init_function;

      register_derived_type (gtk_grid_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Grid_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Grid_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Grid ((GtkGrid*) (o)));
  }

  Grid::Grid (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Grid::Grid (GtkGrid* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Grid::Grid (Grid&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Grid::operator= (Grid&& src) noexcept -> Grid&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Grid::~Grid () noexcept
  {
    destroy_ ();
  }

  Grid::CppClassType Grid::grid_class_;

  auto
  Grid::get_type () -> GType
  {
    return grid_class_.init ().get_type ();
  }

  auto
  Grid::get_base_type () -> GType
  {
    return gtk_grid_get_type ();
  }

  Grid::Grid ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (grid_class_.init ()))
  {
  }

  auto
  Grid::attach (Widget& child, int column, int row, int width, int height) -> void
  {
    gtk_grid_attach (gobj (), (child).gobj (), column, row, width, height);
  }

  auto
  Grid::attach_next_to (Widget& child,
                        Widget& sibling,
                        PositionType side,
                        int width,
                        int height) -> void
  {
    gtk_grid_attach_next_to (gobj (),
                             (child).gobj (),
                             (sibling).gobj (),
                             static_cast<GtkPositionType> (side),
                             width,
                             height);
  }

  auto
  Grid::attach_next_to (Widget& child, PositionType side, int width, int height) -> void
  {
    gtk_grid_attach_next_to (gobj (),
                             (child).gobj (),
                             nullptr,
                             static_cast<GtkPositionType> (side),
                             width,
                             height);
  }

  auto
  Grid::get_child_at (int column, int row) -> Widget*
  {
    return glib::wrap (gtk_grid_get_child_at (gobj (), column, row));
  }

  auto
  Grid::get_child_at (int column, int row) const -> const Widget*
  {
    return glib::wrap (
        gtk_grid_get_child_at (const_cast<GtkGrid*> (gobj ()), column, row));
  }

  auto
  Grid::remove (Widget& child) -> void
  {
    gtk_grid_remove (gobj (), (child).gobj ());
  }

  auto
  Grid::insert_row (int position) -> void
  {
    gtk_grid_insert_row (gobj (), position);
  }

  auto
  Grid::insert_column (int position) -> void
  {
    gtk_grid_insert_column (gobj (), position);
  }

  auto
  Grid::remove_row (int position) -> void
  {
    gtk_grid_remove_row (gobj (), position);
  }

  auto
  Grid::remove_column (int position) -> void
  {
    gtk_grid_remove_column (gobj (), position);
  }

  auto
  Grid::insert_next_to (Widget& sibling, PositionType side) -> void
  {
    gtk_grid_insert_next_to (gobj (),
                             (sibling).gobj (),
                             static_cast<GtkPositionType> (side));
  }

  auto
  Grid::set_row_homogeneous (bool homogeneous) -> void
  {
    gtk_grid_set_row_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Grid::get_row_homogeneous () const -> bool
  {
    return gtk_grid_get_row_homogeneous (const_cast<GtkGrid*> (gobj ()));
  }

  auto
  Grid::set_row_spacing (guint spacing) -> void
  {
    gtk_grid_set_row_spacing (gobj (), spacing);
  }

  auto
  Grid::get_row_spacing () const -> guint
  {
    return gtk_grid_get_row_spacing (const_cast<GtkGrid*> (gobj ()));
  }

  auto
  Grid::set_column_homogeneous (bool homogeneous) -> void
  {
    gtk_grid_set_column_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Grid::get_column_homogeneous () const -> bool
  {
    return gtk_grid_get_column_homogeneous (const_cast<GtkGrid*> (gobj ()));
  }

  auto
  Grid::set_column_spacing (guint spacing) -> void
  {
    gtk_grid_set_column_spacing (gobj (), spacing);
  }

  auto
  Grid::get_column_spacing () const -> guint
  {
    return gtk_grid_get_column_spacing (const_cast<GtkGrid*> (gobj ()));
  }

  auto
  Grid::set_row_baseline_position (int row, BaselinePosition pos) -> void
  {
    gtk_grid_set_row_baseline_position (gobj (),
                                        row,
                                        static_cast<GtkBaselinePosition> (pos));
  }

  auto
  Grid::get_row_baseline_position (int row) const -> BaselinePosition
  {
    return static_cast<BaselinePosition> (
        gtk_grid_get_row_baseline_position (const_cast<GtkGrid*> (gobj ()),
                                            row));
  }

  auto
  Grid::set_baseline_row (int row) -> void
  {
    gtk_grid_set_baseline_row (gobj (), row);
  }

  auto
  Grid::get_baseline_row () const -> int
  {
    return gtk_grid_get_baseline_row (const_cast<GtkGrid*> (gobj ()));
  }

  auto
  Grid::query_child (const Widget& child,
                     int& column,
                     int& row,
                     int& width,
                     int& height) const -> void
  {
    gtk_grid_query_child (const_cast<GtkGrid*> (gobj ()),
                          const_cast<GtkWidget*> ((child).gobj ()),
                          &(column),
                          &(row),
                          &(width),
                          &(height));
  }

  auto
  Grid::property_row_spacing () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "row-spacing");
  }

  auto
  Grid::property_row_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "row-spacing");
  }

  auto
  Grid::property_column_spacing () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "column-spacing");
  }

  auto
  Grid::property_column_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "column-spacing");
  }

  auto
  Grid::property_row_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "row-homogeneous");
  }

  auto
  Grid::property_row_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "row-homogeneous");
  }

  auto
  Grid::property_column_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "column-homogeneous");
  }

  auto
  Grid::property_column_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "column-homogeneous");
  }

  auto
  Grid::property_baseline_row () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "baseline-row");
  }

  auto
  Grid::property_baseline_row () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "baseline-row");
  }

} // namespace gtk
