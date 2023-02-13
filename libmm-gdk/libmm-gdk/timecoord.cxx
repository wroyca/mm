


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/timecoord.hxx>
#include <libmm-gdk/timecoord_p.hxx>


/* Copyright (C) 2010 The gtkmm Development Team
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
#include <utility> // std::move(), std::swap()

namespace
{

inline auto time_coord_copy(const GdkTimeCoord* gobject) -> GdkTimeCoord*
{
  // Don't use g_memdup(). It's deprecated in glib 2.67.3.
  // Its replacement, g_memdup2(), is new in glib 2.67.3.
  if (!gobject)
    return nullptr;

  GdkTimeCoord* new_obj = g_new(GdkTimeCoord, 1);
  *new_obj = *gobject;
  return new_obj;
}

} // anonymous namespace

namespace Gdk
{

TimeCoord::TimeCoord(GdkTimeCoord* gobject, const bool make_a_copy)
:
  gobject_(make_a_copy && gobject ? time_coord_copy(gobject) : gobject)
{}

TimeCoord::TimeCoord(const TimeCoord& other)
:
  gobject_(time_coord_copy(other.gobject_))
{}

auto TimeCoord::operator=(const TimeCoord& other) -> TimeCoord&
{
  TimeCoord temp(other);
  std::swap(gobject_, temp.gobject_);
  return *this;
}

TimeCoord::TimeCoord(TimeCoord&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  other.gobject_ = nullptr;
}

auto TimeCoord::operator=(TimeCoord&& other) noexcept -> TimeCoord&
{
  TimeCoord temp(std::move(other));
  std::swap(gobject_, temp.gobject_);
  return *this;
}

TimeCoord::~TimeCoord() noexcept
{
  // If gobject_ == nullptr, g_free() does nothing.
  g_free(gobject_);
}

auto TimeCoord::get_value_at_axis(
  const guint index) const -> double
{
  if (gobject_)
  {
    return gobject_->axes[index];
  }
  return 0;
}

} // namespace Gdk

namespace
{
} // anonymous namespace


namespace Gdk
{


auto TimeCoord::get_time() const -> guint32
{
  return gobj()->time;
}


} // namespace Gdk


