
#ifndef _GDKMM_APPLAUNCHCONTEXT_H
#define _GDKMM_APPLAUNCHCONTEXT_H

#include <libmm-gdk/mm-gdkconfig.hxx>


#include <libmm-glib/ustring.hxx>
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


#include <libmm-gio/appinfo.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkAppLaunchContext = struct _GdkAppLaunchContext;
using GdkAppLaunchContextClass = struct _GdkAppLaunchContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API AppLaunchContext_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{
class GDKMM_API Display;

/** This is an implementation of Gio::AppLaunchContext that
 * handles launching an application in a graphical context. It provides
 * startup notification and allows to launch applications on a specific
 * screen or workspace.
 *
 * @newin{3,4}
 */

class GDKMM_API AppLaunchContext : public Gio::AppLaunchContext
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AppLaunchContext;
  using CppClassType = AppLaunchContext_Class;
  using BaseObjectType = GdkAppLaunchContext;
  using BaseClassType = GdkAppLaunchContextClass;

  // noncopyable
  AppLaunchContext(const AppLaunchContext&) = delete;
  auto operator=(const AppLaunchContext&) -> AppLaunchContext& = delete;

private:  friend class AppLaunchContext_Class;
  static CppClassType applaunchcontext_class_;

protected:
  explicit AppLaunchContext(const Glib::ConstructParams& construct_params);
  explicit AppLaunchContext(GdkAppLaunchContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AppLaunchContext(AppLaunchContext&& src) noexcept;
  auto operator=(AppLaunchContext&& src) noexcept -> AppLaunchContext&;

  ~AppLaunchContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkAppLaunchContext*       { return reinterpret_cast<GdkAppLaunchContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkAppLaunchContext* { return reinterpret_cast<GdkAppLaunchContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkAppLaunchContext*;

private:


protected:
  AppLaunchContext();

public:

  static auto create() -> Glib::RefPtr<AppLaunchContext>;


  /** Gets the `Gdk::Display` that @a context is for.
   *
   * @return The display of @a context.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Gets the `Gdk::Display` that @a context is for.
   *
   * @return The display of @a context.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;

  /** Sets the workspace on which applications will be launched.
   *
   * This only works when running under a window manager that
   * supports multiple workspaces, as described in the
   * [Extended Window Manager Hints](http://www.freedesktop.org/Standards/wm-spec).
   * Specifically this sets the `_NET_WM_DESKTOP` property described
   * in that spec.
   *
   * This only works when using the X11 backend.
   *
   * When the workspace is not specified or @a desktop is set to -1,
   * it is up to the window manager to pick one, typically it will
   * be the current workspace.
   *
   * @param desktop The number of a workspace, or -1.
   */
  void set_desktop(int desktop);

  /** Sets the timestamp of @a context.
   *
   * The timestamp should ideally be taken from the event that
   * triggered the launch.
   *
   * %Window managers can use this information to avoid moving the
   * focus to the newly launched application when the user is busy
   * typing in another window. This is also known as 'focus stealing
   * prevention'.
   *
   * @param timestamp A timestamp.
   */
  void set_timestamp(guint32 timestamp);

  /** Sets the icon for applications that are launched with this
   * context.
   *
   * Window Managers can use this information when displaying startup
   * notification.
   *
   * See also set_icon_name().
   *
   * @param icon A `Gio::Icon`.
   */
  void set_icon(const Glib::RefPtr<Gio::Icon>& icon);

  /** Sets the icon for applications that are launched with this context.
   *
   * The @a icon_name will be interpreted in the same way as the Icon field
   * in desktop files. See also set_icon().
   *
   * If both @a icon and @a icon_name are set, the @a icon_name takes priority.
   * If neither @a icon or @a icon_name is set, the icon is taken from either
   * the file that is passed to launched application or from the `Gio::AppInfo`
   * for the launched application itself.
   *
   * @param icon_name An icon name.
   */
  void set_icon_name(const Glib::ustring& icon_name);

  /** The display that the `Gdk::AppLaunchContext` is on.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::AppLaunchContext
   */
  GDKMM_API
  auto wrap(GdkAppLaunchContext* object, bool take_copy = false) -> Glib::RefPtr<Gdk::AppLaunchContext>;
}


#endif /* _GDKMM_APPLAUNCHCONTEXT_H */
