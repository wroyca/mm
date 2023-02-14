#pragma once

#if defined(LIBMM_GDK_STATIC)
  #define LIBMM_GDK_SYMEXPORT
#elif defined(LIBMM_GDK_STATIC_BUILD)
  #define LIBMM_GDK_SYMEXPORT
#elif defined(LIBMM_GDK_SHARED)
  #ifdef _WIN32
    #define LIBMM_GDK_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_GDK_SYMEXPORT
  #endif
#elif defined(LIBMM_GDK_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_GDK_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_GDK_SYMEXPORT
  #endif
#else

  #define LIBMM_GDK_SYMEXPORT

#endif
