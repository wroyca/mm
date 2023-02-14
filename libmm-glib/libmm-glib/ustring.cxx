

#include <libmm-glib/convert.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/utility.hxx>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>
#ifdef HAVE_CONFIG_H
  #include <config.h>
#endif

#if !defined(SIZEOF_WCHAR_T) && defined(GLIBMM_SIZEOF_WCHAR_T)
  #define SIZEOF_WCHAR_T GLIBMM_SIZEOF_WCHAR_T
#endif

namespace
{

  using Glib::ustring;
  using Glib::UStringView;

  struct UnicharToUtf8
  {
    char buf[6];
    ustring::size_type len;

    explicit UnicharToUtf8 (const gunichar uc)
      : len (g_unichar_to_utf8 (uc, buf))
    {
    }
  };

  auto
  utf8_byte_offset (const char* str, ustring::size_type offset) -> ustring::size_type
  {
    if (offset == ustring::npos)
      return ustring::npos;

    const char* const utf8_skip = g_utf8_skip;
    const char* p = str;

    for (; offset != 0; --offset)
    {
      const unsigned int c = static_cast<unsigned char> (*p);

      if (c == 0)
        return ustring::npos;

      p += utf8_skip[c];
    }

    return p - str;
  }

  auto
  utf8_byte_offset (const char* str,
                    ustring::size_type offset,
                    const ustring::size_type maxlen) -> ustring::size_type
  {
    if (offset == ustring::npos)
      return ustring::npos;

    const char* const utf8_skip = g_utf8_skip;
    const char* const pend = str + maxlen;
    const char* p = str;

    for (; offset != 0; --offset)
    {
      if (p >= pend)
        return ustring::npos;

      p += utf8_skip[static_cast<unsigned char> (*p)];
    }

    return p - str;
  }

  inline auto
  utf8_byte_offset (const std::string& str, const ustring::size_type offset) -> ustring::size_type
  {
    return utf8_byte_offset (str.data (), offset, str.size ());
  }

  struct Utf8SubstrBounds
  {
    ustring::size_type i;
    ustring::size_type n;

    Utf8SubstrBounds (const std::string& str,
                      const ustring::size_type ci,
                      const ustring::size_type cn)
      : i (utf8_byte_offset (str, ci)),
        n (ustring::npos)
    {
      if (i != ustring::npos)
        n = utf8_byte_offset (str.data () + i, cn, str.size () - i);
    }
  };

  inline auto
  utf8_char_offset (const std::string& str, const ustring::size_type offset) -> ustring::size_type
  {
    if (offset == ustring::npos)
      return ustring::npos;

    const char* const pdata = str.data ();
    return g_utf8_pointer_to_offset (pdata, pdata + offset);
  }

  auto
  utf8_find_first_of (const std::string& str,
                      ustring::size_type offset,
                      const char* utf8_match,
                      const long utf8_match_size,
                      const bool find_not_of) -> ustring::size_type
  {
    const ustring::size_type byte_offset = utf8_byte_offset (str, offset);
    if (byte_offset == ustring::npos)
      return ustring::npos;

    long ucs4_match_size = 0;
    const auto ucs4_match = Glib::make_unique_ptr_gfree (
        g_utf8_to_ucs4_fast (utf8_match, utf8_match_size, &ucs4_match_size));

    const gunichar* const match_begin = ucs4_match.get ();
    const gunichar* const match_end = match_begin + ucs4_match_size;

    const char* const str_begin = str.data ();
    const char* const str_end = str_begin + str.size ();

    for (const char* pstr = str_begin + byte_offset; pstr < str_end;
         pstr = g_utf8_next_char (pstr))
    {
      const gunichar* const pfound =
          std::find (match_begin, match_end, g_utf8_get_char (pstr));

      if (pfound != match_end != find_not_of)
        return offset;

      ++offset;
    }

    return ustring::npos;
  }

