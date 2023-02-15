// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONFIG_H
#define _GDKMM_CONFIG_H

#include <libmm-pango/mm-pangoconfig.hxx>

#undef GDKMM_DISABLE_DEPRECATED

#undef GDKMM_MAJOR_VERSION

#undef GDKMM_MICRO_VERSION

#undef GDKMM_MINOR_VERSION

#if !defined(__CYGWIN__) && defined(_WIN32) && !defined(GDKMM_STATIC_LIB)
  #define GDKMM_DLL 1
#endif

#ifdef GDKMM_DLL
  #if defined(GDKMM_BUILD) || defined(GTKMM_BUILD)
    #define GDKMM_API __declspec (dllexport)
  #elif !defined(__GNUC__)
    #define GDKMM_API __declspec (dllimport)
  #else
    #define GDKMM_API
  #endif
#else

  #define GDKMM_API
#endif

#endif
