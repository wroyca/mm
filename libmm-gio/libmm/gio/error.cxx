// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/error.hxx>
#include <libmm/gio/error_p.hxx>

#include <gio/gio.h>

namespace gio
{

}

namespace
{
}

gio::Error::Error (const Code error_code, const glib::ustring& error_message)
  : glib::Error (G_IO_ERROR, error_code, error_message)
{
}

gio::Error::Error (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gio::Error::code () const -> Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gio::Error::throw_func (GError* gobject) -> void
{
  throw Error (gobject);
}

gio::ResolverError::ResolverError (const Code error_code,
                                   const glib::ustring& error_message)
  : Error (G_RESOLVER_ERROR, error_code, error_message)
{
}

gio::ResolverError::ResolverError (GError* gobject)
  : Error (gobject)
{
}

auto
gio::ResolverError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
gio::ResolverError::throw_func (GError* gobject) -> void
{
  throw ResolverError (gobject);
}

gio::TlsError::TlsError (const Code error_code,
                         const glib::ustring& error_message)
  : Error (G_TLS_ERROR, error_code, error_message)
{
}

gio::TlsError::TlsError (GError* gobject)
  : Error (gobject)
{
}

auto
gio::TlsError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
gio::TlsError::throw_func (GError* gobject) -> void
{
  throw TlsError (gobject);
}
