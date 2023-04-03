// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSERROR_H
#define _GIOMM_DBUSERROR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/error.hxx>

namespace Gio::DBus
{

  class Error : public Glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      NO_MEMORY,
      SERVICE_UNKNOWN,
      NAME_HAS_NO_OWNER,
      NO_REPLY,
      IO_ERROR,
      BAD_ADDRESS,
      NOT_SUPPORTED,
      LIMITS_EXCEEDED,
      ACCESS_DENIED,
      AUTH_FAILED,
      NO_SERVER,
      TIMEOUT,
      NO_NETWORK,
      ADDRESS_IN_USE,
      DISCONNECTED,
      INVALID_ARGS,
      FILE_NOT_FOUND,
      FILE_EXISTS,
      UNKNOWN_METHOD,
      TIMED_OUT,
      MATCH_RULE_NOT_FOUND,
      MATCH_RULE_INVALID,
      SPAWN_EXEC_FAILED,
      SPAWN_FORK_FAILED,
      SPAWN_CHILD_EXITED,
      SPAWN_CHILD_SIGNALED,
      SPAWN_FAILED,
      SPAWN_SETUP_FAILED,
      SPAWN_CONFIG_INVALID,
      SPAWN_SERVICE_INVALID,
      SPAWN_SERVICE_NOT_FOUND,
      SPAWN_PERMISSIONS_INVALID,
      SPAWN_FILE_INVALID,
      SPAWN_NO_MEMORY,
      UNIX_PROCESS_ID_UNKNOWN,
      INVALID_SIGNATURE,
      INVALID_FILE_CONTENT,
      SELINUX_SECURITY_CONTEXT_UNKNOWN,
      ADT_AUDIT_DATA_UNKNOWN,
      OBJECT_PATH_IN_USE,
      UNKNOWN_OBJECT,
      UNKNOWN_INTERFACE,
      UNKNOWN_PROPERTY,
      PROPERTY_READ_ONLY
    };

    LIBMM_GIO_SYMEXPORT
    Error (Code error_code, const Glib::ustring& error_message);
    LIBMM_GIO_SYMEXPORT explicit Error (GError* gobject);
    LIBMM_GIO_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GIO_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GIO_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace Gio::DBus

#endif
