// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_WRAP_INIT_H
#define _GDKMM_WRAP_INIT_H

#include <libmm-gdk/mm-gdkconfig.hxx>

namespace Gdk
{
  LIBMM_GDK_SYMEXPORT auto
  wrap_init () -> void;

}

#endif
