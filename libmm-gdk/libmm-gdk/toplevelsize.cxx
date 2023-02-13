


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/toplevelsize.hxx>
#include <libmm-gdk/toplevelsize_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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

#include <gdk/gdk.h>
#include <utility> // std::move(), std::swap()

namespace Gdk
{

ToplevelSize::operator bool() const
{
  return gobj();
}

ToplevelSize::ToplevelSize(GdkToplevelSize* gobject)
:
  gobject_(gobject)
{}

ToplevelSize::ToplevelSize(ToplevelSize&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  other.gobject_ = nullptr;
}

auto ToplevelSize::operator=(ToplevelSize&& other) noexcept -> ToplevelSize&
{
  ToplevelSize temp(std::move(other));
  std::swap(gobject_, temp.gobject_);
  return *this;
}

ToplevelSize::~ToplevelSize() noexcept
{
  // The Gdk::ToplevelSize instance does not own the wrapped GdkToplevelSize instance.
  // GdkToplevelSize is a private gtk struct with no public create,
  // copy or free functions.
}

} // namespace Gdk

namespace
{
} // anonymous namespace


namespace Gdk
{


auto ToplevelSize::get_bounds (int &bounds_width, int &bounds_height) const -> void
{
  gdk_toplevel_size_get_bounds(const_cast<GdkToplevelSize*>(gobj()), &bounds_width, &bounds_height);
}

auto ToplevelSize::set_size (
  const int width, const int height) -> void
{
  gdk_toplevel_size_set_size(gobj(), width, height);
}

auto ToplevelSize::set_min_size (
  const int min_width, const int min_height) -> void
{
  gdk_toplevel_size_set_min_size(gobj(), min_width, min_height);
}

auto ToplevelSize::set_shadow_width (
  const int left, const int right, const int top, const int bottom) -> void
{
  gdk_toplevel_size_set_shadow_width(gobj(), left, right, top, bottom);
}


} // namespace Gdk


