// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/appchooserbutton.hxx>
  #include <libmm/gtk/appchooserbutton_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

}

namespace
{

  static const glib::SignalProxyInfo AppChooserButton_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  AppChooserButton_signal_custom_item_activated_callback (
      GtkAppChooserButton* self,
      const gchar* p0,
      void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<AppChooserButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      AppChooserButton_signal_custom_item_activated_info = {
          "custom-item-activated",
          (GCallback) &AppChooserButton_signal_custom_item_activated_callback,
          (GCallback) &AppChooserButton_signal_custom_item_activated_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkAppChooserButton* object, bool take_copy) -> gtk::AppChooserButton*
  {
    return dynamic_cast<gtk::AppChooserButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  AppChooserButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppChooserButton_Class::class_init_function;

      register_derived_type (gtk_app_chooser_button_get_type ());

      AppChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  AppChooserButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AppChooserButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new AppChooserButton ((GtkAppChooserButton*) (o)));
  }

  AppChooserButton::AppChooserButton (
      const glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  AppChooserButton::AppChooserButton (GtkAppChooserButton* castitem)
    : Widget ((GtkWidget*) (castitem))
  {
  }

  AppChooserButton::AppChooserButton (AppChooserButton&& src) noexcept
    : Widget (std::move (src)),
      AppChooser (std::move (src))
  {
  }

  auto
  AppChooserButton::operator= (AppChooserButton&& src) noexcept -> AppChooserButton&
  {
    Widget::operator= (std::move (src));
    AppChooser::operator= (std::move (src));
    return *this;
  }

  AppChooserButton::~AppChooserButton () noexcept
  {
    destroy_ ();
  }

  AppChooserButton::CppClassType AppChooserButton::appchooserbutton_class_;

  auto
  AppChooserButton::get_type () -> GType
  {
    return appchooserbutton_class_.init ().get_type ();
  }

  auto
  AppChooserButton::get_base_type () -> GType
  {
    return gtk_app_chooser_button_get_type ();
  }

  AppChooserButton::AppChooserButton (const glib::ustring& content_type)
    : glib::ObjectBase (nullptr),
      Widget (glib::ConstructParams (appchooserbutton_class_.init (),
                                     "content_type",
                                     content_type.c_str (),
                                     nullptr))
  {
  }

  auto
  AppChooserButton::append_separator () -> void
  {
    gtk_app_chooser_button_append_separator (gobj ());
  }

  auto
  AppChooserButton::append_custom_item (const glib::ustring& name,
                                        const glib::ustring& label,
                                        const glib::RefPtr<gio::Icon>& icon) -> void
  {
    gtk_app_chooser_button_append_custom_item (
        gobj (),
        name.c_str (),
        label.c_str (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)));
  }

  auto
  AppChooserButton::set_active_custom_item (const glib::ustring& name) -> void
  {
    gtk_app_chooser_button_set_active_custom_item (gobj (), name.c_str ());
  }

  auto
  AppChooserButton::set_show_dialog_item (bool setting) -> void
  {
    gtk_app_chooser_button_set_show_dialog_item (gobj (),
                                                 static_cast<int> (setting));
  }

  auto
  AppChooserButton::get_show_dialog_item () const -> bool
  {
    return gtk_app_chooser_button_get_show_dialog_item (
        const_cast<GtkAppChooserButton*> (gobj ()));
  }

  auto
  AppChooserButton::set_heading (const glib::ustring& heading) -> void
  {
    gtk_app_chooser_button_set_heading (gobj (), heading.c_str ());
  }

  auto
  AppChooserButton::get_heading () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_app_chooser_button_get_heading (
            const_cast<GtkAppChooserButton*> (gobj ())));
  }

  auto
  AppChooserButton::set_show_default_item (bool setting) -> void
  {
    gtk_app_chooser_button_set_show_default_item (gobj (),
                                                  static_cast<int> (setting));
  }

  auto
  AppChooserButton::get_show_default_item () const -> bool
  {
    return gtk_app_chooser_button_get_show_default_item (
        const_cast<GtkAppChooserButton*> (gobj ()));
  }

  auto
  AppChooserButton::set_modal (bool modal) -> void
  {
    gtk_app_chooser_button_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  AppChooserButton::get_modal () const -> bool
  {
    return gtk_app_chooser_button_get_modal (
        const_cast<GtkAppChooserButton*> (gobj ()));
  }

  auto
  AppChooserButton::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &AppChooserButton_signal_changed_info);
  }

  auto
  AppChooserButton::signal_custom_item_activated (
      const glib::ustring& custom_item_name) -> glib::SignalProxyDetailed<void (const glib::ustring&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&)> (
        this,
        &AppChooserButton_signal_custom_item_activated_info,
        custom_item_name);
  }

  auto
  AppChooserButton::property_show_dialog_item () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-dialog-item");
  }

  auto
  AppChooserButton::property_show_dialog_item () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-dialog-item");
  }

  auto
  AppChooserButton::property_heading () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "heading");
  }

  auto
  AppChooserButton::property_heading () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "heading");
  }

  auto
  AppChooserButton::property_show_default_item () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-default-item");
  }

  auto
  AppChooserButton::property_show_default_item () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-default-item");
  }

  auto
  AppChooserButton::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  AppChooserButton::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

} // namespace gtk

#endif
