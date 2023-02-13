
#ifndef _GTKMM_APPCHOOSERBUTTON_H
#define _GTKMM_APPCHOOSERBUTTON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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

#include <libmm-gtk/appchooser.hxx>
#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserButton = struct _GtkAppChooserButton;
using GtkAppChooserButtonClass = struct _GtkAppChooserButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AppChooserButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A button to launch an application chooser dialog.
 *
 * This widget lets the user select an application. See the AppChooser base class API.
 *
 * Initially, an AppChooserButton selects the first application
 * in its list, which will either be the most-recently used application
 * or, if property_show_default_item() is <tt>true</tt>, the
 * default application.
 *
 * The list of applications shown in an AppChooserButton includes
 * the recommended applications for the given content type. When
 * property_show_default_item() is set, the default application
 * is also included. To let the user choose other applications,
 * you can set property_show_dialog_item(),
 * which allows to open a full AppChooserDialog.
 *
 * It is possible to add custom items to the list, using append_custom_item().
 * These items cause signal_custom_item_activated() to be
 * emitted when they are selected.
 *
 * To track changes in the selected application, use signal_changed().
 *
 * The AppChooserButton widget looks like this:
 * @image html appchooserbutton1.png
 *
 * @ingroup Widgets
 *
 * @newin{3,0}
 */

class GTKMM_API AppChooserButton
  : public Widget,
    public AppChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AppChooserButton CppObjectType;
  typedef AppChooserButton_Class CppClassType;
  typedef GtkAppChooserButton BaseObjectType;
  typedef GtkAppChooserButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  AppChooserButton(AppChooserButton&& src) noexcept;
  auto operator=(AppChooserButton&& src) noexcept -> AppChooserButton&;

  // noncopyable
  AppChooserButton(const AppChooserButton&) = delete;
  auto operator=(const AppChooserButton&) -> AppChooserButton& = delete;

  ~AppChooserButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class AppChooserButton_Class;
  static CppClassType appchooserbutton_class_;

protected:
  explicit AppChooserButton(const Glib::ConstructParams& construct_params);
  explicit AppChooserButton(GtkAppChooserButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAppChooserButton*       { return reinterpret_cast<GtkAppChooserButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAppChooserButton* { return reinterpret_cast<GtkAppChooserButton*>(gobject_); }

private:


public:

  /** Creates a new app-chooser button for applications that can handle content of the given type.
   *
   * See @ref giommContentType in glibmm for more information about content types.
   *
   * @param content_type The content type to show applications for
   */
    explicit AppChooserButton(const Glib::ustring& content_type);


  /** Appends a separator to the list of applications that is shown
   * in the popup.
   */
  void append_separator();

  /** Appends a custom item to the list of applications that is shown
   * in the popup.
   *
   * The item name must be unique per-widget. Clients can use the
   * provided name as a detail for the
   * signal_custom_item_activated() signal, to add a
   * callback for the activation of a particular custom item in the list.
   *
   * See also append_separator().
   *
   * @param name The name of the custom item.
   * @param label The label for the custom item.
   * @param icon The icon for the custom item.
   */
  void append_custom_item(const Glib::ustring& name, const Glib::ustring& label, const Glib::RefPtr<Gio::Icon>& icon);

  /** Selects a custom item.
   *
   * See append_custom_item().
   *
   * Use refresh() to bring the selection
   * to its initial state.
   *
   * @param name The name of the custom item.
   */
  void set_active_custom_item(const Glib::ustring& name);

  /** Sets whether the dropdown menu of this button should show an
   * entry to trigger a `Gtk::AppChooserDialog`.
   *
   * @param setting The new value for property_show_dialog_item().
   */
  void set_show_dialog_item(bool setting =  true);

  /** Returns whether the dropdown menu shows an item
   * for a `Gtk::AppChooserDialog`.
   *
   * @return The value of property_show_dialog_item().
   */
  auto get_show_dialog_item() const -> bool;

  /** Sets the text to display at the top of the dialog.
   *
   * If the heading is not set, the dialog displays a default text.
   *
   * @param heading A string containing Pango markup.
   */
  void set_heading(const Glib::ustring& heading);

  /** Returns the text to display at the top of the dialog.
   *
   * @return The text to display at the top of the dialog,
   * or <tt>nullptr</tt>, in which case a default text is displayed.
   */
  auto get_heading() const -> Glib::ustring;

  /** Sets whether the dropdown menu of this button should show the
   * default application for the given content type at top.
   *
   * @param setting The new value for property_show_default_item().
   */
  void set_show_default_item(bool setting =  true);

  /** Returns whether the dropdown menu should show the default
   * application at the top.
   *
   * @return The value of property_show_default_item().
   */
  auto get_show_default_item() const -> bool;

  /** Sets whether the dialog should be modal.
   *
   * @param modal <tt>true</tt> to make the dialog modal.
   */
  void set_modal(bool modal =  true);

  /** Gets whether the dialog is modal.
   *
   * @return <tt>true</tt> if the dialog is modal.
   */
  auto get_modal() const -> bool;

  // no_default_handler because GtkAppChooserButtonClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the active application changes.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%custom_item_activated(const Glib::ustring& item_name)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a custom item is activated.
   *
   * Use Gtk::AppChooserButton::append_custom_item(),
   * to add custom items.
   *
   * @param item_name The name of the activated item.
   */

  auto signal_custom_item_activated(const Glib::ustring& custom_item_name = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


  /** Determines whether the dropdown menu shows an item to open
   * a `Gtk::AppChooserDialog`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_dialog_item() -> Glib::PropertyProxy< bool > ;

/** Determines whether the dropdown menu shows an item to open
   * a `Gtk::AppChooserDialog`.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_dialog_item() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The text to show at the top of the dialog that can be
   * opened from the button.
   *
   * The string may contain Pango markup.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_heading() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text to show at the top of the dialog that can be
   * opened from the button.
   *
   * The string may contain Pango markup.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_heading() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Determines whether the dropdown menu shows the default application
   * on top for the provided content type.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_default_item() -> Glib::PropertyProxy< bool > ;

/** Determines whether the dropdown menu shows the default application
   * on top for the provided content type.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_default_item() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the app chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() -> Glib::PropertyProxy< bool > ;

/** Whether the app chooser dialog should be modal.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::AppChooserButton
   */
  GTKMM_API
  auto wrap(GtkAppChooserButton* object, bool take_copy = false) -> Gtk::AppChooserButton*;
} //namespace Glib


#endif /* _GTKMM_APPCHOOSERBUTTON_H */

