// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/dropdown.hxx>
#include <libmm/gtk/dropdown_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/stringlist.hxx>

namespace Gtk
{

  DropDown::DropDown (const std::vector<Glib::ustring>& strings)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (dropdown_class_.init (),
                                          "model",
                                          StringList::create (strings)->gobj (),
                                          nullptr))
  {
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkDropDown* object, bool take_copy) -> Gtk::DropDown*
  {
    return dynamic_cast<Gtk::DropDown*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  DropDown_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DropDown_Class::class_init_function;

      gtype_ = gtk_drop_down_get_type ();
    }

    return *this;
  }

  auto
  DropDown_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DropDown_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new DropDown ((GtkDropDown*) (o)));
  }

  DropDown::DropDown (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  DropDown::DropDown (GtkDropDown* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  DropDown::DropDown (DropDown&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  DropDown::operator= (DropDown&& src) noexcept -> DropDown&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  DropDown::~DropDown () noexcept
  {
    destroy_ ();
  }

  DropDown::CppClassType DropDown::dropdown_class_;

  auto
  DropDown::get_type () -> GType
  {
    return dropdown_class_.init ().get_type ();
  }

  auto
  DropDown::get_base_type () -> GType
  {
    return gtk_drop_down_get_type ();
  }

  DropDown::DropDown (const Glib::RefPtr<Gio::ListModel>& model,
                      const Glib::RefPtr<Expression<Glib::ustring>>& expression)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (
          dropdown_class_.init (),
          "model",
          Glib::unwrap (model),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  DropDown::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_drop_down_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  DropDown::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_drop_down_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_model () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<DropDown*> (this)->get_model ();
  }

  auto
  DropDown::set_selected (guint position) -> void
  {
    gtk_drop_down_set_selected (gobj (), position);
  }

  auto
  DropDown::get_selected () const -> guint
  {
    return gtk_drop_down_get_selected (const_cast<GtkDropDown*> (gobj ()));
  }

  auto
  DropDown::get_selected_item () -> Glib::RefPtr<Glib::ObjectBase>
  {
    auto retvalue = Glib::make_refptr_for_instance<Glib::ObjectBase> (
        Glib::wrap_auto (G_OBJECT (gtk_drop_down_get_selected_item (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_selected_item () const -> Glib::RefPtr<const Glib::ObjectBase>
  {
    return const_cast<DropDown*> (this)->get_selected_item ();
  }

  auto
  DropDown::set_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_drop_down_set_factory (gobj (), Glib::unwrap (factory));
  }

  auto
  DropDown::get_factory () -> Glib::RefPtr<ListItemFactory>
  {
    auto retvalue = Glib::wrap (gtk_drop_down_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_factory () const -> Glib::RefPtr<const ListItemFactory>
  {
    return const_cast<DropDown*> (this)->get_factory ();
  }

  auto
  DropDown::set_list_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_drop_down_set_list_factory (gobj (), Glib::unwrap (factory));
  }

  auto
  DropDown::get_list_factory () -> Glib::RefPtr<ListItemFactory>
  {
    auto retvalue = Glib::wrap (gtk_drop_down_get_list_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_list_factory () const -> Glib::RefPtr<const ListItemFactory>
  {
    return const_cast<DropDown*> (this)->get_list_factory ();
  }

  auto
  DropDown::set_expression (
      const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> void
  {
    gtk_drop_down_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  DropDown::get_expression () -> Glib::RefPtr<Expression<Glib::ustring>>
  {
    auto retvalue =
        Glib::wrap<Glib::ustring> (gtk_drop_down_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_expression () const -> Glib::RefPtr<const Expression<Glib::ustring>>
  {
    auto retvalue = Glib::wrap<Glib::ustring> (
        gtk_drop_down_get_expression (const_cast<GtkDropDown*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::set_enable_search (bool enable_search) -> void
  {
    gtk_drop_down_set_enable_search (gobj (), static_cast<int> (enable_search));
  }

  auto
  DropDown::get_enable_search () const -> bool
  {
    return gtk_drop_down_get_enable_search (const_cast<GtkDropDown*> (gobj ()));
  }

  auto
  DropDown::set_show_arrow (bool show_arrow) -> void
  {
    gtk_drop_down_set_show_arrow (gobj (), static_cast<int> (show_arrow));
  }

  auto
  DropDown::set_show_arrow () const -> bool
  {
    return gtk_drop_down_get_show_arrow (const_cast<GtkDropDown*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ListItemFactory>>::value,
      "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropDown::property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  DropDown::property_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ListItemFactory>>::value,
      "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropDown::property_list_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>> (this,
                                                               "list-factory");
  }

  auto
  DropDown::property_list_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>> (
        this,
        "list-factory");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropDown::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  DropDown::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  DropDown::property_selected () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "selected");
  }

  auto
  DropDown::property_selected () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "selected");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropDown::property_selected_item () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>> (
        this,
        "selected-item");
  }

  auto
  DropDown::property_enable_search () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-search");
  }

  auto
  DropDown::property_enable_search () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-search");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Expression<Glib::ustring>>>::value,
      "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropDown::property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>> (
        this,
        "expression");
  }

  auto
  DropDown::property_expression () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Expression<Glib::ustring>>> (this, "expression");
  }

  auto
  DropDown::property_show_arrow () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-arrow");
  }

  auto
  DropDown::property_show_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-arrow");
  }

} // namespace Gtk
