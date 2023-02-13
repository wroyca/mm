
#ifndef _GTKMM_BOXLAYOUT_H
#define _GTKMM_BOXLAYOUT_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/layoutmanager.hxx>
#include <libmm-gtk/orientable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API BoxLayout_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** %Layout manager for placing all children in a single row or column.
 *
 * A %Gtk::BoxLayout is a layout manager that arranges the children of any
 * widget using it into a single row or column, depending on the value
 * of its Gtk::Orientable::property_orientation(). Within the other dimension
 * all children all allocated the same size. The %Gtk::BoxLayout will respect
 * Gtk::Widget::property_halign() and Gtk::Widget::property_valign() of each
 * child widget.
 *
 * If you want all children to be assigned the same size, you can use
 * property_homogeneous().
 *
 * If you want to specify the amount of space placed between each child,
 * you can use the property_spacing().
 *
 * @newin{3,96}
 */

class GTKMM_API BoxLayout : public LayoutManager, public Orientable
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = BoxLayout;
  using CppClassType = BoxLayout_Class;
  using BaseObjectType = GtkBoxLayout;
  using BaseClassType = GtkBoxLayoutClass;

  // noncopyable
  BoxLayout(const BoxLayout&) = delete;
  auto operator=(const BoxLayout&) -> BoxLayout& = delete;

private:  friend class BoxLayout_Class;
  static CppClassType boxlayout_class_;

protected:
  explicit BoxLayout(const Glib::ConstructParams& construct_params);
  explicit BoxLayout(GtkBoxLayout* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  BoxLayout(BoxLayout&& src) noexcept;
  auto operator=(BoxLayout&& src) noexcept -> BoxLayout&;

  ~BoxLayout() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBoxLayout*       { return reinterpret_cast<GtkBoxLayout*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBoxLayout* { return reinterpret_cast<GtkBoxLayout*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkBoxLayout*;

private:


protected:
    explicit BoxLayout(Orientation orientation =  Orientation::HORIZONTAL);


public:

  static auto create(Orientation orientation =  Orientation::HORIZONTAL) -> Glib::RefPtr<BoxLayout>;


  /** Sets whether the box layout will allocate the same
   * size to all children.
   *
   * @param homogeneous <tt>true</tt> to set the box layout as homogeneous.
   */
  void set_homogeneous(bool homogeneous =  true);

  /** Returns whether the layout is set to be homogeneous.
   *
   * Return: <tt>true</tt> if the layout is homogeneous
   */
  auto get_homogeneous() const -> bool;


  /** Sets how much spacing to put between children.
   *
   * @param spacing The spacing to apply between children.
   */
  void set_spacing(guint spacing);

  /** Returns the space that @a box_layout puts between children.
   *
   * @return The spacing of the layout.
   */
  auto get_spacing() const -> guint;


  /** Sets the baseline position of a box layout.
   *
   * The baseline position affects only horizontal boxes with at least one
   * baseline aligned child. If there is more vertical space available than
   * requested, and the baseline is not allocated by the parent then the
   * given @a position is used to allocate the baseline within the extra
   * space available.
   *
   * @param position A `Gtk::BaselinePosition`.
   */
  void set_baseline_position(BaselinePosition position);

  /** Gets the value set by set_baseline_position().
   *
   * @return The baseline position.
   */
  auto get_baseline_position() const -> BaselinePosition;

  // spacing is int in property_spacing(), but guint in set/get_spacing().
  // That's how it's done in gtk.
  /** Whether the box layout should distribute the available space
   * equally among the children.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() -> Glib::PropertyProxy< bool > ;

/** Whether the box layout should distribute the available space
   * equally among the children.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The space to put between the children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() -> Glib::PropertyProxy< int > ;

/** The space to put between the children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** The position of the allocated baseline within the extra space
   * allocated to each child.
   *
   * This property is only relevant for horizontal layouts containing
   * at least one child with a baseline alignment.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() -> Glib::PropertyProxy< BaselinePosition > ;

/** The position of the allocated baseline within the extra space
   * allocated to each child.
   *
   * This property is only relevant for horizontal layouts containing
   * at least one child with a baseline alignment.
   *
   * Default value: Gtk::BaselinePosition::CENTER
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_baseline_position() const -> Glib::PropertyProxy_ReadOnly< BaselinePosition >;


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
   * @relates Gtk::BoxLayout
   */
  GTKMM_API
  auto wrap(GtkBoxLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BoxLayout>;
}


#endif /* _GTKMM_BOXLAYOUT_H */

