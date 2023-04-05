// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/splitbutton.hxx>
#include <libmm/adw/splitbutton_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo SplitButton_signal_activate_info = {
      "activate",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SplitButton_signal_clicked_info = {
      "clicked",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwSplitButton* object, bool take_copy) -> adw::SplitButton*
  {
    return dynamic_cast<adw::SplitButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  SplitButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_split_button_get_type ();
    }

    return *this;
  }

  auto
  SplitButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new SplitButton ((AdwSplitButton*) (o)));
  }

  SplitButton::SplitButton (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  SplitButton::SplitButton (AdwSplitButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SplitButton::SplitButton (SplitButton&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Actionable (std::move (src))
  {
  }

  auto
  SplitButton::operator= (SplitButton&& src) noexcept -> SplitButton&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Actionable::operator= (std::move (src));
    return *this;
  }

  SplitButton::~SplitButton () noexcept
  {
    destroy_ ();
  }

  SplitButton::CppClassType SplitButton::splitbutton_class_;

  auto
  SplitButton::get_type () -> GType
  {
    return splitbutton_class_.init ().get_type ();
  }

  auto
  SplitButton::get_base_type () -> GType
  {
    return adw_split_button_get_type ();
  }

  SplitButton::SplitButton ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (splitbutton_class_.init ()))
  {
  }

  auto
  SplitButton::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_split_button_get_child (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_direction () const -> gtk::ArrowType
  {
    return static_cast<gtk::ArrowType> (
        adw_split_button_get_direction (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_dropdown_tooltip () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_dropdown_tooltip (
            const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_icon_name (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_label (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_menu_model () const -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (adw_split_button_get_menu_model (
        const_cast<AdwSplitButton*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SplitButton::get_popover () const -> gtk::Popover*
  {
    return glib::wrap (
        adw_split_button_get_popover (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_use_underline () const -> bool
  {
    return adw_split_button_get_use_underline (
        const_cast<AdwSplitButton*> (gobj ()));
  }

  auto
  SplitButton::popdown () -> void
  {
    adw_split_button_popdown (gobj ());
  }

  auto
  SplitButton::popup () -> void
  {
    adw_split_button_popup (gobj ());
  }

  auto
  SplitButton::set_child (gtk::Widget* child) -> void
  {
    adw_split_button_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  SplitButton::set_direction (gtk::ArrowType direction) -> void
  {
    adw_split_button_set_direction (gobj (),
                                    static_cast<GtkArrowType> (direction));
  }

  auto
  SplitButton::set_dropdown_tooltip (const glib::ustring& dropdown_tooltip) -> void
  {
    adw_split_button_set_dropdown_tooltip (gobj (), dropdown_tooltip.c_str ());
  }

  auto
  SplitButton::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_split_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  SplitButton::set_label (const glib::ustring& label) -> void
  {
    adw_split_button_set_label (gobj (), label.c_str ());
  }

  auto
  SplitButton::set_menu_model (const glib::RefPtr<gio::MenuModel>& menu_model) -> void
  {
    adw_split_button_set_menu_model (gobj (), glib::unwrap (menu_model));
  }

  auto
  SplitButton::set_popover (gtk::Popover* popover) -> void
  {
    adw_split_button_set_popover (gobj (),
                                  (GtkPopover*) glib::unwrap (popover));
  }

  auto
  SplitButton::set_use_underline (bool use_underline) -> void
  {
    adw_split_button_set_use_underline (gobj (),
                                        static_cast<int> (use_underline));
  }

  auto
  SplitButton::signal_activate () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &SplitButton_signal_activate_info);
  }

  auto
  SplitButton::signal_clicked () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &SplitButton_signal_clicked_info);
  }

  auto
  SplitButton::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  SplitButton::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::ArrowType>::value,
      "Type gtk::ArrowType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SplitButton::property_direction () -> glib::PropertyProxy<gtk::ArrowType>
  {
    return glib::PropertyProxy<gtk::ArrowType> (this, "direction");
  }

  auto
  SplitButton::property_direction () const -> glib::PropertyProxy_ReadOnly<gtk::ArrowType>
  {
    return glib::PropertyProxy_ReadOnly<gtk::ArrowType> (this, "direction");
  }

  auto
  SplitButton::property_dropdown_tooltip () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "dropdown-tooltip");
  }

  auto
  SplitButton::property_dropdown_tooltip () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "dropdown-tooltip");
  }

  auto
  SplitButton::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  SplitButton::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  SplitButton::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "label");
  }

  auto
  SplitButton::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "label");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SplitButton::property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  SplitButton::property_menu_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "menu-model");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::Popover*>::value,
      "Type gtk::Popover* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SplitButton::property_popover () -> glib::PropertyProxy<gtk::Popover*>
  {
    return glib::PropertyProxy<gtk::Popover*> (this, "popover");
  }

  auto
  SplitButton::property_popover () const -> glib::PropertyProxy_ReadOnly<gtk::Popover*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Popover*> (this, "popover");
  }

  auto
  SplitButton::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  SplitButton::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace adw
