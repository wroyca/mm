


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/fileutils.hxx>
#include <libmm-glib/fileutils_p.hxx>


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

#include <glib.h>
#include <libmm-glib/utility.hxx>

namespace Glib
{

/**** Glib::Dir ************************************************************/

Dir::Dir(const std::string& path)
{
  GError* error = nullptr;
  gobject_ = g_dir_open(path.c_str(), 0, &error);

  if (error)
    Error::throw_exception(error);
}

Dir::Dir(GDir* gobject) : gobject_(gobject)
{
}

Dir::~Dir()
{
  if (gobject_)
    g_dir_close(gobject_);
}

auto
Dir::read_name() -> std::string
{
  const char* const name = g_dir_read_name(gobject_);
  return convert_const_gchar_ptr_to_stdstring(name);
}

auto Dir::rewind () -> void
{
  g_dir_rewind(gobject_);
}

auto Dir::close () -> void
{
  if (gobject_)
  {
    g_dir_close(gobject_);
    gobject_ = nullptr;
  }
}

auto
Dir::begin() -> DirIterator
{
  g_dir_rewind(gobject_);
  return {gobject_, g_dir_read_name(gobject_)};
}

auto
Dir::end() -> DirIterator
{
  return {gobject_, nullptr};
}

/**** Glib::DirIterator ****************************************************/

DirIterator::DirIterator() : gobject_(nullptr), current_(nullptr)
{
}

DirIterator::DirIterator(GDir* gobject, const char* current) : gobject_(gobject), current_(current)
{
}

auto DirIterator::operator*() const -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(current_);
}

auto DirIterator::operator++() -> DirIterator&
{
  current_ = g_dir_read_name(gobject_);
  return *this;
}

auto DirIterator::operator++ (int) -> void
{
  current_ = g_dir_read_name(gobject_);
}

auto
DirIterator::operator==(const DirIterator& rhs) const -> bool
{
  return current_ == rhs.current_;
}

auto
DirIterator::operator!=(const DirIterator& rhs) const -> bool
{
  return current_ != rhs.current_;
}

auto
file_test(const std::string& filename, FileTest test) -> bool
{
  return g_file_test(filename.c_str(), static_cast<GFileTest>(unsigned(test)));
}

auto
mkstemp(std::string& filename_template) -> int
{
  const auto buf =
    make_unique_ptr_gfree(g_strndup(filename_template.data(), filename_template.size()));
  const auto fileno = g_mkstemp(buf.get());

  filename_template = buf.get();
  return fileno;
}

auto
file_open_tmp(std::string& name_used, const std::string& prefix) -> int
{
  std::string basename_template(prefix);
  basename_template += "XXXXXX"; // this sillyness shouldn't be in the interface

  GError* error = nullptr;
  char* pch_buf_name_used = nullptr;

  const auto fileno = g_file_open_tmp(basename_template.c_str(), &pch_buf_name_used, &error);
  const auto buf_name_used = make_unique_ptr_gfree(pch_buf_name_used);
  if (error)
    Error::throw_exception(error);

  name_used = buf_name_used.get();
  return fileno;
}

auto
file_open_tmp(std::string& name_used) -> int
{
  GError* error = nullptr;
  char* pch_buf_name_used = nullptr;

  const auto fileno = g_file_open_tmp(nullptr, &pch_buf_name_used, &error);
  const auto buf_name_used = make_unique_ptr_gfree(pch_buf_name_used);
  if (error)
    Error::throw_exception(error);

  name_used = buf_name_used.get();
  return fileno;
}

auto
file_get_contents(const std::string& filename) -> std::string
{
  gsize length = 0;
  GError* error = nullptr;

  char* pch_contents = nullptr;
  g_file_get_contents(filename.c_str(), &pch_contents, &length, &error);
  const auto contents = make_unique_ptr_gfree(pch_contents);
  if (error)
    Error::throw_exception(error);

  return std::string(contents.get(), length);
}

auto file_set_contents (const std::string &filename, const gchar *contents, const gssize length) -> void
{
  GError* error = nullptr;

  g_file_set_contents(filename.c_str(), contents, length, &error);

  if (error)
    Error::throw_exception(error);
}

auto file_set_contents (const std::string &filename, const std::string &contents) -> void
{
  file_set_contents(filename, contents.c_str(), contents.size());
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::FileError::FileError(const Code error_code, const ustring & error_message)
: Error(G_FILE_ERROR, error_code, error_message)
{}

Glib::FileError::FileError(GError* gobject)
: Error(gobject)
{}

auto Glib::FileError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Glib::FileError::throw_func (GError *gobject) -> void
{
  throw FileError(gobject);
}


