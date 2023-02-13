
#ifndef _GTKMM_WINDOW_H
#define _GTKMM_WINDOW_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2013 The gtkmm Development Team
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

#include <vector>

#include <libmm-glib/object.hxx>
#include <libmm-gdk/surface.hxx>
#include <libmm-gdk/texture.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/native.hxx>
#include <libmm-gtk/root.hxx>
#include <libmm-gtk/shortcutmanager.hxx>
#include <libmm-gtk/windowgroup.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWindow = struct _GtkWindow;
using GtkWindowClass = struct _GtkWindowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Window_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GTKMM_API ListModel;
}

namespace Gtk
{

class GTKMM_API Application;
class GTKMM_API WindowGroup;

/** Toplevel %Window.
 * This represents all widgets which are physical windows controlled
 * by the window manager.
 *
 * The window will be destroyed when the window manager's close button is clicked.
 * Call set_hide_on_close() if you want it to be hidden instead.
 *
 * When a window is closed (hidden), it's removed from its application.
 * This can cause Application::run() to return, if it is the last window.
 *
 * @ingroup Widgets
 */

class GTKMM_API Window : public Widget, public Native, public ShortcutManager, public Root
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Window CppObjectType;
  typedef Window_Class CppClassType;
  typedef GtkWindow BaseObjectType;
  typedef GtkWindowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  // noncopyable
  Window(const Window&) = delete;
  auto operator=(const Window&) -> Window& = delete;

