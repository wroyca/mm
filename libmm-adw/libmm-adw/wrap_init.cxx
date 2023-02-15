// SPDX-License-Identifier: LGPL-2.1-or-later

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC

#include <libmm-adw/wrap_init.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-glib/object.hxx>

#include <libmm-adw/aboutwindow.hxx>
#include <libmm-adw/actionrow.hxx>
#include <libmm-adw/animation.hxx>
#include <libmm-adw/animationtarget.hxx>
#include <libmm-adw/application.hxx>
#include <libmm-adw/applicationwindow.hxx>
#include <libmm-adw/avatar.hxx>
#include <libmm-adw/bin.hxx>
#include <libmm-adw/buttoncontent.hxx>
#include <libmm-adw/callbackanimationtarget.hxx>
#include <libmm-adw/carousel.hxx>
#include <libmm-adw/carouselindicatordots.hxx>
#include <libmm-adw/carouselindicatorlines.hxx>
#include <libmm-adw/clamp.hxx>
#include <libmm-adw/clamplayout.hxx>
#include <libmm-adw/clampscrollable.hxx>
#include <libmm-adw/comborow.hxx>
#include <libmm-adw/easing.hxx>
#include <libmm-adw/entryrow.hxx>
#include <libmm-adw/enumlistitem.hxx>
#include <libmm-adw/enumlistmodel.hxx>
#include <libmm-adw/expanderrow.hxx>
#include <libmm-adw/flap.hxx>
#include <libmm-adw/foldthresholdpolicy.hxx>
#include <libmm-adw/headerbar.hxx>
#include <libmm-adw/leaflet.hxx>
#include <libmm-adw/leafletpage.hxx>
#include <libmm-adw/messagedialog.hxx>
#include <libmm-adw/navigationdirection.hxx>
#include <libmm-adw/passwordentryrow.hxx>
#include <libmm-adw/preferencesgroup.hxx>
#include <libmm-adw/preferencespage.hxx>
#include <libmm-adw/preferencesrow.hxx>
#include <libmm-adw/preferenceswindow.hxx>
#include <libmm-adw/propertyanimationtarget.hxx>
#include <libmm-adw/splitbutton.hxx>
#include <libmm-adw/springanimation.hxx>
#include <libmm-adw/springparams.hxx>
#include <libmm-adw/squeezer.hxx>
#include <libmm-adw/squeezerpage.hxx>
#include <libmm-adw/statuspage.hxx>
#include <libmm-adw/stylemanager.hxx>
#include <libmm-adw/swipeable.hxx>
#include <libmm-adw/swipetracker.hxx>
#include <libmm-adw/tabbar.hxx>
#include <libmm-adw/tabpage.hxx>
#include <libmm-adw/tabview.hxx>
#include <libmm-adw/timedanimation.hxx>
#include <libmm-adw/toast.hxx>
#include <libmm-adw/toastoverlay.hxx>
#include <libmm-adw/viewstack.hxx>
#include <libmm-adw/viewstackpage.hxx>
#include <libmm-adw/viewswitcher.hxx>
#include <libmm-adw/viewswitcherbar.hxx>
#include <libmm-adw/viewswitchertitle.hxx>
#include <libmm-adw/window.hxx>
#include <libmm-adw/windowtitle.hxx>

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

namespace Adw
{

