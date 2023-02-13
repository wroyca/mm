


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbuserror.hxx>
#include <libmm-gio/dbuserror_p.hxx>


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

#include <gio/gio.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


Gio::DBus::Error::Error(const Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_DBUS_ERROR, error_code, error_message)
{}

Gio::DBus::Error::Error(GError* gobject)
:
  Glib::Error (gobject)
{}

auto Gio::DBus::Error::code() const -> Code
{
  return static_cast<Code>(Glib::Error::code());
}

auto Gio::DBus::Error::throw_func (GError *gobject) -> void
{
  throw Error(gobject);
}


