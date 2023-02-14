

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
  wrap (GtkListBoxRow* object, const bool take_copy) -> Gtk::ListBoxRow*
  {
    return dynamic_cast<Gtk::ListBoxRow*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListBoxRow_Class::init () -> const Class&
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
    return manage (new ListBoxRow ((GtkListBoxRow*) o));
  }

  ListBoxRow::ListBoxRow (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  ListBoxRow::ListBoxRow (GtkListBoxRow* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  ListBoxRow::ListBoxRow (ListBoxRow&& src) noexcept
    : Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  ListBoxRow::operator= (ListBoxRow&& src) noexcept -> ListBoxRow&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (listboxrow_class_.init ()))
  {
  }

  auto
  ListBoxRow::set_child (Widget& child) -> void
  {
    gtk_list_box_row_set_child (gobj (), child.gobj ());
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
    gtk_list_box_row_set_header (gobj (), header.gobj ());
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
  ListBoxRow::set_selectable (const bool selectable) -> void
  {
    gtk_list_box_row_set_selectable (gobj (), selectable);
  }

  auto
  ListBoxRow::get_selectable () const -> bool
  {
    return gtk_list_box_row_get_selectable (
        const_cast<GtkListBoxRow*> (gobj ()));
  }

  auto
  ListBoxRow::set_activatable (const bool activatable) -> void
  {
    gtk_list_box_row_set_activatable (gobj (), activatable);
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
    return {this, "selectable"};
  }

  auto
  ListBoxRow::property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "selectable"};
  }

  auto
  ListBoxRow::property_activatable () -> Glib::PropertyProxy<bool>
  {
    return {this, "activatable"};
  }

  auto
  ListBoxRow::property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "activatable"};
  }

  auto
  ListBoxRow::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  ListBoxRow::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
