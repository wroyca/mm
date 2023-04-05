// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/init.hxx>
#include <libmm/pango/wrap_init.hxx>

namespace pango
{

  auto
  init () -> void
  {
    glib::init ();
    wrap_init ();
  }

} // namespace pango
