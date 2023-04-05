// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MARKUP_H
#define _GLIBMM_MARKUP_H

#include <libmm/glib/error.hxx>
#include <map>
#include <sigc++/sigc++.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GMarkupParseContext GMarkupParseContext;
}
#endif

namespace glib
{

  class MarkupError : public glib::Error
  {
  public:
    enum Code
    {
      BAD_UTF8,
      EMPTY,
      PARSE,
      UNKNOWN_ELEMENT,
      UNKNOWN_ATTRIBUTE,
      INVALID_CONTENT,
      MISSING_ATTRIBUTE
    };

    LIBMM_GLIB_SYMEXPORT
    MarkupError (Code error_code, const glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit MarkupError (GError* gobject);
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

  namespace Markup
  {

    class ParseContext;

    using Error = glib::MarkupError;

    LIBMM_GLIB_SYMEXPORT
    auto
    escape_text (const glib::ustring& text) -> glib::ustring;

    enum class ParseFlags
    {
      DEFAULT_FLAGS = 0x0,
      DO_NOT_USE_THIS_UNSUPPORTED_FLAG = 1 << 0,
      TREAT_CDATA_AS_TEXT = 1 << 1,
      PREFIX_ERROR_POSITION = 1 << 2,
      IGNORE_QUALIFIED = 1 << 3
    };

    inline auto
    operator| (ParseFlags lhs, ParseFlags rhs) -> ParseFlags
    {
      return static_cast<ParseFlags> (static_cast<unsigned> (lhs) |
                                      static_cast<unsigned> (rhs));
    }

    inline auto
    operator& (ParseFlags lhs, ParseFlags rhs) -> ParseFlags
    {
      return static_cast<ParseFlags> (static_cast<unsigned> (lhs) &
                                      static_cast<unsigned> (rhs));
    }

    inline auto
    operator^ (ParseFlags lhs, ParseFlags rhs) -> ParseFlags
    {
      return static_cast<ParseFlags> (static_cast<unsigned> (lhs) ^
                                      static_cast<unsigned> (rhs));
    }

    inline auto
    operator~(ParseFlags flags) -> ParseFlags
    {
      return static_cast<ParseFlags> (~static_cast<unsigned> (flags));
    }

    inline auto
    operator|= (ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
    {
      return (lhs = static_cast<ParseFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs)));
    }

    inline auto
    operator&= (ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
    {
      return (lhs = static_cast<ParseFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs)));
    }

    inline auto
    operator^= (ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
    {
      return (lhs = static_cast<ParseFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs)));
    }

    class LIBMM_GLIB_SYMEXPORT AttributeKeyLess
    {
    public:
      using first_argument_type = glib::ustring;
      using second_argument_type = glib::ustring;
      typedef bool result_type;

      auto
      operator() (const glib::ustring& lhs, const glib::ustring& rhs) const
          -> bool;
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    class ParserCallbacks;
#endif

    class LIBMM_GLIB_SYMEXPORT Parser : public sigc::trackable
    {
    public:
      typedef std::
          map<glib::ustring, glib::ustring, glib::Markup::AttributeKeyLess>
              AttributeMap;

      virtual ~Parser () = 0;

    protected:
      Parser ();

      Parser (const Parser&) = delete;
      auto
      operator= (const Parser&) -> Parser& = delete;

      Parser (Parser&& other) noexcept;
      auto
      operator= (Parser&& other) noexcept -> Parser&;

      virtual auto
      on_start_element (ParseContext& context,
                        const glib::ustring& element_name,
                        const AttributeMap& attributes) -> void;

      virtual auto
      on_end_element (ParseContext& context, const glib::ustring& element_name)
          -> void;

      virtual auto
      on_text (ParseContext& context, const glib::ustring& text) -> void;

      virtual auto
      on_passthrough (ParseContext& context,
                      const glib::ustring& passthrough_text) -> void;

      virtual auto
      on_error (ParseContext& context, const MarkupError& error) -> void;

    private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      friend class glib::Markup::ParserCallbacks;
#endif
    };

    class LIBMM_GLIB_SYMEXPORT ParseContext : public sigc::trackable
    {
    public:
      explicit ParseContext (Parser& parser, ParseFlags flags = ParseFlags (0));

      ParseContext (const ParseContext&) = delete;
      auto
      operator= (const ParseContext&) -> ParseContext& = delete;

      ParseContext (ParseContext&& other) noexcept;
      auto
      operator= (ParseContext&& other) noexcept -> ParseContext&;

      virtual ~ParseContext ();

      auto
      parse (const glib::ustring& text) -> void;

      auto
      parse (const char* text_begin, const char* text_end) -> void;

      auto
      end_parse () -> void;

      auto
      get_element () const -> glib::ustring;

      auto
      get_line_number () const -> int;

      auto
      get_char_number () const -> int;

      auto
      get_parser () -> Parser*
      {
        return parser_;
      }

      auto
      get_parser () const -> const Parser*
      {
        return parser_;
      }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
      auto
      gobj () -> GMarkupParseContext*
      {
        return gobject_;
      }

      auto
      gobj () const -> const GMarkupParseContext*
      {
        return gobject_;
      }
#endif

    private:
      Markup::Parser* parser_;
      GMarkupParseContext* gobject_;

      static auto
      destroy_notify_callback (void* data) -> void;
    };

  } // namespace Markup

} // namespace glib

#endif