  auto
  utf8_find_last_of (const std::string& str,
                     const ustring::size_type offset,
                     const char* utf8_match,
                     const long utf8_match_size,
                     const bool find_not_of) -> ustring::size_type
  {
    long ucs4_match_size = 0;
    const auto ucs4_match = Glib::make_unique_ptr_gfree (
        g_utf8_to_ucs4_fast (utf8_match, utf8_match_size, &ucs4_match_size));

    const gunichar* const match_begin = ucs4_match.get ();
    const gunichar* const match_end = match_begin + ucs4_match_size;

    const char* const str_begin = str.data ();
    const char* pstr = str_begin;

    const ustring::size_type byte_offset = utf8_byte_offset (str, offset);
    pstr += byte_offset < str.size () ? byte_offset + 1 : str.size ();

    while (pstr > str_begin)
    {
      do
        --pstr;
      while ((static_cast<unsigned char> (*pstr) & 0xC0u) == 0x80);

      const gunichar* const pfound =
          std::find (match_begin, match_end, g_utf8_get_char (pstr));

      if (pfound != match_end != find_not_of)
        return g_utf8_pointer_to_offset (str_begin, pstr);
    }

    return ustring::npos;
  }

} // namespace

namespace Glib
{

#ifndef GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS

  const ustring::size_type ustring::npos = std::string::npos;
#endif

  auto
  get_unichar_from_std_iterator (std::string::const_iterator pos) -> gunichar
  {
    unsigned int result = static_cast<unsigned char> (*pos);

    if ((result & 0x80) != 0)
    {
      unsigned int mask = 0x40;

      do
      {
        result <<= 6;
        const unsigned int c = static_cast<unsigned char> (*++pos);
        mask <<= 5;
        result += c - 0x80;
      } while ((result & mask) != 0);

      result &= mask - 1;
    }

    return result;
  }

  ustring::ustring ()
    : string_ ()
  {
  }

  ustring::ustring (const ustring& other) = default;

  ustring::ustring (ustring&& other)
    : string_ (std::move (other.string_))
  {
  }

  ustring::ustring (const ustring& src, const size_type i, const size_type n)
    : string_ ()
  {
    const Utf8SubstrBounds bounds (src.string_, i, n);
    string_.assign (src.string_, bounds.i, bounds.n);
  }

  ustring::ustring (const char* src, const size_type n)
    : string_ (src, utf8_byte_offset (src, n))
  {
  }

  ustring::ustring (const char* src)
    : string_ (src)
  {
  }

  ustring::ustring (size_type n, const gunichar uc)
    : string_ ()
  {
    if (uc < 0x80)
    {
      string_.assign (n, static_cast<char> (uc));
    }
    else
    {
      const UnicharToUtf8 conv (uc);
      string_.reserve (n * conv.len);

      for (; n > 0; --n)
        string_.append (conv.buf, conv.len);
    }
  }

  ustring::ustring (const size_type n, const char c)
    : string_ (n, c)
  {
  }

  ustring::ustring (const std::string& src)
    : string_ (src)
  {
  }

  ustring::ustring (std::string&& src)
    : string_ (std::move (src))
  {
  }

  ustring::~ustring () noexcept = default;

  auto
  ustring::swap (ustring& other) -> void
  {
    string_.swap (other.string_);
  }

  auto
  ustring::operator= (const ustring& other) -> ustring& = default;

  auto
  ustring::operator= (ustring&& other) -> ustring&
  {
    string_ = std::move (other.string_);
    return *this;
  }

  auto
  ustring::operator= (const std::string& src) -> ustring&
  {
    string_ = src;
    return *this;
  }

  auto
  ustring::operator= (std::string&& src) -> ustring&
  {
    string_ = std::move (src);
    return *this;
  }

  auto
  ustring::operator= (const char* src) -> ustring&
  {
    string_ = src;
    return *this;
  }

  auto
  ustring::operator= (const gunichar uc) -> ustring&
  {
    const UnicharToUtf8 conv (uc);
    string_.assign (conv.buf, conv.len);
    return *this;
  }

  auto
  ustring::operator= (const char c) -> ustring&
  {
    string_ = c;
    return *this;
  }

  auto
  ustring::assign (const ustring& src) -> ustring&
  {
    string_ = src.string_;
    return *this;
  }

  auto
  ustring::assign (ustring&& src) -> ustring&
  {
    string_ = std::move (src.string_);
    return *this;
  }

  auto
  ustring::assign (const ustring& src, const size_type i, const size_type n) -> ustring&
  {
    const Utf8SubstrBounds bounds (src.string_, i, n);
    string_.assign (src.string_, bounds.i, bounds.n);
    return *this;
  }

  auto
  ustring::assign (const char* src, const size_type n) -> ustring&
  {
    string_.assign (src, utf8_byte_offset (src, n));
    return *this;
  }

  auto
  ustring::assign (const char* src) -> ustring&
  {
    string_ = src;
    return *this;
  }

  auto
  ustring::assign (const size_type n, const gunichar uc) -> ustring&
  {
    ustring temp (n, uc);
    string_.swap (temp.string_);
    return *this;
  }

