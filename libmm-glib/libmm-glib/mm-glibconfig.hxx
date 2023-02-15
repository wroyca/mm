
#ifndef _GLIBMM_CONFIG_H
#define _GLIBMM_CONFIG_H

#define GLIBMM_MAJOR_VERSION 2

#define GLIBMM_MINOR_VERSION 74

#define GLIBMM_MICRO_VERSION 0

#define GLIBMM_SIZEOF_WCHAR_T 4

#include <libmm-glib/export.hxx>

#ifdef _WIN32
  #if defined(_MSC_VER)
    #define GLIBMM_MSC   1
    #define GLIBMM_WIN32 1
    #define GLIBMM_DLL   1
  #elif defined(__CYGWIN__)
    #define GLIBMM_CONFIGURE 1
  #elif defined(__MINGW32__)
    #define GLIBMM_WIN32     1
    #define GLIBMM_CONFIGURE 1
  #else
    #error "Unknown architecture (send me gcc --dumpspecs or equiv)"
  #endif
#else
  #define GLIBMM_CONFIGURE 1
#endif

#ifdef GLIBMM_CONFIGURE

  #define GLIBMM_CAN_ASSIGN_NON_EXTERN_C_FUNCTIONS_TO_EXTERN_C_CALLBACKS 1

  #define GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION 1

  #define GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS 1

  #define GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS 1

  #define GLIBMM_HAVE_STD_ITERATOR_TRAITS 1

  #define GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS 1

  #define GLIBMM_HAVE_WIDE_STREAM 1

#endif

#ifdef GLIBMM_MSC
  #define GLIBMM_HAVE_STD_ITERATOR_TRAITS                                   1
  #define GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS                               1
  #define GLIBMM_HAVE_WIDE_STREAM                                           1
  #define GLIBMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS           1
  #define GLIBMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION 1
  #define GLIBMM_CAN_ASSIGN_NON_EXTERN_C_FUNCTIONS_TO_EXTERN_C_CALLBACKS    1
  #pragma warning(disable : 4786 4355 4800 4181)

  #if (_MSC_VER >= 1910)
    #define GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS 1
  #endif

#endif


#endif
