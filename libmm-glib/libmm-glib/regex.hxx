
#ifndef _GLIBMM_REGEX_H
#define _GLIBMM_REGEX_H


/* Copyright (C) 2007 The glibmm Development Team
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


#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/error.hxx>
#include <glib.h>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GRegex GRegex;
#endif

namespace Glib
{


/**  %Exception class for Regex
 */
class RegexError : public Glib::Error
{
public:
  /**  @var Code COMPILE
   * Compilation of the regular expression failed.
   *
   *  @var Code OPTIMIZE
   * Optimization of the regular expression failed.
   *
   *  @var Code REPLACE
   * Replacement failed due to an ill-formed replacement
   * string.
   *
   *  @var Code MATCH
   * The match process failed.
   *
   *  @var Code INTERNAL
   * Internal error of the regular expression engine.
   * @newin{2,16}
   *
   *  @var Code STRAY_BACKSLASH
   * "\\\\" at end of pattern. @newin{2,16}
   *
   *  @var Code MISSING_CONTROL_CHAR
   * "\\\\c" at end of pattern. @newin{2,16}
   *
   *  @var Code UNRECOGNIZED_ESCAPE
   * Unrecognized character follows "\\\\".
   * @newin{2,16}
   *
   *  @var Code QUANTIFIERS_OUT_OF_ORDER
   * Numbers out of order in "{}"
   * quantifier. @newin{2,16}
   *
   *  @var Code QUANTIFIER_TOO_BIG
   * Number too big in "{}" quantifier.
   * @newin{2,16}
   *
   *  @var Code UNTERMINATED_CHARACTER_CLASS
   * Missing terminating "]" for
   * character class. @newin{2,16}
   *
   *  @var Code INVALID_ESCAPE_IN_CHARACTER_CLASS
   * Invalid escape sequence
   * in character class. @newin{2,16}
   *
   *  @var Code RANGE_OUT_OF_ORDER
   * Range out of order in character class.
   * @newin{2,16}
   *
   *  @var Code NOTHING_TO_REPEAT
   * Nothing to repeat. @newin{2,16}
   *
   *  @var Code UNRECOGNIZED_CHARACTER
   * Unrecognized character after "(?",
   * "(?<" or "(?P". @newin{2,16}
   *
   *  @var Code POSIX_NAMED_CLASS_OUTSIDE_CLASS
   * POSIX named classes are
   * supported only within a class. @newin{2,16}
   *
   *  @var Code UNMATCHED_PARENTHESIS
   * Missing terminating ")" or ")"
   * without opening "(". @newin{2,16}
   *
   *  @var Code INEXISTENT_SUBPATTERN_REFERENCE
   * Reference to non-existent
   * subpattern. @newin{2,16}
   *
   *  @var Code UNTERMINATED_COMMENT
   * Missing terminating ")" after comment.
   * @newin{2,16}
   *
   *  @var Code EXPRESSION_TOO_LARGE
   * Regular expression too large.
   * @newin{2,16}
   *
   *  @var Code MEMORY_ERROR
   * Failed to get memory. @newin{2,16}
   *
   *  @var Code VARIABLE_LENGTH_LOOKBEHIND
   * Lookbehind assertion is not
   * fixed length. @newin{2,16}
   *
   *  @var Code MALFORMED_CONDITION
   * Malformed number or name after "(?(".
   * @newin{2,16}
   *
   *  @var Code TOO_MANY_CONDITIONAL_BRANCHES
   * Conditional group contains
   * more than two branches. @newin{2,16}
   *
   *  @var Code ASSERTION_EXPECTED
   * Assertion expected after "(?(".
   * @newin{2,16}
   *
   *  @var Code UNKNOWN_POSIX_CLASS_NAME
   * Unknown POSIX class name.
   * @newin{2,16}
   *
   *  @var Code POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED
   * POSIX collating
   * elements are not supported. @newin{2,16}
   *
   *  @var Code HEX_CODE_TOO_LARGE
   * Character value in "\\\\x{...}" sequence
   * is too large. @newin{2,16}
   *
   *  @var Code INVALID_CONDITION
   * Invalid condition "(?(0)". @newin{2,16}
   *
   *  @var Code SINGLE_BYTE_MATCH_IN_LOOKBEHIND
   * \\\\C not allowed in
   * lookbehind assertion. @newin{2,16}
   *
   *  @var Code INFINITE_LOOP
   * Recursive call could loop indefinitely.
   * @newin{2,16}
   *
   *  @var Code MISSING_SUBPATTERN_NAME_TERMINATOR
   * Missing terminator
   * in subpattern name. @newin{2,16}
   *
   *  @var Code DUPLICATE_SUBPATTERN_NAME
   * Two named subpatterns have
   * the same name. @newin{2,16}
   *
   *  @var Code MALFORMED_PROPERTY
   * Malformed "\\\\P" or "\\\\p" sequence.
   * @newin{2,16}
   *
   *  @var Code UNKNOWN_PROPERTY
   * Unknown property name after "\\\\P" or
   * "\\\\p". @newin{2,16}
   *
   *  @var Code SUBPATTERN_NAME_TOO_LONG
   * Subpattern name is too long
   * (maximum 32 characters). @newin{2,16}
   *
   *  @var Code TOO_MANY_SUBPATTERNS
   * Too many named subpatterns (maximum
   * 10,000). @newin{2,16}
   *
   *  @var Code INVALID_OCTAL_VALUE
   * Octal value is greater than "\\\\377".
   * @newin{2,16}
   *
   *  @var Code TOO_MANY_BRANCHES_IN_DEFINE
   * "DEFINE" group contains more
   * than one branch. @newin{2,16}
   *
   *  @var Code DEFINE_REPETION
   * Repeating a "DEFINE" group is not allowed.
   * This error is never raised. @newin{2,16} Deprecated: 2.34.
   *
   *  @var Code INCONSISTENT_NEWLINE_OPTIONS
   * Inconsistent newline options.
   * @newin{2,16}
   *
   *  @var Code MISSING_BACK_REFERENCE
   * "\\\\g" is not followed by a braced,
   * angle-bracketed, or quoted name or number, or by a plain number. @newin{2,16}
   *
   *  @var Code INVALID_RELATIVE_REFERENCE
   * Relative reference must not be zero. @newin{2,34}
   *
   *  @var Code BACKTRACKING_CONTROL_VERB_ARGUMENT_FORBIDDEN
   * The backtracing
   * control verb used does not allow an argument. @newin{2,34}
   *
   *  @var Code UNKNOWN_BACKTRACKING_CONTROL_VERB
   * Unknown backtracing
   * control verb. @newin{2,34}
   *
   *  @var Code NUMBER_TOO_BIG
   * Number is too big in escape sequence. @newin{2,34}
   *
   *  @var Code MISSING_SUBPATTERN_NAME
   * Missing subpattern name. @newin{2,34}
   *
   *  @var Code MISSING_DIGIT
   * Missing digit. @newin{2,34}
   *
   *  @var Code INVALID_DATA_CHARACTER
   * In JavaScript compatibility mode,
   * "[" is an invalid data character. @newin{2,34}
   *
   *  @var Code EXTRA_SUBPATTERN_NAME
   * Different names for subpatterns of the
   * same number are not allowed. @newin{2,34}
   *
   *  @var Code BACKTRACKING_CONTROL_VERB_ARGUMENT_REQUIRED
   * The backtracing control
   * verb requires an argument. @newin{2,34}
   *
   *  @var Code INVALID_CONTROL_CHAR
   * "\\\\c" must be followed by an ASCII
   * character. @newin{2,34}
   *
   *  @var Code MISSING_NAME
   * "\\\\k" is not followed by a braced, angle-bracketed, or
   * quoted name. @newin{2,34}
   *
   *  @var Code NOT_SUPPORTED_IN_CLASS
   * "\\\\N" is not supported in a class. @newin{2,34}
   *
   *  @var Code TOO_MANY_FORWARD_REFERENCES
   * Too many forward references. @newin{2,34}
   *
   *  @var Code NAME_TOO_LONG
   * The name is too long in "(*MARK)", "(*PRUNE)",
   * "(*SKIP)", or "(*THEN)". @newin{2,34}
   *
   *  @var Code CHARACTER_VALUE_TOO_LARGE
   * The character value in the \\\\u sequence is
   * too large. @newin{2,34}
   *
   *  @enum Code
   *
   * %Error codes returned by regular expressions functions.
   *
   * @newin{2,14}
   */
  enum Code
  {
    COMPILE = 0,
    OPTIMIZE = 1,
    REPLACE = 2,
    MATCH = 3,
    INTERNAL = 4,
    STRAY_BACKSLASH = 101,
    MISSING_CONTROL_CHAR = 102,
    UNRECOGNIZED_ESCAPE = 103,
    QUANTIFIERS_OUT_OF_ORDER = 104,
    QUANTIFIER_TOO_BIG = 105,
    UNTERMINATED_CHARACTER_CLASS = 106,
    INVALID_ESCAPE_IN_CHARACTER_CLASS = 107,
    RANGE_OUT_OF_ORDER = 108,
    NOTHING_TO_REPEAT = 109,
    UNRECOGNIZED_CHARACTER = 112,
    POSIX_NAMED_CLASS_OUTSIDE_CLASS = 113,
    UNMATCHED_PARENTHESIS = 114,
    INEXISTENT_SUBPATTERN_REFERENCE = 115,
    UNTERMINATED_COMMENT = 118,
    EXPRESSION_TOO_LARGE = 120,
    MEMORY_ERROR = 121,
    VARIABLE_LENGTH_LOOKBEHIND = 125,
    MALFORMED_CONDITION = 126,
    TOO_MANY_CONDITIONAL_BRANCHES = 127,
    ASSERTION_EXPECTED = 128,
    UNKNOWN_POSIX_CLASS_NAME = 130,
    POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED = 131,
    HEX_CODE_TOO_LARGE = 134,
    INVALID_CONDITION = 135,
    SINGLE_BYTE_MATCH_IN_LOOKBEHIND = 136,
    INFINITE_LOOP = 140,
    MISSING_SUBPATTERN_NAME_TERMINATOR = 142,
    DUPLICATE_SUBPATTERN_NAME = 143,
    MALFORMED_PROPERTY = 146,
    UNKNOWN_PROPERTY = 147,
    SUBPATTERN_NAME_TOO_LONG = 148,
    TOO_MANY_SUBPATTERNS = 149,
    INVALID_OCTAL_VALUE = 151,
    TOO_MANY_BRANCHES_IN_DEFINE = 154,
    DEFINE_REPETION = 155,
    INCONSISTENT_NEWLINE_OPTIONS = 156,
    MISSING_BACK_REFERENCE = 157,
    INVALID_RELATIVE_REFERENCE = 158,
    BACKTRACKING_CONTROL_VERB_ARGUMENT_FORBIDDEN = 159,
    UNKNOWN_BACKTRACKING_CONTROL_VERB = 160,
    NUMBER_TOO_BIG = 161,
    MISSING_SUBPATTERN_NAME = 162,
    MISSING_DIGIT = 163,
    INVALID_DATA_CHARACTER = 164,
    EXTRA_SUBPATTERN_NAME = 165,
    BACKTRACKING_CONTROL_VERB_ARGUMENT_REQUIRED = 166,
    INVALID_CONTROL_CHAR = 168,
    MISSING_NAME = 169,
    NOT_SUPPORTED_IN_CLASS = 171,
    TOO_MANY_FORWARD_REFERENCES = 172,
    NAME_TOO_LONG = 175,
    CHARACTER_VALUE_TOO_LARGE = 176
  };

