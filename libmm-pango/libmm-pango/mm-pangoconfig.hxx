
#ifndef PANGOMM_PANGOMMCONFIG_H_INCLUDED
#define PANGOMM_PANGOMMCONFIG_H_INCLUDED

#define PANGOMM_MAJOR_VERSION 2

#define PANGOMM_MINOR_VERSION 50

#define PANGOMM_MICRO_VERSION 1

#if !defined(__CYGWIN__) && (defined(__MINGW32__) || defined(_MSC_VER)) && \
    !defined(PANGOMM_STATIC_LIB)
  #define PANGOMM_DLL 1
#endif

#ifdef PANGOMM_DLL
  #if defined(PANGOMM_BUILD)
    #define PANGOMM_API __declspec (dllexport)
  #elif !defined(__GNUC__)
    #define PANGOMM_API __declspec (dllimport)
  #else
    #define PANGOMM_API
  #endif
#else

  #define PANGOMM_API
#endif

#endif
