// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbuserrorutils.hxx>
#include <libmm/gio/dbuserrorutils_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/error.hxx>
#include <libmm/glib/utility.hxx>

namespace gio::DBus::ErrorUtils
{

  auto
  is_remote_error (const glib::Error& error) -> bool
  {
    return static_cast<bool> (g_dbus_error_is_remote_error (error.gobj ()));
  }

  auto
  get_remote_error (const glib::Error& error) -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_error_get_remote_error (error.gobj ()));
  }

  auto
  strip_remote_error (glib::Error& error) -> bool
  {
    return static_cast<bool> (g_dbus_error_strip_remote_error (error.gobj ()));
  }

} // namespace gio::DBus::ErrorUtils

namespace
{
}
