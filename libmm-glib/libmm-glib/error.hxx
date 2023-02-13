#ifndef _GLIBMM_ERROR_H
#define _GLIBMM_ERROR_H

/* Copyright 2002 The gtkmm Development Team
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

#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/value.hxx>
#include <glib.h>
#include <exception>

namespace Glib
{

class Error : public std::exception
{
public:
  GLIBMM_API Error();
  GLIBMM_API Error(GQuark error_domain, int error_code, const Glib::ustring& message);
  GLIBMM_API explicit Error(GError* gobject, bool take_copy = false);

  GLIBMM_API Error(const Error& other);
  GLIBMM_API auto operator=(const Error& other) -> Error&;

  GLIBMM_API ~Error() noexcept override;

  /** Test whether the %Error has an underlying instance.
   *
   * @newin{2,60}
   */
  GLIBMM_API explicit operator bool() const;

  GLIBMM_API auto domain() const -> GQuark;
  GLIBMM_API auto code() const -> int;
  GLIBMM_API auto what() const noexcept -> const char* override;

  GLIBMM_API auto matches(GQuark error_domain, int error_code) const -> bool;

  GLIBMM_API auto gobj() -> GError*;
  GLIBMM_API auto gobj() const -> const GError*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  GLIBMM_API void propagate(GError** dest);

  using ThrowFunc = void(*)(GError*);

  GLIBMM_API static void register_init();
  GLIBMM_API static void register_cleanup();
  GLIBMM_API static void register_domain(GQuark error_domain, ThrowFunc throw_func);

  GLIBMM_API static void throw_exception(GError* gobject) G_GNUC_NORETURN;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

protected:
  GError* gobject_;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// This is needed so Glib::Error can be used with
// Glib::Value and _WRAP_PROPERTY in Gtk::MediaStream.
template <>
class GLIBMM_API Value<Glib::Error> : public ValueBase_Boxed
{
public:
  using CppType = Glib::Error;
  using CType = GError*;

  static auto value_type() -> GType;

  void set(const CppType& data);
  auto get() const -> CppType;
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib

#endif /* _GLIBMM_ERROR_H */
