// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/comborow.hxx>
#include <libmm/adw/comborow_p.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwComboRow* object, bool take_copy) -> adw::ComboRow*
  {
    return dynamic_cast<adw::ComboRow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ComboRow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ComboRow_Class::class_init_function;

      register_derived_type (adw_combo_row_get_type ());
    }

    return *this;
  }

  auto
  ComboRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ComboRow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ComboRow ((AdwComboRow*) (o)));
  }

  ComboRow::ComboRow (const glib::ConstructParams& construct_params)
    : adw::action_row (construct_params)
  {
  }

  ComboRow::ComboRow (AdwComboRow* castitem)
    : adw::action_row ((AdwActionRow*) (castitem))
  {
  }

  ComboRow::ComboRow (ComboRow&& src) noexcept
    : adw::action_row (std::move (src))
  {
  }

  auto
  ComboRow::operator= (ComboRow&& src) noexcept -> ComboRow&
  {
    adw::action_row::operator= (std::move (src));
    return *this;
  }

  ComboRow::~ComboRow () noexcept
  {
    destroy_ ();
  }

  ComboRow::CppClassType ComboRow::comborow_class_;

  auto
  ComboRow::get_type () -> GType
  {
    return comborow_class_.init ().get_type ();
  }

  auto
  ComboRow::get_base_type () -> GType
  {
    return adw_combo_row_get_type ();
  }

  ComboRow::ComboRow ()
    : glib::ObjectBase (nullptr),
      adw::action_row (glib::ConstructParams (comborow_class_.init ()))
  {
  }

  auto
  ComboRow::get_expression () const -> glib::RefPtr<gtk::Expression<glib::ustring>>
  {
    auto retvalue = glib::wrap<glib::ustring> (
        adw_combo_row_get_expression (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_factory () const -> glib::RefPtr<gtk::ListItemFactory>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_list_factory () const -> glib::RefPtr<gtk::ListItemFactory>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_list_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_model () const -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_model (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_selected () const -> guint
  {
    return adw_combo_row_get_selected (const_cast<AdwComboRow*> (gobj ()));
  }

  auto
  ComboRow::get_selected_item () const -> glib::RefPtr<glib::ObjectBase>
  {
    auto retvalue = glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (adw_combo_row_get_selected_item (
            const_cast<AdwComboRow*> (gobj ())))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_use_subtitle () const -> bool
  {
    return adw_combo_row_get_use_subtitle (const_cast<AdwComboRow*> (gobj ()));
  }

  auto
  ComboRow::set_factory (const glib::RefPtr<gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_factory (gobj (), glib::unwrap (factory));
  }

  auto
  ComboRow::set_list_factory (const glib::RefPtr<gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_list_factory (gobj (), glib::unwrap (factory));
  }

  auto
  ComboRow::set_use_subtitle (bool use_subtitle) const -> void
  {
    adw_combo_row_set_use_subtitle (const_cast<AdwComboRow*> (gobj ()),
                                    static_cast<int> (use_subtitle));
  }

  auto
  ComboRow::set_selected (guint position) const -> void
  {
    adw_combo_row_set_selected (const_cast<AdwComboRow*> (gobj ()), position);
  }

  auto
  ComboRow::set_expression (
      const glib::RefPtr<gtk::Expression<glib::ustring>>& expression) -> void
  {
    adw_combo_row_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  ComboRow::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    adw_combo_row_set_model (gobj (), glib::unwrap (model));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::Expression<glib::ustring>>>::value,
      "Type glib::RefPtr<gtk::Expression<glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboRow::property_expression () -> glib::PropertyProxy<glib::RefPtr<gtk::Expression<glib::ustring>>>
  {
    return glib::PropertyProxy<glib::RefPtr<gtk::Expression<glib::ustring>>> (
        this,
        "expression");
  }

  auto
  ComboRow::property_expression () const -> glib::PropertyProxy_ReadOnly<
      glib::RefPtr<gtk::Expression<glib::ustring>>>
  {
    return glib::PropertyProxy_ReadOnly<
        glib::RefPtr<gtk::Expression<glib::ustring>>> (this, "expression");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboRow::property_selected_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "selected-item");
  }

  auto
  ComboRow::property_selected () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "selected");
  }

  auto
  ComboRow::property_selected () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "selected");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::ListItemFactory>>::value,
      "Type glib::RefPtr<gtk::ListItemFactory> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboRow::property_factory () -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>> (this,
                                                                    "factory");
  }

  auto
  ComboRow::property_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>> (
        this,
        "factory");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::ListItemFactory>>::value,
      "Type glib::RefPtr<gtk::ListItemFactory> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboRow::property_list_factory () -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>> (
        this,
        "list-factory");
  }

  auto
  ComboRow::property_list_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>> (
        this,
        "list-factory");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboRow::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  ComboRow::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  ComboRow::property_use_subtitle () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-subtitle");
  }

  auto
  ComboRow::property_use_subtitle () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-subtitle");
  }

} // namespace adw
