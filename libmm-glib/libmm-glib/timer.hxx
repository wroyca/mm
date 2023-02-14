#ifndef _GLIBMM_TIMER_H
#define _GLIBMM_TIMER_H

#include <libmm-glib/mm-glibconfig.hxx>

extern "C"
{
  using GTimer = struct _GTimer;
}

namespace Glib
{

  class GLIBMM_API Timer
  {
  public:
    Timer ();
    ~Timer () noexcept;

    Timer (const Timer&) = delete;
    auto
    operator= (const Timer&) -> Timer& = delete;

    void
    start ();
    void
    stop ();
    void
    reset ();

    void
    resume ();

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

  GLIBMM_API
  void
  usleep (unsigned long microseconds);

} // namespace Glib

#endif
