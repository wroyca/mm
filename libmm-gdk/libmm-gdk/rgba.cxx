


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/rgba.hxx>
#include <libmm-gdk/rgba_p.hxx>


/*
 * Copyright 2010 The gtkmm Development Team
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

#include <gdk/gdk.h>

namespace Gdk
{

 const float MULTIPLIER = 65535.0f;

RGBA::RGBA()
{
  const GdkRGBA tmp = { 0, 0, 0, 0, };
  gobject_ = gdk_rgba_copy(&tmp);
}

RGBA::RGBA(const Glib::ustring& value)
: RGBA()
{
  set(value);
}

RGBA::RGBA(const float red_, const float green_, const float blue_, const float alpha_)
{
  const GdkRGBA tmp = { red_, green_, blue_, alpha_, };
  gobject_ = gdk_rgba_copy(&tmp);
}

auto RGBA::set_grey_u (
  const gushort value, const gushort alpha) -> void
{
  gobject_->red = gobject_->green = gobject_->blue = value / MULTIPLIER;
  gobject_->alpha = alpha / MULTIPLIER;
}

auto RGBA::set_grey (
  const float g, const float alpha) -> void
{
  gobject_->red = gobject_->green = gobject_->blue = g;
  gobject_->alpha = alpha;
}

auto RGBA::set_rgba_u (
  const gushort red_, const gushort green_, const gushort blue_, const gushort alpha_) -> void
{
  gobject_->red = red_ / MULTIPLIER;
  gobject_->green = green_/ MULTIPLIER;
  gobject_->blue = blue_ / MULTIPLIER;
  gobject_->alpha = alpha_/ MULTIPLIER;
}

auto RGBA::set_rgba (
  const float red_, const float green_, const float blue_, const float alpha_) -> void
{
  gobject_->red = red_;
  gobject_->green = green_;
  gobject_->blue = blue_;
  gobject_->alpha = alpha_;
}

auto RGBA::set_hsv (float h, const float s, const float v, const float alpha) -> void
{
  // The HSV color space is described in a long Wikipedia article,
  // http://en.wikipedia.org/wiki/HSV_color_space
  // The following conversion from HSV to RGB is equivalent to the conversion
  // shown in Wikipedia. The following relations hold between the Wikipedia
  // equations (uppercase letters) and the equations used here (lowercase letters):
  //
  // h = H' (after division of h by 60 degrees)
  // p = V - C = m (m from Wikipedia), thus v = C + m
  // When i is odd:  X + m = V - C * abs(H' mod 2 - 1)
  //                       = v - vs * (h - i) = q
  // When i is even: X + m = V - C * abs(H' mod 2 - 1)
  //                       = v - vs * (1 - (h - i)) = t

  h /= 60.0f;
  const int i = (int)h;
  const float p = v * (1 - s);
  const float q = v * (1 - s * (h - i));
  const float t = v * (1 - s * (1 - h + i));

  switch(i)
  {
    case 1:
      set_rgba(q, v, p, alpha);
      break;
    case 2:
      set_rgba(p, v, t, alpha);
      break;
    case 3:
      set_rgba(p, q, v, alpha);
      break;
    case 4:
      set_rgba(t, p, v, alpha);
      break;
    case 5:
      set_rgba(v, p, q, alpha);
      break;
    default: // i == 0 || i == 6
      set_rgba(v, t, p, alpha);
  }
}

auto RGBA::set_hsl (float h, const float s, const float l, const float alpha) -> void
{
  // The HSL color space is described in a long Wikipedia article,
  // http://en.wikipedia.org/wiki/HSV_color_space
  // The following conversion from HSL to RGB is equivalent to the conversion
  // shown in Wikipedia. The following relations hold between the Wikipedia
  // equations (uppercase letters) and the equations used here (lowercase letters):
  //
  // 6*h = H' (after division of h by 360 degrees)
  // t2 = C + m (m from Wikipedia)
  // t1 = m
  //
  // The conversion algorithm used here is shown at
  // http://www.w3.org/TR/css3-color/#hsl-color

  if(s == 0.0f)
    set_grey(l, alpha);
  else
  {
    const float t2 = l < 0.5f ? l * (1.0f + s) : l + s - l * s;
    const float t1 = 2*l-t2;
    h /= 360.0f;

    float tr = h + 1.0f/3.0f;
    const float tg = h;
    float tb = h - 1.0f/3.0f;
    if (tr > 1.0f) tr -= 1.0f;
    if (tb < 0.0f) tb += 1.0f;

    float r = t1;
    float g = t1;
    float b = t1;

    if (tr < 1.0f/6.0f)
      r = t1 +(t2-t1) * 6 * tr;
    else if (tr < 1.0f/2.0f)
      r = t2;
    else if (tr < 2.0f/3.0f)
      r = t1+(t2-t1)*(2.0f/3.0f - tr) * 6.0f;

    if (tg < 1.0f/6.0f)
      g = t1 + (t2 - t1) * 6 * tg;
    else if (tg < 1.0f/2.0f)
      g = t2;
    else if (tg < 2.0f/3.0f)
      g = t1+(t2-t1)*(2.0f/3.0f - tg) * 6.0f;

    if (tb < 1.0f/6.0f)
      b = t1 +(t2-t1) * 6 * tb;
    else if (tb < 1.0f/2.0f)
      b = t2;
    else if (tb < 2.0f/3.0f)
      b = t1+(t2-t1)*(2.0f/3.0f - tb) * 6.0f;

    set_rgba(r, g, b, alpha);
  }
}

auto RGBA::get_red_u() const -> gushort
{
  return gobject_->red *  MULTIPLIER;
}

auto RGBA::get_green_u() const -> gushort
{
  return gobject_->green *  MULTIPLIER;

}

auto RGBA::get_blue_u() const -> gushort
{
  return gobject_->blue *  MULTIPLIER;
}

auto RGBA::get_alpha_u() const -> gushort
{
  return gobject_->alpha *  MULTIPLIER;
}

auto RGBA::set_red_u (
  const gushort value) -> void
{
  gobject_->red = value / MULTIPLIER;
}

auto RGBA::set_green_u (
  const gushort value) -> void
{
  gobject_->green = value / MULTIPLIER;
}

auto RGBA::set_blue_u (
  const gushort value) -> void
{
  gobject_->blue = value / MULTIPLIER;
}

auto RGBA::set_alpha_u (
  const gushort value) -> void
{
  gobject_->alpha = value / MULTIPLIER;
}

auto RGBA::set_red (
  const float value) -> void
{
  gobject_->red = value;
}

auto RGBA::set_green (
  const float value) -> void
{
  gobject_->green = value;
}

auto RGBA::set_blue (
  const float value) -> void
{
  gobject_->blue = value;
}

auto RGBA::set_alpha (
  const float value) -> void
{
  gobject_->alpha = value;
}

auto RGBA::get_red() const -> float
{
  return gobject_->red;
}

auto RGBA::get_green() const -> float
{
  return gobject_->green;
}

auto RGBA::get_blue() const -> float
{
  return gobject_->blue;
}

auto RGBA::get_alpha() const -> float
{
  return gobject_->alpha;
}

} //namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkRGBA* object, const bool take_copy) -> Gdk::RGBA
{
  return Gdk::RGBA(object, take_copy);
}

} // namespace Glib


namespace Gdk
{


// static
auto RGBA::get_type() -> GType
{
  return gdk_rgba_get_type();
}


RGBA::RGBA(const RGBA& other)
:
  gobject_ (other.gobject_ ? gdk_rgba_copy(other.gobject_) : nullptr)
{}

RGBA::RGBA(RGBA&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto RGBA::operator=(RGBA&& other) noexcept -> RGBA&
{
  RGBA temp (std::move(other));
  swap(temp);
  return *this;
}

RGBA::RGBA(GdkRGBA* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? gdk_rgba_copy(gobject) : gobject)
{}

auto RGBA::operator=(const RGBA& other) -> RGBA&
{
  RGBA temp (other);
  swap(temp);
  return *this;
}

RGBA::~RGBA() noexcept
{
  if(gobject_)
    gdk_rgba_free(gobject_);
}

auto RGBA::swap (RGBA &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto RGBA::gobj_copy() const -> GdkRGBA*
{
  return gdk_rgba_copy(gobject_);
}


auto RGBA::set(const Glib::ustring& spec) -> bool
{
  return gdk_rgba_parse(gobj(), spec.c_str());
}

auto RGBA::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_rgba_to_string(gobj()));
}

auto RGBA::is_clear() const -> bool
{
  return gdk_rgba_is_clear(gobj());
}

auto RGBA::is_opaque() const -> bool
{
  return gdk_rgba_is_opaque(gobj());
}


auto operator==(const RGBA& lhs, const RGBA& rhs) -> bool
{
  return gdk_rgba_equal(lhs.gobj(), rhs.gobj()) != 0;
}

auto operator!=(const RGBA& lhs, const RGBA& rhs) -> bool
{
  return gdk_rgba_equal(lhs.gobj(), rhs.gobj()) == 0;
}


} // namespace Gdk


