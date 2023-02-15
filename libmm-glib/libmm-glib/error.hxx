// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_ERROR_H
#define _GLIBMM_ERROR_H

#include <exception>
#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/value.hxx>

namespace Glib
{

  class Error : public std::exception
  {
  public:
    LIBMM_GLIB_SYMEXPORT
    Error ();
    LIBMM_GLIB_SYMEXPORT
    Error (GQuark error_domain, int error_code, const Glib::ustring& message);
    LIBMM_GLIB_SYMEXPORT explicit Error (GError* gobject, bool take_copy = false);

    LIBMM_GLIB_SYMEXPORT
    Error (const Error& other);
    LIBMM_GLIB_SYMEXPORT auto
    operator= (const Error& other) -> Error&;

    LIBMM_GLIB_SYMEXPORT ~Error () noexcept override;

    LIBMM_GLIB_SYMEXPORT explicit operator bool () const;

    LIBMM_GLIB_SYMEXPORT auto
    domain () const -> GQuark;
    LIBMM_GLIB_SYMEXPORT auto
    code () const -> int;
    LIBMM_GLIB_SYMEXPORT auto
    what () const noexcept -> const char* override;

    LIBMM_GLIB_SYMEXPORT auto
    matches (GQuark error_domain, int error_code) const -> bool;

    LIBMM_GLIB_SYMEXPORT auto
    gobj () -> GError*;
    LIBMM_GLIB_SYMEXPORT auto
    gobj () const -> const GError*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    LIBMM_GLIB_SYMEXPORT auto
    propagate (GError** dest) -> void;

    using ThrowFunc = void (*) (GError*);

    LIBMM_GLIB_SYMEXPORT static auto
    register_init () -> void;
    LIBMM_GLIB_SYMEXPORT static auto
    register_cleanup () -> void;
    LIBMM_GLIB_SYMEXPORT static auto
    register_domain (GQuark error_domain, ThrowFunc throw_func) -> void;

    LIBMM_GLIB_SYMEXPORT static auto
    throw_exception (GError* gobject) -> void G_GNUC_NORETURN;

#endif

  protected:
    GError* gobject_;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<Glib::Error> : public ValueBase_Boxed
  {
  public:
    using CppType = Glib::Error;
    using CType = GError*;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };
#endif

} // namespace Glib

#endif
