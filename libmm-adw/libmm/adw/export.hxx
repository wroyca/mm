// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#if defined(LIBMM_ADW_STATIC)
  #define LIBMM_ADW_SYMEXPORT
#elif defined(LIBMM_ADW_STATIC_BUILD)
  #define LIBMM_ADW_SYMEXPORT
#elif defined(LIBMM_ADW_SHARED)
  #ifdef _WIN32
    #define LIBMM_ADW_SYMEXPORT __declspec (dllimport)
  #else
    #define LIBMM_ADW_SYMEXPORT
  #endif
#elif defined(LIBMM_ADW_SHARED_BUILD)
  #ifdef _WIN32
    #define LIBMM_ADW_SYMEXPORT __declspec (dllexport)
  #else
    #define LIBMM_ADW_SYMEXPORT
  #endif
#else

  #define LIBMM_ADW_SYMEXPORT

#endif
