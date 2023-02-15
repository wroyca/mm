// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_TIMER_H
#define _GLIBMM_TIMER_H

#include <libmm-glib/mm-glibconfig.hxx>

extern "C"
{
  using GTimer = struct _GTimer;
}

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT Timer
  {
  public:
    Timer ();
    ~Timer () noexcept;

    Timer (const Timer&) = delete;
    auto
    operator= (const Timer&) -> Timer& = delete;

    auto
    start () -> void;
    auto
    stop () -> void;
    auto
    reset () -> void;

    auto
    resume () -> void;

    auto
    elapsed () const -> double;

    auto
    elapsed (unsigned long& microseconds) const -> double;

    auto
    is_active () const -> bool;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    gobj () -> GTimer*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GTimer*
    {
      return gobject_;
    }
#endif

  private:
    GTimer* gobject_;
  };

  LIBMM_GLIB_SYMEXPORT auto
  usleep (unsigned long microseconds) -> void;

} // namespace Glib

#endif
