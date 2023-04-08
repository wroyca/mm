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
  wrap (AdwSplitButton* object, bool take_copy) -> adw::split_button*
  {
    return dynamic_cast<adw::split_button*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  split_button_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_split_button_get_type ();
    }

    return *this;
  }

  auto
  split_button_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new split_button ((AdwSplitButton*) (o)));
  }

  split_button::split_button (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  split_button::split_button (AdwSplitButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  split_button::split_button (split_button&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Actionable (std::move (src))
  {
  }

  auto
  split_button::operator= (split_button&& src) noexcept -> split_button&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Actionable::operator= (std::move (src));
    return *this;
  }

  split_button::~split_button () noexcept
  {
    destroy_ ();
  }

  split_button::CppClassType split_button::splitbutton_class_;

  auto
  split_button::get_type () -> GType
  {
    return splitbutton_class_.init ().get_type ();
  }

  auto
  split_button::get_base_type () -> GType
  {
    return adw_split_button_get_type ();
  }

  split_button::split_button ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (splitbutton_class_.init ()))
  {
  }

  auto
  split_button::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_split_button_get_child (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_direction () const -> gtk::ArrowType
  {
    return static_cast<gtk::ArrowType> (
        adw_split_button_get_direction (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_dropdown_tooltip () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_dropdown_tooltip (
            const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_icon_name (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_split_button_get_label (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_menu_model () const -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (adw_split_button_get_menu_model (
        const_cast<AdwSplitButton*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  split_button::get_popover () const -> gtk::Popover*
  {
    return glib::wrap (
        adw_split_button_get_popover (const_cast<AdwSplitButton*> (gobj ())));
  }

  auto
  split_button::get_use_underline () const -> bool
  {
    return adw_split_button_get_use_underline (
        const_cast<AdwSplitButton*> (gobj ()));
  }

  auto
  split_button::popdown () -> void
  {
    adw_split_button_popdown (gobj ());
  }

  auto
  split_button::popup () -> void
  {
    adw_split_button_popup (gobj ());
  }

  auto
  split_button::set_child (gtk::Widget* child) -> void
  {
    adw_split_button_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  split_button::set_direction (gtk::ArrowType direction) -> void
  {
    adw_split_button_set_direction (gobj (),
                                    static_cast<GtkArrowType> (direction));
  }

  auto
  split_button::set_dropdown_tooltip (const glib::ustring& dropdown_tooltip) -> void
  {
    adw_split_button_set_dropdown_tooltip (gobj (), dropdown_tooltip.c_str ());
  }

  auto
  split_button::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_split_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  split_button::set_label (const glib::ustring& label) -> void
  {
    adw_split_button_set_label (gobj (), label.c_str ());
  }

  auto
  split_button::set_menu_model (const glib::RefPtr<gio::MenuModel>& menu_model) -> void
  {
    adw_split_button_set_menu_model (gobj (), glib::unwrap (menu_model));
  }

  auto
  split_button::set_popover (gtk::Popover* popover) -> void
  {
    adw_split_button_set_popover (gobj (),
                                  (GtkPopover*) glib::unwrap (popover));
  }

  auto
  split_button::set_use_underline (bool use_underline) -> void
  {
    adw_split_button_set_use_underline (gobj (),
                                        static_cast<int> (use_underline));
  }

  auto
  split_button::signal_activate () -> glib::SignalProxy<void ()>
  {
    return {this, &SplitButton_signal_activate_info};
  }

  auto
  split_button::signal_clicked () -> glib::SignalProxy<void ()>
  {
    return {this, &SplitButton_signal_clicked_info};
  }

  auto
  split_button::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  split_button::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::ArrowType>::value,
      "Type gtk::ArrowType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  split_button::property_direction () -> glib::PropertyProxy<gtk::ArrowType>
  {
    return {this, "direction"};
  }

  auto
  split_button::property_direction () const -> glib::PropertyProxy_ReadOnly<gtk::ArrowType>
  {
    return {this, "direction"};
  }

  auto
  split_button::property_dropdown_tooltip () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "dropdown-tooltip"};
  }

  auto
  split_button::property_dropdown_tooltip () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {
      this,
                                                        "dropdown-tooltip"
    };
  }

  auto
  split_button::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  split_button::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  split_button::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  split_button::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  split_button::property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return {
      this,
                                                              "menu-model"
    };
  }

  auto
  split_button::property_menu_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  auto
  split_button::property_popover () -> glib::PropertyProxy<gtk::Popover*>
  {
    return {this, "popover"};
  }

  auto
  split_button::property_popover () const -> glib::PropertyProxy_ReadOnly<gtk::Popover*>
  {
    return {this, "popover"};
  }

  auto
  split_button::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  split_button::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
