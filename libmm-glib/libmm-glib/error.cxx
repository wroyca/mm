// SPDX-License-Identifier: LGPL-2.1-or-later

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/wrap.hxx>
#include <libmm-glib/wrap_init.hxx>
#include <map>

namespace
{

  using ThrowFuncTable = std::map<GQuark, Glib::Error::ThrowFunc>;

  ThrowFuncTable* throw_func_table = nullptr;

} // namespace

namespace Glib
{

  Error::Error ()
    : gobject_ (nullptr)
  {
  }

  Error::Error (const GQuark error_domain,
                const int error_code,
                const ustring& message)
    : gobject_ (
          g_error_new_literal (error_domain, error_code, message.c_str ()))
  {
  }

  Error::Error (GError* gobject, const bool take_copy)
    : gobject_ (take_copy && gobject ? g_error_copy (gobject) : gobject)
  {
  }

  Error::Error (const Error& other)
    : std::exception (other),
      gobject_ (other.gobject_ ? g_error_copy (other.gobject_) : nullptr)
  {
  }

  auto
  Error::operator= (const Error& other) -> Error&
  {
    if (gobject_ != other.gobject_)
    {
      if (gobject_)
      {
        g_error_free (gobject_);
        gobject_ = nullptr;
      }
      if (other.gobject_)
      {
        gobject_ = g_error_copy (other.gobject_);
      }
    }
    return *this;
  }

  Error::~Error () noexcept
  {
    if (gobject_)
      g_error_free (gobject_);
  }

  Error::operator bool () const
  {
    return gobject_ != nullptr;
  }

  auto
  Error::domain () const -> GQuark
  {
    g_return_val_if_fail (gobject_ != nullptr, 0);

    return gobject_->domain;
  }

  auto
  Error::code () const -> int
  {
    g_return_val_if_fail (gobject_ != nullptr, -1);

    return gobject_->code;
  }

  auto
  Error::what () const noexcept -> const char*
  {
    g_return_val_if_fail (gobject_ != nullptr, "");
    g_return_val_if_fail (gobject_->message != nullptr, "");

    return gobject_->message;
  }

  auto
  Error::matches (const GQuark error_domain, const int error_code) const -> bool
  {
    return g_error_matches (gobject_, error_domain, error_code);
  }

  auto
  Error::gobj () -> GError*
  {
    return gobject_;
  }

  auto
  Error::gobj () const -> const GError*
  {
    return gobject_;
  }

  auto
  Error::propagate (GError** dest) -> void
  {
    g_propagate_error (dest, gobject_);
    gobject_ = nullptr;
  }

  auto
  Error::register_init () -> void
  {
    if (!throw_func_table)
    {
      throw_func_table = new ThrowFuncTable ();
      wrap_register_init ();
      wrap_init ();
    }
  }

  auto
  Error::register_cleanup () -> void
  {
    if (throw_func_table)
    {
      delete throw_func_table;
      throw_func_table = nullptr;
    }
  }

  auto
  Error::register_domain (const GQuark error_domain, const ThrowFunc throw_func) -> void
  {
    g_assert (throw_func_table != nullptr);

    (*throw_func_table)[error_domain] = throw_func;
  }

  auto
  Error::throw_exception (GError* gobject) -> void
  {
    g_assert (gobject != nullptr);

    if (!throw_func_table)
      register_init ();

    if (const ThrowFunc throw_func = (*throw_func_table)[gobject->domain])
    {
      (*throw_func) (gobject);
      g_assert_not_reached ();
    }

    g_warning (
        "Glib::Error::throw_exception():\n  "
        "unknown error domain '%s': throwing generic Glib::Error exception\n",
        gobject->domain ? g_quark_to_string (gobject->domain) : "(null)");

    throw Error (gobject);
  }

  auto
  Value<Error>::value_type () -> GType
  {
    return g_error_get_type ();
  }

  auto
  Value<Error>::set (const CppType& data) -> void
  {
    set_boxed (data.gobj ());
  }

  auto
  Value<Error>::get () const -> CppType
  {
    return Error (static_cast<CType> (get_boxed ()), true);
  }

} // namespace Glib
