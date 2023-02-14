// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/convert.hxx>
#include <libmm-glib/convert_p.hxx>

#include <glib.h>

#include <libmm-glib/utility.hxx>

namespace Glib
{

  IConv::IConv (const std::string& to_codeset, const std::string& from_codeset)
    : gobject_ (g_iconv_open (to_codeset.c_str (), from_codeset.c_str ()))
  {
    if (gobject_ == reinterpret_cast<GIConv> (-1))
    {
      GError* gerror = nullptr;

      g_convert ("",
                 0,
                 to_codeset.c_str (),
                 from_codeset.c_str (),
                 nullptr,
                 nullptr,
                 &gerror);

      g_assert (gerror != nullptr);

      if (gerror)
        Error::throw_exception (gerror);
    }
  }

  IConv::IConv (const GIConv gobject)
    : gobject_ (gobject)
  {
  }

  IConv::~IConv ()
  {
    g_iconv_close (gobject_);
  }

  auto
  IConv::iconv (char** inbuf,
                gsize* inbytes_left,
                char** outbuf,
                gsize* outbytes_left) -> std::size_t
  {
    return g_iconv (gobject_, inbuf, inbytes_left, outbuf, outbytes_left);
  }

  auto
  IConv::reset () -> void
  {
    char* outbuf = nullptr;
    gsize inbytes_left = 0;
    gsize outbytes_left = 0;

    g_iconv (gobject_, nullptr, &inbytes_left, &outbuf, &outbytes_left);
  }

  auto
  IConv::convert (const std::string& str) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_convert_with_iconv (str.data (),
                                            str.size (),
                                            gobject_,
                                            nullptr,
                                            &bytes_written,
                                            &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  get_charset () -> bool
  {
    return g_get_charset (nullptr);
  }

  auto
  get_charset (std::string& charset) -> bool
  {
    const char* charset_cstr = nullptr;
    const bool is_utf8 = g_get_charset (&charset_cstr);

    charset = charset_cstr;
    return is_utf8;
  }

  auto
  convert (const std::string& str,
           const std::string& to_codeset,
           const std::string& from_codeset) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_convert (str.data (),
                                 str.size (),
                                 to_codeset.c_str (),
                                 from_codeset.c_str (),
                                 nullptr,
                                 &bytes_written,
                                 &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_convert_with_fallback (str.data (),
                                               str.size (),
                                               to_codeset.c_str (),
                                               from_codeset.c_str (),
                                               nullptr,
                                               nullptr,
                                               &bytes_written,
                                               &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset,
                         const ustring& fallback) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_convert_with_fallback (str.data (),
                                               str.size (),
                                               to_codeset.c_str (),
                                               from_codeset.c_str (),
                                               fallback.c_str (),
                                               nullptr,
                                               &bytes_written,
                                               &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  locale_to_utf8 (const std::string& opsys_string) -> ustring
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_locale_to_utf8 (opsys_string.data (),
                                        opsys_string.size (),
                                        nullptr,
                                        &bytes_written,
                                        &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    const auto scoped_buf = make_unique_ptr_gfree (buf);
    return {scoped_buf.get (), scoped_buf.get () + bytes_written};
  }

  auto
  locale_from_utf8 (const ustring& utf8_string) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_locale_from_utf8 (utf8_string.data (),
                                          utf8_string.bytes (),
                                          nullptr,
                                          &bytes_written,
                                          &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  filename_to_utf8 (const std::string& opsys_string) -> ustring
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_filename_to_utf8 (opsys_string.data (),
                                          opsys_string.size (),
                                          nullptr,
                                          &bytes_written,
                                          &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    const auto scoped_buf = make_unique_ptr_gfree (buf);
    return {scoped_buf.get (), scoped_buf.get () + bytes_written};
  }

  auto
  filename_from_utf8 (const ustring& utf8_string) -> std::string
  {
    gsize bytes_written = 0;
    GError* gerror = nullptr;

    char* const buf = g_filename_from_utf8 (utf8_string.data (),
                                            utf8_string.bytes (),
                                            nullptr,
                                            &bytes_written,
                                            &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get (), bytes_written);
  }

  auto
  filename_from_uri (const ustring& uri, ustring& hostname) -> std::string
  {
    char* hostname_buf = nullptr;
    GError* gerror = nullptr;

    char* const buf =
        g_filename_from_uri (uri.c_str (), &hostname_buf, &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    const auto scoped_buf = make_unique_ptr_gfree (buf);

    if (hostname_buf)
      hostname = make_unique_ptr_gfree (buf).get ();
    else
      hostname.erase ();

    return std::string (scoped_buf.get ());
  }

  auto
  filename_from_uri (const ustring& uri) -> std::string
  {
    GError* gerror = nullptr;
    char* const buf = g_filename_from_uri (uri.c_str (), nullptr, &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return std::string (make_unique_ptr_gfree (buf).get ());
  }

  auto
  filename_to_uri (const std::string& filename, const ustring& hostname) -> ustring
  {
    GError* gerror = nullptr;
    char* const buf =
        g_filename_to_uri (filename.c_str (), hostname.c_str (), &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return {make_unique_ptr_gfree (buf).get ()};
  }

  auto
  filename_to_uri (const std::string& filename) -> ustring
  {
    GError* gerror = nullptr;
    char* const buf = g_filename_to_uri (filename.c_str (), nullptr, &gerror);

    if (gerror)
      Error::throw_exception (gerror);

    return {make_unique_ptr_gfree (buf).get ()};
  }

  auto
  filename_display_basename (const std::string& filename) -> ustring
  {
    char* const buf = g_filename_display_basename (filename.c_str ());

    return {make_unique_ptr_gfree (buf).get ()};
  }

  auto
  filename_display_name (const std::string& filename) -> ustring
  {
    char* const buf = g_filename_display_name (filename.c_str ());

    return {make_unique_ptr_gfree (buf).get ()};
  }

} // namespace Glib

namespace
{
}

Glib::ConvertError::ConvertError (const Code error_code,
                                  const ustring& error_message)
  : Error (G_CONVERT_ERROR, error_code, error_message)
{
}

Glib::ConvertError::ConvertError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::ConvertError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::ConvertError::throw_func (GError* gobject) -> void
{
  throw ConvertError (gobject);
}
