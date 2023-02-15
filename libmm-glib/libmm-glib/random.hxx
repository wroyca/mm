// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_RANDOM_H
#define _GLIBMM_RANDOM_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>

extern "C"
{
  using GRand = struct _GRand;
}

namespace Glib
{

  class GLIBMM_API Rand
  {
  public:
    Rand ();
    explicit Rand (guint32 seed);
    ~Rand () noexcept;

    Rand (const Rand&) = delete;
    auto
    operator= (const Rand&) -> Rand& = delete;

    auto
    set_seed (guint32 seed) -> void;

    auto
    get_bool () -> bool;

    auto
    get_int () -> guint32;
    auto
    get_int_range (gint32 begin, gint32 end) -> gint32;

    auto
    get_double () -> double;
    auto
    get_double_range (double begin, double end) -> double;

    auto
    gobj () -> GRand*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GRand*
    {
      return gobject_;
    }

  private:
    GRand* gobject_;
  };

} // namespace Glib

#endif
