
#ifndef _GLIBMM_SHELL_H
#define _GLIBMM_SHELL_H


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


#include <libmm-glib/error.hpp>
#include <glib.h>
#include <string>
#include <vector>

namespace Glib
{

/** @defgroup ShellUtils Shell-related Utilities
 * Shell-like command line handling.
 * @{
 */

/**  %Exception class for shell utility errors.
 */
class ShellError : public Glib::Error
{
public:
  /**  @var Code BAD_QUOTING
   * Mismatched or otherwise mangled quoting.
   *
   *  @var Code EMPTY_STRING
   * String to be parsed was empty.
   *
   *  @var Code FAILED
   * Some other error.
   *
   *  @enum Code
   *
   * %Error codes returned by shell functions.
   */
  enum Code
  {
    BAD_QUOTING,
    EMPTY_STRING,
    FAILED
  };

  GLIBMM_API ShellError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit ShellError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/** Parses a command line into an argument vector, in much the same way the
 * shell would, but without many of the expansions the shell would perform
 * (variable expansion, globs, operators, filename expansion, etc.\ are not
 * supported).  The results are defined to be the same as those you would
 * get from a UNIX98 /bin/sh, as long as the input contains none of the
 * unsupported shell expansions.  If the input does contain such expansions,
 * they are passed through literally.
 * @param command_line Command line to parse.
 * @return Array of args (The generic ArrayHandle will be implicitly
 * converted to any STL compatible container type).
 * @throw Glib::ShellError
 */
GLIBMM_API
auto shell_parse_argv(const std::string& command_line) -> std::vector<std::string>;

/** Quotes a string so that the shell (/bin/sh) will interpret the quoted
 * string to mean @a unquoted_string.  If you pass a filename to the shell,
 * for example, you should first quote it with this function.  The quoting
 * style used is undefined (single or double quotes may be used).
 * @param unquoted_string A literal string.
 * @return A quoted string.
 */
GLIBMM_API
auto shell_quote(const std::string& unquoted_string) -> std::string;

/** Unquotes a string as the shell (/bin/sh) would.  Only handles quotes; if
 * a string contains file globs, arithmetic operators, variables, backticks,
 * redirections, or other special-to-the-shell features, the result will be
 * different from the result a real shell would produce (the variables,
 * backticks, etc. will be passed through literally instead of being expanded).
 * This function is guaranteed to succeed if applied to the result of
 * shell_quote().  If it fails, it throws a Glib::ShellError exception.  The
 * @a quoted_string need not actually contain quoted or escaped text;
 * shell_unquote() simply goes through the string and unquotes/unescapes
 * anything that the shell would.  Both single and double quotes are handled,
 * as are escapes including escaped newlines.
 *
 * Shell quoting rules are a bit strange.  Single quotes preserve the literal
 * string exactly.  Escape sequences are not allowed; not even <tt>\\'</tt> --
 * if you want a <tt>'</tt> in the quoted text, you have to do something like
 * <tt>'foo'\\''bar'</tt>.  Double quotes allow <tt>$</tt>, <tt>`</tt>,
 * <tt>"</tt>, <tt>\\</tt>, and newline to be escaped with backslash.
 * Otherwise double quotes preserve things literally.
 *
 * @param quoted_string Shell-quoted string.
 * @return An unquoted string.
 * @throw Glib::ShellError
 */
GLIBMM_API
auto shell_unquote(const std::string& quoted_string) -> std::string;

/** @} group ShellUtils */

} // namespace Glib


#endif /* _GLIBMM_SHELL_H */

