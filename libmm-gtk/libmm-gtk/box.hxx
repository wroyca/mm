
#ifndef _GTKMM_BOX_H
#define _GTKMM_BOX_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/orientable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBox = struct _GtkBox;
using GtkBoxClass = struct _GtkBoxClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Box_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container for packing widgets in a single row or column.
 *
 * The %Gtk::Box widget arranges child widgets into a single row or column,
 * depending upon the value of its Gtk::Orientable::property_orientation() property.
 * Within the other dimension, all children are allocated the same size. Of course,
 * Gtk::Widget::set_halign() and Gtk::Widget::set_valign() can be used on
 * the children to influence their allocation.
 *
 * Use repeated calls to append() to pack widgets into a %Gtk::Box
 * from start to end. Use remove() to remove widgets from the %Gtk::Box.
 * insert_child_after() can be used to add a child at a particular position.
 *
 * Use set_homogeneous() to specify whether or not all children
 * of the %Gtk::Box are forced to get the same amount of space.
 *
 * Use set_spacing() to determine how much space will be
 * minimally placed between all children in the %Gtk::Box. Note that
 * spacing is added between the children.
 *
 * Use reorder_child_after() and reorder_child_at_start() to move a child to
 * a different place in the box.
 */

class GTKMM_API Box
  : public Widget,
    public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Box CppObjectType;
  typedef Box_Class CppClassType;
  typedef GtkBox BaseObjectType;
  typedef GtkBoxClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Box(Box&& src) noexcept;
  auto operator=(Box&& src) noexcept -> Box&;

  // noncopyable
  Box(const Box&) = delete;
  auto operator=(const Box&) -> Box& = delete;

  ~Box() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Box_Class;
  static CppClassType box_class_;

protected:
  explicit Box(const Glib::ConstructParams& construct_params);
  explicit Box(GtkBox* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkBox*       { return reinterpret_cast<GtkBox*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBox* { return reinterpret_cast<GtkBox*>(gobject_); }

private:


public:

  //Note that we try to use the same default parameter value as the default property value.
  /** Creates a new box.
   * @param orientation The box's orientation.
   * @param spacing Determines the space in pixels between child widgets.
   */
    explicit Box(Orientation orientation =  Orientation::HORIZONTAL, int spacing =  0);


  /** Sets whether or not all children of @a box are given equal space
   * in the box.
   *
   * @param homogeneous A boolean value, <tt>true</tt> to create equal allotments,
   * <tt>false</tt> for variable allotments.
   */
  void set_homogeneous(bool homogeneous =  true);

  /** Returns whether the box is homogeneous (all children are the
   * same size).
   *
   * @return <tt>true</tt> if the box is homogeneous.
   */
  auto get_homogeneous() const -> bool;


  /** Sets the number of pixels to place between children of @a box.
   *
   * @param spacing The number of pixels to put between children.
   */
  void set_spacing(int spacing);

  /** Gets the value set by set_spacing().
   *
   * @return Spacing between children.
   */
  auto get_spacing() const -> int;


  /** Sets the baseline position of a box.
   *
   * This affects only horizontal boxes with at least one baseline
   * aligned child. If there is more vertical space available than
   * requested, and the baseline is not allocated by the parent then
   *  @a position is used to allocate the baseline with respect to the
   * extra space available.
   *
   * @param position A `Gtk::BaselinePosition`.
   */
  void set_baseline_position(BaselinePosition position);

  /** Gets the value set by set_baseline_position().
   *
   * @return The baseline position.
   */
  auto get_baseline_position() const -> BaselinePosition;


  /** Adds @a child as the last child to @a box.
   *
   * @param child The `Gtk::Widget` to append.
   */
  void append(Gtk::Widget& child);

  /** Adds @a child as the first child to @a box.
   *
   * @param child The `Gtk::Widget` to prepend.
   */
  void prepend(Gtk::Widget& child);

  /** Removes a child widget from @a box.
   *
   * The child must have been added before with
   * append(), prepend(), or
   * insert_child_after().
   *
   * @param child The child to remove.
   */
  void remove(Gtk::Widget& child);


  /** Inserts @a child in the position after @a sibling in the list of children.
   *
   * @param child The Gtk::Widget to insert.
   * @param sibling The sibling to move @a child after.
   */
  void insert_child_after(Widget& child, const Widget& sibling);

  /** Inserts @a child in the first position in the list of children.
   *
   * @param child The Gtk::Widget to insert.
   */
  void insert_child_at_start(Widget& child);


  /** Moves @a child to the position after @a sibling in the list of children.
   *
   * @param child The Gtk::Widget to move. Must be a child of the %Box.
   * @param sibling The sibling to move @a child after.
   */
  void reorder_child_after(Widget& child, const Widget& sibling);

  /** Moves @a child to the first position in the list of children.
   *
   * @param child The Gtk::Widget to move. Must be a child of the %Box.
   */
  void reorder_child_at_start(Widget& child);

  /** The amount of space between children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() -> Glib::PropertyProxy< int > ;

/** The amount of space between children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the children should all be the same size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() -> Glib::PropertyProxy< bool > ;

/** Whether the children should all be the same size.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The position of the baseline aligned widgets if extra space is available.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() -> Glib::PropertyProxy< BaselinePosition > ;

/** The position of the baseline aligned widgets if extra space is available.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() const -> Glib::PropertyProxy_ReadOnly< BaselinePosition >;


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
   * @relates Gtk::Box
   */
  GTKMM_API
  auto wrap(GtkBox* object, bool take_copy = false) -> Gtk::Box*;
} //namespace Glib


#endif /* _GTKMM_BOX_H */

