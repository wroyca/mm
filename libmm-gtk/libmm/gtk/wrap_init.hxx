// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WRAP_INIT_H
#define _GTKMM_WRAP_INIT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

namespace gtk
{

#define GDK_DISABLE_DEPRECATION_WARNINGS 1

  LIBMM_GTK_SYMEXPORT auto
  wrap_init () -> void;

} // namespace gtk

#endif
