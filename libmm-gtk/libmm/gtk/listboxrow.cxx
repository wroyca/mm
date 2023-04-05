// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/listboxrow.hxx>
#include <libmm/gtk/listboxrow_p.hxx>

#include <gtk/gtk.h>

namespace gtk
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

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkListBoxRow* object, bool take_copy) -> gtk::ListBoxRow*
  {
    return dynamic_cast<gtk::ListBoxRow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ListBoxRow_Class::init () -> const glib::Class&
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
  ListBoxRow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ListBoxRow ((GtkListBoxRow*) (o)));
  }

  ListBoxRow::ListBoxRow (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ListBoxRow::ListBoxRow (GtkListBoxRow* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ListBoxRow::ListBoxRow (ListBoxRow&& src) noexcept
    : gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  ListBoxRow::operator= (ListBoxRow&& src) noexcept -> ListBoxRow&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (listboxrow_class_.init ()))
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
    return glib::wrap (gtk_list_box_row_get_child (gobj ()));
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
    return glib::wrap (gtk_list_box_row_get_header (gobj ()));
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
  ListBoxRow::property_selectable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "selectable");
  }

  auto
  ListBoxRow::property_selectable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "selectable");
  }

  auto
  ListBoxRow::property_activatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activatable");
  }

  auto
  ListBoxRow::property_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activatable");
  }

  auto
  ListBoxRow::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  ListBoxRow::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
