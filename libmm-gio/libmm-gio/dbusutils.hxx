// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSUTILS_H
#define _GIOMM_DBUSUTILS_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

namespace Gio::DBus
{

  LIBMM_GIO_SYMEXPORT
  auto
  generate_guid () -> std::string;

  LIBMM_GIO_SYMEXPORT
  auto
  is_guid (const std::string& string) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  is_name (const Glib::ustring& string) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  is_unique_name (const Glib::ustring& string) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  is_member_name (const Glib::ustring& string) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  is_interface_name (const Glib::ustring& string) -> bool;

} // namespace Gio::DBus

#endif
