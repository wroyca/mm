


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/shell.hpp>
#include <libmm-glib/shell_p.hpp>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <libmm-glib/utility.hpp>

namespace Glib
{

/**** shell utility functions **********************************************/

auto
shell_parse_argv(const std::string& command_line) -> std::vector<std::string>
{
  char** argv = nullptr;
  int argc = 0;
  GError* error = nullptr;

  g_shell_parse_argv(command_line.c_str(), &argc, &argv, &error);

  if (error)
    Error::throw_exception(error);

  return ArrayHandler<std::string>::array_to_vector(argv, argc, OWNERSHIP_DEEP);
}

auto
shell_quote(const std::string& unquoted_string) -> std::string
{
  const auto buf = make_unique_ptr_gfree(g_shell_quote(unquoted_string.c_str()));
  return std::string(buf.get());
}

auto
shell_unquote(const std::string& quoted_string) -> std::string
{
  GError* error = nullptr;
  char* const buf = g_shell_unquote(quoted_string.c_str(), &error);

  if (error)
    Error::throw_exception(error);

  return std::string(make_unique_ptr_gfree(buf).get());
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::ShellError::ShellError(const Code error_code, const ustring & error_message)
: Error(G_SHELL_ERROR, error_code, error_message)
{}

Glib::ShellError::ShellError(GError* gobject)
: Error(gobject)
{}

auto Glib::ShellError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Glib::ShellError::throw_func (GError *gobject) -> void
{
  throw ShellError(gobject);
}


