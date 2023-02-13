
#ifndef _GTKMM_APPLICATION_H
#define _GTKMM_APPLICATION_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003-2014 The gtkmm Development Team
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


#include <vector>
#include <type_traits>
#include <utility>
#include <libmm-gio/application.hxx>
#include <libmm-gio/menumodel.hxx>
#include <libmm-gio/menu.hxx>
#include <libmm-gtk/window.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkApplication = struct _GtkApplication;
using GtkApplicationClass = struct _GtkApplicationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Application_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

//TODO: Add overview documentation discussing the techniques show in the examples in gtkmm-docmentation.
//TODO: Add the screenshots from the C API?

/** Application class.
 *
 * The %Gtk::Application class handles many important aspects
 * of a GTK+ application in a convenient fashion, without enforcing
 * a one-size-fits-all application model.
 *
 * Currently, %Gtk::Application handles GTK and gtkmm initialization, application
 * uniqueness, session management, provides some basic scriptability and
 * desktop shell integration by exporting actions and menus, and manages a
 * list of toplevel windows whose life-cycle is automatically tied to the
 * life-cycle of your application.
 *
 * While %Gtk::Application works fine with plain Gtk::Window%s, it is recommended
 * to use it together with Gtk::ApplicationWindow.
 *
 * When GDK threads are enabled, %Gtk::Application will acquire the GDK
 * lock when invoking actions that arrive from other processes.  The GDK
 * lock is not touched for local action invocations.  In order to have
 * actions invoked in a predictable context it is therefore recommended
 * that the GDK lock be held while invoking actions locally with
 * Gio::ActionGroup::activate_action().  The same applies to actions
 * associated with Gtk::ApplicationWindow and to the Gio::Application::activate() and
 * Gio::Application::open() methods.
 *
 * To specify a menubar that will be shown by
 * Gtk::ApplicationWindow%s, use set_menubar(). Use the base
 * Gio::ActionMap interface to add actions, to respond to the user
 * selecting these menu items.
 *
 * %Gtk::Application optionally registers with a session manager
 * of the users session (if you set the register-session
 * property) and offers various functionality related to the session
 * life-cycle.
 *
 * An application can block various ways to end the session with
 * the inhibit() method. Typical use cases for
 * this kind of inhibiting are long-running, uninterruptible operations,
 * such as burning a CD or performing a disk backup. The session
 * manager may not honor the inhibitor, but it can be expected to
 * inform the user about the negative consequences of ending the
 * session while inhibitors are present.
 *
 * @note
 * Most widgets can't safely be created before the application has been registered
 * (Gio::Application::register_application() called) or activated
 * (Gio::Application::signal_activate() emitted).
 * They can't safely be deleted after run() or make_window_and_run() returns.
 *
 * @newin{3,4}
 */

