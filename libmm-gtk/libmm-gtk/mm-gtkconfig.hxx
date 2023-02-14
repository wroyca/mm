#ifndef _GTKMM_CONFIG_H
#define _GTKMM_CONFIG_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#define GTKMM_MAJOR_VERSION 4

#define GTKMM_MINOR_VERSION 8

#define GTKMM_MICRO_VERSION 0

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