  GLIBMM_API RegexError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit RegexError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


class MatchInfo;

/** Perl-compatible regular expressions - matches strings against regular expressions.
 *
 * The Glib::Regex functions implement regular expression pattern matching using
 * syntax and semantics similar to Perl regular expression.
 *
 * Some functions accept a start_position argument, setting it differs from just
 * passing over a shortened string and setting REGEX_MATCH_NOTBOL in the case
 * of a pattern that begins with any kind of lookbehind assertion. For example,
 * consider the pattern "\Biss\B" which finds occurrences of "iss" in the middle
 * of words. ("\B" matches only if the current position in the subject is not a
 * word boundary.) When applied to the string "Mississipi" from the fourth byte,
 * namely "issipi", it does not match, because "\B" is always false at the
 * start of the subject, which is deemed to be a word boundary. However, if
 * the entire string is passed , but with start_position set to 4, it finds the
 * second occurrence of "iss" because it is able to look behind the starting point
 * to discover that it is preceded by a letter.
 *
 * Note that, unless you set the REGEX_RAW flag, all the strings passed to these
 * functions must be encoded in UTF-8. The lengths and the positions inside the
 *  strings are in bytes and not in characters, so, for instance,
 * "\xc3\xa0" (i.e. "à") is two bytes long but it is treated as a single
 * character. If you set REGEX_RAW the strings can be non-valid UTF-8 strings
 * and a byte is treated as a character, so "\xc3\xa0" is two bytes and
 * two characters long.
 *
 * When matching a pattern, "\n" matches only against a "\n" character in the
 * string, and "\r" matches only a "\r" character. To match any newline sequence
 * use "\R". This particular group matches either the two-character sequence
 * CR + LF ("\r\n"), or one of the single characters LF (linefeed, U+000A, "\n"),
 *  VT (vertical tab, U+000B, "\v"), FF (formfeed, U+000C, "\f"), CR (carriage
 * return, U+000D, "\r"), NEL (next line, U+0085), LS (line separator, U+2028),
 * or PS (paragraph separator, U+2029).
 *
 * The behaviour of the dot, circumflex, and dollar metacharacters are affected
 * by newline characters, the default is to recognize any newline character (the
 * same characters recognized by "\R"). This can be changed with REGEX_NEWLINE_CR,
 * REGEX_NEWLINE_LF and REGEX_NEWLINE_CRLF compile options, and with
 * REGEX_MATCH_NEWLINE_ANY, REGEX_MATCH_NEWLINE_CR, REGEX_MATCH_NEWLINE_LF
 * and REGEX_MATCH_NEWLINE_CRLF match options. These settings are also
 * relevant when compiling a pattern if REGEX_EXTENDED is set, and an unescaped
 * "#" outside a character class is encountered. This indicates a comment that
 * lasts until after the next newline.
 *
 * Creating and manipulating the same Glib::Regex class from different threads is
 * not a problem as Glib::Regex does not modify its internal state between creation and
 * destruction, on the other hand Glib::MatchInfo is not threadsafe.
 *
 * The regular expressions low level functionalities are obtained through the
 * excellent PCRE library written by Philip Hazel.
 *
 * @newin{2,14}
 */
class GLIBMM_API Regex final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Regex;
  using BaseObjectType = GRegex;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GRegex*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GRegex*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GRegex*;

  Regex() = delete;

  // noncopyable
  Regex(const Regex&) = delete;
  auto operator=(const Regex&) -> Regex& = delete;

protected:
  // Do not derive this.  Glib::Regex can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** @addtogroup glibmmEnums glibmm Enums and Flags */

