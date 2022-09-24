/* error.cc
 *
 * Copyright 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/glib/mm-glibconfig.h>
#include <mm/glib/error.h>
#include <mm/glib/wrap.h>
#include <mm/glib/wrap_init.h>
#include <glib.h>
#include <map>

namespace
{

using ThrowFuncTable = std::map<GQuark, Glib::Error::ThrowFunc>;

ThrowFuncTable* throw_func_table = nullptr;

} // anonymous namespace

namespace Glib
{

Error::Error() : gobject_(nullptr)
{
}

Error::Error(GQuark error_domain, int error_code, const Glib::ustring& message)
: gobject_(g_error_new_literal(error_domain, error_code, message.c_str()))
{
}

Error::Error(GError* gobject, bool take_copy)
: gobject_((take_copy && gobject) ? g_error_copy(gobject) : gobject)
{
}

Error::Error(const Error& other)
: std::exception(other), gobject_((other.gobject_) ? g_error_copy(other.gobject_) : nullptr)
{
}

auto
Error::operator=(const Error& other) -> Error&
{
  if (gobject_ != other.gobject_)
  {
    if (gobject_)
    {
      g_error_free(gobject_);
      gobject_ = nullptr;
    }
    if (other.gobject_)
    {
      gobject_ = g_error_copy(other.gobject_);
    }
  }
  return *this;
}

Error::~Error() noexcept
{
  if (gobject_)
    g_error_free(gobject_);
}

Error::operator bool() const
{
  return gobject_ != nullptr;
}

auto
Error::domain() const -> GQuark
{
  g_return_val_if_fail(gobject_ != nullptr, 0);

  return gobject_->domain;
}

auto
Error::code() const -> int
{
  g_return_val_if_fail(gobject_ != nullptr, -1);

  return gobject_->code;
}

auto
Error::what() const noexcept -> const char*
{
  g_return_val_if_fail(gobject_ != nullptr, "");
  g_return_val_if_fail(gobject_->message != nullptr, "");

  return gobject_->message;
}

auto
Error::matches(GQuark error_domain, int error_code) const -> bool
{
  return g_error_matches(gobject_, error_domain, error_code);
}

auto
Error::gobj() -> GError*
{
  return gobject_;
}

auto
Error::gobj() const -> const GError*
{
  return gobject_;
}

void
Error::propagate(GError** dest)
{
  g_propagate_error(dest, gobject_);
  gobject_ = nullptr;
}

// static
void
Error::register_init()
{
  if (!throw_func_table)
  {
    throw_func_table = new ThrowFuncTable();
    Glib::wrap_register_init();
    Glib::wrap_init(); // make sure that at least the Glib exceptions are registered
  }
}

// static
void
Error::register_cleanup()
{
  if (throw_func_table)
  {
    delete throw_func_table;
    throw_func_table = nullptr;
  }
}

// static
void
Error::register_domain(GQuark error_domain, Error::ThrowFunc throw_func)
{
  g_assert(throw_func_table != nullptr);

  (*throw_func_table)[error_domain] = throw_func;
}

// static, noreturn
void
Error::throw_exception(GError* gobject)
{
  g_assert(gobject != nullptr);

  // Just in case Gtk::Main hasn't been instantiated yet.
  if (!throw_func_table)
    register_init();

  if (const ThrowFunc throw_func = (*throw_func_table)[gobject->domain])
  {
    (*throw_func)(gobject);
    g_assert_not_reached();
  }

  g_warning("Glib::Error::throw_exception():\n  "
            "unknown error domain '%s': throwing generic Glib::Error exception\n",
    (gobject->domain) ? g_quark_to_string(gobject->domain) : "(null)");

  // Doesn't copy, because error-returning functions return a newly allocated GError for us.
  throw Glib::Error(gobject);
}

// Glib::Value<Glib::Error>
auto Value<Error>::value_type() -> GType
{
  return g_error_get_type();
}

void Value<Error>::set(const CppType& data)
{
  set_boxed(data.gobj());
}

auto Value<Error>::get() const -> Value<Error>::CppType
{
  return Glib::Error(static_cast<CType>(get_boxed()), true);
}

} // namespace Glib
