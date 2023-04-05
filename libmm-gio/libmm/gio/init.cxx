// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gio/init.hxx>
#include <libmm/glib/init.hxx>

namespace gio
{

  auto
  init () -> void
  {
    static bool s_init = false;
    if (!s_init)
    {
      glib::init ();
      wrap_init ();
      s_init = true;
    }
  }

} // namespace gio
