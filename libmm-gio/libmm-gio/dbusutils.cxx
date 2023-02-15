// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusutils.hxx>
#include <libmm-gio/dbusutils_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/utility.hxx>

namespace Gio::DBus
{

  auto
  generate_guid () -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (g_dbus_generate_guid ());
  }

  auto
  is_guid (const std::string& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_guid (string.c_str ()));
  }

  auto
  is_name (const Glib::ustring& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_name (string.c_str ()));
  }

  auto
  is_unique_name (const Glib::ustring& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_unique_name (string.c_str ()));
  }

  auto
  is_member_name (const Glib::ustring& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_member_name (string.c_str ()));
  }

  auto
  is_interface_name (const Glib::ustring& string) -> bool
  {
    return static_cast<bool> (g_dbus_is_interface_name (string.c_str ()));
  }

} // namespace Gio::DBus

namespace
{
}
