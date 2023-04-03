// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/splitbutton.hxx>
#include <libmm/adw/splitbutton_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo SplitButton_signal_activate_info = {
      "activate",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo SplitButton_signal_clicked_info = {
      "clicked",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwSplitButton* object, bool take_copy) -> Adw::SplitButton*
  {
    return dynamic_cast<Adw::SplitButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  SplitButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_split_button_get_type ();
    }

    return *this;
  }

  auto
  SplitButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new SplitButton ((AdwSplitButton*) (o)));
  }

  SplitButton::SplitButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  SplitButton::SplitButton (AdwSplitButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SplitButton::SplitButton (SplitButton&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Actionable (std::move (src))
  {
  }

  auto
  SplitButton::operator= (SplitButton&& src) noexcept -> SplitButton&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Actionable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (splitbutton_class_.init ()))
  {
  }

  auto
  SplitButton::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_split_button_get_child (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_direction () const -> Gtk::ArrowType
  {
    return static_cast<Gtk::ArrowType> (
        adw_split_button_get_direction (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_dropdown_tooltip () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_dropdown_tooltip (
            const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_icon_name (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_label (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  SplitButton::get_menu_model () const -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (adw_split_button_get_menu_model (
        const_cast<AdwSplitButton*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SplitButton::get_popover () const -> Gtk::Popover*
  {
    return Glib::wrap (
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
  SplitButton::set_child (Gtk::Widget* child) -> void
  {
    adw_split_button_set_child (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  SplitButton::set_direction (Gtk::ArrowType direction) -> void
  {
    adw_split_button_set_direction (gobj (),
                                    static_cast<GtkArrowType> (direction));
  }

  auto
  SplitButton::set_dropdown_tooltip (const Glib::ustring& dropdown_tooltip) -> void
  {
    adw_split_button_set_dropdown_tooltip (gobj (), dropdown_tooltip.c_str ());
  }

  auto
  SplitButton::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_split_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  SplitButton::set_label (const Glib::ustring& label) -> void
  {
    adw_split_button_set_label (gobj (), label.c_str ());
  }

  auto
  SplitButton::set_menu_model (const Glib::RefPtr<Gio::MenuModel>& menu_model) -> void
  {
    adw_split_button_set_menu_model (gobj (), Glib::unwrap (menu_model));
  }

  auto
  SplitButton::set_popover (Gtk::Popover* popover) -> void
  {
    adw_split_button_set_popover (gobj (),
                                  (GtkPopover*) Glib::unwrap (popover));
  }

  auto
  SplitButton::set_use_underline (bool use_underline) -> void
  {
    adw_split_button_set_use_underline (gobj (),
                                        static_cast<int> (use_underline));
  }

  auto
  SplitButton::signal_activate () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &SplitButton_signal_activate_info);
  }

  auto
  SplitButton::signal_clicked () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &SplitButton_signal_clicked_info);
  }

  auto
  SplitButton::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  SplitButton::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::ArrowType>::value,
      "Type Gtk::ArrowType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SplitButton::property_direction () -> Glib::PropertyProxy<Gtk::ArrowType>
  {
    return Glib::PropertyProxy<Gtk::ArrowType> (this, "direction");
  }

  auto
  SplitButton::property_direction () const -> Glib::PropertyProxy_ReadOnly<Gtk::ArrowType>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::ArrowType> (this, "direction");
  }

  auto
  SplitButton::property_dropdown_tooltip () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "dropdown-tooltip");
  }

  auto
  SplitButton::property_dropdown_tooltip () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "dropdown-tooltip");
  }

  auto
  SplitButton::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  SplitButton::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  SplitButton::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  SplitButton::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SplitButton::property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  SplitButton::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "menu-model");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::Popover*>::value,
      "Type Gtk::Popover* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SplitButton::property_popover () -> Glib::PropertyProxy<Gtk::Popover*>
  {
    return Glib::PropertyProxy<Gtk::Popover*> (this, "popover");
  }

  auto
  SplitButton::property_popover () const -> Glib::PropertyProxy_ReadOnly<Gtk::Popover*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Popover*> (this, "popover");
  }

  auto
  SplitButton::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  SplitButton::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace Adw
