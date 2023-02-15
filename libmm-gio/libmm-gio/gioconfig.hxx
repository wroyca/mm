// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONFIG_H
#define _GIOMM_CONFIG_H

#include <libmm-glib/mm-glibconfig.hxx>

#undef GIOMM_DISABLE_DEPRECATED

#undef GIOMM_MAJOR_VERSION

#undef GIOMM_MICRO_VERSION

#undef GIOMM_MINOR_VERSION

#undef GIOMM_STATIC_LIB

#if !defined(__CYGWIN__) && (defined(__MINGW32__) || defined(_MSC_VER)) && \
    !defined(GIOMM_STATIC_LIB)
  #define GIOMM_DLL 1
#endif

#ifdef GIOMM_DLL
  #if defined(GIOMM_BUILD)
    #define GIOMM_API __declspec (dllexport)
  #elif !defined(__GNUC__)
    #define GIOMM_API __declspec (dllimport)
  #else
    #define GIOMM_API
  #endif

#else
  #define GIOMM_API
#endif

#endif
