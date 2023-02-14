// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WRAP_INIT_H
#define _GTKMM_WRAP_INIT_H

#include <libmm-gtk/mm-gtkconfig.hxx>

namespace Gtk
{

#define GDK_DISABLE_DEPRECATION_WARNINGS 1

  GTKMM_API void
  wrap_init ();

} // namespace Gtk

#endif
