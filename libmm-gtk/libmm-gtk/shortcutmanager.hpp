
#ifndef _GTKMM_SHORTCUTMANAGER_H
#define _GTKMM_SHORTCUTMANAGER_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <mm/glib/interface.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkShortcutManagerInterface GtkShortcutManagerInterface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutManager = struct _GtkShortcutManager;
using GtkShortcutManagerClass = struct _GtkShortcutManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutManager_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API ShortcutController;

/** Interface for managing shortcuts.
 *
 * The %Gtk::ShortcutManager interface is used to implement
 * shortcut scopes.
 *
 * This is important for Gtk::Native widgets that have their own surface,
 * since the event controllers that are used to implement managed and
 * global scopes are limited to the same native.
 *
 * Examples of widgets implementing %Gtk::ShortcutManager are Gtk::Window
 * and Gtk::Popover.
 *
 * @newin{3,98}
 */

class GTKMM_API ShortcutManager : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ShortcutManager;
  using CppClassType = ShortcutManager_Class;
  using BaseObjectType = GtkShortcutManager;
  using BaseClassType = GtkShortcutManagerInterface;

  // noncopyable
  ShortcutManager(const ShortcutManager&) = delete;
  auto operator=(const ShortcutManager&) -> ShortcutManager& = delete;

private:
  friend class ShortcutManager_Class;
  static CppClassType shortcutmanager_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ShortcutManager();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ShortcutManager(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ShortcutManager(GtkShortcutManager* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ShortcutManager(ShortcutManager&& src) noexcept;
  auto operator=(ShortcutManager&& src) noexcept -> ShortcutManager&;

  ~ShortcutManager() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutManager*       { return reinterpret_cast<GtkShortcutManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutManager* { return reinterpret_cast<GtkShortcutManager*>(gobject_); }

private:


public:

protected:


    virtual void add_controller_vfunc(const Glib::RefPtr<ShortcutController>& controller);

    virtual void remove_controller_vfunc(const Glib::RefPtr<ShortcutController>& controller);


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
   * @relates Gtk::ShortcutManager
   */
  GTKMM_API
  auto wrap(GtkShortcutManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutManager>;

} // namespace Glib


#endif /* _GTKMM_SHORTCUTMANAGER_H */

