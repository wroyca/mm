// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gridlayout.hxx>
#include <libmm/gtk/gridlayout_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkGridLayout* object, bool take_copy) -> glib::RefPtr<gtk::GridLayout>
  {
    return glib::make_refptr_for_instance<gtk::GridLayout> (
        dynamic_cast<gtk::GridLayout*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GridLayout_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GridLayout_Class::class_init_function;

      gtype_ = gtk_grid_layout_get_type ();
    }

    return *this;
  }

  auto
  GridLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GridLayout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GridLayout ((GtkGridLayout*) object);
  }

  auto
  GridLayout::gobj_copy () -> GtkGridLayout*
  {
    reference ();
    return gobj ();
  }

  GridLayout::GridLayout (const glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  GridLayout::GridLayout (GtkGridLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  GridLayout::GridLayout (GridLayout&& src) noexcept
    : LayoutManager (std::move (src))
  {
  }

  auto
  GridLayout::operator= (GridLayout&& src) noexcept -> GridLayout&
  {
    LayoutManager::operator= (std::move (src));
    return *this;
  }

  GridLayout::~GridLayout () noexcept {}

  GridLayout::CppClassType GridLayout::gridlayout_class_;

  auto
  GridLayout::get_type () -> GType
  {
    return gridlayout_class_.init ().get_type ();
  }

  auto
  GridLayout::get_base_type () -> GType
  {
    return gtk_grid_layout_get_type ();
  }

  GridLayout::GridLayout ()
    : glib::ObjectBase (nullptr),
      LayoutManager (glib::ConstructParams (gridlayout_class_.init ()))
  {
  }

  auto
  GridLayout::create () -> glib::RefPtr<GridLayout>
  {
    return glib::make_refptr_for_instance<GridLayout> (new GridLayout ());
  }

  auto
  GridLayout::set_row_homogeneous (bool homogeneous) -> void
  {
    gtk_grid_layout_set_row_homogeneous (gobj (),
                                         static_cast<int> (homogeneous));
  }

  auto
  GridLayout::get_row_homogeneous () const -> bool
  {
    return gtk_grid_layout_get_row_homogeneous (
        const_cast<GtkGridLayout*> (gobj ()));
  }

  auto
  GridLayout::set_row_spacing (guint spacing) -> void
  {
    gtk_grid_layout_set_row_spacing (gobj (), spacing);
  }

  auto
  GridLayout::get_row_spacing () const -> guint
  {
    return gtk_grid_layout_get_row_spacing (
        const_cast<GtkGridLayout*> (gobj ()));
  }

  auto
  GridLayout::set_column_homogeneous (bool homogeneous) -> void
  {
    gtk_grid_layout_set_column_homogeneous (gobj (),
                                            static_cast<int> (homogeneous));
  }

  auto
  GridLayout::get_column_homogeneous () const -> bool
  {
    return gtk_grid_layout_get_column_homogeneous (
        const_cast<GtkGridLayout*> (gobj ()));
  }

  auto
  GridLayout::set_column_spacing (guint spacing) -> void
  {
    gtk_grid_layout_set_column_spacing (gobj (), spacing);
  }

  auto
  GridLayout::get_column_spacing () const -> guint
  {
    return gtk_grid_layout_get_column_spacing (
        const_cast<GtkGridLayout*> (gobj ()));
  }

  auto
  GridLayout::set_row_baseline_position (int row, BaselinePosition pos) -> void
  {
    gtk_grid_layout_set_row_baseline_position (
        gobj (),
        row,
        static_cast<GtkBaselinePosition> (pos));
  }

  auto
  GridLayout::get_row_baseline_position (int row) const -> BaselinePosition
  {
    return static_cast<BaselinePosition> (
        gtk_grid_layout_get_row_baseline_position (
            const_cast<GtkGridLayout*> (gobj ()),
            row));
  }

  auto
  GridLayout::set_baseline_row (int row) -> void
  {
    gtk_grid_layout_set_baseline_row (gobj (), row);
  }

  auto
  GridLayout::get_baseline_row () const -> int
  {
    return gtk_grid_layout_get_baseline_row (
        const_cast<GtkGridLayout*> (gobj ()));
  }

  auto
  GridLayout::property_row_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "row-spacing");
  }

  auto
  GridLayout::property_row_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "row-spacing");
  }

  auto
  GridLayout::property_column_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "column-spacing");
  }

  auto
  GridLayout::property_column_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "column-spacing");
  }

  auto
  GridLayout::property_row_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "row-homogeneous");
  }

  auto
  GridLayout::property_row_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "row-homogeneous");
  }

  auto
  GridLayout::property_column_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "column-homogeneous");
  }

  auto
  GridLayout::property_column_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "column-homogeneous");
  }

  auto
  GridLayout::property_baseline_row () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "baseline-row");
  }

  auto
  GridLayout::property_baseline_row () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "baseline-row");
  }

} // namespace gtk
