// SPDX-License-Identifier: LGPL-2.0-or-later

#pragma once

#if defined(LIBMM_PANGO_STATIC)
  #define LIBMM_PANGO_SYMEXPORT
#elif defined(LIBMM_PANGO_STATIC_BUILD)
  #define LIBMM_PANGO_SYMEXPORT
#elif defined(LIBMM_PANGO_SHARED)
  #ifdef _WIN32
    #define LIBMM_PANGO_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_PANGO_SYMEXPORT
  #endif
#elif defined(LIBMM_PANGO_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_PANGO_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_PANGO_SYMEXPORT
  #endif
#else

  #define LIBMM_PANGO_SYMEXPORT

#endif
