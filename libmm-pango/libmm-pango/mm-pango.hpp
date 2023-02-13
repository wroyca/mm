/* pangomm - a C++ wrapper for the GLib toolkit
 *
 * Copyright 2002 Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _PANGOMM_H
#define _PANGOMM_H

/** @mainpage pangomm Reference Manual
 *
 * @section description Description
 *
 * pangomm is the official C++ interface for the <a href="http://www.pango.org/">Pango</a> font layout library.
 * See, for instance, the Pango::Layout class.
 *
 * @section basics Basic usage
 *
 * Include the pangomm header:
 * @code
 * #include <pangomm.h>
 * @endcode
 * This includes every header installed by pangomm, so can slow down
 * compilation, but suffices for this simple example. Assuming that your
 * program source file is @c program.cc, compile it with:
 * @code
 * g++ program.cc -o program  `pkg-config --cflags --libs pangomm-2.48`
 * @endcode
 * If your version of g++ is not C++17-compliant by default,
 * add the @c -std=c++17 option.
 *
 * If you use <a href="https://mesonbuild.com/">Meson</a>, include the following
 * in @c meson.build:
 * @code
 * pangomm_dep = dependency('pangomm-2.48')
 * program_name = 'program'
 * cpp_sources = [ 'program.cc' ]
 * executable(program_name,
 *   cpp_sources,
 *   dependencies: [ pangomm_dep ]
 * )
 * @endcode
 *
 * Alternatively, if using autoconf, use the following in @c configure.ac:
 * @code
 * PKG_CHECK_MODULES([PANGOMM], [pangomm-2.48])
 * @endcode
 * Then use the generated @c PANGOMM_CFLAGS and @c PANGOMM_LIBS variables in
 * the project @c Makefile.am files. For example:
 * @code
 * program_CPPFLAGS = $(PANGOMM_CFLAGS)
 * program_LDADD = $(PANGOMM_LIBS)
 * @endcode
 */


#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/context.hxx>
#include <libmm-pango/coverage.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/fontface.hxx>
#include <libmm-pango/fontfamily.hxx>
#include <libmm-pango/font.hxx>
#include <libmm-pango/fontmap.hxx>
#include <libmm-pango/fontmetrics.hxx>
#include <libmm-pango/fontset.hxx>
#include <libmm-pango/layout.hxx>
#include <libmm-pango/layoutiter.hxx>
#include <libmm-pango/layoutline.hxx>
#include <libmm-pango/tabarray.hxx>

#endif /* _PANGOMM_H */