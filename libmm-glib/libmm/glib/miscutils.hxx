// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MISCUTILS_H
#define _GLIBMM_MISCUTILS_H

#include <libmm/glib/ustring.hxx>
#include <libmm/glib/utility.hxx>
#include <vector>

namespace Glib
{

  enum class UserDirectory
  {
    DESKTOP,
    DOCUMENTS,
    DOWNLOAD,
    MUSIC,
    PICTURES,
    PUBLIC_SHARE,
    TEMPLATES,
    VIDEOS,
    N_DIRECTORIES
  };

  enum class FormatSizeFlags
  {
    DEFAULT = 0x0,
    LONG_FORMAT = 1 << 0,
    IEC_UNITS = 1 << 1,
    BITS = 1 << 2,
    ONLY_VALUE = 1 << 3,
    ONLY_UNIT = 1 << 4
  };

  inline auto
  operator| (FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  {
    return static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  {
    return static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FormatSizeFlags lhs, FormatSizeFlags rhs) -> FormatSizeFlags
  {
    return static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FormatSizeFlags flags) -> FormatSizeFlags
  {
    return static_cast<FormatSizeFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  {
    return (lhs = static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  {
    return (lhs = static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FormatSizeFlags& lhs, FormatSizeFlags rhs) -> FormatSizeFlags&
  {
    return (lhs = static_cast<FormatSizeFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }

  LIBMM_GLIB_SYMEXPORT
  auto
  get_application_name () -> Glib::ustring;

  LIBMM_GLIB_SYMEXPORT auto
  set_application_name (UStringView application_name) -> void;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_prgname () -> std::string;

  LIBMM_GLIB_SYMEXPORT auto
  set_prgname (StdStringView prgname) -> void;

  LIBMM_GLIB_SYMEXPORT
  auto
  getenv (StdStringView variable, bool& found) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  getenv (StdStringView variable) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  setenv (StdStringView variable, StdStringView value, bool overwrite = true) -> bool;

  LIBMM_GLIB_SYMEXPORT auto
  unsetenv (StdStringView variable) -> void;

  LIBMM_GLIB_SYMEXPORT
  auto
  listenv () -> std::vector<std::string>;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_name () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_real_name () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_host_name () -> Glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_home_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_tmp_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_current_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_special_dir (UserDirectory directory) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_data_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_config_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_system_data_dirs () -> std::vector<std::string>;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_system_config_dirs () -> std::vector<std::string>;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_cache_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_user_runtime_dir () -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  path_is_absolute (StdStringView filename) -> bool;

  LIBMM_GLIB_SYMEXPORT
  auto
  path_skip_root (StdStringView filename) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  path_get_basename (StdStringView filename) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  path_get_dirname (StdStringView filename) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  canonicalize_filename (StdStringView filename,
                         StdStringView relative_to = nullptr) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  build_filename (const std::vector<std::string>& elements) -> std::string;

  template <typename... Strings>
  auto
  build_filename (const Strings&... strings) -> std::string
  {
    return Glib::convert_return_gchar_ptr_to_stdstring (
        g_build_filename (StdStringView (strings).c_str ()..., nullptr));
  }

  LIBMM_GLIB_SYMEXPORT
  auto
  build_path (const std::string& separator,
              const std::vector<std::string>& elements) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  find_program_in_path (StdStringView program) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  format_size (guint64 size, FormatSizeFlags flags = FormatSizeFlags::DEFAULT) -> Glib::ustring;

} // namespace Glib

#endif
