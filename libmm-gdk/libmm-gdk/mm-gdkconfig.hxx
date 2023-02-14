// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONFIG_H
#define _GDKMM_CONFIG_H

#define GDKMM_MAJOR_VERSION 4

#define GDKMM_MINOR_VERSION 8

#define GDKMM_MICRO_VERSION 0

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