class GTKMM_API Application
  : public Gio::Application
{
protected:

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Application;
  using CppClassType = Application_Class;
  using BaseObjectType = GtkApplication;
  using BaseClassType = GtkApplicationClass;

  // noncopyable
  Application(const Application&) = delete;
  auto operator=(const Application&) -> Application& = delete;

private:  friend class Application_Class;
  static CppClassType application_class_;

protected:
  explicit Application(const Glib::ConstructParams& construct_params);
  explicit Application(GtkApplication* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Application(Application&& src) noexcept;
  auto operator=(Application&& src) noexcept -> Application&;

  ~Application() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkApplication*       { return reinterpret_cast<GtkApplication*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkApplication* { return reinterpret_cast<GtkApplication*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkApplication*;

private:


protected:
  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you.
   * The global locale is set as specified by Glib::set_init_to_users_preferred_locale().
   *
   * If non-empty, the application ID must be valid. See Gio::Application::id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param application_id A valid application ID.
   * @param flags The application flags.
   *
   * @newin{3,4}
   */
  explicit Application(const Glib::ustring& application_id = {}, Gio::Application::Flags flags = Gio::Application::Flags::NONE);


public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var InhibitFlags LOGOUT
   * Inhibit ending the user session
   * by logging out or by shutting down the computer.
   *
   *  @var InhibitFlags SWITCH
   * Inhibit user switching.
   *
   *  @var InhibitFlags SUSPEND
   * Inhibit suspending the
   * session or computer.
   *
   *  @var InhibitFlags IDLE
   * Inhibit the session being
   * marked as idle (and possibly locked).
   *
   *  @enum InhibitFlags
   *
   * Types of user actions that may be blocked by `Gtk::Application`.
   *
   * See Gtk::Application::inhibit().
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>Application::InhibitFlags operator|(Application::InhibitFlags, Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags operator&(Application::InhibitFlags, Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags operator^(Application::InhibitFlags, Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags operator~(Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags& operator|=(Application::InhibitFlags&, Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags& operator&=(Application::InhibitFlags&, Application::InhibitFlags)</tt><br>
   * <tt>Application::InhibitFlags& operator^=(Application::InhibitFlags&, Application::InhibitFlags)</tt><br>
   */
  enum class InhibitFlags
  {
    LOGOUT = (1 << 0),
    SWITCH = (1 << 1),
    SUSPEND = (1 << 2),
    IDLE = (1 << 3)
  };


  /** Creates a new Application instance.
   *
   * This initializes gtkmm (and the GObject type system) for you.
   * The global locale is set as specified by Glib::set_init_to_users_preferred_locale().
   *
   * If non-empty, the application ID must be valid. See Gio::Application::id_is_valid().
   *
   * If no application ID is given then some features (most notably application
   * uniqueness) will be disabled. A null application ID is only allowed with
   * gtkmm 3.6 or later.
   *
   * @param application_id A valid application ID.
   * @param flags The application flags.
   *
   * @newin{3,4}
   */
  static auto create(const Glib::ustring& application_id = {}, Gio::Application::Flags flags = Gio::Application::Flags::NONE) -> Glib::RefPtr<Application>;


  /** Gets a list of the Gtk::Window instances associated with `application`.
   *
   * The list is sorted by most recently focused window, such that the first
   * element is the currently focused window. (Useful for choosing a parent
   * for a transient window.)
   *
   * The list that is returned should not be modified in any way. It will
   * only remain valid until the next focus change or window creation or
   * deletion.
   *
   * @return A `GList` of `Gtk::Window`
   * instances.
   */
  auto get_windows() -> std::vector<Window*>;


  /** Gets a list of the Gtk::Window instances associated with `application`.
   *
   * The list is sorted by most recently focused window, such that the first
   * element is the currently focused window. (Useful for choosing a parent
   * for a transient window.)
   *
   * The list that is returned should not be modified in any way. It will
   * only remain valid until the next focus change or window creation or
   * deletion.
   *
   * @return A `GList` of `Gtk::Window`
   * instances.
   */
  auto get_windows() const -> std::vector<const Window*>;

  // Concerning the note on quit(), see https://bugzilla.gnome.org/show_bug.cgi?id=731126
  // Concerning the return from run() on hidden windows, see
  // https://bugzilla.gnome.org/show_bug.cgi?id=639931 and Gtk::Widget_Class::hide_callback().

  /** Adds a window to the Gtk::Application.
   *
   * If all the windows managed by Gtk::Application are closed (hidden) or
   * removed from the application then the call to run() will return,
   * unless Gio::Application::hold() has been called.
   *
   * This call is equivalent to calling Gtk::Window::set_application().
   *
   * Normally, the connection between the application and the window
   * will remain until the window is closed (hidden) or destroyed, but you can explicitly
   * remove it with remove_window().
   *
   * @note If you call Gio::Application::quit() while a window is connected to
   * the application, and then return from main() without removing the window
   * from the application, the application's destructor will not be called.
   *
   * @newin{3,4}
   *
   * @param window A toplevel window to add to the application.
   */
  void add_window(Window& window);


  /** Remove a window from `application`.
   *
   * If `window` belongs to `application` then this call is equivalent to
   * setting the Gtk::Window::property_application() property of `window` to
   * <tt>nullptr</tt>.
   *
   * The application may stop running as a result of a call to this
   * function, if `window` was the last window of the `application`.
   *
   * @param window A `Gtk::Window`.
   */
  void remove_window(Window& window);

  /** Starts the application.
   *
   * @param argc The argc from main() (or 0 if @a argv is <tt>nullptr</tt>).
   * @param argv The argv from main(), or <tt>nullptr</tt>.
   * @return The exit status.
   *
   * @see Gio::Application::run()
   *
   * @newin{3,4}
   */
  auto run(int argc, char** argv) -> int;

  /** Starts the application.
   *
   * @return The exit status.
   *
   * @see Gio::Application::run()
   *
   * @newin{3,4}
   */
  auto run() -> int;

  /** Starts the application, creates and presents a window.
   *
   * A window of type T_Window is constructed and added to the application
   * in a signal_activate() handler. The window is deleted when it is hidden
   * or removed from the application. The method returns when the window is hidden,
   * unless other windows have been added but not removed.
   *
   * The window is only constructed on the first activate signal. Any activations
   * thereafter only cause the window to be raised.
   *
   * @tparam T_Window The type of window to present. Must be Gtk::Window or a class type
   *                  that inherits from Gtk::Window.
   * @param argc The argc from main() (or 0 if @a argv is <tt>nullptr</tt>).
   * @param argv The argv from main(), or <tt>nullptr</tt>.
   * @param args Arguments to T_Window's constructor, if any.
   * @return The exit status.
   *
   * @see Gio::Application::run()
   *
   * @newin{3,98}
   */
  template <typename T_Window, typename... T_Args>
  auto make_window_and_run(int argc, char** argv, T_Args&&... args) -> int;

  /** Get the window, constructed by make_window_and_run().
   */
  auto get_run_window() -> Window* { return m_run_window; }
  /** Get the window, constructed by make_window_and_run().
   */
  auto get_run_window() const -> const Window* { return m_run_window; }


  /** Returns the menu model that has been set with
   * set_menubar().
   *
   * @return The menubar for windows of `application`.
   */
  auto get_menubar() -> Glib::RefPtr<Gio::MenuModel>;

  /** Returns the menu model that has been set with
   * set_menubar().
   *
   * @return The menubar for windows of `application`.
   */
  auto get_menubar() const -> Glib::RefPtr<const Gio::MenuModel>;


  /** Sets or unsets the menubar for windows of `application`.
   *
   * This is a menubar in the traditional sense.
   *
   * This can only be done in the primary instance of the application,
   * after it has been registered. `GApplication::startup` is a good place
   * to call this.
   *
   * Depending on the desktop environment, this may appear at the top of
   * each window, or at the top of the screen.  In some environments, if
   * both the application menu and the menubar are set, the application
   * menu will be presented as if it were the first item of the menubar.
   * Other environments treat the two as completely separate — for example,
   * the application menu may be rendered by the desktop shell while the
   * menubar (if set) remains in each individual window.
   *
   * Use the base `Gio::ActionMap` interface to add actions, to respond to the
   * user selecting these menu items.
   *
   * @param menubar A `Gio::MenuModel`.
   */
  void set_menubar(const Glib::RefPtr<Gio::MenuModel>& menubar);


  /** Inform the session manager that certain types of actions should be
   * inhibited.
   *
   * This is not guaranteed to work on all platforms and for all types of
   * actions.
   *
   * Applications should invoke this method when they begin an operation
   * that should not be interrupted, such as creating a CD or DVD. The
   * types of actions that may be blocked are specified by the `flags`
   * parameter. When the application completes the operation it should
   * call uninhibit() to remove the inhibitor. Note
   * that an application can have multiple inhibitors, and all of them must
   * be individually removed. Inhibitors are also cleared when the
   * application exits.
   *
   * Applications should not expect that they will always be able to block
   * the action. In most cases, users will be given the option to force
   * the action to take place.
   *
   * The `reason` message should be short and to the point.
   *
   * If `window` is given, the session manager may point the user to
   * this window to find out more about why the action is inhibited.
   *
   * @param window A `Gtk::Window`.
   * @param flags What types of actions should be inhibited.
   * @param reason A short, human-readable string that explains
   * why these operations are inhibited.
   * @return A non-zero cookie that is used to uniquely identify this
   * request. It should be used as an argument to uninhibit()
   * in order to remove the request. If the platform does not support
   * inhibiting or the request failed for some reason, 0 is returned.
   */
  auto inhibit(Window& window, InhibitFlags flags, const Glib::ustring& reason) -> guint;

  /** Removes an inhibitor that has been previously established.
   *
   * See inhibit().
   *
   * Inhibitors are also cleared when the application exits.
   *
   * @param cookie A cookie that was returned by inhibit().
   */
  void uninhibit(guint cookie);


  /** Returns the Gtk::ApplicationWindow with the given ID.
   *
   * The ID of a `Gtk::ApplicationWindow` can be retrieved with
   * Gtk::ApplicationWindow::get_id().
   *
   * @param id An identifier number.
   * @return The window for the given `id`.
   */
  auto get_window_by_id(guint id) -> Window*;

  /** Returns the Gtk::ApplicationWindow with the given ID.
   *
   * The ID of a `Gtk::ApplicationWindow` can be retrieved with
   * Gtk::ApplicationWindow::get_id().
   *
   * @param id An identifier number.
   * @return The window for the given `id`.
   */
  auto get_window_by_id(guint id) const -> const Window*;


  /** Gets the “active” window for the application.
   *
   * The active window is the one that was most recently focused (within
   * the application).  This window may not have the focus at the moment
   * if another application has it — this is just the most
   * recently-focused window within this application.
   *
   * @return The active window.
   */
  auto get_active_window() -> Window*;

  /** Gets the “active” window for the application.
   *
   * The active window is the one that was most recently focused (within
   * the application).  This window may not have the focus at the moment
   * if another application has it — this is just the most
   * recently-focused window within this application.
   *
   * @return The active window.
   */
  auto get_active_window() const -> const Window*;


  /** Lists the detailed action names which have associated accelerators.
   *
   * See set_accels_for_action().
   *
   * @return The detailed action names.
   */
  auto list_action_descriptions() const -> std::vector<Glib::ustring>;


  /** Gets the accelerators that are currently associated with
   * the given action.
   *
   * @param detailed_action_name A detailed action name, specifying an action
   * and target to obtain accelerators for.
   * @return Accelerators for `detailed_action_name`.
   */
  auto get_accels_for_action(const Glib::ustring& detailed_action_name) const -> std::vector<Glib::ustring>;


  /** Returns the list of actions (possibly empty) that `accel` maps to.
   *
   * Each item in the list is a detailed action name in the usual form.
   *
   * This might be useful to discover if an accel already exists in
   * order to prevent installation of a conflicting accelerator (from
   * an accelerator editor or a plugin system, for example). Note that
   * having more than one action per accelerator may not be a bad thing
   * and might make sense in cases where the actions never appear in the
   * same context.
   *
   * In case there are no actions for a given accelerator, an empty array
   * is returned. <tt>nullptr</tt> is never returned.
   *
   * It is a programmer error to pass an invalid accelerator string.
   *
   * If you are unsure, check it with gtk_accelerator_parse() first.
   *
   * @param accel An accelerator that can be parsed by gtk_accelerator_parse().
   * @return A <tt>nullptr</tt>-terminated array of actions for `accel`.
   */
  auto get_actions_for_accel(const Glib::ustring& accel) const -> std::vector<Glib::ustring>;


  /** Sets zero or more keyboard accelerators that will trigger the
   * given action.
   *
   * The first item in `accels` will be the primary accelerator, which may be
   * displayed in the UI.
   *
   * To remove all accelerators for an action, use an empty, zero-terminated
   * array for `accels`.
   *
   * For the `detailed_action_name`, see `Glib::action_parse_detailed_name()` and
   * `Glib::action_print_detailed_name()`.
   *
   * @param detailed_action_name A detailed action name, specifying an action
   * and target to associate accelerators with.
   * @param accels A list of accelerators in the format
   * understood by gtk_accelerator_parse().
   */
  void set_accels_for_action(const Glib::ustring& detailed_action_name, const std::vector<Glib::ustring>& accels);

  /** Sets a keyboard accelerator that will trigger the
   * given action. It will be the primary
   * accelerator, which may be displayed in the UI.
   *
   * See unset_accels_for_action().
   *
   * @param detailed_action_name A detailed action name, specifying an action
   * and target to associate accelerators with.
   * @param accel An accelerator in the format understood by gtk_accelerator_parse().
   *
   * @newin{3,12}
   */
  void set_accel_for_action(const Glib::ustring& detailed_action_name, const Glib::ustring& accel);

  /** Unsets a keyboard accelerator that will trigger the
   * given action. See set_accels_for_action() and set_accel_for_action().
   *
   * @param detailed_action_name A detailed action name, specifying an action
   * and target to associate accelerators with.
   *
   * @newin{3,12}
   */
  void unset_accels_for_action(const Glib::ustring& detailed_action_name);


  /** Gets a menu from automatically loaded resources.
   *
   * See [the section on Automatic resources](class.Application.html#automatic-resources)
   * for more information.
   *
   * @param id The id of the menu to look up.
   * @return Gets the menu with the
   * given id from the automatically loaded resources.
   */
  auto get_menu_by_id(const Glib::ustring& id) -> Glib::RefPtr<Gio::Menu>;

  /** Gets a menu from automatically loaded resources.
   *
   * See [the section on Automatic resources](class.Application.html#automatic-resources)
   * for more information.
   *
   * @param id The id of the menu to look up.
   * @return Gets the menu with the
   * given id from the automatically loaded resources.
   */
  auto get_menu_by_id(const Glib::ustring& id) const -> Glib::RefPtr<const Gio::Menu>;

  /** The `Gio::MenuModel` to be used for the application's menu bar.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menubar() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> > ;

/** The `Gio::MenuModel` to be used for the application's menu bar.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_menubar() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >;

  /** Set this property to <tt>true</tt> to register with the session manager.
   *
   * This will make GTK track the session state (such as the
   * property_screensaver_active() property).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_register_session() -> Glib::PropertyProxy< bool > ;

/** Set this property to <tt>true</tt> to register with the session manager.
   *
   * This will make GTK track the session state (such as the
   * property_screensaver_active() property).
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_register_session() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** This property is <tt>true</tt> if GTK believes that the screensaver is
   * currently active.
   *
   * GTK only tracks session state (including this) when
   * property_register_session() is set to <tt>true</tt>.
   *
   * Tracking the screensaver state is currently only supported on
   * Linux.
   *
   * @newin{3,94}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_screensaver_active() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The currently focused window of the application.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_active_window() const -> Glib::PropertyProxy_ReadOnly< Window* >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%window_added(Window* window)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a Gtk::Window is added to `application` through
   * Gtk::Application::add_window().
   *
   * @param window The newly-added Gtk::Window.
   */

  auto signal_window_added() -> Glib::SignalProxy<void(Window*)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%window_removed(Window* window)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a Gtk::Window is removed from `application`.
   *
   * This can happen as a side-effect of the window being destroyed
   * or explicitly through Gtk::Application::remove_window().
   *
   * @param window The Gtk::Window that is being removed.
   */

  auto signal_window_removed() -> Glib::SignalProxy<void(Window*)>;

  // no_default_handler because the wrapped C signal has no default handler.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%query_end()</tt>
   *
   * Flags: Run First
   *
   * Emitted when the session manager is about to end the session.
   *
   * This signal is only emitted if property_register_session()
   * is <tt>true</tt>. Applications can connect to this signal and call
   * Gtk::Application::inhibit() with `Gtk::Application::InhibitFlags::LOGOUT`
   * to delay the end of the session until state has been saved.
   */

  auto signal_query_end() -> Glib::SignalProxy<void()>;


private:
  /** This is just a way to call Glib::init() before calling a Glib::Object ctor,
   * so that glibmm's GQuarks are created before they are used.
   */
  auto custom_class_init() -> const Glib::Class&;

  Window* m_run_window = nullptr;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_window_added().
  virtual void on_window_added(Window* window);
  /// This is a default handler for the signal signal_window_removed().
  virtual void on_window_removed(Window* window);


};

template <typename T_Window, typename... T_Args>
auto Application::make_window_and_run(int argc, char** argv, T_Args&&... args) -> int
{
  static_assert(std::is_base_of<Window, T_Window>::value);

  signal_activate().connect([this, &args...] () {
    if (!m_run_window)
    {
      // The created window is managed. Thus, the C++ wrapper is deleted
      // by Gtk::Object::destroy_notify_() when the C window is destroyed.
      // https://gitlab.gnome.org/GNOME/gtkmm/-/issues/114
      auto window = make_managed<T_Window>(std::forward<T_Args>(args)...);
      m_run_window = window;
      add_window(*window);
      window->present();
    } else {
      m_run_window->present();
    }
  });

  signal_window_removed().connect([this] (Window* window) {
    if (window == m_run_window)
    {
      if (window)
        window->destroy();
      m_run_window = nullptr;
    }
  });

  return Gio::Application::run(argc, argv);
}

} // namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  { return static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  { return static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(Application::InhibitFlags lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags
  { return static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(Application::InhibitFlags flags) -> Application::InhibitFlags
  { return static_cast<Application::InhibitFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  { return (lhs = static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  { return (lhs = static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(Application::InhibitFlags& lhs, Application::InhibitFlags rhs) -> Application::InhibitFlags&
  { return (lhs = static_cast<Application::InhibitFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::Application::InhibitFlags> : public Glib::Value_Flags<Gtk::Application::InhibitFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Application
   */
  GTKMM_API
  auto wrap(GtkApplication* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Application>;
}


#endif /* _GTKMM_APPLICATION_H */

