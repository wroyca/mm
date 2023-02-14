

#include <glib.h>
#include <libmm-glib/mm-glib.hxx>

namespace Glib
{

  Timer::Timer ()
    : gobject_ (g_timer_new ())
  {
  }

  Timer::~Timer () noexcept
  {
    g_timer_destroy (gobject_);
  }

  auto
  Timer::start () -> void
  {
    g_timer_start (gobject_);
  }

  auto
  Timer::stop () -> void
  {
    g_timer_stop (gobject_);
  }

  auto
  Timer::reset () -> void
  {
    g_timer_reset (gobject_);
  }

  auto
  Timer::resume () -> void
  {
    g_timer_continue (gobject_);
  }

  auto
  Timer::elapsed () const -> double
  {
    return g_timer_elapsed (gobject_, nullptr);
  }

  auto
  Timer::elapsed (unsigned long& microseconds) const -> double
  {
    return g_timer_elapsed (gobject_, &microseconds);
  }

  auto
  Timer::is_active () const -> bool
  {
    return g_timer_is_active (gobject_);
  }

  auto
  usleep (const unsigned long microseconds) -> void
  {
    g_usleep (microseconds);
  }

} // namespace Glib
