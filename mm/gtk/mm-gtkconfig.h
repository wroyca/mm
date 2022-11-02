#ifndef _GTKMM_CONFIG_H
#define _GTKMM_CONFIG_H

#include <mm/gdk/mm-gdkconfig.h>

/* Define to omit deprecated API from gtkmm. */
/* #undef GTKMM_DISABLE_DEPRECATED */

/* Major version number of gtkmm. */
#define GTKMM_MAJOR_VERSION 4

/* Minor version number of gtkmm. */
#define GTKMM_MINOR_VERSION 8

/* Micro version number of gtkmm. */
#define GTKMM_MICRO_VERSION 0

/* Define when building gtkmm as a static library. */
/* #undef GTKMM_STATIC_LIB */

/* Enable DLL-specific stuff only when not building a static library */
#if !defined(__CYGWIN__) && defined(_WIN32) && !defined(GTKMM_STATIC_LIB)
# define GTKMM_DLL 1
#endif

#  define GTKMM_API __declspec(dllexport)


#endif /* !_GTKMM_CONFIG_H */