  /**
   *  @var CompileFlags DEFAULT
   * No special options set. @newin{2,74}
   *
   *  @var CompileFlags CASELESS
   * Letters in the pattern match both upper- and
   * lowercase letters. This option can be changed within a pattern
   * by a "(?i)" option setting.
   *
   *  @var CompileFlags MULTILINE
   * By default, GRegex treats the strings as consisting
   * of a single line of characters (even if it actually contains
   * newlines). The "start of line" metacharacter ("^") matches only
   * at the start of the string, while the "end of line" metacharacter
   * ("$") matches only at the end of the string, or before a terminating
   * newline (unless Glib::Regex::CompileFlags::DOLLAR_ENDONLY is set). When
   * Glib::Regex::CompileFlags::MULTILINE is set, the "start of line" and "end of line"
   * constructs match immediately following or immediately before any
   * newline in the string, respectively, as well as at the very start
   * and end. This can be changed within a pattern by a "(?m)" option
   * setting.
   *
   *  @var CompileFlags DOTALL
   * A dot metacharacter (".") in the pattern matches all
   * characters, including newlines. Without it, newlines are excluded.
   * This option can be changed within a pattern by a ("?s") option setting.
   *
   *  @var CompileFlags EXTENDED
   * Whitespace data characters in the pattern are
   * totally ignored except when escaped or inside a character class.
   * Whitespace does not include the VT character (code 11). In addition,
   * characters between an unescaped "#" outside a character class and
   * the next newline character, inclusive, are also ignored. This can
   * be changed within a pattern by a "(?x)" option setting.
   *
   *  @var CompileFlags ANCHORED
   * The pattern is forced to be "anchored", that is,
   * it is constrained to match only at the first matching point in the
   * string that is being searched. This effect can also be achieved by
   * appropriate constructs in the pattern itself such as the "^"
   * metacharacter.
   *
   *  @var CompileFlags DOLLAR_ENDONLY
   * A dollar metacharacter ("$") in the pattern
   * matches only at the end of the string. Without this option, a
   * dollar also matches immediately before the final character if
   * it is a newline (but not before any other newlines). This option
   * is ignored if Glib::Regex::CompileFlags::MULTILINE is set.
   *
   *  @var CompileFlags UNGREEDY
   * Inverts the "greediness" of the quantifiers so that
   * they are not greedy by default, but become greedy if followed by "?".
   * It can also be set by a "(?U)" option setting within the pattern.
   *
   *  @var CompileFlags RAW
   * Usually strings must be valid UTF-8 strings, using this
   * flag they are considered as a raw sequence of bytes.
   *
   *  @var CompileFlags NO_AUTO_CAPTURE
   * Disables the use of numbered capturing
   * parentheses in the pattern. Any opening parenthesis that is not
   * followed by "?" behaves as if it were followed by "?:" but named
   * parentheses can still be used for capturing (and they acquire numbers
   * in the usual way).
   *
   *  @var CompileFlags OPTIMIZE
   * Since 2.74 and the port to pcre2, requests JIT
   * compilation, which, if the just-in-time compiler is available, further
   * processes a compiled pattern into machine code that executes much
   * faster. However, it comes at the cost of extra processing before the
   * match is performed, so it is most beneficial to use this when the same
   * compiled pattern is used for matching many times. Before 2.74 this
   * option used the built-in non-JIT optimizations in pcre1.
   *
   *  @var CompileFlags FIRSTLINE
   * Limits an unanchored pattern to match before (or at) the
   * first newline. @newin{2,34}
   *
   *  @var CompileFlags DUPNAMES
   * Names used to identify capturing subpatterns need not
   * be unique. This can be helpful for certain types of pattern when it
   * is known that only one instance of the named subpattern can ever be
   * matched.
   *
   *  @var CompileFlags NEWLINE_CR
   * Usually any newline character or character sequence is
   * recognized. If this option is set, the only recognized newline character
   * is '\\r'.
   *
   *  @var CompileFlags NEWLINE_LF
   * Usually any newline character or character sequence is
   * recognized. If this option is set, the only recognized newline character
   * is '\\n'.
   *
   *  @var CompileFlags NEWLINE_CRLF
   * Usually any newline character or character sequence is
   * recognized. If this option is set, the only recognized newline character
   * sequence is '\\r\\n'.
   *
   *  @var CompileFlags NEWLINE_ANYCRLF
   * Usually any newline character or character sequence
   * is recognized. If this option is set, the only recognized newline character
   * sequences are '\\r', '\\n', and '\\r\\n'. @newin{2,34}
   *
   *  @var CompileFlags BSR_ANYCRLF
   * Usually any newline character or character sequence
   * is recognised. If this option is set, then "\\R" only recognizes the newline
   * characters '\\r', '\\n' and '\\r\\n'. @newin{2,34}
   *
   *  @var CompileFlags JAVASCRIPT_COMPAT
   * Changes behaviour so that it is compatible with
   * JavaScript rather than PCRE. Since GLib 2.74 this is no longer supported,
   * as libpcre2 does not support it. @newin{2,34} Deprecated: 2.74.
   *
   *  @enum CompileFlags
   *
   * Flags specifying compile-time options.
   *
   * @newin{2,14}
   *
   * @ingroup glibmmEnums
   * @par Bitwise operators:
   * <tt>Regex::CompileFlags operator|(Regex::CompileFlags, Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags operator&(Regex::CompileFlags, Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags operator^(Regex::CompileFlags, Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags operator~(Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags& operator|=(Regex::CompileFlags&, Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags& operator&=(Regex::CompileFlags&, Regex::CompileFlags)</tt><br>
   * <tt>Regex::CompileFlags& operator^=(Regex::CompileFlags&, Regex::CompileFlags)</tt><br>
   */
  enum class CompileFlags
  {
    DEFAULT = 0x0,
    CASELESS = 1 << 0,
    MULTILINE = 1 << 1,
    DOTALL = 1 << 2,
    EXTENDED = 1 << 3,
    ANCHORED = 1 << 4,
    DOLLAR_ENDONLY = 1 << 5,
    UNGREEDY = 1 << 9,
    RAW = 1 << 11,
    NO_AUTO_CAPTURE = 1 << 12,
    OPTIMIZE = 1 << 13,
    FIRSTLINE = 1 << 18,
    DUPNAMES = 1 << 19,
    NEWLINE_CR = 1 << 20,
    NEWLINE_LF = 1 << 21,
    NEWLINE_CRLF = 0x300000,
    NEWLINE_ANYCRLF = 0x500000,
    BSR_ANYCRLF = 1 << 23,
    JAVASCRIPT_COMPAT = 1 << 25
  };


