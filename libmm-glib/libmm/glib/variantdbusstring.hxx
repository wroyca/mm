// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VARIANT_DBUS_STRING_H
#define _GLIBMM_VARIANT_DBUS_STRING_H

#include <libmm/glib/ustring.hxx>

namespace glib
{

  class DBusObjectPathString : public glib::ustring
  {
  public:
    using glib::ustring::ustring;
  };

  class DBusSignatureString : public glib::ustring
  {
  public:
    using glib::ustring::ustring;
  };

} // namespace glib

#endif