  class AboutWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ActionRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Animation_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class AnimationTarget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Application_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ApplicationWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Avatar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Bin_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ButtonContent_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class CallbackAnimationTarget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Carousel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class CarouselIndicatorDots_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class CarouselIndicatorLines_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Clamp_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ClampLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ClampScrollable_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ComboRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class EntryRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class EnumListItem_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class EnumListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ExpanderRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Flap_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class HeaderBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Leaflet_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class LeafletPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class MessageDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PasswordEntryRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PreferencesGroup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PreferencesPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PreferencesRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PreferencesWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class PropertyAnimationTarget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class SplitButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class SpringAnimation_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Squeezer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class SqueezerPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class StatusPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class StyleManager_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class SwipeTracker_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class TabBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class TabPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class TabView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class TimedAnimation_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Toast_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ToastOverlay_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ViewStack_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ViewStackPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ViewSwitcher_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ViewSwitcherBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class ViewSwitcherTitle_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class Window_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  class WindowTitle_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;
  };

  auto
  wrap_init () -> void
  {
    Glib::wrap_register (adw_about_window_get_type (),
                         &AboutWindow_Class::wrap_new);
    Glib::wrap_register (adw_action_row_get_type (),
                         &ActionRow_Class::wrap_new);
    Glib::wrap_register (adw_animation_get_type (), &Animation_Class::wrap_new);
    Glib::wrap_register (adw_animation_target_get_type (),
                         &AnimationTarget_Class::wrap_new);
    Glib::wrap_register (adw_application_get_type (),
                         &Application_Class::wrap_new);
    Glib::wrap_register (adw_application_window_get_type (),
                         &ApplicationWindow_Class::wrap_new);
    Glib::wrap_register (adw_avatar_get_type (), &Avatar_Class::wrap_new);
    Glib::wrap_register (adw_bin_get_type (), &Bin_Class::wrap_new);
    Glib::wrap_register (adw_button_content_get_type (),
                         &ButtonContent_Class::wrap_new);
    Glib::wrap_register (adw_callback_animation_target_get_type (),
                         &CallbackAnimationTarget_Class::wrap_new);
    Glib::wrap_register (adw_carousel_get_type (), &Carousel_Class::wrap_new);
    Glib::wrap_register (adw_carousel_indicator_dots_get_type (),
                         &CarouselIndicatorDots_Class::wrap_new);
    Glib::wrap_register (adw_carousel_indicator_lines_get_type (),
                         &CarouselIndicatorLines_Class::wrap_new);
    Glib::wrap_register (adw_clamp_get_type (), &Clamp_Class::wrap_new);
    Glib::wrap_register (adw_clamp_layout_get_type (),
                         &ClampLayout_Class::wrap_new);
    Glib::wrap_register (adw_clamp_scrollable_get_type (),
                         &ClampScrollable_Class::wrap_new);
    Glib::wrap_register (adw_combo_row_get_type (), &ComboRow_Class::wrap_new);
    Glib::wrap_register (adw_entry_row_get_type (), &EntryRow_Class::wrap_new);
    Glib::wrap_register (adw_enum_list_item_get_type (),
                         &EnumListItem_Class::wrap_new);
    Glib::wrap_register (adw_enum_list_model_get_type (),
                         &EnumListModel_Class::wrap_new);
    Glib::wrap_register (adw_expander_row_get_type (),
                         &ExpanderRow_Class::wrap_new);
    Glib::wrap_register (adw_flap_get_type (), &Flap_Class::wrap_new);
    Glib::wrap_register (adw_header_bar_get_type (),
                         &HeaderBar_Class::wrap_new);
    Glib::wrap_register (adw_leaflet_get_type (), &Leaflet_Class::wrap_new);
    Glib::wrap_register (adw_leaflet_page_get_type (),
                         &LeafletPage_Class::wrap_new);
    Glib::wrap_register (adw_message_dialog_get_type (),
                         &MessageDialog_Class::wrap_new);
    Glib::wrap_register (adw_password_entry_row_get_type (),
                         &PasswordEntryRow_Class::wrap_new);
    Glib::wrap_register (adw_preferences_group_get_type (),
                         &PreferencesGroup_Class::wrap_new);
    Glib::wrap_register (adw_preferences_page_get_type (),
                         &PreferencesPage_Class::wrap_new);
    Glib::wrap_register (adw_preferences_row_get_type (),
                         &PreferencesRow_Class::wrap_new);
    Glib::wrap_register (adw_preferences_window_get_type (),
                         &PreferencesWindow_Class::wrap_new);
    Glib::wrap_register (adw_property_animation_target_get_type (),
                         &PropertyAnimationTarget_Class::wrap_new);
    Glib::wrap_register (adw_split_button_get_type (),
                         &SplitButton_Class::wrap_new);
    Glib::wrap_register (adw_spring_animation_get_type (),
                         &SpringAnimation_Class::wrap_new);
    Glib::wrap_register (adw_squeezer_get_type (), &Squeezer_Class::wrap_new);
    Glib::wrap_register (adw_squeezer_page_get_type (),
                         &SqueezerPage_Class::wrap_new);
    Glib::wrap_register (adw_status_page_get_type (),
                         &StatusPage_Class::wrap_new);
    Glib::wrap_register (adw_style_manager_get_type (),
                         &StyleManager_Class::wrap_new);
    Glib::wrap_register (adw_swipe_tracker_get_type (),
                         &SwipeTracker_Class::wrap_new);
    Glib::wrap_register (adw_tab_bar_get_type (), &TabBar_Class::wrap_new);
    Glib::wrap_register (adw_tab_page_get_type (), &TabPage_Class::wrap_new);
    Glib::wrap_register (adw_tab_view_get_type (), &TabView_Class::wrap_new);
    Glib::wrap_register (adw_timed_animation_get_type (),
                         &TimedAnimation_Class::wrap_new);
    Glib::wrap_register (adw_toast_get_type (), &Toast_Class::wrap_new);
    Glib::wrap_register (adw_toast_overlay_get_type (),
                         &ToastOverlay_Class::wrap_new);
    Glib::wrap_register (adw_view_stack_get_type (),
                         &ViewStack_Class::wrap_new);
    Glib::wrap_register (adw_view_stack_page_get_type (),
                         &ViewStackPage_Class::wrap_new);
    Glib::wrap_register (adw_view_switcher_get_type (),
                         &ViewSwitcher_Class::wrap_new);
    Glib::wrap_register (adw_view_switcher_bar_get_type (),
                         &ViewSwitcherBar_Class::wrap_new);
    Glib::wrap_register (adw_view_switcher_title_get_type (),
                         &ViewSwitcherTitle_Class::wrap_new);
    Glib::wrap_register (adw_window_get_type (), &Window_Class::wrap_new);
    Glib::wrap_register (adw_window_title_get_type (),
                         &WindowTitle_Class::wrap_new);

    g_type_ensure (AboutWindow::get_type ());
    g_type_ensure (ActionRow::get_type ());
    g_type_ensure (Animation::get_type ());
    g_type_ensure (AnimationTarget::get_type ());
    g_type_ensure (Application::get_type ());
    g_type_ensure (ApplicationWindow::get_type ());
    g_type_ensure (Avatar::get_type ());
    g_type_ensure (Bin::get_type ());
    g_type_ensure (ButtonContent::get_type ());
    g_type_ensure (CallbackAnimationTarget::get_type ());
    g_type_ensure (Carousel::get_type ());
    g_type_ensure (CarouselIndicatorDots::get_type ());
    g_type_ensure (CarouselIndicatorLines::get_type ());
    g_type_ensure (Clamp::get_type ());
    g_type_ensure (ClampLayout::get_type ());
    g_type_ensure (ClampScrollable::get_type ());
    g_type_ensure (ComboRow::get_type ());
    g_type_ensure (EntryRow::get_type ());
    g_type_ensure (EnumListItem::get_type ());
    g_type_ensure (EnumListModel::get_type ());
    g_type_ensure (ExpanderRow::get_type ());
    g_type_ensure (Flap::get_type ());
    g_type_ensure (HeaderBar::get_type ());
    g_type_ensure (Leaflet::get_type ());
    g_type_ensure (LeafletPage::get_type ());
    g_type_ensure (MessageDialog::get_type ());
    g_type_ensure (PasswordEntryRow::get_type ());
    g_type_ensure (PreferencesGroup::get_type ());
    g_type_ensure (PreferencesPage::get_type ());
    g_type_ensure (PreferencesRow::get_type ());
    g_type_ensure (PreferencesWindow::get_type ());
    g_type_ensure (PropertyAnimationTarget::get_type ());
    g_type_ensure (SplitButton::get_type ());
    g_type_ensure (SpringAnimation::get_type ());
    g_type_ensure (Squeezer::get_type ());
    g_type_ensure (SqueezerPage::get_type ());
    g_type_ensure (StatusPage::get_type ());
    g_type_ensure (StyleManager::get_type ());
    g_type_ensure (SwipeTracker::get_type ());
    g_type_ensure (TabBar::get_type ());
    g_type_ensure (TabPage::get_type ());
    g_type_ensure (TabView::get_type ());
    g_type_ensure (TimedAnimation::get_type ());
    g_type_ensure (Toast::get_type ());
    g_type_ensure (ToastOverlay::get_type ());
    g_type_ensure (ViewStack::get_type ());
    g_type_ensure (ViewStackPage::get_type ());
    g_type_ensure (ViewSwitcher::get_type ());
    g_type_ensure (ViewSwitcherBar::get_type ());
    g_type_ensure (ViewSwitcherTitle::get_type ());
    g_type_ensure (Window::get_type ());
    g_type_ensure (WindowTitle::get_type ());
  }

} // namespace Adw
