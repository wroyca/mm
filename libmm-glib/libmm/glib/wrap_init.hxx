// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_WRAP_INIT_H
#define _GLIBMM_WRAP_INIT_H

#include <libmm/glib/error.hxx>

namespace Glib
{
  LIBMM_GLIB_SYMEXPORT auto
  wrap_init () -> void;

}

#endif
