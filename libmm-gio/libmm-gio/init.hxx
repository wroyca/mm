// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INIT_H
#define _GIOMM_INIT_H

#include <libmm-gio/wrap_init.hxx>

namespace Gio
{
  LIBMM_GIO_SYMEXPORT auto
  init () -> void;

}

#endif
