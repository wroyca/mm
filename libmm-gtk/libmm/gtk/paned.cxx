// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/paned.hxx>
#include <libmm/gtk/paned_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPaned* object, bool take_copy) -> Gtk::Paned*
  {
    return dynamic_cast<Gtk::Paned*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Paned_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Paned_Class::class_init_function;

      register_derived_type (gtk_paned_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Paned_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Paned_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Paned ((GtkPaned*) (o)));
  }

  Paned::Paned (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Paned::Paned (GtkPaned* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Paned::Paned (Paned&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Paned::operator= (Paned&& src) noexcept -> Paned&
  {
    Gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Paned::~Paned () noexcept
  {
    destroy_ ();
  }

  Paned::CppClassType Paned::paned_class_;

  auto
  Paned::get_type () -> GType
  {
    return paned_class_.init ().get_type ();
  }

  auto
  Paned::get_base_type () -> GType
  {
    return gtk_paned_get_type ();
  }

  Paned::Paned (Orientation orientation)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (
          Glib::ConstructParams (paned_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 nullptr))
  {
  }

  auto
  Paned::set_start_child (Widget& child) -> void
  {
    gtk_paned_set_start_child (gobj (), (child).gobj ());
  }

  auto
  Paned::get_start_child () -> Widget*
  {
    return Glib::wrap (gtk_paned_get_start_child (gobj ()));
  }

  auto
  Paned::get_start_child () const -> const Widget*
  {
    return const_cast<Paned*> (this)->get_start_child ();
  }

  auto
  Paned::set_resize_start_child (bool resize) -> void
  {
    gtk_paned_set_resize_start_child (gobj (), static_cast<int> (resize));
  }

  auto
  Paned::get_resize_start_child () const -> bool
  {
    return gtk_paned_get_resize_start_child (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::set_shrink_start_child (bool resize) -> void
  {
    gtk_paned_set_shrink_start_child (gobj (), static_cast<int> (resize));
  }

  auto
  Paned::get_shrink_start_child () const -> bool
  {
    return gtk_paned_get_shrink_start_child (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::set_end_child (Widget& child) -> void
  {
    gtk_paned_set_end_child (gobj (), (child).gobj ());
  }

  auto
  Paned::get_end_child () -> Widget*
  {
    return Glib::wrap (gtk_paned_get_end_child (gobj ()));
  }

  auto
  Paned::get_end_child () const -> const Widget*
  {
    return const_cast<Paned*> (this)->get_end_child ();
  }

  auto
  Paned::set_resize_end_child (bool resize) -> void
  {
    gtk_paned_set_resize_end_child (gobj (), static_cast<int> (resize));
  }

  auto
  Paned::get_resize_end_child () const -> bool
  {
    return gtk_paned_get_resize_end_child (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::set_shrink_end_child (bool resize) -> void
  {
    gtk_paned_set_shrink_end_child (gobj (), static_cast<int> (resize));
  }

  auto
  Paned::get_shrink_end_child () const -> bool
  {
    return gtk_paned_get_shrink_end_child (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::get_position () const -> int
  {
    return gtk_paned_get_position (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::set_position (int position) -> void
  {
    gtk_paned_set_position (gobj (), position);
  }

  auto
  Paned::set_wide_handle (bool wide) -> void
  {
    gtk_paned_set_wide_handle (gobj (), static_cast<int> (wide));
  }

  auto
  Paned::get_wide_handle () const -> bool
  {
    return gtk_paned_get_wide_handle (const_cast<GtkPaned*> (gobj ()));
  }

  auto
  Paned::property_position () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "position");
  }

  auto
  Paned::property_position () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "position");
  }

  auto
  Paned::property_position_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "position-set");
  }

  auto
  Paned::property_position_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "position-set");
  }

  auto
  Paned::property_min_position () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "min-position");
  }

  auto
  Paned::property_max_position () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-position");
  }

  auto
  Paned::property_wide_handle () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "wide-handle");
  }

  auto
  Paned::property_wide_handle () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "wide-handle");
  }

  auto
  Paned::property_resize_start_child () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "resize-start-child");
  }

  auto
  Paned::property_resize_start_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "resize-start-child");
  }

  auto
  Paned::property_resize_end_child () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "resize-end-child");
  }

  auto
  Paned::property_resize_end_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "resize-end-child");
  }

  auto
  Paned::property_shrink_start_child () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "shrink-start-child");
  }

  auto
  Paned::property_shrink_start_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "shrink-start-child");
  }

  auto
  Paned::property_shrink_end_child () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "shrink-end-child");
  }

  auto
  Paned::property_shrink_end_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "shrink-end-child");
  }

  auto
  Paned::property_start_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "start-child");
  }

  auto
  Paned::property_start_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "start-child");
  }

  auto
  Paned::property_end_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "end-child");
  }

  auto
  Paned::property_end_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "end-child");
  }

} // namespace Gtk
