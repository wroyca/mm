/* timer.cc
 *
 * Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/mm-glib.h>
#include <glib.h>

namespace Glib
{

Timer::Timer() : gobject_(g_timer_new())
{
}

Timer::~Timer() noexcept
{
  g_timer_destroy(gobject_);
}

void
Timer::start()
{
  g_timer_start(gobject_);
}

void
Timer::stop()
{
  g_timer_stop(gobject_);
}

void
Timer::reset()
{
  g_timer_reset(gobject_);
}

void
Timer::resume()
{
  g_timer_continue(gobject_);
}

auto
Timer::elapsed() const -> double
{
  return g_timer_elapsed(gobject_, nullptr);
}

auto
Timer::elapsed(unsigned long& microseconds) const -> double
{
  return g_timer_elapsed(gobject_, &microseconds);
}

auto
Timer::is_active() const -> bool
{
  return g_timer_is_active(gobject_);
}

void
usleep(unsigned long microseconds)
{
  g_usleep(microseconds);
}

} // namespace Glib