  /**
   *  @var MatchFlags DEFAULT
   * No special options set. @newin{2,74}
   *
   *  @var MatchFlags ANCHORED
   * The pattern is forced to be "anchored", that is,
   * it is constrained to match only at the first matching point in the
   * string that is being searched. This effect can also be achieved by
   * appropriate constructs in the pattern itself such as the "^"
   * metacharacter.
   *
   *  @var MatchFlags NOTBOL
   * Specifies that first character of the string is
   * not the beginning of a line, so the circumflex metacharacter should
   * not match before it. Setting this without Glib::Regex::CompileFlags::MULTILINE (at
   * compile time) causes circumflex never to match. This option affects
   * only the behaviour of the circumflex metacharacter, it does not
   * affect "\\A".
   *
   *  @var MatchFlags NOTEOL
   * Specifies that the end of the subject string is
   * not the end of a line, so the dollar metacharacter should not match
   * it nor (except in multiline mode) a newline immediately before it.
   * Setting this without Glib::Regex::CompileFlags::MULTILINE (at compile time) causes
   * dollar never to match. This option affects only the behaviour of
   * the dollar metacharacter, it does not affect "\\Z" or "\\z".
   *
   *  @var MatchFlags NOTEMPTY
   * An empty string is not considered to be a valid
   * match if this option is set. If there are alternatives in the pattern,
   * they are tried. If all the alternatives match the empty string, the
   * entire match fails. For example, if the pattern "a?b?" is applied to
   * a string not beginning with "a" or "b", it matches the empty string
   * at the start of the string. With this flag set, this match is not
   * valid, so GRegex searches further into the string for occurrences
   * of "a" or "b".
   *
   *  @var MatchFlags PARTIAL
   * Turns on the partial matching feature, for more
   * documentation on partial matching see g_match_info_is_partial_match().
   *
   *  @var MatchFlags NEWLINE_CR
   * Overrides the newline definition set when
   * creating a new Regex, setting the '\\r' character as line terminator.
   *
   *  @var MatchFlags NEWLINE_LF
   * Overrides the newline definition set when
   * creating a new Regex, setting the '\\n' character as line terminator.
   *
   *  @var MatchFlags NEWLINE_CRLF
   * Overrides the newline definition set when
   * creating a new Regex, setting the '\\r\\n' characters sequence as line terminator.
   *
   *  @var MatchFlags NEWLINE_ANY
   * Overrides the newline definition set when
   * creating a new Regex, any Unicode newline sequence
   * is recognised as a newline. These are '\\r', '\\n' and '\\rn', and the
   * single characters U+000B LINE TABULATION, U+000C FORM FEED (FF),
   * U+0085 NEXT LINE (NEL), U+2028 LINE SEPARATOR and
   * U+2029 PARAGRAPH SEPARATOR.
   *
   *  @var MatchFlags NEWLINE_ANYCRLF
   * Overrides the newline definition set when
   * creating a new Regex; any '\\r', '\\n', or '\\r\\n' character sequence
   * is recognized as a newline. @newin{2,34}
   *
   *  @var MatchFlags BSR_ANYCRLF
   * Overrides the newline definition for "\\R" set when
   * creating a new Regex; only '\\r', '\\n', or '\\r\\n' character sequences
   * are recognized as a newline by "\\R". @newin{2,34}
   *
   *  @var MatchFlags BSR_ANY
   * Overrides the newline definition for "\\R" set when
   * creating a new Regex; any Unicode newline character or character sequence
   * are recognized as a newline by "\\R". These are '\\r', '\\n' and '\\rn', and the
   * single characters U+000B LINE TABULATION, U+000C FORM FEED (FF),
   * U+0085 NEXT LINE (NEL), U+2028 LINE SEPARATOR and
   * U+2029 PARAGRAPH SEPARATOR. @newin{2,34}
   *
   *  @var MatchFlags PARTIAL_SOFT
   * An alias for Glib::Regex::MatchFlags::PARTIAL. @newin{2,34}
   *
   *  @var MatchFlags PARTIAL_HARD
   * Turns on the partial matching feature. In contrast to
   * to Glib::Regex::MatchFlags::PARTIAL_SOFT, this stops matching as soon as a partial match
   * is found, without continuing to search for a possible complete match. See
   * g_match_info_is_partial_match() for more information. @newin{2,34}
   *
   *  @var MatchFlags NOTEMPTY_ATSTART
   * Like Glib::Regex::MatchFlags::NOTEMPTY, but only applied to
   * the start of the matched string. For anchored
   * patterns this can only happen for pattern containing "\\K". @newin{2,34}
   *
   *  @enum MatchFlags
   *
   * Flags specifying match-time options.
   *
   * @newin{2,14}
   *
   * @ingroup glibmmEnums
   * @par Bitwise operators:
   * <tt>Regex::MatchFlags operator|(Regex::MatchFlags, Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags operator&(Regex::MatchFlags, Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags operator^(Regex::MatchFlags, Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags operator~(Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags& operator|=(Regex::MatchFlags&, Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags& operator&=(Regex::MatchFlags&, Regex::MatchFlags)</tt><br>
   * <tt>Regex::MatchFlags& operator^=(Regex::MatchFlags&, Regex::MatchFlags)</tt><br>
   */
  enum class MatchFlags
  {
    DEFAULT = 0x0,
    ANCHORED = 1 << 4,
    NOTBOL = 1 << 7,
    NOTEOL = 1 << 8,
    NOTEMPTY = 1 << 10,
    PARTIAL = 1 << 15,
    NEWLINE_CR = 1 << 20,
    NEWLINE_LF = 1 << 21,
    NEWLINE_CRLF = 0x300000,
    NEWLINE_ANY = 1 << 22,
    NEWLINE_ANYCRLF = 0x500000,
    BSR_ANYCRLF = 1 << 23,
    BSR_ANY = 1 << 24,
    PARTIAL_SOFT = 0x8000,
    PARTIAL_HARD = 1 << 27,
    NOTEMPTY_ATSTART = 1 << 28
  };


  /// @throws Glib::RegexError
  static auto create(Glib::UStringView pattern, CompileFlags compile_options = static_cast<CompileFlags>(0), MatchFlags match_options = static_cast<MatchFlags>(0)) -> Glib::RefPtr<Glib::Regex>;


  /** Gets the pattern string associated with @a regex, i.e.\ a copy of
   * the string passed to g_regex_new().
   *
   * @newin{2,14}
   *
   * @return The pattern of @a regex.
   */
  auto get_pattern() const -> Glib::ustring;

  /** Returns the number of the highest back reference
   * in the pattern, or 0 if the pattern does not contain
   * back references.
   *
   * @newin{2,14}
   *
   * @return The number of the highest back reference.
   */
  auto get_max_backref() const -> int;

  /** Returns the number of capturing subpatterns in the pattern.
   *
   * @newin{2,14}
   *
   * @return The number of capturing subpatterns.
   */
  auto get_capture_count() const -> int;

  /** Checks whether the pattern contains explicit CR or LF references.
   *
   * @newin{2,34}
   *
   * @return <tt>true</tt> if the pattern contains explicit CR or LF references.
   */
  auto get_has_cr_or_lf() const -> bool;

  /** Gets the number of characters in the longest lookbehind assertion in the
   * pattern. This information is useful when doing multi-segment matching using
   * the partial matching facilities.
   *
   * @newin{2,38}
   *
   * @return The number of characters in the longest lookbehind assertion.
   */
  auto get_max_lookbehind() const -> int;

  /** Retrieves the number of the subexpression named @a name.
   *
   * @newin{2,14}
   *
   * @param name Name of the subexpression.
   * @return The number of the subexpression or -1 if @a name
   * does not exists.
   */
  auto get_string_number(Glib::UStringView name) const -> int;

  /** Returns the compile options that @a regex was created with.
   *
   * Depending on the version of PCRE that is used, this may or may not
   * include flags set by option expressions such as `(?i)` found at the
   * top-level within the compiled pattern.
   *
   * @newin{2,26}
   *
   * @return Flags from Glib::Regex::CompileFlags.
   */
  auto get_compile_flags() const -> CompileFlags;

  /** Returns the match options that @a regex was created with.
   *
   * @newin{2,26}
   *
   * @return Flags from Glib::Regex::MatchFlags.
   */
  auto get_match_flags() const -> MatchFlags;

  static auto escape_string(const Glib::ustring& string) -> Glib::ustring;


