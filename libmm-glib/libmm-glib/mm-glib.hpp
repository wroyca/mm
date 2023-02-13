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
 * #include <libmm-glib/mm-glib.hpp>
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

#include <libmm-glib/mm-glibconfig.hpp>
//#include <libmm-glib/i18n.hpp> //This must be included by the application, after system headers such as
//<iostream>.

#include <libmm-glib/base64.hpp>
#ifndef GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
// wrap_init.cc includes this file after it has cleared G_GNUC_CONST.
#include <libmm-glib/binding.hpp>
#endif
#include <libmm-glib/bytearray.hpp>
#include <libmm-glib/bytes.hpp>
#include <libmm-glib/checksum.hpp>
#include <libmm-glib/class.hpp>
#include <libmm-glib/containerhandle_shared.hpp>
#include <libmm-glib/convert.hpp>
#include <libmm-glib/date.hpp>
#include <libmm-glib/datetime.hpp>
#include <libmm-glib/dispatcher.hpp>
#include <libmm-glib/enums.hpp>
#include <libmm-glib/environ.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-glib/fileutils.hpp>
#include <libmm-glib/interface.hpp>
#include <libmm-glib/iochannel.hpp>
#include <libmm-glib/init.hpp>
#include <libmm-glib/keyfile.hpp>
#include <libmm-glib/main.hpp>
#include <libmm-glib/markup.hpp>
#include <libmm-glib/miscutils.hpp>
#include <libmm-glib/module.hpp>
#include <libmm-glib/nodetree.hpp>
#include <libmm-glib/objectbase.hpp>
#include <libmm-glib/object.hpp>
#include <libmm-glib/optioncontext.hpp>
#include <libmm-glib/pattern.hpp>
#include <libmm-glib/property.hpp>
#include <libmm-glib/propertyproxy_base.hpp>
#include <libmm-glib/propertyproxy.hpp>
#include <libmm-glib/quark.hpp>
#include <libmm-glib/random.hpp>
#include <libmm-glib/regex.hpp>
#include <libmm-glib/refptr.hpp>
#include <libmm-glib/shell.hpp>
#include <libmm-glib/signalproxy_connectionnode.hpp>
#include <libmm-glib/signalproxy.hpp>
#include <libmm-glib/spawn.hpp>
#include <libmm-glib/stringutils.hpp>
#include <libmm-glib/timer.hpp>
#include <libmm-glib/timezone.hpp>
#include <libmm-glib/uriutils.hpp>
#include <libmm-glib/ustring.hpp>
#include <libmm-glib/value.hpp>
#include <libmm-glib/variant.hpp>
#include <libmm-glib/variantdict.hpp>
#include <libmm-glib/variantiter.hpp>
#include <libmm-glib/varianttype.hpp>
#include <libmm-glib/vectorutils.hpp>
#include <libmm-glib/wrap.hpp>

#endif /* _GLIBMM_H */
