// SPDX-License-Identifier: LGPL-2.1-or-later

#include <clocale>
#include <libmm/glib/error.hxx>
#include <libmm/glib/init.hxx>
#include <locale>
#include <stdexcept>

namespace
{
  bool init_to_users_preferred_locale = true;

}

namespace Glib
{
  auto
  set_init_to_users_preferred_locale (const bool state) -> void
  {
    init_to_users_preferred_locale = state;
  }

  auto
  get_init_to_users_preferred_locale () -> bool
  {
    return init_to_users_preferred_locale;
  }

  auto
  init () -> void
  {
    static bool is_initialized = false;

    if (is_initialized)
      return;

    if (init_to_users_preferred_locale)
    {
      try
      {
        std::locale::global (std::locale (""));
      }
      catch (const std::runtime_error& ex)
      {
        g_warning (
            "Can't set the global locale to the user's preferred locale.\n"
            "   %s\n   The environment variable LANG may be wrong.\n",
            ex.what ());
      }
    }
    else
    {
      try
      {
        std::locale::global (std::locale (std::setlocale (LC_ALL, nullptr)));
      }
      catch (const std::runtime_error& ex)
      {
        g_warning ("Can't make the global C++ locale equal to the C locale.\n"
                   "   %s\n   C locale = %s\n",
                   ex.what (),
                   std::setlocale (LC_ALL, nullptr));
      }
    }

    Error::register_init ();

    is_initialized = true;
  }

} // namespace Glib
