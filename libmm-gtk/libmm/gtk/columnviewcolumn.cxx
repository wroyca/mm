// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/columnviewcolumn.hxx>
#include <libmm/gtk/columnviewcolumn_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/columnview.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkColumnViewColumn* object, bool take_copy) -> glib::RefPtr<gtk::ColumnViewColumn>
  {
    return glib::make_refptr_for_instance<gtk::ColumnViewColumn> (
        dynamic_cast<gtk::ColumnViewColumn*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ColumnViewColumn_Class::init () -> const glib::Class&
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
  ColumnViewColumn_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ColumnViewColumn::ColumnViewColumn (GtkColumnViewColumn* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ColumnViewColumn::ColumnViewColumn (ColumnViewColumn&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ColumnViewColumn::operator= (ColumnViewColumn&& src) noexcept -> ColumnViewColumn&
  {
    glib::Object::operator= (std::move (src));
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
      const glib::ustring& title,
      const glib::RefPtr<ListItemFactory>& factory)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (columnviewcolumn_class_.init (),
                                           "title",
                                           title.c_str (),
                                           "factory",
                                           glib::unwrap (factory),
                                           nullptr))
  {
  }

  auto
  ColumnViewColumn::create (const glib::ustring& title,
                            const glib::RefPtr<ListItemFactory>& factory) -> glib::RefPtr<ColumnViewColumn>
  {
    return glib::make_refptr_for_instance<ColumnViewColumn> (
        new ColumnViewColumn (title, factory));
  }

  auto
  ColumnViewColumn::get_column_view () -> ColumnView*
  {
    return glib::wrap (gtk_column_view_column_get_column_view (gobj ()));
  }

  auto
  ColumnViewColumn::get_column_view () const -> const ColumnView*
  {
    return const_cast<ColumnViewColumn*> (this)->get_column_view ();
  }

  auto
  ColumnViewColumn::set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_column_view_column_set_factory (gobj (), glib::unwrap (factory));
  }

  auto
  ColumnViewColumn::get_factory () -> glib::RefPtr<ListItemFactory>
  {
    auto retvalue = glib::wrap (gtk_column_view_column_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_factory () const -> glib::RefPtr<const ListItemFactory>
  {
    return const_cast<ColumnViewColumn*> (this)->get_factory ();
  }

  auto
  ColumnViewColumn::set_title (const glib::ustring& title) -> void
  {
    gtk_column_view_column_set_title (gobj (), title.c_str ());
  }

  auto
  ColumnViewColumn::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_column_view_column_get_title (
            const_cast<GtkColumnViewColumn*> (gobj ())));
  }

  auto
  ColumnViewColumn::set_sorter (const glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_column_view_column_set_sorter (gobj (), glib::unwrap (sorter));
  }

  auto
  ColumnViewColumn::get_sorter () -> glib::RefPtr<Sorter>
  {
    auto retvalue = glib::wrap (gtk_column_view_column_get_sorter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_sorter () const -> glib::RefPtr<const Sorter>
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
  ColumnViewColumn::set_header_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_column_view_column_set_header_menu (gobj (), glib::unwrap (model));
  }

  auto
  ColumnViewColumn::get_header_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue =
        glib::wrap (gtk_column_view_column_get_header_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewColumn::get_header_menu () const -> glib::RefPtr<const gio::MenuModel>
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
  ColumnViewColumn::set_id (const glib::ustring& id) -> void
  {
    gtk_column_view_column_set_id (gobj (), id.c_str ());
  }

  auto
  ColumnViewColumn::get_id () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_column_view_column_get_id (
            const_cast<GtkColumnViewColumn*> (gobj ())));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ColumnView*>::value,
      "Type ColumnView* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewColumn::property_column_view () const -> glib::PropertyProxy_ReadOnly<ColumnView*>
  {
    return glib::PropertyProxy_ReadOnly<ColumnView*> (this, "column-view");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ListItemFactory>>::value,
      "Type glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewColumn::property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  ColumnViewColumn::property_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  auto
  ColumnViewColumn::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  ColumnViewColumn::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Sorter>>::value,
      "Type glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewColumn::property_sorter () -> glib::PropertyProxy<glib::RefPtr<Sorter>>
  {
    return glib::PropertyProxy<glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  ColumnViewColumn::property_sorter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  ColumnViewColumn::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  ColumnViewColumn::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewColumn::property_header_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "header-menu");
  }

  auto
  ColumnViewColumn::property_header_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "header-menu");
  }

  auto
  ColumnViewColumn::property_resizable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "resizable");
  }

  auto
  ColumnViewColumn::property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "resizable");
  }

  auto
  ColumnViewColumn::property_expand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "expand");
  }

  auto
  ColumnViewColumn::property_expand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "expand");
  }

  auto
  ColumnViewColumn::property_fixed_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "fixed-width");
  }

  auto
  ColumnViewColumn::property_fixed_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "fixed-width");
  }

  auto
  ColumnViewColumn::property_id () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "id");
  }

  auto
  ColumnViewColumn::property_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "id");
  }

} // namespace gtk
