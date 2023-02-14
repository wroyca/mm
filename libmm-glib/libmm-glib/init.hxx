// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_INIT_H
#define _GLIBMM_INIT_H

#include <libmm-glib/mm-glibconfig.hxx>

namespace Glib
{

  GLIBMM_API
  void
  init ();

  GLIBMM_API
  void
  set_init_to_users_preferred_locale (bool state = true);

  GLIBMM_API
  auto
  get_init_to_users_preferred_locale () -> bool;

} // namespace Glib

#endif