  auto
  ustring::assign (const size_type n, const char c) -> ustring&
  {
    string_.assign (n, c);
    return *this;
  }

  auto
  ustring::operator+= (const ustring& src) -> ustring&
  {
    string_ += src.string_;
    return *this;
  }

  auto
  ustring::operator+= (const char* src) -> ustring&
  {
    string_ += src;
    return *this;
  }

  auto
  ustring::operator+= (const gunichar uc) -> ustring&
  {
    const UnicharToUtf8 conv (uc);
    string_.append (conv.buf, conv.len);
    return *this;
  }

  auto
  ustring::operator+= (const char c) -> ustring&
  {
    string_ += c;
    return *this;
  }

  auto
  ustring::push_back (const gunichar uc) -> void
  {
    const UnicharToUtf8 conv (uc);
    string_.append (conv.buf, conv.len);
  }

  auto
  ustring::push_back (const char c) -> void
  {
    string_ += c;
  }

  auto
  ustring::append (const ustring& src) -> ustring&
  {
    string_ += src.string_;
    return *this;
  }

  auto
  ustring::append (const ustring& src, const size_type i, const size_type n) -> ustring&
  {
    const Utf8SubstrBounds bounds (src.string_, i, n);
    string_.append (src.string_, bounds.i, bounds.n);
    return *this;
  }

  auto
  ustring::append (const char* src, const size_type n) -> ustring&
  {
    string_.append (src, utf8_byte_offset (src, n));
    return *this;
  }

  auto
  ustring::append (const char* src) -> ustring&
  {
    string_ += src;
    return *this;
  }

  auto
  ustring::append (const size_type n, const gunichar uc) -> ustring&
  {
    string_.append (ustring (n, uc).string_);
    return *this;
  }

  auto
  ustring::append (const size_type n, const char c) -> ustring&
  {
    string_.append (n, c);
    return *this;
  }

  auto
  ustring::insert (const size_type i, const ustring& src) -> ustring&
  {
    string_.insert (utf8_byte_offset (string_, i), src.string_);
    return *this;
  }

  auto
  ustring::insert (const size_type i,
                   const ustring& src,
                   const size_type i2,
                   const size_type n) -> ustring&
  {
    const Utf8SubstrBounds bounds2 (src.string_, i2, n);
    string_.insert (utf8_byte_offset (string_, i),
                    src.string_,
                    bounds2.i,
                    bounds2.n);
    return *this;
  }

  auto
  ustring::insert (const size_type i, const char* src, const size_type n) -> ustring&
  {
    string_.insert (utf8_byte_offset (string_, i),
                    src,
                    utf8_byte_offset (src, n));
    return *this;
  }

  auto
  ustring::insert (const size_type i, const char* src) -> ustring&
  {
    string_.insert (utf8_byte_offset (string_, i), src);
    return *this;
  }

  auto
  ustring::insert (const size_type i, const size_type n, const gunichar uc) -> ustring&
  {
    string_.insert (utf8_byte_offset (string_, i), ustring (n, uc).string_);
    return *this;
  }

  auto
  ustring::insert (const size_type i, const size_type n, const char c) -> ustring&
  {
    string_.insert (utf8_byte_offset (string_, i), n, c);
    return *this;
  }

  auto
  ustring::insert (const iterator p, const gunichar uc) -> iterator
  {
    const size_type offset = p.base () - string_.begin ();
    const UnicharToUtf8 conv (uc);
    string_.insert (offset, conv.buf, conv.len);
    return iterator (string_.begin () + offset);
  }

  auto
  ustring::insert (const iterator p, const char c) -> iterator
  {
    return iterator (string_.insert (p.base (), c));
  }

  auto
  ustring::insert (const iterator p, const size_type n, const gunichar uc) -> void
  {
    string_.insert (p.base () - string_.begin (), ustring (n, uc).string_);
  }

  auto
  ustring::insert (const iterator p, const size_type n, const char c) -> void
  {
    string_.insert (p.base (), n, c);
  }

