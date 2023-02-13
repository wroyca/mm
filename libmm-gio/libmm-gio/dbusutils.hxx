
#ifndef _GIOMM_DBUSUTILS_H
#define _GIOMM_DBUSUTILS_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
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


namespace Gio::DBus
{

/** Generate a D-Bus GUID that can be used with e.g.
 * Gio::DBus::Connection::create().
 *
 * See the D-Bus specification regarding what strings are valid D-Bus GUID
 * (for example, D-Bus GUIDs are not RFC-4122 compliant).
 *
 * @return A valid D-Bus GUID.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto generate_guid() -> std::string;

/** Checks if @a string is a D-Bus GUID.
 *
 * See the D-Bus specification regarding what strings are valid D-Bus GUID
 * (for example, D-Bus GUIDs are not RFC-4122 compliant).
 *
 * @param string The string to check.
 * @return <tt>true</tt> if string is a guid, <tt>false</tt> otherwise.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto is_guid(const std::string& string) -> bool;

/** Checks if @a string is a valid D-Bus bus name (either unique or
 * well-known).
 *
 * @param string The string to check.
 * @return <tt>true</tt> if valid, <tt>false</tt> otherwise.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto is_name(const Glib::ustring& string) -> bool;

/** Checks if @a string is a valid D-Bus unique bus name.
 *
 * @param string The string to check.
 * @return <tt>true</tt> if valid, <tt>false</tt> otherwise.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto is_unique_name(const Glib::ustring& string) -> bool;

/** Checks if @a string is a valid D-Bus member (e.g. signal or method) name.
 *
 * @param string The string to check.
 * @return <tt>true</tt> if valid, <tt>false</tt> otherwise.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto is_member_name(const Glib::ustring& string) -> bool;

/** Checks if @a string is a valid D-Bus interface name.
 *
 * @param string The string to check.
 * @return <tt>true</tt> if valid, <tt>false</tt> otherwise.
 * @newin{2,28}
 * @ingroup DBus
 */
GIOMM_API
auto is_interface_name(const Glib::ustring& string) -> bool;

} // namespace Gio


#endif /* _GIOMM_DBUSUTILS_H */

