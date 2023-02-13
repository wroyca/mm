
#ifndef _GTKMM_STACKSIDEBAR_H
#define _GTKMM_STACKSIDEBAR_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The gtkmm Development Team
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

#include <mm/gtk/widget.hpp>
#include <mm/gtk/stack.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackSidebar = struct _GtkStackSidebar;
using GtkStackSidebarClass = struct _GtkStackSidebarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StackSidebar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Stack;

/** Sidebar widget that shows the pages of a Stack.
 *
 * A %StackSidebar enables you to quickly and easily provide a
 * consistent "sidebar" object for your user interface.
 *
 * In order to use a %StackSidebar, you simply use a Stack to
 * organize your UI flow, and add the sidebar to your sidebar area. You
 * can use set_stack() to connect the %StackSidebar to the Stack.
 *
 * @ingroup Widgets
 * @newin{3,16}
 */

class GTKMM_API StackSidebar : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef StackSidebar CppObjectType;
  typedef StackSidebar_Class CppClassType;
  typedef GtkStackSidebar BaseObjectType;
  typedef GtkStackSidebarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  StackSidebar(StackSidebar&& src) noexcept;
  auto operator=(StackSidebar&& src) noexcept -> StackSidebar&;

  // noncopyable
  StackSidebar(const StackSidebar&) = delete;
  auto operator=(const StackSidebar&) -> StackSidebar& = delete;

  ~StackSidebar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class StackSidebar_Class;
  static CppClassType stacksidebar_class_;

protected:
  explicit StackSidebar(const Glib::ConstructParams& construct_params);
  explicit StackSidebar(GtkStackSidebar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkStackSidebar*       { return reinterpret_cast<GtkStackSidebar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStackSidebar* { return reinterpret_cast<GtkStackSidebar*>(gobject_); }

private:

public:
  StackSidebar();


  /** Set the `Gtk::Stack` associated with this `Gtk::StackSidebar`.
   *
   * The sidebar widget will automatically update according to
   * the order and items within the given `Gtk::Stack`.
   *
   * @param stack A `Gtk::Stack`.
   */
  void set_stack(Stack& stack);
  /** Unsets the associated Stack.
   * @see set_stack().
   * @newin{3,16}
   */
  void unset_stack();


  /** Retrieves the stack.
   *
   * @return The associated `Gtk::Stack` or
   * <tt>nullptr</tt> if none has been set explicitly.
   */
  auto get_stack() -> Stack*;

  /** Retrieves the stack.
   *
   * @return The associated `Gtk::Stack` or
   * <tt>nullptr</tt> if none has been set explicitly.
   */
  auto get_stack() const -> const Stack*;

  /** The stack.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stack() -> Glib::PropertyProxy< Stack* > ;

/** The stack.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_stack() const -> Glib::PropertyProxy_ReadOnly< Stack* >;


  // There are no signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::StackSidebar
   */
  GTKMM_API
  auto wrap(GtkStackSidebar* object, bool take_copy = false) -> Gtk::StackSidebar*;
} //namespace Glib


#endif /* _GTKMM_STACKSIDEBAR_H */

