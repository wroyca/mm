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
  wrap (AdwComboRow* object, bool take_copy) -> adw::combo_row*
  {
    return dynamic_cast<adw::combo_row*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  combo_row_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &combo_row_class::class_init_function;

      register_derived_type (adw_combo_row_get_type ());
    }

    return *this;
  }

  auto
  combo_row_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  combo_row_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new combo_row ((AdwComboRow*) (o)));
  }

  combo_row::combo_row (const glib::ConstructParams& construct_params)
    : adw::action_row (construct_params)
  {
  }

  combo_row::combo_row (AdwComboRow* castitem)
    : adw::action_row ((AdwActionRow*) (castitem))
  {
  }

  combo_row::combo_row (combo_row&& src) noexcept
    : adw::action_row (std::move (src))
  {
  }

  auto
  combo_row::operator= (combo_row&& src) noexcept -> combo_row&
  {
    adw::action_row::operator= (std::move (src));
    return *this;
  }

  combo_row::~combo_row () noexcept
  {
    destroy_ ();
  }

  combo_row::CppClassType combo_row::comborow_class_;

  auto
  combo_row::get_type () -> GType
  {
    return comborow_class_.init ().get_type ();
  }

  auto
  combo_row::get_base_type () -> GType
  {
    return adw_combo_row_get_type ();
  }

  combo_row::combo_row ()
    : glib::ObjectBase (nullptr),
      adw::action_row (glib::ConstructParams (comborow_class_.init ()))
  {
  }

  auto
  combo_row::get_expression () const -> glib::RefPtr<gtk::Expression<glib::ustring>>
  {
    auto retvalue = glib::wrap<glib::ustring> (
        adw_combo_row_get_expression (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  combo_row::get_factory () const -> glib::RefPtr<gtk::ListItemFactory>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  combo_row::get_list_factory () const -> glib::RefPtr<gtk::ListItemFactory>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_list_factory (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  combo_row::get_model () const -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (
        adw_combo_row_get_model (const_cast<AdwComboRow*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  combo_row::get_selected () const -> guint
  {
    return adw_combo_row_get_selected (const_cast<AdwComboRow*> (gobj ()));
  }

  auto
  combo_row::get_selected_item () const -> glib::RefPtr<glib::ObjectBase>
  {
    auto retvalue = glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (adw_combo_row_get_selected_item (
            const_cast<AdwComboRow*> (gobj ())))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  combo_row::get_use_subtitle () const -> bool
  {
    return adw_combo_row_get_use_subtitle (const_cast<AdwComboRow*> (gobj ()));
  }

  auto
  combo_row::set_factory (const glib::RefPtr<gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_factory (gobj (), glib::unwrap (factory));
  }

  auto
  combo_row::set_list_factory (const glib::RefPtr<gtk::ListItemFactory>& factory) -> void
  {
    adw_combo_row_set_list_factory (gobj (), glib::unwrap (factory));
  }

  auto
  combo_row::set_use_subtitle (bool use_subtitle) const -> void
  {
    adw_combo_row_set_use_subtitle (const_cast<AdwComboRow*> (gobj ()),
                                    static_cast<int> (use_subtitle));
  }

  auto
  combo_row::set_selected (guint position) const -> void
  {
    adw_combo_row_set_selected (const_cast<AdwComboRow*> (gobj ()), position);
  }

  auto
  combo_row::set_expression (
      const glib::RefPtr<gtk::Expression<glib::ustring>>& expression) -> void
  {
    adw_combo_row_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  combo_row::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    adw_combo_row_set_model (gobj (), glib::unwrap (model));
  }

  auto
  combo_row::property_expression () -> glib::PropertyProxy<glib::RefPtr<gtk::Expression<glib::ustring>>>
  {
    return {this, "expression"};
  }

  auto
  combo_row::property_expression () const -> glib::PropertyProxy_ReadOnly<
      glib::RefPtr<gtk::Expression<glib::ustring>>>
  {
    return {this, "expression"};
  }

  auto
  combo_row::property_selected_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return {this, "selected-item"};
  }

  auto
  combo_row::property_selected () -> glib::PropertyProxy<guint>
  {
    return {this, "selected"};
  }

  auto
  combo_row::property_selected () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "selected"};
  }

  auto
  combo_row::property_factory () -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>
  {
    return {this, "factory"};
  }

  auto
  combo_row::property_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>
  {
    return {this, "factory"};
  }

  auto
  combo_row::property_list_factory () -> glib::PropertyProxy<glib::RefPtr<gtk::ListItemFactory>>
  {
    return {this, "list-factory"};
  }

  auto
  combo_row::property_list_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::ListItemFactory>>
  {
    return {this, "list-factory"};
  }

  auto
  combo_row::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return {this, "model"};
  }

  auto
  combo_row::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return {this, "model"};
  }

  auto
  combo_row::property_use_subtitle () -> glib::PropertyProxy<bool>
  {
    return {this, "use-subtitle"};
  }

  auto
  combo_row::property_use_subtitle () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-subtitle"};
  }

} // namespace adw
