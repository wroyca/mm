// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SETTINGS_H
#define _GTKMM_SETTINGS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/display.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/styleprovider.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSettings = struct _GtkSettings;
using GtkSettingsClass = struct _GtkSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Settings_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Settings : public glib::Object,
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
    explicit Settings (const glib::ConstructParams& construct_params);
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
    get_default () -> glib::RefPtr<Settings>;

    static auto
    get_for_display (const glib::RefPtr<gdk::Display>& display)
        -> glib::RefPtr<Settings>;

    auto
    reset_property (const glib::ustring& name) -> void;

    auto
    property_gtk_double_click_time () -> glib::PropertyProxy<int>;

    auto
    property_gtk_double_click_time () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_double_click_distance () -> glib::PropertyProxy<int>;

    auto
    property_gtk_double_click_distance () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_cursor_blink () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_cursor_blink () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_blink_time () -> glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_blink_time () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_cursor_blink_timeout () -> glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_blink_timeout () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_split_cursor () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_split_cursor () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_aspect_ratio () -> glib::PropertyProxy<double>;

    auto
    property_gtk_cursor_aspect_ratio () const
        -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_gtk_theme_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_theme_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_dnd_drag_threshold () -> glib::PropertyProxy<int>;

    auto
    property_gtk_dnd_drag_threshold () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_font_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_font_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_xft_antialias () -> glib::PropertyProxy<int>;

    auto
    property_gtk_xft_antialias () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_xft_hinting () -> glib::PropertyProxy<int>;

    auto
    property_gtk_xft_hinting () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_xft_hintstyle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_xft_hintstyle () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_xft_rgba () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_xft_rgba () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_xft_dpi () -> glib::PropertyProxy<int>;

    auto
    property_gtk_xft_dpi () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_hint_font_metrics () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_hint_font_metrics () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_cursor_theme_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_cursor_theme_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_cursor_theme_size () -> glib::PropertyProxy<int>;

    auto
    property_gtk_cursor_theme_size () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_alternative_button_order () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_alternative_button_order () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_alternative_sort_arrows () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_alternative_sort_arrows () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_animations () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_animations () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_error_bell () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_error_bell () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_print_backends () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_print_backends () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_print_preview_command () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_print_preview_command () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_enable_accels () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_accels () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_im_module () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_im_module () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_recent_files_max_age () -> glib::PropertyProxy<int>;

    auto
    property_gtk_recent_files_max_age () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_fontconfig_timestamp () -> glib::PropertyProxy<int>;

    auto
    property_gtk_fontconfig_timestamp () const
        -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_gtk_sound_theme_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_sound_theme_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_enable_input_feedback_sounds () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_input_feedback_sounds () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_event_sounds () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_event_sounds () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_application_prefer_dark_theme () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_application_prefer_dark_theme () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_app_menu () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_app_menu () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_menubar () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_menubar () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_shell_shows_desktop () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_shell_shows_desktop () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_enable_primary_paste () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_enable_primary_paste () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_label_select_on_focus () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_label_select_on_focus () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_entry_password_hint_timeout () -> glib::PropertyProxy<guint>;

    auto
    property_gtk_entry_password_hint_timeout () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_gtk_entry_select_on_focus () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_entry_select_on_focus () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_icon_theme_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_icon_theme_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_recent_files_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_recent_files_enabled () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_primary_button_warps_slider () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_primary_button_warps_slider () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_decoration_layout () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_decoration_layout () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_titlebar_double_click () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_titlebar_double_click () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_titlebar_middle_click () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_titlebar_middle_click () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_titlebar_right_click () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_gtk_titlebar_right_click () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_gtk_dialogs_use_header () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_dialogs_use_header () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_long_press_time () -> glib::PropertyProxy<guint>;

    auto
    property_gtk_long_press_time () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_gtk_keynav_use_caret () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_keynav_use_caret () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_gtk_overlay_scrolling () -> glib::PropertyProxy<bool>;

    auto
    property_gtk_overlay_scrolling () const
        -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSettings* object, bool take_copy = false) -> glib::RefPtr<gtk::Settings>;
} // namespace glib

#endif
