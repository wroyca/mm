// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/shell.hxx>
#include <libmm-glib/shell_p.hxx>

#include <libmm-glib/utility.hxx>

namespace Glib
{

  auto
  shell_parse_argv (const std::string& command_line) -> std::vector<std::string>
  {
    char** argv = nullptr;
    int argc = 0;
    GError* error = nullptr;

    g_shell_parse_argv (command_line.c_str (), &argc, &argv, &error);

    if (error)
      Error::throw_exception (error);

    return ArrayHandler<std::string>::array_to_vector (argv,
                                                       argc,
                                                       OWNERSHIP_DEEP);
  }

  auto
  shell_quote (const std::string& unquoted_string) -> std::string
  {
    const auto buf =
        make_unique_ptr_gfree (g_shell_quote (unquoted_string.c_str ()));
    return std::string (buf.get ());
  }

  auto
  shell_unquote (const std::string& quoted_string) -> std::string
  {
    GError* error = nullptr;
    char* const buf = g_shell_unquote (quoted_string.c_str (), &error);

    if (error)
      Error::throw_exception (error);

    return std::string (make_unique_ptr_gfree (buf).get ());
  }

} // namespace Glib

namespace
{
}

Glib::ShellError::ShellError (const Code error_code,
                              const ustring& error_message)
  : Error (G_SHELL_ERROR, error_code, error_message)
{
}

Glib::ShellError::ShellError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::ShellError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::ShellError::throw_func (GError* gobject) -> void
{
  throw ShellError (gobject);
}
