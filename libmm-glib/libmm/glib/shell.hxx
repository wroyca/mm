// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_SHELL_H
#define _GLIBMM_SHELL_H

#include <glib.h>
#include <libmm/glib/error.hxx>
#include <string>
#include <vector>

namespace Glib
{

  class ShellError : public Glib::Error
  {
  public:
    enum Code
    {
      BAD_QUOTING,
      EMPTY_STRING,
      FAILED
    };

    LIBMM_GLIB_SYMEXPORT
    ShellError (Code error_code, const Glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit ShellError (GError* gobject);
    LIBMM_GLIB_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GLIB_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GLIB_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

  LIBMM_GLIB_SYMEXPORT
  auto
  shell_parse_argv (const std::string& command_line) -> std::vector<std::string>;

  LIBMM_GLIB_SYMEXPORT
  auto
  shell_quote (const std::string& unquoted_string) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  shell_unquote (const std::string& quoted_string) -> std::string;

} // namespace Glib

#endif
