// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/toplevelsize.hpp>
#include <mm/gdk/private/toplevelsize_p.hpp>


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


void ToplevelSize::get_bounds(int& bounds_width, int& bounds_height) const
{
  gdk_toplevel_size_get_bounds(const_cast<GdkToplevelSize*>(gobj()), &(bounds_width), &(bounds_height));
}

void ToplevelSize::set_size(int width, int height)
{
  gdk_toplevel_size_set_size(gobj(), width, height);
}

void ToplevelSize::set_min_size(int min_width, int min_height)
{
  gdk_toplevel_size_set_min_size(gobj(), min_width, min_height);
}

void ToplevelSize::set_shadow_width(int left, int right, int top, int bottom)
{
  gdk_toplevel_size_set_shadow_width(gobj(), left, right, top, bottom);
}


} // namespace Gdk

