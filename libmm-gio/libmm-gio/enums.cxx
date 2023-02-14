

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/enums.hxx>
#include <libmm-gio/enums_p.hxx>

namespace
{
}

auto
Glib::Value<Gio::DataStreamByteOrder>::value_type () -> GType
{
  return g_data_stream_byte_order_get_type ();
}

auto
Glib::Value<Gio::DataStreamNewlineType>::value_type () -> GType
{
  return g_data_stream_newline_type_get_type ();
}

auto
Glib::Value<Gio::SocketFamily>::value_type () -> GType
{
  return g_socket_family_get_type ();
}

auto
Glib::Value<Gio::TlsAuthenticationMode>::value_type () -> GType
{
  return g_tls_authentication_mode_get_type ();
}

auto
Glib::Value<Gio::TlsCertificateFlags>::value_type () -> GType
{
  return g_tls_certificate_flags_get_type ();
}
