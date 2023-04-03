// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_REGEX_H
#define _GLIBMM_REGEX_H

#include <glib.h>
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GRegex GRegex;
#endif

namespace Glib
{

  class RegexError : public Glib::Error
  {
  public:
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

    LIBMM_GLIB_SYMEXPORT
    RegexError (Code error_code, const Glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit RegexError (GError* gobject);
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

  class MatchInfo;

  class LIBMM_GLIB_SYMEXPORT Regex final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Regex;
    using BaseObjectType = GRegex;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GRegex*;

    auto
    gobj () const -> const GRegex*;

    auto
    gobj_copy () const -> GRegex*;

    Regex () = delete;

    Regex (const Regex&) = delete;
    auto
    operator= (const Regex&) -> Regex& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
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

    static auto
    create (Glib::UStringView pattern,
            CompileFlags compile_options = static_cast<CompileFlags> (0),
            MatchFlags match_options = static_cast<MatchFlags> (0))
        -> Glib::RefPtr<Glib::Regex>;

    auto
    get_pattern () const -> Glib::ustring;

    auto
    get_max_backref () const -> int;

    auto
    get_capture_count () const -> int;

    auto
    get_has_cr_or_lf () const -> bool;

    auto
    get_max_lookbehind () const -> int;

    auto
    get_string_number (Glib::UStringView name) const -> int;

    auto
    get_compile_flags () const -> CompileFlags;

    auto
    get_match_flags () const -> MatchFlags;

    static auto
    escape_string (const Glib::ustring& string) -> Glib::ustring;

    static auto
    match_simple (Glib::UStringView pattern,
                  Glib::UStringView string,
                  CompileFlags compile_options = static_cast<CompileFlags> (0),
                  MatchFlags match_options = static_cast<MatchFlags> (0))
        -> bool;

    auto
    match (Glib::UStringView string,
           Glib::MatchInfo& match_info,
           MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match (Glib::UStringView string,
           MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match (Glib::UStringView string,
           int start_position,
           Glib::MatchInfo& match_info,
           MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match (Glib::UStringView string,
           gssize string_len,
           int start_position,
           Glib::MatchInfo& match_info,
           MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match (Glib::UStringView string,
           int start_position,
           MatchFlags match_options) -> bool;

    auto
    match (Glib::UStringView string,
           gssize string_len,
           int start_position,
           MatchFlags match_options) -> bool;

    auto
    match_all (Glib::UStringView string,
               Glib::MatchInfo& match_info,
               MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match_all (Glib::UStringView string,
               MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match_all (Glib::UStringView string,
               int start_position,
               Glib::MatchInfo& match_info,
               MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match_all (Glib::UStringView string,
               gssize string_len,
               int start_position,
               Glib::MatchInfo& match_info,
               MatchFlags match_options = static_cast<MatchFlags> (0)) -> bool;

    auto
    match_all (Glib::UStringView string,
               int start_position,
               MatchFlags match_options) -> bool;

    auto
    match_all (Glib::UStringView string,
               gssize string_len,
               int start_position,
               MatchFlags match_options) -> bool;

    static auto
    split_simple (Glib::UStringView pattern,
                  Glib::UStringView string,
                  CompileFlags compile_options = static_cast<CompileFlags> (0),
                  MatchFlags match_options = static_cast<MatchFlags> (0))
        -> std::vector<Glib::ustring>;

    auto
    split (Glib::UStringView string,
           MatchFlags match_options = static_cast<MatchFlags> (0))
        -> std::vector<Glib::ustring>;

    auto
    split (const gchar* string,
           gssize string_len,
           int start_position,
           MatchFlags match_options = static_cast<MatchFlags> (0),
           int max_tokens = 0) const -> std::vector<Glib::ustring>;

    auto
    split (Glib::UStringView string,
           int start_position,
           MatchFlags match_options,
           int max_tokens) const -> std::vector<Glib::ustring>;

    auto
    replace (const gchar* string,
             gssize string_len,
             int start_position,
             Glib::UStringView replacement,
             MatchFlags match_options = static_cast<MatchFlags> (0))
        -> Glib::ustring;

    auto
    replace (Glib::UStringView string,
             int start_position,
             Glib::UStringView replacement,
             MatchFlags match_options) -> Glib::ustring;

    auto
    replace_literal (const gchar* string,
                     gssize string_len,
                     int start_position,
                     Glib::UStringView replacement,
                     MatchFlags match_options = static_cast<MatchFlags> (0))
        -> Glib::ustring;

    auto
    replace_literal (Glib::UStringView string,
                     int start_position,
                     Glib::UStringView replacement,
                     MatchFlags match_options) -> Glib::ustring;

    auto
    replace_eval (Glib::UStringView string,
                  gssize string_len,
                  int start_position,
                  MatchFlags match_options,
                  GRegexEvalCallback eval,
                  gpointer user_data) -> Glib::ustring;

    static auto
    check_replacement (Glib::UStringView replacement, gboolean* has_references)
        -> bool;
  };

  class LIBMM_GLIB_SYMEXPORT MatchInfo
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MatchInfo;
    using BaseObjectType = GMatchInfo;
#endif

  private:
  public:
    MatchInfo ();

    explicit MatchInfo (GMatchInfo* castitem, bool take_ownership = true);

    MatchInfo (const MatchInfo& other) = delete;
    auto
    operator= (const MatchInfo& other) -> MatchInfo& = delete;

    MatchInfo (MatchInfo&& other) noexcept;
    auto
    operator= (MatchInfo&& other) noexcept -> MatchInfo&;

    virtual ~MatchInfo ();

    auto
    gobj () -> GMatchInfo*
    {
      return reinterpret_cast<GMatchInfo*> (gobject_);
    }

    auto
    gobj () const -> const GMatchInfo*
    {
      return reinterpret_cast<GMatchInfo*> (gobject_);
    }

  private:
    friend class Regex;

  public:
    auto
    get_regex () -> Glib::RefPtr<Regex>;

    auto
    get_regex () const -> Glib::RefPtr<const Regex>;

    auto
    get_string () const -> Glib::ustring;

    auto
    matches () const -> bool;

    auto
    next () -> bool;

    auto
    get_match_count () const -> int;

    auto
    is_partial_match () const -> bool;

    auto
    expand_references (Glib::UStringView string_to_expand) -> Glib::ustring;

    auto
    fetch (int match_num) -> Glib::ustring;

    auto
    fetch_pos (int match_num, int& start_pos, int& end_pos) -> bool;

    auto
    fetch_named (Glib::UStringView name) -> Glib::ustring;

    auto
    fetch_named_pos (Glib::UStringView name, int& start_pos, int& end_pos)
        -> bool;

    auto
    fetch_all () -> std::vector<Glib::ustring>;

  protected:
    GMatchInfo* gobject_;
    bool take_ownership_;

  protected:
    auto
    set_gobject (GMatchInfo* castitem, bool take_ownership = true) -> void;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  operator| (Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  {
    return static_cast<Regex::CompileFlags> (static_cast<unsigned> (lhs) |
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  {
    return static_cast<Regex::CompileFlags> (static_cast<unsigned> (lhs) &
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Regex::CompileFlags lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags
  {
    return static_cast<Regex::CompileFlags> (static_cast<unsigned> (lhs) ^
                                             static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Regex::CompileFlags flags) -> Regex::CompileFlags
  {
    return static_cast<Regex::CompileFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  {
    return (lhs = static_cast<Regex::CompileFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  {
    return (lhs = static_cast<Regex::CompileFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Regex::CompileFlags& lhs, Regex::CompileFlags rhs) -> Regex::CompileFlags&
  {
    return (lhs = static_cast<Regex::CompileFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Glib

namespace Glib
{

  inline auto
  operator| (Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  {
    return static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  {
    return static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Regex::MatchFlags lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags
  {
    return static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Regex::MatchFlags flags) -> Regex::MatchFlags
  {
    return static_cast<Regex::MatchFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  {
    return (lhs = static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  {
    return (lhs = static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Regex::MatchFlags& lhs, Regex::MatchFlags rhs) -> Regex::MatchFlags&
  {
    return (lhs = static_cast<Regex::MatchFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }
} // namespace Glib

namespace Glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GRegex* object, bool take_copy = false) -> Glib::RefPtr<Glib::Regex>;

} // namespace Glib

#endif
