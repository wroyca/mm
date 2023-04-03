// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/error.hxx>
#include <libmm/gio/error_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{
}

Gio::Error::Error (const Code error_code, const Glib::ustring& error_message)
  : Glib::Error (G_IO_ERROR, error_code, error_message)
{
}

Gio::Error::Error (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gio::Error::code () const -> Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gio::Error::throw_func (GError* gobject) -> void
{
  throw Error (gobject);
}

Gio::ResolverError::ResolverError (const Code error_code,
                                   const Glib::ustring& error_message)
  : Error (G_RESOLVER_ERROR, error_code, error_message)
{
}

Gio::ResolverError::ResolverError (GError* gobject)
  : Error (gobject)
{
}

auto
Gio::ResolverError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gio::ResolverError::throw_func (GError* gobject) -> void
{
  throw ResolverError (gobject);
}

Gio::TlsError::TlsError (const Code error_code,
                         const Glib::ustring& error_message)
  : Error (G_TLS_ERROR, error_code, error_message)
{
}

Gio::TlsError::TlsError (GError* gobject)
  : Error (gobject)
{
}

auto
Gio::TlsError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gio::TlsError::throw_func (GError* gobject) -> void
{
  throw TlsError (gobject);
}
