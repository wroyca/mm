
#ifndef _GTKMM_PANED_H
#define _GTKMM_PANED_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
#include <libmm-gtk/orientable.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPaned = struct _GtkPaned;
using GtkPanedClass = struct _GtkPanedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Paned_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget with two adjustable panes.
 *
 * Gtk::Paned has two panes, arranged either
 * horizontally or vertically. The division between
 * the two panes is adjustable by the user by dragging
 * a handle.
 *
 * Child widgets are added to the panes of the widget with
 * set_start_child() and set_end_child().
 * The division between the two children is set by default from the size
 * requests of the children, but it can be adjusted by the user.
 *
 * A paned widget draws a separator between the two child widgets and a small
 * handle that the user can drag to adjust the division. It does not draw any
 * relief around the children or around the separator.  (The space
 * in which the separator is called the gutter.) Often, it is useful to
 * put each child inside a Gtk::Frame so that the gutter appears as a ridge.
 * No separator is drawn if one of the children is missing.
 *
 * Each child has two options that can be set - resize and shrink. If resize is
 * true, then when the GtkPaned is resized, that child will expand or shrink
 * along with the paned widget. If shrink is true, then when that child can be
 * made smaller than it's requisition. Setting shrink to false allows the
 * application to set a minimum size. If resize is false for both children,
 * then this is treated as if resize is true for both children.
 *
 * The application can set the position of the slider as if it were set by the
 * user, by calling set_position().
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Paned
 : public Widget,
   public Orientable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Paned CppObjectType;
  typedef Paned_Class CppClassType;
  typedef GtkPaned BaseObjectType;
  typedef GtkPanedClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Paned(Paned&& src) noexcept;
  auto operator=(Paned&& src) noexcept -> Paned&;

  // noncopyable
  Paned(const Paned&) = delete;
  auto operator=(const Paned&) -> Paned& = delete;

  ~Paned() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Paned_Class;
  static CppClassType paned_class_;

