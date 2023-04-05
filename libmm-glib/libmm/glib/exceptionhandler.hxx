// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_EXCEPTIONHANDLER_H
#define _GLIBMM_EXCEPTIONHANDLER_H

#include <libmm/glib/mm-glibconfig.hxx>
#include <sigc++/sigc++.h>

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  add_exception_handler (const sigc::slot<void ()>& slot) -> sigc::connection;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  LIBMM_GLIB_SYMEXPORT auto
  exception_handlers_invoke () noexcept -> void;
#endif

} // namespace glib

#endif
