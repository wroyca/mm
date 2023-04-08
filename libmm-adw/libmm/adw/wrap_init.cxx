// SPDX-License-Identifier: LGPL-2.1-or-later

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC

#include <libmm/adw/wrap_init.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/glib/object.hxx>

#include <libmm/adw/aboutwindow.hxx>
#include <libmm/adw/actionrow.hxx>
#include <libmm/adw/animation.hxx>
#include <libmm/adw/animationtarget.hxx>
#include <libmm/adw/application.hxx>
#include <libmm/adw/applicationwindow.hxx>
#include <libmm/adw/avatar.hxx>
#include <libmm/adw/bin.hxx>
#include <libmm/adw/buttoncontent.hxx>
#include <libmm/adw/callbackanimationtarget.hxx>
#include <libmm/adw/carousel.hxx>
#include <libmm/adw/carouselindicatordots.hxx>
#include <libmm/adw/carouselindicatorlines.hxx>
#include <libmm/adw/clamp.hxx>
#include <libmm/adw/clamplayout.hxx>
#include <libmm/adw/clampscrollable.hxx>
#include <libmm/adw/comborow.hxx>
#include <libmm/adw/easing.hxx>
#include <libmm/adw/entryrow.hxx>
#include <libmm/adw/enumlistitem.hxx>
#include <libmm/adw/enumlistmodel.hxx>
#include <libmm/adw/expanderrow.hxx>
#include <libmm/adw/flap.hxx>
#include <libmm/adw/foldthresholdpolicy.hxx>
#include <libmm/adw/headerbar.hxx>
#include <libmm/adw/leaflet.hxx>
#include <libmm/adw/leafletpage.hxx>
#include <libmm/adw/messagedialog.hxx>
#include <libmm/adw/navigationdirection.hxx>
#include <libmm/adw/passwordentryrow.hxx>
#include <libmm/adw/preferencesgroup.hxx>
#include <libmm/adw/preferencespage.hxx>
#include <libmm/adw/preferencesrow.hxx>
#include <libmm/adw/preferenceswindow.hxx>
#include <libmm/adw/propertyanimationtarget.hxx>
#include <libmm/adw/splitbutton.hxx>
#include <libmm/adw/springanimation.hxx>
#include <libmm/adw/springparams.hxx>
#include <libmm/adw/squeezer.hxx>
#include <libmm/adw/squeezerpage.hxx>
#include <libmm/adw/statuspage.hxx>
#include <libmm/adw/stylemanager.hxx>
#include <libmm/adw/swipeable.hxx>
#include <libmm/adw/swipetracker.hxx>
#include <libmm/adw/tabbar.hxx>
#include <libmm/adw/tabpage.hxx>
#include <libmm/adw/tabview.hxx>
#include <libmm/adw/timedanimation.hxx>
#include <libmm/adw/toast.hxx>
#include <libmm/adw/toastoverlay.hxx>
#include <libmm/adw/viewstack.hxx>
#include <libmm/adw/viewstackpage.hxx>
#include <libmm/adw/viewswitcher.hxx>
#include <libmm/adw/viewswitcherbar.hxx>
#include <libmm/adw/viewswitchertitle.hxx>
#include <libmm/adw/window.hxx>
#include <libmm/adw/windowtitle.hxx>

