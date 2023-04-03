// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ERROR_H
#define _GIOMM_ERROR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/error.hxx>
#include <libmm/glib/interface.hxx>

#ifdef HOST_NOT_FOUND
  #define GIOMM_SAVED_HOST_NOT_FOUND HOST_NOT_FOUND
  #undef HOST_NOT_FOUND
#endif

namespace Gio
{

  class Error : public Glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      NOT_FOUND,
      EXISTS,
      IS_DIRECTORY,
      NOT_DIRECTORY,
      NOT_EMPTY,
      NOT_REGULAR_FILE,
      NOT_SYMBOLIC_LINK,
      NOT_MOUNTABLE_FILE,
      FILENAME_TOO_LONG,
      INVALID_FILENAME,
      TOO_MANY_LINKS,
      NO_SPACE,
      INVALID_ARGUMENT,
      PERMISSION_DENIED,
      NOT_SUPPORTED,
      NOT_MOUNTED,
      ALREADY_MOUNTED,
      CLOSED,
      CANCELLED,
      PENDING,
      READ_ONLY,
      CANT_CREATE_BACKUP,
      WRONG_ETAG,
      TIMED_OUT,
      WOULD_RECURSE,
      BUSY,
      WOULD_BLOCK,
      HOST_NOT_FOUND,
      HOST_WAS_NOT_FOUND = HOST_NOT_FOUND,
      WOULD_MERGE,
      FAILED_HANDLED,
      TOO_MANY_OPEN_FILES,
      NOT_INITIALIZED,
      ADDRESS_IN_USE,
      PARTIAL_INPUT,
      INVALID_DATA,
      DBUS_ERROR,
      HOST_UNREACHABLE,
      NETWORK_UNREACHABLE,
      CONNECTION_REFUSED,
      PROXY_FAILED,
      PROXY_AUTH_FAILED,
      PROXY_NEED_AUTH,
      PROXY_NOT_ALLOWED,
      BROKEN_PIPE,
      CONNECTION_CLOSED = BROKEN_PIPE,
      NOT_CONNECTED,
      MESSAGE_TOO_LARGE,
      NO_SUCH_DEVICE
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

  class ResolverError : public Glib::Error
  {
  public:
    enum Code
    {
      NOT_FOUND,
      TEMPORARY_FAILURE,
      INTERNAL
    };

    LIBMM_GIO_SYMEXPORT
    ResolverError (Code error_code, const Glib::ustring& error_message);
    LIBMM_GIO_SYMEXPORT explicit ResolverError (GError* gobject);
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

  class TlsError : public Glib::Error
  {
  public:
    enum Code
    {
      UNAVAILABLE,
      MISC,
      BAD_CERTIFICATE,
      NOT_TLS,
      HANDSHAKE,
      CERTIFICATE_REQUIRED,
      ENDOFFILE,
      INAPPROPRIATE_FALLBACK,
      BAD_CERTIFICATE_PASSWORD
    };

    LIBMM_GIO_SYMEXPORT
    TlsError (Code error_code, const Glib::ustring& error_message);
    LIBMM_GIO_SYMEXPORT explicit TlsError (GError* gobject);
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

} // namespace Gio

#ifdef GIOMM_SAVED_HOST_NOT_FOUND

  #define HOST_NOT_FOUND GIOMM_SAVED_HOST_NOT_FOUND
  #undef GIOMM_SAVED_HOST_NOT_FOUND
#endif

#endif
