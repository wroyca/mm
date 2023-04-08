// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/toast.hxx>
#include <libmm/adw/toast_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo Toast_signal_button_clicked_info = {
      "button-clicked",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Toast_signal_dismissed_info = {
      "dismissed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<adw::ToastPriority>::value_type () -> GType
{
  return adw_toast_priority_get_type ();
}

namespace glib
{

  auto
  wrap (AdwToast* object, bool take_copy) -> glib::RefPtr<adw::Toast>
  {
    return glib::make_refptr_for_instance<adw::Toast> (
        dynamic_cast<adw::Toast*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  Toast_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_toast_get_type ();
    }

    return *this;
  }

  auto
  Toast_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Toast ((AdwToast*) object);
  }

  auto
  Toast::gobj_copy () -> AdwToast*
  {
    reference ();
    return gobj ();
  }

  Toast::Toast (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Toast::Toast (AdwToast* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Toast::Toast (Toast&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Toast::operator= (Toast&& src) noexcept -> Toast&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Toast::~Toast () noexcept {}

  Toast::CppClassType Toast::toast_class_;

  auto
  Toast::get_type () -> GType
  {
    return toast_class_.init ().get_type ();
  }

  auto
  Toast::get_base_type () -> GType
  {
    return adw_toast_get_type ();
  }

  Toast::Toast ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (toast_class_.init ()))
  {
  }

  Toast::Toast (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (toast_class_.init (),
                                           "title",
                                           title.c_str (),
                                           nullptr))
  {
  }

  auto
  Toast::dismiss () -> void
  {
    adw_toast_dismiss (gobj ());
  }

  auto
  Toast::get_action_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_action_name (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_button_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_button_label (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_custom_title () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_toast_get_custom_title (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_priority () const -> ToastPriority
  {
    return static_cast<ToastPriority> (
        adw_toast_get_priority (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_timeout () const -> guint
  {
    return adw_toast_get_timeout (const_cast<AdwToast*> (gobj ()));
  }

  auto
  Toast::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_title (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::set_action_name (const glib::ustring& action_name) -> void
  {
    adw_toast_set_action_name (gobj (), action_name.c_str ());
  }

  auto
  Toast::set_button_label (const glib::ustring& button_label) -> void
  {
    adw_toast_set_button_label (gobj (), button_label.c_str ());
  }

  auto
  Toast::set_custom_title (gtk::Widget* widget) -> void
  {
    adw_toast_set_custom_title (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  Toast::set_detailed_action_name (const glib::ustring& detailed_action_name) -> void
  {
    adw_toast_set_detailed_action_name (gobj (), detailed_action_name.c_str ());
  }

  auto
  Toast::set_priority (ToastPriority priority) -> void
  {
    adw_toast_set_priority (gobj (), static_cast<AdwToastPriority> (priority));
  }

  auto
  Toast::set_timeout (guint timeout) -> void
  {
    adw_toast_set_timeout (gobj (), timeout);
  }

  auto
  Toast::set_title (const glib::ustring& title) -> void
  {
    adw_toast_set_title (gobj (), title.c_str ());
  }

  auto
  Toast::get_action_target_value () const -> glib::VariantBase
  {
    return glib::wrap (
        adw_toast_get_action_target_value (const_cast<AdwToast*> (gobj ())),
        true);
  }

  auto
  Toast::set_action_target_value (const glib::VariantBase& target_value) -> void
  {
    adw_toast_set_action_target_value (
        gobj (),
        const_cast<GVariant*> ((target_value).gobj ()));
  }

  auto
  Toast::signal_button_clicked () -> glib::SignalProxy<void ()>
  {
    return {this, &Toast_signal_button_clicked_info};
  }

  auto
  Toast::signal_dismissed () -> glib::SignalProxy<void ()>
  {
    return {this, &Toast_signal_dismissed_info};
  }

  auto
  Toast::property_action_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "action-name"};
  }

  auto
  Toast::property_action_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "action-name"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::VariantBase>::value,
      "Type glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Toast::property_action_target () -> glib::PropertyProxy<glib::VariantBase>
  {
    return {this, "action-target"};
  }

  auto
  Toast::property_action_target () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>
  {
    return {
      this,
                                                            "action-target"
    };
  }

  auto
  Toast::property_button_label () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "button-label"};
  }

  auto
  Toast::property_button_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "button-label"};
  }

  auto
  Toast::property_custom_title () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "custom-title"};
  }

  auto
  Toast::property_custom_title () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "custom-title"};
  }

  auto
  Toast::property_priority () -> glib::PropertyProxy<ToastPriority>
  {
    return {this, "priority"};
  }

  auto
  Toast::property_priority () const -> glib::PropertyProxy_ReadOnly<ToastPriority>
  {
    return {this, "priority"};
  }

  auto
  Toast::property_timeout () -> glib::PropertyProxy<guint>
  {
    return {this, "timeout"};
  }

  auto
  Toast::property_timeout () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "timeout"};
  }

  auto
  Toast::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  Toast::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

} // namespace adw
