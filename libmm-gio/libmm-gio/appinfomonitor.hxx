
#ifndef _GIOMM_APPINFOMONITOR_H
#define _GIOMM_APPINFOMONITOR_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2022 The giomm Development Team
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


#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAppInfoMonitor = struct _GAppInfoMonitor;
using GAppInfoMonitorClass = struct _GAppInfoMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API AppInfoMonitor_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Monitor application information for changes.
 *
 * %Gio::AppInfoMonitor is a very simple object used for monitoring the app
 * info database for changes (ie: newly installed or removed
 * applications).
 *
 * Call get() to get a %Gio::AppInfoMonitor and connect to signal_changed().
 *
 * In the usual case, applications should try to make note of the change
 * (doing things like invalidating caches) but not act on it. In
 * particular, applications should avoid making calls to Gio::AppInfo APIs
 * in response to the change signal, deferring these until the time that
 * the data is actually required. The exception to this case is when
 * application information is actually being displayed on the screen
 * (eg: during a search or when the list of all applications is shown).
 * The reason for this is that changes to the list of installed
 * applications often come in groups (like during system updates) and
 * rescanning the list on every change is pointless and expensive.
 *
 * @newin{2,72}
 */

class GIOMM_API AppInfoMonitor : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AppInfoMonitor;
  using CppClassType = AppInfoMonitor_Class;
  using BaseObjectType = GAppInfoMonitor;
  using BaseClassType = GAppInfoMonitorClass;

  // noncopyable
  AppInfoMonitor(const AppInfoMonitor&) = delete;
  auto operator=(const AppInfoMonitor&) -> AppInfoMonitor& = delete;

private:  friend class AppInfoMonitor_Class;
  static CppClassType appinfomonitor_class_;

protected:
  explicit AppInfoMonitor(const Glib::ConstructParams& construct_params);
  explicit AppInfoMonitor(GAppInfoMonitor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AppInfoMonitor(AppInfoMonitor&& src) noexcept;
  auto operator=(AppInfoMonitor&& src) noexcept -> AppInfoMonitor&;

  ~AppInfoMonitor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GAppInfoMonitor*       { return reinterpret_cast<GAppInfoMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GAppInfoMonitor* { return reinterpret_cast<GAppInfoMonitor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GAppInfoMonitor*;

private:


public:

  /** Gets the %AppInfoMonitor for the current thread-default main context.
   *
   * The %AppInfoMonitor will emit a "changed" signal in the
   * thread-default main context whenever the list of installed
   * applications (as reported by Gio::AppInfo::get_all()) may have changed.
   *
   * You must only drop the last reference on the return value from under
   * the same main context as you created it.
   *
   * @newin{2,72}
   *
   * @return A reference to a %Gio::AppInfoMonitor.
   */
  static auto get() -> Glib::RefPtr<AppInfoMonitor>;

  // no_default_handler because the wrapped C signal has no default handler.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run First
   *
   * Signal emitted when the app info database for changes (ie: newly installed
   * or removed applications).
   *
   * @newin{2,72}
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


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
   * @relates Gio::AppInfoMonitor
   */
  GIOMM_API
  auto wrap(GAppInfoMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::AppInfoMonitor>;
}


#endif /* _GIOMM_APPINFOMONITOR_H */