  /** Scans for a match in @a string for @a pattern.
   *
   * This function is equivalent to g_regex_match() but it does not
   * require to compile the pattern with g_regex_new(), avoiding some
   * lines of code when you need just to do a match without extracting
   * substrings, capture counts, and so on.
   *
   * If this function is to be called on the same @a pattern more than
   * once, it's more efficient to compile the pattern once with
   * g_regex_new() and then use g_regex_match().
   *
   * @newin{2,14}
   *
   * @param pattern The regular expression.
   * @param string The string to scan for matches.
   * @param compile_options Compile options for the regular expression, or 0.
   * @param match_options Match options, or 0.
   * @return <tt>true</tt> if the string matched, <tt>false</tt> otherwise.
   */
  static auto match_simple(Glib::UStringView pattern, Glib::UStringView string, CompileFlags compile_options =  static_cast<CompileFlags>(0), MatchFlags match_options =  static_cast<MatchFlags>(0)) -> bool;


  /** Scans for a match in @a string for the pattern in @a regex.
   * The @a match_options are combined with the match options specified
   * when the @a regex structure was created, letting you have more
   * flexibility in reusing Regex structures.
   *
   * Unless Glib::Regex::CompileFlags::RAW is specified in the options, @a string must be valid UTF-8.
   *
   * A MatchInfo structure, used to get information on the match,
   * is stored in @a match_info if not <tt>nullptr</tt>. Note that if @a match_info
   * is not <tt>nullptr</tt> then it is created even if the function returns <tt>false</tt>,
   * i.e. you must free it regardless if regular expression actually matched.
   *
   * To retrieve all the non-overlapping matches of the pattern in
   * string you can use g_match_info_next().
   *
   *
   * [C example ellipted]
   *
   *  @a string is not copied and is used in MatchInfo internally. If
   * you use any MatchInfo method (except g_match_info_free()) after
   * freeing or modifying @a string then the behaviour is undefined.
   *
   * @newin{2,14}
   *
   * @param string The string to scan for matches.
   * @param match_options Match options.
   * @param match_info Pointer to location where to store
   * the MatchInfo, or <tt>nullptr</tt> if you do not need it.
   * @return <tt>true</tt> is the string matched, <tt>false</tt> otherwise.
   */

