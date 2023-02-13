


#include <libmm-glib/mm-glib.hpp>

#include <libmm-glib/convert.hpp>
#include <libmm-glib/convert_p.hpp>


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

//#include <glib/gtestutils.h> //For g_assert() in glib >= 2.15.0
//#include <glib/gmessages.h> //For g_assert() in glib < 2.15.0
#include <glib.h> //For g_assert() in all versions of glib.

#include <libmm-glib/utility.hpp>

namespace Glib
{

/**** Glib::IConv **********************************************************/

IConv::IConv(const std::string& to_codeset, const std::string& from_codeset)
: gobject_(g_iconv_open(to_codeset.c_str(), from_codeset.c_str()))
{
  if (gobject_ == reinterpret_cast<GIConv>(-1))
  {
    GError* gerror = nullptr;

    // Abuse g_convert() to create a GError object.  This may seem a weird
    // thing to do, but it gives us consistently translated error messages
    // at no further cost.
    g_convert("", 0, to_codeset.c_str(), from_codeset.c_str(), nullptr, nullptr, &gerror);

    // If this should ever fail we're fucked.
    g_assert(gerror != nullptr);

    if (gerror)
      Error::throw_exception(gerror);
  }
}

IConv::IConv(const GIConv gobject) : gobject_(gobject)
{
}

IConv::~IConv()
{
  g_iconv_close(gobject_);
}

auto
IConv::iconv(char** inbuf, gsize* inbytes_left, char** outbuf, gsize* outbytes_left) -> std::size_t
{
  return g_iconv(gobject_, inbuf, inbytes_left, outbuf, outbytes_left);
}

auto IConv::reset () -> void
{
  // Apparently iconv() on Solaris <= 7 segfaults if you pass in
  // NULL for anything but inbuf; work around that. (NULL outbuf
  // or NULL *outbuf is allowed by Unix98.)

  char* outbuf = nullptr;
  gsize inbytes_left = 0;
  gsize outbytes_left = 0;

  g_iconv(gobject_, nullptr, &inbytes_left, &outbuf, &outbytes_left);
}

auto
IConv::convert(const std::string& str) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_convert_with_iconv(str.data(), str.size(), gobject_, nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

/**** charset conversion functions *****************************************/

auto
get_charset() -> bool
{
  return g_get_charset(nullptr);
}

auto
get_charset(std::string& charset) -> bool
{
  const char* charset_cstr = nullptr;
  const bool is_utf8 = g_get_charset(&charset_cstr);

  charset = charset_cstr;
  return is_utf8;
}

auto
convert(const std::string& str, const std::string& to_codeset, const std::string& from_codeset) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert(str.data(), str.size(), to_codeset.c_str(), from_codeset.c_str(),
    nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

auto
convert_with_fallback(
  const std::string& str, const std::string& to_codeset, const std::string& from_codeset) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert_with_fallback(str.data(), str.size(), to_codeset.c_str(),
    from_codeset.c_str(), nullptr, nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

auto
convert_with_fallback(const std::string& str, const std::string& to_codeset,
  const std::string& from_codeset, const ustring & fallback) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf = g_convert_with_fallback(str.data(), str.size(), to_codeset.c_str(),
    from_codeset.c_str(), fallback.c_str(), nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

auto
locale_to_utf8(const std::string& opsys_string) -> ustring
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_locale_to_utf8(opsys_string.data(), opsys_string.size(), nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  const auto scoped_buf = make_unique_ptr_gfree(buf);
  return {scoped_buf.get(), scoped_buf.get() + bytes_written};
}

auto
locale_from_utf8(const ustring & utf8_string) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_locale_from_utf8(utf8_string.data(), utf8_string.bytes(), nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

auto
filename_to_utf8(const std::string& opsys_string) -> ustring
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_filename_to_utf8(opsys_string.data(), opsys_string.size(), nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  const auto scoped_buf = make_unique_ptr_gfree(buf);
  return {scoped_buf.get(), scoped_buf.get() + bytes_written};
}

auto
filename_from_utf8(const ustring & utf8_string) -> std::string
{
  gsize bytes_written = 0;
  GError* gerror = nullptr;

  char* const buf =
    g_filename_from_utf8(utf8_string.data(), utf8_string.bytes(), nullptr, &bytes_written, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get(), bytes_written);
}

auto
filename_from_uri(const ustring & uri, ustring & hostname) -> std::string
{
  char* hostname_buf = nullptr;
  GError* gerror = nullptr;

  char* const buf = g_filename_from_uri(uri.c_str(), &hostname_buf, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  // Let's take ownership at this point.
  const auto scoped_buf = make_unique_ptr_gfree(buf);

  if (hostname_buf)
    hostname = make_unique_ptr_gfree(buf).get();
  else
    hostname.erase();

  return std::string(scoped_buf.get());
}

auto
filename_from_uri(const ustring & uri) -> std::string
{
  GError* gerror = nullptr;
  char* const buf = g_filename_from_uri(uri.c_str(), nullptr, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return std::string(make_unique_ptr_gfree(buf).get());
}

auto
filename_to_uri(const std::string& filename, const ustring & hostname) -> ustring
{
  GError* gerror = nullptr;
  char* const buf = g_filename_to_uri(filename.c_str(), hostname.c_str(), &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return {make_unique_ptr_gfree(buf).get()};
}

auto
filename_to_uri(const std::string& filename) -> ustring
{
  GError* gerror = nullptr;
  char* const buf = g_filename_to_uri(filename.c_str(), nullptr, &gerror);

  if (gerror)
    Error::throw_exception(gerror);

  return {make_unique_ptr_gfree(buf).get()};
}

auto
filename_display_basename(const std::string& filename) -> ustring
{
  char* const buf = g_filename_display_basename(filename.c_str());

  return {make_unique_ptr_gfree(buf).get()};
}

auto
filename_display_name(const std::string& filename) -> ustring
{
  char* const buf = g_filename_display_name(filename.c_str());

  return {make_unique_ptr_gfree(buf).get()};
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::ConvertError::ConvertError(const Code error_code, const ustring & error_message)
: Error(G_CONVERT_ERROR, error_code, error_message)
{}

Glib::ConvertError::ConvertError(GError* gobject)
: Error(gobject)
{}

auto Glib::ConvertError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Glib::ConvertError::throw_func (GError *gobject) -> void
{
  throw ConvertError(gobject);
}


