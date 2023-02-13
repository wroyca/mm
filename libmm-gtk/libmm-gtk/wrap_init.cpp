

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/mm-glib.hpp>
#include <libmm-gtk/wrap_init.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <libmm-gtk/aboutdialog.hpp>
#include <libmm-gtk/accessible.hpp>
#include <libmm-gtk/actionable.hpp>
#include <libmm-gtk/actionbar.hpp>
#include <libmm-gtk/adjustment.hpp>
#include <libmm-gtk/appchooser.hpp>
#include <libmm-gtk/appchooserbutton.hpp>
#include <libmm-gtk/appchooserdialog.hpp>
#include <libmm-gtk/appchooserwidget.hpp>
#include <libmm-gtk/application.hpp>
#include <libmm-gtk/applicationwindow.hpp>
#include <libmm-gtk/aspectframe.hpp>
#include <libmm-gtk/assistant.hpp>
#include <libmm-gtk/assistantpage.hpp>
#include <libmm-gtk/binlayout.hpp>
#include <libmm-gtk/bitset.hpp>
#include <libmm-gtk/boolfilter.hpp>
#include <libmm-gtk/border.hpp>
#include <libmm-gtk/box.hpp>
#include <libmm-gtk/boxlayout.hpp>
#include <libmm-gtk/buildable.hpp>
#include <libmm-gtk/builder.hpp>
#include <libmm-gtk/buildercscope.hpp>
#include <libmm-gtk/builderscope.hpp>
#include <libmm-gtk/button.hpp>
#include <libmm-gtk/calendar.hpp>
#include <libmm-gtk/cellarea.hpp>
#include <libmm-gtk/cellareabox.hpp>
#include <libmm-gtk/cellareacontext.hpp>
#include <libmm-gtk/celleditable.hpp>
#include <libmm-gtk/celllayout.hpp>
#include <libmm-gtk/cellrenderer.hpp>
#include <libmm-gtk/cellrendereraccel.hpp>
#include <libmm-gtk/cellrenderercombo.hpp>
#include <libmm-gtk/cellrendererpixbuf.hpp>
#include <libmm-gtk/cellrendererprogress.hpp>
#include <libmm-gtk/cellrendererspin.hpp>
#include <libmm-gtk/cellrendererspinner.hpp>
#include <libmm-gtk/cellrenderertext.hpp>
#include <libmm-gtk/cellrenderertoggle.hpp>
#include <libmm-gtk/cellview.hpp>
#include <libmm-gtk/centerbox.hpp>
#include <libmm-gtk/centerlayout.hpp>
#include <libmm-gtk/checkbutton.hpp>
#include <libmm-gtk/colorbutton.hpp>
#include <libmm-gtk/colorchooser.hpp>
#include <libmm-gtk/colorchooserdialog.hpp>
#include <libmm-gtk/columnview.hpp>
#include <libmm-gtk/columnviewcolumn.hpp>
#include <libmm-gtk/combobox.hpp>
#include <libmm-gtk/comboboxtext.hpp>
#include <libmm-gtk/constraint.hpp>
#include <libmm-gtk/constraintguide.hpp>
#include <libmm-gtk/constraintlayout.hpp>
#include <libmm-gtk/constrainttarget.hpp>
#include <libmm-gtk/csslocation.hpp>
#include <libmm-gtk/cssprovider.hpp>
#include <libmm-gtk/csssection.hpp>
#include <libmm-gtk/dialog.hpp>
#include <libmm-gtk/directorylist.hpp>
#include <libmm-gtk/dragicon.hpp>
#include <libmm-gtk/dragsource.hpp>
#include <libmm-gtk/drawingarea.hpp>
#include <libmm-gtk/dropcontrollermotion.hpp>
#include <libmm-gtk/dropdown.hpp>
#include <libmm-gtk/droptarget.hpp>
#include <libmm-gtk/droptargetasync.hpp>
#include <libmm-gtk/editable.hpp>
#include <libmm-gtk/editablelabel.hpp>
#include <libmm-gtk/emojichooser.hpp>
#include <libmm-gtk/entry.hpp>
#include <libmm-gtk/entrybuffer.hpp>
#include <libmm-gtk/entrycompletion.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gtk/eventcontroller.hpp>
#include <libmm-gtk/eventcontrollerfocus.hpp>
#include <libmm-gtk/eventcontrollerkey.hpp>
#include <libmm-gtk/eventcontrollerlegacy.hpp>
#include <libmm-gtk/eventcontrollermotion.hpp>
#include <libmm-gtk/eventcontrollerscroll.hpp>
#include <libmm-gtk/expander.hpp>
#include <libmm-gtk/expression.hpp>
#include <libmm-gtk/expressionwatch.hpp>
#include <libmm-gtk/filechooser.hpp>
#include <libmm-gtk/filechooserdialog.hpp>
#include <libmm-gtk/filechoosernative.hpp>
#include <libmm-gtk/filechooserwidget.hpp>
#include <libmm-gtk/filefilter.hpp>
#include <libmm-gtk/filter.hpp>
#include <libmm-gtk/filterlistmodel.hpp>
#include <libmm-gtk/fixed.hpp>
#include <libmm-gtk/flattenlistmodel.hpp>
#include <libmm-gtk/flowbox.hpp>
#include <libmm-gtk/flowboxchild.hpp>
#include <libmm-gtk/fontbutton.hpp>
#include <libmm-gtk/fontchooser.hpp>
#include <libmm-gtk/fontchooserdialog.hpp>
#include <libmm-gtk/fontchooserwidget.hpp>
#include <libmm-gtk/frame.hpp>
#include <libmm-gtk/gesture.hpp>
#include <libmm-gtk/gestureclick.hpp>
#include <libmm-gtk/gesturedrag.hpp>
#include <libmm-gtk/gesturelongpress.hpp>
#include <libmm-gtk/gesturepan.hpp>
#include <libmm-gtk/gesturerotate.hpp>
#include <libmm-gtk/gesturesingle.hpp>
#include <libmm-gtk/gesturestylus.hpp>
#include <libmm-gtk/gestureswipe.hpp>
#include <libmm-gtk/gesturezoom.hpp>
#include <libmm-gtk/glarea.hpp>
#include <libmm-gtk/grid.hpp>
#include <libmm-gtk/gridlayout.hpp>
#include <libmm-gtk/gridlayoutchild.hpp>
#include <libmm-gtk/gridview.hpp>
#include <libmm-gtk/headerbar.hpp>
#include <libmm-gtk/iconpaintable.hpp>
#include <libmm-gtk/icontheme.hpp>
#include <libmm-gtk/iconview.hpp>
#include <libmm-gtk/image.hpp>
#include <libmm-gtk/infobar.hpp>
#include <libmm-gtk/inscription.hpp>
#include <libmm-gtk/label.hpp>
#include <libmm-gtk/layoutchild.hpp>
#include <libmm-gtk/layoutmanager.hpp>
#include <libmm-gtk/levelbar.hpp>
#include <libmm-gtk/linkbutton.hpp>
#include <libmm-gtk/listbase.hpp>
#include <libmm-gtk/listbox.hpp>
#include <libmm-gtk/listboxrow.hpp>
#include <libmm-gtk/listitem.hpp>
#include <libmm-gtk/listitemfactory.hpp>
#include <libmm-gtk/liststore.hpp>
#include <libmm-gtk/listview.hpp>
#include <libmm-gtk/lockbutton.hpp>
#include <libmm-gtk/mediacontrols.hpp>
#include <libmm-gtk/mediafile.hpp>
#include <libmm-gtk/mediastream.hpp>
#include <libmm-gtk/menubutton.hpp>
#include <libmm-gtk/messagedialog.hpp>
#include <libmm-gtk/multifilter.hpp>
#include <libmm-gtk/multiselection.hpp>
#include <libmm-gtk/multisorter.hpp>
#include <libmm-gtk/native.hpp>
#include <libmm-gtk/nativedialog.hpp>
#include <libmm-gtk/noselection.hpp>
#include <libmm-gtk/notebook.hpp>
#include <libmm-gtk/notebookpage.hpp>
#include <libmm-gtk/numericsorter.hpp>
#include <libmm-gtk/orientable.hpp>
#include <libmm-gtk/overlay.hpp>
#include <libmm-gtk/padactionentry.hpp>
#include <libmm-gtk/padcontroller.hpp>
#include <libmm-gtk/pagesetup.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/pagesetupunixdialog.hpp>
#endif // ifndef G_OS_WIN32
#include <libmm-gtk/paned.hpp>
#include <libmm-gtk/papersize.hpp>
#include <libmm-gtk/passwordentry.hpp>
#include <libmm-gtk/picture.hpp>
#include <libmm-gtk/popover.hpp>
#include <libmm-gtk/popovermenu.hpp>
#include <libmm-gtk/popovermenubar.hpp>
#include <libmm-gtk/printcontext.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/printer.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gtk/printjob.hpp>
#endif // ifndef G_OS_WIN32
#include <libmm-gtk/printoperation.hpp>
#include <libmm-gtk/printoperationpreview.hpp>
#include <libmm-gtk/printsettings.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/printunixdialog.hpp>
#endif // ifndef G_OS_WIN32
#include <libmm-gtk/progressbar.hpp>
#include <libmm-gtk/range.hpp>
#include <libmm-gtk/recentinfo.hpp>
#include <libmm-gtk/recentmanager.hpp>
#include <libmm-gtk/requisition.hpp>
#include <libmm-gtk/revealer.hpp>
#include <libmm-gtk/root.hpp>
#include <libmm-gtk/scale.hpp>
#include <libmm-gtk/scalebutton.hpp>
#include <libmm-gtk/scrollable.hpp>
#include <libmm-gtk/scrollbar.hpp>
#include <libmm-gtk/scrolledwindow.hpp>
#include <libmm-gtk/searchbar.hpp>
#include <libmm-gtk/searchentry.hpp>
#include <libmm-gtk/selectionfiltermodel.hpp>
#include <libmm-gtk/selectionmodel.hpp>
#include <libmm-gtk/separator.hpp>
#include <libmm-gtk/settings.hpp>
#include <libmm-gtk/shortcut.hpp>
#include <libmm-gtk/shortcutaction.hpp>
#include <libmm-gtk/shortcutcontroller.hpp>
#include <libmm-gtk/shortcutlabel.hpp>
#include <libmm-gtk/shortcutmanager.hpp>
#include <libmm-gtk/shortcutsgroup.hpp>
#include <libmm-gtk/shortcutssection.hpp>
#include <libmm-gtk/shortcutsshortcut.hpp>
#include <libmm-gtk/shortcutswindow.hpp>
#include <libmm-gtk/shortcuttrigger.hpp>
#include <libmm-gtk/signallistitemfactory.hpp>
#include <libmm-gtk/singleselection.hpp>
#include <libmm-gtk/sizegroup.hpp>
#include <libmm-gtk/slicelistmodel.hpp>
#include <libmm-gtk/snapshot.hpp>
#include <libmm-gtk/sorter.hpp>
#include <libmm-gtk/sortlistmodel.hpp>
#include <libmm-gtk/spinbutton.hpp>
#include <libmm-gtk/spinner.hpp>
#include <libmm-gtk/stack.hpp>
#include <libmm-gtk/stackpage.hpp>
#include <libmm-gtk/stacksidebar.hpp>
#include <libmm-gtk/stackswitcher.hpp>
#include <libmm-gtk/statusbar.hpp>
#include <libmm-gtk/stringfilter.hpp>
#include <libmm-gtk/stringlist.hpp>
#include <libmm-gtk/stringobject.hpp>
#include <libmm-gtk/stringsorter.hpp>
#include <libmm-gtk/stylecontext.hpp>
#include <libmm-gtk/styleprovider.hpp>
#include <libmm-gtk/switch.hpp>
#include <libmm-gtk/text.hpp>
#include <libmm-gtk/textbuffer.hpp>
#include <libmm-gtk/textchildanchor.hpp>
#include <libmm-gtk/textiter.hpp>
#include <libmm-gtk/textmark.hpp>
#include <libmm-gtk/texttag.hpp>
#include <libmm-gtk/texttagtable.hpp>
#include <libmm-gtk/textview.hpp>
#include <libmm-gtk/togglebutton.hpp>
#include <libmm-gtk/tooltip.hpp>
#include <libmm-gtk/treedragdest.hpp>
#include <libmm-gtk/treedragsource.hpp>
#include <libmm-gtk/treeexpander.hpp>
#include <libmm-gtk/treeiter.hpp>
#include <libmm-gtk/treelistmodel.hpp>
#include <libmm-gtk/treelistrow.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gtk/treemodelfilter.hpp>
#include <libmm-gtk/treemodelsort.hpp>
#include <libmm-gtk/treepath.hpp>
#include <libmm-gtk/treerowreference.hpp>
#include <libmm-gtk/treeselection.hpp>
#include <libmm-gtk/treesortable.hpp>
#include <libmm-gtk/treestore.hpp>
#include <libmm-gtk/treeview.hpp>
#include <libmm-gtk/treeviewcolumn.hpp>
#include <libmm-gtk/video.hpp>
#include <libmm-gtk/viewport.hpp>
#include <libmm-gtk/volumebutton.hpp>
#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/widgetpaintable.hpp>
#include <libmm-gtk/window.hpp>
#include <libmm-gtk/windowcontrols.hpp>
#include <libmm-gtk/windowgroup.hpp>
#include <libmm-gtk/windowhandle.hpp>

