// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_VERSION_H
#define _GTKMM_VERSION_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#ifdef DOXYGEN_SHOULD_SKIP_THIS
  #define GTKMM_MAJOR_VERSION
  #define GTKMM_MINOR_VERSION
  #define GTKMM_MICRO_VERSION
#endif

#define GTKMM_CHECK_VERSION(major, minor, micro)                        \
  (GTKMM_MAJOR_VERSION > (major) ||                                     \
   (GTKMM_MAJOR_VERSION == (major) && GTKMM_MINOR_VERSION > (minor)) || \
   (GTKMM_MAJOR_VERSION == (major) && GTKMM_MINOR_VERSION == (minor) && \
    GTKMM_MICRO_VERSION >= (micro)))

#endif
