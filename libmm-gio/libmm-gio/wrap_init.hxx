// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_WRAP_INIT_H
#define _GIOMM_WRAP_INIT_H

#include <libmm-gio/mm-gioconfig.hxx>

namespace Gio
{
  LIBMM_GIO_SYMEXPORT auto
  wrap_init () -> void;
}

#endif
