


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/enums.hpp>
#include <mm/gio/private/enums_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
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

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::DataStreamByteOrder>::value_type() -> GType
{
  return g_data_stream_byte_order_get_type();
}

// static
auto Glib::Value<Gio::DataStreamNewlineType>::value_type() -> GType
{
  return g_data_stream_newline_type_get_type();
}

// static
auto Glib::Value<Gio::SocketFamily>::value_type() -> GType
{
  return g_socket_family_get_type();
}

// static
auto Glib::Value<Gio::TlsAuthenticationMode>::value_type() -> GType
{
  return g_tls_authentication_mode_get_type();
}

// static
auto Glib::Value<Gio::TlsCertificateFlags>::value_type() -> GType
{
  return g_tls_certificate_flags_get_type();
}


