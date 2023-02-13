
#ifndef _PANGOMM_COLOR_H
#define _PANGOMM_COLOR_H

#include <mm/pango/mm-pangoconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <mm/glib/value.hpp>
#include <mm/glib/utility.hpp>
#include <pango/pango.h>


namespace Pango
{

/** A Pango::Color is used to represent a color in an uncalibrated RGB colorspace.
 */
class PANGOMM_API Color
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Color;
  using BaseObjectType = PangoColor;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Color(const Color& other) noexcept;
  auto operator=(const Color& other) noexcept -> Color&;

  Color(Color&& other) noexcept;
  auto operator=(Color&& other) noexcept -> Color&;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;

  Color();

  explicit Color(const PangoColor* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoColor*       { return &gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoColor* { return &gobject_; }

protected:
  PangoColor gobject_;

private:


public:

  /// Tests whether the Color is valid.
  explicit operator bool() const;

  /** Gets the red component of the color.
   * @return The red component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  auto get_red() const -> guint16;

  /** Gets the green component of the color.
   * @return The green component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  auto get_green() const -> guint16;

  /** Gets the blue component of the color.
   * @return The blue component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  auto get_blue() const -> guint16;

  /** Sets the red component of the color.
   * @param value The red component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  void set_red(const guint16& value);

  /** Sets the green component of the color.
   * @param value The green component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  void set_green(const guint16& value);

  /** Sets the blue component of the color.
   * @param value The blue component of the color. This is a value between 0 and 65535, with 65535 indicating full intensity.
   */
  void set_blue(const guint16& value);


  /** Fill in the fields of a color from a string specification. The
   * string can either one of a large set of standard names. (Taken
   * from the X11 &lt;filename&gt;rgb.txt&lt;/filename&gt; file), or it can be a hex value in the
   * form '#rgb' '#rrggbb' '#rrrgggbbb' or '#rrrrggggbbbb' where
   * 'r', 'g' and 'b' are hex digits of the red, green, and blue
   * components of the color, respectively. (White in the four
   * forms is '#fff' '#ffffff' '#fffffffff' and '#ffffffffffff')
   *
   * @param spec A string specifying the new color.
   * @return <tt>true</tt> if parsing of the specifier succeeded,
   * otherwise <tt>false</tt>.
   */
  auto parse(const Glib::ustring& spec) -> bool;


  /** Returns a textual specification of @a color.
   *
   * The string is in the hexadecimal form `#rrrrggggbbbb`,
   * where `r`, `g` and `b` are hex digits representing the
   * red, green, and blue components respectively.
   *
   * @newin{1,16}
   *
   * @return A newly-allocated text string that must
   * be freed with Glib::free().
   */
  auto to_string() const -> Glib::ustring;


};

} /* namespace Pango */


namespace Glib
{

/** @relates Pango::Color
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
PANGOMM_API
auto wrap(PangoColor* object) -> Pango::Color&;

/** @relates Pango::Color
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
PANGOMM_API
auto wrap(const PangoColor* object) -> const Pango::Color&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::Color> : public Glib::Value_Boxed<Pango::Color>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_COLOR_H */

