// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_UTILITY_H
#define _GLIBMM_UTILITY_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>
#include <memory>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

  template <typename T>
  auto
  make_unique_ptr_gfree (T* p) -> std::unique_ptr<T[], decltype (&g_free)>
  {
    return std::unique_ptr<T[], decltype (&g_free)> (p, &g_free);
  }

  inline auto
  convert_const_gchar_ptr_to_ustring (const char* str) -> Glib::ustring
  {
    return (str) ? Glib::ustring (str) : Glib::ustring ();
  }

  inline auto
  convert_const_gchar_ptr_to_stdstring (const char* str) -> std::string
  {
    return (str) ? std::string (str) : std::string ();
  }

  inline auto
  convert_return_gchar_ptr_to_ustring (char* str) -> Glib::ustring
  {
    return (str) ? Glib::ustring (Glib::make_unique_ptr_gfree (str).get ()) :
                   Glib::ustring ();
  }

  inline auto
  convert_return_gchar_ptr_to_stdstring (char* str) -> std::string
  {
    return (str) ? std::string (Glib::make_unique_ptr_gfree (str).get ()) :
                   std::string ();
  }

  template <typename T>
  inline auto
  c_str_or_nullptr (const T& str) -> const char*
  {
    return str.empty () ? nullptr : str.c_str ();
  }

  GLIBMM_API
  void
  append_canonical_typename (std::string& dest, const char* type_name);

  template <typename T>
  void
  destroy_notify_delete (void* data)
  {
    delete static_cast<T*> (data);
  }

  template <typename T_out, typename T_in>
  inline auto
  function_pointer_cast (T_in in) -> T_out
  {
    return reinterpret_cast<T_out> (reinterpret_cast<void (*) ()> (in));
  }

} // namespace Glib

#endif

#endif
