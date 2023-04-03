// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/columnviewcolumn.hxx>
#include <libmm/gtk/columnviewcolumn_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/columnview.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkColumnViewColumn* object, bool take_copy) -> Glib::RefPtr<Gtk::ColumnViewColumn>
  {
    return Glib::make_refptr_for_instance<Gtk::ColumnViewColumn> (
        dynamic_cast<Gtk::ColumnViewColumn*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColumnViewColumn_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ColumnViewColumn_Class::class_init_function;

      register_derived_type (gtk_column_view_column_get_type ());
    }

    return *this;
  }

  auto
  ColumnViewColumn_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ColumnViewColumn_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ColumnViewColumn ((GtkColumnViewColumn*) object);
  }

  auto
  ColumnViewColumn::gobj_copy () -> GtkColumnViewColumn*
  {
    reference ();
    return gobj ();
  }

  ColumnViewColumn::ColumnViewColumn (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ColumnViewColumn::ColumnViewColumn (GtkColumnViewColumn* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ColumnViewColumn::ColumnViewColumn (ColumnViewColumn&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ColumnViewColumn::operator= (ColumnViewColumn&& src) noexcept -> ColumnViewColumn&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  ColumnViewColumn::~ColumnViewColumn () noexcept {}

  ColumnViewColumn::CppClassType ColumnViewColumn::columnviewcolumn_class_;

  auto
  ColumnViewColumn::get_type () -> GType
  {
    return columnviewcolumn_class_.init ().get_type ();
  }

  auto
  ColumnViewColumn::get_base_type () -> GType
  {
    return gtk_column_view_column_get_type ();
  }

  ColumnViewColumn::ColumnViewColumn (
      const Glib::ustring& title,
      const Glib::RefPtr<ListItemFactory>& factory)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (columnviewcolumn_class_.init (),
                                           "title",
                                           title.c_str (),
                                           "factory",
                                           Glib::unwrap (factory),
                                           nullptr))
  {
  }

  auto
  ColumnViewColumn::create (const Glib::ustring& title,
                            const Glib::RefPtr<ListItemFactory>& factory) -> Glib::RefPtr<ColumnViewColumn>
  {
    return Glib::make_refptr_for_instance<ColumnViewColumn> (
        new ColumnViewColumn (title, factory));
  }

  auto
  ColumnViewColumn::get_column_view () -> ColumnView*
  {
    return Glib::wrap (gtk_column_view_column_get_column_view (gobj ()));
  }

  auto
  ColumnViewColumn::get_column_view () const -> const ColumnView*
  {
    return const_cast<ColumnViewColumn*> (this)->get_column_view ();
  }

  auto
  ColumnViewColumn::set_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_column_view_column_set_factory (gobj (), Glib::unwrap (factory));
  }

  auto
  ColumnViewColumn::get_factory () -> Glib::RefPtr<ListItemFactory>
  {
    auto retvalue = Glib::wrap (gtk_column_view_column_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_factory () const -> Glib::RefPtr<const ListItemFactory>
  {
    return const_cast<ColumnViewColumn*> (this)->get_factory ();
  }

  auto
  ColumnViewColumn::set_title (const Glib::ustring& title) -> void
  {
    gtk_column_view_column_set_title (gobj (), title.c_str ());
  }

  auto
  ColumnViewColumn::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_column_view_column_get_title (
            const_cast<GtkColumnViewColumn*> (gobj ())));
  }

  auto
  ColumnViewColumn::set_sorter (const Glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_column_view_column_set_sorter (gobj (), Glib::unwrap (sorter));
  }

  auto
  ColumnViewColumn::get_sorter () -> Glib::RefPtr<Sorter>
  {
    auto retvalue = Glib::wrap (gtk_column_view_column_get_sorter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_sorter () const -> Glib::RefPtr<const Sorter>
  {
    return const_cast<ColumnViewColumn*> (this)->get_sorter ();
  }

  auto
  ColumnViewColumn::set_visible (bool visible) -> void
  {
    gtk_column_view_column_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  ColumnViewColumn::get_visible () const -> bool
  {
    return gtk_column_view_column_get_visible (
        const_cast<GtkColumnViewColumn*> (gobj ()));
  }

  auto
  ColumnViewColumn::set_header_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_column_view_column_set_header_menu (gobj (), Glib::unwrap (model));
  }

  auto
  ColumnViewColumn::get_header_menu () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue =
        Glib::wrap (gtk_column_view_column_get_header_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_header_menu () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<ColumnViewColumn*> (this)->get_header_menu ();
  }

  auto
  ColumnViewColumn::set_fixed_width (int fixed_width) -> void
  {
    gtk_column_view_column_set_fixed_width (gobj (), fixed_width);
  }

  auto
  ColumnViewColumn::get_fixed_width () const -> int
  {
    return gtk_column_view_column_get_fixed_width (
        const_cast<GtkColumnViewColumn*> (gobj ()));
  }

  auto
  ColumnViewColumn::set_resizable (bool resizable) -> void
  {
    gtk_column_view_column_set_resizable (gobj (),
                                          static_cast<int> (resizable));
  }

  auto
  ColumnViewColumn::get_resizable () const -> bool
  {
    return gtk_column_view_column_get_resizable (
        const_cast<GtkColumnViewColumn*> (gobj ()));
  }

  auto
  ColumnViewColumn::set_expand (bool expand) -> void
  {
    gtk_column_view_column_set_expand (gobj (), static_cast<int> (expand));
  }

  auto
  ColumnViewColumn::get_expand () const -> bool
  {
    return gtk_column_view_column_get_expand (
        const_cast<GtkColumnViewColumn*> (gobj ()));
  }

  auto
  ColumnViewColumn::set_id (const Glib::ustring& id) -> void
  {
    gtk_column_view_column_set_id (gobj (), id.c_str ());
  }

  auto
  ColumnViewColumn::get_id () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_column_view_column_get_id (
            const_cast<GtkColumnViewColumn*> (gobj ())));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ColumnView*>::value,
      "Type ColumnView* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewColumn::property_column_view () const -> Glib::PropertyProxy_ReadOnly<ColumnView*>
  {
    return Glib::PropertyProxy_ReadOnly<ColumnView*> (this, "column-view");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ListItemFactory>>::value,
      "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewColumn::property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  ColumnViewColumn::property_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  auto
  ColumnViewColumn::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ColumnViewColumn::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Sorter>>::value,
      "Type Glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewColumn::property_sorter () -> Glib::PropertyProxy<Glib::RefPtr<Sorter>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  ColumnViewColumn::property_sorter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  ColumnViewColumn::property_visible () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  ColumnViewColumn::property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewColumn::property_header_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "header-menu");
  }

  auto
  ColumnViewColumn::property_header_menu () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "header-menu");
  }

  auto
  ColumnViewColumn::property_resizable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "resizable");
  }

  auto
  ColumnViewColumn::property_resizable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "resizable");
  }

  auto
  ColumnViewColumn::property_expand () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "expand");
  }

  auto
  ColumnViewColumn::property_expand () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "expand");
  }

  auto
  ColumnViewColumn::property_fixed_width () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "fixed-width");
  }

  auto
  ColumnViewColumn::property_fixed_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "fixed-width");
  }

  auto
  ColumnViewColumn::property_id () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "id");
  }

  auto
  ColumnViewColumn::property_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "id");
  }

} // namespace Gtk
