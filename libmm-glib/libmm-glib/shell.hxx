// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_SHELL_H
#define _GLIBMM_SHELL_H

#include <glib.h>
#include <libmm-glib/error.hxx>
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

    GLIBMM_API
    ShellError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit ShellError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GLIBMM_API auto
    wrap_init () -> void;

#endif
  };

  GLIBMM_API
  auto
  shell_parse_argv (const std::string& command_line) -> std::vector<std::string>;

  GLIBMM_API
  auto
  shell_quote (const std::string& unquoted_string) -> std::string;

  GLIBMM_API
  auto
  shell_unquote (const std::string& quoted_string) -> std::string;

} // namespace Glib

#endif
