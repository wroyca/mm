// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_PRIORITIES_H
#define _GLIBMM_PRIORITIES_H

namespace glib
{

  enum
  {
    PRIORITY_HIGH = -100,

    PRIORITY_DEFAULT = 0,

    PRIORITY_HIGH_IDLE = 100,

    PRIORITY_DEFAULT_IDLE = 200,

    PRIORITY_LOW = 300
  };

} // namespace glib

#endif
