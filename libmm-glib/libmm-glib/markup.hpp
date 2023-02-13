
#ifndef _GLIBMM_MARKUP_H
#define _GLIBMM_MARKUP_H


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


#include <libmm-glib/error.hpp>
#include <sigc++/sigc++.h>
#include <map>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GMarkupParseContext GMarkupParseContext; }
#endif

namespace Glib
{

/** @defgroup Markup Simple XML Subset Parser
 *
 * The Glib::Markup parser is intended to parse a simple markup format that's a
 * subset of XML. This is a small, efficient, easy-to-use parser. It should not
 * be used if you expect to interoperate with other applications generating
 * full-scale XML. However, it's very useful for application data files, config
 * files, etc. where you know your application will be the only one writing the
 * file. Full-scale XML parsers should be able to parse the subset used by
 * Glib::Markup parser, so you can easily migrate to full-scale XML at a later
 * time if the need arises.
 *
 * Glib::Markup is not guaranteed to signal an error on all invalid XML;
 * the parser may accept documents that an XML parser would not. However,
 * invalid XML documents are not considered valid Glib::Markup documents.
 *
 * @par Simplifications to XML include:
 *
 * - Only UTF-8 encoding is allowed.
 * - No user-defined entities.
 * - Processing instructions, comments and the doctype declaration are "passed
 *   through" but are not interpreted in any way.
 * - No DTD or validation.
 *
 * @par The markup format does support:
 *
 * - Elements
 * - Attributes
 * - 5 standard entities: <tt>\&amp; \&lt; \&gt; \&quot; \&apos;</tt>
 * - Character references
 * - Sections marked as <tt>CDATA</tt>
 *
 * @{
 */

/**  %Exception class for markup parsing errors.
 */
class MarkupError : public Glib::Error
{
public:
  /**  @var Code BAD_UTF8
   * Text being parsed was not valid UTF-8.
   *
   *  @var Code EMPTY
   * Document contained nothing, or only whitespace.
   *
   *  @var Code PARSE
   * Document was ill-formed.
   *
   *  @var Code UNKNOWN_ELEMENT
   * Error should be set by MarkupParser
   * functions; element wasn't known.
   *
   *  @var Code UNKNOWN_ATTRIBUTE
   * Error should be set by MarkupParser
   * functions; attribute wasn't known.
   *
   *  @var Code INVALID_CONTENT
   * Error should be set by MarkupParser
   * functions; content was invalid.
   *
   *  @var Code MISSING_ATTRIBUTE
   * Error should be set by MarkupParser
   * functions; a required attribute was missing.
   *
   *  @enum Code
   *
   * %Error codes returned by markup parsing.
   */
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

