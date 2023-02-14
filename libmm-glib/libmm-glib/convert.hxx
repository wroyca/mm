
#ifndef _GLIBMM_CONVERT_H
#define _GLIBMM_CONVERT_H

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GIConv* GIConv;
}
#endif

namespace Glib
{

  class ConvertError : public Glib::Error
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

    GLIBMM_API
    ConvertError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit ConvertError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static void
    throw_func (GError* gobject);

    friend GLIBMM_API void
    wrap_init ();

#endif
  };

  class GLIBMM_API IConv
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

    void
    reset ();

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

  GLIBMM_API
  auto
  get_charset () -> bool;

  GLIBMM_API
  auto
  get_charset (std::string& charset) -> bool;

  GLIBMM_API
  auto
  convert (const std::string& str,
           const std::string& to_codeset,
           const std::string& from_codeset) -> std::string;

  GLIBMM_API
  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset) -> std::string;

  GLIBMM_API
  auto
  convert_with_fallback (const std::string& str,
                         const std::string& to_codeset,
                         const std::string& from_codeset,
                         const Glib::ustring& fallback) -> std::string;

  GLIBMM_API
  auto
  locale_to_utf8 (const std::string& opsys_string) -> Glib::ustring;

  GLIBMM_API
  auto
  locale_from_utf8 (const Glib::ustring& utf8_string) -> std::string;

  GLIBMM_API
  auto
  filename_to_utf8 (const std::string& opsys_string) -> Glib::ustring;

  GLIBMM_API
  auto
  filename_from_utf8 (const Glib::ustring& utf8_string) -> std::string;

  GLIBMM_API
  auto
  filename_from_uri (const Glib::ustring& uri, Glib::ustring& hostname) -> std::string;

  GLIBMM_API
  auto
  filename_from_uri (const Glib::ustring& uri) -> std::string;

  GLIBMM_API
  auto
  filename_to_uri (const std::string& filename, const Glib::ustring& hostname) -> Glib::ustring;

  GLIBMM_API
  auto
  filename_to_uri (const std::string& filename) -> Glib::ustring;

  GLIBMM_API
  auto
  filename_display_basename (const std::string& filename) -> Glib::ustring;

  GLIBMM_API
  auto
  filename_display_name (const std::string& filename) -> Glib::ustring;

} // namespace Glib

#endif
