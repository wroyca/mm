// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/listboxrow.hxx>
#include <libmm-gtk/listboxrow_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  ListBoxRow::unset_header () -> void
  {
    gtk_list_box_row_set_header (gobj (), nullptr);
  }

  auto
  ListBoxRow::unset_child () -> void
  {
    gtk_list_box_row_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkListBoxRow* object, bool take_copy) -> Gtk::ListBoxRow*
  {
    return dynamic_cast<Gtk::ListBoxRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListBoxRow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListBoxRow_Class::class_init_function;

      register_derived_type (gtk_list_box_row_get_type ());

      Actionable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ListBoxRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListBoxRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ListBoxRow ((GtkListBoxRow*) (o)));
  }

  ListBoxRow::ListBoxRow (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ListBoxRow::ListBoxRow (GtkListBoxRow* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ListBoxRow::ListBoxRow (ListBoxRow&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  ListBoxRow::operator= (ListBoxRow&& src) noexcept -> ListBoxRow&
  {
    Gtk::Widget::operator= (std::move (src));
    Actionable::operator= (std::move (src));
    return *this;
  }

  ListBoxRow::~ListBoxRow () noexcept
  {
    destroy_ ();
  }

  ListBoxRow::CppClassType ListBoxRow::listboxrow_class_;

  auto
  ListBoxRow::get_type () -> GType
  {
    return listboxrow_class_.init ().get_type ();
  }

  auto
  ListBoxRow::get_base_type () -> GType
  {
    return gtk_list_box_row_get_type ();
  }

  ListBoxRow::ListBoxRow ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (listboxrow_class_.init ()))
  {
  }

  auto
  ListBoxRow::set_child (Widget& child) -> void
  {
    gtk_list_box_row_set_child (gobj (), (child).gobj ());
  }

  auto
  ListBoxRow::get_child () -> Widget*
  {
    return Glib::wrap (gtk_list_box_row_get_child (gobj ()));
  }

  auto
  ListBoxRow::get_child () const -> const Widget*
  {
    return const_cast<ListBoxRow*> (this)->get_child ();
  }

  auto
  ListBoxRow::set_header (Widget& header) -> void
  {
    gtk_list_box_row_set_header (gobj (), (header).gobj ());
  }

  auto
  ListBoxRow::get_header () -> Widget*
  {
    return Glib::wrap (gtk_list_box_row_get_header (gobj ()));
  }

  auto
  ListBoxRow::get_header () const -> const Widget*
  {
    return const_cast<ListBoxRow*> (this)->get_header ();
  }

  auto
  ListBoxRow::get_index () const -> int
  {
    return gtk_list_box_row_get_index (const_cast<GtkListBoxRow*> (gobj ()));
  }

  auto
  ListBoxRow::changed () -> void
  {
    gtk_list_box_row_changed (gobj ());
  }

  auto
  ListBoxRow::is_selected () const -> bool
  {
    return gtk_list_box_row_is_selected (const_cast<GtkListBoxRow*> (gobj ()));
  }

  auto
  ListBoxRow::set_selectable (bool selectable) -> void
  {
    gtk_list_box_row_set_selectable (gobj (), static_cast<int> (selectable));
  }

  auto
  ListBoxRow::get_selectable () const -> bool
  {
    return gtk_list_box_row_get_selectable (
        const_cast<GtkListBoxRow*> (gobj ()));
  }

  auto
  ListBoxRow::set_activatable (bool activatable) -> void
  {
    gtk_list_box_row_set_activatable (gobj (), static_cast<int> (activatable));
  }

  auto
  ListBoxRow::get_activatable () const -> bool
  {
    return gtk_list_box_row_get_activatable (
        const_cast<GtkListBoxRow*> (gobj ()));
  }

  auto
  ListBoxRow::property_selectable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "selectable");
  }

  auto
  ListBoxRow::property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "selectable");
  }

  auto
  ListBoxRow::property_activatable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activatable");
  }

  auto
  ListBoxRow::property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "activatable");
  }

  auto
  ListBoxRow::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  ListBoxRow::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace Gtk
