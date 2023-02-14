// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_EXCEPTIONHANDLER_H
#define _GLIBMM_EXCEPTIONHANDLER_H

#include <libmm-glib/mm-glibconfig.hxx>
#include <sigc++/sigc++.h>

namespace Glib
{

  GLIBMM_API
  auto
  add_exception_handler (const sigc::slot<void ()>& slot) -> sigc::connection;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  GLIBMM_API
  void
  exception_handlers_invoke () noexcept;
#endif

} // namespace Glib

#endif
