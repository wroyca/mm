// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/settings.hxx>
#include <libmm/gtk/settings_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSettings* object, bool take_copy) -> Glib::RefPtr<Gtk::Settings>
  {
    return Glib::make_refptr_for_instance<Gtk::Settings> (
        dynamic_cast<Gtk::Settings*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Settings_Class::init () -> const Glib::Class&
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
  Settings_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Settings ((GtkSettings*) object);
  }

  auto
  Settings::gobj_copy () -> GtkSettings*
  {
    reference ();
    return gobj ();
  }

  Settings::Settings (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Settings::Settings (GtkSettings* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Settings::Settings (Settings&& src) noexcept
    : Glib::Object (std::move (src)),
      StyleProvider (std::move (src))
  {
  }

  auto
  Settings::operator= (Settings&& src) noexcept -> Settings&
  {
    Glib::Object::operator= (std::move (src));
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
  Settings::get_default () -> Glib::RefPtr<Settings>
  {
    auto retvalue = Glib::wrap (gtk_settings_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Settings::get_for_display (const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<Settings>
  {
    auto retvalue =
        Glib::wrap (gtk_settings_get_for_display (Glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Settings::reset_property (const Glib::ustring& name) -> void
  {
    gtk_settings_reset_property (gobj (), name.c_str ());
  }

  auto
  Settings::property_gtk_double_click_time () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-double-click-time");
  }

  auto
  Settings::property_gtk_double_click_time () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-double-click-time");
  }

  auto
  Settings::property_gtk_double_click_distance () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-double-click-distance");
  }

  auto
  Settings::property_gtk_double_click_distance () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this,
                                              "gtk-double-click-distance");
  }

  auto
  Settings::property_gtk_cursor_blink () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-cursor-blink");
  }

  auto
  Settings::property_gtk_cursor_blink () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-cursor-blink");
  }

  auto
  Settings::property_gtk_cursor_blink_time () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-cursor-blink-time");
  }

  auto
  Settings::property_gtk_cursor_blink_time () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-blink-time");
  }

  auto
  Settings::property_gtk_cursor_blink_timeout () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-cursor-blink-timeout");
  }

  auto
  Settings::property_gtk_cursor_blink_timeout () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-blink-timeout");
  }

  auto
  Settings::property_gtk_split_cursor () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-split-cursor");
  }

  auto
  Settings::property_gtk_split_cursor () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-split-cursor");
  }

  auto
  Settings::property_gtk_cursor_aspect_ratio () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "gtk-cursor-aspect-ratio");
  }

  auto
  Settings::property_gtk_cursor_aspect_ratio () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this,
                                                 "gtk-cursor-aspect-ratio");
  }

  auto
  Settings::property_gtk_theme_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-theme-name");
  }

  auto
  Settings::property_gtk_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "gtk-theme-name");
  }

  auto
  Settings::property_gtk_dnd_drag_threshold () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-dnd-drag-threshold");
  }

  auto
  Settings::property_gtk_dnd_drag_threshold () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-dnd-drag-threshold");
  }

  auto
  Settings::property_gtk_font_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-font-name");
  }

  auto
  Settings::property_gtk_font_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "gtk-font-name");
  }

  auto
  Settings::property_gtk_xft_antialias () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-xft-antialias");
  }

  auto
  Settings::property_gtk_xft_antialias () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-antialias");
  }

  auto
  Settings::property_gtk_xft_hinting () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-xft-hinting");
  }

  auto
  Settings::property_gtk_xft_hinting () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-hinting");
  }

  auto
  Settings::property_gtk_xft_hintstyle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-xft-hintstyle");
  }

  auto
  Settings::property_gtk_xft_hintstyle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "gtk-xft-hintstyle");
  }

  auto
  Settings::property_gtk_xft_rgba () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-xft-rgba");
  }

  auto
  Settings::property_gtk_xft_rgba () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "gtk-xft-rgba");
  }

  auto
  Settings::property_gtk_xft_dpi () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-xft-dpi");
  }

  auto
  Settings::property_gtk_xft_dpi () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-xft-dpi");
  }

  auto
  Settings::property_gtk_hint_font_metrics () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-hint-font-metrics");
  }

  auto
  Settings::property_gtk_hint_font_metrics () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-hint-font-metrics");
  }

  auto
  Settings::property_gtk_cursor_theme_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-cursor-theme-name");
  }

  auto
  Settings::property_gtk_cursor_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-cursor-theme-name");
  }

  auto
  Settings::property_gtk_cursor_theme_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-cursor-theme-size");
  }

  auto
  Settings::property_gtk_cursor_theme_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-cursor-theme-size");
  }

  auto
  Settings::property_gtk_alternative_button_order () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-alternative-button-order");
  }

  auto
  Settings::property_gtk_alternative_button_order () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-alternative-button-order");
  }

  auto
  Settings::property_gtk_alternative_sort_arrows () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-alternative-sort-arrows");
  }

  auto
  Settings::property_gtk_alternative_sort_arrows () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-alternative-sort-arrows");
  }

  auto
  Settings::property_gtk_enable_animations () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-enable-animations");
  }

  auto
  Settings::property_gtk_enable_animations () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-animations");
  }

  auto
  Settings::property_gtk_error_bell () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-error-bell");
  }

  auto
  Settings::property_gtk_error_bell () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-error-bell");
  }

  auto
  Settings::property_gtk_print_backends () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-print-backends");
  }

  auto
  Settings::property_gtk_print_backends () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "gtk-print-backends");
  }

  auto
  Settings::property_gtk_print_preview_command () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this,
                                               "gtk-print-preview-command");
  }

  auto
  Settings::property_gtk_print_preview_command () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-print-preview-command");
  }

  auto
  Settings::property_gtk_enable_accels () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-enable-accels");
  }

  auto
  Settings::property_gtk_enable_accels () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-accels");
  }

  auto
  Settings::property_gtk_im_module () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-im-module");
  }

  auto
  Settings::property_gtk_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "gtk-im-module");
  }

  auto
  Settings::property_gtk_recent_files_max_age () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-recent-files-max-age");
  }

  auto
  Settings::property_gtk_recent_files_max_age () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-recent-files-max-age");
  }

  auto
  Settings::property_gtk_fontconfig_timestamp () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "gtk-fontconfig-timestamp");
  }

  auto
  Settings::property_gtk_fontconfig_timestamp () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "gtk-fontconfig-timestamp");
  }

  auto
  Settings::property_gtk_sound_theme_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-sound-theme-name");
  }

  auto
  Settings::property_gtk_sound_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "gtk-sound-theme-name");
  }

  auto
  Settings::property_gtk_enable_input_feedback_sounds () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-enable-input-feedback-sounds");
  }

  auto
  Settings::property_gtk_enable_input_feedback_sounds () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-enable-input-feedback-sounds");
  }

  auto
  Settings::property_gtk_enable_event_sounds () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-enable-event-sounds");
  }

  auto
  Settings::property_gtk_enable_event_sounds () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-enable-event-sounds");
  }

  auto
  Settings::property_gtk_application_prefer_dark_theme () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this,
                                      "gtk-application-prefer-dark-theme");
  }

  auto
  Settings::property_gtk_application_prefer_dark_theme () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-application-prefer-dark-theme");
  }

  auto
  Settings::property_gtk_shell_shows_app_menu () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-shell-shows-app-menu");
  }

  auto
  Settings::property_gtk_shell_shows_app_menu () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-shell-shows-app-menu");
  }

  auto
  Settings::property_gtk_shell_shows_menubar () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-shell-shows-menubar");
  }

  auto
  Settings::property_gtk_shell_shows_menubar () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-shell-shows-menubar");
  }

  auto
  Settings::property_gtk_shell_shows_desktop () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-shell-shows-desktop");
  }

  auto
  Settings::property_gtk_shell_shows_desktop () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-shell-shows-desktop");
  }

  auto
  Settings::property_gtk_enable_primary_paste () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-enable-primary-paste");
  }

  auto
  Settings::property_gtk_enable_primary_paste () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-enable-primary-paste");
  }

  auto
  Settings::property_gtk_label_select_on_focus () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-label-select-on-focus");
  }

  auto
  Settings::property_gtk_label_select_on_focus () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-label-select-on-focus");
  }

  auto
  Settings::property_gtk_entry_password_hint_timeout () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "gtk-entry-password-hint-timeout");
  }

  auto
  Settings::property_gtk_entry_password_hint_timeout () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (
        this,
        "gtk-entry-password-hint-timeout");
  }

  auto
  Settings::property_gtk_entry_select_on_focus () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-entry-select-on-focus");
  }

  auto
  Settings::property_gtk_entry_select_on_focus () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-entry-select-on-focus");
  }

  auto
  Settings::property_gtk_icon_theme_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-icon-theme-name");
  }

  auto
  Settings::property_gtk_icon_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "gtk-icon-theme-name");
  }

  auto
  Settings::property_gtk_recent_files_enabled () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-recent-files-enabled");
  }

  auto
  Settings::property_gtk_recent_files_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "gtk-recent-files-enabled");
  }

  auto
  Settings::property_gtk_primary_button_warps_slider () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-primary-button-warps-slider");
  }

  auto
  Settings::property_gtk_primary_button_warps_slider () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (
        this,
        "gtk-primary-button-warps-slider");
  }

  auto
  Settings::property_gtk_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "gtk-decoration-layout");
  }

  auto
  Settings::property_gtk_decoration_layout () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-decoration-layout");
  }

  auto
  Settings::property_gtk_titlebar_double_click () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this,
                                               "gtk-titlebar-double-click");
  }

  auto
  Settings::property_gtk_titlebar_double_click () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-titlebar-double-click");
  }

  auto
  Settings::property_gtk_titlebar_middle_click () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this,
                                               "gtk-titlebar-middle-click");
  }

  auto
  Settings::property_gtk_titlebar_middle_click () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-titlebar-middle-click");
  }

  auto
  Settings::property_gtk_titlebar_right_click () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this,
                                               "gtk-titlebar-right-click");
  }

  auto
  Settings::property_gtk_titlebar_right_click () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "gtk-titlebar-right-click");
  }

  auto
  Settings::property_gtk_dialogs_use_header () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-dialogs-use-header");
  }

  auto
  Settings::property_gtk_dialogs_use_header () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-dialogs-use-header");
  }

  auto
  Settings::property_gtk_long_press_time () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "gtk-long-press-time");
  }

  auto
  Settings::property_gtk_long_press_time () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "gtk-long-press-time");
  }

  auto
  Settings::property_gtk_keynav_use_caret () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-keynav-use-caret");
  }

  auto
  Settings::property_gtk_keynav_use_caret () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-keynav-use-caret");
  }

  auto
  Settings::property_gtk_overlay_scrolling () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "gtk-overlay-scrolling");
  }

  auto
  Settings::property_gtk_overlay_scrolling () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "gtk-overlay-scrolling");
  }

} // namespace Gtk