  GLIBMM_API MarkupError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit MarkupError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


/*! @var MarkupError::Code MarkupError::BAD_UTF8
 * Text being parsed was not valid UTF-8.
 */
/*! @var MarkupError::Code MarkupError::EMPTY
 * Document contained nothing, or only whitespace.
 */
/*! @var MarkupError::Code MarkupError::PARSE
 * Document was ill-formed.
 */
/*! @var MarkupError::Code MarkupError::UNKNOWN_ELEMENT
 * This error should be set by Glib::Markup::Parser virtual methods;
 * element wasn't known.
 */
/*! @var MarkupError::Code MarkupError::UNKNOWN_ATTRIBUTE
 * This error should be set by Glib::Markup::Parser virtual methods;
 * attribute wasn't known.
 */
/*! @var MarkupError::Code MarkupError::INVALID_CONTENT
 * This error should be set by Glib::Markup::Parser virtual methods;
 * something was wrong with contents of the document, e.g. invalid attribute value.
 */

/** @} group Markup */


namespace Markup
{

class ParseContext;

/** @ingroup Markup */
using Error = Glib::MarkupError;


/** Escapes text so that the markup parser will parse it verbatim.
 * Less than, greater than, ampersand, etc. are replaced with the corresponding
 * entities.  This function would typically be used when writing out a file to
 * be parsed with the markup parser.
 * @ingroup Markup
 * @param text Some valid UTF-8 text.
 * @return Escaped text.
 */
GLIBMM_API
auto escape_text(const Glib::ustring& text) -> Glib::ustring;

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var ParseFlags DEFAULT_FLAGS
 * No special behaviour. @newin{2,74}
 *
 *  @var ParseFlags DO_NOT_USE_THIS_UNSUPPORTED_FLAG
 * Flag you should not use.
 *
 *  @var ParseFlags TREAT_CDATA_AS_TEXT
 * When this flag is set, CDATA marked
 * sections are not passed literally to the @a passthrough function of
 * the parser. Instead, the content of the section (without the
 * `<![CDATA[` and `]]>`) is
 * passed to the @a text function. This flag was added in GLib 2.12.
 *
 *  @var ParseFlags PREFIX_ERROR_POSITION
 * Normally errors caught by GMarkup
 * itself have line/column information prefixed to them to let the
 * caller know the location of the error. When this flag is set the
 * location information is also prefixed to errors generated by the
 * MarkupParser implementation functions.
 *
 *  @var ParseFlags IGNORE_QUALIFIED
 * Ignore (don't report) qualified
 * attributes and tags, along with their contents.  A qualified
 * attribute or tag is one that contains ':' in its name (ie: is in
 * another namespace).  @newin{2,40}
 *
 *  @enum ParseFlags
 *
 * Flags that affect the behaviour of the parser.
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>ParseFlags operator|(ParseFlags, ParseFlags)</tt><br>
 * <tt>ParseFlags operator&(ParseFlags, ParseFlags)</tt><br>
 * <tt>ParseFlags operator^(ParseFlags, ParseFlags)</tt><br>
 * <tt>ParseFlags operator~(ParseFlags)</tt><br>
 * <tt>ParseFlags& operator|=(ParseFlags&, ParseFlags)</tt><br>
 * <tt>ParseFlags& operator&=(ParseFlags&, ParseFlags)</tt><br>
 * <tt>ParseFlags& operator^=(ParseFlags&, ParseFlags)</tt><br>
 */
enum class ParseFlags
{
  DEFAULT_FLAGS = 0x0,
  DO_NOT_USE_THIS_UNSUPPORTED_FLAG = 1 << 0,
  TREAT_CDATA_AS_TEXT = 1 << 1,
  PREFIX_ERROR_POSITION = 1 << 2,
  IGNORE_QUALIFIED = 1 << 3
};

/** @ingroup glibmmEnums */
inline auto operator|(ParseFlags lhs, ParseFlags rhs) -> ParseFlags
  { return static_cast<ParseFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(ParseFlags lhs, ParseFlags rhs) -> ParseFlags
  { return static_cast<ParseFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(ParseFlags lhs, ParseFlags rhs) -> ParseFlags
  { return static_cast<ParseFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(ParseFlags flags) -> ParseFlags
  { return static_cast<ParseFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
  { return (lhs = static_cast<ParseFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
  { return (lhs = static_cast<ParseFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(ParseFlags& lhs, ParseFlags rhs) -> ParseFlags&
  { return (lhs = static_cast<ParseFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** Binary predicate used by Markup::Parser::AttributeMap.
 * @ingroup Markup
 * Unlike <tt>operator<(const ustring& lhs, const ustring& rhs)</tt>
 * which would be used by the default <tt>std::less<></tt> predicate,
 * the AttributeKeyLess predicate is locale-independent.  This is both
 * more correct and much more efficient.
 */
class GLIBMM_API AttributeKeyLess
{
public:
  using first_argument_type = Glib::ustring;
  using second_argument_type = Glib::ustring;
  typedef bool          result_type;

  auto operator()(const Glib::ustring& lhs, const Glib::ustring& rhs) const -> bool;
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
class ParserCallbacks;
#endif

/** The abstract markup parser base class.
 * @ingroup Markup
 * To implement a parser for your markup format, derive from
 * Glib::Markup::Parser and implement the virtual methods.
 *
 * You don't have to override all of the virtual methods.  If a particular
 * method is not implement the data passed to it will be ignored.  Except for
 * the error method, any of these callbacks can throw an error exception; in
 * particular the MarkupError::UNKNOWN_ELEMENT,
 * MarkupError::UNKNOWN_ATTRIBUTE, and MarkupError::INVALID_CONTENT errors
 * are intended to be thrown from these overridden methods. If you throw an
 * error from a method, Glib::Markup::ParseContext::parse() will report that
 * error back to its caller.
 */
class GLIBMM_API Parser : public sigc::trackable
{
public:
  typedef std::map<Glib::ustring, Glib::ustring, Glib::Markup::AttributeKeyLess> AttributeMap;

  virtual ~Parser() = 0;

protected:
  /** Constructs a Parser object.
   * Note that Markup::Parser is an abstract class which can't be instantiated
   * directly.  To implement the parser for your markup format, derive from
   * Markup::Parser and implement the virtual methods.
   */
  Parser();

  Parser(const Parser&) = delete;
  auto operator=(const Parser&) -> Parser& = delete;

  Parser(Parser&& other) noexcept;
  auto operator=(Parser&& other) noexcept -> Parser&;

  /** Called for open tags <tt>\<foo bar="baz"\></tt>.
   * This virtual method is invoked when the opening tag of an element is seen.
   * @param context The Markup::ParseContext object the parsed data belongs to.
   * @param element_name The name of the element.
   * @param attributes A map of attribute name/value pairs.
   * @throw Glib::MarkupError An exception <em>you</em> should throw if
   * something went wrong, for instance if an unknown attribute name was
   * encountered.  In particular the MarkupError::UNKNOWN_ELEMENT,
   * MarkupError::UNKNOWN_ATTRIBUTE, and MarkupError::INVALID_CONTENT
   * errors are intended to be thrown from user-implemented methods.
   */
  virtual void on_start_element(ParseContext&        context,
                                const Glib::ustring& element_name,
                                const AttributeMap&  attributes);

  /** Called for close tags <tt>\</foo\></tt>.
   * This virtual method is invoked when the closing tag of an element is seen.
   * @param context The Markup::ParseContext object the parsed data belongs to.
   * @param element_name The name of the element.
   * @throw Glib::MarkupError An exception <em>you</em> should throw if
   * something went wrong, for instance if an unknown attribute name was
   * encountered.  In particular the MarkupError::UNKNOWN_ELEMENT,
   * MarkupError::UNKNOWN_ATTRIBUTE, and MarkupError::INVALID_CONTENT
   * errors are intended to be thrown from user-implemented methods.
   */
  virtual void on_end_element(ParseContext& context, const Glib::ustring& element_name);

  /** Called for character data.
   * This virtual method is invoked when some text is seen (text is always
   * inside an element).
   * @param context The Markup::ParseContext object the parsed data belongs to.
   * @param text The parsed text in UTF-8 encoding.
   * @throw Glib::MarkupError An exception <em>you</em> should throw if
   * something went wrong, for instance if an unknown attribute name was
   * encountered.  In particular the MarkupError::UNKNOWN_ELEMENT,
   * MarkupError::UNKNOWN_ATTRIBUTE, and MarkupError::INVALID_CONTENT
   * errors are intended to be thrown from user-implemented methods.
   */
  virtual void on_text(ParseContext& context, const Glib::ustring& text);

  /** Called for strings that should be re-saved verbatim in this same
   * position, but are not otherwise interpretable.
   * This virtual method is invoked for comments, processing instructions and
   * doctype declarations; if you're re-writing the parsed document, write the
   * passthrough text back out in the same position.
   * @param context The Markup::ParseContext object the parsed data belongs to.
   * @param passthrough_text The text that should be passed through.
   * @throw Glib::MarkupError An exception <em>you</em> should throw if
   * something went wrong, for instance if an unknown attribute name was
   * encountered.  In particular the MarkupError::UNKNOWN_ELEMENT,
   * MarkupError::UNKNOWN_ATTRIBUTE, and MarkupError::INVALID_CONTENT
   * errors are intended to be thrown from user-implemented methods.
   */
  virtual void on_passthrough(ParseContext& context, const Glib::ustring& passthrough_text);

  /** Called on error, including one thrown by an overridden virtual method.
   * @param context The Markup::ParseContext object the parsed data belongs to.
   * @param error A MarkupError object with detailed information about the error.
   */
  virtual void on_error(ParseContext& context, const MarkupError& error);

private:

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  friend class Glib::Markup::ParserCallbacks;
#endif
};


/** A parse context is used to parse marked-up documents.
 * @ingroup Markup
 * You can feed any number of documents into a context, as long as no errors
 * occur; once an error occurs, the parse context can't continue to parse text
 * (you have to destroy it and create a new parse context).
 */
class GLIBMM_API ParseContext : public sigc::trackable
{
public:
  /** Creates a new parse context.
   * @param parser A Markup::Parser instance.
   * @param flags Bitwise combination of Markup::ParseFlags.
   */
  explicit ParseContext(Parser& parser, ParseFlags flags = ParseFlags(0));

  ParseContext(const ParseContext&) = delete;
  auto operator=(const ParseContext&) -> ParseContext& = delete;

  ParseContext(ParseContext&& other) noexcept;
  auto operator=(ParseContext&& other) noexcept -> ParseContext&;

  virtual ~ParseContext();

  /** Feed some data to the ParseContext.
   * The data need not be valid UTF-8; an error will be signalled if it's
   * invalid. The data need not be an entire document; you can feed a document
   * into the parser incrementally, via multiple calls to this function.
   * Typically, as you receive data from a network connection or file, you feed
   * each received chunk of data into this function, aborting the process if an
   * error occurs. Once an error is reported, no further data may be fed to the
   * ParseContext; all errors are fatal.
   * @param text Chunk of text to parse.
   * @throw Glib::MarkupError
   */
  void parse(const Glib::ustring& text);

  /** Feed some data to the ParseContext.
   * The data need not be valid UTF-8; an error will be signalled if it's
   * invalid. The data need not be an entire document; you can feed a document
   * into the parser incrementally, via multiple calls to this function.
   * Typically, as you receive data from a network connection or file, you feed
   * each received chunk of data into this function, aborting the process if an
   * error occurs. Once an error is reported, no further data may be fed to the
   * ParseContext; all errors are fatal.
   * @param text_begin Begin of chunk of text to parse.
   * @param text_end End of chunk of text to parse.
   * @throw Glib::MarkupError
   */
  void parse(const char* text_begin, const char* text_end);

  /** Signals to the ParseContext that all data has been fed into the parse
   * context with parse(). This method reports an error if the document isn't
   * complete, for example if elements are still open.
   * @throw Glib::MarkupError
   */
  void end_parse();

  /** Retrieves the name of the currently open element.
   * @return The name of the currently open element, or <tt>""</tt>.
   */
  auto get_element() const -> Glib::ustring;

  /** Retrieves the current line number.
   * Intended for use in error messages; there are no strict semantics for what
   * constitutes the "current" line number other than "the best number we could
   * come up with for error messages."
   */
  auto get_line_number() const -> int;

  /** Retrieves the number of the current character on the current line.
   * Intended for use in error messages; there are no strict semantics for what
   * constitutes the "current" character number other than "the best number we
   * could come up with for error messages."
   */
  auto get_char_number() const -> int;

  auto       get_parser() -> Parser*       { return parser_; }
  auto get_parser() const -> const Parser* { return parser_; }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  auto       gobj() -> GMarkupParseContext*       { return gobject_; }
  auto gobj() const -> const GMarkupParseContext* { return gobject_; }
#endif

private:
  Markup::Parser*       parser_;
  GMarkupParseContext*  gobject_;

  static void destroy_notify_callback(void* data);
};

} // namespace Markup

} // namespace Glib


#endif /* _GLIBMM_MARKUP_H */

