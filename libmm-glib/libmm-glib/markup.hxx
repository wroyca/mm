// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MARKUP_H
#define _GLIBMM_MARKUP_H

#include <libmm-glib/error.hxx>
#include <map>
#include <sigc++/sigc++.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GMarkupParseContext GMarkupParseContext;
}
#endif

namespace Glib
{

  class MarkupError : public Glib::Error
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

    GLIBMM_API
    MarkupError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit MarkupError (GError* gobject);
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

  namespace Markup
  {

    class ParseContext;

    using Error = Glib::MarkupError;

    GLIBMM_API
    auto
    escape_text (const Glib::ustring& text) -> Glib::ustring;

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

    class GLIBMM_API AttributeKeyLess
    {
    public:
      using first_argument_type = Glib::ustring;
      using second_argument_type = Glib::ustring;
      typedef bool result_type;

      auto
      operator() (const Glib::ustring& lhs, const Glib::ustring& rhs) const
          -> bool;
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    class ParserCallbacks;
#endif

    class GLIBMM_API Parser : public sigc::trackable
    {
    public:
      typedef std::
          map<Glib::ustring, Glib::ustring, Glib::Markup::AttributeKeyLess>
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
                        const Glib::ustring& element_name,
                        const AttributeMap& attributes) -> void;

      virtual auto
      on_end_element (ParseContext& context, const Glib::ustring& element_name)
          -> void;

      virtual auto
      on_text (ParseContext& context, const Glib::ustring& text) -> void;

      virtual auto
      on_passthrough (ParseContext& context,
                      const Glib::ustring& passthrough_text) -> void;

      virtual auto
      on_error (ParseContext& context, const MarkupError& error) -> void;

    private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      friend class Glib::Markup::ParserCallbacks;
#endif
    };

    class GLIBMM_API ParseContext : public sigc::trackable
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
      parse (const Glib::ustring& text) -> void;

      auto
      parse (const char* text_begin, const char* text_end) -> void;

      auto
      end_parse () -> void;

      auto
      get_element () const -> Glib::ustring;

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

} // namespace Glib

#endif
