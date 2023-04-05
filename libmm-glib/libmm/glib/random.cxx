// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

namespace glib
{

  Rand::Rand ()
    : gobject_ (g_rand_new ())
  {
  }

  Rand::Rand (const guint32 seed)
    : gobject_ (g_rand_new_with_seed (seed))
  {
  }

  Rand::~Rand () noexcept
  {
    g_rand_free (gobject_);
  }

  auto
  Rand::set_seed (const guint32 seed) -> void
  {
    g_rand_set_seed (gobject_, seed);
  }

  auto
  Rand::get_bool () -> bool
  {
    return g_rand_boolean (gobject_);
  }

  auto
  Rand::get_int () -> guint32
  {
    return g_rand_int (gobject_);
  }

  auto
  Rand::get_int_range (const gint32 begin, const gint32 end) -> gint32
  {
    return g_rand_int_range (gobject_, begin, end);
  }

  auto
  Rand::get_double () -> double
  {
    return g_rand_double (gobject_);
  }

  auto
  Rand::get_double_range (const double begin, const double end) -> double
  {
    return g_rand_double_range (gobject_, begin, end);
  }

} // namespace glib
