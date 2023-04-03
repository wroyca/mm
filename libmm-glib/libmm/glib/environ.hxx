// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_ENVIRON_H
#define _GLIBMM_ENVIRON_H

#include <libmm/glib/ustring.hxx>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace Glib
{

  class Environ
  {
  public:
    LIBMM_GLIB_SYMEXPORT
    Environ ();

    LIBMM_GLIB_SYMEXPORT explicit Environ (const std::vector<std::string>& env_vec);

    LIBMM_GLIB_SYMEXPORT auto
    get (StdStringView variable) const -> std::optional<std::string>;

    LIBMM_GLIB_SYMEXPORT auto
    operator[] (StdStringView variable) const -> std::optional<std::string>
    {
      return get (variable);
    }

    LIBMM_GLIB_SYMEXPORT auto
    set (StdStringView variable, StdStringView value, bool overwrite = true)
        -> void;

    LIBMM_GLIB_SYMEXPORT auto
    unset (StdStringView variable) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    to_vector () const -> std::vector<std::string>;

  private:
    std::unique_ptr<char*, decltype (&g_strfreev)> envp;
  };

} // namespace Glib

#endif