extern "C"
{
  auto
  adw_about_window_get_type (void) -> GType;
  auto
  adw_action_row_get_type (void) -> GType;
  auto
  adw_animation_get_type (void) -> GType;
  auto
  adw_animation_target_get_type (void) -> GType;
  auto
  adw_application_get_type (void) -> GType;
  auto
  adw_application_window_get_type (void) -> GType;
  auto
  adw_avatar_get_type (void) -> GType;
  auto
  adw_bin_get_type (void) -> GType;
  auto
  adw_button_content_get_type (void) -> GType;
  auto
  adw_callback_animation_target_get_type (void) -> GType;
  auto
  adw_carousel_get_type (void) -> GType;
  auto
  adw_carousel_indicator_dots_get_type (void) -> GType;
  auto
  adw_carousel_indicator_lines_get_type (void) -> GType;
  auto
  adw_clamp_get_type (void) -> GType;
  auto
  adw_clamp_layout_get_type (void) -> GType;
  auto
  adw_clamp_scrollable_get_type (void) -> GType;
  auto
  adw_combo_row_get_type (void) -> GType;
  auto
  adw_entry_row_get_type (void) -> GType;
  auto
  adw_enum_list_item_get_type (void) -> GType;
  auto
  adw_enum_list_model_get_type (void) -> GType;
  auto
  adw_expander_row_get_type (void) -> GType;
  auto
  adw_flap_get_type (void) -> GType;
  auto
  adw_header_bar_get_type (void) -> GType;
  auto
  adw_leaflet_get_type (void) -> GType;
  auto
  adw_leaflet_page_get_type (void) -> GType;
  auto
  adw_message_dialog_get_type (void) -> GType;
  auto
  adw_password_entry_row_get_type (void) -> GType;
  auto
  adw_preferences_group_get_type (void) -> GType;
  auto
  adw_preferences_page_get_type (void) -> GType;
  auto
  adw_preferences_row_get_type (void) -> GType;
  auto
  adw_preferences_window_get_type (void) -> GType;
  auto
  adw_property_animation_target_get_type (void) -> GType;
  auto
  adw_split_button_get_type (void) -> GType;
  auto
  adw_spring_animation_get_type (void) -> GType;
  auto
  adw_squeezer_get_type (void) -> GType;
  auto
  adw_squeezer_page_get_type (void) -> GType;
  auto
  adw_status_page_get_type (void) -> GType;
  auto
  adw_style_manager_get_type (void) -> GType;
  auto
  adw_swipe_tracker_get_type (void) -> GType;
  auto
  adw_tab_bar_get_type (void) -> GType;
  auto
  adw_tab_page_get_type (void) -> GType;
  auto
  adw_tab_view_get_type (void) -> GType;
  auto
  adw_timed_animation_get_type (void) -> GType;
  auto
  adw_toast_get_type (void) -> GType;
  auto
  adw_toast_overlay_get_type (void) -> GType;
  auto
  adw_view_stack_get_type (void) -> GType;
  auto
  adw_view_stack_page_get_type (void) -> GType;
  auto
  adw_view_switcher_get_type (void) -> GType;
  auto
  adw_view_switcher_bar_get_type (void) -> GType;
  auto
  adw_view_switcher_title_get_type (void) -> GType;
  auto
  adw_window_get_type (void) -> GType;
  auto
  adw_window_title_get_type (void) -> GType;
}

namespace adw
{