extern "C"
{
//Declarations of the *_get_type() functions:

auto gtk_about_dialog_get_type(void) -> GType;
auto gtk_action_bar_get_type(void) -> GType;
auto gtk_adjustment_get_type(void) -> GType;
auto gtk_app_chooser_button_get_type(void) -> GType;
auto gtk_app_chooser_dialog_get_type(void) -> GType;
auto gtk_app_chooser_widget_get_type(void) -> GType;
auto gtk_application_get_type(void) -> GType;
auto gtk_application_window_get_type(void) -> GType;
auto gtk_aspect_frame_get_type(void) -> GType;
auto gtk_assistant_get_type(void) -> GType;
auto gtk_assistant_page_get_type(void) -> GType;
auto gtk_bin_layout_get_type(void) -> GType;
auto gtk_bool_filter_get_type(void) -> GType;
auto gtk_box_get_type(void) -> GType;
auto gtk_box_layout_get_type(void) -> GType;
auto gtk_builder_get_type(void) -> GType;
auto gtk_builder_cscope_get_type(void) -> GType;
auto gtk_button_get_type(void) -> GType;
auto gtk_calendar_get_type(void) -> GType;
auto gtk_cell_area_get_type(void) -> GType;
auto gtk_cell_area_box_get_type(void) -> GType;
auto gtk_cell_area_context_get_type(void) -> GType;
auto gtk_cell_renderer_get_type(void) -> GType;
auto gtk_cell_renderer_accel_get_type(void) -> GType;
auto gtk_cell_renderer_combo_get_type(void) -> GType;
auto gtk_cell_renderer_pixbuf_get_type(void) -> GType;
auto gtk_cell_renderer_progress_get_type(void) -> GType;
auto gtk_cell_renderer_spin_get_type(void) -> GType;
auto gtk_cell_renderer_spinner_get_type(void) -> GType;
auto gtk_cell_renderer_text_get_type(void) -> GType;
auto gtk_cell_renderer_toggle_get_type(void) -> GType;
auto gtk_cell_view_get_type(void) -> GType;
auto gtk_center_box_get_type(void) -> GType;
auto gtk_center_layout_get_type(void) -> GType;
auto gtk_check_button_get_type(void) -> GType;
auto gtk_color_button_get_type(void) -> GType;
auto gtk_color_chooser_dialog_get_type(void) -> GType;
auto gtk_column_view_get_type(void) -> GType;
auto gtk_column_view_column_get_type(void) -> GType;
auto gtk_combo_box_get_type(void) -> GType;
auto gtk_combo_box_text_get_type(void) -> GType;
auto gtk_constraint_get_type(void) -> GType;
auto gtk_constraint_guide_get_type(void) -> GType;
auto gtk_constraint_layout_get_type(void) -> GType;
auto gtk_css_provider_get_type(void) -> GType;
auto gtk_dialog_get_type(void) -> GType;
auto gtk_directory_list_get_type(void) -> GType;
auto gtk_drag_icon_get_type(void) -> GType;
auto gtk_drag_source_get_type(void) -> GType;
auto gtk_drawing_area_get_type(void) -> GType;
auto gtk_drop_controller_motion_get_type(void) -> GType;
auto gtk_drop_down_get_type(void) -> GType;
auto gtk_drop_target_get_type(void) -> GType;
auto gtk_drop_target_async_get_type(void) -> GType;
auto gtk_editable_label_get_type(void) -> GType;
auto gtk_emoji_chooser_get_type(void) -> GType;
auto gtk_entry_get_type(void) -> GType;
auto gtk_entry_buffer_get_type(void) -> GType;
auto gtk_entry_completion_get_type(void) -> GType;
auto gtk_event_controller_get_type(void) -> GType;
auto gtk_event_controller_focus_get_type(void) -> GType;
auto gtk_event_controller_key_get_type(void) -> GType;
auto gtk_event_controller_legacy_get_type(void) -> GType;
auto gtk_event_controller_motion_get_type(void) -> GType;
auto gtk_event_controller_scroll_get_type(void) -> GType;
auto gtk_expander_get_type(void) -> GType;
auto gtk_file_chooser_dialog_get_type(void) -> GType;
auto gtk_file_chooser_native_get_type(void) -> GType;
auto gtk_file_chooser_widget_get_type(void) -> GType;
auto gtk_file_filter_get_type(void) -> GType;
auto gtk_filter_get_type(void) -> GType;
auto gtk_filter_list_model_get_type(void) -> GType;
auto gtk_fixed_get_type(void) -> GType;
auto gtk_flatten_list_model_get_type(void) -> GType;
auto gtk_flow_box_get_type(void) -> GType;
auto gtk_flow_box_child_get_type(void) -> GType;
auto gtk_font_button_get_type(void) -> GType;
auto gtk_font_chooser_dialog_get_type(void) -> GType;
auto gtk_font_chooser_widget_get_type(void) -> GType;
auto gtk_frame_get_type(void) -> GType;
auto gtk_gesture_get_type(void) -> GType;
auto gtk_gesture_click_get_type(void) -> GType;
auto gtk_gesture_drag_get_type(void) -> GType;
auto gtk_gesture_long_press_get_type(void) -> GType;
auto gtk_gesture_pan_get_type(void) -> GType;
auto gtk_gesture_rotate_get_type(void) -> GType;
auto gtk_gesture_single_get_type(void) -> GType;
auto gtk_gesture_stylus_get_type(void) -> GType;
auto gtk_gesture_swipe_get_type(void) -> GType;
auto gtk_gesture_zoom_get_type(void) -> GType;
auto gtk_gl_area_get_type(void) -> GType;
auto gtk_grid_get_type(void) -> GType;
auto gtk_grid_layout_get_type(void) -> GType;
auto gtk_grid_layout_child_get_type(void) -> GType;
auto gtk_grid_view_get_type(void) -> GType;
auto gtk_header_bar_get_type(void) -> GType;
auto gtk_icon_paintable_get_type(void) -> GType;
auto gtk_icon_theme_get_type(void) -> GType;
auto gtk_icon_view_get_type(void) -> GType;
auto gtk_image_get_type(void) -> GType;
auto gtk_info_bar_get_type(void) -> GType;
auto gtk_inscription_get_type(void) -> GType;
auto gtk_label_get_type(void) -> GType;
auto gtk_layout_child_get_type(void) -> GType;
auto gtk_layout_manager_get_type(void) -> GType;
auto gtk_level_bar_get_type(void) -> GType;
auto gtk_link_button_get_type(void) -> GType;
auto gtk_list_base_get_type(void) -> GType;
auto gtk_list_box_get_type(void) -> GType;
auto gtk_list_box_row_get_type(void) -> GType;
auto gtk_list_item_get_type(void) -> GType;
auto gtk_list_item_factory_get_type(void) -> GType;
auto gtk_list_store_get_type(void) -> GType;
auto gtk_list_view_get_type(void) -> GType;
auto gtk_lock_button_get_type(void) -> GType;
auto gtk_media_controls_get_type(void) -> GType;
auto gtk_media_file_get_type(void) -> GType;
auto gtk_media_stream_get_type(void) -> GType;
auto gtk_menu_button_get_type(void) -> GType;
auto gtk_message_dialog_get_type(void) -> GType;
auto gtk_multi_filter_get_type(void) -> GType;
auto gtk_any_filter_get_type(void) -> GType;
auto gtk_every_filter_get_type(void) -> GType;
auto gtk_multi_selection_get_type(void) -> GType;
auto gtk_multi_sorter_get_type(void) -> GType;
auto gtk_native_dialog_get_type(void) -> GType;
auto gtk_no_selection_get_type(void) -> GType;
auto gtk_notebook_get_type(void) -> GType;
auto gtk_notebook_page_get_type(void) -> GType;
auto gtk_numeric_sorter_get_type(void) -> GType;
auto gtk_overlay_get_type(void) -> GType;
auto gtk_pad_controller_get_type(void) -> GType;
auto gtk_page_setup_get_type(void) -> GType;
#ifndef G_OS_WIN32
auto gtk_page_setup_unix_dialog_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
auto gtk_paned_get_type(void) -> GType;
auto gtk_password_entry_get_type(void) -> GType;
auto gtk_picture_get_type(void) -> GType;
auto gtk_popover_get_type(void) -> GType;
auto gtk_popover_menu_get_type(void) -> GType;
auto gtk_popover_menu_bar_get_type(void) -> GType;
auto gtk_print_context_get_type(void) -> GType;
#ifndef G_OS_WIN32
auto gtk_printer_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto gtk_print_job_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
auto gtk_print_operation_get_type(void) -> GType;
auto gtk_print_settings_get_type(void) -> GType;
#ifndef G_OS_WIN32
auto gtk_print_unix_dialog_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
auto gtk_progress_bar_get_type(void) -> GType;
auto gtk_range_get_type(void) -> GType;
auto gtk_recent_manager_get_type(void) -> GType;
auto gtk_revealer_get_type(void) -> GType;
auto gtk_scale_get_type(void) -> GType;
auto gtk_scale_button_get_type(void) -> GType;
auto gtk_scrollbar_get_type(void) -> GType;
auto gtk_scrolled_window_get_type(void) -> GType;
auto gtk_search_bar_get_type(void) -> GType;
auto gtk_search_entry_get_type(void) -> GType;
auto gtk_selection_filter_model_get_type(void) -> GType;
auto gtk_separator_get_type(void) -> GType;
auto gtk_settings_get_type(void) -> GType;
auto gtk_shortcut_get_type(void) -> GType;
auto gtk_shortcut_action_get_type(void) -> GType;
auto gtk_nothing_action_get_type(void) -> GType;
auto gtk_callback_action_get_type(void) -> GType;
auto gtk_mnemonic_action_get_type(void) -> GType;
auto gtk_activate_action_get_type(void) -> GType;
auto gtk_signal_action_get_type(void) -> GType;
auto gtk_named_action_get_type(void) -> GType;
auto gtk_shortcut_controller_get_type(void) -> GType;
auto gtk_shortcut_label_get_type(void) -> GType;
auto gtk_shortcuts_group_get_type(void) -> GType;
auto gtk_shortcuts_section_get_type(void) -> GType;
auto gtk_shortcuts_shortcut_get_type(void) -> GType;
auto gtk_shortcuts_window_get_type(void) -> GType;
auto gtk_shortcut_trigger_get_type(void) -> GType;
auto gtk_never_trigger_get_type(void) -> GType;
auto gtk_keyval_trigger_get_type(void) -> GType;
auto gtk_mnemonic_trigger_get_type(void) -> GType;
auto gtk_alternative_trigger_get_type(void) -> GType;
auto gtk_signal_list_item_factory_get_type(void) -> GType;
auto gtk_single_selection_get_type(void) -> GType;
auto gtk_size_group_get_type(void) -> GType;
auto gtk_slice_list_model_get_type(void) -> GType;
auto gtk_snapshot_get_type(void) -> GType;
auto gtk_sorter_get_type(void) -> GType;
auto gtk_sort_list_model_get_type(void) -> GType;
auto gtk_spin_button_get_type(void) -> GType;
auto gtk_spinner_get_type(void) -> GType;
auto gtk_stack_get_type(void) -> GType;
auto gtk_stack_page_get_type(void) -> GType;
auto gtk_stack_sidebar_get_type(void) -> GType;
auto gtk_stack_switcher_get_type(void) -> GType;
auto gtk_statusbar_get_type(void) -> GType;
auto gtk_string_filter_get_type(void) -> GType;
auto gtk_string_list_get_type(void) -> GType;
auto gtk_string_object_get_type(void) -> GType;
auto gtk_string_sorter_get_type(void) -> GType;
auto gtk_style_context_get_type(void) -> GType;
auto gtk_switch_get_type(void) -> GType;
auto gtk_text_get_type(void) -> GType;
auto gtk_text_buffer_get_type(void) -> GType;
auto gtk_text_child_anchor_get_type(void) -> GType;
auto gtk_text_mark_get_type(void) -> GType;
auto gtk_text_tag_get_type(void) -> GType;
auto gtk_text_tag_table_get_type(void) -> GType;
auto gtk_text_view_get_type(void) -> GType;
auto gtk_toggle_button_get_type(void) -> GType;
auto gtk_tooltip_get_type(void) -> GType;
auto gtk_tree_expander_get_type(void) -> GType;
auto gtk_tree_list_model_get_type(void) -> GType;
auto gtk_tree_list_row_get_type(void) -> GType;
auto gtk_tree_model_filter_get_type(void) -> GType;
auto gtk_tree_model_sort_get_type(void) -> GType;
auto gtk_tree_selection_get_type(void) -> GType;
auto gtk_tree_store_get_type(void) -> GType;
auto gtk_tree_view_get_type(void) -> GType;
auto gtk_tree_view_column_get_type(void) -> GType;
auto gtk_video_get_type(void) -> GType;
auto gtk_viewport_get_type(void) -> GType;
auto gtk_volume_button_get_type(void) -> GType;
auto gtk_widget_get_type(void) -> GType;
auto gtk_widget_paintable_get_type(void) -> GType;
auto gtk_window_get_type(void) -> GType;
auto gtk_window_controls_get_type(void) -> GType;
auto gtk_window_group_get_type(void) -> GType;
auto gtk_window_handle_get_type(void) -> GType;

//Declarations of the *_error_quark() functions:

auto gtk_builder_error_quark(void) -> GQuark;
auto gtk_constraint_vfl_parser_error_quark(void) -> GQuark;
auto gtk_css_parser_error_quark(void) -> GQuark;
auto gtk_css_parser_warning_quark(void) -> GQuark;
auto gtk_file_chooser_error_quark(void) -> GQuark;
auto gtk_icon_theme_error_quark(void) -> GQuark;
auto gtk_print_error_quark(void) -> GQuark;
auto gtk_recent_manager_error_quark(void) -> GQuark;
} // extern "C"

