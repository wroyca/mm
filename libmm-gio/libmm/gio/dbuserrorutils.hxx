// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSERRORUTILS_H
#define _GIOMM_DBUSERRORUTILS_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

namespace glib
{

  class Error;

}

namespace gio::DBus::ErrorUtils
{

  LIBMM_GIO_SYMEXPORT
  auto
  is_remote_error (const glib::Error& error) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  get_remote_error (const glib::Error& error) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  strip_remote_error (glib::Error& error) -> bool;

} // namespace gio::DBus::ErrorUtils

#endif
