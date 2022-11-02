// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GDKMM_RGBA_H
#define _GDKMM_RGBA_H

#include <mm/gdk/mm-gdkconfig.h>


#include <mm/glib/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2010 The gtkmm Development Team
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


#include <mm/glib/value.h>
#include <gdk/gdk.h> //Needed for our RGBATraits here.


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GdkRGBA GdkRGBA; }
#endif

namespace Gdk
{

/** An %RGBA color.
 * The %RGBA class is a convenient way to pass colors around.
 * It's based on cairo's way to deal with (possibly translucent) colors and mirrors its behavior.
 * All values are in the range from 0.0 to 1.0 inclusive.
 * So the color (0.0, 0.0, 0.0, 0.0) represents transparent black and (1.0, 1.0, 1.0, 1.0) is opaque white.
 * Other values will be clamped to this range when drawing.
 */
class GDKMM_API RGBA
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = RGBA;
  using BaseObjectType = GdkRGBA;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  explicit RGBA(GdkRGBA* gobject, bool make_a_copy = true);

  RGBA(const RGBA& other);
  auto operator=(const RGBA& other) -> RGBA&;

  RGBA(RGBA&& other) noexcept;
  auto operator=(RGBA&& other) noexcept -> RGBA&;

  ~RGBA() noexcept;

