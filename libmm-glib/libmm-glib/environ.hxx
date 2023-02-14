// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_ENVIRON_H
#define _GLIBMM_ENVIRON_H

#include <libmm-glib/ustring.hxx>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace Glib
{

  class Environ
  {
  public:
    GLIBMM_API
    Environ ();

    GLIBMM_API explicit Environ (const std::vector<std::string>& env_vec);

    GLIBMM_API auto
    get (StdStringView variable) const -> std::optional<std::string>;

    GLIBMM_API auto
    operator[] (StdStringView variable) const -> std::optional<std::string>
    {
      return get (variable);
    }

    GLIBMM_API void
    set (StdStringView variable, StdStringView value, bool overwrite = true);

    GLIBMM_API void
    unset (StdStringView variable);

    GLIBMM_API auto
    to_vector () const -> std::vector<std::string>;

  private:
    std::unique_ptr<char*, decltype (&g_strfreev)> envp;
  };

} // namespace Glib

#endif
