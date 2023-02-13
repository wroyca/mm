
#ifndef _GTKMM_LAYOUTCHILD_H
#define _GTKMM_LAYOUTCHILD_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2019 The gtkmm Development Team
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


#include <libmm-glib/object.hpp>
#include <libmm-glib/refptr.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLayoutChild = struct _GtkLayoutChild;
using GtkLayoutChildClass = struct _GtkLayoutChildClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API LayoutChild_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API LayoutManager;
class GTKMM_API Widget;

/** An object containing layout properties.
 *
 * %Gtk::LayoutChild is the base class for objects that are meant to hold
 * layout properties. If a Gtk::LayoutManager has per-child properties,
 * like their packing type, or the horizontal and vertical span, or the
 * icon name, then the layout manager should use a %Gtk::LayoutChild
 * implementation to store those properties.
 *
 * A %Gtk::LayoutChild instance is only ever valid while a widget is part
 * of a layout.
 *
 * @newin{3,96}
 */

class GTKMM_API LayoutChild : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = LayoutChild;
  using CppClassType = LayoutChild_Class;
  using BaseObjectType = GtkLayoutChild;
  using BaseClassType = GtkLayoutChildClass;

  // noncopyable
  LayoutChild(const LayoutChild&) = delete;
  auto operator=(const LayoutChild&) -> LayoutChild& = delete;

private:  friend class LayoutChild_Class;
  static CppClassType layoutchild_class_;

protected:
  explicit LayoutChild(const Glib::ConstructParams& construct_params);
  explicit LayoutChild(GtkLayoutChild* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  LayoutChild(LayoutChild&& src) noexcept;
  auto operator=(LayoutChild&& src) noexcept -> LayoutChild&;

  ~LayoutChild() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkLayoutChild*       { return reinterpret_cast<GtkLayoutChild*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkLayoutChild* { return reinterpret_cast<GtkLayoutChild*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkLayoutChild*;

private:


protected:
  /** There is no create() method that corresponds to this constructor,
   * because only derived classes shall be created.
   */
  LayoutChild();

public:
  // No create() because only derived classes shall be instantiated.


  /** Retrieves the `Gtk::LayoutManager` instance that created the
   * given @a layout_child.
   *
   * @return A `Gtk::LayoutManager`.
   */
  auto get_layout_manager() -> Glib::RefPtr<LayoutManager>;

  /** Retrieves the `Gtk::LayoutManager` instance that created the
   * given @a layout_child.
   *
   * @return A `Gtk::LayoutManager`.
   */
  auto get_layout_manager() const -> Glib::RefPtr<const LayoutManager>;


  /** Retrieves the `Gtk::Widget` associated to the given @a layout_child.
   *
   * @return A `Gtk::Widget`.
   */
  auto get_child_widget() -> Widget*;

  /** Retrieves the `Gtk::Widget` associated to the given @a layout_child.
   *
   * @return A `Gtk::Widget`.
   */
  auto get_child_widget() const -> const Widget*;

  /** The layout manager that created the `Gtk::LayoutChild` instance.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_layout_manager() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<LayoutManager> >;


  /** The widget that is associated to the `Gtk::LayoutChild` instance.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_child_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


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
   * @relates Gtk::LayoutChild
   */
  GTKMM_API
  auto wrap(GtkLayoutChild* object, bool take_copy = false) -> Glib::RefPtr<Gtk::LayoutChild>;
}


#endif /* _GTKMM_LAYOUTCHILD_H */

