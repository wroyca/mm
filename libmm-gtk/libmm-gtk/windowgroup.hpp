
#ifndef _GTKMM_WINDOWGROUP_H
#define _GTKMM_WINDOWGROUP_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2015 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWindowGroup = struct _GtkWindowGroup;
using GtkWindowGroupClass = struct _GtkWindowGroupClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API WindowGroup_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API Window;

/** Limit the effect of grabs
 */

class GTKMM_API WindowGroup : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = WindowGroup;
  using CppClassType = WindowGroup_Class;
  using BaseObjectType = GtkWindowGroup;
  using BaseClassType = GtkWindowGroupClass;

  // noncopyable
  WindowGroup(const WindowGroup&) = delete;
  auto operator=(const WindowGroup&) -> WindowGroup& = delete;

private:  friend class WindowGroup_Class;
  static CppClassType windowgroup_class_;

protected:
  explicit WindowGroup(const Glib::ConstructParams& construct_params);
  explicit WindowGroup(GtkWindowGroup* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  WindowGroup(WindowGroup&& src) noexcept;
  auto operator=(WindowGroup&& src) noexcept -> WindowGroup&;

  ~WindowGroup() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkWindowGroup*       { return reinterpret_cast<GtkWindowGroup*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkWindowGroup* { return reinterpret_cast<GtkWindowGroup*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkWindowGroup*;

private:


protected:
  WindowGroup();

public:

  static auto create() -> Glib::RefPtr<WindowGroup>;


  /** Adds a window to a `Gtk::WindowGroup`.
   *
   * @param window The `Gtk::Window` to add.
   */
  void add_window(Window& window);

  /** Removes a window from a `Gtk::WindowGroup`.
   *
   * @param window The `Gtk::Window` to remove.
   */
  void remove_window(Window& window);


  /** Returns a list of the `Gtk::Windows` that belong to @a window_group.
   *
   * @return A
   * newly-allocated list of windows inside the group.
   */
  auto list_windows() -> std::vector<Window*>;


  /** Returns a list of the `Gtk::Windows` that belong to @a window_group.
   *
   * @return A
   * newly-allocated list of windows inside the group.
   */
  auto list_windows() const -> std::vector<const Window*>;


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
   * @relates Gtk::WindowGroup
   */
  GTKMM_API
  auto wrap(GtkWindowGroup* object, bool take_copy = false) -> Glib::RefPtr<Gtk::WindowGroup>;
}


#endif /* _GTKMM_WINDOWGROUP_H */

