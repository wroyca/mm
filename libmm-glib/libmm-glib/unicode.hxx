
#ifndef _GLIBMM_UNICODE_H
#define _GLIBMM_UNICODE_H


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

// Not used, but we want to get rid of possible <ctype.h> macros.
#include <cctype>

#undef isalnum
#undef isalpha
#undef iscntrl
#undef isdigit
#undef isgraph
#undef islower
#undef isprint
#undef ispunct
#undef isspace
#undef isupper
#undef isxdigit
#undef istitle
#undef isdefined
#undef iswide
#undef toupper
#undef tolower
#undef totitle


namespace Glib
{

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/** 
 *  @var UnicodeType CONTROL
 * General category "Other, Control" (Cc).
 * 
 *  @var UnicodeType FORMAT
 * General category "Other, Format" (Cf).
 * 
 *  @var UnicodeType UNASSIGNED
 * General category "Other, Not Assigned" (Cn).
 * 
 *  @var UnicodeType PRIVATE_USE
 * General category "Other, Private Use" (Co).
 * 
 *  @var UnicodeType SURROGATE
 * General category "Other, Surrogate" (Cs).
 * 
 *  @var UnicodeType LOWERCASE_LETTER
 * General category "Letter, Lowercase" (Ll).
 * 
 *  @var UnicodeType MODIFIER_LETTER
 * General category "Letter, Modifier" (Lm).
 * 
 *  @var UnicodeType OTHER_LETTER
 * General category "Letter, Other" (Lo).
 * 
 *  @var UnicodeType TITLECASE_LETTER
 * General category "Letter, Titlecase" (Lt).
 * 
 *  @var UnicodeType UPPERCASE_LETTER
 * General category "Letter, Uppercase" (Lu).
 * 
 *  @var UnicodeType SPACING_MARK
 * General category "Mark, Spacing" (Mc).
 * 
 *  @var UnicodeType ENCLOSING_MARK
 * General category "Mark, Enclosing" (Me).
 * 
 *  @var UnicodeType NON_SPACING_MARK
 * General category "Mark, Nonspacing" (Mn).
 * 
 *  @var UnicodeType DECIMAL_NUMBER
 * General category "Number, Decimal Digit" (Nd).
 * 
 *  @var UnicodeType LETTER_NUMBER
 * General category "Number, Letter" (Nl).
 * 
 *  @var UnicodeType OTHER_NUMBER
 * General category "Number, Other" (No).
 * 
 *  @var UnicodeType CONNECT_PUNCTUATION
 * General category "Punctuation, Connector" (Pc).
 * 
 *  @var UnicodeType DASH_PUNCTUATION
 * General category "Punctuation, Dash" (Pd).
 * 
 *  @var UnicodeType CLOSE_PUNCTUATION
 * General category "Punctuation, Close" (Pe).
 * 
 *  @var UnicodeType FINAL_PUNCTUATION
 * General category "Punctuation, Final quote" (Pf).
 * 
 *  @var UnicodeType INITIAL_PUNCTUATION
 * General category "Punctuation, Initial quote" (Pi).
 * 
 *  @var UnicodeType OTHER_PUNCTUATION
 * General category "Punctuation, Other" (Po).
 * 
 *  @var UnicodeType OPEN_PUNCTUATION
 * General category "Punctuation, Open" (Ps).
 * 
 *  @var UnicodeType CURRENCY_SYMBOL
 * General category "Symbol, Currency" (Sc).
 * 
 *  @var UnicodeType MODIFIER_SYMBOL
 * General category "Symbol, Modifier" (Sk).
 * 
 *  @var UnicodeType MATH_SYMBOL
 * General category "Symbol, Math" (Sm).
 * 
 *  @var UnicodeType OTHER_SYMBOL
 * General category "Symbol, Other" (So).
 * 
 *  @var UnicodeType LINE_SEPARATOR
 * General category "Separator, Line" (Zl).
 * 
 *  @var UnicodeType PARAGRAPH_SEPARATOR
 * General category "Separator, Paragraph" (Zp).
 * 
 *  @var UnicodeType SPACE_SEPARATOR
 * General category "Separator, Space" (Zs).
 * 
 *  @enum UnicodeType
 * 
 * These are the possible character classifications from the
 * Unicode specification.
 * See [Unicode Character Database](http://www.unicode.org/reports/tr44/#General_Category_Values).
 *
 * @ingroup glibmmEnums
 */
enum class UnicodeType
{
  CONTROL,
  FORMAT,
  UNASSIGNED,
  PRIVATE_USE,
  SURROGATE,
  LOWERCASE_LETTER,
  MODIFIER_LETTER,
  OTHER_LETTER,
  TITLECASE_LETTER,
  UPPERCASE_LETTER,
  SPACING_MARK,
  ENCLOSING_MARK,
  NON_SPACING_MARK,
  DECIMAL_NUMBER,
  LETTER_NUMBER,
  OTHER_NUMBER,
  CONNECT_PUNCTUATION,
  DASH_PUNCTUATION,
  CLOSE_PUNCTUATION,
  FINAL_PUNCTUATION,
  INITIAL_PUNCTUATION,
  OTHER_PUNCTUATION,
  OPEN_PUNCTUATION,
  CURRENCY_SYMBOL,
  MODIFIER_SYMBOL,
  MATH_SYMBOL,
  OTHER_SYMBOL,
  LINE_SEPARATOR,
  PARAGRAPH_SEPARATOR,
  SPACE_SEPARATOR
};


/** 
 *  @var UnicodeBreakType MANDATORY
 * Mandatory Break (BK).
 * 
 *  @var UnicodeBreakType CARRIAGE_RETURN
 * Carriage Return (CR).
 * 
 *  @var UnicodeBreakType LINE_FEED
 * Line Feed (LF).
 * 
 *  @var UnicodeBreakType COMBINING_MARK
 * Attached Characters and Combining Marks (CM).
 * 
 *  @var UnicodeBreakType SURROGATE
 * Surrogates (SG).
 * 
 *  @var UnicodeBreakType ZERO_WIDTH_SPACE
 * Zero Width Space (ZW).
 * 
 *  @var UnicodeBreakType INSEPARABLE
 * Inseparable (IN).
 * 
 *  @var UnicodeBreakType NON_BREAKING_GLUE
 * Non-breaking ("Glue") (GL).
 * 
 *  @var UnicodeBreakType CONTINGENT
 * Contingent Break Opportunity (CB).
 * 
 *  @var UnicodeBreakType SPACE
 * Space (SP).
 * 
 *  @var UnicodeBreakType AFTER
 * Break Opportunity After (BA).
 * 
 *  @var UnicodeBreakType BEFORE
 * Break Opportunity Before (BB).
 * 
 *  @var UnicodeBreakType BEFORE_AND_AFTER
 * Break Opportunity Before and After (B2).
 * 
 *  @var UnicodeBreakType HYPHEN
 * Hyphen (HY).
 * 
 *  @var UnicodeBreakType NON_STARTER
 * Nonstarter (NS).
 * 
 *  @var UnicodeBreakType OPEN_PUNCTUATION
 * Opening Punctuation (OP).
 * 
 *  @var UnicodeBreakType CLOSE_PUNCTUATION
 * Closing Punctuation (CL).
 * 
 *  @var UnicodeBreakType QUOTATION
 * Ambiguous Quotation (QU).
 * 
 *  @var UnicodeBreakType EXCLAMATION
 * Exclamation/Interrogation (EX).
 * 
 *  @var UnicodeBreakType IDEOGRAPHIC
 * Ideographic (ID).
 * 
 *  @var UnicodeBreakType NUMERIC
 * Numeric (NU).
 * 
 *  @var UnicodeBreakType INFIX_SEPARATOR
 * Infix Separator (Numeric) (IS).
 * 
 *  @var UnicodeBreakType SYMBOL
 * Symbols Allowing Break After (SY).
 * 
 *  @var UnicodeBreakType ALPHABETIC
 * Ordinary Alphabetic and Symbol Characters (AL).
 * 
 *  @var UnicodeBreakType PREFIX
 * Prefix (Numeric) (PR).
 * 
 *  @var UnicodeBreakType POSTFIX
 * Postfix (Numeric) (PO).
 * 
 *  @var UnicodeBreakType COMPLEX_CONTEXT
 * Complex Content Dependent (South East Asian) (SA).
 * 
 *  @var UnicodeBreakType AMBIGUOUS
 * Ambiguous (Alphabetic or Ideographic) (AI).
 * 
 *  @var UnicodeBreakType UNKNOWN
 * Unknown (XX).
 * 
 *  @var UnicodeBreakType NEXT_LINE
 * Next Line (NL).
 * 
 *  @var UnicodeBreakType WORD_JOINER
 * Word Joiner (WJ).
 * 
 *  @var UnicodeBreakType HANGUL_L_JAMO
 * Hangul L Jamo (JL).
 * 
 *  @var UnicodeBreakType HANGUL_V_JAMO
 * Hangul V Jamo (JV).
 * 
 *  @var UnicodeBreakType HANGUL_T_JAMO
 * Hangul T Jamo (JT).
 * 
 *  @var UnicodeBreakType HANGUL_LV_SYLLABLE
 * Hangul LV Syllable (H2).
 * 
 *  @var UnicodeBreakType HANGUL_LVT_SYLLABLE
 * Hangul LVT Syllable (H3).
 * 
 *  @var UnicodeBreakType CLOSE_PARANTHESIS
 * Closing Parenthesis (CP). @newin{2,28} Deprecated: 2.70: Use Glib::UnicodeBreakType::CLOSE_PARENTHESIS instead.
 * 
 *  @var UnicodeBreakType CLOSE_PARENTHESIS
 * Closing Parenthesis (CP). @newin{2,70}
 * 
 *  @var UnicodeBreakType CONDITIONAL_JAPANESE_STARTER
 * Conditional Japanese Starter (CJ). @newin{2,32}
 * 
 *  @var UnicodeBreakType HEBREW_LETTER
 * Hebrew Letter (HL). @newin{2,32}
 * 
 *  @var UnicodeBreakType REGIONAL_INDICATOR
 * Regional Indicator (RI). @newin{2,36}
 * 
 *  @var UnicodeBreakType EMOJI_BASE
 * Emoji Base (EB). @newin{2,50}
 * 
 *  @var UnicodeBreakType EMOJI_MODIFIER
 * Emoji Modifier (EM). @newin{2,50}
 * 
 *  @var UnicodeBreakType ZERO_WIDTH_JOINER
 * Zero Width Joiner (ZWJ). @newin{2,50}
 * 
 *  @enum UnicodeBreakType
 * 
 * These are the possible line break classifications.
 * 
 * Since new unicode versions may add new types here, applications should be ready 
 * to handle unknown values. They may be regarded as Glib::UnicodeBreakType::UNKNOWN.
 * 
 * See [Unicode Line Breaking Algorithm](http://www.unicode.org/unicode/reports/tr14/).
 *
 * @ingroup glibmmEnums
 */
enum class UnicodeBreakType
{
  MANDATORY,
  CARRIAGE_RETURN,
  LINE_FEED,
  COMBINING_MARK,
  SURROGATE,
  ZERO_WIDTH_SPACE,
  INSEPARABLE,
  NON_BREAKING_GLUE,
  CONTINGENT,
  SPACE,
  AFTER,
  BEFORE,
  BEFORE_AND_AFTER,
  HYPHEN,
  NON_STARTER,
  OPEN_PUNCTUATION,
  CLOSE_PUNCTUATION,
  QUOTATION,
  EXCLAMATION,
  IDEOGRAPHIC,
  NUMERIC,
  INFIX_SEPARATOR,
  SYMBOL,
  ALPHABETIC,
  PREFIX,
  POSTFIX,
  COMPLEX_CONTEXT,
  AMBIGUOUS,
  UNKNOWN,
  NEXT_LINE,
  WORD_JOINER,
  HANGUL_L_JAMO,
  HANGUL_V_JAMO,
  HANGUL_T_JAMO,
  HANGUL_LV_SYLLABLE,
  HANGUL_LVT_SYLLABLE,
  CLOSE_PARANTHESIS,
  CLOSE_PARENTHESIS = CLOSE_PARANTHESIS,
  CONDITIONAL_JAPANESE_STARTER,
  HEBREW_LETTER,
  REGIONAL_INDICATOR,
  EMOJI_BASE,
  EMOJI_MODIFIER,
  ZERO_WIDTH_JOINER
};


/** 
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>AsciiType operator|(AsciiType, AsciiType)</tt><br>
 * <tt>AsciiType operator&(AsciiType, AsciiType)</tt><br>
 * <tt>AsciiType operator^(AsciiType, AsciiType)</tt><br>
 * <tt>AsciiType operator~(AsciiType)</tt><br>
 * <tt>AsciiType& operator|=(AsciiType&, AsciiType)</tt><br>
 * <tt>AsciiType& operator&=(AsciiType&, AsciiType)</tt><br>
 * <tt>AsciiType& operator^=(AsciiType&, AsciiType)</tt><br>
 */
enum class AsciiType
{
  ALNUM = 1 << 0,
  ALPHA = 1 << 1,
  CNTRL = 1 << 2,
  DIGIT = 1 << 3,
  GRAPH = 1 << 4,
  LOWER = 1 << 5,
  PRINT = 1 << 6,
  PUNCT = 1 << 7,
  SPACE = 1 << 8,
  UPPER = 1 << 9,
  XDIGIT = 1 << 10
};

/** @ingroup glibmmEnums */
inline auto operator|(AsciiType lhs, AsciiType rhs) -> AsciiType
  { return static_cast<AsciiType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(AsciiType lhs, AsciiType rhs) -> AsciiType
  { return static_cast<AsciiType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(AsciiType lhs, AsciiType rhs) -> AsciiType
  { return static_cast<AsciiType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(AsciiType flags) -> AsciiType
  { return static_cast<AsciiType>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(AsciiType& lhs, AsciiType rhs) -> AsciiType&
  { return (lhs = static_cast<AsciiType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(AsciiType& lhs, AsciiType rhs) -> AsciiType&
  { return (lhs = static_cast<AsciiType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(AsciiType& lhs, AsciiType rhs) -> AsciiType&
  { return (lhs = static_cast<AsciiType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** 
 *  @var NormalizeMode DEFAULT
 * Standardize differences that do not affect the
 * text content, such as the above-mentioned accent representation.
 * 
 *  @var NormalizeMode NFD
 * Another name for Glib::NormalizeMode::DEFAULT.
 * 
 *  @var NormalizeMode DEFAULT_COMPOSE
 * Like Glib::NormalizeMode::DEFAULT, but with
 * composed forms rather than a maximally decomposed form.
 * 
 *  @var NormalizeMode NFC
 * Another name for Glib::NormalizeMode::DEFAULT_COMPOSE.
 * 
 *  @var NormalizeMode ALL
 * Beyond Glib::NormalizeMode::DEFAULT also standardize the
 * "compatibility" characters in Unicode, such as SUPERSCRIPT THREE
 * to the standard forms (in this case DIGIT THREE). Formatting
 * information may be lost but for most text operations such
 * characters should be considered the same.
 * 
 *  @var NormalizeMode NFKD
 * Another name for Glib::NormalizeMode::ALL.
 * 
 *  @var NormalizeMode ALL_COMPOSE
 * Like Glib::NormalizeMode::ALL, but with composed
 * forms rather than a maximally decomposed form.
 * 
 *  @var NormalizeMode NFKC
 * Another name for Glib::NormalizeMode::ALL_COMPOSE.
 * 
 *  @enum NormalizeMode
 * 
 * Defines how a Unicode string is transformed in a canonical
 * form, standardizing such issues as whether a character with
 * an accent is represented as a base character and combining
 * accent or as a single precomposed character. Unicode strings
 * should generally be normalized before comparing them.
 *
 * @ingroup glibmmEnums
 */
enum class NormalizeMode
{
  DEFAULT,
  NFD = DEFAULT,
  DEFAULT_COMPOSE,
  NFC = DEFAULT_COMPOSE,
  ALL,
  NFKD = ALL,
  ALL_COMPOSE,
  NFKC = ALL_COMPOSE
};


/** @defgroup Unicode Unicode Manipulation
 * Functions operating on Unicode characters and UTF-8 strings.
 * @{
 */

namespace Unicode
{

inline auto validate(gunichar uc) -> bool
  { return (g_unichar_validate(uc) != 0); }
inline auto isalnum(gunichar uc) -> bool
  { return (g_unichar_isalnum(uc) != 0); }
inline auto isalpha(gunichar uc) -> bool
  { return (g_unichar_isalpha(uc) != 0); }
inline auto iscntrl(gunichar uc) -> bool
  { return (g_unichar_iscntrl(uc) != 0); }
inline auto isdigit(gunichar uc) -> bool
  { return (g_unichar_isdigit(uc) != 0); }
inline auto isgraph(gunichar uc) -> bool
  { return (g_unichar_isgraph(uc) != 0); }
inline auto islower(gunichar uc) -> bool
  { return (g_unichar_islower(uc) != 0); }
inline auto isprint(gunichar uc) -> bool
  { return (g_unichar_isprint(uc) != 0); }
inline auto ispunct(gunichar uc) -> bool
  { return (g_unichar_ispunct(uc) != 0); }
inline auto isspace(gunichar uc) -> bool
  { return (g_unichar_isspace(uc) != 0); }
inline auto isupper(gunichar uc) -> bool
  { return (g_unichar_isupper(uc) != 0); }
inline auto isxdigit(gunichar uc) -> bool
  { return (g_unichar_isxdigit(uc) != 0); }
inline auto istitle(gunichar uc) -> bool
  { return (g_unichar_istitle(uc) != 0); }
inline auto isdefined(gunichar uc) -> bool
  { return (g_unichar_isdefined(uc) != 0); }
inline auto iswide(gunichar uc) -> bool
  { return (g_unichar_iswide(uc) != 0); }

inline auto toupper(gunichar uc) -> gunichar
  { return g_unichar_toupper(uc); }
inline auto tolower(gunichar uc) -> gunichar
  { return g_unichar_tolower(uc); }
inline auto totitle(gunichar uc) -> gunichar
  { return g_unichar_totitle(uc); }

inline auto digit_value(gunichar uc) -> int
  { return g_unichar_digit_value(uc); }
inline auto xdigit_value(gunichar uc) -> int
  { return g_unichar_xdigit_value(uc); }

inline auto type(gunichar uc) -> Glib::UnicodeType
  { return static_cast<Glib::UnicodeType>(static_cast<int>(g_unichar_type(uc))); }

inline auto break_type(gunichar uc) -> Glib::UnicodeBreakType
  { return static_cast<Glib::UnicodeBreakType>(static_cast<int>(g_unichar_break_type(uc))); }

} // namespace Unicode


namespace Ascii
{

inline auto isalnum(char c) -> bool
  { return g_ascii_isalnum(c); }
inline auto isalpha(char c) -> bool
  { return g_ascii_isalpha(c); }
inline auto iscntrl(char c) -> bool
  { return g_ascii_iscntrl(c); }
inline auto isdigit(char c) -> bool
  { return g_ascii_isdigit(c); }
inline auto isgraph(char c) -> bool
  { return g_ascii_isgraph(c); }
inline auto islower(char c) -> bool
  { return g_ascii_islower(c); }
inline auto isprint(char c) -> bool
  { return g_ascii_isprint(c); }
inline auto ispunct(char c) -> bool
  { return g_ascii_ispunct(c); }
inline auto isspace(char c) -> bool
  { return g_ascii_isspace(c); }
inline auto isupper(char c) -> bool
  { return g_ascii_isupper(c); }
inline auto isxdigit(char c) -> bool
  { return g_ascii_isxdigit(c); }

inline auto tolower(char c) -> char
  { return g_ascii_tolower(c); }
inline auto toupper(char c) -> char
  { return g_ascii_toupper(c); }

inline auto digit_value(char c) -> int
  { return g_ascii_digit_value(c); }
inline auto xdigit_value(char c) -> int
  { return g_ascii_xdigit_value(c); }

} // namespace Ascii


/** @} group Unicode */

} // namespace Glib


#endif /* _GLIBMM_UNICODE_H */
