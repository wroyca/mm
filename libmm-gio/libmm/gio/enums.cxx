// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/enums.hxx>
#include <libmm/gio/enums_p.hxx>

namespace
{
}

auto
glib::Value<gio::DataStreamByteOrder>::value_type () -> GType
{
  return g_data_stream_byte_order_get_type ();
}

auto
glib::Value<gio::DataStreamNewlineType>::value_type () -> GType
{
  return g_data_stream_newline_type_get_type ();
}

auto
glib::Value<gio::SocketFamily>::value_type () -> GType
{
  return g_socket_family_get_type ();
}

auto
glib::Value<gio::TlsAuthenticationMode>::value_type () -> GType
{
  return g_tls_authentication_mode_get_type ();
}

auto
glib::Value<gio::TlsCertificateFlags>::value_type () -> GType
{
  return g_tls_certificate_flags_get_type ();
}
