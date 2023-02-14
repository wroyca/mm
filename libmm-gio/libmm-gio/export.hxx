#pragma once

#if defined(LIBMM_GIO_STATIC)
  #define LIBMM_GIO_SYMEXPORT
#elif defined(LIBMM_GIO_STATIC_BUILD)
  #define LIBMM_GIO_SYMEXPORT
#elif defined(LIBMM_GIO_SHARED)
  #ifdef _WIN32
    #define LIBMM_GIO_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_GIO_SYMEXPORT
  #endif
#elif defined(LIBMM_GIO_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_GIO_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_GIO_SYMEXPORT
  #endif
#else

  #define LIBMM_GIO_SYMEXPORT

#endif
