// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_DEBUG_H
#define _GLIBMM_DEBUG_H

#include <glib.h>
#include <libmm/glib/mm-glibconfig.hxx>

#ifdef GLIBMM_DEBUG_REFCOUNTING

  #ifdef __GNUC__
    #define GLIBMM_GNUC_PRETTY_FUNCTION __PRETTY_FUNCTION__
  #else
    #define GLIBMM_GNUC_PRETTY_FUNCTION ""
  #endif

  #define GLIBMM_DEBUG_REFERENCE(cppInstance, cInstance)                      \
    G_STMT_START                                                              \
    {                                                                         \
      void* const cppInstance__ = (void*) (cppInstance);                      \
      void* const cInstance__ = (void*) (cInstance);                          \
      g_log (G_LOG_DOMAIN,                                                    \
             G_LOG_LEVEL_DEBUG,                                               \
             "file %s: line %d (%s):\n"                                       \
             "ref: C++ instance: %p; C instance: %p, ref_count = %u, type = " \
             "%s\n",                                                          \
             __FILE__,                                                        \
             __LINE__,                                                        \
             GLIBMM_GNUC_PRETTY_FUNCTION,                                     \
             cppInstance__,                                                   \
             cInstance__,                                                     \
             G_OBJECT (cInstance__)->ref_count,                               \
             G_OBJECT_TYPE_NAME (cInstance__));                               \
    }                                                                         \
    G_STMT_END

  #define GLIBMM_DEBUG_UNREFERENCE(cppInstance, cInstance)                    \
    G_STMT_START                                                              \
    {                                                                         \
      void* const cppInstance__ = (void*) (cppInstance);                      \
      void* const cInstance__ = (void*) (cInstance);                          \
      g_log (G_LOG_DOMAIN,                                                    \
             G_LOG_LEVEL_DEBUG,                                               \
             "file %s: line %d (%s):\n"                                       \
             "unref: C++ instance: %p; C instance: %p, ref_count = %u, type " \
             "= %s\n",                                                        \
             __FILE__,                                                        \
             __LINE__,                                                        \
             GLIBMM_GNUC_PRETTY_FUNCTION,                                     \
             cppInstance__,                                                   \
             cInstance__,                                                     \
             G_OBJECT (cInstance__)->ref_count,                               \
             G_OBJECT_TYPE_NAME (cInstance__));                               \
    }                                                                         \
    G_STMT_END

#else

  #define GLIBMM_DEBUG_REFERENCE(cppInstance, cInstance) \
    G_STMT_START                                         \
    {                                                    \
      (void) 0;                                          \
    }                                                    \
    G_STMT_END
  #define GLIBMM_DEBUG_UNREFERENCE(cppInstance, cInstance) \
    G_STMT_START                                           \
    {                                                      \
      (void) 0;                                            \
    }                                                      \
    G_STMT_END

#endif

#endif
