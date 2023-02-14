// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/markup.hxx>
#include <libmm-glib/markup_p.hxx>

#include <glib.h>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/markup.hxx>
#include <libmm-glib/utility.hxx>

namespace Glib::Markup
{

  auto
  escape_text (const ustring& text) -> ustring
  {
    const auto buf = make_unique_ptr_gfree (
        g_markup_escape_text (text.data (), text.bytes ()));
    return {buf.get ()};
  }

  auto
  AttributeKeyLess::operator() (const ustring& lhs, const ustring& rhs) const -> bool
  {
    return lhs.raw () < rhs.raw ();
  }

  class ParserCallbacks
  {
  public:
    static const GMarkupParser vfunc_table;

    static auto
    start_element (GMarkupParseContext* context,
                   const char* element_name,
                   const char** attribute_names,
                   const char** attribute_values,
                   void* user_data,
                   GError** error) -> void;

    static auto
    end_element (GMarkupParseContext* context,
                 const char* element_name,
                 void* user_data,
                 GError** error) -> void;

    static auto
    text (GMarkupParseContext* context,
          const char* text,
          gsize text_len,
          void* user_data,
          GError** error) -> void;

    static auto
    passthrough (GMarkupParseContext* context,
                 const char* passthrough_text,
                 gsize text_len,
                 void* user_data,
                 GError** error) -> void;

    static auto
    error (GMarkupParseContext* context, GError* error, void* user_data)
        -> void;
  };

  const GMarkupParser ParserCallbacks::vfunc_table = {
      &ParserCallbacks::start_element,
      &ParserCallbacks::end_element,
      &ParserCallbacks::text,
      &ParserCallbacks::passthrough,
      &ParserCallbacks::error,
  };

