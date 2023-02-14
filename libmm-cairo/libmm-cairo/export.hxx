#pragma once

#if defined(LIBMM_CAIRO_STATIC)
  #define LIBMM_CAIRO_SYMEXPORT
#elif defined(LIBMM_CAIRO_STATIC_BUILD)
  #define LIBMM_CAIRO_SYMEXPORT
#elif defined(LIBMM_CAIRO_SHARED)
  #ifdef _WIN32
    #define LIBMM_CAIRO_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_CAIRO_SYMEXPORT
  #endif
#elif defined(LIBMM_CAIRO_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_CAIRO_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_CAIRO_SYMEXPORT
  #endif
#else

  #define LIBMM_CAIRO_SYMEXPORT

#endif
