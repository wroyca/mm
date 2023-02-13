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
 * #include <mm/glib/mm-glib.hpp>
 * #include <mm/gio.h>
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

#include <mm/glib/mm-glibconfig.hpp>
//#include <mm/glib/i18n.hpp> //This must be included by the application, after system headers such as
//<iostream>.

#include <mm/glib/base64.hpp>
#ifndef GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
// wrap_init.cc includes this file after it has cleared G_GNUC_CONST.
#include <mm/glib/binding.hpp>
#endif
#include <mm/glib/bytearray.hpp>
#include <mm/glib/bytes.hpp>
#include <mm/glib/checksum.hpp>
#include <mm/glib/class.hpp>
#include <mm/glib/containerhandle_shared.hpp>
#include <mm/glib/convert.hpp>
#include <mm/glib/date.hpp>
#include <mm/glib/datetime.hpp>
#include <mm/glib/dispatcher.hpp>
#include <mm/glib/enums.hpp>
#include <mm/glib/environ.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/exceptionhandler.hpp>
#include <mm/glib/fileutils.hpp>
#include <mm/glib/interface.hpp>
#include <mm/glib/iochannel.hpp>
#include <mm/glib/init.hpp>
#include <mm/glib/keyfile.hpp>
#include <mm/glib/main.hpp>
#include <mm/glib/markup.hpp>
#include <mm/glib/miscutils.hpp>
#include <mm/glib/module.hpp>
#include <mm/glib/nodetree.hpp>
#include <mm/glib/objectbase.hpp>
#include <mm/glib/object.hpp>
#include <mm/glib/optioncontext.hpp>
#include <mm/glib/pattern.hpp>
#include <mm/glib/property.hpp>
#include <mm/glib/propertyproxy_base.hpp>
#include <mm/glib/propertyproxy.hpp>
#include <mm/glib/quark.hpp>
#include <mm/glib/random.hpp>
#include <mm/glib/regex.hpp>
#include <mm/glib/refptr.hpp>
#include <mm/glib/shell.hpp>
#include <mm/glib/signalproxy_connectionnode.hpp>
#include <mm/glib/signalproxy.hpp>
#include <mm/glib/spawn.hpp>
#include <mm/glib/stringutils.hpp>
#include <mm/glib/timer.hpp>
#include <mm/glib/timezone.hpp>
#include <mm/glib/uriutils.hpp>
#include <mm/glib/ustring.hpp>
#include <mm/glib/value.hpp>
#include <mm/glib/variant.hpp>
#include <mm/glib/variantdict.hpp>
#include <mm/glib/variantiter.hpp>
#include <mm/glib/varianttype.hpp>
#include <mm/glib/vectorutils.hpp>
#include <mm/glib/wrap.hpp>

#endif /* _GLIBMM_H */
