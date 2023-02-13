#ifndef _GLIBMM_TIMER_H
#define _GLIBMM_TIMER_H

/* timer.h
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

#include <mm/glib/mm-glibconfig.hpp>

extern "C" {
using GTimer = struct _GTimer;
}

namespace Glib
{

/** Portable stop watch interface.
 * This resembles a convenient and portable timer with microseconds resolution.
 */
class GLIBMM_API Timer
{
public:
  /** Create a new timer.
   * Also starts timing by calling start() implicitly.
   */
  Timer();
  ~Timer() noexcept;

  // not copyable
  Timer(const Timer&) = delete;
  auto operator=(const Timer&) -> Timer& = delete;

  void start();
  void stop();
  void reset();

  // Can't call it Timer::continue(). continue is a keyword in C and C++.
  /** Resumes a timer that has previously been stopped with stop().
   * stop() must be called before using this function.
   *
   * @newin{2,70]
   */
  void resume();

  /** Get the elapsed time.
   * @return The value in seconds.
   */
  auto elapsed() const -> double;

  /** Get the elapsed time.
   * @return The value in seconds.  Also fills @p microseconds
   * with the corresponding @htmlonly&micro;s@endhtmlonly value.
   */
  auto elapsed(unsigned long& microseconds) const -> double;

  /** Exposes whether the timer is currently active.
   *
   * @newin{2,70]
   * @return <tt>true</tt> if the timer is running, <tt>false</tt> otherwise.
   */
  auto is_active() const -> bool;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  auto gobj() -> GTimer* { return gobject_; }
  auto gobj() const -> const GTimer* { return gobject_; }
#endif

private:
  GTimer* gobject_;
};

/// Pauses the current thread for the given number of microseconds.
GLIBMM_API
void usleep(unsigned long microseconds);

} // namespace Glib

#endif /* _GLIBMM_TIMER_H */
