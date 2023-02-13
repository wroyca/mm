
#ifndef _GTKMM_SETTINGS_H
#define _GTKMM_SETTINGS_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/object.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gtk/styleprovider.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSettings = struct _GtkSettings;
using GtkSettingsClass = struct _GtkSettingsClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Settings_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Sharing settings between applications.
 *
 */

class GTKMM_API Settings : public Glib::Object, public StyleProvider
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Settings;
  using CppClassType = Settings_Class;
  using BaseObjectType = GtkSettings;
  using BaseClassType = GtkSettingsClass;

  // noncopyable
  Settings(const Settings&) = delete;
  auto operator=(const Settings&) -> Settings& = delete;

private:  friend class Settings_Class;
  static CppClassType settings_class_;

protected:
  explicit Settings(const Glib::ConstructParams& construct_params);
  explicit Settings(GtkSettings* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Settings(Settings&& src) noexcept;
  auto operator=(Settings&& src) noexcept -> Settings&;

  ~Settings() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSettings*       { return reinterpret_cast<GtkSettings*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSettings* { return reinterpret_cast<GtkSettings*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSettings*;

private:


public:

  /** Gets the `Gtk::Settings` object for the default display, creating
   * it if necessary.
   *
   * See gtk_settings_get_for_display().
   *
   * @return A `Gtk::Settings` object. If there is
   * no default display, then returns <tt>nullptr</tt>.
   */
  static auto get_default() -> Glib::RefPtr<Settings>;


  /** Gets the `Gtk::Settings` object for @a display, creating it if necessary.
   *
   * @param display A `Gdk::Display`.
   * @return A `Gtk::Settings` object.
   */
  static auto get_for_display(const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<Settings>;


  /** Undoes the effect of calling Glib::object_set() to install an
   * application-specific value for a setting.
   *
   * After this call, the setting will again follow the session-wide
   * value for this setting.
   *
   * @param name The name of the setting to reset.
   */
  void reset_property(const Glib::ustring& name);

  /** The maximum time to allow between two clicks for them to be considered
   * a double click, in milliseconds.
   *
   * Default value: 400
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_double_click_time() -> Glib::PropertyProxy< int > ;

/** The maximum time to allow between two clicks for them to be considered
   * a double click, in milliseconds.
   *
   * Default value: 400
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_double_click_time() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The maximum distance allowed between two clicks for them to be considered
   * a double click, in pixels.
   *
   * Default value: 5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_double_click_distance() -> Glib::PropertyProxy< int > ;

/** The maximum distance allowed between two clicks for them to be considered
   * a double click, in pixels.
   *
   * Default value: 5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_double_click_distance() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the cursor should blink.
   *
   * Also see the property_gtk_cursor_blink_timeout() setting,
   * which allows more flexible control over cursor blinking.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink() -> Glib::PropertyProxy< bool > ;

/** Whether the cursor should blink.
   *
   * Also see the property_gtk_cursor_blink_timeout() setting,
   * which allows more flexible control over cursor blinking.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Length of the cursor blink cycle, in milliseconds.
   *
   * Default value: 1200
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink_time() -> Glib::PropertyProxy< int > ;

/** Length of the cursor blink cycle, in milliseconds.
   *
   * Default value: 1200
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink_time() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Time after which the cursor stops blinking, in seconds.
   *
   * The timer is reset after each user interaction.
   *
   * Setting this to zero has the same effect as setting
   * property_gtk_cursor_blink() to <tt>false</tt>.
   *
   * Default value: 10
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink_timeout() -> Glib::PropertyProxy< int > ;

/** Time after which the cursor stops blinking, in seconds.
   *
   * The timer is reset after each user interaction.
   *
   * Setting this to zero has the same effect as setting
   * property_gtk_cursor_blink() to <tt>false</tt>.
   *
   * Default value: 10
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_blink_timeout() const -> Glib::PropertyProxy_ReadOnly< int >;
 //since 3.4
  /** Whether two cursors should be displayed for mixed left-to-right and
   * right-to-left text.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_split_cursor() -> Glib::PropertyProxy< bool > ;

/** Whether two cursors should be displayed for mixed left-to-right and
   * right-to-left text.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_split_cursor() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The aspect ratio of the text caret.
   *
   * Default value: 0.04
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_aspect_ratio() -> Glib::PropertyProxy< double > ;

/** The aspect ratio of the text caret.
   *
   * Default value: 0.04
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_aspect_ratio() const -> Glib::PropertyProxy_ReadOnly< double >;

  /** Name of the theme to load.
   *
   * See Gtk::CssProvider for details about how
   * GTK finds the CSS stylesheet for a theme.
   *
   * Default value: "Default"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_theme_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** Name of the theme to load.
   *
   * See Gtk::CssProvider for details about how
   * GTK finds the CSS stylesheet for a theme.
   *
   * Default value: "Default"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_theme_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The number of pixels the cursor can move before dragging.
   *
   * Default value: 8
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_dnd_drag_threshold() -> Glib::PropertyProxy< int > ;

/** The number of pixels the cursor can move before dragging.
   *
   * Default value: 8
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_dnd_drag_threshold() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The default font to use.
   *
   * GTK uses the family name and size from this string.
   *
   * Default value: "Sans 10"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_font_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The default font to use.
   *
   * GTK uses the family name and size from this string.
   *
   * Default value: "Sans 10"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_font_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to antialias fonts.
   *
   * The values are 0 for no, 1 for yes, or -1 for the system default.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_antialias() -> Glib::PropertyProxy< int > ;

/** Whether to antialias fonts.
   *
   * The values are 0 for no, 1 for yes, or -1 for the system default.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_antialias() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether to enable font hinting.
   *
   * The values are 0 for no, 1 for yes, or -1 for the system default.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_hinting() -> Glib::PropertyProxy< int > ;

/** Whether to enable font hinting.
   *
   * The values are 0 for no, 1 for yes, or -1 for the system default.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_hinting() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** What degree of font hinting to use.
   *
   * The possible vaues are hintnone, hintslight,
   * hintmedium, hintfull.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_hintstyle() -> Glib::PropertyProxy< Glib::ustring > ;

/** What degree of font hinting to use.
   *
   * The possible vaues are hintnone, hintslight,
   * hintmedium, hintfull.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_hintstyle() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The type of subpixel antialiasing to use.
   *
   * The possible values are none, rgb, bgr, vrgb, vbgr.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_rgba() -> Glib::PropertyProxy< Glib::ustring > ;

/** The type of subpixel antialiasing to use.
   *
   * The possible values are none, rgb, bgr, vrgb, vbgr.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_rgba() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The font resolution, in 1024 * dots/inch.
   *
   * -1 to use the default value.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_dpi() -> Glib::PropertyProxy< int > ;

/** The font resolution, in 1024 * dots/inch.
   *
   * -1 to use the default value.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_xft_dpi() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether hinting should be applied to font metrics.
   *
   * Note that this also turns off subpixel positioning of glyphs,
   * since it conflicts with metrics hinting.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_hint_font_metrics() -> Glib::PropertyProxy< bool > ;

/** Whether hinting should be applied to font metrics.
   *
   * Note that this also turns off subpixel positioning of glyphs,
   * since it conflicts with metrics hinting.
   *
   * @newin{4,6}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_hint_font_metrics() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Name of the cursor theme to use.
   *
   * Use <tt>nullptr</tt> to use the default theme.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_theme_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** Name of the cursor theme to use.
   *
   * Use <tt>nullptr</tt> to use the default theme.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_theme_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The size to use for cursors.
   *
   * 0 means to use the default size.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_theme_size() -> Glib::PropertyProxy< int > ;

/** The size to use for cursors.
   *
   * 0 means to use the default size.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_cursor_theme_size() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether buttons in dialogs should use the alternative button order.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_alternative_button_order() -> Glib::PropertyProxy< bool > ;

/** Whether buttons in dialogs should use the alternative button order.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_alternative_button_order() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Controls the direction of the sort indicators in sorted list and tree
   * views.
   *
   * By default an arrow pointing down means the column is sorted
   * in ascending order. When set to <tt>true</tt>, this order will be inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_alternative_sort_arrows() -> Glib::PropertyProxy< bool > ;

/** Controls the direction of the sort indicators in sorted list and tree
   * views.
   *
   * By default an arrow pointing down means the column is sorted
   * in ascending order. When set to <tt>true</tt>, this order will be inverted.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_alternative_sort_arrows() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to enable toolkit-wide animations.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_animations() -> Glib::PropertyProxy< bool > ;

/** Whether to enable toolkit-wide animations.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_animations() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** When <tt>true</tt>, keyboard navigation and other input-related errors
   * will cause a beep.
   *
   * Since the error bell is implemented using gdk_surface_beep(), the
   * windowing system may offer ways to configure the error bell in many
   * ways, such as flashing the window or similar visual effects.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_error_bell() -> Glib::PropertyProxy< bool > ;

/** When <tt>true</tt>, keyboard navigation and other input-related errors
   * will cause a beep.
   *
   * Since the error bell is implemented using gdk_surface_beep(), the
   * windowing system may offer ways to configure the error bell in many
   * ways, such as flashing the window or similar visual effects.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_error_bell() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** A comma-separated list of print backends to use in the print
   * dialog.
   *
   * Available print backends depend on the GTK installation,
   * and may include "file", "cups", "lpr" or "papi".
   *
   * Default value: "cups,file"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_print_backends() -> Glib::PropertyProxy< Glib::ustring > ;

/** A comma-separated list of print backends to use in the print
   * dialog.
   *
   * Available print backends depend on the GTK installation,
   * and may include "file", "cups", "lpr" or "papi".
   *
   * Default value: "cups,file"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_print_backends() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** A command to run for displaying the print preview.
   *
   * The command should contain a `%f` placeholder, which will get
   * replaced by the path to the pdf file. The command may also
   * contain a `%s` placeholder, which will get replaced by the
   * path to a file containing the print settings in the format
   * produced by Gtk::PrintSettings::to_file().
   *
   * The preview application is responsible for removing the pdf
   * file and the print settings file when it is done.
   *
   * Default value: "evince --unlink-tempfile --preview --print-settings %s %f"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_print_preview_command() -> Glib::PropertyProxy< Glib::ustring > ;

/** A command to run for displaying the print preview.
   *
   * The command should contain a `%f` placeholder, which will get
   * replaced by the path to the pdf file. The command may also
   * contain a `%s` placeholder, which will get replaced by the
   * path to a file containing the print settings in the format
   * produced by Gtk::PrintSettings::to_file().
   *
   * The preview application is responsible for removing the pdf
   * file and the print settings file when it is done.
   *
   * Default value: "evince --unlink-tempfile --preview --print-settings %s %f"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_print_preview_command() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether menu items should have visible accelerators which can be
   * activated.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_accels() -> Glib::PropertyProxy< bool > ;

/** Whether menu items should have visible accelerators which can be
   * activated.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_accels() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Which IM (input method) module should be used by default.
   *
   * This is the input method that will be used if the user has not
   * explicitly chosen another input method from the IM context menu.
   * This also can be a colon-separated list of input methods, which GTK
   * will try in turn until it finds one available on the system.
   *
   * See Gtk::IMContext.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_im_module() -> Glib::PropertyProxy< Glib::ustring > ;

/** Which IM (input method) module should be used by default.
   *
   * This is the input method that will be used if the user has not
   * explicitly chosen another input method from the IM context menu.
   * This also can be a colon-separated list of input methods, which GTK
   * will try in turn until it finds one available on the system.
   *
   * See Gtk::IMContext.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The maximum age, in days, of the items inside the recently used
   * resources list.
   *
   * Items older than this setting will be excised from the list.
   * If set to 0, the list will always be empty; if set to -1, no
   * item will be removed.
   *
   * Default value: 30
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_recent_files_max_age() -> Glib::PropertyProxy< int > ;

/** The maximum age, in days, of the items inside the recently used
   * resources list.
   *
   * Items older than this setting will be excised from the list.
   * If set to 0, the list will always be empty; if set to -1, no
   * item will be removed.
   *
   * Default value: 30
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_recent_files_max_age() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Timestamp of the curent fontconfig configuration.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_fontconfig_timestamp() -> Glib::PropertyProxy< int > ;

/** Timestamp of the curent fontconfig configuration.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_fontconfig_timestamp() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The XDG sound theme to use for event sounds.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use
   * a loadable module like the one that comes with libcanberra.
   *
   * Default value: "freedesktop"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_sound_theme_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The XDG sound theme to use for event sounds.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use
   * a loadable module like the one that comes with libcanberra.
   *
   * Default value: "freedesktop"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_sound_theme_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to play event sounds as feedback to user input.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use a loadable
   * module like the one that comes with libcanberra.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_input_feedback_sounds() -> Glib::PropertyProxy< bool > ;

/** Whether to play event sounds as feedback to user input.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use a loadable
   * module like the one that comes with libcanberra.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_input_feedback_sounds() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether to play any event sounds at all.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use a loadable
   * module like the one that comes with libcanberra.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_event_sounds() -> Glib::PropertyProxy< bool > ;

/** Whether to play any event sounds at all.
   *
   * See the [Sound Theme Specifications](http://www.freedesktop.org/wiki/Specifications/sound-theme-spec)
   * for more information on event sounds and sound themes.
   *
   * GTK itself does not support event sounds, you have to use a loadable
   * module like the one that comes with libcanberra.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_event_sounds() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the application prefers to use a dark theme.
   *
   * If a GTK theme includes a dark variant, it will be used
   * instead of the configured theme.
   *
   * Some applications benefit from minimizing the amount of light
   * pollution that interferes with the content. Good candidates for
   * dark themes are photo and video editors that make the actual
   * content get all the attention and minimize the distraction of
   * the chrome.
   *
   * Dark themes should not be used for documents, where large spaces
   * are white/light and the dark chrome creates too much contrast
   * (web browser, text editor...).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_application_prefer_dark_theme() -> Glib::PropertyProxy< bool > ;

/** Whether the application prefers to use a dark theme.
   *
   * If a GTK theme includes a dark variant, it will be used
   * instead of the configured theme.
   *
   * Some applications benefit from minimizing the amount of light
   * pollution that interferes with the content. Good candidates for
   * dark themes are photo and video editors that make the actual
   * content get all the attention and minimize the distraction of
   * the chrome.
   *
   * Dark themes should not be used for documents, where large spaces
   * are white/light and the dark chrome creates too much contrast
   * (web browser, text editor...).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_application_prefer_dark_theme() const -> Glib::PropertyProxy_ReadOnly< bool >;
  // since 2.22
  /** Set to <tt>true</tt> if the desktop environment is displaying
   * the app menu, <tt>false</tt> if the app should display it itself.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_app_menu() -> Glib::PropertyProxy< bool > ;

/** Set to <tt>true</tt> if the desktop environment is displaying
   * the app menu, <tt>false</tt> if the app should display it itself.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_app_menu() const -> Glib::PropertyProxy_ReadOnly< bool >;
 //since 3.4
  /** Set to <tt>true</tt> if the desktop environment is displaying
   * the menubar, <tt>false</tt> if the app should display it itself.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_menubar() -> Glib::PropertyProxy< bool > ;

/** Set to <tt>true</tt> if the desktop environment is displaying
   * the menubar, <tt>false</tt> if the app should display it itself.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_menubar() const -> Glib::PropertyProxy_ReadOnly< bool >;
 //since 3.4
  /** Set to <tt>true</tt> if the desktop environment is displaying
   * the desktop folder, <tt>false</tt> if not.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_desktop() -> Glib::PropertyProxy< bool > ;

/** Set to <tt>true</tt> if the desktop environment is displaying
   * the desktop folder, <tt>false</tt> if not.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_shell_shows_desktop() const -> Glib::PropertyProxy_ReadOnly< bool >;
 //since 3.12
  /** Whether a middle click on a mouse should paste the
   * 'PRIMARY' clipboard content at the cursor location.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_primary_paste() -> Glib::PropertyProxy< bool > ;

/** Whether a middle click on a mouse should paste the
   * 'PRIMARY' clipboard content at the cursor location.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_enable_primary_paste() const -> Glib::PropertyProxy_ReadOnly< bool >;
 //since 3.6

  /** Whether to select the contents of a selectable
   * label when it is focused.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_label_select_on_focus() -> Glib::PropertyProxy< bool > ;

/** Whether to select the contents of a selectable
   * label when it is focused.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_label_select_on_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;
 //since 3.4
  /** How long to show the last input character in hidden
   * entries.
   *
   * This value is in milliseconds. 0 disables showing the
   * last char. 600 is a good value for enabling it.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_entry_password_hint_timeout() -> Glib::PropertyProxy< guint > ;

/** How long to show the last input character in hidden
   * entries.
   *
   * This value is in milliseconds. 0 disables showing the
   * last char. 600 is a good value for enabling it.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_entry_password_hint_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >;
 //since 3.4

  /** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_entry_select_on_focus() -> Glib::PropertyProxy< bool > ;

/** Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_entry_select_on_focus() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Name of the icon theme to use.
   *
   * See Gtk::IconTheme for details about how
   * GTK handles icon themes.
   *
   * Default value: "Adwaita"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_icon_theme_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** Name of the icon theme to use.
   *
   * See Gtk::IconTheme for details about how
   * GTK handles icon themes.
   *
   * Default value: "Adwaita"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_icon_theme_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** Whether GTK should keep track of items inside the recently used
   * resources list.
   *
   * If set to <tt>false</tt>, the list will always be empty.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_recent_files_enabled() -> Glib::PropertyProxy< bool > ;

/** Whether GTK should keep track of items inside the recently used
   * resources list.
   *
   * If set to <tt>false</tt>, the list will always be empty.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_recent_files_enabled() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If the value of this setting is <tt>true</tt>, clicking the primary button in a
   * `Gtk::Range` trough will move the slider, and hence set the range’s value, to
   * the point that you clicked.
   *
   * If it is <tt>false</tt>, a primary click will cause the slider/value to move
   * by the range’s page-size towards the point clicked.
   *
   * Whichever action you choose for the primary button, the other action will
   * be available by holding Shift and primary-clicking, or clicking the middle
   * mouse button.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_primary_button_warps_slider() -> Glib::PropertyProxy< bool > ;

/** If the value of this setting is <tt>true</tt>, clicking the primary button in a
   * `Gtk::Range` trough will move the slider, and hence set the range’s value, to
   * the point that you clicked.
   *
   * If it is <tt>false</tt>, a primary click will cause the slider/value to move
   * by the range’s page-size towards the point clicked.
   *
   * Whichever action you choose for the primary button, the other action will
   * be available by holding Shift and primary-clicking, or clicking the middle
   * mouse button.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_primary_button_warps_slider() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Determines which buttons should be put in the
   * titlebar of client-side decorated windows, and whether they
   * should be placed at the left of right.
   *
   * The format of the string is button names, separated by commas.
   * A colon separates the buttons that should appear on the left
   * from those on the right. Recognized button names are minimize,
   * maximize, close, icon (the window icon) and menu (a menu button
   * for the fallback app menu).
   *
   * For example, "menu:minimize,maximize,close" specifies a menu
   * on the left, and minimize, maximize and close buttons on the right.
   *
   * Note that buttons will only be shown when they are meaningful.
   * E.g. a menu button only appears when the desktop shell does not
   * show the app menu, and a close button only appears on a window
   * that can be closed.
   *
   * Also note that the setting can be overridden with the
   * Gtk::HeaderBar::property_decoration_layout() property.
   *
   * Default value: "menu:minimize,maximize,close"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_decoration_layout() -> Glib::PropertyProxy< Glib::ustring > ;

/** Determines which buttons should be put in the
   * titlebar of client-side decorated windows, and whether they
   * should be placed at the left of right.
   *
   * The format of the string is button names, separated by commas.
   * A colon separates the buttons that should appear on the left
   * from those on the right. Recognized button names are minimize,
   * maximize, close, icon (the window icon) and menu (a menu button
   * for the fallback app menu).
   *
   * For example, "menu:minimize,maximize,close" specifies a menu
   * on the left, and minimize, maximize and close buttons on the right.
   *
   * Note that buttons will only be shown when they are meaningful.
   * E.g. a menu button only appears when the desktop shell does not
   * show the app menu, and a close button only appears on a window
   * that can be closed.
   *
   * Also note that the setting can be overridden with the
   * Gtk::HeaderBar::property_decoration_layout() property.
   *
   * Default value: "menu:minimize,maximize,close"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_decoration_layout() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;
 // since 3.12
  /** Determines the action to take when a double-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "toggle-maximize"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_double_click() -> Glib::PropertyProxy< Glib::ustring > ;

/** Determines the action to take when a double-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "toggle-maximize"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_double_click() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Determines the action to take when a middle-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "none"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_middle_click() -> Glib::PropertyProxy< Glib::ustring > ;

/** Determines the action to take when a middle-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "none"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_middle_click() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Determines the action to take when a right-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "menu"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_right_click() -> Glib::PropertyProxy< Glib::ustring > ;

/** Determines the action to take when a right-click
   * occurs on the titlebar of client-side decorated windows.
   *
   * Recognized actions are minimize, toggle-maximize, menu, lower
   * or none.
   *
   * @newin{3,20}
   *
   * Default value: "menu"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_titlebar_right_click() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether builtin GTK dialogs such as the file chooser, the
   * color chooser or the font chooser will use a header bar at
   * the top to show action widgets, or an action area at the bottom.
   *
   * This setting does not affect custom dialogs using `Gtk::Dialog`
   * directly, or message dialogs.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_dialogs_use_header() -> Glib::PropertyProxy< bool > ;

/** Whether builtin GTK dialogs such as the file chooser, the
   * color chooser or the font chooser will use a header bar at
   * the top to show action widgets, or an action area at the bottom.
   *
   * This setting does not affect custom dialogs using `Gtk::Dialog`
   * directly, or message dialogs.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_dialogs_use_header() const -> Glib::PropertyProxy_ReadOnly< bool >;
 // since 3.12

  /** The time for a button or touch press to be considered a “long press”.
   *
   * See Gtk::GestureLongPress.
   *
   * Default value: 500
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_long_press_time() -> Glib::PropertyProxy< guint > ;

/** The time for a button or touch press to be considered a “long press”.
   *
   * See Gtk::GestureLongPress.
   *
   * Default value: 500
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_long_press_time() const -> Glib::PropertyProxy_ReadOnly< guint >;
 // since 3.14
  /** Whether GTK should make sure that text can be navigated with
   * a caret, even if it is not editable.
   *
   * This is useful when using a screen reader.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_keynav_use_caret() -> Glib::PropertyProxy< bool > ;

/** Whether GTK should make sure that text can be navigated with
   * a caret, even if it is not editable.
   *
   * This is useful when using a screen reader.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_keynav_use_caret() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether scrolled windows may use overlaid scrolling indicators.
   *
   * If this is set to <tt>false</tt>, scrolled windows will have permanent
   * scrollbars.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_overlay_scrolling() -> Glib::PropertyProxy< bool > ;

/** Whether scrolled windows may use overlaid scrolling indicators.
   *
   * If this is set to <tt>false</tt>, scrolled windows will have permanent
   * scrollbars.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_gtk_overlay_scrolling() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Settings
   */
  GTKMM_API
  auto wrap(GtkSettings* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Settings>;
}


#endif /* _GTKMM_SETTINGS_H */

