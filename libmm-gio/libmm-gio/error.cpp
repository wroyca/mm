


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/error.hpp>
#include <libmm-gio/error_p.hpp>


/* Copyright (C) 2007 The giomm Development Team
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


Gio::Error::Error(const Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_IO_ERROR, error_code, error_message)
{}

Gio::Error::Error(GError* gobject)
:
  Glib::Error (gobject)
{}

auto Gio::Error::code() const -> Code
{
  return static_cast<Code>(Glib::Error::code());
}

auto Gio::Error::throw_func (GError *gobject) -> void
{
  throw Error(gobject);
}


Gio::ResolverError::ResolverError(const Code error_code, const Glib::ustring& error_message)
: Error(G_RESOLVER_ERROR, error_code, error_message)
{}

Gio::ResolverError::ResolverError(GError* gobject)
: Error(gobject)
{}

auto Gio::ResolverError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gio::ResolverError::throw_func (GError *gobject) -> void
{
  throw ResolverError(gobject);
}


Gio::TlsError::TlsError(const Code error_code, const Glib::ustring& error_message)
: Error(G_TLS_ERROR, error_code, error_message)
{}

Gio::TlsError::TlsError(GError* gobject)
: Error(gobject)
{}

auto Gio::TlsError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gio::TlsError::throw_func (GError *gobject) -> void
{
  throw TlsError(gobject);
}


