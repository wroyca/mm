


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/keyfile.hpp>
#include <libmm-glib/keyfile_p.hpp>


/* Copyright 2006 The gtkmm Development Team
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

namespace Glib
{

auto
KeyFile::load_from_data(const ustring & data, Flags flags) -> bool
{
  GError* gerror = nullptr;

  const gboolean result = g_key_file_load_from_data(
    gobj(), data.c_str(), data.bytes(), static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return result != 0;
}

auto
KeyFile::load_from_data_dirs(const std::string& file, std::string& full_path, Flags flags) -> bool
{
  GError* gerror = nullptr;
  char* full_path_c = nullptr;

  const gboolean result = g_key_file_load_from_data_dirs(
    gobj(), file.c_str(), &full_path_c, static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  if (full_path_c)
    full_path = make_unique_ptr_gfree(full_path_c).get();
  else
    full_path.erase();

  return result != 0;
}

auto
KeyFile::load_from_dirs(const std::string& file, const std::vector<std::string>&  search_dirs,
  std::string& full_path, Flags flags) -> bool
{
  GError* gerror = nullptr;
  char* full_path_c = nullptr;

  const gboolean result =
    g_key_file_load_from_dirs(gobj(), file.c_str(), ArrayHandler<std::string>::vector_to_array(search_dirs).data(),
      &full_path_c, static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
  {
    if (full_path_c)
    {
      g_free(full_path_c);
    }
    Error::throw_exception(gerror);
  }

  if (full_path_c)
    full_path = make_unique_ptr_gfree(full_path_c).get();
  else
    full_path.erase();

  return result != 0;
}

auto
KeyFile::to_data() -> ustring
{
  GError* gerror = nullptr;
  char* const str = g_key_file_to_data(gobj(), nullptr, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return convert_return_gchar_ptr_to_ustring(str);
}

auto
KeyFile::get_groups() const -> std::vector<ustring>
{
  gsize length = 0;
  char** const array = g_key_file_get_groups(const_cast<GKeyFile*>(gobj()), &length);

  return ArrayHandler<ustring>::array_to_vector(array, length, OWNERSHIP_DEEP);
}

auto
KeyFile::get_keys(const ustring & group_name) const -> std::vector<ustring>
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_keys(
    const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), &length, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return ArrayHandler<ustring>::array_to_vector(array, length, OWNERSHIP_DEEP);
}

auto
KeyFile::get_locale_string(const ustring & group_name, const ustring & key) const -> ustring
{
  GError* gerror = nullptr;
  char* const str = g_key_file_get_locale_string(const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), key.c_str(), nullptr, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return convert_return_gchar_ptr_to_ustring(str);
}

auto
KeyFile::get_boolean(const ustring & key) const -> bool
{
  GError* gerror = nullptr;
  const bool value = static_cast<bool>(
    g_key_file_get_boolean(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror));
  if (gerror)
    Error::throw_exception(gerror);

  return value;
}

auto
KeyFile::get_integer(const ustring & key) const -> int
{
  GError* gerror = nullptr;
  const int value =
    g_key_file_get_integer(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);
  if (gerror)
    Error::throw_exception(gerror);

  return value;
}

auto
KeyFile::get_int64(const ustring & key) const -> gint64
{
  GError* gerror = nullptr;

  const gint64 value =
    g_key_file_get_int64(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return value;
}

auto
KeyFile::get_uint64(const ustring & key) const -> guint64
{
  GError* gerror = nullptr;

  const guint64 value =
    g_key_file_get_uint64(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return value;
}

auto
KeyFile::get_double(const ustring & key) const -> double
{
  GError* gerror = nullptr;
  const double retvalue =
    g_key_file_get_double(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return retvalue;
}

auto KeyFile::set_double (const ustring &key, const double value) -> void
{
  g_key_file_set_double(gobj(), nullptr, key.c_str(), value);
}

#define GLIBMM_ERROR_ARG
#define GLIBMM_THROW(err) \
  if (err)                \
  Glib::Error::throw_exception(err)

auto
KeyFile::get_string_list(
  const ustring & group_name, const ustring & key GLIBMM_ERROR_ARG) const -> std::vector<ustring>
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_string_list(const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return ArrayHandler<ustring>::array_to_vector(array, length, OWNERSHIP_DEEP);
}

auto
KeyFile::get_locale_string_list(const ustring & group_name, const ustring & key,
  const ustring & locale GLIBMM_ERROR_ARG) const -> std::vector<ustring>
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_locale_string_list(const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), key.c_str(), locale.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return ArrayHandler<ustring>::array_to_vector(array, length, OWNERSHIP_DEEP);
}

auto
KeyFile::get_boolean_list(
  const ustring & group_name, const ustring & key GLIBMM_ERROR_ARG) const -> std::vector<bool>
{
  gsize length = 0;
  GError* gerror = nullptr;

  const gboolean* const array = g_key_file_get_boolean_list(const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return ArrayHandler<bool>::array_to_vector(array, length, OWNERSHIP_SHALLOW);
}

auto
KeyFile::get_integer_list(
  const ustring & group_name, const ustring & key GLIBMM_ERROR_ARG) const -> std::vector<int>
{
  gsize length = 0;
  GError* gerror = nullptr;

  const int* const array = g_key_file_get_integer_list(const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return ArrayHandler<int>::array_to_vector(array, length, OWNERSHIP_SHALLOW);
}

auto
KeyFile::get_double_list(
  const ustring & group_name, const ustring & key GLIBMM_ERROR_ARG) const -> std::vector<double>
{
  gsize length = 0;
  GError* gerror = nullptr;

  const double* const array = g_key_file_get_double_list(
    const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &length, &gerror);
  GLIBMM_THROW(gerror);

  return ArrayHandler<double>::array_to_vector(array, length, OWNERSHIP_SHALLOW);
}

auto KeyFile::set_string_list (
  const ustring &group_name, const ustring &key,
  const std::vector <ustring> &list) -> void
{
  g_key_file_set_string_list(
    gobj(), c_str_or_nullptr(group_name), key.c_str(), ArrayHandler<ustring>::vector_to_array(list).data(), list.size());
}

auto KeyFile::set_locale_string_list (
  const ustring &group_name, const ustring &key,
  const ustring &locale, const std::vector <ustring> &list) -> void
{
  g_key_file_set_locale_string_list(gobj(), c_str_or_nullptr(group_name), key.c_str(),
    locale.c_str(), ArrayHandler<ustring>::vector_to_array(list).data(), list.size());
}

auto KeyFile::set_integer_list (
  const ustring &group_name, const ustring &key, const std::vector <int> &list) -> void
{
  g_key_file_set_integer_list(gobj(), c_str_or_nullptr(group_name), key.c_str(), ArrayHandler<int>::vector_to_array(list).data(), list.size());
}

auto KeyFile::set_double_list (
  const ustring &group_name, const ustring &key,
  const std::vector <double> &list) -> void
{
  g_key_file_set_double_list(
    gobj(), group_name.c_str(), key.c_str(), ArrayHandler<double>::vector_to_array(list).data(), list.size());
}

auto KeyFile::set_boolean_list (
  const ustring &group_name, const ustring &key, const std::vector <bool> &list) -> void
{
  g_key_file_set_boolean_list(gobj(), c_str_or_nullptr(group_name), key.c_str(), ArrayHandler<bool>::vector_to_array(list).data(), list.size());
}

auto
KeyFile::get_comment() const -> ustring
{
  GError* gerror = nullptr;
  char* const str =
    g_key_file_get_comment(const_cast<GKeyFile*>(gobj()), nullptr, nullptr, &gerror);

  GLIBMM_THROW(gerror);

  return convert_return_gchar_ptr_to_ustring(str);
}

auto
KeyFile::get_comment(const ustring & group_name GLIBMM_ERROR_ARG) const -> ustring
{
  GError* gerror = nullptr;
  char* const str = g_key_file_get_comment(
    const_cast<GKeyFile*>(gobj()), c_str_or_nullptr(group_name), nullptr, &gerror);
  GLIBMM_THROW(gerror);

  return convert_return_gchar_ptr_to_ustring(str);
}

auto KeyFile::set_comment (const ustring &comment GLIBMM_ERROR_ARG) -> void
{
  GError* gerror = nullptr;
  g_key_file_set_comment(gobj(), nullptr, nullptr, comment.c_str(), &gerror);

  GLIBMM_THROW(gerror);
}

auto KeyFile::set_comment (
  const ustring &group_name, const ustring &comment GLIBMM_ERROR_ARG) -> void
{
  GError* gerror = nullptr;
  g_key_file_set_comment(
    gobj(), c_str_or_nullptr(group_name), nullptr, comment.c_str(), &gerror);
  GLIBMM_THROW(gerror);
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::KeyFileError::KeyFileError(const Code error_code, const ustring & error_message)
: Error(G_KEY_FILE_ERROR, error_code, error_message)
{}

Glib::KeyFileError::KeyFileError(GError* gobject)
: Error(gobject)
{}

auto Glib::KeyFileError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Glib::KeyFileError::throw_func (GError *gobject) -> void
{
  throw KeyFileError(gobject);
}


/* Why reinterpret_cast<KeyFile*>(gobject) is needed:
 *
 * A KeyFile instance is in fact always a GKeyFile instance.
 * Unfortunately, GKeyFile cannot be a member of KeyFile,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because KeyFile does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GKeyFile* object, const bool take_copy) -> RefPtr<KeyFile>
{
  if(take_copy && object)
    g_key_file_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<KeyFile>(reinterpret_cast<KeyFile *>(object));
}

} // namespace Glib


namespace Glib
{

// static
auto KeyFile::create() -> RefPtr<KeyFile>
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<KeyFile>(reinterpret_cast<KeyFile*>(g_key_file_new()));
}

auto KeyFile::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_key_file_ref(reinterpret_cast<GKeyFile*>(const_cast<KeyFile*>(this)));
}

auto KeyFile::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_key_file_unref(reinterpret_cast<GKeyFile*>(const_cast<KeyFile*>(this)));
}

auto KeyFile::gobj() -> GKeyFile*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GKeyFile*>(this);
}

auto KeyFile::gobj() const -> const GKeyFile*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GKeyFile*>(this);
}

auto KeyFile::gobj_copy() const -> GKeyFile*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GKeyFile*>(const_cast<KeyFile*>(this));
  g_key_file_ref(gobject);
  return gobject;
}


auto KeyFile::load_from_file(const std::string& file, Flags flags) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_load_from_file(gobj(), file.c_str(), static_cast<GKeyFileFlags>(flags), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::save_to_file(const std::string& filename) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_save_to_file(gobj(), filename.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_start_group() const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_key_file_get_start_group(const_cast<GKeyFile*>(gobj())));
}

auto KeyFile::has_group(const ustring & group_name) const -> bool
{
  return g_key_file_has_group(const_cast<GKeyFile*>(gobj()), group_name.c_str());
}

auto KeyFile::has_key(const ustring & group_name, const ustring & key) const -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_has_key(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_value(const ustring & group_name, const ustring & key) const -> ustring
{
  GError* gerror = nullptr;
  auto retvalue = convert_return_gchar_ptr_to_ustring(g_key_file_get_value(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror));
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_string(const ustring & group_name, const ustring & key) const -> ustring
{
  GError* gerror = nullptr;
  auto retvalue = convert_return_gchar_ptr_to_ustring(g_key_file_get_string(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror));
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_locale_for_key(const ustring & group_name, const ustring & key, const ustring & locale) const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_key_file_get_locale_for_key(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), locale.empty() ? nullptr : locale.c_str()));
}

auto KeyFile::get_locale_string(const ustring & group_name, const ustring & key, const ustring & locale) const -> ustring
{
  GError* gerror = nullptr;
  auto retvalue = convert_return_gchar_ptr_to_ustring(g_key_file_get_locale_string(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), locale.c_str(), &gerror));
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_boolean(const ustring & group_name, const ustring & key) const -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_get_boolean(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_integer(const ustring & group_name, const ustring & key) const -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_get_integer(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_int64(const ustring & group_name, const ustring & key) const -> gint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_get_int64(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_uint64(const ustring & group_name, const ustring & key) const -> guint64
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_get_uint64(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::get_double(const ustring & group_name, const ustring & key) const -> double
{
  GError* gerror = nullptr;
  const auto retvalue = g_key_file_get_double(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::set_double (
  const ustring &group_name, const ustring &key, const double value) -> void
{
  g_key_file_set_double(gobj(), group_name.c_str(), key.c_str(), value);
}

auto KeyFile::get_comment(const ustring & group_name, const ustring & key) const -> ustring
{
  GError* gerror = nullptr;
  auto retvalue = convert_return_gchar_ptr_to_ustring(g_key_file_get_comment(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &gerror));
  if(gerror)
    Error::throw_exception(gerror);
  return retvalue;
}

auto KeyFile::set_list_separator (
  const gchar separator) -> void
{
  g_key_file_set_list_separator(gobj(), separator);
}

auto KeyFile::set_value (
  const ustring &group_name, const ustring &key, const ustring &value) -> void
{
  g_key_file_set_value(gobj(), group_name.c_str(), key.c_str(), value.c_str());
}

auto KeyFile::set_string (
  const ustring &group_name, const ustring &key, const ustring &string) -> void
{
  g_key_file_set_string(gobj(), group_name.c_str(), key.c_str(), string.c_str());
}

auto KeyFile::set_locale_string (
  const ustring &group_name, const ustring &key, const ustring &locale,
  const ustring &string) -> void
{
  g_key_file_set_locale_string(gobj(), group_name.c_str(), key.c_str(), locale.c_str(), string.c_str());
}

auto KeyFile::set_boolean (
  const ustring &group_name, const ustring &key, const bool value) -> void
{
  g_key_file_set_boolean(gobj(), group_name.c_str(), key.c_str(), value);
}

auto KeyFile::set_integer (
  const ustring &group_name, const ustring &key, const int value) -> void
{
  g_key_file_set_integer(gobj(), group_name.c_str(), key.c_str(), value);
}

auto KeyFile::set_int64 (
  const ustring &group_name, const ustring &key, const gint64 value) -> void
{
  g_key_file_set_int64(gobj(), group_name.c_str(), key.c_str(), value);
}

auto KeyFile::set_uint64 (
  const ustring &group_name, const ustring &key, const guint64 value) -> void
{
  g_key_file_set_uint64(gobj(), group_name.c_str(), key.c_str(), value);
}

auto KeyFile::set_comment (
  const ustring &group_name, const ustring &key, const ustring &comment) -> void
{
  GError* gerror = nullptr;
  g_key_file_set_comment(gobj(), group_name.c_str(), key.c_str(), comment.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
}

auto KeyFile::remove_comment (const ustring &group_name, const ustring &key) -> void
{
  GError* gerror = nullptr;
  g_key_file_remove_comment(gobj(), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
}

auto KeyFile::remove_key (const ustring &group_name, const ustring &key) -> void
{
  GError* gerror = nullptr;
  g_key_file_remove_key(gobj(), group_name.c_str(), key.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
}

auto KeyFile::remove_group (const ustring &group_name) -> void
{
  GError* gerror = nullptr;
  g_key_file_remove_group(gobj(), group_name.c_str(), &gerror);
  if(gerror)
    Error::throw_exception(gerror);
}


} // namespace Glib


