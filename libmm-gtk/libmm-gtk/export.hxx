#pragma once

#if defined(LIBMM_GTK_STATIC)
  #define LIBMM_GTK_SYMEXPORT
#elif defined(LIBMM_GTK_STATIC_BUILD)
  #define LIBMM_GTK_SYMEXPORT
#elif defined(LIBMM_GTK_SHARED)
  #ifdef _WIN32
    #define LIBMM_GTK_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_GTK_SYMEXPORT
  #endif
#elif defined(LIBMM_GTK_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_GTK_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_GTK_SYMEXPORT
  #endif
#else

  #define LIBMM_GTK_SYMEXPORT

#endif
