// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/regex.hxx>
#include <libmm/glib/regex_p.hxx>

#include <libmm/glib/utility.hxx>

using CompileFlags = Glib::Regex::CompileFlags;
using MatchFlags = Glib::Regex::MatchFlags;

namespace Glib
{

  auto
  Regex::create (const UStringView pattern,
                 CompileFlags compile_options,
                 MatchFlags match_options) -> RefPtr<Regex>
  {
    GError* gerror = nullptr;
    const auto regex = g_regex_new (pattern.c_str (),
                                    (GRegexCompileFlags) compile_options,
                                    (GRegexMatchFlags) match_options,
                                    &gerror);

    if (gerror)
      Error::throw_exception (gerror);
    return wrap (regex);
  }

  auto
  Regex::escape_string (const ustring& string) -> ustring
  {
    const auto buf = make_unique_ptr_gfree (
        g_regex_escape_string (string.raw ().c_str (), string.raw ().size ()));
    return {buf.get ()};
  }

  auto
  Regex::match (const UStringView string,
                MatchInfo& match_info,
                MatchFlags match_options) -> bool
  {
    GMatchInfo* ginfo = nullptr;
    const bool result = static_cast<bool> (
        g_regex_match (gobj (),
                       string.c_str (),
                       static_cast<GRegexMatchFlags> (match_options),
                       &ginfo));
    match_info.set_gobject (ginfo);
    return result;
  }

  auto
  Regex::match (const UStringView string, MatchFlags match_options) -> bool
  {
    return g_regex_match (gobj (),
                          string.c_str (),
                          (GRegexMatchFlags) match_options,
                          nullptr);
  }

  auto
  Regex::match (const UStringView string,
                const int start_position,
                MatchInfo& match_info,
                MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    GMatchInfo* ginfo = nullptr;

    const bool result = static_cast<bool> (
        g_regex_match_full (gobj (),
                            string.c_str (),
                            -1,
                            start_position,
                            static_cast<GRegexMatchFlags> (match_options),
                            &ginfo,
                            &gerror));

    if (gerror)
      Error::throw_exception (gerror);

    match_info.set_gobject (ginfo);
    return result;
  }

  auto
  Regex::match (const UStringView string,
                const gssize string_len,
                const int start_position,
                MatchInfo& match_info,
                MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    GMatchInfo* ginfo = nullptr;

    const bool result = static_cast<bool> (
        g_regex_match_full (gobj (),
                            string.c_str (),
                            string_len,
                            start_position,
                            static_cast<GRegexMatchFlags> (match_options),
                            &ginfo,
                            &gerror));

    if (gerror)
      Error::throw_exception (gerror);

    match_info.set_gobject (ginfo);
    return result;
  }

