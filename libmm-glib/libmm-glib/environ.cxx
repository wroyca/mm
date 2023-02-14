// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/environ.hxx>
#include <libmm-glib/vectorutils.hxx>

namespace Glib
{

  Environ::Environ ()
    : envp (g_get_environ (), &g_strfreev)
  {
  }

  Environ::Environ (const std::vector<std::string>& env_vec)
    : envp (g_new (char*, env_vec.size () + 1), &g_strfreev)
  {
    for (unsigned int i = 0; i < env_vec.size (); ++i)
      envp.get ()[i] = g_strdup (env_vec[i].c_str ());
    envp.get ()[env_vec.size ()] = nullptr;
  }

  auto
  Environ::get (const StdStringView variable) const -> std::optional<std::string>
  {
    const char* value = g_environ_getenv (envp.get (), variable.c_str ());
    if (value)
      return std::optional<std::string> (std::in_place, value);
    return {};
  }

  auto
  Environ::set (const StdStringView variable,
                const StdStringView value,
                const bool overwrite) -> void
  {
    envp.reset (g_environ_setenv (envp.release (),
                                  variable.c_str (),
                                  value.c_str (),
                                  overwrite));
  }

  auto
  Environ::unset (const StdStringView variable) -> void
  {
    envp.reset (g_environ_unsetenv (envp.release (), variable.c_str ()));
  }

  auto
  Environ::to_vector () const -> std::vector<std::string>
  {
    return ArrayHandler<std::string>::array_to_vector (envp.get (),
                                                       OWNERSHIP_NONE);
  }

} // namespace Glib
