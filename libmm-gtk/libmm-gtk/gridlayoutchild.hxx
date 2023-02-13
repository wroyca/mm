
#ifndef _GTKMM_GRIDLAYOUTCHILD_H
#define _GTKMM_GRIDLAYOUTCHILD_H


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

#include <libmm-gtk/layoutchild.hpp>
#include <gtk/gtk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GridLayoutChild_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Layout properties for children of Gtk::GridLayout.
 *
 * %Gtk::GridLayoutChild instances are created by Gtk::GridLayout.
 * To create or get a %Gtk::GridLayoutChild instance, call Gtk::LayoutManager::get_layout_child()
 * from a Gtk::GridLayout instance.
 * @code
 * Glib::RefPtr<Gtk::LayoutChild> layout_child =
 *   grid_layout->get_layout_child(child);
 * Glib::RefPtr<Gtk::GridLayoutChild> grid_layout_child =
 *   std::dynamic_pointer_cast<Gtk::GridLayoutChild>(layout_child);
 * if (grid_layout_child)
 *   // Do something with grid_layout_child
 * @endcode
 *
 * @newin{3,96}
 */

class GTKMM_API GridLayoutChild : public LayoutChild
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = GridLayoutChild;
  using CppClassType = GridLayoutChild_Class;
  using BaseObjectType = GtkGridLayoutChild;
  using BaseClassType = GtkGridLayoutChildClass;

  // noncopyable
  GridLayoutChild(const GridLayoutChild&) = delete;
  auto operator=(const GridLayoutChild&) -> GridLayoutChild& = delete;

private:  friend class GridLayoutChild_Class;
  static CppClassType gridlayoutchild_class_;

protected:
  explicit GridLayoutChild(const Glib::ConstructParams& construct_params);
  explicit GridLayoutChild(GtkGridLayoutChild* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  GridLayoutChild(GridLayoutChild&& src) noexcept;
  auto operator=(GridLayoutChild&& src) noexcept -> GridLayoutChild&;

  ~GridLayoutChild() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkGridLayoutChild*       { return reinterpret_cast<GtkGridLayoutChild*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkGridLayoutChild* { return reinterpret_cast<GtkGridLayoutChild*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkGridLayoutChild*;

private:


protected:
  /** Default constructor.
   *
   * There is no create() method that corresponds to this constructor.
   * To create or get a %Gtk::GridLayoutChild instance, call Gtk::LayoutManager::get_layout_child()
   * from a Gtk::GridLayout instance.
   */
  GridLayoutChild();

public:
  // No create() method. Use Gtk::LayoutManager::get_layout_child().


  /** Sets the row to place @a child in.
   *
   * @param row The row for @a child.
   */
  void set_row(int row);

  /** Retrieves the row number to which @a child attaches its top side.
   *
   * @return The row number.
   */
  auto get_row() const -> int;

  /** Sets the column number to attach the left side of @a child.
   *
   * @param column The attach point for @a child.
   */
  void set_column(int column);

  /** Retrieves the column number to which @a child attaches its left side.
   *
   * @return The column number.
   */
  auto get_column() const -> int;

  /** Sets the number of columns @a child spans to.
   *
   * @param span The span of @a child.
   */
  void set_column_span(int span);

  /** Retrieves the number of columns that @a child spans to.
   *
   * @return The number of columns.
   */
  auto get_column_span() const -> int;

  /** Sets the number of rows @a child spans to.
   *
   * @param span The span of @a child.
   */
  void set_row_span(int span);

  /** Retrieves the number of rows that @a child spans to.
   *
   * @return The number of row.
   */
  auto get_row_span() const -> int;

  /** The column to place the child in.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column() -> Glib::PropertyProxy< int > ;

/** The column to place the child in.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The row to place the child in.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row() -> Glib::PropertyProxy< int > ;

/** The row to place the child in.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The number of columns the child spans to.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_span() -> Glib::PropertyProxy< int > ;

/** The number of columns the child spans to.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_column_span() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The number of rows the child spans to.
   *
   * Default value: 1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_span() -> Glib::PropertyProxy< int > ;

/** The number of rows the child spans to.
   *
   * Default value: 1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_row_span() const -> Glib::PropertyProxy_ReadOnly< int >;


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
   * @relates Gtk::GridLayoutChild
   */
  GTKMM_API
  auto wrap(GtkGridLayoutChild* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GridLayoutChild>;
}


#endif /* _GTKMM_GRIDLAYOUTCHILD_H */