protected:
  explicit Paned(const Glib::ConstructParams& construct_params);
  explicit Paned(GtkPaned* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkPaned*       { return reinterpret_cast<GtkPaned*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkPaned* { return reinterpret_cast<GtkPaned*>(gobject_); }

private:


public:

  //Note that we try to use the same defaul parameter value as the default property value.
    explicit Paned(Orientation orientation =  Orientation::HORIZONTAL);


  /** Sets the start child of @a paned to @a child.
   *
   * If @a child is <tt>nullptr</tt>, the existing child will be removed.
   *
   * @param child The widget to add.
   */
  void set_start_child(Widget& child);

  /** Retrieves the start child of the given `Gtk::Paned`.
   *
   * @return The start child widget.
   */
  auto get_start_child() -> Widget*;

  /** Retrieves the start child of the given `Gtk::Paned`.
   *
   * @return The start child widget.
   */
  auto get_start_child() const -> const Widget*;

  /** Sets whether the property_start_child() can be resized.
   *
   * @param resize True to let the start child be resized.
   */
  void set_resize_start_child(bool resize =  true);

  /** Returns whether the property_start_child() can be resized.
   *
   * @return True if the start child is resizable.
   */
  auto get_resize_start_child() const -> bool;

  /** Sets whether the property_start_child() can shrink.
   *
   * @param resize True to let the start child be shrunk.
   */
  void set_shrink_start_child(bool resize =  true);

  /** Returns whether the property_start_child() can shrink.
   *
   * @return True if the start child is shrinkable.
   */
  auto get_shrink_start_child() const -> bool;


  /** Sets the end child of @a paned to @a child.
   *
   * If @a child is <tt>nullptr</tt>, the existing child will be removed.
   *
   * @param child The widget to add.
   */
  void set_end_child(Widget& child);

  /** Retrieves the end child of the given `Gtk::Paned`.
   *
   * @return The end child widget.
   */
  auto get_end_child() -> Widget*;

  /** Retrieves the end child of the given `Gtk::Paned`.
   *
   * @return The end child widget.
   */
  auto get_end_child() const -> const Widget*;

  /** Sets whether the property_end_child() can be resized.
   *
   * @param resize True to let the end child be resized.
   */
  void set_resize_end_child(bool resize =  true);

  /** Returns whether the property_end_child() can be resized.
   *
   * @return True if the end child is resizable.
   */
  auto get_resize_end_child() const -> bool;

  /** Sets whether the property_end_child() can shrink.
   *
   * @param resize True to let the end child be shrunk.
   */
  void set_shrink_end_child(bool resize =  true);

  /** Returns whether the property_end_child() can shrink.
   *
   * @return True if the end child is shrinkable.
   */
  auto get_shrink_end_child() const -> bool;


  /** Obtains the position of the divider between the two panes.
   *
   * @return The position of the divider, in pixels.
   */
  auto get_position() const -> int;

  /** Sets the position of the divider between the two panes.
   *
   * @param position Pixel position of divider, a negative value means that the position
   * is unset.
   */
  void set_position(int position);


  /** Sets whether the separator should be wide.
   *
   * @param wide The new value for the property_wide_handle() property.
   */
  void set_wide_handle(bool wide =  true);

  /** Gets whether the separator should be wide.
   *
   * @return <tt>true</tt> if the paned should have a wide handle.
   */
  auto get_wide_handle() const -> bool;

  //Keybinding signals:


  /** Position of the separator in pixels, from the left/top.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position() -> Glib::PropertyProxy< int > ;

/** Position of the separator in pixels, from the left/top.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the property_position() property has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position_set() -> Glib::PropertyProxy< bool > ;

/** Whether the property_position() property has been set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_position_set() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The smallest possible value for the property_position()
   * property.
   *
   * This property is derived from the size and shrinkability
   * of the widget's children.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_min_position() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** The largest possible value for the property_position()
   * property.
   *
   * This property is derived from the size and shrinkability
   * of the widget's children.
   *
   * Default value: 2147483647
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_max_position() const -> Glib::PropertyProxy_ReadOnly< int >;


  /** Whether the `Gtk::Paned` should provide a stronger visual separation.
   *
   * For example, this could be set when a paned contains two
   * Gtk::Notebooks, whose tab rows would otherwise merge visually.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wide_handle() -> Glib::PropertyProxy< bool > ;

/** Whether the `Gtk::Paned` should provide a stronger visual separation.
   *
   * For example, this could be set when a paned contains two
   * Gtk::Notebooks, whose tab rows would otherwise merge visually.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wide_handle() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the first child expands and shrinks
   * along with the paned widget.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resize_start_child() -> Glib::PropertyProxy< bool > ;

/** Determines whether the first child expands and shrinks
   * along with the paned widget.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resize_start_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the second child expands and shrinks
   * along with the paned widget.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resize_end_child() -> Glib::PropertyProxy< bool > ;

/** Determines whether the second child expands and shrinks
   * along with the paned widget.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resize_end_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the first child can be made smaller
   * than its requisition.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shrink_start_child() -> Glib::PropertyProxy< bool > ;

/** Determines whether the first child can be made smaller
   * than its requisition.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shrink_start_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** Determines whether the second child can be made smaller
   * than its requisition.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shrink_end_child() -> Glib::PropertyProxy< bool > ;

/** Determines whether the second child can be made smaller
   * than its requisition.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_shrink_end_child() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The first child.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_start_child() -> Glib::PropertyProxy< Widget* > ;

/** The first child.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_start_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;

  /** The second child.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_end_child() -> Glib::PropertyProxy< Widget* > ;

/** The second child.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_end_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >;


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
   * @relates Gtk::Paned
   */
  GTKMM_API
  auto wrap(GtkPaned* object, bool take_copy = false) -> Gtk::Paned*;
} //namespace Glib


#endif /* _GTKMM_PANED_H */

