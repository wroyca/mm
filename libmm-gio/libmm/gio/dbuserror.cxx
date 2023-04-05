// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbuserror.hxx>
#include <libmm/gio/dbuserror_p.hxx>

#include <gio/gio.h>

namespace gio
{

}

namespace
{
}

gio::DBus::Error::Error (const Code error_code,
                         const glib::ustring& error_message)
  : glib::Error (G_DBUS_ERROR, error_code, error_message)
{
}

gio::DBus::Error::Error (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gio::DBus::Error::code () const -> Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gio::DBus::Error::throw_func (GError* gobject) -> void
{
  throw Error (gobject);
}
