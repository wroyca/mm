// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/comborow.hxx>
#include <libmm/adw/comborow_p.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwComboRow* object, bool take_copy) -> Adw::ComboRow*
  {
    return dynamic_cast<Adw::ComboRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ComboRow_Class::init () -> const Glib::Class&
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
  ComboRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ComboRow ((AdwComboRow*) (o)));
  }

  ComboRow::ComboRow (const Glib::ConstructParams& construct_params)
    : Adw::ActionRow (construct_params)
  {
  }

  ComboRow::ComboRow (AdwComboRow* castitem)
    : Adw::ActionRow ((AdwActionRow*) (castitem))
  {
  }

  ComboRow::ComboRow (ComboRow&& src) noexcept
    : Adw::ActionRow (std::move (src))
  {
  }

  auto
  ComboRow::operator= (ComboRow&& src) noexcept -> ComboRow&
  {
    Adw::ActionRow::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Adw::ActionRow (Glib::ConstructParams (comborow_class_.init ()))
  {
  }

  auto
  ComboRow::get_expression () const -> Glib::RefPtr<Gtk::Expression<Glib::ustring>>
  {
    auto retvalue = Glib::wrap<Glib::ustring> (
        adw_combo_row_get_expression (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_factory () const -> Glib::RefPtr<Gtk::ListItemFactory>
  {
    auto retvalue = Glib::wrap (
        adw_combo_row_get_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_list_factory () const -> Glib::RefPtr<Gtk::ListItemFactory>
  {
    auto retvalue = Glib::wrap (
        adw_combo_row_get_list_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboRow::get_model () const -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (
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
  ComboRow::get_selected_item () const -> Glib::RefPtr<Glib::ObjectBase>
  {
    auto retvalue = Glib::make_refptr_for_instance<Glib::ObjectBase> (
        Glib::wrap_auto (G_OBJECT (adw_combo_row_get_selected_item (
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
  ComboRow::set_factory (const Glib::RefPtr<Gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_factory (gobj (), Glib::unwrap (factory));
  }

  auto
  ComboRow::set_list_factory (const Glib::RefPtr<Gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_list_factory (gobj (), Glib::unwrap (factory));
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
      const Glib::RefPtr<Gtk::Expression<Glib::ustring>>& expression) -> void
  {
    adw_combo_row_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  ComboRow::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    adw_combo_row_set_model (gobj (), Glib::unwrap (model));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::Expression<Glib::ustring>>>::value,
      "Type Glib::RefPtr<Gtk::Expression<Glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ComboRow::property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Gtk::Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gtk::Expression<Glib::ustring>>> (
        this,
        "expression");
  }

  auto
  ComboRow::property_expression () const -> Glib::PropertyProxy_ReadOnly<
      Glib::RefPtr<Gtk::Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Gtk::Expression<Glib::ustring>>> (this, "expression");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ComboRow::property_selected_item () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>> (
        this,
        "selected-item");
  }

  auto
  ComboRow::property_selected () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "selected");
  }

  auto
  ComboRow::property_selected () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "selected");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::ListItemFactory>>::value,
      "Type Glib::RefPtr<Gtk::ListItemFactory> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ComboRow::property_factory () -> Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>> (this,
                                                                    "factory");
  }

  auto
  ComboRow::property_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>> (
        this,
        "factory");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::ListItemFactory>>::value,
      "Type Glib::RefPtr<Gtk::ListItemFactory> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ComboRow::property_list_factory () -> Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gtk::ListItemFactory>> (
        this,
        "list-factory");
  }

  auto
  ComboRow::property_list_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::ListItemFactory>> (
        this,
        "list-factory");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ComboRow::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  ComboRow::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  ComboRow::property_use_subtitle () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-subtitle");
  }

  auto
  ComboRow::property_use_subtitle () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-subtitle");
  }

} // namespace Adw
