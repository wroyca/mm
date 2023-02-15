// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SETTINGS_H
#define _GTKMM_SETTINGS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/display.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/styleprovider.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSettings = struct _GtkSettings;
using GtkSettingsClass = struct _GtkSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Settings_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Settings : public Glib::Object,
                             public StyleProvider
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Settings;
    using CppClassType = Settings_Class;
    using BaseObjectType = GtkSettings;
    using BaseClassType = GtkSettingsClass;

    Settings (const Settings&) = delete;
    auto
    operator= (const Settings&) -> Settings& = delete;

  private:
    friend class Settings_Class;
    static CppClassType settings_class_;

  protected:
    explicit Settings (const Glib::ConstructParams& construct_params);
    explicit Settings (GtkSettings* castitem);

#endif

  public:
    Settings (Settings&& src) noexcept;
    auto
    operator= (Settings&& src) noexcept -> Settings&;

    ~Settings () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSettings*
    {
      return reinterpret_cast<GtkSettings*> (gobject_);
    }

    auto
    gobj () const -> const GtkSettings*
    {
      return reinterpret_cast<GtkSettings*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSettings*;

  private:
  public:
    static auto
    get_default () -> Glib::RefPtr<Settings>;

    static auto
    get_for_display (const Glib::RefPtr<Gdk::Display>& display)
        -> Glib::RefPtr<Settings>;

    auto
    reset_property (const Glib::ustring& name) -> void;

    auto
    property_gtk_double_click_time () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_double_click_time () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_double_click_distance () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_double_click_distance () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_cursor_blink () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_cursor_blink () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_blink_time () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_blink_time () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_cursor_blink_timeout () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_blink_timeout () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_split_cursor () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_split_cursor () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_aspect_ratio () -> Glib::PropertyProxy<double>;

    auto
    property_gtk_cursor_aspect_ratio () const
        -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_gtk_theme_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_theme_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_dnd_drag_threshold () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_dnd_drag_threshold () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_font_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_font_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_xft_antialias () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_xft_antialias () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_xft_hinting () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_xft_hinting () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_xft_hintstyle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_xft_hintstyle () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_xft_rgba () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_xft_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_xft_dpi () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_xft_dpi () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_hint_font_metrics () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_hint_font_metrics () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_theme_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_cursor_theme_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_cursor_theme_size () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_theme_size () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_alternative_button_order () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_alternative_button_order () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_alternative_sort_arrows () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_alternative_sort_arrows () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_animations () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_animations () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_error_bell () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_error_bell () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_print_backends () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_print_backends () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_print_preview_command () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_print_preview_command () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_enable_accels () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_accels () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_im_module () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_im_module () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_recent_files_max_age () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_recent_files_max_age () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_fontconfig_timestamp () -> Glib::PropertyProxy<int>;

    auto
    property_gtk_fontconfig_timestamp () const
        -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_sound_theme_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_sound_theme_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_enable_input_feedback_sounds () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_input_feedback_sounds () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_event_sounds () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_event_sounds () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_application_prefer_dark_theme () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_application_prefer_dark_theme () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_app_menu () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_app_menu () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_menubar () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_menubar () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_desktop () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_desktop () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_primary_paste () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_primary_paste () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_label_select_on_focus () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_label_select_on_focus () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_entry_password_hint_timeout () -> Glib::PropertyProxy<guint>;

    auto
    property_gtk_entry_password_hint_timeout () const
        -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_gtk_entry_select_on_focus () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_entry_select_on_focus () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_icon_theme_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_icon_theme_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_recent_files_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_recent_files_enabled () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_primary_button_warps_slider () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_primary_button_warps_slider () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_decoration_layout () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_titlebar_double_click () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_titlebar_double_click () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_titlebar_middle_click () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_titlebar_middle_click () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_titlebar_right_click () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_gtk_titlebar_right_click () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gtk_dialogs_use_header () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_dialogs_use_header () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_long_press_time () -> Glib::PropertyProxy<guint>;

    auto
    property_gtk_long_press_time () const
        -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_gtk_keynav_use_caret () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_keynav_use_caret () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_overlay_scrolling () -> Glib::PropertyProxy<bool>;

    auto
    property_gtk_overlay_scrolling () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkSettings* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Settings>;
} // namespace Glib

#endif
