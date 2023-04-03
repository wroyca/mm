// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gridlayoutchild.hxx>
#include <libmm/gtk/gridlayoutchild_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkGridLayoutChild* object, bool take_copy) -> Glib::RefPtr<Gtk::GridLayoutChild>
  {
    return Glib::make_refptr_for_instance<Gtk::GridLayoutChild> (
        dynamic_cast<Gtk::GridLayoutChild*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GridLayoutChild_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GridLayoutChild_Class::class_init_function;

      gtype_ = gtk_grid_layout_child_get_type ();
    }

    return *this;
  }

  auto
  GridLayoutChild_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GridLayoutChild_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GridLayoutChild ((GtkGridLayoutChild*) object);
  }

  auto
  GridLayoutChild::gobj_copy () -> GtkGridLayoutChild*
  {
    reference ();
    return gobj ();
  }

  GridLayoutChild::GridLayoutChild (
      const Glib::ConstructParams& construct_params)
    : LayoutChild (construct_params)
  {
  }

  GridLayoutChild::GridLayoutChild (GtkGridLayoutChild* castitem)
    : LayoutChild ((GtkLayoutChild*) (castitem))
  {
  }

  GridLayoutChild::GridLayoutChild (GridLayoutChild&& src) noexcept
    : LayoutChild (std::move (src))
  {
  }

  auto
  GridLayoutChild::operator= (GridLayoutChild&& src) noexcept -> GridLayoutChild&
  {
    LayoutChild::operator= (std::move (src));
    return *this;
  }

  GridLayoutChild::~GridLayoutChild () noexcept {}

  GridLayoutChild::CppClassType GridLayoutChild::gridlayoutchild_class_;

  auto
  GridLayoutChild::get_type () -> GType
  {
    return gridlayoutchild_class_.init ().get_type ();
  }

  auto
  GridLayoutChild::get_base_type () -> GType
  {
    return gtk_grid_layout_child_get_type ();
  }

  GridLayoutChild::GridLayoutChild ()
    : Glib::ObjectBase (nullptr),
      LayoutChild (Glib::ConstructParams (gridlayoutchild_class_.init ()))
  {
  }

  auto
  GridLayoutChild::set_row (int row) -> void
  {
    gtk_grid_layout_child_set_row (gobj (), row);
  }

  auto
  GridLayoutChild::get_row () const -> int
  {
    return gtk_grid_layout_child_get_row (
        const_cast<GtkGridLayoutChild*> (gobj ()));
  }

  auto
  GridLayoutChild::set_column (int column) -> void
  {
    gtk_grid_layout_child_set_column (gobj (), column);
  }

  auto
  GridLayoutChild::get_column () const -> int
  {
    return gtk_grid_layout_child_get_column (
        const_cast<GtkGridLayoutChild*> (gobj ()));
  }

  auto
  GridLayoutChild::set_column_span (int span) -> void
  {
    gtk_grid_layout_child_set_column_span (gobj (), span);
  }

  auto
  GridLayoutChild::get_column_span () const -> int
  {
    return gtk_grid_layout_child_get_column_span (
        const_cast<GtkGridLayoutChild*> (gobj ()));
  }

  auto
  GridLayoutChild::set_row_span (int span) -> void
  {
    gtk_grid_layout_child_set_row_span (gobj (), span);
  }

  auto
  GridLayoutChild::get_row_span () const -> int
  {
    return gtk_grid_layout_child_get_row_span (
        const_cast<GtkGridLayoutChild*> (gobj ()));
  }

  auto
  GridLayoutChild::property_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "column");
  }

  auto
  GridLayoutChild::property_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "column");
  }

  auto
  GridLayoutChild::property_row () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "row");
  }

  auto
  GridLayoutChild::property_row () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "row");
  }

  auto
  GridLayoutChild::property_column_span () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "column-span");
  }

  auto
  GridLayoutChild::property_column_span () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "column-span");
  }

  auto
  GridLayoutChild::property_row_span () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "row-span");
  }

  auto
  GridLayoutChild::property_row_span () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "row-span");
  }

} // namespace Gtk
