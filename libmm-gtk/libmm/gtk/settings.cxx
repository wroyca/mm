// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/settings.hxx>
#include <libmm/gtk/settings_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSettings* object, bool take_copy) -> glib::RefPtr<gtk::Settings>
  {
    return glib::make_refptr_for_instance<gtk::Settings> (
        dynamic_cast<gtk::Settings*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Settings_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Settings_Class::class_init_function;

      register_derived_type (gtk_settings_get_type ());

      StyleProvider::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Settings_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Settings_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Settings ((GtkSettings*) object);
  }

  auto
  Settings::gobj_copy () -> GtkSettings*
  {
    reference ();
    return gobj ();
  }

  Settings::Settings (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Settings::Settings (GtkSettings* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Settings::Settings (Settings&& src) noexcept
    : glib::Object (std::move (src)),
      StyleProvider (std::move (src))
  {
  }

  auto
  Settings::operator= (Settings&& src) noexcept -> Settings&
  {
    glib::Object::operator= (std::move (src));
    StyleProvider::operator= (std::move (src));
    return *this;
  }

  Settings::~Settings () noexcept {}

  Settings::CppClassType Settings::settings_class_;

  auto
  Settings::get_type () -> GType
  {
    return settings_class_.init ().get_type ();
  }

  auto
  Settings::get_base_type () -> GType
  {
    return gtk_settings_get_type ();
  }

  auto
  Settings::get_default () -> glib::RefPtr<Settings>
  {
    auto retvalue = glib::wrap (gtk_settings_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Settings::get_for_display (const glib::RefPtr<gdk::Display>& display) -> glib::RefPtr<Settings>
  {
    auto retvalue =
        glib::wrap (gtk_settings_get_for_display (glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Settings::reset_property (const glib::ustring& name) -> void
  {
    gtk_settings_reset_property (gobj (), name.c_str ());
  }

  auto
  Settings::property_gtk_double_click_time () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-double-click-time");
  }

  auto
  Settings::property_gtk_double_click_time () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-double-click-time");
  }

  auto
  Settings::property_gtk_double_click_distance () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-double-click-distance");
  }

  auto
  Settings::property_gtk_double_click_distance () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this,
                                              "gtk-double-click-distance");
  }

  auto
  Settings::property_gtk_cursor_blink () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-cursor-blink");
  }

  auto
  Settings::property_gtk_cursor_blink () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-cursor-blink");
  }

  auto
  Settings::property_gtk_cursor_blink_time () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-cursor-blink-time");
  }

  auto
  Settings::property_gtk_cursor_blink_time () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-blink-time");
  }

  auto
  Settings::property_gtk_cursor_blink_timeout () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-cursor-blink-timeout");
  }

  auto
  Settings::property_gtk_cursor_blink_timeout () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-blink-timeout");
  }

  auto
  Settings::property_gtk_split_cursor () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-split-cursor");
  }

  auto
  Settings::property_gtk_split_cursor () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-split-cursor");
  }

  auto
  Settings::property_gtk_cursor_aspect_ratio () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "gtk-cursor-aspect-ratio");
  }

  auto
  Settings::property_gtk_cursor_aspect_ratio () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this,
                                                 "gtk-cursor-aspect-ratio");
  }

  auto
  Settings::property_gtk_theme_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-theme-name");
  }

  auto
  Settings::property_gtk_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "gtk-theme-name");
  }

  auto
  Settings::property_gtk_dnd_drag_threshold () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-dnd-drag-threshold");
  }

  auto
  Settings::property_gtk_dnd_drag_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-dnd-drag-threshold");
  }

  auto
  Settings::property_gtk_font_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-font-name");
  }

  auto
  Settings::property_gtk_font_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "gtk-font-name");
  }

  auto
  Settings::property_gtk_xft_antialias () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-xft-antialias");
  }

  auto
  Settings::property_gtk_xft_antialias () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-antialias");
  }

  auto
  Settings::property_gtk_xft_hinting () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-xft-hinting");
  }

  auto
  Settings::property_gtk_xft_hinting () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-hinting");
  }

  auto
  Settings::property_gtk_xft_hintstyle () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-xft-hintstyle");
  }

  auto
  Settings::property_gtk_xft_hintstyle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "gtk-xft-hintstyle");
  }

  auto
  Settings::property_gtk_xft_rgba () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-xft-rgba");
  }

  auto
  Settings::property_gtk_xft_rgba () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "gtk-xft-rgba");
  }

  auto
  Settings::property_gtk_xft_dpi () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-xft-dpi");
  }

  auto
  Settings::property_gtk_xft_dpi () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-dpi");
  }

  auto
  Settings::property_gtk_hint_font_metrics () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-hint-font-metrics");
  }

  auto
  Settings::property_gtk_hint_font_metrics () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-hint-font-metrics");
  }

  auto
  Settings::property_gtk_cursor_theme_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-cursor-theme-name");
  }

  auto
  Settings::property_gtk_cursor_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-cursor-theme-name");
  }

  auto
  Settings::property_gtk_cursor_theme_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-cursor-theme-size");
  }

  auto
  Settings::property_gtk_cursor_theme_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-theme-size");
  }

  auto
  Settings::property_gtk_alternative_button_order () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-alternative-button-order");
  }

  auto
  Settings::property_gtk_alternative_button_order () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-alternative-button-order");
  }

  auto
  Settings::property_gtk_alternative_sort_arrows () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-alternative-sort-arrows");
  }

  auto
  Settings::property_gtk_alternative_sort_arrows () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-alternative-sort-arrows");
  }

  auto
  Settings::property_gtk_enable_animations () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-enable-animations");
  }

  auto
  Settings::property_gtk_enable_animations () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-animations");
  }

  auto
  Settings::property_gtk_error_bell () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-error-bell");
  }

  auto
  Settings::property_gtk_error_bell () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-error-bell");
  }

  auto
  Settings::property_gtk_print_backends () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-print-backends");
  }

  auto
  Settings::property_gtk_print_backends () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "gtk-print-backends");
  }

  auto
  Settings::property_gtk_print_preview_command () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this,
                                               "gtk-print-preview-command");
  }

  auto
  Settings::property_gtk_print_preview_command () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-print-preview-command");
  }

  auto
  Settings::property_gtk_enable_accels () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-enable-accels");
  }

  auto
  Settings::property_gtk_enable_accels () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-accels");
  }

  auto
  Settings::property_gtk_im_module () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-im-module");
  }

  auto
  Settings::property_gtk_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "gtk-im-module");
  }

  auto
  Settings::property_gtk_recent_files_max_age () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-recent-files-max-age");
  }

  auto
  Settings::property_gtk_recent_files_max_age () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-recent-files-max-age");
  }

  auto
  Settings::property_gtk_fontconfig_timestamp () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "gtk-fontconfig-timestamp");
  }

  auto
  Settings::property_gtk_fontconfig_timestamp () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "gtk-fontconfig-timestamp");
  }

  auto
  Settings::property_gtk_sound_theme_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-sound-theme-name");
  }

  auto
  Settings::property_gtk_sound_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "gtk-sound-theme-name");
  }

  auto
  Settings::property_gtk_enable_input_feedback_sounds () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-enable-input-feedback-sounds");
  }

  auto
  Settings::property_gtk_enable_input_feedback_sounds () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-enable-input-feedback-sounds");
  }

  auto
  Settings::property_gtk_enable_event_sounds () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-enable-event-sounds");
  }

  auto
  Settings::property_gtk_enable_event_sounds () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-event-sounds");
  }

  auto
  Settings::property_gtk_application_prefer_dark_theme () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this,
                                      "gtk-application-prefer-dark-theme");
  }

  auto
  Settings::property_gtk_application_prefer_dark_theme () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-application-prefer-dark-theme");
  }

  auto
  Settings::property_gtk_shell_shows_app_menu () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-shell-shows-app-menu");
  }

  auto
  Settings::property_gtk_shell_shows_app_menu () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-shell-shows-app-menu");
  }

  auto
  Settings::property_gtk_shell_shows_menubar () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-shell-shows-menubar");
  }

  auto
  Settings::property_gtk_shell_shows_menubar () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-shell-shows-menubar");
  }

  auto
  Settings::property_gtk_shell_shows_desktop () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-shell-shows-desktop");
  }

  auto
  Settings::property_gtk_shell_shows_desktop () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-shell-shows-desktop");
  }

  auto
  Settings::property_gtk_enable_primary_paste () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-enable-primary-paste");
  }

  auto
  Settings::property_gtk_enable_primary_paste () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-enable-primary-paste");
  }

  auto
  Settings::property_gtk_label_select_on_focus () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-label-select-on-focus");
  }

  auto
  Settings::property_gtk_label_select_on_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-label-select-on-focus");
  }

  auto
  Settings::property_gtk_entry_password_hint_timeout () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "gtk-entry-password-hint-timeout");
  }

  auto
  Settings::property_gtk_entry_password_hint_timeout () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (
        this,
        "gtk-entry-password-hint-timeout");
  }

  auto
  Settings::property_gtk_entry_select_on_focus () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-entry-select-on-focus");
  }

  auto
  Settings::property_gtk_entry_select_on_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-entry-select-on-focus");
  }

  auto
  Settings::property_gtk_icon_theme_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-icon-theme-name");
  }

  auto
  Settings::property_gtk_icon_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "gtk-icon-theme-name");
  }

  auto
  Settings::property_gtk_recent_files_enabled () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-recent-files-enabled");
  }

  auto
  Settings::property_gtk_recent_files_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-recent-files-enabled");
  }

  auto
  Settings::property_gtk_primary_button_warps_slider () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-primary-button-warps-slider");
  }

  auto
  Settings::property_gtk_primary_button_warps_slider () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-primary-button-warps-slider");
  }

  auto
  Settings::property_gtk_decoration_layout () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "gtk-decoration-layout");
  }

  auto
  Settings::property_gtk_decoration_layout () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-decoration-layout");
  }

  auto
  Settings::property_gtk_titlebar_double_click () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this,
                                               "gtk-titlebar-double-click");
  }

  auto
  Settings::property_gtk_titlebar_double_click () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-titlebar-double-click");
  }

  auto
  Settings::property_gtk_titlebar_middle_click () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this,
                                               "gtk-titlebar-middle-click");
  }

  auto
  Settings::property_gtk_titlebar_middle_click () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-titlebar-middle-click");
  }

  auto
  Settings::property_gtk_titlebar_right_click () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this,
                                               "gtk-titlebar-right-click");
  }

  auto
  Settings::property_gtk_titlebar_right_click () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "gtk-titlebar-right-click");
  }

  auto
  Settings::property_gtk_dialogs_use_header () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-dialogs-use-header");
  }

  auto
  Settings::property_gtk_dialogs_use_header () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-dialogs-use-header");
  }

  auto
  Settings::property_gtk_long_press_time () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "gtk-long-press-time");
  }

  auto
  Settings::property_gtk_long_press_time () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "gtk-long-press-time");
  }

  auto
  Settings::property_gtk_keynav_use_caret () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-keynav-use-caret");
  }

  auto
  Settings::property_gtk_keynav_use_caret () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-keynav-use-caret");
  }

  auto
  Settings::property_gtk_overlay_scrolling () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "gtk-overlay-scrolling");
  }

  auto
  Settings::property_gtk_overlay_scrolling () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "gtk-overlay-scrolling");
  }

} // namespace gtk
