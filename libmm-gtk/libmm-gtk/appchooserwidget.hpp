
#ifndef _GTKMM_APPCHOOSERWIDGET_H
#define _GTKMM_APPCHOOSERWIDGET_H


#include <mm/glib/ustring.hpp>
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

#include <mm/gtk/appchooser.hpp>
#include <mm/gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserWidget = struct _GtkAppChooserWidget;
using GtkAppChooserWidgetClass = struct _GtkAppChooserWidgetClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AppChooserWidget_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An application chooser widget that can be embedded in other widgets.
 *
 * This widget is for selecting applications. It is the main building block for AppChooserDialog.
 * Most applications only need to use the latter, but you can use this widget as part of
 * a larger widget if you have special needs.
 *
 * AppChooserWidget offers detailed control over what applications are shown, using
 * property_show_default() and its other properties.
 * See the AppChooser documentation for more information about the groups of applications.
 *
 * To keep track of the selected application, use signal_application_selected() and
 * signal_application_activated().
 *
 * @ingroup Widgets
 *
 * @newin{3,0}
 */

class GTKMM_API AppChooserWidget
  : public Widget,
    public AppChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AppChooserWidget CppObjectType;
  typedef AppChooserWidget_Class CppClassType;
  typedef GtkAppChooserWidget BaseObjectType;
  typedef GtkAppChooserWidgetClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  AppChooserWidget(AppChooserWidget&& src) noexcept;
  auto operator=(AppChooserWidget&& src) noexcept -> AppChooserWidget&;

  // noncopyable
  AppChooserWidget(const AppChooserWidget&) = delete;
  auto operator=(const AppChooserWidget&) -> AppChooserWidget& = delete;

  ~AppChooserWidget() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class AppChooserWidget_Class;
  static CppClassType appchooserwidget_class_;

protected:
  explicit AppChooserWidget(const Glib::ConstructParams& construct_params);
  explicit AppChooserWidget(GtkAppChooserWidget* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAppChooserWidget*       { return reinterpret_cast<GtkAppChooserWidget*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAppChooserWidget* { return reinterpret_cast<GtkAppChooserWidget*>(gobject_); }

private:


public:

  /** Creates a new app-chooser widget for applications that can handle content of the given type.
   *
   * See @ref giommContentType in glibmm for more information about content types.
   *
   * @param content_type The content type to show applications for
   */
    explicit AppChooserWidget(const Glib::ustring& content_type);


  /** Sets whether the app chooser should show the default handler
   * for the content type in a separate section.
   *
   * @param setting The new value for property_show_default().
   */
  void set_show_default(bool setting =  true);

  /** Gets whether the app chooser should show the default handler
   * for the content type in a separate section.
   *
   * @return The value of property_show_default().
   */
  auto get_show_default() -> bool;


  /** Sets whether the app chooser should show recommended applications
   * for the content type in a separate section.
   *
   * @param setting The new value for property_show_recommended().
   */
  void set_show_recommended(bool setting =  true);

  /** Gets whether the app chooser should show recommended applications
   * for the content type in a separate section.
   *
   * @return The value of property_show_recommended().
   */
  auto get_show_recommended() const -> bool;


  /** Sets whether the app chooser should show related applications
   * for the content type in a separate section.
   *
   * @param setting The new value for property_show_fallback().
   */
  void set_show_fallback(bool setting =  true);

  /** Gets whether the app chooser should show related applications
   * for the content type in a separate section.
   *
   * @return The value of property_show_fallback().
   */
  auto get_show_fallback() const -> bool;


  /** Sets whether the app chooser should show applications
   * which are unrelated to the content type.
   *
   * @param setting The new value for property_show_other().
   */
  void set_show_other(bool setting =  true);

  /** Gets whether the app chooser should show applications
   * which are unrelated to the content type.
   *
   * @return The value of property_show_other().
   */
  auto get_show_other() const -> bool;


  /** Sets whether the app chooser should show all applications
   * in a flat list.
   *
   * @param setting The new value for property_show_all().
   */
  void set_show_all(bool setting =  true);

  /** Gets whether the app chooser should show all applications
   * in a flat list.
   *
   * @return The value of property_show_all().
   */
  auto get_show_all() const -> bool;


  /** Sets the text that is shown if there are not applications
   * that can handle the content type.
   *
   * @param text The new value for property_default_text().
   */
  void set_default_text(const Glib::ustring& text);

  /** Returns the text that is shown if there are not applications
   * that can handle the content type.
   *
   * @return The value of property_default_text().
   */
  auto get_default_text() -> Glib::ustring;

  // no_default_handler because GtkAppChooserWidgetClass is private.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%application_selected(const Glib::RefPtr<Gio::AppInfo>& app_info)</tt>
   *
   * Flags: Run First
   *
   * Emitted when an application item is selected from the widget's list.
   *
   * @param app_info The selected `Gio::AppInfo`.
   */

  auto signal_application_selected() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::AppInfo>&)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%application_activated(const Glib::RefPtr<Gio::AppInfo>& app_info)</tt>
   *
   * Flags: Run First
   *
   * Emitted when an application item is activated from the widget's list.
   *
   * This usually happens when the user double clicks an item, or an item
   * is selected and the user presses one of the keys Space, Shift+Space,
   * Return or Enter.
   *
   * @param app_info The activated `Gio::AppInfo`.
   */

  auto signal_application_activated() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::AppInfo>&)>;


  /** Determines whether the app chooser should show the default
   * handler for the content type in a separate section.
   *
   * If <tt>false</tt>, the default handler is listed among the recommended
   * applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_default() -> Glib::PropertyProxy< bool > ;

/** Determines whether the app chooser should show the default
   * handler for the content type in a separate section.
   *
   * If <tt>false</tt>, the default handler is listed among the recommended
   * applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_default() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the app chooser should show a section
   * for recommended applications.
   *
   * If <tt>false</tt>, the recommended applications are listed
   * among the other applications.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_recommended() -> Glib::PropertyProxy< bool > ;

/** Determines whether the app chooser should show a section
   * for recommended applications.
   *
   * If <tt>false</tt>, the recommended applications are listed
   * among the other applications.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_recommended() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the app chooser should show a section
   * for fallback applications.
   *
   * If <tt>false</tt>, the fallback applications are listed among the
   * other applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_fallback() -> Glib::PropertyProxy< bool > ;

/** Determines whether the app chooser should show a section
   * for fallback applications.
   *
   * If <tt>false</tt>, the fallback applications are listed among the
   * other applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the app chooser should show a section
   * for other applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_other() -> Glib::PropertyProxy< bool > ;

/** Determines whether the app chooser should show a section
   * for other applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_other() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, the app chooser presents all applications
   * in a single list, without subsections for default,
   * recommended or related applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_all() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the app chooser presents all applications
   * in a single list, without subsections for default,
   * recommended or related applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_all() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The text that appears in the widget when there are no applications
   * for the given content type.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The text that appears in the widget when there are no applications
   * for the given content type.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::AppChooserWidget
   */
  GTKMM_API
  auto wrap(GtkAppChooserWidget* object, bool take_copy = false) -> Gtk::AppChooserWidget*;
} //namespace Glib


#endif /* _GTKMM_APPCHOOSERWIDGET_H */

