


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/miscutils.hpp>
#include <libmm-glib/miscutils_p.hpp>


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

#include <cstddef>
#include <cstring>

#include <libmm-glib/miscutils.hpp>
#include <libmm-glib/utility.hpp>
#include <glib.h>

namespace Glib
{

auto
get_application_name() -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_get_application_name());
}

auto set_application_name (
  const UStringView application_name) -> void
{
  g_set_application_name(application_name.c_str());
}

auto
get_prgname() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_prgname());
}

auto set_prgname (
  const StdStringView prgname) -> void
{
  g_set_prgname(prgname.c_str());
}

auto
getenv(
  const StdStringView variable, bool& found) -> std::string
{
  const char* const value = g_getenv(variable.c_str());
  found = value != nullptr;
  return convert_const_gchar_ptr_to_stdstring(value);
}

auto
getenv(
  const StdStringView variable) -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_getenv(variable.c_str()));
}

auto
setenv(
  const StdStringView variable, const StdStringView value, const bool overwrite) -> bool
{
  return g_setenv(variable.c_str(), value.c_str(), overwrite);
}

auto unsetenv (
  const StdStringView variable) -> void
{
  g_unsetenv(variable.c_str());
}

auto
listenv() -> std::vector<std::string>
{
  return ArrayHandler<std::string>::array_to_vector(g_listenv(), OWNERSHIP_DEEP);
}

auto
get_user_name() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_name());
}

auto
get_real_name() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_real_name());
}

auto
get_host_name() -> ustring
{
  return convert_const_gchar_ptr_to_ustring(g_get_host_name());
}

auto
get_home_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_home_dir());
}

auto
get_tmp_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_tmp_dir());
}

auto
get_current_dir() -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_get_current_dir());
}

auto
get_user_special_dir(UserDirectory directory) -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_special_dir((GUserDirectory)directory));
}

auto
get_user_data_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_data_dir());
}

auto
get_user_config_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_config_dir());
}

auto
get_system_data_dirs() -> std::vector<std::string>
{
  return ArrayHandler<std::string>::array_to_vector(g_get_system_data_dirs(), OWNERSHIP_NONE);
}

auto
get_system_config_dirs() -> std::vector<std::string>
{
  return ArrayHandler<std::string>::array_to_vector(g_get_system_config_dirs(), OWNERSHIP_NONE);
}

auto
get_user_cache_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_cache_dir());
}

auto
get_user_runtime_dir() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_get_user_runtime_dir());
}

auto
path_is_absolute(
  const StdStringView filename) -> bool
{
  return g_path_is_absolute(filename.c_str()) != 0;
}

auto
path_skip_root(
  const StdStringView filename) -> std::string
{
  // g_path_skip_root() returns a pointer _into_ the argument string,
  // or NULL if there was no root component.
  return convert_const_gchar_ptr_to_stdstring(g_path_skip_root(filename.c_str()));
}

auto
path_get_basename(
  const StdStringView filename) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_path_get_basename(filename.c_str()));
}

auto
path_get_dirname(
  const StdStringView filename) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_path_get_dirname(filename.c_str()));
}

auto
canonicalize_filename(
  const StdStringView filename, const StdStringView relative_to) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_canonicalize_filename(
    filename.c_str(), relative_to.c_str()));
}

auto
build_filename(const std::vector<std::string>& elements) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(
    g_build_filenamev(const_cast<char**>(ArrayHandler<std::string>::vector_to_array(elements).data())));
}

auto
build_path(const std::string& separator, const std::vector<std::string>& elements) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(
    g_build_pathv(separator.c_str(), const_cast<char**>(ArrayHandler<std::string>::vector_to_array(elements).data())));
}

auto
find_program_in_path(
  const StdStringView program) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_find_program_in_path(program.c_str()));
}

auto
format_size(
  const guint64 size, FormatSizeFlags flags) -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_format_size_full(size, (GFormatSizeFlags)flags));
}

} // namespace Glib

namespace
{
} // anonymous namespace


