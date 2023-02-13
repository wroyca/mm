
#ifndef _GTKMM_APPLICATIONWINDOW_H
#define _GTKMM_APPLICATIONWINDOW_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <libmm-gtk/window.hpp>
#include <libmm-gio/actiongroup.hpp>
#include <libmm-gio/actionmap.hpp>
#include <libmm-gtk/application.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkApplicationWindow = struct _GtkApplicationWindow;
using GtkApplicationWindowClass = struct _GtkApplicationWindowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ApplicationWindow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API ShortcutsWindow;

/** A Gtk::Window subclass with Gtk::Application support.
 *
 * %ApplicationWindow is a Gtk::Window subclass that offers some
 * extra functionality for better integration with Gtk::Application
 * features.  Notably, it can handle both the application menu as well
 * as the menubar. See set_app_menu() and set_menubar().
 *
 * This class derives from Gio::ActionGroup and Gio::ActionMap,
 * to let you add window-specific actions that will be exported by the
 * associated Gtk::Application, together with its application-wide
 * actions.  Window-specific actions are prefixed with the "win."
 * prefix and application-wide actions are prefixed with the "app."
 * prefix.  Actions must be addressed with the prefixed name when
 * referring to them from a Gio::MenuModel, or in activate_action().
 * Gio::ActionGroup::activate_action() does not accept prefixes.
 *
 * Note that widgets that are placed inside a %Gtk::ApplicationWindow
 * can also activate these actions, if they implement the
 * Gtk::Actionable interface.
 *
 * As with Gtk::Application, the GDK lock will be acquired when
 * processing actions arriving from other processes and should therefore
 * be held when activating actions locally (if GDK threads are enabled).
 *
 * The settings Gtk::Settings::property_gtk_shell_shows_app_menu() and
 * Gtk::Settings::property_gtk_shell_shows_menubar() tell GTK whether the
 * desktop environment is showing the application menu and menubar
 * models outside the application as part of the desktop shell.
 * For instance, on OS X, both menus will be displayed remotely;
 * on Windows neither will be. gnome-shell (starting with version 3.4)
 * will display the application menu, but not the menubar.
 *
 * If the desktop environment does not display the menubar, then
 * %Gtk::ApplicationWindow will automatically show a menubar for it.
 * This behaviour can be overridden with property_show_menubar().
 * If the desktop environment does not display the application
 * menu, then it will automatically be included in the menubar.
 */

class GTKMM_API ApplicationWindow
: public Gtk::Window,
  public Gio::ActionGroup,
  public Gio::ActionMap
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ApplicationWindow CppObjectType;
  typedef ApplicationWindow_Class CppClassType;
  typedef GtkApplicationWindow BaseObjectType;
  typedef GtkApplicationWindowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  ApplicationWindow(ApplicationWindow&& src) noexcept;
  auto operator=(ApplicationWindow&& src) noexcept -> ApplicationWindow&;

  // noncopyable
  ApplicationWindow(const ApplicationWindow&) = delete;
  auto operator=(const ApplicationWindow&) -> ApplicationWindow& = delete;

  ~ApplicationWindow() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class ApplicationWindow_Class;
  static CppClassType applicationwindow_class_;

protected:
  explicit ApplicationWindow(const Glib::ConstructParams& construct_params);
  explicit ApplicationWindow(GtkApplicationWindow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkApplicationWindow*       { return reinterpret_cast<GtkApplicationWindow*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkApplicationWindow* { return reinterpret_cast<GtkApplicationWindow*>(gobject_); }

private:


public:
  // Disambiguate calls to activate_action().
  // g_action_group_activate_action() and gtk_widget_activate_action() are
  // very similar, but gtk_widget_activate_action() requires a "win." prefix.
  // If you prefer g_action_group_activate_action(), call
  // Gio::ActionGroup::activate_action().
  // https://discourse.gnome.org/t/which-activate-action-shall-be-chosen-in-gtkapplicationwindow/10555/2
  using Widget::activate_action;

  ApplicationWindow();
  explicit ApplicationWindow(const Glib::RefPtr<Application>& application);


  /** Sets whether the window will display a menubar for the app menu
   * and menubar as needed.
   *
   * @param show_menubar Whether to show a menubar when needed.
   */
  void set_show_menubar(bool show_menubar =  true);

  /** Returns whether the window will display a menubar for the app menu
   * and menubar as needed.
   *
   * @return <tt>true</tt> if @a window will display a menubar when needed.
   */
  auto get_show_menubar() const -> bool;


  /** Returns the unique ID of the window.
   *
   * If the window has not yet been added to a `Gtk::Application`, returns `0`.
   *
   * @return The unique ID for @a window, or `0` if the window
   * has not yet been added to a `Gtk::Application`.
   */
  auto get_id() const -> guint;


  /** Associates a shortcuts window with the application window.
   *
   * Additionally, sets up an action with the name
   * `win.show-help-overlay` to present it.
   *
   *  @a window takes responsibility for destroying @a help_overlay.
   *
   * @param help_overlay A `Gtk::ShortcutsWindow`.
   */
  void set_help_overlay(ShortcutsWindow& help_overlay);
  /** Undoes the effect of a previous call to set_help_overlay().
   * @newin{3,20}
   */
  void unset_help_overlay();

  /** Gets the `Gtk::ShortcutsWindow` that is associated with @a window.
   *
   * See set_help_overlay().
   *
   * @return The help overlay associated
   * with @a window.
   */
  auto get_help_overlay() -> ShortcutsWindow*;

  /** Gets the `Gtk::ShortcutsWindow` that is associated with @a window.
   *
   * See set_help_overlay().
   *
   * @return The help overlay associated
   * with @a window.
   */
  auto get_help_overlay() const -> const ShortcutsWindow*;

  /** If this property is <tt>true</tt>, the window will display a menubar
   * unless it is shown by the desktop shell.
   *
   * See Gtk::Application::set_menubar().
   *
   * If <tt>false</tt>, the window will not display a menubar, regardless
   * of whether the desktop shell is showing it or not.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_menubar() -> Glib::PropertyProxy< bool > ;

/** If this property is <tt>true</tt>, the window will display a menubar
   * unless it is shown by the desktop shell.
   *
   * See Gtk::Application::set_menubar().
   *
   * If <tt>false</tt>, the window will not display a menubar, regardless
   * of whether the desktop shell is showing it or not.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_menubar() const -> Glib::PropertyProxy_ReadOnly< bool >;


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
   * @relates Gtk::ApplicationWindow
   */
  GTKMM_API
  auto wrap(GtkApplicationWindow* object, bool take_copy = false) -> Gtk::ApplicationWindow*;
} //namespace Glib


#endif /* _GTKMM_APPLICATIONWINDOW_H */

