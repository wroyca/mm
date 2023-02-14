
#ifndef _GLIBMM_UNICODE_H
#define _GLIBMM_UNICODE_H

#include <glib.h>

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

  inline auto
  operator| (AsciiType lhs, AsciiType rhs) -> AsciiType
  {
    return static_cast<AsciiType> (static_cast<unsigned> (lhs) |
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (AsciiType lhs, AsciiType rhs) -> AsciiType
  {
    return static_cast<AsciiType> (static_cast<unsigned> (lhs) &
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (AsciiType lhs, AsciiType rhs) -> AsciiType
  {
    return static_cast<AsciiType> (static_cast<unsigned> (lhs) ^
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(AsciiType flags) -> AsciiType
  {
    return static_cast<AsciiType> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (AsciiType& lhs, AsciiType rhs) -> AsciiType&
  {
    return (lhs = static_cast<AsciiType> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (AsciiType& lhs, AsciiType rhs) -> AsciiType&
  {
    return (lhs = static_cast<AsciiType> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (AsciiType& lhs, AsciiType rhs) -> AsciiType&
  {
    return (lhs = static_cast<AsciiType> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs)));
  }

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

  namespace Unicode
  {

    inline auto
    validate (gunichar uc) -> bool
    {
      return (g_unichar_validate (uc) != 0);
    }

    inline auto
    isalnum (gunichar uc) -> bool
    {
      return (g_unichar_isalnum (uc) != 0);
    }

    inline auto
    isalpha (gunichar uc) -> bool
    {
      return (g_unichar_isalpha (uc) != 0);
    }

    inline auto
    iscntrl (gunichar uc) -> bool
    {
      return (g_unichar_iscntrl (uc) != 0);
    }

    inline auto
    isdigit (gunichar uc) -> bool
    {
      return (g_unichar_isdigit (uc) != 0);
    }

    inline auto
    isgraph (gunichar uc) -> bool
    {
      return (g_unichar_isgraph (uc) != 0);
    }

    inline auto
    islower (gunichar uc) -> bool
    {
      return (g_unichar_islower (uc) != 0);
    }

    inline auto
    isprint (gunichar uc) -> bool
    {
      return (g_unichar_isprint (uc) != 0);
    }

    inline auto
    ispunct (gunichar uc) -> bool
    {
      return (g_unichar_ispunct (uc) != 0);
    }

    inline auto
    isspace (gunichar uc) -> bool
    {
      return (g_unichar_isspace (uc) != 0);
    }

    inline auto
    isupper (gunichar uc) -> bool
    {
      return (g_unichar_isupper (uc) != 0);
    }

    inline auto
    isxdigit (gunichar uc) -> bool
    {
      return (g_unichar_isxdigit (uc) != 0);
    }

    inline auto
    istitle (gunichar uc) -> bool
    {
      return (g_unichar_istitle (uc) != 0);
    }

    inline auto
    isdefined (gunichar uc) -> bool
    {
      return (g_unichar_isdefined (uc) != 0);
    }

    inline auto
    iswide (gunichar uc) -> bool
    {
      return (g_unichar_iswide (uc) != 0);
    }

    inline auto
    toupper (gunichar uc) -> gunichar
    {
      return g_unichar_toupper (uc);
    }

    inline auto
    tolower (gunichar uc) -> gunichar
    {
      return g_unichar_tolower (uc);
    }

    inline auto
    totitle (gunichar uc) -> gunichar
    {
      return g_unichar_totitle (uc);
    }

    inline auto
    digit_value (gunichar uc) -> int
    {
      return g_unichar_digit_value (uc);
    }

    inline auto
    xdigit_value (gunichar uc) -> int
    {
      return g_unichar_xdigit_value (uc);
    }

    inline auto
    type (gunichar uc) -> Glib::UnicodeType
    {
      return static_cast<Glib::UnicodeType> (
          static_cast<int> (g_unichar_type (uc)));
    }

    inline auto
    break_type (gunichar uc) -> Glib::UnicodeBreakType
    {
      return static_cast<Glib::UnicodeBreakType> (
          static_cast<int> (g_unichar_break_type (uc)));
    }

  } // namespace Unicode

  namespace Ascii
  {

    inline auto
    isalnum (char c) -> bool
    {
      return g_ascii_isalnum (c);
    }

    inline auto
    isalpha (char c) -> bool
    {
      return g_ascii_isalpha (c);
    }

    inline auto
    iscntrl (char c) -> bool
    {
      return g_ascii_iscntrl (c);
    }

    inline auto
    isdigit (char c) -> bool
    {
      return g_ascii_isdigit (c);
    }

    inline auto
    isgraph (char c) -> bool
    {
      return g_ascii_isgraph (c);
    }

    inline auto
    islower (char c) -> bool
    {
      return g_ascii_islower (c);
    }

    inline auto
    isprint (char c) -> bool
    {
      return g_ascii_isprint (c);
    }

    inline auto
    ispunct (char c) -> bool
    {
      return g_ascii_ispunct (c);
    }

    inline auto
    isspace (char c) -> bool
    {
      return g_ascii_isspace (c);
    }

    inline auto
    isupper (char c) -> bool
    {
      return g_ascii_isupper (c);
    }

    inline auto
    isxdigit (char c) -> bool
    {
      return g_ascii_isxdigit (c);
    }

    inline auto
    tolower (char c) -> char
    {
      return g_ascii_tolower (c);
    }

    inline auto
    toupper (char c) -> char
    {
      return g_ascii_toupper (c);
    }

    inline auto
    digit_value (char c) -> int
    {
      return g_ascii_digit_value (c);
    }

    inline auto
    xdigit_value (char c) -> int
    {
      return g_ascii_xdigit_value (c);
    }

  } // namespace Ascii

} // namespace Glib

#endif