  class LIBMM_ADW_SYMEXPORT about_window_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT action_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT animation_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT animation_target_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT application_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT application_window_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT avatar_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT bin_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT button_content_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT callback_animation_target_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT carousel_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT carousel_indicator_dots_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT carousel_indicator_lines_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT clamp_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT clamp_layout_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT clamp_scrollable_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT combo_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT entry_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT enum_list_item_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT enum_list_model_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT expander_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT flap_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT header_bar_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT leaflet_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT leaflet_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT message_dialog_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT password_entry_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT preferences_group_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT preferences_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT preferences_row_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT preferences_window_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT property_animation_target_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT split_button_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT spring_animation_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT squeezer_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT squeezer_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT status_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT style_manager_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT swipe_tracker_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT tab_bar_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT tab_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT tab_view_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT timed_animation_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT toast_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT toast_overlay_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT view_stack_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT view_stack_page_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT view_switcher_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT view_switcher_bar_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT view_switcher_title_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT window_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LIBMM_ADW_SYMEXPORT window_title_class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  auto
  wrap_init () -> void
  {
    glib::wrap_register (adw_about_window_get_type (),
                         &about_window_class::wrap_new);
    glib::wrap_register (adw_action_row_get_type (),
                         &action_row_class::wrap_new);
    glib::wrap_register (adw_animation_get_type (), &animation_class::wrap_new);
    glib::wrap_register (adw_animation_target_get_type (),
                         &animation_target_class::wrap_new);
    glib::wrap_register (adw_application_get_type (),
                         &application_class::wrap_new);
    glib::wrap_register (adw_application_window_get_type (),
                         &application_window_class::wrap_new);
    glib::wrap_register (adw_avatar_get_type (), &avatar_class::wrap_new);
    glib::wrap_register (adw_bin_get_type (), &bin_class::wrap_new);
    glib::wrap_register (adw_button_content_get_type (),
                         &button_content_class::wrap_new);
    glib::wrap_register (adw_callback_animation_target_get_type (),
                         &callback_animation_target_class::wrap_new);
    glib::wrap_register (adw_carousel_get_type (), &carousel_class::wrap_new);
    glib::wrap_register (adw_carousel_indicator_dots_get_type (),
                         &carousel_indicator_dots_class::wrap_new);
    glib::wrap_register (adw_carousel_indicator_lines_get_type (),
                         &carousel_indicator_lines_class::wrap_new);
    glib::wrap_register (adw_clamp_get_type (), &clamp_class::wrap_new);
    glib::wrap_register (adw_clamp_layout_get_type (),
                         &clamp_layout_class::wrap_new);
    glib::wrap_register (adw_clamp_scrollable_get_type (),
                         &clamp_scrollable_class::wrap_new);
    glib::wrap_register (adw_combo_row_get_type (), &combo_row_class::wrap_new);
    glib::wrap_register (adw_entry_row_get_type (), &entry_row_class::wrap_new);
    glib::wrap_register (adw_enum_list_item_get_type (),
                         &enum_list_item_class::wrap_new);
    glib::wrap_register (adw_enum_list_model_get_type (),
                         &enum_list_model_class::wrap_new);
    glib::wrap_register (adw_expander_row_get_type (),
                         &expander_row_class::wrap_new);
    glib::wrap_register (adw_flap_get_type (), &flap_class::wrap_new);
    glib::wrap_register (adw_header_bar_get_type (),
                         &header_bar_class::wrap_new);
    glib::wrap_register (adw_leaflet_get_type (), &leaflet_class::wrap_new);
    glib::wrap_register (adw_leaflet_page_get_type (),
                         &leaflet_page_class::wrap_new);
    glib::wrap_register (adw_message_dialog_get_type (),
                         &message_dialog_class::wrap_new);
    glib::wrap_register (adw_password_entry_row_get_type (),
                         &password_entry_row_class::wrap_new);
    glib::wrap_register (adw_preferences_group_get_type (),
                         &preferences_group_class::wrap_new);
    glib::wrap_register (adw_preferences_page_get_type (),
                         &preferences_page_class::wrap_new);
    glib::wrap_register (adw_preferences_row_get_type (),
                         &preferences_row_class::wrap_new);
    glib::wrap_register (adw_preferences_window_get_type (),
                         &preferences_window_class::wrap_new);
    glib::wrap_register (adw_property_animation_target_get_type (),
                         &property_animation_target_class::wrap_new);
    glib::wrap_register (adw_split_button_get_type (),
                         &split_button_class::wrap_new);
    glib::wrap_register (adw_spring_animation_get_type (),
                         &spring_animation_class::wrap_new);
    glib::wrap_register (adw_squeezer_get_type (), &squeezer_class::wrap_new);
    glib::wrap_register (adw_squeezer_page_get_type (),
                         &squeezer_page_class::wrap_new);
    glib::wrap_register (adw_status_page_get_type (),
                         &status_page_class::wrap_new);
    glib::wrap_register (adw_style_manager_get_type (),
                         &style_manager_class::wrap_new);
    glib::wrap_register (adw_swipe_tracker_get_type (),
                         &swipe_tracker_class::wrap_new);
    glib::wrap_register (adw_tab_bar_get_type (), &tab_bar_class::wrap_new);
    glib::wrap_register (adw_tab_page_get_type (), &tab_page_class::wrap_new);
    glib::wrap_register (adw_tab_view_get_type (), &tab_view_class::wrap_new);
    glib::wrap_register (adw_timed_animation_get_type (),
                         &timed_animation_class::wrap_new);
    glib::wrap_register (adw_toast_get_type (), &toast_class::wrap_new);
    glib::wrap_register (adw_toast_overlay_get_type (),
                         &toast_overlay_class::wrap_new);
    glib::wrap_register (adw_view_stack_get_type (),
                         &view_stack_class::wrap_new);
    glib::wrap_register (adw_view_stack_page_get_type (),
                         &view_stack_page_class::wrap_new);
    glib::wrap_register (adw_view_switcher_get_type (),
                         &view_switcher_class::wrap_new);
    glib::wrap_register (adw_view_switcher_bar_get_type (),
                         &view_switcher_bar_class::wrap_new);
    glib::wrap_register (adw_view_switcher_title_get_type (),
                         &view_switcher_title_class::wrap_new);
    glib::wrap_register (adw_window_get_type (), &window_class::wrap_new);
    glib::wrap_register (adw_window_title_get_type (),
                         &window_title_class::wrap_new);

    g_type_ensure (about_window::get_type ());
    g_type_ensure (action_row::get_type ());
    g_type_ensure (animation::get_type ());
    g_type_ensure (AnimationTarget::get_type ());
    g_type_ensure (application::get_type ());
    g_type_ensure (application_window::get_type ());
    g_type_ensure (avatar::get_type ());
    g_type_ensure (bin::get_type ());
    g_type_ensure (button_content::get_type ());
    g_type_ensure (callback_animation_target::get_type ());
    g_type_ensure (carousel::get_type ());
    g_type_ensure (carousel_indicator_dots::get_type ());
    g_type_ensure (carousel_indicator_lines::get_type ());
    g_type_ensure (clamp::get_type ());
    g_type_ensure (clamp_layout::get_type ());
    g_type_ensure (clamp_scrollable::get_type ());
    g_type_ensure (combo_row::get_type ());
    g_type_ensure (entry_row::get_type ());
    g_type_ensure (enum_list_item::get_type ());
    g_type_ensure (enum_list_model::get_type ());
    g_type_ensure (expander_row::get_type ());
    g_type_ensure (flap::get_type ());
    g_type_ensure (header_bar::get_type ());
    g_type_ensure (leaflet::get_type ());
    g_type_ensure (leaflet_page::get_type ());
    g_type_ensure (message_dialog::get_type ());
    g_type_ensure (password_entry_row::get_type ());
    g_type_ensure (preferences_group::get_type ());
    g_type_ensure (preferences_page::get_type ());
    g_type_ensure (preferences_row::get_type ());
    g_type_ensure (preferences_window::get_type ());
    g_type_ensure (property_animation_target::get_type ());
    g_type_ensure (split_button::get_type ());
    g_type_ensure (spring_animation::get_type ());
    g_type_ensure (squeezer::get_type ());
    g_type_ensure (squeezer_page::get_type ());
    g_type_ensure (status_page::get_type ());
    g_type_ensure (style_manager::get_type ());
    g_type_ensure (swipe_tracker::get_type ());
    g_type_ensure (tab_bar::get_type ());
    g_type_ensure (tab_page::get_type ());
    g_type_ensure (tab_view::get_type ());
    g_type_ensure (timed_animation::get_type ());
    g_type_ensure (toast::get_type ());
    g_type_ensure (toast_overlay::get_type ());
    g_type_ensure (view_stack::get_type ());
    g_type_ensure (view_stack_page::get_type ());
    g_type_ensure (view_switcher::get_type ());
    g_type_ensure (view_switcher_bar::get_type ());
    g_type_ensure (view_switcher_title::get_type ());
    g_type_ensure (window::get_type ());
    g_type_ensure (window_title::get_type ());
  }

} // namespace adw
