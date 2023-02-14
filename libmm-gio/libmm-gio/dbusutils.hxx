
#ifndef _GIOMM_DBUSUTILS_H
#define _GIOMM_DBUSUTILS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

namespace Gio::DBus
{

  GIOMM_API
  auto
  generate_guid () -> std::string;

  GIOMM_API
  auto
  is_guid (const std::string& string) -> bool;

  GIOMM_API
  auto
  is_name (const Glib::ustring& string) -> bool;

  GIOMM_API
  auto
  is_unique_name (const Glib::ustring& string) -> bool;

  GIOMM_API
  auto
  is_member_name (const Glib::ustring& string) -> bool;

  GIOMM_API
  auto
  is_interface_name (const Glib::ustring& string) -> bool;

} // namespace Gio::DBus

#endif
