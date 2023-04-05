// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/dropdown.hxx>
#include <libmm/gtk/dropdown_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/stringlist.hxx>

namespace gtk
{

  DropDown::DropDown (const std::vector<glib::ustring>& strings)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (dropdown_class_.init (),
                                          "model",
                                          StringList::create (strings)->gobj (),
                                          nullptr))
  {
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkDropDown* object, bool take_copy) -> gtk::DropDown*
  {
    return dynamic_cast<gtk::DropDown*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  DropDown_Class::init () -> const glib::Class&
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
  DropDown_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new DropDown ((GtkDropDown*) (o)));
  }

  DropDown::DropDown (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  DropDown::DropDown (GtkDropDown* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  DropDown::DropDown (DropDown&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  DropDown::operator= (DropDown&& src) noexcept -> DropDown&
  {
    gtk::Widget::operator= (std::move (src));
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

  DropDown::DropDown (const glib::RefPtr<gio::ListModel>& model,
                      const glib::RefPtr<Expression<glib::ustring>>& expression)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (
          dropdown_class_.init (),
          "model",
          glib::unwrap (model),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  DropDown::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_drop_down_set_model (gobj (), glib::unwrap (model));
  }

  auto
  DropDown::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_drop_down_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_model () const -> glib::RefPtr<const gio::ListModel>
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
  DropDown::get_selected_item () -> glib::RefPtr<glib::ObjectBase>
  {
    auto retvalue = glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (gtk_drop_down_get_selected_item (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_selected_item () const -> glib::RefPtr<const glib::ObjectBase>
  {
    return const_cast<DropDown*> (this)->get_selected_item ();
  }

  auto
  DropDown::set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_drop_down_set_factory (gobj (), glib::unwrap (factory));
  }

  auto
  DropDown::get_factory () -> glib::RefPtr<ListItemFactory>
  {
    auto retvalue = glib::wrap (gtk_drop_down_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_factory () const -> glib::RefPtr<const ListItemFactory>
  {
    return const_cast<DropDown*> (this)->get_factory ();
  }

  auto
  DropDown::set_list_factory (const glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_drop_down_set_list_factory (gobj (), glib::unwrap (factory));
  }

  auto
  DropDown::get_list_factory () -> glib::RefPtr<ListItemFactory>
  {
    auto retvalue = glib::wrap (gtk_drop_down_get_list_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_list_factory () const -> glib::RefPtr<const ListItemFactory>
  {
    return const_cast<DropDown*> (this)->get_list_factory ();
  }

  auto
  DropDown::set_expression (
      const glib::RefPtr<Expression<glib::ustring>>& expression) -> void
  {
    gtk_drop_down_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  DropDown::get_expression () -> glib::RefPtr<Expression<glib::ustring>>
  {
    auto retvalue =
        glib::wrap<glib::ustring> (gtk_drop_down_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropDown::get_expression () const -> glib::RefPtr<const Expression<glib::ustring>>
  {
    auto retvalue = glib::wrap<glib::ustring> (
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ListItemFactory>>::value,
      "Type glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropDown::property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  DropDown::property_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ListItemFactory>>::value,
      "Type glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropDown::property_list_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<ListItemFactory>> (this,
                                                               "list-factory");
  }

  auto
  DropDown::property_list_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>> (
        this,
        "list-factory");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropDown::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  DropDown::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  DropDown::property_selected () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "selected");
  }

  auto
  DropDown::property_selected () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "selected");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropDown::property_selected_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "selected-item");
  }

  auto
  DropDown::property_enable_search () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-search");
  }

  auto
  DropDown::property_enable_search () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-search");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Expression<glib::ustring>>>::value,
      "Type glib::RefPtr<Expression<glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropDown::property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>> (
        this,
        "expression");
  }

  auto
  DropDown::property_expression () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy_ReadOnly<
        glib::RefPtr<Expression<glib::ustring>>> (this, "expression");
  }

  auto
  DropDown::property_show_arrow () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-arrow");
  }

  auto
  DropDown::property_show_arrow () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-arrow");
  }

} // namespace gtk
