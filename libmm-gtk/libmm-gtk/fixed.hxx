
#ifndef _GTKMM_FIXED_H
#define _GTKMM_FIXED_H


#include <libmm-glib/ustring.hxx>
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

#include <libmm-gtk/widget.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFixed = struct _GtkFixed;
using GtkFixedClass = struct _GtkFixedClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Fixed_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A container which allows you to position widgets at fixed coordinates.
 *
 * The Gtk::Fixed widget is a container which can place child widgets at fixed positions and with fixed sizes, given in pixels. It performs no automatic layout management.
 * For most applications, you should not use this container, because it will result in truncated text, overlapping widgets, and other display bugs:
 * - Themes may change widget sizes.
 * - Fonts other than the one you used to write the app will of course change the size of widgets containing text; keep in mind that users may use a larger font because of difficulty reading the default, or they may be using Windows or the framebuffer port of GTK+, where different fonts are available.
 * - Translation of text into other languages changes its size. Also, display of non-English text will use a different font in many cases.
 * In addition, the fixed widget can't properly be mirrored in right-to-left languages such as Hebrew and Arabic. i.e. normally GTK+ will flip the interface to put labels to the right of the thing they label, but it can't do that with Gtk::Fixed. So your application will not be usable in right-to-left languages.
 * Finally, fixed positioning makes it kind of annoying to add/remove GUI elements, since you have to reposition all the other elements. This is a long-term maintenance problem for your application.
 * If you know none of these things are an issue for your application, and prefer the simplicity of Gtk::Fixed, by all means use the widget. But you should be aware of the tradeoffs.
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API Fixed : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Fixed CppObjectType;
  typedef Fixed_Class CppClassType;
  typedef GtkFixed BaseObjectType;
  typedef GtkFixedClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Fixed(Fixed&& src) noexcept;
  auto operator=(Fixed&& src) noexcept -> Fixed&;

  // noncopyable
  Fixed(const Fixed&) = delete;
  auto operator=(const Fixed&) -> Fixed& = delete;

  ~Fixed() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class Fixed_Class;
  static CppClassType fixed_class_;

protected:
  explicit Fixed(const Glib::ConstructParams& construct_params);
  explicit Fixed(GtkFixed* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkFixed*       { return reinterpret_cast<GtkFixed*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFixed* { return reinterpret_cast<GtkFixed*>(gobject_); }

private:

public:
  Fixed();


  /** Adds a widget to a `Gtk::Fixed` at the given position.
   *
   * @param widget The widget to add.
   * @param x The horizontal position to place the widget at.
   * @param y The vertical position to place the widget at.
   */
  void put(Widget& widget, double x, double y);

  /** Removes a child from @a fixed.
   *
   * @param widget The child widget to remove.
   */
  void remove(Widget& widget);

  /** Sets a translation transformation to the given @a x and @a y
   * coordinates to the child @a widget of the `Gtk::Fixed`.
   *
   * @param widget The child widget.
   * @param x The horizontal position to move the widget to.
   * @param y The vertical position to move the widget to.
   */
  void move(Widget& widget, double x, double y);

  /** Retrieves the translation transformation of the
   * given child `Gtk::Widget` in the `Gtk::Fixed`.
   *
   * See also: get_child_transform().
   *
   * @param widget A child of @a fixed.
   * @param x The horizontal position of the @a widget.
   * @param y The vertical position of the @a widget.
   */
  void get_child_position(Widget& widget, double& x, double& y) const;


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
   * @relates Gtk::Fixed
   */
  GTKMM_API
  auto wrap(GtkFixed* object, bool take_copy = false) -> Gtk::Fixed*;
} //namespace Glib


#endif /* _GTKMM_FIXED_H */

