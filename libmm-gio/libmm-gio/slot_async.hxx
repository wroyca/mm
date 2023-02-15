// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SLOT_ASYNC_H
#define _GIOMM_SLOT_ASYNC_H

#include <gio/gio.h>
#include <libmm-gio/gioconfig.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
  GIOMM_API auto
  SignalProxy_async_callback (GObject*, GAsyncResult* res, void* data) -> void;

}

#endif

#endif
