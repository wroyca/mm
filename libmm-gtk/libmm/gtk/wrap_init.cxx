// SPDX-License-Identifier: LGPL-2.1-or-later

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/wrap_init.hxx>

#include <libmm/gtk/aboutdialog.hxx>
#include <libmm/gtk/accessible.hxx>
#include <libmm/gtk/actionable.hxx>
#include <libmm/gtk/actionbar.hxx>
#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/alertdialog.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/appchooser.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/appchooserbutton.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/appchooserdialog.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/appchooserwidget.hxx>
#endif
#include <libmm/gtk/application.hxx>
#include <libmm/gtk/applicationwindow.hxx>
#include <libmm/gtk/aspectframe.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/assistant.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/assistantpage.hxx>
#endif
#include <libmm/gtk/atcontext.hxx>
#include <libmm/gtk/binlayout.hxx>
#include <libmm/gtk/bitset.hxx>
#include <libmm/gtk/boolfilter.hxx>
#include <libmm/gtk/border.hxx>
#include <libmm/gtk/box.hxx>
#include <libmm/gtk/boxlayout.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/builder.hxx>
#include <libmm/gtk/buildercscope.hxx>
#include <libmm/gtk/builderscope.hxx>
#include <libmm/gtk/button.hxx>
#include <libmm/gtk/calendar.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellarea.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellareabox.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellareacontext.hxx>
#endif
#include <libmm/gtk/celleditable.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/celllayout.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrenderer.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrendereraccel.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrenderercombo.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrendererpixbuf.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrendererprogress.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrendererspin.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrendererspinner.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrenderertext.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellrenderertoggle.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/cellview.hxx>
#endif
#include <libmm/gtk/centerbox.hxx>
#include <libmm/gtk/centerlayout.hxx>
#include <libmm/gtk/checkbutton.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/colorbutton.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/colorchooser.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/colorchooserdialog.hxx>
#endif
#include <libmm/gtk/colordialog.hxx>
#include <libmm/gtk/colordialogbutton.hxx>
#include <libmm/gtk/columnview.hxx>
#include <libmm/gtk/columnviewcolumn.hxx>
#include <libmm/gtk/columnviewsorter.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/combobox.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/comboboxtext.hxx>
#endif
#include <libmm/gtk/constraint.hxx>
#include <libmm/gtk/constraintguide.hxx>
#include <libmm/gtk/constraintlayout.hxx>
#include <libmm/gtk/constrainttarget.hxx>
#include <libmm/gtk/csslocation.hxx>
#include <libmm/gtk/cssprovider.hxx>
#include <libmm/gtk/csssection.hxx>
#include <libmm/gtk/dialog.hxx>
#include <libmm/gtk/directorylist.hxx>
#include <libmm/gtk/dragicon.hxx>
#include <libmm/gtk/dragsource.hxx>
#include <libmm/gtk/drawingarea.hxx>
#include <libmm/gtk/dropcontrollermotion.hxx>
#include <libmm/gtk/dropdown.hxx>
#include <libmm/gtk/droptarget.hxx>
#include <libmm/gtk/droptargetasync.hxx>
#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/editablelabel.hxx>
#include <libmm/gtk/emojichooser.hxx>
#include <libmm/gtk/entry.hxx>
#include <libmm/gtk/entrybuffer.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/entrycompletion.hxx>
#endif
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/error.hxx>
#include <libmm/gtk/eventcontroller.hxx>
#include <libmm/gtk/eventcontrollerfocus.hxx>
#include <libmm/gtk/eventcontrollerkey.hxx>
#include <libmm/gtk/eventcontrollerlegacy.hxx>
#include <libmm/gtk/eventcontrollermotion.hxx>
#include <libmm/gtk/eventcontrollerscroll.hxx>
#include <libmm/gtk/expander.hxx>
#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/expressionwatch.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/filechooser.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/filechooserdialog.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/filechoosernative.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/filechooserwidget.hxx>
#endif
#include <libmm/gtk/filedialog.hxx>
#include <libmm/gtk/filefilter.hxx>
#include <libmm/gtk/filelauncher.hxx>
#include <libmm/gtk/filter.hxx>
#include <libmm/gtk/filterlistmodel.hxx>
#include <libmm/gtk/fixed.hxx>
#include <libmm/gtk/flattenlistmodel.hxx>
#include <libmm/gtk/flowbox.hxx>
#include <libmm/gtk/flowboxchild.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/fontbutton.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/fontchooser.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/fontchooserdialog.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/fontchooserwidget.hxx>
#endif
#include <libmm/gtk/fontdialog.hxx>
#include <libmm/gtk/fontdialogbutton.hxx>
#include <libmm/gtk/frame.hxx>
#include <libmm/gtk/gesture.hxx>
#include <libmm/gtk/gestureclick.hxx>
#include <libmm/gtk/gesturedrag.hxx>
#include <libmm/gtk/gesturelongpress.hxx>
#include <libmm/gtk/gesturepan.hxx>
#include <libmm/gtk/gesturerotate.hxx>
#include <libmm/gtk/gesturesingle.hxx>
#include <libmm/gtk/gesturestylus.hxx>
#include <libmm/gtk/gestureswipe.hxx>
#include <libmm/gtk/gesturezoom.hxx>
#include <libmm/gtk/glarea.hxx>
#include <libmm/gtk/grid.hxx>
#include <libmm/gtk/gridlayout.hxx>
#include <libmm/gtk/gridlayoutchild.hxx>
#include <libmm/gtk/gridview.hxx>
#include <libmm/gtk/headerbar.hxx>
#include <libmm/gtk/iconpaintable.hxx>
#include <libmm/gtk/icontheme.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/iconview.hxx>
#endif
#include <libmm/gtk/image.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/infobar.hxx>
#endif
#include <libmm/gtk/inscription.hxx>
#include <libmm/gtk/label.hxx>
#include <libmm/gtk/layoutchild.hxx>
#include <libmm/gtk/layoutmanager.hxx>
#include <libmm/gtk/levelbar.hxx>
#include <libmm/gtk/linkbutton.hxx>
#include <libmm/gtk/listbase.hxx>
#include <libmm/gtk/listbox.hxx>
#include <libmm/gtk/listboxrow.hxx>
#include <libmm/gtk/listitem.hxx>
#include <libmm/gtk/listitemfactory.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/liststore.hxx>
#endif
#include <libmm/gtk/listview.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/lockbutton.hxx>
#endif
#include <libmm/gtk/mediacontrols.hxx>
#include <libmm/gtk/mediafile.hxx>
#include <libmm/gtk/mediastream.hxx>
#include <libmm/gtk/menubutton.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/messagedialog.hxx>
#endif
#include <libmm/gtk/multifilter.hxx>
#include <libmm/gtk/multiselection.hxx>
#include <libmm/gtk/multisorter.hxx>
#include <libmm/gtk/native.hxx>
#include <libmm/gtk/nativedialog.hxx>
#include <libmm/gtk/noselection.hxx>
#include <libmm/gtk/notebook.hxx>
#include <libmm/gtk/notebookpage.hxx>
#include <libmm/gtk/numericsorter.hxx>
#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/overlay.hxx>
#include <libmm/gtk/padactionentry.hxx>
#include <libmm/gtk/padcontroller.hxx>
#include <libmm/gtk/pagesetup.hxx>
#ifndef G_OS_WIN32
  #include <libmm/gtk/pagesetupunixdialog.hxx>
#endif
#include <libmm/gtk/paned.hxx>
#include <libmm/gtk/papersize.hxx>
#include <libmm/gtk/passwordentry.hxx>
#include <libmm/gtk/picture.hxx>
#include <libmm/gtk/popover.hxx>
#include <libmm/gtk/popovermenu.hxx>
#include <libmm/gtk/popovermenubar.hxx>
#include <libmm/gtk/printcontext.hxx>
#ifndef G_OS_WIN32
  #include <libmm/gtk/printer.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gtk/printjob.hxx>
#endif
#include <libmm/gtk/printoperation.hxx>
#include <libmm/gtk/printoperationpreview.hxx>
#include <libmm/gtk/printsettings.hxx>
#ifndef G_OS_WIN32
  #include <libmm/gtk/printunixdialog.hxx>
