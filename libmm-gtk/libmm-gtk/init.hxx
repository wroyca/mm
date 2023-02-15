// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_INIT_H
#define _GTKMM_INIT_H

#include <libmm-gtk/mm-gtkconfig.hxx>

namespace Gtk
{
  GTKMM_API auto
  init_gtkmm_internals () -> void;

} // namespace Gtk

#endif
