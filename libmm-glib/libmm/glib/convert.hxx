// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_CONVERT_H
#define _GLIBMM_CONVERT_H

#include <glib.h>
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GIConv* GIConv;
}
#endif

namespace glib
{

  class ConvertError : public glib::Error
  {
  public:
    enum Code
    {
      NO_CONVERSION,
      ILLEGAL_SEQUENCE,
      FAILED,
      PARTIAL_INPUT,
      BAD_URI,
      NOT_ABSOLUTE_PATH,
      NO_MEMORY,
      EMBEDDED_NUL
    };

    LIBMM_GLIB_SYMEXPORT
    ConvertError (Code error_code, const glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit ConvertError (GError* gobject);
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

  class LIBMM_GLIB_SYMEXPORT IConv
  {
  public:
    IConv (const std::string& to_codeset, const std::string& from_codeset);

    IConv (const IConv&) = delete;
    auto
    operator= (const IConv&) -> IConv& = delete;

    explicit IConv (GIConv gobject);

    ~IConv ();

    auto
    iconv (char** inbuf,
           gsize* inbytes_left,
           char** outbuf,
           gsize* outbytes_left) -> std::size_t;

    auto
    reset () -> void;

    auto
    convert (const std::string& str) -> std::string;

    auto
    gobj () -> GIConv
    {
      return gobject_;
    }

  private:
    GIConv gobject_;
  };

  LIBMM_GLIB_SYMEXPORT
  auto
  get_charset () -> bool;

  LIBMM_GLIB_SYMEXPORT
  auto
  get_charset (std::string& charset) -> bool;

  LIBMM_GLIB_SYMEXPORT
  auto
  convert (const std::string& str,
           const std::string& to_codeset,
           const std::string& from_codeset) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset,
                         const glib::ustring& fallback) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  locale_to_utf8 (const std::string& opsys_string) -> glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  locale_from_utf8 (const glib::ustring& utf8_string) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_to_utf8 (const std::string& opsys_string) -> glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_from_utf8 (const glib::ustring& utf8_string) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_from_uri (const glib::ustring& uri, glib::ustring& hostname) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_from_uri (const glib::ustring& uri) -> std::string;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_to_uri (const std::string& filename, const glib::ustring& hostname) -> glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_to_uri (const std::string& filename) -> glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_display_basename (const std::string& filename) -> glib::ustring;

  LIBMM_GLIB_SYMEXPORT
  auto
  filename_display_name (const std::string& filename) -> glib::ustring;

} // namespace glib

#endif