  auto
  Regex::match (const UStringView string,
                const int start_position,
                MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_regex_match_full (gobj (),
                                              string.c_str (),
                                              -1,
                                              start_position,
                                              (GRegexMatchFlags) match_options,
                                              nullptr,
                                              &gerror);
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::match (const UStringView string,
                const gssize string_len,
                const int start_position,
                MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_regex_match_full (gobj (),
                                              string.c_str (),
                                              string_len,
                                              start_position,
                                              (GRegexMatchFlags) match_options,
                                              nullptr,
                                              &gerror);
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::match_all (const UStringView string,
                    MatchInfo& match_info,
                    MatchFlags match_options) -> bool
  {
    GMatchInfo* ginfo = nullptr;
    const bool result = static_cast<bool> (
        g_regex_match_all (gobj (),
                           string.c_str (),
                           static_cast<GRegexMatchFlags> (match_options),
                           &ginfo));
    match_info.set_gobject (ginfo);
    return result;
  }

  auto
  Regex::match_all (const UStringView string, MatchFlags match_options) -> bool
  {
    return g_regex_match_all (gobj (),
                              string.c_str (),
                              (GRegexMatchFlags) match_options,
                              nullptr);
  }

  auto
  Regex::match_all (const UStringView string,
                    const int start_position,
                    MatchInfo& match_info,
                    MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    GMatchInfo* ginfo = nullptr;

    const bool retvalue = static_cast<bool> (
        g_regex_match_all_full (gobj (),
                                string.c_str (),
                                -1,
                                start_position,
                                static_cast<GRegexMatchFlags> (match_options),
                                &ginfo,
                                &gerror));

    if (gerror)
      Error::throw_exception (gerror);

    match_info.set_gobject (ginfo);
    return retvalue;
  }

  auto
  Regex::match_all (const UStringView string,
                    const gssize string_len,
                    const int start_position,
                    MatchInfo& match_info,
                    MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    GMatchInfo* ginfo = nullptr;

    const bool retvalue = static_cast<bool> (
        g_regex_match_all_full (gobj (),
                                string.c_str (),
                                string_len,
                                start_position,
                                static_cast<GRegexMatchFlags> (match_options),
                                &ginfo,
                                &gerror));

    if (gerror)
      Error::throw_exception (gerror);

    match_info.set_gobject (ginfo);
    return retvalue;
  }

  auto
  Regex::match_all (const UStringView string,
                    const int start_position,
                    MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_regex_match_all_full (
        gobj (),
        string.c_str (),
        -1,
        start_position,
        (GRegexMatchFlags) match_options,
        nullptr,
        &gerror);
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::match_all (const UStringView string,
                    const gssize string_len,
                    const int start_position,
                    MatchFlags match_options) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = g_regex_match_all_full (
        gobj (),
        string.c_str (),
        string_len,
        start_position,
        (GRegexMatchFlags) match_options,
        nullptr,
        &gerror);
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::replace (const UStringView string,
                  const int start_position,
                  const UStringView replacement,
                  MatchFlags match_options) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_regex_replace (gobj (),
                         string.c_str (),
                         -1,
                         start_position,
                         replacement.c_str (),
                         (GRegexMatchFlags) match_options,
                         &gerror));
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::replace_literal (const UStringView string,
                          const int start_position,
                          const UStringView replacement,
                          MatchFlags match_options) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_regex_replace_literal (gobj (),
                                 string.c_str (),
                                 -1,
                                 start_position,
                                 replacement.c_str (),
                                 (GRegexMatchFlags) match_options,
                                 &gerror));
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Regex::split (const UStringView string,
                const int start_position,
                MatchFlags match_options,
                const int max_tokens) const -> std::vector<ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = ArrayHandler<ustring>::array_to_vector (
        g_regex_split_full (gobj (),
                            string.c_str (),
                            -1,
                            start_position,
                            (GRegexMatchFlags) match_options,
                            max_tokens,
                            &gerror),
        OWNERSHIP_DEEP);
    if (gerror)
      Error::throw_exception (gerror);

    return retvalue;
  }

  MatchInfo::MatchInfo ()
    : gobject_ (nullptr),
      take_ownership_ (false)
  {
  }

  MatchInfo::MatchInfo (GMatchInfo* castitem, const bool take_ownership)
    : gobject_ (castitem),
      take_ownership_ (take_ownership)
  {
  }

  MatchInfo::MatchInfo (MatchInfo&& other) noexcept
    : gobject_ (std::move (other.gobject_)),
      take_ownership_ (std::move (other.take_ownership_))
  {
    other.gobject_ = nullptr;
    other.take_ownership_ = false;
  }

  auto
  MatchInfo::operator= (MatchInfo&& other) noexcept -> MatchInfo&
  {
    if (take_ownership_ && gobject_)
      g_match_info_free (gobject_);

    gobject_ = std::move (other.gobject_);
    take_ownership_ = std::move (other.take_ownership_);

    other.gobject_ = nullptr;
    other.take_ownership_ = false;

    return *this;
  }

  auto
  MatchInfo::set_gobject (GMatchInfo* castitem, const bool take_ownership) -> void
  {
    if (gobject_ && this->take_ownership_)
      g_match_info_free (gobject_);

    gobject_ = castitem;
    this->take_ownership_ = take_ownership;
  }

