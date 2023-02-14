#ifndef _GLIBMM_PRIORITIES_H
#define _GLIBMM_PRIORITIES_H

namespace Glib
{

  enum
  {
    PRIORITY_HIGH = -100,

    PRIORITY_DEFAULT = 0,

    PRIORITY_HIGH_IDLE = 100,

    PRIORITY_DEFAULT_IDLE = 200,

    PRIORITY_LOW = 300
  };

} // namespace Glib

#endif
