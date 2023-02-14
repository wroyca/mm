
#ifndef _GIOMM_DBUSERRORUTILS_H
#define _GIOMM_DBUSERRORUTILS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

namespace Glib
{

  class Error;

}

namespace Gio::DBus::ErrorUtils
{

  GIOMM_API
  auto
  is_remote_error (const Glib::Error& error) -> bool;

  GIOMM_API
  auto
  get_remote_error (const Glib::Error& error) -> Glib::ustring;

  GIOMM_API
  auto
  strip_remote_error (Glib::Error& error) -> bool;

} // namespace Gio::DBus::ErrorUtils

#endif