  MatchInfo::~MatchInfo ()
  {
    if (take_ownership_ && gobject_)
      g_match_info_free (gobject_);
  }

} // namespace Glib

namespace
{
}

Glib::RegexError::RegexError (const Code error_code,
                              const ustring& error_message)
  : Error (G_REGEX_ERROR, error_code, error_message)
{
}

Glib::RegexError::RegexError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::RegexError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::RegexError::throw_func (GError* gobject) -> void
{
  throw RegexError (gobject);
}

namespace Glib
{

  auto
  wrap (GRegex* object, const bool take_copy) -> RefPtr<Regex>
  {
    if (take_copy && object)
      g_regex_ref (object);

    return Glib::make_refptr_for_instance<Regex> (
        reinterpret_cast<Regex*> (object));
  }

} // namespace Glib

namespace Glib
{

  auto
  Regex::reference () const -> void
  {
    g_regex_ref (reinterpret_cast<GRegex*> (const_cast<Regex*> (this)));
  }

  auto
  Regex::unreference () const -> void
  {
    g_regex_unref (reinterpret_cast<GRegex*> (const_cast<Regex*> (this)));
  }

  auto
  Regex::gobj () -> GRegex*
  {
    return reinterpret_cast<GRegex*> (this);
  }

  auto
  Regex::gobj () const -> const GRegex*
  {
    return reinterpret_cast<const GRegex*> (this);
  }

  auto
  Regex::gobj_copy () const -> GRegex*
  {
    const auto gobject = reinterpret_cast<GRegex*> (const_cast<Regex*> (this));
    g_regex_ref (gobject);
    return gobject;
  }