namespace Gtk {

//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

class AboutDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ActionBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Adjustment_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AppChooserButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AppChooserDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AppChooserWidget_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Application_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ApplicationWindow_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AspectFrame_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Assistant_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AssistantPage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BinLayout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BoolFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Box_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BoxLayout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Builder_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BuilderCScope_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Button_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Calendar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellArea_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellAreaBox_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellAreaContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRenderer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererAccel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererCombo_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererPixbuf_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererProgress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererSpin_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererSpinner_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererText_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellRendererToggle_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CellView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CenterBox_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CenterLayout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CheckButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ColorButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ColorChooserDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ColumnView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ColumnViewColumn_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ComboBox_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ComboBoxText_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Constraint_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ConstraintGuide_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ConstraintLayout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CssProvider_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Dialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DirectoryList_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DragIcon_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DragSource_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DrawingArea_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DropControllerMotion_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DropDown_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DropTarget_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DropTargetAsync_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EditableLabel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EmojiChooser_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Entry_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EntryBuffer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EntryCompletion_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventController_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventControllerFocus_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventControllerKey_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventControllerLegacy_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventControllerMotion_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EventControllerScroll_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Expander_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileChooserDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileChooserNative_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileChooserWidget_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Filter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FilterListModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Fixed_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FlattenListModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FlowBox_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FlowBoxChild_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontChooserDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FontChooserWidget_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Frame_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Gesture_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureClick_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureDrag_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureLongPress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GesturePan_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureRotate_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureSingle_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureStylus_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureSwipe_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GestureZoom_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GLArea_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Grid_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GridLayout_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GridLayoutChild_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class GridView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class HeaderBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class IconPaintable_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class IconTheme_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class IconView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Image_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class InfoBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Inscription_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Label_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class LayoutChild_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class LayoutManager_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class LevelBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class LinkButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListBase_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListBox_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListBoxRow_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListItem_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListItemFactory_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListStore_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class LockButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MediaControls_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MediaFile_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MediaStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MenuButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MessageDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MultiFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AnyFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EveryFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MultiSelection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MultiSorter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NativeDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NoSelection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Notebook_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NotebookPage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NumericSorterBase_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Overlay_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PadController_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PageSetup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#ifndef G_OS_WIN32
class PageSetupUnixDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
class Paned_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PasswordEntry_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Picture_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Popover_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PopoverMenu_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PopoverMenuBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PrintContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#ifndef G_OS_WIN32
class Printer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class PrintJob_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
class PrintOperation_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PrintSettings_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#ifndef G_OS_WIN32
class PrintUnixDialog_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
class ProgressBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Range_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class RecentManager_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Revealer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Scale_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ScaleButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Scrollbar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ScrolledWindow_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SearchBar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SearchEntry_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SelectionFilterModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Separator_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Settings_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Shortcut_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NothingAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CallbackAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MnemonicAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ActivateAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SignalAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NamedAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutController_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutLabel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutsGroup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutsSection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutsShortcut_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutsWindow_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ShortcutTrigger_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NeverTrigger_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class KeyvalTrigger_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MnemonicTrigger_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AlternativeTrigger_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SignalListItemFactory_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SingleSelection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SizeGroup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SliceListModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Snapshot_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Sorter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SortListModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SpinButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Spinner_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Stack_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StackPage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StackSidebar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StackSwitcher_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Statusbar_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StringFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StringList_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StringObject_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StringSorter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class StyleContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Switch_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Text_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextBuffer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextChildAnchor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextMark_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextTag_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextTagTable_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TextView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ToggleButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Tooltip_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeExpander_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeListModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeListRow_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeModelFilter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeModelSort_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeSelection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeStore_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeView_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TreeViewColumn_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Video_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Viewport_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class VolumeButton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Widget_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class WidgetPaintable_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Window_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class WindowControls_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class WindowGroup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class WindowHandle_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };

