// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONFIG_H
#define _GTKMM_CONFIG_H

#include <libmm-gdk/mm-gdk.hxx>

#undef GTKMM_DISABLE_DEPRECATED

#undef GTKMM_MAJOR_VERSION

#undef GTKMM_MICRO_VERSION

#undef GTKMM_MINOR_VERSION

#undef GTKMM_STATIC_LIB

#if !defined(__CYGWIN__) && defined(_WIN32) && !defined(GTKMM_STATIC_LIB)
  #define GTKMM_DLL 1
#endif

#ifdef GTKMM_DLL
  #if defined(GDKMM_BUILD) || defined(GTKMM_BUILD)
    #define GTKMM_API __declspec (dllexport)
  #elif !defined(__GNUC__)
    #define GTKMM_API __declspec (dllimport)
  #else
    #define GTKMM_API
  #endif
#else

  #define GTKMM_API
#endif

#endif