#endif
#include <libmm/gtk/progressbar.hxx>
#include <libmm/gtk/range.hxx>
#include <libmm/gtk/recentinfo.hxx>
#include <libmm/gtk/recentmanager.hxx>
#include <libmm/gtk/requisition.hxx>
#include <libmm/gtk/revealer.hxx>
#include <libmm/gtk/root.hxx>
#include <libmm/gtk/scale.hxx>
#include <libmm/gtk/scalebutton.hxx>
#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/scrollbar.hxx>
#include <libmm/gtk/scrolledwindow.hxx>
#include <libmm/gtk/searchbar.hxx>
#include <libmm/gtk/searchentry.hxx>
#include <libmm/gtk/selectionfiltermodel.hxx>
#include <libmm/gtk/selectionmodel.hxx>
#include <libmm/gtk/separator.hxx>
#include <libmm/gtk/settings.hxx>
#include <libmm/gtk/shortcut.hxx>
#include <libmm/gtk/shortcutaction.hxx>
#include <libmm/gtk/shortcutcontroller.hxx>
#include <libmm/gtk/shortcutlabel.hxx>
#include <libmm/gtk/shortcutmanager.hxx>
#include <libmm/gtk/shortcutsgroup.hxx>
#include <libmm/gtk/shortcutssection.hxx>
#include <libmm/gtk/shortcutsshortcut.hxx>
#include <libmm/gtk/shortcutswindow.hxx>
#include <libmm/gtk/shortcuttrigger.hxx>
#include <libmm/gtk/signallistitemfactory.hxx>
#include <libmm/gtk/singleselection.hxx>
#include <libmm/gtk/sizegroup.hxx>
#include <libmm/gtk/slicelistmodel.hxx>
#include <libmm/gtk/snapshot.hxx>
#include <libmm/gtk/sorter.hxx>
#include <libmm/gtk/sortlistmodel.hxx>
#include <libmm/gtk/spinbutton.hxx>
#include <libmm/gtk/spinner.hxx>
#include <libmm/gtk/stack.hxx>
#include <libmm/gtk/stackpage.hxx>
#include <libmm/gtk/stacksidebar.hxx>
#include <libmm/gtk/stackswitcher.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/statusbar.hxx>
#endif
#include <libmm/gtk/stringfilter.hxx>
#include <libmm/gtk/stringlist.hxx>
#include <libmm/gtk/stringobject.hxx>
#include <libmm/gtk/stringsorter.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/stylecontext.hxx>
#endif
#include <libmm/gtk/styleprovider.hxx>
#include <libmm/gtk/switch.hxx>
#include <libmm/gtk/text.hxx>
#include <libmm/gtk/textbuffer.hxx>
#include <libmm/gtk/textchildanchor.hxx>
#include <libmm/gtk/textiter.hxx>
#include <libmm/gtk/textmark.hxx>
#include <libmm/gtk/texttag.hxx>
#include <libmm/gtk/texttagtable.hxx>
#include <libmm/gtk/textview.hxx>
#include <libmm/gtk/togglebutton.hxx>
#include <libmm/gtk/tooltip.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treedragdest.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treedragsource.hxx>
#endif
#include <libmm/gtk/treeexpander.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treeiter.hxx>
#endif
#include <libmm/gtk/treelistmodel.hxx>
#include <libmm/gtk/treelistrow.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treemodel.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treemodelfilter.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treemodelsort.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treepath.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treerowreference.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treeselection.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treesortable.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treestore.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treeview.hxx>
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  #include <libmm/gtk/treeviewcolumn.hxx>
#endif
#include <libmm/gtk/urilauncher.hxx>
#include <libmm/gtk/video.hxx>
#include <libmm/gtk/viewport.hxx>
#include <libmm/gtk/volumebutton.hxx>
#include <libmm/gtk/widget.hxx>
#include <libmm/gtk/widgetpaintable.hxx>
#include <libmm/gtk/window.hxx>
#include <libmm/gtk/windowcontrols.hxx>
#include <libmm/gtk/windowgroup.hxx>
#include <libmm/gtk/windowhandle.hxx>

#ifdef _MSC_VER
  #pragma warning(push)
  #pragma warning(disable : 4273)
#endif