auto wrap_init () -> void
{
  // Register Error domains in the main namespace:
  Glib::Error::register_domain(gtk_builder_error_quark(), &BuilderError::throw_func);
  Glib::Error::register_domain(gtk_constraint_vfl_parser_error_quark(), &ConstraintVflParserError::throw_func);
  Glib::Error::register_domain(gtk_css_parser_error_quark(), &CssParserError::throw_func);
  Glib::Error::register_domain(gtk_css_parser_warning_quark(), &CssParserWarning::throw_func);
  Glib::Error::register_domain(gtk_file_chooser_error_quark(), &FileChooserError::throw_func);
  Glib::Error::register_domain(gtk_icon_theme_error_quark(), &IconThemeError::throw_func);
  Glib::Error::register_domain(gtk_print_error_quark(), &PrintError::throw_func);
  Glib::Error::register_domain(gtk_recent_manager_error_quark(), &RecentManagerError::throw_func);

  // Map gtypes to gtkmm wrapper-creation functions:
  wrap_register(gtk_about_dialog_get_type(), &AboutDialog_Class::wrap_new);
  wrap_register(gtk_action_bar_get_type(), &ActionBar_Class::wrap_new);
  wrap_register(gtk_adjustment_get_type(), &Adjustment_Class::wrap_new);
  wrap_register(gtk_app_chooser_button_get_type(), &AppChooserButton_Class::wrap_new);
  wrap_register(gtk_app_chooser_dialog_get_type(), &AppChooserDialog_Class::wrap_new);
  wrap_register(gtk_app_chooser_widget_get_type(), &AppChooserWidget_Class::wrap_new);
  wrap_register(gtk_application_get_type(), &Application_Class::wrap_new);
  wrap_register(gtk_application_window_get_type(), &ApplicationWindow_Class::wrap_new);
  wrap_register(gtk_aspect_frame_get_type(), &AspectFrame_Class::wrap_new);
  wrap_register(gtk_assistant_get_type(), &Assistant_Class::wrap_new);
  wrap_register(gtk_assistant_page_get_type(), &AssistantPage_Class::wrap_new);
  wrap_register(gtk_bin_layout_get_type(), &BinLayout_Class::wrap_new);
  wrap_register(gtk_bool_filter_get_type(), &BoolFilter_Class::wrap_new);
  wrap_register(gtk_box_get_type(), &Box_Class::wrap_new);
  wrap_register(gtk_box_layout_get_type(), &BoxLayout_Class::wrap_new);
  wrap_register(gtk_builder_get_type(), &Builder_Class::wrap_new);
  wrap_register(gtk_builder_cscope_get_type(), &BuilderCScope_Class::wrap_new);
  wrap_register(gtk_button_get_type(), &Button_Class::wrap_new);
  wrap_register(gtk_calendar_get_type(), &Calendar_Class::wrap_new);
  wrap_register(gtk_cell_area_get_type(), &CellArea_Class::wrap_new);
  wrap_register(gtk_cell_area_box_get_type(), &CellAreaBox_Class::wrap_new);
  wrap_register(gtk_cell_area_context_get_type(), &CellAreaContext_Class::wrap_new);
  wrap_register(gtk_cell_renderer_get_type(), &CellRenderer_Class::wrap_new);
  wrap_register(gtk_cell_renderer_accel_get_type(), &CellRendererAccel_Class::wrap_new);
  wrap_register(gtk_cell_renderer_combo_get_type(), &CellRendererCombo_Class::wrap_new);
  wrap_register(gtk_cell_renderer_pixbuf_get_type(), &CellRendererPixbuf_Class::wrap_new);
  wrap_register(gtk_cell_renderer_progress_get_type(), &CellRendererProgress_Class::wrap_new);
  wrap_register(gtk_cell_renderer_spin_get_type(), &CellRendererSpin_Class::wrap_new);
  wrap_register(gtk_cell_renderer_spinner_get_type(), &CellRendererSpinner_Class::wrap_new);
  wrap_register(gtk_cell_renderer_text_get_type(), &CellRendererText_Class::wrap_new);
  wrap_register(gtk_cell_renderer_toggle_get_type(), &CellRendererToggle_Class::wrap_new);
  wrap_register(gtk_cell_view_get_type(), &CellView_Class::wrap_new);
  wrap_register(gtk_center_box_get_type(), &CenterBox_Class::wrap_new);
  wrap_register(gtk_center_layout_get_type(), &CenterLayout_Class::wrap_new);
  wrap_register(gtk_check_button_get_type(), &CheckButton_Class::wrap_new);
  wrap_register(gtk_color_button_get_type(), &ColorButton_Class::wrap_new);
  wrap_register(gtk_color_chooser_dialog_get_type(), &ColorChooserDialog_Class::wrap_new);
  wrap_register(gtk_column_view_get_type(), &ColumnView_Class::wrap_new);
  wrap_register(gtk_column_view_column_get_type(), &ColumnViewColumn_Class::wrap_new);
  wrap_register(gtk_combo_box_get_type(), &ComboBox_Class::wrap_new);
  wrap_register(gtk_combo_box_text_get_type(), &ComboBoxText_Class::wrap_new);
  wrap_register(gtk_constraint_get_type(), &Constraint_Class::wrap_new);
  wrap_register(gtk_constraint_guide_get_type(), &ConstraintGuide_Class::wrap_new);
  wrap_register(gtk_constraint_layout_get_type(), &ConstraintLayout_Class::wrap_new);
  wrap_register(gtk_css_provider_get_type(), &CssProvider_Class::wrap_new);
  wrap_register(gtk_dialog_get_type(), &Dialog_Class::wrap_new);
  wrap_register(gtk_directory_list_get_type(), &DirectoryList_Class::wrap_new);
  wrap_register(gtk_drag_icon_get_type(), &DragIcon_Class::wrap_new);
  wrap_register(gtk_drag_source_get_type(), &DragSource_Class::wrap_new);
  wrap_register(gtk_drawing_area_get_type(), &DrawingArea_Class::wrap_new);
  wrap_register(gtk_drop_controller_motion_get_type(), &DropControllerMotion_Class::wrap_new);
  wrap_register(gtk_drop_down_get_type(), &DropDown_Class::wrap_new);
  wrap_register(gtk_drop_target_get_type(), &DropTarget_Class::wrap_new);
  wrap_register(gtk_drop_target_async_get_type(), &DropTargetAsync_Class::wrap_new);
  wrap_register(gtk_editable_label_get_type(), &EditableLabel_Class::wrap_new);
  wrap_register(gtk_emoji_chooser_get_type(), &EmojiChooser_Class::wrap_new);
  wrap_register(gtk_entry_get_type(), &Entry_Class::wrap_new);
  wrap_register(gtk_entry_buffer_get_type(), &EntryBuffer_Class::wrap_new);
  wrap_register(gtk_entry_completion_get_type(), &EntryCompletion_Class::wrap_new);
  wrap_register(gtk_event_controller_get_type(), &EventController_Class::wrap_new);
  wrap_register(gtk_event_controller_focus_get_type(), &EventControllerFocus_Class::wrap_new);
  wrap_register(gtk_event_controller_key_get_type(), &EventControllerKey_Class::wrap_new);
  wrap_register(gtk_event_controller_legacy_get_type(), &EventControllerLegacy_Class::wrap_new);
  wrap_register(gtk_event_controller_motion_get_type(), &EventControllerMotion_Class::wrap_new);
  wrap_register(gtk_event_controller_scroll_get_type(), &EventControllerScroll_Class::wrap_new);
  wrap_register(gtk_expander_get_type(), &Expander_Class::wrap_new);
  wrap_register(gtk_file_chooser_dialog_get_type(), &FileChooserDialog_Class::wrap_new);
  wrap_register(gtk_file_chooser_native_get_type(), &FileChooserNative_Class::wrap_new);
  wrap_register(gtk_file_chooser_widget_get_type(), &FileChooserWidget_Class::wrap_new);
  wrap_register(gtk_file_filter_get_type(), &FileFilter_Class::wrap_new);
  wrap_register(gtk_filter_get_type(), &Filter_Class::wrap_new);
  wrap_register(gtk_filter_list_model_get_type(), &FilterListModel_Class::wrap_new);
  wrap_register(gtk_fixed_get_type(), &Fixed_Class::wrap_new);
  wrap_register(gtk_flatten_list_model_get_type(), &FlattenListModel_Class::wrap_new);
  wrap_register(gtk_flow_box_get_type(), &FlowBox_Class::wrap_new);
  wrap_register(gtk_flow_box_child_get_type(), &FlowBoxChild_Class::wrap_new);
  wrap_register(gtk_font_button_get_type(), &FontButton_Class::wrap_new);
  wrap_register(gtk_font_chooser_dialog_get_type(), &FontChooserDialog_Class::wrap_new);
  wrap_register(gtk_font_chooser_widget_get_type(), &FontChooserWidget_Class::wrap_new);
  wrap_register(gtk_frame_get_type(), &Frame_Class::wrap_new);
  wrap_register(gtk_gesture_get_type(), &Gesture_Class::wrap_new);
  wrap_register(gtk_gesture_click_get_type(), &GestureClick_Class::wrap_new);
  wrap_register(gtk_gesture_drag_get_type(), &GestureDrag_Class::wrap_new);
  wrap_register(gtk_gesture_long_press_get_type(), &GestureLongPress_Class::wrap_new);
  wrap_register(gtk_gesture_pan_get_type(), &GesturePan_Class::wrap_new);
  wrap_register(gtk_gesture_rotate_get_type(), &GestureRotate_Class::wrap_new);
  wrap_register(gtk_gesture_single_get_type(), &GestureSingle_Class::wrap_new);
  wrap_register(gtk_gesture_stylus_get_type(), &GestureStylus_Class::wrap_new);
  wrap_register(gtk_gesture_swipe_get_type(), &GestureSwipe_Class::wrap_new);
  wrap_register(gtk_gesture_zoom_get_type(), &GestureZoom_Class::wrap_new);
  wrap_register(gtk_gl_area_get_type(), &GLArea_Class::wrap_new);
  wrap_register(gtk_grid_get_type(), &Grid_Class::wrap_new);
  wrap_register(gtk_grid_layout_get_type(), &GridLayout_Class::wrap_new);
  wrap_register(gtk_grid_layout_child_get_type(), &GridLayoutChild_Class::wrap_new);
  wrap_register(gtk_grid_view_get_type(), &GridView_Class::wrap_new);
  wrap_register(gtk_header_bar_get_type(), &HeaderBar_Class::wrap_new);
  wrap_register(gtk_icon_paintable_get_type(), &IconPaintable_Class::wrap_new);
  wrap_register(gtk_icon_theme_get_type(), &IconTheme_Class::wrap_new);
  wrap_register(gtk_icon_view_get_type(), &IconView_Class::wrap_new);
  wrap_register(gtk_image_get_type(), &Image_Class::wrap_new);
  wrap_register(gtk_info_bar_get_type(), &InfoBar_Class::wrap_new);
  wrap_register(gtk_inscription_get_type(), &Inscription_Class::wrap_new);
  wrap_register(gtk_label_get_type(), &Label_Class::wrap_new);
  wrap_register(gtk_layout_child_get_type(), &LayoutChild_Class::wrap_new);
  wrap_register(gtk_layout_manager_get_type(), &LayoutManager_Class::wrap_new);
  wrap_register(gtk_level_bar_get_type(), &LevelBar_Class::wrap_new);
  wrap_register(gtk_link_button_get_type(), &LinkButton_Class::wrap_new);
  wrap_register(gtk_list_base_get_type(), &ListBase_Class::wrap_new);
  wrap_register(gtk_list_box_get_type(), &ListBox_Class::wrap_new);
  wrap_register(gtk_list_box_row_get_type(), &ListBoxRow_Class::wrap_new);
  wrap_register(gtk_list_item_get_type(), &ListItem_Class::wrap_new);
  wrap_register(gtk_list_item_factory_get_type(), &ListItemFactory_Class::wrap_new);
  wrap_register(gtk_list_store_get_type(), &ListStore_Class::wrap_new);
  wrap_register(gtk_list_view_get_type(), &ListView_Class::wrap_new);
  wrap_register(gtk_lock_button_get_type(), &LockButton_Class::wrap_new);
  wrap_register(gtk_media_controls_get_type(), &MediaControls_Class::wrap_new);
  wrap_register(gtk_media_file_get_type(), &MediaFile_Class::wrap_new);
  wrap_register(gtk_media_stream_get_type(), &MediaStream_Class::wrap_new);
  wrap_register(gtk_menu_button_get_type(), &MenuButton_Class::wrap_new);
  wrap_register(gtk_message_dialog_get_type(), &MessageDialog_Class::wrap_new);
  wrap_register(gtk_multi_filter_get_type(), &MultiFilter_Class::wrap_new);
  wrap_register(gtk_any_filter_get_type(), &AnyFilter_Class::wrap_new);
  wrap_register(gtk_every_filter_get_type(), &EveryFilter_Class::wrap_new);
  wrap_register(gtk_multi_selection_get_type(), &MultiSelection_Class::wrap_new);
  wrap_register(gtk_multi_sorter_get_type(), &MultiSorter_Class::wrap_new);
  wrap_register(gtk_native_dialog_get_type(), &NativeDialog_Class::wrap_new);
  wrap_register(gtk_no_selection_get_type(), &NoSelection_Class::wrap_new);
  wrap_register(gtk_notebook_get_type(), &Notebook_Class::wrap_new);
  wrap_register(gtk_notebook_page_get_type(), &NotebookPage_Class::wrap_new);
  wrap_register(gtk_numeric_sorter_get_type(), &NumericSorterBase_Class::wrap_new);
  wrap_register(gtk_overlay_get_type(), &Overlay_Class::wrap_new);
  wrap_register(gtk_pad_controller_get_type(), &PadController_Class::wrap_new);
  wrap_register(gtk_page_setup_get_type(), &PageSetup_Class::wrap_new);
#ifndef G_OS_WIN32
  Glib::wrap_register(gtk_page_setup_unix_dialog_get_type(), &PageSetupUnixDialog_Class::wrap_new);
#endif // ifndef G_OS_WIN32
  wrap_register(gtk_paned_get_type(), &Paned_Class::wrap_new);
  wrap_register(gtk_password_entry_get_type(), &PasswordEntry_Class::wrap_new);
  wrap_register(gtk_picture_get_type(), &Picture_Class::wrap_new);
  wrap_register(gtk_popover_get_type(), &Popover_Class::wrap_new);
  wrap_register(gtk_popover_menu_get_type(), &PopoverMenu_Class::wrap_new);
  wrap_register(gtk_popover_menu_bar_get_type(), &PopoverMenuBar_Class::wrap_new);
  wrap_register(gtk_print_context_get_type(), &PrintContext_Class::wrap_new);
#ifndef G_OS_WIN32
  Glib::wrap_register(gtk_printer_get_type(), &Printer_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(gtk_print_job_get_type(), &PrintJob_Class::wrap_new);
#endif // ifndef G_OS_WIN32
  wrap_register(gtk_print_operation_get_type(), &PrintOperation_Class::wrap_new);
  wrap_register(gtk_print_settings_get_type(), &PrintSettings_Class::wrap_new);
#ifndef G_OS_WIN32
  Glib::wrap_register(gtk_print_unix_dialog_get_type(), &PrintUnixDialog_Class::wrap_new);
#endif // ifndef G_OS_WIN32
  wrap_register(gtk_progress_bar_get_type(), &ProgressBar_Class::wrap_new);
  wrap_register(gtk_range_get_type(), &Range_Class::wrap_new);
  wrap_register(gtk_recent_manager_get_type(), &RecentManager_Class::wrap_new);
  wrap_register(gtk_revealer_get_type(), &Revealer_Class::wrap_new);
  wrap_register(gtk_scale_get_type(), &Scale_Class::wrap_new);
  wrap_register(gtk_scale_button_get_type(), &ScaleButton_Class::wrap_new);
  wrap_register(gtk_scrollbar_get_type(), &Scrollbar_Class::wrap_new);
  wrap_register(gtk_scrolled_window_get_type(), &ScrolledWindow_Class::wrap_new);
  wrap_register(gtk_search_bar_get_type(), &SearchBar_Class::wrap_new);
  wrap_register(gtk_search_entry_get_type(), &SearchEntry_Class::wrap_new);
  wrap_register(gtk_selection_filter_model_get_type(), &SelectionFilterModel_Class::wrap_new);
  wrap_register(gtk_separator_get_type(), &Separator_Class::wrap_new);
  wrap_register(gtk_settings_get_type(), &Settings_Class::wrap_new);
  wrap_register(gtk_shortcut_get_type(), &Shortcut_Class::wrap_new);
  wrap_register(gtk_shortcut_action_get_type(), &ShortcutAction_Class::wrap_new);
  wrap_register(gtk_nothing_action_get_type(), &NothingAction_Class::wrap_new);
  wrap_register(gtk_callback_action_get_type(), &CallbackAction_Class::wrap_new);
  wrap_register(gtk_mnemonic_action_get_type(), &MnemonicAction_Class::wrap_new);
  wrap_register(gtk_activate_action_get_type(), &ActivateAction_Class::wrap_new);
  wrap_register(gtk_signal_action_get_type(), &SignalAction_Class::wrap_new);
  wrap_register(gtk_named_action_get_type(), &NamedAction_Class::wrap_new);
  wrap_register(gtk_shortcut_controller_get_type(), &ShortcutController_Class::wrap_new);
  wrap_register(gtk_shortcut_label_get_type(), &ShortcutLabel_Class::wrap_new);
  wrap_register(gtk_shortcuts_group_get_type(), &ShortcutsGroup_Class::wrap_new);
  wrap_register(gtk_shortcuts_section_get_type(), &ShortcutsSection_Class::wrap_new);
  wrap_register(gtk_shortcuts_shortcut_get_type(), &ShortcutsShortcut_Class::wrap_new);
  wrap_register(gtk_shortcuts_window_get_type(), &ShortcutsWindow_Class::wrap_new);
  wrap_register(gtk_shortcut_trigger_get_type(), &ShortcutTrigger_Class::wrap_new);
  wrap_register(gtk_never_trigger_get_type(), &NeverTrigger_Class::wrap_new);
  wrap_register(gtk_keyval_trigger_get_type(), &KeyvalTrigger_Class::wrap_new);
  wrap_register(gtk_mnemonic_trigger_get_type(), &MnemonicTrigger_Class::wrap_new);
  wrap_register(gtk_alternative_trigger_get_type(), &AlternativeTrigger_Class::wrap_new);
  wrap_register(gtk_signal_list_item_factory_get_type(), &SignalListItemFactory_Class::wrap_new);
  wrap_register(gtk_single_selection_get_type(), &SingleSelection_Class::wrap_new);
  wrap_register(gtk_size_group_get_type(), &SizeGroup_Class::wrap_new);
  wrap_register(gtk_slice_list_model_get_type(), &SliceListModel_Class::wrap_new);
  wrap_register(gtk_snapshot_get_type(), &Snapshot_Class::wrap_new);
  wrap_register(gtk_sorter_get_type(), &Sorter_Class::wrap_new);
  wrap_register(gtk_sort_list_model_get_type(), &SortListModel_Class::wrap_new);
  wrap_register(gtk_spin_button_get_type(), &SpinButton_Class::wrap_new);
  wrap_register(gtk_spinner_get_type(), &Spinner_Class::wrap_new);
  wrap_register(gtk_stack_get_type(), &Stack_Class::wrap_new);
  wrap_register(gtk_stack_page_get_type(), &StackPage_Class::wrap_new);
  wrap_register(gtk_stack_sidebar_get_type(), &StackSidebar_Class::wrap_new);
  wrap_register(gtk_stack_switcher_get_type(), &StackSwitcher_Class::wrap_new);
  wrap_register(gtk_statusbar_get_type(), &Statusbar_Class::wrap_new);
  wrap_register(gtk_string_filter_get_type(), &StringFilter_Class::wrap_new);
  wrap_register(gtk_string_list_get_type(), &StringList_Class::wrap_new);
  wrap_register(gtk_string_object_get_type(), &StringObject_Class::wrap_new);
  wrap_register(gtk_string_sorter_get_type(), &StringSorter_Class::wrap_new);
  wrap_register(gtk_style_context_get_type(), &StyleContext_Class::wrap_new);
  wrap_register(gtk_switch_get_type(), &Switch_Class::wrap_new);
  wrap_register(gtk_text_get_type(), &Text_Class::wrap_new);
  wrap_register(gtk_text_buffer_get_type(), &TextBuffer_Class::wrap_new);
  wrap_register(gtk_text_child_anchor_get_type(), &TextChildAnchor_Class::wrap_new);
  wrap_register(gtk_text_mark_get_type(), &TextMark_Class::wrap_new);
  wrap_register(gtk_text_tag_get_type(), &TextTag_Class::wrap_new);
  wrap_register(gtk_text_tag_table_get_type(), &TextTagTable_Class::wrap_new);
  wrap_register(gtk_text_view_get_type(), &TextView_Class::wrap_new);
  wrap_register(gtk_toggle_button_get_type(), &ToggleButton_Class::wrap_new);
  wrap_register(gtk_tooltip_get_type(), &Tooltip_Class::wrap_new);
  wrap_register(gtk_tree_expander_get_type(), &TreeExpander_Class::wrap_new);
  wrap_register(gtk_tree_list_model_get_type(), &TreeListModel_Class::wrap_new);
  wrap_register(gtk_tree_list_row_get_type(), &TreeListRow_Class::wrap_new);
  wrap_register(gtk_tree_model_filter_get_type(), &TreeModelFilter_Class::wrap_new);
  wrap_register(gtk_tree_model_sort_get_type(), &TreeModelSort_Class::wrap_new);
  wrap_register(gtk_tree_selection_get_type(), &TreeSelection_Class::wrap_new);
  wrap_register(gtk_tree_store_get_type(), &TreeStore_Class::wrap_new);
  wrap_register(gtk_tree_view_get_type(), &TreeView_Class::wrap_new);
  wrap_register(gtk_tree_view_column_get_type(), &TreeViewColumn_Class::wrap_new);
  wrap_register(gtk_video_get_type(), &Video_Class::wrap_new);
  wrap_register(gtk_viewport_get_type(), &Viewport_Class::wrap_new);
  wrap_register(gtk_volume_button_get_type(), &VolumeButton_Class::wrap_new);
  wrap_register(gtk_widget_get_type(), &Widget_Class::wrap_new);
  wrap_register(gtk_widget_paintable_get_type(), &WidgetPaintable_Class::wrap_new);
  wrap_register(gtk_window_get_type(), &Window_Class::wrap_new);
  wrap_register(gtk_window_controls_get_type(), &WindowControls_Class::wrap_new);
  wrap_register(gtk_window_group_get_type(), &WindowGroup_Class::wrap_new);
  wrap_register(gtk_window_handle_get_type(), &WindowHandle_Class::wrap_new);

  // Register the gtkmm gtypes:
  g_type_ensure(AboutDialog::get_type());
  g_type_ensure(ActionBar::get_type());
  g_type_ensure(Adjustment::get_type());
  g_type_ensure(AppChooserButton::get_type());
  g_type_ensure(AppChooserDialog::get_type());
  g_type_ensure(AppChooserWidget::get_type());
  g_type_ensure(Application::get_type());
  g_type_ensure(ApplicationWindow::get_type());
  g_type_ensure(AspectFrame::get_type());
  g_type_ensure(Assistant::get_type());
  g_type_ensure(AssistantPage::get_type());
  g_type_ensure(BinLayout::get_type());
  g_type_ensure(BoolFilter::get_type());
  g_type_ensure(Box::get_type());
  g_type_ensure(BoxLayout::get_type());
  g_type_ensure(Builder::get_type());
  g_type_ensure(BuilderCScope::get_type());
  g_type_ensure(Button::get_type());
  g_type_ensure(Calendar::get_type());
  g_type_ensure(CellArea::get_type());
  g_type_ensure(CellAreaBox::get_type());
  g_type_ensure(CellAreaContext::get_type());
  g_type_ensure(CellRenderer::get_type());
  g_type_ensure(CellRendererAccel::get_type());
  g_type_ensure(CellRendererCombo::get_type());
  g_type_ensure(CellRendererPixbuf::get_type());
  g_type_ensure(CellRendererProgress::get_type());
  g_type_ensure(CellRendererSpin::get_type());
  g_type_ensure(CellRendererSpinner::get_type());
  g_type_ensure(CellRendererText::get_type());
  g_type_ensure(CellRendererToggle::get_type());
  g_type_ensure(CellView::get_type());
  g_type_ensure(CenterBox::get_type());
  g_type_ensure(CenterLayout::get_type());
  g_type_ensure(CheckButton::get_type());
  g_type_ensure(ColorButton::get_type());
  g_type_ensure(ColorChooserDialog::get_type());
  g_type_ensure(ColumnView::get_type());
  g_type_ensure(ColumnViewColumn::get_type());
  g_type_ensure(ComboBox::get_type());
  g_type_ensure(ComboBoxText::get_type());
  g_type_ensure(Constraint::get_type());
  g_type_ensure(ConstraintGuide::get_type());
  g_type_ensure(ConstraintLayout::get_type());
  g_type_ensure(CssProvider::get_type());
  g_type_ensure(Dialog::get_type());
  g_type_ensure(DirectoryList::get_type());
  g_type_ensure(DragIcon::get_type());
  g_type_ensure(DragSource::get_type());
  g_type_ensure(DrawingArea::get_type());
  g_type_ensure(DropControllerMotion::get_type());
  g_type_ensure(DropDown::get_type());
  g_type_ensure(DropTarget::get_type());
  g_type_ensure(DropTargetAsync::get_type());
  g_type_ensure(EditableLabel::get_type());
  g_type_ensure(EmojiChooser::get_type());
  g_type_ensure(Entry::get_type());
  g_type_ensure(EntryBuffer::get_type());
  g_type_ensure(EntryCompletion::get_type());
  g_type_ensure(EventController::get_type());
  g_type_ensure(EventControllerFocus::get_type());
  g_type_ensure(EventControllerKey::get_type());
  g_type_ensure(EventControllerLegacy::get_type());
  g_type_ensure(EventControllerMotion::get_type());
  g_type_ensure(EventControllerScroll::get_type());
  g_type_ensure(Expander::get_type());
  g_type_ensure(FileChooserDialog::get_type());
  g_type_ensure(FileChooserNative::get_type());
  g_type_ensure(FileChooserWidget::get_type());
  g_type_ensure(FileFilter::get_type());
  g_type_ensure(Filter::get_type());
  g_type_ensure(FilterListModel::get_type());
  g_type_ensure(Fixed::get_type());
  g_type_ensure(FlattenListModel::get_type());
  g_type_ensure(FlowBox::get_type());
  g_type_ensure(FlowBoxChild::get_type());
  g_type_ensure(FontButton::get_type());
  g_type_ensure(FontChooserDialog::get_type());
  g_type_ensure(FontChooserWidget::get_type());
  g_type_ensure(Frame::get_type());
  g_type_ensure(Gesture::get_type());
  g_type_ensure(GestureClick::get_type());
  g_type_ensure(GestureDrag::get_type());
  g_type_ensure(GestureLongPress::get_type());
  g_type_ensure(GesturePan::get_type());
  g_type_ensure(GestureRotate::get_type());
  g_type_ensure(GestureSingle::get_type());
  g_type_ensure(GestureStylus::get_type());
  g_type_ensure(GestureSwipe::get_type());
  g_type_ensure(GestureZoom::get_type());
  g_type_ensure(GLArea::get_type());
  g_type_ensure(Grid::get_type());
  g_type_ensure(GridLayout::get_type());
  g_type_ensure(GridLayoutChild::get_type());
  g_type_ensure(GridView::get_type());
  g_type_ensure(HeaderBar::get_type());
  g_type_ensure(IconPaintable::get_type());
  g_type_ensure(IconTheme::get_type());
  g_type_ensure(IconView::get_type());
  g_type_ensure(Image::get_type());
  g_type_ensure(InfoBar::get_type());
  g_type_ensure(Inscription::get_type());
  g_type_ensure(Label::get_type());
  g_type_ensure(LayoutChild::get_type());
  g_type_ensure(LayoutManager::get_type());
  g_type_ensure(LevelBar::get_type());
  g_type_ensure(LinkButton::get_type());
  g_type_ensure(ListBase::get_type());
  g_type_ensure(ListBox::get_type());
  g_type_ensure(ListBoxRow::get_type());
  g_type_ensure(ListItem::get_type());
  g_type_ensure(ListItemFactory::get_type());
  g_type_ensure(ListStore::get_type());
  g_type_ensure(ListView::get_type());
  g_type_ensure(LockButton::get_type());
  g_type_ensure(MediaControls::get_type());
  g_type_ensure(MediaFile::get_type());
  g_type_ensure(MediaStream::get_type());
  g_type_ensure(MenuButton::get_type());
  g_type_ensure(MessageDialog::get_type());
  g_type_ensure(MultiFilter::get_type());
  g_type_ensure(AnyFilter::get_type());
  g_type_ensure(EveryFilter::get_type());
  g_type_ensure(MultiSelection::get_type());
  g_type_ensure(MultiSorter::get_type());
  g_type_ensure(NativeDialog::get_type());
  g_type_ensure(NoSelection::get_type());
  g_type_ensure(Notebook::get_type());
  g_type_ensure(NotebookPage::get_type());
  g_type_ensure(NumericSorterBase::get_type());
  g_type_ensure(Overlay::get_type());
  g_type_ensure(PadController::get_type());
  g_type_ensure(PageSetup::get_type());
#ifndef G_OS_WIN32
  g_type_ensure(PageSetupUnixDialog::get_type());
#endif // ifndef G_OS_WIN32
  g_type_ensure(Paned::get_type());
  g_type_ensure(PasswordEntry::get_type());
  g_type_ensure(Picture::get_type());
  g_type_ensure(Popover::get_type());
  g_type_ensure(PopoverMenu::get_type());
  g_type_ensure(PopoverMenuBar::get_type());
  g_type_ensure(PrintContext::get_type());
#ifndef G_OS_WIN32
  g_type_ensure(Printer::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(PrintJob::get_type());
#endif // ifndef G_OS_WIN32
  g_type_ensure(PrintOperation::get_type());
  g_type_ensure(PrintSettings::get_type());
#ifndef G_OS_WIN32
  g_type_ensure(PrintUnixDialog::get_type());
#endif // ifndef G_OS_WIN32
  g_type_ensure(ProgressBar::get_type());
  g_type_ensure(Range::get_type());
  g_type_ensure(RecentManager::get_type());
  g_type_ensure(Revealer::get_type());
  g_type_ensure(Scale::get_type());
  g_type_ensure(ScaleButton::get_type());
  g_type_ensure(Scrollbar::get_type());
  g_type_ensure(ScrolledWindow::get_type());
  g_type_ensure(SearchBar::get_type());
  g_type_ensure(SearchEntry::get_type());
  g_type_ensure(SelectionFilterModel::get_type());
  g_type_ensure(Separator::get_type());
  g_type_ensure(Settings::get_type());
  g_type_ensure(Shortcut::get_type());
  g_type_ensure(ShortcutAction::get_type());
  g_type_ensure(NothingAction::get_type());
  g_type_ensure(CallbackAction::get_type());
  g_type_ensure(MnemonicAction::get_type());
  g_type_ensure(ActivateAction::get_type());
  g_type_ensure(SignalAction::get_type());
  g_type_ensure(NamedAction::get_type());
  g_type_ensure(ShortcutController::get_type());
  g_type_ensure(ShortcutLabel::get_type());
  g_type_ensure(ShortcutsGroup::get_type());
  g_type_ensure(ShortcutsSection::get_type());
  g_type_ensure(ShortcutsShortcut::get_type());
  g_type_ensure(ShortcutsWindow::get_type());
  g_type_ensure(ShortcutTrigger::get_type());
  g_type_ensure(NeverTrigger::get_type());
  g_type_ensure(KeyvalTrigger::get_type());
  g_type_ensure(MnemonicTrigger::get_type());
  g_type_ensure(AlternativeTrigger::get_type());
  g_type_ensure(SignalListItemFactory::get_type());
  g_type_ensure(SingleSelection::get_type());
  g_type_ensure(SizeGroup::get_type());
  g_type_ensure(SliceListModel::get_type());
  g_type_ensure(Snapshot::get_type());
  g_type_ensure(Sorter::get_type());
  g_type_ensure(SortListModel::get_type());
  g_type_ensure(SpinButton::get_type());
  g_type_ensure(Spinner::get_type());
  g_type_ensure(Stack::get_type());
  g_type_ensure(StackPage::get_type());
  g_type_ensure(StackSidebar::get_type());
  g_type_ensure(StackSwitcher::get_type());
  g_type_ensure(Statusbar::get_type());
  g_type_ensure(StringFilter::get_type());
  g_type_ensure(StringList::get_type());
  g_type_ensure(StringObject::get_type());
  g_type_ensure(StringSorter::get_type());
  g_type_ensure(StyleContext::get_type());
  g_type_ensure(Switch::get_type());
  g_type_ensure(Text::get_type());
  g_type_ensure(TextBuffer::get_type());
  g_type_ensure(TextChildAnchor::get_type());
  g_type_ensure(TextMark::get_type());
  g_type_ensure(TextTag::get_type());
  g_type_ensure(TextTagTable::get_type());
  g_type_ensure(TextView::get_type());
  g_type_ensure(ToggleButton::get_type());
  g_type_ensure(Tooltip::get_type());
  g_type_ensure(TreeExpander::get_type());
  g_type_ensure(TreeListModel::get_type());
  g_type_ensure(TreeListRow::get_type());
  g_type_ensure(TreeModelFilter::get_type());
  g_type_ensure(TreeModelSort::get_type());
  g_type_ensure(TreeSelection::get_type());
  g_type_ensure(TreeStore::get_type());
  g_type_ensure(TreeView::get_type());
  g_type_ensure(TreeViewColumn::get_type());
  g_type_ensure(Video::get_type());
  g_type_ensure(Viewport::get_type());
  g_type_ensure(VolumeButton::get_type());
  g_type_ensure(Widget::get_type());
  g_type_ensure(WidgetPaintable::get_type());
  g_type_ensure(Window::get_type());
  g_type_ensure(WindowControls::get_type());
  g_type_ensure(WindowGroup::get_type());
  g_type_ensure(WindowHandle::get_type());

} // wrap_init()

} // Gtk