  auto match(
    Glib::UStringView string,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;

  /// A match() method not requiring a Glib::MatchInfo.
  auto match(Glib::UStringView string, MatchFlags match_options = static_cast<MatchFlags>(0)) -> bool;

  /** A match() method with a start position and a Glib::MatchInfo.
   * @throws Glib::RegexError
   */
  auto match(
    Glib::UStringView string,
    int start_position,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;


  /** Scans for a match in @a string for the pattern in @a regex.
   * The @a match_options are combined with the match options specified
   * when the @a regex structure was created, letting you have more
   * flexibility in reusing Regex structures.
   *
   * Setting @a start_position differs from just passing over a shortened
   * string and setting Glib::Regex::MatchFlags::NOTBOL in the case of a pattern
   * that begins with any kind of lookbehind assertion, such as "\\b".
   *
   * Unless Glib::Regex::CompileFlags::RAW is specified in the options, @a string must be valid UTF-8.
   *
   * A MatchInfo structure, used to get information on the match, is
   * stored in @a match_info if not <tt>nullptr</tt>. Note that if @a match_info is
   * not <tt>nullptr</tt> then it is created even if the function returns <tt>false</tt>,
   * i.e. you must free it regardless if regular expression actually
   * matched.
   *
   *  @a string is not copied and is used in MatchInfo internally. If
   * you use any MatchInfo method (except g_match_info_free()) after
   * freeing or modifying @a string then the behaviour is undefined.
   *
   * To retrieve all the non-overlapping matches of the pattern in
   * string you can use g_match_info_next().
   *
   *
   * [C example ellipted]
   *
   * @newin{2,14}
   *
   * @param string The string to scan for matches.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param match_options Match options.
   * @param match_info Pointer to location where to store
   * the MatchInfo, or <tt>nullptr</tt> if you do not need it.
   * @return <tt>true</tt> is the string matched, <tt>false</tt> otherwise.
   *
   * @throws Glib::RegexError
   */

  auto match(
    Glib::UStringView string,
    gssize string_len,
    int start_position,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;

  /** A match() method with a start position not requiring a Glib::MatchInfo.
   * @throws Glib::RegexError
   */
  auto match(Glib::UStringView string, int start_position, MatchFlags match_options) -> bool;

  /** A match() method with a string length and start position not requiring a
   * Glib::MatchInfo.
   */
  auto match(Glib::UStringView string, gssize string_len, int start_position, MatchFlags match_options) -> bool;


  /** Using the standard algorithm for regular expression matching only
   * the longest match in the string is retrieved. This function uses
   * a different algorithm so it can retrieve all the possible matches.
   * For more documentation see g_regex_match_all_full().
   *
   * A MatchInfo structure, used to get information on the match, is
   * stored in @a match_info if not <tt>nullptr</tt>. Note that if @a match_info is
   * not <tt>nullptr</tt> then it is created even if the function returns <tt>false</tt>,
   * i.e. you must free it regardless if regular expression actually
   * matched.
   *
   *  @a string is not copied and is used in MatchInfo internally. If
   * you use any MatchInfo method (except g_match_info_free()) after
   * freeing or modifying @a string then the behaviour is undefined.
   *
   * @newin{2,14}
   *
   * @param string The string to scan for matches.
   * @param match_options Match options.
   * @param match_info Pointer to location where to store
   * the MatchInfo, or <tt>nullptr</tt> if you do not need it.
   * @return <tt>true</tt> is the string matched, <tt>false</tt> otherwise.
   */

  auto match_all(
    Glib::UStringView string,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;

  /// A match_all() method not requiring a Glib::MatchInfo.
  auto match_all(Glib::UStringView string, MatchFlags match_options = static_cast<MatchFlags>(0)) -> bool;

  /** A match_all() method with a start positon and a Glib::MatchInfo.
   * @throws Glib::RegexError
   */
  auto match_all(
    Glib::UStringView string,
    int start_position,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;


  /** Using the standard algorithm for regular expression matching only
   * the longest match in the @a string is retrieved, it is not possible
   * to obtain all the available matches. For instance matching
   * "<a> <b> <c>" against the pattern "<.*>"
   * you get "<a> <b> <c>".
   *
   * This function uses a different algorithm (called DFA, i.e. deterministic
   * finite automaton), so it can retrieve all the possible matches, all
   * starting at the same point in the string. For instance matching
   * "<a> <b> <c>" against the pattern "<.*>;"
   * you would obtain three matches: "<a> <b> <c>",
   * "<a> <b>" and "<a>".
   *
   * The number of matched strings is retrieved using
   * g_match_info_get_match_count(). To obtain the matched strings and
   * their position you can use, respectively, g_match_info_fetch() and
   * g_match_info_fetch_pos(). Note that the strings are returned in
   * reverse order of length; that is, the longest matching string is
   * given first.
   *
   * Note that the DFA algorithm is slower than the standard one and it
   * is not able to capture substrings, so backreferences do not work.
   *
   * Setting @a start_position differs from just passing over a shortened
   * string and setting Glib::Regex::MatchFlags::NOTBOL in the case of a pattern
   * that begins with any kind of lookbehind assertion, such as "\\b".
   *
   * Unless Glib::Regex::CompileFlags::RAW is specified in the options, @a string must be valid UTF-8.
   *
   * A MatchInfo structure, used to get information on the match, is
   * stored in @a match_info if not <tt>nullptr</tt>. Note that if @a match_info is
   * not <tt>nullptr</tt> then it is created even if the function returns <tt>false</tt>,
   * i.e. you must free it regardless if regular expression actually
   * matched.
   *
   *  @a string is not copied and is used in MatchInfo internally. If
   * you use any MatchInfo method (except g_match_info_free()) after
   * freeing or modifying @a string then the behaviour is undefined.
   *
   * @newin{2,14}
   *
   * @param string The string to scan for matches.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param match_options Match options.
   * @param match_info Pointer to location where to store
   * the MatchInfo, or <tt>nullptr</tt> if you do not need it.
   * @return <tt>true</tt> is the string matched, <tt>false</tt> otherwise.
   *
   * @throws Glib::RegexError
   */

  auto match_all(
    Glib::UStringView string,
    gssize string_len,
    int start_position,
    Glib::MatchInfo& match_info,
    MatchFlags match_options = static_cast<MatchFlags>(0)
  ) -> bool;

  /** A match_all() method with a start position not requiring a Glib::MatchInfo.
   * @throws Glib::RegexError
   */
  auto match_all(Glib::UStringView string, int start_position, MatchFlags match_options) -> bool;

  /** A match_all() method with a start position and a string length not
   * requiring a Glib::MatchInfo.
   * @throws Glib::RegexError
   */
  auto match_all(Glib::UStringView string, gssize string_len, int start_position, MatchFlags match_options) -> bool;


  /** Breaks the string on the pattern, and returns an array of
   * the tokens. If the pattern contains capturing parentheses,
   * then the text for each of the substrings will also be returned.
   * If the pattern does not match anywhere in the string, then the
   * whole string is returned as the first token.
   *
   * This function is equivalent to g_regex_split() but it does
   * not require to compile the pattern with g_regex_new(), avoiding
   * some lines of code when you need just to do a split without
   * extracting substrings, capture counts, and so on.
   *
   * If this function is to be called on the same @a pattern more than
   * once, it's more efficient to compile the pattern once with
   * g_regex_new() and then use g_regex_split().
   *
   * As a special case, the result of splitting the empty string ""
   * is an empty vector, not a vector containing a single string.
   * The reason for this special case is that being able to represent
   * an empty vector is typically more useful than consistent handling
   * of empty elements. If you do need to represent empty elements,
   * you'll need to check for the empty string before calling this
   * function.
   *
   * A pattern that can match empty strings splits @a string into
   * separate characters wherever it matches the empty string between
   * characters. For example splitting "ab c" using as a separator
   * "\\s*", you will get "a", "b" and "c".
   *
   * @newin{2,14}
   *
   * @param pattern The regular expression.
   * @param string The string to scan for matches.
   * @param compile_options Compile options for the regular expression, or 0.
   * @param match_options Match options, or 0.
   * @return A <tt>nullptr</tt>-terminated array of strings.
   */
  static auto split_simple(Glib::UStringView pattern, Glib::UStringView string, CompileFlags compile_options =  static_cast<CompileFlags>(0), MatchFlags match_options =  static_cast<MatchFlags>(0)) -> std::vector<Glib::ustring>;

  /** Breaks the string on the pattern, and returns an array of the tokens.
   * If the pattern contains capturing parentheses, then the text for each
   * of the substrings will also be returned. If the pattern does not match
   * anywhere in the string, then the whole string is returned as the first
   * token.
   *
   * As a special case, the result of splitting the empty string "" is an
   * empty vector, not a vector containing a single string. The reason for
   * this special case is that being able to represent an empty vector is
   * typically more useful than consistent handling of empty elements. If
   * you do need to represent empty elements, you'll need to check for the
   * empty string before calling this function.
   *
   * A pattern that can match empty strings splits @a string into separate
   * characters wherever it matches the empty string between characters.
   * For example splitting "ab c" using as a separator "\\s*", you will get
   * "a", "b" and "c".
   *
   * @newin{2,14}
   *
   * @param string The string to split with the pattern.
   * @param match_options Match time option flags.
   * @return A <tt>nullptr</tt>-terminated gchar ** array.
   */
  auto split(Glib::UStringView string, MatchFlags match_options =  static_cast<MatchFlags>(0)) -> std::vector<Glib::ustring>;


  /** Breaks the string on the pattern, and returns an array of the tokens.
   * If the pattern contains capturing parentheses, then the text for each
   * of the substrings will also be returned. If the pattern does not match
   * anywhere in the string, then the whole string is returned as the first
   * token.
   *
   * As a special case, the result of splitting the empty string "" is an
   * empty vector, not a vector containing a single string. The reason for
   * this special case is that being able to represent an empty vector is
   * typically more useful than consistent handling of empty elements. If
   * you do need to represent empty elements, you'll need to check for the
   * empty string before calling this function.
   *
   * A pattern that can match empty strings splits @a string into separate
   * characters wherever it matches the empty string between characters.
   * For example splitting "ab c" using as a separator "\\s*", you will get
   * "a", "b" and "c".
   *
   * Setting @a start_position differs from just passing over a shortened
   * string and setting Glib::Regex::MatchFlags::NOTBOL in the case of a pattern
   * that begins with any kind of lookbehind assertion, such as "\\b".
   *
   * @newin{2,14}
   *
   * @param string The string to split with the pattern.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param match_options Match time option flags.
   * @param max_tokens The maximum number of tokens to split @a string into.
   * If this is less than 1, the string is split completely.
   * @return A <tt>nullptr</tt>-terminated gchar ** array.
   *
   * @throws Glib::RegexError
   */
  auto split(const gchar* string, gssize string_len, int start_position, MatchFlags match_options =  static_cast<MatchFlags>(0), int max_tokens =  0) const -> std::vector<Glib::ustring>;

  /// @throws Glib::RegexError
  auto split(Glib::UStringView string, int start_position, MatchFlags match_options, int max_tokens) const -> std::vector<Glib::ustring>;


  /** Replaces all occurrences of the pattern in @a regex with the
   * replacement text. Backreferences of the form '\\number' or
   * '\\g<number>' in the replacement text are interpolated by the
   * number-th captured subexpression of the match, '\\g<name>' refers
   * to the captured subexpression with the given name. '\\0' refers
   * to the complete match, but '\\0' followed by a number is the octal
   * representation of a character. To include a literal '\\' in the
   * replacement, write '\\\\\\\\'.
   *
   * There are also escapes that changes the case of the following text:
   *
   * - \\l: Convert to lower case the next character
   * - \\u: Convert to upper case the next character
   * - \\L: Convert to lower case till \\E
   * - \\U: Convert to upper case till \\E
   * - \\E: End case modification
   *
   * If you do not need to use backreferences use g_regex_replace_literal().
   *
   * The @a replacement string must be UTF-8 encoded even if Glib::Regex::CompileFlags::RAW was
   * passed to g_regex_new(). If you want to use not UTF-8 encoded strings
   * you can use g_regex_replace_literal().
   *
   * Setting @a start_position differs from just passing over a shortened
   * string and setting Glib::Regex::MatchFlags::NOTBOL in the case of a pattern that
   * begins with any kind of lookbehind assertion, such as "\\b".
   *
   * @newin{2,14}
   *
   * @param string The string to perform matches against.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param replacement Text to replace each match with.
   * @param match_options Options for the match.
   * @return A newly allocated string containing the replacements.
   *
   * @throws Glib::RegexError
   */
  auto replace(const gchar* string, gssize string_len, int start_position, Glib::UStringView replacement, MatchFlags match_options =  static_cast<MatchFlags>(0)) -> Glib::ustring;
  /// @throws Glib::RegexError
  auto replace(Glib::UStringView string, int start_position, Glib::UStringView replacement, MatchFlags match_options) -> Glib::ustring;


  /** Replaces all occurrences of the pattern in @a regex with the
   * replacement text. @a replacement is replaced literally, to
   * include backreferences use g_regex_replace().
   *
   * Setting @a start_position differs from just passing over a
   * shortened string and setting Glib::Regex::MatchFlags::NOTBOL in the
   * case of a pattern that begins with any kind of lookbehind
   * assertion, such as "\\b".
   *
   * @newin{2,14}
   *
   * @param string The string to perform matches against.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param replacement Text to replace each match with.
   * @param match_options Options for the match.
   * @return A newly allocated string containing the replacements.
   *
   * @throws Glib::RegexError
   */
  auto replace_literal(const gchar * string, gssize string_len, int start_position, Glib::UStringView replacement, MatchFlags match_options =  static_cast<MatchFlags>(0)) -> Glib::ustring;
  /// @throws Glib::RegexError
  auto replace_literal(Glib::UStringView string, int start_position, Glib::UStringView replacement, MatchFlags match_options) -> Glib::ustring;


  /** Replaces occurrences of the pattern in regex with the output of
   *  @a eval for that occurrence.
   *
   * Setting @a start_position differs from just passing over a shortened
   * string and setting Glib::Regex::MatchFlags::NOTBOL in the case of a pattern
   * that begins with any kind of lookbehind assertion, such as "\\b".
   *
   * The following example uses g_regex_replace_eval() to replace multiple
   * strings at once:
   *
   * [C example ellipted]
   *
   * @newin{2,14}
   *
   * @param string String to perform matches against.
   * @param string_len The length of @a string, in bytes, or -1 if @a string is nul-terminated.
   * @param start_position Starting index of the string to match, in bytes.
   * @param match_options Options for the match.
   * @param eval A function to call for each match.
   * @param user_data User data to pass to the function.
   * @return A newly allocated string containing the replacements.
   *
   * @throws Glib::RegexError
   */
  auto replace_eval(Glib::UStringView string, gssize string_len, int start_position, MatchFlags match_options, GRegexEvalCallback eval, gpointer user_data) -> Glib::ustring;

  /** Checks whether @a replacement is a valid replacement string
   * (see g_regex_replace()), i.e.\ that all escape sequences in
   * it are valid.
   *
   * If @a has_references is not <tt>nullptr</tt> then @a replacement is checked
   * for pattern references. For instance, replacement text 'foo\\n'
   * does not contain references and may be evaluated without information
   * about actual match, but '\\0\\1' (whole match followed by first
   * subpattern) requires valid MatchInfo object.
   *
   * @newin{2,14}
   *
   * @param replacement The replacement string.
   * @param has_references Location to store information about
   * references in @a replacement or <tt>nullptr</tt>.
   * @return Whether @a replacement is a valid replacement string.
   *
   * @throws Glib::RegexError
   */
  static auto check_replacement(Glib::UStringView replacement, gboolean* has_references) -> bool;


};

//TODO: Add C++ iterator like functionality for this class.
/** MatchInfo - MatchInfo is used to retrieve information about the regular
 * expression match which created it.
 * @newin{2,28}
 */
class GLIBMM_API MatchInfo
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MatchInfo;
  using BaseObjectType = GMatchInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  /// Default constructor.
  MatchInfo();

  /** C object constructor.
   * @param castitem The C object.
   * @param take_ownership Whether to destroy the C object with the wrapper or not.
   */
  explicit MatchInfo(GMatchInfo* castitem, bool take_ownership = true);

  MatchInfo(const MatchInfo& other) = delete;
  auto operator=(const MatchInfo& other) -> MatchInfo& = delete;

  MatchInfo(MatchInfo&& other) noexcept;
  auto operator=(MatchInfo&& other) noexcept -> MatchInfo&;

  /// Destructor.
  virtual ~MatchInfo();

  /// Provides access to the underlying C object.
  auto gobj() -> GMatchInfo*
    { return reinterpret_cast<GMatchInfo*>(gobject_); }

  /// Provides access to the underlying C object.
  auto gobj() const -> const GMatchInfo*
    { return reinterpret_cast<GMatchInfo*>(gobject_); }

private:

  friend class Regex;

public:


  /** Returns Regex object used in @a match_info. It belongs to Glib
   * and must not be freed. Use g_regex_ref() if you need to keep it
   * after you free @a match_info object.
   *
   * @newin{2,14}
   *
   * @return Regex object used in @a match_info.
   */
  auto get_regex() -> Glib::RefPtr<Regex>;

  /** Returns Regex object used in @a match_info. It belongs to Glib
   * and must not be freed. Use g_regex_ref() if you need to keep it
   * after you free @a match_info object.
   *
   * @newin{2,14}
   *
   * @return Regex object used in @a match_info.
   */
  auto get_regex() const -> Glib::RefPtr<const Regex>;


  /** Returns the string searched with @a match_info. This is the
   * string passed to g_regex_match() or g_regex_replace() so
   * you may not free it before calling this function.
   *
   * @newin{2,14}
   *
   * @return The string searched with @a match_info.
   */
  auto get_string() const -> Glib::ustring;

  /** Returns whether the previous match operation succeeded.
   *
   * @newin{2,14}
   *
   * @return <tt>true</tt> if the previous match operation succeeded,
   * <tt>false</tt> otherwise.
   */
  auto matches() const -> bool;


  /** Scans for the next match using the same parameters of the previous
   * call to g_regex_match_full() or g_regex_match() that returned
   *  @a match_info.
   *
   * The match is done on the string passed to the match function, so you
   * cannot free it before calling this function.
   *
   * @newin{2,14}
   *
   * @return <tt>true</tt> is the string matched, <tt>false</tt> otherwise.
   *
   * @throws Glib::RegexError
   */
  auto next() -> bool;


  /** Retrieves the number of matched substrings (including substring 0,
   * that is the whole matched text), so 1 is returned if the pattern
   * has no substrings in it and 0 is returned if the match failed.
   *
   * If the last match was obtained using the DFA algorithm, that is
   * using g_regex_match_all() or g_regex_match_all_full(), the retrieved
   * count is not that of the number of capturing parentheses but that of
   * the number of matched substrings.
   *
   * @newin{2,14}
   *
   * @return Number of matched substrings, or -1 if an error occurred.
   */
  auto get_match_count() const -> int;

  /** Usually if the string passed to g_regex_match*() matches as far as
   * it goes, but is too short to match the entire pattern, <tt>false</tt> is
   * returned. There are circumstances where it might be helpful to
   * distinguish this case from other cases in which there is no match.
   *
   * Consider, for example, an application where a human is required to
   * type in data for a field with specific formatting requirements. An
   * example might be a date in the form ddmmmyy, defined by the pattern
   * "^\\d?\\d(jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec)\\d\\d$".
   * If the application sees the user’s keystrokes one by one, and can
   * check that what has been typed so far is potentially valid, it is
   * able to raise an error as soon as a mistake is made.
   *
   * GRegex supports the concept of partial matching by means of the
   * Glib::Regex::MatchFlags::PARTIAL_SOFT and Glib::Regex::MatchFlags::PARTIAL_HARD flags.
   * When they are used, the return code for
   * g_regex_match() or g_regex_match_full() is, as usual, <tt>true</tt>
   * for a complete match, <tt>false</tt> otherwise. But, when these functions
   * return <tt>false</tt>, you can check if the match was partial calling
   * g_match_info_is_partial_match().
   *
   * The difference between Glib::Regex::MatchFlags::PARTIAL_SOFT and
   * Glib::Regex::MatchFlags::PARTIAL_HARD is that when a partial match is encountered
   * with Glib::Regex::MatchFlags::PARTIAL_SOFT, matching continues to search for a
   * possible complete match, while with Glib::Regex::MatchFlags::PARTIAL_HARD matching
   * stops at the partial match.
   * When both Glib::Regex::MatchFlags::PARTIAL_SOFT and Glib::Regex::MatchFlags::PARTIAL_HARD
   * are set, the latter takes precedence.
   *
   * There were formerly some restrictions on the pattern for partial matching.
   * The restrictions no longer apply.
   *
   * See pcrepartial(3) for more information on partial matching.
   *
   * @newin{2,14}
   *
   * @return <tt>true</tt> if the match was partial, <tt>false</tt> otherwise.
   */
  auto is_partial_match() const -> bool;


  /** Returns a new string containing the text in @a string_to_expand with
   * references and escape sequences expanded. References refer to the last
   * match done with @a string against @a regex and have the same syntax used by
   * g_regex_replace().
   *
   * The @a string_to_expand must be UTF-8 encoded even if Glib::Regex::CompileFlags::RAW was
   * passed to g_regex_new().
   *
   * The backreferences are extracted from the string passed to the match
   * function, so you cannot call this function after freeing the string.
   *
   *  @a match_info may be <tt>nullptr</tt> in which case @a string_to_expand must not
   * contain references. For instance "foo\\n" does not refer to an actual
   * pattern and '\\n' merely will be replaced with \\n character,
   * while to expand "\\0" (whole match) one needs the result of a match.
   * Use g_regex_check_replacement() to find out whether @a string_to_expand
   * contains references.
   *
   * @newin{2,14}
   *
   * @param string_to_expand The string to expand.
   * @return The expanded string, or <tt>nullptr</tt> if an error occurred.
   *
   * @throws Glib::RegexError
   */
  auto expand_references(Glib::UStringView string_to_expand) -> Glib::ustring;


  /** Retrieves the text matching the @a match_num'th capturing
   * parentheses. 0 is the full text of the match, 1 is the first paren
   * set, 2 the second, and so on.
   *
   * If @a match_num is a valid sub pattern but it didn't match anything
   * (e.g. sub pattern 1, matching "b" against "(a)?b") then an empty
   * string is returned.
   *
   * If the match was obtained using the DFA algorithm, that is using
   * g_regex_match_all() or g_regex_match_all_full(), the retrieved
   * string is not that of a set of parentheses but that of a matched
   * substring. Substrings are matched in reverse order of length, so
   * 0 is the longest match.
   *
   * The string is fetched from the string passed to the match function,
   * so you cannot call this function after freeing the string.
   *
   * @newin{2,14}
   *
   * @param match_num Number of the sub expression.
   * @return The matched substring, or <tt>nullptr</tt> if an error
   * occurred. You have to free the string yourself.
   */
  auto fetch(int match_num) -> Glib::ustring;


  /** Retrieves the position in bytes of the @a match_num'th capturing
   * parentheses. 0 is the full text of the match, 1 is the first
   * paren set, 2 the second, and so on.
   *
   * If @a match_num is a valid sub pattern but it didn't match anything
   * (e.g. sub pattern 1, matching "b" against "(a)?b") then @a start_pos
   * and @a end_pos are set to -1 and <tt>true</tt> is returned.
   *
   * If the match was obtained using the DFA algorithm, that is using
   * g_regex_match_all() or g_regex_match_all_full(), the retrieved
   * position is not that of a set of parentheses but that of a matched
   * substring. Substrings are matched in reverse order of length, so
   * 0 is the longest match.
   *
   * @newin{2,14}
   *
   * @param match_num Number of the sub expression.
   * @param start_pos Pointer to location where to store
   * the start position, or <tt>nullptr</tt>.
   * @param end_pos Pointer to location where to store
   * the end position, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the position was fetched, <tt>false</tt> otherwise. If
   * the position cannot be fetched, @a start_pos and @a end_pos are left
   * unchanged.
   */
  auto fetch_pos(int match_num, int& start_pos, int& end_pos) -> bool;


  /** Retrieves the text matching the capturing parentheses named @a name.
   *
   * If @a name is a valid sub pattern name but it didn't match anything
   * (e.g. sub pattern "X", matching "b" against "(?P<X>a)?b")
   * then an empty string is returned.
   *
   * The string is fetched from the string passed to the match function,
   * so you cannot call this function after freeing the string.
   *
   * @newin{2,14}
   *
   * @param name Name of the subexpression.
   * @return The matched substring, or <tt>nullptr</tt> if an error
   * occurred. You have to free the string yourself.
   */
  auto fetch_named(Glib::UStringView name) -> Glib::ustring;


  /** Retrieves the position in bytes of the capturing parentheses named @a name.
   *
   * If @a name is a valid sub pattern name but it didn't match anything
   * (e.g. sub pattern "X", matching "b" against "(?P<X>a)?b")
   * then @a start_pos and @a end_pos are set to -1 and <tt>true</tt> is returned.
   *
   * @newin{2,14}
   *
   * @param name Name of the subexpression.
   * @param start_pos Pointer to location where to store
   * the start position, or <tt>nullptr</tt>.
   * @param end_pos Pointer to location where to store
   * the end position, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the position was fetched, <tt>false</tt> otherwise.
   * If the position cannot be fetched, @a start_pos and @a end_pos
   * are left unchanged.
   */
  auto fetch_named_pos(Glib::UStringView name, int& start_pos, int& end_pos) -> bool;


  /** Bundles up pointers to each of the matching substrings from a match
   * and stores them in an array of gchar pointers. The first element in
   * the returned array is the match number 0, i.e. the entire matched
   * text.
   *
   * If a sub pattern didn't match anything (e.g. sub pattern 1, matching
   * "b" against "(a)?b") then an empty string is inserted.
   *
   * If the last match was obtained using the DFA algorithm, that is using
   * g_regex_match_all() or g_regex_match_all_full(), the retrieved
   * strings are not that matched by sets of parentheses but that of the
   * matched substring. Substrings are matched in reverse order of length,
   * so the first one is the longest match.
   *
   * The strings are fetched from the string passed to the match function,
   * so you cannot call this function after freeing the string.
   *
   * @newin{2,14}
   *
   * @return A <tt>nullptr</tt>-terminated array of gchar *
   * pointers. If the previous
   * match failed <tt>nullptr</tt> is returned.
   */
  auto fetch_all() -> std::vector<Glib::ustring>;

protected:
  GMatchInfo* gobject_;      // The C object.
  bool take_ownership_;      // Bool signaling ownership.

protected:
  // So that Glib::Regex::match() can set the C object.
  void set_gobject(GMatchInfo* castitem, bool take_ownership = true);


};

} // namespace Glib

namespace Glib
{

/** @ingroup glibmmEnums */
inline auto operator|(Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  { return static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  { return static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  { return static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(Regex::CompileFlags flags) -> Regex::CompileFlags
  { return static_cast<Regex::CompileFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  { return (lhs = static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  { return (lhs = static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  { return (lhs = static_cast<Regex::CompileFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Glib
namespace Glib
{

/** @ingroup glibmmEnums */
inline auto operator|(Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  { return static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  { return static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  { return static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(Regex::MatchFlags flags) -> Regex::MatchFlags
  { return static_cast<Regex::MatchFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  { return (lhs = static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  { return (lhs = static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  { return (lhs = static_cast<Regex::MatchFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Glib

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Glib::Regex
 */
GLIBMM_API
auto wrap(GRegex* object, bool take_copy = false) -> Glib::RefPtr<Glib::Regex>;

} // namespace Glib


#endif /* _GLIBMM_REGEX_H */