extern "C"
{
  auto
  gtk_about_dialog_get_type (void) -> GType;
  auto
  gtk_action_bar_get_type (void) -> GType;
  auto
  gtk_adjustment_get_type (void) -> GType;
  auto
  gtk_alert_dialog_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_app_chooser_button_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_app_chooser_dialog_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_app_chooser_widget_get_type (void) -> GType;
#endif
  auto
  gtk_application_get_type (void) -> GType;
  auto
  gtk_application_window_get_type (void) -> GType;
  auto
  gtk_aspect_frame_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_assistant_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_assistant_page_get_type (void) -> GType;
#endif
  auto
  gtk_at_context_get_type (void) -> GType;
  auto
  gtk_bin_layout_get_type (void) -> GType;
  auto
  gtk_bool_filter_get_type (void) -> GType;
  auto
  gtk_box_get_type (void) -> GType;
  auto
  gtk_box_layout_get_type (void) -> GType;
  auto
  gtk_builder_get_type (void) -> GType;
  auto
  gtk_builder_cscope_get_type (void) -> GType;
  auto
  gtk_button_get_type (void) -> GType;
  auto
  gtk_calendar_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_area_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_area_box_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_area_context_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_accel_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_combo_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_pixbuf_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_progress_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_spin_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_spinner_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_text_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_renderer_toggle_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_cell_view_get_type (void) -> GType;
#endif
  auto
  gtk_center_box_get_type (void) -> GType;
  auto
  gtk_center_layout_get_type (void) -> GType;
  auto
  gtk_check_button_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_color_button_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_color_chooser_dialog_get_type (void) -> GType;
#endif
  auto
  gtk_color_dialog_get_type (void) -> GType;
  auto
  gtk_color_dialog_button_get_type (void) -> GType;
  auto
  gtk_column_view_get_type (void) -> GType;
  auto
  gtk_column_view_column_get_type (void) -> GType;
  auto
  gtk_column_view_sorter_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_combo_box_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_combo_box_text_get_type (void) -> GType;
#endif
  auto
  gtk_constraint_get_type (void) -> GType;
  auto
  gtk_constraint_guide_get_type (void) -> GType;
  auto
  gtk_constraint_layout_get_type (void) -> GType;
  auto
  gtk_css_provider_get_type (void) -> GType;
  auto
  gtk_dialog_get_type (void) -> GType;
  auto
  gtk_directory_list_get_type (void) -> GType;
  auto
  gtk_drag_icon_get_type (void) -> GType;
  auto
  gtk_drag_source_get_type (void) -> GType;
  auto
  gtk_drawing_area_get_type (void) -> GType;
  auto
  gtk_drop_controller_motion_get_type (void) -> GType;
  auto
  gtk_drop_down_get_type (void) -> GType;
  auto
  gtk_drop_target_get_type (void) -> GType;
  auto
  gtk_drop_target_async_get_type (void) -> GType;
  auto
  gtk_editable_label_get_type (void) -> GType;
  auto
  gtk_emoji_chooser_get_type (void) -> GType;
  auto
  gtk_entry_get_type (void) -> GType;
  auto
  gtk_entry_buffer_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_entry_completion_get_type (void) -> GType;
#endif
  auto
  gtk_event_controller_get_type (void) -> GType;
  auto
  gtk_event_controller_focus_get_type (void) -> GType;
  auto
  gtk_event_controller_key_get_type (void) -> GType;
  auto
  gtk_event_controller_legacy_get_type (void) -> GType;
  auto
  gtk_event_controller_motion_get_type (void) -> GType;
  auto
  gtk_event_controller_scroll_get_type (void) -> GType;
  auto
  gtk_expander_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_file_chooser_dialog_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_file_chooser_native_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_file_chooser_widget_get_type (void) -> GType;
#endif
  auto
  gtk_file_dialog_get_type (void) -> GType;
  auto
  gtk_file_filter_get_type (void) -> GType;
  auto
  gtk_file_launcher_get_type (void) -> GType;
  auto
  gtk_filter_get_type (void) -> GType;
  auto
  gtk_filter_list_model_get_type (void) -> GType;
  auto
  gtk_fixed_get_type (void) -> GType;
  auto
  gtk_flatten_list_model_get_type (void) -> GType;
  auto
  gtk_flow_box_get_type (void) -> GType;
  auto
  gtk_flow_box_child_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_font_button_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_font_chooser_dialog_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_font_chooser_widget_get_type (void) -> GType;
#endif
  auto
  gtk_font_dialog_get_type (void) -> GType;
  auto
  gtk_font_dialog_button_get_type (void) -> GType;
  auto
  gtk_frame_get_type (void) -> GType;
  auto
  gtk_gesture_get_type (void) -> GType;
  auto
  gtk_gesture_click_get_type (void) -> GType;
  auto
  gtk_gesture_drag_get_type (void) -> GType;
  auto
  gtk_gesture_long_press_get_type (void) -> GType;
  auto
  gtk_gesture_pan_get_type (void) -> GType;
  auto
  gtk_gesture_rotate_get_type (void) -> GType;
  auto
  gtk_gesture_single_get_type (void) -> GType;
  auto
  gtk_gesture_stylus_get_type (void) -> GType;
  auto
  gtk_gesture_swipe_get_type (void) -> GType;
  auto
  gtk_gesture_zoom_get_type (void) -> GType;
  auto
  gtk_gl_area_get_type (void) -> GType;
  auto
  gtk_grid_get_type (void) -> GType;
  auto
  gtk_grid_layout_get_type (void) -> GType;
  auto
  gtk_grid_layout_child_get_type (void) -> GType;
  auto
  gtk_grid_view_get_type (void) -> GType;
  auto
  gtk_header_bar_get_type (void) -> GType;
  auto
  gtk_icon_paintable_get_type (void) -> GType;
  auto
  gtk_icon_theme_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_icon_view_get_type (void) -> GType;
#endif
  auto
  gtk_image_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_info_bar_get_type (void) -> GType;
#endif
  auto
  gtk_inscription_get_type (void) -> GType;
  auto
  gtk_label_get_type (void) -> GType;
  auto
  gtk_layout_child_get_type (void) -> GType;
  auto
  gtk_layout_manager_get_type (void) -> GType;
  auto
  gtk_level_bar_get_type (void) -> GType;
  auto
  gtk_link_button_get_type (void) -> GType;
  auto
  gtk_list_base_get_type (void) -> GType;
  auto
  gtk_list_box_get_type (void) -> GType;
  auto
  gtk_list_box_row_get_type (void) -> GType;
  auto
  gtk_list_item_get_type (void) -> GType;
  auto
  gtk_list_item_factory_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_list_store_get_type (void) -> GType;
#endif
  auto
  gtk_list_view_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_lock_button_get_type (void) -> GType;
#endif
  auto
  gtk_media_controls_get_type (void) -> GType;
  auto
  gtk_media_file_get_type (void) -> GType;
  auto
  gtk_media_stream_get_type (void) -> GType;
  auto
  gtk_menu_button_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_message_dialog_get_type (void) -> GType;
#endif
  auto
  gtk_multi_filter_get_type (void) -> GType;
  auto
  gtk_any_filter_get_type (void) -> GType;
  auto
  gtk_every_filter_get_type (void) -> GType;
  auto
  gtk_multi_selection_get_type (void) -> GType;
  auto
  gtk_multi_sorter_get_type (void) -> GType;
  auto
  gtk_native_dialog_get_type (void) -> GType;
  auto
  gtk_no_selection_get_type (void) -> GType;
  auto
  gtk_notebook_get_type (void) -> GType;
  auto
  gtk_notebook_page_get_type (void) -> GType;
  auto
  gtk_numeric_sorter_get_type (void) -> GType;
  auto
  gtk_overlay_get_type (void) -> GType;
  auto
  gtk_pad_controller_get_type (void) -> GType;
  auto
  gtk_page_setup_get_type (void) -> GType;
#ifndef G_OS_WIN32
  GType
  gtk_page_setup_unix_dialog_get_type (void);
#endif
  auto
  gtk_paned_get_type (void) -> GType;
  auto
  gtk_password_entry_get_type (void) -> GType;
  auto
  gtk_picture_get_type (void) -> GType;
  auto
  gtk_popover_get_type (void) -> GType;
  auto
  gtk_popover_menu_get_type (void) -> GType;
  auto
  gtk_popover_menu_bar_get_type (void) -> GType;
  auto
  gtk_print_context_get_type (void) -> GType;
#ifndef G_OS_WIN32
  GType
  gtk_printer_get_type (void);
#endif
#ifndef G_OS_WIN32
  GType
  gtk_print_job_get_type (void);
#endif
  auto
  gtk_print_operation_get_type (void) -> GType;
  auto
  gtk_print_settings_get_type (void) -> GType;
#ifndef G_OS_WIN32
  GType
  gtk_print_unix_dialog_get_type (void);
#endif
  auto
  gtk_progress_bar_get_type (void) -> GType;
  auto
  gtk_range_get_type (void) -> GType;
  auto
  gtk_recent_manager_get_type (void) -> GType;
  auto
  gtk_revealer_get_type (void) -> GType;
  auto
  gtk_scale_get_type (void) -> GType;
  auto
  gtk_scale_button_get_type (void) -> GType;
  auto
  gtk_scrollbar_get_type (void) -> GType;
  auto
  gtk_scrolled_window_get_type (void) -> GType;
  auto
  gtk_search_bar_get_type (void) -> GType;
  auto
  gtk_search_entry_get_type (void) -> GType;
  auto
  gtk_selection_filter_model_get_type (void) -> GType;
  auto
  gtk_separator_get_type (void) -> GType;
  auto
  gtk_settings_get_type (void) -> GType;
  auto
  gtk_shortcut_get_type (void) -> GType;
  auto
  gtk_shortcut_action_get_type (void) -> GType;
  auto
  gtk_nothing_action_get_type (void) -> GType;
  auto
  gtk_callback_action_get_type (void) -> GType;
  auto
  gtk_mnemonic_action_get_type (void) -> GType;
  auto
  gtk_activate_action_get_type (void) -> GType;
  auto
  gtk_signal_action_get_type (void) -> GType;
  auto
  gtk_named_action_get_type (void) -> GType;
  auto
  gtk_shortcut_controller_get_type (void) -> GType;
  auto
  gtk_shortcut_label_get_type (void) -> GType;
  auto
  gtk_shortcuts_group_get_type (void) -> GType;
  auto
  gtk_shortcuts_section_get_type (void) -> GType;
  auto
  gtk_shortcuts_shortcut_get_type (void) -> GType;
  auto
  gtk_shortcuts_window_get_type (void) -> GType;
  auto
  gtk_shortcut_trigger_get_type (void) -> GType;
  auto
  gtk_never_trigger_get_type (void) -> GType;
  auto
  gtk_keyval_trigger_get_type (void) -> GType;
  auto
  gtk_mnemonic_trigger_get_type (void) -> GType;
  auto
  gtk_alternative_trigger_get_type (void) -> GType;
  auto
  gtk_signal_list_item_factory_get_type (void) -> GType;
  auto
  gtk_single_selection_get_type (void) -> GType;
  auto
  gtk_size_group_get_type (void) -> GType;
  auto
  gtk_slice_list_model_get_type (void) -> GType;
  auto
  gtk_snapshot_get_type (void) -> GType;
  auto
  gtk_sorter_get_type (void) -> GType;
  auto
  gtk_sort_list_model_get_type (void) -> GType;
  auto
  gtk_spin_button_get_type (void) -> GType;
  auto
  gtk_spinner_get_type (void) -> GType;
  auto
  gtk_stack_get_type (void) -> GType;
  auto
  gtk_stack_page_get_type (void) -> GType;
  auto
  gtk_stack_sidebar_get_type (void) -> GType;
  auto
  gtk_stack_switcher_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_statusbar_get_type (void) -> GType;
#endif
  auto
  gtk_string_filter_get_type (void) -> GType;
  auto
  gtk_string_list_get_type (void) -> GType;
  auto
  gtk_string_object_get_type (void) -> GType;
  auto
  gtk_string_sorter_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_style_context_get_type (void) -> GType;
#endif
  auto
  gtk_switch_get_type (void) -> GType;
  auto
  gtk_text_get_type (void) -> GType;
  auto
  gtk_text_buffer_get_type (void) -> GType;
  auto
  gtk_text_child_anchor_get_type (void) -> GType;
  auto
  gtk_text_mark_get_type (void) -> GType;
  auto
  gtk_text_tag_get_type (void) -> GType;
  auto
  gtk_text_tag_table_get_type (void) -> GType;
  auto
  gtk_text_view_get_type (void) -> GType;
  auto
  gtk_toggle_button_get_type (void) -> GType;
  auto
  gtk_tooltip_get_type (void) -> GType;
  auto
  gtk_tree_expander_get_type (void) -> GType;
  auto
  gtk_tree_list_model_get_type (void) -> GType;
  auto
  gtk_tree_list_row_get_type (void) -> GType;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_model_filter_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_model_sort_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_selection_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_store_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_view_get_type (void) -> GType;
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_tree_view_column_get_type (void) -> GType;
#endif
  auto
  gtk_uri_launcher_get_type (void) -> GType;
  auto
  gtk_video_get_type (void) -> GType;
  auto
  gtk_viewport_get_type (void) -> GType;
  auto
  gtk_volume_button_get_type (void) -> GType;
  auto
  gtk_widget_get_type (void) -> GType;
  auto
  gtk_widget_paintable_get_type (void) -> GType;
  auto
  gtk_window_get_type (void) -> GType;
  auto
  gtk_window_controls_get_type (void) -> GType;
  auto
  gtk_window_group_get_type (void) -> GType;
  auto
  gtk_window_handle_get_type (void) -> GType;

  auto
  gtk_builder_error_quark (void) -> GQuark;
  auto
  gtk_constraint_vfl_parser_error_quark (void) -> GQuark;
  auto
  gtk_css_parser_error_quark (void) -> GQuark;
  auto
  gtk_css_parser_warning_quark (void) -> GQuark;
  auto
  gtk_dialog_error_quark (void) -> GQuark;
#ifndef GTKMM_DISABLE_DEPRECATED
  auto
  gtk_file_chooser_error_quark (void) -> GQuark;
#endif
  auto
  gtk_icon_theme_error_quark (void) -> GQuark;
  auto
  gtk_print_error_quark (void) -> GQuark;
  auto
  gtk_recent_manager_error_quark (void) -> GQuark;
}

