
#ifndef _GTKMM_BORDER_H
#define _GTKMM_BORDER_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright 2009 The gtkmm Development Team
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


#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkBorder GtkBorder; }
#endif

namespace Gtk
{

/** This specifies a border around a rectangular area that can be of a different width on each side.
 */
class GTKMM_API Border
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Border;
  using BaseObjectType = GtkBorder;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  Border();

  explicit Border(GtkBorder* gobject, bool make_a_copy = true);

  Border(const Border& other);
  auto operator=(const Border& other) -> Border&;

  Border(Border&& other) noexcept;
  auto operator=(Border&& other) noexcept -> Border&;

  ~Border() noexcept;

  void swap(Border& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkBorder*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkBorder* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkBorder*;

protected:
  GtkBorder* gobject_;

private:

public:

  /** Get the width of the left border.
   */
  auto get_left() const -> int;

  /** Set the width of the left border.
   */
  void set_left(const int& value);

  /** Get the width of the right border.
   */
  auto get_right() const -> int;

  /** Set the width of the right border.
   */
  void set_right(const int& value);

  /** Get the width of the top border.
   */
  auto get_top() const -> int;

  /** Set the width of the top border.
   */
  void set_top(const int& value);

  /** Get the width of the bottom border.
   */
  auto get_bottom() const -> int;

  /** Set the width of the bottom border.
   */
  void set_bottom(const int& value);


};

} //namespace Gtk


namespace Gtk
{

/** @relates Gtk::Border
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(Border& lhs, Border& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gtk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::Border
 */
GTKMM_API
auto wrap(GtkBorder* object, bool take_copy = false) -> Gtk::Border;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GTKMM_API Value<Gtk::Border> : public Glib::Value_Boxed<Gtk::Border>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_BORDER_H */

