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
    GLIBMM_API
    Error ();
    GLIBMM_API
    Error (GQuark error_domain, int error_code, const Glib::ustring& message);
    GLIBMM_API explicit Error (GError* gobject, bool take_copy = false);

    GLIBMM_API
    Error (const Error& other);
    GLIBMM_API auto
    operator= (const Error& other) -> Error&;

    GLIBMM_API ~Error () noexcept override;

    GLIBMM_API explicit operator bool () const;

    GLIBMM_API auto
    domain () const -> GQuark;
    GLIBMM_API auto
    code () const -> int;
    GLIBMM_API auto
    what () const noexcept -> const char* override;

    GLIBMM_API auto
    matches (GQuark error_domain, int error_code) const -> bool;

    GLIBMM_API auto
    gobj () -> GError*;
    GLIBMM_API auto
    gobj () const -> const GError*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    GLIBMM_API auto
    propagate (GError** dest) -> void;

    using ThrowFunc = void (*) (GError*);

    GLIBMM_API static auto
    register_init () -> void;
    GLIBMM_API static auto
    register_cleanup () -> void;
    GLIBMM_API static auto
    register_domain (GQuark error_domain, ThrowFunc throw_func) -> void;

    GLIBMM_API static auto
    throw_exception (GError* gobject) -> void G_GNUC_NORETURN;

#endif

  protected:
    GError* gobject_;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <>
  class GLIBMM_API Value<Glib::Error> : public ValueBase_Boxed
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