  auto
  ParserCallbacks::start_element (GMarkupParseContext* context,
                                  const char* element_name,
                                  const char** attribute_names,
                                  const char** attribute_values,
                                  void* user_data,
                                  GError** error) -> void
  {
    ParseContext& cpp_context = *static_cast<ParseContext*> (user_data);
    g_return_if_fail (context == cpp_context.gobj ());

    try
    {
      Parser::AttributeMap attributes;

      if (attribute_names && attribute_values)
      {
        const char* const* pname = attribute_names;
        const char* const* pvalue = attribute_values;

        for (; *pname && *pvalue; ++pname, ++pvalue)
          attributes.insert (
              Parser::AttributeMap::value_type (*pname, *pvalue));

        g_return_if_fail (*pname == nullptr && *pvalue == nullptr);
      }

      cpp_context.get_parser ()->on_start_element (cpp_context,
                                                   element_name,
                                                   attributes);
    }
    catch (MarkupError& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
  }

  auto
  ParserCallbacks::end_element (GMarkupParseContext* context,
                                const char* element_name,
                                void* user_data,
                                GError** error) -> void
  {
    ParseContext& cpp_context = *static_cast<ParseContext*> (user_data);
    g_return_if_fail (context == cpp_context.gobj ());

    try
    {
      cpp_context.get_parser ()->on_end_element (cpp_context, element_name);
    }
    catch (MarkupError& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
  }

  auto
  ParserCallbacks::text (GMarkupParseContext* context,
                         const char* text,
                         const gsize text_len,
                         void* user_data,
                         GError** error) -> void
  {
    ParseContext& cpp_context = *static_cast<ParseContext*> (user_data);
    g_return_if_fail (context == cpp_context.gobj ());

    try
    {
      cpp_context.get_parser ()->on_text (cpp_context,
                                          ustring (text, text + text_len));
    }
    catch (MarkupError& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
  }

  auto
  ParserCallbacks::passthrough (GMarkupParseContext* context,
                                const char* passthrough_text,
                                const gsize text_len,
                                void* user_data,
                                GError** error) -> void
  {
    ParseContext& cpp_context = *static_cast<ParseContext*> (user_data);
    g_return_if_fail (context == cpp_context.gobj ());

    try
    {
      cpp_context.get_parser ()->on_passthrough (
          cpp_context,
          ustring (passthrough_text, passthrough_text + text_len));
    }
    catch (MarkupError& err)
    {
      err.propagate (error);
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
  }

  auto
  ParserCallbacks::error (GMarkupParseContext* context,
                          GError* error,
                          void* user_data) -> void
  {
    ParseContext& cpp_context = *static_cast<ParseContext*> (user_data);

    g_return_if_fail (context == cpp_context.gobj ());
    g_return_if_fail (error->domain == G_MARKUP_ERROR);

    try
    {
      cpp_context.get_parser ()->on_error (cpp_context,
                                           MarkupError (g_error_copy (error)));
    }
    catch (...)
    {
      exception_handlers_invoke ();
    }
  }

  Parser::Parser () = default;

  Parser::Parser (Parser&& other) noexcept
    : trackable (std::move (other))
  {
  }

  auto
  Parser::operator= (Parser&& other) noexcept -> Parser&
  {
    trackable::operator= (std::move (other));
    return *this;
  }

  Parser::~Parser () = default;

  auto
  Parser::on_start_element (ParseContext&, const ustring&, const AttributeMap&) -> void
  {
  }

  auto
  Parser::on_end_element (ParseContext&, const ustring&) -> void
  {
  }

  auto
  Parser::on_text (ParseContext&, const ustring&) -> void
  {
  }

  auto
  Parser::on_passthrough (ParseContext&, const ustring&) -> void
  {
  }

  auto
  Parser::on_error (ParseContext&, const MarkupError&) -> void
  {
  }

  ParseContext::ParseContext (Parser& parser, ParseFlags flags)
    : parser_ (&parser),
      gobject_ (
          g_markup_parse_context_new (&ParserCallbacks::vfunc_table,
                                      (GMarkupParseFlags) flags,
                                      this,
                                      &ParseContext::destroy_notify_callback))
  {
  }

  ParseContext::ParseContext (ParseContext&& other) noexcept
    : trackable (std::move (other)),
      parser_ (std::move (other.parser_)),
      gobject_ (std::move (other.gobject_))
  {
  }

  auto
  ParseContext::operator= (ParseContext&& other) noexcept -> ParseContext&
  {
    trackable::operator= (std::move (other));

    parser_ = std::move (other.parser_);
    gobject_ = std::move (other.gobject_);

    other.parser_ = nullptr;
    other.gobject_ = nullptr;

    return *this;
  }

  ParseContext::~ParseContext ()
  {
    parser_ = nullptr;
    g_markup_parse_context_free (gobject_);
  }

  auto
  ParseContext::parse (const ustring& text) -> void
  {
    GError* error = nullptr;
    g_markup_parse_context_parse (gobject_,
                                  text.data (),
                                  text.bytes (),
                                  &error);

    if (error)
      Glib::Error::throw_exception (error);
  }

  auto
  ParseContext::parse (const char* text_begin, const char* text_end) -> void
  {
    GError* error = nullptr;
    g_markup_parse_context_parse (gobject_,
                                  text_begin,
                                  text_end - text_begin,
                                  &error);

    if (error)
      Glib::Error::throw_exception (error);
  }

  auto
  ParseContext::end_parse () -> void
  {
    GError* error = nullptr;
    g_markup_parse_context_end_parse (gobject_, &error);

    if (error)
      Glib::Error::throw_exception (error);
  }

  auto
  ParseContext::get_element () const -> ustring
  {
    const char* const element_name =
        g_markup_parse_context_get_element (gobject_);
    return convert_const_gchar_ptr_to_ustring (element_name);
  }

  auto
  ParseContext::get_line_number () const -> int
  {
    int line_number = 0;
    g_markup_parse_context_get_position (gobject_, &line_number, nullptr);
    return line_number;
  }

  auto
  ParseContext::get_char_number () const -> int
  {
    int char_number = 0;
    g_markup_parse_context_get_position (gobject_, nullptr, &char_number);
    return char_number;
  }

  auto
  ParseContext::destroy_notify_callback (void* data) -> void
  {
    const ParseContext* const self = static_cast<ParseContext*> (data);

    g_return_if_fail (self->parser_ == nullptr);
  }

} // namespace Glib::Markup

namespace
{
}

Glib::MarkupError::MarkupError (const Code error_code,
                                const ustring& error_message)
  : Error (G_MARKUP_ERROR, error_code, error_message)
{
}

Glib::MarkupError::MarkupError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::MarkupError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::MarkupError::throw_func (GError* gobject) -> void
{
  throw MarkupError (gobject);
}