#ifdef _MSC_VER
  #pragma warning(pop)
#endif

namespace gtk
{

  class AboutDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ActionBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Adjustment_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class AlertDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class AppChooserButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class AppChooserDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class AppChooserWidget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class Application_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ApplicationWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class AspectFrame_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class Assistant_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class AssistantPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class ATContext_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BinLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BoolFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Box_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BoxLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Builder_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BuilderCScope_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Button_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Calendar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellArea_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellAreaBox_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellAreaContext_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRenderer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererAccel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererCombo_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererPixbuf_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererProgress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererSpin_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererSpinner_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererText_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellRendererToggle_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class CellView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class CenterBox_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class CenterLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class CheckButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class ColorButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class ColorChooserDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class ColorDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ColorDialogButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ColumnView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ColumnViewColumn_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ColumnViewSorter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class ComboBox_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class ComboBoxText_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class Constraint_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ConstraintGuide_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ConstraintLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class CssProvider_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Dialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DirectoryList_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DragIcon_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DragSource_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DrawingArea_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DropControllerMotion_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DropDown_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DropTarget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DropTargetAsync_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EditableLabel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EmojiChooser_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Entry_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EntryBuffer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class EntryCompletion_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class EventController_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EventControllerFocus_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EventControllerKey_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EventControllerLegacy_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EventControllerMotion_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EventControllerScroll_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Expander_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class FileChooserDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class FileChooserNative_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class FileChooserWidget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class FileDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileLauncher_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Filter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FilterListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Fixed_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FlattenListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FlowBox_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FlowBoxChild_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class FontButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class FontChooserDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class FontChooserWidget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class FontDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FontDialogButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Frame_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Gesture_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureClick_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureDrag_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureLongPress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GesturePan_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureRotate_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureSingle_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureStylus_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureSwipe_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GestureZoom_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GLArea_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Grid_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GridLayout_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GridLayoutChild_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class GridView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class HeaderBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class IconPaintable_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class IconTheme_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class IconView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class Image_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class InfoBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class Inscription_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Label_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LayoutChild_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LayoutManager_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LevelBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class LinkButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListBase_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListBox_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListBoxRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListItem_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListItemFactory_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class ListStore_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class ListView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class LockButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class MediaControls_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MediaFile_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MediaStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MenuButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class MessageDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class MultiFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class AnyFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EveryFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MultiSelection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MultiSorter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NativeDialog_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NoSelection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Notebook_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NotebookPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NumericSorterBase_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Overlay_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PadController_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PageSetup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef G_OS_WIN32
  class PageSetupUnixDialog_Class
  {
  public:
    static glib::ObjectBase*
    wrap_new (GObject*);
  };
#endif
  class Paned_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PasswordEntry_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Picture_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Popover_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PopoverMenu_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PopoverMenuBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PrintContext_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef G_OS_WIN32
  class Printer_Class
  {
  public:
    static glib::ObjectBase*
    wrap_new (GObject*);
  };
#endif
#ifndef G_OS_WIN32
  class PrintJob_Class
  {
  public:
    static glib::ObjectBase*
    wrap_new (GObject*);
  };
#endif
  class PrintOperation_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PrintSettings_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef G_OS_WIN32
  class PrintUnixDialog_Class
  {
  public:
    static glib::ObjectBase*
    wrap_new (GObject*);
  };
#endif
  class ProgressBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Range_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class RecentManager_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Revealer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Scale_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ScaleButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Scrollbar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ScrolledWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SearchBar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SearchEntry_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SelectionFilterModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Separator_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Settings_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Shortcut_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NothingAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class CallbackAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MnemonicAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ActivateAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SignalAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NamedAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutController_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutLabel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutsGroup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutsSection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutsShortcut_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutsWindow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ShortcutTrigger_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NeverTrigger_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class KeyvalTrigger_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MnemonicTrigger_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class AlternativeTrigger_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SignalListItemFactory_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SingleSelection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SizeGroup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SliceListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Snapshot_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Sorter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SortListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SpinButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Spinner_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Stack_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StackPage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StackSidebar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StackSwitcher_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class Statusbar_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class StringFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StringList_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StringObject_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class StringSorter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class StyleContext_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class Switch_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Text_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextBuffer_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextChildAnchor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextMark_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextTag_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextTagTable_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TextView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ToggleButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Tooltip_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TreeExpander_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TreeListModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TreeListRow_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeModelFilter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeModelSort_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeSelection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeStore_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeView_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
  class TreeViewColumn_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class UriLauncher_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Video_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Viewport_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class VolumeButton_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Widget_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class WidgetPaintable_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Window_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class WindowControls_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class WindowGroup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class WindowHandle_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  auto
  wrap_init () -> void
  {
    glib::Error::register_domain (gtk_builder_error_quark (),
                                  &BuilderError::throw_func);
    glib::Error::register_domain (gtk_constraint_vfl_parser_error_quark (),
                                  &ConstraintVflParserError::throw_func);
    glib::Error::register_domain (gtk_css_parser_error_quark (),
                                  &CssParserError::throw_func);
    glib::Error::register_domain (gtk_css_parser_warning_quark (),
                                  &CssParserWarning::throw_func);
    glib::Error::register_domain (gtk_dialog_error_quark (),
                                  &DialogError::throw_func);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::Error::register_domain (gtk_file_chooser_error_quark (),
                                  &FileChooserError::throw_func);
#endif
    glib::Error::register_domain (gtk_icon_theme_error_quark (),
                                  &IconThemeError::throw_func);
    glib::Error::register_domain (gtk_print_error_quark (),
                                  &PrintError::throw_func);
    glib::Error::register_domain (gtk_recent_manager_error_quark (),
                                  &RecentManagerError::throw_func);

    glib::wrap_register (gtk_about_dialog_get_type (),
                         &AboutDialog_Class::wrap_new);
    glib::wrap_register (gtk_action_bar_get_type (),
                         &ActionBar_Class::wrap_new);
    glib::wrap_register (gtk_adjustment_get_type (),
                         &Adjustment_Class::wrap_new);
    glib::wrap_register (gtk_alert_dialog_get_type (),
                         &AlertDialog_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_app_chooser_button_get_type (),
                         &AppChooserButton_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_app_chooser_dialog_get_type (),
                         &AppChooserDialog_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_app_chooser_widget_get_type (),
                         &AppChooserWidget_Class::wrap_new);
#endif
    glib::wrap_register (gtk_application_get_type (),
                         &Application_Class::wrap_new);
    glib::wrap_register (gtk_application_window_get_type (),
                         &ApplicationWindow_Class::wrap_new);
    glib::wrap_register (gtk_aspect_frame_get_type (),
                         &AspectFrame_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_assistant_get_type (), &Assistant_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_assistant_page_get_type (),
                         &AssistantPage_Class::wrap_new);
#endif
    glib::wrap_register (gtk_at_context_get_type (),
                         &ATContext_Class::wrap_new);
    glib::wrap_register (gtk_bin_layout_get_type (),
                         &BinLayout_Class::wrap_new);
    glib::wrap_register (gtk_bool_filter_get_type (),
                         &BoolFilter_Class::wrap_new);
    glib::wrap_register (gtk_box_get_type (), &Box_Class::wrap_new);
    glib::wrap_register (gtk_box_layout_get_type (),
                         &BoxLayout_Class::wrap_new);
    glib::wrap_register (gtk_builder_get_type (), &Builder_Class::wrap_new);
    glib::wrap_register (gtk_builder_cscope_get_type (),
                         &BuilderCScope_Class::wrap_new);
    glib::wrap_register (gtk_button_get_type (), &Button_Class::wrap_new);
    glib::wrap_register (gtk_calendar_get_type (), &Calendar_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_area_get_type (), &CellArea_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_area_box_get_type (),
                         &CellAreaBox_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_area_context_get_type (),
                         &CellAreaContext_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_get_type (),
                         &CellRenderer_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_accel_get_type (),
                         &CellRendererAccel_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_combo_get_type (),
                         &CellRendererCombo_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_pixbuf_get_type (),
                         &CellRendererPixbuf_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_progress_get_type (),
                         &CellRendererProgress_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_spin_get_type (),
                         &CellRendererSpin_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_spinner_get_type (),
                         &CellRendererSpinner_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_text_get_type (),
                         &CellRendererText_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_renderer_toggle_get_type (),
                         &CellRendererToggle_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_cell_view_get_type (), &CellView_Class::wrap_new);
#endif
    glib::wrap_register (gtk_center_box_get_type (),
                         &CenterBox_Class::wrap_new);
    glib::wrap_register (gtk_center_layout_get_type (),
                         &CenterLayout_Class::wrap_new);
    glib::wrap_register (gtk_check_button_get_type (),
                         &CheckButton_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_color_button_get_type (),
                         &ColorButton_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_color_chooser_dialog_get_type (),
                         &ColorChooserDialog_Class::wrap_new);
#endif
    glib::wrap_register (gtk_color_dialog_get_type (),
                         &ColorDialog_Class::wrap_new);
    glib::wrap_register (gtk_color_dialog_button_get_type (),
                         &ColorDialogButton_Class::wrap_new);
    glib::wrap_register (gtk_column_view_get_type (),
                         &ColumnView_Class::wrap_new);
    glib::wrap_register (gtk_column_view_column_get_type (),
                         &ColumnViewColumn_Class::wrap_new);
    glib::wrap_register (gtk_column_view_sorter_get_type (),
                         &ColumnViewSorter_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_combo_box_get_type (), &ComboBox_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_combo_box_text_get_type (),
                         &ComboBoxText_Class::wrap_new);
#endif
    glib::wrap_register (gtk_constraint_get_type (),
                         &Constraint_Class::wrap_new);
    glib::wrap_register (gtk_constraint_guide_get_type (),
                         &ConstraintGuide_Class::wrap_new);
    glib::wrap_register (gtk_constraint_layout_get_type (),
                         &ConstraintLayout_Class::wrap_new);
    glib::wrap_register (gtk_css_provider_get_type (),
                         &CssProvider_Class::wrap_new);
    glib::wrap_register (gtk_dialog_get_type (), &Dialog_Class::wrap_new);
    glib::wrap_register (gtk_directory_list_get_type (),
                         &DirectoryList_Class::wrap_new);
    glib::wrap_register (gtk_drag_icon_get_type (), &DragIcon_Class::wrap_new);
    glib::wrap_register (gtk_drag_source_get_type (),
                         &DragSource_Class::wrap_new);
    glib::wrap_register (gtk_drawing_area_get_type (),
                         &DrawingArea_Class::wrap_new);
    glib::wrap_register (gtk_drop_controller_motion_get_type (),
                         &DropControllerMotion_Class::wrap_new);
    glib::wrap_register (gtk_drop_down_get_type (), &DropDown_Class::wrap_new);
    glib::wrap_register (gtk_drop_target_get_type (),
                         &DropTarget_Class::wrap_new);
    glib::wrap_register (gtk_drop_target_async_get_type (),
                         &DropTargetAsync_Class::wrap_new);
    glib::wrap_register (gtk_editable_label_get_type (),
                         &EditableLabel_Class::wrap_new);
    glib::wrap_register (gtk_emoji_chooser_get_type (),
                         &EmojiChooser_Class::wrap_new);
    glib::wrap_register (gtk_entry_get_type (), &Entry_Class::wrap_new);
    glib::wrap_register (gtk_entry_buffer_get_type (),
                         &EntryBuffer_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_entry_completion_get_type (),
                         &EntryCompletion_Class::wrap_new);
#endif
    glib::wrap_register (gtk_event_controller_get_type (),
                         &EventController_Class::wrap_new);
    glib::wrap_register (gtk_event_controller_focus_get_type (),
                         &EventControllerFocus_Class::wrap_new);
    glib::wrap_register (gtk_event_controller_key_get_type (),
                         &EventControllerKey_Class::wrap_new);
    glib::wrap_register (gtk_event_controller_legacy_get_type (),
                         &EventControllerLegacy_Class::wrap_new);
    glib::wrap_register (gtk_event_controller_motion_get_type (),
                         &EventControllerMotion_Class::wrap_new);
    glib::wrap_register (gtk_event_controller_scroll_get_type (),
                         &EventControllerScroll_Class::wrap_new);
    glib::wrap_register (gtk_expander_get_type (), &Expander_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_file_chooser_dialog_get_type (),
                         &FileChooserDialog_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_file_chooser_native_get_type (),
                         &FileChooserNative_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_file_chooser_widget_get_type (),
                         &FileChooserWidget_Class::wrap_new);
#endif
    glib::wrap_register (gtk_file_dialog_get_type (),
                         &FileDialog_Class::wrap_new);
    glib::wrap_register (gtk_file_filter_get_type (),
                         &FileFilter_Class::wrap_new);
    glib::wrap_register (gtk_file_launcher_get_type (),
                         &FileLauncher_Class::wrap_new);
    glib::wrap_register (gtk_filter_get_type (), &Filter_Class::wrap_new);
    glib::wrap_register (gtk_filter_list_model_get_type (),
                         &FilterListModel_Class::wrap_new);
    glib::wrap_register (gtk_fixed_get_type (), &Fixed_Class::wrap_new);
    glib::wrap_register (gtk_flatten_list_model_get_type (),
                         &FlattenListModel_Class::wrap_new);
    glib::wrap_register (gtk_flow_box_get_type (), &FlowBox_Class::wrap_new);
    glib::wrap_register (gtk_flow_box_child_get_type (),
                         &FlowBoxChild_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_font_button_get_type (),
                         &FontButton_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_font_chooser_dialog_get_type (),
                         &FontChooserDialog_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_font_chooser_widget_get_type (),
                         &FontChooserWidget_Class::wrap_new);
#endif
    glib::wrap_register (gtk_font_dialog_get_type (),
                         &FontDialog_Class::wrap_new);
    glib::wrap_register (gtk_font_dialog_button_get_type (),
                         &FontDialogButton_Class::wrap_new);
    glib::wrap_register (gtk_frame_get_type (), &Frame_Class::wrap_new);
    glib::wrap_register (gtk_gesture_get_type (), &Gesture_Class::wrap_new);
    glib::wrap_register (gtk_gesture_click_get_type (),
                         &GestureClick_Class::wrap_new);
    glib::wrap_register (gtk_gesture_drag_get_type (),
                         &GestureDrag_Class::wrap_new);
    glib::wrap_register (gtk_gesture_long_press_get_type (),
                         &GestureLongPress_Class::wrap_new);
    glib::wrap_register (gtk_gesture_pan_get_type (),
                         &GesturePan_Class::wrap_new);
    glib::wrap_register (gtk_gesture_rotate_get_type (),
                         &GestureRotate_Class::wrap_new);
    glib::wrap_register (gtk_gesture_single_get_type (),
                         &GestureSingle_Class::wrap_new);
    glib::wrap_register (gtk_gesture_stylus_get_type (),
                         &GestureStylus_Class::wrap_new);
    glib::wrap_register (gtk_gesture_swipe_get_type (),
                         &GestureSwipe_Class::wrap_new);
    glib::wrap_register (gtk_gesture_zoom_get_type (),
                         &GestureZoom_Class::wrap_new);
    glib::wrap_register (gtk_gl_area_get_type (), &GLArea_Class::wrap_new);
    glib::wrap_register (gtk_grid_get_type (), &Grid_Class::wrap_new);
    glib::wrap_register (gtk_grid_layout_get_type (),
                         &GridLayout_Class::wrap_new);
    glib::wrap_register (gtk_grid_layout_child_get_type (),
                         &GridLayoutChild_Class::wrap_new);
    glib::wrap_register (gtk_grid_view_get_type (), &GridView_Class::wrap_new);
    glib::wrap_register (gtk_header_bar_get_type (),
                         &HeaderBar_Class::wrap_new);
    glib::wrap_register (gtk_icon_paintable_get_type (),
                         &IconPaintable_Class::wrap_new);
    glib::wrap_register (gtk_icon_theme_get_type (),
                         &IconTheme_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_icon_view_get_type (), &IconView_Class::wrap_new);
#endif
    glib::wrap_register (gtk_image_get_type (), &Image_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_info_bar_get_type (), &InfoBar_Class::wrap_new);
#endif
    glib::wrap_register (gtk_inscription_get_type (),
                         &Inscription_Class::wrap_new);
    glib::wrap_register (gtk_label_get_type (), &Label_Class::wrap_new);
    glib::wrap_register (gtk_layout_child_get_type (),
                         &LayoutChild_Class::wrap_new);
    glib::wrap_register (gtk_layout_manager_get_type (),
                         &LayoutManager_Class::wrap_new);
    glib::wrap_register (gtk_level_bar_get_type (), &LevelBar_Class::wrap_new);
    glib::wrap_register (gtk_link_button_get_type (),
                         &LinkButton_Class::wrap_new);
    glib::wrap_register (gtk_list_base_get_type (), &ListBase_Class::wrap_new);
    glib::wrap_register (gtk_list_box_get_type (), &ListBox_Class::wrap_new);
    glib::wrap_register (gtk_list_box_row_get_type (),
                         &ListBoxRow_Class::wrap_new);
    glib::wrap_register (gtk_list_item_get_type (), &ListItem_Class::wrap_new);
    glib::wrap_register (gtk_list_item_factory_get_type (),
                         &ListItemFactory_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_list_store_get_type (),
                         &ListStore_Class::wrap_new);
#endif
    glib::wrap_register (gtk_list_view_get_type (), &ListView_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_lock_button_get_type (),
                         &LockButton_Class::wrap_new);
#endif
    glib::wrap_register (gtk_media_controls_get_type (),
                         &MediaControls_Class::wrap_new);
    glib::wrap_register (gtk_media_file_get_type (),
                         &MediaFile_Class::wrap_new);
    glib::wrap_register (gtk_media_stream_get_type (),
                         &MediaStream_Class::wrap_new);
    glib::wrap_register (gtk_menu_button_get_type (),
                         &MenuButton_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_message_dialog_get_type (),
                         &MessageDialog_Class::wrap_new);
#endif
    glib::wrap_register (gtk_multi_filter_get_type (),
                         &MultiFilter_Class::wrap_new);
    glib::wrap_register (gtk_any_filter_get_type (),
                         &AnyFilter_Class::wrap_new);
    glib::wrap_register (gtk_every_filter_get_type (),
                         &EveryFilter_Class::wrap_new);
    glib::wrap_register (gtk_multi_selection_get_type (),
                         &MultiSelection_Class::wrap_new);
    glib::wrap_register (gtk_multi_sorter_get_type (),
                         &MultiSorter_Class::wrap_new);
    glib::wrap_register (gtk_native_dialog_get_type (),
                         &NativeDialog_Class::wrap_new);
    glib::wrap_register (gtk_no_selection_get_type (),
                         &NoSelection_Class::wrap_new);
    glib::wrap_register (gtk_notebook_get_type (), &Notebook_Class::wrap_new);
    glib::wrap_register (gtk_notebook_page_get_type (),
                         &NotebookPage_Class::wrap_new);
    glib::wrap_register (gtk_numeric_sorter_get_type (),
                         &NumericSorterBase_Class::wrap_new);
    glib::wrap_register (gtk_overlay_get_type (), &Overlay_Class::wrap_new);
    glib::wrap_register (gtk_pad_controller_get_type (),
                         &PadController_Class::wrap_new);
    glib::wrap_register (gtk_page_setup_get_type (),
                         &PageSetup_Class::wrap_new);
#ifndef G_OS_WIN32
    glib::wrap_register (gtk_page_setup_unix_dialog_get_type (),
                         &PageSetupUnixDialog_Class::wrap_new);
#endif
    glib::wrap_register (gtk_paned_get_type (), &Paned_Class::wrap_new);
    glib::wrap_register (gtk_password_entry_get_type (),
                         &PasswordEntry_Class::wrap_new);
    glib::wrap_register (gtk_picture_get_type (), &Picture_Class::wrap_new);
    glib::wrap_register (gtk_popover_get_type (), &Popover_Class::wrap_new);
    glib::wrap_register (gtk_popover_menu_get_type (),
                         &PopoverMenu_Class::wrap_new);
    glib::wrap_register (gtk_popover_menu_bar_get_type (),
                         &PopoverMenuBar_Class::wrap_new);
    glib::wrap_register (gtk_print_context_get_type (),
                         &PrintContext_Class::wrap_new);
#ifndef G_OS_WIN32
    glib::wrap_register (gtk_printer_get_type (), &Printer_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (gtk_print_job_get_type (), &PrintJob_Class::wrap_new);
#endif
    glib::wrap_register (gtk_print_operation_get_type (),
                         &PrintOperation_Class::wrap_new);
    glib::wrap_register (gtk_print_settings_get_type (),
                         &PrintSettings_Class::wrap_new);
#ifndef G_OS_WIN32
    glib::wrap_register (gtk_print_unix_dialog_get_type (),
                         &PrintUnixDialog_Class::wrap_new);
#endif
    glib::wrap_register (gtk_progress_bar_get_type (),
                         &ProgressBar_Class::wrap_new);
    glib::wrap_register (gtk_range_get_type (), &Range_Class::wrap_new);
    glib::wrap_register (gtk_recent_manager_get_type (),
                         &RecentManager_Class::wrap_new);
    glib::wrap_register (gtk_revealer_get_type (), &Revealer_Class::wrap_new);
    glib::wrap_register (gtk_scale_get_type (), &Scale_Class::wrap_new);
    glib::wrap_register (gtk_scale_button_get_type (),
                         &ScaleButton_Class::wrap_new);
    glib::wrap_register (gtk_scrollbar_get_type (), &Scrollbar_Class::wrap_new);
    glib::wrap_register (gtk_scrolled_window_get_type (),
                         &ScrolledWindow_Class::wrap_new);
    glib::wrap_register (gtk_search_bar_get_type (),
                         &SearchBar_Class::wrap_new);
    glib::wrap_register (gtk_search_entry_get_type (),
                         &SearchEntry_Class::wrap_new);
    glib::wrap_register (gtk_selection_filter_model_get_type (),
                         &SelectionFilterModel_Class::wrap_new);
    glib::wrap_register (gtk_separator_get_type (), &Separator_Class::wrap_new);
    glib::wrap_register (gtk_settings_get_type (), &Settings_Class::wrap_new);
    glib::wrap_register (gtk_shortcut_get_type (), &Shortcut_Class::wrap_new);
    glib::wrap_register (gtk_shortcut_action_get_type (),
                         &ShortcutAction_Class::wrap_new);
    glib::wrap_register (gtk_nothing_action_get_type (),
                         &NothingAction_Class::wrap_new);
    glib::wrap_register (gtk_callback_action_get_type (),
                         &CallbackAction_Class::wrap_new);
    glib::wrap_register (gtk_mnemonic_action_get_type (),
                         &MnemonicAction_Class::wrap_new);
    glib::wrap_register (gtk_activate_action_get_type (),
                         &ActivateAction_Class::wrap_new);
    glib::wrap_register (gtk_signal_action_get_type (),
                         &SignalAction_Class::wrap_new);
    glib::wrap_register (gtk_named_action_get_type (),
                         &NamedAction_Class::wrap_new);
    glib::wrap_register (gtk_shortcut_controller_get_type (),
                         &ShortcutController_Class::wrap_new);
    glib::wrap_register (gtk_shortcut_label_get_type (),
                         &ShortcutLabel_Class::wrap_new);
    glib::wrap_register (gtk_shortcuts_group_get_type (),
                         &ShortcutsGroup_Class::wrap_new);
    glib::wrap_register (gtk_shortcuts_section_get_type (),
                         &ShortcutsSection_Class::wrap_new);
    glib::wrap_register (gtk_shortcuts_shortcut_get_type (),
                         &ShortcutsShortcut_Class::wrap_new);
    glib::wrap_register (gtk_shortcuts_window_get_type (),
                         &ShortcutsWindow_Class::wrap_new);
    glib::wrap_register (gtk_shortcut_trigger_get_type (),
                         &ShortcutTrigger_Class::wrap_new);
    glib::wrap_register (gtk_never_trigger_get_type (),
                         &NeverTrigger_Class::wrap_new);
    glib::wrap_register (gtk_keyval_trigger_get_type (),
                         &KeyvalTrigger_Class::wrap_new);
    glib::wrap_register (gtk_mnemonic_trigger_get_type (),
                         &MnemonicTrigger_Class::wrap_new);
    glib::wrap_register (gtk_alternative_trigger_get_type (),
                         &AlternativeTrigger_Class::wrap_new);
    glib::wrap_register (gtk_signal_list_item_factory_get_type (),
                         &SignalListItemFactory_Class::wrap_new);
    glib::wrap_register (gtk_single_selection_get_type (),
                         &SingleSelection_Class::wrap_new);
    glib::wrap_register (gtk_size_group_get_type (),
                         &SizeGroup_Class::wrap_new);
    glib::wrap_register (gtk_slice_list_model_get_type (),
                         &SliceListModel_Class::wrap_new);
    glib::wrap_register (gtk_snapshot_get_type (), &Snapshot_Class::wrap_new);
    glib::wrap_register (gtk_sorter_get_type (), &Sorter_Class::wrap_new);
    glib::wrap_register (gtk_sort_list_model_get_type (),
                         &SortListModel_Class::wrap_new);
    glib::wrap_register (gtk_spin_button_get_type (),
                         &SpinButton_Class::wrap_new);
    glib::wrap_register (gtk_spinner_get_type (), &Spinner_Class::wrap_new);
    glib::wrap_register (gtk_stack_get_type (), &Stack_Class::wrap_new);
    glib::wrap_register (gtk_stack_page_get_type (),
                         &StackPage_Class::wrap_new);
    glib::wrap_register (gtk_stack_sidebar_get_type (),
                         &StackSidebar_Class::wrap_new);
    glib::wrap_register (gtk_stack_switcher_get_type (),
                         &StackSwitcher_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_statusbar_get_type (), &Statusbar_Class::wrap_new);
#endif
    glib::wrap_register (gtk_string_filter_get_type (),
                         &StringFilter_Class::wrap_new);
    glib::wrap_register (gtk_string_list_get_type (),
                         &StringList_Class::wrap_new);
    glib::wrap_register (gtk_string_object_get_type (),
                         &StringObject_Class::wrap_new);
    glib::wrap_register (gtk_string_sorter_get_type (),
                         &StringSorter_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_style_context_get_type (),
                         &StyleContext_Class::wrap_new);
#endif
    glib::wrap_register (gtk_switch_get_type (), &Switch_Class::wrap_new);
    glib::wrap_register (gtk_text_get_type (), &Text_Class::wrap_new);
    glib::wrap_register (gtk_text_buffer_get_type (),
                         &TextBuffer_Class::wrap_new);
    glib::wrap_register (gtk_text_child_anchor_get_type (),
                         &TextChildAnchor_Class::wrap_new);
    glib::wrap_register (gtk_text_mark_get_type (), &TextMark_Class::wrap_new);
    glib::wrap_register (gtk_text_tag_get_type (), &TextTag_Class::wrap_new);
    glib::wrap_register (gtk_text_tag_table_get_type (),
                         &TextTagTable_Class::wrap_new);
    glib::wrap_register (gtk_text_view_get_type (), &TextView_Class::wrap_new);
    glib::wrap_register (gtk_toggle_button_get_type (),
                         &ToggleButton_Class::wrap_new);
    glib::wrap_register (gtk_tooltip_get_type (), &Tooltip_Class::wrap_new);
    glib::wrap_register (gtk_tree_expander_get_type (),
                         &TreeExpander_Class::wrap_new);
    glib::wrap_register (gtk_tree_list_model_get_type (),
                         &TreeListModel_Class::wrap_new);
    glib::wrap_register (gtk_tree_list_row_get_type (),
                         &TreeListRow_Class::wrap_new);
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_model_filter_get_type (),
                         &TreeModelFilter_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_model_sort_get_type (),
                         &TreeModelSort_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_selection_get_type (),
                         &TreeSelection_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_store_get_type (),
                         &TreeStore_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_view_get_type (), &TreeView_Class::wrap_new);
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    glib::wrap_register (gtk_tree_view_column_get_type (),
                         &TreeViewColumn_Class::wrap_new);
#endif
    glib::wrap_register (gtk_uri_launcher_get_type (),
                         &UriLauncher_Class::wrap_new);
    glib::wrap_register (gtk_video_get_type (), &Video_Class::wrap_new);
    glib::wrap_register (gtk_viewport_get_type (), &Viewport_Class::wrap_new);
    glib::wrap_register (gtk_volume_button_get_type (),
                         &VolumeButton_Class::wrap_new);
    glib::wrap_register (gtk_widget_get_type (), &Widget_Class::wrap_new);
    glib::wrap_register (gtk_widget_paintable_get_type (),
                         &WidgetPaintable_Class::wrap_new);
    glib::wrap_register (gtk_window_get_type (), &Window_Class::wrap_new);
    glib::wrap_register (gtk_window_controls_get_type (),
                         &WindowControls_Class::wrap_new);
    glib::wrap_register (gtk_window_group_get_type (),
                         &WindowGroup_Class::wrap_new);
    glib::wrap_register (gtk_window_handle_get_type (),
                         &WindowHandle_Class::wrap_new);

    g_type_ensure (AboutDialog::get_type ());
    g_type_ensure (ActionBar::get_type ());
    g_type_ensure (Adjustment::get_type ());
    g_type_ensure (AlertDialog::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (AppChooserButton::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (AppChooserDialog::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (AppChooserWidget::get_type ());
#endif
    g_type_ensure (Application::get_type ());
    g_type_ensure (ApplicationWindow::get_type ());
    g_type_ensure (AspectFrame::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (Assistant::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (AssistantPage::get_type ());
#endif
    g_type_ensure (ATContext::get_type ());
    g_type_ensure (BinLayout::get_type ());
    g_type_ensure (BoolFilter::get_type ());
    g_type_ensure (Box::get_type ());
    g_type_ensure (BoxLayout::get_type ());
    g_type_ensure (Builder::get_type ());
    g_type_ensure (BuilderCScope::get_type ());
    g_type_ensure (Button::get_type ());
    g_type_ensure (Calendar::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellArea::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellAreaBox::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellAreaContext::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRenderer::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererAccel::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererCombo::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererPixbuf::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererProgress::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererSpin::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererSpinner::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererText::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellRendererToggle::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (CellView::get_type ());
#endif
    g_type_ensure (CenterBox::get_type ());
    g_type_ensure (CenterLayout::get_type ());
    g_type_ensure (CheckButton::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (ColorButton::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (ColorChooserDialog::get_type ());
#endif
    g_type_ensure (ColorDialog::get_type ());
    g_type_ensure (ColorDialogButton::get_type ());
    g_type_ensure (ColumnView::get_type ());
    g_type_ensure (ColumnViewColumn::get_type ());
    g_type_ensure (ColumnViewSorter::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (ComboBox::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (ComboBoxText::get_type ());
#endif
    g_type_ensure (Constraint::get_type ());
    g_type_ensure (ConstraintGuide::get_type ());
    g_type_ensure (ConstraintLayout::get_type ());
    g_type_ensure (CssProvider::get_type ());
    g_type_ensure (Dialog::get_type ());
    g_type_ensure (DirectoryList::get_type ());
    g_type_ensure (DragIcon::get_type ());
    g_type_ensure (DragSource::get_type ());
    g_type_ensure (DrawingArea::get_type ());
    g_type_ensure (DropControllerMotion::get_type ());
    g_type_ensure (DropDown::get_type ());
    g_type_ensure (DropTarget::get_type ());
    g_type_ensure (DropTargetAsync::get_type ());
    g_type_ensure (EditableLabel::get_type ());
    g_type_ensure (EmojiChooser::get_type ());
    g_type_ensure (Entry::get_type ());
    g_type_ensure (EntryBuffer::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (EntryCompletion::get_type ());
#endif
    g_type_ensure (EventController::get_type ());
    g_type_ensure (EventControllerFocus::get_type ());
    g_type_ensure (EventControllerKey::get_type ());
    g_type_ensure (EventControllerLegacy::get_type ());
    g_type_ensure (EventControllerMotion::get_type ());
    g_type_ensure (EventControllerScroll::get_type ());
    g_type_ensure (Expander::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FileChooserDialog::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FileChooserNative::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FileChooserWidget::get_type ());
#endif
    g_type_ensure (FileDialog::get_type ());
    g_type_ensure (FileFilter::get_type ());
    g_type_ensure (FileLauncher::get_type ());
    g_type_ensure (Filter::get_type ());
    g_type_ensure (FilterListModel::get_type ());
    g_type_ensure (Fixed::get_type ());
    g_type_ensure (FlattenListModel::get_type ());
    g_type_ensure (FlowBox::get_type ());
    g_type_ensure (FlowBoxChild::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FontButton::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FontChooserDialog::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (FontChooserWidget::get_type ());
#endif
    g_type_ensure (FontDialog::get_type ());
    g_type_ensure (FontDialogButton::get_type ());
    g_type_ensure (Frame::get_type ());
    g_type_ensure (Gesture::get_type ());
    g_type_ensure (GestureClick::get_type ());
    g_type_ensure (GestureDrag::get_type ());
    g_type_ensure (GestureLongPress::get_type ());
    g_type_ensure (GesturePan::get_type ());
    g_type_ensure (GestureRotate::get_type ());
    g_type_ensure (GestureSingle::get_type ());
    g_type_ensure (GestureStylus::get_type ());
    g_type_ensure (GestureSwipe::get_type ());
    g_type_ensure (GestureZoom::get_type ());
    g_type_ensure (GLArea::get_type ());
    g_type_ensure (Grid::get_type ());
    g_type_ensure (GridLayout::get_type ());
    g_type_ensure (GridLayoutChild::get_type ());
    g_type_ensure (GridView::get_type ());
    g_type_ensure (HeaderBar::get_type ());
    g_type_ensure (IconPaintable::get_type ());
    g_type_ensure (IconTheme::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (IconView::get_type ());
#endif
    g_type_ensure (Image::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (InfoBar::get_type ());
#endif
    g_type_ensure (Inscription::get_type ());
    g_type_ensure (Label::get_type ());
    g_type_ensure (LayoutChild::get_type ());
    g_type_ensure (LayoutManager::get_type ());
    g_type_ensure (LevelBar::get_type ());
    g_type_ensure (LinkButton::get_type ());
    g_type_ensure (ListBase::get_type ());
    g_type_ensure (ListBox::get_type ());
    g_type_ensure (ListBoxRow::get_type ());
    g_type_ensure (ListItem::get_type ());
    g_type_ensure (ListItemFactory::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (ListStore::get_type ());
#endif
    g_type_ensure (ListView::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (LockButton::get_type ());
#endif
    g_type_ensure (MediaControls::get_type ());
    g_type_ensure (MediaFile::get_type ());
    g_type_ensure (MediaStream::get_type ());
    g_type_ensure (MenuButton::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (MessageDialog::get_type ());
#endif
    g_type_ensure (MultiFilter::get_type ());
    g_type_ensure (AnyFilter::get_type ());
    g_type_ensure (EveryFilter::get_type ());
    g_type_ensure (MultiSelection::get_type ());
    g_type_ensure (MultiSorter::get_type ());
    g_type_ensure (NativeDialog::get_type ());
    g_type_ensure (NoSelection::get_type ());
    g_type_ensure (Notebook::get_type ());
    g_type_ensure (NotebookPage::get_type ());
    g_type_ensure (NumericSorterBase::get_type ());
    g_type_ensure (Overlay::get_type ());
    g_type_ensure (PadController::get_type ());
    g_type_ensure (PageSetup::get_type ());
#ifndef G_OS_WIN32
    g_type_ensure (PageSetupUnixDialog::get_type ());
#endif
    g_type_ensure (Paned::get_type ());
    g_type_ensure (PasswordEntry::get_type ());
    g_type_ensure (Picture::get_type ());
    g_type_ensure (Popover::get_type ());
    g_type_ensure (PopoverMenu::get_type ());
    g_type_ensure (PopoverMenuBar::get_type ());
    g_type_ensure (PrintContext::get_type ());
#ifndef G_OS_WIN32
    g_type_ensure (Printer::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (PrintJob::get_type ());
#endif
    g_type_ensure (PrintOperation::get_type ());
    g_type_ensure (PrintSettings::get_type ());
#ifndef G_OS_WIN32
    g_type_ensure (PrintUnixDialog::get_type ());
#endif
    g_type_ensure (ProgressBar::get_type ());
    g_type_ensure (Range::get_type ());
    g_type_ensure (RecentManager::get_type ());
    g_type_ensure (Revealer::get_type ());
    g_type_ensure (Scale::get_type ());
    g_type_ensure (ScaleButton::get_type ());
    g_type_ensure (Scrollbar::get_type ());
    g_type_ensure (ScrolledWindow::get_type ());
    g_type_ensure (SearchBar::get_type ());
    g_type_ensure (SearchEntry::get_type ());
    g_type_ensure (SelectionFilterModel::get_type ());
    g_type_ensure (Separator::get_type ());
    g_type_ensure (Settings::get_type ());
    g_type_ensure (Shortcut::get_type ());
    g_type_ensure (ShortcutAction::get_type ());
    g_type_ensure (NothingAction::get_type ());
    g_type_ensure (CallbackAction::get_type ());
    g_type_ensure (MnemonicAction::get_type ());
    g_type_ensure (ActivateAction::get_type ());
    g_type_ensure (SignalAction::get_type ());
    g_type_ensure (NamedAction::get_type ());
    g_type_ensure (ShortcutController::get_type ());
    g_type_ensure (ShortcutLabel::get_type ());
    g_type_ensure (ShortcutsGroup::get_type ());
    g_type_ensure (ShortcutsSection::get_type ());
    g_type_ensure (ShortcutsShortcut::get_type ());
    g_type_ensure (ShortcutsWindow::get_type ());
    g_type_ensure (ShortcutTrigger::get_type ());
    g_type_ensure (NeverTrigger::get_type ());
    g_type_ensure (KeyvalTrigger::get_type ());
    g_type_ensure (MnemonicTrigger::get_type ());
    g_type_ensure (AlternativeTrigger::get_type ());
    g_type_ensure (SignalListItemFactory::get_type ());
    g_type_ensure (SingleSelection::get_type ());
    g_type_ensure (SizeGroup::get_type ());
    g_type_ensure (SliceListModel::get_type ());
    g_type_ensure (Snapshot::get_type ());
    g_type_ensure (Sorter::get_type ());
    g_type_ensure (SortListModel::get_type ());
    g_type_ensure (SpinButton::get_type ());
    g_type_ensure (Spinner::get_type ());
    g_type_ensure (Stack::get_type ());
    g_type_ensure (StackPage::get_type ());
    g_type_ensure (StackSidebar::get_type ());
    g_type_ensure (StackSwitcher::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (Statusbar::get_type ());
#endif
    g_type_ensure (StringFilter::get_type ());
    g_type_ensure (StringList::get_type ());
    g_type_ensure (StringObject::get_type ());
    g_type_ensure (StringSorter::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (StyleContext::get_type ());
#endif
    g_type_ensure (Switch::get_type ());
    g_type_ensure (Text::get_type ());
    g_type_ensure (TextBuffer::get_type ());
    g_type_ensure (TextChildAnchor::get_type ());
    g_type_ensure (TextMark::get_type ());
    g_type_ensure (TextTag::get_type ());
    g_type_ensure (TextTagTable::get_type ());
    g_type_ensure (TextView::get_type ());
    g_type_ensure (ToggleButton::get_type ());
    g_type_ensure (Tooltip::get_type ());
    g_type_ensure (TreeExpander::get_type ());
    g_type_ensure (TreeListModel::get_type ());
    g_type_ensure (TreeListRow::get_type ());
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeModelFilter::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeModelSort::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeSelection::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeStore::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeView::get_type ());
#endif
#ifndef GTKMM_DISABLE_DEPRECATED
    g_type_ensure (TreeViewColumn::get_type ());
#endif
    g_type_ensure (UriLauncher::get_type ());
    g_type_ensure (Video::get_type ());
    g_type_ensure (Viewport::get_type ());
    g_type_ensure (VolumeButton::get_type ());
    g_type_ensure (Widget::get_type ());
    g_type_ensure (WidgetPaintable::get_type ());
    g_type_ensure (Window::get_type ());
    g_type_ensure (WindowControls::get_type ());
    g_type_ensure (WindowGroup::get_type ());
    g_type_ensure (WindowHandle::get_type ());
  }

} // namespace gtk