  void swap(RGBA& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GdkRGBA*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GdkRGBA* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GdkRGBA*;

protected:
  GdkRGBA* gobject_;

private:


public:


  /** Instantiate a new Gdk::RGBA.
   */
  RGBA();

  /** Parses a textual representation of a color and creates a new Gdk::RGBA
   * with the corresponding values in its <tt>red</tt>, <tt>green</tt>,
   * <tt>blue</tt> and <tt>alpha</tt> fields.
   *
   * The string can be one of:
   *
   * <ul>
   *   <li>A standard name (taken from the X11 rgb.txt file)</li>
   *   <li>A hexadecimal value in the form <tt>#rgb</tt>, <tt>#rrggbb</tt>,
   *     <tt>#rrrgggbbb</tt> or </tt>#rrrrggggbbbb</tt></li>
   *   <li>An RGB color in the form <tt>rgb(r,g,b)</tt> (In this case the color will have full opacity)</li>
   *   <li>An RGBA color in the form <tt>rgba(r,g,b,a)</tt></li>
   * </ul>
   *
   * Where <tt>r</tt>, <tt>g</tt>, <tt>b</tt> and <tt>a</tt> are respectively
   * the red, green, blue and alpha color values. In the last two cases,
   * <tt>r</tt> <tt>g</tt> and <tt>b</tt> are either integers in the range 0 to
   * 255 or percentage values in the range 0% to 100%, and <tt>a</tt> is a
   * floating point value in the range 0 to 1.
   *
   * @param value the string specifying the color.
   */
  explicit RGBA(const Glib::ustring& value);


  /** Construct a Gdk::RGBA, by specifying red, green, and blue color component values, as fractions.
   * @param red_ The red component of the color, as a fraction.
   * @param green_ The green component of the color, as a fraction.
   * @param blue_ The blue component of the color, as a fraction.
   * @param alpha_ The alpha component of the color, as a fraction.
   */
  RGBA(float red_, float green_, float blue_, float alpha_ = 1.0);

  /** Set a grey color, by using the same value for all color components.
   * @param value The value to be used for the red, green, and blue components, in the range 0..65535.
   * @param alpha The alpha component of the color, in the range 0..65535.
   */
  void set_grey_u(gushort value, gushort alpha = 65535);

  /** Set a grey color, by using the same value for all color components.
   * @param g The value to be used for the red, green, and blue components, as a fraction.
   * @param alpha The alpha component of the color, as a fraction.
   */
  void set_grey(float g, float alpha = 1.0);

  /** Set the color, by specifying red, green, and blue color component values.
   * @param red_ The red component of the color, in the range 0..65535.
   * @param green_ The green component of the color, in the range 0..65535.
   * @param blue_ The blue component of the color, in the range 0..65535.
   * @param alpha_ The alpha component of the color, in the range 0..65535.
   */
  void set_rgba_u(gushort red_, gushort green_, gushort blue_, gushort alpha_ = 65535);

  /** Set the color, by specifying red, green, and blue color component values, as fractions.
   * @param red_ The red component of the color, as a fraction.
   * @param green_ The green component of the color, as a fraction.
   * @param blue_ The blue component of the color, as a fraction.
   * @param alpha_ The alpha component of the color, as a fraction.
   */
  void set_rgba(float red_, float green_, float blue_, float alpha_ = 1.0);

  /** Set the color, by specifying hue, saturation, and value (brightness).
   * @param h Hue, in the range 0..360 degrees.
   * @param s Saturation, in the range 0..1.
   * @param v Value (a.k.a. brightness), in the range 0..1.
   * @param alpha The alpha component of the color, in the range 0..1.
   */
  void set_hsv(float h, float s, float v, float alpha = 1.0);

  /** Set the color, by specifying hue, saturation, and lightness.
   * @param h Hue, in the range 0..360 degrees.
   * @param s Saturation, in the range 0..1.
   * @param l Lightness, in the range 0..1.
   * @param alpha The alpha component of the color, in the range 0..1.
   */
  void set_hsl(float h, float s, float l, float alpha = 1.0);


  /** Parses a textual representation of a color.
   *
   * The string can be either one of:
   *
   * - A standard name (Taken from the Css specification).
   * - A hexadecimal value in the form “\\#rgb”, “\\#rrggbb”,
   * “\\#rrrgggbbb” or ”\\#rrrrggggbbbb”
   * - A hexadecimal value in the form “\\#rgba”, “\\#rrggbbaa”,
   * or ”\\#rrrrggggbbbbaaaa”
   * - A RGB color in the form “rgb(r,g,b)” (In this case the color
   * will have full opacity)
   * - A RGBA color in the form “rgba(r,g,b,a)”
   *
   * Where “r”, “g”, “b” and “a” are respectively the red, green,
   * blue and alpha color values. In the last two cases, “r”, “g”,
   * and “b” are either integers in the range 0 to 255 or percentage
   * values in the range 0% to 100%, and a is a floating point value
   * in the range 0 to 1.
   *
   * @param spec The string specifying the color.
   * @return <tt>true</tt> if the parsing succeeded.
   */
  auto set(const Glib::ustring& spec) -> bool;

  /** Get the red component of the color.
   * @result The red component of the color, in the range 0..65535.
   */
  auto get_red_u() const -> gushort;

  /** Get the green component of the color.
   * @result The green component of the color, in the range 0..65535.
   */
  auto get_green_u() const -> gushort;

  /** Get the blue component of the color.
   * @result The blue component of the color, in the range 0..65535.
   */
  auto get_blue_u() const -> gushort;

  /** Get the alpha component of the color.
   * @result The alpha component of the color, in the range 0..65535.
   */
  auto get_alpha_u() const -> gushort;

  /** Set the red component of the color.
   * @param value The red component of the color, in the range 0..65535.
   */
  void set_red_u(gushort value);

  /** Set the green component of the color.
   * @param value The green component of the color, in the range 0..65535.
   */
  void set_green_u(gushort value);

  /** Set the blue component of the color.
   * @param value The blue component of the color, in the range 0..65535.
   */
  void set_blue_u(gushort value);

  /** Set the alpha component of the color.
   * @param value The alpha component of the color, in the range 0..65535.
   */
  void set_alpha_u(gushort value);


  /** Get the red component of the color, as a fraction.
   * @result The red component of the color, as a fraction.
   */
  auto get_red() const -> float;

  /** Get the green component of the color, as a fraction.
   * @result The green component of the color, as a fraction.
   */
  auto get_green() const -> float;

  /** Get the blue component of the color, as a fraction.
   * @result The blue component of the color, as a fraction.
   */
  auto get_blue() const -> float;

  /** Get the alpha component of the color, as a fraction.
   * @result The alpha component of the color, as a fraction.
   */
  auto get_alpha() const -> float;

  /** Set the red component of the color, as a fraction.
   * @param value The red component of the color, as a fraction.
   */
  void set_red(float value);

  /** Set the green component of the color, as a fraction.
   * @param value The green component of the color, as a fraction.
   */
  void set_green(float value);

  /** Set the blue component of the color, as a fraction.
   * @param value The blue component of the color, as a fraction.
   */
  void set_blue(float value);

  /** Set the alpha component of the color, as a fraction.
   * @param value The alpha component of the color, as a fraction.
   */
  void set_alpha(float value);


  /** Returns a textual specification of @a rgba in the form
   * `rgb(r,g,b)` or `rgba(r,g,b,a)`, where “r”, “g”, “b” and
   * “a” represent the red, green, blue and alpha values
   * respectively. “r”, “g”, and “b” are represented as integers
   * in the range 0 to 255, and “a” is represented as a floating
   * point value in the range 0 to 1.
   *
   * These string forms are string forms that are supported by
   * the CSS3 colors module, and can be parsed by parse().
   *
   * Note that this string representation may lose some precision,
   * since “r”, “g” and “b” are represented as 8-bit integers. If
   * this is a concern, you should use a different representation.
   *
   * @return A newly allocated text string.
   */
  auto to_string() const -> Glib::ustring;


  /** Checks if an @a rgba value is transparent.
   *
   * That is, drawing with the value would not produce any change.
   *
   * @return <tt>true</tt> if the @a rgba is clear.
   */
  auto is_clear() const -> bool;

  /** Checks if an @a rgba value is opaque.
   *
   * That is, drawing with the value will not retain any results
   * from previous contents.
   *
   * @return <tt>true</tt> if the @a rgba is opaque.
   */
  auto is_opaque() const -> bool;


};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* These traits are for arrays of GdkRGBA structs -- not pointer arrays.
 */
struct RGBATraits
{
  typedef Gdk::RGBA  CppType;
  typedef GdkRGBA    CType;
  typedef GdkRGBA    CTypeNonConst;

  static auto   to_c_type      (const CppType& obj) -> CType { return *obj.gobj(); }
  static auto   to_c_type      (const CType&   obj) -> CType { return obj; }
  static auto to_cpp_type    (const CType&   obj) -> CppType { return CppType(const_cast<CType*>(&obj), true); }
  static void    release_c_type (const CType&)       {}
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

} // namespace Gdk


namespace Gdk
{

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GDKMM_API
auto operator==(const RGBA& lhs, const RGBA& rhs) -> bool;

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 * @result The result
 */
GDKMM_API
auto operator!=(const RGBA& lhs, const RGBA& rhs) -> bool;


} // namespace Gdk


namespace Gdk
{

/** @relates Gdk::RGBA
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(RGBA& lhs, RGBA& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gdk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gdk::RGBA
 */
GDKMM_API
auto wrap(GdkRGBA* object, bool take_copy = false) -> Gdk::RGBA;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GDKMM_API Value<Gdk::RGBA> : public Glib::Value_Boxed<Gdk::RGBA>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GDKMM_RGBA_H */
