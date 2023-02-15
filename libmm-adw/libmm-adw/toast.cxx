// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/toast.hxx>
#include <libmm-adw/toast_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo Toast_signal_button_clicked_info = {
      "button-clicked",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo Toast_signal_dismissed_info = {
      "dismissed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Adw::ToastPriority>::value_type () -> GType
{
  return adw_toast_priority_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwToast* object, bool take_copy) -> Glib::RefPtr<Adw::Toast>
  {
    return Glib::make_refptr_for_instance<Adw::Toast> (
        dynamic_cast<Adw::Toast*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  Toast_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_toast_get_type ();
    }

    return *this;
  }

  auto
  Toast_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Toast ((AdwToast*) object);
  }

  auto
  Toast::gobj_copy () -> AdwToast*
  {
    reference ();
    return gobj ();
  }

  Toast::Toast (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Toast::Toast (AdwToast* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Toast::Toast (Toast&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Toast::operator= (Toast&& src) noexcept -> Toast&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (toast_class_.init ()))
  {
  }

  Toast::Toast (const Glib::ustring& title)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (toast_class_.init (),
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
  Toast::get_action_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_action_name (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_button_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_button_label (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::get_custom_title () const -> Gtk::Widget*
  {
    return Glib::wrap (
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
  Toast::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_toast_get_title (const_cast<AdwToast*> (gobj ())));
  }

  auto
  Toast::set_action_name (const Glib::ustring& action_name) -> void
  {
    adw_toast_set_action_name (gobj (), action_name.c_str ());
  }

  auto
  Toast::set_button_label (const Glib::ustring& button_label) -> void
  {
    adw_toast_set_button_label (gobj (), button_label.c_str ());
  }

  auto
  Toast::set_custom_title (Gtk::Widget* widget) -> void
  {
    adw_toast_set_custom_title (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  Toast::set_detailed_action_name (const Glib::ustring& detailed_action_name) -> void
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
  Toast::set_title (const Glib::ustring& title) -> void
  {
    adw_toast_set_title (gobj (), title.c_str ());
  }

  auto
  Toast::get_action_target_value () const -> Glib::VariantBase
  {
    return Glib::wrap (
        adw_toast_get_action_target_value (const_cast<AdwToast*> (gobj ())),
        true);
  }

  auto
  Toast::set_action_target_value (const Glib::VariantBase& target_value) -> void
  {
    adw_toast_set_action_target_value (
        gobj (),
        const_cast<GVariant*> ((target_value).gobj ()));
  }

  auto
  Toast::signal_button_clicked () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Toast_signal_button_clicked_info);
  }

  auto
  Toast::signal_dismissed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Toast_signal_dismissed_info);
  }

  auto
  Toast::property_action_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "action-name");
  }

  auto
  Toast::property_action_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "action-name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
      "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Toast::property_action_target () -> Glib::PropertyProxy<Glib::VariantBase>
  {
    return Glib::PropertyProxy<Glib::VariantBase> (this, "action-target");
  }

  auto
  Toast::property_action_target () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::VariantBase> (this,
                                                            "action-target");
  }

  auto
  Toast::property_button_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "button-label");
  }

  auto
  Toast::property_button_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "button-label");
  }

  auto
  Toast::property_custom_title () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "custom-title");
  }

  auto
  Toast::property_custom_title () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "custom-title");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ToastPriority>::value,
      "Type ToastPriority cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Toast::property_priority () -> Glib::PropertyProxy<ToastPriority>
  {
    return Glib::PropertyProxy<ToastPriority> (this, "priority");
  }

  auto
  Toast::property_priority () const -> Glib::PropertyProxy_ReadOnly<ToastPriority>
  {
    return Glib::PropertyProxy_ReadOnly<ToastPriority> (this, "priority");
  }

  auto
  Toast::property_timeout () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "timeout");
  }

  auto
  Toast::property_timeout () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "timeout");
  }

  auto
  Toast::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  Toast::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

} // namespace Adw