  ~Window() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Window_Class;
  static CppClassType window_class_;

protected:
  explicit Window(const Glib::ConstructParams& construct_params);
  explicit Window(GtkWindow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto gobj() -> GtkWindow* { return reinterpret_cast<GtkWindow*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWindow* { return reinterpret_cast<GtkWindow*>(gobject_); }

private:


public:
  // Disambiguate calls to get_display(). Use Root::get_display(), not Widget::get_display().
  // gtk_widget_get_display() calls gtk_root_get_display(). There is no reason
  // to call gtk_widget_get_display() from a class that implements GtkRoot.
  using Root::get_display;

  // All constructors are hand-coded, because they connect a signal handler.


  Window(Window&& src) noexcept;
  auto operator=(Window&& src) noexcept -> Window&;

  explicit Window();


  /** The title of the window.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() -> Glib::PropertyProxy< Glib::ustring > ;

/** The title of the window.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** A write-only property for setting window's startup notification identifier.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_startup_id() -> Glib::PropertyProxy_WriteOnly< Glib::ustring > ;


  /** If <tt>true</tt>, users can resize the window.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, users can resize the window.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resizable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If <tt>true</tt>, the window is modal.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() -> Glib::PropertyProxy< bool > ;

/** If <tt>true</tt>, the window is modal.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The default width of the window.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_width() -> Glib::PropertyProxy< int > ;

/** The default width of the window.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_width() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The default height of the window.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_height() -> Glib::PropertyProxy< int > ;

/** The default height of the window.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_height() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** If this window should be destroyed when the parent is destroyed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_destroy_with_parent() -> Glib::PropertyProxy< bool > ;

/** If this window should be destroyed when the parent is destroyed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_destroy_with_parent() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** If this window should be hidden when the users clicks the close button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hide_on_close() -> Glib::PropertyProxy< bool > ;

/** If this window should be hidden when the users clicks the close button.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_hide_on_close() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether mnemonics are currently visible in this window.
   *
   * This property is maintained by GTK based on user input,
   * and should not be set by applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonics_visible() -> Glib::PropertyProxy< bool > ;

/** Whether mnemonics are currently visible in this window.
   *
   * This property is maintained by GTK based on user input,
   * and should not be set by applications.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_mnemonics_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Specifies the name of the themed icon to use as the window icon.
   *
   * See Gtk::IconTheme for more details.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** Specifies the name of the themed icon to use as the window icon.
   *
   * See Gtk::IconTheme for more details.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The display that will display this window.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Display> > ;

/** The display that will display this window.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Display> >;

  /** Whether the toplevel is the currently active window.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_active() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** Whether the window should have a frame (also known as *decorations*).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decorated() -> Glib::PropertyProxy< bool > ;

/** Whether the window should have a frame (also known as *decorations*).
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_decorated() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The transient parent of the window.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transient_for() -> Glib::PropertyProxy< Window* > ;

/** The transient parent of the window.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_transient_for() const -> Glib::PropertyProxy_ReadOnly< Window* >;


  /** Whether the window frame should have a close button.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_deletable() -> Glib::PropertyProxy< bool > ;

/** Whether the window frame should have a close button.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_deletable() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The `Gtk::Application` associated with the window.
   *
   * The application will be kept alive for at least as long as it
   * has any windows associated with it (see Glib::application_hold()
   * for a way to keep it alive without windows).
   *
   * Normally, the connection between the application and the window
   * will remain until the window is destroyed, but you can explicitly
   * remove it by setting the :application property to <tt>nullptr</tt>.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_application() -> Glib::PropertyProxy< Glib::RefPtr<Application> > ;

/** The `Gtk::Application` associated with the window.
   *
   * The application will be kept alive for at least as long as it
   * has any windows associated with it (see Glib::application_hold()
   * for a way to keep it alive without windows).
   *
   * Normally, the connection between the application and the window
   * will remain until the window is destroyed, but you can explicitly
   * remove it by setting the :application property to <tt>nullptr</tt>.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_application() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Application> >;

  /** Whether 'focus rectangles' are currently visible in this window.
   *
   * This property is maintained by GTK based on user input
   * and should not be set by applications.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_visible() -> Glib::PropertyProxy< bool > ;

/** Whether 'focus rectangles' are currently visible in this window.
   *
   * This property is maintained by GTK based on user input
   * and should not be set by applications.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_visible() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the window is maximized.
   *
   * Setting this property is the equivalent of calling
   * Gtk::Window::maximize() or Gtk::Window::unmaximize();
   * either operation is asynchronous, which means you will need to
   * connect to the signal_notify() signal in order to know whether the
   * operation was successful.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_maximized() -> Glib::PropertyProxy< bool > ;

/** Whether the window is maximized.
   *
   * Setting this property is the equivalent of calling
   * Gtk::Window::maximize() or Gtk::Window::unmaximize();
   * either operation is asynchronous, which means you will need to
   * connect to the signal_notify() signal in order to know whether the
   * operation was successful.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_maximized() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Whether the window is fullscreen.
   *
   * Setting this property is the equivalent of calling
   * Gtk::Window::fullscreen() or Gtk::Window::unfullscreen();
   * either operation is asynchronous, which means you will need to
   * connect to the signal_notify() signal in order to know whether the
   * operation was successful.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fullscreened() -> Glib::PropertyProxy< bool > ;

/** Whether the window is fullscreen.
   *
   * Setting this property is the equivalent of calling
   * Gtk::Window::fullscreen() or Gtk::Window::unfullscreen();
   * either operation is asynchronous, which means you will need to
   * connect to the signal_notify() signal in order to know whether the
   * operation was successful.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_fullscreened() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The default widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_widget() -> Glib::PropertyProxy< Widget* > ;

/** The default widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_default_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The focus widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_widget() -> Glib::PropertyProxy< Widget* > ;

/** The focus widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_focus_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The child widget.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() -> Glib::PropertyProxy< Widget* > ;

/** The child widget.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The titlebar widget.
   *
   * @newin{4,6}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_titlebar() -> Glib::PropertyProxy< Widget* > ;

/** The titlebar widget.
   *
   * @newin{4,6}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_titlebar() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** Whether the window frame should handle F10 for activating
   * menubars.
   *
   * @newin{4,2}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_handle_menubar_accel() -> Glib::PropertyProxy< bool > ;

/** Whether the window frame should handle F10 for activating
   * menubars.
   *
   * @newin{4,2}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_handle_menubar_accel() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%keys_changed()</tt>
   *
   * Flags: Run First
   *
   * emitted when the set of accelerators or mnemonics that
   * are associated with @a window changes.
   */

  auto signal_keys_changed() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%close_request()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user clicks on the close button of the window.
   *
   * Return: <tt>true</tt> to stop other handlers from being invoked for the signal
   */

  auto signal_close_request() -> Glib::SignalProxy<bool()>;


  //Keybinding signals:


  /** Sets the title of the `Gtk::Window`.
   *
   * The title of a window will be displayed in its title bar; on the
   * X&nbsp;%Window System, the title bar is rendered by the window manager
   * so exactly how the title appears to users may vary according to a
   * user’s exact configuration. The title should help a user distinguish
   * this window from other windows they may have open. A good title might
   * include the application name and current document filename, for example.
   *
   * Passing <tt>nullptr</tt> does the same as setting the title to an empty string.
   *
   * @param title Title of the window.
   */
  void set_title(const Glib::ustring& title);


  /** Retrieves the title of the window.
   *
   * @return The title of the window.
   */
  auto get_title() const -> Glib::ustring;


  /** Sets the startup notification ID.
   *
   * Startup notification identifiers are used by desktop environment
   * to track application startup, to provide user feedback and other
   * features. This function changes the corresponding property on the
   * underlying `Gdk::Surface`.
   *
   * Normally, startup identifier is managed automatically and you should
   * only use this function in special cases like transferring focus from
   * other processes. You should use this function before calling
   * present() or any equivalent function generating
   * a window map event.
   *
   * This function is only useful on X11, not with other GTK targets.
   *
   * @param startup_id A string with startup-notification identifier.
   */
  void set_startup_id(const Glib::ustring& startup_id);


  /** If @a focus is not the current focus widget, and is focusable, sets
   * it as the focus widget for the window. To set the focus to a particular
   * widget in the toplevel, it is usually more convenient to use
   * Gtk::Widget::grab_focus() instead of this function.
   *
   * @param focus Widget to be the new focus widget.
   */
  void set_focus(Gtk::Widget& focus);
  void unset_focus();


  /** Retrieves the current focused widget within the window.
   *
   * Note that this is the widget that would have the focus
   * if the toplevel window focused; if the toplevel window
   * is not focused then `gtk_widget_has_focus (widget)` will
   * not be <tt>true</tt> for the widget.
   *
   * @return The currently focused widget.
   */
  auto get_focus() -> Widget*;

  /** Retrieves the current focused widget within the window.
   *
   * Note that this is the widget that would have the focus
   * if the toplevel window focused; if the toplevel window
   * is not focused then `gtk_widget_has_focus (widget)` will
   * not be <tt>true</tt> for the widget.
   *
   * @return The currently focused widget.
   */
  auto get_focus() const -> const Widget*;

  /** Sets the default widget.
   *
   * The default widget is the widget that is activated when the user
   * presses Enter in a dialog (for example).
   *
   * @param default_widget Widget to be the default.
   */
  void set_default_widget(Gtk::Widget& default_widget);
  void unset_default_widget();


  /** Returns the default widget for @a window.
   *
   * @return The default widget.
   */
  auto get_default_widget() -> Widget*;

  /** Returns the default widget for @a window.
   *
   * @return The default widget.
   */
  auto get_default_widget() const -> const Widget*;


  /** Dialog windows should be set transient for the main application
   * window they were spawned from. This allows window managers to e.g.
   * keep the dialog on top of the main window, or center the dialog
   * over the main window. Gtk::Dialog::new_with_buttons() and other
   * convenience functions in GTK will sometimes call
   * set_transient_for() on your behalf.
   *
   * Passing <tt>nullptr</tt> for @a parent unsets the current transient window.
   *
   * On Windows, this function puts the child window on top of the parent,
   * much as the window manager would have done on X.
   *
   * @param parent Parent window.
   */
  void set_transient_for(Window& parent);

  /** Unsets the current transient window.
   * @see set_transient_for().
   * @newin{2,20}
   */
  void unset_transient_for();


  /** Fetches the transient parent for this window.
   *
   * @return The transient parent for this window.
   */
  auto get_transient_for() -> Window*;

  /** Fetches the transient parent for this window.
   *
   * @return The transient parent for this window.
   */
  auto get_transient_for() const -> const Window*;


  /** If @a setting is <tt>true</tt>, then destroying the transient parent of @a window
   * will also destroy @a window itself.
   *
   * This is useful for dialogs that shouldn’t persist beyond the lifetime
   * of the main window they are associated with, for example.
   *
   * @newin{4,8}
   *
   * @param setting Whether to destroy @a window with its transient parent.
   */
  void set_destroy_with_parent(bool setting =  true);

  /** Returns whether the window will be destroyed with its transient parent.
   *
   * @return <tt>true</tt> if the window will be destroyed with its transient parent.
   */
  auto get_destroy_with_parent() const -> bool;

  /** Drop the internal reference GTK holds on toplevel windows.
   *
   * If this window is managed, this C++ wrapper will be deleted when the
   * underlying C instance is destroyed.
   *
   * After a call to %destroy(), don't call any method that accesses the
   * underlying C instance.
   *
   * If the C++ wrapper is deleted, the underlying C instance will be destroyed.
   * If the C instance is destroyed and the C++ wrapper is managed, the wrapper
   * will be deleted. The difference is in the order in which actions are taken.
   * That may or may not be important. If the C instance is destroyed before
   * the wrapper is deleted, C++ signal handlers can be called during the destruction.
   * For instance, if you connect to Gtk::Widget::signal_unrealize() or override
   * Gtk::Widget::on_unrealize(), those signal handlers can be called only if
   * the wrapper still exists when the signal is emitted.
   *
   * @newin{4,8}
   */
  void destroy();


  /** If @a setting is <tt>true</tt>, then clicking the close button on the window
   * will not destroy it, but only hide it.
   *
   * @param setting Whether to hide the window when it is closed.
   */
  void set_hide_on_close(bool setting =  true);

  /** Returns whether the window will be hidden when the close button is clicked.
   *
   * @return <tt>true</tt> if the window will be hidden.
   */
  auto get_hide_on_close() const -> bool;


  /** Sets whether mnemonics are supposed to be visible.
   *
   * @param setting The new value.
   */
  void set_mnemonics_visible(bool setting =  true);

  /** Gets whether mnemonics are supposed to be visible.
   *
   * @return <tt>true</tt> if mnemonics are supposed to be visible
   * in this window.
   */
  auto get_mnemonics_visible() const -> bool;


  /** Sets whether “focus rectangles” are supposed to be visible.
   *
   * @param setting The new value.
   */
  void set_focus_visible(bool setting =  true);

  /** Gets whether “focus rectangles” are supposed to be visible.
   *
   * @return <tt>true</tt> if “focus rectangles” are supposed to be visible
   * in this window.
   */
  auto get_focus_visible() const -> bool;


  /** Sets whether the user can resize a window.
   *
   * Windows are user resizable by default.
   *
   * @param resizable <tt>true</tt> if the user can resize this window.
   */
  void set_resizable(bool resizable =  true);


  /** Gets the value set by set_resizable().
   *
   * @return <tt>true</tt> if the user can resize the window.
   */
  auto get_resizable() const -> bool;


  /** Sets the `Gdk::Display` where the @a window is displayed.
   *
   * If the window is already mapped, it will be unmapped,
   * and then remapped on the new display.
   *
   * @param display A `Gdk::Display`.
   */
  void set_display(const Glib::RefPtr<Gdk::Display>& display);


  /** Returns whether the window is part of the current active toplevel.
   *
   * The active toplevel is the window receiving keystrokes.
   *
   * The return value is <tt>true</tt> if the window is active toplevel itself.
   * You might use this function if you wanted to draw a widget
   * differently in an active window from a widget in an inactive window.
   *
   * @return <tt>true</tt> if the window part of the current active window.
   */
  auto is_active() const -> bool;


  /** Sets whether the window should be decorated.
   *
   * By default, windows are decorated with a title bar, resize
   * controls, etc. Some window managers allow GTK to disable these
   * decorations, creating a borderless window. If you set the decorated
   * property to <tt>false</tt> using this function, GTK will do its best to
   * convince the window manager not to decorate the window. Depending on
   * the system, this function may not have any effect when called on a
   * window that is already visible, so you should call it before calling
   * Gtk::Widget::show().
   *
   * On Windows, this function always works, since there’s no window manager
   * policy involved.
   *
   * @param setting <tt>true</tt> to decorate the window.
   */
  void set_decorated(bool setting =  true);

  /** Returns whether the window has been set to have decorations.
   *
   * @return <tt>true</tt> if the window has been set to have decorations.
   */
  auto get_decorated() const -> bool;


  /** Sets whether the window should be deletable.
   *
   * By default, windows have a close button in the window frame.
   * Some  window managers allow GTK to disable this button. If you
   * set the deletable property to <tt>false</tt> using this function, GTK
   * will do its best to convince the window manager not to show a
   * close button. Depending on the system, this function may not
   * have any effect when called on a window that is already visible,
   * so you should call it before calling Gtk::Widget::show().
   *
   * On Windows, this function always works, since there’s no window
   * manager policy involved.
   *
   * @param setting <tt>true</tt> to decorate the window as deletable.
   */
  void set_deletable(bool setting =  true);

  /** Returns whether the window has been set to have a close button.
   *
   * @return <tt>true</tt> if the window has been set to have a close button.
   */
  auto get_deletable() const -> bool;


  /** Sets the icon for the window from a named themed icon.
   *
   * See the docs for Gtk::IconTheme for more details.
   * On some platforms, the window icon is not used at all.
   *
   * Note that this has nothing to do with the WM_ICON_NAME
   * property which is mentioned in the ICCCM.
   *
   * @newin{2,18}
   *
   * @param name The name of the themed icon.
   */
  void set_icon_name(const Glib::ustring& name);

  /** Returns the name of the themed icon for the window.
   *
   * @return The icon name.
   */
  auto get_icon_name() const -> Glib::ustring;


  /** Sets an icon to be used as fallback.
   *
   * The fallback icon is used for windows that
   * haven't had set_icon_name()
   * called on them.
   *
   * @param name The name of the themed icon.
   */
  static void set_default_icon_name(const Glib::ustring& name);

  /** Returns the fallback icon name for windows.
   *
   * The returned string is owned by GTK and should not
   * be modified. It is only valid until the next call to
   * set_default_icon_name().
   *
   * @return The fallback icon name for windows.
   */
  static auto get_default_icon_name() -> Glib::ustring;

  /** Sets whether the window should request startup notification.
   *
   * By default, after showing the first `Gtk::Window`, GTK calls
   * Gdk::Display::notify_startup_complete(). Call this function
   * to disable the automatic startup notification. You might do this
   * if your first window is a splash screen, and you want to delay
   * notification until after your real main window has been shown,
   * for example.
   *
   * In that example, you would disable startup notification
   * temporarily, show your splash screen, then re-enable it so that
   * showing the main window would automatically result in notification.
   *
   * @param setting <tt>true</tt> to automatically do startup notification.
   */
  static void set_auto_startup_notification(bool setting =  true);


  /** Sets a window modal or non-modal.
   *
   * Modal windows prevent interaction with other windows in the same
   * application. To keep modal dialogs on top of main application windows,
   * use set_transient_for() to make the dialog transient
   * for the parent; most window managers will then disallow lowering the
   * dialog below the parent.
   *
   * @param modal Whether the window is modal.
   */
  void set_modal(bool modal =  true);

  /** Returns whether the window is modal.
   *
   * @return <tt>true</tt> if the window is set to be modal and
   * establishes a grab when shown.
   */
  auto get_modal() const -> bool;


  /** Returns a list of all existing toplevel windows.
   *
   * If you want to iterate through the list and perform actions involving
   * callbacks that might destroy the widgets or add new ones, be aware that
   * the list of toplevels will change and emit the "items-changed" signal.
   *
   * @return The list
   * of toplevel widgets.
   */
  static auto get_toplevels() -> Glib::RefPtr<Gio::ListModel>;


  /** Returns a list of all existing toplevel windows.
   *
   * The widgets in the list are not individually referenced.
   * If you want to iterate through the list and perform actions
   * involving callbacks that might destroy the widgets, you must
   * call `g_list_foreach (result, (GFunc)g_object_ref, <tt>nullptr</tt>)` first,
   * and then unref all the widgets afterwards.
   *
   * @return List of
   * toplevel widgets.
   */
  static auto list_toplevels() -> std::vector<Window*>;


  /** Presents a window to the user.
   *
   * This function should not be used as when it is called,
   * it is too late to gather a valid timestamp to allow focus
   * stealing prevention to work correctly.
   */
  void present();

  /** Presents a window to the user.
   *
   * This may mean raising the window in the stacking order,
   * unminimizing it, moving it to the current desktop, and/or
   * giving it the keyboard focus, possibly dependent on the user’s
   * platform, window manager, and preferences.
   *
   * If @a window is hidden, this function calls Gtk::Widget::show()
   * as well.
   *
   * This function should be used when the user tries to open a window
   * that’s already open. Say for example the preferences dialog is
   * currently open, and the user chooses Preferences from the menu
   * a second time; use present() to move the
   * already-open dialog where the user can see it.
   *
   * Presents a window to the user in response to a user interaction.
   * The timestamp should be gathered when the window was requested
   * to be shown (when clicking a link for example), rather than once
   * the window is ready to be shown.
   *
   * @param timestamp The timestamp of the user interaction (typically a
   * button or key press event) which triggered this call.
   */
  void present(guint32 timestamp);


  /** Asks to minimize the specified @a window.
   *
   * Note that you shouldn’t assume the window is definitely minimized
   * afterward, because the windowing system might not support this
   * functionality; other entities (e.g. the user or the window manager
   * could unminimize it again, or there may not be a window manager in
   * which case minimization isn’t possible, etc.
   *
   * It’s permitted to call this function before showing a window,
   * in which case the window will be minimized before it ever appears
   * onscreen.
   *
   * You can track result of this operation via the
   * Gdk::Toplevel::property_state() property.
   */
  void minimize();

  /** Asks to unminimize the specified @a window.
   *
   * Note that you shouldn’t assume the window is definitely unminimized
   * afterward, because the windowing system might not support this
   * functionality; other entities (e.g. the user or the window manager
   * could minimize it again, or there may not be a window manager in
   * which case minimization isn’t possible, etc.
   *
   * You can track result of this operation via the
   * Gdk::Toplevel::property_state() property.
   */
  void unminimize();


  /** Asks to maximize @a window, so that it fills the screen.
   *
   * Note that you shouldn’t assume the window is definitely maximized
   * afterward, because other entities (e.g. the user or window manager
   * could unmaximize it again, and not all window managers support
   * maximization.
   *
   * It’s permitted to call this function before showing a window,
   * in which case the window will be maximized when it appears onscreen
   * initially.
   *
   * You can track the result of this operation via the
   * Gdk::Toplevel::property_state() property, or by listening to
   * notifications on the property_maximized()
   * property.
   */
  void maximize();

  /** Asks to unmaximize @a window.
   *
   * Note that you shouldn’t assume the window is definitely unmaximized
   * afterward, because other entities (e.g. the user or window manager
   * maximize it again, and not all window managers honor requests to
   * unmaximize.
   *
   * You can track the result of this operation via the
   * Gdk::Toplevel::property_state() property, or by listening to
   * notifications on the property_maximized() property.
   */
  void unmaximize();


  /** Asks to place @a window in the fullscreen state.
   *
   * Note that you shouldn’t assume the window is definitely fullscreen
   * afterward, because other entities (e.g. the user or window manager
   * unfullscreen it again, and not all window managers honor requests
   * to fullscreen windows.
   *
   * You can track the result of this operation via the
   * Gdk::Toplevel::property_state() property, or by listening to
   * notifications of the property_fullscreened() property.
   */
  void fullscreen();

  /** Asks to remove the fullscreen state for @a window, and return to
   * its previous state.
   *
   * Note that you shouldn’t assume the window is definitely not
   * fullscreen afterward, because other entities (e.g. the user or
   * window manager could fullscreen it again, and not all window
   * managers honor requests to unfullscreen windows; normally the
   * window will end up restored to its normal state. Just don’t
   * write code that crashes if not.
   *
   * You can track the result of this operation via the
   * Gdk::Toplevel::property_state() property, or by listening to
   * notifications of the property_fullscreened() property.
   */
  void unfullscreen();

  /** Asks to place @a window in the fullscreen state on the given @a monitor.
   *
   * Note that you shouldn't assume the window is definitely fullscreen
   * afterward, or that the windowing system allows fullscreen windows on
   * any given monitor.
   *
   * You can track the result of this operation via the
   * Gdk::Toplevel::property_state() property, or by listening to
   * notifications of the property_fullscreened() property.
   *
   * @param monitor Which monitor to go fullscreen on.
   */
  void fullscreen_on_monitor(const Glib::RefPtr<Gdk::Monitor>& monitor);

  /** Requests that the window is closed.
   *
   * This is similar to what happens when a window manager
   * close button is clicked.
   *
   * This function can be used with close buttons in custom
   * titlebars.
   */
  void close();


  /** Sets the default size of a window.
   *
   * If the window’s “natural” size (its size request) is larger than
   * the default, the default will be ignored.
   *
   * Unlike Gtk::Widget::set_size_request(), which sets a size
   * request for a widget and thus would keep users from shrinking
   * the window, this function only sets the initial size, just as
   * if the user had resized the window themselves. Users can still
   * shrink the window again as they normally would. Setting a default
   * size of -1 means to use the “natural” default size (the size request
   * of the window).
   *
   * The default size of a window only affects the first time a window is
   * shown; if a window is hidden and re-shown, it will remember the size
   * it had prior to hiding, rather than using the default size.
   *
   * Windows can’t actually be 0x0 in size, they must be at least 1x1, but
   * passing 0 for @a width and @a height is OK, resulting in a 1x1 default size.
   *
   * If you use this function to reestablish a previously saved window size,
   * note that the appropriate size to save is the one returned by
   * get_default_size(). Using the window allocation
   * directly will not work in all circumstances and can lead to growing
   * or shrinking windows.
   *
   * @param width Width in pixels, or -1 to unset the default width.
   * @param height Height in pixels, or -1 to unset the default height.
   */
  void set_default_size(int width, int height);


  /** Gets the default size of the window.
   *
   * A value of 0 for the width or height indicates that a default
   * size has not been explicitly set for that dimension, so the
   * “natural” size of the window will be used.
   *
   * @param width Location to store the default width.
   * @param height Location to store the default height.
   */
  void get_default_size(int& width, int& height) const;


  /** Returns the group for @a window.
   *
   * If the window has no group, then the default group is returned.
   *
   * @return The `Gtk::WindowGroup` for a window
   * or the default group.
   */
  auto get_group() -> Glib::RefPtr<WindowGroup>;

  /** Returns the group for @a window.
   *
   * If the window has no group, then the default group is returned.
   *
   * @return The `Gtk::WindowGroup` for a window
   * or the default group.
   */
  auto get_group() const -> Glib::RefPtr<const WindowGroup>;


  /** Returns whether @a window has an explicit window group.
   *
   * @return <tt>true</tt> if @a window has an explicit window group.
   */
  auto has_group() const -> bool;


  /** Gets the `Gtk::Application` associated with the window.
   *
   * @return A `Gtk::Application`.
   */
  auto get_application() -> Glib::RefPtr<Application>;

  /** Gets the `Gtk::Application` associated with the window.
   *
   * @return A `Gtk::Application`.
   */
  auto get_application() const -> Glib::RefPtr<const Application>;

  // Concerning the removal of a hidden window from the application, see
  // https://bugzilla.gnome.org/show_bug.cgi?id=639931 and Gtk::Widget_Class::hide_callback().

  /** Sets the Gtk::Application associated with the window.
   *
   * The application will be kept alive for at least as long as it has any windows
   * associated with it. (See Gio::Application::hold() for a way to keep it alive
   * without windows.)
   *
   * Normally, the connection between the application and the window will remain
   * until the window is closed (hidden), but you can explicitly remove it by
   * calling unset_application().
   *
   * This is equivalent to calling Gtk::Application::remove_window() and/or
   * Gtk::Application::add_window() on the old/new applications as relevant.
   *
   * @param application A Gtk::Application.
   */
  void set_application(const Glib::RefPtr<Application>& application);

  /** Unsets the Application associated with the window.
   * This could cause the application to exit if it is the application's last window.
   */
  void unset_application();


  /** Sets the child widget of @a window.
   *
   * @param child The child widget.
   */
  void set_child(Widget& child);
  void unset_child();

  /** Gets the child widget of @a window.
   *
   * @return The child widget of @a window.
   */
  auto get_child() -> Widget*;

  /** Gets the child widget of @a window.
   *
   * @return The child widget of @a window.
   */
  auto get_child() const -> const Widget*;


  /** Sets a custom titlebar for @a window.
   *
   * A typical widget used here is Gtk::HeaderBar, as it
   * provides various features expected of a titlebar while allowing
   * the addition of child widgets to it.
   *
   * If you set a custom titlebar, GTK will do its best to convince
   * the window manager not to put its own titlebar on the window.
   * Depending on the system, this function may not work for a window
   * that is already visible, so you set the titlebar before calling
   * Gtk::Widget::show().
   *
   * @param titlebar The widget to use as titlebar.
   */
  void set_titlebar(Widget& titlebar);

  /** Unsets the titlebar.
   * @see set_titlebar()
   */
  void unset_titlebar();


  /** Returns the custom titlebar that has been set with
   * set_titlebar().
   *
   * @return The custom titlebar.
   */
  auto get_titlebar() -> Widget*;

  /** Returns the custom titlebar that has been set with
   * set_titlebar().
   *
   * @return The custom titlebar.
   */
  auto get_titlebar() const -> const Widget*;


  /** Retrieves the current maximized state of @a window.
   *
   * Note that since maximization is ultimately handled by the window
   * manager and happens asynchronously to an application request, you
   * shouldn’t assume the return value of this function changing
   * immediately (or at all), as an effect of calling
   * maximize() or unmaximize().
   *
   * If the window isn't yet mapped, the value returned will whether the
   * initial requested state is maximized.
   *
   * @return Whether the window has a maximized state.
   */
  auto is_maximized() const -> bool;

  /** Retrieves the current fullscreen state of @a window.
   *
   * Note that since fullscreening is ultimately handled by the window
   * manager and happens asynchronously to an application request, you
   * shouldn’t assume the return value of this function changing
   * immediately (or at all), as an effect of calling
   * fullscreen() or unfullscreen().
   *
   * If the window isn't yet mapped, the value returned will whether the
   * initial requested state is fullscreen.
   *
   * @return Whether the window has a fullscreen state.
   */
  auto is_fullscreen() const -> bool;


  /** Sets whether this window should react to F10 key presses
   * by activating a menubar it contains.
   *
   * @newin{4,2}
   *
   * @param handle_menubar_accel <tt>true</tt> to make @a window handle F10.
   */
  void set_handle_menubar_accel(bool handle_menubar_accel);

  /** Returns whether this window reacts to F10 key presses by
   * activating a menubar it contains.
   *
   * @newin{4,2}
   *
   * @return <tt>true</tt> if the window handles F10.
   */
  auto get_handle_menubar_accel() const -> bool;

  // from gtk/gtkshow.h:
  //TODO: _WRAP_METHOD(void show_uri(const Glib::ustring& uri, guint32 timestamp), gtk_show_uri)
  // gtk_show_uri_full[_finish]()

  /** Used by Gtk::manage() and Gtk::make_managed(). You should not need to use this directly.
   * Overridden because a %Gtk::Window is not managed by a container.
   * Beginning with gtkmm 4.8, a %Gtk::Window can be managed. If managed, it's
   * deleted when its underlying C instance is destroyed.
   */
  void set_manage() override;

protected:
  void on_window_hide();

  //See comments in the implementations:
  void destroy_();
  void _release_c_instance();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_keys_changed().
  virtual void on_keys_changed();
  /// This is a default handler for the signal signal_close_request().
  virtual auto on_close_request() -> bool;


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
   * @relates Gtk::Window
   */
  GTKMM_API
  auto wrap(GtkWindow* object, bool take_copy = false) -> Gtk::Window*;
} //namespace Glib


#endif /* _GTKMM_WINDOW_H */