  auto
  Regex::get_pattern () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (g_regex_get_pattern (gobj ()));
  }

  auto
  Regex::get_max_backref () const -> int
  {
    return g_regex_get_max_backref (gobj ());
  }

  auto
  Regex::get_capture_count () const -> int
  {
    return g_regex_get_capture_count (gobj ());
  }

  auto
  Regex::get_has_cr_or_lf () const -> bool
  {
    return g_regex_get_has_cr_or_lf (gobj ());
  }

  auto
  Regex::get_max_lookbehind () const -> int
  {
    return g_regex_get_max_lookbehind (gobj ());
  }

  auto
  Regex::get_string_number (const UStringView name) const -> int
  {
    return g_regex_get_string_number (gobj (), name.c_str ());
  }

  auto
  Regex::get_compile_flags () const -> CompileFlags
  {
    return static_cast<CompileFlags> (g_regex_get_compile_flags (gobj ()));
  }

  auto
  Regex::get_match_flags () const -> MatchFlags
  {
    return static_cast<MatchFlags> (g_regex_get_match_flags (gobj ()));
  }

  auto
  Regex::match_simple (const UStringView pattern,
                       const UStringView string,
                       CompileFlags compile_options,
                       MatchFlags match_options) -> bool
  {
    return g_regex_match_simple (
        pattern.c_str (),
        string.c_str (),
        static_cast<GRegexCompileFlags> (compile_options),
        static_cast<GRegexMatchFlags> (match_options));
  }

  auto
  Regex::split_simple (const UStringView pattern,
                       const UStringView string,
                       CompileFlags compile_options,
                       MatchFlags match_options) -> std::vector<ustring>
  {
    return ArrayHandler<ustring>::array_to_vector (
        g_regex_split_simple (pattern.c_str (),
                              string.c_str (),
                              static_cast<GRegexCompileFlags> (compile_options),
                              static_cast<GRegexMatchFlags> (match_options)),
        OWNERSHIP_DEEP);
  }

  auto
  Regex::split (const UStringView string, MatchFlags match_options) -> std::vector<ustring>
  {
    return ArrayHandler<ustring>::array_to_vector (
        g_regex_split (gobj (),
                       string.c_str (),
                       static_cast<GRegexMatchFlags> (match_options)),
        OWNERSHIP_DEEP);
  }

  auto
  Regex::split (const gchar* string,
                const gssize string_len,
                const int start_position,
                MatchFlags match_options,
                const int max_tokens) const -> std::vector<ustring>
  {
    GError* gerror = nullptr;
    auto retvalue = ArrayHandler<ustring>::array_to_vector (
        g_regex_split_full (gobj (),
                            string,
                            string_len,
                            start_position,
                            static_cast<GRegexMatchFlags> (match_options),
                            max_tokens,
                            &gerror),
        OWNERSHIP_DEEP);
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Regex::replace (const gchar* string,
                  const gssize string_len,
                  const int start_position,
                  const UStringView replacement,
                  MatchFlags match_options) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_regex_replace (gobj (),
                         string,
                         string_len,
                         start_position,
                         replacement.c_str (),
                         static_cast<GRegexMatchFlags> (match_options),
                         &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Regex::replace_literal (const gchar* string,
                          const gssize string_len,
                          const int start_position,
                          const UStringView replacement,
                          MatchFlags match_options) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_regex_replace_literal (gobj (),
                                 string,
                                 string_len,
                                 start_position,
                                 replacement.c_str (),
                                 static_cast<GRegexMatchFlags> (match_options),
                                 &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Regex::replace_eval (const UStringView string,
                       const gssize string_len,
                       const int start_position,
                       MatchFlags match_options,
                       const GRegexEvalCallback eval,
                       const gpointer user_data) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_regex_replace_eval (gobj (),
                              string.c_str (),
                              string_len,
                              start_position,
                              static_cast<GRegexMatchFlags> (match_options),
                              eval,
                              user_data,
                              &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Regex::check_replacement (const UStringView replacement,
                            gboolean* has_references) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_regex_check_replacement (replacement.c_str (),
                                                     has_references,
                                                     &gerror);
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace Glib

namespace Glib
{

  auto
  MatchInfo::get_regex () -> RefPtr<Regex>
  {
    return wrap (g_match_info_get_regex (gobj ()));
  }

  auto
  MatchInfo::get_regex () const -> RefPtr<const Regex>
  {
    return const_cast<MatchInfo*> (this)->get_regex ();
  }

  auto
  MatchInfo::get_string () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_match_info_get_string (gobj ()));
  }

  auto
  MatchInfo::matches () const -> bool
  {
    return g_match_info_matches (gobj ());
  }

  auto
  MatchInfo::next () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_match_info_next (gobj (), &gerror);
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  MatchInfo::get_match_count () const -> int
  {
    return g_match_info_get_match_count (gobj ());
  }

  auto
  MatchInfo::is_partial_match () const -> bool
  {
    return g_match_info_is_partial_match (gobj ());
  }

  auto
  MatchInfo::expand_references (const UStringView string_to_expand) -> ustring
  {
    GError* gerror = nullptr;
    auto retvalue = convert_return_gchar_ptr_to_ustring (
        g_match_info_expand_references (gobj (),
                                        string_to_expand.c_str (),
                                        &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  MatchInfo::fetch (const int match_num) -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_match_info_fetch (gobj (), match_num));
  }

  auto
  MatchInfo::fetch_pos (const int match_num, int& start_pos, int& end_pos) -> bool
  {
    return g_match_info_fetch_pos (gobj (), match_num, &start_pos, &end_pos);
  }

  auto
  MatchInfo::fetch_named (const UStringView name) -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_match_info_fetch_named (gobj (), name.c_str ()));
  }

  auto
  MatchInfo::fetch_named_pos (const UStringView name,
                              int& start_pos,
                              int& end_pos) -> bool
  {
    return g_match_info_fetch_named_pos (gobj (),
                                         name.c_str (),
                                         &start_pos,
                                         &end_pos);
  }

  auto
  MatchInfo::fetch_all () -> std::vector<ustring>
  {
    return ArrayHandler<ustring>::array_to_vector (
        g_match_info_fetch_all (gobj ()),
        OWNERSHIP_DEEP);
  }

} // namespace Glib
