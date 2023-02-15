// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbuserror.hxx>
#include <libmm-gio/dbuserror_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{
}

Gio::DBus::Error::Error (const Code error_code,
                         const Glib::ustring& error_message)
  : Glib::Error (G_DBUS_ERROR, error_code, error_message)
{
}

Gio::DBus::Error::Error (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gio::DBus::Error::code () const -> Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gio::DBus::Error::throw_func (GError* gobject) -> void
{
  throw Error (gobject);
}