  auto
  ustring::replace (const size_type i, const size_type n, const ustring& src) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.replace (bounds.i, bounds.n, src.string_);
    return *this;
  }

  auto
  ustring::replace (const size_type i,
                    const size_type n,
                    const ustring& src,
                    const size_type i2,
                    const size_type n2) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    const Utf8SubstrBounds bounds2 (src.string_, i2, n2);
    string_.replace (bounds.i, bounds.n, src.string_, bounds2.i, bounds2.n);
    return *this;
  }

  auto
  ustring::replace (const size_type i,
                    const size_type n,
                    const char* src,
                    const size_type n2) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.replace (bounds.i, bounds.n, src, utf8_byte_offset (src, n2));
    return *this;
  }

  auto
  ustring::replace (const size_type i, const size_type n, const char* src) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.replace (bounds.i, bounds.n, src);
    return *this;
  }

  auto
  ustring::replace (const size_type i,
                    const size_type n,
                    const size_type n2,
                    const gunichar uc) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.replace (bounds.i, bounds.n, ustring (n2, uc).string_);
    return *this;
  }

  auto
  ustring::replace (const size_type i,
                    const size_type n,
                    const size_type n2,
                    const char c) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.replace (bounds.i, bounds.n, n2, c);
    return *this;
  }

  auto
  ustring::replace (const iterator pbegin,
                    const iterator pend,
                    const ustring& src) -> ustring&
  {
    string_.replace (pbegin.base (), pend.base (), src.string_);
    return *this;
  }

  auto
  ustring::replace (const iterator pbegin,
                    const iterator pend,
                    const char* src,
                    const size_type n) -> ustring&
  {
    string_.replace (pbegin.base (),
                     pend.base (),
                     src,
                     utf8_byte_offset (src, n));
    return *this;
  }

  auto
  ustring::replace (const iterator pbegin, const iterator pend, const char* src) -> ustring&
  {
    string_.replace (pbegin.base (), pend.base (), src);
    return *this;
  }

  auto
  ustring::replace (const iterator pbegin,
                    const iterator pend,
                    const size_type n,
                    const gunichar uc) -> ustring&
  {
    string_.replace (pbegin.base (), pend.base (), ustring (n, uc).string_);
    return *this;
  }

  auto
  ustring::replace (const iterator pbegin,
                    const iterator pend,
                    const size_type n,
                    const char c) -> ustring&
  {
    string_.replace (pbegin.base (), pend.base (), n, c);
    return *this;
  }

  auto
  ustring::clear () -> void
  {
    string_.erase ();
  }

  auto
  ustring::erase (const size_type i, const size_type n) -> ustring&
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    string_.erase (bounds.i, bounds.n);
    return *this;
  }

  auto
  ustring::erase () -> ustring&
  {
    string_.erase ();
    return *this;
  }

  auto
  ustring::erase (const iterator p) -> iterator
  {
    iterator iter_end = p;
    ++iter_end;

    return iterator (string_.erase (p.base (), iter_end.base ()));
  }

  auto
  ustring::erase (const iterator pbegin, const iterator pend) -> iterator
  {
    return iterator (string_.erase (pbegin.base (), pend.base ()));
  }

  auto
  ustring::compare (const UStringView rhs) const -> int
  {
    return g_utf8_collate (string_.c_str (), rhs.c_str ());
  }

  auto
  ustring::compare (const size_type i,
                    const size_type n,
                    const UStringView rhs) const -> int
  {
    return ustring (*this, i, n).compare (rhs.c_str ());
  }

  auto
  ustring::compare (const size_type i,
                    const size_type n,
                    const ustring& rhs,
                    const size_type i2,
                    const size_type n2) const -> int
  {
    return ustring (*this, i, n).compare (ustring (rhs, i2, n2));
  }

  auto
  ustring::compare (const size_type i,
                    const size_type n,
                    const char* rhs,
                    const size_type n2) const -> int
  {
    return ustring (*this, i, n).compare (ustring (rhs, n2));
  }

  auto
  ustring::operator[] (const size_type i) const -> value_type
  {
    return g_utf8_get_char (g_utf8_offset_to_pointer (string_.data (), i));
  }

  auto
  ustring::at (const size_type i) const -> value_type
  {
    const size_type byte_offset = utf8_byte_offset (string_, i);

    return g_utf8_get_char (&string_.at (byte_offset));
  }

  auto
  ustring::begin () -> iterator
  {
    return iterator (string_.begin ());
  }

  auto
  ustring::end () -> iterator
  {
    return iterator (string_.end ());
  }

  auto
  ustring::begin () const -> const_iterator
  {
    return const_iterator (string_.begin ());
  }

  auto
  ustring::end () const -> const_iterator
  {
    return const_iterator (string_.end ());
  }

  auto
  ustring::rbegin () -> reverse_iterator
  {
    return reverse_iterator (iterator (string_.end ()));
  }

  auto
  ustring::rend () -> reverse_iterator
  {
    return reverse_iterator (iterator (string_.begin ()));
  }

  auto
  ustring::rbegin () const -> const_reverse_iterator
  {
    return const_reverse_iterator (const_iterator (string_.end ()));
  }

  auto
  ustring::rend () const -> const_reverse_iterator
  {
    return const_reverse_iterator (const_iterator (string_.begin ()));
  }

  auto
  ustring::cbegin () const -> const_iterator
  {
    return const_iterator (string_.begin ());
  }

  auto
  ustring::cend () const -> const_iterator
  {
    return const_iterator (string_.end ());
  }

  auto
  ustring::find (const ustring& str, const size_type i) const -> size_type
  {
    return utf8_char_offset (
        string_,
        string_.find (str.string_, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::find (const char* str, const size_type i, const size_type n) const -> size_type
  {
    return utf8_char_offset (string_,
                             string_.find (str,
                                           utf8_byte_offset (string_, i),
                                           utf8_byte_offset (str, n)));
  }

  auto
  ustring::find (const char* str, const size_type i) const -> size_type
  {
    return utf8_char_offset (string_,
                             string_.find (str, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::find (const gunichar uc, const size_type i) const -> size_type
  {
    const UnicharToUtf8 conv (uc);
    return utf8_char_offset (
        string_,
        string_.find (conv.buf, utf8_byte_offset (string_, i), conv.len));
  }

  auto
  ustring::find (const char c, const size_type i) const -> size_type
  {
    return utf8_char_offset (string_,
                             string_.find (c, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::rfind (const ustring& str, const size_type i) const -> size_type
  {
    return utf8_char_offset (
        string_,
        string_.rfind (str.string_, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::rfind (const char* str, const size_type i, const size_type n) const -> size_type
  {
    return utf8_char_offset (string_,
                             string_.rfind (str,
                                            utf8_byte_offset (string_, i),
                                            utf8_byte_offset (str, n)));
  }

  auto
  ustring::rfind (const char* str, const size_type i) const -> size_type
  {
    return utf8_char_offset (
        string_,
        string_.rfind (str, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::rfind (const gunichar uc, const size_type i) const -> size_type
  {
    const UnicharToUtf8 conv (uc);
    return utf8_char_offset (
        string_,
        string_.rfind (conv.buf, utf8_byte_offset (string_, i), conv.len));
  }

  auto
  ustring::rfind (const char c, const size_type i) const -> size_type
  {
    return utf8_char_offset (string_,
                             string_.rfind (c, utf8_byte_offset (string_, i)));
  }

  auto
  ustring::find_first_of (const ustring& match, const size_type i) const -> size_type
  {
    return utf8_find_first_of (string_,
                               i,
                               match.string_.data (),
                               match.string_.size (),
                               false);
  }

  auto
  ustring::find_first_of (const char* match,
                          const size_type i,
                          const size_type n) const -> size_type
  {
    return utf8_find_first_of (string_, i, match, n, false);
  }

  auto
  ustring::find_first_of (const char* match, const size_type i) const -> size_type
  {
    return utf8_find_first_of (string_, i, match, -1, false);
  }

  auto
  ustring::find_first_of (const gunichar uc, const size_type i) const -> size_type
  {
    return find (uc, i);
  }

  auto
  ustring::find_first_of (const char c, const size_type i) const -> size_type
  {
    return find (c, i);
  }

  auto
  ustring::find_last_of (const ustring& match, const size_type i) const -> size_type
  {
    return utf8_find_last_of (string_,
                              i,
                              match.string_.data (),
                              match.string_.size (),
                              false);
  }

  auto
  ustring::find_last_of (const char* match,
                         const size_type i,
                         const size_type n) const -> size_type
  {
    return utf8_find_last_of (string_, i, match, n, false);
  }

  auto
  ustring::find_last_of (const char* match, const size_type i) const -> size_type
  {
    return utf8_find_last_of (string_, i, match, -1, false);
  }

  auto
  ustring::find_last_of (const gunichar uc, const size_type i) const -> size_type
  {
    return rfind (uc, i);
  }

  auto
  ustring::find_last_of (const char c, const size_type i) const -> size_type
  {
    return rfind (c, i);
  }

  auto
  ustring::find_first_not_of (const ustring& match, const size_type i) const -> size_type
  {
    return utf8_find_first_of (string_,
                               i,
                               match.string_.data (),
                               match.string_.size (),
                               true);
  }

  auto
  ustring::find_first_not_of (const char* match,
                              const size_type i,
                              const size_type n) const -> size_type
  {
    return utf8_find_first_of (string_, i, match, n, true);
  }

  auto
  ustring::find_first_not_of (const char* match, const size_type i) const -> size_type
  {
    return utf8_find_first_of (string_, i, match, -1, true);
  }

  auto
  ustring::find_first_not_of (const gunichar uc, size_type i) const -> size_type
  {
    const size_type bi = utf8_byte_offset (string_, i);
    if (bi != npos)
    {
      const char* const pbegin = string_.data ();
      const char* const pend = pbegin + string_.size ();

      for (const char* p = pbegin + bi; p < pend; p = g_utf8_next_char (p), ++i)
      {
        if (g_utf8_get_char (p) != uc)
          return i;
      }
    }
    return npos;
  }

  auto
  ustring::find_first_not_of (const char c, size_type i) const -> size_type
  {
    const size_type bi = utf8_byte_offset (string_, i);
    if (bi != npos)
    {
      const char* const pbegin = string_.data ();
      const char* const pend = pbegin + string_.size ();

      for (const char* p = pbegin + bi; p < pend; p = g_utf8_next_char (p), ++i)
      {
        if (*p != c)
          return i;
      }
    }
    return npos;
  }

  auto
  ustring::find_last_not_of (const ustring& match, const size_type i) const -> size_type
  {
    return utf8_find_last_of (string_,
                              i,
                              match.string_.data (),
                              match.string_.size (),
                              true);
  }

  auto
  ustring::find_last_not_of (const char* match,
                             const size_type i,
                             const size_type n) const -> size_type
  {
    return utf8_find_last_of (string_, i, match, n, true);
  }

  auto
  ustring::find_last_not_of (const char* match, const size_type i) const -> size_type
  {
    return utf8_find_last_of (string_, i, match, -1, true);
  }

  auto
  ustring::find_last_not_of (const gunichar uc, const size_type i) const -> size_type
  {
    const char* const pbegin = string_.data ();
    const char* const pend = pbegin + string_.size ();
    size_type i_cur = 0;
    size_type i_found = npos;

    for (const char* p = pbegin; p < pend && i_cur <= i;
         p = g_utf8_next_char (p), ++i_cur)
    {
      if (g_utf8_get_char (p) != uc)
        i_found = i_cur;
    }
    return i_found;
  }

  auto
  ustring::find_last_not_of (const char c, const size_type i) const -> size_type
  {
    const char* const pbegin = string_.data ();
    const char* const pend = pbegin + string_.size ();
    size_type i_cur = 0;
    size_type i_found = npos;

    for (const char* p = pbegin; p < pend && i_cur <= i;
         p = g_utf8_next_char (p), ++i_cur)
    {
      if (*p != c)
        i_found = i_cur;
    }
    return i_found;
  }

  auto
  ustring::empty () const -> bool
  {
    return string_.empty ();
  }

  auto
  ustring::size () const -> size_type
  {
    const char* const pdata = string_.data ();
    return g_utf8_pointer_to_offset (pdata, pdata + string_.size ());
  }

  auto
  ustring::length () const -> size_type
  {
    const char* const pdata = string_.data ();
    return g_utf8_pointer_to_offset (pdata, pdata + string_.size ());
  }

  auto
  ustring::bytes () const -> size_type
  {
    return string_.size ();
  }

  auto
  ustring::capacity () const -> size_type
  {
    return string_.capacity ();
  }

  auto
  ustring::max_size () const -> size_type
  {
    return string_.max_size ();
  }

  auto
  ustring::resize (const size_type n, const gunichar uc) -> void
  {
    const size_type size_now = size ();
    if (n < size_now)
      erase (n, npos);
    else if (n > size_now)
      append (n - size_now, uc);
  }

  auto
  ustring::resize (const size_type n, const char c) -> void
  {
    const size_type size_now = size ();
    if (n < size_now)
      erase (n, npos);
    else if (n > size_now)
      string_.append (n - size_now, c);
  }

  auto
  ustring::reserve (const size_type n) -> void
  {
    string_.reserve (n);
  }

  auto
  ustring::data () const -> const char*
  {
    return string_.data ();
  }

  auto
  ustring::c_str () const -> const char*
  {
    return string_.c_str ();
  }

  auto
  ustring::copy (char* dest, const size_type n, const size_type i) const -> size_type
  {
    const Utf8SubstrBounds bounds (string_, i, n);
    return string_.copy (dest, bounds.n, bounds.i);
  }

  auto
  ustring::validate () const -> bool
  {
    return g_utf8_validate (string_.data (), string_.size (), nullptr) != 0;
  }

  auto
  ustring::validate (iterator& first_invalid) -> bool
  {
    const char* const pdata = string_.data ();
    const char* valid_end = pdata;
    const int is_valid = g_utf8_validate (pdata, string_.size (), &valid_end);

    first_invalid = iterator (string_.begin () + (valid_end - pdata));
    return is_valid != 0;
  }

  auto
  ustring::validate (const_iterator& first_invalid) const -> bool
  {
    const char* const pdata = string_.data ();
    const char* valid_end = pdata;
    const int is_valid = g_utf8_validate (pdata, string_.size (), &valid_end);

    first_invalid = const_iterator (string_.begin () + (valid_end - pdata));
    return is_valid != 0;
  }

  auto
  ustring::make_valid () const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_utf8_make_valid (string_.data (), string_.size ()));
  }

  auto
  ustring::is_ascii () const -> bool
  {
    const char* p = string_.data ();
    const char* const pend = p + string_.size ();

    for (; p != pend; ++p)
    {
      if ((static_cast<unsigned char> (*p) & 0x80u) != 0)
        return false;
    }

    return true;
  }

  auto
  ustring::normalize (NormalizeMode mode) const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_utf8_normalize (string_.data (),
                          string_.size (),
                          static_cast<GNormalizeMode> (int (mode))));
  }

  auto
  ustring::uppercase () const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_utf8_strup (string_.data (), string_.size ()));
  }

  auto
  ustring::lowercase () const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_utf8_strdown (string_.data (), string_.size ()));
  }

  auto
  ustring::casefold () const -> ustring
  {
    return convert_return_gchar_ptr_to_ustring (
        g_utf8_casefold (string_.data (), string_.size ()));
  }

  auto
  ustring::collate_key () const -> std::string
  {
    return convert_return_gchar_ptr_to_stdstring (
        g_utf8_collate_key (string_.data (), string_.size ()));
  }

  auto
  ustring::casefold_collate_key () const -> std::string
  {
    char* const casefold_buf = g_utf8_casefold (string_.data (),
                                                string_.size ());
    char* const key_buf = g_utf8_collate_key (casefold_buf, -1);
    g_free (casefold_buf);
    return std::string (make_unique_ptr_gfree (key_buf).get ());
  }

  auto
  ustring::compose_private (const ustring& fmt,
                            const std::initializer_list<const ustring*> ilist) -> ustring
  {
    std::string::size_type result_size = fmt.raw ().size ();

    for (const auto it : ilist)
      result_size += it->raw ().size ();

    std::string result;
    result.reserve (result_size);

    const char* const pfmt = fmt.raw ().c_str ();
    const char* start = pfmt;

    while (const char* const stop = std::strchr (start, '%'))
    {
      if (stop[1] == '%')
      {
        result.append (start, stop - start + 1);
        start = stop + 2;
      }
      else
      {
        const int index = Ascii::digit_value (stop[1]) - 1;
        const int size = ilist.size ();

        if (index >= 0 && index < size)
        {
          result.append (start, stop - start);
          result += (*(ilist.begin () + index))->raw ();
          start = stop + 2;
        }
        else
        {
          const char* const next =
              stop[1] != '\0' ? g_utf8_next_char (stop + 1) : stop + 1;

          result.append (start, next - start);

          g_warning ("invalid substitution \"%s\" in fmt string \"%s\"",
                     result.c_str () + result.size () - (next - stop),
                     pfmt);
          start = next;
        }
      }
    }

    result.append (start, pfmt + fmt.raw ().size () - start);

    return result;
  }

  ustring::SequenceToString<ustring::iterator, gunichar>::SequenceToString (
      const ustring::iterator pbegin,
      const ustring::iterator pend)
    : std::string (pbegin.base (), pend.base ())
  {
  }

  ustring::SequenceToString<ustring::const_iterator, gunichar>::
      SequenceToString (const ustring::const_iterator pbegin,
                        const ustring::const_iterator pend)
    : std::string (pbegin.base (), pend.base ())
  {
  }

  ustring::FormatStream::FormatStream ()
    : stream_ ()
  {
  }

  ustring::FormatStream::~FormatStream () noexcept = default;

  auto
  ustring::FormatStream::to_string () const -> ustring
  {
    GError* error = nullptr;

#ifdef GLIBMM_HAVE_WIDE_STREAM
    const std::wstring str = stream_.str ();

  #if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && \
      SIZEOF_WCHAR_T == 4

    glong n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_ucs4_to_utf8 (reinterpret_cast<const gunichar*> (str.data ()),
                        str.size (),
                        nullptr,
                        &n_bytes,
                        &error));
  #elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2

    glong n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_utf16_to_utf8 (reinterpret_cast<const gunichar2*> (str.data ()),
                         str.size (),
                         nullptr,
                         &n_bytes,
                         &error));
  #else
    gsize n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_convert (reinterpret_cast<const char*> (str.data ()),
                   str.size () * sizeof (std::wstring::value_type),
                   "UTF-8",
                   "WCHAR_T",
                   nullptr,
                   &n_bytes,
                   &error));
  #endif

#else
    const std::string str = stream_.str ();

    gsize n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_locale_to_utf8 (str.data (), str.size (), 0, &n_bytes, &error));
#endif

    if (error)
    {
      Error::throw_exception (error);
    }

    return {buf.get (), buf.get () + n_bytes};
  }

  auto
  operator>> (std::istream& is, ustring& utf8_string) -> std::istream&
  {
    std::string str;
    is >> str;

    GError* error = nullptr;
    gsize n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_locale_to_utf8 (str.data (), str.size (), nullptr, &n_bytes, &error));

    if (error)
    {
      Error::throw_exception (error);
    }

    utf8_string.assign (buf.get (), buf.get () + n_bytes);

    return is;
  }

  auto
  operator<< (std::ostream& os, const ustring& utf8_string) -> std::ostream&
  {
    GError* error = nullptr;
    const auto buf =
        make_unique_ptr_gfree (g_locale_from_utf8 (utf8_string.raw ().data (),
                                                   utf8_string.raw ().size (),
                                                   nullptr,
                                                   nullptr,
                                                   &error));
    if (error)
    {
      Error::throw_exception (error);
    }

    os << buf.get ();

    return os;
  }

#ifdef GLIBMM_HAVE_WIDE_STREAM

  auto
  operator>> (std::wistream& is, ustring& utf8_string) -> std::wistream&
  {
    GError* error = nullptr;

    std::wstring wstr;
    is >> wstr;

  #if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && \
      SIZEOF_WCHAR_T == 4

    glong n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_ucs4_to_utf8 (reinterpret_cast<const gunichar*> (wstr.data ()),
                        wstr.size (),
                        nullptr,
                        &n_bytes,
                        &error));
  #elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2

    glong n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_utf16_to_utf8 (reinterpret_cast<const gunichar2*> (wstr.data ()),
                         wstr.size (),
                         nullptr,
                         &n_bytes,
                         &error));
  #else
    gsize n_bytes = 0;
    const auto buf = make_unique_ptr_gfree (
        g_convert (reinterpret_cast<const char*> (wstr.data ()),
                   wstr.size () * sizeof (std::wstring::value_type),
                   "UTF-8",
                   "WCHAR_T",
                   nullptr,
                   &n_bytes,
                   &error));
  #endif

    if (error)
    {
      Error::throw_exception (error);
    }

    utf8_string.assign (buf.get (), buf.get () + n_bytes);

    return is;
  }

  auto
  operator<< (std::wostream& os, const ustring& utf8_string) -> std::wostream&
  {
    GError* error = nullptr;

  #if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && \
      SIZEOF_WCHAR_T == 4

    const auto buf =
        make_unique_ptr_gfree (g_utf8_to_ucs4 (utf8_string.raw ().data (),
                                               utf8_string.raw ().size (),
                                               nullptr,
                                               nullptr,
                                               &error));
  #elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2

    const auto buf =
        make_unique_ptr_gfree (g_utf8_to_utf16 (utf8_string.raw ().data (),
                                                utf8_string.raw ().size (),
                                                nullptr,
                                                nullptr,
                                                &error));
  #else
    const auto buf =
        make_unique_ptr_gfree (g_convert (utf8_string.raw ().data (),
                                          utf8_string.raw ().size (),
                                          "WCHAR_T",
                                          "UTF-8",
                                          nullptr,
                                          nullptr,
                                          &error));
  #endif

    if (error)
    {
      Error::throw_exception (error);
    }

    os << reinterpret_cast<wchar_t*> (buf.get ());

    return os;
  }

#endif

} // namespace Glib
