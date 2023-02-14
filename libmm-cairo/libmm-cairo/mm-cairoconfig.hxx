// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _CAIROMM_CONFIG_H
#define _CAIROMM_CONFIG_H

#define CAIROMM_EXCEPTIONS_ENABLED 1

#define CAIROMM_MAJOR_VERSION 1

#define CAIROMM_MINOR_VERSION 16

#define CAIROMM_MICRO_VERSION 2

#if !defined(__CYGWIN__) && (defined(__MINGW32__) || defined(_MSC_VER)) && \
    !defined(CAIROMM_STATIC_LIB)
  #define CAIROMM_DLL 1
#endif

#ifdef CAIROMM_DLL
  #if defined(CAIROMM_BUILD)
    #define CAIROMM_API __declspec (dllexport)
  #elif !defined(__GNUC__)
    #define CAIROMM_API __declspec (dllimport)
  #else
    #define CAIROMM_API
  #endif

#else
  #define CAIROMM_API
#endif

#endif
