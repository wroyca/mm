#pragma once

#if defined(LIBMM_GLIB_STATIC)
  #define LIBMM_GLIB_SYMEXPORT
#elif defined(LIBMM_GLIB_STATIC_BUILD)
  #define LIBMM_GLIB_SYMEXPORT
#elif defined(LIBMM_GLIB_SHARED)
  #ifdef _WIN32
    #define LIBMM_GLIB_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_GLIB_SYMEXPORT
  #endif
#elif defined(LIBMM_GLIB_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_GLIB_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_GLIB_SYMEXPORT
  #endif
#else

  #define LIBMM_GLIB_SYMEXPORT

#endif
