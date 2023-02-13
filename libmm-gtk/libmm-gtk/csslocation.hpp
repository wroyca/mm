
#ifndef _GTKMM_CSSLOCATION_H
#define _GTKMM_CSSLOCATION_H

#include <mm/gtk/mm-gtkconfig.hpp>


#include <mm/glib/ustring.hpp>
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


#include <gtk/gtk.h>
#include <cstddef> // std::size_t


namespace Gtk
{
/** Presents a location in a file - or other source of data parsed by the CSS engine.
 *
 * The @a bytes and @a line_bytes offsets are meant to be used to
 * programmatically match data. The @a lines and @a line_chars offsets
 * can be used for printing the location in a file.
 *
 * Note that the @a lines parameter starts from 0 and is increased
 * whenever a CSS line break is encountered. (CSS defines the C character
 * sequences "\r\n", "\r", "\n" and "\f" as newlines.)
 * If your document uses different rules for line breaking, you might
 * run into problems here.
 *
 * @newin{3,96}
 */
class GTKMM_API CssLocation
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CssLocation;
  using BaseObjectType = GtkCssLocation;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:

  CssLocation();
  CssLocation(const GtkCssLocation* location);
  CssLocation(std::size_t bytes, std::size_t chars, std::size_t lines,
    std::size_t line_bytes, std::size_t line_chars);


  /** @returns Number of bytes parsed since the beginning.
   */
  auto get_bytes() const -> std::size_t;
  void set_bytes(const std::size_t& value);

  /** @returns Number of characters parsed since the beginning.
   */
  auto get_chars() const -> std::size_t;
  void set_chars(const std::size_t& value);

  /** @returns Number of full lines that have been parsed.
   *           If you want to display this as a line number, you
   *           need to add 1 to this.
   */
  auto get_lines() const -> std::size_t;
  void set_lines(const std::size_t& value);

  /** @returns Number of bytes parsed since the last line break.
   */
  auto get_line_bytes() const -> std::size_t;
  void set_line_bytes(const std::size_t& value);

  /** @returns Number of characters parsed since the last line break.
   */
  auto get_line_chars() const -> std::size_t;
  void set_line_chars(const std::size_t& value);

  auto       gobj() -> GtkCssLocation*       { return &gobject_; }
  auto gobj() const -> const GtkCssLocation* { return &gobject_; }

protected:
  GtkCssLocation gobject_;


};

} // namespace Gtk

namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @result A C++ instance that wraps a copy of this C instance.
   *
   * @relates Gtk::CssLocation
   */
GTKMM_API
auto wrap(const GtkCssLocation* object) -> Gtk::CssLocation;

} // namespace Glib


#endif /* _GTKMM_CSSLOCATION_H */

