// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSERRORUTILS_H
#define _GIOMM_DBUSERRORUTILS_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

namespace Glib
{

  class Error;

}

namespace Gio::DBus::ErrorUtils
{

  LIBMM_GIO_SYMEXPORT
  auto
  is_remote_error (const Glib::Error& error) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  get_remote_error (const Glib::Error& error) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  strip_remote_error (Glib::Error& error) -> bool;

} // namespace Gio::DBus::ErrorUtils

#endif
