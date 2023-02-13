
#ifndef _GTKMM_STACKSWITCHER_H
#define _GTKMM_STACKSWITCHER_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2013 The gtkmm Development Team
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

#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/stack.hpp>
//TODO: When we can break ABI: #include <libmm-gtk/orientable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackSwitcher = struct _GtkStackSwitcher;
using GtkStackSwitcherClass = struct _GtkStackSwitcherClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StackSwitcher_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** A controller for a %Gtk::Stack.
 *
 * It shows a row of buttons to switch between the various pages of
 * the associated stack widget.
 *
 * All the content for the buttons comes from the child properties of
 * the Gtk::Stack.
 *
 * It is possible to associate multiple %StackSwitcher widgets with
 * the same stack widget.
 *
 * @ingroup Widgets
 * @newin{3,10}
 */

class GTKMM_API StackSwitcher : public Widget //TODO: When we can break ABI: public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef StackSwitcher CppObjectType;
  typedef StackSwitcher_Class CppClassType;
  typedef GtkStackSwitcher BaseObjectType;
  typedef GtkStackSwitcherClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  StackSwitcher(StackSwitcher&& src) noexcept;
  auto operator=(StackSwitcher&& src) noexcept -> StackSwitcher&;

  // noncopyable
  StackSwitcher(const StackSwitcher&) = delete;
  auto operator=(const StackSwitcher&) -> StackSwitcher& = delete;

  ~StackSwitcher() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class StackSwitcher_Class;
  static CppClassType stackswitcher_class_;

protected:
  explicit StackSwitcher(const Glib::ConstructParams& construct_params);
  explicit StackSwitcher(GtkStackSwitcher* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkStackSwitcher*       { return reinterpret_cast<GtkStackSwitcher*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStackSwitcher* { return reinterpret_cast<GtkStackSwitcher*>(gobject_); }

private:

  //TODO: When we can break ABI: _IMPLEMENTS_INTERFACE(Orientable)
public:
  StackSwitcher();


  /** Sets the stack to control.
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
   * @return The stack.
   */
  auto get_stack() -> Stack*;

  /** Retrieves the stack.
   *
   * @return The stack.
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

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::StackSwitcher
   */
  GTKMM_API
  auto wrap(GtkStackSwitcher* object, bool take_copy = false) -> Gtk::StackSwitcher*;
} //namespace Glib


#endif /* _GTKMM_STACKSWITCHER_H */

