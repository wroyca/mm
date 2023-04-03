// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VARIANT_DBUS_STRING_H
#define _GLIBMM_VARIANT_DBUS_STRING_H

#include <libmm/glib/ustring.hxx>

namespace Glib
{

  class DBusObjectPathString : public Glib::ustring
  {
  public:
    using Glib::ustring::ustring;
  };

  class DBusSignatureString : public Glib::ustring
  {
  public:
    using Glib::ustring::ustring;
  };

} // namespace Glib

#endif
