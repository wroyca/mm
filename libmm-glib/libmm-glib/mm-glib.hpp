/* glibmm - a C++ wrapper for the GLib toolkit
 *
 * Copyright 2002 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GLIBMM_H
#define _GLIBMM_H

/** @mainpage glibmm Reference Manual
 *
 * @section description Description
 *
 * glibmm is the official C++ interface for the popular cross-platform library %Glib.
 * It provides non-UI API that is not available in standard C++ and makes it
 * possible for gtkmm to wrap GObject-based APIs.
 * See also the <a href="https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/">
 * Programming with gtkmm</a> book for a tutorial on programming with gtkmm and
 * glibmm.
 *
 * @section features Features
 *
 * - Glib::ustring: A UTF-8 string class that can be used interchangably with std::string.
 *   Plus @ref StringUtils
 * - Glib::RefPtr: A reference-counting smartpointer, for use with Glib::ObjectBase or similar
 * - @ref CharsetConv
 * - Glib::Regex: Regular expression string matching.
 * - Glib::KeyFile: Parsing and writing of key files (similar to .ini files)
 * - Glib::Checksum
 * - Glib::Date, Glib::DateTime, Glib::Timer
 * - Glib::Dispatcher: Inter-thread communication
 * - @ref FileUtils and @ref UriUtils
 * - @ref MainLoop
 * - @ref Spawn
 * - @ref MiscUtils
 *
 * giomm (part of the glibmm project) also contains:
 * - Asynchronous IO. See Gio::File and the @ref Streams.
 * - @ref NetworkIO
 * - @ref DBus
 * - Gio::Settings for application settings.
 *
 * @section basics Basic Usage
 *
 * Include the glibmm header, plus giomm if necessary:
 * @code
 * #include <libmm-glib/mm-glib.hxx>
 * #include <libmm-gio.h>
 * @endcode
 * (You may include individual headers, such as @c glibmm/ustring.h instead.)
 *
 * If your  source file is @c program.cc, you can compile it with:
 * @code
 * g++ program.cc -o program  `pkg-config --cflags --libs glibmm-2.68 giomm-2.68`
 * @endcode
 * If your version of g++ is not C++17-compliant by default,
 * add the @c -std=c++17 option.
 *
 * If you use <a href="https://mesonbuild.com/">Meson</a>, include the following
 * in @c meson.build:
 * @code
 * glibmm_dep = dependency('glibmm-2.68')
 * giomm_dep = dependency('giomm-2.68')
 * program_name = 'program'
 * cpp_sources = [ 'program.cc' ]
 * executable(program_name,
 *   cpp_sources,
 *   dependencies: [ glibmm_dep, giomm_dep ]
 * )
 * @endcode
 *
 * Alternatively, if using autoconf, use the following in @c configure.ac:
 * @code
 * PKG_CHECK_MODULES([GLIBMM], [glibmm-2.68 giomm-2.68])
 * @endcode
 * Then use the generated @c GLIBMM_CFLAGS and @c GLIBMM_LIBS variables in the
 * project Makefile.am files. For example:
 * @code
 * program_CPPFLAGS = $(GLIBMM_CFLAGS)
 * program_LDADD = $(GLIBMM_LIBS)
 * @endcode
 */

#include <libmm-glib/mm-glibconfig.hxx>
//#include <libmm-glib/i18n.hxx> //This must be included by the application, after system headers such as
//<iostream>.

#include <libmm-glib/base64.hxx>
#ifndef GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
// wrap_init.cc includes this file after it has cleared G_GNUC_CONST.
#include <libmm-glib/binding.hxx>
#endif
#include <libmm-glib/bytearray.hxx>
#include <libmm-glib/bytes.hxx>
#include <libmm-glib/checksum.hxx>
#include <libmm-glib/class.hxx>
#include <libmm-glib/containerhandle_shared.hxx>
#include <libmm-glib/convert.hxx>
#include <libmm-glib/date.hxx>
#include <libmm-glib/datetime.hxx>
#include <libmm-glib/dispatcher.hxx>
#include <libmm-glib/enums.hxx>
#include <libmm-glib/environ.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/fileutils.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/iochannel.hxx>
#include <libmm-glib/init.hxx>
#include <libmm-glib/keyfile.hxx>
#include <libmm-glib/main.hxx>
#include <libmm-glib/markup.hxx>
#include <libmm-glib/miscutils.hxx>
#include <libmm-glib/module.hxx>
#include <libmm-glib/nodetree.hxx>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/optioncontext.hxx>
#include <libmm-glib/pattern.hxx>
#include <libmm-glib/property.hxx>
#include <libmm-glib/propertyproxy_base.hxx>
#include <libmm-glib/propertyproxy.hxx>
#include <libmm-glib/quark.hxx>
#include <libmm-glib/random.hxx>
#include <libmm-glib/regex.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/shell.hxx>
#include <libmm-glib/signalproxy_connectionnode.hxx>
#include <libmm-glib/signalproxy.hxx>
#include <libmm-glib/spawn.hxx>
#include <libmm-glib/stringutils.hxx>
#include <libmm-glib/timer.hxx>
#include <libmm-glib/timezone.hxx>
#include <libmm-glib/uriutils.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/variantdict.hxx>
#include <libmm-glib/variantiter.hxx>
#include <libmm-glib/varianttype.hxx>
#include <libmm-glib/vectorutils.hxx>
#include <libmm-glib/wrap.hxx>

#endif /* _GLIBMM_H */
