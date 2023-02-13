


#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/color.hxx>
#include <libmm-pango/color_p.hxx>

#include <cstring> // std::memset()

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

namespace Pango
{

/* For some unknown reason pango doesn't provide pango_color_new(). Let's define an
 * equivalent function ourself! */
auto _pango_color_new() -> PangoColor*
{
  return g_new(PangoColor, 1);
}

Color::operator bool() const
{
  return gobj() != nullptr;
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoColor* object) -> Pango::Color&
{
  return *reinterpret_cast<Pango::Color*>(object);
}

auto wrap(const PangoColor* object) -> const Pango::Color&
{
  return *reinterpret_cast<const Pango::Color*>(object);
}

} // namespace Glib


namespace Pango
{


Color::Color(const Color& other) noexcept = default;

auto Color::operator=(const Color& other) noexcept -> Color& = default;

Color::Color(Color&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  //We could wipe other.gobject_ via memset,
  //but that is not really necessary:
  //other.gobject_ = nullptr;
}

auto Color::operator=(Color&& other) noexcept -> Color&
{
  gobject_ = std::move(other.gobject_);
  return *this;
}

// static
auto Color::get_type() -> GType
{
  return pango_color_get_type();
}

Color::Color()
{
  std::memset(&gobject_, 0, sizeof(PangoColor));
}

Color::Color(const PangoColor* gobject)
{
  if(gobject)
    gobject_ = *gobject;
  else
    std::memset(&gobject_, 0, sizeof(PangoColor));
}


auto Color::get_red() const -> guint16
{
  return gobj()->red;
}

auto Color::get_green() const -> guint16
{
  return gobj()->green;
}

auto Color::get_blue() const -> guint16
{
  return gobj()->blue;
}

auto Color::set_red (const guint16 &value) -> void
{
  gobj()->red = value;
}

auto Color::set_green (const guint16 &value) -> void
{
  gobj()->green = value;
}

auto Color::set_blue (const guint16 &value) -> void
{
  gobj()->blue = value;
}

auto Color::parse(const Glib::ustring& spec) -> bool
{
  return pango_color_parse(gobj(), spec.c_str());
}

auto Color::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(pango_color_to_string(gobj()));
}


} // namespace Pango


