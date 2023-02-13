
#ifndef _GIOMM_DESKTOPAPPINFO_H
#define _GIOMM_DESKTOPAPPINFO_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/glib/object.hpp>
#include <mm/gio/appinfo.hpp>


// This file is not used on Windows and Mac OS Cocoa
//This is available only #if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA).
//Otherwise this source file will not be compiled,
//and no class defined in it will be registered by wrap_init().


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDesktopAppInfo = struct _GDesktopAppInfo;
using GDesktopAppInfoClass = struct _GDesktopAppInfoClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API DesktopAppInfo_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

class GLIBMM_API KeyFile;

}

namespace Gio
{

/**
 * DesktopAppInfo is an implementation of AppInfo based on desktop files.
 *
 * @newin{2,16}
 */

class GIOMM_API DesktopAppInfo
: public Glib::Object,
  public AppInfo
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DesktopAppInfo;
  using CppClassType = DesktopAppInfo_Class;
  using BaseObjectType = GDesktopAppInfo;
  using BaseClassType = GDesktopAppInfoClass;

  // noncopyable
  DesktopAppInfo(const DesktopAppInfo&) = delete;
  auto operator=(const DesktopAppInfo&) -> DesktopAppInfo& = delete;

private:  friend class DesktopAppInfo_Class;
  static CppClassType desktopappinfo_class_;

protected:
  explicit DesktopAppInfo(const Glib::ConstructParams& construct_params);
  explicit DesktopAppInfo(GDesktopAppInfo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DesktopAppInfo(DesktopAppInfo&& src) noexcept;
  auto operator=(DesktopAppInfo&& src) noexcept -> DesktopAppInfo&;

  ~DesktopAppInfo() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GDesktopAppInfo*       { return reinterpret_cast<GDesktopAppInfo*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GDesktopAppInfo* { return reinterpret_cast<GDesktopAppInfo*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GDesktopAppInfo*;

private:


public:
  // We can't use _WRAP_CTOR() and _WRAP_CREATE() because the C functions do more
  // than just call g_object_new(). There's quite a bit of error-handling to do.

  /** Creates a new DesktopAppInfo based on a desktop file id.
   *
   * A desktop file id is the basename of the desktop file, including the
   * .desktop extension. GIO is looking for a desktop file with this name
   * in the `applications` subdirectories of the XDG
   * data directories (i.e. the directories specified in the `XDG_DATA_HOME`
   * and `XDG_DATA_DIRS` environment variables). GIO also supports the
   * prefix-to-subdirectory mapping that is described in the
   * [Menu Spec](http://standards.freedesktop.org/menu-spec/latest/)
   * (i.e. a desktop id of kde-foo.desktop will match
   * `/usr/share/applications/kde/foo.desktop`).
   *
   * @param desktop_id The desktop file id.
   * @return A new DesktopAppInfo, or <tt>nullptr</tt> if no desktop
   * file with that id exists.
   */
  static auto create(const std::string& desktop_id) -> Glib::RefPtr<DesktopAppInfo>;

  /** Creates a new DesktopAppInfo.
   *
   * @newin{2,18}
   *
   * @param key_file An opened KeyFile.
   * @return A new DesktopAppInfo or <tt>nullptr</tt> on error.
   */
  static auto create_from_keyfile(const Glib::RefPtr<Glib::KeyFile>& key_file) -> Glib::RefPtr<DesktopAppInfo>;

  /** Creates a new DesktopAppInfo.
   *
   * @param filename The path of a desktop file, in the GLib
   * filename encoding.
   * @return A new DesktopAppInfo or <tt>nullptr</tt> on error.
   */
  static auto create_from_filename(const std::string& filename) -> Glib::RefPtr<DesktopAppInfo>;


  /** When @a info was created from a known filename, return it.  In some
   * situations such as the DesktopAppInfo returned from
   * g_desktop_app_info_new_from_keyfile(), this function will return <tt>nullptr</tt>.
   *
   * @newin{2,24}
   *
   * @return The full path to the file for @a info,
   * or <tt>nullptr</tt> if not known.
   */
  auto get_filename() const -> std::string;

  /** A desktop file is hidden if the Hidden key in it is
   * set to True.
   *
   * @return <tt>true</tt> if hidden, <tt>false</tt> otherwise.
   */
  auto is_hidden() const -> bool;


  /** Gets the keywords from the desktop file.
   *
   * @newin{2,32}
   *
   * @return The value of the Keywords key.
   */
  auto get_keywords() const -> std::vector<Glib::ustring>;


  /** Retrieves the StartupWMClass field from @a info. This represents the
   * WM_CLASS property of the main window of the application, if launched
   * through @a info.
   *
   * @newin{2,34}
   *
   * @return The startup WM class, or <tt>nullptr</tt> if none is set
   * in the desktop file.
   */
  auto get_startup_wm_class() const -> std::string;

  /** Gets the value of the NoDisplay key, which helps determine if the
   * application info should be shown in menus. See
   * G_KEY_FILE_DESKTOP_KEY_NO_DISPLAY and g_app_info_should_show().
   *
   * @newin{2,30}
   *
   * @return The value of the NoDisplay key.
   */
  auto get_nodisplay() const -> bool;

  /** Checks if the application info should be shown in menus that list available
   * applications for a specific name of the desktop, based on the
   * `OnlyShowIn` and `NotShowIn` keys.
   *
   *  @a desktop_env should typically be given as <tt>nullptr</tt>, in which case the
   * `XDG_CURRENT_DESKTOP` environment variable is consulted.  If you want
   * to override the default mechanism then you may specify @a desktop_env,
   * but this is not recommended.
   *
   * Note that g_app_info_should_show() for @a info will include this check (with
   * <tt>nullptr</tt> for @a desktop_env) as well as additional checks.
   *
   * @newin{2,30}
   *
   * @param desktop_env A string specifying a desktop name.
   * @return <tt>true</tt> if the @a info should be shown in @a desktop_env according to the
   * `OnlyShowIn` and `NotShowIn` keys, <tt>false</tt>
   * otherwise.
   */
  auto get_show_in(const std::string& desktop_env) const -> bool;

  /** Gets the generic name from the desktop file.
   *
   * @return The value of the GenericName key.
   */
  auto get_generic_name() const -> std::string;

  /** Gets the categories from the desktop file.
   *
   * @return The unparsed Categories key from the desktop file;
   * i.e. no attempt is made to split it by ';' or validate it.
   */
  auto get_categories() const -> std::string;


  /** Returns whether @a key exists in the "Desktop Entry" group
   * of the keyfile backing @a info.
   *
   * @newin{2,36}
   *
   * @param key The key to look up.
   * @return <tt>true</tt> if the @a key exists.
   */
  auto has_key(const Glib::ustring& key) const -> bool;

  /** Looks up a string value in the keyfile backing @a info.
   *
   * The @a key is looked up in the "Desktop Entry" group.
   *
   * @newin{2,36}
   *
   * @param key The key to look up.
   * @return A newly allocated string, or <tt>nullptr</tt> if the key
   * is not found.
   */
  auto get_string(const Glib::ustring& key) -> Glib::ustring;

  /** Looks up a localized string value in the keyfile backing @a info
   * translated to the current locale.
   *
   * The @a key is looked up in the "Desktop Entry" group.
   *
   * @newin{2,56}
   *
   * @param key The key to look up.
   * @return A newly allocated string, or <tt>nullptr</tt> if the key
   * is not found.
   */
  auto get_locale_string(const Glib::ustring& key) -> Glib::ustring;

  /** Looks up a boolean value in the keyfile backing @a info.
   *
   * The @a key is looked up in the "Desktop Entry" group.
   *
   * @newin{2,36}
   *
   * @param key The key to look up.
   * @return The boolean value, or <tt>false</tt> if the key
   * is not found.
   */
  auto get_boolean(const Glib::ustring& key) const -> bool;


  /** Returns the list of "additional application actions" supported on the
   * desktop file, as per the desktop file specification.
   *
   * As per the specification, this is the list of actions that are
   * explicitly listed in the "Actions" key of the [Desktop Entry] group.
   *
   * @newin{2,38}
   *
   * @return A list of strings, always non-<tt>nullptr</tt>.
   */
  auto list_actions() const -> std::vector<Glib::ustring>;


  /** Activates the named application action.
   *
   * You may only call this function on action names that were
   * returned from g_desktop_app_info_list_actions().
   *
   * Note that if the main entry of the desktop file indicates that the
   * application supports startup notification, and @a launch_context is
   * non-<tt>nullptr</tt>, then startup notification will be used when activating the
   * action (and as such, invocation of the action on the receiving side
   * must signal the end of startup notification when it is completed).
   * This is the expected behaviour of applications declaring additional
   * actions, as per the desktop file specification.
   *
   * As with g_app_info_launch() there is no way to detect failures that
   * occur while using this function.
   *
   * @newin{2,38}
   *
   * @param action_name The name of the action as from
   * g_desktop_app_info_list_actions().
   * @param launch_context A AppLaunchContext.
   */
  void launch_action(const Glib::ustring& action_name, const Glib::RefPtr<AppLaunchContext>& launch_context);

  /// A launch_action() convenience overload.
  void launch_action(const Glib::ustring& action_name);


  /** Gets the user-visible display name of the "additional application
   * action" specified by @a action_name.
   *
   * This corresponds to the "Name" key within the keyfile group for the
   * action.
   *
   * @newin{2,38}
   *
   * @param action_name The name of the action as from
   * g_desktop_app_info_list_actions().
   * @return The locale-specific action name.
   */
  auto get_action_name(const Glib::ustring& action_name) const -> Glib::ustring;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DesktopAppInfo
   */
  GIOMM_API
  auto wrap(GDesktopAppInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DesktopAppInfo>;
}


#endif /* _GIOMM_DESKTOPAPPINFO_H */

