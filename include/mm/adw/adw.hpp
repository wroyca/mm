// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

/* Define to omit deprecated API from Libadwaita. */
/* #undef MM_ADW_DISABLE_DEPRECATED */

/* Major version number of Libadwaita. */
#define MM_ADW_MAJOR_VERSION 1

/* Minor version number of Libadwaita. */
#define MM_ADW_MINOR_VERSION 2

/* Micro version number of Libadwaita. */
#define MM_ADW_MICRO_VERSION 0

/* Define when building Libadwaita as a static library. */
/* #undef MM_ADW_STATIC_LIB */

/* Enable DLL-specific stuff only when not building a static library */
#if !defined(__CYGWIN__) && defined(_WIN32) && !defined(MM_ADW_STATIC_LIB)
# define MM_ADW_DLL 1
#endif

#ifdef MM_ADW_DLL
# if defined (GDKMM_BUILD) || defined(MM_ADW_BUILD)
#  define MM_ADW_API __declspec(dllexport)
# elif !defined (__GNUC__)
#  define MM_ADW_API __declspec(dllimport)
# else /* don't dllimport classes/methods on GCC/MinGW */
#  define MM_ADW_API
# endif
#else
/* Build a static library or a non-native Windows library */
# define MM_ADW_API
#endif /* MM_ADW_DLL */
