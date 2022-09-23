# NMake Makefile portion for enabling features for Windows builds

# These are the base minimum libraries required for building gjs.
BASE_INCLUDES =	/I$(PREFIX)\include

# Please do not change anything beneath this line unless maintaining the NMake Makefiles

CAIROMM_MAJOR_VERSION = 1
CAIROMM_MINOR_VERSION = 16

LIBSIGC_MAJOR_VERSION = 3
LIBSIGC_MINOR_VERSION = 0

!if "$(CFG)" == "debug" || "$(CFG)" == "Debug"
DEBUG_SUFFIX = -d
!else
DEBUG_SUFFIX =
!endif

# We build the resource module sources directly into the gjs DLL, not as a separate .lib,
# so that we don't have to worry about the Visual Studio linker dropping items during
# optimization

CAIROMM_BASE_CFLAGS =			\
	/D_CRT_SECURE_NO_WARNINGS	\
	/D_CRT_NONSTDC_NO_WARNINGS	\
	/I.. /I.\cairomm		\
	/D_USE_MATH_DEFINES		\
	/EHsc /utf-8	\
	/std:c++17

CAIROMM_EXTRA_INCLUDES =	\
	/I$(PREFIX)\include\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)	\
	/I$(PREFIX)\lib\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)\include	\
	/I$(PREFIX)\include

LIBCAIROMM_CFLAGS = /DCAIROMM_BUILD $(CAIROMM_BASE_CFLAGS) $(CAIROMM_EXTRA_INCLUDES)
CAIROMM_EX_CFLAGS = $(CAIROMM_BASE_CFLAGS) $(CAIROMM_EXTRA_INCLUDES)
CAIROMM_TEST_CFLAGS =	\
	$(CAIROMM_EX_CFLAGS)	\
	/DBOOST_TEST_MODULE=$(<B:test-=)	\
	/DPNG_STREAM_FILE=\"$(MAKEDIR:\=/)/../tests/png-stream-test.png\"	\
	/std:c++latest

CAIROMM_INT_SOURCES = $(cairomm_cc:/=\)
CAIROMM_INT_HDRS = $(cairomm_public_h:/=\)

# We build cairomm-vc$(VSVER_LIB)-$(CAIROMM_MAJOR_VERSION)_$(CAIROMM_MINOR_VERSION).dll or
#          cairomm-vc$(VSVER_LIB)-d-$(CAIROMM_MAJOR_VERSION)_$(CAIROMM_MINOR_VERSION).dll at least

!if $(VSVER) > 14 && "$(USE_COMPAT_LIBS)" != ""
VSVER_LIB = 150
MESON_VSVER_LIB =
!else
VSVER_LIB = $(PDBVER)$(VSVER_SUFFIX)
MESON_VSVER_LIB = -vc$(VSVER_LIB)
!endif

!ifdef USE_MESON_LIBS
LIBSIGC_LIBNAME = sigc-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)
CAIROMM_LIBNAME = cairomm$(MESON_VSVER_LIB)-$(CAIROMM_MAJOR_VERSION).$(CAIROMM_MINOR_VERSION)

CAIROMM_DLLNAME = $(CAIROMM_LIBNAME)-1
!else
LIBSIGC_LIBNAME = sigc-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(LIBSIGC_MAJOR_VERSION)_$(LIBSIGC_MINOR_VERSION)
CAIROMM_LIBNAME = cairomm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(CAIROMM_MAJOR_VERSION)_$(CAIROMM_MINOR_VERSION)

CAIROMM_DLLNAME = $(CAIROMM_LIBNAME)
!endif

LIBSIGC_LIB = $(LIBSIGC_LIBNAME).lib


CAIROMM_DLL = vs$(VSVER)\$(CFG)\$(PLAT)\$(CAIROMM_DLLNAME).dll
CAIROMM_LIB = vs$(VSVER)\$(CFG)\$(PLAT)\$(CAIROMM_LIBNAME).lib

CAIRO_LIB = cairo.lib

!ifdef BOOST_DLL
CAIROMM_EX_CFLAGS = $(CAIROMM_EX_CFLAGS) /DBOOST_ALL_DYN_LINK
!endif
